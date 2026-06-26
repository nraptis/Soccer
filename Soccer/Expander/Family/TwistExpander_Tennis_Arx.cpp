#include "TwistExpander_Tennis_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Tennis_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xF463CF438556C8B7ULL + 0x83410994E027C2FDULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xC6BB475BD01289C5ULL + 0xD3DACE68AA861B34ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC2144916D64A6E41ULL + 0xC8A5DA4216E3103CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x917886A2F1C31591ULL + 0xCA2953310186714BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xD9ABA52D20C47CE9ULL + 0xE87296D45ABB364BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x84229DAC1E8B9ABFULL + 0xBE2537682B0975E2ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xF2F5FACAA26704CBULL + 0x9BE462E5669CACACULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xB362A5DA46F31E39ULL + 0xE6AE2C929CFA2B4EULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 56U) ^ RotL64(aNonceWordB, 21U)) ^ RotL64(aNonceWordF, 3U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 950U)) & S_BLOCK1], 29U) ^ RotL64(mSnow[((aIndex + 985U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 19U) ^ RotL64(aNonceWordD, 57U)) ^ RotL64(aNonceWordE, 10U));
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 2816U)) & S_BLOCK1], 27U) ^ RotL64(mSnow[((S_BLOCK1 - aIndex + 205U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aPrevious, 6U)) ^ (RotL64(aCarry, 23U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererB + RotL64(aIngress, 51U)) + 5171470532667965920U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 57U)) + 750549462358682403U;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 60U)) + 3325689257577120525U;
            aOrbiterF = (aWandererC + RotL64(aCross, 35U)) + 18031575461559790826U;
            aOrbiterH = (((aWandererJ + RotL64(aScatter, 13U)) + RotL64(aCarry, 27U)) + 13874739537012288677U) + RotL64(aNonceWordE, 29U);
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 23U)) + 4250029868785016865U) + aOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aIngress, 40U)) + 8211158803112611161U;
            aOrbiterC = ((aWandererA + RotL64(aCross, 47U)) + RotL64(aCarry, 39U)) + 1083939790236786027U;
            aOrbiterE = (aWandererE + RotL64(aScatter, 53U)) + 3446525462376962464U;
            aOrbiterG = ((aWandererK + RotL64(aCross, 5U)) + 6973817815000417325U) + aOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (((aWandererG + RotL64(aIngress, 29U)) + RotL64(aCarry, 57U)) + 15230876489676945543U) + RotL64(aNonceWordH, 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 9359727659738755880U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 8775170107816327654U;
            aOrbiterK = RotL64((aOrbiterK * 6910680458261008653U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 11958941755525038545U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterF) ^ 16966819714283167348U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]) ^ RotL64(aNonceWordF, 41U);
            aOrbiterJ = RotL64((aOrbiterJ * 16363457661846050749U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 14556087985619763243U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 17915047508377045221U;
            aOrbiterB = RotL64((aOrbiterB * 6727635453185130109U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 8578745677485367222U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 7002181668717618866U;
            aOrbiterF = RotL64((aOrbiterF * 12329703532414955235U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 3569939503066735457U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 2956247934282522184U;
            aOrbiterD = RotL64((aOrbiterD * 9946650822131152531U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 4285180013402474041U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 5976239869535619811U) ^ RotL64(aNonceWordD, 6U);
            aOrbiterE = RotL64((aOrbiterE * 3458095419039067465U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 2424524955161695463U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 6849595426583763537U;
            aOrbiterA = RotL64((aOrbiterA * 12727902040238318101U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 11414890686374886716U) + aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 5668287266836153445U;
            aOrbiterI = RotL64((aOrbiterI * 8011885266143066285U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 9976985606260445887U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 9223940029500676834U;
            aOrbiterH = RotL64((aOrbiterH * 8508023992488499955U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 4480967907876921958U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 5132766654502526597U;
            aOrbiterC = RotL64((aOrbiterC * 321625389942019245U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 12921555132452983464U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 5171470532667965920U;
            aOrbiterG = RotL64((aOrbiterG * 9710487797420618879U), 41U);
            //
            aIngress = RotL64(aOrbiterF, 60U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 52U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterE, 58U)) + aWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 41U) + aOrbiterD) + RotL64(aOrbiterE, 19U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 39U) + aOrbiterF) + RotL64(aOrbiterG, 53U));
            aWandererK = aWandererK + (((RotL64(aScatter, 58U) + aOrbiterI) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 41U)) + aOrbiterJ);
            aWandererE = aWandererE + ((RotL64(aCross, 13U) + RotL64(aOrbiterH, 39U)) + aOrbiterF);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 11U)) + aOrbiterK);
            aWandererI = aWandererI + ((RotL64(aIngress, 3U) + RotL64(aOrbiterB, 26U)) + aOrbiterC);
            aWandererB = aWandererB ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterK, 43U)) + aOrbiterE) + RotL64(aNonceWordA, 15U));
            aWandererD = aWandererD + (((((RotL64(aPrevious, 23U) + RotL64(aOrbiterF, 13U)) + aOrbiterD) + RotL64(aCarry, 29U)) + RotL64(aNonceWordC, 27U)) + aWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 28U) + RotL64(aOrbiterD, 23U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 60U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererI);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 42U));
            aCarry = aCarry + RotL64(aWandererH, 51U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 13U) ^ RotL64(aNonceWordE, 35U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 6602U)) & S_BLOCK1], 52U) ^ RotL64(mSnow[((S_BLOCK1 - aIndex + 6722U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 5U) ^ RotL64(aNonceWordA, 26U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10280U)) & S_BLOCK1], 51U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 10111U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 22U)) ^ (RotL64(aIngress, 51U) + RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (((aWandererA + RotL64(aCross, 53U)) + RotL64(aCarry, 35U)) + 11480359716598965890U) + aOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (aWandererD + RotL64(aScatter, 56U)) + 15431182525482873419U;
            aOrbiterB = (aWandererB + RotL64(aIngress, 43U)) + 11360504974812776707U;
            aOrbiterF = (aWandererF + RotL64(aPrevious, 23U)) + 9292576416573382769U;
            aOrbiterH = (aWandererE + RotL64(aIngress, 11U)) + 1549257414531028975U;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 29U)) + 5347769463033129317U) + RotL64(aNonceWordB, 14U);
            aOrbiterI = ((aWandererK + RotL64(aCross, 3U)) + 17019199177478377234U) + aOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 35U)) + RotL64(aCarry, 21U)) + 16558106007323125094U;
            aOrbiterJ = (((aWandererH + RotL64(aIngress, 47U)) + RotL64(aCarry, 47U)) + 3976182233825939422U) + RotL64(aNonceWordG, 29U);
            aOrbiterC = (aWandererG + RotL64(aPrevious, 5U)) + 2889047161195954395U;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 50U)) + 2241831345026962605U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 12850802412140579294U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 13541744735436450160U) ^ RotL64(aNonceWordF, 45U);
            aOrbiterB = RotL64((aOrbiterB * 906089290000537439U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 2085863085516538212U) + aOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 2969034221711544086U;
            aOrbiterD = RotL64((aOrbiterD * 7768528124408400403U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 6482666944512391472U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 16969153556875844613U;
            aOrbiterH = RotL64((aOrbiterH * 9483462388353216219U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 5161314086757363678U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 7150282484670673211U;
            aOrbiterI = RotL64((aOrbiterI * 8522427002337918663U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 5465304381272305847U) + aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 2344610773390354017U;
            aOrbiterJ = RotL64((aOrbiterJ * 17010258514288089191U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 8335906578006588582U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 13668796013474193793U;
            aOrbiterG = RotL64((aOrbiterG * 8228000547141147777U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 9663362594301419686U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 3683773739120343413U;
            aOrbiterF = RotL64((aOrbiterF * 8319320803406104749U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 2538583190438044942U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 4454069062219406996U) ^ aOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16329554225309389599U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 17177136683616247897U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 3680497519697457252U;
            aOrbiterA = RotL64((aOrbiterA * 6479357366957384599U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 16812938441063719463U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 4545693142067578891U;
            aOrbiterC = RotL64((aOrbiterC * 17479957806084346527U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 9232311730019478327U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 11480359716598965890U) ^ RotL64(aNonceWordD, 51U);
            aOrbiterE = RotL64((aOrbiterE * 6678546065399772697U), 47U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterE, 35U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 46U));
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + RotL64(aOrbiterA, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterF, 57U)) + aOrbiterD);
            aWandererF = aWandererF + (((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 37U)) + aOrbiterD) + aWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 11U) + aOrbiterC) + RotL64(aOrbiterD, 11U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 26U) + aOrbiterC) + RotL64(aOrbiterH, 52U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 35U) + aOrbiterK) + RotL64(aOrbiterB, 3U));
            aWandererA = aWandererA + ((RotL64(aCross, 13U) + RotL64(aOrbiterF, 23U)) + aOrbiterA);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterG, 39U)) + RotL64(aNonceWordA, 43U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterK, 5U)) + aOrbiterH) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 24U) + RotL64(aOrbiterI, 50U)) + aOrbiterE);
            aWandererH = aWandererH + ((((RotL64(aCross, 37U) + RotL64(aOrbiterE, 47U)) + aOrbiterJ) + RotL64(aCarry, 11U)) + RotL64(aNonceWordC, 41U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterJ, 19U)) + aOrbiterB) + aWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 14U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (RotL64(aWandererB, 52U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 3U) ^ RotL64(aNonceWordB, 42U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 14490U)) & S_BLOCK1], 11U) ^ RotL64(mSnow[((S_BLOCK1 - aIndex + 15886U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 29U) ^ RotL64(aNonceWordD, 42U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11125U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((aIndex + 15780U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 22U)) ^ (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererH + RotL64(aIngress, 53U)) + 6733949564325516029U) + RotL64(aNonceWordC, 45U);
            aOrbiterF = (aWandererC + RotL64(aCross, 14U)) + 7304098437143918796U;
            aOrbiterD = (aWandererB + RotL64(aScatter, 19U)) + 3923949518391777800U;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 3U)) + RotL64(aCarry, 53U)) + 14243591003388927124U;
            aOrbiterJ = (aWandererE + RotL64(aIngress, 35U)) + 18329498724605410406U;
            aOrbiterI = (aWandererA + RotL64(aScatter, 5U)) + 13118172167747037249U;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 26U)) + 5272025143849174212U;
            aOrbiterG = ((((aWandererK + RotL64(aCross, 23U)) + RotL64(aCarry, 39U)) + 16075917179214318424U) + aOrbiterAssignSaltE[((aIndex + 24U)) & S_SALT1]) + RotL64(aNonceWordA, 11U);
            aOrbiterH = (aWandererF + RotL64(aScatter, 41U)) + 15263590648674658399U;
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 43U)) + RotL64(aCarry, 11U)) + 13730046728289525921U;
            aOrbiterE = ((aWandererD + RotL64(aCross, 47U)) + 7703141464499623408U) + aOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 1382279753822135359U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 2973369221699098292U;
            aOrbiterD = RotL64((aOrbiterD * 7440242040663550631U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 11578274119583013219U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 3419411247737896674U;
            aOrbiterI = RotL64((aOrbiterI * 17814942652262802991U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 2582783513078999303U) + aOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 3959762790273529677U;
            aOrbiterF = RotL64((aOrbiterF * 383974377372162751U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 465795011576934604U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 17880826624185821135U;
            aOrbiterJ = RotL64((aOrbiterJ * 4445949147592860913U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 10819659185349413173U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 17298208553586835030U;
            aOrbiterG = RotL64((aOrbiterG * 1965860510614222093U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 12585880006661489402U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 16650193903267408586U;
            aOrbiterA = RotL64((aOrbiterA * 5781132589396936615U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 885882046325991589U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 869560078374809974U;
            aOrbiterB = RotL64((aOrbiterB * 13440973563438747181U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 11871305571797951851U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 12137095015607196226U;
            aOrbiterK = RotL64((aOrbiterK * 7618152256560808581U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 6044048326509186958U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 622564532811968856U) ^ aOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14988345089359014037U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 17133994029325040272U) + RotL64(aNonceWordD, 39U);
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 8612895899003926829U;
            aOrbiterH = RotL64((aOrbiterH * 2128664397481732179U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 2169081503433534750U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 6733949564325516029U) ^ RotL64(aNonceWordG, 7U);
            aOrbiterE = RotL64((aOrbiterE * 10062179904046311601U), 27U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterH, 21U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterC, 26U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 23U));
            aIngress = aIngress + RotL64(aOrbiterK, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aPrevious, 53U) + aOrbiterI) + RotL64(aOrbiterH, 39U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterE, 51U)) + aOrbiterC);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 13U)) + aOrbiterC) + aWandererUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 37U) + aOrbiterH) + RotL64(aOrbiterF, 37U));
            aWandererA = aWandererA + (((RotL64(aCross, 28U) + RotL64(aOrbiterJ, 44U)) + aOrbiterD) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 23U) + RotL64(aOrbiterG, 41U)) + aOrbiterH) + RotL64(aNonceWordF, 20U)) + aWandererUpdateSaltC[((aIndex + 28U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 47U)) + RotL64(aNonceWordH, 49U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterK, 35U)) + aOrbiterC);
            aWandererF = aWandererF + ((RotL64(aCross, 57U) + RotL64(aOrbiterK, 54U)) + aOrbiterG);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 11U) + aOrbiterB) + RotL64(aOrbiterF, 47U));
            aWandererC = aWandererC + ((RotL64(aIngress, 26U) + RotL64(aOrbiterG, 21U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (RotL64(aWandererH, 20U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + RotL64(aWandererI, 5U);
            aCarry = aCarry + RotL64(aIngress, 26U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 35U) ^ RotL64(aNonceWordB, 20U));
            aIngress = aIngress ^ (RotL64(mSnow[((aIndex + 19155U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 17669U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 37U) ^ RotL64(aNonceWordD, 23U)) ^ RotL64(aNonceWordF, 60U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18124U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20274U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCross, 53U)) + (RotL64(aIngress, 20U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererH + RotL64(aIngress, 60U)) + 10336802574069791273U) + aOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = (aWandererG + RotL64(aScatter, 43U)) + 169025388197058936U;
            aOrbiterI = (((aWandererC + RotL64(aCross, 41U)) + RotL64(aCarry, 27U)) + 6541354188379168846U) + RotL64(aNonceWordG, 29U);
            aOrbiterG = (aWandererD + RotL64(aPrevious, 57U)) + 16223920526599306104U;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 27U)) + 12756613707692514808U;
            aOrbiterE = (aWandererI + RotL64(aCross, 46U)) + 5082475548176484035U;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 19U)) + 4907435526952698526U;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 39U)) + 14236627073831834337U) + RotL64(aNonceWordA, 3U);
            aOrbiterH = ((aWandererF + RotL64(aIngress, 3U)) + RotL64(aCarry, 39U)) + 11502511046130497584U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 21U)) + RotL64(aCarry, 51U)) + 3679044835550219497U;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 23U)) + 11254838916686736746U) + aOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 10582608424233200966U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 10449735026385340313U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7363770199734997411U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 4628253464169957835U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 17664454668473204465U;
            aOrbiterK = RotL64((aOrbiterK * 4234720298731378527U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 3798386391743884889U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 1379331161819246587U;
            aOrbiterE = RotL64((aOrbiterE * 13086160171095077295U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 9816600392407327227U) + aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 16781971616348376878U;
            aOrbiterJ = RotL64((aOrbiterJ * 12503867584828289879U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 4807797577690520554U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 2492057261148595922U;
            aOrbiterD = RotL64((aOrbiterD * 9453302540675483005U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 7909676419643119585U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 256053568910383007U;
            aOrbiterH = RotL64((aOrbiterH * 11965085163352053161U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 16179914439220412472U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 3968867762761955845U) ^ RotL64(aNonceWordE, 41U);
            aOrbiterB = RotL64((aOrbiterB * 7473632378251893139U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 7474832923901283742U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 4736994731050735779U;
            aOrbiterA = RotL64((aOrbiterA * 9839654409121414047U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 596484364660389193U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 13822222274464306169U;
            aOrbiterC = RotL64((aOrbiterC * 1723502278319885511U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 16307920280681985443U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 3505106171801702915U;
            aOrbiterF = RotL64((aOrbiterF * 8479675421552861243U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 4987142580981135150U) + aOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 10336802574069791273U) ^ RotL64(aNonceWordC, 35U);
            aOrbiterG = RotL64((aOrbiterG * 2670706512498539705U), 41U);
            //
            aIngress = RotL64(aOrbiterH, 21U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterI, 46U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + RotL64(aOrbiterE, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 10U) + RotL64(aOrbiterI, 5U)) + aOrbiterG);
            aWandererC = aWandererC + ((RotL64(aScatter, 37U) + aOrbiterG) + RotL64(aOrbiterB, 57U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 39U) + aOrbiterF) + RotL64(aOrbiterK, 53U));
            aWandererA = aWandererA + ((RotL64(aIngress, 3U) + aOrbiterJ) + RotL64(aOrbiterF, 19U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterE, 29U)) + aOrbiterC);
            aWandererK = aWandererK + ((((RotL64(aScatter, 27U) + aOrbiterA) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 13U)) + aWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterE, 22U)) + aOrbiterA) + RotL64(aNonceWordD, 51U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 42U) + aOrbiterH) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 21U)) + RotL64(aNonceWordB, 20U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 27U)) + aOrbiterF);
            aWandererI = aWandererI + ((RotL64(aIngress, 21U) + RotL64(aOrbiterI, 47U)) + aOrbiterH);
            aWandererG = aWandererG ^ (((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterK, 24U)) + aWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 24U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + RotL64(aWandererB, 54U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 57U) ^ RotL64(aNonceWordC, 11U)) ^ RotL64(aNonceWordE, 47U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 26245U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((aIndex + 26798U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 21U) ^ RotL64(aNonceWordA, 42U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22391U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26724U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 43U)) ^ (RotL64(aCarry, 57U) + RotL64(aIngress, 28U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 51U)) + RotL64(aCarry, 27U)) + 13960289014350612206U;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 53U)) + RotL64(aCarry, 13U)) + 3483331015269589730U;
            aOrbiterB = (((aWandererG + RotL64(aCross, 41U)) + 6873299241002444518U) + aOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1]) + RotL64(aNonceWordG, 42U);
            aOrbiterK = (aWandererB + RotL64(aPrevious, 39U)) + 3562094007125534229U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 47U)) + 11422367439932782705U) + aOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = (aWandererC + RotL64(aIngress, 23U)) + 532453428514259816U;
            aOrbiterF = ((aWandererI + RotL64(aCross, 58U)) + 17810941465810193088U) + RotL64(aNonceWordH, 59U);
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 35U)) + 11869759058631106331U;
            aOrbiterH = (aWandererK + RotL64(aCross, 21U)) + 8837581071876177566U;
            aOrbiterG = (aWandererF + RotL64(aIngress, 35U)) + 17185378327053837778U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 60U)) + 7578253375676981500U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 17112646434432814442U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 14949096407295697881U;
            aOrbiterB = RotL64((aOrbiterB * 14770977858283051753U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 4259590620758467836U) + RotL64(aNonceWordD, 57U);
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 6534899413644542303U;
            aOrbiterD = RotL64((aOrbiterD * 7987609419215568661U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 2637407498893694243U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 15819295597921425711U;
            aOrbiterC = RotL64((aOrbiterC * 5202015597375051399U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 6373559542002699718U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterH) ^ 11694562937392022505U) ^ aOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1]) ^ RotL64(aNonceWordE, 55U);
            aOrbiterG = RotL64((aOrbiterG * 9311557972331218597U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 3308736483775453062U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 12749929710650475901U;
            aOrbiterE = RotL64((aOrbiterE * 248428400724560945U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 1569528215675579656U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 1044077933631689572U;
            aOrbiterK = RotL64((aOrbiterK * 6443796233912755143U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 8393422728124537471U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 2002732612516530754U;
            aOrbiterF = RotL64((aOrbiterF * 13702146823622364279U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 13469191942843147943U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 7633171368709520560U;
            aOrbiterH = RotL64((aOrbiterH * 9713514012478203047U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 4023206337737491091U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 15990323932023596968U;
            aOrbiterI = RotL64((aOrbiterI * 4816480271959713463U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 837005729394899591U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 9692088757104339973U) ^ aOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17971548293495807419U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 18039464962413134616U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 13960289014350612206U;
            aOrbiterA = RotL64((aOrbiterA * 931609478642506411U), 53U);
            //
            aIngress = RotL64(aOrbiterG, 39U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 4U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 53U) + RotL64(aOrbiterD, 47U)) + aOrbiterE) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 21U) + aOrbiterA) + RotL64(aOrbiterK, 44U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 50U) + aOrbiterH) + RotL64(aOrbiterI, 23U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterI, 13U)) + aOrbiterJ);
            aWandererC = aWandererC + ((((RotL64(aIngress, 13U) + aOrbiterC) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 35U)) + RotL64(aNonceWordB, 61U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterC, 27U)) + aOrbiterI) + aWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 19U) + aOrbiterK) + RotL64(aOrbiterB, 37U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 60U) + RotL64(aOrbiterI, 35U)) + aOrbiterE) + aWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterK, 5U)) + RotL64(aNonceWordA, 15U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterK, 52U));
            aWandererE = aWandererE + ((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterE, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 58U));
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 13U) ^ RotL64(aNonceWordH, 43U)) ^ RotL64(aNonceWordB, 5U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 30782U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30870U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 27U) ^ RotL64(aNonceWordE, 14U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29749U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 31096U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 52U) ^ RotL64(aCross, 5U)) + (RotL64(aIngress, 19U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererJ + RotL64(aScatter, 29U)) + 5131645209694953015U;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 52U)) + RotL64(aCarry, 53U)) + 12070391048835379854U;
            aOrbiterF = ((aWandererG + RotL64(aCross, 41U)) + 2604295836242338724U) + aOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aIngress, 43U)) + 14042039029284001596U;
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 5U)) + 8914654543854559327U) + RotL64(aNonceWordA, 35U);
            aOrbiterI = (((aWandererD + RotL64(aCross, 19U)) + RotL64(aCarry, 27U)) + 2185619407969359869U) + aOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 13U)) + RotL64(aCarry, 19U)) + 5187406295103352574U;
            aOrbiterG = (aWandererC + RotL64(aScatter, 3U)) + 8022832481290871217U;
            aOrbiterD = ((aWandererE + RotL64(aCross, 47U)) + 8783061916740573472U) + RotL64(aNonceWordC, 17U);
            aOrbiterB = (aWandererK + RotL64(aPrevious, 22U)) + 10711028365596196301U;
            aOrbiterE = (aWandererF + RotL64(aIngress, 39U)) + 13387065038269133571U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 11187001318931801582U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 14191473173276034019U;
            aOrbiterF = RotL64((aOrbiterF * 2491253922434756431U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 16207761776716426435U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 9677408414452078760U;
            aOrbiterA = RotL64((aOrbiterA * 5487303383095129949U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 17812460332794370649U) + aOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 7736423148554132028U;
            aOrbiterI = RotL64((aOrbiterI * 15588733747232852555U), 19U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterA) + 17293203944059014763U) + aOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1]) + RotL64(aNonceWordF, 13U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 13487243633338010243U;
            aOrbiterJ = RotL64((aOrbiterJ * 9468688858740539095U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 15979293016815060755U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 17645215484691359547U;
            aOrbiterG = RotL64((aOrbiterG * 1449450767288733995U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 11635961468586927692U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 10530136578329059784U;
            aOrbiterD = RotL64((aOrbiterD * 8785021493374398437U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 4900370530116992731U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 15952900504821599445U;
            aOrbiterB = RotL64((aOrbiterB * 5413316082800365261U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 9938000151832814778U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 14170277411106520726U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5058343552974910737U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 14091010427448547620U) + RotL64(aNonceWordD, 51U);
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 13658560822164111421U;
            aOrbiterC = RotL64((aOrbiterC * 9523184040517290629U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 13954269172267844623U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 3921811946419945868U;
            aOrbiterH = RotL64((aOrbiterH * 6839440867046147039U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 14296483810577739898U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 5131645209694953015U;
            aOrbiterK = RotL64((aOrbiterK * 10190969526209064367U), 51U);
            //
            aIngress = RotL64(aOrbiterG, 43U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 60U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 19U) + RotL64(aOrbiterA, 14U)) + aOrbiterD) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 27U) + aOrbiterD) + RotL64(aOrbiterI, 21U)) + aWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 42U) + aOrbiterC) + RotL64(aOrbiterF, 41U)) + RotL64(aCarry, 21U)) + RotL64(aNonceWordG, 55U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 53U) + aOrbiterK) + RotL64(aOrbiterD, 53U)) + RotL64(aNonceWordB, 36U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterK, 47U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 3U)) + aOrbiterF);
            aWandererE = aWandererE + ((RotL64(aScatter, 37U) + RotL64(aOrbiterB, 43U)) + aOrbiterE);
            aWandererF = aWandererF ^ ((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterF, 29U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 40U) + aOrbiterK) + RotL64(aOrbiterG, 39U)) + aWandererUpdateSaltF[((aIndex + 22U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterD, 23U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterK, 12U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 60U));
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + RotL64(aWandererA, 37U);
            aCarry = aCarry + RotL64(aIngress, 40U);
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

void TwistExpander_Tennis_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xC0848B459E8F144FULL + 0xC21D5F6A0A067ECFULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x8122C9360C852D39ULL + 0xCBBD60B7ED89DB57ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xB7C7E182420192C7ULL + 0xEEED189EAA2CAB88ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xB374AB38B5D24C77ULL + 0xFAB25F08BA4830A5ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xD7939D1B0D863DABULL + 0xEB78B8DBB9E9A18AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB98E48F4AB23A5D9ULL + 0xC8D70DB9C8B2ACB0ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xDD6ED8F6475586E3ULL + 0xBD6C903E249030B9ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xA825A7E809623BF3ULL + 0xF436F1ECABC167A6ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 26U) ^ RotL64(aNonceWordA, 47U)) ^ RotL64(aNonceWordG, 13U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 6459U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((aIndex + 1941U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 37U) ^ RotL64(aNonceWordE, 48U)) ^ RotL64(aNonceWordC, 3U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4997U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7163U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCarry, 19U)) ^ (RotL64(aPrevious, 54U) + RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 19U)) + RotL64(aCarry, 27U)) + 12380376990224645149U;
            aOrbiterK = (aWandererH + RotL64(aPrevious, 35U)) + 18296928500297384014U;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 14U)) + 3550626816361145100U) + aOrbiterAssignSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = ((aWandererI + RotL64(aCross, 5U)) + 2667792936946706027U) + RotL64(aNonceWordE, 61U);
            aOrbiterD = (aWandererB + RotL64(aScatter, 47U)) + 12020969779370926953U;
            aOrbiterI = ((aWandererC + RotL64(aCross, 57U)) + 737340727886903447U) + RotL64(aNonceWordF, 49U);
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 28U)) + RotL64(aCarry, 39U)) + 1681797651799760502U;
            aOrbiterJ = (aWandererA + RotL64(aIngress, 53U)) + 2956186342689489064U;
            aOrbiterA = (((aWandererD + RotL64(aCross, 43U)) + RotL64(aCarry, 5U)) + 1876852870402977177U) + aOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 6433205819353555071U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 9065076854974222998U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5459675878087242021U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 3254410578766789992U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 2005081975473815576U;
            aOrbiterI = RotL64((aOrbiterI * 9947701153722014085U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 15992999234834560419U) + aOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterH) ^ 3458344156815120948U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]) ^ RotL64(aNonceWordD, 37U);
            aOrbiterJ = RotL64((aOrbiterJ * 1668460113964608051U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 17069783053664877727U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 1260234710193913099U;
            aOrbiterA = RotL64((aOrbiterA * 4561226779897414381U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 3825186451876061335U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 2905344294992827535U;
            aOrbiterB = RotL64((aOrbiterB * 2469896090698580795U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 18141402347899180617U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 8760129857609925066U;
            aOrbiterE = RotL64((aOrbiterE * 2507999156108123047U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 594052473780678210U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 13216719212966128379U) ^ RotL64(aNonceWordH, 23U);
            aOrbiterH = RotL64((aOrbiterH * 10691355329696722303U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 10029948739466316169U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 11912428807431992996U;
            aOrbiterK = RotL64((aOrbiterK * 85016510811938307U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 8735634019801417287U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 12785916159063273545U;
            aOrbiterD = RotL64((aOrbiterD * 1161917531260663357U), 29U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 47U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 26U));
            aIngress = aIngress + (RotL64(aOrbiterA, 23U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 35U)) + aOrbiterD) + RotL64(aNonceWordC, 21U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 30U) + aOrbiterA) + RotL64(aOrbiterB, 60U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterI, 47U)) + aOrbiterH);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 27U)) + aOrbiterJ) + aWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 11U) + aOrbiterK) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 11U)) + aWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 6U)) + aOrbiterJ);
            aWandererC = aWandererC + ((((RotL64(aIngress, 48U) + RotL64(aOrbiterA, 23U)) + aOrbiterE) + RotL64(aCarry, 35U)) + RotL64(aNonceWordB, 54U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 39U) + aOrbiterH) + RotL64(aOrbiterK, 53U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 23U) + aOrbiterB) + RotL64(aOrbiterD, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 14U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + RotL64(aWandererD, 27U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 5U) ^ RotL64(aNonceWordF, 13U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 8528U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneD[((aIndex + 11191U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 5U) ^ RotL64(aNonceWordH, 20U)) ^ RotL64(aNonceWordG, 29U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13844U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((aIndex + 8455U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 50U) ^ RotL64(aIngress, 19U)) ^ (RotL64(aPrevious, 35U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererK + RotL64(aScatter, 35U)) + RotL64(aCarry, 53U)) + 18180797995100240808U;
            aOrbiterB = ((aWandererI + RotL64(aIngress, 53U)) + RotL64(aCarry, 5U)) + 6585906608223552885U;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 46U)) + 14088708930575939855U) + aOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = (((aWandererE + RotL64(aCross, 11U)) + RotL64(aCarry, 41U)) + 468974153311516044U) + aOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aIngress, 19U)) + 12481951025619894110U;
            aOrbiterD = ((aWandererG + RotL64(aCross, 3U)) + 17227987923860711763U) + RotL64(aNonceWordA, 57U);
            aOrbiterI = (aWandererH + RotL64(aScatter, 60U)) + 4373962756657477139U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 39U)) + 2077576476565420951U) + RotL64(aNonceWordG, 35U);
            aOrbiterF = (aWandererC + RotL64(aIngress, 27U)) + 17435011300234663764U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 4118039398293246896U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 13724716599855216683U;
            aOrbiterA = RotL64((aOrbiterA * 17556333902751079677U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 12391461204689596339U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 9900605191533799627U;
            aOrbiterG = RotL64((aOrbiterG * 13553565332531046301U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 972946858824366125U) + RotL64(aNonceWordE, 47U);
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 17247681919694541215U;
            aOrbiterI = RotL64((aOrbiterI * 2974639094630445643U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 15442851427306771601U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 7303586227288294037U) ^ RotL64(aNonceWordF, 45U);
            aOrbiterK = RotL64((aOrbiterK * 15406402525021428799U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 12650358753454105119U) + aOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 1483710933373510492U) ^ aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6531763256577221891U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 18065810162229740788U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 11311677121338794007U;
            aOrbiterC = RotL64((aOrbiterC * 15116367961682119467U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 2355285311890287611U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 1287783821903407734U;
            aOrbiterH = RotL64((aOrbiterH * 8054011680932255985U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 9282654686791135654U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 15488608017745542551U;
            aOrbiterD = RotL64((aOrbiterD * 7858866274035085123U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 13296835576073421802U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 7127700236018338741U) ^ aOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11246173563106014149U), 53U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 27U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 4U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterD, 11U)) + aOrbiterA) + aWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterC, 19U)) + aOrbiterB);
            aWandererI = aWandererI + ((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 48U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 18U) + RotL64(aOrbiterA, 35U)) + aOrbiterH);
            aWandererC = aWandererC + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 3U)) + aOrbiterH) + RotL64(aCarry, 27U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 57U)) + aOrbiterK) + RotL64(aNonceWordH, 59U));
            aWandererH = aWandererH + (((RotL64(aCross, 53U) + aOrbiterK) + RotL64(aOrbiterD, 39U)) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 23U) + aOrbiterI) + RotL64(aOrbiterD, 44U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 10U) + aOrbiterF) + RotL64(aOrbiterB, 29U)) + RotL64(aNonceWordC, 14U)) + aWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (RotL64(aWandererB, 14U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 29U) ^ RotL64(aNonceWordG, 11U)) ^ RotL64(aNonceWordC, 54U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 18389U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18667U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 13U) ^ RotL64(aNonceWordE, 21U)) ^ RotL64(aNonceWordH, 58U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 23913U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((aIndex + 20540U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 20U) ^ RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererD + RotL64(aScatter, 30U)) + 3561491146322798260U) + RotL64(aNonceWordB, 60U);
            aOrbiterE = (((aWandererF + RotL64(aPrevious, 11U)) + RotL64(aCarry, 23U)) + 7075025056181885339U) + aOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aCross, 3U)) + 9230910887904171613U;
            aOrbiterD = (aWandererG + RotL64(aIngress, 41U)) + 4119781172609908917U;
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 23U)) + 17155609083870983149U;
            aOrbiterH = ((aWandererC + RotL64(aCross, 51U)) + RotL64(aCarry, 5U)) + 2423018561430181695U;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 57U)) + 12957280305617615744U) + RotL64(aNonceWordC, 47U);
            aOrbiterA = (aWandererB + RotL64(aScatter, 47U)) + 2461704174772065813U;
            aOrbiterG = (((aWandererI + RotL64(aIngress, 36U)) + RotL64(aCarry, 47U)) + 7907123257849391997U) + aOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 7257868138318960007U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 16425903703085702285U;
            aOrbiterF = RotL64((aOrbiterF * 7996935869077231999U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 2990822664594079467U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 5654819006718953817U) ^ aOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4465096036756887801U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 12183676471235678779U) + RotL64(aNonceWordE, 37U);
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 15026286960542123922U;
            aOrbiterD = RotL64((aOrbiterD * 17199049329995315279U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 12169080607071830522U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 2906296852254787499U;
            aOrbiterE = RotL64((aOrbiterE * 6754514406846040163U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 3029858695410344584U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 14406410317495954566U;
            aOrbiterJ = RotL64((aOrbiterJ * 9663780721657983421U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 11048818178401163861U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 13622063920319445043U;
            aOrbiterH = RotL64((aOrbiterH * 2516025554421589857U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 2642646089141233277U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 12761571777929273548U;
            aOrbiterI = RotL64((aOrbiterI * 5518252696078700127U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 7753802695131502382U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 8510425459525030222U) ^ RotL64(aNonceWordD, 15U);
            aOrbiterA = RotL64((aOrbiterA * 12412361423636026483U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 13522645164493316722U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 1437430302489702713U;
            aOrbiterG = RotL64((aOrbiterG * 14019316635365783545U), 53U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterI, 3U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 37U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + RotL64(aOrbiterE, 46U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 23U) + RotL64(aOrbiterH, 11U)) + aOrbiterG) + aWandererUpdateSaltF[((aIndex + 26U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 36U) + RotL64(aOrbiterE, 18U)) + aOrbiterI);
            aWandererH = aWandererH + (((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterI, 43U)) + aWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterF, 5U)) + aOrbiterE) + RotL64(aNonceWordA, 35U));
            aWandererG = aWandererG + (((RotL64(aIngress, 57U) + RotL64(aOrbiterA, 29U)) + aOrbiterB) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 23U)) + aOrbiterG);
            aWandererF = aWandererF + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 47U)) + aOrbiterB);
            aWandererI = aWandererI ^ ((RotL64(aCross, 5U) + aOrbiterI) + RotL64(aOrbiterG, 52U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 10U) + aOrbiterD) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 21U)) + RotL64(aNonceWordH, 27U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (RotL64(aWandererJ, 40U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 43U);
            aCarry = aCarry + RotL64(aIngress, 26U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 37U) ^ RotL64(aNonceWordG, 48U)) ^ RotL64(aNonceWordB, 5U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 30237U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32649U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 37U) ^ RotL64(aNonceWordC, 21U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29482U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((aIndex + 27221U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aPrevious, 60U)) ^ (RotL64(aIngress, 11U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererB + RotL64(aScatter, 47U)) + 9751314027302668907U;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 22U)) + 12175450995523107056U) + RotL64(aNonceWordA, 28U);
            aOrbiterG = (aWandererC + RotL64(aCross, 11U)) + 17519694958730119552U;
            aOrbiterK = (aWandererG + RotL64(aIngress, 43U)) + 9093525527925682263U;
            aOrbiterJ = (((aWandererD + RotL64(aScatter, 35U)) + RotL64(aCarry, 3U)) + 3713831321786810138U) + aOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (((aWandererA + RotL64(aPrevious, 3U)) + RotL64(aCarry, 53U)) + 10108355209191835040U) + aOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aIngress, 39U)) + RotL64(aCarry, 41U)) + 12956307447311314768U;
            aOrbiterE = (aWandererF + RotL64(aCross, 58U)) + 1904298513945877359U;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 29U)) + 4658049993308574460U) + RotL64(aNonceWordD, 25U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 9826333658248851902U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 12058666914724365134U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 964233873188373939U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 2516574707110528099U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 13335308331049750235U;
            aOrbiterJ = RotL64((aOrbiterJ * 5880227828760598587U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 8230749255538495304U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 16536559486797811486U) ^ RotL64(aNonceWordB, 51U);
            aOrbiterA = RotL64((aOrbiterA * 7097036838156464969U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 12387639130570188998U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 8459259798142872020U;
            aOrbiterB = RotL64((aOrbiterB * 8001346480955847013U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 16083784052002800300U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 1957284290736468379U) ^ RotL64(aNonceWordE, 21U);
            aOrbiterK = RotL64((aOrbiterK * 5046501301740813065U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 7349538179311335863U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 16395170077006105258U;
            aOrbiterD = RotL64((aOrbiterD * 4230485452156662763U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 3317652065873784068U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 5517155804799120700U;
            aOrbiterE = RotL64((aOrbiterE * 9789270651974719183U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 5568525912112200094U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 9334250662962319598U;
            aOrbiterI = RotL64((aOrbiterI * 5034887614541768961U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 5641394627075994165U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 13524971148931512745U;
            aOrbiterC = RotL64((aOrbiterC * 3699457147759854357U), 29U);
            //
            aIngress = RotL64(aOrbiterD, 19U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 48U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 24U) + aOrbiterA) + RotL64(aOrbiterE, 47U));
            aWandererA = aWandererA + (((RotL64(aCross, 11U) + aOrbiterB) + RotL64(aOrbiterK, 3U)) + RotL64(aNonceWordF, 41U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 39U) + aOrbiterJ) + RotL64(aOrbiterE, 38U)) + aWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 23U)) + aOrbiterD) + RotL64(aCarry, 3U)) + RotL64(aNonceWordH, 11U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterC, 43U));
            aWandererG = aWandererG + ((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 51U)) + aOrbiterI);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 29U)) + aOrbiterC);
            aWandererC = aWandererC + ((((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 11U)) + aWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 20U) + aOrbiterC) + RotL64(aOrbiterI, 56U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 34U));
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void TwistExpander_Tennis_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xE08300A4946A94F7ULL + 0xC68520A5ACA93D6FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xFD82E719D0C2945DULL + 0x9917CA3EA3717218ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xEC70F8091FE50701ULL + 0xC67FCB8F2CAD34A9ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xA0EAD86886025BF5ULL + 0xD335340D25B31C9CULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x9FF370D100123617ULL + 0x87024DFFE2988820ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xB621FD4BFD1FA7B5ULL + 0xF68CE837E913A34AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xBC9E483B03DE1025ULL + 0xB8884CCF05EABE59ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xABF8D85AD3EF531BULL + 0xEFB6EACB70C45E12ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 53U) ^ RotL64(aNonceWordA, 35U)) ^ RotL64(aNonceWordF, 27U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 2927U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7180U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 21U) ^ RotL64(aNonceWordD, 60U)) ^ RotL64(aNonceWordG, 29U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 242U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 7987U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aIngress, 53U)) ^ (RotL64(aPrevious, 34U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererA + RotL64(aIngress, 12U)) + 6916817163240024692U;
            aOrbiterF = (((aWandererK + RotL64(aScatter, 21U)) + 14554930751292077817U) + aOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1]) + RotL64(aNonceWordB, 3U);
            aOrbiterC = (((aWandererF + RotL64(aPrevious, 57U)) + RotL64(aCarry, 29U)) + 1098305064484336101U) + aOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = (((aWandererH + RotL64(aCross, 3U)) + RotL64(aCarry, 41U)) + 12192821172420471527U) + RotL64(aNonceWordF, 12U);
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 41U)) + RotL64(aCarry, 3U)) + 2435134991707318845U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 1896745368738512624U) + aOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 1114996424222923873U;
            aOrbiterC = RotL64((aOrbiterC * 6248754732325773087U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 9839135798371512656U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 8037967239603177043U;
            aOrbiterH = RotL64((aOrbiterH * 7848951103759663025U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 15185468738487237432U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterF) ^ 4912098316394854543U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]) ^ RotL64(aNonceWordH, 17U);
            aOrbiterJ = RotL64((aOrbiterJ * 3072785550384399929U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 13142688607850380888U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 4507379759608945839U) ^ aOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2989332387754215967U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 7299006009652289342U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterC) ^ 5390655277207053627U) ^ aOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1]) ^ RotL64(aNonceWordA, 47U);
            aOrbiterD = RotL64((aOrbiterD * 10973744708856143715U), 3U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 29U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + RotL64(aOrbiterH, 4U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aScatter, 29U) + aOrbiterF) + RotL64(aOrbiterJ, 48U)) + aWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererK = aWandererK + (((((RotL64(aPrevious, 37U) + aOrbiterD) + RotL64(aOrbiterC, 23U)) + RotL64(aCarry, 21U)) + RotL64(aNonceWordG, 11U)) + aWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterJ, 11U)) + RotL64(aNonceWordE, 51U));
            aWandererF = aWandererF + (((RotL64(aIngress, 21U) + aOrbiterC) + RotL64(aOrbiterH, 39U)) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterF, 57U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + RotL64(aWandererH, 30U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 47U) ^ RotL64(aNonceWordC, 27U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 15513U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 8615U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 35U) ^ RotL64(aNonceWordE, 52U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15157U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 11868U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 13U) + RotL64(aPrevious, 41U)) ^ (RotL64(aIngress, 26U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (((aWandererI + RotL64(aScatter, 27U)) + RotL64(aCarry, 5U)) + 13499155707765393469U) + aOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 39U)) + 3740324981823726185U) + RotL64(aNonceWordF, 61U);
            aOrbiterE = ((((aWandererE + RotL64(aPrevious, 5U)) + RotL64(aCarry, 35U)) + 5470765363949735652U) + aOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1]) + RotL64(aNonceWordH, 13U);
            aOrbiterK = ((aWandererC + RotL64(aCross, 47U)) + RotL64(aCarry, 21U)) + 3446436171274452326U;
            aOrbiterF = (aWandererG + RotL64(aIngress, 58U)) + 1778929412631211933U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 14666308799855220954U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 4548410236791175055U;
            aOrbiterE = RotL64((aOrbiterE * 6822908616815218501U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 5829739767694190372U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 14319231414903675748U;
            aOrbiterF = RotL64((aOrbiterF * 4966501102515775601U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 1513851750246111405U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 1685620217748986019U) ^ RotL64(aNonceWordE, 25U);
            aOrbiterH = RotL64((aOrbiterH * 9286548037413609445U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 16284162182006054402U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 6271539598462003309U;
            aOrbiterJ = RotL64((aOrbiterJ * 13923286694131331137U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 12669312437565969473U) + aOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = (((aOrbiterK ^ aOrbiterF) ^ 11894755313393001665U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]) ^ RotL64(aNonceWordD, 11U);
            aOrbiterK = RotL64((aOrbiterK * 12556759675372354075U), 11U);
            //
            aIngress = RotL64(aOrbiterF, 18U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 56U)) + aOrbiterK) + RotL64(aNonceWordC, 4U));
            aWandererG = aWandererG + (((((RotL64(aPrevious, 11U) + aOrbiterE) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 23U)) + RotL64(aNonceWordA, 59U)) + aWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 58U) + aOrbiterJ) + RotL64(aOrbiterK, 11U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterH, 27U)) + RotL64(aCarry, 35U)) + aWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterK, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + RotL64(aWandererA, 26U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 21U) ^ RotL64(aNonceWordE, 5U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 18020U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((aIndex + 23022U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 26U) ^ RotL64(aNonceWordD, 3U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 19073U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 18052U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCarry, 19U)) ^ (RotL64(aCross, 39U) + RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 23U)) + RotL64(aCarry, 19U)) + 9107326720193244489U;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 53U)) + RotL64(aCarry, 43U)) + 10868585484401664145U;
            aOrbiterI = ((aWandererE + RotL64(aCross, 39U)) + 13637736741437846622U) + aOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aIngress, 5U)) + 6130725216183918844U) + RotL64(aNonceWordA, 15U);
            aOrbiterB = ((((aWandererF + RotL64(aCross, 14U)) + RotL64(aCarry, 57U)) + 2063834478521338187U) + aOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1]) + RotL64(aNonceWordG, 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 8564870627911949158U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 6524015751064086390U;
            aOrbiterI = RotL64((aOrbiterI * 12055267995727104463U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 9874937766875388236U) + RotL64(aNonceWordH, 61U);
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 14723718409522680894U;
            aOrbiterK = RotL64((aOrbiterK * 17379140128833323431U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 13767059954741528279U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 6387608251033722169U;
            aOrbiterD = RotL64((aOrbiterD * 6601902195707980693U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 5391425980008431000U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 11524218415655093779U) ^ aOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12508457981779189389U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 155510463350385905U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterK) ^ 10554591788433641311U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]) ^ RotL64(aNonceWordB, 49U);
            aOrbiterB = RotL64((aOrbiterB * 5412084824127934293U), 43U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterI, 6U);
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aScatter, 29U) + aOrbiterG) + RotL64(aOrbiterI, 57U)) + RotL64(aCarry, 19U)) + RotL64(aNonceWordD, 3U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterD, 23U)) + aOrbiterK) + aWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterB, 3U)) + aOrbiterG) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterI, 13U)) + aOrbiterK);
            aWandererA = aWandererA + ((((RotL64(aCross, 60U) + RotL64(aOrbiterI, 42U)) + aOrbiterB) + RotL64(aNonceWordF, 18U)) + aWandererUpdateSaltE[((aIndex + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (RotL64(aWandererJ, 56U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 13U) ^ RotL64(aNonceWordF, 41U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 32666U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28899U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 3U) ^ RotL64(aNonceWordA, 43U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26949U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 28030U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 4U) + RotL64(aPrevious, 19U)) ^ (RotL64(aIngress, 53U) + RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererD + RotL64(aScatter, 39U)) + 7632760812370906911U) + aOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = (((aWandererC + RotL64(aIngress, 51U)) + RotL64(aCarry, 3U)) + 6007174525479723089U) + RotL64(aNonceWordG, 3U);
            aOrbiterF = ((aWandererE + RotL64(aCross, 27U)) + RotL64(aCarry, 51U)) + 3362829642521821048U;
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 18U)) + RotL64(aCarry, 19U)) + 18009548556107978286U;
            aOrbiterK = (((aWandererA + RotL64(aIngress, 5U)) + 17880909432272697327U) + aOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1]) + RotL64(aNonceWordE, 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 15961567935420752568U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 10136559064656837921U) ^ aOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14473810261421912849U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 17622019364405410277U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 6927494824421416306U;
            aOrbiterD = RotL64((aOrbiterD * 2686290883767829973U), 19U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterF) + 7125170407794874847U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]) + RotL64(aNonceWordA, 31U);
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 12342273503071032250U;
            aOrbiterB = RotL64((aOrbiterB * 867417849555857179U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 14997696377476124836U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 14874498694181230698U;
            aOrbiterE = RotL64((aOrbiterE * 4026127545746010937U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 2549397729130885686U) + RotL64(aNonceWordF, 23U);
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 4217995818662767955U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5525525344485251063U), 51U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterE, 29U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + RotL64(aOrbiterB, 42U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterK, 27U)) + aOrbiterB) + aWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 11U)) + aOrbiterE) + RotL64(aCarry, 51U)) + RotL64(aNonceWordC, 8U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterB, 39U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 60U)) + aOrbiterE) + RotL64(aCarry, 13U)) + RotL64(aNonceWordB, 21U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 10U) + aOrbiterD) + RotL64(aOrbiterK, 47U)) + aWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 58U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererG, 13U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void TwistExpander_Tennis_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xC80DAF4724816A35ULL + 0xE1363C5BB64D4E02ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xEF66463E5E906501ULL + 0xA27F60761442BF9CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xCDB4DA558887DC89ULL + 0x899BF905FDAE266EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xA9FD37A36963B3B7ULL + 0xA187273774E494A0ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x8212F0DFA6A2C653ULL + 0xABEC1E768677DFE3ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB63B6EDDBB056D53ULL + 0x96A1B6B94C2FF849ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xFE36BE8D13226787ULL + 0xAB81CE5D1E26B382ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x8F1A8C901E45F0D9ULL + 0xFA224C40D225311FULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 13U) ^ RotL64(aNonceWordC, 34U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 637U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((aIndex + 3328U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 21U) ^ RotL64(aNonceWordF, 13U)) ^ RotL64(aNonceWordG, 3U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1696U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 1910U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 6U) ^ RotL64(aCarry, 19U)) ^ (RotL64(aIngress, 57U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (((aWandererH + RotL64(aScatter, 58U)) + RotL64(aCarry, 5U)) + 15316464782468770057U) + aOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 27U)) + RotL64(aCarry, 39U)) + 6642872057476351588U;
            aOrbiterA = (aWandererB + RotL64(aIngress, 35U)) + 660732654689529192U;
            aOrbiterC = (((aWandererE + RotL64(aCross, 11U)) + RotL64(aCarry, 19U)) + 7235418086884000655U) + RotL64(aNonceWordC, 7U);
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 47U)) + 14784518476694580493U) + aOrbiterAssignSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = (aWandererK + RotL64(aIngress, 41U)) + 12222433977933449375U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 5U)) + 8573001207708329927U) + RotL64(aNonceWordF, 10U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 16035256260815013172U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 15767726974121910203U;
            aOrbiterA = RotL64((aOrbiterA * 719060452537759331U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 17712217935322939971U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 13488963456923357159U;
            aOrbiterD = RotL64((aOrbiterD * 16785285630840310405U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 10222949131965611079U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 1495561412321657209U;
            aOrbiterK = RotL64((aOrbiterK * 9706305581868526265U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 16156530750584361434U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 7773792489045606309U;
            aOrbiterE = RotL64((aOrbiterE * 10730624207715601393U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 11544578291333360613U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterD) ^ 3665587867634242865U) ^ aOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1]) ^ RotL64(aNonceWordD, 27U);
            aOrbiterB = RotL64((aOrbiterB * 4840528190844842595U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 15248434984650998090U) + aOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 15487979645426567581U) ^ aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10868107809356766183U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 6972347795052712690U) + aOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 16074994810010431338U) ^ RotL64(aNonceWordA, 53U);
            aOrbiterF = RotL64((aOrbiterF * 1262655238856775853U), 11U);
            //
            aIngress = RotL64(aOrbiterD, 19U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterK, 19U));
            aWandererC = aWandererC + (((RotL64(aCross, 19U) + RotL64(aOrbiterB, 27U)) + aOrbiterD) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 43U) + aOrbiterB) + RotL64(aOrbiterE, 13U)) + RotL64(aNonceWordB, 43U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 27U) + aOrbiterC) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 37U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 11U) + aOrbiterB) + RotL64(aOrbiterA, 51U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 60U) + RotL64(aOrbiterE, 41U)) + aOrbiterA) + RotL64(aNonceWordG, 15U)) + aWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 53U) + aOrbiterD) + RotL64(aOrbiterF, 58U)) + aWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 6U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 53U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 11U) ^ RotL64(aNonceWordF, 43U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 16100U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13355U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 41U) ^ RotL64(aNonceWordG, 21U)) ^ RotL64(aNonceWordD, 29U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8959U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10716U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aIngress, 19U)) + (RotL64(aCarry, 52U) ^ RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererD + RotL64(aCross, 37U)) + 5173905450211892891U;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 13U)) + 3555542451908039957U) + RotL64(aNonceWordC, 35U);
            aOrbiterC = (aWandererE + RotL64(aPrevious, 57U)) + 11559884700283861559U;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 43U)) + RotL64(aCarry, 57U)) + 1352524329968738673U;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 51U)) + 8914206450420616349U;
            aOrbiterB = (((aWandererH + RotL64(aScatter, 6U)) + RotL64(aCarry, 41U)) + 2251523378498463946U) + aOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = ((((aWandererI + RotL64(aCross, 27U)) + RotL64(aCarry, 19U)) + 9541575923299247038U) + aOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1]) + RotL64(aNonceWordA, 56U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 1239854507907214595U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 17698101462598498934U;
            aOrbiterC = RotL64((aOrbiterC * 2304948713665996433U), 27U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterA) + 12305566971683256060U) + aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1]) + RotL64(aNonceWordD, 17U);
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 13804545036303215569U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10359543704152744971U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 10239749097704329264U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 4212214906286320308U;
            aOrbiterH = RotL64((aOrbiterH * 3661436621615751071U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 12192418916967430783U) + aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 4475514289326450361U;
            aOrbiterD = RotL64((aOrbiterD * 17497164630368757887U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 17376102613298827459U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 18129393209955439341U;
            aOrbiterA = RotL64((aOrbiterA * 6404089025014118979U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 4014763724300253568U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 17325007199676828814U) ^ RotL64(aNonceWordF, 51U);
            aOrbiterB = RotL64((aOrbiterB * 1420888274815627083U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 15480474849292388685U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 14357924730184375449U;
            aOrbiterJ = RotL64((aOrbiterJ * 16723492259068034209U), 3U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 5U);
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 60U));
            aIngress = aIngress + RotL64(aOrbiterD, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 27U)) + aOrbiterB) + RotL64(aNonceWordH, 53U));
            aWandererF = aWandererF + ((((RotL64(aCross, 37U) + RotL64(aOrbiterB, 21U)) + aOrbiterC) + RotL64(aCarry, 27U)) + RotL64(aNonceWordG, 15U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 10U) + aOrbiterJ) + RotL64(aOrbiterC, 4U));
            aWandererB = aWandererB + (((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterH, 57U)) + aWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 57U) + aOrbiterA) + RotL64(aOrbiterB, 51U));
            aWandererE = aWandererE + (((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterH, 41U)) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterD, 11U)) + aWandererUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + (RotL64(aWandererF, 38U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 57U) ^ RotL64(aNonceWordH, 13U)) ^ RotL64(aNonceWordF, 34U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 17848U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((aIndex + 23747U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 3U) ^ RotL64(aNonceWordG, 41U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18454U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneC[((aIndex + 17068U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aIngress, 19U)) + (RotL64(aPrevious, 52U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererD + RotL64(aIngress, 19U)) + RotL64(aCarry, 39U)) + 17936518874386450467U;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 47U)) + 13722737841589910344U) + aOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 53U)) + 11774969167948715796U) + RotL64(aNonceWordC, 17U);
            aOrbiterB = ((aWandererE + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 3640101505680493777U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 29U)) + 1369495382725650822U) + RotL64(aNonceWordE, 27U);
            aOrbiterI = (aWandererA + RotL64(aScatter, 12U)) + 11827310354654653345U;
            aOrbiterE = (((aWandererI + RotL64(aCross, 41U)) + RotL64(aCarry, 19U)) + 186037671377175394U) + aOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 11428829344234627340U) + RotL64(aNonceWordG, 22U);
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 2275016369870029068U;
            aOrbiterD = RotL64((aOrbiterD * 14936799202145280833U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 15471646673734798328U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 12172082573115640145U) ^ aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9629417882787847753U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 6626736341348283154U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 12220614992483863623U;
            aOrbiterH = RotL64((aOrbiterH * 8137086205714097487U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 13157102324253760215U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 4143587482368093601U;
            aOrbiterB = RotL64((aOrbiterB * 5060677690991506895U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 11007575246013796426U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 11721585930088637162U) ^ aOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15009627907125738519U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 5720789204450196217U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 3094696226821431648U;
            aOrbiterI = RotL64((aOrbiterI * 4412033981712165541U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 14675830108100986773U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 9444071495289719645U) ^ RotL64(aNonceWordH, 9U);
            aOrbiterE = RotL64((aOrbiterE * 10983136361953366557U), 53U);
            //
            aIngress = RotL64(aOrbiterI, 20U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aPrevious, 18U) + aOrbiterI) + RotL64(aOrbiterD, 19U)) + RotL64(aNonceWordD, 39U)) + aWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterB, 39U)) + aOrbiterC) + RotL64(aNonceWordB, 21U));
            aWandererA = aWandererA + ((RotL64(aCross, 27U) + aOrbiterD) + RotL64(aOrbiterK, 3U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 41U) + aOrbiterB) + RotL64(aOrbiterI, 60U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 11U)) + aOrbiterE) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 51U) + aOrbiterK) + RotL64(aOrbiterH, 53U)) + aWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 27U)) + aOrbiterH) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 60U));
            aCarry = aCarry + RotL64(aWandererK, 43U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 34U) ^ RotL64(aNonceWordD, 21U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 28371U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25223U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 52U) ^ RotL64(aNonceWordE, 35U)) ^ RotL64(aNonceWordA, 3U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28838U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 25098U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aPrevious, 6U)) ^ (RotL64(aCarry, 21U) + RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 51U)) + RotL64(aCarry, 13U)) + 15036852811491820366U;
            aOrbiterD = (((aWandererI + RotL64(aIngress, 13U)) + RotL64(aCarry, 39U)) + 305637140752898475U) + RotL64(aNonceWordC, 35U);
            aOrbiterF = (aWandererA + RotL64(aScatter, 3U)) + 11948631574496129610U;
            aOrbiterK = (aWandererH + RotL64(aCross, 19U)) + 5321623592482991426U;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 29U)) + 4075270159062690728U) + aOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 42U)) + RotL64(aCarry, 57U)) + 15111580500356908928U;
            aOrbiterH = (((aWandererD + RotL64(aIngress, 57U)) + 7244150695504160363U) + aOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1]) + RotL64(aNonceWordA, 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 5131563519577488862U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 5881954992088651371U;
            aOrbiterF = RotL64((aOrbiterF * 2424421828597294607U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 12780935808751507998U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 12599159643925470226U) ^ RotL64(aNonceWordG, 50U);
            aOrbiterJ = RotL64((aOrbiterJ * 17690046932587062701U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 9466589929741834066U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 6093158735705189789U;
            aOrbiterD = RotL64((aOrbiterD * 7453778295800853653U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 17461243886150519249U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 15456408913739900718U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16093292401746174671U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 11260643903290392780U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 7870342756041882616U;
            aOrbiterG = RotL64((aOrbiterG * 2431528656086173419U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 134484990005888936U) + aOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 10626896209992890407U) ^ RotL64(aNonceWordD, 21U);
            aOrbiterK = RotL64((aOrbiterK * 12034131076645285597U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 14031164129515132292U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 1771835705730244212U;
            aOrbiterH = RotL64((aOrbiterH * 186981668443596623U), 3U);
            //
            aIngress = RotL64(aOrbiterC, 41U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 4U));
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 53U) + aOrbiterK) + RotL64(aOrbiterJ, 35U));
            aWandererA = aWandererA + ((RotL64(aIngress, 19U) + aOrbiterH) + RotL64(aOrbiterJ, 41U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterK, 11U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterH, 29U)) + aOrbiterC) + RotL64(aCarry, 57U)) + aWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 57U)) + aOrbiterH) + RotL64(aNonceWordE, 25U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 12U) + aOrbiterD) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 43U)) + aWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterC, 4U)) + aOrbiterD) + RotL64(aNonceWordF, 17U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 48U));
            aCarry = aCarry + RotL64(aWandererE, 3U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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

void TwistExpander_Tennis_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xB43E2A694C6C572BULL + 0xC4DB504B2B49CA37ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xF5DDA98475516585ULL + 0xC3185713E658845CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xA4D50AAD5036DFD1ULL + 0xB78F1A09342379A6ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x9D9EF482776B14B9ULL + 0xA40FF2123B7BCDB4ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x9F4494AEB3224CE1ULL + 0xD3600F47312F7D00ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xF9E37FB411B42931ULL + 0xFB0C1AA76E059645ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xE06142597ACCC8D1ULL + 0xA7FF0333F9942C85ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xCB3EE7E78C844089ULL + 0xE845CE6ABBD9FD3CULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 18U) ^ RotL64(aNonceWordF, 43U)) ^ RotL64(aNonceWordC, 27U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 7828U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7615U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 44U) ^ RotL64(aNonceWordH, 21U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 7683U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 7789U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 19U) ^ RotL64(aPrevious, 35U)) + (RotL64(aCross, 47U) ^ RotL64(aIngress, 60U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererA + RotL64(aIngress, 47U)) + 966899917801652720U) + RotL64(aNonceWordA, 59U);
            aOrbiterF = ((aWandererJ + RotL64(aCross, 60U)) + RotL64(aCarry, 19U)) + 10996327672320748649U;
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 3U)) + 4188171566846621107U;
            aOrbiterC = (((aWandererC + RotL64(aScatter, 21U)) + RotL64(aCarry, 39U)) + 5886209243097387959U) + aOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aCross, 11U)) + 14940428957136728111U) + RotL64(aNonceWordH, 8U);
            aOrbiterK = (((aWandererH + RotL64(aPrevious, 39U)) + RotL64(aCarry, 53U)) + 179187285531914832U) + aOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aIngress, 29U)) + 6685351948936817752U;
            //
            aOrbiterI = (((aOrbiterI + aOrbiterF) + 1894506461704029700U) + aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1]) + RotL64(aNonceWordD, 49U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 4182760368636977082U;
            aOrbiterJ = RotL64((aOrbiterJ * 972988091869133921U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 12523318028514940790U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 5059306166973366892U;
            aOrbiterG = RotL64((aOrbiterG * 2857409765717296483U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 5890872367917643851U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 17747338389865221534U) ^ aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5306740664798049267U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 13906227834259884100U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterJ) ^ 7152105382899756368U) ^ aOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1]) ^ RotL64(aNonceWordB, 47U);
            aOrbiterA = RotL64((aOrbiterA * 6772157117358310485U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 17868101884759619240U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 11758843266314148347U;
            aOrbiterI = RotL64((aOrbiterI * 5919135169337501485U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 13950566197090324859U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 17278105609930477854U;
            aOrbiterC = RotL64((aOrbiterC * 11431842718945107359U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 9556785965646738355U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 841298436857932987U;
            aOrbiterF = RotL64((aOrbiterF * 15077843186688841797U), 35U);
            //
            aIngress = RotL64(aOrbiterI, 29U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterC, 58U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 3U) + RotL64(aOrbiterA, 39U)) + aOrbiterG) + RotL64(aCarry, 39U));
            aWandererC = aWandererC ^ ((((RotL64(aCross, 48U) + aOrbiterI) + RotL64(aOrbiterF, 13U)) + RotL64(aNonceWordE, 5U)) + aWandererUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 51U)) + aOrbiterC) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterJ, 30U)) + RotL64(aNonceWordC, 3U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 19U)) + aOrbiterK);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 21U) + aOrbiterF) + RotL64(aOrbiterA, 57U)) + aWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 41U) + RotL64(aOrbiterJ, 3U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererC, 12U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + RotL64(aWandererF, 41U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 21U) ^ RotL64(aNonceWordG, 10U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 8384U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15993U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 13U) ^ RotL64(aNonceWordC, 22U)) ^ RotL64(aNonceWordD, 3U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 14517U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 9552U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCarry, 35U)) + (RotL64(aCross, 11U) + RotL64(aPrevious, 56U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererI + RotL64(aPrevious, 19U)) + 6916817163240024692U;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 35U)) + RotL64(aCarry, 3U)) + 14554930751292077817U;
            aOrbiterK = ((aWandererH + RotL64(aCross, 57U)) + RotL64(aCarry, 19U)) + 1098305064484336101U;
            aOrbiterA = (((aWandererE + RotL64(aScatter, 51U)) + 12192821172420471527U) + aOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1]) + RotL64(aNonceWordG, 27U);
            aOrbiterC = ((aWandererK + RotL64(aIngress, 11U)) + 2435134991707318845U) + RotL64(aNonceWordD, 54U);
            aOrbiterG = ((aWandererF + RotL64(aScatter, 41U)) + RotL64(aCarry, 47U)) + 1896745368738512624U;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 4U)) + 1114996424222923873U) + aOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 9839135798371512656U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 8037967239603177043U;
            aOrbiterK = RotL64((aOrbiterK * 7848951103759663025U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 15185468738487237432U) + aOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 4912098316394854543U) ^ RotL64(aNonceWordH, 11U);
            aOrbiterD = RotL64((aOrbiterD * 3072785550384399929U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 13142688607850380888U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 4507379759608945839U) ^ aOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2989332387754215967U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 7299006009652289342U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 5390655277207053627U;
            aOrbiterE = RotL64((aOrbiterE * 10973744708856143715U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 6744737023577785725U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 15539737698867067285U;
            aOrbiterC = RotL64((aOrbiterC * 4686092035261336911U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 13329866734681377952U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 13284937458969166257U) ^ RotL64(aNonceWordF, 7U);
            aOrbiterG = RotL64((aOrbiterG * 3965985432462699445U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 8695002088915702168U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 3858059421620839286U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9559783727301092937U), 57U);
            //
            aIngress = RotL64(aOrbiterA, 35U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aScatter, 11U) + RotL64(aOrbiterE, 53U)) + aOrbiterC);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterC, 47U)) + RotL64(aNonceWordE, 49U));
            aWandererF = aWandererF + ((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterE, 5U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterJ, 60U)) + aOrbiterK) + aWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aIngress, 58U) + RotL64(aOrbiterD, 11U)) + aOrbiterK) + RotL64(aCarry, 57U)) + aWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterE, 39U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 27U) + RotL64(aOrbiterC, 27U)) + aOrbiterJ) + RotL64(aCarry, 11U)) + RotL64(aNonceWordA, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 58U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 51U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 3U) ^ RotL64(aNonceWordG, 37U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 19933U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 22720U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 19U) ^ RotL64(aNonceWordA, 60U)) ^ RotL64(aNonceWordB, 5U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 22466U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneC[((aIndex + 23484U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aIngress, 12U)) ^ (RotL64(aPrevious, 29U) ^ RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 29U)) + RotL64(aCarry, 23U)) + 13053031069776604052U;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 11U)) + RotL64(aCarry, 43U)) + 1331396630251085122U;
            aOrbiterD = ((aWandererD + RotL64(aCross, 3U)) + 15879286043343942393U) + aOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = (aWandererK + RotL64(aIngress, 60U)) + 13590365633321406830U;
            aOrbiterI = ((aWandererG + RotL64(aScatter, 43U)) + 14569235423040242618U) + RotL64(aNonceWordB, 29U);
            aOrbiterE = (((aWandererI + RotL64(aCross, 53U)) + RotL64(aCarry, 11U)) + 11397370636618371560U) + RotL64(aNonceWordA, 51U);
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 21U)) + 3455933494593971847U) + aOrbiterAssignSaltD[((aIndex + 16U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 1307153376443784593U) + aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 10688618762584786871U;
            aOrbiterD = RotL64((aOrbiterD * 9503823896874842411U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 17746248451153600096U) + RotL64(aNonceWordH, 52U);
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 8512568600755410158U;
            aOrbiterH = RotL64((aOrbiterH * 16648320170768234063U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 8950230550112591092U) + RotL64(aNonceWordD, 57U);
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 17790968369472845496U;
            aOrbiterF = RotL64((aOrbiterF * 5104988920132008913U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 12583323865381967534U) + aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 11243927099685293887U;
            aOrbiterA = RotL64((aOrbiterA * 12867003042486433971U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 9690268715525781389U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 7466066217365074653U;
            aOrbiterI = RotL64((aOrbiterI * 17565696765505320889U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 3673528673209875118U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 14079103852360952255U;
            aOrbiterE = RotL64((aOrbiterE * 17449228863409999629U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 6747836856132250630U) + aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 5027692924422297153U;
            aOrbiterJ = RotL64((aOrbiterJ * 2492421273167124437U), 5U);
            //
            aIngress = RotL64(aOrbiterA, 13U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterI, 47U)) + aOrbiterE) + aWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 41U) + aOrbiterF) + RotL64(aOrbiterD, 41U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterH, 58U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 5U) + aOrbiterH) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 48U) + aOrbiterJ) + RotL64(aOrbiterE, 19U));
            aWandererD = aWandererD + (((((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterI, 11U)) + RotL64(aCarry, 53U)) + RotL64(aNonceWordE, 3U)) + aWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 27U)) + aOrbiterH) + RotL64(aNonceWordC, 17U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 22U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererI, 13U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 11U) ^ RotL64(aNonceWordA, 40U)) ^ RotL64(aNonceWordC, 53U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31583U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24861U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 41U) ^ RotL64(aNonceWordB, 56U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25241U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneD[((aIndex + 26063U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aIngress, 5U)) + (RotL64(aPrevious, 22U) + RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 27U)) + RotL64(aCarry, 57U)) + 18144572925667544139U;
            aOrbiterC = ((aWandererB + RotL64(aCross, 51U)) + 5659758077574059728U) + RotL64(aNonceWordE, 49U);
            aOrbiterE = (aWandererI + RotL64(aIngress, 13U)) + 6343330616999166392U;
            aOrbiterA = (((aWandererC + RotL64(aScatter, 37U)) + RotL64(aCarry, 41U)) + 17754639838410839447U) + RotL64(aNonceWordG, 29U);
            aOrbiterK = (aWandererH + RotL64(aIngress, 20U)) + 9451843819849581729U;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 5U)) + 7957854457197462212U) + aOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = (((aWandererE + RotL64(aCross, 57U)) + RotL64(aCarry, 5U)) + 1461994799722205010U) + aOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 18002214276252170177U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 14689869073147027164U) ^ RotL64(aNonceWordF, 7U);
            aOrbiterE = RotL64((aOrbiterE * 12242482963989582191U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 3978104368003440293U) + aOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 8512135845221335386U;
            aOrbiterJ = RotL64((aOrbiterJ * 10506667163729414667U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 1477533446382953439U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 2166717790929947990U;
            aOrbiterC = RotL64((aOrbiterC * 6538884492418324461U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 8082437060686606995U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 4363687722464700362U;
            aOrbiterK = RotL64((aOrbiterK * 7199165810993478887U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 15782763348014924206U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 8572509150015960728U) ^ RotL64(aNonceWordH, 13U);
            aOrbiterI = RotL64((aOrbiterI * 3340528604891897779U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 12248271773316742521U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 9602078627638561949U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1860631869877427405U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 17244849374768558859U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 1030743048280579012U;
            aOrbiterH = RotL64((aOrbiterH * 10858949914285817051U), 3U);
            //
            aIngress = RotL64(aOrbiterJ, 41U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 60U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + RotL64(aOrbiterI, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterA, 19U));
            aWandererF = aWandererF + (((RotL64(aCross, 40U) + aOrbiterC) + RotL64(aOrbiterH, 54U)) + aWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterK, 37U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterI, 43U)) + aOrbiterC) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 47U) + aOrbiterI) + RotL64(aOrbiterH, 29U)) + aWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterC, 5U)) + aOrbiterE) + RotL64(aCarry, 21U)) + RotL64(aNonceWordD, 21U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterH, 13U)) + RotL64(aNonceWordB, 12U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 34U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_Tennis_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xE7816EDCBD7CD11BULL + 0xCD79654E358114F4ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xF2D55B306BFDA1F1ULL + 0xACCE16CE0EC930ADULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xF42ADD15EEB3440FULL + 0x81B367249FDBFFA6ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xA97EA0B03CB0394DULL + 0xCD4530E3B3937062ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xF3C11BEB3A0744DFULL + 0xD27E6C5D709DE0EDULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xC7A3554C7A7E5117ULL + 0xF2E196D8491724E3ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x8318EBA46423606FULL + 0xC02A5FE6A9AE0CCFULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x9F698A5B8B9C5C1BULL + 0xE538F3E0ED64F244ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 5U) ^ RotL64(aNonceWordF, 23U)) ^ RotL64(aNonceWordC, 13U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5055U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1553U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 20U) ^ RotL64(aNonceWordE, 53U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5862U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 4453U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCarry, 23U)) ^ (RotL64(aCross, 54U) ^ RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (((aWandererG + RotL64(aPrevious, 29U)) + 12775735908960052604U) + aOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1]) + RotL64(aNonceWordB, 3U);
            aOrbiterF = (aWandererI + RotL64(aScatter, 11U)) + 11791373812080296887U;
            aOrbiterH = ((aWandererD + RotL64(aCross, 57U)) + RotL64(aCarry, 43U)) + 5537362877706057303U;
            aOrbiterK = (aWandererA + RotL64(aIngress, 51U)) + 2023912048504189380U;
            aOrbiterA = (aWandererB + RotL64(aCross, 35U)) + 17668828109963766893U;
            aOrbiterE = (aWandererC + RotL64(aScatter, 14U)) + 558908629933941224U;
            aOrbiterB = (((aWandererH + RotL64(aIngress, 27U)) + 1479633119685446888U) + aOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1]) + RotL64(aNonceWordF, 10U);
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 19U)) + RotL64(aCarry, 19U)) + 15460320397843364063U;
            aOrbiterI = (aWandererE + RotL64(aScatter, 47U)) + 10059749397555469054U;
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 37U)) + 9987633811929693924U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 22U)) + RotL64(aCarry, 35U)) + 10087337844580228269U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 4446204415503364254U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 15106063243302192717U) ^ RotL64(aNonceWordD, 41U);
            aOrbiterH = RotL64((aOrbiterH * 13273756657334709803U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 9430197906134676162U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 1226048679997253363U;
            aOrbiterE = RotL64((aOrbiterE * 14247538885252664127U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 10611580584157624739U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 3137391249289641509U;
            aOrbiterD = RotL64((aOrbiterD * 5462682413239873181U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 9327201928815412810U) + aOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 7890659377013147073U;
            aOrbiterK = RotL64((aOrbiterK * 13827717178378062047U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 10675114832750356941U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 8804440385852327267U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8520671775587260601U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 12871947817782057116U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 11015991745792051390U;
            aOrbiterI = RotL64((aOrbiterI * 17152451500505815031U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 6320437975845673731U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 702457937087191287U;
            aOrbiterG = RotL64((aOrbiterG * 17491257114676739589U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 16629064896250312921U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 6054107387816339103U) ^ aOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6983767878966747219U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 13274874838094190290U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 12211422735294360321U) ^ RotL64(aNonceWordH, 45U);
            aOrbiterA = RotL64((aOrbiterA * 5113738196151089817U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 15338616110718583619U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 1475787183754511373U;
            aOrbiterC = RotL64((aOrbiterC * 10904607643785840003U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 15486810401396777742U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 12775735908960052604U;
            aOrbiterJ = RotL64((aOrbiterJ * 7478156942468930207U), 27U);
            //
            aIngress = RotL64(aOrbiterA, 41U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + RotL64(aOrbiterI, 38U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aIngress, 26U) + aOrbiterG) + RotL64(aOrbiterI, 54U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 37U) + aOrbiterF) + RotL64(aOrbiterE, 35U)) + aWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterE, 37U)) + aOrbiterA) + aWandererUpdateSaltE[((aIndex + 8U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 39U) + aOrbiterC) + RotL64(aOrbiterH, 41U)) + RotL64(aNonceWordG, 37U));
            aWandererF = aWandererF + (((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 3U)) + aOrbiterC) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 28U) + aOrbiterJ) + RotL64(aOrbiterD, 29U));
            aWandererK = aWandererK + ((RotL64(aScatter, 21U) + RotL64(aOrbiterB, 57U)) + aOrbiterG);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 43U) + aOrbiterD) + RotL64(aOrbiterA, 47U));
            aWandererI = aWandererI + (((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 5U)) + aOrbiterE) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterE, 52U)) + RotL64(aNonceWordA, 47U));
            aWandererE = aWandererE + ((RotL64(aCross, 23U) + aOrbiterA) + RotL64(aOrbiterK, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 4U));
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + RotL64(aWandererK, 36U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 29U) ^ RotL64(aNonceWordF, 57U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 12486U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((aIndex + 12567U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 3U) ^ RotL64(aNonceWordD, 51U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12119U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 14880U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCross, 10U)) + (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererF + RotL64(aIngress, 27U)) + 16451272412693907816U;
            aOrbiterC = (aWandererE + RotL64(aCross, 13U)) + 10099485419723255462U;
            aOrbiterH = (aWandererI + RotL64(aScatter, 11U)) + 17668900099534923192U;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 30U)) + 5497093724143181753U) + RotL64(aNonceWordC, 17U);
            aOrbiterB = ((aWandererC + RotL64(aIngress, 3U)) + RotL64(aCarry, 23U)) + 10354044773550071706U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 53U)) + 12728258851198019099U) + RotL64(aNonceWordG, 45U);
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 23U)) + RotL64(aCarry, 11U)) + 4144050505314242618U;
            aOrbiterI = (aWandererB + RotL64(aCross, 20U)) + 14133805325480076530U;
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 47U)) + 308863673210602899U;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 57U)) + 11741180130160569753U) + aOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = (((aWandererH + RotL64(aScatter, 41U)) + RotL64(aCarry, 5U)) + 12926863156769180448U) + aOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 211920854786494259U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 13234608842479411078U;
            aOrbiterH = RotL64((aOrbiterH * 2556747209733759467U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 9164711974854618892U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 6667377062281954219U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2603737166987437649U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 4559040002406721850U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 1749875480850675109U;
            aOrbiterB = RotL64((aOrbiterB * 15822640067349481089U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 9555365165561936366U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 18289733999504213574U;
            aOrbiterK = RotL64((aOrbiterK * 14156217554673229429U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 8727162691639622461U) + aOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 291406782452963706U;
            aOrbiterJ = RotL64((aOrbiterJ * 8413500075082350243U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 8294911802626492257U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 15853578397277298548U;
            aOrbiterG = RotL64((aOrbiterG * 13256191781365357747U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 11535146194939658681U) + RotL64(aNonceWordA, 27U);
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 2177540476748375661U) ^ RotL64(aNonceWordH, 55U);
            aOrbiterF = RotL64((aOrbiterF * 15791341922007841029U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 2705306323728084136U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 17617871830709148043U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3449981219502809255U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 3699834746313613206U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 17952609181629473245U;
            aOrbiterI = RotL64((aOrbiterI * 6103160209028988839U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 8016694658897707674U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 6971251395823324489U;
            aOrbiterA = RotL64((aOrbiterA * 13483776115929040277U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 17467528888050817915U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 16451272412693907816U;
            aOrbiterD = RotL64((aOrbiterD * 13689734638238895071U), 19U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterC, 5U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 10U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + RotL64(aOrbiterE, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aIngress, 5U) + RotL64(aOrbiterJ, 34U)) + aOrbiterD);
            aWandererH = aWandererH ^ ((((RotL64(aScatter, 26U) + aOrbiterE) + RotL64(aOrbiterB, 27U)) + RotL64(aNonceWordE, 61U)) + aWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 43U) + aOrbiterK) + RotL64(aOrbiterF, 3U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterD, 41U)) + aOrbiterE) + aWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterC, 58U)) + aOrbiterF) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterA, 39U));
            aWandererA = aWandererA + (((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 53U)) + aOrbiterI) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 39U) + aOrbiterG) + RotL64(aOrbiterH, 13U)) + RotL64(aNonceWordB, 28U));
            aWandererG = aWandererG + ((RotL64(aIngress, 22U) + aOrbiterJ) + RotL64(aOrbiterK, 37U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterD, 51U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 23U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 56U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererK, 53U);
            aCarry = aCarry + RotL64(aIngress, 34U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 30U) ^ RotL64(aNonceWordD, 53U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 18161U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((aIndex + 22286U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 44U) ^ RotL64(aNonceWordC, 57U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17134U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((aIndex + 19356U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 56U) + RotL64(aPrevious, 39U)) ^ (RotL64(aCross, 27U) + RotL64(aIngress, 13U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 3U)) + RotL64(aCarry, 23U)) + 7896237440058555694U;
            aOrbiterB = (aWandererB + RotL64(aIngress, 47U)) + 11870529476037558635U;
            aOrbiterC = (((aWandererC + RotL64(aScatter, 60U)) + RotL64(aCarry, 39U)) + 9158983227801569448U) + aOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aCross, 39U)) + RotL64(aCarry, 27U)) + 4710172270996950329U;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 41U)) + 14634482800356647630U) + RotL64(aNonceWordH, 45U);
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 57U)) + 8822207952170610891U) + aOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aScatter, 19U)) + 13755891414028982553U;
            aOrbiterD = (aWandererK + RotL64(aCross, 21U)) + 4555293067488040719U;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 35U)) + 2816805148093762081U) + RotL64(aNonceWordA, 37U);
            aOrbiterK = (aWandererD + RotL64(aCross, 13U)) + 2122631477965135190U;
            aOrbiterE = (aWandererI + RotL64(aIngress, 54U)) + 4592922416380416071U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 7102471666524164715U) + RotL64(aNonceWordB, 43U);
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 17274623547879474204U;
            aOrbiterC = RotL64((aOrbiterC * 5443572270546181789U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 938587316977094680U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 18258015823797023523U) ^ aOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6068819567674605919U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 5809987756043471595U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 5083075160112581620U;
            aOrbiterB = RotL64((aOrbiterB * 3313957222154937503U), 3U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterK) + 5960021727750946496U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]) + RotL64(aNonceWordE, 29U);
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 5967477320950630150U;
            aOrbiterF = RotL64((aOrbiterF * 330964768256424655U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 6578428711689296132U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 5601728218197771276U;
            aOrbiterD = RotL64((aOrbiterD * 9552559022315971847U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 7923809409017855241U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 16479366540906497019U;
            aOrbiterK = RotL64((aOrbiterK * 7118578387798460919U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 17000467091738009736U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 6801634573655508028U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10584635770060137089U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 123668445682719574U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 14462802805503986316U;
            aOrbiterA = RotL64((aOrbiterA * 12398236364304875941U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 2433338393261685871U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 13869012262404991729U;
            aOrbiterJ = RotL64((aOrbiterJ * 12443261517483942937U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 4832421585086516998U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 11284414949564414958U;
            aOrbiterG = RotL64((aOrbiterG * 1586650935440790991U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 17872556812561387030U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 7896237440058555694U;
            aOrbiterE = RotL64((aOrbiterE * 16784165278693056013U), 53U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 57U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 28U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterH, 23U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterF, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 44U)) + aOrbiterC);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 41U) + RotL64(aOrbiterF, 11U)) + aOrbiterE) + RotL64(aCarry, 57U)) + RotL64(aNonceWordF, 19U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterB, 23U)) + aOrbiterG) + aWandererUpdateSaltC[((aIndex + 24U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 60U) + aOrbiterF) + RotL64(aOrbiterJ, 5U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 43U) + aOrbiterK) + RotL64(aOrbiterE, 57U)) + aWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 23U) + RotL64(aOrbiterI, 35U)) + aOrbiterH);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 51U)) + aOrbiterG);
            aWandererI = aWandererI + (((RotL64(aCross, 27U) + RotL64(aOrbiterC, 37U)) + aOrbiterH) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 27U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aCross, 36U) + aOrbiterG) + RotL64(aOrbiterD, 13U)) + RotL64(aNonceWordG, 58U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterK, 46U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 46U));
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + RotL64(aWandererB, 60U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 3U) ^ RotL64(aNonceWordB, 24U)) ^ RotL64(aNonceWordG, 35U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 31930U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((aIndex + 24840U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 35U) ^ RotL64(aNonceWordF, 22U)) ^ RotL64(aNonceWordA, 3U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29709U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((aIndex + 27664U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 37U) ^ RotL64(aCross, 19U)) ^ (RotL64(aIngress, 51U) + RotL64(aCarry, 4U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (aWandererE + RotL64(aIngress, 3U)) + 2974056819475622600U;
            aOrbiterD = (((aWandererF + RotL64(aCross, 42U)) + RotL64(aCarry, 37U)) + 7345051759236356098U) + RotL64(aNonceWordA, 49U);
            aOrbiterC = (aWandererI + RotL64(aScatter, 27U)) + 12738468816846628882U;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 39U)) + 7694520596043297922U) + aOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = (aWandererA + RotL64(aScatter, 29U)) + 5530753590015084774U;
            aOrbiterF = (aWandererH + RotL64(aPrevious, 23U)) + 3776309161718383105U;
            aOrbiterG = (((aWandererJ + RotL64(aIngress, 13U)) + RotL64(aCarry, 13U)) + 784780304358106404U) + RotL64(aNonceWordD, 5U);
            aOrbiterK = (aWandererG + RotL64(aCross, 51U)) + 8999942326995036509U;
            aOrbiterE = ((aWandererC + RotL64(aScatter, 10U)) + RotL64(aCarry, 21U)) + 5194986506064092779U;
            aOrbiterI = (aWandererK + RotL64(aCross, 53U)) + 7920040007459652762U;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 37U)) + 11311997270710107937U) + aOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 5365231114813547251U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 8630110234623825263U;
            aOrbiterC = RotL64((aOrbiterC * 2735881715888325759U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 2358235238039571072U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 18059414891616491807U;
            aOrbiterB = RotL64((aOrbiterB * 17150786106857185467U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 14526050556461782864U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 6937282036603272474U) ^ aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14954512365270028029U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 10105832250694931310U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 3884223553012098137U;
            aOrbiterG = RotL64((aOrbiterG * 16340956813003906195U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 10385284339549648087U) + aOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = (((aOrbiterK ^ aOrbiterB) ^ 1257633893341505930U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]) ^ RotL64(aNonceWordC, 57U);
            aOrbiterK = RotL64((aOrbiterK * 2669950791270500977U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 5528890519572824318U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 15664241747527713256U;
            aOrbiterE = RotL64((aOrbiterE * 16670884497088220497U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 14264122979415331887U) + RotL64(aNonceWordB, 45U);
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 17985061405540198036U;
            aOrbiterI = RotL64((aOrbiterI * 2729487440173395133U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 1663986734997903415U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 3706166884286400587U) ^ aOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10549736618301955745U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 12736963182099961466U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 95411267612114381U;
            aOrbiterA = RotL64((aOrbiterA * 8011937916302325057U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 4966620136499917388U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 8478316876240452401U;
            aOrbiterD = RotL64((aOrbiterD * 13297718919105366563U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 11123814701411614557U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 2974056819475622600U;
            aOrbiterJ = RotL64((aOrbiterJ * 5913569942407618997U), 43U);
            //
            aIngress = RotL64(aOrbiterJ, 58U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + RotL64(aOrbiterB, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aPrevious, 23U) + aOrbiterD) + RotL64(aOrbiterK, 57U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 46U) + RotL64(aOrbiterF, 48U)) + aOrbiterJ);
            aWandererI = aWandererI + ((RotL64(aScatter, 37U) + aOrbiterD) + RotL64(aOrbiterG, 27U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 41U)) + aOrbiterB) + aWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterH, 43U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 40U) + RotL64(aOrbiterB, 5U)) + aOrbiterH);
            aWandererD = aWandererD + (((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 23U)) + aOrbiterA) + RotL64(aNonceWordF, 47U)) + aWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 51U) + RotL64(aOrbiterE, 39U)) + aOrbiterK) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 53U)) + aOrbiterC) + RotL64(aNonceWordE, 28U));
            aWandererE = aWandererE + ((RotL64(aIngress, 13U) + RotL64(aOrbiterI, 36U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + (RotL64(aWandererF, 6U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererK, 48U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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

void TwistExpander_Tennis_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xBF21B502D7F7BAA9ULL + 0x8A253B3589F383B1ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x8FA82A56EBBF2DA3ULL + 0xA64E111B56E07DEDULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xDEF92A54840C996DULL + 0xE3D4EEEA70E23D6EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x826811F7B58AF035ULL + 0xE0F5AB93AA112FCCULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x89C7D1B044DE9A29ULL + 0xB86AEC65D9309346ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xBE8D4257FC4E626DULL + 0xFA13FE85410C1318ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xAE942C73A391F8C9ULL + 0xD51E15CFDEBC6742ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE5223675537378E5ULL + 0x98B613B3A2D5BB5CULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 50U) ^ RotL64(aNonceWordD, 3U)) ^ RotL64(aNonceWordF, 19U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 2663U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((aIndex + 4319U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 39U) ^ RotL64(aNonceWordB, 12U)) ^ RotL64(aNonceWordA, 27U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 3202U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 215U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 27U) + RotL64(aCarry, 39U)) ^ (RotL64(aCross, 52U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (((aWandererD + RotL64(aPrevious, 56U)) + RotL64(aCarry, 47U)) + 1708250618750199233U) + aOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aScatter, 23U)) + RotL64(aCarry, 23U)) + 12009147777553691142U;
            aOrbiterE = (((aWandererI + RotL64(aIngress, 51U)) + RotL64(aCarry, 5U)) + 8393982703399156592U) + RotL64(aNonceWordA, 6U);
            aOrbiterJ = (aWandererB + RotL64(aCross, 19U)) + 3247327098356831221U;
            aOrbiterC = (aWandererH + RotL64(aPrevious, 43U)) + 3403590155376353737U;
            aOrbiterG = (aWandererC + RotL64(aCross, 6U)) + 18197244558104735044U;
            aOrbiterB = (aWandererG + RotL64(aIngress, 13U)) + 3096253642040701606U;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 47U)) + 8012692688785412179U) + aOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 27U)) + 17531946907545680745U) + RotL64(aNonceWordC, 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 17687695944270225817U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 16147773866007628769U;
            aOrbiterE = RotL64((aOrbiterE * 16926442582711557877U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 18244641303026196497U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 8839160526348897457U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14268021129087663397U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 10599266240854068246U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 2056723540756216155U;
            aOrbiterD = RotL64((aOrbiterD * 13311591601230386375U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 4629354220460621284U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterI) ^ 9505955649473204942U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]) ^ RotL64(aNonceWordB, 5U);
            aOrbiterA = RotL64((aOrbiterA * 17775391885312236187U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 17078153810088721310U) + aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 9470436761716263000U;
            aOrbiterF = RotL64((aOrbiterF * 5431855497250357229U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 3305863413630104742U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 14377172434239576161U;
            aOrbiterJ = RotL64((aOrbiterJ * 6880176890091033423U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 415687827894226513U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 16975319836893760993U;
            aOrbiterB = RotL64((aOrbiterB * 6597144958013976445U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 12707054129431596074U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 8974182792497231239U;
            aOrbiterI = RotL64((aOrbiterI * 7874658957269462717U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 10826131924322955095U) + RotL64(aNonceWordG, 35U);
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 4168545139712703154U;
            aOrbiterC = RotL64((aOrbiterC * 10305904857550051705U), 39U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterE, 57U);
            aIngress = aIngress + (RotL64(aOrbiterA, 30U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 41U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aIngress, 6U) + RotL64(aOrbiterF, 43U)) + aOrbiterG);
            aWandererG = aWandererG ^ ((RotL64(aCross, 51U) + aOrbiterG) + RotL64(aOrbiterI, 10U));
            aWandererA = aWandererA + (((RotL64(aScatter, 27U) + RotL64(aOrbiterB, 5U)) + aOrbiterJ) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 39U)) + aOrbiterD) + aWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 19U)) + aOrbiterB) + RotL64(aNonceWordD, 53U)) + aWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 12U) + aOrbiterE) + RotL64(aOrbiterC, 47U)) + RotL64(aNonceWordE, 37U));
            aWandererF = aWandererF + (((RotL64(aCross, 23U) + RotL64(aOrbiterA, 60U)) + aOrbiterJ) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 27U)) + aOrbiterJ);
            aWandererH = aWandererH + ((RotL64(aPrevious, 37U) + aOrbiterI) + RotL64(aOrbiterA, 23U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + (RotL64(aWandererC, 42U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 11U) ^ RotL64(aNonceWordC, 41U)) ^ RotL64(aNonceWordA, 51U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10472U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((aIndex + 9846U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 43U) ^ RotL64(aNonceWordG, 30U)) ^ RotL64(aNonceWordD, 21U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 10020U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((aIndex + 8293U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 37U) + RotL64(aIngress, 53U)) ^ (RotL64(aCross, 5U) ^ RotL64(aPrevious, 20U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererI + RotL64(aIngress, 51U)) + 8375305456876489425U;
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 19U)) + 16193562952772453047U;
            aOrbiterG = (aWandererK + RotL64(aScatter, 23U)) + 18088652458594816223U;
            aOrbiterI = (((aWandererD + RotL64(aCross, 36U)) + RotL64(aCarry, 11U)) + 767344788620249944U) + aOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = (((aWandererG + RotL64(aIngress, 41U)) + RotL64(aCarry, 19U)) + 7705194930396368752U) + aOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aCross, 11U)) + 3829736891311272834U;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 57U)) + 9881681671347640061U) + RotL64(aNonceWordF, 6U);
            aOrbiterE = ((aWandererB + RotL64(aScatter, 4U)) + RotL64(aCarry, 43U)) + 1721196560190164264U;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 27U)) + 3002652618388454213U) + RotL64(aNonceWordB, 21U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterB) + 9811621464004005202U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]) + RotL64(aNonceWordD, 13U);
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 5652598941069986530U;
            aOrbiterG = RotL64((aOrbiterG * 4797973356708091621U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 6250499348327316328U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 16025054277615264530U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16446892258704281903U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 13800298546867243172U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 12256104592865905782U) ^ aOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16983140179497142713U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 17817225416918329229U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 17738671327352776217U) ^ aOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 393488251327705063U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 6816031224188400541U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 16989563985059237014U;
            aOrbiterK = RotL64((aOrbiterK * 8677884225771717797U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 16891524847268207549U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 1833508573940405571U;
            aOrbiterC = RotL64((aOrbiterC * 9709196587703979539U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 12729999421507068973U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 6839758643521968957U;
            aOrbiterI = RotL64((aOrbiterI * 16350557395881283975U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 8524167125469267428U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 14741523560290472617U) ^ RotL64(aNonceWordH, 61U);
            aOrbiterD = RotL64((aOrbiterD * 4367850822282205897U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 10983798459868424892U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 5649250846622078964U;
            aOrbiterB = RotL64((aOrbiterB * 7149612714806023987U), 51U);
            //
            aIngress = RotL64(aOrbiterC, 47U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 50U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterE, 56U)) + RotL64(aNonceWordG, 15U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 20U) + aOrbiterB) + RotL64(aOrbiterE, 23U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterK, 27U)) + aOrbiterF) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 11U) + aOrbiterG) + RotL64(aOrbiterE, 47U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterI, 35U)) + aOrbiterB) + RotL64(aCarry, 35U)) + RotL64(aNonceWordA, 43U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 51U) + aOrbiterE) + RotL64(aOrbiterC, 13U)) + aWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 34U) + aOrbiterD) + RotL64(aOrbiterF, 41U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 57U) + aOrbiterA) + RotL64(aOrbiterC, 3U));
            aWandererA = aWandererA + (((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterK, 52U)) + aWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 58U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 51U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 47U) ^ RotL64(aNonceWordH, 35U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 11715U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 11087U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 57U) ^ RotL64(aNonceWordD, 21U)) ^ RotL64(aNonceWordB, 37U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 13993U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneC[((aIndex + 13104U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aPrevious, 5U)) ^ (RotL64(aCarry, 40U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (((aWandererE + RotL64(aIngress, 3U)) + RotL64(aCarry, 43U)) + 17936518874386450467U) + aOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 13U)) + RotL64(aCarry, 51U)) + 13722737841589910344U;
            aOrbiterA = (aWandererI + RotL64(aCross, 53U)) + 11774969167948715796U;
            aOrbiterG = (aWandererK + RotL64(aScatter, 30U)) + 3640101505680493777U;
            aOrbiterF = ((((aWandererD + RotL64(aCross, 41U)) + RotL64(aCarry, 11U)) + 1369495382725650822U) + aOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1]) + RotL64(aNonceWordE, 29U);
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 23U)) + 11827310354654653345U) + RotL64(aNonceWordG, 16U);
            aOrbiterD = (aWandererH + RotL64(aScatter, 57U)) + 186037671377175394U;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 36U)) + 11428829344234627340U;
            aOrbiterI = (aWandererJ + RotL64(aCross, 47U)) + 2275016369870029068U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 15471646673734798328U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 12172082573115640145U;
            aOrbiterA = RotL64((aOrbiterA * 9629417882787847753U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 6626736341348283154U) + aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 12220614992483863623U) ^ RotL64(aNonceWordA, 31U);
            aOrbiterC = RotL64((aOrbiterC * 8137086205714097487U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 13157102324253760215U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 4143587482368093601U;
            aOrbiterG = RotL64((aOrbiterG * 5060677690991506895U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 11007575246013796426U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 11721585930088637162U;
            aOrbiterB = RotL64((aOrbiterB * 15009627907125738519U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 5720789204450196217U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 3094696226821431648U) ^ RotL64(aNonceWordB, 23U);
            aOrbiterF = RotL64((aOrbiterF * 4412033981712165541U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 14675830108100986773U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 9444071495289719645U) ^ aOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10983136361953366557U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 5106753847015199956U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 7585421898593510010U;
            aOrbiterD = RotL64((aOrbiterD * 140996914192351011U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 11746948407655524690U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 16336323220286344483U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6590417628835864497U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 8030445186765781136U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 276034088015165891U;
            aOrbiterI = RotL64((aOrbiterI * 7626025612710225099U), 41U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 43U);
            aIngress = aIngress + (RotL64(aOrbiterE, 50U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + RotL64(aOrbiterC, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 4U) + aOrbiterA) + RotL64(aOrbiterC, 57U)) + RotL64(aNonceWordF, 5U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 47U) + RotL64(aOrbiterJ, 24U)) + aOrbiterF);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 47U)) + aOrbiterE);
            aWandererD = aWandererD + (((RotL64(aScatter, 37U) + RotL64(aOrbiterB, 5U)) + aOrbiterJ) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterD, 41U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterC, 19U)) + aOrbiterF) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterD, 53U)) + aOrbiterF) + RotL64(aNonceWordC, 53U));
            aWandererA = aWandererA + (((RotL64(aCross, 58U) + RotL64(aOrbiterG, 29U)) + aOrbiterE) + aWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterJ, 36U)) + aWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 60U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 47U) ^ RotL64(aNonceWordB, 29U)) ^ RotL64(aNonceWordF, 12U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 21365U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17833U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 14U) ^ RotL64(aNonceWordE, 47U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21673U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneD[((aIndex + 16966U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aIngress, 27U)) + (RotL64(aCross, 57U) ^ RotL64(aPrevious, 42U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 27U)) + 3621877681473089725U) + aOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aScatter, 48U)) + 4451752751536414717U;
            aOrbiterI = ((aWandererF + RotL64(aCross, 19U)) + RotL64(aCarry, 35U)) + 11371625415377772117U;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 23U)) + 6046792758881150619U) + RotL64(aNonceWordF, 18U);
            aOrbiterD = ((aWandererE + RotL64(aIngress, 13U)) + RotL64(aCarry, 5U)) + 8213166120394461682U;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 40U)) + RotL64(aCarry, 57U)) + 4343156661140422645U;
            aOrbiterA = (aWandererA + RotL64(aCross, 5U)) + 11105271483234947905U;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 57U)) + 348904609985341372U) + RotL64(aNonceWordD, 3U);
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 53U)) + 12924652822526858767U) + aOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 7461211697358520287U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 16551553555297890558U;
            aOrbiterI = RotL64((aOrbiterI * 16432952324635746293U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 11908056404140782995U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 9147367258259948715U;
            aOrbiterD = RotL64((aOrbiterD * 10777628928376261667U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 8876461054692728610U) + aOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = (((aOrbiterA ^ aOrbiterH) ^ 10546855952702525404U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]) ^ RotL64(aNonceWordG, 45U);
            aOrbiterA = RotL64((aOrbiterA * 10071104785895309677U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 4748636139110443794U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 783046909529525098U;
            aOrbiterJ = RotL64((aOrbiterJ * 8969157702460927215U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 16683965945838696665U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 12385412690177109575U;
            aOrbiterE = RotL64((aOrbiterE * 10795062772707143187U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 8210546822184469023U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 13146493623236979963U) ^ RotL64(aNonceWordH, 35U);
            aOrbiterH = RotL64((aOrbiterH * 13199947810161148155U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 13857628148804187115U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 7241297989337473475U;
            aOrbiterC = RotL64((aOrbiterC * 16223448508809614229U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 773904571213804946U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 7660676598236419707U;
            aOrbiterB = RotL64((aOrbiterB * 14467390638468925567U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 16822672435156055469U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 6514707119190640433U) ^ aOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7097496727567460535U), 13U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 57U);
            aIngress = aIngress + (RotL64(aOrbiterI, 24U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aScatter, 36U) + RotL64(aOrbiterF, 51U)) + aOrbiterA) + RotL64(aNonceWordB, 7U));
            aWandererB = aWandererB + (((RotL64(aCross, 47U) + RotL64(aOrbiterJ, 35U)) + aOrbiterH) + RotL64(aCarry, 23U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterF, 44U)) + aOrbiterH);
            aWandererD = aWandererD + ((((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 13U)) + aWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterH, 39U)) + aOrbiterC);
            aWandererE = aWandererE + (((RotL64(aCross, 41U) + RotL64(aOrbiterE, 5U)) + aOrbiterB) + aWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 21U) + aOrbiterA) + RotL64(aOrbiterB, 10U)) + RotL64(aNonceWordC, 9U));
            aWandererC = aWandererC + ((RotL64(aIngress, 30U) + RotL64(aOrbiterI, 57U)) + aOrbiterD);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterE, 21U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (RotL64(aWandererE, 6U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 57U) ^ RotL64(aNonceWordH, 29U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24506U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneA[((aIndex + 22810U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 53U) ^ RotL64(aNonceWordE, 37U)) ^ RotL64(aNonceWordA, 13U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25572U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23885U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 4U)) ^ (RotL64(aCross, 47U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererC + RotL64(aPrevious, 30U)) + 18191288703716505885U;
            aOrbiterH = ((aWandererB + RotL64(aIngress, 23U)) + RotL64(aCarry, 43U)) + 9824014524910417136U;
            aOrbiterI = (aWandererG + RotL64(aCross, 19U)) + 11953012029254917548U;
            aOrbiterK = (aWandererE + RotL64(aScatter, 39U)) + 6297568011027199089U;
            aOrbiterC = ((aWandererH + RotL64(aCross, 11U)) + RotL64(aCarry, 3U)) + 2576999400457367975U;
            aOrbiterB = (((aWandererA + RotL64(aScatter, 43U)) + RotL64(aCarry, 19U)) + 13176139160575558254U) + RotL64(aNonceWordH, 36U);
            aOrbiterA = (aWandererF + RotL64(aIngress, 47U)) + 9978408174563621810U;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 6U)) + 16765834875061607142U) + aOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = (((aWandererI + RotL64(aScatter, 53U)) + 16534507305459121344U) + aOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1]) + RotL64(aNonceWordG, 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 3114710944346151807U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 10240517868726718592U;
            aOrbiterI = RotL64((aOrbiterI * 4645691562915606463U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 10721450637990777883U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 16689590768796583952U;
            aOrbiterB = RotL64((aOrbiterB * 3046344179729901637U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 2427422768928450209U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 13495584061816457831U;
            aOrbiterF = RotL64((aOrbiterF * 6670984773768885119U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 7058636403765106682U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 9897341853944713767U) ^ RotL64(aNonceWordA, 35U);
            aOrbiterE = RotL64((aOrbiterE * 14286816859999869231U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 17749559755733386064U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 12515645083926326659U;
            aOrbiterG = RotL64((aOrbiterG * 6582878478865838245U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 2625692458813609962U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 10596240255026143019U) ^ RotL64(aNonceWordD, 43U);
            aOrbiterK = RotL64((aOrbiterK * 11605800195771080135U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 12374290338067865540U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 1507386663796330249U) ^ aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1210241080424446087U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 9288099549484146726U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 15159312464747000702U) ^ aOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 500055502081347757U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 14998608679505446229U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 17625038109437732009U;
            aOrbiterC = RotL64((aOrbiterC * 14785862243019841689U), 35U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 39U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 26U));
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 53U));
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 47U)) + aOrbiterB) + RotL64(aCarry, 57U)) + aWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 19U)) + aOrbiterC);
            aWandererI = aWandererI + (((((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterB, 34U)) + RotL64(aCarry, 29U)) + RotL64(aNonceWordC, 41U)) + aWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterF, 51U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((RotL64(aCross, 56U) + aOrbiterG) + RotL64(aOrbiterH, 43U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 57U)) + aOrbiterF) + RotL64(aNonceWordB, 23U));
            aWandererG = aWandererG + ((RotL64(aIngress, 19U) + aOrbiterK) + RotL64(aOrbiterB, 38U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 23U) + aOrbiterI) + RotL64(aOrbiterE, 5U));
            aWandererA = aWandererA + ((RotL64(aScatter, 60U) + aOrbiterB) + RotL64(aOrbiterG, 13U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 38U));
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererG, 41U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 56U) ^ RotL64(aNonceWordH, 37U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28668U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32706U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 19U) ^ RotL64(aNonceWordB, 57U)) ^ RotL64(aNonceWordE, 3U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30800U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31742U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aPrevious, 53U)) + (RotL64(aIngress, 4U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (((aWandererA + RotL64(aScatter, 23U)) + RotL64(aCarry, 51U)) + 12136097566601676613U) + aOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = (aWandererE + RotL64(aCross, 19U)) + 7969431322248040056U;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 39U)) + 10530676021510553889U;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 46U)) + 8740777303075445264U;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 35U)) + 13249434169895564739U) + RotL64(aNonceWordA, 21U);
            aOrbiterI = (aWandererH + RotL64(aCross, 53U)) + 15529577005925628472U;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 29U)) + 344627093687331562U) + aOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = (((aWandererF + RotL64(aIngress, 13U)) + RotL64(aCarry, 35U)) + 8824277416519988893U) + RotL64(aNonceWordF, 27U);
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 6U)) + RotL64(aCarry, 5U)) + 5636276438449709875U;
            //
            aOrbiterA = (((aOrbiterA + aOrbiterC) + 2079413361031851552U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]) + RotL64(aNonceWordB, 29U);
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 7807998179168655561U;
            aOrbiterE = RotL64((aOrbiterE * 961456853699784753U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 13589392896232029112U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 10733011474804473996U;
            aOrbiterG = RotL64((aOrbiterG * 361749145931578805U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 15934162328347805968U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 7573511217796245232U) ^ RotL64(aNonceWordG, 5U);
            aOrbiterF = RotL64((aOrbiterF * 10694563909931636155U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 4828475187337891975U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 13284974329890393113U;
            aOrbiterD = RotL64((aOrbiterD * 10831075817642374287U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 13173869918669643112U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 15841507674783398167U;
            aOrbiterB = RotL64((aOrbiterB * 15632933198136963277U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 14168272451055700516U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 11134471485501999898U;
            aOrbiterA = RotL64((aOrbiterA * 8019507184494591705U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 2611858916687822610U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 17863271539727513641U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4987884722174985677U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 8874401993454249066U) + aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 5131480593493950665U) ^ aOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8585874663602346121U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 9366563022381918996U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 7890729519928340296U;
            aOrbiterC = RotL64((aOrbiterC * 11428572374057899517U), 29U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterG, 42U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterD, 50U)) + aOrbiterC);
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 37U) + RotL64(aOrbiterC, 5U)) + aOrbiterA) + RotL64(aNonceWordD, 36U)) + aWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 43U) + RotL64(aOrbiterE, 29U)) + aOrbiterA);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 10U) + RotL64(aOrbiterI, 11U)) + aOrbiterB);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 23U) + aOrbiterF) + RotL64(aOrbiterJ, 43U)) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 29U) + aOrbiterJ) + RotL64(aOrbiterB, 19U));
            aWandererG = aWandererG + (((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterC, 23U)) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 18U) + aOrbiterA) + RotL64(aOrbiterG, 39U)) + aWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 47U) + RotL64(aOrbiterI, 34U)) + aOrbiterJ) + RotL64(aNonceWordE, 55U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + RotL64(aWandererC, 18U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_Tennis_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x80F6E3F2A5822EADULL + 0xA6F25019196C7586ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xCF0971F8F5C6A955ULL + 0xFF9EA651AF0371ABULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x9F38138A697715EFULL + 0xAE7A9C8371BE523DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x8401525A24F72375ULL + 0xE0E734A195C3215CULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xE824C293BFA43201ULL + 0xB2F879797DD4749BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xCC30DFA231189DF1ULL + 0xD3508EFA99ED0A39ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xBDC7CD91B1E9A1E5ULL + 0xCD96FB30C9306324ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xA54F2E031E0B4007ULL + 0xD63FF1526B1BAC33ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 35U) ^ RotL64(aNonceWordC, 4U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 5342U)) & S_BLOCK1], 27U) ^ RotL64(aKeyRowReadA[((aIndex + 5461U)) & W_KEY1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 27U) ^ RotL64(aNonceWordG, 37U));
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 1929U)) & W_KEY1], 47U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 3525U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCross, 22U)) ^ (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterJ = (aWandererA + RotL64(aIngress, 3U)) + 4384716820085860551U;
            aOrbiterE = ((aWandererD + RotL64(aCross, 51U)) + 9715780315942116888U) + aPhaseAOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aScatter, 13U)) + 15963520052789178632U;
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 35U)) + 14346700690686392938U) + RotL64(aNonceWordE, 31U);
            aOrbiterI = ((aWandererI + RotL64(aCross, 43U)) + RotL64(aCarry, 57U)) + 6005518012489966643U;
            aOrbiterC = ((((aWandererG + RotL64(aPrevious, 58U)) + RotL64(aCarry, 11U)) + 2506732930310252119U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1]) + RotL64(aNonceWordA, 9U);
            aOrbiterA = ((aWandererF + RotL64(aScatter, 19U)) + RotL64(aCarry, 27U)) + 16782163084851775826U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 823673076571076303U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 1634084509064077736U) ^ RotL64(aNonceWordF, 40U);
            aOrbiterD = RotL64((aOrbiterD * 1128407326773234517U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 1288134975466877686U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 2998220403162908444U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4321412662318298283U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 220430672180734911U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 10223923547068528867U;
            aOrbiterC = RotL64((aOrbiterC * 12577370238343872139U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 11696469696177647608U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 6545430420379636963U;
            aOrbiterA = RotL64((aOrbiterA * 8387163146257553773U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 79691451831797107U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 8971444023498649419U;
            aOrbiterJ = RotL64((aOrbiterJ * 7148919880477390009U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 5624403902454498793U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 9468064161002030997U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8243560528100864595U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 4619361544913629805U) + RotL64(aNonceWordH, 19U);
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 12682446273369750704U;
            aOrbiterE = RotL64((aOrbiterE * 10879074713156075641U), 51U);
            //
            aIngress = RotL64(aOrbiterC, 35U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 60U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 35U) + aOrbiterE) + RotL64(aOrbiterA, 60U)) + RotL64(aNonceWordD, 15U)) + aPhaseAWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 3U) + aOrbiterH) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterE, 41U)) + aOrbiterJ);
            aWandererD = aWandererD + ((((RotL64(aIngress, 51U) + RotL64(aOrbiterE, 47U)) + aOrbiterC) + RotL64(aNonceWordC, 45U)) + aPhaseAWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 10U) + aOrbiterC) + RotL64(aOrbiterH, 21U));
            aWandererG = aWandererG + (((RotL64(aCross, 27U) + aOrbiterC) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 21U) + aOrbiterE) + RotL64(aOrbiterI, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 42U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 53U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 19U) ^ RotL64(aNonceWordF, 46U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 7933U)) & S_BLOCK1], 35U) ^ RotL64(mSource[((aIndex + 6143U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 11U) ^ RotL64(aNonceWordA, 35U));
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 9153U)) & W_KEY1], 57U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 7359U)) & W_KEY1], 22U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 18U)) ^ (RotL64(aCross, 37U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterB = (((aWandererE + RotL64(aIngress, 11U)) + RotL64(aCarry, 29U)) + 6381335981879993247U) + RotL64(aNonceWordC, 59U);
            aOrbiterI = (aWandererF + RotL64(aCross, 43U)) + 15595429101600023172U;
            aOrbiterG = (aWandererD + RotL64(aPrevious, 3U)) + 5449234297249826461U;
            aOrbiterJ = ((((aWandererJ + RotL64(aScatter, 23U)) + RotL64(aCarry, 5U)) + 11213734849329731168U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1]) + RotL64(aNonceWordH, 14U);
            aOrbiterK = (((aWandererC + RotL64(aCross, 51U)) + RotL64(aCarry, 47U)) + 16438473952464514248U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aScatter, 35U)) + 7357872882115186976U;
            aOrbiterA = (aWandererK + RotL64(aIngress, 58U)) + 394402075160738643U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 11112941985410283532U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 14955125011182736212U;
            aOrbiterG = RotL64((aOrbiterG * 10711684773326395603U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 14770727009821304070U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 11286366598129204910U;
            aOrbiterB = RotL64((aOrbiterB * 15884310771003021989U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 7358400908565425780U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 15635109923749114761U;
            aOrbiterJ = RotL64((aOrbiterJ * 12415152149408700329U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 13826842523738623579U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 1072811298828325231U;
            aOrbiterI = RotL64((aOrbiterI * 9662800288646215083U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 4017334196009350776U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 8812213572751410831U;
            aOrbiterK = RotL64((aOrbiterK * 12744171921566782795U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 6723457786170634403U) + RotL64(aNonceWordD, 61U);
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 9785583533999417673U;
            aOrbiterE = RotL64((aOrbiterE * 7776915427605471097U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 10265132640322153964U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 8435670887514808087U) ^ RotL64(aNonceWordA, 37U);
            aOrbiterA = RotL64((aOrbiterA * 2706263045620662131U), 37U);
            //
            aIngress = RotL64(aOrbiterJ, 3U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterG, 5U)) + aPhaseAWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterG, 29U)) + aOrbiterE) + RotL64(aNonceWordF, 29U)) + aPhaseAWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 47U) + aOrbiterI) + RotL64(aOrbiterB, 46U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 54U) + RotL64(aOrbiterK, 11U)) + aOrbiterI) + RotL64(aNonceWordE, 45U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 29U) + aOrbiterE) + RotL64(aOrbiterI, 35U));
            aWandererD = aWandererD + (((RotL64(aCross, 23U) + aOrbiterA) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 56U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 53U) ^ RotL64(aNonceWordC, 21U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 11201U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15056U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 27U) ^ RotL64(aNonceWordA, 35U));
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15572U)) & W_KEY1], 57U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 13611U)) & W_KEY1], 14U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 54U) + RotL64(aCarry, 21U)) ^ (RotL64(aCross, 35U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterJ = (aWandererK + RotL64(aScatter, 13U)) + 4068921616130916949U;
            aOrbiterG = (((aWandererJ + RotL64(aCross, 41U)) + RotL64(aCarry, 51U)) + 12077715273915151726U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aPrevious, 57U)) + 16047546802670596833U;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 27U)) + 9690277462716999763U) + RotL64(aNonceWordH, 41U);
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 48U)) + RotL64(aCarry, 37U)) + 14484814700447992628U;
            aOrbiterH = (((aWandererI + RotL64(aIngress, 35U)) + RotL64(aCarry, 23U)) + 17089267243053958210U) + aPhaseAOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aCross, 21U)) + 9138746214446211147U) + RotL64(aNonceWordF, 59U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 10181001536979097045U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterJ) ^ 6657458969093373191U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]) ^ RotL64(aNonceWordB, 11U);
            aOrbiterK = RotL64((aOrbiterK * 4311019792293202747U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 7515983477876590988U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 3039935555863947600U;
            aOrbiterG = RotL64((aOrbiterG * 12511160550780270119U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 16209389224740851136U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterC) ^ 725253312098083182U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]) ^ RotL64(aNonceWordE, 54U);
            aOrbiterJ = RotL64((aOrbiterJ * 17535989492095522597U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 13307041115748941383U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 7159572004825238263U;
            aOrbiterI = RotL64((aOrbiterI * 4855009895002398449U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 12027236743251643820U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 8717826175991286553U;
            aOrbiterC = RotL64((aOrbiterC * 1175614802543098451U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 4769096034227659937U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 11201226563992939616U;
            aOrbiterH = RotL64((aOrbiterH * 15595355978388159931U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 17295978531215563256U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 11850923890626719833U;
            aOrbiterA = RotL64((aOrbiterA * 3854851059897397075U), 5U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterA, 29U);
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + RotL64(aOrbiterC, 44U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 56U)) + aOrbiterI) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 28U) + RotL64(aOrbiterI, 19U)) + aOrbiterK);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterC, 11U));
            aWandererD = aWandererD + (((RotL64(aScatter, 21U) + RotL64(aOrbiterC, 3U)) + aOrbiterJ) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 41U) + aOrbiterI) + RotL64(aOrbiterC, 35U));
            aWandererC = aWandererC + ((((RotL64(aCross, 13U) + RotL64(aOrbiterG, 43U)) + aOrbiterK) + RotL64(aCarry, 27U)) + RotL64(aNonceWordA, 57U));
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterJ, 29U)) + RotL64(aNonceWordG, 29U)) + aPhaseAWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 6U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 35U) ^ RotL64(aNonceWordE, 5U)) ^ RotL64(aNonceWordH, 23U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 20113U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17150U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 41U) ^ RotL64(aNonceWordF, 53U)) ^ RotL64(aNonceWordB, 11U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19082U)) & S_BLOCK1], 19U) ^ RotL64(mSource[((aIndex + 17345U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCarry, 18U)) + (RotL64(aCross, 35U) ^ RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterA = (aWandererA + RotL64(aScatter, 21U)) + 6342299552323486695U;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 35U)) + 12692748514781367538U) + RotL64(aNonceWordH, 45U);
            aOrbiterD = (aWandererH + RotL64(aIngress, 29U)) + 8202639945493229155U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 41U)) + 4439975701793231639U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aIngress, 11U)) + RotL64(aCarry, 53U)) + 16774235182859553759U;
            aOrbiterG = ((((aWandererJ + RotL64(aPrevious, 60U)) + RotL64(aCarry, 11U)) + 8764155413335405667U) + aPhaseAOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1]) + RotL64(aNonceWordD, 57U);
            aOrbiterK = ((aWandererI + RotL64(aScatter, 53U)) + RotL64(aCarry, 27U)) + 7167848811974967685U;
            //
            aOrbiterA = (((aOrbiterA + aOrbiterF) + 16768278912125334220U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]) + RotL64(aNonceWordG, 59U);
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 9090838954826296201U;
            aOrbiterD = RotL64((aOrbiterD * 5459329624017272077U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 7644075729758006298U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 17326182797908071215U) ^ RotL64(aNonceWordF, 54U);
            aOrbiterG = RotL64((aOrbiterG * 2408330168749256075U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 16158809721888137555U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 8029938783858263694U;
            aOrbiterF = RotL64((aOrbiterF * 12628072435324195483U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 8716553521415553404U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 7012599977009208840U;
            aOrbiterE = RotL64((aOrbiterE * 8775355876188948851U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 13250558696578541499U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 13705957059101025396U;
            aOrbiterA = RotL64((aOrbiterA * 16889495686487056367U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 2796775206291902461U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 13741676263512390669U;
            aOrbiterI = RotL64((aOrbiterI * 10455782033465595947U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 1691908360612389252U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 4114939415206031540U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2797401802892718297U), 29U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterD, 11U);
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterK, 22U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterA, 27U)) + RotL64(aNonceWordE, 27U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 6U) + aOrbiterF) + RotL64(aOrbiterI, 13U)) + aPhaseAWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 39U) + aOrbiterD) + RotL64(aOrbiterI, 19U)) + RotL64(aCarry, 51U)) + RotL64(aNonceWordC, 5U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterG, 51U));
            aWandererK = aWandererK + ((RotL64(aScatter, 23U) + RotL64(aOrbiterF, 3U)) + aOrbiterE);
            aWandererI = aWandererI ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterE, 57U)) + aOrbiterK);
            aWandererA = aWandererA + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 42U)) + aOrbiterG) + RotL64(aCarry, 37U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 38U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 26U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 43U) ^ RotL64(aNonceWordA, 29U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22248U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((aIndex + 25450U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 5U) ^ RotL64(aNonceWordH, 30U)) ^ RotL64(aNonceWordG, 41U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24266U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((aIndex + 25201U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 19U)) + (RotL64(aIngress, 37U) + RotL64(aCross, 54U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterB = (((aWandererB + RotL64(aPrevious, 51U)) + RotL64(aCarry, 53U)) + 3561491146322798260U) + aPhaseAOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aScatter, 43U)) + 7075025056181885339U;
            aOrbiterF = (aWandererH + RotL64(aCross, 35U)) + 9230910887904171613U;
            aOrbiterI = (((aWandererC + RotL64(aIngress, 23U)) + RotL64(aCarry, 23U)) + 4119781172609908917U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = (((aWandererF + RotL64(aScatter, 60U)) + RotL64(aCarry, 37U)) + 17155609083870983149U) + RotL64(aNonceWordH, 48U);
            aOrbiterG = (aWandererK + RotL64(aCross, 29U)) + 2423018561430181695U;
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 11U)) + 12957280305617615744U) + RotL64(aNonceWordC, 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 2461704174772065813U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 7907123257849391997U;
            aOrbiterF = RotL64((aOrbiterF * 9416171962847312179U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 7257868138318960007U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 16425903703085702285U;
            aOrbiterB = RotL64((aOrbiterB * 7996935869077231999U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 2990822664594079467U) + RotL64(aNonceWordD, 3U);
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 5654819006718953817U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4465096036756887801U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 12183676471235678779U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 15026286960542123922U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17199049329995315279U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 12169080607071830522U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 2906296852254787499U) ^ RotL64(aNonceWordB, 31U);
            aOrbiterH = RotL64((aOrbiterH * 6754514406846040163U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 3029858695410344584U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 14406410317495954566U;
            aOrbiterG = RotL64((aOrbiterG * 9663780721657983421U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 11048818178401163861U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 13622063920319445043U;
            aOrbiterA = RotL64((aOrbiterA * 2516025554421589857U), 13U);
            //
            aIngress = RotL64(aOrbiterI, 3U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterB, 57U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 46U)) + aOrbiterI);
            aWandererB = aWandererB + (((RotL64(aCross, 3U) + RotL64(aOrbiterF, 37U)) + aOrbiterG) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 12U) + aOrbiterK) + RotL64(aOrbiterG, 3U)) + RotL64(aNonceWordF, 23U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 51U) + aOrbiterI) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterK, 21U)) + aOrbiterB) + RotL64(aNonceWordE, 21U));
            aWandererA = aWandererA + (((RotL64(aCross, 23U) + aOrbiterA) + RotL64(aOrbiterB, 11U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (RotL64(aWandererJ, 54U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 51U) ^ RotL64(aNonceWordH, 3U)) ^ RotL64(aNonceWordB, 37U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27963U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((aIndex + 28668U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 19U) ^ RotL64(aNonceWordF, 5U)) ^ RotL64(aNonceWordE, 53U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28218U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 30414U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCarry, 5U)) ^ (RotL64(aCross, 43U) + RotL64(aPrevious, 24U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 41U)) + 11700815697312060726U) + RotL64(aNonceWordE, 57U);
            aOrbiterI = (aWandererF + RotL64(aCross, 29U)) + 11808423452327465441U;
            aOrbiterD = (((aWandererJ + RotL64(aIngress, 35U)) + RotL64(aCarry, 5U)) + 8670503858631730886U) + RotL64(aNonceWordA, 61U);
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 57U)) + RotL64(aCarry, 41U)) + 2400061067991988544U;
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 23U)) + RotL64(aCarry, 19U)) + 16163118178366229686U;
            aOrbiterC = ((aWandererE + RotL64(aCross, 12U)) + 3280178595904941068U) + aPhaseAOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = ((aWandererH + RotL64(aScatter, 3U)) + 3298683600817047727U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 16321624053445183574U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 6730229877611375225U;
            aOrbiterD = RotL64((aOrbiterD * 2022290495153519279U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 10162830636713641322U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 15646771327759599256U;
            aOrbiterA = RotL64((aOrbiterA * 15333053762177144775U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 14841751262270544102U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 9545541117228834895U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11529769874752969377U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 14676615635857599982U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = (((aOrbiterK ^ aOrbiterD) ^ 1231768638470558855U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1]) ^ RotL64(aNonceWordC, 51U);
            aOrbiterK = RotL64((aOrbiterK * 2716808508509014677U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 1945905595345404833U) + RotL64(aNonceWordH, 8U);
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 1406171421638586846U;
            aOrbiterG = RotL64((aOrbiterG * 4577864352425476233U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 1970292335806697198U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 12309719390375013297U;
            aOrbiterJ = RotL64((aOrbiterJ * 16540660957923687327U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 5352135521358954576U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 15465675376193501658U;
            aOrbiterI = RotL64((aOrbiterI * 16385761112921041387U), 3U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterG, 29U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterK, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 37U) + RotL64(aOrbiterG, 5U)) + aOrbiterC) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterG, 11U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterD, 51U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 11U) + aOrbiterG) + RotL64(aOrbiterD, 21U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 58U) + aOrbiterC) + RotL64(aOrbiterA, 34U)) + RotL64(aNonceWordB, 15U));
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 41U)) + aOrbiterD) + RotL64(aNonceWordG, 7U)) + aPhaseAWandererUpdateSaltE[((aIndex + 26U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterI, 57U)) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + (RotL64(aWandererE, 18U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + RotL64(aWandererJ, 39U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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

void TwistExpander_Tennis_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xF0D5AD43F3898BE5ULL + 0xD421170E95C35AFEULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xC46E556221AA9265ULL + 0xDC1145BF1AA785A5ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x87C064E0C4567639ULL + 0xFBB6B3C0FDE945FBULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE7167C35DD7AA9AFULL + 0xDF86251CEC921DE1ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xEA538BD02422AB0BULL + 0xABB03651C4F7A0D3ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xC221EC8B5849ED19ULL + 0xB8D84A06B0414E6FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xFC17C3E778A738F1ULL + 0xDA8ECD8F026C9EE6ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x80BE69DD3F6E3EB7ULL + 0xE9338336741427EAULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 46U) ^ RotL64(aNonceWordF, 3U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2101U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((aIndex + 5338U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 19U) ^ RotL64(aNonceWordH, 35U)) ^ RotL64(aNonceWordB, 46U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2524U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 4193U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 37U) + RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 18U) ^ RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterD = ((aWandererK + RotL64(aCross, 47U)) + 964165145848253292U) + RotL64(aNonceWordG, 49U);
            aOrbiterI = (((aWandererC + RotL64(aPrevious, 22U)) + RotL64(aCarry, 35U)) + 10645976767204934746U) + RotL64(aNonceWordD, 23U);
            aOrbiterE = ((aWandererB + RotL64(aScatter, 13U)) + RotL64(aCarry, 47U)) + 8241612229349212650U;
            aOrbiterG = (((aWandererF + RotL64(aIngress, 57U)) + RotL64(aCarry, 11U)) + 4159196033256913347U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 39U)) + 7194795864620233507U) + aPhaseBOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 7638928444536778384U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = (((aOrbiterE ^ aOrbiterD) ^ 11819105916503968109U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1]) ^ RotL64(aNonceWordC, 25U);
            aOrbiterE = RotL64((aOrbiterE * 9052440449038441625U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 18052213302858186237U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 8663575313970041570U;
            aOrbiterD = RotL64((aOrbiterD * 14131073322476609161U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 16644136720439299786U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 16930316530442679864U;
            aOrbiterG = RotL64((aOrbiterG * 2650922074098320859U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 16251107616988250593U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 7171986193609401665U;
            aOrbiterI = RotL64((aOrbiterI * 3543709971414550087U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 17885046834432626644U) + RotL64(aNonceWordA, 43U);
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 7757069274715713557U;
            aOrbiterF = RotL64((aOrbiterF * 15766885299397923879U), 11U);
            //
            aIngress = RotL64(aOrbiterI, 57U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + RotL64(aOrbiterD, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterI, 19U)) + aOrbiterG) + aPhaseBWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 13U) + aOrbiterG) + RotL64(aOrbiterD, 53U)) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 37U)) + aOrbiterE) + RotL64(aNonceWordH, 59U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterI, 27U)) + RotL64(aCarry, 29U)) + RotL64(aNonceWordB, 42U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 4U) + aOrbiterD) + RotL64(aOrbiterE, 4U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 18U) ^ RotL64(aNonceWordH, 47U)) ^ RotL64(aNonceWordA, 57U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 6052U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9164U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 27U) ^ RotL64(aNonceWordB, 51U)) ^ RotL64(aNonceWordE, 41U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9664U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneB[((aIndex + 7045U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCarry, 39U)) ^ (RotL64(aCross, 57U) + RotL64(aPrevious, 26U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterF = ((((aWandererF + RotL64(aScatter, 3U)) + RotL64(aCarry, 39U)) + 13924571355038625040U) + aPhaseBOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1]) + RotL64(aNonceWordB, 9U);
            aOrbiterE = (aWandererC + RotL64(aIngress, 21U)) + 16328300979357156658U;
            aOrbiterK = (((aWandererK + RotL64(aPrevious, 37U)) + RotL64(aCarry, 13U)) + 3947771961206012461U) + RotL64(aNonceWordG, 46U);
            aOrbiterH = ((aWandererA + RotL64(aCross, 58U)) + RotL64(aCarry, 51U)) + 15428284250569311285U;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 11U)) + 5777369485254032486U) + aPhaseBOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 16813320300717644673U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 16689933050200758251U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4832495563863469353U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 1856422419049390708U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterE) ^ 18214498743831925517U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1]) ^ RotL64(aNonceWordC, 27U);
            aOrbiterG = RotL64((aOrbiterG * 10744120577560529379U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 18278550878494094923U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 797712062039591797U;
            aOrbiterF = RotL64((aOrbiterF * 7212998747080137625U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 15854849439012341347U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 996882939768167773U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14936703950807908575U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 3005829974130671692U) + RotL64(aNonceWordE, 23U);
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 8793495343509953906U;
            aOrbiterH = RotL64((aOrbiterH * 14065479348374612031U), 53U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterF, 11U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 53U) + aOrbiterF) + RotL64(aOrbiterH, 57U)) + RotL64(aNonceWordH, 31U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 3U)) + aOrbiterE) + RotL64(aCarry, 35U)) + RotL64(aNonceWordD, 37U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 39U)) + aOrbiterG) + aPhaseBWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 4U) + RotL64(aOrbiterK, 20U)) + aOrbiterH) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 43U) + aOrbiterE) + RotL64(aOrbiterF, 11U)) + aPhaseBWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 51U) ^ RotL64(aNonceWordA, 23U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 11637U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11039U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 37U) ^ RotL64(aNonceWordB, 28U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12777U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((aIndex + 14163U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCross, 50U)) ^ (RotL64(aIngress, 37U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 53U)) + RotL64(aCarry, 51U)) + 1866656689936219099U;
            aOrbiterH = (((aWandererA + RotL64(aPrevious, 5U)) + 2312314528139448289U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1]) + RotL64(aNonceWordG, 41U);
            aOrbiterK = ((aWandererE + RotL64(aCross, 42U)) + 3554037526469185237U) + aPhaseBOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = (((aWandererC + RotL64(aScatter, 29U)) + RotL64(aCarry, 11U)) + 405707755060974111U) + RotL64(aNonceWordH, 23U);
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 21U)) + RotL64(aCarry, 23U)) + 1862976326004007697U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 12992483065443288263U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 3793854946371595197U) ^ RotL64(aNonceWordE, 53U);
            aOrbiterK = RotL64((aOrbiterK * 1819119223110966487U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 4244007978867369382U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 10280867500312580308U;
            aOrbiterH = RotL64((aOrbiterH * 13729899124177931289U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 472563452959164242U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 12041770406895816553U) ^ RotL64(aNonceWordD, 46U);
            aOrbiterJ = RotL64((aOrbiterJ * 17811798500132002631U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 6118634015704900486U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 13637107920449233307U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17712028184714868053U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 16673735670669318830U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 8602681273646630496U;
            aOrbiterD = RotL64((aOrbiterD * 6995213887710749241U), 29U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 3U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + RotL64(aOrbiterD, 18U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterD, 56U)) + aOrbiterC);
            aWandererE = aWandererE + (((((RotL64(aPrevious, 43U) + aOrbiterK) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 27U)) + RotL64(aNonceWordC, 13U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterJ, 27U)) + aPhaseBWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 51U) + RotL64(aOrbiterH, 13U)) + aOrbiterK) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 22U) + RotL64(aOrbiterJ, 47U)) + aOrbiterH) + RotL64(aNonceWordB, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 5U) ^ RotL64(aNonceWordE, 58U)) ^ RotL64(aNonceWordA, 43U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 19117U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((aIndex + 21400U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 44U) ^ RotL64(aNonceWordH, 27U)) ^ RotL64(aNonceWordD, 53U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19371U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19697U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 37U) + RotL64(aIngress, 19U)) + (RotL64(aCross, 51U) ^ RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterI = ((aWandererE + RotL64(aIngress, 11U)) + 7825479804710770560U) + RotL64(aNonceWordG, 7U);
            aOrbiterB = ((aWandererK + RotL64(aScatter, 52U)) + RotL64(aCarry, 5U)) + 5298124167101358123U;
            aOrbiterK = (((aWandererJ + RotL64(aCross, 21U)) + RotL64(aCarry, 21U)) + 17774541024369233726U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = (aWandererD + RotL64(aPrevious, 35U)) + 7679371833537454082U;
            aOrbiterA = ((((aWandererF + RotL64(aIngress, 43U)) + RotL64(aCarry, 35U)) + 5385914900748772224U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1]) + RotL64(aNonceWordC, 49U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 3879781930908486531U) + RotL64(aNonceWordA, 60U);
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 659110346638873236U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17439162088869824407U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 10749021728538539749U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 3631252455767429457U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8552825360915119613U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 2271978810960685021U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 5963558780692551176U;
            aOrbiterE = RotL64((aOrbiterE * 4772055335210781149U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 974909966119198104U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 9296998242911152296U) ^ RotL64(aNonceWordD, 43U);
            aOrbiterB = RotL64((aOrbiterB * 2613629915877957661U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 2245318466901521959U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 13391076374843288568U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 18094558036982107419U), 11U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 29U);
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 23U)) + RotL64(aNonceWordH, 61U)) + aPhaseBWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 39U)) + aOrbiterB);
            aWandererF = aWandererF + (((RotL64(aPrevious, 39U) + aOrbiterK) + RotL64(aOrbiterE, 22U)) + aPhaseBWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 3U) + aOrbiterE) + RotL64(aOrbiterI, 5U)) + RotL64(aNonceWordB, 39U));
            aWandererE = aWandererE + (((RotL64(aIngress, 50U) + RotL64(aOrbiterE, 13U)) + aOrbiterA) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + RotL64(aWandererK, 48U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 11U) ^ RotL64(aNonceWordD, 3U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 23646U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((aIndex + 25614U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 43U) ^ RotL64(aNonceWordB, 24U)) ^ RotL64(aNonceWordG, 3U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26179U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((aIndex + 23261U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 5U)) + (RotL64(aIngress, 50U) + RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterD = (((aWandererI + RotL64(aPrevious, 43U)) + RotL64(aCarry, 51U)) + 13880995121909552664U) + aPhaseBOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (((aWandererB + RotL64(aIngress, 5U)) + 14534942818069300546U) + aPhaseBOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1]) + RotL64(aNonceWordA, 6U);
            aOrbiterI = (aWandererJ + RotL64(aCross, 35U)) + 17745973100886007133U;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 13U)) + RotL64(aCarry, 5U)) + 2249805580771946872U;
            aOrbiterC = (((aWandererA + RotL64(aCross, 60U)) + RotL64(aCarry, 37U)) + 4460116116396439410U) + RotL64(aNonceWordB, 7U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 3378683994078106878U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 3992996501048809123U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13273544260537223797U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 12057768808864451929U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 4115362079047921130U;
            aOrbiterC = RotL64((aOrbiterC * 12263015903331031345U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 15297384955502206698U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 17623548383481905636U;
            aOrbiterD = RotL64((aOrbiterD * 7487278217901483685U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 3559213898000162417U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterI) ^ 12311605719074507335U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1]) ^ RotL64(aNonceWordH, 11U);
            aOrbiterG = RotL64((aOrbiterG * 3982199462062847697U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 14807313864347885885U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 11222085523291581822U) ^ RotL64(aNonceWordC, 57U);
            aOrbiterH = RotL64((aOrbiterH * 12580941911587215653U), 39U);
            //
            aIngress = RotL64(aOrbiterH, 35U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterI, 58U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 11U) + aOrbiterC) + RotL64(aOrbiterD, 3U));
            aWandererI = aWandererI + (((RotL64(aIngress, 39U) + aOrbiterG) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 48U) + aOrbiterI) + RotL64(aOrbiterC, 48U)) + RotL64(aNonceWordE, 25U)) + aPhaseBWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 29U) + RotL64(aOrbiterI, 39U)) + aOrbiterH) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 21U) + aOrbiterG) + RotL64(aOrbiterC, 57U)) + RotL64(aNonceWordF, 37U)) + aPhaseBWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 53U) ^ RotL64(aNonceWordD, 39U)) ^ RotL64(aNonceWordB, 5U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 30537U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30414U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 35U) ^ RotL64(aNonceWordC, 10U)) ^ RotL64(aNonceWordE, 27U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31269U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 30676U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 56U) + RotL64(aIngress, 39U)) ^ (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterC = (((aWandererK + RotL64(aScatter, 29U)) + 8975885703279267062U) + aPhaseBOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1]) + RotL64(aNonceWordC, 56U);
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 18U)) + RotL64(aCarry, 41U)) + 8664844915562660637U;
            aOrbiterK = ((((aWandererF + RotL64(aCross, 43U)) + RotL64(aCarry, 3U)) + 12281774799736296726U) + aPhaseBOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1]) + RotL64(aNonceWordH, 7U);
            aOrbiterE = ((aWandererD + RotL64(aIngress, 57U)) + RotL64(aCarry, 19U)) + 15347461352311329726U;
            aOrbiterF = (aWandererA + RotL64(aScatter, 5U)) + 12967500561828907834U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 5002833859280402726U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 11908257536954668983U;
            aOrbiterK = RotL64((aOrbiterK * 4384790916151202785U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 17017174811949227162U) + RotL64(aNonceWordB, 9U);
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterE) ^ 16851323125613931180U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]) ^ RotL64(aNonceWordA, 61U);
            aOrbiterJ = RotL64((aOrbiterJ * 12446990992858763577U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 13469326957728686706U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 5228638551056105241U;
            aOrbiterC = RotL64((aOrbiterC * 13369947664646167255U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 11945166198089308564U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 16268645041872996022U;
            aOrbiterE = RotL64((aOrbiterE * 5391448793718370911U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 14781204627695095701U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 5365325354838101092U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8017284997946310807U), 11U);
            //
            aIngress = RotL64(aOrbiterF, 41U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + RotL64(aOrbiterJ, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterC, 5U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 13U) + aOrbiterJ) + RotL64(aOrbiterF, 51U));
            aWandererD = aWandererD + ((((RotL64(aCross, 43U) + RotL64(aOrbiterE, 39U)) + aOrbiterK) + RotL64(aCarry, 11U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 35U) + aOrbiterF) + RotL64(aOrbiterK, 60U)) + RotL64(aNonceWordF, 31U));
            aWandererF = aWandererF + (((((RotL64(aIngress, 26U) + RotL64(aOrbiterJ, 29U)) + aOrbiterE) + RotL64(aCarry, 51U)) + RotL64(aNonceWordG, 43U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererD, 41U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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

void TwistExpander_Tennis_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xEA12BA4DC37094CFULL + 0xBDF14004F7727197ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xE324671B36A5BABBULL + 0xE74A0265128C852AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xAF0E64B3602B0761ULL + 0xC55F1E5C82300B0BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xAEE33B88288706E1ULL + 0xAE1D737850EFE54AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x8BD8FFE7291805E5ULL + 0x8254086B39E63C1DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xACEB0A6A0A72949BULL + 0xD30FD0C8730A8CC3ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xD98B84B8151E3EE1ULL + 0xBF5336EADC485B2AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xD8B9366AD733BFA9ULL + 0xAFFE6E26A3B2BBC9ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 29U) ^ RotL64(aNonceWordF, 42U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 4532U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4942U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 14U) ^ RotL64(aNonceWordH, 3U)) ^ RotL64(aNonceWordC, 57U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 3763U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneA[((aIndex + 3185U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 57U)) + (RotL64(aIngress, 5U) + RotL64(aCross, 44U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterA = (aWandererE + RotL64(aPrevious, 29U)) + 7825479804710770560U;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 42U)) + 5298124167101358123U) + RotL64(aNonceWordF, 35U);
            aOrbiterK = ((aWandererI + RotL64(aCross, 23U)) + RotL64(aCarry, 29U)) + 17774541024369233726U;
            aOrbiterC = (((aWandererA + RotL64(aScatter, 53U)) + RotL64(aCarry, 47U)) + 7679371833537454082U) + RotL64(aNonceWordC, 5U);
            aOrbiterE = ((aWandererD + RotL64(aIngress, 57U)) + 5385914900748772224U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 46U)) + 3879781930908486531U;
            aOrbiterH = (aWandererK + RotL64(aCross, 5U)) + 659110346638873236U;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 13U)) + 10749021728538539749U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aIngress, 19U)) + RotL64(aCarry, 3U)) + 3631252455767429457U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 2271978810960685021U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 5963558780692551176U;
            aOrbiterK = RotL64((aOrbiterK * 4772055335210781149U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 974909966119198104U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 9296998242911152296U;
            aOrbiterJ = RotL64((aOrbiterJ * 2613629915877957661U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 2245318466901521959U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 13391076374843288568U;
            aOrbiterI = RotL64((aOrbiterI * 18094558036982107419U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 6184487746594236737U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 1563385912137291418U;
            aOrbiterF = RotL64((aOrbiterF * 4805455299959232321U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 1744840092006498629U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 2100927276837188416U;
            aOrbiterA = RotL64((aOrbiterA * 3541788262067077997U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 9998911862807246338U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 12239948725635220096U) ^ RotL64(aNonceWordE, 7U);
            aOrbiterC = RotL64((aOrbiterC * 7098620484129489129U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 3307447094994950246U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 12746613971448298932U) ^ RotL64(aNonceWordD, 23U);
            aOrbiterH = RotL64((aOrbiterH * 9463975886346934681U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 11577488293733790649U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 191108997585598809U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9574978681405356871U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 18096145693841273722U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 10026281133603934071U;
            aOrbiterE = RotL64((aOrbiterE * 17261343107314203471U), 3U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 30U);
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterJ, 37U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterI, 57U)) + RotL64(aNonceWordA, 11U));
            aWandererK = aWandererK + ((RotL64(aIngress, 20U) + RotL64(aOrbiterA, 27U)) + aOrbiterF);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 35U)) + aOrbiterI);
            aWandererI = aWandererI + (((RotL64(aCross, 13U) + aOrbiterJ) + RotL64(aOrbiterC, 42U)) + RotL64(aCarry, 21U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterE, 21U));
            aWandererC = aWandererC + ((RotL64(aIngress, 41U) + aOrbiterJ) + RotL64(aOrbiterD, 5U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 53U) + aOrbiterK) + RotL64(aOrbiterJ, 11U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 28U) + aOrbiterA) + RotL64(aOrbiterI, 46U)) + RotL64(aCarry, 51U)) + aPhaseCWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterJ, 53U)) + RotL64(aNonceWordG, 48U)) + aPhaseCWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 52U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 6U) ^ RotL64(aNonceWordC, 27U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 15036U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneD[((aIndex + 16112U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 42U) ^ RotL64(aNonceWordB, 27U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 16168U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 13645U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCross, 19U)) ^ (RotL64(aIngress, 3U) + RotL64(aCarry, 48U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterH = ((aWandererC + RotL64(aScatter, 21U)) + 11274974230580265396U) + RotL64(aNonceWordF, 15U);
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 60U)) + RotL64(aCarry, 5U)) + 16658438747342741547U;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 3U)) + RotL64(aCarry, 57U)) + 16612986966106053844U;
            aOrbiterF = (aWandererK + RotL64(aCross, 39U)) + 9329502236843231290U;
            aOrbiterC = (aWandererE + RotL64(aScatter, 51U)) + 14088261356708344656U;
            aOrbiterB = (aWandererH + RotL64(aCross, 35U)) + 13692608802007789581U;
            aOrbiterD = (((aWandererF + RotL64(aIngress, 56U)) + 6824473946645682398U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1]) + RotL64(aNonceWordG, 58U);
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 11U)) + 2072915876348570040U;
            aOrbiterI = (((aWandererD + RotL64(aCross, 47U)) + RotL64(aCarry, 21U)) + 7420507753044460759U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 4677557318688502593U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 15081678577055628459U;
            aOrbiterJ = RotL64((aOrbiterJ * 16659305295251177155U), 23U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterJ) + 7026792817486507482U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]) + RotL64(aNonceWordE, 53U);
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 14871665922943969918U;
            aOrbiterC = RotL64((aOrbiterC * 694073180313083145U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 6807734532159292872U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 17882797335141303280U;
            aOrbiterD = RotL64((aOrbiterD * 15439872930381050291U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 9233542707022629190U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 1205501586581350876U;
            aOrbiterG = RotL64((aOrbiterG * 2596053290311090589U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 10878718669747466677U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 8066049063548639241U;
            aOrbiterI = RotL64((aOrbiterI * 3031382633089381605U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 861295180226875235U) + RotL64(aNonceWordA, 57U);
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 9134969787937288583U;
            aOrbiterH = RotL64((aOrbiterH * 7565008208670843555U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 6726642007159809594U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 8061661744643240470U;
            aOrbiterF = RotL64((aOrbiterF * 6703498926835391813U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 13541412083111962884U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 8617442758729315637U;
            aOrbiterB = RotL64((aOrbiterB * 15471862889276160953U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 16884403561131293362U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 9490680911678221233U;
            aOrbiterE = RotL64((aOrbiterE * 15988763830018001033U), 39U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 29U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 34U));
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterD, 39U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 38U) + RotL64(aOrbiterE, 48U)) + aOrbiterC) + aPhaseCWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterB, 19U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 47U) + aOrbiterH) + RotL64(aOrbiterC, 11U)) + aPhaseCWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 3U)) + aOrbiterB);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 29U)) + aOrbiterH) + RotL64(aNonceWordD, 39U));
            aWandererD = aWandererD + (((RotL64(aScatter, 58U) + RotL64(aOrbiterC, 43U)) + aOrbiterF) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 37U)) + aOrbiterH);
            aWandererB = aWandererB + ((((RotL64(aCross, 51U) + aOrbiterG) + RotL64(aOrbiterD, 56U)) + RotL64(aCarry, 35U)) + RotL64(aNonceWordB, 43U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 23U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererG, 26U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + RotL64(aWandererF, 37U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 51U) ^ RotL64(aNonceWordF, 23U)) ^ RotL64(aNonceWordC, 14U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 18813U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18089U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 51U) ^ RotL64(aNonceWordG, 37U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 17889U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneC[((aIndex + 20479U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 14U)) + (RotL64(aIngress, 29U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterE = ((aWandererC + RotL64(aScatter, 6U)) + RotL64(aCarry, 29U)) + 7948891781097675369U;
            aOrbiterC = (aWandererI + RotL64(aCross, 51U)) + 13928362874228230226U;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 21U)) + 10776180542602258926U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = ((aWandererD + RotL64(aIngress, 43U)) + 5735115172149470447U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 28U)) + 5353591822981766987U) + RotL64(aNonceWordB, 31U);
            aOrbiterH = (((aWandererE + RotL64(aCross, 13U)) + RotL64(aCarry, 47U)) + 562301708107268570U) + RotL64(aNonceWordE, 21U);
            aOrbiterF = (aWandererH + RotL64(aScatter, 37U)) + 10467810247578364868U;
            aOrbiterG = (aWandererA + RotL64(aIngress, 47U)) + 14541630141152308564U;
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 57U)) + RotL64(aCarry, 3U)) + 2350076897065139429U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 17519109078651162228U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 6061035173339902910U;
            aOrbiterJ = RotL64((aOrbiterJ * 10021905773432907835U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 15654836633731000065U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 13723521735153718904U;
            aOrbiterE = RotL64((aOrbiterE * 14459516479283070563U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 2849680038315532197U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 17336102435576647923U) ^ RotL64(aNonceWordG, 19U);
            aOrbiterK = RotL64((aOrbiterK * 10984689101753586739U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 7671010488872356142U) + RotL64(aNonceWordA, 49U);
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 11485114338165600777U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4162584865462407791U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 8759060657343458985U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 11009137869375286581U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8741417343929809115U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 15792999392743144135U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 6180808423175992479U;
            aOrbiterH = RotL64((aOrbiterH * 13681230339693676907U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 361487389591183005U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 15292753806514404853U;
            aOrbiterF = RotL64((aOrbiterF * 17478232597253311153U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 14929153438443362045U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 7904556383593914086U;
            aOrbiterG = RotL64((aOrbiterG * 2484130486635511403U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 3793180909904286848U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 10391957637467171320U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 505484041943467117U), 47U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterA, 56U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 39U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterE, 28U)) + aOrbiterK);
            aWandererE = aWandererE + (((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 58U) + aOrbiterG) + RotL64(aOrbiterH, 53U)) + RotL64(aNonceWordD, 18U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 23U) + aOrbiterG) + RotL64(aOrbiterK, 35U));
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 57U)) + aOrbiterF) + RotL64(aNonceWordH, 43U)) + aPhaseCWandererUpdateSaltD[((aIndex + 20U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 11U)) + aOrbiterI);
            aWandererK = aWandererK ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterC, 19U)) + aOrbiterH);
            aWandererG = aWandererG + (((RotL64(aIngress, 6U) + aOrbiterF) + RotL64(aOrbiterC, 46U)) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterI, 39U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererH, 54U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererJ, 51U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 27U) ^ RotL64(aNonceWordB, 19U)) ^ RotL64(aNonceWordD, 5U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 31009U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24939U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 11U) ^ RotL64(aNonceWordC, 3U)) ^ RotL64(aNonceWordG, 27U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28831U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneD[((aIndex + 30356U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCross, 52U)) + (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterE = (aWandererD + RotL64(aScatter, 29U)) + 4204560462077827182U;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 23U)) + 6572370199668594039U) + RotL64(aNonceWordH, 47U);
            aOrbiterA = ((aWandererI + RotL64(aIngress, 13U)) + 15958999876732622825U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = (((aWandererA + RotL64(aCross, 19U)) + RotL64(aCarry, 43U)) + 9969349486879280377U) + RotL64(aNonceWordB, 4U);
            aOrbiterF = ((aWandererF + RotL64(aIngress, 46U)) + 15450238998293956181U) + aPhaseCOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aCross, 51U)) + 9128619863683138259U;
            aOrbiterI = (aWandererC + RotL64(aScatter, 35U)) + 5691270563628979565U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 3U)) + RotL64(aCarry, 51U)) + 5901029710568933106U;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 40U)) + RotL64(aCarry, 35U)) + 10442738941988588834U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 3508116020325721993U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 13221917083569767259U;
            aOrbiterA = RotL64((aOrbiterA * 6845108555710135357U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 11627915460377128176U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 17858261365514253433U;
            aOrbiterF = RotL64((aOrbiterF * 7535577636975884641U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 4294837988806295989U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 11242915481585070249U) ^ RotL64(aNonceWordA, 55U);
            aOrbiterI = RotL64((aOrbiterI * 17540688242763829319U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 13030663829236027109U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 7451948220723185149U;
            aOrbiterE = RotL64((aOrbiterE * 5191778587712222029U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 5575508866505031037U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 5161096033789876794U;
            aOrbiterJ = RotL64((aOrbiterJ * 16843827915802461797U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 3980482740649505122U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 11188906150207270241U;
            aOrbiterC = RotL64((aOrbiterC * 408550837615188413U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 4435504916461645189U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 9970252853543702833U;
            aOrbiterK = RotL64((aOrbiterK * 5829143716916091997U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 3766347619186305854U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 11004616087340082895U;
            aOrbiterG = RotL64((aOrbiterG * 14469267845747063735U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 17600791542296175812U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterI) ^ 2556224430252009744U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]) ^ RotL64(aNonceWordC, 7U);
            aOrbiterH = RotL64((aOrbiterH * 14469426539907112137U), 51U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterC, 51U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + RotL64(aOrbiterG, 20U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterK, 3U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 36U) + aOrbiterF) + RotL64(aOrbiterI, 43U)) + aPhaseCWandererUpdateSaltA[((aIndex + 12U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 29U) + RotL64(aOrbiterC, 51U)) + aOrbiterE) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterC, 29U)) + aOrbiterI);
            aWandererF = aWandererF + (((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 24U)) + aOrbiterE) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 56U) + RotL64(aOrbiterH, 57U)) + aOrbiterE);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 35U)) + RotL64(aNonceWordF, 17U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 23U) + aOrbiterE) + RotL64(aOrbiterA, 19U));
            aWandererI = aWandererI + (((RotL64(aCross, 47U) + RotL64(aOrbiterJ, 36U)) + aOrbiterC) + RotL64(aNonceWordG, 39U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 6U));
            aCarry = aCarry + RotL64(aWandererK, 19U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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

void TwistExpander_Tennis_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xDA307FCAF7A588A3ULL + 0xA3CFC00E1A39172BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xE12352D36B4EDA25ULL + 0x925495F431AE993CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xB5F43F5A8329FA19ULL + 0xE2A42CF3657C30E8ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xAD3D812482C308F3ULL + 0xD0AC45B362BDF56DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xC514AEF268E6DD23ULL + 0x90A0AFDB133C91B3ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x9A8BB7A9CE5FFAB9ULL + 0xEDD223209142A69CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xCE494478F66B283FULL + 0xF0764126786090BFULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x9C97B3DB61C1C903ULL + 0xA498C83B03F0AAEFULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 13U) ^ RotL64(aNonceWordD, 53U)) ^ RotL64(aNonceWordB, 4U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4160U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneC[((aIndex + 5398U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 14U) ^ RotL64(aNonceWordE, 37U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3038U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 4654U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 52U) ^ RotL64(aIngress, 23U)) ^ (RotL64(aCross, 11U) + RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterC = ((aWandererH + RotL64(aIngress, 11U)) + 5568146815535263910U) + RotL64(aNonceWordE, 5U);
            aOrbiterI = (((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 21U)) + 7736084960873834666U) + RotL64(aNonceWordA, 6U);
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 50U)) + 1336413621817562093U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = ((aWandererI + RotL64(aScatter, 5U)) + RotL64(aCarry, 35U)) + 5218462026934984692U;
            aOrbiterB = (aWandererJ + RotL64(aCross, 19U)) + 7048890985969555935U;
            aOrbiterA = (((aWandererF + RotL64(aPrevious, 39U)) + RotL64(aCarry, 3U)) + 13415955213864702118U) + aPhaseDOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = (aWandererE + RotL64(aIngress, 46U)) + 5657023257021528548U;
            aOrbiterG = (aWandererA + RotL64(aScatter, 23U)) + 14338310943137497116U;
            aOrbiterE = (aWandererG + RotL64(aCross, 3U)) + 12305161641833950473U;
            aOrbiterK = (aWandererD + RotL64(aIngress, 27U)) + 14514226578370459131U;
            aOrbiterF = (aWandererC + RotL64(aScatter, 13U)) + 12692904083266024340U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 11012959130001327964U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 7106471380403489078U;
            aOrbiterD = RotL64((aOrbiterD * 515626559384817223U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 3718101961355280891U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 13364192077222322664U) ^ RotL64(aNonceWordG, 49U);
            aOrbiterA = RotL64((aOrbiterA * 1411328915372590283U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 6720867800318913440U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 14497243926965866546U;
            aOrbiterC = RotL64((aOrbiterC * 13595058589060114653U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 5789056168233262435U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 14438482587495779937U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10593535547917767263U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 313917798940179945U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 15241845511889502917U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16483477103771326107U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 3591957424821693032U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 1559050939014453558U;
            aOrbiterE = RotL64((aOrbiterE * 17933346117866604725U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 15340590914441451383U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 5538037287390050110U;
            aOrbiterF = RotL64((aOrbiterF * 4082576643144951473U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 4151270491894969214U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 263593701314144898U;
            aOrbiterI = RotL64((aOrbiterI * 10372046955804512457U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 9025145270653080646U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 6867950904094870056U;
            aOrbiterB = RotL64((aOrbiterB * 9975247022340627751U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 3183454301841252109U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 3054904157641290615U;
            aOrbiterG = RotL64((aOrbiterG * 4092317552439599475U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 1768555574434776135U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 5568146815535263910U) ^ RotL64(aNonceWordF, 41U);
            aOrbiterK = RotL64((aOrbiterK * 12466957001078663927U), 47U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 27U);
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 37U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 44U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterK, 13U)) + RotL64(aNonceWordC, 35U));
            aWandererA = aWandererA + ((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterK, 21U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 14U) + aOrbiterB) + RotL64(aOrbiterE, 37U)) + aPhaseDWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterJ, 6U)) + RotL64(aNonceWordD, 13U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterG, 47U)) + aOrbiterA);
            aWandererH = aWandererH + ((((RotL64(aCross, 37U) + aOrbiterC) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 37U)) + aPhaseDWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterJ, 39U));
            aWandererE = aWandererE + (((RotL64(aScatter, 34U) + aOrbiterH) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterA, 60U)) + aOrbiterH);
            aWandererF = aWandererF + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterA, 51U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterC, 57U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 18U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + RotL64(aWandererD, 27U);
            aCarry = aCarry + RotL64(aIngress, 14U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 35U) ^ RotL64(aNonceWordG, 27U)) ^ RotL64(aNonceWordA, 13U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 7099U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((aIndex + 10652U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 6U) ^ RotL64(aNonceWordF, 51U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5770U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9140U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 23U)) + (RotL64(aCross, 40U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterE = (aWandererI + RotL64(aScatter, 60U)) + 13880995121909552664U;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 5U)) + 14534942818069300546U;
            aOrbiterF = (aWandererE + RotL64(aCross, 43U)) + 17745973100886007133U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 57U)) + 2249805580771946872U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aScatter, 51U)) + RotL64(aCarry, 13U)) + 4460116116396439410U;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 21U)) + 3378683994078106878U) + RotL64(aNonceWordH, 3U);
            aOrbiterC = ((aWandererB + RotL64(aCross, 24U)) + 3992996501048809123U) + RotL64(aNonceWordA, 9U);
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 35U)) + 12057768808864451929U;
            aOrbiterK = ((aWandererD + RotL64(aScatter, 13U)) + 4115362079047921130U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = ((aWandererG + RotL64(aIngress, 39U)) + RotL64(aCarry, 35U)) + 15297384955502206698U;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 11U)) + RotL64(aCarry, 53U)) + 17623548383481905636U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 3559213898000162417U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 12311605719074507335U;
            aOrbiterF = RotL64((aOrbiterF * 3982199462062847697U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 14807313864347885885U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 11222085523291581822U;
            aOrbiterD = RotL64((aOrbiterD * 12580941911587215653U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 916681229436292462U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 2441350114032314686U;
            aOrbiterB = RotL64((aOrbiterB * 7336079498999018067U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 7361470539894653271U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 12153585147213579808U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3040327545467672961U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 13566300726101613579U) + RotL64(aNonceWordB, 35U);
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 14875254144748509128U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13699179902908972403U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 9268158535644002904U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 14144295981814993491U;
            aOrbiterE = RotL64((aOrbiterE * 12739937231684038161U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 13861225650900541642U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 12620513474052058164U;
            aOrbiterJ = RotL64((aOrbiterJ * 18141974182442267181U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 14163773386433257965U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 5725700029399455855U;
            aOrbiterH = RotL64((aOrbiterH * 10446930901088908809U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 16644838246877860102U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 6611825438224873117U;
            aOrbiterA = RotL64((aOrbiterA * 5336239588054125897U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 9408958265247071226U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 16980073477599191801U) ^ RotL64(aNonceWordC, 53U);
            aOrbiterG = RotL64((aOrbiterG * 7985839560318985205U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 6513029242607881518U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 13880995121909552664U;
            aOrbiterI = RotL64((aOrbiterI * 17463079726765044639U), 29U);
            //
            aIngress = RotL64(aOrbiterI, 44U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterC, 41U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterK, 39U));
            aWandererC = aWandererC + (((RotL64(aIngress, 4U) + aOrbiterD) + RotL64(aOrbiterG, 51U)) + RotL64(aNonceWordG, 57U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 18U)) + aOrbiterD) + RotL64(aNonceWordD, 44U));
            aWandererK = aWandererK + ((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterB, 47U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterA, 29U));
            aWandererD = aWandererD + (((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterA, 41U)) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 43U)) + aOrbiterB) + aPhaseDWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 41U) + aOrbiterE) + RotL64(aOrbiterI, 11U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 58U) + aOrbiterH) + RotL64(aOrbiterA, 21U));
            aWandererH = aWandererH + ((((RotL64(aScatter, 51U) + aOrbiterH) + RotL64(aOrbiterI, 5U)) + RotL64(aCarry, 13U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 39U) + aOrbiterC) + RotL64(aOrbiterK, 14U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 54U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + RotL64(aWandererA, 34U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 35U) ^ RotL64(aNonceWordE, 43U)) ^ RotL64(aNonceWordA, 19U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 11729U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((aIndex + 13366U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 57U) ^ RotL64(aNonceWordF, 23U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15094U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11193U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 37U) ^ RotL64(aCarry, 53U)) + (RotL64(aCross, 23U) ^ RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterB = (aWandererD + RotL64(aCross, 47U)) + 9630214189402543339U;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 30U)) + 4072576573737526819U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = (((aWandererF + RotL64(aIngress, 35U)) + RotL64(aCarry, 3U)) + 15994787452709618869U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aScatter, 37U)) + 6403240137132259482U) + RotL64(aNonceWordB, 46U);
            aOrbiterA = (aWandererC + RotL64(aCross, 3U)) + 10229266900170507720U;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 53U)) + RotL64(aCarry, 37U)) + 5025294577989748989U;
            aOrbiterH = (aWandererH + RotL64(aIngress, 5U)) + 16696461238217956883U;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 27U)) + RotL64(aCarry, 27U)) + 9878318855341719119U;
            aOrbiterI = (aWandererJ + RotL64(aIngress, 51U)) + 16086635438116177346U;
            aOrbiterG = ((aWandererB + RotL64(aCross, 21U)) + 12295437783084203730U) + RotL64(aNonceWordA, 35U);
            aOrbiterE = (aWandererI + RotL64(aPrevious, 44U)) + 7681150419912842402U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 2639104034287637448U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 12298170009332243573U;
            aOrbiterJ = RotL64((aOrbiterJ * 9397919591171238575U), 47U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterA) + 3485932317267669626U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1]) + RotL64(aNonceWordH, 43U);
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 16569551670038752475U;
            aOrbiterC = RotL64((aOrbiterC * 8139802826402217631U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 4448490103784103954U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 14510534073046885941U;
            aOrbiterK = RotL64((aOrbiterK * 7777192047386438305U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 4286195398675733451U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 15790355933840266463U;
            aOrbiterA = RotL64((aOrbiterA * 13342257823027075501U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 6362891510370156055U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 15121822034579983174U;
            aOrbiterF = RotL64((aOrbiterF * 7268045994574844937U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 13817341015719915628U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 14113474087906143783U;
            aOrbiterG = RotL64((aOrbiterG * 12838910141533126059U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 9988301252236121106U) + RotL64(aNonceWordE, 41U);
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 11287477288382171758U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4979297247881426383U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 9491727010910328644U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 7961202721830514030U;
            aOrbiterD = RotL64((aOrbiterD * 16300364540313620767U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 10058066852293995222U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 541563830282750968U;
            aOrbiterH = RotL64((aOrbiterH * 1516823517052019845U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 7791201128863372861U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 8334318157449352359U;
            aOrbiterI = RotL64((aOrbiterI * 2924838607279239375U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 6861081455774799715U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 9630214189402543339U;
            aOrbiterE = RotL64((aOrbiterE * 10837610668580336781U), 3U);
            //
            aIngress = RotL64(aOrbiterA, 47U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 14U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 23U));
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterH, 12U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterE, 23U)) + aOrbiterH);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 50U) + aOrbiterG) + RotL64(aOrbiterC, 37U));
            aWandererE = aWandererE + (((RotL64(aCross, 21U) + aOrbiterH) + RotL64(aOrbiterI, 19U)) + RotL64(aNonceWordC, 55U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 51U)) + aOrbiterK);
            aWandererK = aWandererK + ((RotL64(aCross, 29U) + RotL64(aOrbiterA, 35U)) + aOrbiterI);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 39U)) + aOrbiterE);
            aWandererG = aWandererG + (((RotL64(aScatter, 43U) + aOrbiterF) + RotL64(aOrbiterE, 47U)) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 39U) + RotL64(aOrbiterD, 41U)) + aOrbiterH) + RotL64(aNonceWordG, 13U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterA, 4U)) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 58U) + aOrbiterB) + RotL64(aOrbiterC, 27U)) + aPhaseDWandererUpdateSaltD[((aIndex + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 6U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 48U));
            aCarry = aCarry + RotL64(aWandererA, 29U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 13U) ^ RotL64(aNonceWordB, 23U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 17055U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 19810U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 41U) ^ RotL64(aNonceWordC, 28U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18784U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20362U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aPrevious, 44U)) ^ (RotL64(aCarry, 11U) + RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterI = ((((aWandererJ + RotL64(aIngress, 53U)) + RotL64(aCarry, 53U)) + 13714409587461539863U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1]) + RotL64(aNonceWordE, 35U);
            aOrbiterJ = (aWandererF + RotL64(aCross, 13U)) + 14101156723903265839U;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 10U)) + 7063754562895369001U;
            aOrbiterA = (((aWandererG + RotL64(aScatter, 29U)) + RotL64(aCarry, 37U)) + 12320578575245519386U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aPrevious, 47U)) + 11744826789631008424U;
            aOrbiterF = ((aWandererE + RotL64(aCross, 51U)) + RotL64(aCarry, 19U)) + 8744816505096675597U;
            aOrbiterG = (aWandererD + RotL64(aScatter, 21U)) + 10405435520084528645U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 23U)) + 1463157688070683543U;
            aOrbiterB = (aWandererI + RotL64(aPrevious, 39U)) + 12379603577919617703U;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 42U)) + 1343439118031348146U) + RotL64(aNonceWordF, 51U);
            aOrbiterC = (aWandererC + RotL64(aCross, 3U)) + 16118850268070235540U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 14116264435819277136U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 5251698273012432109U;
            aOrbiterH = RotL64((aOrbiterH * 1495818611622063967U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 14806408656041403829U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 11569345414052398227U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9913158908301414861U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 17063874769147888574U) + RotL64(aNonceWordA, 23U);
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 9927420478679581917U;
            aOrbiterF = RotL64((aOrbiterF * 9042782809534196563U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 2550285599827162167U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 17801534123304996448U;
            aOrbiterG = RotL64((aOrbiterG * 2160836889363614721U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 6456685241021762041U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 17064208177372969289U;
            aOrbiterD = RotL64((aOrbiterD * 13726627607233302493U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 18279938244131982650U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 8211002229712129419U;
            aOrbiterB = RotL64((aOrbiterB * 12931373380977640645U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 12795832560781931767U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 286378504074349650U;
            aOrbiterE = RotL64((aOrbiterE * 85453101173293509U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 5835304250436889513U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 12704972686724379659U;
            aOrbiterC = RotL64((aOrbiterC * 1198789639656336053U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 12555700587254295099U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 6740149669657971715U) ^ RotL64(aNonceWordB, 31U);
            aOrbiterI = RotL64((aOrbiterI * 9376048577305482691U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 1541392147096889431U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 16891341703173286949U;
            aOrbiterJ = RotL64((aOrbiterJ * 697452963711223355U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 8811637585092392653U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 13714409587461539863U;
            aOrbiterA = RotL64((aOrbiterA * 2578939920876994763U), 3U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterE, 21U);
            aIngress = aIngress + (RotL64(aOrbiterH, 23U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterI, 6U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 39U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + RotL64(aOrbiterC, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((((RotL64(aCross, 58U) + RotL64(aOrbiterB, 27U)) + aOrbiterF) + RotL64(aNonceWordG, 26U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 39U) + RotL64(aOrbiterB, 23U)) + aOrbiterH) + RotL64(aNonceWordD, 53U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterK, 3U));
            aWandererE = aWandererE + (((RotL64(aScatter, 23U) + RotL64(aOrbiterC, 37U)) + aOrbiterI) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 42U) + RotL64(aOrbiterI, 35U)) + aOrbiterD);
            aWandererH = aWandererH + ((RotL64(aIngress, 11U) + RotL64(aOrbiterI, 44U)) + aOrbiterG);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 39U)) + aOrbiterE);
            aWandererF = aWandererF + (((RotL64(aCross, 5U) + aOrbiterH) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 29U) + aOrbiterK) + RotL64(aOrbiterE, 21U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 11U)) + aOrbiterD);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterC, 30U)) + aOrbiterJ) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 42U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 27U);
            aCarry = aCarry + RotL64(aIngress, 36U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 21U) ^ RotL64(aNonceWordC, 39U)) ^ RotL64(aNonceWordE, 5U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 22130U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23096U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 37U) ^ RotL64(aNonceWordH, 13U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 22840U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 27009U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aIngress, 43U)) + (RotL64(aPrevious, 56U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterK = (aWandererC + RotL64(aCross, 13U)) + 6318740973868639425U;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 48U)) + 5487840061430920881U) + RotL64(aNonceWordE, 57U);
            aOrbiterF = (((aWandererI + RotL64(aScatter, 53U)) + RotL64(aCarry, 21U)) + 10258706763248072672U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = (aWandererE + RotL64(aPrevious, 29U)) + 18356875269730338208U;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 19U)) + 12883160282903147010U;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 51U)) + 1010140474942697730U;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 11U)) + RotL64(aCarry, 57U)) + 17733939421700898293U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 37U)) + 13693055887924981201U) + RotL64(aNonceWordA, 7U);
            aOrbiterA = ((aWandererD + RotL64(aIngress, 60U)) + 14574732452793385269U) + aPhaseDOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 39U)) + RotL64(aCarry, 11U)) + 10832873941223609012U;
            aOrbiterB = (aWandererA + RotL64(aCross, 23U)) + 8212600587135328040U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 5312744319781971178U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 6173741211706546923U;
            aOrbiterF = RotL64((aOrbiterF * 12854414066390848249U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 3693249147883790810U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 18365859989736602556U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3348463719324104997U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 10645056678337549771U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 1175668356822251045U;
            aOrbiterD = RotL64((aOrbiterD * 6579675292775345579U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 13556844570541823717U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 4790355739411849736U;
            aOrbiterH = RotL64((aOrbiterH * 4083544011788850307U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 14905575502272644116U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 17047244574558476634U;
            aOrbiterK = RotL64((aOrbiterK * 2356386971503880047U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 10161614295718414869U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 13413914082651612468U;
            aOrbiterC = RotL64((aOrbiterC * 16224039093981079491U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 6072693130156927774U) + RotL64(aNonceWordB, 37U);
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 4333656233793103787U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9374745547133955709U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 17209776289202130250U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 11752001118070361543U;
            aOrbiterA = RotL64((aOrbiterA * 4416523594812872339U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 15367365111105608277U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 8650687767097460704U) ^ RotL64(aNonceWordG, 10U);
            aOrbiterB = RotL64((aOrbiterB * 11430451559660578667U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 18074648514448405693U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 10857586858462237581U;
            aOrbiterE = RotL64((aOrbiterE * 3722891011080095849U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 17219932344278345591U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 6318740973868639425U;
            aOrbiterG = RotL64((aOrbiterG * 8846295038878812229U), 3U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterB, 44U);
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 24U)) + aOrbiterH);
            aWandererG = aWandererG + (((RotL64(aScatter, 39U) + RotL64(aOrbiterE, 11U)) + aOrbiterD) + RotL64(aNonceWordF, 23U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterC, 19U)) + aOrbiterG);
            aWandererF = aWandererF + (((RotL64(aPrevious, 54U) + RotL64(aOrbiterJ, 57U)) + aOrbiterC) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 3U)) + aOrbiterA) + RotL64(aNonceWordD, 51U));
            aWandererH = aWandererH + (((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 37U)) + aOrbiterA) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 43U) + aOrbiterG) + RotL64(aOrbiterK, 35U)) + aPhaseDWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 41U) + aOrbiterF) + RotL64(aOrbiterK, 5U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 37U) + aOrbiterG) + RotL64(aOrbiterE, 53U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 58U) + aOrbiterC) + RotL64(aOrbiterI, 46U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterH, 21U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (RotL64(aWandererE, 42U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + RotL64(aWandererB, 37U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 22U) ^ RotL64(aNonceWordF, 47U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 27377U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32150U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 27U) ^ RotL64(aNonceWordH, 13U)) ^ RotL64(aNonceWordG, 53U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31197U)) & S_BLOCK1], 42U) ^ RotL64(aOperationLaneB[((aIndex + 31985U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 29U) + RotL64(aIngress, 53U)) ^ (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 14U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterG = (aWandererF + RotL64(aScatter, 6U)) + 16424657151168221875U;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 51U)) + 17150123681886380361U) + RotL64(aNonceWordA, 54U);
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 19U)) + 16041993588694572757U;
            aOrbiterH = (((aWandererE + RotL64(aCross, 57U)) + RotL64(aCarry, 23U)) + 9871185846434828537U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aIngress, 29U)) + 11227236398354430757U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 27U)) + 5399325217402192631U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 47U)) + RotL64(aCarry, 41U)) + 9248828789282890454U;
            aOrbiterC = (((aWandererA + RotL64(aPrevious, 41U)) + 9041370494203701062U) + aPhaseDOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1]) + RotL64(aNonceWordC, 45U);
            aOrbiterE = (aWandererG + RotL64(aCross, 13U)) + 14944424084524970764U;
            aOrbiterD = (aWandererI + RotL64(aPrevious, 22U)) + 5481938174456671041U;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 5U)) + 14783648629543752715U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 12355573914530445723U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 9863991559011968318U;
            aOrbiterA = RotL64((aOrbiterA * 8495251211794343179U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 16149688605937250965U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 106041828692026825U;
            aOrbiterI = RotL64((aOrbiterI * 12199934305374582599U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 8076098639554567792U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 11155119311895580013U;
            aOrbiterJ = RotL64((aOrbiterJ * 1495180896564818647U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 6847612160595917702U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 16094377920388017367U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4875801863643206333U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 13584719866672696684U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 13446209321646234607U;
            aOrbiterC = RotL64((aOrbiterC * 9945349065094781529U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 15829806645369560988U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 12573767256739062550U;
            aOrbiterE = RotL64((aOrbiterE * 5649504278826069077U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 3850030870300393809U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 11857593987748189858U;
            aOrbiterD = RotL64((aOrbiterD * 15942863910931814193U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 5505918410521728373U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 12949653497121247860U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 90944913639560027U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 2448323375614082955U) + RotL64(aNonceWordD, 25U);
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 4386059032042654583U) ^ RotL64(aNonceWordH, 35U);
            aOrbiterG = RotL64((aOrbiterG * 11730132905525317201U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 108129028178045299U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 18292666533864994149U;
            aOrbiterF = RotL64((aOrbiterF * 2599590507178673531U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 10771402979550786312U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 16424657151168221875U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6255743082177474607U), 57U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 44U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + RotL64(aOrbiterJ, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 27U)) + aOrbiterF) + RotL64(aNonceWordB, 49U));
            aWandererK = aWandererK + (((RotL64(aCross, 51U) + RotL64(aOrbiterD, 56U)) + aOrbiterE) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 53U) + aOrbiterB) + RotL64(aOrbiterC, 39U));
            aWandererE = aWandererE + ((RotL64(aScatter, 41U) + RotL64(aOrbiterD, 47U)) + aOrbiterJ);
            aWandererI = aWandererI ^ ((RotL64(aCross, 12U) + RotL64(aOrbiterK, 37U)) + aOrbiterD);
            aWandererA = aWandererA + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 21U)) + aOrbiterA) + RotL64(aCarry, 21U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterK, 14U)) + aOrbiterI);
            aWandererF = aWandererF + ((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterA, 23U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterI, 41U)) + aPhaseDWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 22U) + aOrbiterD) + RotL64(aOrbiterA, 3U)) + RotL64(aNonceWordE, 5U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 39U) + aOrbiterH) + RotL64(aOrbiterD, 53U)) + aPhaseDWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 28U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + RotL64(aWandererD, 52U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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

void TwistExpander_Tennis_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xA358735F29230FFDULL + 0xA62E59C0900686D6ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xDD574B0499ABB713ULL + 0xBC902094E65B40B1ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xA9472AC722D43789ULL + 0xF237032D443693E6ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xAC4009B2A905E033ULL + 0x9B97F77F5BA521C6ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x87BA581648BA9E91ULL + 0xF15AEDD8B10463E5ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA0FE18DD5B1352EBULL + 0x97FDFD9098DE53E7ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x85C5E8F4321A404DULL + 0x9912366742E237CFULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xFB55EBB9E0202553ULL + 0xCFF3ABAFB4E9CCB5ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 10U) ^ RotL64(aNonceWordH, 29U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 891U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneC[((aIndex + 4574U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 11U) ^ RotL64(aNonceWordB, 47U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 1029U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 2195U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCarry, 5U)) + (RotL64(aIngress, 57U) ^ RotL64(aCross, 44U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 21U)) + 13278949403988203974U) + RotL64(aNonceWordA, 8U);
            aOrbiterI = (aWandererF + RotL64(aCross, 53U)) + 9213599924054673756U;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 39U)) + 1255746482932381798U;
            aOrbiterD = (aWandererA + RotL64(aScatter, 18U)) + 11575321997144516122U;
            aOrbiterE = (((aWandererE + RotL64(aPrevious, 11U)) + RotL64(aCarry, 53U)) + 15881587525529432437U) + aPhaseEOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aCross, 23U)) + RotL64(aCarry, 41U)) + 9846195809864862707U;
            aOrbiterG = (aWandererH + RotL64(aScatter, 47U)) + 12319815691858217670U;
            aOrbiterA = (aWandererG + RotL64(aIngress, 28U)) + 16322617427294439587U;
            aOrbiterH = (aWandererC + RotL64(aCross, 57U)) + 16332130810525887437U;
            aOrbiterF = (aWandererI + RotL64(aIngress, 37U)) + 4920951156015336794U;
            aOrbiterB = ((((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 35U)) + 16767126455124552329U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1]) + RotL64(aNonceWordF, 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 12553595911087945223U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 1437522202135436142U;
            aOrbiterC = RotL64((aOrbiterC * 2001992794165550905U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 12313100454852227143U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 2761983020631055729U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3874839760378039509U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 17635303588421554367U) + RotL64(aNonceWordD, 19U);
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 788212489507463763U;
            aOrbiterK = RotL64((aOrbiterK * 17896475584538528059U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 5192552894670654434U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 6784748488807738811U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8077237651953896479U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 16113417046719114943U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 1096874945215225916U;
            aOrbiterG = RotL64((aOrbiterG * 17308604412622879833U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 7610274704570171595U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 10466070212284342550U;
            aOrbiterH = RotL64((aOrbiterH * 6449728258497920613U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 6777845928873855221U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 5251515022021984126U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9018277343404261611U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 13849343158824111498U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 7977711210181714021U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4182053966171053577U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 6494539818728106982U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 11314590450226080781U;
            aOrbiterE = RotL64((aOrbiterE * 12455979257225599157U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 552687702594328012U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 14961304171192292246U;
            aOrbiterA = RotL64((aOrbiterA * 846375892915484717U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 9771874402848476494U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 13278949403988203974U) ^ RotL64(aNonceWordG, 43U);
            aOrbiterF = RotL64((aOrbiterF * 2119203863777871233U), 41U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 44U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + RotL64(aOrbiterH, 14U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterD, 22U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 24U) + RotL64(aOrbiterI, 47U)) + aOrbiterK);
            aWandererG = aWandererG + (((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 5U)) + aOrbiterH) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 27U)) + aOrbiterF) + RotL64(aNonceWordB, 39U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 3U) + aOrbiterE) + RotL64(aOrbiterJ, 51U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 37U) + aOrbiterD) + RotL64(aOrbiterC, 29U));
            aWandererF = aWandererF + ((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterB, 18U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterE, 57U)) + aOrbiterK);
            aWandererA = aWandererA + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 13U)) + aOrbiterJ);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 35U)) + aOrbiterC);
            aWandererB = aWandererB + (((((RotL64(aIngress, 46U) + aOrbiterC) + RotL64(aOrbiterF, 53U)) + RotL64(aCarry, 11U)) + RotL64(aNonceWordC, 41U)) + aPhaseEWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 26U));
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 11U) ^ RotL64(aNonceWordC, 46U)) ^ RotL64(aNonceWordB, 23U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 9862U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 9780U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 11U) ^ RotL64(aNonceWordE, 43U)) ^ RotL64(aNonceWordA, 51U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6403U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((aIndex + 6399U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCarry, 29U)) ^ (RotL64(aCross, 5U) ^ RotL64(aPrevious, 56U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterF = (aWandererI + RotL64(aScatter, 57U)) + 12136097566601676613U;
            aOrbiterC = (aWandererD + RotL64(aPrevious, 38U)) + 7969431322248040056U;
            aOrbiterJ = (((aWandererK + RotL64(aCross, 53U)) + RotL64(aCarry, 19U)) + 10530676021510553889U) + RotL64(aNonceWordE, 22U);
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 43U)) + RotL64(aCarry, 13U)) + 8740777303075445264U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 47U)) + RotL64(aCarry, 39U)) + 13249434169895564739U;
            aOrbiterE = ((aWandererC + RotL64(aScatter, 12U)) + 15529577005925628472U) + aPhaseEOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aIngress, 29U)) + 344627093687331562U) + RotL64(aNonceWordF, 61U);
            aOrbiterA = (aWandererB + RotL64(aCross, 27U)) + 8824277416519988893U;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 3U)) + 5636276438449709875U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aCross, 41U)) + 2079413361031851552U;
            aOrbiterH = (aWandererH + RotL64(aIngress, 5U)) + 7807998179168655561U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 13589392896232029112U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 10733011474804473996U;
            aOrbiterJ = RotL64((aOrbiterJ * 361749145931578805U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 15934162328347805968U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 7573511217796245232U;
            aOrbiterC = RotL64((aOrbiterC * 10694563909931636155U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 4828475187337891975U) + RotL64(aNonceWordC, 51U);
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 13284974329890393113U;
            aOrbiterD = RotL64((aOrbiterD * 10831075817642374287U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 13173869918669643112U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 15841507674783398167U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15632933198136963277U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 14168272451055700516U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 11134471485501999898U;
            aOrbiterB = RotL64((aOrbiterB * 8019507184494591705U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 2611858916687822610U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 17863271539727513641U) ^ RotL64(aNonceWordG, 15U);
            aOrbiterF = RotL64((aOrbiterF * 4987884722174985677U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 8874401993454249066U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 5131480593493950665U;
            aOrbiterI = RotL64((aOrbiterI * 8585874663602346121U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 9366563022381918996U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 7890729519928340296U;
            aOrbiterE = RotL64((aOrbiterE * 11428572374057899517U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 131774386529223292U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 4108356674478240148U;
            aOrbiterA = RotL64((aOrbiterA * 2492753294539081613U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 7651738365157869789U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 2745458108574051004U;
            aOrbiterG = RotL64((aOrbiterG * 2175955806036373729U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 10492013124307434604U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 12136097566601676613U;
            aOrbiterH = RotL64((aOrbiterH * 13128652803485742119U), 27U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 51U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 58U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterH, 48U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterI, 5U)) + RotL64(aNonceWordA, 9U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterB, 44U)) + aOrbiterJ);
            aWandererH = aWandererH + ((RotL64(aScatter, 30U) + aOrbiterD) + RotL64(aOrbiterA, 23U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 3U) + aOrbiterB) + RotL64(aOrbiterE, 21U));
            aWandererD = aWandererD + (((RotL64(aIngress, 41U) + RotL64(aOrbiterB, 57U)) + aOrbiterH) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 47U)) + aOrbiterC) + aPhaseEWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aScatter, 51U) + aOrbiterH) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 37U)) + RotL64(aNonceWordD, 59U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 53U) + aOrbiterI) + RotL64(aOrbiterF, 11U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterH, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterF, 28U)) + aOrbiterC);
            aWandererF = aWandererF + ((RotL64(aIngress, 20U) + aOrbiterB) + RotL64(aOrbiterC, 37U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 22U));
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 19U);
            aCarry = aCarry + RotL64(aIngress, 50U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 43U) ^ RotL64(aNonceWordE, 29U)) ^ RotL64(aNonceWordB, 57U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 15798U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 12434U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 41U) ^ RotL64(aNonceWordC, 10U)) ^ RotL64(aNonceWordD, 51U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 14504U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 11367U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 23U)) + (RotL64(aCarry, 37U) ^ RotL64(aPrevious, 54U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterJ = (((aWandererG + RotL64(aScatter, 51U)) + 8793908991006073956U) + aPhaseEOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1]) + RotL64(aNonceWordH, 37U);
            aOrbiterE = (aWandererH + RotL64(aPrevious, 13U)) + 2932916283348441943U;
            aOrbiterB = (aWandererB + RotL64(aIngress, 41U)) + 11069042087940968262U;
            aOrbiterF = (aWandererC + RotL64(aCross, 44U)) + 14369628676782894441U;
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 11U)) + 8602903272780978282U) + aPhaseEOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = ((aWandererF + RotL64(aCross, 27U)) + RotL64(aCarry, 39U)) + 3827036107178568820U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 35U)) + RotL64(aCarry, 57U)) + 8905245209036772489U;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 19U)) + RotL64(aCarry, 5U)) + 13331387530760017893U;
            aOrbiterA = ((aWandererA + RotL64(aIngress, 37U)) + 9880107580289737823U) + RotL64(aNonceWordD, 5U);
            aOrbiterI = (aWandererK + RotL64(aScatter, 3U)) + 10199619040626900278U;
            aOrbiterK = (aWandererE + RotL64(aCross, 60U)) + 2466307560891374281U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 13973403407981259448U) + RotL64(aNonceWordA, 9U);
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 2851460278409385243U;
            aOrbiterB = RotL64((aOrbiterB * 11226902976321781743U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 10365453393815690776U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 2382382358987358791U;
            aOrbiterD = RotL64((aOrbiterD * 481563628980705781U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 5058198848163792422U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 10500434740387593487U;
            aOrbiterE = RotL64((aOrbiterE * 5946747708776079787U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 11289798395177667084U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 14327152153231286666U) ^ RotL64(aNonceWordG, 17U);
            aOrbiterC = RotL64((aOrbiterC * 18155778059595245561U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 8065137263811956313U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 3865153574847924816U;
            aOrbiterG = RotL64((aOrbiterG * 9495741102667755161U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 18102279969722473375U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 6306428427188742325U;
            aOrbiterI = RotL64((aOrbiterI * 17826782872351406167U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 16953348204663693724U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 11950791817032898613U;
            aOrbiterJ = RotL64((aOrbiterJ * 1498946055469611133U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 11980823193543752994U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 17845490308799454871U;
            aOrbiterF = RotL64((aOrbiterF * 16385153013485463791U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 5566398755702887071U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 10308378271388889968U;
            aOrbiterH = RotL64((aOrbiterH * 142732084484961281U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 6717846700455219260U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 8297225372883997017U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14102812043481327907U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 12249337046267666603U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 8793908991006073956U;
            aOrbiterK = RotL64((aOrbiterK * 5851229209188473467U), 21U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterB, 57U);
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + (RotL64(aOrbiterK, 60U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + RotL64(aOrbiterH, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 53U) + aOrbiterK) + RotL64(aOrbiterF, 43U)) + RotL64(aNonceWordC, 11U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 50U) + RotL64(aOrbiterD, 39U)) + aOrbiterH);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterG, 5U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 34U)) + aOrbiterF) + RotL64(aCarry, 5U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterI, 51U)) + aOrbiterE);
            aWandererC = aWandererC + ((RotL64(aScatter, 14U) + RotL64(aOrbiterA, 19U)) + aOrbiterK);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 29U)) + aOrbiterH);
            aWandererB = aWandererB + (((((RotL64(aIngress, 21U) + RotL64(aOrbiterA, 57U)) + aOrbiterJ) + RotL64(aCarry, 37U)) + RotL64(aNonceWordB, 46U)) + aPhaseEWandererUpdateSaltC[((aIndex + 12U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterG, 21U)) + aOrbiterB);
            aWandererK = aWandererK + ((RotL64(aIngress, 43U) + aOrbiterA) + RotL64(aOrbiterE, 24U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 41U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 6U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + RotL64(aWandererD, 39U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 5U) ^ RotL64(aNonceWordF, 14U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 21324U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneB[((aIndex + 19986U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 29U) ^ RotL64(aNonceWordC, 50U)) ^ RotL64(aNonceWordG, 39U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 16527U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 19745U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 27U)) ^ (RotL64(aCross, 51U) + RotL64(aIngress, 12U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterK = (aWandererD + RotL64(aScatter, 18U)) + 4773124477323378268U;
            aOrbiterE = (aWandererF + RotL64(aCross, 27U)) + 16848723289435796005U;
            aOrbiterI = (aWandererK + RotL64(aIngress, 39U)) + 13846642134917107058U;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 43U)) + RotL64(aCarry, 11U)) + 6472057872482789939U;
            aOrbiterF = (aWandererA + RotL64(aScatter, 35U)) + 2747019500690707226U;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 37U)) + 9003965289739733880U) + aPhaseEOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = (aWandererG + RotL64(aIngress, 50U)) + 3013390651936257377U;
            aOrbiterB = (((aWandererB + RotL64(aCross, 21U)) + RotL64(aCarry, 53U)) + 3331004709895625067U) + RotL64(aNonceWordB, 51U);
            aOrbiterC = (aWandererI + RotL64(aPrevious, 11U)) + 15355010435553517129U;
            aOrbiterD = ((aWandererJ + RotL64(aCross, 13U)) + 7709870658004280052U) + RotL64(aNonceWordF, 5U);
            aOrbiterA = (((aWandererH + RotL64(aScatter, 41U)) + RotL64(aCarry, 37U)) + 13568728443963926564U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 12409548853419307131U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 969183352023661537U;
            aOrbiterI = RotL64((aOrbiterI * 5549220554838837145U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 15370309834426476775U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 3896803894396631184U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11018830202891911603U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 10848873633291935766U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 12885336509190543440U;
            aOrbiterH = RotL64((aOrbiterH * 1487357252619221365U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 8252290890093788010U) + RotL64(aNonceWordE, 23U);
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 9201553615601641350U;
            aOrbiterG = RotL64((aOrbiterG * 420321130559162915U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 14014209645503188472U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 4015071464301844550U;
            aOrbiterB = RotL64((aOrbiterB * 17444195018239904971U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 16173085647514027347U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 16916627014974363360U;
            aOrbiterC = RotL64((aOrbiterC * 7699587344277490953U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 1591680303404522110U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 16499606051269327916U) ^ RotL64(aNonceWordC, 49U);
            aOrbiterD = RotL64((aOrbiterD * 814405848002794813U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 6932673635509444619U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 8745681160108707944U;
            aOrbiterA = RotL64((aOrbiterA * 14565255558668084787U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 10387263947888920455U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 2553335462317280031U;
            aOrbiterK = RotL64((aOrbiterK * 7253573275397985211U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 17449861295444216249U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 15716408844914738774U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10132631423215542589U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 16974370193820578179U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 4773124477323378268U;
            aOrbiterJ = RotL64((aOrbiterJ * 8982190762960590543U), 11U);
            //
            aIngress = RotL64(aOrbiterJ, 13U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterK, 46U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 42U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 37U) + aOrbiterB) + RotL64(aOrbiterC, 48U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 35U) + aOrbiterA) + RotL64(aOrbiterD, 21U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterE, 37U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 19U)) + aOrbiterC);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterF, 23U)) + aOrbiterI);
            aWandererH = aWandererH + (((RotL64(aCross, 48U) + RotL64(aOrbiterK, 3U)) + aOrbiterB) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterG, 53U)) + aOrbiterK);
            aWandererB = aWandererB + (((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 56U)) + aOrbiterJ) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterH, 43U)) + aOrbiterA) + RotL64(aNonceWordD, 22U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 50U) + aOrbiterE) + RotL64(aOrbiterA, 27U)) + RotL64(aNonceWordH, 59U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterA, 51U)) + aOrbiterI) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 46U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 48U));
            aCarry = aCarry + RotL64(aWandererF, 39U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 24U) ^ RotL64(aNonceWordH, 11U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 25422U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((aIndex + 25326U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 39U) ^ RotL64(aNonceWordA, 13U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24596U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26983U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCross, 23U)) ^ (RotL64(aCarry, 43U) + RotL64(aPrevious, 58U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterK = (aWandererK + RotL64(aCross, 3U)) + 5568146815535263910U;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 43U)) + RotL64(aCarry, 41U)) + 7736084960873834666U;
            aOrbiterG = (((aWandererC + RotL64(aIngress, 37U)) + RotL64(aCarry, 19U)) + 1336413621817562093U) + RotL64(aNonceWordD, 7U);
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 27U)) + RotL64(aCarry, 47U)) + 5218462026934984692U;
            aOrbiterE = (aWandererD + RotL64(aCross, 6U)) + 7048890985969555935U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 23U)) + 13415955213864702118U;
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 39U)) + 5657023257021528548U;
            aOrbiterB = (aWandererH + RotL64(aIngress, 47U)) + 14338310943137497116U;
            aOrbiterC = ((aWandererA + RotL64(aCross, 11U)) + 12305161641833950473U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aScatter, 35U)) + 14514226578370459131U;
            aOrbiterF = (((aWandererE + RotL64(aPrevious, 30U)) + 12692904083266024340U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 18U)) & S_SALT1]) + RotL64(aNonceWordB, 4U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 11012959130001327964U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 7106471380403489078U;
            aOrbiterG = RotL64((aOrbiterG * 515626559384817223U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 3718101961355280891U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 13364192077222322664U;
            aOrbiterA = RotL64((aOrbiterA * 1411328915372590283U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 6720867800318913440U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 14497243926965866546U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13595058589060114653U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 5789056168233262435U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 14438482587495779937U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10593535547917767263U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 313917798940179945U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 15241845511889502917U;
            aOrbiterK = RotL64((aOrbiterK * 16483477103771326107U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 3591957424821693032U) + RotL64(aNonceWordC, 9U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 1559050939014453558U;
            aOrbiterJ = RotL64((aOrbiterJ * 17933346117866604725U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 15340590914441451383U) + RotL64(aNonceWordG, 31U);
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 5538037287390050110U;
            aOrbiterI = RotL64((aOrbiterI * 4082576643144951473U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 4151270491894969214U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 263593701314144898U;
            aOrbiterC = RotL64((aOrbiterC * 10372046955804512457U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 9025145270653080646U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 6867950904094870056U;
            aOrbiterF = RotL64((aOrbiterF * 9975247022340627751U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 3183454301841252109U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 3054904157641290615U;
            aOrbiterH = RotL64((aOrbiterH * 4092317552439599475U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 1768555574434776135U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 5568146815535263910U;
            aOrbiterE = RotL64((aOrbiterE * 12466957001078663927U), 51U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 35U);
            aIngress = aIngress + (RotL64(aOrbiterH, 48U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 51U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterD, 22U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 46U) + RotL64(aOrbiterG, 60U)) + aOrbiterD) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 53U) + aOrbiterA) + RotL64(aOrbiterF, 3U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 11U) + aOrbiterE) + RotL64(aOrbiterH, 29U)) + aPhaseEWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 5U)) + aOrbiterJ) + RotL64(aNonceWordE, 5U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterE, 21U)) + aOrbiterC) + RotL64(aCarry, 29U)) + RotL64(aNonceWordF, 59U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 5U) + aOrbiterB) + RotL64(aOrbiterJ, 57U));
            aWandererK = aWandererK + ((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterG, 18U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterH, 51U)) + aPhaseEWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 60U) + aOrbiterH) + RotL64(aOrbiterI, 39U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 23U) + aOrbiterB) + RotL64(aOrbiterI, 43U));
            aWandererB = aWandererB + ((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 13U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 60U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 41U));
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 6U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 29U) ^ RotL64(aNonceWordG, 43U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 29101U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30590U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 29U) ^ RotL64(aNonceWordD, 57U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31465U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29924U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCarry, 35U)) + (RotL64(aCross, 48U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterK = (aWandererE + RotL64(aIngress, 41U)) + 964165145848253292U;
            aOrbiterD = (aWandererB + RotL64(aScatter, 3U)) + 10645976767204934746U;
            aOrbiterF = ((aWandererA + RotL64(aCross, 11U)) + RotL64(aCarry, 53U)) + 8241612229349212650U;
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 48U)) + 4159196033256913347U;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 37U)) + RotL64(aCarry, 19U)) + 7194795864620233507U;
            aOrbiterG = (((aWandererG + RotL64(aCross, 35U)) + 7638928444536778384U) + aPhaseEOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1]) + RotL64(aNonceWordB, 3U);
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 43U)) + RotL64(aCarry, 39U)) + 11819105916503968109U;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 23U)) + 18052213302858186237U;
            aOrbiterE = (aWandererK + RotL64(aCross, 21U)) + 8663575313970041570U;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 6U)) + 16644136720439299786U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 13U)) + 16930316530442679864U) + RotL64(aNonceWordC, 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 16251107616988250593U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 7171986193609401665U;
            aOrbiterF = RotL64((aOrbiterF * 3543709971414550087U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 17885046834432626644U) + RotL64(aNonceWordE, 9U);
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 7757069274715713557U) ^ RotL64(aNonceWordF, 59U);
            aOrbiterH = RotL64((aOrbiterH * 15766885299397923879U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 2212805322061155615U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 6368539134638838822U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13383744883433594259U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 5264326094252925613U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 6126345334815012938U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17180934809764905307U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 13826731214018407061U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 6621261811613643620U;
            aOrbiterJ = RotL64((aOrbiterJ * 2823596473596114171U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 5964406317285863781U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 2167324450276308078U;
            aOrbiterE = RotL64((aOrbiterE * 1098346374733634905U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 16740710162977859724U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 8236083581048717923U;
            aOrbiterI = RotL64((aOrbiterI * 4364887787000704039U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 13967473987446124012U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 5136051802217149813U;
            aOrbiterA = RotL64((aOrbiterA * 13997246005108872883U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 5842999397215390366U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 8621394946580065499U;
            aOrbiterK = RotL64((aOrbiterK * 11658023035736362355U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 18086875424872976900U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 7429246355923896047U;
            aOrbiterD = RotL64((aOrbiterD * 5077079237334961761U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 18123753993386959014U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 964165145848253292U;
            aOrbiterC = RotL64((aOrbiterC * 3178072569980307307U), 57U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 35U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 18U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 41U));
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 37U) + aOrbiterI) + RotL64(aOrbiterD, 53U));
            aWandererC = aWandererC + (((RotL64(aIngress, 27U) + aOrbiterC) + RotL64(aOrbiterA, 44U)) + RotL64(aNonceWordG, 42U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 20U) + aOrbiterK) + RotL64(aOrbiterF, 51U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 41U) + aOrbiterJ) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 57U)) + aPhaseEWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 39U)) + aOrbiterG) + aPhaseEWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 51U) + RotL64(aOrbiterF, 37U)) + aOrbiterC);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 11U) + aOrbiterF) + RotL64(aOrbiterJ, 21U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterE, 19U)) + aOrbiterB) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 46U) + aOrbiterJ) + RotL64(aOrbiterA, 23U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 39U) + RotL64(aOrbiterF, 41U)) + aOrbiterI) + RotL64(aNonceWordA, 19U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterH, 48U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (RotL64(aWandererI, 54U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 4U);
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

void TwistExpander_Tennis_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x906E54A83EF3B855ULL + 0xA3D62E30BE335605ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x9D69ABC97A8C18DFULL + 0xC432FBC7130D73A5ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xB91BB44A90ADDC49ULL + 0xF9C276498FF2602DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xCE9638EA868B2D01ULL + 0xBBA63981EDE57422ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xE91945B5C2D0B0DBULL + 0xB6FFD1801A6BF1F8ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xBFDF060E7C28F94DULL + 0x9CE690266229BAADULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xF4D87FAC4211C055ULL + 0x9DA143ECF2FB9EB8ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xE1EB727962129A79ULL + 0xA0DD67C3B633A43FULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 23U) ^ RotL64(aNonceWordA, 13U)) ^ RotL64(aNonceWordE, 41U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 5399U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1379U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 13U) ^ RotL64(aNonceWordF, 23U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 4009U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((aIndex + 2479U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 22U) + RotL64(aPrevious, 35U)) ^ (RotL64(aIngress, 53U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = (aWandererE + RotL64(aCross, 57U)) + 1708250618750199233U;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 28U)) + 12009147777553691142U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (((aWandererA + RotL64(aIngress, 13U)) + RotL64(aCarry, 35U)) + 8393982703399156592U) + RotL64(aNonceWordB, 8U);
            aOrbiterC = (((aWandererD + RotL64(aPrevious, 37U)) + RotL64(aCarry, 41U)) + 3247327098356831221U) + RotL64(aNonceWordC, 35U);
            aOrbiterJ = (aWandererI + RotL64(aCross, 41U)) + 3403590155376353737U;
            aOrbiterB = (aWandererC + RotL64(aIngress, 21U)) + 18197244558104735044U;
            aOrbiterK = (((aWandererK + RotL64(aScatter, 47U)) + RotL64(aCarry, 57U)) + 3096253642040701606U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aPrevious, 10U)) + 8012692688785412179U;
            aOrbiterG = (aWandererB + RotL64(aScatter, 35U)) + 17531946907545680745U;
            aOrbiterE = (aWandererG + RotL64(aCross, 5U)) + 17687695944270225817U;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 23U)) + 16147773866007628769U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 18244641303026196497U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 8839160526348897457U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14268021129087663397U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 10599266240854068246U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 2056723540756216155U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13311591601230386375U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 4629354220460621284U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 9505955649473204942U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17775391885312236187U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 17078153810088721310U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 9470436761716263000U;
            aOrbiterC = RotL64((aOrbiterC * 5431855497250357229U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 3305863413630104742U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 14377172434239576161U;
            aOrbiterK = RotL64((aOrbiterK * 6880176890091033423U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 415687827894226513U) + RotL64(aNonceWordF, 15U);
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 16975319836893760993U;
            aOrbiterG = RotL64((aOrbiterG * 6597144958013976445U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 12707054129431596074U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 8974182792497231239U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7874658957269462717U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 10826131924322955095U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 4168545139712703154U;
            aOrbiterD = RotL64((aOrbiterD * 10305904857550051705U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 4539070253658625193U) + RotL64(aNonceWordA, 5U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 3737870219498561326U;
            aOrbiterJ = RotL64((aOrbiterJ * 13130847633918921393U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 11563084648810555040U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 7410695535361901473U;
            aOrbiterF = RotL64((aOrbiterF * 7540855656023807389U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 6687453696858775037U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 1708250618750199233U;
            aOrbiterE = RotL64((aOrbiterE * 13104250803527718135U), 41U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterC, 54U);
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 56U));
            aIngress = aIngress + RotL64(aOrbiterE, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 27U)) + aOrbiterH);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 39U) + aOrbiterC) + RotL64(aOrbiterB, 29U));
            aWandererB = aWandererB + ((RotL64(aCross, 53U) + aOrbiterK) + RotL64(aOrbiterA, 39U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 12U) + RotL64(aOrbiterG, 47U)) + aOrbiterD);
            aWandererE = aWandererE + (((((RotL64(aCross, 37U) + aOrbiterB) + RotL64(aOrbiterD, 43U)) + RotL64(aCarry, 27U)) + RotL64(aNonceWordH, 51U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 51U)) + aOrbiterI);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 19U) + aOrbiterE) + RotL64(aOrbiterI, 58U)) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 53U)) + aOrbiterK) + RotL64(aNonceWordE, 53U));
            aWandererC = aWandererC + (((RotL64(aIngress, 21U) + RotL64(aOrbiterK, 21U)) + aOrbiterI) + aPhaseFWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 27U) + aOrbiterE) + RotL64(aOrbiterJ, 19U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 58U) + RotL64(aOrbiterA, 14U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererB, 24U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + RotL64(aWandererD, 44U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 39U) ^ RotL64(aNonceWordE, 18U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 5852U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneD[((aIndex + 6060U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 35U) ^ RotL64(aNonceWordD, 57U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 9274U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10205U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aPrevious, 42U)) ^ (RotL64(aCross, 23U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = ((aWandererF + RotL64(aCross, 29U)) + 10812151398716051703U) + RotL64(aNonceWordE, 48U);
            aOrbiterF = (aWandererG + RotL64(aScatter, 37U)) + 18202551453336003710U;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 60U)) + RotL64(aCarry, 43U)) + 9434410809101973752U;
            aOrbiterG = (((aWandererE + RotL64(aPrevious, 57U)) + RotL64(aCarry, 21U)) + 12955829998028534045U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aCross, 35U)) + 12271740641929640181U) + aPhaseFOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aScatter, 27U)) + RotL64(aCarry, 51U)) + 14009351527014534752U;
            aOrbiterC = (aWandererI + RotL64(aIngress, 46U)) + 4316296955679133450U;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 43U)) + 16473324966997442872U) + RotL64(aNonceWordA, 21U);
            aOrbiterA = (aWandererJ + RotL64(aIngress, 11U)) + 15735123324965019802U;
            aOrbiterH = (aWandererK + RotL64(aScatter, 23U)) + 17656375090484080236U;
            aOrbiterI = (aWandererB + RotL64(aCross, 5U)) + 16066325053456055298U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 12908968778503516903U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterD) ^ 12761433987676836197U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]) ^ RotL64(aNonceWordB, 7U);
            aOrbiterB = RotL64((aOrbiterB * 1023329467480907925U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 12737513138040664509U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 14535795767570998392U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15560519667062222269U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 14370908061811284364U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 7001358781208669795U;
            aOrbiterJ = RotL64((aOrbiterJ * 11641248025734015835U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 7298578161120090849U) + RotL64(aNonceWordF, 39U);
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 10498302152357484629U;
            aOrbiterC = RotL64((aOrbiterC * 13144110412179037175U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 11447343228638006767U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 18284143620422655675U;
            aOrbiterA = RotL64((aOrbiterA * 572862190073605651U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 5918253208127360199U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 3910541329178205943U;
            aOrbiterD = RotL64((aOrbiterD * 4550654545328228103U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 10357053096941367910U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 5610891501128498748U;
            aOrbiterG = RotL64((aOrbiterG * 8676370811772047449U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 9049881176058575811U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 6307599924966452216U;
            aOrbiterE = RotL64((aOrbiterE * 5551444450572055895U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 17109966783467892046U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 11563095828344462249U;
            aOrbiterK = RotL64((aOrbiterK * 15463753739272001875U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 3739147427725509014U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 5324449517615050698U;
            aOrbiterH = RotL64((aOrbiterH * 5926079615575226853U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 5706251076252597592U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 10812151398716051703U;
            aOrbiterI = RotL64((aOrbiterI * 5666491216813197045U), 29U);
            //
            aIngress = RotL64(aOrbiterC, 39U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 58U));
            aIngress = aIngress + RotL64(aOrbiterK, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aIngress, 35U) + aOrbiterA) + RotL64(aOrbiterH, 60U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 47U) + aOrbiterC) + RotL64(aOrbiterJ, 53U)) + aPhaseFWandererUpdateSaltF[((aIndex + 16U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 23U) + aOrbiterA) + RotL64(aOrbiterB, 51U)) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 10U) + aOrbiterD) + RotL64(aOrbiterG, 35U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 21U) + aOrbiterE) + RotL64(aOrbiterB, 29U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 37U) + aOrbiterJ) + RotL64(aOrbiterI, 19U));
            aWandererK = aWandererK + ((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterH, 57U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 50U) + aOrbiterK) + RotL64(aOrbiterG, 14U)) + RotL64(aNonceWordC, 45U));
            aWandererC = aWandererC + (((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterB, 23U)) + aOrbiterF) + RotL64(aNonceWordH, 43U));
            aWandererD = aWandererD + ((RotL64(aCross, 27U) + RotL64(aOrbiterI, 5U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 26U));
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 24U));
            aCarry = aCarry + RotL64(aWandererB, 21U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 24U) ^ RotL64(aNonceWordC, 5U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12302U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15708U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 57U) ^ RotL64(aNonceWordA, 13U)) ^ RotL64(aNonceWordD, 44U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 14689U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15357U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 40U) + RotL64(aCross, 53U)) + (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = (((aWandererK + RotL64(aCross, 23U)) + RotL64(aCarry, 29U)) + 6069475454765660321U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aScatter, 35U)) + RotL64(aCarry, 35U)) + 11483704742497268068U;
            aOrbiterC = (aWandererB + RotL64(aIngress, 39U)) + 11055697447388986418U;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 21U)) + 10897095046039997004U;
            aOrbiterE = (aWandererG + RotL64(aIngress, 5U)) + 4731637118230457840U;
            aOrbiterG = (((aWandererH + RotL64(aCross, 10U)) + 13855839187084986751U) + aPhaseFOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1]) + RotL64(aNonceWordG, 29U);
            aOrbiterI = (aWandererI + RotL64(aScatter, 53U)) + 5328208115460188239U;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 3U)) + RotL64(aCarry, 3U)) + 12479538544291412985U;
            aOrbiterB = (aWandererA + RotL64(aScatter, 13U)) + 10740165998792608231U;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 41U)) + 6492798157284955373U) + RotL64(aNonceWordH, 35U);
            aOrbiterK = (aWandererC + RotL64(aIngress, 58U)) + 13056825957483891921U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 2068184064919194657U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 5656302738780746294U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16493021179127646345U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 11193756120230763294U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 17306750816837208999U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7949360041241439741U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 12952818800389361804U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 15380412293642628312U;
            aOrbiterH = RotL64((aOrbiterH * 2914662289178925547U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 7706090204767242996U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 14598802276412649570U;
            aOrbiterE = RotL64((aOrbiterE * 4821408736292041399U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 17819762117328075515U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 6481384240915075101U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4836701121865783029U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 754936290510338717U) + RotL64(aNonceWordF, 7U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 15510875946573720154U;
            aOrbiterJ = RotL64((aOrbiterJ * 2994718968852184303U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 9245381722813944586U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 2629847912019726214U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6718795794951106961U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 3909987749797113773U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 9277056074757335265U;
            aOrbiterD = RotL64((aOrbiterD * 11580847505996697115U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 12577180954515966707U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 9144513680789115458U;
            aOrbiterI = RotL64((aOrbiterI * 8880777678193004979U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 1544232962956974411U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 2658275904714859636U;
            aOrbiterB = RotL64((aOrbiterB * 1926083316365175327U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 5733515391293514025U) + RotL64(aNonceWordD, 36U);
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 6069475454765660321U;
            aOrbiterK = RotL64((aOrbiterK * 9627476106108146391U), 11U);
            //
            aIngress = RotL64(aOrbiterI, 51U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 26U));
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + RotL64(aOrbiterJ, 60U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 19U) + aOrbiterE) + RotL64(aOrbiterI, 51U)) + aPhaseFWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aScatter, 21U) + aOrbiterF) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 11U)) + RotL64(aNonceWordA, 13U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 27U) + aOrbiterB) + RotL64(aOrbiterA, 47U));
            aWandererB = aWandererB + ((RotL64(aCross, 3U) + RotL64(aOrbiterK, 11U)) + aOrbiterI);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 30U) + aOrbiterJ) + RotL64(aOrbiterH, 21U));
            aWandererI = aWandererI + ((RotL64(aIngress, 37U) + aOrbiterC) + RotL64(aOrbiterD, 54U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 53U) + aOrbiterK) + RotL64(aOrbiterH, 19U));
            aWandererH = aWandererH + ((((RotL64(aCross, 41U) + aOrbiterD) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 35U)) + RotL64(aNonceWordE, 15U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 50U) + aOrbiterG) + RotL64(aOrbiterA, 43U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterB, 41U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 58U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 22U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 27U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 47U) ^ RotL64(aNonceWordH, 57U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 18759U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19629U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 11U) ^ RotL64(aNonceWordB, 51U)) ^ RotL64(aNonceWordG, 22U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21368U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneD[((aIndex + 17184U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 12U) + RotL64(aCarry, 27U)) + (RotL64(aCross, 41U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = (aWandererE + RotL64(aPrevious, 14U)) + 4751694786009671052U;
            aOrbiterD = (aWandererA + RotL64(aScatter, 23U)) + 16362725160370844224U;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 27U)) + RotL64(aCarry, 29U)) + 6360885380915941057U;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 43U)) + 5154536007972297036U) + aPhaseFOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aScatter, 53U)) + 9362540581874808253U) + RotL64(aNonceWordH, 23U);
            aOrbiterK = (aWandererI + RotL64(aIngress, 41U)) + 13902493871525612934U;
            aOrbiterC = ((aWandererK + RotL64(aCross, 5U)) + 10208452885367546542U) + RotL64(aNonceWordF, 17U);
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 3U)) + 3117030377279160998U;
            aOrbiterB = ((aWandererB + RotL64(aCross, 51U)) + RotL64(aCarry, 47U)) + 17286247690414027870U;
            aOrbiterI = (aWandererF + RotL64(aIngress, 37U)) + 3930314320040949141U;
            aOrbiterA = (((aWandererH + RotL64(aScatter, 46U)) + RotL64(aCarry, 3U)) + 7289525252391668404U) + aPhaseFOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 3434167955466809185U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 17852573095128575663U;
            aOrbiterH = RotL64((aOrbiterH * 1485660158767033425U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 6137259687928853253U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 13992510605237574698U;
            aOrbiterE = RotL64((aOrbiterE * 15346263295995333395U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6470556523400123474U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 4333255670390099293U) ^ RotL64(aNonceWordE, 15U);
            aOrbiterK = RotL64((aOrbiterK * 11089933812030082647U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 7700424876430257995U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 16920736951239453071U;
            aOrbiterC = RotL64((aOrbiterC * 8920407493132380497U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 1635071690430295730U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 9966700845966398620U) ^ RotL64(aNonceWordA, 27U);
            aOrbiterJ = RotL64((aOrbiterJ * 17210048121896546867U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 9833458070123027075U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 1990346556486746432U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8704943923474148699U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 13339523466436517327U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 5018264760406215603U;
            aOrbiterI = RotL64((aOrbiterI * 2769197961801783627U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 123427497520755346U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 4535841104215792886U;
            aOrbiterA = RotL64((aOrbiterA * 1417676310539177131U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 3525925567359163763U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 3273741481392187986U;
            aOrbiterG = RotL64((aOrbiterG * 16116160744647235811U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 6230742908784102407U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 7578784912496239362U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2614448818452560369U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 14669810330213234082U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 4751694786009671052U;
            aOrbiterF = RotL64((aOrbiterF * 9583151676882991817U), 19U);
            //
            aIngress = RotL64(aOrbiterE, 11U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterA, 34U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + RotL64(aOrbiterC, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterG, 13U)) + aOrbiterB);
            aWandererC = aWandererC + (((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterI, 35U)) + RotL64(aNonceWordD, 60U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterE, 23U)) + aOrbiterD) + aPhaseFWandererUpdateSaltA[((aIndex + 14U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 30U) + aOrbiterH) + RotL64(aOrbiterJ, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 37U) + aOrbiterJ) + RotL64(aOrbiterC, 51U));
            aWandererD = aWandererD + (((RotL64(aCross, 21U) + aOrbiterJ) + RotL64(aOrbiterG, 18U)) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 3U)) + aOrbiterI);
            aWandererI = aWandererI + ((RotL64(aPrevious, 60U) + aOrbiterD) + RotL64(aOrbiterG, 39U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterI, 21U)) + aOrbiterF) + RotL64(aNonceWordB, 7U));
            aWandererG = aWandererG + (((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 57U)) + aOrbiterF) + RotL64(aCarry, 41U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterB, 60U)) + aOrbiterK) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 54U));
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + RotL64(aWandererJ, 27U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 3U) ^ RotL64(aNonceWordF, 58U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24707U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25813U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 24U) ^ RotL64(aNonceWordG, 13U)) ^ RotL64(aNonceWordC, 41U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25574U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 23704U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCarry, 41U)) ^ (RotL64(aIngress, 56U) ^ RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 3U)) + 17454559218352016650U) + RotL64(aNonceWordH, 36U);
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 19U)) + 8005709669325164803U) + aPhaseFOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = (aWandererA + RotL64(aCross, 56U)) + 13393741948412816357U;
            aOrbiterB = (aWandererH + RotL64(aIngress, 41U)) + 3665865624348875553U;
            aOrbiterI = ((aWandererK + RotL64(aCross, 29U)) + RotL64(aCarry, 39U)) + 8334142570031883436U;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 39U)) + RotL64(aCarry, 3U)) + 17226066128706139657U;
            aOrbiterG = (((aWandererE + RotL64(aPrevious, 43U)) + RotL64(aCarry, 47U)) + 3319093033121522613U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aScatter, 35U)) + 6657535603401588798U;
            aOrbiterH = (aWandererC + RotL64(aCross, 60U)) + 5469746182326331147U;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 11U)) + 17846791786050221418U) + RotL64(aNonceWordG, 59U);
            aOrbiterE = (aWandererF + RotL64(aScatter, 37U)) + 15939541003714896288U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 12076763190461077406U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 3594038213596405284U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10244002692575821495U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 8301291631324464622U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 8460406137668390582U;
            aOrbiterC = RotL64((aOrbiterC * 9117147929757711595U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 7612394867020871200U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 8525076134853103975U;
            aOrbiterA = RotL64((aOrbiterA * 5790440201072204659U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 11929899088215090379U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 7119509166360685726U;
            aOrbiterJ = RotL64((aOrbiterJ * 1662341427992528823U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 5081078459225240607U) + RotL64(aNonceWordD, 15U);
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 17149991983909906705U;
            aOrbiterF = RotL64((aOrbiterF * 950223374568067343U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 8817303295675241994U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 7962039282652745113U) ^ RotL64(aNonceWordE, 61U);
            aOrbiterB = RotL64((aOrbiterB * 12773588587795522121U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 13596273086338032370U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 8186297702278180956U;
            aOrbiterG = RotL64((aOrbiterG * 6226504769888753861U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 1696277861691580263U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 17360461831507082959U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1651378456022210983U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 1384868996572650981U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 2039624849777183290U;
            aOrbiterE = RotL64((aOrbiterE * 13148024378138271937U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 14530407348595669913U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 18023931565754525034U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 18025122652259338105U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 11245556671533878373U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 17454559218352016650U;
            aOrbiterI = RotL64((aOrbiterI * 15665798947106818229U), 51U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterJ, 19U);
            aIngress = aIngress + (RotL64(aOrbiterH, 46U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterF, 21U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterH, 60U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterH, 29U)) + aOrbiterJ);
            aWandererC = aWandererC + (((RotL64(aCross, 36U) + RotL64(aOrbiterE, 27U)) + aOrbiterK) + RotL64(aNonceWordC, 51U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 47U)) + aOrbiterC);
            aWandererD = aWandererD + ((((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 57U)) + aOrbiterE) + RotL64(aCarry, 37U)) + RotL64(aNonceWordB, 39U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 5U) + aOrbiterB) + RotL64(aOrbiterA, 22U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 39U) + aOrbiterH) + RotL64(aOrbiterF, 5U)) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 28U) + RotL64(aOrbiterJ, 53U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterI, 43U)) + aPhaseFWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterG, 51U)) + aOrbiterI);
            aWandererI = aWandererI + ((RotL64(aCross, 21U) + RotL64(aOrbiterJ, 35U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 28U));
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + RotL64(aWandererG, 37U);
            aCarry = aCarry + RotL64(aIngress, 54U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 27U) ^ RotL64(aNonceWordB, 3U)) ^ RotL64(aNonceWordG, 39U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29207U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31812U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 3U) ^ RotL64(aNonceWordE, 58U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29472U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((aIndex + 29480U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 43U) + RotL64(aCarry, 57U)) ^ (RotL64(aCross, 27U) + RotL64(aIngress, 12U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = (aWandererC + RotL64(aPrevious, 13U)) + 6973892330986118220U;
            aOrbiterE = (((aWandererE + RotL64(aIngress, 42U)) + RotL64(aCarry, 13U)) + 9886813896272094864U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = ((aWandererA + RotL64(aCross, 57U)) + RotL64(aCarry, 57U)) + 10996306582517553173U;
            aOrbiterH = ((aWandererK + RotL64(aScatter, 47U)) + RotL64(aCarry, 5U)) + 8490648283899856223U;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 35U)) + 105141713530704655U;
            aOrbiterA = (aWandererI + RotL64(aPrevious, 27U)) + 3114337422810562588U;
            aOrbiterB = ((aWandererH + RotL64(aCross, 11U)) + 980857684690886131U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aScatter, 19U)) + 6562042345807072665U) + RotL64(aNonceWordB, 27U);
            aOrbiterI = (aWandererG + RotL64(aCross, 44U)) + 15665371138706353619U;
            aOrbiterJ = (aWandererB + RotL64(aIngress, 29U)) + 18113013571374375028U;
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 23U)) + 17405346422601997299U) + RotL64(aNonceWordE, 4U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 5130876096426182506U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 1813821672299154629U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15478100342425611875U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 15793814882743306728U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 13925299440495476399U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12049601510660117401U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 9924458846049579438U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 7810034662781768090U;
            aOrbiterA = RotL64((aOrbiterA * 10310594595026622513U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 12812586478656872854U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 5709576448057435237U;
            aOrbiterB = RotL64((aOrbiterB * 9101555233909853025U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 7839807649914541516U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 4717944526755429647U;
            aOrbiterC = RotL64((aOrbiterC * 8515229146471335721U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 3933911971504256022U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterA) ^ 4814079680865379831U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1]) ^ RotL64(aNonceWordC, 49U);
            aOrbiterI = RotL64((aOrbiterI * 15100740696230557391U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 18352577312212175569U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 9670612998448920742U;
            aOrbiterJ = RotL64((aOrbiterJ * 5743579439303300553U), 41U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterI) + 72737302703035726U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1]) + RotL64(aNonceWordG, 57U);
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 10032869372369626210U;
            aOrbiterF = RotL64((aOrbiterF * 7449905669249993731U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 2669999453643982386U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 2016129534922291383U;
            aOrbiterG = RotL64((aOrbiterG * 11730911201750754301U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 5108689262300895422U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 3753457479225942895U;
            aOrbiterE = RotL64((aOrbiterE * 11503304711866175497U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 859776381005289485U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 6973892330986118220U;
            aOrbiterH = RotL64((aOrbiterH * 12337041087475258221U), 23U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterG, 43U);
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterD, 58U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 41U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 23U) + aOrbiterD) + RotL64(aOrbiterJ, 48U));
            aWandererC = aWandererC + ((RotL64(aScatter, 13U) + RotL64(aOrbiterE, 27U)) + aOrbiterI);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 18U) + aOrbiterF) + RotL64(aOrbiterH, 53U));
            aWandererH = aWandererH + ((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 37U)) + aOrbiterF);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 13U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 39U) + aOrbiterA) + RotL64(aOrbiterE, 43U)) + RotL64(aCarry, 3U)) + RotL64(aNonceWordF, 21U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterG, 51U)) + aOrbiterK) + RotL64(aNonceWordD, 29U));
            aWandererD = aWandererD + ((RotL64(aIngress, 37U) + aOrbiterC) + RotL64(aOrbiterD, 23U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 20U) + aOrbiterA) + RotL64(aOrbiterG, 11U));
            aWandererF = aWandererF + ((((RotL64(aCross, 41U) + aOrbiterB) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 51U)) + aPhaseFWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterE, 46U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 24U));
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + RotL64(aWandererC, 60U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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

void TwistExpander_Tennis_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x869742D8F64D9D29ULL + 0xD2F5B1E67F76B126ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xD702027507C72FF1ULL + 0xF2EF328097364F94ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xF996C73C408A2D19ULL + 0xC8381D25C6880217ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x833E5EADB0C27A87ULL + 0xAB36A810E98C157DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x822CA690DCF95A31ULL + 0xA5E4A6B3F31A78EFULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xBDCC6F1AACDC338FULL + 0xBA2C820CD31A28FBULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xC487B4C8EA8A3D41ULL + 0x9D239676F5A2BCD1ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x880192E7880AA6ABULL + 0xD1735CAFA4F3DB99ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 12U) ^ RotL64(aNonceWordA, 3U)) ^ RotL64(aNonceWordD, 29U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 1671U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 4949U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 19U) ^ RotL64(aNonceWordF, 29U)) ^ RotL64(aNonceWordE, 5U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 5000U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 1036U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 20U)) + (RotL64(aIngress, 5U) ^ RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = ((aWandererE + RotL64(aScatter, 20U)) + 6771552164800695068U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 57U)) + 12131763371571322040U;
            aOrbiterD = (aWandererF + RotL64(aIngress, 51U)) + 3326182381395522013U;
            aOrbiterB = ((aWandererB + RotL64(aCross, 23U)) + RotL64(aCarry, 23U)) + 12288775097697156383U;
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 11U)) + RotL64(aCarry, 43U)) + 5195948373449796741U;
            aOrbiterF = (aWandererK + RotL64(aIngress, 27U)) + 14404044002250137144U;
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 39U)) + RotL64(aCarry, 13U)) + 11142382920035825426U;
            aOrbiterK = ((aWandererI + RotL64(aCross, 6U)) + 2967149520256475485U) + RotL64(aNonceWordD, 3U);
            aOrbiterH = (aWandererG + RotL64(aPrevious, 43U)) + 1470907369577818097U;
            aOrbiterE = ((aWandererH + RotL64(aCross, 37U)) + 9231668148004163910U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = ((aWandererA + RotL64(aIngress, 41U)) + 13078929163913892386U) + RotL64(aNonceWordC, 58U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 9485274692075657877U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 12216951187543631673U;
            aOrbiterD = RotL64((aOrbiterD * 6571066246507310805U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 6933334652581744234U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 17260276102423580920U;
            aOrbiterF = RotL64((aOrbiterF * 7796879893790990605U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 387767848169714392U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 8597538259308082638U;
            aOrbiterC = RotL64((aOrbiterC * 4888054690557707241U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 7996708724489146033U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 15357384191688149939U;
            aOrbiterB = RotL64((aOrbiterB * 9827691726832491373U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 17739222908739454637U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 1614322333281471170U;
            aOrbiterI = RotL64((aOrbiterI * 7063116837752240891U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 4531604274893197209U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 3453280714992341288U;
            aOrbiterH = RotL64((aOrbiterH * 8390029711127907805U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 116623650872661533U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 6565636510115095988U;
            aOrbiterG = RotL64((aOrbiterG * 9691897067492501177U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 10303258439817808058U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterK) ^ 10917642773040237611U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]) ^ RotL64(aNonceWordE, 23U);
            aOrbiterJ = RotL64((aOrbiterJ * 10232856828372963363U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 2087058228468680821U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 3691125545393861889U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1768745056298937903U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 9240209357066002219U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 7645250700232422804U;
            aOrbiterK = RotL64((aOrbiterK * 6762116797395687607U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 9859862257084218280U) + RotL64(aNonceWordH, 25U);
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 6771552164800695068U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11063630807191661109U), 47U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 13U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 48U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterD, 30U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 39U) + RotL64(aOrbiterA, 21U)) + aOrbiterC) + RotL64(aCarry, 23U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 47U) + aOrbiterH) + RotL64(aOrbiterA, 53U));
            aWandererA = aWandererA + (((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 21U) + aOrbiterK) + RotL64(aOrbiterD, 5U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 18U) + aOrbiterI) + RotL64(aOrbiterD, 19U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 53U) + aOrbiterF) + RotL64(aOrbiterE, 47U)) + RotL64(aNonceWordB, 9U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 37U) + aOrbiterB) + RotL64(aOrbiterE, 43U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterI, 38U)) + aOrbiterG) + RotL64(aNonceWordF, 39U));
            aWandererI = aWandererI + (((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 27U)) + aOrbiterH) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 42U) + RotL64(aOrbiterK, 51U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (RotL64(aWandererD, 44U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + RotL64(aWandererC, 27U);
            aCarry = aCarry + RotL64(aIngress, 42U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 27U) ^ RotL64(aNonceWordG, 43U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 6696U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8450U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 11U) ^ RotL64(aNonceWordD, 21U)) ^ RotL64(aNonceWordH, 51U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 10830U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 9345U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCross, 6U)) ^ (RotL64(aCarry, 53U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 23U)) + 10336802574069791273U;
            aOrbiterK = (((aWandererG + RotL64(aIngress, 29U)) + RotL64(aCarry, 5U)) + 169025388197058936U) + aPhaseFOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aScatter, 11U)) + RotL64(aCarry, 29U)) + 6541354188379168846U;
            aOrbiterG = ((aWandererK + RotL64(aCross, 5U)) + RotL64(aCarry, 11U)) + 16223920526599306104U;
            aOrbiterH = (((aWandererD + RotL64(aScatter, 54U)) + 12756613707692514808U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1]) + RotL64(aNonceWordF, 39U);
            aOrbiterD = (aWandererC + RotL64(aPrevious, 3U)) + 5082475548176484035U;
            aOrbiterA = (aWandererB + RotL64(aCross, 27U)) + 4907435526952698526U;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 21U)) + 14236627073831834337U) + RotL64(aNonceWordA, 49U);
            aOrbiterE = (aWandererA + RotL64(aScatter, 51U)) + 11502511046130497584U;
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 19U)) + 3679044835550219497U;
            aOrbiterC = (aWandererH + RotL64(aIngress, 60U)) + 11254838916686736746U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 10582608424233200966U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 10449735026385340313U;
            aOrbiterB = RotL64((aOrbiterB * 7363770199734997411U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 4628253464169957835U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 17664454668473204465U;
            aOrbiterK = RotL64((aOrbiterK * 4234720298731378527U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 3798386391743884889U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 1379331161819246587U;
            aOrbiterH = RotL64((aOrbiterH * 13086160171095077295U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 9816600392407327227U) + RotL64(aNonceWordE, 53U);
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 16781971616348376878U;
            aOrbiterA = RotL64((aOrbiterA * 12503867584828289879U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 4807797577690520554U) + RotL64(aNonceWordB, 22U);
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 2492057261148595922U;
            aOrbiterE = RotL64((aOrbiterE * 9453302540675483005U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 7909676419643119585U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 256053568910383007U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11965085163352053161U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 16179914439220412472U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 3968867762761955845U;
            aOrbiterG = RotL64((aOrbiterG * 7473632378251893139U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 7474832923901283742U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 4736994731050735779U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9839654409121414047U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 596484364660389193U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 13822222274464306169U;
            aOrbiterI = RotL64((aOrbiterI * 1723502278319885511U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 16307920280681985443U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 3505106171801702915U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8479675421552861243U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 4987142580981135150U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 10336802574069791273U;
            aOrbiterC = RotL64((aOrbiterC * 2670706512498539705U), 53U);
            //
            aIngress = RotL64(aOrbiterG, 29U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterE, 58U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterC, 51U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + RotL64(aOrbiterB, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 53U) + aOrbiterI) + RotL64(aOrbiterK, 60U));
            aWandererF = aWandererF + ((RotL64(aCross, 23U) + RotL64(aOrbiterG, 11U)) + aOrbiterF);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterK, 3U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterB, 37U)) + aOrbiterH);
            aWandererH = aWandererH ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterI, 13U)) + aOrbiterG);
            aWandererD = aWandererD + ((((RotL64(aScatter, 13U) + aOrbiterE) + RotL64(aOrbiterB, 43U)) + RotL64(aCarry, 3U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 44U) + aOrbiterC) + RotL64(aOrbiterG, 53U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 51U) + aOrbiterH) + RotL64(aOrbiterC, 57U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 21U) + aOrbiterG) + RotL64(aOrbiterA, 18U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterD, 39U)) + RotL64(aCarry, 23U)) + RotL64(aNonceWordD, 19U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 38U) + aOrbiterE) + RotL64(aOrbiterC, 47U)) + RotL64(aNonceWordH, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 10U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + RotL64(aWandererC, 60U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 60U) ^ RotL64(aNonceWordB, 37U)) ^ RotL64(aNonceWordF, 13U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 14214U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 13476U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 43U) ^ RotL64(aNonceWordD, 11U)) ^ RotL64(aNonceWordC, 56U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 13634U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneC[((aIndex + 13186U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aPrevious, 13U)) ^ (RotL64(aIngress, 43U) + RotL64(aCarry, 56U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = ((aWandererI + RotL64(aScatter, 47U)) + RotL64(aCarry, 23U)) + 13854738573712660276U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 43U)) + 16835460633412286294U) + aPhaseFOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aCross, 35U)) + 6785859293758091931U;
            aOrbiterK = (((aWandererE + RotL64(aIngress, 23U)) + RotL64(aCarry, 39U)) + 126317283127992659U) + RotL64(aNonceWordC, 57U);
            aOrbiterG = (aWandererD + RotL64(aScatter, 51U)) + 7568963536291415413U;
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 4U)) + 12294016745653004819U;
            aOrbiterB = (aWandererB + RotL64(aIngress, 27U)) + 18269588932920281147U;
            aOrbiterC = (aWandererC + RotL64(aCross, 39U)) + 5872406424994751026U;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 29U)) + 7764434758831474129U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 54U)) + 4804168969415573371U) + aPhaseFOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aIngress, 13U)) + 959601763507651280U) + RotL64(aNonceWordB, 17U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 9257644462479293048U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 14332699366894494579U;
            aOrbiterJ = RotL64((aOrbiterJ * 8829304078930625541U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 10487012596470786004U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 612729229562321440U;
            aOrbiterF = RotL64((aOrbiterF * 11380387280507726003U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 7845523921295625315U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 12742115479740024747U;
            aOrbiterD = RotL64((aOrbiterD * 15578543510683986421U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 10294667720904610944U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 14369711143154904567U;
            aOrbiterG = RotL64((aOrbiterG * 13753005602288309379U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 10918344717497681894U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 18136794828308636957U;
            aOrbiterC = RotL64((aOrbiterC * 17899418637978002409U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 14378638206724886404U) + RotL64(aNonceWordH, 7U);
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 7077588188450008059U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 485375960462924335U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 8941870012851971932U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 15242087859620352399U;
            aOrbiterE = RotL64((aOrbiterE * 4963002810455992839U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 10395280254030875387U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 6826595516076975980U) ^ RotL64(aNonceWordA, 21U);
            aOrbiterK = RotL64((aOrbiterK * 6198886240333178001U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 10407910809564430664U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 6368255889263255730U;
            aOrbiterB = RotL64((aOrbiterB * 3809496492809859731U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 6365669830464231626U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 596785214258266904U;
            aOrbiterI = RotL64((aOrbiterI * 6338109335634389561U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 4807438574488830717U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 13854738573712660276U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6954368463489446551U), 29U);
            //
            aIngress = RotL64(aOrbiterC, 37U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterF, 51U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 56U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 21U));
            aIngress = aIngress + RotL64(aOrbiterK, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aIngress, 5U) + RotL64(aOrbiterI, 47U)) + aOrbiterC);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterA, 19U)) + aOrbiterC);
            aWandererF = aWandererF + ((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterI, 40U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterA, 3U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 30U) + RotL64(aOrbiterI, 51U)) + aOrbiterG) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterF, 23U)) + aOrbiterI) + RotL64(aNonceWordD, 58U));
            aWandererG = aWandererG + (((RotL64(aScatter, 37U) + RotL64(aOrbiterB, 53U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 21U) + RotL64(aOrbiterE, 11U)) + aOrbiterJ) + RotL64(aNonceWordE, 47U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 58U) + RotL64(aOrbiterD, 13U)) + aOrbiterK) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterK, 29U)) + aOrbiterG);
            aWandererB = aWandererB + ((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 38U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererC, 30U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + (RotL64(aWandererJ, 60U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 14U) ^ RotL64(aNonceWordH, 27U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 16801U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((aIndex + 16635U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 57U) ^ RotL64(aNonceWordC, 37U)) ^ RotL64(aNonceWordB, 47U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18665U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneD[((aIndex + 21802U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCarry, 23U)) ^ (RotL64(aPrevious, 58U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = (aWandererJ + RotL64(aScatter, 41U)) + 11700815697312060726U;
            aOrbiterF = ((aWandererH + RotL64(aCross, 34U)) + RotL64(aCarry, 41U)) + 11808423452327465441U;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 23U)) + RotL64(aCarry, 13U)) + 8670503858631730886U;
            aOrbiterH = (aWandererK + RotL64(aIngress, 21U)) + 2400061067991988544U;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 53U)) + 16163118178366229686U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 19U)) + 3280178595904941068U) + RotL64(aNonceWordE, 11U);
            aOrbiterC = (aWandererC + RotL64(aScatter, 5U)) + 3298683600817047727U;
            aOrbiterK = ((aWandererB + RotL64(aIngress, 51U)) + 16321624053445183574U) + RotL64(aNonceWordH, 35U);
            aOrbiterA = ((aWandererA + RotL64(aCross, 13U)) + 6730229877611375225U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aIngress, 26U)) + RotL64(aCarry, 57U)) + 10162830636713641322U;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 43U)) + 15646771327759599256U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 14841751262270544102U) + RotL64(aNonceWordD, 9U);
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 9545541117228834895U;
            aOrbiterG = RotL64((aOrbiterG * 11529769874752969377U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 14676615635857599982U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 1231768638470558855U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2716808508509014677U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 1945905595345404833U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 1406171421638586846U;
            aOrbiterD = RotL64((aOrbiterD * 4577864352425476233U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 1970292335806697198U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 12309719390375013297U;
            aOrbiterC = RotL64((aOrbiterC * 16540660957923687327U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 5352135521358954576U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 15465675376193501658U;
            aOrbiterK = RotL64((aOrbiterK * 16385761112921041387U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 2842123638916600369U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 3544764287036748668U;
            aOrbiterA = RotL64((aOrbiterA * 3360772950777850115U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 6038297172906492282U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 10249342332287140970U;
            aOrbiterB = RotL64((aOrbiterB * 16701083081566042277U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 1662076777040529446U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 1949705569959740274U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11340691546658994529U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 13934194245417822360U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 5720408806425535958U) ^ RotL64(aNonceWordC, 17U);
            aOrbiterI = RotL64((aOrbiterI * 15237561081637415383U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 2209251362417210658U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 4917447930929521699U;
            aOrbiterF = RotL64((aOrbiterF * 17489570156694692569U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 14817115766683623486U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 11700815697312060726U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16982411053956669181U), 21U);
            //
            aIngress = RotL64(aOrbiterD, 3U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 60U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterG, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 11U)) + aOrbiterK);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 54U) + RotL64(aOrbiterG, 29U)) + aOrbiterA);
            aWandererD = aWandererD ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterB, 19U)) + aOrbiterF) + RotL64(aNonceWordG, 8U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterK, 4U)) + aOrbiterF);
            aWandererE = aWandererE ^ ((RotL64(aCross, 5U) + aOrbiterF) + RotL64(aOrbiterI, 35U));
            aWandererF = aWandererF + (((RotL64(aIngress, 35U) + aOrbiterJ) + RotL64(aOrbiterH, 37U)) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 50U) + RotL64(aOrbiterG, 47U)) + aOrbiterK);
            aWandererH = aWandererH + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 39U)) + aOrbiterB) + RotL64(aCarry, 19U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterH, 52U)) + aOrbiterD) + RotL64(aNonceWordA, 31U));
            aWandererC = aWandererC + (((RotL64(aIngress, 21U) + aOrbiterG) + RotL64(aOrbiterJ, 23U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterH, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 20U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + RotL64(aWandererI, 60U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 5U) ^ RotL64(aNonceWordF, 43U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23093U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27226U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 4U) ^ RotL64(aNonceWordE, 13U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 23021U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneA[((aIndex + 26923U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aIngress, 5U)) + (RotL64(aPrevious, 28U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = (((aWandererE + RotL64(aCross, 12U)) + 15045917390223766480U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1]) + RotL64(aNonceWordB, 54U);
            aOrbiterC = (aWandererB + RotL64(aScatter, 43U)) + 10763054007033668758U;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 27U)) + RotL64(aCarry, 29U)) + 13190170142593666607U;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 39U)) + RotL64(aCarry, 57U)) + 9657025731441167065U;
            aOrbiterK = (aWandererF + RotL64(aScatter, 51U)) + 11433367178975954211U;
            aOrbiterH = (aWandererI + RotL64(aIngress, 5U)) + 17904920143996810366U;
            aOrbiterD = ((aWandererD + RotL64(aCross, 47U)) + RotL64(aCarry, 51U)) + 3244383020512113283U;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 36U)) + 6538815775171139091U;
            aOrbiterE = (aWandererG + RotL64(aIngress, 3U)) + 7195368312757976343U;
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 57U)) + 18134430713910279374U) + RotL64(aNonceWordG, 57U);
            aOrbiterB = ((aWandererH + RotL64(aCross, 21U)) + 6571776588427107976U) + aPhaseFOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 11830778129647517758U) + RotL64(aNonceWordF, 39U);
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 9793702760907767365U;
            aOrbiterG = RotL64((aOrbiterG * 4096246227968677179U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 2287235876793192036U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 8951959188326141794U;
            aOrbiterH = RotL64((aOrbiterH * 9968356718110753845U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 7583061790273240157U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 3571364625022806085U;
            aOrbiterI = RotL64((aOrbiterI * 6238360922735480669U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 13869345563551689212U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 277480328952975002U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1057564597096163085U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 4983735092494677578U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 9490022869381030928U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12926352917961703123U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 7928039573014765566U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 6504190875809407084U;
            aOrbiterJ = RotL64((aOrbiterJ * 14648214826494826711U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 2787985600176307413U) + RotL64(aNonceWordE, 5U);
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 16308785053443116826U;
            aOrbiterD = RotL64((aOrbiterD * 17867565986311256691U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 12788128335006767824U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 1187040019537798339U;
            aOrbiterE = RotL64((aOrbiterE * 10834905007658184183U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 10771230162770496645U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 6542421559654716320U;
            aOrbiterB = RotL64((aOrbiterB * 16829492790597069373U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 702458690970201679U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 2806140783487813070U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7415398198842270381U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 950611302199732036U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 15045917390223766480U;
            aOrbiterK = RotL64((aOrbiterK * 9358017420417979347U), 3U);
            //
            aIngress = RotL64(aOrbiterA, 53U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + (RotL64(aOrbiterB, 10U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + RotL64(aOrbiterC, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterH, 57U)) + aOrbiterD);
            aWandererI = aWandererI + (((RotL64(aIngress, 48U) + aOrbiterI) + RotL64(aOrbiterA, 27U)) + RotL64(aCarry, 57U));
            aWandererF = aWandererF ^ ((((RotL64(aCross, 27U) + RotL64(aOrbiterA, 50U)) + aOrbiterB) + RotL64(aNonceWordH, 51U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 41U)) + aOrbiterB);
            aWandererC = aWandererC ^ ((RotL64(aCross, 37U) + aOrbiterC) + RotL64(aOrbiterJ, 35U));
            aWandererG = aWandererG + (((RotL64(aScatter, 51U) + aOrbiterE) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterJ, 10U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterK, 43U)) + aOrbiterA) + RotL64(aNonceWordD, 25U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterE, 53U));
            aWandererE = aWandererE + ((RotL64(aCross, 5U) + RotL64(aOrbiterC, 39U)) + aOrbiterH);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 14U) + RotL64(aOrbiterC, 23U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 60U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 56U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 47U) ^ RotL64(aNonceWordH, 5U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27892U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((aIndex + 28312U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 29U) ^ RotL64(aNonceWordG, 56U)) ^ RotL64(aNonceWordD, 5U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28713U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((aIndex + 32747U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCross, 27U)) + (RotL64(aIngress, 41U) ^ RotL64(aCarry, 12U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = (aWandererA + RotL64(aScatter, 11U)) + 5573188770530340913U;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 44U)) + 1431772230889897111U) + RotL64(aNonceWordC, 48U);
            aOrbiterH = (aWandererG + RotL64(aPrevious, 3U)) + 4809192776429682319U;
            aOrbiterG = (aWandererE + RotL64(aCross, 37U)) + 5576603692574369341U;
            aOrbiterB = (((aWandererC + RotL64(aScatter, 13U)) + RotL64(aCarry, 27U)) + 2720143226007220386U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aIngress, 50U)) + 17220328778565331629U) + RotL64(aNonceWordG, 51U);
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 29U)) + 9629485808442089423U;
            aOrbiterC = ((aWandererB + RotL64(aCross, 21U)) + 1136998437010390983U) + aPhaseFOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aIngress, 19U)) + RotL64(aCarry, 53U)) + 11893390497814523841U;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 39U)) + RotL64(aCarry, 23U)) + 1764986431917532370U;
            aOrbiterK = (aWandererD + RotL64(aPrevious, 53U)) + 1741014798007010376U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 12221368453236547044U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 7694538641172350430U;
            aOrbiterH = RotL64((aOrbiterH * 8439120733670016501U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 17472344518811560603U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 3308740700728172984U;
            aOrbiterB = RotL64((aOrbiterB * 15290400462887712083U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 9535358833412446771U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 11192312491731312451U;
            aOrbiterF = RotL64((aOrbiterF * 17405609148475445743U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 14850451970047190039U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 11932493299452443256U;
            aOrbiterJ = RotL64((aOrbiterJ * 7964808728820467795U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 5972619895614731870U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 17174497535809891690U;
            aOrbiterC = RotL64((aOrbiterC * 15471084511364572533U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 17412894714378898351U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 14675615208706549810U;
            aOrbiterD = RotL64((aOrbiterD * 7864845089606499769U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 16116792108013658523U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 9702262005960966336U;
            aOrbiterE = RotL64((aOrbiterE * 970452849653781703U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 17337264966818542841U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 7004462033775827275U;
            aOrbiterK = RotL64((aOrbiterK * 11943575980344402681U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 17499850384482055438U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 1839357713256560566U;
            aOrbiterI = RotL64((aOrbiterI * 12943750650487416281U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 8144238113917577524U) + RotL64(aNonceWordE, 13U);
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 888195876227325908U;
            aOrbiterA = RotL64((aOrbiterA * 7941506708630993709U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 5081763359501717653U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterK) ^ 5573188770530340913U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1]) ^ RotL64(aNonceWordF, 59U);
            aOrbiterG = RotL64((aOrbiterG * 9699901099898698965U), 37U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterI, 13U);
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + (RotL64(aOrbiterF, 36U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterJ, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aScatter, 36U) + aOrbiterC) + RotL64(aOrbiterA, 47U)) + RotL64(aNonceWordB, 41U)) + aPhaseFWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 39U) + aOrbiterJ) + RotL64(aOrbiterG, 44U));
            aWandererB = aWandererB + (((RotL64(aCross, 47U) + RotL64(aOrbiterH, 3U)) + aOrbiterD) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterD, 57U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 43U) + aOrbiterJ) + RotL64(aOrbiterK, 37U)) + RotL64(aCarry, 41U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterB, 27U)) + aOrbiterK);
            aWandererD = aWandererD + (((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterE, 14U)) + RotL64(aNonceWordD, 3U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 14U) + RotL64(aOrbiterI, 29U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterB, 35U)) + aOrbiterD);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 51U) + aOrbiterF) + RotL64(aOrbiterG, 51U));
            aWandererH = aWandererH + (((RotL64(aCross, 23U) + RotL64(aOrbiterB, 5U)) + aOrbiterH) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + (RotL64(aWandererD, 46U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + RotL64(aWandererA, 13U);
            aCarry = aCarry + RotL64(aIngress, 18U);
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

void TwistExpander_Tennis_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 1307U)) & S_BLOCK1], 36U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 6077U)) & W_KEY1], 3U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 824U)) & W_KEY1], 13U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 4175U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCarry, 5U)) ^ (RotL64(aPrevious, 37U) ^ RotL64(aCross, 56U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (aWandererB + RotL64(aScatter, 22U)) + 18087125778766689269U;
            aOrbiterH = (aWandererF + RotL64(aCross, 51U)) + 13710545066503235196U;
            aOrbiterK = (((aWandererG + RotL64(aPrevious, 5U)) + RotL64(aCarry, 11U)) + 1701939704736254645U) + aPhaseCOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aIngress, 27U)) + RotL64(aCarry, 51U)) + 8064093611384019909U;
            aOrbiterG = (aWandererH + RotL64(aPrevious, 47U)) + 16623332751533885431U;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 11U)) + RotL64(aCarry, 43U)) + 15590129153794910109U;
            aOrbiterF = (aWandererA + RotL64(aIngress, 41U)) + 7413312683079107383U;
            aOrbiterJ = (aWandererC + RotL64(aCross, 37U)) + 4186064478651458810U;
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 60U)) + 5501191643940735954U) + aPhaseCOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 11064645242200570835U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 13825922087298055833U;
            aOrbiterK = RotL64((aOrbiterK * 7529317892716108867U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 5944980709887369970U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 8181136916070569646U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 395183021205661827U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 15442336949157292482U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 11580554435240641337U;
            aOrbiterJ = RotL64((aOrbiterJ * 6654637892858767739U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 11240018128174598322U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 2027565596050777471U;
            aOrbiterD = RotL64((aOrbiterD * 18048186560314431815U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 16425887196883725233U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 16828683527588834095U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17746289103235902485U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 9923829146479008804U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 6669171007279929454U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 681823450939955099U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 3902430046523165149U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 6739998149289590041U;
            aOrbiterF = RotL64((aOrbiterF * 2675037435528416821U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 16014401255534234075U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 14741857638680634564U;
            aOrbiterH = RotL64((aOrbiterH * 8723611021403369393U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 5064807861673260054U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 968747317273200299U;
            aOrbiterG = RotL64((aOrbiterG * 14122304002722582329U), 5U);
            //
            aIngress = RotL64(aOrbiterH, 51U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 48U));
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterB, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterG, 23U)) + aOrbiterH);
            aWandererF = aWandererF + ((RotL64(aIngress, 18U) + RotL64(aOrbiterF, 58U)) + aOrbiterH);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterC, 29U)) + aOrbiterD);
            aWandererE = aWandererE + ((((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 39U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 27U) + aOrbiterJ) + RotL64(aOrbiterC, 19U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterI, 48U)) + aOrbiterC) + RotL64(aCarry, 51U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterJ, 43U));
            aWandererH = aWandererH + ((RotL64(aCross, 6U) + RotL64(aOrbiterK, 5U)) + aOrbiterI);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 23U) + aOrbiterH) + RotL64(aOrbiterD, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (RotL64(aWandererD, 36U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 27U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 12618U)) & S_BLOCK1], 5U) ^ RotL64(mSource[((aIndex + 15539U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 11801U)) & W_KEY1], 21U) ^ RotL64(aKeyRowReadB[((aIndex + 14604U)) & W_KEY1], 40U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 29U) ^ RotL64(aCarry, 60U)) ^ (RotL64(aPrevious, 47U) + RotL64(aCross, 13U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (aWandererG + RotL64(aScatter, 48U)) + 9914837590440975587U;
            aOrbiterI = ((aWandererC + RotL64(aCross, 23U)) + 6706125076401958051U) + aPhaseCOrbiterAssignSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = (aWandererF + RotL64(aPrevious, 13U)) + 16570817772679258409U;
            aOrbiterB = (aWandererA + RotL64(aIngress, 39U)) + 6843705658115186948U;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 57U)) + 16099930446791572351U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = ((aWandererI + RotL64(aIngress, 19U)) + RotL64(aCarry, 3U)) + 5420550009556030459U;
            aOrbiterJ = (aWandererK + RotL64(aCross, 35U)) + 5729549069420177477U;
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 44U)) + RotL64(aCarry, 47U)) + 15590601126188675834U;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 27U)) + RotL64(aCarry, 19U)) + 13044027390998620029U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 11068338135659636772U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 6584988841809544332U;
            aOrbiterK = RotL64((aOrbiterK * 1683336180438945439U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 8516813219883915404U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 10647314042912492785U;
            aOrbiterG = RotL64((aOrbiterG * 15559481057047148785U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 201691689889605304U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 15512161798401184003U;
            aOrbiterJ = RotL64((aOrbiterJ * 11473219183982564709U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 3883760518944464145U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 13861805129175491145U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17194438894492581181U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 12019138626550801486U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 13030350224959652248U;
            aOrbiterD = RotL64((aOrbiterD * 11724200983306280107U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 2643807255422544248U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 4127143302485631794U;
            aOrbiterA = RotL64((aOrbiterA * 5441038881111578487U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 14602951930809633069U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 4555737199162278494U;
            aOrbiterB = RotL64((aOrbiterB * 12415825635220991865U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 6343143902997169834U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 10404783711336491985U;
            aOrbiterC = RotL64((aOrbiterC * 6235474458879439079U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 7406959231434835393U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 6684368109277850196U;
            aOrbiterI = RotL64((aOrbiterI * 8760360417572331159U), 27U);
            //
            aIngress = RotL64(aOrbiterD, 53U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterB, 24U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aScatter, 39U) + aOrbiterB) + RotL64(aOrbiterG, 11U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 23U) + aOrbiterI) + RotL64(aOrbiterB, 35U));
            aWandererE = aWandererE + (((RotL64(aIngress, 58U) + RotL64(aOrbiterK, 19U)) + aOrbiterJ) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterD, 53U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterG, 42U)) + aOrbiterI) + RotL64(aCarry, 53U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterB, 23U));
            aWandererG = aWandererG + ((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterI, 47U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 18U) + RotL64(aOrbiterJ, 27U)) + aOrbiterF) + aPhaseCWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterC, 60U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 6U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 21555U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneA[((aIndex + 16550U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 19321U)) & W_KEY1], 36U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 24067U)) & W_KEY1], 21U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aPrevious, 27U)) ^ (RotL64(aIngress, 13U) ^ RotL64(aCarry, 54U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = (aWandererE + RotL64(aCross, 53U)) + 12692813903177772178U;
            aOrbiterC = (((aWandererA + RotL64(aScatter, 60U)) + RotL64(aCarry, 11U)) + 7112496446691277899U) + aPhaseCOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aIngress, 19U)) + 2112247138290568813U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 23U)) + RotL64(aCarry, 27U)) + 3699421080882855947U;
            aOrbiterF = ((aWandererF + RotL64(aCross, 29U)) + RotL64(aCarry, 53U)) + 13761832028354380922U;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 47U)) + 9243822514887600214U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 11U)) + 6863833516853046129U;
            aOrbiterG = (aWandererK + RotL64(aIngress, 36U)) + 8863897995943098018U;
            aOrbiterH = (aWandererI + RotL64(aScatter, 5U)) + 13346785686701467520U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 15309543066305531619U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 17515530938817919111U;
            aOrbiterD = RotL64((aOrbiterD * 16625193986319048245U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 760493237816424254U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 7282586354117620860U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2327153408185290635U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 4129706068526969105U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 7020175432730888755U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10095158356907592239U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 9102258982216515596U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 10822031305361453690U;
            aOrbiterC = RotL64((aOrbiterC * 2036205056490578491U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 12571477440964330246U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 8436347026653095199U;
            aOrbiterF = RotL64((aOrbiterF * 17930734781213681573U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 14214789872073941940U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 12915911919403385001U;
            aOrbiterA = RotL64((aOrbiterA * 13161681603528031511U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 15443240166233851298U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 7311369180113240915U;
            aOrbiterI = RotL64((aOrbiterI * 13339195007946889423U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 12976516224995960015U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 7823308381434556721U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 502385172763861451U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 4829417661664149137U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 16306394751966719700U;
            aOrbiterH = RotL64((aOrbiterH * 5294376579588592157U), 41U);
            //
            aIngress = RotL64(aOrbiterJ, 44U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + RotL64(aOrbiterA, 10U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterD, 57U)) + aOrbiterC);
            aWandererA = aWandererA + ((RotL64(aIngress, 43U) + aOrbiterK) + RotL64(aOrbiterG, 13U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterG, 36U)) + aOrbiterI);
            aWandererK = aWandererK + ((RotL64(aScatter, 5U) + aOrbiterH) + RotL64(aOrbiterJ, 3U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 48U) + RotL64(aOrbiterF, 19U)) + aOrbiterK);
            aWandererB = aWandererB + ((((RotL64(aCross, 35U) + RotL64(aOrbiterK, 41U)) + aOrbiterD) + RotL64(aCarry, 23U)) + aPhaseCWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 53U)) + aOrbiterJ);
            aWandererI = aWandererI + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterC, 24U)) + aOrbiterA) + RotL64(aCarry, 11U)) + aPhaseCWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 12U) + aOrbiterH) + RotL64(aOrbiterG, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 22U));
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 25683U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28504U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27238U)) & S_BLOCK1], 37U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 24828U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 12U) + RotL64(aIngress, 57U)) ^ (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = (aWandererK + RotL64(aIngress, 43U)) + 7632760812370906911U;
            aOrbiterD = (aWandererE + RotL64(aPrevious, 35U)) + 6007174525479723089U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 39U)) + 3362829642521821048U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aScatter, 48U)) + 18009548556107978286U;
            aOrbiterA = (aWandererG + RotL64(aIngress, 21U)) + 17880909432272697327U;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 27U)) + RotL64(aCarry, 37U)) + 15961567935420752568U;
            aOrbiterI = (((aWandererF + RotL64(aCross, 57U)) + RotL64(aCarry, 21U)) + 10136559064656837921U) + aPhaseCOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aScatter, 10U)) + RotL64(aCarry, 53U)) + 17622019364405410277U;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 5U)) + 6927494824421416306U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 7125170407794874847U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 12342273503071032250U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 867417849555857179U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 14997696377476124836U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 14874498694181230698U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4026127545746010937U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 2549397729130885686U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 4217995818662767955U;
            aOrbiterI = RotL64((aOrbiterI * 5525525344485251063U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 4706089044415442525U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 17983900172670031015U;
            aOrbiterH = RotL64((aOrbiterH * 541552737180932879U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 1904937798143929988U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 10620877287033139483U;
            aOrbiterF = RotL64((aOrbiterF * 16711012562024287213U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 15681091173163181525U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 2655543246639000084U;
            aOrbiterK = RotL64((aOrbiterK * 16686375598149755947U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 2647895110857289213U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 5581609212017175954U;
            aOrbiterE = RotL64((aOrbiterE * 15330263616699031311U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 13609076329627787987U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 6244266279516622070U;
            aOrbiterJ = RotL64((aOrbiterJ * 12488345779236971095U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 5289624364508923581U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 16351476803965903112U;
            aOrbiterD = RotL64((aOrbiterD * 9012522724650442597U), 41U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 39U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + (RotL64(aOrbiterH, 24U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 5U)) + aOrbiterC);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterC, 58U)) + aOrbiterH);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 43U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 48U) + aOrbiterK) + RotL64(aOrbiterA, 53U));
            aWandererB = aWandererB + ((RotL64(aIngress, 23U) + RotL64(aOrbiterI, 35U)) + aOrbiterA);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 37U) + aOrbiterE) + RotL64(aOrbiterI, 14U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 5U) + aOrbiterJ) + RotL64(aOrbiterF, 29U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterI, 23U)) + aOrbiterH);
            aWandererF = aWandererF + (((RotL64(aScatter, 60U) + RotL64(aOrbiterA, 41U)) + aOrbiterJ) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 12U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + RotL64(aWandererB, 29U);
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

void TwistExpander_Tennis_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 974U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1995U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 592U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 2569U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 48U) + RotL64(aCarry, 19U)) + (RotL64(aPrevious, 35U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 57U)) + RotL64(aCarry, 57U)) + 14157904117287696136U;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 21U)) + RotL64(aCarry, 5U)) + 7369512677371640676U;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 36U)) + 8411250745902073798U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aIngress, 3U)) + RotL64(aCarry, 29U)) + 5002041814539710275U;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 47U)) + 9538041410816283124U) + aPhaseDOrbiterAssignSaltD[((aIndex + 20U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 5210700103927513061U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 7600709399101287982U;
            aOrbiterG = RotL64((aOrbiterG * 6777896926889560889U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 2366369466696580499U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 5544575244203019109U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16231219246786333057U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 8710073749110329779U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 15998211310115361630U;
            aOrbiterH = RotL64((aOrbiterH * 15275657696897688955U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 15354357553877376422U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 10657523549259276169U;
            aOrbiterJ = RotL64((aOrbiterJ * 13695239532898311073U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 10405750198355464768U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 3465819693133515142U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14678343718277562799U), 11U);
            //
            aIngress = RotL64(aOrbiterF, 21U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterF, 19U)) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterE, 58U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 58U) + RotL64(aOrbiterF, 47U)) + aOrbiterH) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 37U) + aOrbiterH) + RotL64(aOrbiterJ, 5U));
            aWandererF = aWandererF + (((RotL64(aIngress, 21U) + RotL64(aOrbiterH, 37U)) + aOrbiterE) + aPhaseDWandererUpdateSaltC[((aIndex + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 46U));
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 14866U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15383U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14692U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((aIndex + 15087U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 6U) ^ RotL64(aCross, 21U)) + (RotL64(aPrevious, 53U) + RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (aWandererI + RotL64(aIngress, 29U)) + 9855743441035905047U;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 41U)) + RotL64(aCarry, 35U)) + 8426286937143990276U;
            aOrbiterA = (((aWandererA + RotL64(aScatter, 21U)) + RotL64(aCarry, 23U)) + 7146752367170267002U) + aPhaseDOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = (((aWandererG + RotL64(aCross, 6U)) + RotL64(aCarry, 5U)) + 12947210066678101726U) + aPhaseDOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = (aWandererF + RotL64(aPrevious, 57U)) + 15902163559925328965U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 8506649889346449469U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 8226286036430263052U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7264199281303956141U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 2703047093452420216U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 6769351326360139560U;
            aOrbiterC = RotL64((aOrbiterC * 5318104980014706265U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 9857025533281333281U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 238297452132277585U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12974709749856065985U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 7203572312072908931U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 12497027346166575632U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1703586436725662307U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 473851890609048879U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 1664484956453886047U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8566500756326590209U), 5U);
            //
            aIngress = RotL64(aOrbiterJ, 6U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 53U) + aOrbiterA) + RotL64(aOrbiterC, 27U));
            aWandererI = aWandererI + (((RotL64(aCross, 19U) + RotL64(aOrbiterC, 53U)) + aOrbiterB) + RotL64(aCarry, 51U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterB, 37U)) + aOrbiterE) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 36U) + RotL64(aOrbiterJ, 5U)) + aOrbiterE) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 5U) + aOrbiterA) + RotL64(aOrbiterJ, 18U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 4U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 19999U)) & S_BLOCK1], 34U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 21797U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 22263U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneC[((aIndex + 24086U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 54U) ^ RotL64(aPrevious, 3U)) + (RotL64(aIngress, 41U) + RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = ((aWandererK + RotL64(aScatter, 47U)) + 2558105147674438050U) + aPhaseDOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (((aWandererI + RotL64(aIngress, 39U)) + RotL64(aCarry, 53U)) + 15856662514774702561U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 35U)) + 13346869226246584582U;
            aOrbiterB = ((aWandererD + RotL64(aCross, 30U)) + RotL64(aCarry, 19U)) + 7632111846116243973U;
            aOrbiterA = (aWandererA + RotL64(aPrevious, 11U)) + 2102101361626976279U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 5605968705067851563U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 6842483186584326681U;
            aOrbiterH = RotL64((aOrbiterH * 11344798544990575365U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 5559797213819425064U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 12422313931331576759U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7399849122565913401U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 2751024420047872601U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 11031320239359798610U;
            aOrbiterK = RotL64((aOrbiterK * 8607639453141148025U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 14366375309473793217U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 11971479429768505316U;
            aOrbiterB = RotL64((aOrbiterB * 10063001532313098203U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 3947595951884469542U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 17882767922372770896U;
            aOrbiterA = RotL64((aOrbiterA * 3361906348965810211U), 11U);
            //
            aIngress = RotL64(aOrbiterH, 13U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterB, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 50U) + aOrbiterA) + RotL64(aOrbiterH, 39U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 37U) + aOrbiterB) + RotL64(aOrbiterK, 11U)) + RotL64(aCarry, 37U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 27U) + aOrbiterB) + RotL64(aOrbiterH, 3U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 56U)) + aOrbiterB) + RotL64(aCarry, 57U)) + aPhaseDWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 13U) + aOrbiterK) + RotL64(aOrbiterD, 47U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 56U));
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 30566U)) & S_BLOCK1], 20U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28501U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26123U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 25840U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 27U) ^ RotL64(aCross, 47U)) + (RotL64(aCarry, 13U) ^ RotL64(aIngress, 60U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (((aWandererB + RotL64(aScatter, 38U)) + RotL64(aCarry, 27U)) + 10726035965553989335U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aIngress, 29U)) + RotL64(aCarry, 41U)) + 967354339530195662U;
            aOrbiterH = ((aWandererK + RotL64(aCross, 47U)) + 10834593005478605624U) + aPhaseDOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 21U)) + RotL64(aCarry, 3U)) + 1012888282838656933U;
            aOrbiterA = (aWandererE + RotL64(aCross, 5U)) + 15283530351725183253U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 11724495956731703750U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 4288330117317505776U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2738997410474076757U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 10894778070022873473U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 15563886747621617467U;
            aOrbiterF = RotL64((aOrbiterF * 17884709931569040065U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 11182488628562891937U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 10420140066310588580U;
            aOrbiterK = RotL64((aOrbiterK * 13898299782819948719U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 11775138062167543111U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 16545391898578161683U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14588306527161321535U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 1550144656312299266U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 14903504853138279883U;
            aOrbiterA = RotL64((aOrbiterA * 8003033561266164387U), 53U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 57U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + RotL64(aOrbiterF, 46U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 54U) + RotL64(aOrbiterA, 57U)) + aOrbiterK);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterF, 34U)) + aOrbiterB) + RotL64(aCarry, 41U)) + aPhaseDWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 11U) + aOrbiterB) + RotL64(aOrbiterH, 13U));
            aWandererA = aWandererA + (((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterK, 21U)) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterF, 3U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + RotL64(aWandererB, 14U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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

void TwistExpander_Tennis_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 6734U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneC[((aIndex + 7342U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6134U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((aIndex + 1844U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aIngress, 6U)) ^ (RotL64(aCross, 39U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = (aWandererH + RotL64(aCross, 5U)) + 3248574644570178787U;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 50U)) + RotL64(aCarry, 5U)) + 4506961512959200024U;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 11U)) + RotL64(aCarry, 27U)) + 8423739774540738590U;
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 23U)) + 6593975869641735337U) + aPhaseEOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aCross, 29U)) + 16441716090557369103U;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 57U)) + 7936601450453207914U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 41U)) + RotL64(aCarry, 51U)) + 13333752583560167065U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 8013703284795432973U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 2349852779887439236U;
            aOrbiterD = RotL64((aOrbiterD * 2422888500648100783U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 5318539364763284138U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 11450957608502944376U;
            aOrbiterE = RotL64((aOrbiterE * 1957880366707810635U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 9058992558327552687U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 632095686920230926U;
            aOrbiterK = RotL64((aOrbiterK * 12460364388358520799U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 14734218428913777098U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 16344357661370784442U;
            aOrbiterI = RotL64((aOrbiterI * 15049472842002138369U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 2981145363531184308U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 14176472085175714494U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2584623327412130939U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 11198457590069700889U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 952584436750426828U;
            aOrbiterH = RotL64((aOrbiterH * 1165713888651280355U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 4311591763498985972U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 16194341833989936369U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9997934560195932575U), 51U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 51U);
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterE, 37U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterA, 14U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 35U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 14U) + aOrbiterE) + RotL64(aOrbiterI, 41U));
            aWandererK = aWandererK + ((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterK, 27U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 41U) + aOrbiterA) + RotL64(aOrbiterI, 21U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 23U) + aOrbiterD) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 30U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 21U);
            aCarry = aCarry + RotL64(aIngress, 26U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 16367U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneD[((aIndex + 16043U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 9580U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((aIndex + 15398U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 50U) + RotL64(aCross, 23U)) + (RotL64(aCarry, 11U) ^ RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = (((aWandererA + RotL64(aCross, 53U)) + RotL64(aCarry, 5U)) + 5131645209694953015U) + aPhaseEOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (((aWandererJ + RotL64(aPrevious, 19U)) + RotL64(aCarry, 43U)) + 12070391048835379854U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = ((aWandererF + RotL64(aIngress, 6U)) + RotL64(aCarry, 29U)) + 2604295836242338724U;
            aOrbiterD = (aWandererG + RotL64(aScatter, 35U)) + 14042039029284001596U;
            aOrbiterG = (aWandererB + RotL64(aIngress, 41U)) + 8914654543854559327U;
            aOrbiterC = (aWandererD + RotL64(aCross, 47U)) + 2185619407969359869U;
            aOrbiterF = (aWandererH + RotL64(aPrevious, 29U)) + 5187406295103352574U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 8022832481290871217U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 8783061916740573472U;
            aOrbiterI = RotL64((aOrbiterI * 3309891377744201773U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 10711028365596196301U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 13387065038269133571U;
            aOrbiterA = RotL64((aOrbiterA * 12444578026365205255U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 11187001318931801582U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 14191473173276034019U;
            aOrbiterD = RotL64((aOrbiterD * 2491253922434756431U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 16207761776716426435U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 9677408414452078760U;
            aOrbiterB = RotL64((aOrbiterB * 5487303383095129949U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 17812460332794370649U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 7736423148554132028U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15588733747232852555U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 17293203944059014763U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 13487243633338010243U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9468688858740539095U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 15979293016815060755U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 17645215484691359547U;
            aOrbiterF = RotL64((aOrbiterF * 1449450767288733995U), 43U);
            //
            aIngress = RotL64(aOrbiterD, 41U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + RotL64(aOrbiterB, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterC, 27U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 21U)) + aOrbiterA);
            aWandererB = aWandererB ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterD, 47U)) + aOrbiterA);
            aWandererA = aWandererA + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 35U)) + aOrbiterG) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterI, 41U)) + aOrbiterD);
            aWandererF = aWandererF + ((((RotL64(aScatter, 28U) + aOrbiterD) + RotL64(aOrbiterG, 14U)) + RotL64(aCarry, 19U)) + aPhaseEWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterD, 53U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererD, 60U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 11U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 19156U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23835U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 19970U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 17415U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCarry, 40U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = ((aWandererE + RotL64(aIngress, 35U)) + RotL64(aCarry, 3U)) + 6916817163240024692U;
            aOrbiterH = ((aWandererA + RotL64(aCross, 3U)) + 14554930751292077817U) + aPhaseEOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = ((aWandererC + RotL64(aScatter, 23U)) + RotL64(aCarry, 53U)) + 1098305064484336101U;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 60U)) + RotL64(aCarry, 41U)) + 12192821172420471527U;
            aOrbiterJ = (aWandererG + RotL64(aCross, 29U)) + 2435134991707318845U;
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 51U)) + 1896745368738512624U) + aPhaseEOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aPrevious, 11U)) + 1114996424222923873U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 9839135798371512656U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 8037967239603177043U;
            aOrbiterK = RotL64((aOrbiterK * 7848951103759663025U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 15185468738487237432U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 4912098316394854543U;
            aOrbiterH = RotL64((aOrbiterH * 3072785550384399929U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 13142688607850380888U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 4507379759608945839U;
            aOrbiterA = RotL64((aOrbiterA * 2989332387754215967U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 7299006009652289342U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 5390655277207053627U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10973744708856143715U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 6744737023577785725U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 15539737698867067285U;
            aOrbiterJ = RotL64((aOrbiterJ * 4686092035261336911U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 13329866734681377952U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 13284937458969166257U;
            aOrbiterI = RotL64((aOrbiterI * 3965985432462699445U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 8695002088915702168U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 3858059421620839286U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9559783727301092937U), 21U);
            //
            aIngress = RotL64(aOrbiterI, 47U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 54U));
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterA, 21U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 13U)) + aOrbiterB) + RotL64(aCarry, 13U)) + aPhaseEWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 41U) + aOrbiterB) + RotL64(aOrbiterI, 52U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterA, 29U)) + aOrbiterB);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterG, 35U));
            aWandererK = aWandererK + (((RotL64(aIngress, 60U) + aOrbiterK) + RotL64(aOrbiterB, 41U)) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterI, 3U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererG, 4U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 41U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 29957U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneB[((aIndex + 31017U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25510U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 26418U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCross, 19U)) + (RotL64(aPrevious, 38U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = ((aWandererB + RotL64(aIngress, 27U)) + RotL64(aCarry, 53U)) + 16189787374324972735U;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 51U)) + 17563763730956242224U;
            aOrbiterA = (((aWandererH + RotL64(aScatter, 21U)) + RotL64(aCarry, 3U)) + 10572803498593789385U) + aPhaseEOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = (aWandererE + RotL64(aCross, 11U)) + 7713105232072974166U;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 42U)) + 10760839534772718139U;
            aOrbiterC = (((aWandererF + RotL64(aCross, 57U)) + RotL64(aCarry, 27U)) + 13397069448391230253U) + aPhaseEOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aIngress, 3U)) + 4569255679998375682U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 9888769350817876949U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 11351796060878856300U;
            aOrbiterA = RotL64((aOrbiterA * 13356749147334008399U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 18153775071965707204U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 1282846411145853435U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12294455920906257823U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 16457743979262460660U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 173493260775251032U;
            aOrbiterD = RotL64((aOrbiterD * 4935807229040883505U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 3927345926316409630U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 5158769729850853623U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2446452358663812945U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 12331351600010165154U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 3940794200348684050U;
            aOrbiterB = RotL64((aOrbiterB * 13248997263062075043U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 11248514843822945425U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 1391497323278226522U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8376841806072565005U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 13265623528678787307U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 2802033745265647317U;
            aOrbiterK = RotL64((aOrbiterK * 3437626962562016147U), 19U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterI, 43U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 21U));
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 58U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 53U) + aOrbiterB) + RotL64(aOrbiterD, 37U));
            aWandererB = aWandererB + (((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterI, 30U)) + aPhaseEWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterI, 53U)) + aOrbiterH);
            aWandererK = aWandererK + (((RotL64(aCross, 11U) + RotL64(aOrbiterA, 43U)) + aOrbiterI) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 34U) + RotL64(aOrbiterK, 5U)) + aOrbiterH);
            aWandererF = aWandererF + ((((RotL64(aIngress, 41U) + RotL64(aOrbiterB, 21U)) + aOrbiterA) + RotL64(aCarry, 13U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterA, 11U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 4U));
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + RotL64(aWandererK, 35U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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

void TwistExpander_Tennis_Arx::Twist_D(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0;
    std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5363U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((aIndex + 159U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2476U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 249U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCross, 6U)) ^ (RotL64(aCarry, 53U) + RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = ((aWandererK + RotL64(aScatter, 37U)) + RotL64(aCarry, 37U)) + 14499676118633326000U;
            aOrbiterH = (aWandererG + RotL64(aPrevious, 27U)) + 17191273593018552288U;
            aOrbiterK = ((aWandererA + RotL64(aCross, 11U)) + RotL64(aCarry, 57U)) + 4085176294948097737U;
            aOrbiterF = (((aWandererB + RotL64(aIngress, 19U)) + RotL64(aCarry, 21U)) + 11112671474158908186U) + aPhaseFOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = ((aWandererC + RotL64(aScatter, 58U)) + 8745787969012266485U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 18074049663777707948U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 2543758649719164688U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7153845562786344373U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 4659584749412700523U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 974639159259871273U;
            aOrbiterA = RotL64((aOrbiterA * 17918719351847605523U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 9211220687971081987U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 8567024626862182714U;
            aOrbiterF = RotL64((aOrbiterF * 7755874089832496393U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 5803002132294840900U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 11968489432878148467U;
            aOrbiterH = RotL64((aOrbiterH * 4501441062617123165U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 9470807228394903442U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 1692347973120388469U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17433393164156231575U), 13U);
            //
            aIngress = RotL64(aOrbiterG, 58U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 53U) + aOrbiterG) + RotL64(aOrbiterA, 56U)) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 19U)) + aOrbiterA);
            aWandererC = aWandererC + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 37U)) + aOrbiterK);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 6U) + RotL64(aOrbiterA, 3U)) + aOrbiterH) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aScatter, 23U) + RotL64(aOrbiterG, 11U)) + aOrbiterH) + RotL64(aCarry, 41U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 60U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10548U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((aIndex + 9185U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9376U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneB[((aIndex + 9141U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCarry, 29U)) ^ (RotL64(aPrevious, 57U) ^ RotL64(aCross, 12U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = ((aWandererD + RotL64(aScatter, 3U)) + 15904465836916519864U) + aPhaseFOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = (((aWandererJ + RotL64(aCross, 47U)) + RotL64(aCarry, 57U)) + 17725629806317789307U) + aPhaseFOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 12U)) + RotL64(aCarry, 43U)) + 13794170125914914828U;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 37U)) + RotL64(aCarry, 27U)) + 2149055907476874332U;
            aOrbiterK = (aWandererH + RotL64(aScatter, 27U)) + 5342047776745074649U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 8268148484060546838U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 10821151364028563719U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13626634259250509711U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 4294213820894407378U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 10884726101307943090U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1116128870387229159U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 16432210042202444824U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 15196602644336228055U;
            aOrbiterF = RotL64((aOrbiterF * 12680438355124070237U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 14117787670220328165U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 219833877949480215U;
            aOrbiterJ = RotL64((aOrbiterJ * 10736293047771972173U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 3326396981881473962U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 14918513066311426279U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14269763278564574663U), 11U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 3U);
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterK, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aPrevious, 53U) + aOrbiterF) + RotL64(aOrbiterJ, 43U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterF, 35U)) + aOrbiterE);
            aWandererD = aWandererD + ((((RotL64(aCross, 39U) + RotL64(aOrbiterE, 60U)) + aOrbiterG) + RotL64(aCarry, 37U)) + aPhaseFWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterG, 5U)) + aOrbiterK) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 12U) + RotL64(aOrbiterE, 19U)) + aOrbiterJ) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 50U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 21954U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 16782U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18117U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneC[((aIndex + 18016U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 20U) ^ RotL64(aCarry, 39U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = ((aWandererK + RotL64(aCross, 3U)) + RotL64(aCarry, 35U)) + 11700815697312060726U;
            aOrbiterE = ((aWandererF + RotL64(aIngress, 58U)) + RotL64(aCarry, 51U)) + 11808423452327465441U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 13U)) + RotL64(aCarry, 23U)) + 8670503858631730886U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 27U)) + 2400061067991988544U) + aPhaseFOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aCross, 37U)) + 16163118178366229686U) + aPhaseFOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 3280178595904941068U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 3298683600817047727U;
            aOrbiterK = RotL64((aOrbiterK * 9865649058799255343U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 16321624053445183574U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 6730229877611375225U;
            aOrbiterE = RotL64((aOrbiterE * 2022290495153519279U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 10162830636713641322U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 15646771327759599256U;
            aOrbiterF = RotL64((aOrbiterF * 15333053762177144775U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 14841751262270544102U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 9545541117228834895U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11529769874752969377U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 14676615635857599982U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 1231768638470558855U;
            aOrbiterJ = RotL64((aOrbiterJ * 2716808508509014677U), 39U);
            //
            aIngress = RotL64(aOrbiterA, 4U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 50U) + RotL64(aOrbiterA, 19U)) + aOrbiterK) + RotL64(aCarry, 53U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterF, 57U)) + aOrbiterE);
            aWandererF = aWandererF + (((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterJ, 37U)) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterA, 48U));
            aWandererH = aWandererH + (((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 3U)) + aOrbiterA) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 46U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 28714U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((aIndex + 26114U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29893U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 26279U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 28U) + RotL64(aPrevious, 41U)) ^ (RotL64(aCarry, 57U) ^ RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 5U)) + RotL64(aCarry, 57U)) + 2571116506511057880U;
            aOrbiterF = ((aWandererI + RotL64(aCross, 41U)) + RotL64(aCarry, 5U)) + 13112435411509707292U;
            aOrbiterA = ((aWandererF + RotL64(aScatter, 19U)) + 10403251762787357256U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aIngress, 58U)) + RotL64(aCarry, 29U)) + 8461951095541400405U;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 27U)) + 9890793478557463815U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 3030229465991783707U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 7273848154043719247U;
            aOrbiterA = RotL64((aOrbiterA * 17562254601517935669U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 10681774862516028276U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 7105082755586853104U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12217705329504230357U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 6588579345319551129U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 14616333550242386092U;
            aOrbiterE = RotL64((aOrbiterE * 2934574715879306337U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 15439666290229654921U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 3360304356760164799U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5164191920584106237U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 14438730801970761889U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 14515616787452085729U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2041601927968559821U), 3U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterE, 23U);
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 35U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterE, 29U)) + aOrbiterA);
            aWandererI = aWandererI + (((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 3U)) + aOrbiterF) + aPhaseFWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterE, 46U)) + aOrbiterK);
            aWandererC = aWandererC + (((RotL64(aIngress, 42U) + aOrbiterA) + RotL64(aOrbiterF, 37U)) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 60U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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

void TwistExpander_Tennis_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 7591U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneB[((aIndex + 2986U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 4463U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneD[((aIndex + 8014U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aIngress, 26U)) + (RotL64(aPrevious, 11U) + RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 57U)) + RotL64(aCarry, 21U)) + 2101601659597850213U;
            aOrbiterA = ((aWandererC + RotL64(aCross, 21U)) + RotL64(aCarry, 47U)) + 2759794072560720121U;
            aOrbiterI = (((aWandererF + RotL64(aIngress, 29U)) + RotL64(aCarry, 3U)) + 9443562552411269339U) + aPhaseGOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = (aWandererD + RotL64(aPrevious, 48U)) + 10801360546699857975U;
            aOrbiterB = ((aWandererI + RotL64(aCross, 5U)) + 8020716394829332019U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 1021894212367773801U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 13346855534622490176U;
            aOrbiterI = RotL64((aOrbiterI * 12668950387932320985U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 16359309548462953836U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 12642446944680783519U;
            aOrbiterC = RotL64((aOrbiterC * 12197935153255283321U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 8197424982767553380U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 14346334610901859094U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16982899923227935679U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 14171304260534233539U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 334531601308283605U;
            aOrbiterA = RotL64((aOrbiterA * 5012968232749075075U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 10707856298471572695U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 18364775750091914766U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15735143943129143265U), 5U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterA, 3U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 14U));
            aIngress = aIngress + RotL64(aOrbiterI, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 41U) + aOrbiterI) + RotL64(aOrbiterC, 19U)) + aPhaseGWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterB, 53U)) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 10U) + aOrbiterI) + RotL64(aOrbiterB, 39U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterA, 28U)) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterH, 3U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 40U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 14161U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneC[((aIndex + 11728U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16003U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 12813U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCarry, 5U)) ^ (RotL64(aPrevious, 27U) ^ RotL64(aCross, 40U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = (((aWandererF + RotL64(aScatter, 39U)) + RotL64(aCarry, 51U)) + 8793908991006073956U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aPrevious, 53U)) + 2932916283348441943U;
            aOrbiterE = (aWandererB + RotL64(aCross, 30U)) + 11069042087940968262U;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 13U)) + RotL64(aCarry, 23U)) + 14369628676782894441U;
            aOrbiterC = (((aWandererH + RotL64(aCross, 5U)) + RotL64(aCarry, 35U)) + 8602903272780978282U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 3827036107178568820U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 8905245209036772489U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5744017326197157667U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 13331387530760017893U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 9880107580289737823U;
            aOrbiterC = RotL64((aOrbiterC * 10302652857542703753U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 10199619040626900278U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 2466307560891374281U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6295342978834217571U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 13973403407981259448U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 2851460278409385243U;
            aOrbiterA = RotL64((aOrbiterA * 11226902976321781743U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 10365453393815690776U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 2382382358987358791U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 481563628980705781U), 21U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterI, 5U);
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 20U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterI, 13U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterI, 3U)) + aOrbiterC);
            aWandererF = aWandererF + (((RotL64(aCross, 19U) + RotL64(aOrbiterC, 56U)) + aOrbiterE) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 58U) + aOrbiterG) + RotL64(aOrbiterE, 43U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterA, 23U)) + RotL64(aCarry, 29U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + RotL64(aWandererF, 43U);
            aCarry = aCarry + RotL64(aIngress, 34U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 21670U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneD[((aIndex + 16581U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24567U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneB[((aIndex + 16839U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCarry, 51U)) + (RotL64(aPrevious, 20U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 27U)) + RotL64(aCarry, 23U)) + 12669015908335980355U;
            aOrbiterK = ((aWandererD + RotL64(aScatter, 48U)) + 5438715179868613192U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aIngress, 19U)) + RotL64(aCarry, 11U)) + 13172104448184536460U;
            aOrbiterD = (((aWandererH + RotL64(aCross, 11U)) + RotL64(aCarry, 57U)) + 13421421503244744803U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = (aWandererA + RotL64(aScatter, 39U)) + 13327113302994856582U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 4671768205922454413U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 5355759962838579929U;
            aOrbiterE = RotL64((aOrbiterE * 15080379163499722187U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 6691720614265406851U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 7063906424700911378U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17091734375516280675U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 17328616394166672263U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 1542940602574207068U;
            aOrbiterG = RotL64((aOrbiterG * 8981679306319627975U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 7203866278803132454U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 993485696233139264U;
            aOrbiterD = RotL64((aOrbiterD * 11609009908810366447U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 15659679028507488331U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 18321361454094675842U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3966860765622641843U), 29U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterE, 13U);
            aIngress = aIngress + (RotL64(aOrbiterD, 42U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterH, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterE, 19U)) + aOrbiterK) + RotL64(aCarry, 41U)) + aPhaseGWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterK, 5U));
            aWandererE = aWandererE + (((RotL64(aIngress, 51U) + RotL64(aOrbiterH, 43U)) + aOrbiterE) + RotL64(aCarry, 19U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 24U) + RotL64(aOrbiterE, 29U)) + aOrbiterD);
            aWandererA = aWandererA + (((RotL64(aScatter, 5U) + aOrbiterD) + RotL64(aOrbiterG, 52U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 31726U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27342U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25423U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 28374U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 48U)) ^ (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = (((aWandererH + RotL64(aScatter, 29U)) + RotL64(aCarry, 35U)) + 3917730204724097072U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = (((aWandererB + RotL64(aCross, 37U)) + RotL64(aCarry, 3U)) + 1874642340716212824U) + aPhaseGOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aIngress, 5U)) + 6900165757434854160U;
            aOrbiterI = (aWandererF + RotL64(aPrevious, 14U)) + 12750946097023807161U;
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 57U)) + RotL64(aCarry, 21U)) + 6563216048479513594U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 14960240191349450795U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 16306180275951788289U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12077366095522790283U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 6502066618271045547U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 6219852857850888738U;
            aOrbiterB = RotL64((aOrbiterB * 10892297250334325283U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 2272931312452845850U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 3028929882263199463U;
            aOrbiterI = RotL64((aOrbiterI * 11005324285856805069U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 6067393030073568112U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 10094809900437037258U;
            aOrbiterH = RotL64((aOrbiterH * 18095564940730322769U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 5962414178157074575U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 15755563045799129417U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3692603590609922031U), 3U);
            //
            aIngress = RotL64(aOrbiterB, 57U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterD, 46U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aPrevious, 40U) + aOrbiterD) + RotL64(aOrbiterH, 12U)) + RotL64(aCarry, 57U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterI, 53U)) + aOrbiterD);
            aWandererB = aWandererB + (((RotL64(aIngress, 21U) + aOrbiterC) + RotL64(aOrbiterI, 3U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterI, 21U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 11U) + aOrbiterH) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 14U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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

void TwistExpander_Tennis_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 6718U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7774U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8142U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 7043U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aIngress, 29U)) + (RotL64(aCross, 57U) ^ RotL64(aPrevious, 44U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 11U)) + RotL64(aCarry, 37U)) + 8367680518550579791U;
            aOrbiterJ = (((aWandererJ + RotL64(aIngress, 27U)) + RotL64(aCarry, 3U)) + 11491674725611181241U) + aPhaseHOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = ((aWandererG + RotL64(aScatter, 37U)) + RotL64(aCarry, 53U)) + 16673861720782164214U;
            aOrbiterC = ((aWandererK + RotL64(aCross, 48U)) + 9786610124108350855U) + aPhaseHOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aPrevious, 3U)) + 5745080601557577637U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 1959402215131684684U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 6121650036079196522U;
            aOrbiterI = RotL64((aOrbiterI * 13375345606276198671U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 12016309761037342392U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 5986936646177049603U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3585650475703294895U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 1000367700904043468U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 17425288243569101032U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2174614006719048535U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 4856917474950325209U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 16312111093223166419U;
            aOrbiterJ = RotL64((aOrbiterJ * 11046477664487805241U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 456110002032422270U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 11393724374787795662U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1176984359123668389U), 13U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterC, 23U);
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 43U)) + aOrbiterJ) + aPhaseHWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 14U) + aOrbiterC) + RotL64(aOrbiterF, 5U));
            aWandererE = aWandererE + ((((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterF, 35U)) + RotL64(aCarry, 53U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterH, 26U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 30U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 14249U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneC[((aIndex + 13794U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11017U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14019U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 29U) ^ RotL64(aPrevious, 41U)) + (RotL64(aIngress, 14U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 27U)) + RotL64(aCarry, 51U)) + 16183871922837164759U;
            aOrbiterI = (((aWandererH + RotL64(aCross, 39U)) + RotL64(aCarry, 13U)) + 7002058258090219055U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aIngress, 10U)) + 5650868611888303705U;
            aOrbiterH = (((aWandererI + RotL64(aScatter, 51U)) + RotL64(aCarry, 35U)) + 11899839660943876690U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = (aWandererJ + RotL64(aCross, 19U)) + 15349649504488111111U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 14060149569086744970U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 12920917574225030112U;
            aOrbiterE = RotL64((aOrbiterE * 6552626684290469367U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 2831994965175330135U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 18312543585028439192U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11618182708195744321U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 11657562205118394239U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 10850792819281246052U;
            aOrbiterJ = RotL64((aOrbiterJ * 10663100544207879337U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 17810371216216125323U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 7963413941144223128U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 534217972450595401U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 5498715358793875584U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 9256727548911651373U;
            aOrbiterH = RotL64((aOrbiterH * 10498848323914000989U), 57U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 29U);
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aScatter, 48U) + RotL64(aOrbiterE, 3U)) + aOrbiterD) + RotL64(aCarry, 13U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 29U) + aOrbiterJ) + RotL64(aOrbiterD, 21U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterJ, 52U)) + RotL64(aCarry, 37U)) + aPhaseHWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterI, 41U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 39U) + aOrbiterJ) + RotL64(aOrbiterE, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 48U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererJ, 29U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 18907U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneD[((aIndex + 21325U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17016U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((aIndex + 16971U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCarry, 34U)) ^ (RotL64(aCross, 5U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = ((aWandererH + RotL64(aScatter, 38U)) + 17264605017518259932U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aCross, 21U)) + RotL64(aCarry, 27U)) + 15209184354580778643U;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 3U)) + RotL64(aCarry, 43U)) + 3299527965014731384U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 29U)) + RotL64(aCarry, 57U)) + 16293096431816127821U;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 47U)) + 11031983436878828337U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 9188018632448236358U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 13420816400363406556U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10958221259662190519U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 2485063384097917101U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 3089135816938128264U;
            aOrbiterK = RotL64((aOrbiterK * 8813152992957361153U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 10730544971770435788U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 10431767565618874806U;
            aOrbiterA = RotL64((aOrbiterA * 4723078464590561545U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 14883796491656899074U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 13465877783538483706U;
            aOrbiterG = RotL64((aOrbiterG * 14311686051108108503U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 13322163435314643713U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 3307316600284371955U;
            aOrbiterI = RotL64((aOrbiterI * 12337846092069506365U), 13U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 24U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 27U)) + aOrbiterA) + RotL64(aCarry, 51U)) + aPhaseHWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterG, 47U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 24U) + aOrbiterI) + RotL64(aOrbiterE, 19U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterE, 4U));
            aWandererF = aWandererF + (((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterE, 37U)) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 34U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererH, 13U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 25873U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28046U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32460U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneC[((aIndex + 32745U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 3U)) + (RotL64(aIngress, 40U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 22U)) + RotL64(aCarry, 11U)) + 9446153639709651566U;
            aOrbiterD = (((aWandererK + RotL64(aCross, 11U)) + RotL64(aCarry, 41U)) + 10550762260670758167U) + aPhaseHOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aScatter, 41U)) + 7062634922142578383U;
            aOrbiterF = (aWandererI + RotL64(aIngress, 3U)) + 9178499097812764515U;
            aOrbiterE = (((aWandererH + RotL64(aScatter, 53U)) + RotL64(aCarry, 23U)) + 6887103379773525538U) + aPhaseHOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 6239750312052010257U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 17645022614523287959U;
            aOrbiterA = RotL64((aOrbiterA * 14448140327044053545U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 3639618183259408272U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 3131737117548745095U;
            aOrbiterH = RotL64((aOrbiterH * 6585057380704940395U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 7253994382396406554U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 15217993711938379561U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17853313384747259923U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 12594152227603630033U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 11250170200489647869U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 546800378327864723U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 12936942656624279424U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 10990736056052106149U;
            aOrbiterE = RotL64((aOrbiterE * 7123916809953459187U), 27U);
            //
            aIngress = RotL64(aOrbiterD, 57U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterF, 12U)) + aOrbiterH) + RotL64(aCarry, 43U)) + aPhaseHWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 4U) + aOrbiterE) + RotL64(aOrbiterF, 21U));
            aWandererB = aWandererB + (((RotL64(aIngress, 13U) + RotL64(aOrbiterF, 51U)) + aOrbiterA) + RotL64(aCarry, 11U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterD, 35U));
            aWandererF = aWandererF + (((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 43U)) + aOrbiterA) + aPhaseHWandererUpdateSaltC[((aIndex + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererI, 35U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
