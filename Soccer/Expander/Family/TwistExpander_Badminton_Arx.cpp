#include "TwistExpander_Badminton_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Badminton_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xC560A5E48545C145ULL + 0xCD675D665B6EB4D4ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xEC4FED5F007DEA01ULL + 0x8861043B1707B9D7ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xD5E38EEF785B1129ULL + 0x81CE8975DDB284F3ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xDF24F412742A515FULL + 0x805FD9A0B3C1FD3AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xAC8866D30CE82D9FULL + 0xA845359EDC2DA468ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x96456EE54E2EB711ULL + 0xDE9D9D221A05496BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xEEAE82A22A16E081ULL + 0xE0129232AAB69936ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xCDFA868DAECDE88DULL + 0xAD5EF59BE0C1EAC9ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x9CFD264EEE2CE32DULL + 0xABC4C622BBF2A4E6ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x814A66606B95F947ULL + 0xCDE57D78E9755306ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xEC8B23BA6CFCFFCDULL + 0xC7243C792AAC31FEULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x996C3C48365F1C13ULL + 0x999EE2D3AE01BEA1ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xE70B61EC58C282C5ULL + 0xF033C66CD504BF45ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xDBFB0C323DB0E125ULL + 0x8A9B6CEC20BEB70DULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xA29F370158656BA1ULL + 0xB859D47E0CF8A4D6ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xEA444DDCA8D44CE3ULL + 0xCDDFD9E312903336ULL);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 2672U)) & S_BLOCK1], 53U) ^ RotL64(pSnow[((aIndex + 369U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 25U)) & S_BLOCK1], 29U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 5379U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCross, 3U)) ^ (RotL64(aCarry, 47U) + RotL64(aIngress, 22U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererI + RotL64(aCross, 35U)) + 10805654776556844351U) + aNonceWordJ;
            aOrbiterK = (aWandererB + RotL64(aPrevious, 5U)) + 582794182442795335U;
            aOrbiterC = ((((aWandererD + RotL64(aIngress, 51U)) + RotL64(aCarry, 27U)) + 2858343650974681068U) + aOrbiterAssignSaltA[((aIndex + 24U)) & S_SALT1]) + aNonceWordA;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 54U)) + 8189584049022064284U) + aNonceWordG;
            aOrbiterA = (aWandererF + RotL64(aCross, 21U)) + 1565100751996962893U;
            aOrbiterE = (aWandererH + RotL64(aScatter, 19U)) + 8062028016947611891U;
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 27U)) + 8280504280578451745U) + aOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (aWandererA + RotL64(aIngress, 47U)) + 11326869194491655350U;
            aOrbiterJ = (aWandererG + RotL64(aCross, 58U)) + 1671695656567777163U;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 13U)) + RotL64(aCarry, 53U)) + 2349843105293943452U;
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 23U)) + RotL64(aCarry, 35U)) + 13015545152052004254U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 16703354404749291869U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 8713231044374305801U;
            aOrbiterC = RotL64((aOrbiterC * 9242480982197688625U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 11118401674497783533U) + aOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 14857556493734710364U;
            aOrbiterE = RotL64((aOrbiterE * 3452566050389715195U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 12953419670951660965U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 12666121730825089017U) ^ aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14049925256934142519U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 11075249639473053423U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 9374217688244187867U;
            aOrbiterF = RotL64((aOrbiterF * 5261156325627117877U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 17608340953291367867U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 13159437499327086340U;
            aOrbiterH = RotL64((aOrbiterH * 4882100944453534805U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 4304700511322366815U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 10172544755256706767U;
            aOrbiterJ = RotL64((aOrbiterJ * 4013006212154771797U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 17340067939877432472U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 14130447570008179105U;
            aOrbiterI = RotL64((aOrbiterI * 8178075071208718915U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 2652532710498072378U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterB) ^ 10384945384238518296U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 17137694272394304045U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 15292159041119433363U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 12103644911645285108U;
            aOrbiterA = RotL64((aOrbiterA * 4565615406415614103U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 16307525158627275744U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 3786908390177579447U;
            aOrbiterB = RotL64((aOrbiterB * 6592585847755318801U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 13595883419843505634U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 10805654776556844351U;
            aOrbiterG = RotL64((aOrbiterG * 10956465099104915639U), 29U);
            //
            aIngress = RotL64(aOrbiterK, 3U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 39U) + aOrbiterG) + RotL64(aOrbiterF, 41U)) + aWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 30U) + aOrbiterH) + RotL64(aOrbiterJ, 27U)) + aWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 6U)) + aOrbiterG) + aNonceWordP);
            aWandererA = aWandererA + (((RotL64(aScatter, 47U) + aOrbiterC) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterA, 53U));
            aWandererB = aWandererB + ((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterD, 23U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterK, 51U)) + aOrbiterD);
            aWandererG = aWandererG + ((RotL64(aPrevious, 24U) + aOrbiterF) + RotL64(aOrbiterC, 37U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterB, 44U)) + aOrbiterH);
            aWandererE = aWandererE + (((RotL64(aIngress, 13U) + aOrbiterD) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 37U) + aOrbiterD) + RotL64(aOrbiterH, 57U)) + aNonceWordC);
            //
            aCarry = aCarry + (RotL64(aWandererA, 18U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 20U));
            aCarry = aCarry + RotL64(aWandererF, 5U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ aNonceWordN;
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8564U)) & S_BLOCK1], 23U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 7626U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(pSnow[((S_BLOCK1 - aIndex + 6497U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8646U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCross, 36U)) ^ (RotL64(aCarry, 19U) + RotL64(aPrevious, 3U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 28U)) + 6342299552323486695U) + aOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = ((aWandererI + RotL64(aScatter, 21U)) + 12692748514781367538U) + aNonceWordO;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 11U)) + 8202639945493229155U) + aOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aCross, 37U)) + 4439975701793231639U;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 13U)) + RotL64(aCarry, 43U)) + 16774235182859553759U;
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 43U)) + 8764155413335405667U;
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 3U)) + RotL64(aCarry, 39U)) + 7167848811974967685U;
            aOrbiterG = (aWandererE + RotL64(aCross, 41U)) + 16768278912125334220U;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 26U)) + 9090838954826296201U;
            aOrbiterI = ((aWandererB + RotL64(aCross, 5U)) + RotL64(aCarry, 23U)) + 7644075729758006298U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 57U)) + 17326182797908071215U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 16158809721888137555U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 8029938783858263694U;
            aOrbiterE = RotL64((aOrbiterE * 12628072435324195483U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 8716553521415553404U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 7012599977009208840U;
            aOrbiterC = RotL64((aOrbiterC * 8775355876188948851U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 13250558696578541499U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 13705957059101025396U;
            aOrbiterF = RotL64((aOrbiterF * 16889495686487056367U), 37U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterK) + 2796775206291902461U) + aOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1]) + aNonceWordA;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 13741676263512390669U;
            aOrbiterJ = RotL64((aOrbiterJ * 10455782033465595947U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 1691908360612389252U) + aNonceWordM;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 4114939415206031540U;
            aOrbiterK = RotL64((aOrbiterK * 2797401802892718297U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 2374911514440738727U) + aOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 12377616933668803091U;
            aOrbiterA = RotL64((aOrbiterA * 2505164835116651215U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 681094033415259645U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 13841322124900463362U;
            aOrbiterH = RotL64((aOrbiterH * 4210414203856902329U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 18082983557580381338U) + aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 15731122225678626778U;
            aOrbiterB = RotL64((aOrbiterB * 7785999919955613789U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 2084336993254383330U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 3600882019682875370U) ^ aNonceWordG;
            aOrbiterG = RotL64((aOrbiterG * 2977569829649654329U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 11436602278656592334U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 5775886971784627864U;
            aOrbiterI = RotL64((aOrbiterI * 6765942246225582787U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 17120308925134658794U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 6342299552323486695U;
            aOrbiterD = RotL64((aOrbiterD * 5788669985396507227U), 41U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterB, 13U);
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 30U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 37U));
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterK, 57U)) + aOrbiterC);
            aWandererI = aWandererI + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 53U)) + aOrbiterJ);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterH, 5U)) + aOrbiterC);
            aWandererG = aWandererG + ((RotL64(aIngress, 23U) + aOrbiterG) + RotL64(aOrbiterH, 35U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 18U) + aOrbiterH) + RotL64(aOrbiterF, 23U)) + aNonceWordB);
            aWandererF = aWandererF + (((RotL64(aScatter, 5U) + aOrbiterH) + RotL64(aOrbiterJ, 42U)) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 51U) + aOrbiterI) + RotL64(aOrbiterJ, 11U)) + aWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 11U) + aOrbiterK) + RotL64(aOrbiterB, 19U)) + RotL64(aCarry, 37U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 60U) + RotL64(aOrbiterJ, 37U)) + aOrbiterE) + aWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 27U) + aOrbiterA) + RotL64(aOrbiterH, 14U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterK, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 44U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 46U));
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15645U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13725U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 13237U)) & S_BLOCK1], 23U) ^ RotL64(pSnow[((aIndex + 13510U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aIngress, 23U)) ^ (RotL64(aPrevious, 36U) + RotL64(aCross, 53U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 47U)) + 9471546960258473684U;
            aOrbiterF = (aWandererK + RotL64(aCross, 43U)) + 18050235435948942244U;
            aOrbiterA = (((aWandererG + RotL64(aScatter, 27U)) + RotL64(aCarry, 23U)) + 3005107102671544641U) + aOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aIngress, 23U)) + 17898396434573801850U) + aNonceWordF;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 37U)) + 15071602525497771648U) + aOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aScatter, 60U)) + 5780119462702672108U;
            aOrbiterH = (aWandererH + RotL64(aIngress, 21U)) + 13301326224151025687U;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 39U)) + RotL64(aCarry, 13U)) + 18129323022260575961U;
            aOrbiterB = (aWandererC + RotL64(aIngress, 13U)) + 1199228670638790709U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 5U)) + RotL64(aCarry, 19U)) + 1839199978088021020U;
            aOrbiterK = (aWandererE + RotL64(aCross, 30U)) + 4999517042246790165U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 8788607633376516299U) + aOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 15143903839930468749U;
            aOrbiterA = RotL64((aOrbiterA * 12735914889325422675U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 16674732686428431869U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 15908873150953195581U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 18049755517524334107U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 11204775359756474667U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 2525984309543939465U) ^ aOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3988529812023791571U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 4566345170476825512U) + aNonceWordO;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 14876612901557406267U;
            aOrbiterD = RotL64((aOrbiterD * 9047956948845135339U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 14926290877038883931U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 12710203178186614846U) ^ aOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14841163494801662515U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 7315094513967387996U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 11050116830482816766U;
            aOrbiterI = RotL64((aOrbiterI * 3702999495721152019U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 4505368486032503953U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 17905748055257551092U) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 14775870175093453197U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 5728886950801376350U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 17998141690182325170U;
            aOrbiterE = RotL64((aOrbiterE * 16008599930125391379U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 4325978018819134558U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 13526905108565989379U;
            aOrbiterH = RotL64((aOrbiterH * 14121321495714166291U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 10597169665474269506U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 7500801022830471869U;
            aOrbiterB = RotL64((aOrbiterB * 3702717219742363777U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 17063616328548689935U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 9471546960258473684U;
            aOrbiterK = RotL64((aOrbiterK * 3029748230803396737U), 3U);
            //
            aIngress = RotL64(aOrbiterH, 3U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 24U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 43U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + RotL64(aOrbiterK, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterF, 19U)) + aOrbiterG) + aWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 21U) + RotL64(aOrbiterH, 13U)) + aOrbiterC);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterC, 53U)) + aOrbiterI);
            aWandererD = aWandererD + ((((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterJ, 21U)) + aNonceWordA) + aWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 56U) + aOrbiterD) + RotL64(aOrbiterJ, 11U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterH, 24U)) + aOrbiterB) + RotL64(aCarry, 13U)) + aNonceWordN);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterE, 27U)) + aOrbiterF);
            aWandererH = aWandererH + (((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterK, 3U)) + RotL64(aCarry, 27U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterE, 43U)) + aOrbiterJ) + aNonceWordE);
            aWandererG = aWandererG + ((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterB, 30U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 4U) + aOrbiterJ) + RotL64(aOrbiterK, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 30U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 54U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordF);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 19384U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((aIndex + 19796U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17332U)) & S_BLOCK1], 23U) ^ RotL64(mSource[((aIndex + 18731U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCross, 41U)) ^ (RotL64(aIngress, 28U) ^ RotL64(aCarry, 57U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 27U)) + RotL64(aCarry, 21U)) + 4634399531433127141U;
            aOrbiterG = (aWandererG + RotL64(aPrevious, 51U)) + 16961792729406903200U;
            aOrbiterE = (aWandererD + RotL64(aIngress, 35U)) + 4105280732301137738U;
            aOrbiterH = (aWandererB + RotL64(aCross, 57U)) + 15692013501147331191U;
            aOrbiterA = (aWandererH + RotL64(aIngress, 48U)) + 1252216715968780587U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 43U)) + RotL64(aCarry, 37U)) + 7958289043012473752U;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 21U)) + RotL64(aCarry, 29U)) + 6611577301818896615U;
            aOrbiterI = (aWandererK + RotL64(aScatter, 29U)) + 8506226754305949140U;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 37U)) + 3648813120449403353U) + aOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aPrevious, 10U)) + 5195245426245535735U;
            aOrbiterK = (((aWandererI + RotL64(aScatter, 5U)) + 542948051600803051U) + aOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1]) + aNonceWordN;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 11974253551208964789U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 10596463592332655367U;
            aOrbiterE = RotL64((aOrbiterE * 10941161258815714641U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 12015129484061440159U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 8254944355710109060U) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 3233697992479357615U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 2754858806943915419U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 5007802002906662779U;
            aOrbiterB = RotL64((aOrbiterB * 15613733948331639723U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 6262190752136523216U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 10528977986487821428U;
            aOrbiterJ = RotL64((aOrbiterJ * 1184258264034585525U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 8511097226098211854U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 12091864735686692582U) ^ aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6128140528141411237U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 4970966265236842566U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 10728884018459718341U;
            aOrbiterC = RotL64((aOrbiterC * 18205183219769602827U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 13760057185629905360U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 6590269178744829056U) ^ aOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14482684769712170123U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 765826377665103262U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 9364759196106579706U;
            aOrbiterK = RotL64((aOrbiterK * 10315111163659289329U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 4629303338428087146U) + aNonceWordI;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 15107221579712215172U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14410837138199304663U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 9407987092859067074U) + aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 13589362515507116096U) ^ aNonceWordF;
            aOrbiterG = RotL64((aOrbiterG * 4544198075069052713U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 2236921538387014026U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 4634399531433127141U;
            aOrbiterH = RotL64((aOrbiterH * 13132011613143486575U), 23U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 21U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 44U));
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aIngress, 37U) + aOrbiterK) + RotL64(aOrbiterF, 10U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterG, 43U)) + aNonceWordH);
            aWandererD = aWandererD + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterF, 19U)) + aOrbiterB) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 6U) + aOrbiterI) + RotL64(aOrbiterD, 3U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 13U)) + aOrbiterH);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 39U) + aOrbiterC) + RotL64(aOrbiterA, 57U));
            aWandererC = aWandererC + (((RotL64(aCross, 41U) + aOrbiterE) + RotL64(aOrbiterA, 21U)) + aWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterJ, 39U)) + aOrbiterH);
            aWandererE = aWandererE + (((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterH, 24U)) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 24U) + RotL64(aOrbiterI, 37U)) + aOrbiterA) + aWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 27U) + RotL64(aOrbiterE, 53U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 60U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 10U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 27158U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((aIndex + 24872U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23956U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 24132U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCarry, 23U)) ^ (RotL64(aCross, 60U) ^ RotL64(aIngress, 41U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererK + RotL64(aIngress, 39U)) + RotL64(aCarry, 47U)) + 12029393034357490020U;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 13U)) + 4526754731580694987U) + aOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aCross, 23U)) + RotL64(aCarry, 51U)) + 17060419646421271853U;
            aOrbiterI = (((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 21U)) + 4128488893837059683U) + aNonceWordH;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 18U)) + 12706894827547160110U) + aNonceWordM;
            aOrbiterK = ((aWandererF + RotL64(aCross, 35U)) + 12506324593645825056U) + aOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aPrevious, 11U)) + 12581344490649250025U;
            aOrbiterF = (aWandererJ + RotL64(aScatter, 43U)) + 14357032418199130132U;
            aOrbiterB = (aWandererG + RotL64(aPrevious, 48U)) + 15341977701796331249U;
            aOrbiterH = (aWandererI + RotL64(aIngress, 29U)) + 7086602307544733241U;
            aOrbiterJ = (aWandererC + RotL64(aCross, 53U)) + 12398300065276832486U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 2499745046076601988U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 7249361592814001829U;
            aOrbiterG = RotL64((aOrbiterG * 14597139848072319685U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 3254456186337366437U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 3472973415969046680U;
            aOrbiterK = RotL64((aOrbiterK * 14583566953969168353U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 7905718972111691591U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterA) ^ 15941413652144021522U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 3473779492962783565U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 10583964125960308762U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 13659925272340853715U) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 16708294803316630743U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 9487054537489454887U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 13287757570441887517U;
            aOrbiterD = RotL64((aOrbiterD * 17351439045329892107U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 15279245465808571942U) + aOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 12424999114621745879U;
            aOrbiterI = RotL64((aOrbiterI * 2274918760256527137U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 13915392738892970475U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 13797668053788805126U;
            aOrbiterA = RotL64((aOrbiterA * 13752161103680525317U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 14344766585550401077U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 13727554194373146727U;
            aOrbiterB = RotL64((aOrbiterB * 17164450431362670223U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 1332966642432651232U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 938583742533681467U;
            aOrbiterJ = RotL64((aOrbiterJ * 13323340043936037549U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 5659239372701978244U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 8501778564909302938U;
            aOrbiterE = RotL64((aOrbiterE * 15629932660749672503U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 1698500835332753591U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 12029393034357490020U;
            aOrbiterC = RotL64((aOrbiterC * 18176507271635640153U), 11U);
            //
            aIngress = RotL64(aOrbiterD, 14U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 43U));
            aIngress = aIngress + (RotL64(aOrbiterG, 39U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + RotL64(aOrbiterH, 54U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterG, 53U)) + aOrbiterD);
            aWandererC = aWandererC + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 5U)) + aOrbiterD) + RotL64(aCarry, 13U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 41U) + aOrbiterA) + RotL64(aOrbiterH, 44U));
            aWandererF = aWandererF + ((RotL64(aCross, 57U) + RotL64(aOrbiterH, 39U)) + aOrbiterF);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 20U) + aOrbiterI) + RotL64(aOrbiterJ, 37U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterE, 11U)) + aWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 37U) + aOrbiterC) + RotL64(aOrbiterH, 47U));
            aWandererA = aWandererA + ((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterA, 50U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterJ, 19U)) + aNonceWordG);
            aWandererH = aWandererH + (((RotL64(aIngress, 53U) + RotL64(aOrbiterB, 23U)) + aOrbiterK) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 22U) + RotL64(aOrbiterG, 21U)) + aOrbiterB) + aWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 20U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 58U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ aNonceWordJ;
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32151U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32607U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28505U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneB[((aIndex + 30687U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 18U) ^ RotL64(aPrevious, 53U)) + (RotL64(aCarry, 5U) + RotL64(aIngress, 35U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (((aWandererJ + RotL64(aScatter, 57U)) + RotL64(aCarry, 19U)) + 898812731947995389U) + aOrbiterAssignSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 50U)) + 8677347622525527167U;
            aOrbiterE = (((aWandererB + RotL64(aIngress, 29U)) + 770321564027567654U) + aOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1]) + aNonceWordK;
            aOrbiterA = (aWandererK + RotL64(aCross, 27U)) + 11020474858081526395U;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 39U)) + 17289793580414993470U;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 47U)) + RotL64(aCarry, 51U)) + 10111912559295118444U;
            aOrbiterH = (aWandererC + RotL64(aScatter, 5U)) + 8083622125544542011U;
            aOrbiterF = (aWandererD + RotL64(aCross, 13U)) + 7149858558922988240U;
            aOrbiterB = (aWandererF + RotL64(aScatter, 11U)) + 5919683821379905699U;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 42U)) + 6860902846079238714U) + aNonceWordH;
            aOrbiterI = (((aWandererI + RotL64(aCross, 35U)) + RotL64(aCarry, 11U)) + 15083517836867542075U) + aNonceWordB;
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 14852868368708376381U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 9860233289028878323U;
            aOrbiterE = RotL64((aOrbiterE * 13418143547952204667U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 772406119079116272U) + aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 7971141501337627589U) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 10168120622976358617U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 8478568022896691911U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 4027604850785607101U;
            aOrbiterK = RotL64((aOrbiterK * 4826627523578901467U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 17199331557841535430U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 7515957656979776361U;
            aOrbiterH = RotL64((aOrbiterH * 5468950152869656599U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 17138249294921502391U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 16236812863923234668U;
            aOrbiterF = RotL64((aOrbiterF * 2925542836624164807U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 16941524155859123682U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 11240343728857342866U;
            aOrbiterB = RotL64((aOrbiterB * 7281012444214294659U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 15163914964139858328U) + aNonceWordL;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 6673576554415729652U;
            aOrbiterD = RotL64((aOrbiterD * 1558880328574736975U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 5399050402101642989U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 11806006719060024615U;
            aOrbiterI = RotL64((aOrbiterI * 15782156615926092159U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 9812148913932011655U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 4737919734590584193U;
            aOrbiterG = RotL64((aOrbiterG * 2739737604370936959U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 3415477403346468057U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 5922725868927615919U;
            aOrbiterJ = RotL64((aOrbiterJ * 12390148483052777871U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 17435294951520465659U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 898812731947995389U) ^ aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17248379279729365007U), 47U);
            //
            aIngress = RotL64(aOrbiterE, 35U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 18U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterA, 23U)) + aNonceWordJ);
            aWandererD = aWandererD + (((RotL64(aPrevious, 4U) + RotL64(aOrbiterB, 5U)) + aOrbiterF) + aNonceWordP);
            aWandererF = aWandererF ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterI, 21U)) + aOrbiterH);
            aWandererK = aWandererK + (((RotL64(aIngress, 53U) + RotL64(aOrbiterC, 29U)) + aOrbiterE) + aWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 26U)) + aOrbiterD);
            aWandererC = aWandererC + (((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterK, 3U)) + RotL64(aCarry, 11U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterG, 51U)) + aNonceWordC);
            aWandererB = aWandererB + ((RotL64(aCross, 13U) + RotL64(aOrbiterA, 39U)) + aOrbiterH);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterH, 37U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 37U) + aOrbiterE) + RotL64(aOrbiterB, 56U)) + RotL64(aCarry, 27U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 24U) + RotL64(aOrbiterC, 53U)) + aOrbiterF) + aWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 26U));
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 44U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordG);
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

void TwistExpander_Badminton_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xAF032E4CC08C8CEBULL + 0xA424307AA2A63A60ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xA9EADA4400509F8DULL + 0xE36F71202AA05A70ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x851C98F5A9B3D2D3ULL + 0xA80E6BF3C1A6C57BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x8BA4DCF6B11B2537ULL + 0xC945CC0D4625D41DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xA9485240521AB6F7ULL + 0x8C15A90094A7B3DDULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xCD0B7F97E148AEFBULL + 0xABA40CF6D4BBFC4BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x936D5C4CBFFFD3F7ULL + 0xF6E1C5B2F2B7CCDAULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xF6DE89EF624ACFE9ULL + 0xE136F2D6B84FEA94ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xBB6C8DCE770080D7ULL + 0xF622317BF96E9E5CULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xE66C81F7E3AEA349ULL + 0xD3EF97BF64BAE70DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xC9C3344FE7CF770DULL + 0x8177D9B78B748708ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x97D8615F2D6FB9F3ULL + 0xEAAAD097FBEF7F1BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xEF8CB9A6DFBB38FFULL + 0xAAEB0CAEB80C8AFDULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x8BE1CA124A567E41ULL + 0xBA4865A8F66616FDULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xC56FFF9A16E021D1ULL + 0xE877D438A6EA61FBULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x9F558C06E1FF6D61ULL + 0x95E1C030B087E7A5ULL);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5372U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2636U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2655U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((aIndex + 511U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aIngress, 11U)) ^ (RotL64(aCross, 23U) ^ RotL64(aPrevious, 56U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (((aWandererH + RotL64(aScatter, 38U)) + RotL64(aCarry, 11U)) + 12380376990224645149U) + aOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = ((aWandererK + RotL64(aIngress, 27U)) + RotL64(aCarry, 53U)) + 18296928500297384014U;
            aOrbiterI = (aWandererI + RotL64(aPrevious, 51U)) + 3550626816361145100U;
            aOrbiterD = ((aWandererA + RotL64(aCross, 57U)) + 2667792936946706027U) + aNonceWordM;
            aOrbiterG = (((aWandererB + RotL64(aPrevious, 42U)) + RotL64(aCarry, 43U)) + 12020969779370926953U) + aOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 19U)) + 737340727886903447U;
            aOrbiterE = (aWandererD + RotL64(aIngress, 11U)) + 1681797651799760502U;
            aOrbiterC = ((aWandererE + RotL64(aCross, 23U)) + 2956186342689489064U) + aNonceWordI;
            aOrbiterA = (aWandererC + RotL64(aScatter, 3U)) + 1876852870402977177U;
            //
            aOrbiterB = (((aOrbiterB + aOrbiterK) + 6433205819353555071U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordL;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 9065076854974222998U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5459675878087242021U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 3254410578766789992U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 2005081975473815576U;
            aOrbiterJ = RotL64((aOrbiterJ * 9947701153722014085U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 15992999234834560419U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 3458344156815120948U;
            aOrbiterC = RotL64((aOrbiterC * 1668460113964608051U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 17069783053664877727U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 1260234710193913099U;
            aOrbiterA = RotL64((aOrbiterA * 4561226779897414381U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 3825186451876061335U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 2905344294992827535U;
            aOrbiterB = RotL64((aOrbiterB * 2469896090698580795U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 18141402347899180617U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 8760129857609925066U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2507999156108123047U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 594052473780678210U) + aNonceWordH;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 13216719212966128379U;
            aOrbiterE = RotL64((aOrbiterE * 10691355329696722303U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 10029948739466316169U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 11912428807431992996U;
            aOrbiterK = RotL64((aOrbiterK * 85016510811938307U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 8735634019801417287U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 12785916159063273545U;
            aOrbiterG = RotL64((aOrbiterG * 1161917531260663357U), 23U);
            //
            aIngress = RotL64(aOrbiterG, 24U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + RotL64(aOrbiterE, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterC, 58U)) + aOrbiterB) + aWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 39U) + aOrbiterG) + RotL64(aOrbiterA, 21U));
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 23U) + RotL64(aOrbiterI, 11U)) + aOrbiterD) + aNonceWordJ) + aWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 34U) + aOrbiterD) + RotL64(aOrbiterA, 43U)) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 19U) + aOrbiterE) + RotL64(aOrbiterK, 35U)) + aNonceWordB);
            aWandererE = aWandererE + ((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterJ, 51U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterB, 28U)) + aOrbiterJ);
            aWandererK = aWandererK + (((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterE, 47U)) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 4U) + aOrbiterK) + RotL64(aOrbiterC, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (RotL64(aWandererJ, 40U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 51U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordB;
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 10986U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8283U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14748U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneB[((aIndex + 13570U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCarry, 48U)) + (RotL64(aPrevious, 19U) + RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 43U)) + 5041131702736607991U;
            aOrbiterG = (aWandererF + RotL64(aScatter, 23U)) + 9295010428212681446U;
            aOrbiterF = (aWandererE + RotL64(aCross, 18U)) + 6235875895358766017U;
            aOrbiterK = (((aWandererI + RotL64(aIngress, 51U)) + RotL64(aCarry, 35U)) + 2622227802531866918U) + aOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aCross, 35U)) + 3888894734834524972U) + aNonceWordB;
            aOrbiterA = (aWandererB + RotL64(aIngress, 39U)) + 241682012014701753U;
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 14U)) + RotL64(aCarry, 3U)) + 15758000422451568079U;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 47U)) + RotL64(aCarry, 19U)) + 2061944548396976912U;
            aOrbiterB = ((aWandererG + RotL64(aCross, 29U)) + 8177144990755754531U) + aOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 554978075608818497U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 250408260560714933U;
            aOrbiterF = RotL64((aOrbiterF * 1295379390497107727U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 8700027645880997552U) + aOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 10026130047465480902U;
            aOrbiterE = RotL64((aOrbiterE * 12417270861933696623U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 9785843014096326696U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 9998582683258411251U;
            aOrbiterJ = RotL64((aOrbiterJ * 7197956237569462269U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 13817734599383455151U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 6647207154174092691U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1578528131687283531U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 4957715980509035719U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 4994885315786213197U;
            aOrbiterB = RotL64((aOrbiterB * 5676683798126497011U), 39U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterB) + 5072908311783966503U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordG;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 5535039946192891515U;
            aOrbiterD = RotL64((aOrbiterD * 2989412783482309753U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 6594577050344146271U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 8750154123258714856U;
            aOrbiterK = RotL64((aOrbiterK * 6942158167127532003U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 3514769314840874873U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 8626045200273524281U;
            aOrbiterA = RotL64((aOrbiterA * 4315441782689789689U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 8524870284841706517U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 1841819423572964209U;
            aOrbiterG = RotL64((aOrbiterG * 9802481758007234681U), 11U);
            //
            aIngress = RotL64(aOrbiterI, 11U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 50U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + RotL64(aOrbiterJ, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aCross, 29U) + RotL64(aOrbiterJ, 47U)) + aOrbiterA) + RotL64(aCarry, 53U)) + aNonceWordI);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 36U) + RotL64(aOrbiterD, 12U)) + aOrbiterF) + aNonceWordP);
            aWandererF = aWandererF + ((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterB, 37U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterA, 41U)) + aWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 23U) + RotL64(aOrbiterF, 23U)) + aOrbiterJ);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 41U) + aOrbiterE) + RotL64(aOrbiterD, 18U)) + aWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 46U) + RotL64(aOrbiterB, 27U)) + aOrbiterA);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 5U) + aOrbiterI) + RotL64(aOrbiterG, 3U));
            aWandererG = aWandererG + (((RotL64(aScatter, 51U) + aOrbiterK) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 38U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 19416U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((aIndex + 19845U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19298U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 17258U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCarry, 11U)) + (RotL64(aIngress, 23U) ^ RotL64(aCross, 54U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererG + RotL64(aScatter, 47U)) + 18144572925667544139U;
            aOrbiterH = (aWandererF + RotL64(aCross, 18U)) + 5659758077574059728U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 11U)) + RotL64(aCarry, 37U)) + 6343330616999166392U;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 51U)) + RotL64(aCarry, 3U)) + 17754639838410839447U;
            aOrbiterA = ((aWandererB + RotL64(aCross, 3U)) + 9451843819849581729U) + aOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 22U)) + 7957854457197462212U;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 41U)) + 1461994799722205010U) + aNonceWordG;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 29U)) + RotL64(aCarry, 57U)) + 18002214276252170177U;
            aOrbiterE = ((aWandererA + RotL64(aCross, 37U)) + 14689869073147027164U) + aOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 3978104368003440293U) + aNonceWordF;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 8512135845221335386U;
            aOrbiterI = RotL64((aOrbiterI * 10506667163729414667U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 1477533446382953439U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 2166717790929947990U;
            aOrbiterG = RotL64((aOrbiterG * 6538884492418324461U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 8082437060686606995U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 4363687722464700362U;
            aOrbiterD = RotL64((aOrbiterD * 7199165810993478887U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 15782763348014924206U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 8572509150015960728U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3340528604891897779U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 12248271773316742521U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 9602078627638561949U;
            aOrbiterA = RotL64((aOrbiterA * 1860631869877427405U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 17244849374768558859U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 1030743048280579012U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10858949914285817051U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 17722342363541914280U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 15667504059789880034U) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 15872269872168533709U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 12645332941998550794U) + aNonceWordM;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 9938135244509986497U;
            aOrbiterC = RotL64((aOrbiterC * 16548185968987392957U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 4024609904162105979U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 6732064218696157303U;
            aOrbiterE = RotL64((aOrbiterE * 3815409766145891393U), 23U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 24U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aScatter, 39U) + RotL64(aOrbiterC, 58U)) + aOrbiterE) + RotL64(aCarry, 29U)) + aWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 56U) + aOrbiterI) + RotL64(aOrbiterE, 13U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterC, 19U)) + aOrbiterJ) + aWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterJ, 51U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterA, 5U)) + RotL64(aCarry, 5U)) + aNonceWordH);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 60U) + aOrbiterA) + RotL64(aOrbiterG, 23U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterE, 37U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 27U) + aOrbiterA) + RotL64(aOrbiterJ, 29U));
            aWandererE = aWandererE + ((RotL64(aIngress, 23U) + RotL64(aOrbiterH, 42U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (RotL64(aWandererA, 34U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + RotL64(aWandererJ, 13U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ aNonceWordL;
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 27578U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneB[((aIndex + 31500U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25237U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneD[((aIndex + 28043U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aIngress, 36U)) ^ (RotL64(aCross, 23U) ^ RotL64(aPrevious, 51U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererF + RotL64(aIngress, 51U)) + RotL64(aCarry, 29U)) + 8367680518550579791U;
            aOrbiterF = (aWandererE + RotL64(aPrevious, 34U)) + 11491674725611181241U;
            aOrbiterC = (aWandererI + RotL64(aScatter, 47U)) + 16673861720782164214U;
            aOrbiterH = (aWandererH + RotL64(aCross, 27U)) + 9786610124108350855U;
            aOrbiterJ = (((aWandererB + RotL64(aIngress, 11U)) + 5745080601557577637U) + aOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 43U)) + 1959402215131684684U) + aOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = (((aWandererA + RotL64(aCross, 39U)) + RotL64(aCarry, 13U)) + 6121650036079196522U) + aNonceWordE;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 3U)) + RotL64(aCarry, 41U)) + 12016309761037342392U;
            aOrbiterD = (aWandererG + RotL64(aScatter, 58U)) + 5986936646177049603U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 1000367700904043468U) + aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 17425288243569101032U;
            aOrbiterC = RotL64((aOrbiterC * 2174614006719048535U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 4856917474950325209U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 16312111093223166419U;
            aOrbiterJ = RotL64((aOrbiterJ * 11046477664487805241U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 456110002032422270U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 11393724374787795662U;
            aOrbiterB = RotL64((aOrbiterB * 1176984359123668389U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 8378176867715697176U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 8086186452345234815U;
            aOrbiterE = RotL64((aOrbiterE * 8450438271765985235U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 8470349167474173245U) + aNonceWordK;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 2528229938740192694U;
            aOrbiterH = RotL64((aOrbiterH * 8717790851266520943U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 13247168811545753141U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 8745293957516815264U;
            aOrbiterA = RotL64((aOrbiterA * 14270617180621072619U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 6165915500564961987U) + aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 12015407798844173213U;
            aOrbiterG = RotL64((aOrbiterG * 3913451986559154153U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 545006684939922156U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 16366753936267185001U;
            aOrbiterD = RotL64((aOrbiterD * 6495185976430013201U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 3097605623436091728U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterB) ^ 15950167830259022926U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 4415538963984293323U), 53U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 34U);
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterF, 21U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterC, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterG, 47U)) + aOrbiterB);
            aWandererG = aWandererG + (((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterF, 58U)) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterJ, 43U)) + aOrbiterC);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterF, 51U)) + RotL64(aCarry, 11U)) + aNonceWordO);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 18U) + aOrbiterC) + RotL64(aOrbiterE, 23U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterJ, 29U)) + aNonceWordA) + aWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 27U) + aOrbiterA) + RotL64(aOrbiterF, 18U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterJ, 5U));
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 44U) + RotL64(aOrbiterG, 11U)) + aOrbiterJ) + aNonceWordI) + aWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 41U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 26U));
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordE);
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

void TwistExpander_Badminton_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterF = 0;
    std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x8E0CF92DDDF7F381ULL + 0xDEE62EA09160A396ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xF25F871CF7A0C7B1ULL + 0xDBEDAB4D3B83F2F2ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xAEF1E23FDF32D47BULL + 0xBD662160FA82AD15ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xA90BCEE0853A84BDULL + 0x84B0312D5DC89203ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xEE1D5F186E865F79ULL + 0x89D9B50529B01236ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x968CE9E2D20F32F3ULL + 0x9AD10D7E7125BE48ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xB47513CCF46B691DULL + 0xC56DC8AE495BA9EAULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x9EC8F1268A049A43ULL + 0xA15C176E47FFB98AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xCB9457D3720FABE5ULL + 0x930C8EF443055A94ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xCAAD943BED169939ULL + 0xFC77905B65D17A0DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xB756D3DB975F5609ULL + 0x963B933A80B11428ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x93460F9C1980BFDBULL + 0x91D95649F77FEF03ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xECC22398FB0A5809ULL + 0xB6885BAE80F38676ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xCE81E2BC420186B9ULL + 0x991D84F859FBA8AEULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xB8323FD4BF5EAE41ULL + 0xC7540F2340C40236ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xB6D7F0AF10D623FBULL + 0x91BD040ED3995247ULL);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 6572U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 187U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7263U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((aIndex + 1550U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 44U) + RotL64(aPrevious, 5U)) ^ (RotL64(aCarry, 57U) ^ RotL64(aIngress, 21U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererB + RotL64(aIngress, 39U)) + RotL64(aCarry, 13U)) + 13333509828310369865U;
            aOrbiterA = (((aWandererG + RotL64(aCross, 19U)) + RotL64(aCarry, 29U)) + 7645352517103840797U) + aOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aScatter, 11U)) + RotL64(aCarry, 53U)) + 5310766306660062655U;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 27U)) + 5165635069832352932U) + aNonceWordL;
            aOrbiterH = ((aWandererA + RotL64(aCross, 50U)) + 15684141764734281849U) + aOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 3327963374225061738U) + aOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 8625811794878848871U;
            aOrbiterD = RotL64((aOrbiterD * 16327750494894125333U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 7598657468430485291U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 2881171216276746485U) ^ aOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3331350584102843605U), 41U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterD) + 10237691227222918101U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordM;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 6419254255884834497U) ^ aOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3816625473642865305U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 4238455444646479956U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 14936613353493061492U;
            aOrbiterA = RotL64((aOrbiterA * 3544216916806292273U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 15324699725208372627U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 9506640480601832011U;
            aOrbiterH = RotL64((aOrbiterH * 12819564111348390227U), 51U);
            //
            aIngress = RotL64(aOrbiterK, 47U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + RotL64(aOrbiterG, 4U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 19U)) + aOrbiterH) + aWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 51U) + RotL64(aOrbiterG, 11U)) + aOrbiterD) + RotL64(aCarry, 3U)) + aNonceWordC);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 30U)) + aOrbiterK);
            aWandererI = aWandererI + ((((RotL64(aCross, 10U) + aOrbiterA) + RotL64(aOrbiterH, 51U)) + RotL64(aCarry, 19U)) + aNonceWordB);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterH, 39U)) + aOrbiterG) + aWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 12U));
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererG, 37U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordC);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 15224U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneD[((aIndex + 8715U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12216U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((aIndex + 12589U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 53U)) ^ (RotL64(aCross, 5U) + RotL64(aIngress, 24U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (aWandererF + RotL64(aIngress, 5U)) + 3238389262925516513U;
            aOrbiterK = ((aWandererG + RotL64(aScatter, 13U)) + RotL64(aCarry, 53U)) + 12381787182611386995U;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 41U)) + RotL64(aCarry, 3U)) + 7883885539305181549U;
            aOrbiterF = (((aWandererK + RotL64(aCross, 53U)) + RotL64(aCarry, 41U)) + 1185413044597727092U) + aOrbiterAssignSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = (((aWandererE + RotL64(aPrevious, 26U)) + 15219353497204773135U) + aOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1]) + aNonceWordM;
            //
            aOrbiterA = (((aOrbiterA + aOrbiterK) + 7533774715626734082U) + aOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1]) + aNonceWordA;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 2599930450937763464U) ^ aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13207380361960949159U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 16074720663961214284U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 15483613196360051221U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11717479088020532861U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 9396557867081376268U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 9668459976852660245U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11748505665890567063U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 9037269914643207212U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 16936742640861088240U;
            aOrbiterK = RotL64((aOrbiterK * 1040172193161012227U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 16481274825758546398U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 481851372837611166U) ^ aNonceWordE;
            aOrbiterF = RotL64((aOrbiterF * 2225030139210599207U), 47U);
            //
            aIngress = RotL64(aOrbiterF, 3U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterK, 56U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterI, 14U)) + RotL64(aCarry, 27U)) + aNonceWordN);
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterF, 53U)) + aNonceWordD) + aWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 41U) + aOrbiterF) + RotL64(aOrbiterA, 5U)) + aNonceWordL);
            aWandererE = aWandererE ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterK, 41U)) + aOrbiterF) + aWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 30U) + aOrbiterA) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + RotL64(aWandererF, 52U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 23147U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 18821U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20529U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 23120U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 60U) + RotL64(aIngress, 13U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCarry, 27U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererH + RotL64(aScatter, 43U)) + RotL64(aCarry, 11U)) + 12583180859826261500U;
            aOrbiterI = ((aWandererC + RotL64(aCross, 24U)) + 9067093488553721468U) + aOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = (((aWandererB + RotL64(aPrevious, 35U)) + RotL64(aCarry, 43U)) + 12173106198862881754U) + aNonceWordF;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 3U)) + RotL64(aCarry, 29U)) + 11333491014394592654U;
            aOrbiterA = ((aWandererE + RotL64(aCross, 13U)) + 3511883526940919554U) + aOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 7416810692106273044U) + aOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 8341174972619784110U;
            aOrbiterK = RotL64((aOrbiterK * 17722163445765437279U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 2220852854836962979U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 8090781422229383825U;
            aOrbiterI = RotL64((aOrbiterI * 578293950675644397U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 2338801236599102223U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 12484514711848308104U;
            aOrbiterF = RotL64((aOrbiterF * 10364216764253366067U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 13684861340589131816U) + aNonceWordM;
            aOrbiterH = (((aOrbiterH ^ aOrbiterK) ^ 12796636819991873058U) ^ aOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterH = RotL64((aOrbiterH * 5533508014234835669U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 7634198650894837690U) + aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 10240326122201201762U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8758703497719125901U), 27U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterI, 30U);
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 35U) + aOrbiterF) + RotL64(aOrbiterH, 5U)) + aNonceWordC);
            aWandererB = aWandererB ^ (((RotL64(aCross, 19U) + aOrbiterH) + RotL64(aOrbiterK, 21U)) + aNonceWordL);
            aWandererH = aWandererH + (((((RotL64(aIngress, 10U) + aOrbiterI) + RotL64(aOrbiterK, 53U)) + RotL64(aCarry, 13U)) + aNonceWordO) + aWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterA, 39U)) + aOrbiterK) + aWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 51U) + aOrbiterH) + RotL64(aOrbiterA, 30U)) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 27144U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30358U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27762U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneD[((aIndex + 29715U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 42U) ^ RotL64(aIngress, 57U)) + (RotL64(aPrevious, 27U) ^ RotL64(aCarry, 11U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 29U)) + RotL64(aCarry, 53U)) + 18255347001097480328U;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 11U)) + RotL64(aCarry, 21U)) + 13679246790311505735U;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 57U)) + 10565839529765027116U) + aNonceWordI;
            aOrbiterC = (((aWandererC + RotL64(aCross, 48U)) + RotL64(aCarry, 3U)) + 14327172566224769901U) + aOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = ((aWandererB + RotL64(aScatter, 39U)) + 16239024612038195174U) + aOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 13800012174212131890U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 13900288860157577583U) ^ aOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13177682776510523095U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 4144386119777112740U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterC) ^ 3154558262670631372U) ^ aOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterD = RotL64((aOrbiterD * 13236911910092437063U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 7456728543137614001U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 11709519851158935384U;
            aOrbiterC = RotL64((aOrbiterC * 7016689518570071587U), 29U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterD) + 15607438907832240304U) + aOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1]) + aNonceWordD;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 9276575329661725624U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8879744070762412745U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 6459435969129449226U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 6442382118416542275U;
            aOrbiterI = RotL64((aOrbiterI * 2921027306686588233U), 41U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 13U);
            aIngress = aIngress + (RotL64(aOrbiterF, 51U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 34U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterF, 19U)) + RotL64(aCarry, 23U)) + aNonceWordN);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 27U)) + aOrbiterD) + aWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 11U) + aOrbiterC) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 52U) + RotL64(aOrbiterC, 35U)) + aOrbiterI);
            aWandererA = aWandererA + (((RotL64(aPrevious, 19U) + aOrbiterC) + RotL64(aOrbiterA, 46U)) + aWandererUpdateSaltA[((aIndex + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererB, 48U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordF);
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

void TwistExpander_Badminton_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xBF23EEE23C72A225ULL + 0xD2E3D8A73372C78FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xA9BC4FC9BFCCB77FULL + 0xDC229D64B1A7CDA3ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xD9151498BD9E381DULL + 0x83FDFCCE99820A35ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE3C84788C11E809FULL + 0xF8A3A8CA9D7E9796ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA2953BB740401D89ULL + 0x855930C8C283C107ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE44D1881C33D79F5ULL + 0x99EE8BAC51E28924ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xF6C68401F553C3D5ULL + 0xEAEDA4A595AA7A21ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xDDCB8061A60EB3E9ULL + 0x8F453BBE043A900FULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xB8FE09A53B4A0447ULL + 0x90303DED1F715EC5ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xF27D7883A655AAA3ULL + 0xE703A9BF9149B856ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xE7488965931A2155ULL + 0xD211AA2B1F8ECB87ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xD4E8362A9A4AE0ABULL + 0xE65A57ACBD63BD0EULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x926B594449DE5E63ULL + 0x92C4436D331650E6ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xF6FAACDE51315095ULL + 0xAB8E29E0C0CDD27FULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xB75329AED1685149ULL + 0x8C87B3B9DED7549FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xDAA8D1F96244C4F5ULL + 0x97BAE8655C08DBF8ULL);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 550U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6060U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 282U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneA[((aIndex + 5184U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 41U)) + (RotL64(aIngress, 19U) + RotL64(aCross, 4U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (((aWandererJ + RotL64(aScatter, 28U)) + RotL64(aCarry, 53U)) + 10336802574069791273U) + aNonceWordL;
            aOrbiterE = ((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 13U)) + 169025388197058936U;
            aOrbiterC = (aWandererA + RotL64(aPrevious, 51U)) + 6541354188379168846U;
            aOrbiterA = (((aWandererG + RotL64(aIngress, 11U)) + RotL64(aCarry, 39U)) + 16223920526599306104U) + aOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = (aWandererE + RotL64(aCross, 43U)) + 12756613707692514808U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 5U)) + 5082475548176484035U;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 21U)) + 4907435526952698526U) + aOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 14236627073831834337U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterD) ^ 11502511046130497584U) ^ aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 3460330807286625917U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 3679044835550219497U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 11254838916686736746U;
            aOrbiterI = RotL64((aOrbiterI * 8631695922983532915U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 10582608424233200966U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 10449735026385340313U;
            aOrbiterG = RotL64((aOrbiterG * 7363770199734997411U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 4628253464169957835U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 17664454668473204465U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4234720298731378527U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 3798386391743884889U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 1379331161819246587U) ^ aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13086160171095077295U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 9816600392407327227U) + aNonceWordO;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 16781971616348376878U;
            aOrbiterA = RotL64((aOrbiterA * 12503867584828289879U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 4807797577690520554U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 2492057261148595922U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9453302540675483005U), 19U);
            //
            aIngress = RotL64(aOrbiterI, 3U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + RotL64(aOrbiterE, 58U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aCross, 44U) + RotL64(aOrbiterK, 13U)) + aOrbiterI) + RotL64(aCarry, 11U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterE, 41U)) + aOrbiterD);
            aWandererH = aWandererH + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 28U)) + aOrbiterE);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterC, 19U)) + aOrbiterG);
            aWandererE = aWandererE + (((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterA, 51U)) + aWandererUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterC, 57U));
            aWandererC = aWandererC + (((((RotL64(aIngress, 51U) + RotL64(aOrbiterK, 3U)) + aOrbiterA) + RotL64(aCarry, 53U)) + aNonceWordM) + aWandererUpdateSaltB[((aIndex + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 42U));
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 35U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordD);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 15022U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((aIndex + 10757U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15214U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((aIndex + 13518U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 57U)) + (RotL64(aIngress, 19U) ^ RotL64(aCross, 36U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (aWandererB + RotL64(aCross, 60U)) + 10915618884692072446U;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 41U)) + RotL64(aCarry, 43U)) + 12634922308499254909U;
            aOrbiterI = (((aWandererJ + RotL64(aIngress, 21U)) + RotL64(aCarry, 3U)) + 6533934734564499389U) + aNonceWordK;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 53U)) + 6744203303756105181U) + aOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aCross, 47U)) + 13086782386652045658U) + aNonceWordJ;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 27U)) + 5693840533331397822U) + aOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 13U)) + RotL64(aCarry, 27U)) + 1803663542535024611U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 3597219300593287708U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 1429753448204448904U;
            aOrbiterI = RotL64((aOrbiterI * 10927459251773273143U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 17229017825587322715U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 1137574712801062932U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3645832160939819415U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 2401991077004083378U) + aNonceWordO;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 1332473247826139292U;
            aOrbiterH = RotL64((aOrbiterH * 15029831858261506447U), 47U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterF) + 11730946340796899885U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordP;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 15319163439700390962U) ^ aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1349242001887975499U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 4744141870145159917U) + aOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 6067132201862688684U;
            aOrbiterC = RotL64((aOrbiterC * 6046100687757836027U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 14991509179286371800U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 4342608825699398682U;
            aOrbiterG = RotL64((aOrbiterG * 10240526103933275875U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 3727521409410742075U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 3302027219498304367U;
            aOrbiterF = RotL64((aOrbiterF * 12153634588200479559U), 35U);
            //
            aIngress = RotL64(aOrbiterF, 35U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 58U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aIngress, 5U) + RotL64(aOrbiterF, 20U)) + aOrbiterI);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterG, 27U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterI, 5U)) + aNonceWordN);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 60U) + aOrbiterI) + RotL64(aOrbiterH, 39U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterC, 53U)) + RotL64(aCarry, 11U)) + aWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 41U) + aOrbiterH) + RotL64(aOrbiterE, 11U)) + aWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 51U) + aOrbiterG) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 58U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + RotL64(aWandererB, 29U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 24515U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneA[((aIndex + 24084U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 23873U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 22227U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 56U) + RotL64(aPrevious, 23U)) ^ (RotL64(aCross, 39U) + RotL64(aIngress, 11U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((((aWandererC + RotL64(aIngress, 37U)) + RotL64(aCarry, 29U)) + 13278949403988203974U) + aOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1]) + aNonceWordP;
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 23U)) + 9213599924054673756U;
            aOrbiterG = (aWandererF + RotL64(aCross, 5U)) + 1255746482932381798U;
            aOrbiterK = (((aWandererI + RotL64(aScatter, 11U)) + RotL64(aCarry, 57U)) + 11575321997144516122U) + aNonceWordF;
            aOrbiterB = ((aWandererK + RotL64(aCross, 57U)) + 15881587525529432437U) + aOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 51U)) + RotL64(aCarry, 43U)) + 9846195809864862707U;
            aOrbiterD = (aWandererA + RotL64(aIngress, 30U)) + 12319815691858217670U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 16322617427294439587U) + aNonceWordK;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 16332130810525887437U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7588076439690559343U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 4920951156015336794U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 16767126455124552329U;
            aOrbiterC = RotL64((aOrbiterC * 4440352337076842603U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 12553595911087945223U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 1437522202135436142U) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 2001992794165550905U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 12313100454852227143U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 2761983020631055729U;
            aOrbiterK = RotL64((aOrbiterK * 3874839760378039509U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 17635303588421554367U) + aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 788212489507463763U;
            aOrbiterB = RotL64((aOrbiterB * 17896475584538528059U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 5192552894670654434U) + aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 6784748488807738811U;
            aOrbiterE = RotL64((aOrbiterE * 8077237651953896479U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 16113417046719114943U) + aNonceWordB;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 1096874945215225916U;
            aOrbiterD = RotL64((aOrbiterD * 17308604412622879833U), 57U);
            //
            aIngress = RotL64(aOrbiterK, 51U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aIngress, 60U) + RotL64(aOrbiterK, 11U)) + aOrbiterC);
            aWandererB = aWandererB ^ (((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterC, 27U)) + aNonceWordL);
            aWandererI = aWandererI + (((RotL64(aScatter, 29U) + aOrbiterC) + RotL64(aOrbiterD, 36U)) + RotL64(aCarry, 41U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterB, 5U)) + aOrbiterE) + aWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererF = aWandererF + (((((RotL64(aIngress, 43U) + aOrbiterK) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 3U)) + aNonceWordO) + aWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterD, 57U)) + aOrbiterE) + aNonceWordN);
            aWandererC = aWandererC + ((RotL64(aCross, 21U) + aOrbiterG) + RotL64(aOrbiterI, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 60U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererI, 51U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordC);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 27119U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31426U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24913U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 27690U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 56U) + RotL64(aIngress, 39U)) + (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 23U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 5U)) + 17019646486641172469U) + aNonceWordJ;
            aOrbiterF = (((aWandererA + RotL64(aCross, 19U)) + RotL64(aCarry, 51U)) + 12276141179299971572U) + aNonceWordD;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 11U)) + RotL64(aCarry, 29U)) + 3617241694029841555U;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 27U)) + 6967963401259371737U) + aOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = ((aWandererG + RotL64(aScatter, 58U)) + RotL64(aCarry, 11U)) + 6340709284279891017U;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 41U)) + 456065368903896482U) + aOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = (aWandererH + RotL64(aIngress, 35U)) + 17686765719908116203U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 1322045955429785736U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 5163772703302372887U) ^ aNonceWordI;
            aOrbiterB = RotL64((aOrbiterB * 3193272189179082313U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 13268431135020363252U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 6538789950366849332U;
            aOrbiterJ = RotL64((aOrbiterJ * 5352960308459065837U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 10390344544314544893U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 5087084271300584267U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15149302947570776165U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 13423071121590981727U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 18324443012024134729U) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 15814349432207734533U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 4129091815978464507U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 17024797553831962245U;
            aOrbiterD = RotL64((aOrbiterD * 3137753479364378175U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 6501545108779991661U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 11930037791867597447U) ^ aOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4904739567549702851U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 4667298703308315851U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 6315980380900062127U;
            aOrbiterE = RotL64((aOrbiterE * 12080555704907924637U), 43U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 13U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + (RotL64(aOrbiterI, 58U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 41U)) + aWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 20U) + aOrbiterF) + RotL64(aOrbiterH, 10U)) + aNonceWordK);
            aWandererK = aWandererK + (((RotL64(aCross, 39U) + aOrbiterD) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterB, 23U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 11U) + aOrbiterI) + RotL64(aOrbiterE, 57U));
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterH, 37U)) + aNonceWordF) + aWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterI, 29U)) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 18U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererK, 53U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordF;
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

void TwistExpander_Badminton_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xDB37F59EC56DDB0FULL + 0xFC85CC74A5DCF892ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xB88768CE744E3467ULL + 0xD94B78C38B699B5BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xEAE320EC5903858DULL + 0xCBC18FD365EC2B6FULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xDCF4D9BB0EED306DULL + 0xD2392254003D6BD2ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xDD3D7500DB54AD41ULL + 0xD61A2C2C9393711EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xEB732D62132608EFULL + 0xCDBD18DD9BE4C940ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x84CC9BC4B8BAC039ULL + 0xBC64B66FA713A14BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE0A83BDC4D899DF3ULL + 0xB46C2E880E077F81ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x98AA836DAECA6D4BULL + 0xDC794656144865B4ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x989E4FFF49E61EEFULL + 0xED39606FC0868C93ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xA2A654C62BEEC06BULL + 0xA4FFB488323C4085ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x8603E6CBC5BFA4A3ULL + 0xE07382EC4AD86ED5ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xCAD45663EE7A36FDULL + 0x9A2C40E26C4E280FULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x997DB077500F01AFULL + 0x896B420137A26970ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x8EC989CFBF035ADDULL + 0xDB9B34EAF5C39975ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xEFB8E89612FB6043ULL + 0xE1B5A116DAC4B5CBULL);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 333U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5649U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 2370U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 202U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 26U) + RotL64(aCarry, 57U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 51U)) + 6973892330986118220U;
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 24U)) + 9886813896272094864U) + aNonceWordM;
            aOrbiterD = (aWandererC + RotL64(aIngress, 35U)) + 10996306582517553173U;
            aOrbiterF = ((((aWandererE + RotL64(aCross, 57U)) + RotL64(aCarry, 27U)) + 8490648283899856223U) + aOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordK;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 43U)) + RotL64(aCarry, 3U)) + 105141713530704655U;
            aOrbiterB = (aWandererI + RotL64(aCross, 11U)) + 3114337422810562588U;
            aOrbiterE = ((((aWandererG + RotL64(aScatter, 5U)) + RotL64(aCarry, 43U)) + 980857684690886131U) + aOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 6562042345807072665U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 15665371138706353619U;
            aOrbiterD = RotL64((aOrbiterD * 8086237578564620623U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 18113013571374375028U) + aOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 17405346422601997299U;
            aOrbiterC = RotL64((aOrbiterC * 11162604605443005253U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 5130876096426182506U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 1813821672299154629U;
            aOrbiterB = RotL64((aOrbiterB * 15478100342425611875U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 15793814882743306728U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 13925299440495476399U;
            aOrbiterE = RotL64((aOrbiterE * 12049601510660117401U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 9924458846049579438U) + aNonceWordC;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 7810034662781768090U;
            aOrbiterG = RotL64((aOrbiterG * 10310594595026622513U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 12812586478656872854U) + aOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 5709576448057435237U;
            aOrbiterF = RotL64((aOrbiterF * 9101555233909853025U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 7839807649914541516U) + aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 4717944526755429647U;
            aOrbiterJ = RotL64((aOrbiterJ * 8515229146471335721U), 19U);
            //
            aIngress = RotL64(aOrbiterC, 44U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterB, 13U)) + aNonceWordB) + aWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 37U) + RotL64(aOrbiterB, 47U)) + aOrbiterF);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 27U)) + aOrbiterF);
            aWandererA = aWandererA + (((RotL64(aIngress, 5U) + aOrbiterC) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterE, 57U)) + aOrbiterD) + aWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 18U) + aOrbiterG) + RotL64(aOrbiterD, 21U)) + RotL64(aCarry, 19U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterJ, 34U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 10U));
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordE;
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 14211U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8218U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 11032U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 8366U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCross, 21U)) + (RotL64(aCarry, 37U) ^ RotL64(aIngress, 54U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 28U)) + RotL64(aCarry, 51U)) + 12583180859826261500U;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 11U)) + 9067093488553721468U) + aNonceWordB;
            aOrbiterA = (aWandererI + RotL64(aCross, 21U)) + 12173106198862881754U;
            aOrbiterD = (((aWandererH + RotL64(aScatter, 53U)) + RotL64(aCarry, 35U)) + 11333491014394592654U) + aOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (((aWandererD + RotL64(aCross, 43U)) + RotL64(aCarry, 5U)) + 3511883526940919554U) + aNonceWordD;
            aOrbiterK = (aWandererG + RotL64(aScatter, 37U)) + 7416810692106273044U;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 5U)) + 8341174972619784110U) + aOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 2220852854836962979U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 8090781422229383825U;
            aOrbiterA = RotL64((aOrbiterA * 578293950675644397U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 2338801236599102223U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 12484514711848308104U;
            aOrbiterH = RotL64((aOrbiterH * 10364216764253366067U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 13684861340589131816U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 12796636819991873058U;
            aOrbiterD = RotL64((aOrbiterD * 5533508014234835669U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 7634198650894837690U) + aOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 10240326122201201762U;
            aOrbiterE = RotL64((aOrbiterE * 8758703497719125901U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 4162814763739453934U) + aNonceWordK;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 2766504649149048469U;
            aOrbiterF = RotL64((aOrbiterF * 16731843453895178671U), 43U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterH) + 11051393030148769655U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordA;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 17687055068651386665U;
            aOrbiterK = RotL64((aOrbiterK * 1042927176246229537U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 3353615315436983420U) + aNonceWordN;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 5971640796220306310U;
            aOrbiterJ = RotL64((aOrbiterJ * 15804313508835034807U), 21U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 29U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + RotL64(aOrbiterD, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 23U) + aOrbiterF) + RotL64(aOrbiterD, 21U));
            aWandererF = aWandererF + (((((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterF, 41U)) + RotL64(aCarry, 53U)) + aNonceWordE) + aWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 57U)) + aOrbiterE) + aNonceWordC);
            aWandererI = aWandererI + (((RotL64(aScatter, 5U) + RotL64(aOrbiterA, 51U)) + aOrbiterJ) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterK, 35U)) + aOrbiterE);
            aWandererH = aWandererH + (((RotL64(aCross, 53U) + RotL64(aOrbiterA, 3U)) + aOrbiterK) + aNonceWordM);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 28U)) + aOrbiterD) + aWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (RotL64(aWandererC, 58U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererF, 43U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22268U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22889U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 22690U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneC[((aIndex + 16728U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCross, 23U)) ^ (RotL64(aCarry, 11U) + RotL64(aPrevious, 50U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (((aWandererD + RotL64(aScatter, 57U)) + 7825479804710770560U) + aOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 3U)) + 5298124167101358123U) + aOrbiterAssignSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aPrevious, 43U)) + 17774541024369233726U;
            aOrbiterF = (aWandererC + RotL64(aCross, 21U)) + 7679371833537454082U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 50U)) + RotL64(aCarry, 51U)) + 5385914900748772224U;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 27U)) + RotL64(aCarry, 11U)) + 3879781930908486531U;
            aOrbiterG = (((aWandererF + RotL64(aCross, 35U)) + RotL64(aCarry, 27U)) + 659110346638873236U) + aNonceWordC;
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 10749021728538539749U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 3631252455767429457U;
            aOrbiterI = RotL64((aOrbiterI * 8552825360915119613U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 2271978810960685021U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 5963558780692551176U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4772055335210781149U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 974909966119198104U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 9296998242911152296U;
            aOrbiterE = RotL64((aOrbiterE * 2613629915877957661U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 2245318466901521959U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 13391076374843288568U;
            aOrbiterF = RotL64((aOrbiterF * 18094558036982107419U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 6184487746594236737U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 1563385912137291418U;
            aOrbiterK = RotL64((aOrbiterK * 4805455299959232321U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 1744840092006498629U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 2100927276837188416U;
            aOrbiterH = RotL64((aOrbiterH * 3541788262067077997U), 29U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterI) + 9998911862807246338U) + aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1]) + aNonceWordH;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 12239948725635220096U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7098620484129489129U), 13U);
            //
            aIngress = RotL64(aOrbiterI, 11U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterG, 18U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterA, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 19U) + RotL64(aOrbiterI, 39U)) + aOrbiterG) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 3U) + aOrbiterH) + RotL64(aOrbiterI, 47U));
            aWandererD = aWandererD + ((RotL64(aIngress, 51U) + aOrbiterK) + RotL64(aOrbiterE, 23U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 58U) + aOrbiterF) + RotL64(aOrbiterH, 5U));
            aWandererH = aWandererH + ((((RotL64(aScatter, 37U) + aOrbiterK) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 11U)) + aWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterI, 11U)) + aOrbiterA);
            aWandererC = aWandererC + ((((RotL64(aCross, 13U) + RotL64(aOrbiterI, 56U)) + aOrbiterF) + aNonceWordA) + aWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 34U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 27U);
            aCarry = aCarry + RotL64(aIngress, 52U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordI);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27376U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25748U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28502U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 28452U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 13U) ^ RotL64(aIngress, 41U)) + (RotL64(aPrevious, 56U) + RotL64(aCarry, 27U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererB + RotL64(aIngress, 5U)) + 2330952702412094686U) + aOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 13U)) + 7820188225935060799U) + aNonceWordP;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 39U)) + RotL64(aCarry, 29U)) + 9347644591709839145U;
            aOrbiterB = (((aWandererF + RotL64(aPrevious, 51U)) + 2288624878446846870U) + aOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordO;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 58U)) + RotL64(aCarry, 11U)) + 9358977729492824128U;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 29U)) + RotL64(aCarry, 51U)) + 1858511275052455039U;
            aOrbiterI = (aWandererI + RotL64(aPrevious, 23U)) + 13715478509322292552U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 16413396625604260455U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 17714322215518432705U;
            aOrbiterG = RotL64((aOrbiterG * 1904184102419934333U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 16188315436202861122U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 5564445841368207813U) ^ aOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14125834616162835983U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 13717068949900594673U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 14143659432287313765U;
            aOrbiterJ = RotL64((aOrbiterJ * 17281441046722262917U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 5729546141908425670U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 4297827922736712074U) ^ aNonceWordH;
            aOrbiterH = RotL64((aOrbiterH * 13631630436759768885U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 829520109395163673U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 11547160328525174295U;
            aOrbiterC = RotL64((aOrbiterC * 4759690159673049775U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 2907177944512117206U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 11100346409065275671U;
            aOrbiterB = RotL64((aOrbiterB * 17927994356809011637U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 1344592529249949068U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 6470438516791143572U) ^ aOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13339390828725370475U), 29U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 13U);
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 37U));
            aIngress = aIngress + RotL64(aOrbiterE, 58U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterG, 21U)) + aOrbiterC) + aWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 42U) + aOrbiterJ) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 47U)) + aOrbiterI) + aWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterE, 27U)) + aNonceWordL);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 12U)) + aOrbiterB);
            aWandererG = aWandererG + (((RotL64(aScatter, 51U) + RotL64(aOrbiterH, 57U)) + aOrbiterI) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 27U) + aOrbiterB) + RotL64(aOrbiterE, 39U)) + aNonceWordK);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 54U));
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordP;
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

void TwistExpander_Badminton_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xC8D5371A327243C7ULL + 0x85933540DB70BE81ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xD6A3F4423C0F87C3ULL + 0xF5369E815D2F66F2ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xE6B698E6A61E3ACFULL + 0x884CD5CCDD059110ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x99A451A27B87100DULL + 0xF9205CA52B50D00CULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xC1BEA86556D71113ULL + 0x898B241692B7E0D9ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xF05FA435AF0D15D9ULL + 0xEEA6CE6573689A9CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xD7C2A9C13055D70BULL + 0x8979DECE8C22578FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xBFE39A5CF59C62F7ULL + 0x88FC3A78F9E04DAFULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x82D721C564F594A3ULL + 0xF28CB1D3D1B819C3ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x9D1F0F21C5E46237ULL + 0xEC8B17203255382EULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xA3361CF1AB3F4967ULL + 0x839A913F6DC113A4ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xAA6991541B410C09ULL + 0xF05716720AADEF1EULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xDA3FDFE27C65769FULL + 0xBADBE361917932FDULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xB47C29E30DEB7F11ULL + 0x855359C4D1F7DE8DULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x975D66E823D30067ULL + 0xF8C9B4E5C48B1001ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xB3A3423B376A0475ULL + 0xF57DD6F4E39724D1ULL);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2325U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((aIndex + 4603U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2065U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((aIndex + 1535U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCarry, 5U)) + (RotL64(aPrevious, 24U) ^ RotL64(aCross, 39U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererH + RotL64(aPrevious, 35U)) + 15549114274303128055U;
            aOrbiterI = (aWandererB + RotL64(aCross, 27U)) + 16466750056388063241U;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 11U)) + RotL64(aCarry, 43U)) + 12209449840836787142U;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 43U)) + 14551496099734294336U) + aOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aIngress, 23U)) + 6266576428679808622U;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 60U)) + RotL64(aCarry, 29U)) + 16892841575635668152U;
            aOrbiterB = (aWandererC + RotL64(aCross, 51U)) + 7375966221423362125U;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 21U)) + RotL64(aCarry, 47U)) + 11926105302821753530U;
            aOrbiterJ = (aWandererI + RotL64(aCross, 19U)) + 16219253791550461124U;
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 13U)) + 7299056065319248160U) + aOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aScatter, 48U)) + 15234001484933728439U) + aNonceWordO;
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 6615802589932632120U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 5481176858895819247U;
            aOrbiterE = RotL64((aOrbiterE * 3604590158551984877U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 17220507586542139380U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 14137921473739415340U;
            aOrbiterC = RotL64((aOrbiterC * 10634645686035907603U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 16981960446540932787U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 10897565927079518588U;
            aOrbiterK = RotL64((aOrbiterK * 418843936329303571U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 2746889569299593263U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 4894117146736361379U;
            aOrbiterH = RotL64((aOrbiterH * 2656750612042673191U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 18294823016957137777U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 86828501068883383U;
            aOrbiterB = RotL64((aOrbiterB * 11432686669235402365U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 6322053762209547826U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 6754524552483363820U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1746163087826694641U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 7306452650619361017U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 12717201204443785828U) ^ aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6121251603905574991U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 10422327053543898585U) + aNonceWordA;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 14786413282036348183U;
            aOrbiterI = RotL64((aOrbiterI * 8713024293107068275U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 4599182534559908397U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterA) ^ 5080179685914177581U) ^ aOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 14984675846207762951U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 6527649204956325409U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 8327234966110052920U;
            aOrbiterG = RotL64((aOrbiterG * 9343969092668123661U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 7845497893651522069U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterC) ^ 15549114274303128055U) ^ aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 15263427406359082909U), 19U);
            //
            aIngress = RotL64(aOrbiterC, 36U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + RotL64(aOrbiterJ, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterE, 6U));
            aWandererC = aWandererC + (((RotL64(aIngress, 48U) + aOrbiterD) + RotL64(aOrbiterJ, 39U)) + aWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 53U) + aOrbiterG) + RotL64(aOrbiterK, 47U));
            aWandererA = aWandererA + (((RotL64(aScatter, 13U) + aOrbiterF) + RotL64(aOrbiterG, 23U)) + aNonceWordC);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 27U) + aOrbiterB) + RotL64(aOrbiterH, 37U));
            aWandererG = aWandererG + ((((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterC, 43U)) + RotL64(aCarry, 51U)) + aWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 37U) + aOrbiterD) + RotL64(aOrbiterA, 13U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 11U) + aOrbiterI) + RotL64(aOrbiterF, 35U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterF, 54U)) + aOrbiterJ);
            aWandererK = aWandererK + (((RotL64(aIngress, 6U) + RotL64(aOrbiterF, 19U)) + aOrbiterC) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterE, 57U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererD, 26U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 37U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordJ);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 16181U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15969U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 16216U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((aIndex + 9511U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 54U) + RotL64(aCarry, 3U)) ^ (RotL64(aIngress, 21U) + RotL64(aCross, 39U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 24U)) + RotL64(aCarry, 37U)) + 6916817163240024692U;
            aOrbiterG = (aWandererE + RotL64(aIngress, 21U)) + 14554930751292077817U;
            aOrbiterD = (((aWandererA + RotL64(aCross, 13U)) + RotL64(aCarry, 57U)) + 1098305064484336101U) + aNonceWordI;
            aOrbiterH = (aWandererK + RotL64(aScatter, 35U)) + 12192821172420471527U;
            aOrbiterA = (aWandererC + RotL64(aIngress, 11U)) + 2435134991707318845U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 37U)) + 1896745368738512624U) + aOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = (aWandererD + RotL64(aScatter, 50U)) + 1114996424222923873U;
            aOrbiterC = (aWandererH + RotL64(aCross, 43U)) + 9839135798371512656U;
            aOrbiterB = (((aWandererB + RotL64(aIngress, 29U)) + RotL64(aCarry, 29U)) + 8037967239603177043U) + aOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aScatter, 57U)) + 15185468738487237432U;
            aOrbiterI = (aWandererI + RotL64(aCross, 27U)) + 4912098316394854543U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 13142688607850380888U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 4507379759608945839U;
            aOrbiterD = RotL64((aOrbiterD * 2989332387754215967U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 7299006009652289342U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 5390655277207053627U;
            aOrbiterG = RotL64((aOrbiterG * 10973744708856143715U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 6744737023577785725U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 15539737698867067285U;
            aOrbiterA = RotL64((aOrbiterA * 4686092035261336911U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 13329866734681377952U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 13284937458969166257U;
            aOrbiterE = RotL64((aOrbiterE * 3965985432462699445U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 8695002088915702168U) + aNonceWordF;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 3858059421620839286U) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 9559783727301092937U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 6609163873243179836U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterI) ^ 9416165620556710540U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 240385043740268229U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 1578449067529000433U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 14309000104419489303U;
            aOrbiterH = RotL64((aOrbiterH * 7599078306153684729U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 15785180680737461320U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 10099222679918382021U;
            aOrbiterK = RotL64((aOrbiterK * 2012232597046182581U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 10666287769220108179U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 13648647399222807034U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10772381733103127201U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 9292207828896796810U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 9155130791347443553U;
            aOrbiterJ = RotL64((aOrbiterJ * 16838229790655977057U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 11334395119119245556U) + aOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 6916817163240024692U;
            aOrbiterI = RotL64((aOrbiterI * 9640906826978028183U), 53U);
            //
            aIngress = RotL64(aOrbiterC, 37U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 21U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 6U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aIngress, 24U) + aOrbiterD) + RotL64(aOrbiterB, 11U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterJ, 27U)) + aOrbiterI);
            aWandererI = aWandererI + ((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterB, 38U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterH, 43U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 51U) + RotL64(aOrbiterK, 3U)) + aOrbiterG) + aNonceWordA) + aWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 21U) + aOrbiterF) + RotL64(aOrbiterH, 35U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterE, 51U)) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterF, 19U)) + aOrbiterJ) + aWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterG, 47U)) + aOrbiterC) + aNonceWordL);
            aWandererD = aWandererD + (((RotL64(aPrevious, 46U) + aOrbiterE) + RotL64(aOrbiterD, 54U)) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (RotL64(aWandererF, 30U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 60U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 23272U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22952U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21225U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 18311U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCarry, 23U)) + (RotL64(aCross, 37U) ^ RotL64(aIngress, 52U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererK + RotL64(aPrevious, 36U)) + 6469584119078165548U;
            aOrbiterF = (((aWandererI + RotL64(aCross, 47U)) + 14329756366517987910U) + aOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1]) + aNonceWordM;
            aOrbiterA = (aWandererA + RotL64(aScatter, 19U)) + 12890831797059772123U;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 41U)) + RotL64(aCarry, 35U)) + 3164503807500018990U;
            aOrbiterG = (aWandererH + RotL64(aScatter, 43U)) + 177531431387646836U;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 23U)) + 3167421392893561015U) + aOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aCross, 11U)) + 2813174781844753460U;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 53U)) + RotL64(aCarry, 3U)) + 10953270419153249857U;
            aOrbiterD = ((aWandererE + RotL64(aCross, 14U)) + RotL64(aCarry, 29U)) + 16911518309710356951U;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 39U)) + 6616750447844893150U) + aNonceWordA;
            aOrbiterB = (aWandererC + RotL64(aIngress, 29U)) + 10276741398025985982U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 6206043608461213208U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 12021552904553405793U;
            aOrbiterA = RotL64((aOrbiterA * 10023362889960174909U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 15283586234744144846U) + aNonceWordE;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 5923238786775948571U;
            aOrbiterI = RotL64((aOrbiterI * 8200882393521882651U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 11044014510971660078U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 9351141024085076044U;
            aOrbiterF = RotL64((aOrbiterF * 13316079344614432317U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 17703395981862992420U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 10154548848376027087U;
            aOrbiterG = RotL64((aOrbiterG * 12324478347590509035U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 8836420852291617425U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 10193385413543886344U;
            aOrbiterE = RotL64((aOrbiterE * 824935982418585449U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 8248580084535685190U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 3910083671888152974U;
            aOrbiterK = RotL64((aOrbiterK * 17825311776715895927U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 12350341628569930642U) + aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 2565977481575002842U) ^ aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 18233446879833776677U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 9271041067874027417U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 14289254596554201861U;
            aOrbiterH = RotL64((aOrbiterH * 7985522692852251413U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 5981802134118235214U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 14047813418129636856U;
            aOrbiterJ = RotL64((aOrbiterJ * 15961435325216504877U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 11808443842149398212U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 11380858372643695792U) ^ aNonceWordJ;
            aOrbiterD = RotL64((aOrbiterD * 100198424024622179U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 10385375464069162356U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 6469584119078165548U;
            aOrbiterB = RotL64((aOrbiterB * 5263876933019848989U), 5U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 53U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 30U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 39U));
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aCross, 37U) + RotL64(aOrbiterG, 11U)) + aOrbiterF);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 56U) + aOrbiterE) + RotL64(aOrbiterG, 39U));
            aWandererI = aWandererI + ((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 51U)) + aOrbiterE);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 11U) + aOrbiterI) + RotL64(aOrbiterA, 24U));
            aWandererC = aWandererC + ((RotL64(aIngress, 23U) + RotL64(aOrbiterF, 43U)) + aOrbiterD);
            aWandererA = aWandererA ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterJ, 57U)) + aOrbiterI);
            aWandererE = aWandererE + (((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 21U)) + aOrbiterE) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterJ, 5U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterB, 19U)) + RotL64(aCarry, 51U)) + aNonceWordG);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 50U) + aOrbiterD) + RotL64(aOrbiterC, 48U)) + aWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 21U) + aOrbiterF) + RotL64(aOrbiterC, 3U)) + aWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 54U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 41U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 30887U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((aIndex + 25944U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26591U)) & S_BLOCK1], 42U) ^ RotL64(aExpandLaneD[((aIndex + 26996U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCross, 19U)) ^ (RotL64(aCarry, 53U) + RotL64(aIngress, 6U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (aWandererB + RotL64(aScatter, 3U)) + 12222235191147985484U;
            aOrbiterG = (aWandererD + RotL64(aCross, 41U)) + 16367317014523328414U;
            aOrbiterD = ((((aWandererC + RotL64(aPrevious, 13U)) + RotL64(aCarry, 5U)) + 3511378091284703789U) + aOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordA;
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 21U)) + 15247492830966725949U) + aNonceWordK;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 19U)) + RotL64(aCarry, 43U)) + 7745995913390407897U;
            aOrbiterF = (((aWandererG + RotL64(aScatter, 27U)) + RotL64(aCarry, 19U)) + 6463593307540108810U) + aOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = (aWandererA + RotL64(aPrevious, 46U)) + 1101669311005268630U;
            aOrbiterK = (aWandererK + RotL64(aIngress, 5U)) + 12988052764067518580U;
            aOrbiterI = (aWandererE + RotL64(aCross, 35U)) + 17717179747434679772U;
            aOrbiterE = (aWandererH + RotL64(aScatter, 43U)) + 11662190906682400416U;
            aOrbiterB = (aWandererI + RotL64(aPrevious, 56U)) + 6563014073547628748U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 13099094932059419219U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 16342730862261868847U;
            aOrbiterD = RotL64((aOrbiterD * 10988124108686164829U), 21U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterC) + 16855346813127524624U) + aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1]) + aNonceWordH;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 6570063128502306944U;
            aOrbiterJ = RotL64((aOrbiterJ * 4571570049463124831U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 11328352033809240501U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 11640986648833160901U;
            aOrbiterF = RotL64((aOrbiterF * 2895830492089678919U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 2675226158571501666U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = (((aOrbiterH ^ aOrbiterD) ^ 17700531248266458165U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 2231403813970188657U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 7729597396731910874U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 15172374484412053756U) ^ aOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 149009041406406517U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 9178769489257842683U) + aNonceWordP;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 9020154972097834926U;
            aOrbiterI = RotL64((aOrbiterI * 8910504667566521429U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 1317403761217790562U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 17151528554929201571U;
            aOrbiterE = RotL64((aOrbiterE * 3735945655450625203U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 11621882033959669977U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 10289504450815075623U;
            aOrbiterB = RotL64((aOrbiterB * 13365982786836243195U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 16178772981106335703U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 16896130772325866910U;
            aOrbiterA = RotL64((aOrbiterA * 6993524735412868965U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 9573223644675562575U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 17552463713786507189U;
            aOrbiterG = RotL64((aOrbiterG * 16103431656424881779U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 4801852246698369631U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 12222235191147985484U;
            aOrbiterC = RotL64((aOrbiterC * 2835204872125428065U), 37U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 35U);
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + (RotL64(aOrbiterK, 58U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + RotL64(aOrbiterA, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterB, 21U)) + aOrbiterE) + RotL64(aCarry, 53U)) + aNonceWordM);
            aWandererA = aWandererA ^ ((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterJ, 11U));
            aWandererG = aWandererG + ((RotL64(aScatter, 13U) + aOrbiterC) + RotL64(aOrbiterF, 18U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 38U) + RotL64(aOrbiterK, 53U)) + aOrbiterI);
            aWandererB = aWandererB + ((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterA, 29U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 21U) + aOrbiterF) + RotL64(aOrbiterI, 13U));
            aWandererF = aWandererF + (((RotL64(aScatter, 23U) + aOrbiterE) + RotL64(aOrbiterH, 23U)) + aWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 34U) + aOrbiterF) + RotL64(aOrbiterA, 3U));
            aWandererK = aWandererK + ((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterJ, 60U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 43U)) + aOrbiterJ);
            aWandererI = aWandererI + (((((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterE, 51U)) + RotL64(aCarry, 47U)) + aNonceWordB) + aWandererUpdateSaltF[((aIndex + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 14U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 52U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordG);
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

void TwistExpander_Badminton_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xA41080E8FACBF7C9ULL + 0xD6B8475307C0E3F3ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xC5A1039E34D879F1ULL + 0x8318088B5597818FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC8C3A83AE03FC49DULL + 0x9D35559471E373E7ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xF4EA0B2BA6B7B4E7ULL + 0xA386ED17C0293AD0ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x932ACF4D0F74B559ULL + 0xCC1A315209245D17ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xCE931F936CB60403ULL + 0xBD92A871956689E1ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x98E8CB9D3BA25BE7ULL + 0xF44E177DF9DBC6D1ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xA6DCF06132EFFF43ULL + 0xBB19B8581EE41296ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xD6744ABE61F90057ULL + 0xFBB97DC5EA58B2C5ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x8B7E00BA0E4ED6E1ULL + 0xA4FDAB9AFFA752F8ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xCA2795773E92E81BULL + 0xFCE7FD6785580599ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xD2574667C133C4D9ULL + 0x89C287B6B2AF20F0ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xE2CA63A5186C00C1ULL + 0xE524E9D9112133D8ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xF8221704512BE355ULL + 0xCFB40C31151A2DEEULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x9E2E390B84A1E0B7ULL + 0xD46BDD88F9D85EF0ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xC30BD19F1491F803ULL + 0xC46268E06321D474ULL);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 603U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneC[((aIndex + 1174U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 911U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneA[((aIndex + 2831U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCarry, 52U)) + (RotL64(aPrevious, 39U) + RotL64(aCross, 3U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererH + RotL64(aScatter, 37U)) + 1142447269198373880U) + aOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = (((aWandererJ + RotL64(aPrevious, 23U)) + RotL64(aCarry, 21U)) + 10581460640040336191U) + aNonceWordB;
            aOrbiterG = (aWandererB + RotL64(aCross, 18U)) + 14703062773878202900U;
            aOrbiterE = ((aWandererF + RotL64(aIngress, 43U)) + 15737525756286914746U) + aNonceWordA;
            aOrbiterK = (aWandererD + RotL64(aScatter, 51U)) + 16178774478273186999U;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 3U)) + 2514897053906809160U;
            aOrbiterC = (((aWandererA + RotL64(aIngress, 60U)) + RotL64(aCarry, 39U)) + 13702496607592508464U) + aOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aCross, 47U)) + RotL64(aCarry, 57U)) + 18030885275418337965U;
            aOrbiterJ = (aWandererE + RotL64(aIngress, 29U)) + 5241783876161655984U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 2807052676283587925U) + aNonceWordK;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 8022804576763271327U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11727096043219370577U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 15597099852232205860U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 1538435607932096400U;
            aOrbiterH = RotL64((aOrbiterH * 7900752511710516981U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 11147868774413615365U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 9325213746830411568U;
            aOrbiterA = RotL64((aOrbiterA * 561819005818948769U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 13792300423550555634U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 3134856508983945719U;
            aOrbiterJ = RotL64((aOrbiterJ * 4271845067763664863U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 8654966018053784882U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 8937113935476779267U;
            aOrbiterF = RotL64((aOrbiterF * 7386875687217705855U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 4135676350355234788U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 11407912615743682678U;
            aOrbiterE = RotL64((aOrbiterE * 2773506587480714695U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 10966950663872392059U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 6686634993700944582U;
            aOrbiterC = RotL64((aOrbiterC * 2509459942163678241U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 14154407529749257990U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 18054640398549782388U) ^ aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7830759861389060149U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 14623473030642960240U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 1857945571104460086U) ^ aOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 18039903315045620079U), 13U);
            //
            aIngress = RotL64(aOrbiterC, 18U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aCross, 29U) + RotL64(aOrbiterE, 3U)) + aOrbiterA) + RotL64(aCarry, 53U)) + aWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 12U) + RotL64(aOrbiterG, 43U)) + aOrbiterJ);
            aWandererA = aWandererA + (((((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterC, 47U)) + RotL64(aCarry, 11U)) + aNonceWordJ) + aWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 28U)) + aOrbiterJ);
            aWandererG = aWandererG + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterF, 39U)) + aOrbiterI) + aNonceWordG);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 51U) + aOrbiterJ) + RotL64(aOrbiterK, 19U));
            aWandererF = aWandererF + ((RotL64(aCross, 24U) + aOrbiterH) + RotL64(aOrbiterI, 23U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterC, 56U)) + aNonceWordH);
            aWandererI = aWandererI + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 11U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 50U));
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordG);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 6780U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneD[((aIndex + 9423U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7901U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5601U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aPrevious, 34U)) ^ (RotL64(aCarry, 3U) + RotL64(aIngress, 21U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererB + RotL64(aIngress, 18U)) + 18255347001097480328U) + aNonceWordK;
            aOrbiterD = (((aWandererC + RotL64(aPrevious, 29U)) + 13679246790311505735U) + aOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordM;
            aOrbiterI = (((aWandererH + RotL64(aScatter, 41U)) + RotL64(aCarry, 27U)) + 10565839529765027116U) + aOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (aWandererF + RotL64(aCross, 23U)) + 14327172566224769901U;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 11U)) + 16239024612038195174U;
            aOrbiterA = ((aWandererE + RotL64(aCross, 57U)) + RotL64(aCarry, 3U)) + 13800012174212131890U;
            aOrbiterE = (((aWandererI + RotL64(aIngress, 3U)) + RotL64(aCarry, 53U)) + 13900288860157577583U) + aNonceWordO;
            aOrbiterF = (aWandererK + RotL64(aScatter, 47U)) + 4144386119777112740U;
            aOrbiterH = (aWandererD + RotL64(aCross, 52U)) + 3154558262670631372U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 7456728543137614001U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 11709519851158935384U) ^ aOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7016689518570071587U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 15607438907832240304U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 9276575329661725624U;
            aOrbiterB = RotL64((aOrbiterB * 8879744070762412745U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 6459435969129449226U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 6442382118416542275U;
            aOrbiterE = RotL64((aOrbiterE * 2921027306686588233U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 12117432107282150865U) + aNonceWordC;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 6831279293184793243U) ^ aOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2435360641135249073U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 9520022957804572889U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 8322178689474588679U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1627707191467537115U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 4162401591586869316U) + aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 8994015844714895961U;
            aOrbiterG = RotL64((aOrbiterG * 15421910378057951895U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 10038095909727959633U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 17756404450592957616U;
            aOrbiterC = RotL64((aOrbiterC * 14255952184627347295U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 3379089265413427719U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 11341713098678108441U) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 2500587373161411961U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 4030296130743454165U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 6332387792111212064U;
            aOrbiterD = RotL64((aOrbiterD * 16490982218150897861U), 3U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 53U);
            aIngress = aIngress + (RotL64(aOrbiterC, 6U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 23U));
            aIngress = aIngress + RotL64(aOrbiterB, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 18U)) + aOrbiterE) + aNonceWordH);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterC, 23U)) + aOrbiterD) + RotL64(aCarry, 47U)) + aNonceWordD);
            aWandererE = aWandererE ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterG, 43U)) + aOrbiterI);
            aWandererI = aWandererI + ((RotL64(aIngress, 43U) + aOrbiterC) + RotL64(aOrbiterI, 53U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 18U) + aOrbiterD) + RotL64(aOrbiterF, 11U)) + aWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 51U) + RotL64(aOrbiterB, 29U)) + aOrbiterG) + aNonceWordG);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterH, 37U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aCross, 23U) + aOrbiterB) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 58U) + aOrbiterB) + RotL64(aOrbiterA, 60U)) + aWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 60U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererI, 23U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12664U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12905U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 11516U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneC[((aIndex + 12061U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 13U) ^ RotL64(aIngress, 29U)) ^ (RotL64(aPrevious, 58U) + RotL64(aCross, 41U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererC + RotL64(aScatter, 19U)) + 13583136155674166402U;
            aOrbiterE = (aWandererB + RotL64(aIngress, 11U)) + 12830472187484919497U;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 47U)) + 18081197909484522509U;
            aOrbiterF = (aWandererG + RotL64(aCross, 39U)) + 8680634051297891550U;
            aOrbiterB = ((aWandererF + RotL64(aIngress, 58U)) + 13939998767458656823U) + aOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 43U)) + 1795730579103692594U) + aNonceWordF;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 35U)) + RotL64(aCarry, 13U)) + 17369751719734069999U;
            aOrbiterD = ((((aWandererA + RotL64(aCross, 23U)) + RotL64(aCarry, 37U)) + 224769585901248068U) + aOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1]) + aNonceWordH;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 4U)) + RotL64(aCarry, 57U)) + 4133547085925268180U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 7022512056309567391U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 10319484359046945495U) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 3400140531307001933U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 10483878349412282069U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterF) ^ 6481381149199985736U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 9701719367082506253U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 13721077228796934509U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 9704818014314175007U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 760445624027740287U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 6253040047758584339U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 16890211690273641226U;
            aOrbiterE = RotL64((aOrbiterE * 5622534399866057841U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 6216227831265032436U) + aNonceWordK;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 2023609047004658739U;
            aOrbiterB = RotL64((aOrbiterB * 3252332895698310147U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 9201669637050388263U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 5106927540934338576U;
            aOrbiterI = RotL64((aOrbiterI * 6368134569042291431U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 10080368957861445998U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 10784789383436485808U;
            aOrbiterC = RotL64((aOrbiterC * 3794918350254445939U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 15426339824951793026U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 17637144549368340331U;
            aOrbiterD = RotL64((aOrbiterD * 10971293914614704441U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 9941300382181962134U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 8118046374121322097U;
            aOrbiterK = RotL64((aOrbiterK * 8481945819050983127U), 29U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterE, 27U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 10U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + RotL64(aOrbiterJ, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterK, 4U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 39U) + aOrbiterK) + RotL64(aOrbiterI, 11U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 39U)) + aOrbiterF);
            aWandererG = aWandererG ^ (((RotL64(aCross, 60U) + RotL64(aOrbiterE, 53U)) + aOrbiterB) + aNonceWordC);
            aWandererB = aWandererB + ((((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 3U)) + aNonceWordI);
            aWandererE = aWandererE ^ (((RotL64(aCross, 5U) + aOrbiterK) + RotL64(aOrbiterD, 58U)) + aWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterK, 43U)) + RotL64(aCarry, 13U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterB, 19U)) + aNonceWordG);
            aWandererC = aWandererC + (((RotL64(aPrevious, 24U) + RotL64(aOrbiterF, 27U)) + aOrbiterB) + aWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 38U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 19606U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((aIndex + 17248U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20373U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 17711U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 56U)) ^ (RotL64(aPrevious, 43U) + RotL64(aCross, 27U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererI + RotL64(aCross, 5U)) + 4739486756133131180U;
            aOrbiterC = (aWandererE + RotL64(aIngress, 20U)) + 16089707555501328184U;
            aOrbiterD = (((aWandererA + RotL64(aPrevious, 27U)) + RotL64(aCarry, 39U)) + 15310047330238536453U) + aOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aScatter, 53U)) + 7901411596386834955U;
            aOrbiterE = ((aWandererH + RotL64(aCross, 47U)) + RotL64(aCarry, 11U)) + 4357555491060982163U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 38U)) + 15667085602825720102U) + aNonceWordI;
            aOrbiterI = ((((aWandererG + RotL64(aScatter, 57U)) + RotL64(aCarry, 29U)) + 8520635334382269253U) + aOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1]) + aNonceWordM;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 43U)) + 1772509779231068315U) + aNonceWordK;
            aOrbiterK = (aWandererJ + RotL64(aCross, 11U)) + 15336170957886025677U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 8628770833489469980U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 15469234024247246228U;
            aOrbiterD = RotL64((aOrbiterD * 8905266995119987947U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 10796430900884288328U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 10660110397012853289U;
            aOrbiterE = RotL64((aOrbiterE * 9140007610912037461U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 11202284258711214794U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 17509491802893182994U;
            aOrbiterI = RotL64((aOrbiterI * 9329107599972703671U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 16212572740740103554U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 2190030203761579226U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3101886685668871045U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 12014337082293041909U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 3733531010807001506U;
            aOrbiterF = RotL64((aOrbiterF * 5797362244066062299U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 7100994963061975529U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 17837541162838600258U;
            aOrbiterG = RotL64((aOrbiterG * 8745987361678166553U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 3311518938023146951U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 7709505172646831553U;
            aOrbiterA = RotL64((aOrbiterA * 7121143171245765213U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 4979968094554018443U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 16822214821463034107U;
            aOrbiterK = RotL64((aOrbiterK * 8618262120451291765U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 8376124175020587079U) + aNonceWordP;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 11084586282092424876U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5835632742522563537U), 57U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterG, 18U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterC, 3U)) + aOrbiterK);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 60U) + aOrbiterE) + RotL64(aOrbiterG, 47U)) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterD, 39U)) + aOrbiterJ) + aWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 11U) + aOrbiterD) + RotL64(aOrbiterA, 51U)) + RotL64(aCarry, 57U)) + aWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 39U) + aOrbiterF) + RotL64(aOrbiterK, 60U));
            aWandererE = aWandererE + (((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterG, 21U)) + aNonceWordD);
            aWandererA = aWandererA ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterC, 11U)) + aOrbiterD);
            aWandererH = aWandererH + ((RotL64(aPrevious, 18U) + aOrbiterE) + RotL64(aOrbiterI, 35U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 56U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 60U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 13U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22818U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneA[((aIndex + 24009U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22763U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25122U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 27U)) ^ (RotL64(aIngress, 57U) + RotL64(aCross, 44U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererD + RotL64(aScatter, 57U)) + 2101601659597850213U;
            aOrbiterI = (aWandererB + RotL64(aIngress, 12U)) + 2759794072560720121U;
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 43U)) + RotL64(aCarry, 3U)) + 9443562552411269339U;
            aOrbiterA = (((aWandererF + RotL64(aCross, 19U)) + RotL64(aCarry, 51U)) + 10801360546699857975U) + aNonceWordM;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 29U)) + 8020716394829332019U) + aOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aScatter, 5U)) + 1021894212367773801U;
            aOrbiterB = (aWandererC + RotL64(aCross, 39U)) + 13346855534622490176U;
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 35U)) + 16359309548462953836U;
            aOrbiterK = ((((aWandererH + RotL64(aIngress, 48U)) + RotL64(aCarry, 11U)) + 12642446944680783519U) + aOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1]) + aNonceWordO;
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 8197424982767553380U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 14346334610901859094U) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 16982899923227935679U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 14171304260534233539U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 334531601308283605U;
            aOrbiterF = RotL64((aOrbiterF * 5012968232749075075U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 10707856298471572695U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 18364775750091914766U;
            aOrbiterJ = RotL64((aOrbiterJ * 15735143943129143265U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 8531394793118363836U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 15352876929406908882U;
            aOrbiterK = RotL64((aOrbiterK * 475199047053777179U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 567682016232278157U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 2068146551757663119U;
            aOrbiterE = RotL64((aOrbiterE * 1557877740957797555U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 7776122587613256525U) + aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 16430938890724272256U;
            aOrbiterA = RotL64((aOrbiterA * 4540270493783593257U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 11912000645055436094U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 16800749242578741498U;
            aOrbiterB = RotL64((aOrbiterB * 17804584625034241737U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 5909199180260499150U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 5751089915336865588U) ^ aOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15376689503142397927U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 3478216857728853008U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 18007567146937338241U;
            aOrbiterC = RotL64((aOrbiterC * 6620498877303917855U), 47U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 3U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 6U));
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 24U) + RotL64(aOrbiterF, 19U)) + aOrbiterA);
            aWandererF = aWandererF + ((((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterI, 42U)) + aNonceWordF) + aWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 57U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aCross, 41U) + aOrbiterE) + RotL64(aOrbiterH, 5U)) + aWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 53U) + aOrbiterK) + RotL64(aOrbiterJ, 13U));
            aWandererB = aWandererB + ((((RotL64(aCross, 47U) + aOrbiterH) + RotL64(aOrbiterB, 53U)) + RotL64(aCarry, 21U)) + aNonceWordK);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 27U)) + aOrbiterF);
            aWandererH = aWandererH + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 34U)) + aOrbiterH) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 10U) + aOrbiterK) + RotL64(aOrbiterH, 47U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 34U));
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererA, 41U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29174U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27501U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30674U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29543U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 20U) ^ RotL64(aCarry, 39U)) ^ (RotL64(aCross, 5U) + RotL64(aPrevious, 57U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererH + RotL64(aIngress, 19U)) + 701291026547470433U;
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 26U)) + 17283292650462111643U) + aNonceWordH;
            aOrbiterH = (aWandererK + RotL64(aCross, 3U)) + 9969124091931303406U;
            aOrbiterE = ((aWandererC + RotL64(aScatter, 39U)) + RotL64(aCarry, 11U)) + 889176772718046988U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 53U)) + 6054541844643748084U) + aNonceWordF;
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 11U)) + 14703226235143028132U;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 43U)) + 7977975878522921062U) + aOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (((aWandererE + RotL64(aIngress, 47U)) + RotL64(aCarry, 47U)) + 16894322614172266274U) + aOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = (((aWandererD + RotL64(aPrevious, 30U)) + RotL64(aCarry, 19U)) + 12160451749345900570U) + aNonceWordJ;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 10870847008043897470U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 8159920947172520247U;
            aOrbiterH = RotL64((aOrbiterH * 4833194641611011805U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 2440099120969517932U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 2428396147731468007U) ^ aOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9363073341539598441U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 2213226274394673479U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 7079731443427765333U;
            aOrbiterC = RotL64((aOrbiterC * 16918930776877030559U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 958896789550478970U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 10788682955708075458U;
            aOrbiterI = RotL64((aOrbiterI * 913321215613559729U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 2003386579317564870U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = (((aOrbiterK ^ aOrbiterH) ^ 8419686358774204999U) ^ aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterK = RotL64((aOrbiterK * 6547052526438697621U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 6989167615157578904U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 17636634003643824148U;
            aOrbiterG = RotL64((aOrbiterG * 11038576417283732937U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 13824962118933907859U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 9543912892587859646U;
            aOrbiterE = RotL64((aOrbiterE * 14736710162285997415U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 15729878041027706114U) + aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 9542137475454825463U;
            aOrbiterB = RotL64((aOrbiterB * 11420547128115090491U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 5327302277575009955U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 2707383132257428583U;
            aOrbiterA = RotL64((aOrbiterA * 6120763309390182129U), 29U);
            //
            aIngress = RotL64(aOrbiterE, 29U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 46U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + (RotL64(aOrbiterB, 37U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterG, 52U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterK, 47U));
            aWandererK = aWandererK + ((RotL64(aCross, 14U) + RotL64(aOrbiterI, 35U)) + aOrbiterE);
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 39U) + aOrbiterH) + RotL64(aOrbiterA, 57U)) + aNonceWordA) + aWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aScatter, 51U) + RotL64(aOrbiterH, 39U)) + aOrbiterK) + RotL64(aCarry, 39U)) + aWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 22U)) + aOrbiterG);
            aWandererJ = aWandererJ + (((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterI, 11U)) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterK, 5U));
            aWandererG = aWandererG + ((RotL64(aCross, 18U) + RotL64(aOrbiterK, 27U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (RotL64(aWandererG, 46U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 35U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordI);
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

void TwistExpander_Badminton_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xBBD45EAE8DDC6ECBULL + 0xB1E0FE0A7FA4E7E2ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x8E6B62F60554B401ULL + 0xD003C479451C7FE5ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x9B7D9B309BF48357ULL + 0xD6A16DA95897D433ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xEEABE1ECF30864C9ULL + 0xBC2B4C26A7AFC9FEULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xE938E583121082CDULL + 0xB7618A6B55679C07ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xD6B24B327CAB414FULL + 0x8ED734DF9766E50EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x81E122E1834C4FE9ULL + 0xA483529813EE1118ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xD14294AF20865709ULL + 0x9BC800CDEBE00C1FULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x9A98CE6F63A29305ULL + 0x8105DD5BD07821FAULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xDBCB8ED1706352B3ULL + 0xCE19CAB7634B38C0ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xE1045AA42501A52FULL + 0x9F51B656BAFF1D0DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xC5B2DC1B3C7EAE87ULL + 0xE47D27DF8F58990AULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xD4F21B3D264B2A5BULL + 0x89362634E8F59B42ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x80DAF447529BAD6DULL + 0xB2340C6D11E26D0BULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xA56BC873F888CCF1ULL + 0xF16F8214D85EC4B6ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xC0B8AEA8B5996F0DULL + 0xE11FF12279947E4DULL);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 5165U)) & S_BLOCK1], 23U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 4628U)) & W_KEY1], 58U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 1151U)) & W_KEY1], 43U) ^ RotL64(mSource[((aIndex + 3632U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 47U) ^ RotL64(aCarry, 4U)) + (RotL64(aCross, 35U) ^ RotL64(aPrevious, 21U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterE = ((aWandererF + RotL64(aCross, 41U)) + 9080426856729228705U) + aNonceWordM;
            aOrbiterB = (((aWandererB + RotL64(aScatter, 27U)) + RotL64(aCarry, 11U)) + 7851218321653539276U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = ((aWandererH + RotL64(aIngress, 3U)) + 7023344692919298036U) + aNonceWordB;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 12U)) + RotL64(aCarry, 51U)) + 9772846154227440734U;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 35U)) + 12008298632429608431U) + aPhaseAOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aCross, 47U)) + RotL64(aCarry, 35U)) + 12201090455849562875U;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 21U)) + 9498721803411445471U) + aNonceWordH;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 351203764023093632U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 4966360430644539250U;
            aOrbiterF = RotL64((aOrbiterF * 10138518378274592739U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 9194167899071345693U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 4922477697284269116U;
            aOrbiterC = RotL64((aOrbiterC * 8444814161720407881U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 15742625291642356429U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 7528703106518431730U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11530049278751507567U), 29U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterG) + 15279053574704935317U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1]) + aNonceWordE;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 2425839793660355555U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11486964816849830667U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 13209849392400008898U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 9041500097716231309U;
            aOrbiterE = RotL64((aOrbiterE * 340661035700748739U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 7885423750878814599U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 1992993999902904603U;
            aOrbiterD = RotL64((aOrbiterD * 1478629826632201617U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 6120758615019314102U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 8529621625846992066U;
            aOrbiterB = RotL64((aOrbiterB * 8485991471612862467U), 11U);
            //
            aIngress = RotL64(aOrbiterI, 19U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterG, 37U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 27U) + RotL64(aOrbiterB, 11U)) + aOrbiterI) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 35U) + aOrbiterB) + RotL64(aOrbiterE, 41U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 13U) + aOrbiterB) + RotL64(aOrbiterC, 54U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 19U)) + aOrbiterG);
            aWandererB = aWandererB + (((RotL64(aPrevious, 21U) + aOrbiterC) + RotL64(aOrbiterE, 3U)) + aPhaseAWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterE, 35U)) + aOrbiterG) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aScatter, 60U) + RotL64(aOrbiterD, 47U)) + aOrbiterI) + RotL64(aCarry, 57U)) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + RotL64(aWandererD, 20U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8390U)) & S_BLOCK1], 21U) ^ RotL64(mSource[((aIndex + 7228U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 9617U)) & W_KEY1], 18U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 8889U)) & W_KEY1], 41U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 27U) ^ RotL64(aCarry, 54U)) + (RotL64(aCross, 3U) ^ RotL64(aPrevious, 41U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 51U)) + 15188686795415908074U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = (((aWandererG + RotL64(aScatter, 41U)) + RotL64(aCarry, 51U)) + 17310049041983079779U) + aPhaseAOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = (aWandererF + RotL64(aIngress, 57U)) + 8246925977992441471U;
            aOrbiterD = (aWandererJ + RotL64(aCross, 27U)) + 8644260919918112781U;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 5U)) + RotL64(aCarry, 35U)) + 13401663736874819483U;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 19U)) + 7940358935238314973U) + aNonceWordH;
            aOrbiterA = (((aWandererD + RotL64(aPrevious, 34U)) + RotL64(aCarry, 11U)) + 13278990328548007839U) + aNonceWordE;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 11346868298353840706U) + aNonceWordK;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 2374077904806833579U;
            aOrbiterK = RotL64((aOrbiterK * 1765686942154321425U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 6978903378645019166U) + aNonceWordA;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 11951633297870965212U;
            aOrbiterF = RotL64((aOrbiterF * 12778236598654492185U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 17398460995357409673U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 1215437945597836770U;
            aOrbiterD = RotL64((aOrbiterD * 9322970054123481621U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 1878751468043972239U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 5343002808239712390U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11878640995447558811U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 9884918450053276861U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 15894599082080422550U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8359936745539546131U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 13917339232771145459U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 18101134009493720683U;
            aOrbiterE = RotL64((aOrbiterE * 15835859435306756387U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 3830086372356903769U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterK) ^ 15894394599564584010U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 9513921913446609263U), 51U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 53U);
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 11U) + aOrbiterH) + RotL64(aOrbiterE, 35U)) + aNonceWordM);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 19U) + aOrbiterE) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 51U) + aOrbiterF) + RotL64(aOrbiterD, 21U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterK, 48U)) + aOrbiterF) + aNonceWordJ);
            aWandererG = aWandererG ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterA, 13U)) + aOrbiterK) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 4U) + aOrbiterH) + RotL64(aOrbiterF, 5U)) + RotL64(aCarry, 13U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterA, 29U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererA, 30U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordJ);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 11844U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneA[((aIndex + 13694U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 13219U)) & W_KEY1], 37U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 12870U)) & W_KEY1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aPrevious, 37U)) + (RotL64(aIngress, 6U) ^ RotL64(aCross, 57U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 57U)) + 12535417189990029950U) + aPhaseAOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = ((aWandererF + RotL64(aCross, 29U)) + 6204401443676390273U) + aNonceWordO;
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 43U)) + RotL64(aCarry, 5U)) + 869613505613154672U;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 3U)) + 15053590879563855802U) + aNonceWordL;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 10U)) + RotL64(aCarry, 51U)) + 13338989605204591428U;
            aOrbiterA = (aWandererA + RotL64(aCross, 21U)) + 18306470022403825392U;
            aOrbiterC = (((aWandererK + RotL64(aScatter, 37U)) + RotL64(aCarry, 27U)) + 1150696349434090218U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 13549541786420596437U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 14302878430259588461U;
            aOrbiterE = RotL64((aOrbiterE * 16813606782134305513U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 4660437084477165225U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 1653628537860912069U;
            aOrbiterI = RotL64((aOrbiterI * 2624835201155303123U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 5594199757006711631U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 11008472193138708891U;
            aOrbiterG = RotL64((aOrbiterG * 13645764762027798301U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 3668516817279364310U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 128159531749679984U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 4523246859249826987U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 6378674346113979108U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 11438762460659123362U) ^ aNonceWordH;
            aOrbiterJ = RotL64((aOrbiterJ * 2733309638158283953U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 10624263004446482910U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 12546839706919241411U) ^ aNonceWordE;
            aOrbiterA = RotL64((aOrbiterA * 11468326687628079347U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 8466639576503293921U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 5828694979857951504U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7835487310289634515U), 29U);
            //
            aIngress = RotL64(aOrbiterE, 56U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterB, 3U)) + aNonceWordA);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 51U) + aOrbiterJ) + RotL64(aOrbiterC, 19U));
            aWandererK = aWandererK + (((RotL64(aCross, 29U) + RotL64(aOrbiterE, 35U)) + aOrbiterC) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 44U) + RotL64(aOrbiterA, 11U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterI, 26U)) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterB, 41U)) + aNonceWordM) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 47U)) + aOrbiterB) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 24U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + RotL64(aWandererH, 51U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordK;
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 19541U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17483U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18505U)) & S_BLOCK1], 43U) ^ RotL64(mSource[((aIndex + 21339U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aIngress, 6U)) ^ (RotL64(aPrevious, 19U) ^ RotL64(aCross, 43U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterJ = (aWandererD + RotL64(aIngress, 37U)) + 9654059367478508868U;
            aOrbiterE = (((aWandererA + RotL64(aCross, 23U)) + RotL64(aCarry, 53U)) + 6473006635864677427U) + aNonceWordO;
            aOrbiterK = (aWandererK + RotL64(aScatter, 11U)) + 6944184481315853243U;
            aOrbiterG = (((aWandererF + RotL64(aPrevious, 60U)) + RotL64(aCarry, 39U)) + 4061496421939102306U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = (((aWandererC + RotL64(aIngress, 43U)) + RotL64(aCarry, 23U)) + 15791809275719085463U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aCross, 5U)) + 14050798802646323055U;
            aOrbiterF = ((aWandererI + RotL64(aScatter, 53U)) + 12072905924741758266U) + aNonceWordB;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 17639076509231343896U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 12195388285571234715U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4317060502521195769U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 4325404419499496529U) + aNonceWordK;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 5910567888204238382U;
            aOrbiterA = RotL64((aOrbiterA * 11503787177122206937U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 13092940059929942699U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 13381962590820308761U;
            aOrbiterE = RotL64((aOrbiterE * 6345904465930943295U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 15622862439323440527U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 14027151901132249793U) ^ aNonceWordP;
            aOrbiterB = RotL64((aOrbiterB * 2273573821630510087U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 4584410023907605157U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 15763755180625487157U;
            aOrbiterJ = RotL64((aOrbiterJ * 6755736130607297639U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 17023059745666559199U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 5298529579288492971U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2483562793328357721U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 2870152867331654736U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 12017191100173748848U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9958191466506480519U), 29U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 51U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterK, 41U));
            aWandererD = aWandererD + ((((RotL64(aCross, 29U) + RotL64(aOrbiterF, 20U)) + aOrbiterB) + RotL64(aCarry, 37U)) + aNonceWordG);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 56U) + aOrbiterG) + RotL64(aOrbiterA, 35U));
            aWandererK = aWandererK + ((RotL64(aIngress, 5U) + aOrbiterF) + RotL64(aOrbiterJ, 29U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterA, 47U)) + aOrbiterF) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 21U) + aOrbiterJ) + RotL64(aOrbiterK, 5U)) + RotL64(aCarry, 13U)) + aPhaseAWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterE, 11U)) + aNonceWordN);
            //
            aCarry = aCarry + (RotL64(aWandererK, 58U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordB;
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24772U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((aIndex + 22626U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23222U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((aIndex + 22864U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aIngress, 28U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCross, 53U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterJ = (aWandererG + RotL64(aScatter, 51U)) + 18087125778766689269U;
            aOrbiterG = (((aWandererD + RotL64(aIngress, 29U)) + RotL64(aCarry, 5U)) + 13710545066503235196U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aCross, 37U)) + 1701939704736254645U;
            aOrbiterD = (aWandererK + RotL64(aPrevious, 13U)) + 8064093611384019909U;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 4U)) + 16623332751533885431U) + aNonceWordD;
            aOrbiterF = (((aWandererI + RotL64(aCross, 19U)) + RotL64(aCarry, 23U)) + 15590129153794910109U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 43U)) + RotL64(aCarry, 41U)) + 7413312683079107383U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 4186064478651458810U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 5501191643940735954U;
            aOrbiterK = RotL64((aOrbiterK * 14254804649177125269U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 11064645242200570835U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 13825922087298055833U;
            aOrbiterJ = RotL64((aOrbiterJ * 7529317892716108867U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 5944980709887369970U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 8181136916070569646U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 395183021205661827U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 15442336949157292482U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterA) ^ 11580554435240641337U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 6654637892858767739U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 11240018128174598322U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 2027565596050777471U) ^ aNonceWordN;
            aOrbiterA = RotL64((aOrbiterA * 18048186560314431815U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 16425887196883725233U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 16828683527588834095U;
            aOrbiterF = RotL64((aOrbiterF * 17746289103235902485U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 9923829146479008804U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 6669171007279929454U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 681823450939955099U), 21U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterI, 20U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + RotL64(aOrbiterA, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aCross, 58U) + aOrbiterJ) + RotL64(aOrbiterK, 53U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterK, 47U)) + aOrbiterI);
            aWandererD = aWandererD + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 41U)) + aOrbiterG) + RotL64(aCarry, 21U)) + aPhaseAWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 29U)) + aOrbiterF) + aNonceWordP);
            aWandererC = aWandererC + ((((RotL64(aScatter, 39U) + aOrbiterK) + RotL64(aOrbiterD, 21U)) + aNonceWordL) + aPhaseAWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterF, 35U)) + aOrbiterI);
            aWandererE = aWandererE + (((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 10U)) + aOrbiterI) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 38U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31813U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((aIndex + 32191U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31556U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((aIndex + 27903U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 11U)) + (RotL64(aIngress, 54U) ^ RotL64(aCross, 41U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterE = ((aWandererH + RotL64(aScatter, 4U)) + 10915618884692072446U) + aPhaseAOrbiterAssignSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = (((aWandererD + RotL64(aCross, 37U)) + 12634922308499254909U) + aPhaseAOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1]) + aNonceWordM;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 43U)) + 6533934734564499389U) + aNonceWordC;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 29U)) + RotL64(aCarry, 5U)) + 6744203303756105181U;
            aOrbiterG = (aWandererA + RotL64(aCross, 53U)) + 13086782386652045658U;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 21U)) + RotL64(aCarry, 19U)) + 5693840533331397822U;
            aOrbiterA = (((aWandererB + RotL64(aScatter, 13U)) + RotL64(aCarry, 53U)) + 1803663542535024611U) + aNonceWordF;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 3597219300593287708U) + aNonceWordG;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 1429753448204448904U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10927459251773273143U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 17229017825587322715U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 1137574712801062932U;
            aOrbiterG = RotL64((aOrbiterG * 3645832160939819415U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 2401991077004083378U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 1332473247826139292U;
            aOrbiterK = RotL64((aOrbiterK * 15029831858261506447U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 11730946340796899885U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 15319163439700390962U;
            aOrbiterA = RotL64((aOrbiterA * 1349242001887975499U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 4744141870145159917U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 6067132201862688684U) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 6046100687757836027U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 14991509179286371800U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 4342608825699398682U;
            aOrbiterH = RotL64((aOrbiterH * 10240526103933275875U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 3727521409410742075U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 3302027219498304367U;
            aOrbiterJ = RotL64((aOrbiterJ * 12153634588200479559U), 11U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 13U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 21U));
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 21U) + aOrbiterH) + RotL64(aOrbiterB, 29U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterE, 51U)) + aNonceWordH);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterJ, 44U));
            aWandererK = aWandererK + (((((RotL64(aCross, 58U) + aOrbiterJ) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 57U)) + aNonceWordL) + aPhaseAWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 37U)) + aOrbiterE) + aNonceWordB);
            aWandererB = aWandererB + ((RotL64(aScatter, 41U) + aOrbiterK) + RotL64(aOrbiterG, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 56U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererK, 13U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = aCarry ^ aNonceWordM;
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

void TwistExpander_Badminton_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xBFEA6484D37F89EBULL + 0xAB2EFD410A7532D7ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xDAF52EC1313FA003ULL + 0xEFEE9ED1ABFF7D82ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xE462DA7A2569CEB9ULL + 0xC8711B1247F0EB8AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x9403C33A30011ECFULL + 0x90F32E81AAD5FE80ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x9CDEB5DF049F31B5ULL + 0xB72CD00B0438F112ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x968AD884C8627AD3ULL + 0xBB8D6DA4068751EEULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xAEF00802812C8C3BULL + 0xDDAEFB19298D25A8ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xAA3AB61512BBFFADULL + 0xC15E6F948F0BCD7EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xF3A377F6A7321BA5ULL + 0xD6CBFD718D924446ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xE855A59B48D20D59ULL + 0xB70BA08DA9546FDBULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xA69128405B7ED51FULL + 0xCCBBBF3EA4A46B7DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xAB9E18DB9CF417B1ULL + 0xF27354DCAB73ADC1ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xF042E396903822C5ULL + 0xF9D76E633342F2ABULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x9B2F509451BECE99ULL + 0xC47C31C075C5D181ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x99094364828326D3ULL + 0xC14CD678A81799DCULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xC1413561DD819BB1ULL + 0xC3BF75A156D111E3ULL);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1792U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 30U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1395U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 1473U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 47U) + RotL64(aIngress, 35U)) ^ (RotL64(aCarry, 13U) + RotL64(aPrevious, 60U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterG = (((aWandererA + RotL64(aPrevious, 57U)) + RotL64(aCarry, 43U)) + 10805654776556844351U) + aNonceWordI;
            aOrbiterK = (((aWandererE + RotL64(aIngress, 29U)) + RotL64(aCarry, 13U)) + 582794182442795335U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = (((aWandererD + RotL64(aScatter, 10U)) + RotL64(aCarry, 27U)) + 2858343650974681068U) + aPhaseBOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = (aWandererK + RotL64(aCross, 37U)) + 8189584049022064284U;
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 47U)) + 1565100751996962893U;
            //
            aOrbiterG = (((aOrbiterG + aOrbiterK) + 8062028016947611891U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1]) + aNonceWordF;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 8280504280578451745U;
            aOrbiterA = RotL64((aOrbiterA * 5212851648135050483U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 11326869194491655350U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 1671695656567777163U;
            aOrbiterG = RotL64((aOrbiterG * 7511554500524257921U), 3U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterA) + 2349843105293943452U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1]) + aNonceWordE;
            aOrbiterH = (((aOrbiterH ^ aOrbiterK) ^ 13015545152052004254U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 1316662811685429983U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 16703354404749291869U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 8713231044374305801U;
            aOrbiterK = RotL64((aOrbiterK * 9242480982197688625U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 11118401674497783533U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 14857556493734710364U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3452566050389715195U), 57U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterG, 3U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + RotL64(aOrbiterK, 34U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 37U) + RotL64(aOrbiterJ, 19U)) + aOrbiterA) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterG, 52U)) + aOrbiterH) + aPhaseBWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aCross, 28U) + aOrbiterJ) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 11U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterK, 43U)) + aOrbiterJ) + aNonceWordN);
            aWandererD = aWandererD + ((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterH, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 60U));
            aCarry = aCarry + RotL64(aWandererI, 43U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordP);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 5576U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneD[((aIndex + 9465U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10514U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7519U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 44U)) + (RotL64(aCross, 21U) + RotL64(aIngress, 5U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 39U)) + RotL64(aCarry, 21U)) + 6469584119078165548U;
            aOrbiterH = (((aWandererF + RotL64(aScatter, 3U)) + RotL64(aCarry, 57U)) + 14329756366517987910U) + aNonceWordN;
            aOrbiterB = (((aWandererH + RotL64(aCross, 47U)) + 12890831797059772123U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordA;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 13U)) + RotL64(aCarry, 5U)) + 3164503807500018990U;
            aOrbiterK = ((aWandererI + RotL64(aCross, 22U)) + 177531431387646836U) + aPhaseBOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 3167421392893561015U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 2813174781844753460U) ^ aNonceWordJ;
            aOrbiterB = RotL64((aOrbiterB * 9760688894575305115U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 10953270419153249857U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 16911518309710356951U;
            aOrbiterK = RotL64((aOrbiterK * 13162785997686570445U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 6616750447844893150U) + aNonceWordC;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 10276741398025985982U;
            aOrbiterJ = RotL64((aOrbiterJ * 6824712685896987133U), 5U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterK) + 6206043608461213208U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1]) + aNonceWordD;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 12021552904553405793U;
            aOrbiterH = RotL64((aOrbiterH * 10023362889960174909U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 15283586234744144846U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 5923238786775948571U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8200882393521882651U), 35U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 35U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + RotL64(aOrbiterA, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 23U) + aOrbiterB) + RotL64(aOrbiterA, 29U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 39U) + RotL64(aOrbiterH, 3U)) + aOrbiterJ) + RotL64(aCarry, 27U)) + aNonceWordO);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 53U)) + aOrbiterJ) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aScatter, 50U) + RotL64(aOrbiterJ, 21U)) + aOrbiterK) + RotL64(aCarry, 39U)) + aPhaseBWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 42U)) + aOrbiterB) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 20U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15044U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneA[((aIndex + 12810U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13145U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11185U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 38U) ^ RotL64(aCarry, 23U)) + (RotL64(aCross, 11U) ^ RotL64(aIngress, 51U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterK = ((aWandererA + RotL64(aIngress, 37U)) + 9751314027302668907U) + aNonceWordB;
            aOrbiterC = ((aWandererB + RotL64(aScatter, 29U)) + RotL64(aCarry, 19U)) + 12175450995523107056U;
            aOrbiterF = ((((aWandererE + RotL64(aCross, 12U)) + RotL64(aCarry, 5U)) + 17519694958730119552U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordP;
            aOrbiterJ = ((((aWandererG + RotL64(aPrevious, 3U)) + RotL64(aCarry, 41U)) + 9093525527925682263U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordC;
            aOrbiterD = (aWandererF + RotL64(aIngress, 47U)) + 3713831321786810138U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 10108355209191835040U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 12956307447311314768U;
            aOrbiterF = RotL64((aOrbiterF * 9198936928658626667U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 1904298513945877359U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 4658049993308574460U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10482422152074338611U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 9826333658248851902U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 12058666914724365134U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 964233873188373939U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 2516574707110528099U) + aNonceWordH;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 13335308331049750235U;
            aOrbiterJ = RotL64((aOrbiterJ * 5880227828760598587U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 8230749255538495304U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 16536559486797811486U;
            aOrbiterD = RotL64((aOrbiterD * 7097036838156464969U), 27U);
            //
            aIngress = RotL64(aOrbiterK, 53U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 48U) + RotL64(aOrbiterF, 27U)) + aOrbiterC) + aPhaseBWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 6U)) + aOrbiterK) + RotL64(aCarry, 19U)) + aPhaseBWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 5U) + aOrbiterD) + RotL64(aOrbiterF, 53U)) + aNonceWordA);
            aWandererE = aWandererE + (((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 43U)) + aOrbiterK) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterJ, 35U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 35U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 18808U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((aIndex + 20261U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20671U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneD[((aIndex + 18144U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCross, 35U)) + (RotL64(aPrevious, 23U) + RotL64(aCarry, 6U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterF = ((aWandererK + RotL64(aIngress, 22U)) + 9023059520606551446U) + aPhaseBOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aCross, 43U)) + RotL64(aCarry, 57U)) + 662441755115638133U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 35U)) + RotL64(aCarry, 5U)) + 16957253361196144712U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 57U)) + RotL64(aCarry, 23U)) + 7840955025765308605U;
            aOrbiterE = (((aWandererJ + RotL64(aIngress, 11U)) + 346855809270395799U) + aPhaseBOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1]) + aNonceWordA;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 16099139781586668343U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 3706457327118322098U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7810030620470889591U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 12166825885547622870U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 7792658665720344200U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16305542632794270697U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 7128477606152986326U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 11116533962780290084U;
            aOrbiterI = RotL64((aOrbiterI * 11993485572912492297U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 10443889548568288532U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 4402387036946561017U;
            aOrbiterJ = RotL64((aOrbiterJ * 9032964741841833277U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 13002706161178447654U) + aNonceWordJ;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 13929727277530310708U;
            aOrbiterE = RotL64((aOrbiterE * 7005639090871200285U), 13U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 47U);
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 60U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 37U) + RotL64(aOrbiterD, 21U)) + aOrbiterI) + RotL64(aCarry, 29U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 48U) + aOrbiterD) + RotL64(aOrbiterJ, 13U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 23U) + aOrbiterF) + RotL64(aOrbiterJ, 30U)) + RotL64(aCarry, 43U)) + aNonceWordF);
            aWandererA = aWandererA ^ (((RotL64(aCross, 13U) + aOrbiterE) + RotL64(aOrbiterF, 41U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterE, 3U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 46U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordI;
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 24777U)) & S_BLOCK1], 24U) ^ RotL64(aOperationLaneA[((aIndex + 24775U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22299U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23708U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aIngress, 11U)) ^ (RotL64(aCarry, 58U) + RotL64(aPrevious, 39U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 22U)) + 4751694786009671052U) + aNonceWordN;
            aOrbiterE = ((((aWandererJ + RotL64(aScatter, 53U)) + RotL64(aCarry, 3U)) + 16362725160370844224U) + aPhaseBOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1]) + aNonceWordM;
            aOrbiterA = (((aWandererH + RotL64(aIngress, 41U)) + RotL64(aCarry, 51U)) + 6360885380915941057U) + aPhaseBOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aCross, 13U)) + RotL64(aCarry, 37U)) + 5154536007972297036U;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 3U)) + 9362540581874808253U) + aNonceWordL;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 13902493871525612934U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 10208452885367546542U;
            aOrbiterA = RotL64((aOrbiterA * 12067703239567933105U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 3117030377279160998U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 17286247690414027870U;
            aOrbiterF = RotL64((aOrbiterF * 4896931759653832095U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 3930314320040949141U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 7289525252391668404U;
            aOrbiterD = RotL64((aOrbiterD * 15452162299105112187U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 3434167955466809185U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 17852573095128575663U;
            aOrbiterE = RotL64((aOrbiterE * 1485660158767033425U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 6137259687928853253U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = (((aOrbiterI ^ aOrbiterF) ^ 13992510605237574698U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 15346263295995333395U), 39U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterI, 37U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + RotL64(aOrbiterF, 26U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterE, 11U)) + aOrbiterF) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 56U) + aOrbiterE) + RotL64(aOrbiterI, 24U)) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 3U)) + aOrbiterA) + aNonceWordA);
            aWandererH = aWandererH + (((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 35U)) + aOrbiterE) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterF, 47U)) + aOrbiterD) + aNonceWordF) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + RotL64(aWandererD, 42U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordF);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 30916U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((aIndex + 29058U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31062U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((aIndex + 30350U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 6U) ^ RotL64(aPrevious, 57U)) + (RotL64(aIngress, 41U) ^ RotL64(aCarry, 23U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterG = (((aWandererJ + RotL64(aCross, 51U)) + RotL64(aCarry, 21U)) + 13296600294247799698U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 43U)) + RotL64(aCarry, 41U)) + 5818503518080877515U;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 3U)) + 6735784238734173597U) + aNonceWordO;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 35U)) + RotL64(aCarry, 3U)) + 7368398209488856201U;
            aOrbiterA = (((aWandererF + RotL64(aCross, 12U)) + 961734029066455638U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordM;
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 797011946660892011U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 12841876018396622350U;
            aOrbiterI = RotL64((aOrbiterI * 14056540056414153277U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 16213253970483895623U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterC) ^ 15186950557113470375U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 4647470430467908107U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 5117930310827477341U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 12265429373166094162U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1522823535151532249U), 21U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterA) + 13920531346698601568U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordH;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 14695405206998211456U;
            aOrbiterC = RotL64((aOrbiterC * 13950964363414164279U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 7851960904825938443U) + aNonceWordF;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 9501511171732550190U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5614164120361489613U), 5U);
            //
            aIngress = RotL64(aOrbiterC, 43U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 58U) + RotL64(aOrbiterA, 27U)) + aOrbiterJ) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 47U)) + aOrbiterC);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 39U) + RotL64(aOrbiterG, 19U)) + aOrbiterA) + RotL64(aCarry, 3U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterG, 38U));
            aWandererB = aWandererB + ((((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterJ, 57U)) + aNonceWordP) + aPhaseBWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 4U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + RotL64(aWandererI, 53U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordJ;
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

void TwistExpander_Badminton_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xBAEE69736831D7B7ULL + 0xBD53F50805F43971ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xE0602761B9BC25C1ULL + 0xC7D3F045C66E334AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC002CC1D9292879BULL + 0xA85A5925A380E8ECULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x9E827F6B5421E103ULL + 0xED2BA700732558A9ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x897E672892A37859ULL + 0xE3F63E83B1E9E28FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x82129BD6759471B3ULL + 0x8C52B8007197505BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xDF85065F5F30A7DDULL + 0xE1F9DAAAE9399095ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xDB7EF4F2902CB507ULL + 0xC4710151642C6174ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xF0FDB3211FD3CC5BULL + 0xD5687C9E58B298D0ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x9A75E572A4368435ULL + 0xB7B17B3A6211E6CCULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xF7059A97430FBBF7ULL + 0xFC1D606090DAFB1DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x80DA3FE38B17C96DULL + 0xF931496CE17C9EA6ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xA505CA2C24B3EF5DULL + 0xB966F7F70DF622FBULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x8CAD53FAA271CC8BULL + 0x9309FB49229AAF72ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xB71D0E57AF068797ULL + 0x81724A0F698E4494ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x8EF23B1828607BFFULL + 0xC9D3670B21D8C125ULL);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 2543U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneC[((aIndex + 5512U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 4900U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 3403U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 52U) + RotL64(aCarry, 37U)) ^ (RotL64(aIngress, 5U) ^ RotL64(aCross, 19U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterC = (((aWandererA + RotL64(aPrevious, 24U)) + RotL64(aCarry, 5U)) + 6163290588946759209U) + aNonceWordE;
            aOrbiterG = (aWandererG + RotL64(aCross, 13U)) + 7342672468560105447U;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 47U)) + 11574563167017282321U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aIngress, 29U)) + RotL64(aCarry, 29U)) + 2254820206194758964U;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 57U)) + 1469783447473099498U) + aNonceWordB;
            aOrbiterH = (aWandererJ + RotL64(aScatter, 51U)) + 14174828900676165088U;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 20U)) + 16277954291890598132U;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 41U)) + 14845750668693136766U) + aPhaseCOrbiterAssignSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aCross, 5U)) + RotL64(aCarry, 37U)) + 150099699692047766U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 1200784917165131703U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 9469982764806754302U;
            aOrbiterB = RotL64((aOrbiterB * 17851969334511301943U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 10956702761701710182U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 7915506894975487807U;
            aOrbiterH = RotL64((aOrbiterH * 8874108311712727983U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 17335794183733623213U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 557028996286989506U) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 3993359298602424281U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 1597385667771002414U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 4376417959915162639U;
            aOrbiterF = RotL64((aOrbiterF * 4626236858205178149U), 13U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterK) + 549770198518993876U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordM;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 756554555648070919U;
            aOrbiterC = RotL64((aOrbiterC * 16272320259614325355U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 7298557532533152193U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterB) ^ 3336802611342112013U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterD = RotL64((aOrbiterD * 14679103452120080499U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 2314938232094714365U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 12215066333571149153U;
            aOrbiterI = RotL64((aOrbiterI * 10747052773052630601U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 7762752719356805046U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 6519429915769040078U;
            aOrbiterG = RotL64((aOrbiterG * 15548676502167938513U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 7556691736109752918U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 13731245903412646404U;
            aOrbiterJ = RotL64((aOrbiterJ * 15581965016668635409U), 27U);
            //
            aIngress = RotL64(aOrbiterJ, 57U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 60U));
            aIngress = aIngress + (RotL64(aOrbiterI, 41U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 20U)) + aOrbiterB);
            aWandererG = aWandererG + ((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterB, 51U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterD, 39U)) + aOrbiterH) + aNonceWordP);
            aWandererD = aWandererD + ((((RotL64(aIngress, 24U) + aOrbiterH) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 11U)) + aNonceWordC);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 12U)) + aOrbiterK);
            aWandererC = aWandererC + (((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 3U)) + aOrbiterJ) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 57U) + aOrbiterJ) + RotL64(aOrbiterC, 35U)) + aNonceWordI) + aPhaseCWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 47U) + RotL64(aOrbiterC, 47U)) + aOrbiterG);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 18U) + RotL64(aOrbiterF, 43U)) + aOrbiterG) + aPhaseCWandererUpdateSaltE[((aIndex + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 10U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 37U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordH);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9666U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 12534U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15484U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 14097U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aIngress, 39U)) ^ (RotL64(aCarry, 52U) ^ RotL64(aPrevious, 21U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterH = (aWandererB + RotL64(aIngress, 3U)) + 1142447269198373880U;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 35U)) + 10581460640040336191U;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 51U)) + 14703062773878202900U) + aPhaseCOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = (((aWandererK + RotL64(aScatter, 39U)) + RotL64(aCarry, 51U)) + 15737525756286914746U) + aPhaseCOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = (((aWandererD + RotL64(aIngress, 46U)) + RotL64(aCarry, 21U)) + 16178774478273186999U) + aNonceWordA;
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 13U)) + RotL64(aCarry, 5U)) + 2514897053906809160U;
            aOrbiterI = (aWandererE + RotL64(aCross, 57U)) + 13702496607592508464U;
            aOrbiterB = (aWandererA + RotL64(aScatter, 27U)) + 18030885275418337965U;
            aOrbiterF = (aWandererH + RotL64(aIngress, 20U)) + 5241783876161655984U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 2807052676283587925U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 8022804576763271327U;
            aOrbiterJ = RotL64((aOrbiterJ * 11727096043219370577U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 15597099852232205860U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 1538435607932096400U;
            aOrbiterE = RotL64((aOrbiterE * 7900752511710516981U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 11147868774413615365U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 9325213746830411568U;
            aOrbiterI = RotL64((aOrbiterI * 561819005818948769U), 27U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterI) + 13792300423550555634U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1]) + aNonceWordI;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 3134856508983945719U) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 4271845067763664863U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 8654966018053784882U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 8937113935476779267U;
            aOrbiterF = RotL64((aOrbiterF * 7386875687217705855U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 4135676350355234788U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 11407912615743682678U;
            aOrbiterH = RotL64((aOrbiterH * 2773506587480714695U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 10966950663872392059U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 6686634993700944582U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2509459942163678241U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 14154407529749257990U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 18054640398549782388U;
            aOrbiterK = RotL64((aOrbiterK * 7830759861389060149U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 14623473030642960240U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 1857945571104460086U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 18039903315045620079U), 35U);
            //
            aIngress = RotL64(aOrbiterG, 4U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterF, 23U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 26U)) + aOrbiterG) + aNonceWordM) + aPhaseCWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 51U) + aOrbiterG) + RotL64(aOrbiterC, 41U)) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterI, 3U));
            aWandererK = aWandererK + (((RotL64(aIngress, 39U) + RotL64(aOrbiterJ, 47U)) + aOrbiterC) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 26U) + aOrbiterK) + RotL64(aOrbiterI, 53U));
            aWandererD = aWandererD + (((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterB, 13U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterE, 21U)) + aOrbiterF);
            aWandererC = aWandererC + (((RotL64(aCross, 19U) + aOrbiterH) + RotL64(aOrbiterB, 57U)) + aNonceWordJ);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 14U) + aOrbiterC) + RotL64(aOrbiterE, 36U)) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 30U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordN;
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 21546U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneA[((aIndex + 19859U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 21371U)) & S_BLOCK1], 46U) ^ RotL64(aOperationLaneC[((aIndex + 17444U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 56U) ^ RotL64(aCarry, 27U)) ^ (RotL64(aPrevious, 11U) + RotL64(aCross, 39U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterI = ((aWandererI + RotL64(aScatter, 36U)) + 16189787374324972735U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aIngress, 3U)) + 17563763730956242224U;
            aOrbiterC = ((((aWandererB + RotL64(aCross, 11U)) + RotL64(aCarry, 43U)) + 10572803498593789385U) + aPhaseCOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1]) + aNonceWordC;
            aOrbiterA = (((aWandererA + RotL64(aPrevious, 27U)) + RotL64(aCarry, 35U)) + 7713105232072974166U) + aNonceWordO;
            aOrbiterD = (aWandererG + RotL64(aCross, 53U)) + 10760839534772718139U;
            aOrbiterG = (aWandererE + RotL64(aPrevious, 57U)) + 13397069448391230253U;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 43U)) + 4569255679998375682U;
            aOrbiterK = ((aWandererC + RotL64(aIngress, 22U)) + RotL64(aCarry, 53U)) + 9888769350817876949U;
            aOrbiterH = (aWandererD + RotL64(aScatter, 47U)) + 11351796060878856300U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 18153775071965707204U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 1282846411145853435U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12294455920906257823U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 16457743979262460660U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 173493260775251032U;
            aOrbiterI = RotL64((aOrbiterI * 4935807229040883505U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 3927345926316409630U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 5158769729850853623U;
            aOrbiterA = RotL64((aOrbiterA * 2446452358663812945U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 12331351600010165154U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 3940794200348684050U) ^ aNonceWordJ;
            aOrbiterF = RotL64((aOrbiterF * 13248997263062075043U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 11248514843822945425U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 1391497323278226522U;
            aOrbiterD = RotL64((aOrbiterD * 8376841806072565005U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 13265623528678787307U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 2802033745265647317U;
            aOrbiterG = RotL64((aOrbiterG * 3437626962562016147U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 6938444301018051844U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 1086544666755559028U;
            aOrbiterJ = RotL64((aOrbiterJ * 16039728388882079889U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 16156443117365816536U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 3619942859562697142U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7589346043159112151U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 17681848914912743292U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 8848238631758130416U;
            aOrbiterH = RotL64((aOrbiterH * 810402256099500607U), 19U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterG, 6U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 39U));
            aIngress = aIngress + RotL64(aOrbiterH, 50U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterG, 47U)) + aOrbiterK);
            aWandererK = aWandererK + ((((RotL64(aIngress, 34U) + aOrbiterC) + RotL64(aOrbiterI, 4U)) + RotL64(aCarry, 53U)) + aNonceWordK);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterD, 23U)) + aOrbiterG) + aNonceWordM);
            aWandererI = aWandererI + (((RotL64(aCross, 11U) + RotL64(aOrbiterK, 57U)) + aOrbiterJ) + aPhaseCWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 27U)) + aOrbiterI);
            aWandererE = aWandererE + (((RotL64(aPrevious, 41U) + aOrbiterJ) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 19U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 56U) + RotL64(aOrbiterA, 39U)) + aOrbiterG);
            aWandererD = aWandererD + ((((RotL64(aCross, 51U) + RotL64(aOrbiterF, 34U)) + aOrbiterG) + aNonceWordA) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterA, 43U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 44U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 41U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 28105U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25363U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29035U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneD[((aIndex + 26588U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aPrevious, 3U)) ^ (RotL64(aIngress, 51U) + RotL64(aCarry, 38U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 48U)) + 18180797995100240808U;
            aOrbiterG = (aWandererG + RotL64(aCross, 53U)) + 6585906608223552885U;
            aOrbiterE = ((((aWandererE + RotL64(aScatter, 5U)) + RotL64(aCarry, 13U)) + 14088708930575939855U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordN;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 13U)) + 468974153311516044U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aCross, 42U)) + 12481951025619894110U;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 57U)) + 17227987923860711763U) + aNonceWordG;
            aOrbiterF = ((aWandererH + RotL64(aIngress, 27U)) + RotL64(aCarry, 53U)) + 4373962756657477139U;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 35U)) + 2077576476565420951U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 23U)) + RotL64(aCarry, 5U)) + 17435011300234663764U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 4118039398293246896U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 13724716599855216683U) ^ aNonceWordB;
            aOrbiterE = RotL64((aOrbiterE * 17556333902751079677U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 12391461204689596339U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 9900605191533799627U) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 13553565332531046301U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 972946858824366125U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 17247681919694541215U;
            aOrbiterF = RotL64((aOrbiterF * 2974639094630445643U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 15442851427306771601U) + aNonceWordF;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 7303586227288294037U;
            aOrbiterJ = RotL64((aOrbiterJ * 15406402525021428799U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 12650358753454105119U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 1483710933373510492U;
            aOrbiterA = RotL64((aOrbiterA * 6531763256577221891U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 18065810162229740788U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 11311677121338794007U;
            aOrbiterK = RotL64((aOrbiterK * 15116367961682119467U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 2355285311890287611U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 1287783821903407734U;
            aOrbiterI = RotL64((aOrbiterI * 8054011680932255985U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 9282654686791135654U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 15488608017745542551U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7858866274035085123U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 13296835576073421802U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 7127700236018338741U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11246173563106014149U), 47U);
            //
            aIngress = RotL64(aOrbiterI, 44U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterA, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 56U) + aOrbiterH) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterE, 39U));
            aWandererI = aWandererI + (((RotL64(aScatter, 35U) + aOrbiterK) + RotL64(aOrbiterG, 18U)) + aNonceWordH);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterH, 13U)) + aOrbiterF);
            aWandererE = aWandererE + (((RotL64(aScatter, 10U) + aOrbiterF) + RotL64(aOrbiterC, 5U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 21U) + aOrbiterC) + RotL64(aOrbiterI, 43U)) + aPhaseCWandererUpdateSaltE[((aIndex + 26U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 51U) + RotL64(aOrbiterK, 57U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 48U)) + aOrbiterJ);
            aWandererH = aWandererH + (((RotL64(aScatter, 39U) + aOrbiterI) + RotL64(aOrbiterF, 53U)) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 26U);
            aCarry = aCarry ^ aNonceWordK;
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

void TwistExpander_Badminton_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x8BB6E4CABC446E7DULL + 0xE34311E4F3C88BD7ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xF3E210E3AB54BB09ULL + 0x9B28DB5B7F6D4B6BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xC51EDA7709182A87ULL + 0xDF16BBA72421C5B5ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xBCA879C45B79E9C9ULL + 0xF89579EAFFD15BFFULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xED05AA04799A5CBBULL + 0x8660D794FF02BEE5ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xD4221FB7B2F51A93ULL + 0xCFE8F67BB84BFF40ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x947A155C1FBF0A63ULL + 0xD65AA4E9505DCBDEULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xF75F7978F628DE9FULL + 0xF2FF44CDF3B633CDULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xF3449BAFE70EC4E5ULL + 0xFE635FD6AA989BF0ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x9D4D1B3FF4220917ULL + 0xBE1978917D3FA71DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x8DB174750C336C03ULL + 0xBF943CEDF748C56CULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xC59C7C65B243F1CBULL + 0xA6AC926028CD0378ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xC38AD9FAFF9F4183ULL + 0xE55EF5F02D9D3F69ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xAF217B606EF4631BULL + 0xCBCC4DF908AD2116ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xE16E8BCC534BDFC9ULL + 0xB623B8FE8C362690ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xE12005001CDA9AD3ULL + 0x9F663BA2FFDD36C2ULL);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 255U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3852U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3995U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((aIndex + 555U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 37U)) ^ (RotL64(aIngress, 52U) + RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 5U)) + 7948891781097675369U;
            aOrbiterB = (aWandererF + RotL64(aIngress, 37U)) + 13928362874228230226U;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 51U)) + 10776180542602258926U;
            aOrbiterA = ((aWandererD + RotL64(aCross, 21U)) + RotL64(aCarry, 11U)) + 5735115172149470447U;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 11U)) + RotL64(aCarry, 5U)) + 5353591822981766987U;
            aOrbiterF = (((aWandererH + RotL64(aScatter, 14U)) + RotL64(aCarry, 39U)) + 562301708107268570U) + aNonceWordN;
            aOrbiterD = (aWandererA + RotL64(aCross, 27U)) + 10467810247578364868U;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 3U)) + 14541630141152308564U;
            aOrbiterC = (((aWandererE + RotL64(aScatter, 35U)) + 2350076897065139429U) + aPhaseDOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1]) + aNonceWordO;
            aOrbiterK = (aWandererB + RotL64(aPrevious, 53U)) + 17519109078651162228U;
            aOrbiterE = ((aWandererI + RotL64(aCross, 56U)) + 6061035173339902910U) + aPhaseDOrbiterAssignSaltA[((aIndex + 6U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 15654836633731000065U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 13723521735153718904U;
            aOrbiterG = RotL64((aOrbiterG * 14459516479283070563U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 2849680038315532197U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 17336102435576647923U;
            aOrbiterF = RotL64((aOrbiterF * 10984689101753586739U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 7671010488872356142U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 11485114338165600777U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4162584865462407791U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 8759060657343458985U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 11009137869375286581U;
            aOrbiterA = RotL64((aOrbiterA * 8741417343929809115U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 15792999392743144135U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 6180808423175992479U;
            aOrbiterD = RotL64((aOrbiterD * 13681230339693676907U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 361487389591183005U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 15292753806514404853U;
            aOrbiterC = RotL64((aOrbiterC * 17478232597253311153U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 14929153438443362045U) + aNonceWordD;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 7904556383593914086U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2484130486635511403U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 3793180909904286848U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 10391957637467171320U) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 505484041943467117U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 11648765065563798353U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 17601185776537566611U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4753179291885740011U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 2907499704986356444U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 17048858067202291241U;
            aOrbiterI = RotL64((aOrbiterI * 2607549567999666889U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 4340465159886930775U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 7948891781097675369U) ^ aNonceWordG;
            aOrbiterK = RotL64((aOrbiterK * 12913104720552907335U), 5U);
            //
            aIngress = RotL64(aOrbiterB, 3U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 30U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 21U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + RotL64(aOrbiterC, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterG, 19U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 27U) + aOrbiterB) + RotL64(aOrbiterF, 13U)) + aNonceWordC);
            aWandererJ = aWandererJ + ((RotL64(aCross, 44U) + RotL64(aOrbiterI, 3U)) + aOrbiterJ);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 19U) + aOrbiterK) + RotL64(aOrbiterH, 52U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 11U)) + aOrbiterF) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterC, 39U)) + aOrbiterE);
            aWandererK = aWandererK + ((((RotL64(aScatter, 39U) + RotL64(aOrbiterA, 35U)) + aOrbiterK) + aNonceWordI) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterE, 60U)) + aOrbiterF);
            aWandererH = aWandererH + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 23U)) + aOrbiterD);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 43U)) + aOrbiterI) + aPhaseDWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 42U) + aOrbiterJ) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 5U)) + aNonceWordE);
            //
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 48U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 23U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordM);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 8344U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 5792U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9645U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((aIndex + 7272U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCarry, 11U)) + (RotL64(aCross, 35U) ^ RotL64(aIngress, 58U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterE = ((aWandererB + RotL64(aCross, 27U)) + 18144572925667544139U) + aPhaseDOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = ((((aWandererC + RotL64(aScatter, 29U)) + RotL64(aCarry, 21U)) + 5659758077574059728U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordA;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 6U)) + 6343330616999166392U) + aNonceWordO;
            aOrbiterB = (aWandererK + RotL64(aPrevious, 21U)) + 17754639838410839447U;
            aOrbiterI = (aWandererI + RotL64(aScatter, 19U)) + 9451843819849581729U;
            aOrbiterA = (aWandererJ + RotL64(aIngress, 13U)) + 7957854457197462212U;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 54U)) + 1461994799722205010U;
            aOrbiterK = ((aWandererG + RotL64(aCross, 57U)) + 18002214276252170177U) + aNonceWordD;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 41U)) + RotL64(aCarry, 37U)) + 14689869073147027164U;
            aOrbiterH = ((aWandererH + RotL64(aCross, 11U)) + RotL64(aCarry, 11U)) + 3978104368003440293U;
            aOrbiterD = (aWandererE + RotL64(aPrevious, 47U)) + 8512135845221335386U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 1477533446382953439U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 2166717790929947990U;
            aOrbiterG = RotL64((aOrbiterG * 6538884492418324461U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 8082437060686606995U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 4363687722464700362U;
            aOrbiterC = RotL64((aOrbiterC * 7199165810993478887U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 15782763348014924206U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterA) ^ 8572509150015960728U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterI = RotL64((aOrbiterI * 3340528604891897779U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 12248271773316742521U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 9602078627638561949U;
            aOrbiterJ = RotL64((aOrbiterJ * 1860631869877427405U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 17244849374768558859U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 1030743048280579012U;
            aOrbiterF = RotL64((aOrbiterF * 10858949914285817051U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 17722342363541914280U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 15667504059789880034U;
            aOrbiterE = RotL64((aOrbiterE * 15872269872168533709U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 12645332941998550794U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 9938135244509986497U;
            aOrbiterB = RotL64((aOrbiterB * 16548185968987392957U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 4024609904162105979U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 6732064218696157303U;
            aOrbiterA = RotL64((aOrbiterA * 3815409766145891393U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 14314117137220703583U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 15244765904057473814U;
            aOrbiterK = RotL64((aOrbiterK * 4034571710808047959U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 17441241682018169245U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 11958974379114644873U;
            aOrbiterH = RotL64((aOrbiterH * 11315689206845170303U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 8310839846793796473U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 18144572925667544139U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11668203295511168011U), 23U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterC, 3U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + (RotL64(aOrbiterK, 41U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 37U));
            aIngress = aIngress + (RotL64(aOrbiterF, 48U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterK, 39U)) + aOrbiterC);
            aWandererD = aWandererD + (((RotL64(aPrevious, 44U) + aOrbiterC) + RotL64(aOrbiterA, 53U)) + RotL64(aCarry, 41U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterD, 21U)) + aOrbiterJ) + aNonceWordP);
            aWandererE = aWandererE + (((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 27U)) + aOrbiterF) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 19U)) + aOrbiterD);
            aWandererH = aWandererH + ((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 60U)) + aOrbiterG);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 19U) + aOrbiterE) + RotL64(aOrbiterF, 57U));
            aWandererF = aWandererF + (((RotL64(aCross, 35U) + RotL64(aOrbiterI, 35U)) + aOrbiterD) + RotL64(aCarry, 29U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 24U) + RotL64(aOrbiterE, 29U)) + aOrbiterD) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 14U)) + aOrbiterD) + aNonceWordC);
            aWandererK = aWandererK ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterB, 5U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (RotL64(aWandererB, 26U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + RotL64(aWandererA, 60U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 14165U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 11657U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13788U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((aIndex + 15755U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aIngress, 5U)) ^ (RotL64(aCross, 37U) ^ RotL64(aPrevious, 18U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterA = (aWandererJ + RotL64(aScatter, 19U)) + 7790166497945719700U;
            aOrbiterE = (aWandererD + RotL64(aCross, 27U)) + 7136208896846119188U;
            aOrbiterG = (aWandererH + RotL64(aIngress, 6U)) + 12123156943355100886U;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 13U)) + RotL64(aCarry, 43U)) + 5095546037880875199U;
            aOrbiterD = (aWandererB + RotL64(aIngress, 57U)) + 17642705393916765992U;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 23U)) + 9918479837334416990U) + aNonceWordJ;
            aOrbiterB = ((aWandererF + RotL64(aCross, 21U)) + RotL64(aCarry, 5U)) + 4890009823843176466U;
            aOrbiterK = ((aWandererK + RotL64(aScatter, 47U)) + 17652590786213674124U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = (((aWandererG + RotL64(aIngress, 39U)) + RotL64(aCarry, 13U)) + 870002527644696135U) + aPhaseDOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aScatter, 53U)) + 12545429703552643682U;
            aOrbiterC = (aWandererE + RotL64(aCross, 10U)) + 5310272867406182581U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 3264719049050179440U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 1967241238180278937U;
            aOrbiterG = RotL64((aOrbiterG * 13004319774269457957U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 773883832927040736U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 12766817190261232485U;
            aOrbiterF = RotL64((aOrbiterF * 7448864556802318431U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 260069382395598265U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 15462103891287350123U;
            aOrbiterE = RotL64((aOrbiterE * 5029268763635635753U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 4072032867513289827U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 17153061419083897076U;
            aOrbiterD = RotL64((aOrbiterD * 11934532169271718913U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 6207264270332656966U) + aNonceWordI;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 18048064697837314947U;
            aOrbiterK = RotL64((aOrbiterK * 13632594619404208489U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 14484617445340272026U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 16160443600497652026U;
            aOrbiterJ = RotL64((aOrbiterJ * 1988599349457831597U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 5873314228291583482U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 16418290052752166515U;
            aOrbiterA = RotL64((aOrbiterA * 18270363452003213317U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 9158414409987627714U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 8205937960146492168U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14008398661393344261U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 16386126219854809263U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 12418021156683187869U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 13897930566207284517U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 5427232681451476584U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 18237670074497382745U;
            aOrbiterI = RotL64((aOrbiterI * 15528665160297906195U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 8330262458028468513U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 7790166497945719700U;
            aOrbiterC = RotL64((aOrbiterC * 6001280767763971107U), 39U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterB, 39U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 58U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 21U));
            aIngress = aIngress + RotL64(aOrbiterD, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 51U) + aOrbiterK) + RotL64(aOrbiterG, 34U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 58U) + RotL64(aOrbiterH, 3U)) + aOrbiterC) + aPhaseDWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 27U) + aOrbiterA) + RotL64(aOrbiterC, 43U));
            aWandererF = aWandererF + (((RotL64(aIngress, 39U) + aOrbiterE) + RotL64(aOrbiterI, 11U)) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterK, 13U));
            aWandererK = aWandererK + (((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterC, 51U)) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 22U)) + aOrbiterE);
            aWandererG = aWandererG + ((RotL64(aIngress, 41U) + RotL64(aOrbiterG, 57U)) + aOrbiterH);
            aWandererE = aWandererE ^ ((RotL64(aCross, 14U) + aOrbiterB) + RotL64(aOrbiterD, 37U));
            aWandererD = aWandererD + (((RotL64(aIngress, 35U) + RotL64(aOrbiterA, 39U)) + aOrbiterD) + aNonceWordA);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 53U) + aOrbiterI) + RotL64(aOrbiterB, 19U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 46U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererK, 18U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordD;
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 19656U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((aIndex + 19016U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 17522U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17249U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aIngress, 38U)) ^ (RotL64(aPrevious, 5U) ^ RotL64(aCross, 53U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 53U)) + RotL64(aCarry, 13U)) + 2177539223979303669U;
            aOrbiterH = (aWandererE + RotL64(aCross, 3U)) + 3962004686551521471U;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 60U)) + RotL64(aCarry, 51U)) + 8457602312617147662U;
            aOrbiterJ = (aWandererA + RotL64(aScatter, 29U)) + 18011802451816510632U;
            aOrbiterB = (((aWandererB + RotL64(aCross, 11U)) + 9046101759168876832U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordK;
            aOrbiterG = (((aWandererI + RotL64(aIngress, 43U)) + 11135620637431969597U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordN;
            aOrbiterA = (aWandererK + RotL64(aScatter, 51U)) + 15913029940697999701U;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 5U)) + 16304193109948135982U;
            aOrbiterF = (aWandererG + RotL64(aScatter, 13U)) + 13208892298820080981U;
            aOrbiterI = ((aWandererC + RotL64(aCross, 38U)) + RotL64(aCarry, 41U)) + 4182377898949419225U;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 35U)) + 13970137023071326151U) + aNonceWordH;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 8402396284835248583U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 8859190834060657829U;
            aOrbiterC = RotL64((aOrbiterC * 13552418608113716117U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 9760005337757990392U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 14108277760135744897U;
            aOrbiterB = RotL64((aOrbiterB * 4474681104256093885U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 12226316121949012350U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 3456392186754113960U;
            aOrbiterG = RotL64((aOrbiterG * 8704729827929941215U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 5004087958637038973U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 7176881295123125567U;
            aOrbiterA = RotL64((aOrbiterA * 15272157962928021009U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 10889800478505074438U) + aNonceWordB;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 13728832441482547824U;
            aOrbiterK = RotL64((aOrbiterK * 17588477761978646139U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 17345665880706866772U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 301139993853297566U;
            aOrbiterF = RotL64((aOrbiterF * 5812445396758354505U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 2061389844760610160U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 13631862266139238355U;
            aOrbiterI = RotL64((aOrbiterI * 143613352104722701U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 10767186080827509622U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 4893486019456886013U;
            aOrbiterE = RotL64((aOrbiterE * 5194746459545610901U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 11264795916303477037U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 16013652139405432608U;
            aOrbiterD = RotL64((aOrbiterD * 14924257021089920495U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 5209743554932653849U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 13160179712987277456U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5003755912040281427U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 12440615920191945386U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 2177539223979303669U;
            aOrbiterJ = RotL64((aOrbiterJ * 3565122523239344029U), 19U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterA, 58U);
            aIngress = aIngress + (RotL64(aOrbiterH, 21U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 39U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 18U) + aOrbiterE) + RotL64(aOrbiterB, 30U));
            aWandererE = aWandererE + ((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 19U)) + aOrbiterA);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterG, 11U));
            aWandererF = aWandererF + (((RotL64(aIngress, 51U) + aOrbiterI) + RotL64(aOrbiterE, 53U)) + aNonceWordO);
            aWandererI = aWandererI ^ (((RotL64(aCross, 37U) + aOrbiterK) + RotL64(aOrbiterC, 3U)) + aPhaseDWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 21U) + aOrbiterK) + RotL64(aOrbiterJ, 51U)) + aPhaseDWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterE, 26U)) + aOrbiterK);
            aWandererK = aWandererK + (((RotL64(aIngress, 34U) + RotL64(aOrbiterI, 57U)) + aOrbiterH) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterF, 37U));
            aWandererH = aWandererH + (((RotL64(aCross, 23U) + aOrbiterD) + RotL64(aOrbiterA, 39U)) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 13U)) + aOrbiterG) + aNonceWordM);
            //
            aCarry = aCarry + (RotL64(aWandererI, 34U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + RotL64(aWandererF, 46U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordG);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 26529U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22049U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 23252U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneA[((aIndex + 22892U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 43U) ^ RotL64(aCarry, 11U)) + (RotL64(aCross, 24U) + RotL64(aIngress, 57U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterG = (aWandererB + RotL64(aScatter, 3U)) + 1142447269198373880U;
            aOrbiterF = (((aWandererE + RotL64(aPrevious, 21U)) + RotL64(aCarry, 13U)) + 10581460640040336191U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aIngress, 53U)) + 14703062773878202900U;
            aOrbiterI = (aWandererI + RotL64(aCross, 51U)) + 15737525756286914746U;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 39U)) + 16178774478273186999U) + aNonceWordM;
            aOrbiterK = ((aWandererF + RotL64(aCross, 46U)) + 2514897053906809160U) + aNonceWordP;
            aOrbiterA = (aWandererD + RotL64(aPrevious, 41U)) + 13702496607592508464U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 19U)) + RotL64(aCarry, 47U)) + 18030885275418337965U;
            aOrbiterD = (((aWandererK + RotL64(aIngress, 35U)) + RotL64(aCarry, 19U)) + 5241783876161655984U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aScatter, 6U)) + 2807052676283587925U;
            aOrbiterC = (aWandererJ + RotL64(aCross, 23U)) + 8022804576763271327U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 15597099852232205860U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 1538435607932096400U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7900752511710516981U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 11147868774413615365U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 9325213746830411568U;
            aOrbiterK = RotL64((aOrbiterK * 561819005818948769U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 13792300423550555634U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 3134856508983945719U;
            aOrbiterB = RotL64((aOrbiterB * 4271845067763664863U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 8654966018053784882U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 8937113935476779267U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7386875687217705855U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 4135676350355234788U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 11407912615743682678U;
            aOrbiterG = RotL64((aOrbiterG * 2773506587480714695U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 10966950663872392059U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 6686634993700944582U;
            aOrbiterI = RotL64((aOrbiterI * 2509459942163678241U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 14154407529749257990U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 18054640398549782388U;
            aOrbiterA = RotL64((aOrbiterA * 7830759861389060149U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 14623473030642960240U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 1857945571104460086U;
            aOrbiterD = RotL64((aOrbiterD * 18039903315045620079U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 17650774450811065797U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 9458168381246672881U) ^ aNonceWordD;
            aOrbiterC = RotL64((aOrbiterC * 3452665113988737563U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 16604923466236483242U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 12447748535184711684U;
            aOrbiterF = RotL64((aOrbiterF * 5982708155382249061U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 9589720286549780720U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 1142447269198373880U;
            aOrbiterJ = RotL64((aOrbiterJ * 8176719948031280789U), 3U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 29U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 24U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 5U));
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + RotL64(aOrbiterH, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterD, 29U)) + aOrbiterA) + aNonceWordN);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 11U) + aOrbiterK) + RotL64(aOrbiterA, 39U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterB, 11U)) + aOrbiterF);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterF, 60U)) + RotL64(aCarry, 41U)) + aPhaseDWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 18U) + RotL64(aOrbiterG, 19U)) + aOrbiterH) + aPhaseDWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 21U) + RotL64(aOrbiterF, 41U)) + aOrbiterG) + aNonceWordA);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 13U)) + aOrbiterK);
            aWandererA = aWandererA + ((((RotL64(aIngress, 41U) + RotL64(aOrbiterG, 57U)) + aOrbiterJ) + RotL64(aCarry, 5U)) + aNonceWordH);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 46U) + RotL64(aOrbiterI, 54U)) + aOrbiterA);
            aWandererI = aWandererI + ((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 47U)) + aOrbiterD);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 37U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 48U));
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + RotL64(aWandererJ, 39U);
            aCarry = aCarry + RotL64(aIngress, 20U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordM);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 32624U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((aIndex + 28050U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28286U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneB[((aIndex + 30987U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 6U) + RotL64(aCross, 21U)) ^ (RotL64(aCarry, 57U) + RotL64(aIngress, 41U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterH = (aWandererK + RotL64(aPrevious, 27U)) + 1297415699043177788U;
            aOrbiterI = (aWandererH + RotL64(aCross, 50U)) + 17583786534509260153U;
            aOrbiterB = (aWandererF + RotL64(aScatter, 43U)) + 643197858925708798U;
            aOrbiterA = (aWandererJ + RotL64(aIngress, 3U)) + 5062653766915694874U;
            aOrbiterC = (aWandererC + RotL64(aCross, 57U)) + 7034273638367180511U;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 20U)) + 2026909726972916996U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = (((aWandererI + RotL64(aIngress, 11U)) + RotL64(aCarry, 29U)) + 2785690475553211646U) + aNonceWordC;
            aOrbiterF = (aWandererB + RotL64(aScatter, 23U)) + 2910341716302991892U;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 39U)) + 2834181605200829791U) + aNonceWordA;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 37U)) + RotL64(aCarry, 37U)) + 13323052600571281928U;
            aOrbiterK = (((aWandererD + RotL64(aPrevious, 13U)) + RotL64(aCarry, 23U)) + 10434901530315760460U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 247903955625194782U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 5196515747387257163U;
            aOrbiterB = RotL64((aOrbiterB * 1799024689023272275U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 7196305682377987476U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 14777739876892587484U;
            aOrbiterC = RotL64((aOrbiterC * 95220583948241581U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 10609060796540136671U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 8386027207212484155U;
            aOrbiterG = RotL64((aOrbiterG * 4855610536246556893U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 729659744301903424U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 2350564261412606157U) ^ aNonceWordK;
            aOrbiterE = RotL64((aOrbiterE * 16713856782349084977U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 16611987556673864177U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 1525195188708550503U) ^ aNonceWordF;
            aOrbiterF = RotL64((aOrbiterF * 10045858602151004553U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 4654808490980989596U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 8189569777087686263U;
            aOrbiterJ = RotL64((aOrbiterJ * 17278657566389299577U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 10932857495004451792U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 1833880112534916813U;
            aOrbiterD = RotL64((aOrbiterD * 8004341577533825681U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 13100236350175516423U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 2773759534195186313U;
            aOrbiterK = RotL64((aOrbiterK * 3194954066097323161U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 13963126688973399221U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 1464529855671190406U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6129954747502059213U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 9489842625026216815U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 17806120432918490594U;
            aOrbiterI = RotL64((aOrbiterI * 349307975773661379U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 13833297268854563081U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 1297415699043177788U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4818542043777342249U), 41U);
            //
            aIngress = RotL64(aOrbiterC, 20U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterJ, 19U));
            aWandererG = aWandererG + (((RotL64(aIngress, 53U) + RotL64(aOrbiterF, 48U)) + aOrbiterI) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterI, 13U)) + aOrbiterG) + aNonceWordD);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 11U) + aOrbiterK) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 21U)) + aPhaseDWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 43U) + aOrbiterE) + RotL64(aOrbiterD, 21U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 36U) + aOrbiterC) + RotL64(aOrbiterG, 5U)) + aPhaseDWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 43U)) + aOrbiterI);
            aWandererI = aWandererI + (((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 23U)) + aOrbiterJ) + aNonceWordL);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 23U) + aOrbiterE) + RotL64(aOrbiterG, 58U));
            aWandererE = aWandererE + (((RotL64(aCross, 38U) + RotL64(aOrbiterA, 37U)) + aOrbiterB) + aNonceWordM);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 51U) + aOrbiterJ) + RotL64(aOrbiterG, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 48U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + RotL64(aWandererG, 34U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordJ;
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

void TwistExpander_Badminton_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x99494CB7C3A25211ULL + 0x9F13BD7FE4F4405AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xA7C020762A1CBFF1ULL + 0xEA154AFEBA7EB954ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xA9F2ABB8F786D3CFULL + 0xDE27B90A63C5A2CAULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x8320A8A74FF5216FULL + 0xAAEB54796EB5822BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xEA856326E9E25505ULL + 0x903826B66F384F61ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x8BA6A9F1773436DBULL + 0xBE19AA7FC464D014ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xC9D2DFFAA87FA967ULL + 0x9BC0430968E4CCB6ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xDC741FF0E1ADA58FULL + 0x8FF893D9C03E5ACCULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xE77819A17E89F897ULL + 0x9B8283CF196B1FF9ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xE4C972DFD1020F29ULL + 0xF6FE9DB092E84E0BULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x82051BC46EBBE345ULL + 0x9ACB979006AF31E2ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xCCBABCCA765A17ABULL + 0xB84004544DC4404FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xBE322EC519620C99ULL + 0xC55C960156303398ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xF6E66E08561F9ACBULL + 0xC45B169995A89ED2ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xA1D629EFA957EC65ULL + 0xFFCFACCA3F0895EEULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xA9733D3E5233AC63ULL + 0xC0CD3782FC51F2D7ULL);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 1502U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneC[((aIndex + 1399U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 707U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 2359U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 56U) ^ RotL64(aPrevious, 23U)) + (RotL64(aCarry, 39U) + RotL64(aIngress, 5U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 21U)) + 3550722402315312207U) + aNonceWordM;
            aOrbiterK = (((aWandererG + RotL64(aCross, 43U)) + RotL64(aCarry, 51U)) + 16724184551669522754U) + aNonceWordD;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 56U)) + RotL64(aCarry, 11U)) + 981751330116773021U;
            aOrbiterB = (aWandererI + RotL64(aPrevious, 53U)) + 7891159229704944868U;
            aOrbiterI = (aWandererK + RotL64(aCross, 37U)) + 13618396711464799841U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 51U)) + 5969291018449003648U) + aPhaseEOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aIngress, 39U)) + 14595540413313640042U;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 41U)) + RotL64(aCarry, 29U)) + 3287990436916111762U;
            aOrbiterD = (aWandererA + RotL64(aIngress, 11U)) + 12534369400200483704U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 58U)) + 2277312067930392274U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = (aWandererC + RotL64(aPrevious, 13U)) + 10026320559261334353U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 11258082063135659551U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 1445958517675746990U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10062265337488757971U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 1011298251290970844U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 6487834862470043744U;
            aOrbiterE = RotL64((aOrbiterE * 15477913837027179675U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 9966279022928268335U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 10285993486057704393U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15965714363201157535U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 16005362468813966136U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 223843444699390781U;
            aOrbiterB = RotL64((aOrbiterB * 665392038954573081U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 18178876294968532775U) + aNonceWordH;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 12490136112181806806U;
            aOrbiterH = RotL64((aOrbiterH * 16380841616662993709U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 8775696166557913635U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 16464340319444310842U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 18111632334728200721U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 6296039992673546227U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 7152939277656436037U;
            aOrbiterG = RotL64((aOrbiterG * 15183918431501487319U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 14066791413416223271U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 5026743227399908016U;
            aOrbiterK = RotL64((aOrbiterK * 5891343232759075675U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 12923870516588764609U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 2509970166609982397U;
            aOrbiterI = RotL64((aOrbiterI * 10708677957633925007U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 15155802288437422950U) + aNonceWordC;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 15615656627428205711U;
            aOrbiterF = RotL64((aOrbiterF * 6199439196177598589U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 17233751123865498186U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 3550722402315312207U;
            aOrbiterA = RotL64((aOrbiterA * 2247546626523919155U), 47U);
            //
            aIngress = RotL64(aOrbiterE, 3U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + (RotL64(aOrbiterF, 14U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 48U)) + aOrbiterB) + RotL64(aCarry, 27U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 37U) + aOrbiterE) + RotL64(aOrbiterF, 41U));
            aWandererD = aWandererD + (((RotL64(aCross, 23U) + RotL64(aOrbiterD, 43U)) + aOrbiterG) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterI, 3U)) + aNonceWordN);
            aWandererK = aWandererK + ((RotL64(aCross, 54U) + RotL64(aOrbiterF, 50U)) + aOrbiterJ);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterK, 27U)) + aOrbiterG);
            aWandererC = aWandererC + (((RotL64(aScatter, 51U) + RotL64(aOrbiterJ, 53U)) + aOrbiterC) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterJ, 5U));
            aWandererE = aWandererE + (((RotL64(aScatter, 41U) + aOrbiterI) + RotL64(aOrbiterJ, 35U)) + aNonceWordB);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 58U) + RotL64(aOrbiterC, 57U)) + aOrbiterG);
            aWandererH = aWandererH + ((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 29U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (RotL64(aWandererK, 18U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ aNonceWordN;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 8968U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8806U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 10778U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 9835U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 47U) ^ RotL64(aCross, 5U)) ^ (RotL64(aCarry, 35U) + RotL64(aIngress, 20U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterK = (aWandererI + RotL64(aPrevious, 11U)) + 18191288703716505885U;
            aOrbiterD = ((((aWandererC + RotL64(aCross, 37U)) + RotL64(aCarry, 43U)) + 9824014524910417136U) + aPhaseEOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = (aWandererG + RotL64(aScatter, 44U)) + 11953012029254917548U;
            aOrbiterH = (aWandererB + RotL64(aIngress, 23U)) + 6297568011027199089U;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 57U)) + 2576999400457367975U;
            aOrbiterF = ((aWandererA + RotL64(aCross, 51U)) + 13176139160575558254U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 13U)) + 9978408174563621810U) + aNonceWordL;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 27U)) + RotL64(aCarry, 53U)) + 16765834875061607142U;
            aOrbiterE = (aWandererH + RotL64(aCross, 60U)) + 16534507305459121344U;
            aOrbiterI = (aWandererF + RotL64(aScatter, 5U)) + 3114710944346151807U;
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 21U)) + RotL64(aCarry, 11U)) + 10240517868726718592U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 10721450637990777883U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 16689590768796583952U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3046344179729901637U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 2427422768928450209U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 13495584061816457831U;
            aOrbiterD = RotL64((aOrbiterD * 6670984773768885119U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 7058636403765106682U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 9897341853944713767U;
            aOrbiterJ = RotL64((aOrbiterJ * 14286816859999869231U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 17749559755733386064U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 12515645083926326659U) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 6582878478865838245U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 2625692458813609962U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 10596240255026143019U) ^ aNonceWordP;
            aOrbiterE = RotL64((aOrbiterE * 11605800195771080135U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 12374290338067865540U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 1507386663796330249U;
            aOrbiterK = RotL64((aOrbiterK * 1210241080424446087U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 9288099549484146726U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 15159312464747000702U;
            aOrbiterH = RotL64((aOrbiterH * 500055502081347757U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 14998608679505446229U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 17625038109437732009U;
            aOrbiterF = RotL64((aOrbiterF * 14785862243019841689U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 10543192232885637211U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 10330547522729618042U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7635903835474874057U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 5753298214283941201U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 15943436872588208065U) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 17704547766822075741U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 5757218926946874970U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 18191288703716505885U;
            aOrbiterB = RotL64((aOrbiterB * 2644970408001409575U), 47U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterH, 36U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 21U) + aOrbiterI) + RotL64(aOrbiterH, 30U));
            aWandererC = aWandererC + (((RotL64(aCross, 41U) + aOrbiterB) + RotL64(aOrbiterI, 19U)) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 41U)) + aOrbiterB) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 57U) + aOrbiterC) + RotL64(aOrbiterA, 21U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 26U) + RotL64(aOrbiterE, 13U)) + aOrbiterB);
            aWandererF = aWandererF + (((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterB, 3U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 43U)) + aOrbiterF) + aNonceWordM);
            aWandererH = aWandererH + (((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 47U)) + aOrbiterG) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 44U) + RotL64(aOrbiterD, 28U)) + aOrbiterC);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 39U) + aOrbiterC) + RotL64(aOrbiterF, 35U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 11U) + aOrbiterK) + RotL64(aOrbiterB, 39U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 52U));
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 40U));
            aCarry = aCarry + RotL64(aWandererJ, 21U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 11594U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 16348U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 11810U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 13514U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aIngress, 41U)) ^ (RotL64(aCross, 3U) + RotL64(aPrevious, 18U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterD = ((aWandererD + RotL64(aCross, 21U)) + 4068921616130916949U) + aNonceWordJ;
            aOrbiterI = (((aWandererE + RotL64(aPrevious, 51U)) + RotL64(aCarry, 37U)) + 12077715273915151726U) + aNonceWordB;
            aOrbiterF = (((aWandererH + RotL64(aScatter, 39U)) + RotL64(aCarry, 23U)) + 16047546802670596833U) + aPhaseEOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aIngress, 24U)) + RotL64(aCarry, 29U)) + 9690277462716999763U;
            aOrbiterK = (aWandererB + RotL64(aScatter, 41U)) + 14484814700447992628U;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 5U)) + 17089267243053958210U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = (aWandererC + RotL64(aPrevious, 53U)) + 9138746214446211147U;
            aOrbiterJ = (aWandererJ + RotL64(aCross, 29U)) + 10181001536979097045U;
            aOrbiterA = (aWandererF + RotL64(aIngress, 60U)) + 6657458969093373191U;
            aOrbiterE = (aWandererA + RotL64(aCross, 47U)) + 7515983477876590988U;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 43U)) + 3039935555863947600U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 16209389224740851136U) + aNonceWordM;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 725253312098083182U;
            aOrbiterF = RotL64((aOrbiterF * 17535989492095522597U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 13307041115748941383U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 7159572004825238263U;
            aOrbiterH = RotL64((aOrbiterH * 4855009895002398449U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 12027236743251643820U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 8717826175991286553U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1175614802543098451U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 4769096034227659937U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 11201226563992939616U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15595355978388159931U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 17295978531215563256U) + aNonceWordH;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 11850923890626719833U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3854851059897397075U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 14139441565288097706U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 988684899382304485U;
            aOrbiterE = RotL64((aOrbiterE * 11929090869999700891U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 6159251276942253175U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 4849529993914550651U;
            aOrbiterD = RotL64((aOrbiterD * 18240712676783671317U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 6679745455842119497U) + aNonceWordG;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 15838404437552215214U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17357853511591350887U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 15853153471104458948U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 12542164757451566994U;
            aOrbiterB = RotL64((aOrbiterB * 12163611303899312043U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 14304233464055838869U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 4037999346933039765U;
            aOrbiterA = RotL64((aOrbiterA * 564236202758328407U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 3582312827630995454U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 4068921616130916949U;
            aOrbiterC = RotL64((aOrbiterC * 1527829107415867363U), 23U);
            //
            aIngress = RotL64(aOrbiterI, 5U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterK, 50U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aIngress, 47U) + aOrbiterH) + RotL64(aOrbiterJ, 11U)) + RotL64(aCarry, 5U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 38U) + aOrbiterD) + RotL64(aOrbiterA, 34U));
            aWandererC = aWandererC + (((RotL64(aCross, 51U) + aOrbiterA) + RotL64(aOrbiterJ, 53U)) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterE, 27U));
            aWandererG = aWandererG + ((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterA, 13U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterF, 37U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterK, 19U)) + aOrbiterC) + aNonceWordE);
            aWandererF = aWandererF ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterB, 5U)) + aOrbiterH);
            aWandererI = aWandererI + (((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterG, 21U)) + aPhaseEWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 54U) + RotL64(aOrbiterG, 41U)) + aOrbiterF) + aNonceWordO);
            aWandererH = aWandererH + ((RotL64(aCross, 41U) + aOrbiterF) + RotL64(aOrbiterD, 56U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 12U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 58U));
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 20254U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneB[((aIndex + 20112U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21373U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 17253U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 43U) + RotL64(aCross, 26U)) + (RotL64(aCarry, 57U) ^ RotL64(aIngress, 13U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterC = ((aWandererF + RotL64(aIngress, 27U)) + 13442819395490639310U) + aNonceWordD;
            aOrbiterA = (((aWandererK + RotL64(aPrevious, 14U)) + RotL64(aCarry, 53U)) + 8187292523194120936U) + aNonceWordN;
            aOrbiterJ = (((aWandererE + RotL64(aCross, 23U)) + RotL64(aCarry, 19U)) + 11469697159823131388U) + aNonceWordJ;
            aOrbiterH = (aWandererC + RotL64(aScatter, 57U)) + 13414083692375929653U;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 39U)) + 11404010733687907517U) + aPhaseEOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aScatter, 60U)) + 6783212827186218247U;
            aOrbiterI = ((aWandererH + RotL64(aCross, 3U)) + 8561131439340372614U) + aPhaseEOrbiterAssignSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aIngress, 5U)) + RotL64(aCarry, 3U)) + 6252609642004429113U;
            aOrbiterD = (aWandererG + RotL64(aScatter, 47U)) + 12804867444200448952U;
            aOrbiterG = (aWandererJ + RotL64(aIngress, 51U)) + 2739648749603690781U;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 11U)) + 14808861217017399752U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 17588866502571268888U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 5882260142735642980U) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 7688252946143263869U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 15493099088132862949U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterA) ^ 5175647411532429582U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterK = RotL64((aOrbiterK * 15226544495598541883U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 14279707376173642767U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 6826363572161275158U;
            aOrbiterF = RotL64((aOrbiterF * 5263708315440161809U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 13267185753040999992U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 9980987858092888720U;
            aOrbiterI = RotL64((aOrbiterI * 13210290848800728635U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 3582972937645514549U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 10140409019562890804U;
            aOrbiterE = RotL64((aOrbiterE * 6944490201647678479U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 6160444117287330557U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 16344602960561293113U;
            aOrbiterD = RotL64((aOrbiterD * 2319964919335633293U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 3497141036108337171U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 91269118352540308U;
            aOrbiterG = RotL64((aOrbiterG * 5160060720189045505U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 12739932748793144857U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 12820180915064791197U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5843849637411948699U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 17572075652083359962U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 10684041099654982701U;
            aOrbiterC = RotL64((aOrbiterC * 7121293375756263771U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 10739534650885677354U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 9731206787727954809U;
            aOrbiterA = RotL64((aOrbiterA * 3730875775588585547U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 9655432616347117764U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 13442819395490639310U;
            aOrbiterH = RotL64((aOrbiterH * 3650859301708619119U), 29U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterI, 11U);
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + RotL64(aOrbiterG, 28U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterH, 46U)) + RotL64(aCarry, 35U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterJ, 39U)) + aOrbiterC);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 51U)) + aOrbiterE) + RotL64(aCarry, 23U)) + aNonceWordO);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterB, 43U)) + aOrbiterA);
            aWandererE = aWandererE + ((RotL64(aScatter, 18U) + RotL64(aOrbiterB, 35U)) + aOrbiterK);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterA, 37U)) + aPhaseEWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 35U) + RotL64(aOrbiterI, 21U)) + aOrbiterC) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterK, 3U)) + aOrbiterE);
            aWandererA = aWandererA + ((RotL64(aCross, 29U) + aOrbiterE) + RotL64(aOrbiterI, 48U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 23U)) + aOrbiterH);
            aWandererC = aWandererC + ((RotL64(aScatter, 48U) + RotL64(aOrbiterD, 11U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 44U));
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 52U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordJ;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 24387U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneA[((aIndex + 24163U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 22473U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25580U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCross, 37U)) ^ (RotL64(aIngress, 3U) ^ RotL64(aCarry, 50U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterB = ((aWandererJ + RotL64(aCross, 19U)) + RotL64(aCarry, 53U)) + 13650869943246163567U;
            aOrbiterE = (((aWandererF + RotL64(aScatter, 41U)) + 3435284932011770999U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordI;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 44U)) + 12388155658186776579U;
            aOrbiterK = (aWandererC + RotL64(aIngress, 35U)) + 2374345913955712039U;
            aOrbiterG = (aWandererG + RotL64(aCross, 39U)) + 6095094526980292156U;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 21U)) + RotL64(aCarry, 27U)) + 4965147025852444174U;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 51U)) + 3261881216269075298U;
            aOrbiterJ = (((aWandererE + RotL64(aScatter, 27U)) + 4939780217097329222U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordM;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 12U)) + RotL64(aCarry, 23U)) + 3019862009792676287U;
            aOrbiterH = (aWandererD + RotL64(aScatter, 29U)) + 901910626217143974U;
            aOrbiterI = (aWandererK + RotL64(aIngress, 57U)) + 3647055146712366383U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 7731765438957392967U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 13409819457393479741U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3345078200262410715U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 5415832109107794258U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 8876738832313114471U;
            aOrbiterA = RotL64((aOrbiterA * 1304277600444504135U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 17135570542519390359U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 2373193062766802082U) ^ aNonceWordP;
            aOrbiterJ = RotL64((aOrbiterJ * 4213691513185791519U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 16318403285501718552U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 8456043288604687045U;
            aOrbiterH = RotL64((aOrbiterH * 10556964529144571683U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 10572534930284516528U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 14616251186735204677U;
            aOrbiterB = RotL64((aOrbiterB * 2048651204265459805U), 47U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterH) + 2837006243817205610U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1]) + aNonceWordG;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 5315917323622194254U;
            aOrbiterK = RotL64((aOrbiterK * 4080522050089666599U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 12084676282761185907U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 7922080344175593788U;
            aOrbiterD = RotL64((aOrbiterD * 7603522302708937379U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 17620847289789547792U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 12140386059533463650U;
            aOrbiterF = RotL64((aOrbiterF * 1443266480620969535U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 4006608081473218762U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 3152507055132739011U;
            aOrbiterI = RotL64((aOrbiterI * 11929522909695002321U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 10845720206369283181U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 16572752872386133133U;
            aOrbiterE = RotL64((aOrbiterE * 2891952650448087211U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 15544908026178481075U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 13650869943246163567U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1275090431127426217U), 3U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterC, 5U);
            aIngress = aIngress + (RotL64(aOrbiterI, 56U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterG, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 13U) + aOrbiterE) + RotL64(aOrbiterK, 48U));
            aWandererE = aWandererE + ((RotL64(aCross, 41U) + aOrbiterC) + RotL64(aOrbiterG, 53U));
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 6U) + RotL64(aOrbiterB, 29U)) + aOrbiterG) + aNonceWordN) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 23U)) + aOrbiterB);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 51U)) + aOrbiterJ);
            aWandererB = aWandererB + (((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 11U)) + aOrbiterD) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterE, 18U)) + aOrbiterF) + aNonceWordE);
            aWandererD = aWandererD + (((RotL64(aPrevious, 21U) + aOrbiterE) + RotL64(aOrbiterJ, 43U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 50U) + RotL64(aOrbiterI, 3U)) + aOrbiterH);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 43U) + RotL64(aOrbiterF, 57U)) + aOrbiterH) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterA, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 28U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 32035U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((aIndex + 29029U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30437U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneB[((aIndex + 27937U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCarry, 35U)) + (RotL64(aPrevious, 47U) + RotL64(aCross, 6U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterD = ((aWandererD + RotL64(aScatter, 21U)) + RotL64(aCarry, 5U)) + 18302975933754610273U;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 37U)) + RotL64(aCarry, 51U)) + 16736972646771456082U;
            aOrbiterH = (((aWandererH + RotL64(aCross, 39U)) + 17389406266488137442U) + aPhaseEOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1]) + aNonceWordG;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 11U)) + 5252511566486165539U;
            aOrbiterF = (aWandererG + RotL64(aScatter, 50U)) + 5730715427422747640U;
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 19U)) + 6412695646456045825U) + aPhaseEOrbiterAssignSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aPrevious, 41U)) + 9539701605708994494U;
            aOrbiterC = (((aWandererE + RotL64(aCross, 3U)) + RotL64(aCarry, 23U)) + 18355107116412945722U) + aNonceWordE;
            aOrbiterE = (aWandererI + RotL64(aIngress, 47U)) + 11735742491750132942U;
            aOrbiterK = (aWandererC + RotL64(aPrevious, 28U)) + 12363819388562658842U;
            aOrbiterB = (aWandererA + RotL64(aScatter, 35U)) + 5861430292304371543U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 15027487084595017708U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 7012850020745791926U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15952928839355613939U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 11904871669287886120U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 11199760114477343208U) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 7156374911847525867U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 3856004502263742700U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 3705931243173921893U;
            aOrbiterJ = RotL64((aOrbiterJ * 10334871178498711485U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 12305785390539209389U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 18057980996551978823U) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 4850564181113470859U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 3229431819292153014U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 2994716629242460094U;
            aOrbiterC = RotL64((aOrbiterC * 1029427328395257917U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 9796307843453735512U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 2957260393651252432U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7261055869794739609U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 4060469664218866340U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterG) ^ 17462081697889685330U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 7712009170974461225U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 13638660073917821172U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 15202349592659062565U;
            aOrbiterB = RotL64((aOrbiterB * 4514326257446024301U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 12071949111168967041U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 11930843273199806728U;
            aOrbiterD = RotL64((aOrbiterD * 16229663295689525137U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 11294220104731500296U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 440743185210586759U;
            aOrbiterI = RotL64((aOrbiterI * 14810195235168807229U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 8514240764798061804U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 18302975933754610273U;
            aOrbiterA = RotL64((aOrbiterA * 1972439346780950873U), 5U);
            //
            aIngress = RotL64(aOrbiterE, 19U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterK, 24U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aCross, 5U) + RotL64(aOrbiterF, 29U)) + aOrbiterD) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 27U) + aOrbiterB) + RotL64(aOrbiterC, 11U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterB, 35U)) + aOrbiterJ) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 58U)) + aOrbiterI) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 21U) + RotL64(aOrbiterA, 21U)) + aOrbiterK);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 19U) + aOrbiterE) + RotL64(aOrbiterJ, 27U)) + aPhaseEWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 10U) + aOrbiterH) + RotL64(aOrbiterC, 13U)) + aNonceWordI);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 39U) + aOrbiterF) + RotL64(aOrbiterJ, 18U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 35U) + RotL64(aOrbiterG, 23U)) + aOrbiterJ);
            aWandererA = aWandererA ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterF, 47U)) + aOrbiterE) + aNonceWordB);
            aWandererH = aWandererH + (((RotL64(aPrevious, 48U) + aOrbiterA) + RotL64(aOrbiterJ, 3U)) + aNonceWordJ);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (RotL64(aWandererJ, 38U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + RotL64(aWandererK, 6U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordO);
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

void TwistExpander_Badminton_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xD2401A5528A236DBULL + 0x805C49C09B4551E0ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x813E3B46A844829DULL + 0xC51FA820000EACA4ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xF30235FE01F5E839ULL + 0xC855E2DDF4B332DEULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x9018660109371341ULL + 0xE11E890B3CC5CA91ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xD6CC596CDF60EBBFULL + 0xB921876C7356C988ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x86C2783AB2DDF21DULL + 0xFB3E3460CC7494DDULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xCCB43F0CC852ADBDULL + 0xDE6CC1B941A30C1DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x824D05B5DFD4A617ULL + 0xF63D1B26C010DCA5ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xAE4C955A1A311739ULL + 0xBEE95CDF3C46B76EULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x9D0B0B1BFB26E8FDULL + 0xE1BA79DFEC7BF48BULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xA15FBF2A866A4C45ULL + 0xD5D426F2341A81C8ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xE07C58ABF982E585ULL + 0x8387E48B2ADF2F3AULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x92E656BCC58B9FD5ULL + 0xB8A9D75CDE4B1E89ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xB1A3816A68D6B2FFULL + 0xEEC632E4C145968EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xC448980EE5090B19ULL + 0x8B1D1DDDCC4A93A4ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xA7C5F2922CB3C63FULL + 0xA355E074AE72C6D5ULL);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 624U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((aIndex + 2535U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 2755U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 492U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 34U) + RotL64(aCross, 53U)) + (RotL64(aCarry, 5U) ^ RotL64(aIngress, 21U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = (((aWandererE + RotL64(aPrevious, 21U)) + RotL64(aCarry, 43U)) + 16462052553719977502U) + aNonceWordF;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 56U)) + 12337064059566619581U;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 47U)) + 15801005007094515447U) + aNonceWordI;
            aOrbiterA = (aWandererC + RotL64(aCross, 43U)) + 8228706742665081656U;
            aOrbiterK = (aWandererA + RotL64(aPrevious, 5U)) + 11006723027845190869U;
            aOrbiterC = ((aWandererB + RotL64(aScatter, 29U)) + 18173765337829177450U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aCross, 37U)) + RotL64(aCarry, 47U)) + 530215083653542558U;
            aOrbiterG = ((aWandererG + RotL64(aIngress, 3U)) + 6608611827035564511U) + aNonceWordJ;
            aOrbiterD = (((aWandererF + RotL64(aScatter, 40U)) + RotL64(aCarry, 51U)) + 2246051826221626809U) + aPhaseFOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aIngress, 19U)) + 5228575308895381421U;
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 27U)) + 10999213210689606857U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 3773371037240485696U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 8887985779436152504U;
            aOrbiterB = RotL64((aOrbiterB * 698713082830739677U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 11150566414723818350U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 8336366151003049546U;
            aOrbiterC = RotL64((aOrbiterC * 9033771197242493699U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 13233968794237090787U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 8172558473508478819U;
            aOrbiterI = RotL64((aOrbiterI * 17837070423649268435U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 133564480283347997U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 15104810248883567064U) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 706802420642303533U), 39U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterB) + 9138629520201127075U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordE;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 13993086066341664080U;
            aOrbiterF = RotL64((aOrbiterF * 4875046427147105077U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 6547273508580516932U) + aNonceWordK;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 9838727018769865759U;
            aOrbiterD = RotL64((aOrbiterD * 11395273371936839815U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 11685694999526122626U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 8945983172566303116U;
            aOrbiterJ = RotL64((aOrbiterJ * 17791527981004597623U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 17606249889617356327U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 9296903152000480008U;
            aOrbiterE = RotL64((aOrbiterE * 18066622289408024413U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 14248192861977167583U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 5467843420970464193U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10121398470914323221U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 17072313558131700643U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 7932446176598954438U;
            aOrbiterG = RotL64((aOrbiterG * 11684711939539349335U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 15377107166135929052U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 16462052553719977502U;
            aOrbiterH = RotL64((aOrbiterH * 9057188521274832217U), 5U);
            //
            aIngress = RotL64(aOrbiterB, 57U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 34U));
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 39U)) + aNonceWordC);
            aWandererA = aWandererA ^ ((RotL64(aCross, 14U) + RotL64(aOrbiterD, 58U)) + aOrbiterE);
            aWandererF = aWandererF + ((RotL64(aIngress, 41U) + aOrbiterE) + RotL64(aOrbiterJ, 51U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 37U) + aOrbiterJ) + RotL64(aOrbiterC, 23U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 53U) + aOrbiterC) + RotL64(aOrbiterA, 39U)) + RotL64(aCarry, 57U)) + aPhaseFWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 6U) + aOrbiterH) + RotL64(aOrbiterF, 29U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 3U)) + aOrbiterG);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterF, 37U)) + aOrbiterB);
            aWandererC = aWandererC + (((RotL64(aIngress, 51U) + aOrbiterE) + RotL64(aOrbiterK, 11U)) + aPhaseFWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterK, 27U));
            aWandererK = aWandererK + ((RotL64(aScatter, 27U) + aOrbiterJ) + RotL64(aOrbiterF, 54U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 50U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 20U);
            aCarry = aCarry ^ aNonceWordJ;
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8827U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 8447U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7997U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((aIndex + 6801U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCross, 3U)) ^ (RotL64(aIngress, 48U) + RotL64(aCarry, 23U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = (aWandererC + RotL64(aCross, 43U)) + 4752759164691497960U;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 35U)) + 12088872623537639782U;
            aOrbiterK = (((aWandererI + RotL64(aScatter, 13U)) + 3734943577379734227U) + aPhaseFOrbiterAssignSaltE[((aIndex + 12U)) & S_SALT1]) + aNonceWordK;
            aOrbiterB = (aWandererD + RotL64(aIngress, 18U)) + 8854778183012444234U;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 3U)) + 16948373492893967275U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aIngress, 21U)) + 7962415690046184385U) + aNonceWordN;
            aOrbiterD = (((aWandererH + RotL64(aPrevious, 39U)) + RotL64(aCarry, 19U)) + 1872682375669714454U) + aNonceWordC;
            aOrbiterI = ((aWandererF + RotL64(aCross, 54U)) + RotL64(aCarry, 47U)) + 7776801806943853566U;
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 11U)) + RotL64(aCarry, 37U)) + 16665439117257230732U;
            aOrbiterA = (aWandererE + RotL64(aScatter, 37U)) + 11088186766134265676U;
            aOrbiterH = (aWandererA + RotL64(aCross, 51U)) + 10850237991780969350U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 6464817712131305812U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 244557182884209844U;
            aOrbiterK = RotL64((aOrbiterK * 2394270354887582889U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 13261563971157415841U) + aNonceWordI;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 2323811103717827362U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11483723582415081925U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 12338803568475493422U) + aNonceWordE;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 2811342930111104982U;
            aOrbiterF = RotL64((aOrbiterF * 5020981755203607757U), 23U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterJ) + 5554497011738996057U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1]) + aNonceWordG;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 12712169745460598698U;
            aOrbiterD = RotL64((aOrbiterD * 1985586486150377769U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 17415058661427002973U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 9430421222715343818U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10321140659099470811U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 3926618548181233180U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 6172453297026957838U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1161551082037835233U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 8633288765997226004U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 17270881130844274342U;
            aOrbiterB = RotL64((aOrbiterB * 8888559940161770791U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 12232950994807835262U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 15352600312956742750U;
            aOrbiterE = RotL64((aOrbiterE * 6140396356904933003U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 5614120002595447983U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 1920822446545182835U;
            aOrbiterI = RotL64((aOrbiterI * 17049182594382482085U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 625576652179261739U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 2362773059031414585U;
            aOrbiterA = RotL64((aOrbiterA * 17049048587829564949U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 16749690978107177915U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 4752759164691497960U;
            aOrbiterH = RotL64((aOrbiterH * 8442185754037031199U), 27U);
            //
            aIngress = RotL64(aOrbiterA, 14U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 4U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 44U) + aOrbiterK) + RotL64(aOrbiterF, 36U)) + aNonceWordD);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterE, 27U)) + aOrbiterA);
            aWandererI = aWandererI + ((RotL64(aCross, 23U) + RotL64(aOrbiterH, 21U)) + aOrbiterK);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 5U)) + aOrbiterA);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterJ, 53U)) + aOrbiterI) + RotL64(aCarry, 57U)) + aNonceWordJ);
            aWandererD = aWandererD ^ ((RotL64(aCross, 14U) + RotL64(aOrbiterH, 29U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 47U)) + aOrbiterH);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 19U)) + aOrbiterE) + aPhaseFWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 21U) + RotL64(aOrbiterF, 57U)) + aOrbiterD) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterC, 3U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 37U) + RotL64(aOrbiterC, 38U)) + aOrbiterG) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererD, 42U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 11627U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((aIndex + 13753U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 11738U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15768U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aIngress, 42U)) + (RotL64(aPrevious, 11U) ^ RotL64(aCross, 57U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = (aWandererB + RotL64(aPrevious, 37U)) + 4384716820085860551U;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 41U)) + 9715780315942116888U) + aPhaseFOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = (aWandererG + RotL64(aCross, 29U)) + 15963520052789178632U;
            aOrbiterK = (aWandererI + RotL64(aScatter, 34U)) + 14346700690686392938U;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 13U)) + 6005518012489966643U;
            aOrbiterH = (aWandererA + RotL64(aScatter, 11U)) + 2506732930310252119U;
            aOrbiterG = (aWandererF + RotL64(aCross, 5U)) + 16782163084851775826U;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 57U)) + RotL64(aCarry, 57U)) + 823673076571076303U;
            aOrbiterI = ((((aWandererC + RotL64(aCross, 21U)) + RotL64(aCarry, 11U)) + 1634084509064077736U) + aPhaseFOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1]) + aNonceWordE;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 60U)) + RotL64(aCarry, 27U)) + 1288134975466877686U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 39U)) + 2998220403162908444U) + aNonceWordP;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 220430672180734911U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 10223923547068528867U;
            aOrbiterA = RotL64((aOrbiterA * 12577370238343872139U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 11696469696177647608U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 6545430420379636963U;
            aOrbiterH = RotL64((aOrbiterH * 8387163146257553773U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 79691451831797107U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 8971444023498649419U;
            aOrbiterF = RotL64((aOrbiterF * 7148919880477390009U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 5624403902454498793U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 9468064161002030997U;
            aOrbiterD = RotL64((aOrbiterD * 8243560528100864595U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 4619361544913629805U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 12682446273369750704U;
            aOrbiterC = RotL64((aOrbiterC * 10879074713156075641U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 8728730962617599223U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 9099675924074253030U;
            aOrbiterB = RotL64((aOrbiterB * 5525644236954497523U), 19U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterG) + 3298303921318288541U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordF;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 5953276499411658358U;
            aOrbiterE = RotL64((aOrbiterE * 10565471305001292693U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 6725769507592688539U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 1057277456510215817U;
            aOrbiterK = RotL64((aOrbiterK * 8269412198279297075U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 11317925732206917722U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 17814749417006079067U;
            aOrbiterG = RotL64((aOrbiterG * 4369209051015735925U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 9258362135343403308U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 4873837345446960113U;
            aOrbiterI = RotL64((aOrbiterI * 14223381466269503273U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 7863380865835889675U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 4384716820085860551U;
            aOrbiterJ = RotL64((aOrbiterJ * 2003891033298374621U), 53U);
            //
            aIngress = RotL64(aOrbiterI, 23U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 43U));
            aIngress = aIngress + (RotL64(aOrbiterB, 48U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 5U) + RotL64(aOrbiterA, 47U)) + aOrbiterG) + aPhaseFWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterD, 35U)) + aOrbiterE) + aNonceWordC);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 14U) + aOrbiterF) + RotL64(aOrbiterG, 23U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterB, 13U)) + aOrbiterA) + aNonceWordB);
            aWandererI = aWandererI + ((((RotL64(aIngress, 39U) + aOrbiterC) + RotL64(aOrbiterI, 10U)) + RotL64(aCarry, 13U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 41U)) + aOrbiterE);
            aWandererE = aWandererE + (((RotL64(aScatter, 51U) + RotL64(aOrbiterH, 21U)) + aOrbiterI) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterD, 5U)) + aNonceWordJ);
            aWandererA = aWandererA + ((RotL64(aPrevious, 48U) + aOrbiterK) + RotL64(aOrbiterH, 56U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 57U) + aOrbiterE) + RotL64(aOrbiterI, 29U));
            aWandererG = aWandererG + ((RotL64(aScatter, 37U) + aOrbiterJ) + RotL64(aOrbiterA, 43U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 24U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + RotL64(aWandererG, 37U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 20019U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21236U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18357U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneD[((aIndex + 18946U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 13U) ^ RotL64(aCross, 43U)) + (RotL64(aPrevious, 30U) + RotL64(aCarry, 57U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = (((aWandererB + RotL64(aPrevious, 26U)) + RotL64(aCarry, 43U)) + 8767379393098711499U) + aNonceWordP;
            aOrbiterA = (((aWandererG + RotL64(aScatter, 13U)) + 7168159491580816433U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordG;
            aOrbiterH = (((aWandererI + RotL64(aIngress, 5U)) + RotL64(aCarry, 29U)) + 9879279829061883406U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aCross, 23U)) + RotL64(aCarry, 35U)) + 10537167136053399303U;
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 19U)) + 2839070018069188936U) + aNonceWordE;
            aOrbiterG = (aWandererD + RotL64(aPrevious, 50U)) + 13844278063968429732U;
            aOrbiterB = (aWandererK + RotL64(aCross, 37U)) + 11278946626186474646U;
            aOrbiterE = (aWandererA + RotL64(aIngress, 21U)) + 11798425216660557799U;
            aOrbiterD = (aWandererC + RotL64(aScatter, 29U)) + 7618446090703335192U;
            aOrbiterI = (aWandererJ + RotL64(aIngress, 41U)) + 695423597006983660U;
            aOrbiterK = (aWandererF + RotL64(aCross, 57U)) + 14344728202803488813U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 11656100506575697086U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 10384358779985773937U;
            aOrbiterH = RotL64((aOrbiterH * 247494692039140973U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 17585001605131977341U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 9964478171465522911U;
            aOrbiterJ = RotL64((aOrbiterJ * 13484044854790175315U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 2710943171829692624U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 17809072853457153057U;
            aOrbiterG = RotL64((aOrbiterG * 16341884203303271365U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 12814092033910687774U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterH) ^ 1743186323268668740U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 11150822630624332557U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 10750472346626754704U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 15925901217078035356U;
            aOrbiterE = RotL64((aOrbiterE * 9276504171291801637U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 2569102106359362359U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 8868261301410769739U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3662495603133918101U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 2143691008373582476U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 10606616796243205921U;
            aOrbiterI = RotL64((aOrbiterI * 15794414817813485643U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 16258070651850746855U) + aNonceWordC;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 11720192793689633315U) ^ aNonceWordD;
            aOrbiterK = RotL64((aOrbiterK * 14475623219460678021U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 8230871037292355675U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 16898650748046368353U;
            aOrbiterF = RotL64((aOrbiterF * 7368697435476300255U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 9071122174426904737U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 4506737259011736474U;
            aOrbiterA = RotL64((aOrbiterA * 11903039808814842447U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 4545409671845718259U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 8767379393098711499U;
            aOrbiterC = RotL64((aOrbiterC * 1210632171306946669U), 39U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 5U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + (RotL64(aOrbiterI, 60U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterB, 37U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aIngress, 53U) + aOrbiterD) + RotL64(aOrbiterC, 22U)) + aNonceWordN);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 35U) + aOrbiterJ) + RotL64(aOrbiterK, 5U));
            aWandererK = aWandererK + ((RotL64(aCross, 60U) + aOrbiterD) + RotL64(aOrbiterI, 29U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterA, 19U)) + aPhaseFWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 37U) + aOrbiterJ) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 53U)) + aOrbiterG) + aNonceWordI);
            aWandererG = aWandererG + (((RotL64(aScatter, 27U) + RotL64(aOrbiterH, 57U)) + aOrbiterC) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 11U) + aOrbiterF) + RotL64(aOrbiterH, 39U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterK, 41U)) + aOrbiterB) + aPhaseFWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 39U) + aOrbiterB) + RotL64(aOrbiterA, 13U));
            aWandererA = aWandererA + ((RotL64(aIngress, 48U) + RotL64(aOrbiterE, 46U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + (RotL64(aWandererI, 10U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + RotL64(aWandererJ, 13U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordA);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 26351U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25480U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23034U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24156U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aPrevious, 38U)) + (RotL64(aCarry, 21U) ^ RotL64(aIngress, 51U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = (((aWandererJ + RotL64(aCross, 26U)) + 14686411261024919129U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordB;
            aOrbiterG = (aWandererG + RotL64(aIngress, 57U)) + 7514582233957632005U;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 37U)) + 6520710480103365552U;
            aOrbiterA = (aWandererA + RotL64(aScatter, 21U)) + 1983621978676188036U;
            aOrbiterH = ((aWandererK + RotL64(aCross, 19U)) + RotL64(aCarry, 35U)) + 9003524602590749672U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 39U)) + 6428568234045228995U;
            aOrbiterJ = (aWandererD + RotL64(aScatter, 4U)) + 8656552687136446989U;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 43U)) + 16916248288415922490U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aCross, 29U)) + 9740237548002535784U;
            aOrbiterE = (((aWandererC + RotL64(aScatter, 47U)) + RotL64(aCarry, 23U)) + 907561000814618339U) + aNonceWordC;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 53U)) + RotL64(aCarry, 43U)) + 4751108900841197631U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 167774899400732287U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 11907484918310854962U;
            aOrbiterC = RotL64((aOrbiterC * 7213139491146402985U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 14910318613649863924U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 14882888155751455276U;
            aOrbiterD = RotL64((aOrbiterD * 11394136445442060201U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 16175942562693781908U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 11022373758481651102U) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 6836331461393816027U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 12548405399045031548U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 10850926364556828443U;
            aOrbiterE = RotL64((aOrbiterE * 16231561687709867431U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 13391684887911141790U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 14648937281264822988U;
            aOrbiterI = RotL64((aOrbiterI * 6533299316940026059U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 8298658887198526821U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 13822977698661348891U;
            aOrbiterA = RotL64((aOrbiterA * 17769262972278410937U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 7505646847564645719U) + aNonceWordA;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 3238749538197209166U;
            aOrbiterJ = RotL64((aOrbiterJ * 15394286542600778567U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 15853506915123709257U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 8426329899401071248U;
            aOrbiterK = RotL64((aOrbiterK * 1330397096577715113U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 14848635392815613098U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 3549927798350175044U;
            aOrbiterF = RotL64((aOrbiterF * 1899044682313056949U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 1798973117197750802U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 13056711228618953977U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9102877396419306689U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 1395893547965799281U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 14686411261024919129U;
            aOrbiterH = RotL64((aOrbiterH * 17075377081365066067U), 57U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 53U);
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 58U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 39U) + RotL64(aOrbiterF, 5U)) + aOrbiterE) + aNonceWordI) + aPhaseFWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 29U) + aOrbiterD) + RotL64(aOrbiterA, 51U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterF, 18U)) + aOrbiterC);
            aWandererH = aWandererH + (((RotL64(aScatter, 56U) + aOrbiterE) + RotL64(aOrbiterI, 13U)) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 23U) + aOrbiterJ) + RotL64(aOrbiterC, 41U));
            aWandererB = aWandererB + ((RotL64(aCross, 21U) + aOrbiterJ) + RotL64(aOrbiterB, 43U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 13U) + aOrbiterB) + RotL64(aOrbiterH, 39U));
            aWandererG = aWandererG + ((RotL64(aIngress, 10U) + aOrbiterG) + RotL64(aOrbiterK, 11U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 27U)) + aOrbiterH) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 51U) + aOrbiterB) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 11U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterA, 60U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 50U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27889U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30651U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28867U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((aIndex + 28986U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 42U)) ^ (RotL64(aCross, 29U) + RotL64(aIngress, 57U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterJ = (aWandererF + RotL64(aIngress, 60U)) + 2786079456995203065U;
            aOrbiterK = (aWandererG + RotL64(aScatter, 51U)) + 7237256119153857253U;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 21U)) + 9310834010563647604U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 27U)) + 17361734905706517877U) + aPhaseFOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = (((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 53U)) + 15837111231884647451U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aScatter, 35U)) + 18065431964418026445U;
            aOrbiterI = ((aWandererC + RotL64(aCross, 39U)) + 3029123922999952652U) + aNonceWordI;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 47U)) + RotL64(aCarry, 43U)) + 5166926595573507837U;
            aOrbiterB = (aWandererD + RotL64(aCross, 58U)) + 1918425684273807598U;
            aOrbiterE = (aWandererA + RotL64(aIngress, 41U)) + 4724551751012661440U;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 53U)) + RotL64(aCarry, 29U)) + 1818014487579644390U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 6670090372241084216U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 8485757110007268693U;
            aOrbiterC = RotL64((aOrbiterC * 11876760095108618363U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 4928130251509514742U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 2528788422725346792U;
            aOrbiterH = RotL64((aOrbiterH * 1855982047967756661U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 2860387120895147503U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 12927802338151379368U;
            aOrbiterG = RotL64((aOrbiterG * 8876144125458603029U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 18029699867733207083U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 13361836994951253312U;
            aOrbiterI = RotL64((aOrbiterI * 5349767426256597073U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 11957294454794128079U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 3755417922063414648U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13896364063651241401U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 18001157153447913032U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 16214145724690286854U;
            aOrbiterB = RotL64((aOrbiterB * 5874139687703360515U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 3860958772090975562U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 12395621524459640173U) ^ aNonceWordP;
            aOrbiterE = RotL64((aOrbiterE * 722817135977510161U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 3402035664910754484U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterD) ^ 2139099117325745602U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterF = RotL64((aOrbiterF * 14008983756425796029U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 7769274487425053026U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 6492669707749367728U) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 5149771861620757839U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 14963366447884375043U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 11398874662567519691U;
            aOrbiterK = RotL64((aOrbiterK * 8221521452475029835U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 7168445485232814860U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 2786079456995203065U;
            aOrbiterA = RotL64((aOrbiterA * 14258367164534307955U), 13U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 52U);
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterC, 27U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + RotL64(aOrbiterJ, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterJ, 27U)) + aNonceWordJ);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 41U)) + aOrbiterD);
            aWandererB = aWandererB + (((RotL64(aCross, 38U) + aOrbiterH) + RotL64(aOrbiterK, 46U)) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterC, 37U)) + aOrbiterF) + aPhaseFWandererUpdateSaltF[((aIndex + 10U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 53U) + aOrbiterE) + RotL64(aOrbiterB, 39U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 53U)) + aOrbiterC) + aNonceWordE);
            aWandererD = aWandererD + ((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 43U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 26U) + RotL64(aOrbiterI, 30U)) + aOrbiterE);
            aWandererA = aWandererA + ((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 57U)) + aOrbiterJ);
            aWandererC = aWandererC ^ (((RotL64(aCross, 5U) + aOrbiterC) + RotL64(aOrbiterB, 11U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 51U) + RotL64(aOrbiterJ, 21U)) + aOrbiterH) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 6U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 56U);
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

void TwistExpander_Badminton_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xD27AF61DD87951EBULL + 0xC57B5AEA72D71DBBULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xABFA3C66B31B3119ULL + 0xC0659A9BD9EE16A5ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xA9CCF082324D31DBULL + 0xC570E4190A2A1204ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xD6847667508C8475ULL + 0xF01F31AC8CDA5121ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xFC344670F583A3ABULL + 0xF0FFB635AB367870ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xA0472FE73F388365ULL + 0xE331E11EA0620258ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x8FE20651ABCCC0A9ULL + 0xC7E6207FB4C66705ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xD7FC42247B6A2709ULL + 0xF923E422174D5738ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x907FE26960016669ULL + 0xD637AC236C6850DBULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x987B6A0DECAFF135ULL + 0xB449E9CA628A4E68ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xBB3FD2A6EDD21A75ULL + 0xD8AB77C28FBB38F3ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x99753545EE0EDAB7ULL + 0xE9FFA649D07711A1ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xF5BDDCD96531C0DFULL + 0xC023EFD413FC9C18ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x96D19F4E3D2F7D51ULL + 0xFD9BDC26A94D634DULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x89C1F8C81356884FULL + 0x8CCFAB07E2A32B65ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xB507E89BC6F6FB99ULL + 0xD2777FBB6BC8264FULL);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 4626U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 2024U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 2055U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 2754U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 26U) ^ RotL64(aCross, 53U)) + (RotL64(aIngress, 39U) ^ RotL64(aCarry, 3U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = (aWandererC + RotL64(aIngress, 60U)) + 12122689833405846292U;
            aOrbiterC = (aWandererH + RotL64(aCross, 43U)) + 9640400270962766788U;
            aOrbiterH = ((((aWandererE + RotL64(aScatter, 41U)) + RotL64(aCarry, 53U)) + 9141937998266739071U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordE;
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 27U)) + 12899395770434090537U;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 57U)) + 13457918115408031842U) + aPhaseFOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aPrevious, 14U)) + 15134784483576000943U;
            aOrbiterG = (aWandererA + RotL64(aScatter, 29U)) + 12540961268790055438U;
            aOrbiterI = (((aWandererJ + RotL64(aCross, 23U)) + RotL64(aCarry, 11U)) + 6306886773092764230U) + aNonceWordK;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 53U)) + RotL64(aCarry, 37U)) + 13573343491337243121U;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 5U)) + 8545588657348974413U) + aNonceWordI;
            aOrbiterD = (aWandererB + RotL64(aCross, 47U)) + 10891410570357275120U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 2877137119767060151U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 9178097682386595144U;
            aOrbiterH = RotL64((aOrbiterH * 3524486002084427513U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 15528007881855616978U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 11368419529245281435U;
            aOrbiterB = RotL64((aOrbiterB * 12433207037378339309U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 5932738914934356645U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 5551842263864055419U;
            aOrbiterK = RotL64((aOrbiterK * 16093776759971522681U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 3824433359595690603U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 17184628855571662441U;
            aOrbiterJ = RotL64((aOrbiterJ * 691208053136187317U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 8724462245014132623U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterD) ^ 7481349499528092352U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 8212182934509617583U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 6908362960248294718U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 5354057969992655314U;
            aOrbiterE = RotL64((aOrbiterE * 16586084885820679343U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 11138301629323903147U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 14164180536320940750U;
            aOrbiterD = RotL64((aOrbiterD * 9099767681053390287U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 709942920176922902U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 17128241237359414945U;
            aOrbiterC = RotL64((aOrbiterC * 14063385518459963529U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 6760410778228957309U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 15333948259759012363U;
            aOrbiterA = RotL64((aOrbiterA * 3685416414008280787U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 6929136132517755104U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 13833415487953533365U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14860437994758579635U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 16143046377679975216U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 12122689833405846292U;
            aOrbiterF = RotL64((aOrbiterF * 227699085983424155U), 35U);
            //
            aIngress = RotL64(aOrbiterJ, 51U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 60U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 50U) + RotL64(aOrbiterK, 53U)) + aOrbiterF);
            aWandererG = aWandererG + ((RotL64(aScatter, 39U) + RotL64(aOrbiterJ, 3U)) + aOrbiterI);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 37U) + aOrbiterI) + RotL64(aOrbiterD, 5U));
            aWandererB = aWandererB + (((RotL64(aCross, 47U) + RotL64(aOrbiterC, 58U)) + aOrbiterE) + RotL64(aCarry, 3U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterA, 27U));
            aWandererD = aWandererD + (((((RotL64(aPrevious, 11U) + aOrbiterC) + RotL64(aOrbiterI, 19U)) + RotL64(aCarry, 23U)) + aNonceWordD) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 23U) + aOrbiterD) + RotL64(aOrbiterJ, 41U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterD, 51U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 13U) + aOrbiterB) + RotL64(aOrbiterI, 21U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterJ, 43U)) + aOrbiterF) + aNonceWordO) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 52U) + RotL64(aOrbiterG, 12U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 30U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 34U));
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 10416U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneD[((aIndex + 10098U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5551U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 10400U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 4U) + RotL64(aPrevious, 23U)) ^ (RotL64(aCarry, 53U) + RotL64(aIngress, 37U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = ((aWandererD + RotL64(aScatter, 13U)) + 8793908991006073956U) + aNonceWordB;
            aOrbiterG = (aWandererG + RotL64(aIngress, 5U)) + 2932916283348441943U;
            aOrbiterJ = (((aWandererB + RotL64(aCross, 37U)) + RotL64(aCarry, 41U)) + 11069042087940968262U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aPrevious, 43U)) + 14369628676782894441U;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 41U)) + RotL64(aCarry, 29U)) + 8602903272780978282U;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 23U)) + 3827036107178568820U) + aPhaseFOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aScatter, 46U)) + 8905245209036772489U;
            aOrbiterD = (aWandererE + RotL64(aCross, 19U)) + 13331387530760017893U;
            aOrbiterE = ((aWandererI + RotL64(aScatter, 39U)) + RotL64(aCarry, 51U)) + 9880107580289737823U;
            aOrbiterI = (aWandererJ + RotL64(aCross, 29U)) + 10199619040626900278U;
            aOrbiterB = (aWandererF + RotL64(aPrevious, 26U)) + 2466307560891374281U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 13973403407981259448U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 2851460278409385243U;
            aOrbiterJ = RotL64((aOrbiterJ * 11226902976321781743U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 10365453393815690776U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 2382382358987358791U;
            aOrbiterG = RotL64((aOrbiterG * 481563628980705781U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 5058198848163792422U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 10500434740387593487U) ^ aNonceWordL;
            aOrbiterC = RotL64((aOrbiterC * 5946747708776079787U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 11289798395177667084U) + aNonceWordI;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 14327152153231286666U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 18155778059595245561U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 8065137263811956313U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 3865153574847924816U;
            aOrbiterE = RotL64((aOrbiterE * 9495741102667755161U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 18102279969722473375U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 6306428427188742325U;
            aOrbiterH = RotL64((aOrbiterH * 17826782872351406167U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 16953348204663693724U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 11950791817032898613U;
            aOrbiterA = RotL64((aOrbiterA * 1498946055469611133U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 11980823193543752994U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 17845490308799454871U;
            aOrbiterF = RotL64((aOrbiterF * 16385153013485463791U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 5566398755702887071U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 10308378271388889968U;
            aOrbiterD = RotL64((aOrbiterD * 142732084484961281U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 6717846700455219260U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 8297225372883997017U;
            aOrbiterI = RotL64((aOrbiterI * 14102812043481327907U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 12249337046267666603U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 8793908991006073956U;
            aOrbiterB = RotL64((aOrbiterB * 5851229209188473467U), 5U);
            //
            aIngress = RotL64(aOrbiterG, 39U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterF, 23U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterA, 4U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 35U) + aOrbiterH) + RotL64(aOrbiterG, 23U)) + aNonceWordE);
            aWandererH = aWandererH + ((RotL64(aCross, 37U) + aOrbiterE) + RotL64(aOrbiterK, 4U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 21U) + aOrbiterD) + RotL64(aOrbiterA, 41U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 5U) + aOrbiterH) + RotL64(aOrbiterB, 43U)) + aNonceWordN);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 46U) + aOrbiterC) + RotL64(aOrbiterJ, 29U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 51U)) + aOrbiterD) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterE, 35U)) + aOrbiterF);
            aWandererF = aWandererF + (((RotL64(aIngress, 39U) + aOrbiterK) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterC, 13U)) + aOrbiterH);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 50U) + aOrbiterF) + RotL64(aOrbiterI, 26U)) + RotL64(aCarry, 21U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterC, 47U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (RotL64(aWandererF, 30U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 15277U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 12658U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 12580U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 15810U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCross, 10U)) + (RotL64(aIngress, 41U) ^ RotL64(aCarry, 53U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = (((aWandererH + RotL64(aScatter, 24U)) + RotL64(aCarry, 13U)) + 14157904117287696136U) + aNonceWordI;
            aOrbiterA = ((aWandererG + RotL64(aCross, 5U)) + 7369512677371640676U) + aPhaseFOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = (aWandererC + RotL64(aPrevious, 53U)) + 8411250745902073798U;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 21U)) + 5002041814539710275U) + aNonceWordD;
            aOrbiterE = (aWandererA + RotL64(aScatter, 43U)) + 9538041410816283124U;
            aOrbiterB = ((aWandererB + RotL64(aCross, 14U)) + RotL64(aCarry, 3U)) + 5210700103927513061U;
            aOrbiterG = (aWandererJ + RotL64(aIngress, 57U)) + 7600709399101287982U;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 37U)) + 2366369466696580499U) + aPhaseFOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = ((aWandererD + RotL64(aIngress, 3U)) + RotL64(aCarry, 43U)) + 5544575244203019109U;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 47U)) + 8710073749110329779U) + aNonceWordM;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 35U)) + 15998211310115361630U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 15354357553877376422U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 10657523549259276169U;
            aOrbiterC = RotL64((aOrbiterC * 13695239532898311073U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 10405750198355464768U) + aNonceWordN;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 3465819693133515142U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14678343718277562799U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 16724189641701408630U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 3484340153620198872U;
            aOrbiterA = RotL64((aOrbiterA * 17247547677520703125U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 7420442404884871126U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 11138445997256757636U;
            aOrbiterE = RotL64((aOrbiterE * 11167543379937571127U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 1428191560884663125U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 16950093140800653985U;
            aOrbiterF = RotL64((aOrbiterF * 4423012306984814805U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 17288299075036481960U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 13793597915359681028U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9639204979982125757U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 5017972942710079726U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 12409957957614320964U;
            aOrbiterD = RotL64((aOrbiterD * 10273295741911545745U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 12487994181992095174U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 1573393166996612118U;
            aOrbiterJ = RotL64((aOrbiterJ * 13364311829104520751U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 13227642825780350128U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 7961292096150889569U;
            aOrbiterG = RotL64((aOrbiterG * 16627209081334341289U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 10312485102088913337U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 3177620041478410950U;
            aOrbiterI = RotL64((aOrbiterI * 15918551366833593853U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 2599092792737616563U) + aNonceWordA;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 14157904117287696136U;
            aOrbiterK = RotL64((aOrbiterK * 14883446269291639813U), 11U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 48U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + (RotL64(aOrbiterH, 43U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 21U) + aOrbiterK) + RotL64(aOrbiterJ, 26U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterF, 23U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 44U) + aOrbiterG) + RotL64(aOrbiterE, 57U));
            aWandererF = aWandererF + (((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 37U)) + aOrbiterF) + RotL64(aCarry, 39U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 11U) + aOrbiterH) + RotL64(aOrbiterG, 41U));
            aWandererH = aWandererH + ((RotL64(aCross, 29U) + aOrbiterJ) + RotL64(aOrbiterG, 19U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 39U) + aOrbiterA) + RotL64(aOrbiterH, 52U));
            aWandererI = aWandererI + (((((RotL64(aPrevious, 48U) + RotL64(aOrbiterD, 29U)) + aOrbiterB) + RotL64(aCarry, 13U)) + aNonceWordL) + aPhaseFWandererUpdateSaltF[((aIndex + 10U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterC, 13U)) + aOrbiterB) + aNonceWordF);
            aWandererE = aWandererE + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterK, 5U)) + aOrbiterA) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterC, 35U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 6U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 19116U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 19057U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18049U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 20172U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aIngress, 39U)) + (RotL64(aCarry, 52U) ^ RotL64(aPrevious, 21U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 47U)) + 2617613537256538553U) + aNonceWordB;
            aOrbiterF = (aWandererC + RotL64(aCross, 43U)) + 16642868916835132715U;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 23U)) + 10860291124337073254U;
            aOrbiterB = ((aWandererG + RotL64(aIngress, 18U)) + RotL64(aCarry, 29U)) + 6432511273906902472U;
            aOrbiterK = (((aWandererI + RotL64(aScatter, 53U)) + RotL64(aCarry, 5U)) + 7505375005848241910U) + aPhaseFOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 39U)) + RotL64(aCarry, 23U)) + 11086616004678821329U;
            aOrbiterE = (aWandererK + RotL64(aCross, 3U)) + 3298830587569881951U;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 11U)) + 9775143140064220979U;
            aOrbiterD = (aWandererE + RotL64(aPrevious, 20U)) + 4147601326580823120U;
            aOrbiterA = (aWandererA + RotL64(aIngress, 51U)) + 12245920269898100415U;
            aOrbiterG = ((aWandererF + RotL64(aCross, 29U)) + 8391940489176734499U) + aPhaseFOrbiterAssignSaltA[((aIndex + 6U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 17876893379544668477U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 18301882058180370541U;
            aOrbiterJ = RotL64((aOrbiterJ * 16680384667098921309U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 6869225862715140102U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 15404118372589259800U;
            aOrbiterK = RotL64((aOrbiterK * 5766851935950389915U), 5U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterJ) + 17757381020518233814U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordL;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 17677969146092374455U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3469432916562405063U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 15783378556632870114U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 5792858258663697864U;
            aOrbiterE = RotL64((aOrbiterE * 12008981883482080427U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 11737803388202260296U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 16001927091970715330U;
            aOrbiterC = RotL64((aOrbiterC * 3062030309852922061U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 1749586939123286632U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 6169421068855905938U;
            aOrbiterD = RotL64((aOrbiterD * 12374789910763348695U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 10073586820719728062U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 17744171227198661555U;
            aOrbiterA = RotL64((aOrbiterA * 10658375268803957647U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 1149819647337612792U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 7725598665625892006U;
            aOrbiterG = RotL64((aOrbiterG * 15097586655234391559U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 13930096050550704122U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 3632241034947389647U;
            aOrbiterI = RotL64((aOrbiterI * 8442222389196610427U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 17933893495867517142U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 7888594392078082482U;
            aOrbiterF = RotL64((aOrbiterF * 9809847720610861237U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 10805303827043372168U) + aNonceWordA;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 2617613537256538553U;
            aOrbiterB = RotL64((aOrbiterB * 3940471942234248791U), 13U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 48U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterB, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 44U) + RotL64(aOrbiterF, 43U)) + aOrbiterI);
            aWandererK = aWandererK + ((RotL64(aScatter, 21U) + aOrbiterG) + RotL64(aOrbiterE, 34U));
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 41U) + RotL64(aOrbiterC, 39U)) + aOrbiterD) + aNonceWordE) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 39U) + RotL64(aOrbiterK, 27U)) + aOrbiterD);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 54U) + RotL64(aOrbiterK, 5U)) + aOrbiterG) + aPhaseFWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterJ, 57U)) + aOrbiterC) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterH, 51U)) + aOrbiterA);
            aWandererA = aWandererA + (((RotL64(aScatter, 5U) + aOrbiterK) + RotL64(aOrbiterA, 41U)) + aNonceWordN);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 24U)) + aOrbiterH);
            aWandererB = aWandererB + (((RotL64(aScatter, 11U) + RotL64(aOrbiterH, 3U)) + aOrbiterB) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterB, 13U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (RotL64(aWandererA, 56U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + RotL64(aWandererI, 23U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordG);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 26163U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((aIndex + 23318U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27096U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26893U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 6U) ^ RotL64(aCarry, 19U)) + (RotL64(aPrevious, 35U) + RotL64(aCross, 47U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = (((aWandererK + RotL64(aPrevious, 24U)) + 15045917390223766480U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordF;
            aOrbiterA = (aWandererB + RotL64(aCross, 57U)) + 10763054007033668758U;
            aOrbiterF = (aWandererD + RotL64(aScatter, 51U)) + 13190170142593666607U;
            aOrbiterJ = (((aWandererA + RotL64(aIngress, 27U)) + RotL64(aCarry, 29U)) + 9657025731441167065U) + aNonceWordG;
            aOrbiterB = ((aWandererH + RotL64(aCross, 43U)) + RotL64(aCarry, 47U)) + 11433367178975954211U;
            aOrbiterD = (((aWandererG + RotL64(aScatter, 5U)) + RotL64(aCarry, 37U)) + 17904920143996810366U) + aNonceWordC;
            aOrbiterH = (aWandererF + RotL64(aIngress, 21U)) + 3244383020512113283U;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 39U)) + 6538815775171139091U;
            aOrbiterI = (aWandererE + RotL64(aScatter, 60U)) + 7195368312757976343U;
            aOrbiterE = (aWandererC + RotL64(aCross, 19U)) + 18134430713910279374U;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 13U)) + 6571776588427107976U) + aPhaseFOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 11830778129647517758U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 9793702760907767365U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4096246227968677179U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 2287235876793192036U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 8951959188326141794U;
            aOrbiterD = RotL64((aOrbiterD * 9968356718110753845U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 7583061790273240157U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 3571364625022806085U;
            aOrbiterG = RotL64((aOrbiterG * 6238360922735480669U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 13869345563551689212U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 277480328952975002U;
            aOrbiterE = RotL64((aOrbiterE * 1057564597096163085U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 4983735092494677578U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 9490022869381030928U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12926352917961703123U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 7928039573014765566U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 6504190875809407084U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14648214826494826711U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 2787985600176307413U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 16308785053443116826U;
            aOrbiterH = RotL64((aOrbiterH * 17867565986311256691U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 12788128335006767824U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 1187040019537798339U;
            aOrbiterI = RotL64((aOrbiterI * 10834905007658184183U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 10771230162770496645U) + aNonceWordO;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 6542421559654716320U;
            aOrbiterK = RotL64((aOrbiterK * 16829492790597069373U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 702458690970201679U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 2806140783487813070U;
            aOrbiterA = RotL64((aOrbiterA * 7415398198842270381U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 950611302199732036U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 15045917390223766480U;
            aOrbiterB = RotL64((aOrbiterB * 9358017420417979347U), 57U);
            //
            aIngress = RotL64(aOrbiterH, 57U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 54U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + RotL64(aOrbiterI, 6U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 58U) + RotL64(aOrbiterC, 19U)) + aOrbiterF);
            aWandererI = aWandererI + ((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterE, 3U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterE, 12U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 23U) + RotL64(aOrbiterG, 5U)) + aOrbiterI) + RotL64(aCarry, 51U)) + aPhaseFWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterF, 41U)) + aOrbiterH);
            aWandererF = aWandererF + (((RotL64(aPrevious, 26U) + aOrbiterH) + RotL64(aOrbiterA, 43U)) + RotL64(aCarry, 37U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterJ, 35U)) + aOrbiterH) + aNonceWordE);
            aWandererA = aWandererA + ((RotL64(aCross, 39U) + RotL64(aOrbiterF, 21U)) + aOrbiterI);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 41U) + aOrbiterC) + RotL64(aOrbiterB, 23U));
            aWandererD = aWandererD + ((RotL64(aCross, 37U) + RotL64(aOrbiterI, 28U)) + aOrbiterD);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 47U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererI);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 24U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererE, 35U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30595U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28298U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31864U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31949U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCarry, 4U)) ^ (RotL64(aPrevious, 37U) + RotL64(aCross, 51U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = ((aWandererH + RotL64(aCross, 21U)) + 9133751643283278896U) + aNonceWordJ;
            aOrbiterC = (aWandererB + RotL64(aScatter, 5U)) + 8971581804375380408U;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 24U)) + RotL64(aCarry, 21U)) + 12559650383714566592U;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 13U)) + 15753206088872859163U;
            aOrbiterH = ((aWandererI + RotL64(aCross, 27U)) + RotL64(aCarry, 29U)) + 7640756270450762350U;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 35U)) + 7340073357551376125U) + aNonceWordD;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 51U)) + 5270256573644196046U) + aPhaseFOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aScatter, 47U)) + 3567367996479995928U;
            aOrbiterI = (((aWandererF + RotL64(aPrevious, 3U)) + RotL64(aCarry, 11U)) + 11939634537492733738U) + aNonceWordN;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 19U)) + 7051817732424527120U) + aPhaseFOrbiterAssignSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aIngress, 10U)) + 1730487669951837941U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 18009252467909454817U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 2361024272031696442U;
            aOrbiterF = RotL64((aOrbiterF * 15215151562500226027U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 15902755877642960397U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 12243517544704116184U;
            aOrbiterH = RotL64((aOrbiterH * 2576071074148141447U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 16846181962302186187U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 636121425116506681U;
            aOrbiterJ = RotL64((aOrbiterJ * 17075030673338779993U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 6887385655828217318U) + aNonceWordK;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 3705834550934775862U;
            aOrbiterD = RotL64((aOrbiterD * 11275428284929594435U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 11165142437077969438U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 6426659930331618269U;
            aOrbiterE = RotL64((aOrbiterE * 17170640810530893705U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 12629082390899315789U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 4277510580069574724U;
            aOrbiterI = RotL64((aOrbiterI * 9829125163412708305U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 13814834144170469978U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 3698381854100295826U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5126359230872258015U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 11623170635983579937U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 7247413650388803796U;
            aOrbiterK = RotL64((aOrbiterK * 3403219499465560059U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 3129755194359521145U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 4081016725582134919U;
            aOrbiterG = RotL64((aOrbiterG * 11564414998539605389U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 15878346077922215753U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 2974440187796944059U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 783253926537018373U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 3922344163443096356U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 9133751643283278896U;
            aOrbiterA = RotL64((aOrbiterA * 16887991698415418429U), 13U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 23U);
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterJ, 10U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 56U) + RotL64(aOrbiterI, 3U)) + aOrbiterD) + aPhaseFWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 35U) + aOrbiterE) + RotL64(aOrbiterA, 13U)) + aNonceWordL);
            aWandererE = aWandererE + (((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 43U)) + aOrbiterK) + aNonceWordB);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterD, 5U)) + aPhaseFWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterG, 18U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 13U) + aOrbiterJ) + RotL64(aOrbiterC, 39U));
            aWandererH = aWandererH + (((RotL64(aScatter, 44U) + aOrbiterH) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 47U)) + aOrbiterJ);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 53U) + aOrbiterI) + RotL64(aOrbiterA, 24U)) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterB, 35U)) + aOrbiterF);
            aWandererK = aWandererK + ((RotL64(aCross, 39U) + aOrbiterB) + RotL64(aOrbiterI, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 58U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 56U));
            aCarry = aCarry + RotL64(aWandererJ, 5U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordF);
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

void TwistExpander_Badminton_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 2150U)) & S_BLOCK1], 21U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 1780U)) & W_KEY1], 12U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 6006U)) & W_KEY1], 41U) ^ RotL64(mSource[((aIndex + 328U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 4U) ^ RotL64(aCross, 35U)) + (RotL64(aCarry, 47U) ^ RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererG + RotL64(aScatter, 51U)) + RotL64(aCarry, 13U)) + 2571116506511057880U;
            aOrbiterF = (aWandererE + RotL64(aIngress, 3U)) + 13112435411509707292U;
            aOrbiterK = ((aWandererA + RotL64(aCross, 29U)) + RotL64(aCarry, 41U)) + 10403251762787357256U;
            aOrbiterC = (aWandererB + RotL64(aPrevious, 57U)) + 8461951095541400405U;
            aOrbiterE = ((aWandererC + RotL64(aCross, 10U)) + 9890793478557463815U) + aPhaseCOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 41U)) + RotL64(aCarry, 5U)) + 3030229465991783707U;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 47U)) + 7273848154043719247U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 23U)) + 10681774862516028276U;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 34U)) + 7105082755586853104U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 6588579345319551129U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 14616333550242386092U;
            aOrbiterK = RotL64((aOrbiterK * 2934574715879306337U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 15439666290229654921U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 3360304356760164799U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5164191920584106237U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 14438730801970761889U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 14515616787452085729U;
            aOrbiterI = RotL64((aOrbiterI * 2041601927968559821U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 4167853822635132419U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 8950982233003320239U;
            aOrbiterB = RotL64((aOrbiterB * 887144270884244907U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 12391327853728029953U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 7100871010552394421U;
            aOrbiterH = RotL64((aOrbiterH * 16552349374101955967U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 15381697462381887944U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 6801677551341079401U;
            aOrbiterC = RotL64((aOrbiterC * 13325954438427340703U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 947011315719204867U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 6356920162398333481U;
            aOrbiterJ = RotL64((aOrbiterJ * 5566721941682667419U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 8910262020598577378U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 8778455415977526457U;
            aOrbiterF = RotL64((aOrbiterF * 4092470497616637283U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 5585696961453127223U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 9670655481681494412U;
            aOrbiterE = RotL64((aOrbiterE * 7863197168965036383U), 3U);
            //
            aIngress = RotL64(aOrbiterI, 6U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aCross, 5U) + RotL64(aOrbiterD, 29U)) + aOrbiterJ);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 51U)) + aOrbiterI);
            aWandererF = aWandererF + (((RotL64(aPrevious, 38U) + aOrbiterB) + RotL64(aOrbiterJ, 60U)) + RotL64(aCarry, 35U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterB, 13U));
            aWandererE = aWandererE + ((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterK, 21U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterB, 37U)) + aOrbiterF);
            aWandererA = aWandererA + ((RotL64(aScatter, 21U) + RotL64(aOrbiterI, 56U)) + aOrbiterH);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 34U) + aOrbiterC) + RotL64(aOrbiterE, 5U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 47U)) + aOrbiterI) + RotL64(aCarry, 21U)) + aPhaseCWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 60U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + RotL64(aWandererC, 11U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 15217U)) & S_BLOCK1], 52U) ^ RotL64(mSource[((aIndex + 13286U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 8800U)) & W_KEY1], 28U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 14875U)) & W_KEY1], 51U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCross, 10U)) + (RotL64(aCarry, 39U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = ((aWandererK + RotL64(aScatter, 58U)) + RotL64(aCarry, 37U)) + 7075016829833562104U;
            aOrbiterA = (aWandererI + RotL64(aCross, 3U)) + 8783765886115517036U;
            aOrbiterK = (aWandererB + RotL64(aPrevious, 19U)) + 2996723892384565829U;
            aOrbiterJ = (((aWandererE + RotL64(aIngress, 41U)) + RotL64(aCarry, 51U)) + 9494134707342189476U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = (aWandererC + RotL64(aCross, 23U)) + 5052642981395679904U;
            aOrbiterD = (aWandererH + RotL64(aScatter, 29U)) + 8766787055127962238U;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 53U)) + RotL64(aCarry, 19U)) + 4467211954388738079U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 34U)) + 8030255604633658608U;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 13U)) + 16962408063455702251U) + aPhaseCOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 3768222186567699076U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 14930990410207899871U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10930005786146268241U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 14179761938395502502U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 1879084742719898108U;
            aOrbiterG = RotL64((aOrbiterG * 16783034788172670121U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 5535012408925981515U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 12792553516710295939U;
            aOrbiterE = RotL64((aOrbiterE * 8577530993755159329U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 8979253163346099252U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 5559189896063990740U;
            aOrbiterB = RotL64((aOrbiterB * 8832485423727331621U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 13937564337299044079U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 2393376759689394948U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2352815657830413941U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 12647519563697356479U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 10946871249960389549U;
            aOrbiterC = RotL64((aOrbiterC * 6272580371881237173U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 13376798695582123147U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 10958115913599631271U;
            aOrbiterJ = RotL64((aOrbiterJ * 18233981473003345217U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 4283914227806672773U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 910842005516235816U;
            aOrbiterD = RotL64((aOrbiterD * 6722229871617873429U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 1509644316619370324U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 165987596716078174U;
            aOrbiterA = RotL64((aOrbiterA * 13600064054240185123U), 43U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 11U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 54U));
            aIngress = aIngress + (RotL64(aOrbiterK, 41U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterG, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aScatter, 27U) + aOrbiterK) + RotL64(aOrbiterB, 44U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 10U) + aOrbiterJ) + RotL64(aOrbiterA, 23U));
            aWandererK = aWandererK + ((((RotL64(aCross, 21U) + aOrbiterF) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 35U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterJ, 13U));
            aWandererC = aWandererC + ((RotL64(aScatter, 39U) + RotL64(aOrbiterC, 3U)) + aOrbiterE);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 37U)) + aOrbiterE);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 60U)) + aOrbiterJ) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterE, 51U)) + aOrbiterB);
            aWandererH = aWandererH + (((RotL64(aScatter, 6U) + aOrbiterE) + RotL64(aOrbiterD, 27U)) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 18U));
            aCarry = aCarry + RotL64(aWandererJ, 35U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 18888U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18062U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 24245U)) & W_KEY1], 35U) ^ RotL64(aKeyRowReadB[((aIndex + 23398U)) & W_KEY1], 10U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 20U) ^ RotL64(aCarry, 5U)) + (RotL64(aPrevious, 47U) ^ RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 10U)) + 7270044678408187242U) + aPhaseCOrbiterAssignSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aCross, 37U)) + 10192278965379756766U;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 27U)) + 17568666746676060748U;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 47U)) + 14312927531124963037U) + aPhaseCOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = ((aWandererC + RotL64(aScatter, 43U)) + RotL64(aCarry, 23U)) + 9825825726152087706U;
            aOrbiterF = (aWandererD + RotL64(aCross, 57U)) + 9696778570255265896U;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 19U)) + 17657841352013417228U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 53U)) + RotL64(aCarry, 3U)) + 16207815085909628439U;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 4U)) + RotL64(aCarry, 57U)) + 1752979206374514227U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 10456310689643905854U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 16127830548663742550U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4355938404839045417U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 2940917376003930842U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 7353596864777649953U;
            aOrbiterJ = RotL64((aOrbiterJ * 7499468723171042005U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 12725092740446150705U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 5791296650856037010U;
            aOrbiterH = RotL64((aOrbiterH * 760379251950502133U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 1200130368046206150U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 16689604428598558547U;
            aOrbiterD = RotL64((aOrbiterD * 13815324235939996623U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 14359561591103730856U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 3975025843599045263U;
            aOrbiterA = RotL64((aOrbiterA * 5025047888533298617U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 14017901732955607601U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 10431526786489555196U;
            aOrbiterF = RotL64((aOrbiterF * 10181915874476132407U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 7320527073559849223U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 15333411223710709907U;
            aOrbiterB = RotL64((aOrbiterB * 3488684905528068775U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 14302474063321663801U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 2104154521019935187U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12944382959742278055U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 5167600586916325228U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 4566823109447208716U;
            aOrbiterG = RotL64((aOrbiterG * 9997799807454267443U), 41U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 19U);
            aIngress = aIngress + (RotL64(aOrbiterA, 42U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aCross, 58U) + aOrbiterF) + RotL64(aOrbiterA, 12U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 39U) + aOrbiterD) + RotL64(aOrbiterH, 3U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 43U)) + aOrbiterB) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 47U)) + aOrbiterF);
            aWandererA = aWandererA + ((RotL64(aScatter, 27U) + RotL64(aOrbiterD, 53U)) + aOrbiterC);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 6U) + RotL64(aOrbiterK, 57U)) + aOrbiterJ);
            aWandererB = aWandererB + ((((RotL64(aIngress, 51U) + aOrbiterF) + RotL64(aOrbiterH, 36U)) + RotL64(aCarry, 29U)) + aPhaseCWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterB, 23U));
            aWandererE = aWandererE + (((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterK, 29U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 26U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 35U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28005U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27381U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24600U)) & S_BLOCK1], 51U) ^ RotL64(mSource[((aIndex + 24795U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aPrevious, 53U)) ^ (RotL64(aCarry, 38U) + RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (aWandererF + RotL64(aScatter, 39U)) + 826930775230515406U;
            aOrbiterE = (aWandererH + RotL64(aIngress, 26U)) + 5137814617363250861U;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 35U)) + RotL64(aCarry, 13U)) + 14761561947426681616U;
            aOrbiterJ = (aWandererJ + RotL64(aCross, 43U)) + 12773023438753662590U;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 53U)) + RotL64(aCarry, 3U)) + 7331345852207096322U;
            aOrbiterK = (aWandererI + RotL64(aScatter, 58U)) + 3899381212671247460U;
            aOrbiterB = (((aWandererG + RotL64(aCross, 5U)) + RotL64(aCarry, 35U)) + 10072004147620068599U) + aPhaseCOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 13U)) + 3424585039401897560U) + aPhaseCOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aCross, 19U)) + 8246760141625966321U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 3655992860610853290U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 11154618022505863898U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4791494171286145231U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 15629361991059709973U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 10842068502278489664U;
            aOrbiterH = RotL64((aOrbiterH * 17223002513104960799U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 5571312349016336686U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 589313823745748879U;
            aOrbiterB = RotL64((aOrbiterB * 1356685926549786027U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 13633457935771935260U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 12684602052812183096U;
            aOrbiterF = RotL64((aOrbiterF * 4689206269919806711U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 5711307583717354204U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 7181854170553728211U;
            aOrbiterJ = RotL64((aOrbiterJ * 9835601115561325911U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 1884620014396115821U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 1471516373272364262U;
            aOrbiterK = RotL64((aOrbiterK * 5126319375714848029U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 742739371092077733U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 8075893317715227838U;
            aOrbiterC = RotL64((aOrbiterC * 11208274111743259795U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 8179547722249281263U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 15305282712174742323U;
            aOrbiterG = RotL64((aOrbiterG * 7951986906055462929U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 1430543231751281079U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 14585341768267283387U;
            aOrbiterE = RotL64((aOrbiterE * 313213844964269133U), 21U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 47U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 44U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterC, 28U)) + RotL64(aCarry, 5U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterE, 23U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterB, 3U)) + aOrbiterG) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 22U) + aOrbiterF) + RotL64(aOrbiterD, 11U));
            aWandererH = aWandererH + ((RotL64(aIngress, 39U) + aOrbiterH) + RotL64(aOrbiterC, 47U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterG, 51U)) + aOrbiterF);
            aWandererG = aWandererG + (((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterF, 19U)) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 12U) + aOrbiterJ) + RotL64(aOrbiterG, 36U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 41U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + (RotL64(aWandererA, 38U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void TwistExpander_Badminton_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 781U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneC[((aIndex + 401U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5327U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneA[((aIndex + 4507U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 35U)) ^ (RotL64(aIngress, 54U) + RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = ((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 13U)) + 15910560457440369082U;
            aOrbiterA = (aWandererJ + RotL64(aIngress, 29U)) + 17953072986407436888U;
            aOrbiterK = (((aWandererI + RotL64(aPrevious, 39U)) + RotL64(aCarry, 53U)) + 15446940721193538669U) + aPhaseDOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = (((aWandererF + RotL64(aScatter, 47U)) + RotL64(aCarry, 37U)) + 3020785262774422009U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = (aWandererC + RotL64(aCross, 14U)) + 7001288645424994404U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 13385250665458462689U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 4841895644623005949U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3898487345974386945U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 13053476783239482065U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 641996979335975244U;
            aOrbiterG = RotL64((aOrbiterG * 3697673197256549833U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 16211238020928688299U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 12715448751323279480U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2116880429675303291U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 17784406727699995290U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 16626339815786580778U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13940754474750138041U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 9035070625716345139U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 6085848172494001945U;
            aOrbiterB = RotL64((aOrbiterB * 10405728912339646693U), 19U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterA, 6U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + RotL64(aOrbiterD, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterD, 47U)) + aOrbiterG);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 43U) + aOrbiterA) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 57U)) + aPhaseDWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 34U) + aOrbiterB) + RotL64(aOrbiterA, 13U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterK, 56U)) + aOrbiterB) + RotL64(aCarry, 13U)) + aPhaseDWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterK, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 54U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 11935U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11149U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10361U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 11241U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 6U)) + (RotL64(aIngress, 21U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = ((aWandererF + RotL64(aCross, 57U)) + RotL64(aCarry, 19U)) + 17264605017518259932U;
            aOrbiterD = (((aWandererB + RotL64(aScatter, 29U)) + RotL64(aCarry, 57U)) + 15209184354580778643U) + aPhaseDOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aPrevious, 20U)) + 3299527965014731384U;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 37U)) + RotL64(aCarry, 37U)) + 16293096431816127821U;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 3U)) + 11031983436878828337U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 9188018632448236358U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 13420816400363406556U;
            aOrbiterG = RotL64((aOrbiterG * 10958221259662190519U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 2485063384097917101U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 3089135816938128264U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8813152992957361153U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 10730544971770435788U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 10431767565618874806U;
            aOrbiterH = RotL64((aOrbiterH * 4723078464590561545U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 14883796491656899074U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 13465877783538483706U;
            aOrbiterD = RotL64((aOrbiterD * 14311686051108108503U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 13322163435314643713U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 3307316600284371955U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12337846092069506365U), 47U);
            //
            aIngress = RotL64(aOrbiterF, 19U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 3U)) + aOrbiterH);
            aWandererB = aWandererB + (((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 39U)) + aOrbiterG) + RotL64(aCarry, 41U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 19U) + aOrbiterG) + RotL64(aOrbiterI, 21U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aCross, 54U) + aOrbiterD) + RotL64(aOrbiterI, 12U)) + RotL64(aCarry, 21U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 35U) + aOrbiterH) + RotL64(aOrbiterI, 53U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 12U));
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 51U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 20136U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18981U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 23578U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneC[((aIndex + 22207U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 5U)) ^ (RotL64(aIngress, 37U) ^ RotL64(aCarry, 18U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = (((aWandererI + RotL64(aIngress, 21U)) + RotL64(aCarry, 47U)) + 2915859148137000694U) + aPhaseDOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aCross, 42U)) + 210680583721444425U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 3U)) + 6668118118775650387U;
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 29U)) + RotL64(aCarry, 23U)) + 15794200818099010989U;
            aOrbiterC = (aWandererE + RotL64(aCross, 53U)) + 6565076707062828369U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 16323164497808856719U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 7965435318816716560U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5984608704943623687U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 7390281030573369017U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 2269738866911824875U;
            aOrbiterA = RotL64((aOrbiterA * 1198697877998135567U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 9664014216039993873U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 18284857398028357633U;
            aOrbiterK = RotL64((aOrbiterK * 8402008251343393737U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 367667619795303009U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 7935945060956274197U;
            aOrbiterI = RotL64((aOrbiterI * 5481786693511955209U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 16683666162337789540U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 10655658270998102390U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15231596813382239841U), 13U);
            //
            aIngress = RotL64(aOrbiterC, 53U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 43U));
            aIngress = aIngress + RotL64(aOrbiterB, 14U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 38U) + aOrbiterB) + RotL64(aOrbiterA, 43U)) + aPhaseDWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterC, 24U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterB, 51U)) + RotL64(aCarry, 5U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterI, 35U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 38U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 29093U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((aIndex + 25239U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26614U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneD[((aIndex + 30131U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCross, 13U)) ^ (RotL64(aCarry, 28U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = (((aWandererB + RotL64(aIngress, 35U)) + RotL64(aCarry, 3U)) + 9107326720193244489U) + aPhaseDOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aCross, 3U)) + RotL64(aCarry, 19U)) + 10868585484401664145U;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 56U)) + RotL64(aCarry, 37U)) + 13637736741437846622U;
            aOrbiterF = (aWandererA + RotL64(aScatter, 11U)) + 6130725216183918844U;
            aOrbiterB = ((aWandererE + RotL64(aCross, 21U)) + 2063834478521338187U) + aPhaseDOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 8564870627911949158U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 6524015751064086390U;
            aOrbiterI = RotL64((aOrbiterI * 12055267995727104463U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 9874937766875388236U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 14723718409522680894U;
            aOrbiterC = RotL64((aOrbiterC * 17379140128833323431U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 13767059954741528279U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 6387608251033722169U;
            aOrbiterF = RotL64((aOrbiterF * 6601902195707980693U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 5391425980008431000U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 11524218415655093779U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12508457981779189389U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 155510463350385905U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 10554591788433641311U;
            aOrbiterB = RotL64((aOrbiterB * 5412084824127934293U), 21U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 3U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterC, 53U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 56U) + aOrbiterB) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterC, 34U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 21U) + RotL64(aOrbiterD, 23U)) + aOrbiterC) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterI, 13U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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

void TwistExpander_Badminton_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 6904U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4719U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6737U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 3586U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCross, 20U)) ^ (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = (((aWandererF + RotL64(aIngress, 41U)) + RotL64(aCarry, 57U)) + 10915618884692072446U) + aPhaseEOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aCross, 29U)) + 12634922308499254909U;
            aOrbiterB = (aWandererA + RotL64(aScatter, 50U)) + 6533934734564499389U;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 57U)) + RotL64(aCarry, 27U)) + 6744203303756105181U;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 11U)) + RotL64(aCarry, 13U)) + 13086782386652045658U;
            aOrbiterK = (aWandererJ + RotL64(aCross, 5U)) + 5693840533331397822U;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 35U)) + 1803663542535024611U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 3597219300593287708U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 1429753448204448904U;
            aOrbiterB = RotL64((aOrbiterB * 10927459251773273143U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 17229017825587322715U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 1137574712801062932U;
            aOrbiterA = RotL64((aOrbiterA * 3645832160939819415U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 2401991077004083378U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 1332473247826139292U;
            aOrbiterK = RotL64((aOrbiterK * 15029831858261506447U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 11730946340796899885U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 15319163439700390962U;
            aOrbiterH = RotL64((aOrbiterH * 1349242001887975499U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 4744141870145159917U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 6067132201862688684U;
            aOrbiterE = RotL64((aOrbiterE * 6046100687757836027U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 14991509179286371800U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 4342608825699398682U;
            aOrbiterC = RotL64((aOrbiterC * 10240526103933275875U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 3727521409410742075U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 3302027219498304367U;
            aOrbiterJ = RotL64((aOrbiterJ * 12153634588200479559U), 11U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 3U);
            aIngress = aIngress + (RotL64(aOrbiterB, 28U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterA, 44U)) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 39U) + aOrbiterC) + RotL64(aOrbiterA, 19U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 50U) + RotL64(aOrbiterH, 57U)) + aOrbiterA);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 27U) + aOrbiterA) + RotL64(aOrbiterE, 11U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 21U) + RotL64(aOrbiterB, 29U)) + aOrbiterK);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 35U)) + aOrbiterH) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + RotL64(aWandererC, 60U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 13093U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneD[((aIndex + 12758U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 11598U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 12543U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCross, 4U)) + (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = ((aWandererI + RotL64(aCross, 13U)) + 17668251151213543491U) + aPhaseEOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = (aWandererG + RotL64(aScatter, 3U)) + 16101602509895104517U;
            aOrbiterB = (aWandererH + RotL64(aIngress, 52U)) + 9083915270773304935U;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 29U)) + 12810720730318214811U;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 5U)) + 18113428002071925621U;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 21U)) + RotL64(aCarry, 35U)) + 1582208899354109878U;
            aOrbiterH = (((aWandererC + RotL64(aCross, 41U)) + RotL64(aCarry, 47U)) + 4180688104819188154U) + aPhaseEOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 8954598189262820611U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 15360094153175355879U;
            aOrbiterB = RotL64((aOrbiterB * 8177798855402983685U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 8383954114668216260U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 15626783326234049197U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15058420415480073793U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 10609978564404958066U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 17656516608997517984U;
            aOrbiterJ = RotL64((aOrbiterJ * 4590620354119899777U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 760077259110786536U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 3597338735888033063U;
            aOrbiterA = RotL64((aOrbiterA * 6548831472863517621U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 4431777844935985157U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 10710423172154671296U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16267496318491473315U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 10240882795242085185U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 7826053487019825891U;
            aOrbiterI = RotL64((aOrbiterI * 15053729937684375907U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9418883403715727353U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 11507423614799075545U;
            aOrbiterH = RotL64((aOrbiterH * 16189463984557044693U), 53U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 34U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterB, 41U)) + aOrbiterJ);
            aWandererF = aWandererF + ((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 11U)) + aOrbiterH);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 5U) + aOrbiterH) + RotL64(aOrbiterB, 51U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aCross, 54U) + aOrbiterI) + RotL64(aOrbiterB, 29U)) + RotL64(aCarry, 53U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 21U) + aOrbiterC) + RotL64(aOrbiterB, 18U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 11U) + aOrbiterA) + RotL64(aOrbiterJ, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 36U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + RotL64(aWandererC, 53U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 20350U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneA[((aIndex + 20649U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 21337U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((aIndex + 19537U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 43U) + RotL64(aCarry, 5U)) ^ (RotL64(aCross, 28U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 5U)) + 11480359716598965890U) + aPhaseEOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aIngress, 21U)) + 15431182525482873419U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aScatter, 13U)) + RotL64(aCarry, 5U)) + 11360504974812776707U;
            aOrbiterI = (aWandererK + RotL64(aCross, 46U)) + 9292576416573382769U;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 57U)) + RotL64(aCarry, 23U)) + 1549257414531028975U;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 39U)) + 5347769463033129317U;
            aOrbiterG = ((aWandererC + RotL64(aCross, 27U)) + RotL64(aCarry, 35U)) + 17019199177478377234U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 16558106007323125094U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 3976182233825939422U;
            aOrbiterC = RotL64((aOrbiterC * 4392162052317572289U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 2889047161195954395U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 2241831345026962605U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5757458560979927857U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 12850802412140579294U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 13541744735436450160U;
            aOrbiterH = RotL64((aOrbiterH * 906089290000537439U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 2085863085516538212U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 2969034221711544086U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7768528124408400403U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 6482666944512391472U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 16969153556875844613U;
            aOrbiterK = RotL64((aOrbiterK * 9483462388353216219U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 5161314086757363678U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 7150282484670673211U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8522427002337918663U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 5465304381272305847U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 2344610773390354017U;
            aOrbiterG = RotL64((aOrbiterG * 17010258514288089191U), 37U);
            //
            aIngress = RotL64(aOrbiterA, 11U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterH, 56U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 13U)) + aOrbiterK) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 22U) + aOrbiterK) + RotL64(aOrbiterG, 47U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 40U)) + aOrbiterC) + RotL64(aCarry, 39U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 37U) + aOrbiterK) + RotL64(aOrbiterI, 3U));
            aWandererB = aWandererB + ((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 29U)) + aOrbiterD);
            aWandererE = aWandererE ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterH, 23U)) + aOrbiterK);
            aWandererD = aWandererD + ((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterD, 53U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + (RotL64(aWandererA, 46U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererC, 27U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 25190U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26094U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28299U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 25304U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCarry, 36U)) ^ (RotL64(aPrevious, 57U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = (((aWandererC + RotL64(aIngress, 3U)) + RotL64(aCarry, 5U)) + 16802219662864902427U) + aPhaseEOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 60U)) + RotL64(aCarry, 51U)) + 14332033461409490629U;
            aOrbiterB = (aWandererD + RotL64(aCross, 51U)) + 8781794298640286845U;
            aOrbiterJ = (((aWandererF + RotL64(aScatter, 27U)) + RotL64(aCarry, 23U)) + 8459933908074937264U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 35U)) + 1883580287986004426U;
            aOrbiterF = (aWandererK + RotL64(aIngress, 43U)) + 17500258188004626118U;
            aOrbiterK = (aWandererB + RotL64(aCross, 11U)) + 7934811305150872870U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 6380363892361098905U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 12623079132626676910U;
            aOrbiterB = RotL64((aOrbiterB * 12406671746344127399U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 10455208121949202703U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 8805532707916767629U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 666082374369701881U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 9161544391400377699U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 3501434325829663268U;
            aOrbiterC = RotL64((aOrbiterC * 7933545151293799637U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 651783304096081996U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 441505031509930622U;
            aOrbiterG = RotL64((aOrbiterG * 8045355432310956143U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 1771159983581326424U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 15227946417377695989U;
            aOrbiterI = RotL64((aOrbiterI * 1563141188972797601U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 4153717524193279095U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 4404521756523902829U;
            aOrbiterJ = RotL64((aOrbiterJ * 1410342912973206203U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 6231945075461813285U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 3864780227164426690U;
            aOrbiterK = RotL64((aOrbiterK * 18031353247480673617U), 35U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterF, 39U);
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 26U));
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterK, 27U)) + aOrbiterI);
            aWandererF = aWandererF + (((RotL64(aCross, 41U) + aOrbiterC) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 53U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterF, 41U)) + aOrbiterG) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 34U) + aOrbiterI) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterI, 3U)) + aOrbiterF);
            aWandererC = aWandererC + (((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterJ, 50U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 23U) + aOrbiterB) + RotL64(aOrbiterI, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 12U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 43U);
            aCarry = aCarry + RotL64(aIngress, 34U);
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

void TwistExpander_Badminton_Arx::Twist_D(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterK = 0;

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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 6290U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneC[((aIndex + 7579U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1773U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((aIndex + 3692U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aPrevious, 35U)) + (RotL64(aCarry, 47U) + RotL64(aIngress, 60U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = (((aWandererH + RotL64(aPrevious, 35U)) + RotL64(aCarry, 35U)) + 1042610313571524121U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aScatter, 5U)) + RotL64(aCarry, 5U)) + 3505725321008825582U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 43U)) + RotL64(aCarry, 47U)) + 12584654563843782991U;
            aOrbiterK = (aWandererA + RotL64(aCross, 51U)) + 6645399144515770935U;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 20U)) + 3608978423753715584U) + aPhaseFOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 8089198857670370983U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 15207251813516399879U;
            aOrbiterE = RotL64((aOrbiterE * 7596841660069752069U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 9579268660105824516U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 16055044469473802812U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2269649280637188723U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 583811872609805949U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 7027491967970873942U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12686754713465826139U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 18256061823189677508U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 12708429127816136937U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12593886633108075321U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 12169216645156306078U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 12694325407567795065U;
            aOrbiterF = RotL64((aOrbiterF * 3711789483877261899U), 29U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 57U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 39U) + RotL64(aOrbiterF, 19U)) + aOrbiterG) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 57U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 3U)) + aOrbiterK) + aPhaseFWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 54U) + RotL64(aOrbiterE, 29U)) + aOrbiterA);
            aWandererD = aWandererD + ((((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterE, 40U)) + RotL64(aCarry, 13U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererA, 21U);
            aCarry = aCarry + RotL64(aIngress, 46U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 14252U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneD[((aIndex + 11548U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12317U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneB[((aIndex + 10044U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 22U) + RotL64(aIngress, 3U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = ((aWandererI + RotL64(aCross, 47U)) + 3550722402315312207U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 37U)) + RotL64(aCarry, 27U)) + 16724184551669522754U;
            aOrbiterK = ((aWandererB + RotL64(aIngress, 3U)) + RotL64(aCarry, 39U)) + 981751330116773021U;
            aOrbiterG = (aWandererK + RotL64(aScatter, 58U)) + 7891159229704944868U;
            aOrbiterD = (((aWandererA + RotL64(aCross, 11U)) + RotL64(aCarry, 53U)) + 13618396711464799841U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 5969291018449003648U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 14595540413313640042U;
            aOrbiterK = RotL64((aOrbiterK * 8151104319012840963U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 3287990436916111762U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 12534369400200483704U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2345945228434740707U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 2277312067930392274U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 10026320559261334353U;
            aOrbiterE = RotL64((aOrbiterE * 11020464940995912637U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 11258082063135659551U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 1445958517675746990U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10062265337488757971U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 1011298251290970844U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 6487834862470043744U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15477913837027179675U), 3U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 44U);
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterE, 26U)) + aOrbiterD) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterC, 35U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 43U) + aOrbiterK) + RotL64(aOrbiterG, 43U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 58U) + aOrbiterD) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + RotL64(aWandererI, 19U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 20430U)) & S_BLOCK1], 40U) ^ RotL64(aWorkLaneA[((aIndex + 23697U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 23929U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((aIndex + 21555U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 42U) + RotL64(aCarry, 5U)) + (RotL64(aCross, 57U) ^ RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (aWandererK + RotL64(aCross, 41U)) + 12136097566601676613U;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 13U)) + 7969431322248040056U;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 5U)) + RotL64(aCarry, 43U)) + 10530676021510553889U;
            aOrbiterD = (((aWandererD + RotL64(aIngress, 27U)) + RotL64(aCarry, 21U)) + 8740777303075445264U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (((aWandererI + RotL64(aPrevious, 52U)) + RotL64(aCarry, 3U)) + 13249434169895564739U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 15529577005925628472U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 344627093687331562U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3226087371456521323U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 8824277416519988893U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 5636276438449709875U;
            aOrbiterE = RotL64((aOrbiterE * 222817930773618893U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 2079413361031851552U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 7807998179168655561U;
            aOrbiterF = RotL64((aOrbiterF * 961456853699784753U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 13589392896232029112U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 10733011474804473996U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 361749145931578805U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 15934162328347805968U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 7573511217796245232U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10694563909931636155U), 29U);
            //
            aIngress = RotL64(aOrbiterD, 57U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aIngress, 19U) + aOrbiterE) + RotL64(aOrbiterF, 3U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 27U) + aOrbiterA) + RotL64(aOrbiterI, 52U));
            aWandererA = aWandererA + ((((RotL64(aCross, 46U) + aOrbiterI) + RotL64(aOrbiterE, 37U)) + RotL64(aCarry, 11U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 35U) + aOrbiterF) + RotL64(aOrbiterD, 21U)) + aPhaseFWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 58U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 25149U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27086U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29552U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 25403U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 6U) ^ RotL64(aCross, 41U)) + (RotL64(aCarry, 19U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = ((aWandererH + RotL64(aIngress, 11U)) + RotL64(aCarry, 53U)) + 18180797995100240808U;
            aOrbiterA = ((aWandererC + RotL64(aCross, 19U)) + 6585906608223552885U) + aPhaseFOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aScatter, 58U)) + 14088708930575939855U;
            aOrbiterK = (((aWandererG + RotL64(aPrevious, 29U)) + RotL64(aCarry, 21U)) + 468974153311516044U) + aPhaseFOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aCross, 41U)) + RotL64(aCarry, 37U)) + 12481951025619894110U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 17227987923860711763U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 4373962756657477139U;
            aOrbiterG = RotL64((aOrbiterG * 6069068316234356267U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 2077576476565420951U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 17435011300234663764U;
            aOrbiterC = RotL64((aOrbiterC * 8910133867294004711U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 4118039398293246896U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 13724716599855216683U;
            aOrbiterK = RotL64((aOrbiterK * 17556333902751079677U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 12391461204689596339U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 9900605191533799627U;
            aOrbiterA = RotL64((aOrbiterA * 13553565332531046301U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 972946858824366125U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 17247681919694541215U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2974639094630445643U), 35U);
            //
            aIngress = RotL64(aOrbiterC, 42U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterK, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 14U) + RotL64(aOrbiterK, 5U)) + aOrbiterG) + aPhaseFWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 27U)) + aOrbiterC) + RotL64(aCarry, 29U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterA, 46U)) + aOrbiterG);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 57U)) + aOrbiterD) + RotL64(aCarry, 57U)) + aPhaseFWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterC, 13U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 18U));
            aCarry = aCarry + RotL64(aWandererH, 57U);
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

void TwistExpander_Badminton_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 229U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneB[((aIndex + 5132U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 899U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 61U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 19U)) + (RotL64(aCarry, 34U) ^ RotL64(aIngress, 47U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = ((aWandererH + RotL64(aScatter, 35U)) + 5576732410244514238U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aCross, 52U)) + 2833808925935929629U;
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 3U)) + RotL64(aCarry, 11U)) + 3670188682914544792U;
            aOrbiterI = (((aWandererI + RotL64(aPrevious, 43U)) + RotL64(aCarry, 23U)) + 15759072378887814995U) + aPhaseGOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = ((aWandererA + RotL64(aCross, 21U)) + RotL64(aCarry, 41U)) + 13934007231137439994U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 11022225696007690512U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 16989177104453635790U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14156758251105809453U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 9256930045263527091U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 17788596104417068290U;
            aOrbiterC = RotL64((aOrbiterC * 675554110563253305U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 17044369456673337625U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 1310908395523250343U;
            aOrbiterI = RotL64((aOrbiterI * 16305084373037705921U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 12067065689034065422U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 15130844248737512262U;
            aOrbiterK = RotL64((aOrbiterK * 9409499577465934107U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 14532689204495587494U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 8198147292120244178U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1418356389507740991U), 13U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterC, 20U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterC, 41U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 38U) + RotL64(aOrbiterC, 58U)) + aOrbiterG) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 13U)) + aOrbiterK);
            aWandererA = aWandererA + ((((RotL64(aScatter, 11U) + aOrbiterI) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 5U)) + aPhaseGWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterK, 21U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererD, 14U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 16156U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 8454U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8576U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneA[((aIndex + 12781U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCross, 60U)) + (RotL64(aCarry, 11U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 39U)) + RotL64(aCarry, 35U)) + 4068921616130916949U;
            aOrbiterH = (aWandererK + RotL64(aCross, 3U)) + 12077715273915151726U;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 23U)) + 16047546802670596833U) + aPhaseGOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aIngress, 47U)) + RotL64(aCarry, 23U)) + 9690277462716999763U;
            aOrbiterB = (((aWandererF + RotL64(aScatter, 12U)) + RotL64(aCarry, 11U)) + 14484814700447992628U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 17089267243053958210U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 9138746214446211147U;
            aOrbiterE = RotL64((aOrbiterE * 8244950097712975043U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 10181001536979097045U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 6657458969093373191U;
            aOrbiterB = RotL64((aOrbiterB * 4311019792293202747U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 7515983477876590988U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 3039935555863947600U;
            aOrbiterI = RotL64((aOrbiterI * 12511160550780270119U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 16209389224740851136U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 725253312098083182U;
            aOrbiterH = RotL64((aOrbiterH * 17535989492095522597U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 13307041115748941383U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 7159572004825238263U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4855009895002398449U), 35U);
            //
            aIngress = RotL64(aOrbiterG, 37U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 19U) + RotL64(aOrbiterG, 13U)) + aOrbiterI) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterI, 27U)) + aOrbiterH);
            aWandererB = aWandererB + ((((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterE, 37U)) + RotL64(aCarry, 37U)) + aPhaseGWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 54U) + RotL64(aOrbiterG, 56U)) + aOrbiterH);
            aWandererI = aWandererI + (((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterI, 47U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (RotL64(aWandererI, 44U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 18686U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 22356U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23348U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneB[((aIndex + 20319U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 13U) ^ RotL64(aPrevious, 43U)) + (RotL64(aCarry, 60U) ^ RotL64(aIngress, 29U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = ((aWandererC + RotL64(aCross, 29U)) + RotL64(aCarry, 5U)) + 8506388683755208267U;
            aOrbiterB = ((aWandererF + RotL64(aIngress, 3U)) + 2179323259055019735U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 57U)) + RotL64(aCarry, 23U)) + 3345902531140983016U;
            aOrbiterD = ((aWandererI + RotL64(aScatter, 39U)) + 17456139311481306584U) + aPhaseGOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aIngress, 18U)) + RotL64(aCarry, 43U)) + 14587864088462311164U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 13178947246650647057U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 12866578138946916962U;
            aOrbiterJ = RotL64((aOrbiterJ * 121991325166969319U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 13098524333655118173U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 15451329483787541982U;
            aOrbiterB = RotL64((aOrbiterB * 13580376920467431451U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 9494299579678389385U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 15581954810375490643U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13670002280188424825U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 4487042505730624892U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 2774455928791636186U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15847933919136777451U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 12435319582397755819U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 10077180055177766823U;
            aOrbiterA = RotL64((aOrbiterA * 3924363471701748703U), 47U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterB, 3U);
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterA, 54U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 43U)) + aOrbiterJ) + RotL64(aCarry, 21U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterG, 53U));
            aWandererI = aWandererI + (((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 5U)) + aOrbiterG) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 21U) + aOrbiterJ) + RotL64(aOrbiterD, 28U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 56U) + RotL64(aOrbiterA, 19U)) + aOrbiterJ) + aPhaseGWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 50U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 29326U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27379U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26914U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneC[((aIndex + 26563U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCarry, 58U)) ^ (RotL64(aCross, 11U) ^ RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 13U)) + RotL64(aCarry, 35U)) + 2974056819475622600U;
            aOrbiterH = ((aWandererC + RotL64(aCross, 5U)) + RotL64(aCarry, 47U)) + 7345051759236356098U;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 27U)) + 12738468816846628882U) + aPhaseGOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 54U)) + RotL64(aCarry, 21U)) + 7694520596043297922U;
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 41U)) + 5530753590015084774U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 3776309161718383105U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 784780304358106404U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1503119308251871519U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 8999942326995036509U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 5194986506064092779U;
            aOrbiterJ = RotL64((aOrbiterJ * 15070787038006135963U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 7920040007459652762U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 11311997270710107937U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6227571709361790209U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 5365231114813547251U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 8630110234623825263U;
            aOrbiterH = RotL64((aOrbiterH * 2735881715888325759U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 2358235238039571072U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 18059414891616491807U;
            aOrbiterG = RotL64((aOrbiterG * 17150786106857185467U), 3U);
            //
            aIngress = RotL64(aOrbiterE, 5U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 36U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterE, 43U));
            aWandererK = aWandererK + (((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterJ, 27U)) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 35U)) + aOrbiterA);
            aWandererI = aWandererI + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 56U)) + aOrbiterJ) + RotL64(aCarry, 11U)) + aPhaseGWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 36U) + RotL64(aOrbiterH, 5U)) + aOrbiterE) + aPhaseGWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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

void TwistExpander_Badminton_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0;

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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 1870U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4629U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1156U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneD[((aIndex + 2950U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 34U) + RotL64(aIngress, 21U)) ^ (RotL64(aCross, 47U) ^ RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = ((aWandererI + RotL64(aCross, 5U)) + RotL64(aCarry, 3U)) + 5573188770530340913U;
            aOrbiterG = (((aWandererA + RotL64(aScatter, 60U)) + RotL64(aCarry, 41U)) + 1431772230889897111U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aIngress, 13U)) + 4809192776429682319U;
            aOrbiterJ = (((aWandererD + RotL64(aPrevious, 29U)) + RotL64(aCarry, 23U)) + 5576603692574369341U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (aWandererC + RotL64(aCross, 39U)) + 2720143226007220386U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 17220328778565331629U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 9629485808442089423U;
            aOrbiterA = RotL64((aOrbiterA * 18349580416082045015U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 1136998437010390983U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 11893390497814523841U;
            aOrbiterB = RotL64((aOrbiterB * 5329621622743089531U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 1764986431917532370U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 1741014798007010376U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13414914086049500731U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 12221368453236547044U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 7694538641172350430U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8439120733670016501U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 17472344518811560603U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 3308740700728172984U;
            aOrbiterH = RotL64((aOrbiterH * 15290400462887712083U), 5U);
            //
            aIngress = RotL64(aOrbiterJ, 57U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + RotL64(aOrbiterG, 12U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterB, 51U)) + aOrbiterH);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 44U) + RotL64(aOrbiterJ, 43U)) + aOrbiterG) + RotL64(aCarry, 47U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterG, 24U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 29U)) + aPhaseHWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterB, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 13U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 9899U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10105U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12129U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12490U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 19U) ^ RotL64(aIngress, 4U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = ((aWandererK + RotL64(aCross, 11U)) + RotL64(aCarry, 5U)) + 8402620908307642697U;
            aOrbiterB = (aWandererC + RotL64(aIngress, 3U)) + 11347672014525086047U;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 20U)) + 2816462912503401876U) + aPhaseHOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 29U)) + RotL64(aCarry, 53U)) + 6940159795470696093U;
            aOrbiterE = (((aWandererJ + RotL64(aIngress, 37U)) + RotL64(aCarry, 23U)) + 9134692490095883851U) + aPhaseHOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 4999455497008026526U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 5992451460350651332U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12796550245322491401U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 3417087346651371924U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 3612773820086198270U;
            aOrbiterE = RotL64((aOrbiterE * 5519856345435871169U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 463398077083428570U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 11249391303705089012U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7106735772303292983U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 17027535139825739501U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 568131384979596481U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5683451044852895957U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 4793712537158004047U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 10415170179135963622U;
            aOrbiterH = RotL64((aOrbiterH * 13729564030210361415U), 29U);
            //
            aIngress = RotL64(aOrbiterG, 23U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aIngress, 43U) + aOrbiterE) + RotL64(aOrbiterG, 29U)) + aPhaseHWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 11U) + RotL64(aOrbiterH, 50U)) + aOrbiterA) + RotL64(aCarry, 13U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 60U) + RotL64(aOrbiterH, 13U)) + aOrbiterG) + aPhaseHWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 19U) + RotL64(aOrbiterB, 39U)) + aOrbiterH) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 51U) + aOrbiterE) + RotL64(aOrbiterA, 21U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + RotL64(aWandererF, 51U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 17932U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((aIndex + 17586U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18535U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19630U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 54U) ^ RotL64(aIngress, 21U)) + (RotL64(aPrevious, 37U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 5U)) + 2974056819475622600U) + aPhaseHOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aCross, 47U)) + 7345051759236356098U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aIngress, 18U)) + RotL64(aCarry, 27U)) + 12738468816846628882U;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 27U)) + RotL64(aCarry, 51U)) + 7694520596043297922U;
            aOrbiterC = ((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 13U)) + 5530753590015084774U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 3776309161718383105U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 784780304358106404U;
            aOrbiterD = RotL64((aOrbiterD * 1503119308251871519U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 8999942326995036509U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 5194986506064092779U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15070787038006135963U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 7920040007459652762U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 11311997270710107937U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6227571709361790209U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 5365231114813547251U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 8630110234623825263U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2735881715888325759U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 2358235238039571072U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 18059414891616491807U;
            aOrbiterC = RotL64((aOrbiterC * 17150786106857185467U), 29U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 29U);
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 37U)) + aOrbiterI) + RotL64(aCarry, 27U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 50U) + RotL64(aOrbiterD, 19U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((RotL64(aCross, 39U) + aOrbiterE) + RotL64(aOrbiterD, 54U)) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 3U)) + aOrbiterC);
            aWandererB = aWandererB + (((RotL64(aCross, 19U) + RotL64(aOrbiterI, 29U)) + aOrbiterE) + aPhaseHWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 56U));
            aCarry = aCarry + RotL64(aWandererJ, 41U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 28569U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32706U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31412U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 27260U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 13U) ^ RotL64(aPrevious, 43U)) + (RotL64(aIngress, 57U) + RotL64(aCarry, 28U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (aWandererB + RotL64(aPrevious, 29U)) + 4980738603982643969U;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 13U)) + 17660278413018470020U;
            aOrbiterG = ((aWandererC + RotL64(aCross, 20U)) + RotL64(aCarry, 41U)) + 17598114429859543466U;
            aOrbiterI = (((aWandererF + RotL64(aIngress, 43U)) + RotL64(aCarry, 29U)) + 10993929335279994739U) + aPhaseHOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aScatter, 11U)) + 17967203122976322481U) + aPhaseHOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 1872290205549034384U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 16607778671782810797U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 340054507611349681U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 4895226930754394376U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 14960359005982301383U;
            aOrbiterA = RotL64((aOrbiterA * 8546231310054433721U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 9921642352377700630U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 893281964367208693U;
            aOrbiterI = RotL64((aOrbiterI * 2345509157333444217U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 8232519988397858732U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 4433022122758913407U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 834240393225479419U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 12689609831247168353U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 404535388957472176U;
            aOrbiterE = RotL64((aOrbiterE * 14534020545479806593U), 35U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterI, 23U);
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterG, 34U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 58U) + aOrbiterI) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterI, 47U)) + aOrbiterE) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 35U) + RotL64(aOrbiterA, 30U)) + aOrbiterD);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterE, 39U));
            aWandererF = aWandererF + ((((RotL64(aCross, 43U) + RotL64(aOrbiterD, 19U)) + aOrbiterG) + RotL64(aCarry, 37U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + RotL64(aWandererC, 51U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
