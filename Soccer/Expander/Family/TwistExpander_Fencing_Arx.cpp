#include "TwistExpander_Fencing_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Fencing_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x953BF88DE8A4396FULL + 0xFE6084576F4E75E7ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xB9F830E8BDC16571ULL + 0xCF689BCCE88AD8B5ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xA1B738CECAB3F085ULL + 0xCF9BA7286F1DC238ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xC0B70A99CB8F31D9ULL + 0x9901A80E6702DEC5ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xE458C6FB9C6E706BULL + 0xF7F5C01B6E1CCF52ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x95421DADDE6A6571ULL + 0xACFEA0C031BE3F84ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xB1968B057D23D6CDULL + 0xC7891455FC8DA2B4ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xE149EFBC794580A5ULL + 0xFDA2715341270BB6ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 4U) ^ RotL64(aNonceWordE, 39U)) ^ RotL64(aNonceWordH, 53U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 4309U)) & S_BLOCK1], 21U) ^ RotL64(mSnow[((aIndex + 3774U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 24U) ^ RotL64(aNonceWordF, 3U)) ^ RotL64(aNonceWordB, 11U));
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 4810U)) & S_BLOCK1], 53U) ^ RotL64(mSnow[((S_BLOCK1 - aIndex + 4700U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 51U)) + (RotL64(aCross, 6U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererI + RotL64(aCross, 60U)) + 7896237440058555694U) + aOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aScatter, 35U)) + 11870529476037558635U;
            aOrbiterK = ((aWandererB + RotL64(aIngress, 13U)) + 9158983227801569448U) + RotL64(aNonceWordG, 7U);
            aOrbiterE = (aWandererC + RotL64(aPrevious, 27U)) + 4710172270996950329U;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 21U)) + 14634482800356647630U;
            aOrbiterA = (((aWandererK + RotL64(aCross, 48U)) + RotL64(aCarry, 23U)) + 8822207952170610891U) + aOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 37U)) + RotL64(aCarry, 27U)) + 13755891414028982553U;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 43U)) + RotL64(aCarry, 41U)) + 4555293067488040719U;
            aOrbiterF = (aWandererF + RotL64(aIngress, 19U)) + 2816805148093762081U;
            aOrbiterI = (aWandererG + RotL64(aScatter, 3U)) + 2122631477965135190U;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 53U)) + 4592922416380416071U) + RotL64(aNonceWordH, 59U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 7102471666524164715U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 17274623547879474204U;
            aOrbiterK = RotL64((aOrbiterK * 5443572270546181789U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 938587316977094680U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 18258015823797023523U) ^ RotL64(aNonceWordE, 31U);
            aOrbiterA = RotL64((aOrbiterA * 6068819567674605919U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 5809987756043471595U) + aOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 5083075160112581620U;
            aOrbiterB = RotL64((aOrbiterB * 3313957222154937503U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 5960021727750946496U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 5967477320950630150U;
            aOrbiterE = RotL64((aOrbiterE * 330964768256424655U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 6578428711689296132U) + aOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 5601728218197771276U;
            aOrbiterC = RotL64((aOrbiterC * 9552559022315971847U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 7923809409017855241U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 16479366540906497019U;
            aOrbiterF = RotL64((aOrbiterF * 7118578387798460919U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 17000467091738009736U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 6801634573655508028U) ^ aOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10584635770060137089U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 123668445682719574U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 14462802805503986316U;
            aOrbiterH = RotL64((aOrbiterH * 12398236364304875941U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 2433338393261685871U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 13869012262404991729U) ^ RotL64(aNonceWordD, 15U);
            aOrbiterD = RotL64((aOrbiterD * 12443261517483942937U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 4832421585086516998U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 11284414949564414958U;
            aOrbiterG = RotL64((aOrbiterG * 1586650935440790991U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 17872556812561387030U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 7896237440058555694U;
            aOrbiterI = RotL64((aOrbiterI * 16784165278693056013U), 29U);
            //
            aIngress = RotL64(aOrbiterI, 43U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 46U));
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 5U) + aOrbiterI) + RotL64(aOrbiterF, 43U)) + RotL64(aCarry, 39U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 51U) + aOrbiterH) + RotL64(aOrbiterG, 11U));
            aWandererB = aWandererB + ((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterA, 3U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterI, 34U)) + RotL64(aNonceWordA, 24U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 14U) + RotL64(aOrbiterB, 23U)) + aOrbiterC) + aWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 37U) + aOrbiterA) + RotL64(aOrbiterG, 13U));
            aWandererI = aWandererI + (((RotL64(aScatter, 21U) + RotL64(aOrbiterJ, 53U)) + aOrbiterK) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 39U) + aOrbiterA) + RotL64(aOrbiterE, 47U)) + RotL64(aNonceWordC, 17U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterC, 5U)) + aOrbiterK);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 28U) + RotL64(aOrbiterG, 41U)) + aOrbiterJ) + aWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 23U) + aOrbiterD) + RotL64(aOrbiterF, 50U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 44U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 50U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 37U) ^ RotL64(aNonceWordH, 3U)) ^ RotL64(aNonceWordG, 48U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 5679U)) & S_BLOCK1], 29U) ^ RotL64(mSnow[((S_BLOCK1 - aIndex + 10474U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 3U) ^ RotL64(aNonceWordB, 11U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8389U)) & S_BLOCK1], 29U) ^ RotL64(mSource[((aIndex + 8953U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 26U) ^ RotL64(aCross, 57U)) + (RotL64(aPrevious, 39U) + RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererG + RotL64(aIngress, 37U)) + 1393781663398437180U) + aOrbiterAssignSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = ((aWandererC + RotL64(aCross, 29U)) + 17414594746688585273U) + RotL64(aNonceWordE, 7U);
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 53U)) + RotL64(aCarry, 5U)) + 2823888497053071250U;
            aOrbiterE = (aWandererA + RotL64(aScatter, 22U)) + 17032631958617884859U;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 41U)) + RotL64(aCarry, 39U)) + 15222697630461125019U;
            aOrbiterA = (aWandererK + RotL64(aScatter, 27U)) + 15737414920751551780U;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 13U)) + 1357196111055783001U) + aOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aCross, 24U)) + 5315122321649251691U;
            aOrbiterK = (aWandererD + RotL64(aIngress, 57U)) + 7893744655508595974U;
            aOrbiterH = ((aWandererB + RotL64(aCross, 39U)) + 16721939414324611738U) + RotL64(aNonceWordF, 51U);
            aOrbiterC = ((aWandererH + RotL64(aScatter, 19U)) + RotL64(aCarry, 21U)) + 3444375866323610848U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 1825716513674511632U) + RotL64(aNonceWordA, 45U);
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 15582066843912467318U;
            aOrbiterB = RotL64((aOrbiterB * 12765146555943757373U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 15673590949193923915U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 13887365046280406413U;
            aOrbiterI = RotL64((aOrbiterI * 3169061375011420121U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 12730414371734709356U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 4819112390640821927U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8782547948627685451U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 3089925954422937464U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 7180179304678622530U;
            aOrbiterJ = RotL64((aOrbiterJ * 16118051565147747413U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 17030269962085008657U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 6675917351883004046U;
            aOrbiterK = RotL64((aOrbiterK * 14134335325316949687U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 12572022803491077491U) + aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 2801421744689267375U) ^ aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 315045745990934023U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 4335148696780313055U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 12526298573395110141U;
            aOrbiterE = RotL64((aOrbiterE * 11276803410698178607U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 6984239833558496091U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 12195433952105336808U;
            aOrbiterA = RotL64((aOrbiterA * 8642600547427664495U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 6392683095502982341U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 18047201953488013325U;
            aOrbiterD = RotL64((aOrbiterD * 16151795290455603489U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 15433458942878109208U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 1700365768743794306U;
            aOrbiterH = RotL64((aOrbiterH * 16151638348775286903U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 10951473638533187729U) + RotL64(aNonceWordC, 29U);
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 1393781663398437180U;
            aOrbiterC = RotL64((aOrbiterC * 2661447713922232789U), 5U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterB, 4U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + (RotL64(aOrbiterG, 37U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterD, 34U));
            aWandererF = aWandererF + ((RotL64(aCross, 13U) + RotL64(aOrbiterH, 19U)) + aOrbiterG);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 34U) + aOrbiterD) + RotL64(aOrbiterB, 57U));
            aWandererK = aWandererK + (((RotL64(aIngress, 19U) + RotL64(aOrbiterJ, 37U)) + aOrbiterB) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterC, 3U)) + aOrbiterA);
            aWandererC = aWandererC + ((((RotL64(aScatter, 27U) + RotL64(aOrbiterI, 41U)) + aOrbiterB) + RotL64(aCarry, 19U)) + RotL64(aNonceWordD, 9U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 53U) + aOrbiterG) + RotL64(aOrbiterA, 43U));
            aWandererG = aWandererG + (((RotL64(aCross, 51U) + RotL64(aOrbiterG, 60U)) + aOrbiterF) + aWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterF, 5U)) + aOrbiterI);
            aWandererB = aWandererB + (((RotL64(aPrevious, 60U) + aOrbiterK) + RotL64(aOrbiterD, 39U)) + aWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterF, 23U)) + aOrbiterE) + RotL64(aNonceWordG, 52U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 56U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 30U) ^ RotL64(aNonceWordB, 19U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 11037U)) & S_BLOCK1], 53U) ^ RotL64(mSnow[((S_BLOCK1 - aIndex + 13923U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 28U) ^ RotL64(aNonceWordE, 37U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11673U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((aIndex + 16055U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 54U) + RotL64(aIngress, 21U)) ^ (RotL64(aPrevious, 3U) + RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererB + RotL64(aPrevious, 13U)) + 6163290588946759209U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 10U)) + RotL64(aCarry, 47U)) + 7342672468560105447U;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 41U)) + 11574563167017282321U) + RotL64(aNonceWordF, 5U);
            aOrbiterC = ((aWandererC + RotL64(aIngress, 37U)) + RotL64(aCarry, 27U)) + 2254820206194758964U;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 39U)) + 1469783447473099498U;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 35U)) + RotL64(aCarry, 11U)) + 14174828900676165088U;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 60U)) + 16277954291890598132U;
            aOrbiterB = (aWandererG + RotL64(aCross, 19U)) + 14845750668693136766U;
            aOrbiterF = (aWandererH + RotL64(aScatter, 27U)) + 150099699692047766U;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 21U)) + 1200784917165131703U) + aOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = (((aWandererK + RotL64(aCross, 51U)) + 9469982764806754302U) + aOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1]) + RotL64(aNonceWordA, 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 10956702761701710182U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 7915506894975487807U;
            aOrbiterH = RotL64((aOrbiterH * 8874108311712727983U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 17335794183733623213U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 557028996286989506U;
            aOrbiterA = RotL64((aOrbiterA * 3993359298602424281U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 1597385667771002414U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 4376417959915162639U;
            aOrbiterI = RotL64((aOrbiterI * 4626236858205178149U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 549770198518993876U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 756554555648070919U;
            aOrbiterG = RotL64((aOrbiterG * 16272320259614325355U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 7298557532533152193U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 3336802611342112013U;
            aOrbiterB = RotL64((aOrbiterB * 14679103452120080499U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 2314938232094714365U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 12215066333571149153U;
            aOrbiterE = RotL64((aOrbiterE * 10747052773052630601U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 7762752719356805046U) + RotL64(aNonceWordC, 9U);
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 6519429915769040078U;
            aOrbiterD = RotL64((aOrbiterD * 15548676502167938513U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 7556691736109752918U) + aOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 13731245903412646404U) ^ RotL64(aNonceWordH, 21U);
            aOrbiterC = RotL64((aOrbiterC * 15581965016668635409U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 5910925625723735162U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 16037704866415841869U) ^ aOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11628217027073824759U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 12605882248192797360U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 9579778913978981884U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5372577227818787957U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 6063171520266734946U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 6163290588946759209U;
            aOrbiterJ = RotL64((aOrbiterJ * 291843698316138251U), 53U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterD, 11U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 26U));
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 37U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aIngress, 35U) + aOrbiterD) + RotL64(aOrbiterH, 5U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterH, 46U)) + aOrbiterJ);
            aWandererI = aWandererI + ((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 51U)) + aOrbiterF);
            aWandererA = aWandererA ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterC, 23U)) + aOrbiterG) + RotL64(aNonceWordD, 14U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 24U) + RotL64(aOrbiterC, 41U)) + aOrbiterI) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterB, 39U)) + aOrbiterA);
            aWandererE = aWandererE + ((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterA, 60U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 19U)) + aOrbiterG);
            aWandererD = aWandererD + ((((RotL64(aIngress, 54U) + RotL64(aOrbiterB, 11U)) + aOrbiterE) + RotL64(aCarry, 57U)) + aWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterB, 43U)) + RotL64(aNonceWordE, 19U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterA, 29U)) + aOrbiterH) + aWandererUpdateSaltC[((aIndex + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + (RotL64(aWandererG, 50U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + RotL64(aWandererJ, 10U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 5U) ^ RotL64(aNonceWordA, 13U));
            aIngress = aIngress ^ (RotL64(mSnow[((aIndex + 16656U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneA[((aIndex + 21461U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 19U) ^ RotL64(aNonceWordF, 54U)) ^ RotL64(aNonceWordB, 3U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20855U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20332U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aPrevious, 27U)) + (RotL64(aCarry, 12U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererC + RotL64(aScatter, 46U)) + 11480359716598965890U;
            aOrbiterB = (((aWandererH + RotL64(aIngress, 13U)) + 15431182525482873419U) + aOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1]) + RotL64(aNonceWordE, 41U);
            aOrbiterJ = ((aWandererA + RotL64(aCross, 43U)) + RotL64(aCarry, 47U)) + 11360504974812776707U;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 21U)) + 9292576416573382769U;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 37U)) + RotL64(aCarry, 19U)) + 1549257414531028975U;
            aOrbiterG = (((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 27U)) + 5347769463033129317U) + RotL64(aNonceWordD, 52U);
            aOrbiterH = (aWandererJ + RotL64(aCross, 52U)) + 17019199177478377234U;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 39U)) + 16558106007323125094U;
            aOrbiterI = (aWandererK + RotL64(aCross, 57U)) + 3976182233825939422U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 11U)) + 2889047161195954395U) + aOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = (aWandererI + RotL64(aScatter, 5U)) + 2241831345026962605U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 12850802412140579294U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 13541744735436450160U;
            aOrbiterJ = RotL64((aOrbiterJ * 906089290000537439U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 2085863085516538212U) + aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 2969034221711544086U) ^ RotL64(aNonceWordH, 57U);
            aOrbiterF = RotL64((aOrbiterF * 7768528124408400403U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 6482666944512391472U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 16969153556875844613U;
            aOrbiterG = RotL64((aOrbiterG * 9483462388353216219U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 5161314086757363678U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 7150282484670673211U;
            aOrbiterH = RotL64((aOrbiterH * 8522427002337918663U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 5465304381272305847U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 2344610773390354017U;
            aOrbiterA = RotL64((aOrbiterA * 17010258514288089191U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 8335906578006588582U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 13668796013474193793U;
            aOrbiterI = RotL64((aOrbiterI * 8228000547141147777U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 9663362594301419686U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 3683773739120343413U;
            aOrbiterD = RotL64((aOrbiterD * 8319320803406104749U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 2538583190438044942U) + aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 4454069062219406996U;
            aOrbiterK = RotL64((aOrbiterK * 16329554225309389599U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 17177136683616247897U) + RotL64(aNonceWordA, 45U);
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 3680497519697457252U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6479357366957384599U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 16812938441063719463U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 4545693142067578891U;
            aOrbiterB = RotL64((aOrbiterB * 17479957806084346527U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 9232311730019478327U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 11480359716598965890U;
            aOrbiterE = RotL64((aOrbiterE * 6678546065399772697U), 39U);
            //
            aIngress = RotL64(aOrbiterH, 57U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 21U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterI, 50U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + RotL64(aOrbiterC, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aIngress, 50U) + RotL64(aOrbiterA, 57U)) + aOrbiterB) + RotL64(aCarry, 19U)) + aWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterB, 14U)) + aOrbiterE) + aWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 21U)) + aOrbiterK);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterA, 39U)) + aOrbiterH) + RotL64(aNonceWordG, 49U));
            aWandererE = aWandererE + (((RotL64(aCross, 35U) + RotL64(aOrbiterG, 35U)) + aOrbiterD) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 43U) + aOrbiterF) + RotL64(aOrbiterB, 27U));
            aWandererG = aWandererG + ((RotL64(aIngress, 23U) + RotL64(aOrbiterG, 54U)) + aOrbiterC);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 18U) + RotL64(aOrbiterH, 51U)) + aOrbiterD);
            aWandererB = aWandererB + (((RotL64(aScatter, 27U) + aOrbiterH) + RotL64(aOrbiterG, 43U)) + RotL64(aNonceWordC, 27U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterA, 23U));
            aWandererF = aWandererF + ((RotL64(aCross, 39U) + aOrbiterJ) + RotL64(aOrbiterE, 37U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 22U));
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 58U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 5U) ^ RotL64(aNonceWordG, 38U)) ^ RotL64(aNonceWordC, 21U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 22468U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21995U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 39U) ^ RotL64(aNonceWordF, 10U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23418U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((aIndex + 23737U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCross, 13U)) ^ (RotL64(aCarry, 54U) + RotL64(aIngress, 29U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 18U)) + RotL64(aCarry, 19U)) + 2330952702412094686U;
            aOrbiterI = ((aWandererC + RotL64(aCross, 21U)) + 7820188225935060799U) + aOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aPrevious, 3U)) + 9347644591709839145U;
            aOrbiterD = (aWandererE + RotL64(aIngress, 13U)) + 2288624878446846870U;
            aOrbiterC = ((((aWandererK + RotL64(aPrevious, 23U)) + RotL64(aCarry, 3U)) + 9358977729492824128U) + aOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1]) + RotL64(aNonceWordG, 51U);
            aOrbiterA = (((aWandererI + RotL64(aCross, 35U)) + RotL64(aCarry, 47U)) + 1858511275052455039U) + RotL64(aNonceWordF, 55U);
            aOrbiterF = (aWandererB + RotL64(aScatter, 37U)) + 13715478509322292552U;
            aOrbiterB = (aWandererF + RotL64(aIngress, 41U)) + 16413396625604260455U;
            aOrbiterG = (aWandererH + RotL64(aPrevious, 11U)) + 17714322215518432705U;
            aOrbiterE = (aWandererA + RotL64(aScatter, 39U)) + 16188315436202861122U;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 6U)) + 5564445841368207813U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 13717068949900594673U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 14143659432287313765U;
            aOrbiterH = RotL64((aOrbiterH * 17281441046722262917U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 5729546141908425670U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 4297827922736712074U;
            aOrbiterA = RotL64((aOrbiterA * 13631630436759768885U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 829520109395163673U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 11547160328525174295U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4759690159673049775U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 2907177944512117206U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 11100346409065275671U;
            aOrbiterE = RotL64((aOrbiterE * 17927994356809011637U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 1344592529249949068U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterK) ^ 6470438516791143572U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]) ^ RotL64(aNonceWordA, 24U);
            aOrbiterJ = RotL64((aOrbiterJ * 13339390828725370475U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 5217751823741520847U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 5371275223586938039U;
            aOrbiterD = RotL64((aOrbiterD * 12318403075523724125U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 14218103150268532919U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 1367628876596800571U) ^ RotL64(aNonceWordC, 21U);
            aOrbiterF = RotL64((aOrbiterF * 13777531272321533137U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 2372041991018455610U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 9870744274890595581U;
            aOrbiterG = RotL64((aOrbiterG * 12093443117747395585U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 15531376915156611594U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 11166549148968363252U;
            aOrbiterK = RotL64((aOrbiterK * 10024372567841218915U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 8555942275137258839U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 3304132937209624841U;
            aOrbiterI = RotL64((aOrbiterI * 7965093976633155809U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 14825330575158830172U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 2330952702412094686U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9146641978165131495U), 57U);
            //
            aIngress = RotL64(aOrbiterJ, 27U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterA, 41U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterK, 53U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 37U));
            aIngress = aIngress + RotL64(aOrbiterH, 20U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterE, 5U)) + aWandererUpdateSaltF[((aIndex + 10U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 24U)) + aOrbiterK) + RotL64(aCarry, 57U)) + aWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 3U) + aOrbiterH) + RotL64(aOrbiterG, 53U));
            aWandererH = aWandererH + (((RotL64(aCross, 53U) + RotL64(aOrbiterD, 47U)) + aOrbiterI) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 24U) + RotL64(aOrbiterC, 27U)) + aOrbiterG);
            aWandererK = aWandererK + ((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 35U)) + aOrbiterC);
            aWandererG = aWandererG ^ ((RotL64(aCross, 37U) + aOrbiterK) + RotL64(aOrbiterE, 41U));
            aWandererE = aWandererE + ((RotL64(aIngress, 41U) + aOrbiterI) + RotL64(aOrbiterG, 20U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterB, 43U)) + RotL64(aNonceWordD, 17U));
            aWandererC = aWandererC + (((RotL64(aIngress, 27U) + RotL64(aOrbiterD, 13U)) + aOrbiterA) + RotL64(aNonceWordE, 41U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 50U) + aOrbiterD) + RotL64(aOrbiterJ, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 58U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 60U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 13U) ^ RotL64(aNonceWordC, 43U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 27594U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31912U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 41U) ^ RotL64(aNonceWordG, 4U)) ^ RotL64(aNonceWordH, 27U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27471U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((aIndex + 30269U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCarry, 35U)) ^ (RotL64(aIngress, 23U) ^ RotL64(aCross, 54U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererG + RotL64(aScatter, 37U)) + 16651241552253078315U;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 54U)) + 4558144676982478003U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 51U)) + 8814884320080367550U) + aOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aCross, 3U)) + 16011579668555672117U;
            aOrbiterB = (aWandererE + RotL64(aScatter, 39U)) + 4738918668759862438U;
            aOrbiterF = ((aWandererA + RotL64(aCross, 5U)) + RotL64(aCarry, 19U)) + 12526083125540985108U;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 28U)) + 8048723561746000552U;
            aOrbiterD = (((aWandererJ + RotL64(aIngress, 11U)) + RotL64(aCarry, 13U)) + 1082218464034639039U) + RotL64(aNonceWordE, 31U);
            aOrbiterK = (aWandererB + RotL64(aCross, 57U)) + 8432043246965946816U;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 47U)) + 9982080524048636852U) + aOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = (((aWandererH + RotL64(aPrevious, 21U)) + RotL64(aCarry, 47U)) + 6720069955755215919U) + RotL64(aNonceWordB, 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 1019035028070247757U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 7360619079463870467U;
            aOrbiterE = RotL64((aOrbiterE * 6623074813047915863U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 10893918488381348474U) + aOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 1390297670907738019U;
            aOrbiterB = RotL64((aOrbiterB * 11909657437658597735U), 21U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterE) + 12512200589031203480U) + aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1]) + RotL64(aNonceWordF, 28U);
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 14741471280748399540U;
            aOrbiterF = RotL64((aOrbiterF * 3012135242889901095U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 8543897248359826770U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 8545972622733791272U) ^ aOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11793879362775346821U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 7049384618581928664U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 14730773807906925408U;
            aOrbiterD = RotL64((aOrbiterD * 10711566871536755073U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 11480717275652449986U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 1135397594974536859U;
            aOrbiterK = RotL64((aOrbiterK * 6347492892938856497U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 6897207625849516702U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 10920630712550287148U;
            aOrbiterI = RotL64((aOrbiterI * 4140705091806993359U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 1094056478999931332U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 6784487144549717207U;
            aOrbiterA = RotL64((aOrbiterA * 6295177724167067891U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 2224992798329560875U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 11486442570446223696U;
            aOrbiterC = RotL64((aOrbiterC * 5680065455032616591U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 14681556190496625711U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 1809388635055225841U;
            aOrbiterG = RotL64((aOrbiterG * 3449474313001177557U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 4480846057441948619U) + RotL64(aNonceWordH, 27U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 16651241552253078315U;
            aOrbiterJ = RotL64((aOrbiterJ * 10628778876898064085U), 19U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 27U);
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 21U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 54U));
            aIngress = aIngress + RotL64(aOrbiterK, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 53U) + RotL64(aOrbiterB, 26U)) + aOrbiterA) + aWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterK, 19U)) + aOrbiterI);
            aWandererI = aWandererI + (((RotL64(aIngress, 19U) + RotL64(aOrbiterI, 5U)) + aOrbiterG) + RotL64(aNonceWordC, 35U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 11U) + aOrbiterE) + RotL64(aOrbiterH, 21U));
            aWandererD = aWandererD + ((RotL64(aCross, 26U) + aOrbiterF) + RotL64(aOrbiterB, 13U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterK, 30U)) + aOrbiterE);
            aWandererA = aWandererA + ((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterJ, 53U));
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 35U)) + aOrbiterJ) + RotL64(aNonceWordG, 53U)) + aWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 41U) + aOrbiterF) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 41U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterD, 43U)) + aOrbiterB);
            aWandererE = aWandererE + (((RotL64(aCross, 24U) + RotL64(aOrbiterB, 11U)) + aOrbiterG) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 26U));
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + RotL64(aWandererF, 5U);
            aCarry = aCarry + RotL64(aIngress, 24U);
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

void TwistExpander_Fencing_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xCB8D96B025E9202BULL + 0xB3D60D4713F497DBULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xDD69A409F693452BULL + 0xE50F728BC17E3749ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xF5F6C788A2402A45ULL + 0xFC2EFFADBF71480EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xC79796275BA5BD81ULL + 0xA5321A6C8CF8C3CBULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xA4221B226CEDAC33ULL + 0xC536C993A36A01F6ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xB39807F5D434C1C7ULL + 0xFE1F6A68E0AC8D8CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xBEB58A83D2354CB1ULL + 0x959E1F947A507026ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x8FEA6BDD93431CB7ULL + 0xC9094885742D24B8ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 37U) ^ RotL64(aNonceWordA, 13U)) ^ RotL64(aNonceWordC, 52U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5526U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5138U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 51U) ^ RotL64(aNonceWordB, 6U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6640U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((aIndex + 5282U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aPrevious, 52U)) + (RotL64(aCarry, 39U) + RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererG + RotL64(aScatter, 41U)) + 18087125778766689269U) + aOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aCross, 51U)) + 13710545066503235196U;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 47U)) + RotL64(aCarry, 5U)) + 1701939704736254645U;
            aOrbiterC = (((aWandererI + RotL64(aIngress, 13U)) + RotL64(aCarry, 53U)) + 8064093611384019909U) + RotL64(aNonceWordF, 15U);
            aOrbiterB = (((aWandererD + RotL64(aPrevious, 36U)) + 16623332751533885431U) + aOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1]) + RotL64(aNonceWordG, 23U);
            aOrbiterI = (aWandererK + RotL64(aIngress, 27U)) + 15590129153794910109U;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 21U)) + RotL64(aCarry, 29U)) + 7413312683079107383U;
            aOrbiterK = (aWandererC + RotL64(aCross, 57U)) + 4186064478651458810U;
            aOrbiterF = (aWandererB + RotL64(aIngress, 4U)) + 5501191643940735954U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 11064645242200570835U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 13825922087298055833U;
            aOrbiterD = RotL64((aOrbiterD * 7529317892716108867U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 5944980709887369970U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 8181136916070569646U;
            aOrbiterI = RotL64((aOrbiterI * 395183021205661827U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 15442336949157292482U) + RotL64(aNonceWordB, 45U);
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 11580554435240641337U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6654637892858767739U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 11240018128174598322U) + aOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 2027565596050777471U;
            aOrbiterF = RotL64((aOrbiterF * 18048186560314431815U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 16425887196883725233U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 16828683527588834095U;
            aOrbiterA = RotL64((aOrbiterA * 17746289103235902485U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 9923829146479008804U) + aOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 6669171007279929454U) ^ RotL64(aNonceWordC, 19U);
            aOrbiterC = RotL64((aOrbiterC * 681823450939955099U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 3902430046523165149U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 6739998149289590041U;
            aOrbiterG = RotL64((aOrbiterG * 2675037435528416821U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 16014401255534234075U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 14741857638680634564U;
            aOrbiterE = RotL64((aOrbiterE * 8723611021403369393U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 5064807861673260054U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 968747317273200299U;
            aOrbiterB = RotL64((aOrbiterB * 14122304002722582329U), 37U);
            //
            aIngress = RotL64(aOrbiterD, 37U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterF, 53U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterI, 40U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterK, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 58U) + aOrbiterI) + RotL64(aOrbiterD, 35U));
            aWandererF = aWandererF + (((RotL64(aCross, 23U) + RotL64(aOrbiterD, 39U)) + aOrbiterG) + RotL64(aNonceWordH, 47U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterF, 18U));
            aWandererD = aWandererD + ((((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterE, 3U)) + RotL64(aCarry, 51U)) + aWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterB, 51U)) + aOrbiterC) + RotL64(aNonceWordD, 28U));
            aWandererC = aWandererC + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 27U)) + aOrbiterA) + RotL64(aCarry, 37U)) + aWandererUpdateSaltF[((aIndex + 10U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterD, 23U));
            aWandererK = aWandererK + ((RotL64(aIngress, 12U) + RotL64(aOrbiterE, 58U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 50U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 29U);
            aCarry = aCarry + RotL64(aIngress, 26U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 36U) ^ RotL64(aNonceWordF, 27U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 10189U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneD[((aIndex + 13207U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 3U) ^ RotL64(aNonceWordE, 11U)) ^ RotL64(aNonceWordA, 23U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15649U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneB[((aIndex + 13092U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 18U) + RotL64(aPrevious, 39U)) ^ (RotL64(aCarry, 51U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererF + RotL64(aScatter, 23U)) + 13650869943246163567U;
            aOrbiterC = (((aWandererG + RotL64(aIngress, 34U)) + RotL64(aCarry, 21U)) + 3435284932011770999U) + RotL64(aNonceWordB, 56U);
            aOrbiterG = (((aWandererH + RotL64(aPrevious, 47U)) + RotL64(aCarry, 47U)) + 12388155658186776579U) + aOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = (aWandererE + RotL64(aCross, 27U)) + 2374345913955712039U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 5U)) + 6095094526980292156U) + aOrbiterAssignSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aScatter, 11U)) + 4965147025852444174U;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 19U)) + RotL64(aCarry, 35U)) + 3261881216269075298U;
            aOrbiterH = (aWandererD + RotL64(aIngress, 53U)) + 4939780217097329222U;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 42U)) + 3019862009792676287U) + RotL64(aNonceWordH, 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 901910626217143974U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 3647055146712366383U;
            aOrbiterG = RotL64((aOrbiterG * 1792602402476450009U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 7731765438957392967U) + aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 13409819457393479741U;
            aOrbiterI = RotL64((aOrbiterI * 3345078200262410715U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 5415832109107794258U) + RotL64(aNonceWordG, 5U);
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 8876738832313114471U;
            aOrbiterK = RotL64((aOrbiterK * 1304277600444504135U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 17135570542519390359U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 2373193062766802082U;
            aOrbiterH = RotL64((aOrbiterH * 4213691513185791519U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 16318403285501718552U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 8456043288604687045U;
            aOrbiterE = RotL64((aOrbiterE * 10556964529144571683U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 10572534930284516528U) + aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 14616251186735204677U) ^ RotL64(aNonceWordC, 27U);
            aOrbiterD = RotL64((aOrbiterD * 2048651204265459805U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 2837006243817205610U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 5315917323622194254U;
            aOrbiterB = RotL64((aOrbiterB * 4080522050089666599U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 12084676282761185907U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 7922080344175593788U) ^ aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7603522302708937379U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 17620847289789547792U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 12140386059533463650U;
            aOrbiterC = RotL64((aOrbiterC * 1443266480620969535U), 39U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 30U);
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterC, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterJ, 19U)) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterE, 58U)) + aOrbiterG);
            aWandererK = aWandererK + (((RotL64(aCross, 28U) + RotL64(aOrbiterI, 47U)) + aOrbiterC) + RotL64(aNonceWordA, 55U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterB, 3U)) + aOrbiterC);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 43U)) + aOrbiterK);
            aWandererF = aWandererF ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterD, 23U)) + aOrbiterG);
            aWandererE = aWandererE + ((((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 39U)) + aWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 24U) + aOrbiterK) + RotL64(aOrbiterH, 35U)) + RotL64(aNonceWordD, 59U)) + aWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterI, 14U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (RotL64(aWandererF, 10U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 41U) ^ RotL64(aNonceWordG, 27U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 17484U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 17693U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 3U) ^ RotL64(aNonceWordC, 13U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17508U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((aIndex + 24187U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aPrevious, 5U)) + (RotL64(aIngress, 37U) + RotL64(aCarry, 54U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (((aWandererF + RotL64(aPrevious, 50U)) + 18255347001097480328U) + aOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1]) + RotL64(aNonceWordE, 23U);
            aOrbiterJ = ((aWandererE + RotL64(aCross, 3U)) + RotL64(aCarry, 5U)) + 13679246790311505735U;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 13U)) + 10565839529765027116U) + aOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aIngress, 19U)) + RotL64(aCarry, 19U)) + 14327172566224769901U;
            aOrbiterA = (aWandererI + RotL64(aCross, 58U)) + 16239024612038195174U;
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 41U)) + RotL64(aCarry, 27U)) + 13800012174212131890U;
            aOrbiterC = ((aWandererB + RotL64(aScatter, 29U)) + 13900288860157577583U) + RotL64(aNonceWordC, 45U);
            aOrbiterB = (aWandererH + RotL64(aIngress, 23U)) + 4144386119777112740U;
            aOrbiterF = (aWandererK + RotL64(aPrevious, 37U)) + 3154558262670631372U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 7456728543137614001U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 11709519851158935384U) ^ RotL64(aNonceWordD, 48U);
            aOrbiterI = RotL64((aOrbiterI * 7016689518570071587U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 15607438907832240304U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 9276575329661725624U) ^ RotL64(aNonceWordF, 5U);
            aOrbiterD = RotL64((aOrbiterD * 8879744070762412745U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 6459435969129449226U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 6442382118416542275U;
            aOrbiterK = RotL64((aOrbiterK * 2921027306686588233U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 12117432107282150865U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 6831279293184793243U;
            aOrbiterJ = RotL64((aOrbiterJ * 2435360641135249073U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 9520022957804572889U) + aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 8322178689474588679U;
            aOrbiterA = RotL64((aOrbiterA * 1627707191467537115U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 4162401591586869316U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 8994015844714895961U;
            aOrbiterH = RotL64((aOrbiterH * 15421910378057951895U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 10038095909727959633U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 17756404450592957616U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14255952184627347295U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 3379089265413427719U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 11341713098678108441U;
            aOrbiterB = RotL64((aOrbiterB * 2500587373161411961U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 4030296130743454165U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 6332387792111212064U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16490982218150897861U), 47U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterI, 19U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 39U));
            aIngress = aIngress + (RotL64(aOrbiterB, 6U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 12U)) + aOrbiterC);
            aWandererC = aWandererC + (((RotL64(aCross, 40U) + aOrbiterA) + RotL64(aOrbiterJ, 43U)) + RotL64(aNonceWordA, 43U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterI, 51U)) + aWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterK, 21U)) + aOrbiterJ) + RotL64(aCarry, 29U)) + RotL64(aNonceWordG, 55U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterA, 5U)) + aWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 23U) + aOrbiterK) + RotL64(aOrbiterI, 57U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 28U) + aOrbiterH) + RotL64(aOrbiterC, 47U));
            aWandererE = aWandererE + (((RotL64(aCross, 19U) + aOrbiterB) + RotL64(aOrbiterK, 28U)) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 53U) + aOrbiterH) + RotL64(aOrbiterJ, 39U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 30U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 21U) ^ RotL64(aNonceWordF, 3U)) ^ RotL64(aNonceWordG, 58U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 29092U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28139U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 57U) ^ RotL64(aNonceWordH, 13U)) ^ RotL64(aNonceWordB, 21U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25753U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 29125U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCross, 10U)) + (RotL64(aIngress, 41U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererI + RotL64(aScatter, 5U)) + 8767379393098711499U;
            aOrbiterG = ((aWandererB + RotL64(aCross, 58U)) + 7168159491580816433U) + aOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aPrevious, 13U)) + 9879279829061883406U;
            aOrbiterI = (aWandererA + RotL64(aIngress, 19U)) + 10537167136053399303U;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 35U)) + RotL64(aCarry, 5U)) + 2839070018069188936U;
            aOrbiterA = ((aWandererK + RotL64(aCross, 51U)) + RotL64(aCarry, 19U)) + 13844278063968429732U;
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 47U)) + RotL64(aCarry, 51U)) + 11278946626186474646U;
            aOrbiterF = (((aWandererC + RotL64(aPrevious, 41U)) + 11798425216660557799U) + aOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1]) + RotL64(aNonceWordG, 31U);
            aOrbiterE = ((aWandererH + RotL64(aIngress, 30U)) + 7618446090703335192U) + RotL64(aNonceWordE, 6U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 695423597006983660U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 14344728202803488813U) ^ RotL64(aNonceWordB, 9U);
            aOrbiterD = RotL64((aOrbiterD * 5168825904902285909U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 11656100506575697086U) + RotL64(aNonceWordH, 59U);
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 10384358779985773937U;
            aOrbiterH = RotL64((aOrbiterH * 247494692039140973U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 17585001605131977341U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 9964478171465522911U;
            aOrbiterJ = RotL64((aOrbiterJ * 13484044854790175315U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 2710943171829692624U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 17809072853457153057U) ^ aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16341884203303271365U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 12814092033910687774U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 1743186323268668740U;
            aOrbiterI = RotL64((aOrbiterI * 11150822630624332557U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 10750472346626754704U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 15925901217078035356U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9276504171291801637U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 2569102106359362359U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 8868261301410769739U;
            aOrbiterF = RotL64((aOrbiterF * 3662495603133918101U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 2143691008373582476U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 10606616796243205921U;
            aOrbiterE = RotL64((aOrbiterE * 15794414817813485643U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 16258070651850746855U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 11720192793689633315U) ^ aOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14475623219460678021U), 3U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 23U);
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 20U));
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aPrevious, 11U) + aOrbiterG) + RotL64(aOrbiterA, 23U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterG, 47U));
            aWandererK = aWandererK + (((RotL64(aIngress, 30U) + aOrbiterJ) + RotL64(aOrbiterK, 52U)) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 29U)) + aOrbiterG);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterE, 39U)) + aOrbiterJ) + RotL64(aNonceWordC, 11U)) + aWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterF, 3U)) + aWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterK, 18U)) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 26U) + aOrbiterH) + RotL64(aOrbiterE, 13U)) + RotL64(aNonceWordD, 17U));
            aWandererE = aWandererE + ((RotL64(aScatter, 51U) + RotL64(aOrbiterD, 35U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 54U));
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererD, 5U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void TwistExpander_Fencing_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xE5D98FE7DD123EE3ULL + 0xBA8DABF4646B45E0ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xB0AF06D2C9121265ULL + 0xDD3CCDCD442A3D46ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xD6C550FE2CB072E5ULL + 0x8149F8587A08FC3FULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x96DB507313A23289ULL + 0x80152FFC5A5DA766ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xC258D5FEBDB876B5ULL + 0xBED53E6D15C57BA6ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xF319C9DBA64F7B13ULL + 0xC714090DA2DA85B0ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xD87E00DADE41DB51ULL + 0xB9EE37FB6B51F3BBULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x98D0DF02CDD83B31ULL + 0xB81139B64BB9F6CBULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 43U) ^ RotL64(aNonceWordA, 35U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 6218U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneC[((aIndex + 556U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 5U) ^ RotL64(aNonceWordE, 27U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 726U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 6846U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aPrevious, 23U)) ^ (RotL64(aCarry, 54U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (((aWandererB + RotL64(aScatter, 30U)) + RotL64(aCarry, 23U)) + 8866844335448071821U) + RotL64(aNonceWordC, 41U);
            aOrbiterJ = (((aWandererH + RotL64(aPrevious, 57U)) + RotL64(aCarry, 39U)) + 15159698739856430085U) + aOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aIngress, 47U)) + RotL64(aCarry, 11U)) + 9582805772989594633U;
            aOrbiterF = (aWandererA + RotL64(aCross, 13U)) + 1438538239931588373U;
            aOrbiterA = (((aWandererE + RotL64(aPrevious, 3U)) + 10862044156620436139U) + aOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1]) + RotL64(aNonceWordF, 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 13682173320058164615U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 8351013291045977592U;
            aOrbiterC = RotL64((aOrbiterC * 5722336275651615473U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 15777857431516633916U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 16178966745333885377U) ^ RotL64(aNonceWordA, 7U);
            aOrbiterB = RotL64((aOrbiterB * 7545129923202147703U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 9031889187993001617U) + aOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 6308472367425865347U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17118710301967158153U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 642109145903321046U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 9186268569255318035U;
            aOrbiterJ = RotL64((aOrbiterJ * 10714674348507516749U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 6091345356803675860U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = (((aOrbiterA ^ aOrbiterC) ^ 13218507921880873749U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]) ^ RotL64(aNonceWordG, 19U);
            aOrbiterA = RotL64((aOrbiterA * 15415157927185637717U), 37U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 53U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + RotL64(aOrbiterB, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 38U)) + aOrbiterA) + aWandererUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterB, 29U)) + RotL64(aCarry, 37U)) + RotL64(aNonceWordH, 58U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterC, 11U)) + aOrbiterA);
            aWandererA = aWandererA + (((((RotL64(aIngress, 4U) + aOrbiterF) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 57U)) + RotL64(aNonceWordB, 29U)) + aWandererUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 21U) + aOrbiterB) + RotL64(aOrbiterF, 47U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 21U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 23U) ^ RotL64(aNonceWordC, 35U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10815U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((aIndex + 16023U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 39U) ^ RotL64(aNonceWordE, 3U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12746U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 16118U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aPrevious, 23U)) ^ (RotL64(aIngress, 3U) ^ RotL64(aCross, 54U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (((aWandererF + RotL64(aScatter, 39U)) + RotL64(aCarry, 3U)) + 3248574644570178787U) + aOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aPrevious, 4U)) + 4506961512959200024U;
            aOrbiterG = ((((aWandererJ + RotL64(aIngress, 27U)) + RotL64(aCarry, 27U)) + 8423739774540738590U) + aOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1]) + RotL64(aNonceWordF, 35U);
            aOrbiterE = (((aWandererA + RotL64(aCross, 13U)) + RotL64(aCarry, 53U)) + 6593975869641735337U) + RotL64(aNonceWordD, 7U);
            aOrbiterK = (aWandererK + RotL64(aScatter, 57U)) + 16441716090557369103U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 7936601450453207914U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 13333752583560167065U) ^ aOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5389149472324384311U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 8013703284795432973U) + aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 2349852779887439236U) ^ aOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2422888500648100783U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 5318539364763284138U) + aOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 11450957608502944376U;
            aOrbiterH = RotL64((aOrbiterH * 1957880366707810635U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 9058992558327552687U) + RotL64(aNonceWordC, 54U);
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 632095686920230926U;
            aOrbiterI = RotL64((aOrbiterI * 12460364388358520799U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 14734218428913777098U) + RotL64(aNonceWordG, 17U);
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 16344357661370784442U;
            aOrbiterE = RotL64((aOrbiterE * 15049472842002138369U), 3U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 26U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aCross, 6U) + aOrbiterH) + RotL64(aOrbiterK, 3U)) + RotL64(aCarry, 27U)) + RotL64(aNonceWordH, 27U));
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 21U) + RotL64(aOrbiterG, 13U)) + aOrbiterK) + RotL64(aNonceWordB, 49U)) + aWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 27U)) + aOrbiterH) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 40U)) + aOrbiterE);
            aWandererF = aWandererF + (((RotL64(aCross, 47U) + aOrbiterH) + RotL64(aOrbiterI, 53U)) + aWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererK, 52U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 51U) ^ RotL64(aNonceWordB, 5U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 16634U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22097U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 43U) ^ RotL64(aNonceWordE, 11U)) ^ RotL64(aNonceWordC, 28U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 18129U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 17637U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 4U) + RotL64(aCross, 35U)) ^ (RotL64(aIngress, 47U) + RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererF + RotL64(aCross, 26U)) + 12690502671561165478U;
            aOrbiterF = (((aWandererI + RotL64(aIngress, 11U)) + RotL64(aCarry, 13U)) + 17519943923428102801U) + aOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = (aWandererA + RotL64(aPrevious, 43U)) + 10705515807975331385U;
            aOrbiterB = (((aWandererG + RotL64(aScatter, 57U)) + RotL64(aCarry, 39U)) + 16586447272278538179U) + RotL64(aNonceWordC, 14U);
            aOrbiterJ = ((((aWandererK + RotL64(aPrevious, 3U)) + RotL64(aCarry, 27U)) + 8006560996840971798U) + aOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1]) + RotL64(aNonceWordB, 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 12928600185788857701U) + RotL64(aNonceWordA, 7U);
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 14240723153798267172U;
            aOrbiterD = RotL64((aOrbiterD * 7446040187505339853U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 8636219177994872072U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 7586790235186467512U;
            aOrbiterF = RotL64((aOrbiterF * 15052686382507614169U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 1103807034179512424U) + aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 7547526530239498693U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3360295583636013509U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 8380239679344786397U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 5690809173787433519U;
            aOrbiterB = RotL64((aOrbiterB * 5354724308093372953U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 8390902801141804609U) + RotL64(aNonceWordG, 35U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 3507306189192059486U;
            aOrbiterJ = RotL64((aOrbiterJ * 18336280496510253103U), 39U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 37U);
            aIngress = aIngress + (RotL64(aOrbiterD, 22U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 13U) + aOrbiterD) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 39U)) + aOrbiterJ);
            aWandererG = aWandererG + (((((RotL64(aIngress, 58U) + RotL64(aOrbiterF, 56U)) + aOrbiterG) + RotL64(aCarry, 5U)) + RotL64(aNonceWordD, 39U)) + aWandererUpdateSaltD[((aIndex + 6U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterD, 29U)) + aOrbiterB) + RotL64(aNonceWordH, 19U)) + aWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 37U) + RotL64(aOrbiterG, 19U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererK, 40U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 43U) ^ RotL64(aNonceWordF, 57U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 28368U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneB[((aIndex + 30857U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 51U) ^ RotL64(aNonceWordE, 21U)) ^ RotL64(aNonceWordH, 3U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31726U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneD[((aIndex + 28422U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aPrevious, 53U)) ^ (RotL64(aCarry, 4U) ^ RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererE + RotL64(aCross, 34U)) + RotL64(aCarry, 53U)) + 9080426856729228705U;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 3U)) + 7851218321653539276U;
            aOrbiterF = (((aWandererK + RotL64(aPrevious, 13U)) + 7023344692919298036U) + aOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1]) + RotL64(aNonceWordB, 43U);
            aOrbiterB = ((aWandererD + RotL64(aScatter, 23U)) + 9772846154227440734U) + aOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (((aWandererB + RotL64(aPrevious, 3U)) + RotL64(aCarry, 37U)) + 12008298632429608431U) + RotL64(aNonceWordE, 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 12201090455849562875U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 9498721803411445471U;
            aOrbiterF = RotL64((aOrbiterF * 6511810500788451775U), 29U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterC) + 351203764023093632U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]) + RotL64(aNonceWordC, 49U);
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 4966360430644539250U;
            aOrbiterE = RotL64((aOrbiterE * 10138518378274592739U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 9194167899071345693U) + aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 4922477697284269116U) ^ RotL64(aNonceWordA, 51U);
            aOrbiterB = RotL64((aOrbiterB * 8444814161720407881U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 15742625291642356429U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 7528703106518431730U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11530049278751507567U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 15279053574704935317U) + aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 2425839793660355555U;
            aOrbiterC = RotL64((aOrbiterC * 11486964816849830667U), 21U);
            //
            aIngress = RotL64(aOrbiterC, 41U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aCross, 27U) + RotL64(aOrbiterG, 56U)) + aOrbiterF);
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 35U) + aOrbiterB) + RotL64(aOrbiterF, 39U)) + RotL64(aNonceWordG, 50U)) + aWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 43U) + aOrbiterC) + RotL64(aOrbiterE, 3U)) + RotL64(aCarry, 53U)) + RotL64(aNonceWordD, 39U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 13U)) + aOrbiterB) + aWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 12U) + RotL64(aOrbiterF, 47U)) + aOrbiterC) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 58U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xE1A6650FB8D9B5F7ULL + 0x80324BB12768B2ACULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xE271E92F4C752F11ULL + 0x8E0AF603553A785DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xF7C1C4D8D3294577ULL + 0xA9C8BBB320FE5626ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x8DD481857A7C1483ULL + 0x8489F093EEE82EDBULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA9FE99403A28EE75ULL + 0xFD7B7EA195D294E9ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xEB641906A8ABBCE7ULL + 0xCA4F2BD374AC3011ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xCD0B4B4ECE293313ULL + 0xB4D76F9FE6884669ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF7CD1010AF771DA9ULL + 0xCB80A569BA5C1F62ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 50U) ^ RotL64(aNonceWordC, 3U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 6141U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((aIndex + 3092U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 34U) ^ RotL64(aNonceWordH, 11U)) ^ RotL64(aNonceWordA, 43U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5548U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 2458U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCross, 5U)) ^ (RotL64(aIngress, 41U) + RotL64(aCarry, 28U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererA + RotL64(aIngress, 60U)) + 4773124477323378268U;
            aOrbiterE = (aWandererI + RotL64(aCross, 53U)) + 16848723289435796005U;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 35U)) + RotL64(aCarry, 11U)) + 13846642134917107058U;
            aOrbiterK = ((((aWandererK + RotL64(aScatter, 5U)) + RotL64(aCarry, 23U)) + 6472057872482789939U) + aOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1]) + RotL64(aNonceWordH, 13U);
            aOrbiterA = ((aWandererF + RotL64(aIngress, 47U)) + 2747019500690707226U) + aOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aCross, 41U)) + RotL64(aCarry, 57U)) + 9003965289739733880U;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 29U)) + 3013390651936257377U) + RotL64(aNonceWordG, 52U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 3331004709895625067U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 15355010435553517129U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8322759117004876831U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 7709870658004280052U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 13568728443963926564U) ^ aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6736090830113688981U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 12409548853419307131U) + RotL64(aNonceWordF, 51U);
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 969183352023661537U;
            aOrbiterH = RotL64((aOrbiterH * 5549220554838837145U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 15370309834426476775U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 3896803894396631184U;
            aOrbiterF = RotL64((aOrbiterF * 11018830202891911603U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 10848873633291935766U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 12885336509190543440U;
            aOrbiterG = RotL64((aOrbiterG * 1487357252619221365U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 8252290890093788010U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 9201553615601641350U;
            aOrbiterK = RotL64((aOrbiterK * 420321130559162915U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 14014209645503188472U) + RotL64(aNonceWordD, 59U);
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 4015071464301844550U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17444195018239904971U), 21U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 12U);
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 29U)) + RotL64(aNonceWordE, 49U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 11U) + aOrbiterK) + RotL64(aOrbiterH, 29U)) + aWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterF, 10U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 58U) + aOrbiterF) + RotL64(aOrbiterK, 43U)) + RotL64(aNonceWordB, 27U));
            aWandererK = aWandererK + ((((RotL64(aCross, 27U) + RotL64(aOrbiterA, 23U)) + aOrbiterE) + RotL64(aCarry, 5U)) + aWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 51U) + aOrbiterK) + RotL64(aOrbiterA, 51U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 57U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 12U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + RotL64(aWandererI, 29U);
            aCarry = aCarry + RotL64(aIngress, 36U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 3U) ^ RotL64(aNonceWordD, 11U)) ^ RotL64(aNonceWordG, 19U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 13131U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneD[((aIndex + 12056U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 53U) ^ RotL64(aNonceWordB, 13U)) ^ RotL64(aNonceWordC, 27U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15266U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((aIndex + 12967U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 29U) + RotL64(aCross, 14U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererC + RotL64(aScatter, 19U)) + 3650233661228036955U;
            aOrbiterB = (((aWandererH + RotL64(aCross, 29U)) + RotL64(aCarry, 35U)) + 11607036400067735729U) + RotL64(aNonceWordF, 23U);
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 43U)) + 3899614406903883035U) + RotL64(aNonceWordH, 13U);
            aOrbiterF = (((aWandererE + RotL64(aIngress, 57U)) + RotL64(aCarry, 11U)) + 8159156925629965143U) + aOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 50U)) + RotL64(aCarry, 53U)) + 7148903913967261270U;
            aOrbiterG = (aWandererI + RotL64(aCross, 3U)) + 9161665622287517848U;
            aOrbiterK = ((aWandererB + RotL64(aScatter, 35U)) + 2981535013474059469U) + aOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 15812469008200319549U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 14687469489893270300U;
            aOrbiterH = RotL64((aOrbiterH * 14142363399696670451U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 6025209349511417063U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 12964750392311112676U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12955480283032701843U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 6572355895765394340U) + aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 3542300121890027981U;
            aOrbiterF = RotL64((aOrbiterF * 11201491178181273935U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 6477175684045398359U) + RotL64(aNonceWordD, 57U);
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 1081388388827929314U;
            aOrbiterB = RotL64((aOrbiterB * 8752188637514143529U), 13U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterH) + 13754328481584620771U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]) + RotL64(aNonceWordE, 44U);
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 3684673342659575917U;
            aOrbiterA = RotL64((aOrbiterA * 6139923312873039143U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 6542045150319909445U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 5352102692424060388U;
            aOrbiterG = RotL64((aOrbiterG * 7385758355501860261U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 9110100774657340354U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 2813273684436269057U;
            aOrbiterK = RotL64((aOrbiterK * 10468759062594022273U), 19U);
            //
            aIngress = RotL64(aOrbiterK, 37U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 41U)) + aOrbiterH) + RotL64(aCarry, 21U)) + aWandererUpdateSaltB[((aIndex + 8U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 11U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((RotL64(aCross, 5U) + RotL64(aOrbiterG, 29U)) + aOrbiterK) + RotL64(aNonceWordC, 43U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterH, 5U)) + aOrbiterC) + aWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 23U) + aOrbiterB) + RotL64(aOrbiterC, 54U)) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 56U) + RotL64(aOrbiterK, 19U)) + aOrbiterA) + RotL64(aNonceWordA, 11U));
            aWandererH = aWandererH + ((RotL64(aCross, 29U) + RotL64(aOrbiterF, 47U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 38U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 51U) ^ RotL64(aNonceWordB, 41U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 21505U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((aIndex + 19590U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 51U) ^ RotL64(aNonceWordF, 14U)) ^ RotL64(aNonceWordG, 3U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19058U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((aIndex + 20856U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCarry, 23U)) ^ (RotL64(aCross, 10U) ^ RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 56U)) + RotL64(aCarry, 13U)) + 18302975933754610273U;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 23U)) + RotL64(aCarry, 57U)) + 16736972646771456082U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 5U)) + 17389406266488137442U) + aOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = ((((aWandererF + RotL64(aPrevious, 11U)) + RotL64(aCarry, 37U)) + 5252511566486165539U) + aOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1]) + RotL64(aNonceWordB, 19U);
            aOrbiterH = (aWandererA + RotL64(aIngress, 29U)) + 5730715427422747640U;
            aOrbiterB = ((aWandererB + RotL64(aCross, 47U)) + 6412695646456045825U) + RotL64(aNonceWordC, 6U);
            aOrbiterI = (aWandererK + RotL64(aPrevious, 41U)) + 9539701605708994494U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 18355107116412945722U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 11735742491750132942U;
            aOrbiterE = RotL64((aOrbiterE * 18129835093627763685U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 12363819388562658842U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 5861430292304371543U) ^ aOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12989055611235382695U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 15027487084595017708U) + RotL64(aNonceWordD, 25U);
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 7012850020745791926U;
            aOrbiterG = RotL64((aOrbiterG * 15952928839355613939U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 11904871669287886120U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterB) ^ 11199760114477343208U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]) ^ RotL64(aNonceWordE, 21U);
            aOrbiterA = RotL64((aOrbiterA * 7156374911847525867U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 3856004502263742700U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 3705931243173921893U;
            aOrbiterH = RotL64((aOrbiterH * 10334871178498711485U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 12305785390539209389U) + aOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 18057980996551978823U;
            aOrbiterB = RotL64((aOrbiterB * 4850564181113470859U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 3229431819292153014U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 2994716629242460094U) ^ aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1029427328395257917U), 51U);
            //
            aIngress = RotL64(aOrbiterH, 39U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 28U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + RotL64(aOrbiterI, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterF, 37U)) + aWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 53U)) + aOrbiterA) + RotL64(aNonceWordA, 9U));
            aWandererA = aWandererA + ((RotL64(aScatter, 18U) + RotL64(aOrbiterH, 21U)) + aOrbiterB);
            aWandererG = aWandererG ^ ((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterE, 46U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 13U)) + aOrbiterB) + RotL64(aCarry, 19U)) + aWandererUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterB, 29U)) + aOrbiterA);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 5U)) + aOrbiterE) + RotL64(aCarry, 3U)) + RotL64(aNonceWordH, 3U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (RotL64(aWandererH, 56U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererK, 35U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 51U) ^ RotL64(aNonceWordH, 19U)) ^ RotL64(aNonceWordC, 6U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 31640U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28690U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 18U) ^ RotL64(aNonceWordE, 43U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30910U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 30656U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 27U) + RotL64(aCarry, 13U)) ^ (RotL64(aCross, 39U) ^ RotL64(aPrevious, 52U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererK + RotL64(aIngress, 5U)) + 12222235191147985484U) + aOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = (((aWandererH + RotL64(aScatter, 58U)) + RotL64(aCarry, 53U)) + 16367317014523328414U) + RotL64(aNonceWordD, 51U);
            aOrbiterA = (aWandererF + RotL64(aPrevious, 13U)) + 3511378091284703789U;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 41U)) + RotL64(aCarry, 11U)) + 15247492830966725949U;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 21U)) + 7745995913390407897U) + RotL64(aNonceWordE, 23U);
            aOrbiterF = ((aWandererC + RotL64(aIngress, 51U)) + RotL64(aCarry, 37U)) + 6463593307540108810U;
            aOrbiterI = ((aWandererB + RotL64(aCross, 29U)) + 1101669311005268630U) + aOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 12988052764067518580U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 17717179747434679772U) ^ RotL64(aNonceWordF, 15U);
            aOrbiterA = RotL64((aOrbiterA * 10820310705487638793U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 11662190906682400416U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 6563014073547628748U;
            aOrbiterF = RotL64((aOrbiterF * 16967910471722117761U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 13099094932059419219U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 16342730862261868847U;
            aOrbiterH = RotL64((aOrbiterH * 10988124108686164829U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 16855346813127524624U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 6570063128502306944U;
            aOrbiterG = RotL64((aOrbiterG * 4571570049463124831U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 11328352033809240501U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 11640986648833160901U;
            aOrbiterE = RotL64((aOrbiterE * 2895830492089678919U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 2675226158571501666U) + aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 17700531248266458165U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2231403813970188657U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 7729597396731910874U) + RotL64(aNonceWordA, 46U);
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 15172374484412053756U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 149009041406406517U), 11U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 11U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 60U));
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterA, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((((RotL64(aIngress, 5U) + aOrbiterF) + RotL64(aOrbiterE, 53U)) + RotL64(aCarry, 29U)) + RotL64(aNonceWordG, 27U)) + aWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterF, 5U));
            aWandererK = aWandererK + (((RotL64(aCross, 47U) + aOrbiterH) + RotL64(aOrbiterI, 11U)) + aWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 38U) + RotL64(aOrbiterA, 20U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aScatter, 19U) + aOrbiterE) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterJ, 27U)) + aOrbiterF) + RotL64(aNonceWordC, 25U));
            aWandererC = aWandererC + ((RotL64(aIngress, 13U) + aOrbiterG) + RotL64(aOrbiterI, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 52U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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

void TwistExpander_Fencing_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xCAB1EA379D163DF5ULL + 0xC6447BCFB6DD5FBBULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xF17D27AB51EA5F1BULL + 0xF61E151E1A3304C4ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x89A50187A90C4807ULL + 0xB3903D6F7051B407ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xC02B4ED6D8871C6FULL + 0xB25BC3287E5122AFULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xFE18027570527319ULL + 0xBF9D1E9C5CA8ECD7ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xE584F5EA92A77057ULL + 0xCC894027D39E4FFEULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xBE91E1235907ACCDULL + 0xC68B772AF273912EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xFE9B7ACEA47EB20FULL + 0xEAFBFDC18F546857ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 5U) ^ RotL64(aNonceWordB, 29U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 1217U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneC[((aIndex + 6651U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 39U) ^ RotL64(aNonceWordC, 28U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 5062U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 7801U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCross, 53U)) + (RotL64(aCarry, 6U) + RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (((aWandererH + RotL64(aCross, 27U)) + RotL64(aCarry, 5U)) + 3448371607470865612U) + RotL64(aNonceWordD, 29U);
            aOrbiterD = (aWandererK + RotL64(aPrevious, 11U)) + 3743742913651580573U;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 43U)) + 13069491287948807280U) + RotL64(aNonceWordA, 35U);
            aOrbiterA = ((aWandererD + RotL64(aScatter, 37U)) + RotL64(aCarry, 39U)) + 16872779275586545632U;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 3U)) + 17945792656755062795U) + aOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aIngress, 56U)) + 18199747196793731853U) + aOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 19U)) + RotL64(aCarry, 21U)) + 15953311878379809513U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 941268763494588338U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 10090221530365796809U) ^ RotL64(aNonceWordE, 5U);
            aOrbiterJ = RotL64((aOrbiterJ * 14035236086292997613U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 8335698093307607001U) + aOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 6147498804734306100U;
            aOrbiterG = RotL64((aOrbiterG * 6904444049941211327U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 5980246079567570090U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 4152167624425912978U;
            aOrbiterF = RotL64((aOrbiterF * 10019421651535123573U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 14990418790239735916U) + RotL64(aNonceWordB, 37U);
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 3418668387496597219U) ^ aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12814077238529863119U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 4206650904177199425U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 3905470780938996069U;
            aOrbiterC = RotL64((aOrbiterC * 16030122739273137005U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 9968672788233080924U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 602258075661864866U;
            aOrbiterA = RotL64((aOrbiterA * 2615726693066300065U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 17751667243048041383U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 2414054413585296027U;
            aOrbiterD = RotL64((aOrbiterD * 1049512574773201893U), 11U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 18U);
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + RotL64(aOrbiterA, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterJ, 13U)) + aOrbiterC) + aWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aIngress, 38U) + RotL64(aOrbiterD, 53U)) + aOrbiterF) + RotL64(aCarry, 53U)) + aWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 27U)) + aOrbiterE) + RotL64(aNonceWordG, 59U));
            aWandererK = aWandererK + (((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 41U)) + aOrbiterF) + RotL64(aCarry, 21U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterA, 47U)) + RotL64(aNonceWordH, 44U));
            aWandererD = aWandererD + ((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterE, 60U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterD, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 18U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 21U) ^ RotL64(aNonceWordB, 29U)) ^ RotL64(aNonceWordC, 3U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 16304U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 12765U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 56U) ^ RotL64(aNonceWordA, 21U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 15821U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 14611U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCarry, 58U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererC + RotL64(aIngress, 47U)) + 12849591986267890852U) + aOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 21U)) + 8232614804696815750U;
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 11U)) + RotL64(aCarry, 57U)) + 12141567259210877281U;
            aOrbiterE = (((aWandererJ + RotL64(aCross, 54U)) + RotL64(aCarry, 39U)) + 2928641981037885644U) + aOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 27U)) + 980733350554783938U) + RotL64(aNonceWordH, 43U);
            aOrbiterK = ((aWandererE + RotL64(aScatter, 21U)) + 2683985177993350746U) + RotL64(aNonceWordF, 55U);
            aOrbiterA = (aWandererF + RotL64(aCross, 39U)) + 14532148403815527355U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 7736296629433884203U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 10428437770166310549U;
            aOrbiterB = RotL64((aOrbiterB * 326634742742373401U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 18327174144859461029U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 6810436935194432002U) ^ RotL64(aNonceWordA, 19U);
            aOrbiterC = RotL64((aOrbiterC * 2715987179577753597U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 12606153309690753435U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 17123256945895150555U;
            aOrbiterE = RotL64((aOrbiterE * 13469111258504672565U), 57U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterA) + 9057777759026189541U) + aOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1]) + RotL64(aNonceWordG, 13U);
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 16478485918911194442U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11054247078884894131U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 18064460487552100483U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 11477276762421684083U) ^ aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3886501230380184395U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 18318375441973295081U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 13849305985380030986U;
            aOrbiterK = RotL64((aOrbiterK * 12962140243967824959U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 10240409420338313641U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 18360586077779529086U;
            aOrbiterA = RotL64((aOrbiterA * 18196875422391501927U), 51U);
            //
            aIngress = RotL64(aOrbiterI, 41U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + RotL64(aOrbiterK, 60U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterB, 4U)) + aOrbiterK);
            aWandererE = aWandererE + (((((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 29U)) + aOrbiterK) + RotL64(aCarry, 21U)) + RotL64(aNonceWordC, 6U)) + aWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterA, 13U)) + aOrbiterB);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 29U) + RotL64(aOrbiterC, 41U)) + aOrbiterB) + RotL64(aNonceWordE, 59U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterE, 35U)) + aOrbiterI);
            aWandererD = aWandererD + (((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 57U)) + aOrbiterA) + RotL64(aCarry, 39U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 12U) + aOrbiterF) + RotL64(aOrbiterI, 19U)) + aWandererUpdateSaltF[((aIndex + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 12U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 21U) ^ RotL64(aNonceWordF, 13U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23729U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((aIndex + 24041U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 29U) ^ RotL64(aNonceWordE, 11U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 17420U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 22570U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 26U) ^ RotL64(aIngress, 41U)) + (RotL64(aPrevious, 53U) + RotL64(aCross, 13U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererA + RotL64(aIngress, 57U)) + 1457104756581596530U;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 37U)) + RotL64(aCarry, 27U)) + 6127240317844622874U;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 21U)) + 16492290056044189421U) + RotL64(aNonceWordE, 37U);
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 3U)) + 10963676850938416468U) + aOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = (((aWandererH + RotL64(aScatter, 11U)) + RotL64(aCarry, 53U)) + 4872917367399752405U) + RotL64(aNonceWordH, 55U);
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 29U)) + RotL64(aCarry, 13U)) + 15218882377875616148U;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 50U)) + 5934166612122118251U) + aOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 14215280930872003003U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 11428034799044600979U;
            aOrbiterK = RotL64((aOrbiterK * 12162528943733976177U), 21U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterG) + 5453003654321728726U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]) + RotL64(aNonceWordB, 61U);
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 14273775120265649389U) ^ RotL64(aNonceWordD, 27U);
            aOrbiterJ = RotL64((aOrbiterJ * 5139018128323795309U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 328723770018440271U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 13032190719588211088U;
            aOrbiterG = RotL64((aOrbiterG * 13363368478932798315U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 2386881543033598494U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 1649501123340887116U;
            aOrbiterD = RotL64((aOrbiterD * 11148976582360499033U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 16462401546754210583U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 1510579201823042227U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16287912400104043275U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 6889066000014251983U) + aOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 11324594596597724357U;
            aOrbiterF = RotL64((aOrbiterF * 15344987814648586023U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 12237796033168436537U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 17306069670330000343U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3167451351403385259U), 5U);
            //
            aIngress = RotL64(aOrbiterE, 37U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterK, 20U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterK, 54U));
            aWandererK = aWandererK + ((RotL64(aIngress, 51U) + aOrbiterF) + RotL64(aOrbiterD, 43U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterK, 11U)) + RotL64(aNonceWordG, 17U));
            aWandererG = aWandererG + (((RotL64(aCross, 41U) + aOrbiterK) + RotL64(aOrbiterC, 37U)) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 19U)) + aOrbiterD) + aWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererI = aWandererI + (((((RotL64(aIngress, 60U) + RotL64(aOrbiterF, 5U)) + aOrbiterC) + RotL64(aCarry, 21U)) + RotL64(aNonceWordC, 58U)) + aWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 23U) + aOrbiterJ) + RotL64(aOrbiterK, 29U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + (RotL64(aWandererI, 6U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 47U) ^ RotL64(aNonceWordC, 29U)) ^ RotL64(aNonceWordF, 37U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31590U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27787U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 39U) ^ RotL64(aNonceWordG, 21U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26015U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneD[((aIndex + 30651U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 28U) + RotL64(aCross, 5U)) ^ (RotL64(aPrevious, 43U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (((aWandererD + RotL64(aCross, 29U)) + RotL64(aCarry, 13U)) + 2225397913940961213U) + RotL64(aNonceWordE, 13U);
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 5U)) + 8342544893601343643U) + aOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = ((aWandererF + RotL64(aScatter, 35U)) + RotL64(aCarry, 41U)) + 162922186381417187U;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 23U)) + 11660218373710972210U) + RotL64(aNonceWordD, 59U);
            aOrbiterE = (aWandererK + RotL64(aPrevious, 57U)) + 14909034764605802354U;
            aOrbiterF = ((aWandererG + RotL64(aCross, 50U)) + 16776955237009701511U) + aOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 13U)) + RotL64(aCarry, 27U)) + 5834487809188925253U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 1498492772767040320U) + aOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 4161765458781579617U;
            aOrbiterI = RotL64((aOrbiterI * 15535994410289065281U), 11U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterE) + 10511923076962447765U) + aOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1]) + RotL64(aNonceWordA, 7U);
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 8575954471692620021U;
            aOrbiterF = RotL64((aOrbiterF * 12526744988828982731U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 6536325446331340573U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 1790628986900286346U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5262997114200816715U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 2623814807619278590U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 11676970995834706612U;
            aOrbiterE = RotL64((aOrbiterE * 10057461115132434901U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 13836786354224256591U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 6293096163612129260U) ^ RotL64(aNonceWordG, 23U);
            aOrbiterH = RotL64((aOrbiterH * 8977954126326217153U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 4271144764978661248U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 15938494256992560202U) ^ aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10004841288382726739U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 11038155227307702976U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 12408749795071243930U;
            aOrbiterJ = RotL64((aOrbiterJ * 5527720475032868855U), 57U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 29U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 6U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 37U) + aOrbiterE) + RotL64(aOrbiterF, 11U)) + aWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 57U)) + aOrbiterE);
            aWandererG = aWandererG + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 42U)) + aOrbiterH) + RotL64(aCarry, 41U)) + RotL64(aNonceWordH, 55U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 53U) + aOrbiterI) + RotL64(aOrbiterE, 5U));
            aWandererI = aWandererI + (((RotL64(aCross, 60U) + RotL64(aOrbiterJ, 21U)) + aOrbiterH) + RotL64(aNonceWordB, 8U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterD, 51U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 35U)) + aOrbiterD) + RotL64(aCarry, 11U)) + aWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 60U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xE32AD546D1826F49ULL + 0xE54E40D8B2274A23ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xD3D65348388941EFULL + 0xA9F49388FE9BEBBFULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xA0524C023B66D079ULL + 0xF3B7A9E244FA09F1ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xEC85426596F57E7FULL + 0xC3DB636A51FC2095ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xE14ECB5A8B82CE2DULL + 0xE32EAD836BC6A438ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xDA11594A52319F4FULL + 0xA19C4B2C3B9E9CA4ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xDB85FE1DFCE7739DULL + 0xACFD78FFE4CDEDDEULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xDC0D663E26A795E3ULL + 0xB316B41FEE09C398ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 47U) ^ RotL64(aNonceWordG, 27U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2614U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2587U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 11U) ^ RotL64(aNonceWordC, 3U)) ^ RotL64(aNonceWordH, 57U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 292U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 5064U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aPrevious, 26U)) + (RotL64(aIngress, 5U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (((aWandererE + RotL64(aPrevious, 39U)) + RotL64(aCarry, 37U)) + 12029393034357490020U) + aOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = (aWandererA + RotL64(aCross, 30U)) + 4526754731580694987U;
            aOrbiterG = (aWandererD + RotL64(aScatter, 11U)) + 17060419646421271853U;
            aOrbiterE = (aWandererK + RotL64(aIngress, 43U)) + 4128488893837059683U;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 23U)) + RotL64(aCarry, 47U)) + 12706894827547160110U;
            aOrbiterD = (aWandererG + RotL64(aIngress, 13U)) + 12506324593645825056U;
            aOrbiterC = (((aWandererI + RotL64(aCross, 35U)) + 12581344490649250025U) + aOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1]) + RotL64(aNonceWordH, 37U);
            aOrbiterK = (aWandererF + RotL64(aPrevious, 20U)) + 14357032418199130132U;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 3U)) + 15341977701796331249U) + RotL64(aNonceWordE, 53U);
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 47U)) + 7086602307544733241U;
            aOrbiterI = ((aWandererB + RotL64(aCross, 51U)) + RotL64(aCarry, 3U)) + 12398300065276832486U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 2499745046076601988U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 7249361592814001829U;
            aOrbiterG = RotL64((aOrbiterG * 14597139848072319685U), 57U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterB) + 3254456186337366437U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]) + RotL64(aNonceWordF, 15U);
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 3472973415969046680U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14583566953969168353U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 7905718972111691591U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 15941413652144021522U;
            aOrbiterJ = RotL64((aOrbiterJ * 3473779492962783565U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 10583964125960308762U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 13659925272340853715U;
            aOrbiterE = RotL64((aOrbiterE * 16708294803316630743U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 9487054537489454887U) + aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 13287757570441887517U) ^ RotL64(aNonceWordB, 11U);
            aOrbiterC = RotL64((aOrbiterC * 17351439045329892107U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 15279245465808571942U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 12424999114621745879U;
            aOrbiterA = RotL64((aOrbiterA * 2274918760256527137U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 13915392738892970475U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 13797668053788805126U;
            aOrbiterI = RotL64((aOrbiterI * 13752161103680525317U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 14344766585550401077U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 13727554194373146727U;
            aOrbiterH = RotL64((aOrbiterH * 17164450431362670223U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 1332966642432651232U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 938583742533681467U;
            aOrbiterB = RotL64((aOrbiterB * 13323340043936037549U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 5659239372701978244U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 8501778564909302938U;
            aOrbiterK = RotL64((aOrbiterK * 15629932660749672503U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 1698500835332753591U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 12029393034357490020U;
            aOrbiterF = RotL64((aOrbiterF * 18176507271635640153U), 27U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterF, 29U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + (RotL64(aOrbiterH, 23U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterK, 56U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 21U));
            aIngress = aIngress + RotL64(aOrbiterI, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 44U) + RotL64(aOrbiterG, 29U)) + aOrbiterE);
            aWandererK = aWandererK + ((RotL64(aIngress, 21U) + aOrbiterI) + RotL64(aOrbiterD, 39U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterF, 35U)) + aOrbiterA);
            aWandererD = aWandererD + (((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterH, 12U)) + RotL64(aNonceWordC, 56U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 37U) + aOrbiterD) + RotL64(aOrbiterJ, 41U));
            aWandererI = aWandererI + (((RotL64(aScatter, 51U) + aOrbiterB) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 23U) + aOrbiterC) + RotL64(aOrbiterH, 47U)) + aWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterE, 27U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 41U) + aOrbiterC) + RotL64(aOrbiterI, 43U)) + RotL64(aNonceWordD, 9U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 26U) + RotL64(aOrbiterF, 23U)) + aOrbiterH) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterK, 56U)) + aOrbiterC) + aWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 34U));
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 38U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 19U) ^ RotL64(aNonceWordE, 11U)) ^ RotL64(aNonceWordA, 43U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 14462U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneD[((aIndex + 11364U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 53U) ^ RotL64(aNonceWordD, 39U)) ^ RotL64(aNonceWordH, 13U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15676U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10533U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCarry, 10U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererK + RotL64(aScatter, 53U)) + 4739486756133131180U;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 57U)) + RotL64(aCarry, 11U)) + 16089707555501328184U;
            aOrbiterG = (aWandererE + RotL64(aCross, 11U)) + 15310047330238536453U;
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 23U)) + RotL64(aCarry, 3U)) + 7901411596386834955U;
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 40U)) + 4357555491060982163U) + aOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aScatter, 21U)) + 15667085602825720102U;
            aOrbiterB = ((((aWandererB + RotL64(aCross, 3U)) + RotL64(aCarry, 47U)) + 8520635334382269253U) + aOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1]) + RotL64(aNonceWordA, 51U);
            aOrbiterC = (aWandererC + RotL64(aIngress, 51U)) + 1772509779231068315U;
            aOrbiterA = ((aWandererD + RotL64(aCross, 29U)) + 15336170957886025677U) + RotL64(aNonceWordC, 41U);
            aOrbiterI = (aWandererH + RotL64(aPrevious, 27U)) + 8628770833489469980U;
            aOrbiterF = (aWandererI + RotL64(aScatter, 6U)) + 15469234024247246228U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 10796430900884288328U) + aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 10660110397012853289U;
            aOrbiterG = RotL64((aOrbiterG * 9140007610912037461U), 27U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterK) + 11202284258711214794U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]) + RotL64(aNonceWordG, 39U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 17509491802893182994U;
            aOrbiterJ = RotL64((aOrbiterJ * 9329107599972703671U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 16212572740740103554U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 2190030203761579226U;
            aOrbiterK = RotL64((aOrbiterK * 3101886685668871045U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 12014337082293041909U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 3733531010807001506U;
            aOrbiterB = RotL64((aOrbiterB * 5797362244066062299U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 7100994963061975529U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 17837541162838600258U) ^ aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8745987361678166553U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 3311518938023146951U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 7709505172646831553U;
            aOrbiterD = RotL64((aOrbiterD * 7121143171245765213U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 4979968094554018443U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 16822214821463034107U;
            aOrbiterE = RotL64((aOrbiterE * 8618262120451291765U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 8376124175020587079U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 11084586282092424876U;
            aOrbiterH = RotL64((aOrbiterH * 5835632742522563537U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 7816368455027681621U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 10893292019060642422U;
            aOrbiterC = RotL64((aOrbiterC * 3995821210667317677U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 13602875505184178486U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 5425735673005681983U;
            aOrbiterI = RotL64((aOrbiterI * 12667085597129312079U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 5995385043278810987U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 4739486756133131180U) ^ RotL64(aNonceWordF, 5U);
            aOrbiterF = RotL64((aOrbiterF * 15709273328685013399U), 41U);
            //
            aIngress = RotL64(aOrbiterH, 37U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + (RotL64(aOrbiterA, 10U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 54U)) + aOrbiterK) + RotL64(aNonceWordD, 55U));
            aWandererI = aWandererI + (((RotL64(aCross, 38U) + RotL64(aOrbiterI, 23U)) + aOrbiterE) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterI, 21U)) + aOrbiterK);
            aWandererE = aWandererE + (((RotL64(aIngress, 3U) + RotL64(aOrbiterA, 3U)) + aOrbiterJ) + aWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 5U) + aOrbiterF) + RotL64(aOrbiterI, 27U));
            aWandererH = aWandererH + (((RotL64(aIngress, 51U) + aOrbiterE) + RotL64(aOrbiterJ, 11U)) + RotL64(aNonceWordH, 18U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterB, 13U)) + aOrbiterE) + aWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 12U) + RotL64(aOrbiterD, 6U)) + aOrbiterC) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterG, 57U)) + aOrbiterH);
            aWandererK = aWandererK + ((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 39U)) + aOrbiterB);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 53U) + aOrbiterK) + RotL64(aOrbiterC, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 18U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 4U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 13U) ^ RotL64(aNonceWordB, 29U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 23176U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18893U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 39U) ^ RotL64(aNonceWordH, 24U)) ^ RotL64(aNonceWordC, 5U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 22575U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 23269U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aPrevious, 21U)) ^ (RotL64(aIngress, 35U) + RotL64(aCross, 48U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererE + RotL64(aScatter, 5U)) + 1142447269198373880U;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 43U)) + RotL64(aCarry, 39U)) + 10581460640040336191U;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 41U)) + RotL64(aCarry, 23U)) + 14703062773878202900U;
            aOrbiterC = (aWandererI + RotL64(aCross, 3U)) + 15737525756286914746U;
            aOrbiterB = (aWandererC + RotL64(aPrevious, 51U)) + 16178774478273186999U;
            aOrbiterI = (((aWandererH + RotL64(aCross, 58U)) + RotL64(aCarry, 27U)) + 2514897053906809160U) + RotL64(aNonceWordD, 5U);
            aOrbiterH = (((aWandererF + RotL64(aScatter, 11U)) + 13702496607592508464U) + aOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1]) + RotL64(aNonceWordA, 31U);
            aOrbiterE = (aWandererG + RotL64(aIngress, 27U)) + 18030885275418337965U;
            aOrbiterF = (aWandererJ + RotL64(aScatter, 39U)) + 5241783876161655984U;
            aOrbiterA = (aWandererB + RotL64(aCross, 21U)) + 2807052676283587925U;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 54U)) + 8022804576763271327U) + aOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 15597099852232205860U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 1538435607932096400U;
            aOrbiterD = RotL64((aOrbiterD * 7900752511710516981U), 53U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterB) + 11147868774413615365U) + aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1]) + RotL64(aNonceWordG, 7U);
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 9325213746830411568U;
            aOrbiterI = RotL64((aOrbiterI * 561819005818948769U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 13792300423550555634U) + RotL64(aNonceWordF, 41U);
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 3134856508983945719U;
            aOrbiterG = RotL64((aOrbiterG * 4271845067763664863U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 8654966018053784882U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 8937113935476779267U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7386875687217705855U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 4135676350355234788U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 11407912615743682678U;
            aOrbiterE = RotL64((aOrbiterE * 2773506587480714695U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 10966950663872392059U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 6686634993700944582U;
            aOrbiterA = RotL64((aOrbiterA * 2509459942163678241U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 14154407529749257990U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 18054640398549782388U) ^ aOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7830759861389060149U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 14623473030642960240U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 1857945571104460086U;
            aOrbiterC = RotL64((aOrbiterC * 18039903315045620079U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 17650774450811065797U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 9458168381246672881U;
            aOrbiterH = RotL64((aOrbiterH * 3452665113988737563U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 16604923466236483242U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 12447748535184711684U;
            aOrbiterF = RotL64((aOrbiterF * 5982708155382249061U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 9589720286549780720U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 1142447269198373880U;
            aOrbiterK = RotL64((aOrbiterK * 8176719948031280789U), 39U);
            //
            aIngress = RotL64(aOrbiterK, 43U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterH, 38U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 23U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aIngress, 19U) + RotL64(aOrbiterC, 46U)) + aOrbiterD) + RotL64(aNonceWordE, 11U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 35U) + aOrbiterG) + RotL64(aOrbiterI, 35U));
            aWandererA = aWandererA + (((RotL64(aCross, 11U) + aOrbiterG) + RotL64(aOrbiterF, 21U)) + aWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterJ, 5U));
            aWandererI = aWandererI + ((RotL64(aScatter, 54U) + aOrbiterA) + RotL64(aOrbiterJ, 10U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 41U) + aOrbiterB) + RotL64(aOrbiterK, 41U));
            aWandererG = aWandererG + (((RotL64(aCross, 23U) + aOrbiterG) + RotL64(aOrbiterH, 37U)) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 29U)) + aOrbiterJ);
            aWandererH = aWandererH + (((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 13U)) + aOrbiterH) + RotL64(aCarry, 3U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 39U)) + aOrbiterD);
            aWandererK = aWandererK + ((((RotL64(aCross, 4U) + RotL64(aOrbiterE, 43U)) + aOrbiterC) + RotL64(aNonceWordB, 6U)) + aWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (RotL64(aWandererI, 26U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 38U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 5U) ^ RotL64(aNonceWordA, 57U)) ^ RotL64(aNonceWordD, 21U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 27839U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26745U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 28U) ^ RotL64(aNonceWordH, 57U)) ^ RotL64(aNonceWordE, 3U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31677U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneD[((aIndex + 29473U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 35U)) ^ (RotL64(aCross, 54U) + RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererI + RotL64(aPrevious, 51U)) + 4980738603982643969U;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 5U)) + 17660278413018470020U) + RotL64(aNonceWordH, 8U);
            aOrbiterH = (aWandererJ + RotL64(aCross, 19U)) + 17598114429859543466U;
            aOrbiterK = (aWandererF + RotL64(aScatter, 13U)) + 10993929335279994739U;
            aOrbiterF = (aWandererA + RotL64(aCross, 28U)) + 17967203122976322481U;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 53U)) + RotL64(aCarry, 19U)) + 1872290205549034384U;
            aOrbiterA = (((aWandererH + RotL64(aIngress, 47U)) + RotL64(aCarry, 37U)) + 16607778671782810797U) + aOrbiterAssignSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = (((aWandererD + RotL64(aPrevious, 23U)) + RotL64(aCarry, 3U)) + 4895226930754394376U) + RotL64(aNonceWordE, 39U);
            aOrbiterC = (aWandererC + RotL64(aCross, 10U)) + 14960359005982301383U;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 39U)) + 9921642352377700630U) + aOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aIngress, 3U)) + 893281964367208693U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 8232519988397858732U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 4433022122758913407U;
            aOrbiterH = RotL64((aOrbiterH * 834240393225479419U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 12689609831247168353U) + aOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 404535388957472176U;
            aOrbiterF = RotL64((aOrbiterF * 14534020545479806593U), 5U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterH) + 3349108201964013155U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]) + RotL64(aNonceWordC, 43U);
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 4386449511297371730U;
            aOrbiterG = RotL64((aOrbiterG * 9596273264321140229U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 14314587717949070586U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 10923886625271054985U;
            aOrbiterA = RotL64((aOrbiterA * 7838969002623486809U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 17634909585329833520U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 2021301459918350372U;
            aOrbiterJ = RotL64((aOrbiterJ * 1388242915918642741U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 5219599112498224367U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 10641339455385046206U) ^ RotL64(aNonceWordA, 51U);
            aOrbiterC = RotL64((aOrbiterC * 1022283727595400719U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 5003342156562330058U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 10951027475628404336U;
            aOrbiterD = RotL64((aOrbiterD * 17836928292555158461U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 13040991872592235460U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 11149099984302782267U;
            aOrbiterB = RotL64((aOrbiterB * 4248667283139686251U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 2202253777854402763U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 16679038924474862612U;
            aOrbiterI = RotL64((aOrbiterI * 2624443661523083597U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 1959650241410955571U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 8415989510614674816U;
            aOrbiterE = RotL64((aOrbiterE * 16340289102832732519U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 2344501711730399821U) + aOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 4980738603982643969U;
            aOrbiterK = RotL64((aOrbiterK * 6419275275477478723U), 39U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 5U);
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterE, 19U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 46U));
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterB, 56U)) + aOrbiterI);
            aWandererG = aWandererG + ((RotL64(aScatter, 30U) + aOrbiterJ) + RotL64(aOrbiterI, 47U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 53U) + aOrbiterB) + RotL64(aOrbiterF, 43U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 29U)) + aOrbiterD);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 5U)) + aOrbiterH);
            aWandererK = aWandererK + (((RotL64(aIngress, 34U) + RotL64(aOrbiterK, 27U)) + aOrbiterC) + aWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 11U) + aOrbiterG) + RotL64(aOrbiterE, 11U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 21U) + aOrbiterJ) + RotL64(aOrbiterA, 40U)) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterE, 35U)) + aWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aScatter, 23U) + aOrbiterA) + RotL64(aOrbiterK, 37U)) + RotL64(aCarry, 23U)) + RotL64(aNonceWordG, 17U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterD, 21U)) + RotL64(aNonceWordB, 23U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 40U));
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + RotL64(aWandererA, 26U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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

void TwistExpander_Fencing_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xFF77DDB8ED0234E7ULL + 0xD45926384FA86D11ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xBC0471A4AE91ABABULL + 0xD4B96E0234B3C0EAULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xFD56242CBD0C01B1ULL + 0xD05E171A6F550D7AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xA683A356E851742BULL + 0xDB2A09052C33D93AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xA595015B214A5025ULL + 0xCA1EF5FA74ED3110ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xB9ECE336B14070B9ULL + 0xF9731985B46D6CCDULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xF8FB9A92F3D1F52BULL + 0xFB19EFBA3C8A7C62ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xCB810C028251AECDULL + 0xD513FAEC0F3ABADFULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 47U) ^ RotL64(aNonceWordE, 39U)) ^ RotL64(aNonceWordC, 13U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 1421U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneC[((aIndex + 1016U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 58U) ^ RotL64(aNonceWordD, 11U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 1643U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((aIndex + 4823U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCarry, 41U)) ^ (RotL64(aPrevious, 27U) + RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererI + RotL64(aIngress, 35U)) + 13499155707765393469U) + aOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (((aWandererK + RotL64(aScatter, 19U)) + RotL64(aCarry, 13U)) + 3740324981823726185U) + aOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = (aWandererC + RotL64(aCross, 60U)) + 5470765363949735652U;
            aOrbiterE = (aWandererE + RotL64(aPrevious, 23U)) + 3446436171274452326U;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 39U)) + RotL64(aCarry, 43U)) + 1778929412631211933U;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 27U)) + 14666308799855220954U) + RotL64(aNonceWordD, 19U);
            aOrbiterC = (aWandererG + RotL64(aScatter, 11U)) + 4548410236791175055U;
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 5U)) + RotL64(aCarry, 35U)) + 5829739767694190372U;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 56U)) + 14319231414903675748U) + RotL64(aNonceWordG, 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 1513851750246111405U) + aOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 1685620217748986019U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9286548037413609445U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 16284162182006054402U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 6271539598462003309U;
            aOrbiterJ = RotL64((aOrbiterJ * 13923286694131331137U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 12669312437565969473U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 11894755313393001665U;
            aOrbiterA = RotL64((aOrbiterA * 12556759675372354075U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 6315983824634946566U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 17106616474222892782U;
            aOrbiterI = RotL64((aOrbiterI * 167205520766791073U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 13350266700180455548U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 4608846311203767162U;
            aOrbiterH = RotL64((aOrbiterH * 2504857468837437365U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 14195866746143604365U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 7917977448256795054U;
            aOrbiterE = RotL64((aOrbiterE * 5927771378657284557U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 10707336923305131629U) + RotL64(aNonceWordC, 38U);
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 17122696159336995392U;
            aOrbiterC = RotL64((aOrbiterC * 13953518568670659191U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 5182322763573586116U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterA) ^ 6503754948502556246U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]) ^ RotL64(aNonceWordA, 25U);
            aOrbiterF = RotL64((aOrbiterF * 14749002194140663519U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 14907832047832987341U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 6258064448676621346U) ^ aOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4407960312705621487U), 47U);
            //
            aIngress = RotL64(aOrbiterJ, 6U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aScatter, 51U) + RotL64(aOrbiterD, 23U)) + aOrbiterJ) + RotL64(aCarry, 27U)) + aWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 22U) + RotL64(aOrbiterA, 39U)) + aOrbiterH);
            aWandererA = aWandererA + ((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterH, 35U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 27U) + aOrbiterD) + RotL64(aOrbiterE, 48U)) + RotL64(aNonceWordE, 15U));
            aWandererH = aWandererH + ((RotL64(aIngress, 39U) + aOrbiterF) + RotL64(aOrbiterG, 5U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 18U) + aOrbiterG) + RotL64(aOrbiterI, 19U));
            aWandererB = aWandererB + ((((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 41U)) + aWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterE, 27U)) + RotL64(aNonceWordF, 3U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterI, 58U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (RotL64(aWandererD, 18U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 14U) ^ RotL64(aNonceWordH, 23U)) ^ RotL64(aNonceWordA, 35U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 6264U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneD[((aIndex + 10502U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 5U) ^ RotL64(aNonceWordC, 14U)) ^ RotL64(aNonceWordB, 57U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 10692U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((aIndex + 6444U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aIngress, 11U)) ^ (RotL64(aPrevious, 58U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 35U)) + RotL64(aCarry, 19U)) + 252059974543142812U;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 24U)) + 11690823093681457368U) + aOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = (((aWandererC + RotL64(aScatter, 5U)) + RotL64(aCarry, 51U)) + 13282189752890971123U) + RotL64(aNonceWordA, 41U);
            aOrbiterC = (aWandererH + RotL64(aCross, 43U)) + 9507416294305708435U;
            aOrbiterF = (aWandererI + RotL64(aScatter, 29U)) + 14053038174390776539U;
            aOrbiterG = (aWandererA + RotL64(aCross, 39U)) + 14605253312318725009U;
            aOrbiterK = (((aWandererE + RotL64(aPrevious, 19U)) + RotL64(aCarry, 27U)) + 18138286582677863671U) + RotL64(aNonceWordD, 57U);
            aOrbiterI = (aWandererB + RotL64(aIngress, 11U)) + 8530091235978489988U;
            aOrbiterA = ((aWandererK + RotL64(aCross, 52U)) + 14381731677571170073U) + aOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 13316413456378978456U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 3910529530149320706U;
            aOrbiterE = RotL64((aOrbiterE * 16000139333493588429U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 6302070286831566901U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 12324134652758551396U;
            aOrbiterF = RotL64((aOrbiterF * 17136438281540250165U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 4773478557638475048U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 4031153435446078944U) ^ aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3876928995240982769U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 3114794895962903899U) + RotL64(aNonceWordH, 47U);
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 3552936509969106796U;
            aOrbiterI = RotL64((aOrbiterI * 16823186892738820299U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 5828754613946145627U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 17985241114076114558U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1986669631395606833U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 11319331046368072261U) + aOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 6104267020171882160U;
            aOrbiterH = RotL64((aOrbiterH * 12525117969211576177U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 7662668379725735125U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 6583034411403600735U;
            aOrbiterC = RotL64((aOrbiterC * 262095656452193889U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 5569865728026310280U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterI) ^ 4176065898330374039U) ^ aOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1]) ^ RotL64(aNonceWordB, 10U);
            aOrbiterG = RotL64((aOrbiterG * 11305749530796963967U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 13677146592276526676U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 2734371113158117596U;
            aOrbiterB = RotL64((aOrbiterB * 13146444882662731975U), 47U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterE, 19U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + (RotL64(aOrbiterA, 48U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterG, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 41U) + aOrbiterI) + RotL64(aOrbiterG, 47U)) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterB, 56U)) + aOrbiterI);
            aWandererH = aWandererH + (((((RotL64(aPrevious, 53U) + RotL64(aOrbiterB, 23U)) + aOrbiterF) + RotL64(aCarry, 43U)) + RotL64(aNonceWordG, 29U)) + aWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 58U) + aOrbiterI) + RotL64(aOrbiterK, 39U)) + aWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterH, 35U)) + aOrbiterI) + RotL64(aNonceWordF, 45U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 43U)) + aOrbiterA);
            aWandererB = aWandererB + ((RotL64(aIngress, 13U) + aOrbiterC) + RotL64(aOrbiterK, 19U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 22U) + RotL64(aOrbiterB, 14U)) + aOrbiterA);
            aWandererC = aWandererC + ((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterA, 51U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 14U));
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 39U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 27U) ^ RotL64(aNonceWordC, 43U)) ^ RotL64(aNonceWordF, 19U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12327U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15952U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 43U) ^ RotL64(aNonceWordB, 22U)) ^ RotL64(aNonceWordE, 13U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 14919U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((aIndex + 16367U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 60U) ^ RotL64(aIngress, 41U)) + (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererD + RotL64(aScatter, 37U)) + 5173905450211892891U) + RotL64(aNonceWordD, 5U);
            aOrbiterA = ((aWandererE + RotL64(aIngress, 19U)) + 3555542451908039957U) + RotL64(aNonceWordH, 59U);
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 47U)) + RotL64(aCarry, 35U)) + 11559884700283861559U;
            aOrbiterG = (aWandererH + RotL64(aCross, 51U)) + 1352524329968738673U;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 60U)) + 8914206450420616349U;
            aOrbiterE = (((aWandererB + RotL64(aIngress, 27U)) + RotL64(aCarry, 53U)) + 2251523378498463946U) + aOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aScatter, 5U)) + 9541575923299247038U;
            aOrbiterH = ((aWandererI + RotL64(aCross, 41U)) + RotL64(aCarry, 5U)) + 1239854507907214595U;
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 14U)) + 17698101462598498934U) + aOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 12305566971683256060U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 13804545036303215569U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10359543704152744971U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 10239749097704329264U) + RotL64(aNonceWordA, 9U);
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 4212214906286320308U) ^ aOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3661436621615751071U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 12192418916967430783U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 4475514289326450361U;
            aOrbiterG = RotL64((aOrbiterG * 17497164630368757887U), 47U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterF) + 17376102613298827459U) + aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1]) + RotL64(aNonceWordG, 49U);
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 18129393209955439341U;
            aOrbiterA = RotL64((aOrbiterA * 6404089025014118979U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 4014763724300253568U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 17325007199676828814U;
            aOrbiterI = RotL64((aOrbiterI * 1420888274815627083U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 15480474849292388685U) + aOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 14357924730184375449U;
            aOrbiterE = RotL64((aOrbiterE * 16723492259068034209U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 4335731868597970070U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 8296023680394303015U;
            aOrbiterF = RotL64((aOrbiterF * 14027415401430120543U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 2807312426993262800U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 15510369660839648501U;
            aOrbiterH = RotL64((aOrbiterH * 18207954408298333959U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 12597844696606519907U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 7231012798553551535U;
            aOrbiterK = RotL64((aOrbiterK * 2841306785994479299U), 13U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 43U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 50U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + RotL64(aOrbiterD, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 23U) + aOrbiterI) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 34U) + RotL64(aOrbiterD, 57U)) + aOrbiterG) + aWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 19U)) + aOrbiterK) + aWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterH, 42U));
            aWandererF = aWandererF + ((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterB, 53U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterK, 23U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 41U) + RotL64(aOrbiterD, 37U)) + aOrbiterF) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterE, 11U)) + aOrbiterI) + RotL64(aNonceWordB, 25U));
            aWandererK = aWandererK + (((RotL64(aCross, 52U) + RotL64(aOrbiterG, 46U)) + aOrbiterB) + RotL64(aNonceWordE, 16U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 26U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 51U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 13U) ^ RotL64(aNonceWordE, 5U)) ^ RotL64(aNonceWordG, 58U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 21613U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((aIndex + 16661U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 6U) ^ RotL64(aNonceWordA, 43U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19664U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneD[((aIndex + 21265U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 29U) + RotL64(aCarry, 14U)) + (RotL64(aIngress, 57U) ^ RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererJ + RotL64(aCross, 47U)) + 7960325128608297381U;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 39U)) + 12773836012104052042U) + aOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aScatter, 29U)) + 3173972621347773016U;
            aOrbiterB = (((aWandererB + RotL64(aPrevious, 14U)) + RotL64(aCarry, 19U)) + 3708401356314308171U) + aOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = ((aWandererD + RotL64(aCross, 51U)) + RotL64(aCarry, 47U)) + 950774285720019449U;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 19U)) + 4170092315705438265U;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 5U)) + 17000449130864980747U) + RotL64(aNonceWordB, 9U);
            aOrbiterF = ((aWandererH + RotL64(aScatter, 43U)) + 8793910540062893860U) + RotL64(aNonceWordE, 36U);
            aOrbiterE = ((aWandererK + RotL64(aIngress, 60U)) + RotL64(aCarry, 29U)) + 520277969543516469U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 12762214857389827271U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 2932451184340207695U;
            aOrbiterJ = RotL64((aOrbiterJ * 7513337346940091655U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 11062179998786293839U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 7919119215271524178U) ^ aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9053677007180081359U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 1774988449597115155U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 3799792889466518953U;
            aOrbiterK = RotL64((aOrbiterK * 17512791286490623455U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 1815062051307896589U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 15260373951371654483U;
            aOrbiterI = RotL64((aOrbiterI * 2208604434669491625U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 12867546628945676853U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 7772820973895846946U) ^ RotL64(aNonceWordG, 15U);
            aOrbiterB = RotL64((aOrbiterB * 7581704643538761985U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 14213957831821966834U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 16561105721170419454U;
            aOrbiterH = RotL64((aOrbiterH * 2540533987337175367U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 16556502948339949526U) + aOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 9706742922075498974U;
            aOrbiterF = RotL64((aOrbiterF * 8527361328901355457U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 13455756934917486016U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 9107769876332723454U;
            aOrbiterE = RotL64((aOrbiterE * 1722386100852683783U), 39U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterE) + 15793099079168487016U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]) + RotL64(aNonceWordA, 51U);
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 7968278803691283365U;
            aOrbiterD = RotL64((aOrbiterD * 11644765391940099387U), 47U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterB, 47U);
            aIngress = aIngress + (RotL64(aOrbiterK, 30U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 56U) + RotL64(aOrbiterH, 27U)) + aOrbiterA);
            aWandererG = aWandererG + (((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 3U)) + aOrbiterK) + aWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 3U) + aOrbiterK) + RotL64(aOrbiterE, 12U)) + RotL64(aNonceWordH, 23U));
            aWandererD = aWandererD + (((((RotL64(aScatter, 39U) + RotL64(aOrbiterA, 39U)) + aOrbiterB) + RotL64(aCarry, 35U)) + RotL64(aNonceWordC, 35U)) + aWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 53U)) + aOrbiterI);
            aWandererH = aWandererH + ((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterJ, 19U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 12U) + aOrbiterK) + RotL64(aOrbiterH, 47U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterF, 23U)) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 23U) + aOrbiterF) + RotL64(aOrbiterA, 60U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 40U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 34U) ^ RotL64(aNonceWordG, 13U)) ^ RotL64(aNonceWordE, 5U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22464U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((aIndex + 25826U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 11U) ^ RotL64(aNonceWordA, 41U)) ^ RotL64(aNonceWordH, 3U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22126U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26943U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCross, 38U)) ^ (RotL64(aCarry, 51U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererH + RotL64(aIngress, 30U)) + 5480870806135400132U;
            aOrbiterI = ((aWandererB + RotL64(aCross, 47U)) + RotL64(aCarry, 35U)) + 8034874599430768743U;
            aOrbiterD = (((aWandererD + RotL64(aPrevious, 43U)) + RotL64(aCarry, 43U)) + 4006919843736863767U) + RotL64(aNonceWordH, 21U);
            aOrbiterH = (aWandererA + RotL64(aScatter, 35U)) + 2988069748674633718U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 39U)) + 12347295651973135786U) + aOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aPrevious, 51U)) + 14152683894431568192U;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 19U)) + 15765143815254196598U) + aOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aIngress, 5U)) + RotL64(aCarry, 27U)) + 10473067082331244233U;
            aOrbiterK = ((aWandererF + RotL64(aCross, 10U)) + 1089466925383677249U) + RotL64(aNonceWordC, 31U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 13215039929873682230U) + RotL64(aNonceWordA, 43U);
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 3957997712247961479U) ^ aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7631186240013784703U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 10023907397941685546U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 14593012591254614353U;
            aOrbiterB = RotL64((aOrbiterB * 17111300092082154687U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 13353797968154036726U) + RotL64(aNonceWordF, 61U);
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 9259966668512102858U;
            aOrbiterF = RotL64((aOrbiterF * 8326732574268308221U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 10757861831070349321U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 10530223113483866178U;
            aOrbiterK = RotL64((aOrbiterK * 11269177745265396583U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 7554320926405521865U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 6978052067277966996U;
            aOrbiterG = RotL64((aOrbiterG * 18020134738536217801U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 1053695861967171420U) + aOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 15980734683539854451U;
            aOrbiterH = RotL64((aOrbiterH * 3208466640010555357U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 17041258393808061556U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 12846551858751995530U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9303891433380993639U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 14617434286683320666U) + aOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 3999309956180741302U;
            aOrbiterI = RotL64((aOrbiterI * 15037707937050015205U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 13452627760403094126U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 2633241575260427158U;
            aOrbiterA = RotL64((aOrbiterA * 2638570213290747581U), 39U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 6U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 3U)) + aOrbiterE) + aWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 29U) + RotL64(aOrbiterE, 47U)) + aOrbiterH) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 52U) + aOrbiterB) + RotL64(aOrbiterI, 14U)) + RotL64(aNonceWordB, 26U)) + aWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 11U) + aOrbiterB) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterI, 23U)) + aOrbiterE) + RotL64(aNonceWordE, 55U));
            aWandererF = aWandererF + ((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterF, 27U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterD, 42U)) + aOrbiterA);
            aWandererH = aWandererH + ((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterA, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 34U) + aOrbiterG) + RotL64(aOrbiterD, 35U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 12U));
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + RotL64(aWandererC, 41U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 37U) ^ RotL64(aNonceWordB, 3U)) ^ RotL64(aNonceWordG, 13U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29288U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((aIndex + 30068U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 27U) ^ RotL64(aNonceWordA, 39U)) ^ RotL64(aNonceWordD, 14U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31193U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 31194U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aPrevious, 19U)) + (RotL64(aIngress, 41U) + RotL64(aCarry, 6U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererE + RotL64(aIngress, 43U)) + 17264605017518259932U;
            aOrbiterD = (((aWandererG + RotL64(aScatter, 39U)) + RotL64(aCarry, 13U)) + 15209184354580778643U) + aOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = ((((aWandererJ + RotL64(aCross, 29U)) + RotL64(aCarry, 37U)) + 3299527965014731384U) + aOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1]) + RotL64(aNonceWordH, 39U);
            aOrbiterF = (aWandererA + RotL64(aPrevious, 60U)) + 16293096431816127821U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 35U)) + RotL64(aCarry, 21U)) + 11031983436878828337U;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 47U)) + 9188018632448236358U) + RotL64(aNonceWordC, 51U);
            aOrbiterB = (aWandererD + RotL64(aCross, 23U)) + 13420816400363406556U;
            aOrbiterC = (aWandererH + RotL64(aScatter, 12U)) + 2485063384097917101U;
            aOrbiterK = (aWandererK + RotL64(aCross, 53U)) + 3089135816938128264U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 10730544971770435788U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 10431767565618874806U;
            aOrbiterI = RotL64((aOrbiterI * 4723078464590561545U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 14883796491656899074U) + aOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 13465877783538483706U;
            aOrbiterA = RotL64((aOrbiterA * 14311686051108108503U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 13322163435314643713U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 3307316600284371955U;
            aOrbiterB = RotL64((aOrbiterB * 12337846092069506365U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 4950101626975919939U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 2596253994220103666U;
            aOrbiterC = RotL64((aOrbiterC * 7181706961838582889U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 17961706029559914243U) + aOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 10321902557977495175U) ^ aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16189559888625084711U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 18146616411403012772U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 8414050129421955787U;
            aOrbiterJ = RotL64((aOrbiterJ * 14879448948196182863U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 11739172334166341121U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 7936637782633487291U) ^ RotL64(aNonceWordB, 19U);
            aOrbiterF = RotL64((aOrbiterF * 14940929920543800413U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 3160044627483874242U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 16816384076887379704U) ^ RotL64(aNonceWordA, 36U);
            aOrbiterG = RotL64((aOrbiterG * 5052772186568301951U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 8101560104988710226U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 8851416379738817624U;
            aOrbiterD = RotL64((aOrbiterD * 16767420038937389027U), 13U);
            //
            aIngress = RotL64(aOrbiterJ, 60U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + RotL64(aOrbiterG, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 11U) + RotL64(aOrbiterF, 29U)) + aOrbiterC) + RotL64(aCarry, 37U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 18U)) + aOrbiterI) + aWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 43U) + aOrbiterJ) + RotL64(aOrbiterK, 11U)) + aWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 18U) + RotL64(aOrbiterG, 37U)) + aOrbiterC);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterG, 23U)) + aOrbiterF) + RotL64(aCarry, 19U)) + RotL64(aNonceWordE, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterA, 57U));
            aWandererA = aWandererA + ((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterD, 3U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 52U) + RotL64(aOrbiterB, 53U)) + aOrbiterK);
            aWandererE = aWandererE + (((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterD, 42U)) + RotL64(aNonceWordF, 41U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 48U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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

void TwistExpander_Fencing_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x8D9BDD01F2275F9FULL + 0xD8A8475072A096ABULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xFCE7891C2D79863BULL + 0xEF08F675FA0C9C26ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xEB55E751F7587979ULL + 0xBBA52DFBAAC5AE05ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xE8E54ECA6C637BD7ULL + 0xEFD22B057B5D8C7EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xB1CFDCA385F0FDBFULL + 0xD157F5653267EA09ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xBC24307A91458F41ULL + 0x8050FB5BF4F439B5ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x947648A85DFE2D83ULL + 0xDC10760FEBBFDBCCULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xB9D89546BC431851ULL + 0xE2FFCBC7A22B42E3ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 39U) ^ RotL64(aNonceWordH, 60U)) ^ RotL64(aNonceWordF, 21U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 490U)) & S_BLOCK1], 5U) ^ RotL64(aKeyRowReadA[((aIndex + 2779U)) & W_KEY1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 37U) ^ RotL64(aNonceWordG, 3U)) ^ RotL64(aNonceWordD, 46U));
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 1217U)) & W_KEY1], 27U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 701U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCarry, 10U)) ^ (RotL64(aPrevious, 51U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterI = (aWandererF + RotL64(aPrevious, 23U)) + 8975885703279267062U;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 41U)) + 8664844915562660637U) + aPhaseAOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aIngress, 4U)) + 12281774799736296726U) + aPhaseAOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 13U)) + RotL64(aCarry, 35U)) + 15347461352311329726U;
            aOrbiterD = ((aWandererH + RotL64(aCross, 35U)) + 12967500561828907834U) + RotL64(aNonceWordE, 27U);
            aOrbiterC = (((aWandererI + RotL64(aPrevious, 53U)) + RotL64(aCarry, 53U)) + 5002833859280402726U) + RotL64(aNonceWordG, 61U);
            aOrbiterG = ((aWandererK + RotL64(aIngress, 47U)) + RotL64(aCarry, 21U)) + 11908257536954668983U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 17017174811949227162U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 16851323125613931180U) ^ RotL64(aNonceWordA, 35U);
            aOrbiterB = RotL64((aOrbiterB * 12446990992858763577U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 13469326957728686706U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 5228638551056105241U;
            aOrbiterD = RotL64((aOrbiterD * 13369947664646167255U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 11945166198089308564U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 16268645041872996022U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5391448793718370911U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 14781204627695095701U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 5365325354838101092U;
            aOrbiterG = RotL64((aOrbiterG * 8017284997946310807U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 563147416025715953U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 14660867395395625851U;
            aOrbiterI = RotL64((aOrbiterI * 4769458126865307103U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 3168989056355712105U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 16179131669773665579U;
            aOrbiterJ = RotL64((aOrbiterJ * 5641461617066671723U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 4160220074225527179U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 8597134686962559111U) ^ RotL64(aNonceWordC, 8U);
            aOrbiterK = RotL64((aOrbiterK * 639572585431474015U), 53U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterC, 35U);
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterK, 35U)) + RotL64(aNonceWordB, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterG, 11U));
            aWandererK = aWandererK + ((((RotL64(aCross, 47U) + RotL64(aOrbiterD, 21U)) + aOrbiterK) + RotL64(aCarry, 19U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 20U) + RotL64(aOrbiterC, 41U)) + aOrbiterB) + RotL64(aNonceWordH, 3U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 51U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 29U) + aOrbiterB) + RotL64(aOrbiterJ, 4U));
            aWandererH = aWandererH + ((RotL64(aCross, 41U) + RotL64(aOrbiterJ, 53U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 60U));
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 12U) ^ RotL64(aNonceWordD, 27U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 7238U)) & S_BLOCK1], 51U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 9944U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 27U) ^ RotL64(aNonceWordC, 35U));
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 5577U)) & W_KEY1], 43U) ^ RotL64(aKeyRowReadB[((aIndex + 10431U)) & W_KEY1], 12U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 20U) ^ RotL64(aCarry, 47U)) + (RotL64(aIngress, 35U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterF = (aWandererH + RotL64(aScatter, 47U)) + 13714409587461539863U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 23U)) + RotL64(aCarry, 13U)) + 14101156723903265839U;
            aOrbiterI = (((aWandererJ + RotL64(aCross, 58U)) + RotL64(aCarry, 27U)) + 7063754562895369001U) + RotL64(aNonceWordB, 57U);
            aOrbiterC = (((aWandererF + RotL64(aIngress, 29U)) + RotL64(aCarry, 57U)) + 12320578575245519386U) + RotL64(aNonceWordH, 43U);
            aOrbiterH = (aWandererI + RotL64(aScatter, 35U)) + 11744826789631008424U;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 13U)) + 8744816505096675597U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 3U)) + 10405435520084528645U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 1463157688070683543U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 12379603577919617703U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14858901470015109311U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 1343439118031348146U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 16118850268070235540U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11184386483735388257U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 14116264435819277136U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 5251698273012432109U;
            aOrbiterC = RotL64((aOrbiterC * 1495818611622063967U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 14806408656041403829U) + RotL64(aNonceWordE, 16U);
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 11569345414052398227U;
            aOrbiterA = RotL64((aOrbiterA * 9913158908301414861U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 17063874769147888574U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 9927420478679581917U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9042782809534196563U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 2550285599827162167U) + RotL64(aNonceWordC, 29U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 17801534123304996448U;
            aOrbiterJ = RotL64((aOrbiterJ * 2160836889363614721U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 6456685241021762041U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 17064208177372969289U;
            aOrbiterD = RotL64((aOrbiterD * 13726627607233302493U), 23U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterI, 19U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + RotL64(aOrbiterD, 54U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aIngress, 41U) + aOrbiterC) + RotL64(aOrbiterA, 47U)) + RotL64(aCarry, 57U)) + RotL64(aNonceWordA, 25U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterI, 41U)) + aOrbiterJ) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 57U) + RotL64(aOrbiterH, 13U)) + aOrbiterA) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 21U) + aOrbiterJ) + RotL64(aOrbiterF, 35U));
            aWandererG = aWandererG + ((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterJ, 27U));
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 4U)) + aOrbiterA) + RotL64(aNonceWordG, 61U)) + aPhaseAWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 4U) + RotL64(aOrbiterC, 19U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 34U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 23U) ^ RotL64(aNonceWordH, 13U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12947U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13239U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 27U) ^ RotL64(aNonceWordF, 14U)) ^ RotL64(aNonceWordB, 53U));
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15839U)) & W_KEY1], 3U) ^ RotL64(aKeyRowReadB[((aIndex + 14978U)) & W_KEY1], 41U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 4U) + RotL64(aCarry, 41U)) ^ (RotL64(aCross, 19U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterD = (aWandererA + RotL64(aScatter, 43U)) + 4068921616130916949U;
            aOrbiterE = (aWandererG + RotL64(aIngress, 51U)) + 12077715273915151726U;
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 60U)) + 16047546802670596833U;
            aOrbiterK = ((aWandererI + RotL64(aCross, 3U)) + 9690277462716999763U) + RotL64(aNonceWordB, 13U);
            aOrbiterB = (((aWandererK + RotL64(aPrevious, 11U)) + RotL64(aCarry, 39U)) + 14484814700447992628U) + RotL64(aNonceWordD, 19U);
            aOrbiterH = (((aWandererB + RotL64(aCross, 19U)) + RotL64(aCarry, 13U)) + 17089267243053958210U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = (((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 53U)) + 9138746214446211147U) + aPhaseAOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 10181001536979097045U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 6657458969093373191U;
            aOrbiterJ = RotL64((aOrbiterJ * 4311019792293202747U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 7515983477876590988U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterK) ^ 3039935555863947600U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]) ^ RotL64(aNonceWordG, 45U);
            aOrbiterE = RotL64((aOrbiterE * 12511160550780270119U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 16209389224740851136U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 725253312098083182U;
            aOrbiterD = RotL64((aOrbiterD * 17535989492095522597U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 13307041115748941383U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 7159572004825238263U;
            aOrbiterK = RotL64((aOrbiterK * 4855009895002398449U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 12027236743251643820U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 8717826175991286553U;
            aOrbiterB = RotL64((aOrbiterB * 1175614802543098451U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 4769096034227659937U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 11201226563992939616U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15595355978388159931U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 17295978531215563256U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 11850923890626719833U) ^ RotL64(aNonceWordE, 8U);
            aOrbiterF = RotL64((aOrbiterF * 3854851059897397075U), 13U);
            //
            aIngress = RotL64(aOrbiterF, 21U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterJ, 53U)) + aOrbiterH);
            aWandererG = aWandererG + (((((RotL64(aPrevious, 4U) + aOrbiterF) + RotL64(aOrbiterE, 60U)) + RotL64(aCarry, 3U)) + RotL64(aNonceWordA, 39U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterD, 39U)) + RotL64(aNonceWordC, 59U));
            aWandererB = aWandererB + ((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 11U)) + aOrbiterK);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterK, 47U));
            aWandererE = aWandererE + (((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 29U)) + aOrbiterK) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterB, 23U)) + aOrbiterK) + aPhaseAWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 20U));
            aCarry = aCarry + RotL64(aWandererA, 39U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 56U) ^ RotL64(aNonceWordB, 43U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 17074U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((aIndex + 17494U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 51U) ^ RotL64(aNonceWordD, 28U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20814U)) & S_BLOCK1], 37U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 20079U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 29U) + RotL64(aCross, 41U)) ^ (RotL64(aPrevious, 6U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterK = ((aWandererK + RotL64(aScatter, 51U)) + 785861751704720606U) + RotL64(aNonceWordB, 21U);
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 5U)) + 15968088718435606299U) + aPhaseAOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = (aWandererA + RotL64(aCross, 23U)) + 1393976526590347151U;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 29U)) + RotL64(aCarry, 57U)) + 17240750947292745884U;
            aOrbiterH = (((aWandererF + RotL64(aScatter, 57U)) + RotL64(aCarry, 21U)) + 4921576136163183137U) + RotL64(aNonceWordC, 25U);
            aOrbiterG = (((aWandererE + RotL64(aCross, 43U)) + RotL64(aCarry, 35U)) + 3334047873553153032U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = (aWandererB + RotL64(aIngress, 36U)) + 15086509978458408698U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 892391205397581998U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 2965686403183767521U;
            aOrbiterB = RotL64((aOrbiterB * 709160942482770225U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 14632215393655706170U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 15740589515342377322U) ^ RotL64(aNonceWordE, 39U);
            aOrbiterG = RotL64((aOrbiterG * 15677716942904794913U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 11131164813943086445U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 6988080581278900960U;
            aOrbiterA = RotL64((aOrbiterA * 6412189142344044255U), 35U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterE) + 16021254613117657178U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) + RotL64(aNonceWordH, 43U);
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 6183615599897921154U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9976411093264211033U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 12533992547026652747U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 3104325358982904219U;
            aOrbiterK = RotL64((aOrbiterK * 14977348108778147265U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 3878525937957474644U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 2120435259884368445U;
            aOrbiterE = RotL64((aOrbiterE * 15964718652193073177U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 14928658302694194856U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 9121310461310309348U;
            aOrbiterI = RotL64((aOrbiterI * 17304439784647477491U), 57U);
            //
            aIngress = RotL64(aOrbiterH, 41U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterG, 28U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterK, 35U)) + aOrbiterA);
            aWandererF = aWandererF + (((((RotL64(aScatter, 5U) + RotL64(aOrbiterA, 23U)) + aOrbiterB) + RotL64(aCarry, 5U)) + RotL64(aNonceWordG, 9U)) + aPhaseAWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 35U) + aOrbiterB) + RotL64(aOrbiterH, 60U)) + RotL64(aNonceWordA, 8U));
            aWandererA = aWandererA + (((RotL64(aCross, 11U) + RotL64(aOrbiterA, 13U)) + aOrbiterE) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterI, 41U)) + aOrbiterA);
            aWandererD = aWandererD + ((RotL64(aPrevious, 60U) + aOrbiterH) + RotL64(aOrbiterI, 51U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterG, 29U)) + aOrbiterE) + aPhaseAWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 10U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 43U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 57U) ^ RotL64(aNonceWordH, 29U)) ^ RotL64(aNonceWordF, 6U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 26636U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24423U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 27U) ^ RotL64(aNonceWordG, 57U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26525U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneA[((aIndex + 26247U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 50U) + RotL64(aCross, 21U)) + (RotL64(aIngress, 3U) ^ RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterC = (aWandererB + RotL64(aPrevious, 5U)) + 10726035965553989335U;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 50U)) + 967354339530195662U) + RotL64(aNonceWordC, 15U);
            aOrbiterI = ((((aWandererA + RotL64(aCross, 39U)) + RotL64(aCarry, 39U)) + 10834593005478605624U) + aPhaseAOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1]) + RotL64(aNonceWordD, 23U);
            aOrbiterA = (aWandererK + RotL64(aIngress, 13U)) + 1012888282838656933U;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 29U)) + RotL64(aCarry, 3U)) + 15283530351725183253U;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 57U)) + RotL64(aCarry, 53U)) + 11724495956731703750U;
            aOrbiterD = ((aWandererI + RotL64(aCross, 21U)) + 4288330117317505776U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 10894778070022873473U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 15563886747621617467U;
            aOrbiterI = RotL64((aOrbiterI * 17884709931569040065U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 11182488628562891937U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 10420140066310588580U) ^ RotL64(aNonceWordB, 59U);
            aOrbiterC = RotL64((aOrbiterC * 13898299782819948719U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 11775138062167543111U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 16545391898578161683U;
            aOrbiterA = RotL64((aOrbiterA * 14588306527161321535U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 1550144656312299266U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 14903504853138279883U;
            aOrbiterH = RotL64((aOrbiterH * 8003033561266164387U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 309935535526750396U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 13991265868040011411U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2887531132228588441U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 1755976294857114222U) + RotL64(aNonceWordA, 25U);
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 2259275858478396846U;
            aOrbiterB = RotL64((aOrbiterB * 7416165760067878161U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 4838175912944552936U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 12307900457200936013U;
            aOrbiterD = RotL64((aOrbiterD * 14719363144850838805U), 29U);
            //
            aIngress = RotL64(aOrbiterI, 11U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 13U)) + aOrbiterC);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 51U) + aOrbiterB) + RotL64(aOrbiterI, 41U)) + RotL64(aNonceWordH, 53U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterD, 47U)) + aPhaseAWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterA, 19U)) + aOrbiterI) + RotL64(aNonceWordE, 36U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 44U) + aOrbiterB) + RotL64(aOrbiterK, 4U)) + RotL64(aCarry, 13U)) + aPhaseAWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterB, 35U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 37U) + aOrbiterD) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 44U));
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 5U) ^ RotL64(aNonceWordD, 27U)) ^ RotL64(aNonceWordH, 57U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30635U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32751U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 23U) ^ RotL64(aNonceWordF, 43U)) ^ RotL64(aNonceWordE, 5U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30259U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28146U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCross, 38U)) + (RotL64(aIngress, 3U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterI = (aWandererA + RotL64(aScatter, 57U)) + 6163290588946759209U;
            aOrbiterD = ((aWandererK + RotL64(aCross, 37U)) + 7342672468560105447U) + RotL64(aNonceWordH, 15U);
            aOrbiterH = ((aWandererD + RotL64(aIngress, 11U)) + RotL64(aCarry, 41U)) + 11574563167017282321U;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 20U)) + 2254820206194758964U;
            aOrbiterF = (((aWandererC + RotL64(aIngress, 29U)) + 1469783447473099498U) + aPhaseAOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1]) + RotL64(aNonceWordF, 19U);
            aOrbiterC = (((aWandererI + RotL64(aCross, 5U)) + RotL64(aCarry, 11U)) + 14174828900676165088U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 43U)) + RotL64(aCarry, 53U)) + 16277954291890598132U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 14845750668693136766U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 150099699692047766U) ^ RotL64(aNonceWordG, 25U);
            aOrbiterH = RotL64((aOrbiterH * 7644895634421086357U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 1200784917165131703U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 9469982764806754302U;
            aOrbiterF = RotL64((aOrbiterF * 17851969334511301943U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 10956702761701710182U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = (((aOrbiterC ^ aOrbiterD) ^ 7915506894975487807U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1]) ^ RotL64(aNonceWordD, 43U);
            aOrbiterC = RotL64((aOrbiterC * 8874108311712727983U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 17335794183733623213U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 557028996286989506U;
            aOrbiterK = RotL64((aOrbiterK * 3993359298602424281U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 1597385667771002414U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 4376417959915162639U;
            aOrbiterI = RotL64((aOrbiterI * 4626236858205178149U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 549770198518993876U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 756554555648070919U;
            aOrbiterE = RotL64((aOrbiterE * 16272320259614325355U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 7298557532533152193U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 3336802611342112013U;
            aOrbiterD = RotL64((aOrbiterD * 14679103452120080499U), 19U);
            //
            aIngress = RotL64(aOrbiterF, 41U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + RotL64(aOrbiterC, 12U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterK, 5U)) + aOrbiterH);
            aWandererI = aWandererI + ((((RotL64(aCross, 37U) + RotL64(aOrbiterK, 13U)) + aOrbiterE) + RotL64(aCarry, 23U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterK, 51U));
            aWandererD = aWandererD + (((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterI, 39U)) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 21U) + aOrbiterH) + RotL64(aOrbiterE, 57U)) + aPhaseAWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterF, 22U)) + RotL64(aNonceWordA, 24U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterI, 29U)) + aOrbiterD) + RotL64(aNonceWordC, 17U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 36U));
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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

void TwistExpander_Fencing_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xC98D993AE4C54411ULL + 0xBB33BDDDFA35B4AAULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xACFB3CE7682C701BULL + 0xCFE1C504C8546383ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xED075B294E8FA229ULL + 0x8E94EE68DFD40DE7ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x94C9EA2F1B0D01F7ULL + 0x99C740242385C4E6ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x9F770B98797F7A55ULL + 0xA774BE86C306202EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x89848D2FE5371BEDULL + 0x9F82B1CA74E20851ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xF3AFE0D37FB4974DULL + 0xE563C1A560F4AFC3ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x8A888B8D3E6266E9ULL + 0x95CCF47A649F814CULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 20U) ^ RotL64(aNonceWordG, 51U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4840U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((aIndex + 1131U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 50U) ^ RotL64(aNonceWordH, 19U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4724U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 3380U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 43U) + RotL64(aIngress, 11U)) + (RotL64(aCross, 23U) ^ RotL64(aPrevious, 60U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 19U)) + RotL64(aCarry, 23U)) + 1708250618750199233U;
            aOrbiterG = ((aWandererD + RotL64(aCross, 53U)) + 12009147777553691142U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aScatter, 5U)) + RotL64(aCarry, 35U)) + 8393982703399156592U;
            aOrbiterE = ((((aWandererE + RotL64(aIngress, 27U)) + RotL64(aCarry, 53U)) + 3247327098356831221U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1]) + RotL64(aNonceWordG, 27U);
            aOrbiterC = ((aWandererB + RotL64(aCross, 42U)) + 3403590155376353737U) + RotL64(aNonceWordD, 56U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 18197244558104735044U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 3096253642040701606U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6656168712438620783U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 8012692688785412179U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterE) ^ 17531946907545680745U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]) ^ RotL64(aNonceWordB, 37U);
            aOrbiterJ = RotL64((aOrbiterJ * 16510602981731506381U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 17687695944270225817U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 16147773866007628769U;
            aOrbiterE = RotL64((aOrbiterE * 16926442582711557877U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 18244641303026196497U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterC) ^ 8839160526348897457U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1]) ^ RotL64(aNonceWordC, 57U);
            aOrbiterG = RotL64((aOrbiterG * 14268021129087663397U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 10599266240854068246U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 2056723540756216155U;
            aOrbiterC = RotL64((aOrbiterC * 13311591601230386375U), 47U);
            //
            aIngress = RotL64(aOrbiterC, 37U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + RotL64(aOrbiterB, 54U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 12U) + RotL64(aOrbiterG, 19U)) + aOrbiterE);
            aWandererH = aWandererH + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 11U)) + aOrbiterB) + RotL64(aCarry, 51U)) + RotL64(aNonceWordE, 13U));
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 37U) + aOrbiterJ) + RotL64(aOrbiterC, 60U)) + RotL64(aNonceWordH, 51U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aCross, 53U) + aOrbiterJ) + RotL64(aOrbiterE, 41U)) + RotL64(aCarry, 5U)) + aPhaseBWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 21U) + aOrbiterC) + RotL64(aOrbiterG, 51U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 43U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 57U) ^ RotL64(aNonceWordA, 39U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 6034U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10818U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 57U) ^ RotL64(aNonceWordF, 21U)) ^ RotL64(aNonceWordE, 39U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8797U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9588U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 27U) + RotL64(aCross, 39U)) ^ (RotL64(aCarry, 51U) + RotL64(aPrevious, 4U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 13U)) + 6654158889644956636U) + RotL64(aNonceWordD, 55U);
            aOrbiterK = (aWandererB + RotL64(aIngress, 37U)) + 9045779659363991870U;
            aOrbiterF = ((((aWandererC + RotL64(aScatter, 23U)) + RotL64(aCarry, 39U)) + 3888897662136993491U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1]) + RotL64(aNonceWordH, 39U);
            aOrbiterJ = (((aWandererH + RotL64(aCross, 46U)) + RotL64(aCarry, 57U)) + 6882016842864459345U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 57U)) + RotL64(aCarry, 23U)) + 15601891715956172291U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 5176811598629335350U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 12519945150889074325U;
            aOrbiterF = RotL64((aOrbiterF * 8721098129033306427U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 4552583214397603278U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 14225482701804864688U;
            aOrbiterB = RotL64((aOrbiterB * 8526052833180466359U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 5485298070606280363U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 11237713257388094289U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11032429223099413011U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 14340345895626142788U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterF) ^ 16275167270553643347U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1]) ^ RotL64(aNonceWordC, 9U);
            aOrbiterK = RotL64((aOrbiterK * 7308578867128951199U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 14041860597556520250U) + RotL64(aNonceWordF, 23U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 1436068974197066343U;
            aOrbiterJ = RotL64((aOrbiterJ * 3938460345031496843U), 43U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 5U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + RotL64(aOrbiterF, 36U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterK, 23U)) + RotL64(aNonceWordB, 46U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 28U) + RotL64(aOrbiterJ, 13U)) + aOrbiterC) + aPhaseBWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 57U)) + aOrbiterJ) + RotL64(aCarry, 29U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 11U) + aOrbiterF) + RotL64(aOrbiterB, 5U));
            aWandererG = aWandererG + (((((RotL64(aScatter, 43U) + RotL64(aOrbiterF, 34U)) + aOrbiterK) + RotL64(aCarry, 47U)) + RotL64(aNonceWordE, 27U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 48U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererC, 37U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 54U) ^ RotL64(aNonceWordG, 13U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15541U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13967U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 3U) ^ RotL64(aNonceWordF, 27U)) ^ RotL64(aNonceWordH, 47U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12979U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15362U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 52U)) ^ (RotL64(aIngress, 27U) + RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterD = (((aWandererA + RotL64(aScatter, 10U)) + 17936518874386450467U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1]) + RotL64(aNonceWordG, 55U);
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 51U)) + 13722737841589910344U;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 37U)) + RotL64(aCarry, 41U)) + 11774969167948715796U;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 29U)) + RotL64(aCarry, 13U)) + 3640101505680493777U;
            aOrbiterB = ((((aWandererG + RotL64(aPrevious, 19U)) + RotL64(aCarry, 27U)) + 1369495382725650822U) + aPhaseBOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1]) + RotL64(aNonceWordC, 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 11827310354654653345U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 186037671377175394U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 829791264853993897U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 11428829344234627340U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 2275016369870029068U) ^ RotL64(aNonceWordD, 7U);
            aOrbiterG = RotL64((aOrbiterG * 14936799202145280833U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 15471646673734798328U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 12172082573115640145U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9629417882787847753U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 6626736341348283154U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 12220614992483863623U) ^ RotL64(aNonceWordA, 50U);
            aOrbiterC = RotL64((aOrbiterC * 8137086205714097487U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 13157102324253760215U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 4143587482368093601U;
            aOrbiterB = RotL64((aOrbiterB * 5060677690991506895U), 3U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterB, 51U);
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 40U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 46U)) + aOrbiterJ) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterC, 57U)) + aOrbiterJ);
            aWandererA = aWandererA + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 27U)) + aOrbiterD) + aPhaseBWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 30U) + RotL64(aOrbiterC, 19U)) + aOrbiterB) + RotL64(aNonceWordF, 19U));
            aWandererJ = aWandererJ + (((((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 35U)) + aOrbiterG) + RotL64(aCarry, 3U)) + RotL64(aNonceWordE, 49U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 30U));
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 53U) ^ RotL64(aNonceWordG, 19U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 21075U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18844U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 14U) ^ RotL64(aNonceWordF, 47U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20071U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21822U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCross, 5U)) + (RotL64(aCarry, 19U) ^ RotL64(aPrevious, 56U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterE = ((((aWandererH + RotL64(aPrevious, 5U)) + RotL64(aCarry, 19U)) + 966899917801652720U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1]) + RotL64(aNonceWordA, 37U);
            aOrbiterD = (aWandererB + RotL64(aCross, 29U)) + 10996327672320748649U;
            aOrbiterF = (((aWandererE + RotL64(aIngress, 53U)) + RotL64(aCarry, 3U)) + 4188171566846621107U) + aPhaseBOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aScatter, 37U)) + 5886209243097387959U) + RotL64(aNonceWordH, 23U);
            aOrbiterG = ((aWandererG + RotL64(aCross, 20U)) + RotL64(aCarry, 35U)) + 14940428957136728111U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 179187285531914832U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 6685351948936817752U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15533370414711696803U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 1894506461704029700U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 4182760368636977082U) ^ RotL64(aNonceWordF, 29U);
            aOrbiterE = RotL64((aOrbiterE * 972988091869133921U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 12523318028514940790U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 5059306166973366892U;
            aOrbiterC = RotL64((aOrbiterC * 2857409765717296483U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 5890872367917643851U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 17747338389865221534U) ^ RotL64(aNonceWordC, 27U);
            aOrbiterD = RotL64((aOrbiterD * 5306740664798049267U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 13906227834259884100U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 7152105382899756368U;
            aOrbiterG = RotL64((aOrbiterG * 6772157117358310485U), 5U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 50U);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 39U) + RotL64(aOrbiterE, 21U)) + aOrbiterC) + RotL64(aCarry, 37U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterD, 42U)) + aPhaseBWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 23U) + aOrbiterD) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 3U)) + RotL64(aNonceWordB, 54U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterG, 5U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 52U) + aOrbiterC) + RotL64(aOrbiterG, 13U)) + RotL64(aNonceWordE, 25U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 58U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 53U) ^ RotL64(aNonceWordD, 41U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 24830U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneA[((aIndex + 21869U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 37U) ^ RotL64(aNonceWordF, 19U)) ^ RotL64(aNonceWordE, 3U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26995U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23851U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 56U) + RotL64(aCross, 27U)) + (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterI = (((aWandererH + RotL64(aPrevious, 35U)) + RotL64(aCarry, 5U)) + 7948891781097675369U) + RotL64(aNonceWordG, 26U);
            aOrbiterG = (aWandererE + RotL64(aCross, 6U)) + 13928362874228230226U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 27U)) + RotL64(aCarry, 21U)) + 10776180542602258926U;
            aOrbiterJ = (((aWandererB + RotL64(aIngress, 57U)) + RotL64(aCarry, 57U)) + 5735115172149470447U) + aPhaseBOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = (((aWandererI + RotL64(aPrevious, 19U)) + 5353591822981766987U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1]) + RotL64(aNonceWordB, 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 562301708107268570U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 10467810247578364868U;
            aOrbiterB = RotL64((aOrbiterB * 10449089554007059823U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 14541630141152308564U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 2350076897065139429U;
            aOrbiterD = RotL64((aOrbiterD * 12222554362482034393U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 17519109078651162228U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 6061035173339902910U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10021905773432907835U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 15654836633731000065U) + RotL64(aNonceWordC, 51U);
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 13723521735153718904U;
            aOrbiterG = RotL64((aOrbiterG * 14459516479283070563U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 2849680038315532197U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 17336102435576647923U) ^ RotL64(aNonceWordE, 53U);
            aOrbiterJ = RotL64((aOrbiterJ * 10984689101753586739U), 39U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 29U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + RotL64(aOrbiterJ, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 3U)) + aOrbiterB) + RotL64(aNonceWordA, 37U));
            aWandererB = aWandererB + ((((RotL64(aCross, 58U) + aOrbiterJ) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 11U)) + aPhaseBWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterJ, 11U));
            aWandererI = aWandererI + ((((RotL64(aCross, 13U) + RotL64(aOrbiterG, 56U)) + aOrbiterD) + RotL64(aNonceWordH, 47U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 26U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + RotL64(aWandererH, 13U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 22U) ^ RotL64(aNonceWordD, 3U)) ^ RotL64(aNonceWordA, 35U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 30921U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((aIndex + 28531U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 57U) ^ RotL64(aNonceWordF, 11U)) ^ RotL64(aNonceWordC, 3U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 32014U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((aIndex + 32400U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 40U)) ^ (RotL64(aIngress, 27U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterF = (aWandererF + RotL64(aScatter, 20U)) + 7960325128608297381U;
            aOrbiterD = ((((aWandererE + RotL64(aCross, 43U)) + RotL64(aCarry, 5U)) + 12773836012104052042U) + aPhaseBOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1]) + RotL64(aNonceWordH, 34U);
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 11U)) + 3173972621347773016U) + aPhaseBOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = (((aWandererB + RotL64(aIngress, 29U)) + RotL64(aCarry, 23U)) + 3708401356314308171U) + RotL64(aNonceWordA, 59U);
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 53U)) + RotL64(aCarry, 57U)) + 950774285720019449U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 4170092315705438265U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 17000449130864980747U;
            aOrbiterK = RotL64((aOrbiterK * 7710635557693533263U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 8793910540062893860U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 520277969543516469U;
            aOrbiterD = RotL64((aOrbiterD * 4150613128885828229U), 29U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterA) + 12762214857389827271U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]) + RotL64(aNonceWordB, 45U);
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 2932451184340207695U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7513337346940091655U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 11062179998786293839U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = (((aOrbiterA ^ aOrbiterK) ^ 7919119215271524178U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) ^ RotL64(aNonceWordC, 21U);
            aOrbiterA = RotL64((aOrbiterA * 9053677007180081359U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 1774988449597115155U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 3799792889466518953U;
            aOrbiterI = RotL64((aOrbiterI * 17512791286490623455U), 57U);
            //
            aIngress = RotL64(aOrbiterK, 40U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterI, 52U)) + aOrbiterF);
            aWandererC = aWandererC + (((((RotL64(aPrevious, 5U) + RotL64(aOrbiterD, 29U)) + aOrbiterI) + RotL64(aCarry, 39U)) + RotL64(aNonceWordF, 39U)) + aPhaseBWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 53U) + aOrbiterD) + RotL64(aOrbiterF, 5U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 13U) + aOrbiterK) + RotL64(aOrbiterA, 41U)) + RotL64(aCarry, 23U)) + aPhaseBWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 28U) + RotL64(aOrbiterD, 13U)) + aOrbiterA) + RotL64(aNonceWordG, 51U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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

void TwistExpander_Fencing_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xC511274A120AAC83ULL + 0x9885FAACD48C872CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xEBC9E85C01F57393ULL + 0xD2D4C62718EB0069ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xE4DC78817F8D03A3ULL + 0xF19F6B97C3C3EA84ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xBF7BA9FE9A209EADULL + 0xA18CB5C696867536ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xDCEEDA2162169C11ULL + 0xB9BC78DBCB2D5945ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x811F6C7BA7F4F355ULL + 0xF096E5DDD924B33BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xE67DCF985D89DFAFULL + 0x933782E0553468E5ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xAD5136810B8A7329ULL + 0x8A30D7CA24DE7949ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 53U) ^ RotL64(aNonceWordH, 10U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 3309U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 6490U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 35U) ^ RotL64(aNonceWordD, 13U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6114U)) & S_BLOCK1], 24U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 1723U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 37U) ^ RotL64(aCross, 51U)) + (RotL64(aPrevious, 22U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterB = ((aWandererK + RotL64(aIngress, 12U)) + RotL64(aCarry, 13U)) + 13714409587461539863U;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 3U)) + 14101156723903265839U;
            aOrbiterE = (((aWandererJ + RotL64(aCross, 41U)) + RotL64(aCarry, 3U)) + 7063754562895369001U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aScatter, 21U)) + 12320578575245519386U) + RotL64(aNonceWordB, 26U);
            aOrbiterC = (aWandererB + RotL64(aCross, 37U)) + 11744826789631008424U;
            aOrbiterA = (((aWandererF + RotL64(aScatter, 47U)) + RotL64(aCarry, 47U)) + 8744816505096675597U) + RotL64(aNonceWordE, 5U);
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 29U)) + 10405435520084528645U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aIngress, 58U)) + 1463157688070683543U;
            aOrbiterG = (aWandererA + RotL64(aScatter, 53U)) + 12379603577919617703U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 1343439118031348146U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 16118850268070235540U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11184386483735388257U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 14116264435819277136U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 5251698273012432109U;
            aOrbiterA = RotL64((aOrbiterA * 1495818611622063967U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 14806408656041403829U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 11569345414052398227U;
            aOrbiterK = RotL64((aOrbiterK * 9913158908301414861U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 17063874769147888574U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 9927420478679581917U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9042782809534196563U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 2550285599827162167U) + RotL64(aNonceWordF, 51U);
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 17801534123304996448U;
            aOrbiterB = RotL64((aOrbiterB * 2160836889363614721U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 6456685241021762041U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 17064208177372969289U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13726627607233302493U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 18279938244131982650U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 8211002229712129419U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12931373380977640645U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 12795832560781931767U) + RotL64(aNonceWordH, 37U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 286378504074349650U;
            aOrbiterJ = RotL64((aOrbiterJ * 85453101173293509U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 5835304250436889513U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 12704972686724379659U;
            aOrbiterC = RotL64((aOrbiterC * 1198789639656336053U), 47U);
            //
            aIngress = RotL64(aOrbiterF, 57U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 46U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + RotL64(aOrbiterJ, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aScatter, 6U) + RotL64(aOrbiterJ, 39U)) + aOrbiterB) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterE, 24U)) + aOrbiterB);
            aWandererC = aWandererC + (((RotL64(aIngress, 37U) + RotL64(aOrbiterF, 3U)) + aOrbiterB) + RotL64(aNonceWordC, 27U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 53U) + aOrbiterJ) + RotL64(aOrbiterK, 47U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterB, 53U)) + aOrbiterA) + RotL64(aNonceWordA, 9U)) + aPhaseCWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 35U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aCross, 10U) + RotL64(aOrbiterE, 60U)) + aOrbiterF) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 11U)) + aOrbiterG);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 41U) + aOrbiterH) + RotL64(aOrbiterE, 19U)) + aPhaseCWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 14U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 14U) ^ RotL64(aNonceWordE, 23U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 15854U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 9638U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 39U) ^ RotL64(aNonceWordD, 12U)) ^ RotL64(aNonceWordH, 47U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12721U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((aIndex + 9087U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 37U) ^ RotL64(aCross, 24U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterB = ((aWandererB + RotL64(aCross, 53U)) + RotL64(aCarry, 3U)) + 5160910997561396461U;
            aOrbiterA = (aWandererG + RotL64(aIngress, 41U)) + 14920764751058512062U;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 5U)) + 6080952401749660022U) + RotL64(aNonceWordE, 15U);
            aOrbiterG = ((aWandererC + RotL64(aScatter, 11U)) + 17667234330526298627U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (aWandererK + RotL64(aCross, 58U)) + 760630072638686756U;
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 23U)) + RotL64(aCarry, 47U)) + 3504157162816997476U;
            aOrbiterD = (((aWandererA + RotL64(aIngress, 27U)) + RotL64(aCarry, 37U)) + 9489022223422585882U) + RotL64(aNonceWordH, 21U);
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 47U)) + 1149898536879968964U) + aPhaseCOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aCross, 34U)) + 10492284328940025310U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 13213275606286399312U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 10557118912847180413U;
            aOrbiterC = RotL64((aOrbiterC * 10077877991284587845U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 15618980209023994776U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 5268600749854045564U;
            aOrbiterE = RotL64((aOrbiterE * 3849660559223919613U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 8011552687609649990U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 3148133096349525066U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5245156554959620007U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 12032847944237867285U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 14999005703490824673U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6631584955208646049U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 5426735969392906710U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 3593177531650386729U) ^ RotL64(aNonceWordF, 45U);
            aOrbiterF = RotL64((aOrbiterF * 12997284886192717043U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 1701444719333347373U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 15928731228196894960U;
            aOrbiterB = RotL64((aOrbiterB * 1919318226904213433U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 5960179456039157036U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 5716434224061596483U;
            aOrbiterG = RotL64((aOrbiterG * 3731976564761202801U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 2136841536293340279U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 12969550408652728526U) ^ RotL64(aNonceWordC, 13U);
            aOrbiterJ = RotL64((aOrbiterJ * 7612191387451455137U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 3641997570461447114U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 4677572491523684525U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2730358077882211651U), 57U);
            //
            aIngress = RotL64(aOrbiterE, 43U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 54U));
            aIngress = aIngress + RotL64(aOrbiterG, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterG, 41U)) + aOrbiterE);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 60U) + aOrbiterB) + RotL64(aOrbiterA, 60U)) + RotL64(aCarry, 23U)) + RotL64(aNonceWordB, 22U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterC, 47U)) + aOrbiterH);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 47U) + aOrbiterE) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 37U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterJ, 29U));
            aWandererE = aWandererE + (((RotL64(aCross, 21U) + RotL64(aOrbiterF, 19U)) + aOrbiterA) + RotL64(aNonceWordG, 61U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 56U) + aOrbiterH) + RotL64(aOrbiterA, 4U)) + aPhaseCWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterH, 13U)) + aOrbiterD) + aPhaseCWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterG, 53U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 18U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererA, 23U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 37U) ^ RotL64(aNonceWordC, 29U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 18843U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((aIndex + 23672U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 23U) ^ RotL64(aNonceWordF, 5U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 18954U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((aIndex + 21298U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCross, 10U)) ^ (RotL64(aCarry, 27U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterD = (aWandererH + RotL64(aIngress, 37U)) + 8506388683755208267U;
            aOrbiterJ = (aWandererJ + RotL64(aCross, 51U)) + 2179323259055019735U;
            aOrbiterB = (aWandererB + RotL64(aScatter, 22U)) + 3345902531140983016U;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 29U)) + 17456139311481306584U;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 11U)) + 14587864088462311164U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = ((((aWandererF + RotL64(aIngress, 47U)) + RotL64(aCarry, 43U)) + 13178947246650647057U) + aPhaseCOrbiterAssignSaltB[((aIndex + 8U)) & S_SALT1]) + RotL64(aNonceWordG, 29U);
            aOrbiterI = ((aWandererG + RotL64(aCross, 57U)) + RotL64(aCarry, 13U)) + 12866578138946916962U;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 42U)) + RotL64(aCarry, 29U)) + 13098524333655118173U;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 3U)) + 15451329483787541982U) + RotL64(aNonceWordB, 38U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 9494299579678389385U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 15581954810375490643U;
            aOrbiterB = RotL64((aOrbiterB * 13670002280188424825U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 4487042505730624892U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 2774455928791636186U;
            aOrbiterD = RotL64((aOrbiterD * 15847933919136777451U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 12435319582397755819U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 10077180055177766823U;
            aOrbiterH = RotL64((aOrbiterH * 3924363471701748703U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 10391963896910956455U) + RotL64(aNonceWordE, 21U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 6149237416725301794U;
            aOrbiterJ = RotL64((aOrbiterJ * 10115917698918612823U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 15673402771629639978U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 14729117178956592426U;
            aOrbiterF = RotL64((aOrbiterF * 9070464269215820531U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 14492001279368870240U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 6278248084483259952U;
            aOrbiterE = RotL64((aOrbiterE * 16731228350971263873U), 37U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterB) + 15727518866499740411U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]) + RotL64(aNonceWordF, 49U);
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 8652631010810965473U;
            aOrbiterI = RotL64((aOrbiterI * 9508484121620912715U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 13660890300188313775U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 14699253534935936300U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3978135617259934869U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 1621689916308271346U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 5651399428852950385U;
            aOrbiterC = RotL64((aOrbiterC * 12220143634120124133U), 19U);
            //
            aIngress = RotL64(aOrbiterE, 44U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 28U) + RotL64(aOrbiterH, 43U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterH, 4U)) + aOrbiterJ) + RotL64(aCarry, 27U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterC, 29U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 51U) + RotL64(aOrbiterK, 47U)) + aOrbiterI);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 11U) + aOrbiterJ) + RotL64(aOrbiterE, 51U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 23U)) + aOrbiterB) + RotL64(aCarry, 43U)) + RotL64(aNonceWordD, 13U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 60U) + aOrbiterB) + RotL64(aOrbiterI, 35U)) + aPhaseCWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 37U) + RotL64(aOrbiterF, 12U)) + aOrbiterD) + RotL64(aNonceWordC, 57U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterH, 39U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 50U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + RotL64(aWandererB, 39U);
            aCarry = aCarry + RotL64(aIngress, 20U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 57U) ^ RotL64(aNonceWordC, 18U)) ^ RotL64(aNonceWordE, 35U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 24971U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26679U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 22U) ^ RotL64(aNonceWordD, 53U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29664U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 29523U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 54U) + RotL64(aCarry, 3U)) ^ (RotL64(aCross, 41U) + RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterF = (aWandererB + RotL64(aScatter, 51U)) + 12046647397183218524U;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 27U)) + 2760779375026461991U) + RotL64(aNonceWordH, 61U);
            aOrbiterH = ((aWandererF + RotL64(aCross, 36U)) + RotL64(aCarry, 3U)) + 13735454443176855650U;
            aOrbiterE = (aWandererE + RotL64(aIngress, 41U)) + 4370377000586647724U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 19U)) + 14566322384189969094U) + RotL64(aNonceWordF, 11U);
            aOrbiterK = ((aWandererG + RotL64(aScatter, 23U)) + 5056565959818422786U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aIngress, 14U)) + RotL64(aCarry, 37U)) + 8795403810686579209U;
            aOrbiterI = (((aWandererC + RotL64(aPrevious, 47U)) + RotL64(aCarry, 29U)) + 9625947666256011567U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aCross, 3U)) + 1703669290934254701U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 6664070663184147951U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 2104148316797553431U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12887842067180975983U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 1197910004222596145U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 9922977170060903197U;
            aOrbiterJ = RotL64((aOrbiterJ * 13047828062605568603U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 2048376210852567829U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 12568990647075931409U;
            aOrbiterD = RotL64((aOrbiterD * 9860242601194210927U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 15026894775772902751U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 3439447160137900629U) ^ RotL64(aNonceWordB, 43U);
            aOrbiterF = RotL64((aOrbiterF * 1813754963043785165U), 19U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterF) + 6532671388552829796U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]) + RotL64(aNonceWordA, 60U);
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 17261098369835997661U;
            aOrbiterE = RotL64((aOrbiterE * 568292591215203521U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 3171300991007459947U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 5935563269327662024U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11271790283157765003U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 14290941734320455612U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 12371794745736518824U;
            aOrbiterI = RotL64((aOrbiterI * 12208762336145168647U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 8782840145467637373U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 4067525421190366741U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6671002797916227485U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 11854812920571789853U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 17564890418553131451U;
            aOrbiterG = RotL64((aOrbiterG * 16657184504366731805U), 57U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 41U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 30U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 58U) + aOrbiterJ) + RotL64(aOrbiterK, 47U)) + RotL64(aNonceWordG, 39U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterA, 19U)) + aOrbiterE) + RotL64(aNonceWordE, 47U));
            aWandererA = aWandererA + ((RotL64(aCross, 19U) + aOrbiterH) + RotL64(aOrbiterI, 13U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 51U)) + aOrbiterF);
            aWandererE = aWandererE + (((RotL64(aScatter, 34U) + aOrbiterE) + RotL64(aOrbiterJ, 56U)) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 35U)) + aOrbiterI);
            aWandererH = aWandererH + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 23U)) + aOrbiterF) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 23U) + aOrbiterD) + RotL64(aOrbiterF, 39U)) + aPhaseCWandererUpdateSaltD[((aIndex + 20U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 39U) + RotL64(aOrbiterG, 4U)) + aOrbiterA) + aPhaseCWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 4U));
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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

void TwistExpander_Fencing_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x8522FED51BECC7EDULL + 0xBF72E89AB51C77C8ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x883C2EBA6E84403DULL + 0xAF2A5A40BFC758A6ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xE8D44A155DE69969ULL + 0xF21463BF2F2B1CABULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xD6B09AF0E4862CEFULL + 0xC7E93565CB05F118ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xEAAEE960689B020DULL + 0x86A56E6380A82CB4ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x8AC5AC1900D45859ULL + 0xBC98D626936E4F32ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xD03DA1ECEF244511ULL + 0xC7CB55D6C595A4B9ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xFE53C6F6BC318CAFULL + 0x8553C7B7D6BFA38BULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 35U) ^ RotL64(aNonceWordD, 23U)) ^ RotL64(aNonceWordA, 44U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5315U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3753U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 51U) ^ RotL64(aNonceWordF, 11U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2241U)) & S_BLOCK1], 42U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 2218U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aPrevious, 6U)) ^ (RotL64(aIngress, 39U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterH = ((aWandererF + RotL64(aScatter, 53U)) + RotL64(aCarry, 35U)) + 6163290588946759209U;
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 29U)) + 7342672468560105447U) + RotL64(aNonceWordC, 47U);
            aOrbiterA = ((aWandererD + RotL64(aCross, 41U)) + 11574563167017282321U) + RotL64(aNonceWordH, 43U);
            aOrbiterD = (aWandererG + RotL64(aIngress, 18U)) + 2254820206194758964U;
            aOrbiterC = (aWandererA + RotL64(aPrevious, 21U)) + 1469783447473099498U;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 27U)) + RotL64(aCarry, 19U)) + 14174828900676165088U;
            aOrbiterI = ((aWandererC + RotL64(aCross, 13U)) + 16277954291890598132U) + aPhaseDOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (aWandererK + RotL64(aScatter, 35U)) + 14845750668693136766U;
            aOrbiterB = (aWandererE + RotL64(aPrevious, 37U)) + 150099699692047766U;
            aOrbiterG = (((aWandererI + RotL64(aCross, 23U)) + RotL64(aCarry, 3U)) + 1200784917165131703U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aScatter, 10U)) + 9469982764806754302U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 10956702761701710182U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 7915506894975487807U;
            aOrbiterA = RotL64((aOrbiterA * 8874108311712727983U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 17335794183733623213U) + RotL64(aNonceWordE, 9U);
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 557028996286989506U;
            aOrbiterK = RotL64((aOrbiterK * 3993359298602424281U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 1597385667771002414U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 4376417959915162639U;
            aOrbiterH = RotL64((aOrbiterH * 4626236858205178149U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 549770198518993876U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 756554555648070919U;
            aOrbiterD = RotL64((aOrbiterD * 16272320259614325355U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 7298557532533152193U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 3336802611342112013U;
            aOrbiterI = RotL64((aOrbiterI * 14679103452120080499U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 2314938232094714365U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 12215066333571149153U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10747052773052630601U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 7762752719356805046U) + RotL64(aNonceWordA, 3U);
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 6519429915769040078U;
            aOrbiterF = RotL64((aOrbiterF * 15548676502167938513U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 7556691736109752918U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 13731245903412646404U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15581965016668635409U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 5910925625723735162U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 16037704866415841869U;
            aOrbiterC = RotL64((aOrbiterC * 11628217027073824759U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 12605882248192797360U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 9579778913978981884U;
            aOrbiterE = RotL64((aOrbiterE * 5372577227818787957U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 6063171520266734946U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 6163290588946759209U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 291843698316138251U), 35U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterC, 27U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 48U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + RotL64(aOrbiterD, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aCross, 37U) + aOrbiterG) + RotL64(aOrbiterI, 41U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 34U) + RotL64(aOrbiterK, 39U)) + aOrbiterD);
            aWandererA = aWandererA + ((RotL64(aPrevious, 53U) + aOrbiterK) + RotL64(aOrbiterH, 36U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 23U) + aOrbiterI) + RotL64(aOrbiterB, 11U));
            aWandererB = aWandererB + (((((RotL64(aScatter, 43U) + RotL64(aOrbiterF, 5U)) + aOrbiterJ) + RotL64(aCarry, 35U)) + RotL64(aNonceWordG, 13U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterF, 21U)) + aOrbiterE) + aPhaseDWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterK, 29U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 39U) + aOrbiterI) + RotL64(aOrbiterD, 54U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterD, 27U)) + RotL64(aNonceWordD, 60U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterC, 23U));
            aWandererI = aWandererI + (((RotL64(aCross, 6U) + aOrbiterC) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 10U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 41U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 51U) ^ RotL64(aNonceWordF, 27U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 9479U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 5916U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 29U) ^ RotL64(aNonceWordE, 11U)) ^ RotL64(aNonceWordB, 47U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10796U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10774U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 6U) ^ RotL64(aCross, 39U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterI = (aWandererK + RotL64(aIngress, 24U)) + 12380376990224645149U;
            aOrbiterG = (((aWandererA + RotL64(aScatter, 41U)) + RotL64(aCarry, 47U)) + 18296928500297384014U) + RotL64(aNonceWordB, 59U);
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 3U)) + 3550626816361145100U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aCross, 5U)) + 2667792936946706027U;
            aOrbiterB = (aWandererI + RotL64(aScatter, 26U)) + 12020969779370926953U;
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 13U)) + 737340727886903447U;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 37U)) + 1681797651799760502U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aCross, 39U)) + 2956186342689489064U) + RotL64(aNonceWordA, 48U);
            aOrbiterF = ((aWandererG + RotL64(aIngress, 21U)) + RotL64(aCarry, 23U)) + 1876852870402977177U;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 43U)) + RotL64(aCarry, 43U)) + 6433205819353555071U;
            aOrbiterK = (aWandererD + RotL64(aCross, 11U)) + 9065076854974222998U;
            //
            aOrbiterI = (((aOrbiterI + aOrbiterG) + 3254410578766789992U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1]) + RotL64(aNonceWordE, 23U);
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 2005081975473815576U;
            aOrbiterH = RotL64((aOrbiterH * 9947701153722014085U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 15992999234834560419U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 3458344156815120948U;
            aOrbiterG = RotL64((aOrbiterG * 1668460113964608051U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 17069783053664877727U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 1260234710193913099U;
            aOrbiterB = RotL64((aOrbiterB * 4561226779897414381U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 3825186451876061335U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 2905344294992827535U;
            aOrbiterE = RotL64((aOrbiterE * 2469896090698580795U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 18141402347899180617U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 8760129857609925066U;
            aOrbiterF = RotL64((aOrbiterF * 2507999156108123047U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 594052473780678210U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 13216719212966128379U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10691355329696722303U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 10029948739466316169U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 11912428807431992996U;
            aOrbiterJ = RotL64((aOrbiterJ * 85016510811938307U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 8735634019801417287U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 12785916159063273545U;
            aOrbiterC = RotL64((aOrbiterC * 1161917531260663357U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 367752057919802452U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 3961036242431041564U;
            aOrbiterD = RotL64((aOrbiterD * 16352646009782597315U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 3858415336170090719U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 14325258358254321551U) ^ RotL64(aNonceWordG, 19U);
            aOrbiterA = RotL64((aOrbiterA * 12080431158781060059U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 16872184337970977180U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 12380376990224645149U;
            aOrbiterK = RotL64((aOrbiterK * 16559121155413059221U), 43U);
            //
            aIngress = RotL64(aOrbiterH, 19U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterK, 53U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 21U));
            aIngress = aIngress + (RotL64(aOrbiterD, 38U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 41U) + aOrbiterA) + RotL64(aOrbiterG, 5U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 37U)) + aOrbiterB);
            aWandererD = aWandererD ^ ((RotL64(aCross, 60U) + aOrbiterK) + RotL64(aOrbiterH, 29U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 53U)) + aOrbiterD) + RotL64(aCarry, 47U)) + aPhaseDWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 43U) + aOrbiterE) + RotL64(aOrbiterC, 39U)) + RotL64(aNonceWordC, 13U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 37U) + aOrbiterJ) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 11U)) + RotL64(aNonceWordH, 21U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 39U) + aOrbiterG) + RotL64(aOrbiterC, 60U));
            aWandererI = aWandererI + ((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 11U)) + aOrbiterI);
            aWandererF = aWandererF ^ ((RotL64(aCross, 53U) + aOrbiterF) + RotL64(aOrbiterC, 43U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 18U) + aOrbiterF) + RotL64(aOrbiterK, 19U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 21U) + aOrbiterE) + RotL64(aOrbiterH, 58U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 46U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 53U);
            aCarry = aCarry + RotL64(aIngress, 50U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 27U) ^ RotL64(aNonceWordA, 38U)) ^ RotL64(aNonceWordG, 53U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 14001U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((aIndex + 15807U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 11U) ^ RotL64(aNonceWordE, 51U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13477U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14259U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 47U) + RotL64(aCarry, 23U)) ^ (RotL64(aPrevious, 35U) ^ RotL64(aCross, 10U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterE = ((aWandererG + RotL64(aIngress, 18U)) + RotL64(aCarry, 3U)) + 17668251151213543491U;
            aOrbiterC = (aWandererF + RotL64(aScatter, 57U)) + 16101602509895104517U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 35U)) + RotL64(aCarry, 21U)) + 9083915270773304935U;
            aOrbiterD = (aWandererD + RotL64(aCross, 3U)) + 12810720730318214811U;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 43U)) + 18113428002071925621U) + RotL64(aNonceWordB, 21U);
            aOrbiterA = (aWandererB + RotL64(aIngress, 37U)) + 1582208899354109878U;
            aOrbiterF = (aWandererA + RotL64(aScatter, 53U)) + 4180688104819188154U;
            aOrbiterK = (((aWandererC + RotL64(aCross, 12U)) + 8954598189262820611U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 22U)) & S_SALT1]) + RotL64(aNonceWordD, 47U);
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 5U)) + 15360094153175355879U) + aPhaseDOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aPrevious, 39U)) + 8383954114668216260U;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 29U)) + RotL64(aCarry, 39U)) + 15626783326234049197U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 10609978564404958066U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 17656516608997517984U) ^ RotL64(aNonceWordF, 59U);
            aOrbiterI = RotL64((aOrbiterI * 4590620354119899777U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 760077259110786536U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 3597338735888033063U;
            aOrbiterA = RotL64((aOrbiterA * 6548831472863517621U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 4431777844935985157U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 10710423172154671296U;
            aOrbiterC = RotL64((aOrbiterC * 16267496318491473315U), 5U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterG) + 10240882795242085185U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]) + RotL64(aNonceWordG, 23U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 7826053487019825891U;
            aOrbiterJ = RotL64((aOrbiterJ * 15053729937684375907U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 9418883403715727353U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 11507423614799075545U;
            aOrbiterK = RotL64((aOrbiterK * 16189463984557044693U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 11545217316421066655U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 617921402135485341U;
            aOrbiterG = RotL64((aOrbiterG * 8182920764965471653U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 14456933220749921009U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 7990243583564535387U;
            aOrbiterE = RotL64((aOrbiterE * 5994900368027985469U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 14023633125757654751U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 11319146808574958827U;
            aOrbiterD = RotL64((aOrbiterD * 13676159969338309307U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 14161653180846538446U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 17993503892528842342U;
            aOrbiterF = RotL64((aOrbiterF * 12184170842617942651U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 10449311783872638478U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 17210495321003036773U;
            aOrbiterH = RotL64((aOrbiterH * 17591257107603354151U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 14586515403314763393U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 17668251151213543491U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9367185933291003363U), 3U);
            //
            aIngress = RotL64(aOrbiterH, 41U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterA, 52U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + RotL64(aOrbiterG, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterB, 51U)) + aOrbiterE) + RotL64(aCarry, 41U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterI, 6U)) + aOrbiterF) + aPhaseDWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterJ, 13U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 39U)) + aOrbiterF);
            aWandererF = aWandererF + (((RotL64(aScatter, 30U) + aOrbiterA) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterH, 35U)) + aOrbiterK);
            aWandererB = aWandererB + (((RotL64(aPrevious, 53U) + aOrbiterK) + RotL64(aOrbiterF, 37U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterI, 27U)) + aOrbiterG) + RotL64(aNonceWordC, 39U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 34U) + RotL64(aOrbiterF, 53U)) + aOrbiterG);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 11U) + aOrbiterG) + RotL64(aOrbiterA, 23U)) + RotL64(aNonceWordA, 56U));
            aWandererE = aWandererE + ((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterH, 60U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 60U));
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 34U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 37U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 43U) ^ RotL64(aNonceWordH, 11U)) ^ RotL64(aNonceWordB, 23U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 17208U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((aIndex + 20014U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 12U) ^ RotL64(aNonceWordE, 53U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 17005U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16795U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aIngress, 5U)) + (RotL64(aCross, 28U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterA = ((aWandererI + RotL64(aScatter, 43U)) + 9446153639709651566U) + aPhaseDOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aCross, 53U)) + 10550762260670758167U) + RotL64(aNonceWordD, 19U);
            aOrbiterG = (aWandererJ + RotL64(aIngress, 18U)) + 7062634922142578383U;
            aOrbiterK = (aWandererK + RotL64(aPrevious, 11U)) + 9178499097812764515U;
            aOrbiterD = ((aWandererC + RotL64(aCross, 35U)) + RotL64(aCarry, 53U)) + 6887103379773525538U;
            aOrbiterJ = (aWandererH + RotL64(aIngress, 51U)) + 6239750312052010257U;
            aOrbiterB = (((aWandererD + RotL64(aPrevious, 39U)) + RotL64(aCarry, 57U)) + 17645022614523287959U) + RotL64(aNonceWordF, 12U);
            aOrbiterF = (aWandererB + RotL64(aScatter, 3U)) + 3639618183259408272U;
            aOrbiterC = ((aWandererG + RotL64(aCross, 21U)) + 3131737117548745095U) + aPhaseDOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aIngress, 46U)) + 7253994382396406554U;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 27U)) + RotL64(aCarry, 35U)) + 15217993711938379561U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 12594152227603630033U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 11250170200489647869U;
            aOrbiterG = RotL64((aOrbiterG * 546800378327864723U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 12936942656624279424U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 10990736056052106149U;
            aOrbiterD = RotL64((aOrbiterD * 7123916809953459187U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 12787293075893090465U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 17154990205620778151U;
            aOrbiterJ = RotL64((aOrbiterJ * 10031369940028159521U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 1270827262969060301U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 17337623431665013136U;
            aOrbiterB = RotL64((aOrbiterB * 1517262088236356107U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 830330490987911853U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 6828309232554560547U) ^ RotL64(aNonceWordG, 35U);
            aOrbiterF = RotL64((aOrbiterF * 9742464176986145819U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 11470087853413986203U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 10470148870747884420U;
            aOrbiterC = RotL64((aOrbiterC * 6766079738799967443U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 18315536891901859637U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 12264670822285914271U;
            aOrbiterH = RotL64((aOrbiterH * 5841574505408674119U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 10931842095884524879U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 11134871340959676257U;
            aOrbiterI = RotL64((aOrbiterI * 11714837622285605745U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 11484168476761306078U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 5964766416973454097U;
            aOrbiterA = RotL64((aOrbiterA * 14721123403032510803U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 10646362765367117994U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 8994267196877016381U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17386417559346134797U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 16797547458402042464U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 9446153639709651566U) ^ RotL64(aNonceWordH, 25U);
            aOrbiterK = RotL64((aOrbiterK * 567585472220695323U), 19U);
            //
            aIngress = RotL64(aOrbiterJ, 43U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterA, 58U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aIngress, 53U) + aOrbiterF) + RotL64(aOrbiterA, 11U)) + RotL64(aNonceWordC, 27U)) + aPhaseDWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 43U) + aOrbiterJ) + RotL64(aOrbiterK, 58U));
            aWandererH = aWandererH + ((RotL64(aCross, 27U) + aOrbiterE) + RotL64(aOrbiterK, 47U));
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterB, 23U)) + aOrbiterA) + RotL64(aNonceWordA, 39U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 48U) + aOrbiterD) + RotL64(aOrbiterG, 41U)) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 37U)) + aOrbiterJ);
            aWandererA = aWandererA + (((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterI, 27U)) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterF, 52U)) + aOrbiterK);
            aWandererI = aWandererI + ((RotL64(aIngress, 23U) + RotL64(aOrbiterH, 43U)) + aOrbiterJ);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 60U) + aOrbiterH) + RotL64(aOrbiterC, 35U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 13U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 38U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererC, 3U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 19U) ^ RotL64(aNonceWordE, 3U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 22562U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((aIndex + 23284U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 53U) ^ RotL64(aNonceWordC, 3U)) ^ RotL64(aNonceWordH, 29U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 23249U)) & S_BLOCK1], 42U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27034U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 3U)) ^ (RotL64(aPrevious, 20U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterB = (aWandererF + RotL64(aScatter, 39U)) + 11698283336767769359U;
            aOrbiterK = (aWandererC + RotL64(aIngress, 37U)) + 13297826354831483872U;
            aOrbiterC = (((aWandererE + RotL64(aPrevious, 43U)) + RotL64(aCarry, 5U)) + 15254999058287530795U) + RotL64(aNonceWordC, 11U);
            aOrbiterI = ((aWandererI + RotL64(aCross, 24U)) + 17474166585085346567U) + RotL64(aNonceWordA, 55U);
            aOrbiterD = ((aWandererG + RotL64(aScatter, 29U)) + RotL64(aCarry, 43U)) + 15684783498452840289U;
            aOrbiterG = (aWandererJ + RotL64(aIngress, 5U)) + 5061229733465216486U;
            aOrbiterE = (aWandererA + RotL64(aPrevious, 47U)) + 15370981279168377944U;
            aOrbiterF = (aWandererH + RotL64(aCross, 52U)) + 17966672773619554092U;
            aOrbiterA = (aWandererK + RotL64(aIngress, 3U)) + 14685092893994491068U;
            aOrbiterJ = (((aWandererD + RotL64(aCross, 41U)) + RotL64(aCarry, 23U)) + 12798804186209406389U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = ((aWandererB + RotL64(aScatter, 27U)) + 2848444181474221574U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 8551142075919636146U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 8833198159158950723U;
            aOrbiterC = RotL64((aOrbiterC * 7650289040764974737U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 7351473160893666232U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 14204899612487622222U;
            aOrbiterG = RotL64((aOrbiterG * 6317485031956448029U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 7008985178526543258U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 13576796403863120356U;
            aOrbiterF = RotL64((aOrbiterF * 13745839827679114077U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 5769784656937900699U) + RotL64(aNonceWordB, 23U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 14075925808204936705U;
            aOrbiterJ = RotL64((aOrbiterJ * 5844894088757604713U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 17818667502858010896U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 16016922065572683130U;
            aOrbiterB = RotL64((aOrbiterB * 7525645833898085373U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 1582458237855075977U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 10830440354527138227U;
            aOrbiterI = RotL64((aOrbiterI * 10499386926982228251U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 10653964151654643772U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 11218475491129483859U;
            aOrbiterE = RotL64((aOrbiterE * 3338108067044357141U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 9863649760189649255U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 13790281439048354358U;
            aOrbiterA = RotL64((aOrbiterA * 4682098083538482849U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 14846954923718136337U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 522207783972623813U) ^ RotL64(aNonceWordH, 37U);
            aOrbiterH = RotL64((aOrbiterH * 14299798934454852811U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 426829715716262697U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 7482977730216354509U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6317437989422015173U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 10736099808538972990U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 11698283336767769359U;
            aOrbiterD = RotL64((aOrbiterD * 17230175904095995929U), 13U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterC, 47U);
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterG, 39U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterI, 56U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 41U)) + RotL64(aNonceWordG, 48U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterF, 29U)) + aOrbiterA);
            aWandererA = aWandererA + ((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterJ, 20U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 27U)) + aOrbiterG);
            aWandererI = aWandererI + ((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterK, 53U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 21U) + aOrbiterK) + RotL64(aOrbiterI, 37U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 58U) + aOrbiterG) + RotL64(aOrbiterC, 43U)) + aPhaseDWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterI, 39U)) + aOrbiterE) + RotL64(aNonceWordF, 41U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 39U) + aOrbiterG) + RotL64(aOrbiterH, 13U)) + aPhaseDWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 11U) + aOrbiterJ) + RotL64(aOrbiterD, 10U));
            aWandererE = aWandererE + (((RotL64(aCross, 60U) + aOrbiterF) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 6U));
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + RotL64(aWandererB, 51U);
            aCarry = aCarry + RotL64(aIngress, 30U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 3U) ^ RotL64(aNonceWordA, 12U)) ^ RotL64(aNonceWordF, 57U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 27961U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32153U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 23U) ^ RotL64(aNonceWordD, 41U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28580U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28693U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aPrevious, 57U)) + (RotL64(aIngress, 37U) ^ RotL64(aCross, 10U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterE = (aWandererK + RotL64(aPrevious, 29U)) + 2915859148137000694U;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 39U)) + 210680583721444425U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aCross, 44U)) + 6668118118775650387U;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 41U)) + RotL64(aCarry, 3U)) + 15794200818099010989U;
            aOrbiterB = (aWandererI + RotL64(aCross, 3U)) + 6565076707062828369U;
            aOrbiterF = (aWandererD + RotL64(aIngress, 47U)) + 16323164497808856719U;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 27U)) + 7965435318816716560U) + RotL64(aNonceWordH, 21U);
            aOrbiterA = (((aWandererA + RotL64(aPrevious, 5U)) + RotL64(aCarry, 13U)) + 7390281030573369017U) + RotL64(aNonceWordG, 57U);
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 35U)) + RotL64(aCarry, 51U)) + 2269738866911824875U;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 24U)) + 9664014216039993873U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aIngress, 37U)) + 18284857398028357633U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 367667619795303009U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 7935945060956274197U;
            aOrbiterK = RotL64((aOrbiterK * 5481786693511955209U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 16683666162337789540U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 10655658270998102390U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15231596813382239841U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 8307037916581540297U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 3247742749860703524U;
            aOrbiterF = RotL64((aOrbiterF * 15052136713218656641U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 10446792483683818139U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 16374602929344972364U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12599903932725787599U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 2411334498322777183U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 1093701164116833765U;
            aOrbiterA = RotL64((aOrbiterA * 13129220206835381729U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 17018480952982840635U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 17348395690080029814U;
            aOrbiterI = RotL64((aOrbiterI * 6212591395713433257U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 16111252311283623152U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 12776492920397785951U;
            aOrbiterD = RotL64((aOrbiterD * 6136009241593081821U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 12214538600808144816U) + RotL64(aNonceWordE, 4U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 10043377462096783363U;
            aOrbiterJ = RotL64((aOrbiterJ * 14639467375095185877U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 5101561512438055661U) + RotL64(aNonceWordC, 27U);
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 3683207847147603335U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14355438383379198639U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 14446947359104987749U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 7596096688268335354U;
            aOrbiterG = RotL64((aOrbiterG * 13522935803383107145U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 14015424109468938015U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 2915859148137000694U;
            aOrbiterC = RotL64((aOrbiterC * 3653144205211106817U), 37U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 21U);
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterI, 60U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 53U));
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterI, 11U));
            aWandererF = aWandererF + (((RotL64(aScatter, 53U) + aOrbiterE) + RotL64(aOrbiterA, 18U)) + RotL64(aCarry, 35U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterD, 21U)) + aOrbiterB);
            aWandererK = aWandererK + (((RotL64(aIngress, 30U) + aOrbiterG) + RotL64(aOrbiterB, 35U)) + aPhaseDWandererUpdateSaltF[((aIndex + 22U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 57U)) + aOrbiterI) + RotL64(aNonceWordF, 49U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 13U)) + aOrbiterJ) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterE, 39U)) + aOrbiterF);
            aWandererB = aWandererB + ((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterG, 29U));
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 5U) + aOrbiterJ) + RotL64(aOrbiterF, 44U)) + RotL64(aNonceWordB, 15U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 39U) + RotL64(aOrbiterK, 41U)) + aOrbiterH);
            aWandererC = aWandererC ^ ((RotL64(aCross, 14U) + aOrbiterA) + RotL64(aOrbiterC, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + (RotL64(aWandererJ, 24U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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

void TwistExpander_Fencing_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xA36A300464425AF9ULL + 0xA89995248A269EF4ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xBC81F6F1DA2F08A1ULL + 0xC6D26AEDFBD5E885ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x8EAB7C811AEE601DULL + 0xEB79749720FAF350ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xDAF68A13B846CB23ULL + 0xFD0F7E63ED13F085ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x9056F03565517413ULL + 0xE16A24F074533625ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x9AB20A9ECFB6825BULL + 0xEFD60E23D7982A03ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xD1622F85A150B773ULL + 0xE11B777450F3481DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xB20CEB23F53038C7ULL + 0xB12BA46E6FB62E98ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 43U) ^ RotL64(aNonceWordD, 54U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 1874U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 1455U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 51U) ^ RotL64(aNonceWordG, 29U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 1313U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneA[((aIndex + 4183U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 6U) ^ RotL64(aCarry, 21U)) + (RotL64(aCross, 57U) ^ RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterK = (aWandererD + RotL64(aPrevious, 43U)) + 1142447269198373880U;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 26U)) + RotL64(aCarry, 39U)) + 10581460640040336191U;
            aOrbiterH = (aWandererB + RotL64(aIngress, 41U)) + 14703062773878202900U;
            aOrbiterD = ((aWandererC + RotL64(aCross, 13U)) + 15737525756286914746U) + RotL64(aNonceWordD, 5U);
            aOrbiterB = ((aWandererF + RotL64(aIngress, 35U)) + 16178774478273186999U) + RotL64(aNonceWordF, 46U);
            aOrbiterI = ((aWandererG + RotL64(aCross, 60U)) + RotL64(aCarry, 13U)) + 2514897053906809160U;
            aOrbiterA = (((aWandererA + RotL64(aPrevious, 5U)) + RotL64(aCarry, 35U)) + 13702496607592508464U) + aPhaseEOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = (aWandererE + RotL64(aScatter, 29U)) + 18030885275418337965U;
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 11U)) + 5241783876161655984U;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 51U)) + 2807052676283587925U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = (aWandererH + RotL64(aIngress, 37U)) + 8022804576763271327U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 15597099852232205860U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 1538435607932096400U;
            aOrbiterH = RotL64((aOrbiterH * 7900752511710516981U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 11147868774413615365U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 9325213746830411568U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 561819005818948769U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 13792300423550555634U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 3134856508983945719U;
            aOrbiterK = RotL64((aOrbiterK * 4271845067763664863U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 8654966018053784882U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 8937113935476779267U;
            aOrbiterD = RotL64((aOrbiterD * 7386875687217705855U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 4135676350355234788U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 11407912615743682678U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2773506587480714695U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 10966950663872392059U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 6686634993700944582U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2509459942163678241U), 57U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterK) + 14154407529749257990U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]) + RotL64(aNonceWordC, 25U);
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 18054640398549782388U;
            aOrbiterG = RotL64((aOrbiterG * 7830759861389060149U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 14623473030642960240U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 1857945571104460086U;
            aOrbiterF = RotL64((aOrbiterF * 18039903315045620079U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 17650774450811065797U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 9458168381246672881U) ^ RotL64(aNonceWordH, 21U);
            aOrbiterB = RotL64((aOrbiterB * 3452665113988737563U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 16604923466236483242U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 12447748535184711684U;
            aOrbiterC = RotL64((aOrbiterC * 5982708155382249061U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 9589720286549780720U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 1142447269198373880U;
            aOrbiterE = RotL64((aOrbiterE * 8176719948031280789U), 11U);
            //
            aIngress = RotL64(aOrbiterC, 57U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 23U));
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 6U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterJ, 28U)) + aOrbiterK);
            aWandererC = aWandererC + ((RotL64(aIngress, 18U) + aOrbiterD) + RotL64(aOrbiterI, 43U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterH, 23U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterE, 51U)) + aOrbiterA) + RotL64(aCarry, 57U)) + RotL64(aNonceWordB, 23U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 21U)) + aOrbiterF);
            aWandererH = aWandererH + ((RotL64(aCross, 51U) + aOrbiterE) + RotL64(aOrbiterH, 35U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 53U)) + aOrbiterC);
            aWandererF = aWandererF + ((RotL64(aIngress, 11U) + aOrbiterG) + RotL64(aOrbiterJ, 39U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterA, 60U)) + aOrbiterK) + RotL64(aNonceWordA, 57U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 19U)) + aOrbiterB) + RotL64(aCarry, 19U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 60U) + aOrbiterB) + RotL64(aOrbiterD, 37U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 34U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + RotL64(aWandererF, 58U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 3U) ^ RotL64(aNonceWordE, 36U)) ^ RotL64(aNonceWordD, 23U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 9867U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneD[((aIndex + 10138U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 5U) ^ RotL64(aNonceWordF, 35U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 10454U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 10613U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 4U)) + (RotL64(aCross, 21U) ^ RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterA = (aWandererH + RotL64(aPrevious, 14U)) + 14249093584376402677U;
            aOrbiterK = ((aWandererG + RotL64(aScatter, 39U)) + 8756965951816492264U) + aPhaseEOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aCross, 53U)) + 11221139480258176330U;
            aOrbiterI = (((aWandererI + RotL64(aIngress, 11U)) + 17218894445564194851U) + aPhaseEOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1]) + RotL64(aNonceWordC, 46U);
            aOrbiterB = (aWandererA + RotL64(aCross, 47U)) + 8064642692524949490U;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 51U)) + RotL64(aCarry, 3U)) + 5822093203710704646U;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 60U)) + 3217799620158102238U;
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 57U)) + 2613757677892120843U) + RotL64(aNonceWordH, 43U);
            aOrbiterD = ((aWandererD + RotL64(aCross, 27U)) + RotL64(aCarry, 27U)) + 13647481499551657237U;
            aOrbiterC = (aWandererC + RotL64(aIngress, 23U)) + 3545714196663685016U;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 5U)) + RotL64(aCarry, 21U)) + 9735422670576621521U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 3911046580637583767U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 9315984027042049203U;
            aOrbiterG = RotL64((aOrbiterG * 12568550776487242469U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 8926367674641729058U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 11035347490524961446U;
            aOrbiterK = RotL64((aOrbiterK * 10948288997163592463U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 10748158733051120339U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 2467801787989056455U;
            aOrbiterB = RotL64((aOrbiterB * 12621934274702358977U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 9244415080474351390U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 8517784887959492079U) ^ RotL64(aNonceWordG, 29U);
            aOrbiterE = RotL64((aOrbiterE * 17022899813765884147U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 8409307332803038455U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 11043806021873232950U) ^ RotL64(aNonceWordB, 41U);
            aOrbiterD = RotL64((aOrbiterD * 8294888329708842989U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 17512395828450251457U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 16849067939795823992U;
            aOrbiterA = RotL64((aOrbiterA * 9361991804481514337U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 17541946638063238056U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 11430501673960586718U;
            aOrbiterI = RotL64((aOrbiterI * 15074409630605450091U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 78307505705383302U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 4834528975263832983U;
            aOrbiterJ = RotL64((aOrbiterJ * 17245673681686752861U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 9647985402149698269U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 6610247710757518931U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8672486173272686859U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 2706696306041774372U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 9519896513600816252U;
            aOrbiterC = RotL64((aOrbiterC * 7468605169665549731U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 14647351223431646222U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 14249093584376402677U;
            aOrbiterF = RotL64((aOrbiterF * 8296105266618697281U), 13U);
            //
            aIngress = RotL64(aOrbiterK, 29U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterB, 36U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterB, 47U)) + aOrbiterC);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterI, 29U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 14U) + aOrbiterI) + RotL64(aOrbiterH, 21U));
            aWandererC = aWandererC + (((RotL64(aCross, 53U) + RotL64(aOrbiterH, 4U)) + aOrbiterD) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 29U) + aOrbiterE) + RotL64(aOrbiterG, 41U)) + RotL64(aNonceWordA, 53U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterJ, 27U)) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 56U) + RotL64(aOrbiterA, 13U)) + aOrbiterG) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 11U) + aOrbiterA) + RotL64(aOrbiterD, 53U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterF, 39U)) + aOrbiterI);
            aWandererE = aWandererE + (((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterB, 19U)) + aPhaseEWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 5U) + aOrbiterD) + RotL64(aOrbiterG, 44U)) + RotL64(aNonceWordD, 31U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (RotL64(aWandererC, 48U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 26U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 11U) ^ RotL64(aNonceWordE, 20U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 14924U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 15101U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 39U) ^ RotL64(aNonceWordA, 56U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 14698U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneC[((aIndex + 15953U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aPrevious, 41U)) + (RotL64(aCross, 5U) ^ RotL64(aIngress, 22U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterH = ((aWandererA + RotL64(aScatter, 47U)) + 3561491146322798260U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aCross, 13U)) + 7075025056181885339U;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 29U)) + 9230910887904171613U) + RotL64(aNonceWordD, 13U);
            aOrbiterF = (aWandererG + RotL64(aPrevious, 37U)) + 4119781172609908917U;
            aOrbiterJ = ((aWandererD + RotL64(aCross, 6U)) + 17155609083870983149U) + RotL64(aNonceWordF, 31U);
            aOrbiterD = (aWandererJ + RotL64(aIngress, 39U)) + 2423018561430181695U;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 43U)) + RotL64(aCarry, 23U)) + 12957280305617615744U;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 41U)) + RotL64(aCarry, 39U)) + 2461704174772065813U;
            aOrbiterA = (aWandererE + RotL64(aScatter, 51U)) + 7907123257849391997U;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 34U)) + RotL64(aCarry, 27U)) + 7257868138318960007U;
            aOrbiterI = ((aWandererF + RotL64(aCross, 11U)) + 16425903703085702285U) + aPhaseEOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 2990822664594079467U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 5654819006718953817U;
            aOrbiterG = RotL64((aOrbiterG * 4465096036756887801U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 12183676471235678779U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 15026286960542123922U;
            aOrbiterD = RotL64((aOrbiterD * 17199049329995315279U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 12169080607071830522U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 2906296852254787499U;
            aOrbiterB = RotL64((aOrbiterB * 6754514406846040163U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 3029858695410344584U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 14406410317495954566U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9663780721657983421U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 11048818178401163861U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 13622063920319445043U;
            aOrbiterK = RotL64((aOrbiterK * 2516025554421589857U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 2642646089141233277U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 12761571777929273548U;
            aOrbiterE = RotL64((aOrbiterE * 5518252696078700127U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 7753802695131502382U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 8510425459525030222U;
            aOrbiterH = RotL64((aOrbiterH * 12412361423636026483U), 21U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterA) + 13522645164493316722U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1]) + RotL64(aNonceWordC, 9U);
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 1437430302489702713U;
            aOrbiterF = RotL64((aOrbiterF * 14019316635365783545U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 14745189473423751499U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 16968328257002103715U;
            aOrbiterC = RotL64((aOrbiterC * 17915588590593471981U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 5001838243344386314U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 13506188720092630563U;
            aOrbiterA = RotL64((aOrbiterA * 7010027510838271877U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 16902624500530747723U) + RotL64(aNonceWordB, 46U);
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 3561491146322798260U;
            aOrbiterI = RotL64((aOrbiterI * 95761172090277669U), 51U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterI, 50U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + (RotL64(aOrbiterE, 19U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + RotL64(aOrbiterC, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 51U)) + aOrbiterE) + RotL64(aNonceWordA, 57U));
            aWandererI = aWandererI + (((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterC, 37U)) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 21U) + aOrbiterJ) + RotL64(aOrbiterH, 35U));
            aWandererD = aWandererD + (((((RotL64(aCross, 50U) + aOrbiterG) + RotL64(aOrbiterK, 46U)) + RotL64(aCarry, 3U)) + RotL64(aNonceWordG, 55U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 5U)) + aOrbiterB) + aPhaseEWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 29U)) + aOrbiterD);
            aWandererB = aWandererB ^ ((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterB, 41U));
            aWandererA = aWandererA + ((RotL64(aScatter, 35U) + aOrbiterK) + RotL64(aOrbiterF, 57U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterJ, 39U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 53U) + aOrbiterF) + RotL64(aOrbiterH, 54U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 6U) + RotL64(aOrbiterC, 23U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 36U));
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + RotL64(aWandererF, 34U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 47U) ^ RotL64(aNonceWordD, 35U)) ^ RotL64(aNonceWordE, 27U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 21788U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 18035U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 3U) ^ RotL64(aNonceWordF, 13U)) ^ RotL64(aNonceWordA, 35U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 16530U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 19262U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 44U)) + (RotL64(aCross, 57U) ^ RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 60U)) + 8506388683755208267U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aCross, 39U)) + 2179323259055019735U;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 35U)) + 3345902531140983016U) + RotL64(aNonceWordC, 8U);
            aOrbiterC = (aWandererI + RotL64(aScatter, 5U)) + 17456139311481306584U;
            aOrbiterA = ((aWandererA + RotL64(aCross, 41U)) + 14587864088462311164U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 43U)) + 13178947246650647057U;
            aOrbiterF = (aWandererE + RotL64(aIngress, 56U)) + 12866578138946916962U;
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 11U)) + RotL64(aCarry, 5U)) + 13098524333655118173U;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 27U)) + RotL64(aCarry, 57U)) + 15451329483787541982U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 29U)) + RotL64(aCarry, 41U)) + 9494299579678389385U;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 51U)) + 15581954810375490643U) + RotL64(aNonceWordG, 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 4487042505730624892U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 2774455928791636186U;
            aOrbiterD = RotL64((aOrbiterD * 15847933919136777451U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 12435319582397755819U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 10077180055177766823U;
            aOrbiterA = RotL64((aOrbiterA * 3924363471701748703U), 57U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterD) + 10391963896910956455U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1]) + RotL64(aNonceWordE, 53U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 6149237416725301794U;
            aOrbiterJ = RotL64((aOrbiterJ * 10115917698918612823U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 15673402771629639978U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 14729117178956592426U;
            aOrbiterF = RotL64((aOrbiterF * 9070464269215820531U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 14492001279368870240U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 6278248084483259952U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16731228350971263873U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 15727518866499740411U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 8652631010810965473U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9508484121620912715U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 13660890300188313775U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 14699253534935936300U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3978135617259934869U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 1621689916308271346U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 5651399428852950385U;
            aOrbiterE = RotL64((aOrbiterE * 12220143634120124133U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 9833573729127477238U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 11171647423058940388U;
            aOrbiterI = RotL64((aOrbiterI * 9692915620701425697U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 10346908196429120039U) + RotL64(aNonceWordA, 41U);
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 11972183669378621435U;
            aOrbiterH = RotL64((aOrbiterH * 12364429258926549335U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 11063215816236490488U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 8506388683755208267U;
            aOrbiterC = RotL64((aOrbiterC * 11514304191652750181U), 13U);
            //
            aIngress = RotL64(aOrbiterF, 53U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterC, 41U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterJ, 60U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterB, 39U)) + aOrbiterI) + RotL64(aNonceWordB, 51U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 21U) + aOrbiterI) + RotL64(aOrbiterE, 24U));
            aWandererG = aWandererG + (((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterI, 11U)) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 53U) + aOrbiterI) + RotL64(aOrbiterG, 13U));
            aWandererB = aWandererB + ((((RotL64(aCross, 44U) + aOrbiterK) + RotL64(aOrbiterG, 41U)) + RotL64(aCarry, 53U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 39U) + aOrbiterF) + RotL64(aOrbiterB, 47U));
            aWandererE = aWandererE + ((RotL64(aScatter, 57U) + RotL64(aOrbiterA, 51U)) + aOrbiterG);
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 27U) + aOrbiterE) + RotL64(aOrbiterJ, 35U)) + RotL64(aNonceWordD, 11U)) + aPhaseEWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 35U) + RotL64(aOrbiterA, 57U)) + aOrbiterH);
            aWandererK = aWandererK ^ ((RotL64(aCross, 29U) + aOrbiterD) + RotL64(aOrbiterK, 54U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 48U) + aOrbiterC) + RotL64(aOrbiterH, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 56U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 60U));
            aCarry = aCarry + RotL64(aWandererE, 37U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 23U) ^ RotL64(aNonceWordA, 43U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 24916U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24269U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 41U) ^ RotL64(aNonceWordC, 54U)) ^ RotL64(aNonceWordB, 11U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26897U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26133U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 54U) + RotL64(aCarry, 23U)) + (RotL64(aCross, 35U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterG = ((aWandererI + RotL64(aScatter, 18U)) + 9855743441035905047U) + RotL64(aNonceWordF, 46U);
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 13U)) + RotL64(aCarry, 27U)) + 8426286937143990276U;
            aOrbiterI = ((aWandererB + RotL64(aCross, 37U)) + 7146752367170267002U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aIngress, 43U)) + 12947210066678101726U) + aPhaseEOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aPrevious, 57U)) + 15902163559925328965U;
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 35U)) + RotL64(aCarry, 37U)) + 8506649889346449469U;
            aOrbiterH = (aWandererG + RotL64(aScatter, 29U)) + 8226286036430263052U;
            aOrbiterE = ((aWandererD + RotL64(aCross, 23U)) + RotL64(aCarry, 13U)) + 2703047093452420216U;
            aOrbiterK = (aWandererE + RotL64(aScatter, 20U)) + 6769351326360139560U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 53U)) + 9857025533281333281U) + RotL64(aNonceWordG, 15U);
            aOrbiterA = (aWandererA + RotL64(aPrevious, 11U)) + 238297452132277585U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 7203572312072908931U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 12497027346166575632U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1703586436725662307U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 473851890609048879U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 1664484956453886047U;
            aOrbiterB = RotL64((aOrbiterB * 8566500756326590209U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 4635095143004754116U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 17695676150967345793U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5780416541584439301U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 15628965269863402796U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 9190117464399730235U;
            aOrbiterJ = RotL64((aOrbiterJ * 5586437438425999715U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 17835918238346011086U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 4398005402429282682U) ^ RotL64(aNonceWordE, 19U);
            aOrbiterG = RotL64((aOrbiterG * 14828737209913317463U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 10902589938246551273U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 15124274429081385923U;
            aOrbiterD = RotL64((aOrbiterD * 13524180348258805367U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 8747233520702236018U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 5445611443463112371U;
            aOrbiterH = RotL64((aOrbiterH * 10294109295823410447U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 16296005217836151910U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 6468336224317602364U) ^ RotL64(aNonceWordH, 31U);
            aOrbiterK = RotL64((aOrbiterK * 7369779919748367133U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 3827976387089403774U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 7773383658122100111U;
            aOrbiterA = RotL64((aOrbiterA * 9784711300597525161U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 18273794621528918389U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 8401424792700263455U;
            aOrbiterC = RotL64((aOrbiterC * 13003420427441089595U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 11402828934846813949U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 9855743441035905047U;
            aOrbiterF = RotL64((aOrbiterF * 7339549576423555273U), 19U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterG, 19U);
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 56U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 37U));
            aIngress = aIngress + RotL64(aOrbiterJ, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 10U) + aOrbiterB) + RotL64(aOrbiterD, 37U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterD, 5U)) + aOrbiterI);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 41U) + aOrbiterH) + RotL64(aOrbiterK, 51U));
            aWandererG = aWandererG + (((RotL64(aIngress, 19U) + RotL64(aOrbiterJ, 22U)) + aOrbiterF) + RotL64(aNonceWordB, 25U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 39U) + aOrbiterI) + RotL64(aOrbiterA, 43U)) + aPhaseEWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 12U) + aOrbiterI) + RotL64(aOrbiterJ, 41U)) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterG, 39U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 47U)) + aOrbiterH) + aPhaseEWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterF, 18U)) + aOrbiterK);
            aWandererD = aWandererD + ((((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 19U)) + RotL64(aNonceWordA, 9U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 51U) + aOrbiterC) + RotL64(aOrbiterA, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 26U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 28U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 3U) ^ RotL64(aNonceWordA, 43U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 29207U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneB[((aIndex + 28333U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 13U) ^ RotL64(aNonceWordB, 21U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27559U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30084U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aPrevious, 43U)) ^ (RotL64(aIngress, 56U) + RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterC = (aWandererG + RotL64(aCross, 27U)) + 4179952823252098240U;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 19U)) + 3745613452332101749U) + aPhaseEOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aPrevious, 40U)) + 2955689793395307176U;
            aOrbiterI = (aWandererE + RotL64(aIngress, 47U)) + 5639060180251322019U;
            aOrbiterG = (((aWandererA + RotL64(aScatter, 51U)) + RotL64(aCarry, 39U)) + 7901969163853586463U) + RotL64(aNonceWordH, 53U);
            aOrbiterB = (aWandererF + RotL64(aPrevious, 21U)) + 2242166787816318119U;
            aOrbiterE = (aWandererB + RotL64(aCross, 13U)) + 5239936443960750064U;
            aOrbiterD = (aWandererI + RotL64(aIngress, 35U)) + 13939136954732185558U;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 5U)) + 17058884136712717463U) + RotL64(aNonceWordE, 39U);
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 11U)) + RotL64(aCarry, 51U)) + 18148618660054585941U;
            aOrbiterH = (((aWandererJ + RotL64(aCross, 24U)) + RotL64(aCarry, 23U)) + 7022023484530327814U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 7722084537340095637U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 11764151879690934182U) ^ RotL64(aNonceWordC, 31U);
            aOrbiterK = RotL64((aOrbiterK * 12264384877711365655U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 16412785901758144708U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 9666718667728274824U;
            aOrbiterG = RotL64((aOrbiterG * 10865799822751771795U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 4307127540152109364U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 2457646804702647606U;
            aOrbiterB = RotL64((aOrbiterB * 6340030928007058595U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 3179394870088602208U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 504977947273774249U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16190282058883481551U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 16182729401018310837U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 7110817020445860609U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13371352088428584087U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 12960656706837391973U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 7103806893724395904U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14365984439655979791U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 1248300178080633527U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 7195473175424961337U;
            aOrbiterF = RotL64((aOrbiterF * 4633558992739305045U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 13007951568242991449U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 10296811247653636372U;
            aOrbiterH = RotL64((aOrbiterH * 16469682651380549395U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 13922797949001028335U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 16773545425463040155U;
            aOrbiterC = RotL64((aOrbiterC * 10639282630227832397U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 2888887140296117803U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 10279517418046269817U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8600355360339461535U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 17303373436784809093U) + RotL64(aNonceWordD, 30U);
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 4179952823252098240U;
            aOrbiterI = RotL64((aOrbiterI * 3675754609699406437U), 51U);
            //
            aIngress = RotL64(aOrbiterE, 24U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + (RotL64(aOrbiterI, 39U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterB, 18U)) + aOrbiterI) + RotL64(aNonceWordG, 3U));
            aWandererB = aWandererB + (((RotL64(aCross, 56U) + RotL64(aOrbiterE, 35U)) + aOrbiterB) + RotL64(aCarry, 21U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 23U)) + aOrbiterC);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 51U) + aOrbiterE) + RotL64(aOrbiterF, 39U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterI, 21U)) + aOrbiterF) + aPhaseEWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 23U) + RotL64(aOrbiterD, 27U)) + aOrbiterG) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterG, 57U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterK, 43U)) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 29U)) + aOrbiterC);
            aWandererE = aWandererE + (((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterA, 48U)) + RotL64(aNonceWordF, 21U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 36U) + aOrbiterB) + RotL64(aOrbiterJ, 41U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 28U));
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (RotL64(aWandererK, 48U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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

void TwistExpander_Fencing_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xA35A49A07A4A7E4DULL + 0xDD247B7AFF63A07AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xE4FA39A77E585051ULL + 0xF08E542A8E95E492ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xF344754342298C7FULL + 0xD7B175768500477AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x8E98D351D9D7874FULL + 0x98952FA338F758A0ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xD8DDE638DDC5558FULL + 0xD16B054447C9A3D1ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xEB3EF4B730BEC997ULL + 0x8328A155BAC76712ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xE107B8426571829FULL + 0xBB355755142BA5B0ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x8E677077070A5C0DULL + 0xD0BC1A7F6E144F34ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 5U) ^ RotL64(aNonceWordE, 24U)) ^ RotL64(aNonceWordG, 37U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 5146U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4910U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 53U) ^ RotL64(aNonceWordH, 29U)) ^ RotL64(aNonceWordB, 3U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5222U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((aIndex + 993U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 54U) + RotL64(aCross, 21U)) ^ (RotL64(aCarry, 3U) + RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = (aWandererB + RotL64(aCross, 26U)) + 6469584119078165548U;
            aOrbiterK = (aWandererH + RotL64(aIngress, 43U)) + 14329756366517987910U;
            aOrbiterJ = (aWandererD + RotL64(aScatter, 57U)) + 12890831797059772123U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 3U)) + RotL64(aCarry, 57U)) + 3164503807500018990U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 21U)) + 177531431387646836U) + aPhaseFOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aIngress, 23U)) + 3167421392893561015U;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 6U)) + 2813174781844753460U) + RotL64(aNonceWordC, 55U);
            aOrbiterH = (((aWandererC + RotL64(aCross, 51U)) + RotL64(aCarry, 27U)) + 10953270419153249857U) + RotL64(aNonceWordG, 19U);
            aOrbiterC = (aWandererF + RotL64(aIngress, 29U)) + 16911518309710356951U;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 37U)) + RotL64(aCarry, 53U)) + 6616750447844893150U;
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 19U)) + 10276741398025985982U) + aPhaseFOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 6206043608461213208U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 12021552904553405793U;
            aOrbiterJ = RotL64((aOrbiterJ * 10023362889960174909U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 15283586234744144846U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 5923238786775948571U;
            aOrbiterF = RotL64((aOrbiterF * 8200882393521882651U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 11044014510971660078U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 9351141024085076044U;
            aOrbiterD = RotL64((aOrbiterD * 13316079344614432317U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 17703395981862992420U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 10154548848376027087U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12324478347590509035U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 8836420852291617425U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 10193385413543886344U;
            aOrbiterG = RotL64((aOrbiterG * 824935982418585449U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 8248580084535685190U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 3910083671888152974U) ^ RotL64(aNonceWordH, 59U);
            aOrbiterC = RotL64((aOrbiterC * 17825311776715895927U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 12350341628569930642U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 2565977481575002842U;
            aOrbiterA = RotL64((aOrbiterA * 18233446879833776677U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 9271041067874027417U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 14289254596554201861U;
            aOrbiterK = RotL64((aOrbiterK * 7985522692852251413U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 5981802134118235214U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 14047813418129636856U) ^ RotL64(aNonceWordE, 25U);
            aOrbiterB = RotL64((aOrbiterB * 15961435325216504877U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 11808443842149398212U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 11380858372643695792U;
            aOrbiterH = RotL64((aOrbiterH * 100198424024622179U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 10385375464069162356U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 6469584119078165548U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5263876933019848989U), 57U);
            //
            aIngress = RotL64(aOrbiterK, 21U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (RotL64(aOrbiterA, 39U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 24U));
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterG, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 41U) + aOrbiterC) + RotL64(aOrbiterE, 29U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterD, 19U)) + aOrbiterB) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterE, 23U));
            aWandererI = aWandererI + (((RotL64(aScatter, 46U) + RotL64(aOrbiterB, 41U)) + aOrbiterC) + RotL64(aCarry, 19U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 53U) + aOrbiterD) + RotL64(aOrbiterE, 46U));
            aWandererE = aWandererE + ((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterG, 5U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterC, 3U)) + RotL64(aNonceWordB, 41U));
            aWandererF = aWandererF + ((RotL64(aScatter, 37U) + aOrbiterF) + RotL64(aOrbiterH, 43U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 56U) + RotL64(aOrbiterH, 35U)) + aOrbiterA);
            aWandererH = aWandererH + (((((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterK, 37U)) + RotL64(aCarry, 29U)) + RotL64(aNonceWordA, 8U)) + aPhaseFWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterH, 52U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 6U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererC, 42U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 20U) ^ RotL64(aNonceWordC, 57U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 7579U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((aIndex + 8477U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 26U) ^ RotL64(aNonceWordG, 43U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 9698U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((aIndex + 7739U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCarry, 5U)) + (RotL64(aCross, 52U) ^ RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = (aWandererA + RotL64(aScatter, 23U)) + 12615321415808640429U;
            aOrbiterG = (aWandererG + RotL64(aCross, 27U)) + 15712784676459931207U;
            aOrbiterF = (aWandererJ + RotL64(aIngress, 21U)) + 11013335427004930046U;
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 53U)) + RotL64(aCarry, 3U)) + 8298733856304768806U;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 35U)) + RotL64(aCarry, 23U)) + 6207732959150824216U;
            aOrbiterA = ((((aWandererF + RotL64(aCross, 48U)) + RotL64(aCarry, 27U)) + 9769864876127544038U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1]) + RotL64(aNonceWordH, 30U);
            aOrbiterC = (aWandererE + RotL64(aPrevious, 57U)) + 10782181918651152563U;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 13U)) + 5790454015845620939U) + aPhaseFOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = (aWandererC + RotL64(aIngress, 5U)) + 15606578025386733803U;
            aOrbiterJ = (aWandererD + RotL64(aCross, 29U)) + 5522352539991175304U;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 42U)) + 5993355818572869649U) + RotL64(aNonceWordB, 55U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 10864534396947622047U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 12090053126235913528U;
            aOrbiterF = RotL64((aOrbiterF * 7250801471645972261U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 14191181677234981396U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 2258570108233924592U) ^ RotL64(aNonceWordG, 51U);
            aOrbiterG = RotL64((aOrbiterG * 8307541155393855209U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 8448114811381534603U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 2702389315763499817U;
            aOrbiterI = RotL64((aOrbiterI * 6710443836432274393U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 17202184076718780200U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 150549910056015002U;
            aOrbiterC = RotL64((aOrbiterC * 195034681254956335U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 4910512055808124967U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 4783477997418403079U;
            aOrbiterD = RotL64((aOrbiterD * 861977492146512865U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 13842899106208709771U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = (((aOrbiterK ^ aOrbiterB) ^ 7930112618036681468U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]) ^ RotL64(aNonceWordE, 61U);
            aOrbiterK = RotL64((aOrbiterK * 8609551859830858419U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 8790107242863198659U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 6882768826643279144U;
            aOrbiterE = RotL64((aOrbiterE * 13745521454063360763U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 12136498871759890015U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 8120456314755584336U;
            aOrbiterA = RotL64((aOrbiterA * 1830725195528043575U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 14425711740351183016U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 15907406009196323049U;
            aOrbiterH = RotL64((aOrbiterH * 8599371693260686839U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 4878521420367891861U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 1184672056055028939U;
            aOrbiterJ = RotL64((aOrbiterJ * 5963961755367831967U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 10126736568567000180U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 12615321415808640429U;
            aOrbiterB = RotL64((aOrbiterB * 11663715449073755137U), 41U);
            //
            aIngress = RotL64(aOrbiterI, 27U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterB, 14U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 43U));
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 37U));
            aIngress = aIngress + RotL64(aOrbiterC, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterJ, 29U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 39U) + aOrbiterB) + RotL64(aOrbiterD, 21U));
            aWandererC = aWandererC + (((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterJ, 36U)) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterC, 41U)) + aPhaseFWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 14U) + RotL64(aOrbiterF, 43U)) + aOrbiterH) + RotL64(aNonceWordD, 19U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 51U) + aOrbiterK) + RotL64(aOrbiterI, 19U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 53U) + aOrbiterK) + RotL64(aOrbiterH, 5U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterB, 39U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aScatter, 5U) + aOrbiterK) + RotL64(aOrbiterE, 48U)) + RotL64(aCarry, 37U));
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 57U)) + aOrbiterC) + RotL64(aNonceWordF, 11U)) + aPhaseFWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 26U) + RotL64(aOrbiterD, 13U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 60U));
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + RotL64(aWandererK, 6U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 52U) ^ RotL64(aNonceWordA, 39U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12713U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 12691U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 20U) ^ RotL64(aNonceWordG, 29U)) ^ RotL64(aNonceWordD, 3U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 13309U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((aIndex + 14265U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 24U) + RotL64(aCarry, 57U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 53U)) + 15726877954695761686U) + RotL64(aNonceWordE, 49U);
            aOrbiterC = (aWandererF + RotL64(aIngress, 35U)) + 14187652171881943587U;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 44U)) + 8420423151313882782U) + aPhaseFOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aCross, 3U)) + RotL64(aCarry, 23U)) + 14942322692433259283U;
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 27U)) + RotL64(aCarry, 19U)) + 7272331475919796255U;
            aOrbiterE = (((aWandererD + RotL64(aIngress, 29U)) + RotL64(aCarry, 39U)) + 154504365041805840U) + RotL64(aNonceWordA, 3U);
            aOrbiterK = (aWandererB + RotL64(aPrevious, 57U)) + 17475491222554948786U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 41U)) + 5759181483165339605U;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 60U)) + 5993060214499322845U) + aPhaseFOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = (aWandererC + RotL64(aIngress, 21U)) + 10901786237875941844U;
            aOrbiterD = (aWandererI + RotL64(aScatter, 47U)) + 17135786595614068473U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 5208202073886811165U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 6821452921018900631U;
            aOrbiterA = RotL64((aOrbiterA * 13119330055184115669U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 13348064837402206969U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 8967943922403445136U;
            aOrbiterE = RotL64((aOrbiterE * 300168481725373093U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 8130283784171430891U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 6351113882502502876U;
            aOrbiterC = RotL64((aOrbiterC * 15960622823993072903U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 6894708729226455769U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 12065058511247133944U) ^ RotL64(aNonceWordC, 14U);
            aOrbiterB = RotL64((aOrbiterB * 5432601727436935831U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 17138279326229372741U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 12987698199066890628U) ^ RotL64(aNonceWordD, 59U);
            aOrbiterJ = RotL64((aOrbiterJ * 12665716655177320977U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 13688833537574196675U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 4211971980434000618U;
            aOrbiterH = RotL64((aOrbiterH * 1374411763361518851U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 10376917117582537592U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 4807742522197923516U;
            aOrbiterG = RotL64((aOrbiterG * 15257251453302090961U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 18038296468177121243U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 6879666349379745258U;
            aOrbiterF = RotL64((aOrbiterF * 15819475269715810555U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 5193656664432659624U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 680899397323387963U;
            aOrbiterK = RotL64((aOrbiterK * 9857476056194621321U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 1851929589073547860U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 13093101559415170218U;
            aOrbiterI = RotL64((aOrbiterI * 13950928576652143737U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 13695333301427028607U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 15726877954695761686U;
            aOrbiterD = RotL64((aOrbiterD * 960063676226172027U), 53U);
            //
            aIngress = RotL64(aOrbiterJ, 39U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterB, 44U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aCross, 47U) + aOrbiterC) + RotL64(aOrbiterD, 11U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterI, 50U)) + aOrbiterB) + RotL64(aCarry, 41U)) + RotL64(aNonceWordH, 27U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterD, 19U)) + aOrbiterG) + RotL64(aNonceWordF, 37U));
            aWandererA = aWandererA + (((RotL64(aIngress, 56U) + aOrbiterI) + RotL64(aOrbiterE, 43U)) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterB, 3U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 37U) + RotL64(aOrbiterA, 27U)) + aOrbiterF);
            aWandererH = aWandererH ^ ((RotL64(aCross, 23U) + aOrbiterK) + RotL64(aOrbiterE, 21U));
            aWandererI = aWandererI + ((RotL64(aIngress, 35U) + RotL64(aOrbiterK, 53U)) + aOrbiterH);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 57U)) + aOrbiterE);
            aWandererG = aWandererG + ((RotL64(aPrevious, 12U) + RotL64(aOrbiterK, 34U)) + aOrbiterF);
            aWandererF = aWandererF ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterG, 47U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererD, 48U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 50U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 41U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 21U) ^ RotL64(aNonceWordD, 51U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 19403U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17050U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 3U) ^ RotL64(aNonceWordA, 51U)) ^ RotL64(aNonceWordE, 14U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16808U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20357U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 26U) + RotL64(aPrevious, 5U)) + (RotL64(aIngress, 39U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = (aWandererK + RotL64(aPrevious, 39U)) + 8020711767807230555U;
            aOrbiterI = (aWandererI + RotL64(aCross, 58U)) + 15368693777246341570U;
            aOrbiterA = (((aWandererE + RotL64(aScatter, 53U)) + RotL64(aCarry, 21U)) + 5117523734225562401U) + RotL64(aNonceWordC, 29U);
            aOrbiterJ = (aWandererA + RotL64(aIngress, 21U)) + 13155269151097507808U;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 41U)) + 9879303753623578272U;
            aOrbiterK = (aWandererG + RotL64(aIngress, 27U)) + 1165799257173794826U;
            aOrbiterD = (aWandererF + RotL64(aPrevious, 29U)) + 930641942062732091U;
            aOrbiterC = ((((aWandererH + RotL64(aCross, 23U)) + RotL64(aCarry, 39U)) + 11330571332221123153U) + aPhaseFOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1]) + RotL64(aNonceWordH, 35U);
            aOrbiterF = (aWandererB + RotL64(aPrevious, 47U)) + 2862963158282518899U;
            aOrbiterH = (((aWandererD + RotL64(aIngress, 6U)) + RotL64(aCarry, 35U)) + 6019186399361476659U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aCross, 51U)) + 1924419843785161958U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 12618629043591380461U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 9334176504266512405U;
            aOrbiterA = RotL64((aOrbiterA * 18239109235362925739U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 16829692481030013551U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 5604784396927022709U;
            aOrbiterB = RotL64((aOrbiterB * 2833893610883508353U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 16124030106598549644U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 16571659812830230677U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4668250364992383549U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 15171089673591843703U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 2826755560293849328U;
            aOrbiterD = RotL64((aOrbiterD * 9397017963457655287U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 9976785768283589291U) + RotL64(aNonceWordG, 43U);
            aOrbiterC = (((aOrbiterC ^ aOrbiterB) ^ 11845100564714691809U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]) ^ RotL64(aNonceWordB, 12U);
            aOrbiterC = RotL64((aOrbiterC * 4935139932585319251U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 7318560453127859950U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 3039196878830506712U;
            aOrbiterF = RotL64((aOrbiterF * 3140508261330698717U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 8850992055588337843U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 4219373528176869146U;
            aOrbiterH = RotL64((aOrbiterH * 1310964742529956743U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 1341474458715938799U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 15937557372891732898U;
            aOrbiterE = RotL64((aOrbiterE * 11437307017920192915U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 7512741986101399499U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 4304636545688233645U;
            aOrbiterG = RotL64((aOrbiterG * 1948671766238131953U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 11460886069492094055U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 2019818350627642126U;
            aOrbiterI = RotL64((aOrbiterI * 9802784763505584769U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 3190374588085859096U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 8020711767807230555U;
            aOrbiterJ = RotL64((aOrbiterJ * 12055760672321414929U), 57U);
            //
            aIngress = RotL64(aOrbiterK, 36U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + (RotL64(aOrbiterE, 23U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 46U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 23U) + RotL64(aOrbiterC, 51U)) + aOrbiterJ) + RotL64(aNonceWordF, 49U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 21U) + aOrbiterB) + RotL64(aOrbiterH, 24U));
            aWandererH = aWandererH + ((RotL64(aIngress, 13U) + aOrbiterJ) + RotL64(aOrbiterA, 5U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 6U) + aOrbiterI) + RotL64(aOrbiterJ, 47U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 41U) + aOrbiterF) + RotL64(aOrbiterB, 13U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterE, 19U));
            aWandererA = aWandererA + (((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterG, 37U)) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 30U) + RotL64(aOrbiterI, 3U)) + aOrbiterC) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterC, 39U)) + aOrbiterF) + RotL64(aCarry, 3U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 28U)) + aOrbiterF) + RotL64(aNonceWordE, 13U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 43U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 30U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 18U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 34U) ^ RotL64(aNonceWordF, 13U)) ^ RotL64(aNonceWordG, 5U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22416U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((aIndex + 23238U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 41U) ^ RotL64(aNonceWordB, 53U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22181U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 24206U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 51U)) + (RotL64(aIngress, 5U) ^ RotL64(aCross, 20U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = ((aWandererD + RotL64(aScatter, 5U)) + RotL64(aCarry, 43U)) + 12222235191147985484U;
            aOrbiterE = (aWandererH + RotL64(aIngress, 19U)) + 16367317014523328414U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 53U)) + RotL64(aCarry, 47U)) + 3511378091284703789U;
            aOrbiterD = (aWandererF + RotL64(aCross, 28U)) + 15247492830966725949U;
            aOrbiterF = (aWandererI + RotL64(aScatter, 21U)) + 7745995913390407897U;
            aOrbiterK = (((aWandererK + RotL64(aCross, 13U)) + RotL64(aCarry, 21U)) + 6463593307540108810U) + RotL64(aNonceWordE, 19U);
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 51U)) + 1101669311005268630U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aIngress, 11U)) + 12988052764067518580U;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 43U)) + 17717179747434679772U) + RotL64(aNonceWordD, 50U);
            aOrbiterG = ((aWandererC + RotL64(aIngress, 57U)) + 11662190906682400416U) + aPhaseFOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 34U)) + 6563014073547628748U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 13099094932059419219U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 16342730862261868847U;
            aOrbiterA = RotL64((aOrbiterA * 10988124108686164829U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 16855346813127524624U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 6570063128502306944U;
            aOrbiterK = RotL64((aOrbiterK * 4571570049463124831U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 11328352033809240501U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 11640986648833160901U;
            aOrbiterI = RotL64((aOrbiterI * 2895830492089678919U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 2675226158571501666U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 17700531248266458165U;
            aOrbiterG = RotL64((aOrbiterG * 2231403813970188657U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 7729597396731910874U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 15172374484412053756U;
            aOrbiterH = RotL64((aOrbiterH * 149009041406406517U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 9178769489257842683U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 9020154972097834926U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8910504667566521429U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 1317403761217790562U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 17151528554929201571U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3735945655450625203U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 11621882033959669977U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 10289504450815075623U) ^ RotL64(aNonceWordC, 39U);
            aOrbiterJ = RotL64((aOrbiterJ * 13365982786836243195U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 16178772981106335703U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 16896130772325866910U;
            aOrbiterB = RotL64((aOrbiterB * 6993524735412868965U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 9573223644675562575U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 17552463713786507189U;
            aOrbiterE = RotL64((aOrbiterE * 16103431656424881779U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 4801852246698369631U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 12222235191147985484U) ^ RotL64(aNonceWordF, 29U);
            aOrbiterF = RotL64((aOrbiterF * 2835204872125428065U), 19U);
            //
            aIngress = RotL64(aOrbiterH, 47U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterE, 44U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + RotL64(aOrbiterJ, 18U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterJ, 23U)) + aOrbiterI);
            aWandererA = aWandererA + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterD, 44U)) + aOrbiterK) + aPhaseFWandererUpdateSaltC[((aIndex + 24U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 18U) + aOrbiterI) + RotL64(aOrbiterE, 3U));
            aWandererC = aWandererC + ((((RotL64(aCross, 11U) + RotL64(aOrbiterB, 11U)) + aOrbiterJ) + RotL64(aCarry, 37U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 41U) + aOrbiterA) + RotL64(aOrbiterF, 41U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 6U)) + aOrbiterG);
            aWandererH = aWandererH ^ (((RotL64(aCross, 54U) + aOrbiterC) + RotL64(aOrbiterE, 21U)) + RotL64(aNonceWordG, 27U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterH, 57U)) + RotL64(aNonceWordA, 53U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 23U) + aOrbiterI) + RotL64(aOrbiterG, 39U));
            aWandererB = aWandererB + (((RotL64(aScatter, 29U) + aOrbiterK) + RotL64(aOrbiterC, 53U)) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 19U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererF, 6U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 53U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 21U) ^ RotL64(aNonceWordF, 60U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32407U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30339U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 24U) ^ RotL64(aNonceWordD, 3U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28284U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29072U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 40U) ^ RotL64(aIngress, 53U)) + (RotL64(aCross, 19U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = ((aWandererJ + RotL64(aCross, 21U)) + 2558105147674438050U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = (aWandererG + RotL64(aScatter, 43U)) + 15856662514774702561U;
            aOrbiterB = (aWandererC + RotL64(aIngress, 5U)) + 13346869226246584582U;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 35U)) + RotL64(aCarry, 11U)) + 7632111846116243973U;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 28U)) + 2102101361626976279U) + RotL64(aNonceWordH, 49U);
            aOrbiterI = ((aWandererE + RotL64(aIngress, 3U)) + 5605968705067851563U) + RotL64(aNonceWordC, 55U);
            aOrbiterK = (aWandererI + RotL64(aPrevious, 47U)) + 6842483186584326681U;
            aOrbiterC = ((aWandererB + RotL64(aCross, 51U)) + RotL64(aCarry, 57U)) + 5559797213819425064U;
            aOrbiterF = (aWandererA + RotL64(aScatter, 24U)) + 12422313931331576759U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 19U)) + RotL64(aCarry, 41U)) + 2751024420047872601U;
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 41U)) + 11031320239359798610U) + aPhaseFOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 14366375309473793217U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 11971479429768505316U;
            aOrbiterB = RotL64((aOrbiterB * 10063001532313098203U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 3947595951884469542U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 17882767922372770896U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3361906348965810211U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 513871456983509223U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 5951677013597794294U;
            aOrbiterI = RotL64((aOrbiterI * 8508629569649935293U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 437626309049021931U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 466674061172005705U) ^ RotL64(aNonceWordG, 29U);
            aOrbiterK = RotL64((aOrbiterK * 1310502572084891157U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 12362602809233133718U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 10525852878882195702U;
            aOrbiterC = RotL64((aOrbiterC * 17755022180514914325U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 17927000184308583095U) + RotL64(aNonceWordD, 61U);
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 566723721423470052U;
            aOrbiterF = RotL64((aOrbiterF * 17710534355278632573U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 9504585484034413577U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 4614306037721859929U;
            aOrbiterA = RotL64((aOrbiterA * 170807293799483539U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 1463218357720031588U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 4036696102163560633U;
            aOrbiterJ = RotL64((aOrbiterJ * 15389914226155130065U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 9907678911300898726U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 11804311892289601322U;
            aOrbiterH = RotL64((aOrbiterH * 13986106774841242253U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 6514645538508331396U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 17246364354815744899U;
            aOrbiterG = RotL64((aOrbiterG * 12800661037742526999U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 6725706155285333764U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 2558105147674438050U;
            aOrbiterE = RotL64((aOrbiterE * 6752457079901154727U), 29U);
            //
            aIngress = RotL64(aOrbiterB, 37U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 26U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + RotL64(aOrbiterK, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterA, 18U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 54U) + RotL64(aOrbiterA, 51U)) + aOrbiterE);
            aWandererA = aWandererA + (((((RotL64(aIngress, 23U) + RotL64(aOrbiterI, 37U)) + aOrbiterF) + RotL64(aCarry, 43U)) + RotL64(aNonceWordA, 5U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 21U) + aOrbiterJ) + RotL64(aOrbiterH, 43U)) + aPhaseFWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 3U)) + aOrbiterK);
            aWandererC = aWandererC ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterC, 29U)) + aOrbiterB);
            aWandererH = aWandererH + ((RotL64(aScatter, 37U) + aOrbiterC) + RotL64(aOrbiterG, 41U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 26U) + aOrbiterH) + RotL64(aOrbiterG, 47U));
            aWandererI = aWandererI + ((RotL64(aCross, 47U) + aOrbiterI) + RotL64(aOrbiterK, 53U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterF, 20U)) + RotL64(aNonceWordE, 48U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 5U)) + aOrbiterC) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 58U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + RotL64(aWandererH, 48U);
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

void TwistExpander_Fencing_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xE3F5C86B8E75DDE5ULL + 0xF7664710E0892ECAULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x969F7B74FCCB3DBFULL + 0xB75B51A2C055BC3AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xC38060B0A2209B83ULL + 0xA9792968BFC949F9ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xCDBFCEE7DA7EFAB3ULL + 0xF535C0A5F09417D8ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xB4BF9B0714381BA9ULL + 0xD62F3461BFC1067CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xCADA6527F1165A2DULL + 0x9A410F0E98A01F24ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x97E61DCA9CC0D7A7ULL + 0xBE317521C52B2822ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xD290E589C51D5D3FULL + 0xDE74A77F006E29C3ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 56U) ^ RotL64(aNonceWordF, 47U)) ^ RotL64(aNonceWordG, 13U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 4236U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneC[((aIndex + 2450U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 11U) ^ RotL64(aNonceWordC, 36U)) ^ RotL64(aNonceWordH, 47U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 1925U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 3936U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCarry, 27U)) ^ (RotL64(aIngress, 44U) + RotL64(aCross, 13U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 21U)) + 479672811032092393U) + aPhaseFOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aIngress, 30U)) + 18061121631394564425U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 39U)) + RotL64(aCarry, 11U)) + 14237400452740566065U;
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 27U)) + 6723123812257706134U) + RotL64(aNonceWordF, 38U);
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 47U)) + RotL64(aCarry, 29U)) + 4247997188026499248U;
            aOrbiterH = (aWandererC + RotL64(aIngress, 54U)) + 1939107415066134869U;
            aOrbiterK = (aWandererF + RotL64(aCross, 5U)) + 3912640123546395979U;
            aOrbiterF = (((aWandererI + RotL64(aScatter, 13U)) + RotL64(aCarry, 53U)) + 8295478436553964298U) + aPhaseFOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aCross, 3U)) + 3218960600711526885U) + RotL64(aNonceWordE, 47U);
            aOrbiterE = (aWandererB + RotL64(aScatter, 11U)) + 5874096203353388890U;
            aOrbiterG = (aWandererD + RotL64(aIngress, 51U)) + 10294536533673023358U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 11268561953904130747U) + RotL64(aNonceWordA, 5U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 16693201256788898423U;
            aOrbiterJ = RotL64((aOrbiterJ * 16291987237693567209U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 7550969634681894654U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 9501647424602245869U;
            aOrbiterH = RotL64((aOrbiterH * 11265865222096866605U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 8881869255994319423U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 16770136406906800016U;
            aOrbiterB = RotL64((aOrbiterB * 1782039587385512923U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 16185384746435761363U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 13841034186650721627U;
            aOrbiterI = RotL64((aOrbiterI * 12000155593277035447U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 15229062695864608309U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 3576122704615303733U) ^ RotL64(aNonceWordC, 41U);
            aOrbiterK = RotL64((aOrbiterK * 2433987493885779279U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 13898167174453181224U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 12878032061609524049U;
            aOrbiterA = RotL64((aOrbiterA * 18104665741338251495U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 12719156051299028649U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 8640980843376950769U;
            aOrbiterG = RotL64((aOrbiterG * 10242616778390983333U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 12133332160916004365U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 8743563985229104484U;
            aOrbiterD = RotL64((aOrbiterD * 4575129690615054691U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 7362223873479167793U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 4230720394788635807U;
            aOrbiterC = RotL64((aOrbiterC * 3658720603716856293U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 5095842824285329272U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 7483469517256234638U;
            aOrbiterF = RotL64((aOrbiterF * 9782114499878763883U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 17426017004856399653U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 479672811032092393U;
            aOrbiterE = RotL64((aOrbiterE * 14921028515589317919U), 43U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 13U);
            aIngress = aIngress + (RotL64(aOrbiterK, 26U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterF, 57U)) + aOrbiterD) + RotL64(aNonceWordD, 31U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterE, 35U)) + RotL64(aNonceWordH, 43U));
            aWandererH = aWandererH + (((RotL64(aIngress, 46U) + aOrbiterJ) + RotL64(aOrbiterK, 53U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 37U)) + aOrbiterG);
            aWandererB = aWandererB + ((RotL64(aCross, 39U) + RotL64(aOrbiterD, 39U)) + aOrbiterE);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterB, 44U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 5U)) + aOrbiterG);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterK, 3U)) + aOrbiterI);
            aWandererK = aWandererK + ((((RotL64(aCross, 14U) + aOrbiterG) + RotL64(aOrbiterI, 21U)) + RotL64(aCarry, 53U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 23U) + aOrbiterH) + RotL64(aOrbiterE, 12U));
            aWandererI = aWandererI + (((RotL64(aIngress, 27U) + RotL64(aOrbiterD, 27U)) + aOrbiterC) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 60U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 12U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 37U) ^ RotL64(aNonceWordE, 56U)) ^ RotL64(aNonceWordH, 27U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 10165U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8045U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 13U) ^ RotL64(aNonceWordA, 29U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 8212U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 7121U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aIngress, 3U)) ^ (RotL64(aCross, 22U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = (aWandererE + RotL64(aIngress, 27U)) + 13960289014350612206U;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 44U)) + RotL64(aCarry, 47U)) + 3483331015269589730U;
            aOrbiterH = (((aWandererA + RotL64(aPrevious, 21U)) + 6873299241002444518U) + aPhaseFOrbiterAssignSaltB[((aIndex + 12U)) & S_SALT1]) + RotL64(aNonceWordE, 35U);
            aOrbiterD = (aWandererF + RotL64(aScatter, 53U)) + 3562094007125534229U;
            aOrbiterI = (aWandererD + RotL64(aIngress, 5U)) + 11422367439932782705U;
            aOrbiterA = (aWandererJ + RotL64(aScatter, 51U)) + 532453428514259816U;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 37U)) + RotL64(aCarry, 19U)) + 17810941465810193088U;
            aOrbiterE = (aWandererG + RotL64(aCross, 12U)) + 11869759058631106331U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 57U)) + 8837581071876177566U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = ((aWandererC + RotL64(aIngress, 19U)) + RotL64(aCarry, 57U)) + 17185378327053837778U;
            aOrbiterC = ((aWandererB + RotL64(aScatter, 23U)) + 7578253375676981500U) + RotL64(aNonceWordC, 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 17112646434432814442U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 14949096407295697881U;
            aOrbiterH = RotL64((aOrbiterH * 14770977858283051753U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 4259590620758467836U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 6534899413644542303U;
            aOrbiterJ = RotL64((aOrbiterJ * 7987609419215568661U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 2637407498893694243U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 15819295597921425711U;
            aOrbiterI = RotL64((aOrbiterI * 5202015597375051399U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 6373559542002699718U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 11694562937392022505U;
            aOrbiterB = RotL64((aOrbiterB * 9311557972331218597U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 3308736483775453062U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 12749929710650475901U;
            aOrbiterF = RotL64((aOrbiterF * 248428400724560945U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 1569528215675579656U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 1044077933631689572U;
            aOrbiterG = RotL64((aOrbiterG * 6443796233912755143U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 8393422728124537471U) + RotL64(aNonceWordG, 47U);
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 2002732612516530754U;
            aOrbiterD = RotL64((aOrbiterD * 13702146823622364279U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 13469191942843147943U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 7633171368709520560U) ^ RotL64(aNonceWordB, 34U);
            aOrbiterA = RotL64((aOrbiterA * 9713514012478203047U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 4023206337737491091U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 15990323932023596968U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4816480271959713463U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 837005729394899591U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 9692088757104339973U;
            aOrbiterK = RotL64((aOrbiterK * 17971548293495807419U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 18039464962413134616U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 13960289014350612206U;
            aOrbiterC = RotL64((aOrbiterC * 931609478642506411U), 21U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterI, 3U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (RotL64(aOrbiterB, 37U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 44U));
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 41U)) + aOrbiterC) + RotL64(aCarry, 51U)) + RotL64(aNonceWordD, 13U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 52U) + RotL64(aOrbiterK, 47U)) + aOrbiterC) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 37U) + aOrbiterK) + RotL64(aOrbiterD, 60U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterH, 13U)) + aOrbiterJ);
            aWandererF = aWandererF + ((RotL64(aScatter, 35U) + aOrbiterG) + RotL64(aOrbiterH, 27U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 29U)) + aOrbiterA);
            aWandererG = aWandererG + (((RotL64(aCross, 29U) + aOrbiterJ) + RotL64(aOrbiterD, 53U)) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 24U) + RotL64(aOrbiterI, 43U)) + aOrbiterA) + RotL64(aNonceWordH, 45U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterF, 4U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterA, 39U));
            aWandererC = aWandererC + ((RotL64(aScatter, 39U) + RotL64(aOrbiterC, 21U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + (RotL64(aWandererG, 38U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 14U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 51U) ^ RotL64(aNonceWordG, 5U)) ^ RotL64(aNonceWordD, 20U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 13764U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((aIndex + 12308U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 3U) ^ RotL64(aNonceWordE, 37U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 11506U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 15069U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCross, 21U)) ^ (RotL64(aIngress, 3U) + RotL64(aCarry, 34U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = (aWandererK + RotL64(aScatter, 39U)) + 2571116506511057880U;
            aOrbiterF = (aWandererH + RotL64(aCross, 53U)) + 13112435411509707292U;
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 56U)) + RotL64(aCarry, 11U)) + 10403251762787357256U;
            aOrbiterK = (aWandererC + RotL64(aIngress, 27U)) + 8461951095541400405U;
            aOrbiterB = ((aWandererE + RotL64(aScatter, 3U)) + 9890793478557463815U) + aPhaseFOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = (aWandererA + RotL64(aPrevious, 23U)) + 3030229465991783707U;
            aOrbiterA = (aWandererG + RotL64(aIngress, 19U)) + 7273848154043719247U;
            aOrbiterD = ((aWandererJ + RotL64(aCross, 51U)) + RotL64(aCarry, 29U)) + 10681774862516028276U;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 5U)) + RotL64(aCarry, 47U)) + 7105082755586853104U;
            aOrbiterJ = (((aWandererD + RotL64(aPrevious, 29U)) + 6588579345319551129U) + aPhaseFOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1]) + RotL64(aNonceWordB, 45U);
            aOrbiterH = ((aWandererI + RotL64(aIngress, 46U)) + 14616333550242386092U) + RotL64(aNonceWordA, 15U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 15439666290229654921U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 3360304356760164799U;
            aOrbiterE = RotL64((aOrbiterE * 5164191920584106237U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 14438730801970761889U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 14515616787452085729U;
            aOrbiterC = RotL64((aOrbiterC * 2041601927968559821U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 4167853822635132419U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 8950982233003320239U;
            aOrbiterF = RotL64((aOrbiterF * 887144270884244907U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 12391327853728029953U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 7100871010552394421U;
            aOrbiterB = RotL64((aOrbiterB * 16552349374101955967U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 15381697462381887944U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 6801677551341079401U;
            aOrbiterD = RotL64((aOrbiterD * 13325954438427340703U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 947011315719204867U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 6356920162398333481U;
            aOrbiterJ = RotL64((aOrbiterJ * 5566721941682667419U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 8910262020598577378U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 8778455415977526457U) ^ RotL64(aNonceWordF, 7U);
            aOrbiterI = RotL64((aOrbiterI * 4092470497616637283U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 5585696961453127223U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 9670655481681494412U) ^ RotL64(aNonceWordE, 43U);
            aOrbiterK = RotL64((aOrbiterK * 7863197168965036383U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 10713004007087085729U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 4036355047492922339U;
            aOrbiterA = RotL64((aOrbiterA * 6923922258047667173U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 14580156873863533497U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 7049502932205025182U;
            aOrbiterG = RotL64((aOrbiterG * 8665428649262370727U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 12707521269341941677U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 2571116506511057880U;
            aOrbiterH = RotL64((aOrbiterH * 2388236789245943699U), 21U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 6U);
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + RotL64(aOrbiterE, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aCross, 5U) + RotL64(aOrbiterJ, 11U)) + aOrbiterI) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterB, 37U)) + aOrbiterF) + RotL64(aNonceWordD, 20U));
            aWandererF = aWandererF + (((RotL64(aIngress, 44U) + aOrbiterB) + RotL64(aOrbiterD, 43U)) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 27U) + aOrbiterK) + RotL64(aOrbiterE, 4U));
            aWandererG = aWandererG + (((RotL64(aCross, 53U) + RotL64(aOrbiterA, 19U)) + aOrbiterE) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 35U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 51U) + RotL64(aOrbiterG, 57U)) + aOrbiterD);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 41U) + aOrbiterK) + RotL64(aOrbiterC, 21U)) + RotL64(aNonceWordC, 9U));
            aWandererA = aWandererA + (((RotL64(aIngress, 3U) + RotL64(aOrbiterE, 13U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 22U) + RotL64(aOrbiterK, 29U)) + aOrbiterH);
            aWandererC = aWandererC + ((RotL64(aScatter, 39U) + RotL64(aOrbiterF, 60U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 48U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + RotL64(aWandererJ, 50U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 20U) ^ RotL64(aNonceWordF, 11U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 17822U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((aIndex + 18135U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 35U) ^ RotL64(aNonceWordD, 51U)) ^ RotL64(aNonceWordA, 43U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 20936U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 18176U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCross, 6U)) ^ (RotL64(aCarry, 57U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = (((aWandererI + RotL64(aScatter, 39U)) + RotL64(aCarry, 29U)) + 17470880031634374199U) + aPhaseFOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aCross, 52U)) + 757565846006937746U) + RotL64(aNonceWordF, 3U);
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 21U)) + 9419282475801345674U) + RotL64(aNonceWordC, 35U);
            aOrbiterF = (aWandererC + RotL64(aIngress, 35U)) + 2014248014107898196U;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 57U)) + RotL64(aCarry, 41U)) + 15113928519446490441U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 19U)) + RotL64(aCarry, 3U)) + 7346126964886259935U;
            aOrbiterC = (aWandererD + RotL64(aIngress, 47U)) + 5594123113093162359U;
            aOrbiterB = (aWandererG + RotL64(aScatter, 23U)) + 5659237263369402005U;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 60U)) + 11565709683423969703U) + aPhaseFOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = (aWandererF + RotL64(aCross, 43U)) + 16782863743534856287U;
            aOrbiterE = (aWandererK + RotL64(aIngress, 5U)) + 13499100900072115907U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 11414447651044205242U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 7545993795121430538U;
            aOrbiterH = RotL64((aOrbiterH * 10758488381206257261U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 11778229237616454988U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 2544793391976514665U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4021060413798523299U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 9972156716619459164U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 17651030383827445664U;
            aOrbiterA = RotL64((aOrbiterA * 6742914240706775487U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 17439147296849134543U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 10021926927948343656U;
            aOrbiterC = RotL64((aOrbiterC * 18139540407315440909U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 9309867875882669289U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 14951424455944346337U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10569523948169951309U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 2166343974068770659U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 11386993629011562026U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3091639433512536097U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 5747849744680120960U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 4019290369160113026U;
            aOrbiterK = RotL64((aOrbiterK * 5567515306039646735U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 3820540009554769592U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 8210747198363020939U;
            aOrbiterE = RotL64((aOrbiterE * 16215133106542452509U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 3006494852696036003U) + RotL64(aNonceWordG, 37U);
            aOrbiterI = (((aOrbiterI ^ aOrbiterG) ^ 2736305345451919450U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1]) ^ RotL64(aNonceWordH, 11U);
            aOrbiterI = RotL64((aOrbiterI * 11993452696344358247U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 6148431711118275178U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 6986633012691940738U;
            aOrbiterJ = RotL64((aOrbiterJ * 15672039482523804893U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 7837859154831245165U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 17470880031634374199U;
            aOrbiterF = RotL64((aOrbiterF * 2153299273348512243U), 23U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 5U);
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterG, 37U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 34U));
            aIngress = aIngress + (RotL64(aOrbiterF, 39U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterA, 35U)) + RotL64(aNonceWordD, 25U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 44U) + aOrbiterK) + RotL64(aOrbiterG, 11U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterD, 48U)) + aOrbiterG);
            aWandererC = aWandererC + (((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterH, 29U)) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterH, 51U)) + aOrbiterD);
            aWandererA = aWandererA + ((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 39U)) + aOrbiterD);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 34U) + aOrbiterD) + RotL64(aOrbiterI, 21U)) + aPhaseFWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 13U) + RotL64(aOrbiterE, 23U)) + aOrbiterB) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 37U) + aOrbiterF) + RotL64(aOrbiterJ, 57U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 3U) + RotL64(aOrbiterK, 41U)) + aOrbiterC) + RotL64(aNonceWordE, 48U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterA, 54U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererC, 56U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 24U));
            aCarry = aCarry + RotL64(aWandererB, 21U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 48U) ^ RotL64(aNonceWordF, 57U)) ^ RotL64(aNonceWordE, 39U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 25842U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23885U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 35U) ^ RotL64(aNonceWordH, 23U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24574U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneA[((aIndex + 25953U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aIngress, 11U)) ^ (RotL64(aCarry, 38U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = (aWandererC + RotL64(aCross, 11U)) + 4634399531433127141U;
            aOrbiterG = (aWandererG + RotL64(aScatter, 18U)) + 16961792729406903200U;
            aOrbiterC = (aWandererH + RotL64(aIngress, 57U)) + 4105280732301137738U;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 21U)) + 15692013501147331191U) + aPhaseFOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aCross, 39U)) + 1252216715968780587U;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 41U)) + RotL64(aCarry, 21U)) + 7958289043012473752U;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 43U)) + RotL64(aCarry, 5U)) + 6611577301818896615U;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 35U)) + 8506226754305949140U) + RotL64(aNonceWordH, 7U);
            aOrbiterD = (aWandererA + RotL64(aIngress, 23U)) + 3648813120449403353U;
            aOrbiterH = ((aWandererB + RotL64(aCross, 54U)) + 5195245426245535735U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = (((aWandererD + RotL64(aScatter, 47U)) + RotL64(aCarry, 39U)) + 542948051600803051U) + RotL64(aNonceWordA, 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 11974253551208964789U) + RotL64(aNonceWordF, 19U);
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 10596463592332655367U;
            aOrbiterC = RotL64((aOrbiterC * 10941161258815714641U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 12015129484061440159U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 8254944355710109060U;
            aOrbiterK = RotL64((aOrbiterK * 3233697992479357615U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 2754858806943915419U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 5007802002906662779U;
            aOrbiterF = RotL64((aOrbiterF * 15613733948331639723U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 6262190752136523216U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 10528977986487821428U;
            aOrbiterH = RotL64((aOrbiterH * 1184258264034585525U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 8511097226098211854U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 12091864735686692582U;
            aOrbiterI = RotL64((aOrbiterI * 6128140528141411237U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 4970966265236842566U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 10728884018459718341U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 18205183219769602827U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 13760057185629905360U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 6590269178744829056U;
            aOrbiterB = RotL64((aOrbiterB * 14482684769712170123U), 23U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterJ) + 765826377665103262U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]) + RotL64(aNonceWordC, 59U);
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 9364759196106579706U;
            aOrbiterD = RotL64((aOrbiterD * 10315111163659289329U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 4629303338428087146U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 15107221579712215172U;
            aOrbiterA = RotL64((aOrbiterA * 14410837138199304663U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 9407987092859067074U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 13589362515507116096U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4544198075069052713U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 2236921538387014026U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 4634399531433127141U;
            aOrbiterE = RotL64((aOrbiterE * 13132011613143486575U), 5U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterH, 47U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + (RotL64(aOrbiterC, 58U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aIngress, 53U) + aOrbiterC) + RotL64(aOrbiterK, 19U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterF, 35U)) + aOrbiterE);
            aWandererG = aWandererG + (((RotL64(aScatter, 57U) + aOrbiterE) + RotL64(aOrbiterJ, 23U)) + aPhaseFWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 18U) + RotL64(aOrbiterG, 37U)) + aOrbiterF);
            aWandererB = aWandererB + (((((RotL64(aScatter, 51U) + RotL64(aOrbiterA, 13U)) + aOrbiterI) + RotL64(aCarry, 39U)) + RotL64(aNonceWordB, 46U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 41U) + aOrbiterE) + RotL64(aOrbiterB, 43U));
            aWandererE = aWandererE + ((RotL64(aIngress, 21U) + aOrbiterH) + RotL64(aOrbiterF, 50U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 37U) + aOrbiterB) + RotL64(aOrbiterF, 27U));
            aWandererI = aWandererI + ((RotL64(aScatter, 30U) + aOrbiterC) + RotL64(aOrbiterD, 53U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterK, 3U)) + RotL64(aNonceWordD, 41U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 11U) + aOrbiterE) + RotL64(aOrbiterC, 48U)) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 10U));
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 3U) ^ RotL64(aNonceWordD, 43U)) ^ RotL64(aNonceWordA, 12U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30234U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((aIndex + 29097U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 27U) ^ RotL64(aNonceWordB, 5U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30284U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneB[((aIndex + 31127U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 53U)) + (RotL64(aIngress, 20U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = (aWandererD + RotL64(aPrevious, 24U)) + 5041131702736607991U;
            aOrbiterH = (aWandererG + RotL64(aCross, 53U)) + 9295010428212681446U;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 43U)) + 6235875895358766017U) + RotL64(aNonceWordG, 49U);
            aOrbiterK = (aWandererB + RotL64(aScatter, 3U)) + 2622227802531866918U;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 37U)) + RotL64(aCarry, 43U)) + 3888894734834524972U;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 35U)) + RotL64(aCarry, 47U)) + 241682012014701753U;
            aOrbiterC = (((aWandererC + RotL64(aScatter, 21U)) + RotL64(aCarry, 57U)) + 15758000422451568079U) + aPhaseFOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aCross, 11U)) + 2061944548396976912U;
            aOrbiterB = (((aWandererA + RotL64(aScatter, 46U)) + 8177144990755754531U) + aPhaseFOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1]) + RotL64(aNonceWordA, 55U);
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 39U)) + 554978075608818497U;
            aOrbiterI = (aWandererF + RotL64(aIngress, 27U)) + 250408260560714933U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 8700027645880997552U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 10026130047465480902U;
            aOrbiterA = RotL64((aOrbiterA * 12417270861933696623U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 9785843014096326696U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 9998582683258411251U;
            aOrbiterG = RotL64((aOrbiterG * 7197956237569462269U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 13817734599383455151U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 6647207154174092691U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1578528131687283531U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 4957715980509035719U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 4994885315786213197U;
            aOrbiterC = RotL64((aOrbiterC * 5676683798126497011U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 5072908311783966503U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 5535039946192891515U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2989412783482309753U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 6594577050344146271U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterE) ^ 8750154123258714856U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1]) ^ RotL64(aNonceWordC, 59U);
            aOrbiterB = RotL64((aOrbiterB * 6942158167127532003U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 3514769314840874873U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 8626045200273524281U;
            aOrbiterJ = RotL64((aOrbiterJ * 4315441782689789689U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 8524870284841706517U) + RotL64(aNonceWordF, 37U);
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 1841819423572964209U;
            aOrbiterI = RotL64((aOrbiterI * 9802481758007234681U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 12668382464510772517U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 6330331402801670515U;
            aOrbiterD = RotL64((aOrbiterD * 9096920618612750935U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 10346986196055766087U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 10932918162471200996U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6863632877625141567U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 6264557195446069146U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 5041131702736607991U;
            aOrbiterK = RotL64((aOrbiterK * 4978591546106895045U), 11U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterG, 19U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 21U));
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterK, 26U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 37U)) + aOrbiterA) + RotL64(aCarry, 21U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 30U) + aOrbiterK) + RotL64(aOrbiterF, 57U)) + RotL64(aNonceWordE, 15U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 41U) + RotL64(aOrbiterB, 5U)) + aOrbiterC) + RotL64(aCarry, 13U)) + RotL64(aNonceWordB, 22U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterA, 52U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((RotL64(aCross, 11U) + RotL64(aOrbiterD, 29U)) + aOrbiterI);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterD, 11U)) + aOrbiterB) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 19U) + RotL64(aOrbiterH, 47U)) + aOrbiterF);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 43U)) + aOrbiterA);
            aWandererC = aWandererC + ((RotL64(aPrevious, 54U) + RotL64(aOrbiterH, 41U)) + aOrbiterJ);
            aWandererH = aWandererH ^ ((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterH, 39U));
            aWandererG = aWandererG + ((RotL64(aScatter, 51U) + RotL64(aOrbiterE, 14U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererH, 22U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 50U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 4884U)) & S_BLOCK1], 54U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 231U)) & W_KEY1], 35U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 7862U)) & W_KEY1], 30U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 4353U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aIngress, 23U)) ^ (RotL64(aCross, 10U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (aWandererE + RotL64(aScatter, 51U)) + 10881271196314989997U;
            aOrbiterH = (aWandererD + RotL64(aIngress, 40U)) + 6406461249988567558U;
            aOrbiterE = ((aWandererH + RotL64(aCross, 29U)) + 17255067918280095959U) + aPhaseCOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aPrevious, 47U)) + 16690850682497718411U;
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 19U)) + RotL64(aCarry, 19U)) + 5576201059361086866U;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 23U)) + 11991259685693687554U;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 13U)) + RotL64(aCarry, 43U)) + 14652535244217836909U;
            aOrbiterF = ((aWandererF + RotL64(aCross, 3U)) + 1701789037170782122U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 36U)) + RotL64(aCarry, 35U)) + 953429054903473833U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 12064513610469714211U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 7993881398822002424U;
            aOrbiterE = RotL64((aOrbiterE * 11572884842788918377U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 14421313768013320050U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 11112386845630998889U;
            aOrbiterI = RotL64((aOrbiterI * 11771526352030371669U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 17069630896535699015U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 3308240081138623373U;
            aOrbiterF = RotL64((aOrbiterF * 10449509484417835159U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 17615529807112933619U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 11782807146851563541U;
            aOrbiterD = RotL64((aOrbiterD * 12992075832343669221U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 14401645829607611983U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 6736397344219993532U;
            aOrbiterG = RotL64((aOrbiterG * 1667287547938175641U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 6446974060524700550U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 7840991992443308254U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6891023544882740107U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 10362169906019794305U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 4503700997923168911U;
            aOrbiterK = RotL64((aOrbiterK * 15066164494038852559U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 13492041134973259041U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 14337899277551397976U;
            aOrbiterH = RotL64((aOrbiterH * 5966740718899290915U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 13693100781608180748U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 16177545026405910052U;
            aOrbiterJ = RotL64((aOrbiterJ * 6019231448444020563U), 5U);
            //
            aIngress = RotL64(aOrbiterD, 51U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 23U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + RotL64(aOrbiterK, 14U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aScatter, 43U) + aOrbiterH) + RotL64(aOrbiterK, 41U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterF, 57U)) + aOrbiterI) + aPhaseCWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 4U) + RotL64(aOrbiterG, 36U)) + aOrbiterE);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 13U) + aOrbiterB) + RotL64(aOrbiterF, 53U)) + aPhaseCWandererUpdateSaltD[((aIndex + 6U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 53U) + aOrbiterD) + RotL64(aOrbiterB, 23U));
            aWandererE = aWandererE + ((RotL64(aCross, 20U) + RotL64(aOrbiterG, 27U)) + aOrbiterF);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterG, 11U));
            aWandererI = aWandererI + (((RotL64(aIngress, 35U) + aOrbiterH) + RotL64(aOrbiterF, 46U)) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 60U));
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 24U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 15591U)) & S_BLOCK1], 3U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 10908U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15888U)) & W_KEY1], 4U) ^ RotL64(aKeyRowReadB[((aIndex + 11577U)) & W_KEY1], 21U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 4U) + RotL64(aCross, 35U)) ^ (RotL64(aPrevious, 51U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (aWandererC + RotL64(aCross, 37U)) + 8402620908307642697U;
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 56U)) + RotL64(aCarry, 37U)) + 11347672014525086047U;
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 29U)) + RotL64(aCarry, 13U)) + 2816462912503401876U;
            aOrbiterD = (aWandererG + RotL64(aScatter, 23U)) + 6940159795470696093U;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 51U)) + RotL64(aCarry, 51U)) + 9134692490095883851U;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 5U)) + 4999455497008026526U;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 47U)) + 5992451460350651332U) + aPhaseCOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aIngress, 12U)) + 3417087346651371924U;
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 19U)) + 3612773820086198270U) + aPhaseCOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 463398077083428570U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 11249391303705089012U;
            aOrbiterJ = RotL64((aOrbiterJ * 7106735772303292983U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 17027535139825739501U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 568131384979596481U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5683451044852895957U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 4793712537158004047U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 10415170179135963622U;
            aOrbiterC = RotL64((aOrbiterC * 13729564030210361415U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 2391473979460065630U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 4240058362680064261U;
            aOrbiterG = RotL64((aOrbiterG * 12375884373396400889U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 9963957011090031698U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 3325305624067445525U;
            aOrbiterA = RotL64((aOrbiterA * 3128542681461806309U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 2094945647665114693U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 10703615640774042674U;
            aOrbiterB = RotL64((aOrbiterB * 12641986098450423751U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 3768738815518590289U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 15021301790376706827U;
            aOrbiterD = RotL64((aOrbiterD * 14445850924223550339U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 10571246886181608316U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 5130325144599151793U;
            aOrbiterH = RotL64((aOrbiterH * 3185251943547657467U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 8617523421720966373U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 16574597770835250074U;
            aOrbiterE = RotL64((aOrbiterE * 1759209403428937799U), 3U);
            //
            aIngress = RotL64(aOrbiterC, 5U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterE, 10U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterC, 58U)) + aOrbiterD);
            aWandererH = aWandererH + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 21U)) + aOrbiterH);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 6U) + RotL64(aOrbiterH, 43U)) + aOrbiterJ);
            aWandererD = aWandererD + ((RotL64(aIngress, 27U) + aOrbiterD) + RotL64(aOrbiterE, 39U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterB, 5U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 53U) + aOrbiterA) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 13U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 36U) + aOrbiterF) + RotL64(aOrbiterD, 27U)) + aPhaseCWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 43U) + aOrbiterB) + RotL64(aOrbiterJ, 11U)) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterG, 52U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererC, 28U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 16724U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20184U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 22300U)) & W_KEY1], 35U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 17141U)) & W_KEY1], 48U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 29U) ^ RotL64(aIngress, 13U)) + (RotL64(aCarry, 47U) ^ RotL64(aPrevious, 60U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (aWandererG + RotL64(aPrevious, 19U)) + 8375305456876489425U;
            aOrbiterA = ((aWandererC + RotL64(aCross, 14U)) + 16193562952772453047U) + aPhaseCOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aIngress, 23U)) + 18088652458594816223U;
            aOrbiterH = (aWandererH + RotL64(aScatter, 47U)) + 767344788620249944U;
            aOrbiterB = (((aWandererI + RotL64(aIngress, 41U)) + RotL64(aCarry, 47U)) + 7705194930396368752U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 39U)) + 3829736891311272834U;
            aOrbiterE = (aWandererD + RotL64(aPrevious, 30U)) + 9881681671347640061U;
            aOrbiterK = ((aWandererK + RotL64(aCross, 35U)) + RotL64(aCarry, 5U)) + 1721196560190164264U;
            aOrbiterC = (aWandererB + RotL64(aScatter, 57U)) + 3002652618388454213U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 9811621464004005202U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 5652598941069986530U;
            aOrbiterF = RotL64((aOrbiterF * 4797973356708091621U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 6250499348327316328U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 16025054277615264530U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16446892258704281903U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 13800298546867243172U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 12256104592865905782U;
            aOrbiterH = RotL64((aOrbiterH * 16983140179497142713U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 17817225416918329229U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 17738671327352776217U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 393488251327705063U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 6816031224188400541U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 16989563985059237014U;
            aOrbiterB = RotL64((aOrbiterB * 8677884225771717797U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 16891524847268207549U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 1833508573940405571U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9709196587703979539U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 12729999421507068973U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 6839758643521968957U;
            aOrbiterE = RotL64((aOrbiterE * 16350557395881283975U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 8524167125469267428U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 14741523560290472617U;
            aOrbiterK = RotL64((aOrbiterK * 4367850822282205897U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 10983798459868424892U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 5649250846622078964U;
            aOrbiterC = RotL64((aOrbiterC * 7149612714806023987U), 53U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 27U);
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + (RotL64(aOrbiterG, 37U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterB, 24U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterG, 53U)) + aOrbiterK) + aPhaseCWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterC, 39U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterF, 24U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 57U)) + aOrbiterG) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 58U) + aOrbiterE) + RotL64(aOrbiterG, 43U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterE, 29U)) + aOrbiterK) + RotL64(aCarry, 19U)) + aPhaseCWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 27U) + aOrbiterF) + RotL64(aOrbiterC, 3U));
            aWandererG = aWandererG + ((RotL64(aIngress, 11U) + aOrbiterK) + RotL64(aOrbiterD, 47U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 6U) + aOrbiterH) + RotL64(aOrbiterG, 12U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 44U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32413U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((aIndex + 28696U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25605U)) & S_BLOCK1], 41U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28670U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aIngress, 50U)) ^ (RotL64(aPrevious, 37U) ^ RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 47U)) + RotL64(aCarry, 39U)) + 11039986441331892533U;
            aOrbiterE = (aWandererI + RotL64(aIngress, 53U)) + 6256024955965426119U;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 57U)) + 9857443189988995666U) + aPhaseCOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aCross, 18U)) + 11900944813380998208U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 5U)) + RotL64(aCarry, 27U)) + 8422577734978875541U;
            aOrbiterF = (aWandererF + RotL64(aPrevious, 37U)) + 3100835100713928724U;
            aOrbiterH = ((aWandererA + RotL64(aCross, 29U)) + RotL64(aCarry, 19U)) + 11871553509810206993U;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 24U)) + 17614749493763417027U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = (aWandererB + RotL64(aScatter, 11U)) + 3638372131856199916U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 6582275259281025770U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 17016882418498941958U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4269869255230867823U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 1747214688658984715U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 9356088987044015278U;
            aOrbiterK = RotL64((aOrbiterK * 16221733545319753695U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 4056238112133473456U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 16013150119949532998U;
            aOrbiterH = RotL64((aOrbiterH * 12913648646318115315U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 16076621211111834889U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 9940824359571581765U;
            aOrbiterC = RotL64((aOrbiterC * 11624767861336495331U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 15624084004784515753U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 7630989544834680335U;
            aOrbiterG = RotL64((aOrbiterG * 12261063237156822067U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 18003586430673313786U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 1654118743290334161U;
            aOrbiterF = RotL64((aOrbiterF * 1153250137357176071U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 3254189676528343910U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 15629083361573065165U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17024833368570949107U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 10056859810555674806U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 15976683222786846254U;
            aOrbiterI = RotL64((aOrbiterI * 2801754232182942635U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 11872378594829637933U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 7633773773528713489U;
            aOrbiterE = RotL64((aOrbiterE * 8218288492011593353U), 19U);
            //
            aIngress = RotL64(aOrbiterI, 35U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 50U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + RotL64(aOrbiterC, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aPrevious, 53U) + aOrbiterH) + RotL64(aOrbiterK, 51U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 21U)) + aOrbiterF) + aPhaseCWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 24U) + RotL64(aOrbiterA, 14U)) + aOrbiterC);
            aWandererI = aWandererI ^ ((RotL64(aCross, 41U) + aOrbiterI) + RotL64(aOrbiterA, 39U));
            aWandererF = aWandererF + (((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 43U)) + aOrbiterI) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterC, 5U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aIngress, 58U) + aOrbiterH) + RotL64(aOrbiterE, 30U)) + aPhaseCWandererUpdateSaltA[((aIndex + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterK, 57U));
            aWandererE = aWandererE + (((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 35U)) + aOrbiterD) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 10U));
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 44U);
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0;
    std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;
    std::uint64_t aOrbiterK = 0;

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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 7771U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneC[((aIndex + 5519U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2829U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneA[((aIndex + 7547U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCross, 39U)) + (RotL64(aCarry, 51U) ^ RotL64(aPrevious, 4U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = (((aWandererH + RotL64(aIngress, 37U)) + RotL64(aCarry, 19U)) + 17454559218352016650U) + aPhaseDOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = (((aWandererC + RotL64(aScatter, 11U)) + RotL64(aCarry, 3U)) + 8005709669325164803U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aCross, 3U)) + 13393741948412816357U;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 24U)) + RotL64(aCarry, 41U)) + 3665865624348875553U;
            aOrbiterH = (aWandererD + RotL64(aScatter, 57U)) + 8334142570031883436U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 17226066128706139657U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 3319093033121522613U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17961784341097933029U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6657535603401588798U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 5469746182326331147U;
            aOrbiterI = RotL64((aOrbiterI * 11315450342347794329U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 17846791786050221418U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 15939541003714896288U;
            aOrbiterF = RotL64((aOrbiterF * 1400351482213119809U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 12076763190461077406U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 3594038213596405284U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10244002692575821495U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 8301291631324464622U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 8460406137668390582U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9117147929757711595U), 35U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 56U);
            aIngress = aIngress + (RotL64(aOrbiterK, 41U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 19U) + aOrbiterA) + RotL64(aOrbiterH, 21U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 60U) + aOrbiterA) + RotL64(aOrbiterI, 13U)) + RotL64(aCarry, 5U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 51U) + aOrbiterK) + RotL64(aOrbiterF, 34U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 27U) + RotL64(aOrbiterF, 43U)) + aOrbiterI) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 41U) + aOrbiterH) + RotL64(aOrbiterI, 51U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + RotL64(aWandererC, 27U);
            aCarry = aCarry + RotL64(aIngress, 38U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 12317U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((aIndex + 14187U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12801U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneB[((aIndex + 11690U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 18U) + RotL64(aCarry, 35U)) ^ (RotL64(aIngress, 53U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (aWandererC + RotL64(aIngress, 44U)) + 4980738603982643969U;
            aOrbiterK = (((aWandererA + RotL64(aScatter, 19U)) + RotL64(aCarry, 11U)) + 17660278413018470020U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 53U)) + RotL64(aCarry, 23U)) + 17598114429859543466U;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 27U)) + RotL64(aCarry, 57U)) + 10993929335279994739U;
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 3U)) + 17967203122976322481U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 1872290205549034384U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 16607778671782810797U;
            aOrbiterF = RotL64((aOrbiterF * 340054507611349681U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 4895226930754394376U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 14960359005982301383U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8546231310054433721U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 9921642352377700630U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 893281964367208693U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2345509157333444217U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 8232519988397858732U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 4433022122758913407U;
            aOrbiterK = RotL64((aOrbiterK * 834240393225479419U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 12689609831247168353U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 404535388957472176U;
            aOrbiterE = RotL64((aOrbiterE * 14534020545479806593U), 19U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 29U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterK, 13U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterJ, 38U)) + RotL64(aCarry, 35U)) + aPhaseDWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterE, 27U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterE, 47U)) + aOrbiterG) + RotL64(aCarry, 21U)) + aPhaseDWandererUpdateSaltE[((aIndex + 22U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 58U) + RotL64(aOrbiterK, 57U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 28U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 21096U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19257U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19938U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((aIndex + 17348U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCross, 12U)) + (RotL64(aIngress, 27U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = (aWandererH + RotL64(aIngress, 47U)) + 12980104182836602177U;
            aOrbiterI = (aWandererF + RotL64(aCross, 27U)) + 3172622203188863995U;
            aOrbiterK = (((aWandererK + RotL64(aPrevious, 19U)) + RotL64(aCarry, 13U)) + 1170974132219980203U) + aPhaseDOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = (((aWandererI + RotL64(aScatter, 57U)) + RotL64(aCarry, 51U)) + 6035201940965047490U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 36U)) + RotL64(aCarry, 27U)) + 18033907118424996722U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 14604813424800580304U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 13720232492851066035U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8927246214721284759U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 3902659710585257448U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 8331560652661619868U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11418103770615560205U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 4485014147538689794U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 168202636924512424U;
            aOrbiterE = RotL64((aOrbiterE * 13711020666131492091U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 16227825670092707848U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 4792781933944671365U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15859849676231455283U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 12636865372722601282U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 18198291399585556632U;
            aOrbiterJ = RotL64((aOrbiterJ * 18155803890313399795U), 5U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterE, 43U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + RotL64(aOrbiterI, 56U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 23U) + aOrbiterJ) + RotL64(aOrbiterG, 3U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 12U) + RotL64(aOrbiterI, 58U)) + aOrbiterE) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 47U)) + aOrbiterK);
            aWandererF = aWandererF + ((((RotL64(aCross, 37U) + aOrbiterJ) + RotL64(aOrbiterK, 37U)) + RotL64(aCarry, 23U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 47U) + aOrbiterE) + RotL64(aOrbiterJ, 13U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 48U));
            aCarry = aCarry + RotL64(aWandererK, 39U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 26236U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28509U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25543U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 25809U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 13U) ^ RotL64(aCross, 41U)) + (RotL64(aCarry, 54U) ^ RotL64(aIngress, 29U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = ((aWandererD + RotL64(aCross, 3U)) + RotL64(aCarry, 3U)) + 8685374557928800912U;
            aOrbiterK = (((aWandererG + RotL64(aScatter, 11U)) + RotL64(aCarry, 29U)) + 3482312691892161229U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aPrevious, 53U)) + 6948130297389161165U;
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 28U)) + RotL64(aCarry, 47U)) + 5506385663788942690U;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 41U)) + 17859982009307397161U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 9178488809207094043U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 1835479501226057169U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5671861318767342087U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 5368101733632614939U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 9050459666576835422U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10351719549990259551U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 9042186993119635078U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 17528342580198295025U;
            aOrbiterD = RotL64((aOrbiterD * 14316671546614386775U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 6495418332558436882U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 8834495762667327342U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10783141541937645995U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 4364314196965690905U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 6357485231062120459U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 289429584586504995U), 23U);
            //
            aIngress = RotL64(aOrbiterD, 57U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterH, 46U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterD, 11U));
            aWandererG = aWandererG + (((RotL64(aCross, 57U) + RotL64(aOrbiterH, 35U)) + aOrbiterK) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 12U) + aOrbiterH) + RotL64(aOrbiterD, 22U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 29U) + aOrbiterD) + RotL64(aOrbiterF, 43U)) + RotL64(aCarry, 23U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterF, 53U)) + aOrbiterK) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + RotL64(aWandererD, 30U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 2368U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneC[((aIndex + 3683U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 3402U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 5048U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 47U) ^ RotL64(aPrevious, 22U)) ^ (RotL64(aIngress, 35U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = (((aWandererI + RotL64(aScatter, 39U)) + RotL64(aCarry, 23U)) + 16651241552253078315U) + aPhaseEOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aCross, 23U)) + RotL64(aCarry, 35U)) + 4558144676982478003U;
            aOrbiterI = (aWandererK + RotL64(aIngress, 48U)) + 8814884320080367550U;
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 3U)) + 16011579668555672117U;
            aOrbiterA = (aWandererH + RotL64(aIngress, 57U)) + 4738918668759862438U;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 29U)) + RotL64(aCarry, 51U)) + 12526083125540985108U;
            aOrbiterK = ((aWandererG + RotL64(aScatter, 13U)) + 8048723561746000552U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 1082218464034639039U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 8432043246965946816U;
            aOrbiterI = RotL64((aOrbiterI * 7801965585991025451U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 9982080524048636852U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 6720069955755215919U;
            aOrbiterA = RotL64((aOrbiterA * 1025046364205332059U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 1019035028070247757U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 7360619079463870467U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6623074813047915863U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 10893918488381348474U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 1390297670907738019U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11909657437658597735U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 12512200589031203480U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 14741471280748399540U;
            aOrbiterG = RotL64((aOrbiterG * 3012135242889901095U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 8543897248359826770U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 8545972622733791272U;
            aOrbiterF = RotL64((aOrbiterF * 11793879362775346821U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 7049384618581928664U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 14730773807906925408U;
            aOrbiterJ = RotL64((aOrbiterJ * 10711566871536755073U), 51U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 21U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + (RotL64(aOrbiterI, 39U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterF, 60U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 53U) + RotL64(aOrbiterC, 21U)) + aOrbiterI) + RotL64(aCarry, 37U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterJ, 57U)) + aPhaseEWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 6U) + aOrbiterG) + RotL64(aOrbiterC, 13U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 47U) + aOrbiterK) + RotL64(aOrbiterJ, 27U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 21U) + aOrbiterF) + RotL64(aOrbiterK, 4U)) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 37U)) + aOrbiterA);
            aWandererI = aWandererI + (((RotL64(aCross, 41U) + aOrbiterI) + RotL64(aOrbiterG, 47U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 24U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 51U);
            aCarry = aCarry + RotL64(aIngress, 56U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8767U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 14076U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 13726U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((aIndex + 14594U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 43U)) + (RotL64(aCarry, 57U) ^ RotL64(aIngress, 24U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (((aWandererH + RotL64(aIngress, 35U)) + RotL64(aCarry, 27U)) + 8101351470141807662U) + aPhaseEOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 53U)) + RotL64(aCarry, 53U)) + 6965474099521076705U;
            aOrbiterH = (aWandererB + RotL64(aCross, 13U)) + 6803828268885684784U;
            aOrbiterF = (aWandererK + RotL64(aScatter, 19U)) + 13454235922950972488U;
            aOrbiterI = ((aWandererI + RotL64(aCross, 29U)) + RotL64(aCarry, 13U)) + 11678091885751244777U;
            aOrbiterK = ((aWandererG + RotL64(aScatter, 41U)) + 5307134544628507141U) + aPhaseEOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = (aWandererD + RotL64(aIngress, 6U)) + 4873703518950429353U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 8542156221858586039U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 3993726182905296513U;
            aOrbiterH = RotL64((aOrbiterH * 11331376012938127609U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 12113047622035464386U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 1944244448665721151U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7010050836758762003U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 12914188029425467576U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 2486762763475327024U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12319769994433811617U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 14580191602982245481U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 12093414832400135066U;
            aOrbiterG = RotL64((aOrbiterG * 12720286833215690663U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 13623906997320021065U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 9977356009806428696U;
            aOrbiterI = RotL64((aOrbiterI * 2005536391712733499U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 3694954095397810851U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 11453812627797091638U;
            aOrbiterK = RotL64((aOrbiterK * 13730420725113907161U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 542311345544726351U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 3024285045990499484U;
            aOrbiterD = RotL64((aOrbiterD * 5153745952148205645U), 5U);
            //
            aIngress = RotL64(aOrbiterJ, 47U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + RotL64(aOrbiterG, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 35U)) + aOrbiterK);
            aWandererG = aWandererG + (((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 54U) + RotL64(aOrbiterG, 19U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterJ, 5U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 21U) + aOrbiterI) + RotL64(aOrbiterG, 13U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterH, 42U)) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 3U) + aOrbiterK) + RotL64(aOrbiterJ, 29U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 38U));
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 19816U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneA[((aIndex + 23257U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 23908U)) & S_BLOCK1], 24U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 17347U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 13U) ^ RotL64(aIngress, 57U)) + (RotL64(aPrevious, 43U) + RotL64(aCross, 30U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 41U)) + RotL64(aCarry, 23U)) + 11700815697312060726U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 3U)) + 11808423452327465441U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aScatter, 48U)) + 8670503858631730886U;
            aOrbiterA = (aWandererB + RotL64(aCross, 35U)) + 2400061067991988544U;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 29U)) + RotL64(aCarry, 37U)) + 16163118178366229686U;
            aOrbiterB = ((aWandererG + RotL64(aCross, 23U)) + RotL64(aCarry, 57U)) + 3280178595904941068U;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 13U)) + 3298683600817047727U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 16321624053445183574U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 6730229877611375225U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2022290495153519279U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 10162830636713641322U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 15646771327759599256U;
            aOrbiterF = RotL64((aOrbiterF * 15333053762177144775U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 14841751262270544102U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 9545541117228834895U;
            aOrbiterI = RotL64((aOrbiterI * 11529769874752969377U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 14676615635857599982U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 1231768638470558855U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2716808508509014677U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 1945905595345404833U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 1406171421638586846U;
            aOrbiterC = RotL64((aOrbiterC * 4577864352425476233U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 1970292335806697198U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 12309719390375013297U;
            aOrbiterB = RotL64((aOrbiterB * 16540660957923687327U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 5352135521358954576U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 15465675376193501658U;
            aOrbiterD = RotL64((aOrbiterD * 16385761112921041387U), 13U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterD, 19U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aCross, 51U) + RotL64(aOrbiterI, 37U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 5U)) + aOrbiterA);
            aWandererF = aWandererF + ((RotL64(aPrevious, 27U) + aOrbiterI) + RotL64(aOrbiterA, 50U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 41U) + aOrbiterD) + RotL64(aOrbiterB, 29U)) + aPhaseEWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 21U) + aOrbiterA) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterH, 21U)) + aOrbiterD);
            aWandererE = aWandererE + ((((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 35U)) + aPhaseEWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + (RotL64(aWandererG, 46U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 24773U)) & S_BLOCK1], 40U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25787U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24613U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 28547U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCross, 20U)) ^ (RotL64(aPrevious, 47U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (aWandererF + RotL64(aCross, 23U)) + 8506388683755208267U;
            aOrbiterH = ((aWandererH + RotL64(aIngress, 3U)) + RotL64(aCarry, 39U)) + 2179323259055019735U;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 37U)) + 3345902531140983016U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 47U)) + RotL64(aCarry, 3U)) + 17456139311481306584U;
            aOrbiterA = (aWandererE + RotL64(aIngress, 54U)) + 14587864088462311164U;
            aOrbiterJ = (aWandererD + RotL64(aScatter, 13U)) + 13178947246650647057U;
            aOrbiterG = (((aWandererA + RotL64(aCross, 29U)) + RotL64(aCarry, 27U)) + 12866578138946916962U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 13098524333655118173U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 15451329483787541982U;
            aOrbiterI = RotL64((aOrbiterI * 13580376920467431451U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 9494299579678389385U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 15581954810375490643U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13670002280188424825U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 4487042505730624892U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 2774455928791636186U;
            aOrbiterH = RotL64((aOrbiterH * 15847933919136777451U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 12435319582397755819U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 10077180055177766823U;
            aOrbiterA = RotL64((aOrbiterA * 3924363471701748703U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 10391963896910956455U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 6149237416725301794U;
            aOrbiterD = RotL64((aOrbiterD * 10115917698918612823U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 15673402771629639978U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 14729117178956592426U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9070464269215820531U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 14492001279368870240U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 6278248084483259952U;
            aOrbiterG = RotL64((aOrbiterG * 16731228350971263873U), 5U);
            //
            aIngress = RotL64(aOrbiterH, 58U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + RotL64(aOrbiterJ, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 3U) + aOrbiterB) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 22U) + RotL64(aOrbiterD, 43U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 47U) + RotL64(aOrbiterD, 58U)) + aOrbiterG) + aPhaseEWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 29U) + aOrbiterB) + RotL64(aOrbiterA, 37U));
            aWandererA = aWandererA + (((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 21U)) + aOrbiterI) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 13U)) + aOrbiterH);
            aWandererB = aWandererB + ((RotL64(aCross, 53U) + RotL64(aOrbiterA, 5U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 30U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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

void TwistExpander_Fencing_Arx::Twist_D(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5606U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6965U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5401U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 1738U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCross, 11U)) + (RotL64(aCarry, 52U) + RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 37U)) + 1557680213571812384U;
            aOrbiterA = (aWandererF + RotL64(aPrevious, 3U)) + 7387349725778021121U;
            aOrbiterC = (((aWandererG + RotL64(aScatter, 57U)) + RotL64(aCarry, 35U)) + 15379264067601586976U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = (((aWandererC + RotL64(aCross, 26U)) + RotL64(aCarry, 23U)) + 3730195724576043708U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aIngress, 47U)) + RotL64(aCarry, 5U)) + 9637070085323827066U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 1170865717363676184U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 2750833653175252030U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1937822982381882775U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 15118992811225568305U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 4974092922102988451U;
            aOrbiterJ = RotL64((aOrbiterJ * 10575977398702460975U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 10625719096296719514U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 855167122475471865U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7441090331293158773U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 11322911068958340262U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 4334591909425429835U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10059025861172038183U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 14263701737208936392U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 678723206735649084U;
            aOrbiterG = RotL64((aOrbiterG * 10823239851733632227U), 47U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterG, 41U);
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 48U) + RotL64(aOrbiterB, 51U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((RotL64(aCross, 23U) + RotL64(aOrbiterG, 43U)) + aOrbiterC) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 11U) + aOrbiterG) + RotL64(aOrbiterA, 11U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 19U)) + aOrbiterJ) + RotL64(aCarry, 3U)) + aPhaseFWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 35U) + aOrbiterG) + RotL64(aOrbiterJ, 30U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 37U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 15387U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15418U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10862U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneB[((aIndex + 14857U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 34U) + RotL64(aCarry, 51U)) + (RotL64(aIngress, 19U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = (aWandererC + RotL64(aScatter, 3U)) + 2786079456995203065U;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 43U)) + RotL64(aCarry, 57U)) + 7237256119153857253U;
            aOrbiterH = (((aWandererK + RotL64(aPrevious, 19U)) + RotL64(aCarry, 5U)) + 9310834010563647604U) + aPhaseFOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = (((aWandererD + RotL64(aCross, 30U)) + RotL64(aCarry, 27U)) + 17361734905706517877U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aScatter, 51U)) + 15837111231884647451U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 18065431964418026445U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 3029123922999952652U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16309219658285890145U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 5166926595573507837U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 1918425684273807598U;
            aOrbiterE = RotL64((aOrbiterE * 16616641579714896719U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 4724551751012661440U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 1818014487579644390U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14904092108647864911U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 6670090372241084216U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 8485757110007268693U;
            aOrbiterI = RotL64((aOrbiterI * 11876760095108618363U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 4928130251509514742U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 2528788422725346792U;
            aOrbiterA = RotL64((aOrbiterA * 1855982047967756661U), 3U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 29U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 18U));
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 37U) + aOrbiterI) + RotL64(aOrbiterB, 53U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterH, 5U)) + aOrbiterA) + RotL64(aCarry, 41U)) + aPhaseFWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 50U) + aOrbiterE) + RotL64(aOrbiterH, 43U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterE, 14U)) + aOrbiterB) + RotL64(aCarry, 53U)) + aPhaseFWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 35U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 60U));
            aCarry = aCarry + RotL64(aWandererA, 13U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 21515U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 21358U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20046U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((aIndex + 24197U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCross, 41U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCarry, 28U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (((aWandererI + RotL64(aPrevious, 13U)) + RotL64(aCarry, 29U)) + 6973892330986118220U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = (((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 57U)) + 9886813896272094864U) + aPhaseFOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = (aWandererA + RotL64(aIngress, 56U)) + 10996306582517553173U;
            aOrbiterJ = (aWandererE + RotL64(aCross, 27U)) + 8490648283899856223U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 43U)) + RotL64(aCarry, 43U)) + 105141713530704655U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 3114337422810562588U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 980857684690886131U;
            aOrbiterH = RotL64((aOrbiterH * 17407927633910728721U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 6562042345807072665U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 15665371138706353619U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8086237578564620623U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 18113013571374375028U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 17405346422601997299U;
            aOrbiterB = RotL64((aOrbiterB * 11162604605443005253U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 5130876096426182506U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 1813821672299154629U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15478100342425611875U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 15793814882743306728U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 13925299440495476399U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12049601510660117401U), 29U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterA, 27U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 14U));
            aIngress = aIngress + RotL64(aOrbiterJ, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterK, 5U));
            aWandererF = aWandererF + ((((RotL64(aCross, 56U) + aOrbiterH) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 11U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterA, 37U)) + aOrbiterH);
            aWandererK = aWandererK + (((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 41U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterB, 48U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + RotL64(aWandererI, 5U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 27620U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30063U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25883U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((aIndex + 29884U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCross, 3U)) + (RotL64(aCarry, 51U) ^ RotL64(aPrevious, 34U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 47U)) + 2974056819475622600U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = (((aWandererK + RotL64(aScatter, 11U)) + RotL64(aCarry, 39U)) + 7345051759236356098U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = ((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 53U)) + 12738468816846628882U;
            aOrbiterI = ((aWandererG + RotL64(aCross, 57U)) + RotL64(aCarry, 27U)) + 7694520596043297922U;
            aOrbiterF = (aWandererF + RotL64(aPrevious, 20U)) + 5530753590015084774U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 3776309161718383105U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 784780304358106404U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1503119308251871519U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 8999942326995036509U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 5194986506064092779U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15070787038006135963U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 7920040007459652762U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 11311997270710107937U;
            aOrbiterI = RotL64((aOrbiterI * 6227571709361790209U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 5365231114813547251U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 8630110234623825263U;
            aOrbiterH = RotL64((aOrbiterH * 2735881715888325759U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 2358235238039571072U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 18059414891616491807U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17150786106857185467U), 43U);
            //
            aIngress = RotL64(aOrbiterF, 35U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 52U)) + aOrbiterF) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterD, 19U)) + aOrbiterF) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 22U) + RotL64(aOrbiterD, 41U)) + aOrbiterI);
            aWandererK = aWandererK + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterK, 29U)) + aOrbiterI) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 48U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 2556U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 8159U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5436U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneD[((aIndex + 2340U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 52U)) + (RotL64(aCross, 21U) ^ RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (((aWandererA + RotL64(aCross, 41U)) + RotL64(aCarry, 3U)) + 9041099828460168106U) + aPhaseGOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = (((aWandererH + RotL64(aPrevious, 11U)) + RotL64(aCarry, 47U)) + 12883711604096848454U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aIngress, 21U)) + RotL64(aCarry, 29U)) + 17420968786226443079U;
            aOrbiterE = (aWandererI + RotL64(aScatter, 3U)) + 3448213891716125104U;
            aOrbiterG = (aWandererB + RotL64(aPrevious, 52U)) + 11866455977445336560U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 4119356835384495905U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 2186212599698637068U;
            aOrbiterA = RotL64((aOrbiterA * 6756888950976735707U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 6506144898969301620U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 12556800923644051626U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15961043406612913121U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 4075551535185182945U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 17877694808492008749U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 901315308379887473U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 5553428900598223316U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 14362304852277160675U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11415103199856419303U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 9174200302876075831U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 16110739511917638547U;
            aOrbiterG = RotL64((aOrbiterG * 7004356839428657949U), 23U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 51U);
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterF, 57U)) + aOrbiterE);
            aWandererK = aWandererK + (((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 11U)) + aOrbiterF) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterD, 46U)) + aOrbiterE) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 21U) + aOrbiterD) + RotL64(aOrbiterA, 21U)) + RotL64(aCarry, 39U)) + aPhaseGWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterG, 3U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (RotL64(aWandererK, 24U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 11287U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneC[((aIndex + 9188U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15477U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneA[((aIndex + 11583U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCross, 23U)) + (RotL64(aCarry, 40U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 37U)) + RotL64(aCarry, 51U)) + 12029393034357490020U;
            aOrbiterK = (aWandererD + RotL64(aCross, 57U)) + 4526754731580694987U;
            aOrbiterE = (((aWandererA + RotL64(aIngress, 12U)) + RotL64(aCarry, 23U)) + 17060419646421271853U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = ((aWandererH + RotL64(aScatter, 47U)) + 4128488893837059683U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aCross, 27U)) + RotL64(aCarry, 5U)) + 12706894827547160110U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 12506324593645825056U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 12581344490649250025U;
            aOrbiterE = RotL64((aOrbiterE * 16311882267466003291U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 14357032418199130132U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 15341977701796331249U;
            aOrbiterH = RotL64((aOrbiterH * 6332369248718076031U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 7086602307544733241U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 12398300065276832486U;
            aOrbiterD = RotL64((aOrbiterD * 18157408831225635333U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 2499745046076601988U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 7249361592814001829U;
            aOrbiterK = RotL64((aOrbiterK * 14597139848072319685U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 3254456186337366437U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 3472973415969046680U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14583566953969168353U), 11U);
            //
            aIngress = RotL64(aOrbiterH, 53U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 42U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterC, 44U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterE, 21U)) + aOrbiterC) + aPhaseGWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 13U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 44U) + RotL64(aOrbiterH, 35U)) + aOrbiterD);
            aWandererA = aWandererA + ((((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterH, 53U)) + RotL64(aCarry, 47U)) + aPhaseGWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 4U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 27U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 21528U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneD[((aIndex + 23417U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21932U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 20563U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aPrevious, 3U)) ^ (RotL64(aIngress, 54U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = ((aWandererH + RotL64(aCross, 21U)) + 8506388683755208267U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aScatter, 30U)) + RotL64(aCarry, 19U)) + 2179323259055019735U;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 3U)) + RotL64(aCarry, 53U)) + 3345902531140983016U;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 11U)) + RotL64(aCarry, 3U)) + 17456139311481306584U;
            aOrbiterB = ((aWandererG + RotL64(aIngress, 43U)) + 14587864088462311164U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 13178947246650647057U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 12866578138946916962U;
            aOrbiterD = RotL64((aOrbiterD * 121991325166969319U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 13098524333655118173U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 15451329483787541982U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13580376920467431451U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9494299579678389385U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 15581954810375490643U;
            aOrbiterA = RotL64((aOrbiterA * 13670002280188424825U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 4487042505730624892U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 2774455928791636186U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15847933919136777451U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 12435319582397755819U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 10077180055177766823U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3924363471701748703U), 5U);
            //
            aIngress = RotL64(aOrbiterB, 37U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 6U));
            aIngress = aIngress + RotL64(aOrbiterA, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 37U) + aOrbiterJ) + RotL64(aOrbiterA, 56U)) + RotL64(aCarry, 39U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 3U)) + aOrbiterA) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 23U) + RotL64(aOrbiterD, 19U)) + aOrbiterJ) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 11U)) + aOrbiterB);
            aWandererG = aWandererG + (((RotL64(aCross, 4U) + aOrbiterF) + RotL64(aOrbiterJ, 27U)) + aPhaseGWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 46U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 28721U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31381U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31659U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 28557U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 34U)) + (RotL64(aIngress, 53U) ^ RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 29U)) + RotL64(aCarry, 57U)) + 10915618884692072446U;
            aOrbiterJ = (((aWandererK + RotL64(aScatter, 41U)) + RotL64(aCarry, 43U)) + 12634922308499254909U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aIngress, 5U)) + 6533934734564499389U;
            aOrbiterK = ((aWandererI + RotL64(aCross, 13U)) + RotL64(aCarry, 23U)) + 6744203303756105181U;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 56U)) + 13086782386652045658U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 5693840533331397822U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 1803663542535024611U;
            aOrbiterF = RotL64((aOrbiterF * 8511046986156781857U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 3597219300593287708U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 1429753448204448904U;
            aOrbiterG = RotL64((aOrbiterG * 10927459251773273143U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 17229017825587322715U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 1137574712801062932U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3645832160939819415U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 2401991077004083378U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 1332473247826139292U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15029831858261506447U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 11730946340796899885U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 15319163439700390962U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1349242001887975499U), 29U);
            //
            aIngress = RotL64(aOrbiterJ, 37U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 26U));
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aCross, 58U) + RotL64(aOrbiterI, 58U)) + aOrbiterK) + aPhaseGWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 13U)) + aOrbiterI) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 5U)) + aOrbiterF) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterG, 37U)) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 21U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 28U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 4403U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 255U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2316U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneD[((aIndex + 1044U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 11U)) + (RotL64(aIngress, 26U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (((aWandererH + RotL64(aPrevious, 23U)) + RotL64(aCarry, 13U)) + 18255347001097480328U) + aPhaseHOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aScatter, 3U)) + 13679246790311505735U;
            aOrbiterE = ((aWandererI + RotL64(aCross, 43U)) + RotL64(aCarry, 35U)) + 10565839529765027116U;
            aOrbiterK = (aWandererF + RotL64(aIngress, 54U)) + 14327172566224769901U;
            aOrbiterJ = (((aWandererD + RotL64(aScatter, 13U)) + RotL64(aCarry, 47U)) + 16239024612038195174U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 13800012174212131890U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 13900288860157577583U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13177682776510523095U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 4144386119777112740U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 3154558262670631372U;
            aOrbiterD = RotL64((aOrbiterD * 13236911910092437063U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 7456728543137614001U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 11709519851158935384U;
            aOrbiterK = RotL64((aOrbiterK * 7016689518570071587U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 15607438907832240304U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 9276575329661725624U;
            aOrbiterF = RotL64((aOrbiterF * 8879744070762412745U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 6459435969129449226U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 6442382118416542275U;
            aOrbiterJ = RotL64((aOrbiterJ * 2921027306686588233U), 19U);
            //
            aIngress = RotL64(aOrbiterD, 47U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + RotL64(aOrbiterJ, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterE, 47U));
            aWandererD = aWandererD + (((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 57U)) + aOrbiterD) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 22U) + RotL64(aOrbiterJ, 23U)) + aOrbiterF) + aPhaseHWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 10U)) + aOrbiterK) + RotL64(aCarry, 29U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterK, 37U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 5U);
            aCarry = aCarry + RotL64(aIngress, 38U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 15809U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11975U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10189U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8409U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCarry, 57U)) ^ (RotL64(aPrevious, 28U) + RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = ((aWandererH + RotL64(aScatter, 21U)) + RotL64(aCarry, 51U)) + 9888431329297626900U;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 58U)) + 2937735167534624403U;
            aOrbiterE = (((aWandererD + RotL64(aIngress, 11U)) + RotL64(aCarry, 39U)) + 17626022970343789617U) + aPhaseHOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = (((aWandererA + RotL64(aCross, 47U)) + RotL64(aCarry, 23U)) + 5665660859333693743U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aPrevious, 3U)) + 1060537034632076669U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 743777763907175800U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 5744905970181808845U;
            aOrbiterE = RotL64((aOrbiterE * 17426701505806885785U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 3545351394494002180U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 4877547088414106007U;
            aOrbiterH = RotL64((aOrbiterH * 5416792889338547109U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 11669378338379598445U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 2961072441706158212U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2677988507090705371U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 13984945589234919765U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 1433097875470903205U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 451996840039906781U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 716415411025451152U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 8542286150858297810U;
            aOrbiterA = RotL64((aOrbiterA * 9139015340823332449U), 23U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 57U);
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterA, 19U)) + aOrbiterB);
            aWandererH = aWandererH + (((RotL64(aScatter, 18U) + aOrbiterH) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterH, 47U)) + aOrbiterE);
            aWandererC = aWandererC + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 57U)) + aOrbiterC) + RotL64(aCarry, 3U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterH, 28U)) + aPhaseHWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 17196U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneD[((aIndex + 19729U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20555U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19439U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 51U) + RotL64(aCarry, 39U)) ^ (RotL64(aCross, 6U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = ((aWandererD + RotL64(aIngress, 37U)) + 785861751704720606U) + aPhaseHOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 29U)) + RotL64(aCarry, 5U)) + 15968088718435606299U;
            aOrbiterJ = (((aWandererC + RotL64(aPrevious, 57U)) + RotL64(aCarry, 57U)) + 1393976526590347151U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aCross, 6U)) + RotL64(aCarry, 21U)) + 17240750947292745884U;
            aOrbiterE = (aWandererE + RotL64(aScatter, 19U)) + 4921576136163183137U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 3334047873553153032U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 15086509978458408698U;
            aOrbiterJ = RotL64((aOrbiterJ * 2162818176367899893U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 892391205397581998U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 2965686403183767521U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 709160942482770225U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 14632215393655706170U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 15740589515342377322U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15677716942904794913U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 11131164813943086445U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 6988080581278900960U;
            aOrbiterF = RotL64((aOrbiterF * 6412189142344044255U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 16021254613117657178U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 6183615599897921154U;
            aOrbiterE = RotL64((aOrbiterE * 9976411093264211033U), 13U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 29U);
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 46U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterF, 53U)) + aPhaseHWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterH, 12U));
            aWandererD = aWandererD + (((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 37U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterE, 23U)) + aOrbiterF) + aPhaseHWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 50U) + RotL64(aOrbiterA, 37U)) + aOrbiterJ) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 11U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 26504U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneA[((aIndex + 25263U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27414U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneC[((aIndex + 25846U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 19U)) ^ (RotL64(aCross, 52U) + RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererC + RotL64(aIngress, 37U)) + RotL64(aCarry, 47U)) + 6973892330986118220U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 21U)) + 9886813896272094864U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aCross, 47U)) + 10996306582517553173U;
            aOrbiterI = (((aWandererE + RotL64(aScatter, 6U)) + RotL64(aCarry, 29U)) + 8490648283899856223U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = ((aWandererI + RotL64(aCross, 29U)) + RotL64(aCarry, 13U)) + 105141713530704655U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 3114337422810562588U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 980857684690886131U;
            aOrbiterG = RotL64((aOrbiterG * 17407927633910728721U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 6562042345807072665U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 15665371138706353619U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8086237578564620623U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 18113013571374375028U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 17405346422601997299U;
            aOrbiterI = RotL64((aOrbiterI * 11162604605443005253U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 5130876096426182506U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 1813821672299154629U;
            aOrbiterF = RotL64((aOrbiterF * 15478100342425611875U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 15793814882743306728U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 13925299440495476399U;
            aOrbiterC = RotL64((aOrbiterC * 12049601510660117401U), 13U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 35U);
            aIngress = aIngress + (RotL64(aOrbiterG, 56U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 37U) + aOrbiterK) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterF, 58U)) + aPhaseHWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 46U) + RotL64(aOrbiterI, 5U)) + aOrbiterK) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 27U) + aOrbiterC) + RotL64(aOrbiterI, 37U));
            aWandererA = aWandererA + (((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterF, 21U)) + aPhaseHWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
