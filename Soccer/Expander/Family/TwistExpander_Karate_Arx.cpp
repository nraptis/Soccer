#include "TwistExpander_Karate_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Karate_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xC716B2D9DFA73DE1ULL + 0xD568E32146221C3BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xDB5C038BA87FA95FULL + 0xE1038DADDB5B6795ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xBD3F2FCD7C932485ULL + 0x930581A6930BF877ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xEA9C21768DB2F101ULL + 0x94A9F21FF3ACC766ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xCC84042EBDE6BCCFULL + 0xAC3DF68E9D30CB82ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xF84A2FC7684D9CD7ULL + 0xD7B11FC04DDADFDAULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xE01C5F91D0E57D87ULL + 0x801AF78791D54973ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xAC1D133EE29CB693ULL + 0x90A92867ABD4DFCBULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xBC61A02F4EF28DFBULL + 0xFD26ABCDC3974452ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xD260D1A2AA6FA11BULL + 0xA6BF744A2B8407DDULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xAF92827070FCD0EDULL + 0xD6EA54B2DC5E4A24ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x8C08B4BD5C45EF3DULL + 0xB238BE95DD11B7A0ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xA35DDED13A108CAFULL + 0x9D80BF32628732D7ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xF5A52101526B7D0DULL + 0xB914DB278743106AULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xFC4D527BDCA7E1BDULL + 0x81295DF0D0403E5DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xC86A6BF40DD2933FULL + 0xAEF1ED785CA8ACC2ULL);
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
            aIngress = RotL64(mSource[((aIndex + 4314U)) & S_BLOCK1], 5U) ^ RotL64(pSnow[((aIndex + 4894U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 2485U)) & S_BLOCK1], 51U) ^ RotL64(mSource[((aIndex + 1833U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 40U) + RotL64(aCarry, 19U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterC = (aWandererH + RotL64(aPrevious, 47U)) + 16160838483846078448U;
            aOrbiterA = (aWandererJ + RotL64(aCross, 57U)) + 15404960896190227946U;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 20U)) + 16904160594024977199U) + aOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = (((aWandererG + RotL64(aIngress, 27U)) + RotL64(aCarry, 57U)) + 17790460246821031802U) + aNonceWordB;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 23U)) + RotL64(aCarry, 11U)) + 16395168254086971959U;
            aOrbiterD = (aWandererF + RotL64(aScatter, 11U)) + 7484373204039901786U;
            aOrbiterB = (aWandererE + RotL64(aCross, 13U)) + 18026814691322913510U;
            aOrbiterK = (aWandererA + RotL64(aIngress, 18U)) + 15244817793136966450U;
            aOrbiterI = (aWandererC + RotL64(aCross, 51U)) + 5795491730356335666U;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 37U)) + 3163873518027801504U) + aNonceWordA;
            aOrbiterH = ((((aWandererI + RotL64(aScatter, 3U)) + RotL64(aCarry, 21U)) + 2690791759507349172U) + aOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordC;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 17898067251167087906U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 8028010015006604239U;
            aOrbiterF = RotL64((aOrbiterF * 5601629670521300241U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 7304739457289910555U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 6476837815096530043U;
            aOrbiterD = RotL64((aOrbiterD * 16380545138701113267U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 14242499233467960602U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 17305645693017634630U;
            aOrbiterC = RotL64((aOrbiterC * 14442976693206929569U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 9772864059444171908U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 7897200728282156408U;
            aOrbiterG = RotL64((aOrbiterG * 816306719390807411U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 4890999319172950996U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 8165132649356094963U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17297706071263690189U), 35U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterF) + 9342923520083533265U) + aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1]) + aNonceWordM;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 7213639583505088067U;
            aOrbiterB = RotL64((aOrbiterB * 1349251979649428909U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 4079475132684197272U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 3350998022472827283U;
            aOrbiterE = RotL64((aOrbiterE * 948841791460066265U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 2479140576609216238U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 7703147534931674972U;
            aOrbiterA = RotL64((aOrbiterA * 11419116495223970801U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 9050277787914448469U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 13295888852307317371U) ^ aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3027097172772140975U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 15380254190549884741U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 17653690414528791774U) ^ aNonceWordH;
            aOrbiterH = RotL64((aOrbiterH * 15923958179714368315U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 6825072759468337036U) + aNonceWordG;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 16160838483846078448U;
            aOrbiterI = RotL64((aOrbiterI * 11690325563580492415U), 53U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterG, 21U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 18U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 60U) + RotL64(aOrbiterI, 3U)) + aOrbiterD) + aNonceWordP) + aWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterA, 28U)) + aOrbiterG);
            aWandererC = aWandererC + (((RotL64(aIngress, 35U) + aOrbiterA) + RotL64(aOrbiterC, 43U)) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 41U) + aOrbiterF) + RotL64(aOrbiterC, 5U));
            aWandererH = aWandererH + (((RotL64(aCross, 39U) + RotL64(aOrbiterE, 53U)) + aOrbiterF) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterH, 19U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 13U) + aOrbiterE) + RotL64(aOrbiterK, 21U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 23U)) + aOrbiterG) + aWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 27U) + aOrbiterD) + RotL64(aOrbiterB, 35U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 37U) + aOrbiterF) + RotL64(aOrbiterI, 11U)) + aNonceWordI);
            aWandererG = aWandererG + (((RotL64(aIngress, 58U) + RotL64(aOrbiterJ, 14U)) + aOrbiterA) + aNonceWordE);
            //
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 52U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 6598U)) & S_BLOCK1], 47U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 8442U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 7141U)) & S_BLOCK1], 40U) ^ RotL64(pSnow[((aIndex + 10660U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 6U) ^ RotL64(aPrevious, 53U)) ^ (RotL64(aIngress, 39U) + RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterB = (aWandererE + RotL64(aIngress, 41U)) + 10915618884692072446U;
            aOrbiterA = (aWandererD + RotL64(aScatter, 21U)) + 12634922308499254909U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 57U)) + 6533934734564499389U) + aOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = (aWandererI + RotL64(aCross, 24U)) + 6744203303756105181U;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 27U)) + 13086782386652045658U) + aOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = (((aWandererH + RotL64(aCross, 5U)) + RotL64(aCarry, 43U)) + 5693840533331397822U) + aNonceWordC;
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 11U)) + 1803663542535024611U;
            aOrbiterH = (aWandererK + RotL64(aScatter, 43U)) + 3597219300593287708U;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 29U)) + RotL64(aCarry, 13U)) + 1429753448204448904U;
            aOrbiterI = (((aWandererF + RotL64(aScatter, 46U)) + RotL64(aCarry, 21U)) + 17229017825587322715U) + aNonceWordB;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 37U)) + 1137574712801062932U) + aNonceWordN;
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 2401991077004083378U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 1332473247826139292U;
            aOrbiterG = RotL64((aOrbiterG * 15029831858261506447U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 11730946340796899885U) + aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 15319163439700390962U;
            aOrbiterD = RotL64((aOrbiterD * 1349242001887975499U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 4744141870145159917U) + aNonceWordK;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 6067132201862688684U;
            aOrbiterH = RotL64((aOrbiterH * 6046100687757836027U), 13U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterH) + 14991509179286371800U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordE;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 4342608825699398682U) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 10240526103933275875U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 3727521409410742075U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 3302027219498304367U;
            aOrbiterC = RotL64((aOrbiterC * 12153634588200479559U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 6039539483340398858U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 2902581519976937051U;
            aOrbiterF = RotL64((aOrbiterF * 2057584328877854239U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 12332784713738947242U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 13761272577223712786U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14930145045480030821U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 2947946397617043735U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 11107014023853644521U) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 15030903626191481831U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 6212403196992771516U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 16107261731677426470U;
            aOrbiterI = RotL64((aOrbiterI * 13764822942405295129U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 8414111492161335472U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 3625937496991123221U;
            aOrbiterK = RotL64((aOrbiterK * 1736741235159600739U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 5466667339391480293U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 10915618884692072446U;
            aOrbiterJ = RotL64((aOrbiterJ * 14719282928172086707U), 41U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterC, 29U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 12U));
            aIngress = aIngress + RotL64(aOrbiterD, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aPrevious, 60U) + aOrbiterB) + RotL64(aOrbiterE, 39U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 53U) + aOrbiterI) + RotL64(aOrbiterK, 29U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 11U) + RotL64(aOrbiterE, 37U)) + aOrbiterG) + aNonceWordI);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 21U) + aOrbiterH) + RotL64(aOrbiterB, 57U)) + aWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 19U) + RotL64(aOrbiterD, 48U)) + aOrbiterJ) + aNonceWordJ);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 41U) + aOrbiterJ) + RotL64(aOrbiterK, 51U));
            aWandererA = aWandererA + ((RotL64(aIngress, 34U) + RotL64(aOrbiterH, 5U)) + aOrbiterK);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 13U) + aOrbiterC) + RotL64(aOrbiterF, 21U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 51U) + aOrbiterF) + RotL64(aOrbiterE, 46U)) + RotL64(aCarry, 11U)) + aWandererUpdateSaltF[((aIndex + 26U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterG, 41U)) + aOrbiterA) + aNonceWordP);
            aWandererI = aWandererI + (((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterJ, 11U)) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 36U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 41U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 60U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 12509U)) & S_BLOCK1], 56U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 11478U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 11965U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneA[((aIndex + 13835U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCross, 10U)) + (RotL64(aCarry, 35U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 35U)) + 252059974543142812U;
            aOrbiterC = (((aWandererF + RotL64(aPrevious, 3U)) + RotL64(aCarry, 23U)) + 11690823093681457368U) + aNonceWordG;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 53U)) + 13282189752890971123U;
            aOrbiterG = ((aWandererE + RotL64(aCross, 43U)) + 9507416294305708435U) + aNonceWordI;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 6U)) + 14053038174390776539U) + aOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aScatter, 47U)) + 14605253312318725009U) + aOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aCross, 11U)) + 18138286582677863671U;
            aOrbiterA = (aWandererH + RotL64(aPrevious, 35U)) + 8530091235978489988U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 14U)) + RotL64(aCarry, 47U)) + 14381731677571170073U;
            aOrbiterK = (aWandererG + RotL64(aIngress, 19U)) + 13316413456378978456U;
            aOrbiterH = (aWandererK + RotL64(aScatter, 39U)) + 3910529530149320706U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 6302070286831566901U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 12324134652758551396U;
            aOrbiterD = RotL64((aOrbiterD * 17136438281540250165U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 4773478557638475048U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 4031153435446078944U;
            aOrbiterC = RotL64((aOrbiterC * 3876928995240982769U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 3114794895962903899U) + aOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 3552936509969106796U;
            aOrbiterJ = RotL64((aOrbiterJ * 16823186892738820299U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 5828754613946145627U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 17985241114076114558U) ^ aNonceWordB;
            aOrbiterF = RotL64((aOrbiterF * 1986669631395606833U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 11319331046368072261U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 6104267020171882160U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12525117969211576177U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 7662668379725735125U) + aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 6583034411403600735U;
            aOrbiterE = RotL64((aOrbiterE * 262095656452193889U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 5569865728026310280U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 4176065898330374039U;
            aOrbiterB = RotL64((aOrbiterB * 11305749530796963967U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 13677146592276526676U) + aNonceWordE;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 2734371113158117596U;
            aOrbiterH = RotL64((aOrbiterH * 13146444882662731975U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 14890607377967461739U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 3110674898918355049U;
            aOrbiterA = RotL64((aOrbiterA * 9637837600671200315U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 15329760212453783067U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 18214263442264013242U;
            aOrbiterI = RotL64((aOrbiterI * 9139354822936682953U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 6727267537859989206U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 252059974543142812U) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 9559128226993261041U), 23U);
            //
            aIngress = RotL64(aOrbiterF, 47U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + (RotL64(aOrbiterB, 38U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterC, 10U)) + RotL64(aCarry, 23U)) + aWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterH, 3U));
            aWandererC = aWandererC + ((RotL64(aIngress, 3U) + aOrbiterD) + RotL64(aOrbiterK, 5U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterB, 29U));
            aWandererB = aWandererB + ((RotL64(aIngress, 41U) + RotL64(aOrbiterG, 41U)) + aOrbiterF);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterH, 51U)) + aNonceWordF);
            aWandererD = aWandererD + ((RotL64(aScatter, 46U) + aOrbiterC) + RotL64(aOrbiterI, 53U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterE, 19U)) + aOrbiterI);
            aWandererI = aWandererI + ((RotL64(aScatter, 37U) + aOrbiterB) + RotL64(aOrbiterE, 26U));
            aWandererF = aWandererF ^ ((((RotL64(aCross, 51U) + aOrbiterK) + RotL64(aOrbiterB, 23U)) + aNonceWordD) + aWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 48U) + aOrbiterD) + RotL64(aOrbiterG, 13U)) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 44U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 42U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 39U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 20095U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17590U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 20839U)) & S_BLOCK1], 21U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 18083U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 20100U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCarry, 10U)) ^ (RotL64(aCross, 35U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterK = (aWandererK + RotL64(aPrevious, 44U)) + 14499676118633326000U;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 3U)) + RotL64(aCarry, 35U)) + 17191273593018552288U;
            aOrbiterH = ((aWandererB + RotL64(aCross, 27U)) + 4085176294948097737U) + aOrbiterAssignSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 11U)) + 11112671474158908186U) + aNonceWordK;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 21U)) + 8745787969012266485U) + aNonceWordM;
            aOrbiterE = (((aWandererG + RotL64(aCross, 13U)) + RotL64(aCarry, 53U)) + 18074049663777707948U) + aNonceWordA;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 56U)) + 2543758649719164688U) + aNonceWordE;
            aOrbiterI = ((aWandererF + RotL64(aScatter, 29U)) + RotL64(aCarry, 11U)) + 4659584749412700523U;
            aOrbiterC = ((aWandererH + RotL64(aCross, 23U)) + 974639159259871273U) + aOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 5U)) + 9211220687971081987U;
            aOrbiterD = (aWandererE + RotL64(aScatter, 19U)) + 8567024626862182714U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 5803002132294840900U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 11968489432878148467U;
            aOrbiterH = RotL64((aOrbiterH * 4501441062617123165U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 9470807228394903442U) + aNonceWordL;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 1692347973120388469U;
            aOrbiterB = RotL64((aOrbiterB * 17433393164156231575U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 16510815732690193145U) + aOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 755159406833096510U;
            aOrbiterA = RotL64((aOrbiterA * 14091736464659561165U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 1518824876475937620U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 701225390867330446U;
            aOrbiterI = RotL64((aOrbiterI * 12264618860580199927U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 8425976693733003889U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 7182176375442410367U;
            aOrbiterE = RotL64((aOrbiterE * 8860605703761731859U), 21U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterC) + 4546566785167467924U) + aOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 2593340999038753749U) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 10152461487764567563U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 9756331608356622299U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 5511625814747641978U;
            aOrbiterC = RotL64((aOrbiterC * 4806076157539829529U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 8694400787420160733U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 12648969491371382682U;
            aOrbiterF = RotL64((aOrbiterF * 5346585704222643759U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 15261238546696118531U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 14236129054778329471U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11789581469516267749U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 16251500056378064213U) + aNonceWordJ;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 790320176607605195U;
            aOrbiterK = RotL64((aOrbiterK * 15706130623435648555U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 17114773669444878655U) + aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 14499676118633326000U;
            aOrbiterG = RotL64((aOrbiterG * 8095707555083587081U), 11U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterI, 57U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 51U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 24U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 37U));
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterK, 43U)) + aOrbiterG) + aNonceWordD);
            aWandererF = aWandererF + (((RotL64(aCross, 37U) + aOrbiterB) + RotL64(aOrbiterI, 48U)) + aNonceWordG);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 41U) + aOrbiterB) + RotL64(aOrbiterK, 11U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 54U) + RotL64(aOrbiterB, 35U)) + aOrbiterJ) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 3U) + aOrbiterB) + RotL64(aOrbiterH, 41U)) + aWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 27U) + aOrbiterK) + RotL64(aOrbiterD, 27U)) + aNonceWordC);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 29U) + aOrbiterE) + RotL64(aOrbiterA, 51U)) + aWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aCross, 23U) + RotL64(aOrbiterK, 60U)) + aOrbiterI) + RotL64(aCarry, 53U)) + aNonceWordP);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterG, 29U));
            aWandererC = aWandererC + ((RotL64(aCross, 50U) + aOrbiterC) + RotL64(aOrbiterF, 53U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 5U) + aOrbiterC) + RotL64(aOrbiterA, 3U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 42U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + RotL64(aWandererE, 27U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 25366U)) & S_BLOCK1], 47U) ^ RotL64(mSource[((aIndex + 25873U)) & S_BLOCK1], 37U));
            aIngress ^= (RotL64(pSnow[((aIndex + 23083U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 22820U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23960U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27041U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 43U) + RotL64(aCarry, 5U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCross, 28U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 41U)) + 8793908991006073956U) + aNonceWordE;
            aOrbiterH = (aWandererJ + RotL64(aCross, 21U)) + 2932916283348441943U;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 27U)) + 11069042087940968262U) + aNonceWordN;
            aOrbiterG = (aWandererF + RotL64(aScatter, 13U)) + 14369628676782894441U;
            aOrbiterA = ((((aWandererD + RotL64(aPrevious, 57U)) + RotL64(aCarry, 35U)) + 8602903272780978282U) + aOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordK;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 3U)) + 3827036107178568820U) + aNonceWordI;
            aOrbiterE = ((aWandererC + RotL64(aCross, 10U)) + RotL64(aCarry, 3U)) + 8905245209036772489U;
            aOrbiterD = (aWandererG + RotL64(aScatter, 47U)) + 13331387530760017893U;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 35U)) + RotL64(aCarry, 13U)) + 9880107580289737823U;
            aOrbiterF = ((aWandererE + RotL64(aCross, 53U)) + 10199619040626900278U) + aOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aScatter, 30U)) + 2466307560891374281U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 13973403407981259448U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 2851460278409385243U;
            aOrbiterB = RotL64((aOrbiterB * 11226902976321781743U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 10365453393815690776U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 2382382358987358791U;
            aOrbiterA = RotL64((aOrbiterA * 481563628980705781U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 5058198848163792422U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 10500434740387593487U) ^ aNonceWordD;
            aOrbiterE = RotL64((aOrbiterE * 5946747708776079787U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 11289798395177667084U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 14327152153231286666U;
            aOrbiterJ = RotL64((aOrbiterJ * 18155778059595245561U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 8065137263811956313U) + aNonceWordF;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 3865153574847924816U;
            aOrbiterG = RotL64((aOrbiterG * 9495741102667755161U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 18102279969722473375U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 6306428427188742325U;
            aOrbiterC = RotL64((aOrbiterC * 17826782872351406167U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 16953348204663693724U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 11950791817032898613U;
            aOrbiterF = RotL64((aOrbiterF * 1498946055469611133U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 11980823193543752994U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 17845490308799454871U;
            aOrbiterH = RotL64((aOrbiterH * 16385153013485463791U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 5566398755702887071U) + aNonceWordH;
            aOrbiterD = (((aOrbiterD ^ aOrbiterA) ^ 10308378271388889968U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterD = RotL64((aOrbiterD * 142732084484961281U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 6717846700455219260U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 8297225372883997017U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14102812043481327907U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 12249337046267666603U) + aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 8793908991006073956U;
            aOrbiterK = RotL64((aOrbiterK * 5851229209188473467U), 23U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 3U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 39U));
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterI, 46U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 39U)) + aOrbiterD);
            aWandererE = aWandererE + (((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterE, 30U)) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 5U)) + aOrbiterA) + aWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterJ, 57U)) + aOrbiterG) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterB, 11U));
            aWandererC = aWandererC + (((RotL64(aIngress, 21U) + RotL64(aOrbiterD, 46U)) + aOrbiterE) + aNonceWordL);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 60U) + aOrbiterI) + RotL64(aOrbiterE, 21U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterB, 23U)) + aNonceWordG) + aWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 23U) + aOrbiterG) + RotL64(aOrbiterC, 41U)) + aNonceWordC);
            aWandererD = aWandererD + ((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterH, 53U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 14U) + RotL64(aOrbiterK, 37U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 22U));
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + RotL64(aWandererK, 34U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 30320U)) & S_BLOCK1], 53U) ^ RotL64(pSnow[((aIndex + 32700U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 31500U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 28347U)) & S_BLOCK1], 39U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 32361U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 30575U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCross, 54U)) ^ (RotL64(aPrevious, 3U) + RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 27U)) + RotL64(aCarry, 37U)) + 11039986441331892533U;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 21U)) + 6256024955965426119U) + aNonceWordG;
            aOrbiterK = ((aWandererG + RotL64(aScatter, 24U)) + 9857443189988995666U) + aOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aIngress, 5U)) + RotL64(aCarry, 43U)) + 11900944813380998208U;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 47U)) + 8422577734978875541U) + aNonceWordP;
            aOrbiterG = (aWandererF + RotL64(aIngress, 37U)) + 3100835100713928724U;
            aOrbiterJ = (aWandererA + RotL64(aCross, 29U)) + 11871553509810206993U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 19U)) + 17614749493763417027U;
            aOrbiterA = (aWandererK + RotL64(aPrevious, 34U)) + 3638372131856199916U;
            aOrbiterE = ((aWandererC + RotL64(aCross, 57U)) + RotL64(aCarry, 47U)) + 6582275259281025770U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 39U)) + 17016882418498941958U) + aOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 1747214688658984715U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 9356088987044015278U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16221733545319753695U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 4056238112133473456U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 16013150119949532998U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12913648646318115315U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 16076621211111834889U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 9940824359571581765U;
            aOrbiterH = RotL64((aOrbiterH * 11624767861336495331U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 15624084004784515753U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 7630989544834680335U;
            aOrbiterA = RotL64((aOrbiterA * 12261063237156822067U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 18003586430673313786U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 1654118743290334161U;
            aOrbiterF = RotL64((aOrbiterF * 1153250137357176071U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 3254189676528343910U) + aNonceWordM;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 15629083361573065165U;
            aOrbiterE = RotL64((aOrbiterE * 17024833368570949107U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 10056859810555674806U) + aOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 15976683222786846254U;
            aOrbiterJ = RotL64((aOrbiterJ * 2801754232182942635U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 11872378594829637933U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 7633773773528713489U;
            aOrbiterG = RotL64((aOrbiterG * 8218288492011593353U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 16305188578382203720U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 13293036594949754170U;
            aOrbiterB = RotL64((aOrbiterB * 1300645662609848183U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 15185013801659166674U) + aNonceWordF;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 11562899709899198100U;
            aOrbiterD = RotL64((aOrbiterD * 9115495024409604629U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 1525205566739385260U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 11039986441331892533U;
            aOrbiterI = RotL64((aOrbiterI * 9802284050237622047U), 19U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterC, 53U);
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterG, 48U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + RotL64(aOrbiterA, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aScatter, 47U) + RotL64(aOrbiterG, 14U)) + aOrbiterK);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 19U)) + aOrbiterK);
            aWandererF = aWandererF + (((RotL64(aCross, 41U) + RotL64(aOrbiterC, 27U)) + aOrbiterH) + aNonceWordJ);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 12U) + aOrbiterE) + RotL64(aOrbiterA, 39U));
            aWandererC = aWandererC + ((RotL64(aIngress, 35U) + RotL64(aOrbiterK, 53U)) + aOrbiterH);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterI, 46U)) + aOrbiterB);
            aWandererK = aWandererK + ((((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterG, 11U)) + aNonceWordN) + aWandererUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 54U) + aOrbiterA) + RotL64(aOrbiterF, 51U));
            aWandererH = aWandererH + (((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 37U) + aOrbiterJ) + RotL64(aOrbiterE, 37U));
            aWandererB = aWandererB + (((((RotL64(aCross, 29U) + aOrbiterD) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 3U)) + aNonceWordI) + aWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 60U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + (RotL64(aWandererA, 34U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void TwistExpander_Karate_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xEB0092CFADF86E93ULL + 0xA079A42E78EE36D9ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x9BA8E22376D165FDULL + 0xBF79A6A1EF723787ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xFEB918768243D36DULL + 0xA6796F9758B6A149ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xAC07AEBDC0E2AE3FULL + 0xC4329B6F31FE2E6EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xC6F8A11BFB1778CBULL + 0xB01C2D1FCC8C7098ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xBE0B378BC221D6ADULL + 0xE1656FE8B3EF1EDEULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xED3AD0D021FCE305ULL + 0xB42ADB7BAAEC414CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x946C67A10C9BE7F1ULL + 0xEF8E5BDE92908EACULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xA1587B4B6115D305ULL + 0xDF91E60320809F02ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xA1FBD2FE6E5E2A1BULL + 0xCE3EDE2B18C7E3CEULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xE86B8DD25850E043ULL + 0xB6FEBB75273486A5ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x81221755F9D0C8F7ULL + 0xAEE3E8FEE56BBD9FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xE1BA5480A5B77883ULL + 0xC234A18C6B6C25F2ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xCA3F9D2D7AAEC05FULL + 0xEF1F86F707D3D833ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x99D7924754E22C99ULL + 0xF9E8D9DC3F38AB02ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xCFBD171FEAB76DA5ULL + 0xF1440D8FBCE1CFEDULL);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 720U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 7774U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 6400U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneD[((aIndex + 7825U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aIngress, 18U)) + (RotL64(aCarry, 47U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterG = (((aWandererB + RotL64(aCross, 19U)) + 18319689184146942855U) + aOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1]) + aNonceWordL;
            aOrbiterD = (aWandererA + RotL64(aIngress, 37U)) + 8041304130090501019U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 43U)) + RotL64(aCarry, 51U)) + 11347064191990897738U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 52U)) + 15242243470024447468U) + aOrbiterAssignSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 11U)) + RotL64(aCarry, 37U)) + 10619749107163611105U;
            aOrbiterB = ((aWandererJ + RotL64(aCross, 3U)) + RotL64(aCarry, 29U)) + 14795614276221947128U;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 29U)) + 1578095288886372393U) + aNonceWordC;
            aOrbiterE = (aWandererD + RotL64(aPrevious, 57U)) + 13593906305770501684U;
            aOrbiterI = (aWandererI + RotL64(aIngress, 24U)) + 8919815528334599172U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 17425548324720065145U) + aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 11125018338392347335U) ^ aNonceWordI;
            aOrbiterF = RotL64((aOrbiterF * 4377887040461528587U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 3779189180734244399U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 10958224663276134041U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6206963519509783781U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 4317305352561612995U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 4891139433808505355U;
            aOrbiterG = RotL64((aOrbiterG * 11507024985663120317U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 5166074784835930965U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 10080890270621589202U;
            aOrbiterB = RotL64((aOrbiterB * 13170894418184288695U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 4501071771615514619U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 6486573807774431753U;
            aOrbiterA = RotL64((aOrbiterA * 324029625116648669U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 15714881857668975753U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 3506619392820235900U) ^ aNonceWordF;
            aOrbiterE = RotL64((aOrbiterE * 5707033870161224499U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 5295711072762443783U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 11192836530396570648U) ^ aNonceWordD;
            aOrbiterD = RotL64((aOrbiterD * 4361810118382207039U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 7993389678399774574U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 12551394763541226695U;
            aOrbiterI = RotL64((aOrbiterI * 11903486656172026403U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 11553674370322129668U) + aNonceWordP;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 4459881583199320245U) ^ aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2805857426321555685U), 51U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterA, 43U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 20U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 58U)) + aOrbiterF) + RotL64(aCarry, 21U)) + aWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 3U)) + aOrbiterI) + aNonceWordB);
            aWandererI = aWandererI + ((RotL64(aIngress, 6U) + RotL64(aOrbiterJ, 35U)) + aOrbiterB);
            aWandererE = aWandererE ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterD, 53U)) + aOrbiterE);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 21U) + RotL64(aOrbiterF, 39U)) + aOrbiterG) + aWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterD, 43U)) + aOrbiterF) + aNonceWordG);
            aWandererF = aWandererF + ((((RotL64(aIngress, 56U) + RotL64(aOrbiterE, 27U)) + aOrbiterI) + RotL64(aCarry, 57U)) + aNonceWordJ);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 13U) + aOrbiterB) + RotL64(aOrbiterE, 14U)) + aNonceWordN);
            aWandererG = aWandererG + ((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 19U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererA, 24U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 15585U)) & S_BLOCK1], 23U) ^ RotL64(aFireLaneB[((aIndex + 15902U)) & S_BLOCK1], 44U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 12270U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 9567U)) & S_BLOCK1], 41U) ^ RotL64(aFireLaneD[((aIndex + 9719U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 51U)) + (RotL64(aIngress, 23U) ^ RotL64(aCarry, 38U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterB = ((((aWandererG + RotL64(aCross, 35U)) + RotL64(aCarry, 13U)) + 17081642665820489793U) + aOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordB;
            aOrbiterI = (aWandererJ + RotL64(aIngress, 39U)) + 14468854040067229623U;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 6U)) + RotL64(aCarry, 23U)) + 2249450222593057429U;
            aOrbiterH = (((aWandererB + RotL64(aPrevious, 19U)) + RotL64(aCarry, 57U)) + 14964389079511378664U) + aNonceWordL;
            aOrbiterD = (aWandererF + RotL64(aIngress, 51U)) + 17003491054252360650U;
            aOrbiterF = (aWandererD + RotL64(aCross, 57U)) + 12710882240582032588U;
            aOrbiterA = (aWandererA + RotL64(aScatter, 29U)) + 9887078182156755359U;
            aOrbiterK = (((aWandererE + RotL64(aPrevious, 13U)) + 7665284531810584704U) + aOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1]) + aNonceWordC;
            aOrbiterC = (aWandererH + RotL64(aScatter, 46U)) + 7304284015511876717U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 5517927023543751734U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterB) ^ 17704756310857362759U) ^ aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 15826832172923213591U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 11347400363019508578U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 11696395232760991243U;
            aOrbiterD = RotL64((aOrbiterD * 9725231749679442003U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 10875780291242873583U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 7808740614343437672U;
            aOrbiterA = RotL64((aOrbiterA * 8889516201913716283U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 3145390996141902032U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 16080636485642732615U;
            aOrbiterF = RotL64((aOrbiterF * 7445756373012217305U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 3929263288176983844U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 18210228766683996806U;
            aOrbiterI = RotL64((aOrbiterI * 13178080076505449091U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 13948962323541421431U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 3037683309790156893U;
            aOrbiterK = RotL64((aOrbiterK * 13406672352222636739U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 17827265198532699474U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 7270895262023504864U;
            aOrbiterC = RotL64((aOrbiterC * 13467417362477308167U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 6431243064980879185U) + aNonceWordG;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 6680205390976259885U) ^ aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10421386694108590789U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 15910655919164357152U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 8046213498216027383U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 18061867495824063553U), 43U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 60U);
            aIngress = aIngress + (RotL64(aOrbiterI, 39U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterC, 51U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 43U) + aOrbiterD) + RotL64(aOrbiterF, 4U)) + aWandererUpdateSaltA[((aIndex + 8U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 29U)) + aOrbiterC) + RotL64(aCarry, 39U)) + aNonceWordP);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 27U) + aOrbiterA) + RotL64(aOrbiterF, 21U));
            aWandererK = aWandererK + ((RotL64(aCross, 22U) + aOrbiterB) + RotL64(aOrbiterI, 57U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterF, 47U)) + aNonceWordA);
            aWandererF = aWandererF + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 35U)) + aOrbiterH);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterC, 40U)) + aOrbiterB);
            aWandererD = aWandererD + ((((RotL64(aCross, 10U) + RotL64(aOrbiterH, 51U)) + aOrbiterE) + RotL64(aCarry, 27U)) + aWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterC, 11U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 41U));
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 38U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 18826U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneD[((aIndex + 16627U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 21211U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24254U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 19445U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 17503U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aIngress, 11U)) + (RotL64(aPrevious, 29U) + RotL64(aCross, 54U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterH = ((aWandererB + RotL64(aScatter, 12U)) + 9435962834163239322U) + aNonceWordE;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 23U)) + 10524704356081318973U;
            aOrbiterK = (((aWandererE + RotL64(aCross, 47U)) + 7403401305665208680U) + aOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1]) + aNonceWordL;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 51U)) + 7525414805023556493U) + aNonceWordO;
            aOrbiterF = (((aWandererK + RotL64(aCross, 43U)) + RotL64(aCarry, 3U)) + 1116686470029070951U) + aOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aIngress, 60U)) + 13257612299137802420U;
            aOrbiterB = (aWandererI + RotL64(aScatter, 3U)) + 9181543003986598283U;
            aOrbiterC = (aWandererH + RotL64(aPrevious, 23U)) + 9739384852307501107U;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 29U)) + RotL64(aCarry, 37U)) + 11308402900229016057U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 14935167593705272337U) + aNonceWordJ;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 7171824007631943535U;
            aOrbiterK = RotL64((aOrbiterK * 4839974427616194289U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 8068411284829563567U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 12350207458513447578U) ^ aNonceWordF;
            aOrbiterF = RotL64((aOrbiterF * 813973258659041895U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 17039236343991574134U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 18291683592714999632U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7771718817924840713U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 6239616841884430968U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 10604527977569876774U;
            aOrbiterH = RotL64((aOrbiterH * 6972820410084939637U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 1707724300671717658U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 3802268808625297647U;
            aOrbiterC = RotL64((aOrbiterC * 11296811630387191563U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 9423064323799920219U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 242153923313096551U;
            aOrbiterB = RotL64((aOrbiterB * 12117679073775630197U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 945801070951928277U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterI) ^ 13094814302414492064U) ^ aOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterE = RotL64((aOrbiterE * 14638176479878969775U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 7572219725951040117U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 16494986983782503428U;
            aOrbiterG = RotL64((aOrbiterG * 2739189408707408171U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 10949497978229234856U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 11219643352002119905U) ^ aNonceWordK;
            aOrbiterA = RotL64((aOrbiterA * 16900635614259262873U), 27U);
            //
            aIngress = RotL64(aOrbiterH, 13U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 35U));
            aIngress = aIngress + (RotL64(aOrbiterE, 30U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aScatter, 38U) + RotL64(aOrbiterE, 43U)) + aOrbiterF) + RotL64(aCarry, 3U)) + aNonceWordD);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 3U)) + aOrbiterC);
            aWandererJ = aWandererJ + (((RotL64(aCross, 19U) + aOrbiterI) + RotL64(aOrbiterH, 47U)) + aNonceWordA);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 39U)) + aOrbiterC);
            aWandererI = aWandererI + ((((RotL64(aScatter, 51U) + RotL64(aOrbiterB, 52U)) + aOrbiterF) + aNonceWordC) + aWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 12U) + RotL64(aOrbiterE, 57U)) + aOrbiterI);
            aWandererB = aWandererB + (((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 19U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 3U) + aOrbiterF) + RotL64(aOrbiterA, 19U)) + aWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 23U) + RotL64(aOrbiterK, 12U)) + aOrbiterB) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 54U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + RotL64(aWandererG, 51U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 30119U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneC[((aIndex + 25466U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 32128U)) & S_BLOCK1], 50U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27656U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 32655U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 26506U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 42U)) + (RotL64(aCarry, 29U) ^ RotL64(aIngress, 13U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterC = ((aWandererC + RotL64(aCross, 56U)) + 8020711767807230555U) + aNonceWordF;
            aOrbiterE = (aWandererI + RotL64(aPrevious, 13U)) + 15368693777246341570U;
            aOrbiterA = ((((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 41U)) + 5117523734225562401U) + aOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1]) + aNonceWordH;
            aOrbiterG = (aWandererE + RotL64(aScatter, 43U)) + 13155269151097507808U;
            aOrbiterF = (aWandererB + RotL64(aIngress, 23U)) + 9879303753623578272U;
            aOrbiterI = ((((aWandererF + RotL64(aCross, 5U)) + RotL64(aCarry, 5U)) + 1165799257173794826U) + aOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordE;
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 47U)) + 930641942062732091U;
            aOrbiterK = ((aWandererK + RotL64(aScatter, 36U)) + RotL64(aCarry, 29U)) + 11330571332221123153U;
            aOrbiterH = (aWandererG + RotL64(aIngress, 19U)) + 2862963158282518899U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 6019186399361476659U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 1924419843785161958U;
            aOrbiterA = RotL64((aOrbiterA * 9485557122500346869U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 12618629043591380461U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterG) ^ 9334176504266512405U) ^ aOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 18239109235362925739U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 16829692481030013551U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 5604784396927022709U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2833893610883508353U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 16124030106598549644U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 16571659812830230677U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4668250364992383549U), 47U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterF) + 15171089673591843703U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordC;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 2826755560293849328U;
            aOrbiterI = RotL64((aOrbiterI * 9397017963457655287U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 9976785768283589291U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 11845100564714691809U;
            aOrbiterH = RotL64((aOrbiterH * 4935139932585319251U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 7318560453127859950U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 3039196878830506712U) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 3140508261330698717U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 8850992055588337843U) + aNonceWordB;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 4219373528176869146U;
            aOrbiterK = RotL64((aOrbiterK * 1310964742529956743U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 1341474458715938799U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 15937557372891732898U;
            aOrbiterC = RotL64((aOrbiterC * 11437307017920192915U), 23U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 56U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 44U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 52U) + RotL64(aOrbiterJ, 51U)) + aOrbiterF) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterA, 37U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 11U)) + aOrbiterC) + aNonceWordP);
            aWandererC = aWandererC ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterJ, 30U)) + aOrbiterI) + aWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterC, 57U)) + RotL64(aCarry, 13U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 39U) + aOrbiterK) + RotL64(aOrbiterG, 19U)) + aWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 23U)) + aOrbiterC);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 6U)) + aOrbiterG);
            aWandererG = aWandererG + (((RotL64(aScatter, 58U) + RotL64(aOrbiterF, 41U)) + aOrbiterC) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererF, 50U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 35U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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

void TwistExpander_Karate_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC0A644998A50C635ULL + 0x8E892204DCABA41FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xDE5B76D6A7BA30B9ULL + 0xAFBF146E90BC6333ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xF07C7879EAC3839DULL + 0xCA08D419C3D92438ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xDB03445D4DFB0627ULL + 0xB8DB1C23011874CFULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xB4063EB87F6D17E9ULL + 0x8ADF19E977D26CB1ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xE946577AA220E4DDULL + 0x9AA0E6E13CFC5061ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xB47272CF8FAC8645ULL + 0xF7204026C2D6231DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x8555C5BCC1566B7DULL + 0xC82C2E969B5DBEE4ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x96EF9072B5508043ULL + 0xB86798480E6201D9ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xEA412295415001E7ULL + 0xE324EB23C002F967ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xC064124F89002C4BULL + 0xA377E270F0E7C8DEULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x8528A9B12D79C82BULL + 0xD48B9058263DE92FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xF673C0937F525F37ULL + 0x8EBFE25F0294E90CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xC805EE2A4AB8FDE7ULL + 0x9B3DB0D7BF6CB719ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x82B7F32556E832F5ULL + 0xC9824BBDB69341C6ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xA1E08573B9DCF15FULL + 0x93AAAE522DD645C7ULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneA, aOperationLaneC, aOperationLaneD, aWorkLaneA, aFireLaneD, aWorkLaneB, aFireLaneC, aWorkLaneC, aFireLaneB
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 359U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((aIndex + 112U)) & S_BLOCK1], 26U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 6473U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 6844U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneD[((aIndex + 3619U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 47U) ^ RotL64(aPrevious, 35U)) + (RotL64(aCarry, 18U) ^ RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterC = (((aWandererD + RotL64(aCross, 46U)) + RotL64(aCarry, 29U)) + 15652862298542575895U) + aOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 57U)) + RotL64(aCarry, 53U)) + 16925323928418184554U;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 35U)) + 4413861484961668394U) + aNonceWordO;
            aOrbiterA = (((aWandererA + RotL64(aScatter, 21U)) + RotL64(aCarry, 5U)) + 2215946422098155969U) + aOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aIngress, 13U)) + 14975185533513111110U) + aNonceWordD;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 9711613814905834552U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 13154957291850149471U) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 17049677190793844477U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 5058313016418534840U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 15011423472941211620U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6125316151731105673U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 2030053257469580168U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 150530795186791193U;
            aOrbiterJ = RotL64((aOrbiterJ * 11106050063717096073U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 10878237472104183427U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 11724672539469573109U;
            aOrbiterC = RotL64((aOrbiterC * 16158741837357985395U), 51U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterI) + 9589700906445846956U) + aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1]) + aNonceWordA;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 1367381624958248949U;
            aOrbiterA = RotL64((aOrbiterA * 8459515089081211977U), 5U);
            //
            aIngress = RotL64(aOrbiterG, 40U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterI, 3U)) + aOrbiterC);
            aWandererD = aWandererD + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 13U)) + aOrbiterG) + RotL64(aCarry, 19U)) + aNonceWordI);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 38U) + RotL64(aOrbiterC, 23U)) + aOrbiterA) + aNonceWordJ);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterA, 37U)) + RotL64(aCarry, 41U)) + aWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterI, 48U)) + aOrbiterG) + aWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererD, 41U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 2
        // ingress from: aWorkLaneA, aOperationLaneC, aFireLaneD
        // ingress directions: aWorkLaneA forward forced, aOperationLaneC forward forced, aFireLaneD forward/backward random
        // cross from: aOperationLaneA, aOperationLaneD, aOperationLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneD backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 12816U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((aIndex + 15438U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 12077U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 9727U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 13768U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 12344U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aIngress, 10U)) ^ (RotL64(aPrevious, 41U) + RotL64(aCarry, 29U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterJ = (((aWandererG + RotL64(aScatter, 47U)) + RotL64(aCarry, 27U)) + 3561491146322798260U) + aNonceWordF;
            aOrbiterB = (((aWandererI + RotL64(aIngress, 29U)) + RotL64(aCarry, 57U)) + 7075025056181885339U) + aOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = ((((aWandererJ + RotL64(aCross, 19U)) + RotL64(aCarry, 13U)) + 9230910887904171613U) + aOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1]) + aNonceWordM;
            aOrbiterK = (aWandererK + RotL64(aPrevious, 37U)) + 4119781172609908917U;
            aOrbiterI = (aWandererH + RotL64(aIngress, 10U)) + 17155609083870983149U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 2423018561430181695U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = (((aOrbiterF ^ aOrbiterJ) ^ 12957280305617615744U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 17696410107705645631U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 2461704174772065813U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 7907123257849391997U) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 9416171962847312179U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 7257868138318960007U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 16425903703085702285U) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 7996935869077231999U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 2990822664594079467U) + aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 5654819006718953817U) ^ aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4465096036756887801U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 12183676471235678779U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 15026286960542123922U) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 17199049329995315279U), 3U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 38U);
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterK, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aCross, 46U) + RotL64(aOrbiterK, 11U)) + aOrbiterF) + RotL64(aCarry, 11U)) + aNonceWordP);
            aWandererH = aWandererH ^ ((((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterK, 58U)) + aNonceWordC) + aWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterB, 3U)) + aNonceWordI);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 37U) + aOrbiterK) + RotL64(aOrbiterJ, 21U)) + aNonceWordO);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 29U)) + aOrbiterK) + RotL64(aCarry, 47U)) + aWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererJ, 23U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 3
        // ingress from: aWorkLaneB, aOperationLaneD, aFireLaneC
        // ingress directions: aWorkLaneB forward forced, aOperationLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aWorkLaneA, aOperationLaneB, aOperationLaneC
        // cross directions: aWorkLaneA backward forced, aOperationLaneB backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 17658U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneD[((aIndex + 18725U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 22844U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19312U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 23360U)) & S_BLOCK1], 28U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 19702U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 43U) + RotL64(aPrevious, 13U)) ^ (RotL64(aCarry, 27U) + RotL64(aIngress, 60U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterC = (((aWandererE + RotL64(aIngress, 29U)) + 12311607308490066301U) + aOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1]) + aNonceWordN;
            aOrbiterE = (aWandererB + RotL64(aCross, 20U)) + 13100864684740679846U;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 5U)) + RotL64(aCarry, 27U)) + 13697304189274329704U;
            aOrbiterF = (((aWandererA + RotL64(aPrevious, 51U)) + RotL64(aCarry, 51U)) + 9047976902871216732U) + aNonceWordI;
            aOrbiterJ = ((((aWandererH + RotL64(aIngress, 43U)) + RotL64(aCarry, 11U)) + 2147897579538537888U) + aOrbiterAssignSaltE[((aIndex + 4U)) & S_SALT1]) + aNonceWordD;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 2072444829390996142U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 2129307836981020908U) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 8065769537670939667U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 10663145333751112064U) + aNonceWordC;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 15019844390503785459U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7442321463110790449U), 13U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterJ) + 5460865577557928142U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordP;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 15806522559993224197U) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 8722932687972240099U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 6361113778657833389U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 8306013884615042570U;
            aOrbiterC = RotL64((aOrbiterC * 8234258702656728667U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 4038420580499706912U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 11908091484457158973U;
            aOrbiterJ = RotL64((aOrbiterJ * 3964111175645156719U), 21U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 13U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + RotL64(aOrbiterH, 54U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aIngress, 48U) + aOrbiterF) + RotL64(aOrbiterJ, 27U)) + RotL64(aCarry, 53U)) + aWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 35U)) + aOrbiterC) + aNonceWordE);
            aWandererB = aWandererB + (((RotL64(aCross, 13U) + RotL64(aOrbiterH, 53U)) + aOrbiterJ) + aNonceWordM);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterH, 3U)) + aOrbiterC);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterC, 14U)) + RotL64(aCarry, 41U)) + aWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aFireLaneB
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aFireLaneB forward/backward random
        // cross from: aWorkLaneB, aOperationLaneC, aOperationLaneD, aOperationLaneA
        // cross directions: aWorkLaneB backward forced, aOperationLaneC backward forced, aOperationLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 24647U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((aIndex + 27455U)) & S_BLOCK1], 12U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 29774U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31852U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 32214U)) & S_BLOCK1], 19U));
            aCross ^= (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 32154U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneA[((aIndex + 30597U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 54U)) + (RotL64(aPrevious, 37U) ^ RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterD = (((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 47U)) + 1708250618750199233U) + aNonceWordB;
            aOrbiterA = (((aWandererK + RotL64(aCross, 21U)) + RotL64(aCarry, 23U)) + 12009147777553691142U) + aNonceWordK;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 46U)) + 8393982703399156592U) + aNonceWordC;
            aOrbiterC = (((aWandererB + RotL64(aScatter, 57U)) + 3247327098356831221U) + aOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1]) + aNonceWordN;
            aOrbiterJ = (((aWandererJ + RotL64(aIngress, 35U)) + RotL64(aCarry, 35U)) + 3403590155376353737U) + aOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 18197244558104735044U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterD) ^ 3096253642040701606U) ^ aOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterE = RotL64((aOrbiterE * 6656168712438620783U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 8012692688785412179U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 17531946907545680745U) ^ aOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16510602981731506381U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 17687695944270225817U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterJ) ^ 16147773866007628769U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 16926442582711557877U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 18244641303026196497U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 8839160526348897457U) ^ aNonceWordF;
            aOrbiterD = RotL64((aOrbiterD * 14268021129087663397U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 10599266240854068246U) + aNonceWordD;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 2056723540756216155U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13311591601230386375U), 29U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 57U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + RotL64(aOrbiterC, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aCross, 38U) + aOrbiterA) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 43U)) + aWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterD, 13U)) + aOrbiterJ) + aNonceWordA);
            aWandererE = aWandererE + (((RotL64(aPrevious, 21U) + aOrbiterE) + RotL64(aOrbiterA, 47U)) + aNonceWordL);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterD, 39U));
            aWandererK = aWandererK + (((((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 30U)) + aOrbiterC) + RotL64(aCarry, 57U)) + aNonceWordE) + aWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + RotL64(aWandererB, 36U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void TwistExpander_Karate_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xB49A7EE1DACF87D7ULL + 0x98441D41A17D6521ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x899B3FC8DA3B8BC1ULL + 0xD8A7B41E07456156ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xFB53A3F44E783061ULL + 0x88ABE75433D1789DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x8D7B5E443D37513BULL + 0xF25D476EEB9C447DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xD007CFFF4F5C6095ULL + 0xF6F9D0CF818EB88FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xFD67567F34EDCAE1ULL + 0xD95AB8F12C421C1CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xCB00E3B15C76DA95ULL + 0xA7FBE1F65A194F4DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xCC8399725AC06A45ULL + 0x9B4C9927BDD90515ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xB8B22015ABDABC97ULL + 0xC8DD7DC2D6935244ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xDDF23DF1CCDD73BBULL + 0xD27F07B8FFFA55EEULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xB5B999004478A985ULL + 0xC79DC8D434C27095ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xB739FFB0D6B9DC61ULL + 0x961509C02337C325ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xAA428B6FC797D78DULL + 0xB369A3D260415E98ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xB8DCFC8D94C7B275ULL + 0xFDA1D90A5CCE5FCBULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x9C76D3F5ABA98CA1ULL + 0xA10DA0B85FD405DCULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xB75679C6665D95D5ULL + 0xB670CA28EC3523EFULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneD, aExpandLaneC, aExpandLaneD, aFireLaneC, aWorkLaneA, aOperationLaneC, aOperationLaneA, aWorkLaneB, aOperationLaneB, aFireLaneB, aWorkLaneC, aFireLaneA, aOperationLaneD
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_d loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneD
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aFireLaneC
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aFireLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 1613U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneB[((aIndex + 1512U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 2218U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5708U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 1527U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 6022U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aIngress, 24U)) ^ (RotL64(aCross, 39U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterG = ((aWandererJ + RotL64(aCross, 5U)) + 18255347001097480328U) + aNonceWordE;
            aOrbiterH = (aWandererF + RotL64(aIngress, 47U)) + 13679246790311505735U;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 41U)) + RotL64(aCarry, 57U)) + 10565839529765027116U;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 12U)) + 14327172566224769901U;
            aOrbiterE = (((aWandererA + RotL64(aIngress, 35U)) + 16239024612038195174U) + aOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1]) + aNonceWordL;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 19U)) + RotL64(aCarry, 13U)) + 13800012174212131890U;
            aOrbiterD = (((aWandererI + RotL64(aCross, 53U)) + RotL64(aCarry, 41U)) + 13900288860157577583U) + aOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 4144386119777112740U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 3154558262670631372U;
            aOrbiterA = RotL64((aOrbiterA * 13236911910092437063U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 7456728543137614001U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 11709519851158935384U;
            aOrbiterE = RotL64((aOrbiterE * 7016689518570071587U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 15607438907832240304U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 9276575329661725624U) ^ aNonceWordA;
            aOrbiterG = RotL64((aOrbiterG * 8879744070762412745U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 6459435969129449226U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 6442382118416542275U;
            aOrbiterB = RotL64((aOrbiterB * 2921027306686588233U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 12117432107282150865U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 6831279293184793243U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2435360641135249073U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 9520022957804572889U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 8322178689474588679U) ^ aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1627707191467537115U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 4162401591586869316U) + aNonceWordH;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 8994015844714895961U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15421910378057951895U), 39U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 21U);
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterB, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aCross, 53U) + aOrbiterK) + RotL64(aOrbiterB, 13U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterK, 41U)) + aOrbiterE);
            aWandererF = aWandererF + (((RotL64(aPrevious, 6U) + RotL64(aOrbiterH, 29U)) + aOrbiterE) + aNonceWordJ);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterB, 35U)) + aOrbiterG) + aNonceWordG);
            aWandererD = aWandererD + ((((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 51U)) + aWandererUpdateSaltC[((aIndex + 12U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 22U)) + aOrbiterA) + aNonceWordN) + aWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 13U) + aOrbiterK) + RotL64(aOrbiterD, 51U)) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 54U));
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 2
        // ingress from: aWorkLaneA, aExpandLaneC, aOperationLaneC
        // ingress directions: aWorkLaneA forward forced, aExpandLaneC forward forced, aOperationLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aOperationLaneA
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 12308U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneC[((aIndex + 10647U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 11768U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 16323U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15208U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8513U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 10U) + RotL64(aIngress, 53U)) ^ (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 58U)) + 2672739400294801233U) + aNonceWordH;
            aOrbiterC = (aWandererD + RotL64(aScatter, 39U)) + 8475624545015101850U;
            aOrbiterI = ((aWandererB + RotL64(aCross, 29U)) + 1252755112289831257U) + aOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (((aWandererG + RotL64(aIngress, 51U)) + RotL64(aCarry, 43U)) + 7938039507649183387U) + aOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = (((aWandererA + RotL64(aCross, 11U)) + RotL64(aCarry, 57U)) + 8167413146948861022U) + aNonceWordO;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 21U)) + 17712313989694374353U) + aNonceWordE;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 5U)) + RotL64(aCarry, 13U)) + 7637042279892596975U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 15770412950033467341U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 3951812021898608685U) ^ aNonceWordL;
            aOrbiterI = RotL64((aOrbiterI * 6623127125223204737U), 57U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterD) + 8656983621098246507U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordD;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 17943342344730687317U;
            aOrbiterK = RotL64((aOrbiterK * 16495519451034883813U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 3087677463651608668U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 16493240011924342788U;
            aOrbiterA = RotL64((aOrbiterA * 16898479041530771871U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 7750923317452683057U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterE) ^ 2185924841611106546U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 708072658250726381U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 14676868738946722416U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 6849098251696302393U;
            aOrbiterD = RotL64((aOrbiterD * 2599806275837778069U), 13U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterI) + 17817755047153606419U) + aOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1]) + aNonceWordN;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 9900465270314068757U;
            aOrbiterE = RotL64((aOrbiterE * 9267925873983176685U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 11380000891112113701U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 15930503831156546113U;
            aOrbiterJ = RotL64((aOrbiterJ * 14450535035065393845U), 37U);
            //
            aIngress = RotL64(aOrbiterD, 29U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterC, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterC, 60U)) + aNonceWordC) + aWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 43U)) + aOrbiterE) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 43U) + aOrbiterA) + RotL64(aOrbiterK, 37U)) + aNonceWordB);
            aWandererB = aWandererB + (((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterK, 53U)) + aNonceWordA);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 51U) + aOrbiterK) + RotL64(aOrbiterE, 27U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 12U) + RotL64(aOrbiterE, 21U)) + aOrbiterC) + RotL64(aCarry, 11U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 11U)) + aOrbiterK) + aWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 4U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + RotL64(aWandererG, 47U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 19239U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((aIndex + 23419U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 20257U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18591U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 19965U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 22482U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 14U)) ^ (RotL64(aIngress, 27U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterH = (((aWandererD + RotL64(aCross, 27U)) + 17074147006464019918U) + aOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1]) + aNonceWordC;
            aOrbiterJ = ((((aWandererE + RotL64(aScatter, 13U)) + RotL64(aCarry, 5U)) + 10559516626129419928U) + aOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordH;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 21U)) + RotL64(aCarry, 53U)) + 13280363679503946221U;
            aOrbiterI = (((aWandererH + RotL64(aIngress, 51U)) + RotL64(aCarry, 27U)) + 17657115422132457413U) + aNonceWordG;
            aOrbiterE = ((aWandererK + RotL64(aCross, 60U)) + 13325837013304973008U) + aNonceWordK;
            aOrbiterG = (aWandererA + RotL64(aScatter, 39U)) + 3059707750486106037U;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 5U)) + 4529045702503050852U;
            //
            aOrbiterH = (((aOrbiterH + aOrbiterJ) + 10726578475550904292U) + aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1]) + aNonceWordP;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 14832537837996659885U;
            aOrbiterB = RotL64((aOrbiterB * 808060368961520519U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 220094417441809246U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 15343130035105342194U) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 7984652435043810845U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 16592263353426409884U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 15649290906447931918U) ^ aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8405875177836650731U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 11437410545843708269U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 5859769136073011444U;
            aOrbiterH = RotL64((aOrbiterH * 1065016088086441107U), 5U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterE) + 15188064100307340341U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordN;
            aOrbiterG = (((aOrbiterG ^ aOrbiterA) ^ 4367466521843260049U) ^ aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterG = RotL64((aOrbiterG * 15916715854192820923U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 8482617283860566845U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 2585745804937342972U;
            aOrbiterA = RotL64((aOrbiterA * 8267269625632139809U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 1687641344403425541U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 13667916445979421400U;
            aOrbiterE = RotL64((aOrbiterE * 8191322670355590027U), 37U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 29U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aCross, 10U) + aOrbiterB) + RotL64(aOrbiterA, 51U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterJ, 29U)) + aOrbiterH) + aWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 27U) + aOrbiterI) + RotL64(aOrbiterG, 23U));
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 53U) + RotL64(aOrbiterG, 57U)) + aOrbiterH) + aNonceWordO) + aWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 41U) + aOrbiterE) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterB, 6U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 13U)) + aOrbiterA) + RotL64(aCarry, 47U)) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererD, 30U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aFireLaneA
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aWorkLaneB, aExpandLaneC, aOperationLaneD
        // cross directions: aWorkLaneB backward forced, aExpandLaneC backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 30290U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneA[((aIndex + 31389U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 30200U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29244U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 26707U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 26246U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 44U) + RotL64(aPrevious, 13U)) ^ (RotL64(aCross, 57U) + RotL64(aIngress, 29U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterA = (aWandererB + RotL64(aCross, 53U)) + 10812151398716051703U;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 19U)) + 18202551453336003710U) + aOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = (((aWandererA + RotL64(aIngress, 13U)) + RotL64(aCarry, 5U)) + 9434410809101973752U) + aNonceWordD;
            aOrbiterG = ((((aWandererJ + RotL64(aPrevious, 29U)) + RotL64(aCarry, 39U)) + 12955829998028534045U) + aOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1]) + aNonceWordI;
            aOrbiterI = (aWandererG + RotL64(aIngress, 39U)) + 12271740641929640181U;
            aOrbiterC = (((aWandererI + RotL64(aCross, 5U)) + RotL64(aCarry, 53U)) + 14009351527014534752U) + aNonceWordL;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 46U)) + 4316296955679133450U) + aNonceWordO;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 16473324966997442872U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 15735123324965019802U;
            aOrbiterH = RotL64((aOrbiterH * 5624078184997601019U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 17656375090484080236U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 16066325053456055298U;
            aOrbiterC = RotL64((aOrbiterC * 17912970706985130327U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 12908968778503516903U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 12761433987676836197U;
            aOrbiterG = RotL64((aOrbiterG * 1023329467480907925U), 57U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterC) + 12737513138040664509U) + aOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1]) + aNonceWordN;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 14535795767570998392U;
            aOrbiterA = RotL64((aOrbiterA * 15560519667062222269U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 14370908061811284364U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 7001358781208669795U) ^ aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11641248025734015835U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 7298578161120090849U) + aOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 10498302152357484629U) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 13144110412179037175U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 11447343228638006767U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 18284143620422655675U;
            aOrbiterE = RotL64((aOrbiterE * 572862190073605651U), 43U);
            //
            aIngress = RotL64(aOrbiterA, 29U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 4U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + RotL64(aOrbiterH, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 46U) + aOrbiterG) + RotL64(aOrbiterF, 35U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 13U) + aOrbiterE) + RotL64(aOrbiterC, 27U)) + RotL64(aCarry, 3U)) + aNonceWordF);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 12U)) + aOrbiterC) + aNonceWordP);
            aWandererG = aWandererG + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 5U)) + aOrbiterI) + RotL64(aCarry, 37U)) + aWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterG, 47U)) + aOrbiterH);
            aWandererF = aWandererF + ((RotL64(aScatter, 29U) + aOrbiterC) + RotL64(aOrbiterG, 21U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterF, 41U)) + aWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + (RotL64(aWandererG, 58U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_Karate_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x96A0CFEAEFA00995ULL + 0x87009A8EAFA74446ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x932F7F2752DD44B1ULL + 0xD92AF94C195FB2C0ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xEF2176B8B7DF43DBULL + 0x9A6B154AC9E44F84ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xE5E1B3F16FD3D247ULL + 0xFC9B25FB4CB7D481ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x83308BE4DF98C0D1ULL + 0xDE37955E46C3F833ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xAEE783FE87C53FD1ULL + 0xCAD9B0BFC2283DFDULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x86153457E9115343ULL + 0xA05635965AAC2317ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x90A270D75744ABFDULL + 0x991E9F7FCE5BA1F0ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x8A3132C6E657B931ULL + 0xBD0828EE3240808EULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x85A35B7525F89539ULL + 0x8BB2537F4769BBE2ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x960DBE69106BF4BFULL + 0x9C03948E00AD6B41ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xD2C6514A8E343701ULL + 0xB0D8014DD363EC21ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x910E52527D53306DULL + 0x93385DE420D76625ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xBDF6956167F3FE1DULL + 0xA1CE048B97EDEE80ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xC6DE569E269A51C7ULL + 0xF7A96608FAB404A3ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xEF9D73B0DED877EFULL + 0xEA62233529A38F59ULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aOperationLaneB, aWorkLaneC, aWorkLaneD, aOperationLaneC, aExpandLaneA, aOperationLaneD, aFireLaneD, aExpandLaneB, aFireLaneA, aFireLaneB, aExpandLaneC, aFireLaneC, aOperationLaneA
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_a loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aOperationLaneB
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aOperationLaneB forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aOperationLaneC
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 538U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((aIndex + 8078U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 1831U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 2177U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 1790U)) & S_BLOCK1], 10U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 1814U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCarry, 23U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCross, 44U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 19U)) + 5160910997561396461U) + aNonceWordN;
            aOrbiterB = (aWandererD + RotL64(aScatter, 3U)) + 14920764751058512062U;
            aOrbiterH = ((((aWandererK + RotL64(aIngress, 35U)) + RotL64(aCarry, 5U)) + 6080952401749660022U) + aOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterI = ((aWandererA + RotL64(aCross, 60U)) + RotL64(aCarry, 21U)) + 17667234330526298627U;
            aOrbiterJ = (((aWandererF + RotL64(aPrevious, 41U)) + RotL64(aCarry, 35U)) + 760630072638686756U) + aNonceWordD;
            aOrbiterC = (((aWandererH + RotL64(aCross, 13U)) + 3504157162816997476U) + aOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1]) + aNonceWordC;
            aOrbiterK = (aWandererB + RotL64(aScatter, 29U)) + 9489022223422585882U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 1149898536879968964U) + aOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 10492284328940025310U;
            aOrbiterH = RotL64((aOrbiterH * 7893416766300156495U), 57U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterI) + 13213275606286399312U) + aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1]) + aNonceWordE;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 10557118912847180413U;
            aOrbiterJ = RotL64((aOrbiterJ * 10077877991284587845U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 15618980209023994776U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 5268600749854045564U;
            aOrbiterK = RotL64((aOrbiterK * 3849660559223919613U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 8011552687609649990U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 3148133096349525066U;
            aOrbiterG = RotL64((aOrbiterG * 5245156554959620007U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 12032847944237867285U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = (((aOrbiterI ^ aOrbiterB) ^ 14999005703490824673U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 6631584955208646049U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 5426735969392906710U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 3593177531650386729U;
            aOrbiterC = RotL64((aOrbiterC * 12997284886192717043U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 1701444719333347373U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 15928731228196894960U;
            aOrbiterB = RotL64((aOrbiterB * 1919318226904213433U), 3U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 11U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterK, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterH, 5U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 43U) + aOrbiterC) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 13U)) + aNonceWordH);
            aWandererB = aWandererB ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterI, 27U)) + aOrbiterC);
            aWandererK = aWandererK + (((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterB, 43U)) + aWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 37U)) + aOrbiterK);
            aWandererF = aWandererF + (((RotL64(aCross, 51U) + aOrbiterK) + RotL64(aOrbiterC, 12U)) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 28U) + aOrbiterH) + RotL64(aOrbiterJ, 51U)) + aNonceWordF) + aWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 10U));
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aOperationLaneD
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aOperationLaneD forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aFireLaneD
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 15851U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneC[((aIndex + 10726U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 9175U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15882U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15375U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 12346U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCarry, 53U)) ^ (RotL64(aPrevious, 20U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterD = ((aWandererJ + RotL64(aCross, 57U)) + RotL64(aCarry, 5U)) + 1393781663398437180U;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 5U)) + 17414594746688585273U;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 51U)) + 2823888497053071250U) + aNonceWordO;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 43U)) + 17032631958617884859U) + aOrbiterAssignSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aIngress, 36U)) + RotL64(aCarry, 23U)) + 15222697630461125019U;
            aOrbiterA = (((aWandererH + RotL64(aScatter, 13U)) + RotL64(aCarry, 47U)) + 15737414920751551780U) + aNonceWordL;
            aOrbiterB = ((aWandererK + RotL64(aCross, 21U)) + 1357196111055783001U) + aOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 5315122321649251691U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 7893744655508595974U;
            aOrbiterI = RotL64((aOrbiterI * 17863000246694319149U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 16721939414324611738U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 3444375866323610848U) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 10874157227815775661U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 1825716513674511632U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 15582066843912467318U;
            aOrbiterB = RotL64((aOrbiterB * 12765146555943757373U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 15673590949193923915U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 13887365046280406413U) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 3169061375011420121U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 12730414371734709356U) + aOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 4819112390640821927U;
            aOrbiterK = RotL64((aOrbiterK * 8782547948627685451U), 37U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterB) + 3089925954422937464U) + aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1]) + aNonceWordK;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 7180179304678622530U;
            aOrbiterE = RotL64((aOrbiterE * 16118051565147747413U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 17030269962085008657U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 6675917351883004046U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14134335325316949687U), 11U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterA, 12U);
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterK, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 27U)) + aOrbiterA) + RotL64(aCarry, 41U)) + aWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 27U) + aOrbiterI) + RotL64(aOrbiterA, 53U)) + aNonceWordI);
            aWandererF = aWandererF + ((RotL64(aCross, 11U) + aOrbiterJ) + RotL64(aOrbiterD, 21U));
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 50U) + RotL64(aOrbiterK, 13U)) + aOrbiterB) + aNonceWordB) + aWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterK, 35U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 41U)) + aOrbiterE);
            aWandererH = aWandererH + (((RotL64(aScatter, 21U) + RotL64(aOrbiterK, 60U)) + aOrbiterA) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + (RotL64(aWandererJ, 6U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 41U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aFireLaneA
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aFireLaneB
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 23524U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneD[((aIndex + 21037U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 19168U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22072U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20871U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 18901U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 20U)) ^ (RotL64(aCarry, 57U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterG = ((aWandererG + RotL64(aCross, 41U)) + 5510690816044082200U) + aOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aIngress, 5U)) + 15967820875033940530U;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 27U)) + RotL64(aCarry, 57U)) + 539348720848176221U;
            aOrbiterI = (aWandererF + RotL64(aScatter, 14U)) + 15779318183635560817U;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 35U)) + RotL64(aCarry, 37U)) + 14511058534424187469U;
            aOrbiterC = ((((aWandererH + RotL64(aScatter, 53U)) + RotL64(aCarry, 19U)) + 5811130556873428391U) + aOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordI;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 47U)) + 1085928476499444025U) + aNonceWordH;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 6973335316600768130U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 10747243745475009744U;
            aOrbiterF = RotL64((aOrbiterF * 17322489216048017061U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 1072260008981349754U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 2018772405352495753U) ^ aNonceWordL;
            aOrbiterI = RotL64((aOrbiterI * 10840562112080574241U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 1092091597048996547U) + aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 15103140149542167197U;
            aOrbiterG = RotL64((aOrbiterG * 621856991658027989U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 13194619321108681542U) + aNonceWordM;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 16749188603268621850U;
            aOrbiterA = RotL64((aOrbiterA * 9575408950550922039U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 7427959503086895166U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 9895804051379551393U;
            aOrbiterJ = RotL64((aOrbiterJ * 2701997336201570715U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 4526020800679774259U) + aOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 4484850928870048176U;
            aOrbiterC = RotL64((aOrbiterC * 17556987520625677313U), 41U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterG) + 1837404844299040155U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordE;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 15213208978489570694U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7062740584650274133U), 29U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 47U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + RotL64(aOrbiterA, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 60U) + aOrbiterG) + RotL64(aOrbiterD, 19U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 5U) + aOrbiterC) + RotL64(aOrbiterA, 26U)) + RotL64(aCarry, 47U)) + aWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterG, 5U)) + aOrbiterF) + aWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 51U) + aOrbiterF) + RotL64(aOrbiterI, 43U)) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 23U) + aOrbiterA) + RotL64(aOrbiterJ, 51U)) + aNonceWordP);
            aWandererF = aWandererF + (((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 37U)) + aOrbiterF) + aNonceWordG);
            aWandererE = aWandererE ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterC, 11U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererA, 10U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneC
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aOperationLaneA
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aOperationLaneA backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 31870U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 31057U)) & S_BLOCK1], 14U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 26639U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26449U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 32562U)) & S_BLOCK1], 6U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27556U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aPrevious, 37U)) + (RotL64(aCarry, 54U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterE = (((aWandererB + RotL64(aIngress, 35U)) + 8685374557928800912U) + aOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordA;
            aOrbiterF = (aWandererA + RotL64(aPrevious, 54U)) + 3482312691892161229U;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 47U)) + 6948130297389161165U) + aNonceWordH;
            aOrbiterG = ((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 57U)) + 5506385663788942690U;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 29U)) + RotL64(aCarry, 19U)) + 17859982009307397161U;
            aOrbiterJ = (((aWandererD + RotL64(aIngress, 41U)) + 9178488809207094043U) + aOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1]) + aNonceWordP;
            aOrbiterD = (((aWandererJ + RotL64(aScatter, 13U)) + RotL64(aCarry, 41U)) + 1835479501226057169U) + aNonceWordI;
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 5368101733632614939U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 9050459666576835422U) ^ aOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10351719549990259551U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 9042186993119635078U) + aNonceWordL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 17528342580198295025U;
            aOrbiterJ = RotL64((aOrbiterJ * 14316671546614386775U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 6495418332558436882U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 8834495762667327342U) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 10783141541937645995U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 4364314196965690905U) + aNonceWordN;
            aOrbiterA = (((aOrbiterA ^ aOrbiterD) ^ 6357485231062120459U) ^ aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 289429584586504995U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 3321488322626415347U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 10817330671781848737U;
            aOrbiterE = RotL64((aOrbiterE * 15875919466358823335U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 17974092279281611763U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 2871472057292789157U) ^ aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16104199340711015181U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 15187929795092006849U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 13482063681546475923U;
            aOrbiterF = RotL64((aOrbiterF * 14466266308157364963U), 57U);
            //
            aIngress = RotL64(aOrbiterD, 27U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterF, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterA, 37U)) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 60U) + aOrbiterJ) + RotL64(aOrbiterG, 27U)) + aNonceWordB);
            aWandererK = aWandererK + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 51U)) + aOrbiterE) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterE, 5U));
            aWandererB = aWandererB + (((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterD, 19U)) + aNonceWordM);
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 21U) + aOrbiterF) + RotL64(aOrbiterE, 44U)) + aNonceWordJ) + aWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterK, 11U)) + aOrbiterG) + aNonceWordK) + aWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + (RotL64(aWandererC, 34U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + RotL64(aWandererE, 27U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void TwistExpander_Karate_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x9E9671CB151D3CC3ULL + 0xE2CB29927C3E6D10ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xE67BE6CC1CA60B2BULL + 0xE88130D5011DAA92ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xE68980FC1E17A72BULL + 0xB4264C50B94CC6A8ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xEAB86FAF7C394C9BULL + 0x9022AE94A7FCB748ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xAEF75B22A87172B7ULL + 0xCA22218CBA6053A9ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xDF84A492BD309C3DULL + 0x98CFC4EDC676627EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xA91D139DD3BF900FULL + 0x90797DC7DC0384E8ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x98195C317359E587ULL + 0x8B9A5920A5588AD6ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xA5A79D94F34935BBULL + 0x8E7F1760C084DB44ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x813AA928DDA4BB0FULL + 0x991A8055D2DC1F53ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xC2DCB08E2DDEFE91ULL + 0xC48BCC6B5DF0B424ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x8C2916EDA1962219ULL + 0xDD9DE4D7EF774B53ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x8CB81F9666A7ADC1ULL + 0x84153AB52449BB72ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xF87A8CA4F200FDADULL + 0xCEC03B37A696F5C9ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xC43E7DB3F16752A9ULL + 0xD73702B8CDA05B4FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xA14EEB5F60EC88F7ULL + 0xCA1DB16BDAA0E15BULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneD, aExpandLaneC, aExpandLaneD, aFireLaneB, aOperationLaneA, aWorkLaneC, aFireLaneC, aOperationLaneB, aFireLaneA, aWorkLaneD, aOperationLaneC, aWorkLaneB, aWorkLaneA
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // kdf_b_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneD
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aFireLaneB
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aFireLaneB backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 1513U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneB[((aIndex + 7449U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 5913U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4296U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 2508U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 158U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCarry, 38U)) + (RotL64(aCross, 21U) ^ RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterB = ((aWandererA + RotL64(aCross, 19U)) + 2225397913940961213U) + aOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aPrevious, 26U)) + 8342544893601343643U;
            aOrbiterG = (aWandererE + RotL64(aIngress, 47U)) + 162922186381417187U;
            aOrbiterI = (((aWandererG + RotL64(aScatter, 23U)) + 11660218373710972210U) + aOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordA;
            aOrbiterC = (aWandererH + RotL64(aIngress, 13U)) + 14909034764605802354U;
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 5U)) + 16776955237009701511U) + aNonceWordL;
            aOrbiterE = (aWandererC + RotL64(aCross, 3U)) + 5834487809188925253U;
            aOrbiterF = (((aWandererJ + RotL64(aScatter, 29U)) + RotL64(aCarry, 3U)) + 1498492772767040320U) + aNonceWordM;
            aOrbiterA = ((aWandererI + RotL64(aCross, 38U)) + 4161765458781579617U) + aNonceWordF;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 53U)) + RotL64(aCarry, 43U)) + 10511923076962447765U;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 51U)) + RotL64(aCarry, 37U)) + 8575954471692620021U;
            //
            aOrbiterB = (((aOrbiterB + aOrbiterK) + 6536325446331340573U) + aOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1]) + aNonceWordB;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 1790628986900286346U;
            aOrbiterG = RotL64((aOrbiterG * 5262997114200816715U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 2623814807619278590U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 11676970995834706612U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10057461115132434901U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 13836786354224256591U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 6293096163612129260U;
            aOrbiterF = RotL64((aOrbiterF * 8977954126326217153U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 4271144764978661248U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 15938494256992560202U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10004841288382726739U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 11038155227307702976U) + aNonceWordK;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 12408749795071243930U;
            aOrbiterH = RotL64((aOrbiterH * 5527720475032868855U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 1673665849053496882U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 12866353361497103629U;
            aOrbiterD = RotL64((aOrbiterD * 6041125499398924871U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 10673935802381580966U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 8946776538955520352U;
            aOrbiterA = RotL64((aOrbiterA * 12293084177712710021U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 16294935203370452805U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 4697759331563852212U;
            aOrbiterC = RotL64((aOrbiterC * 14407806317275373043U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 17633118874112283386U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 89602424202721105U;
            aOrbiterB = RotL64((aOrbiterB * 1010654844008668685U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 4019154066191316616U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 15029609435149173243U;
            aOrbiterI = RotL64((aOrbiterI * 3522168783248806167U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 11765990698273078458U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 2225397913940961213U;
            aOrbiterJ = RotL64((aOrbiterJ * 8471538922288466221U), 29U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterH, 40U);
            aIngress = aIngress + (RotL64(aOrbiterC, 53U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 43U));
            aIngress = aIngress + RotL64(aOrbiterE, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aCross, 39U) + RotL64(aOrbiterJ, 35U)) + aOrbiterK);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 23U) + aOrbiterH) + RotL64(aOrbiterF, 47U)) + aNonceWordP);
            aWandererC = aWandererC + (((RotL64(aScatter, 48U) + aOrbiterD) + RotL64(aOrbiterK, 27U)) + aWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 43U)) + aOrbiterF);
            aWandererG = aWandererG + ((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 51U)) + aOrbiterI);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterD, 6U)) + aOrbiterE) + aNonceWordO);
            aWandererI = aWandererI + (((RotL64(aCross, 35U) + RotL64(aOrbiterC, 37U)) + aOrbiterH) + aNonceWordE);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterA, 39U)) + aOrbiterK);
            aWandererD = aWandererD + (((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 53U)) + aOrbiterD) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 46U) + aOrbiterJ) + RotL64(aOrbiterD, 60U)) + aWandererUpdateSaltE[((aIndex + 22U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 29U)) + aOrbiterB) + RotL64(aCarry, 13U)) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererC, 44U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 20U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 2
        // ingress from: aOperationLaneA, aExpandLaneC, aWorkLaneC
        // ingress directions: aOperationLaneA forward forced, aExpandLaneC forward forced, aWorkLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aFireLaneC
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aFireLaneC backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 10881U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((aIndex + 13930U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 9603U)) & S_BLOCK1], 24U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 12397U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8900U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 14662U)) & S_BLOCK1], 40U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 27U) ^ RotL64(aCross, 6U)) + (RotL64(aCarry, 41U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterB = ((aWandererB + RotL64(aIngress, 18U)) + 2177539223979303669U) + aNonceWordO;
            aOrbiterI = (aWandererE + RotL64(aPrevious, 5U)) + 3962004686551521471U;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 41U)) + 8457602312617147662U) + aOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aCross, 35U)) + RotL64(aCarry, 21U)) + 18011802451816510632U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 39U)) + RotL64(aCarry, 39U)) + 9046101759168876832U;
            aOrbiterA = ((aWandererA + RotL64(aIngress, 46U)) + 11135620637431969597U) + aNonceWordB;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 43U)) + 15913029940697999701U;
            aOrbiterD = ((aWandererI + RotL64(aCross, 51U)) + 16304193109948135982U) + aNonceWordA;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 27U)) + RotL64(aCarry, 53U)) + 13208892298820080981U;
            aOrbiterK = ((aWandererG + RotL64(aScatter, 13U)) + 4182377898949419225U) + aOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 53U)) + 13970137023071326151U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 8402396284835248583U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 8859190834060657829U) ^ aNonceWordN;
            aOrbiterE = RotL64((aOrbiterE * 13552418608113716117U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 9760005337757990392U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 14108277760135744897U;
            aOrbiterC = RotL64((aOrbiterC * 4474681104256093885U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 12226316121949012350U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 3456392186754113960U) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 8704729827929941215U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 5004087958637038973U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 7176881295123125567U) ^ aOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15272157962928021009U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 10889800478505074438U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 13728832441482547824U;
            aOrbiterA = RotL64((aOrbiterA * 17588477761978646139U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 17345665880706866772U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 301139993853297566U;
            aOrbiterF = RotL64((aOrbiterF * 5812445396758354505U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 2061389844760610160U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 13631862266139238355U;
            aOrbiterI = RotL64((aOrbiterI * 143613352104722701U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 10767186080827509622U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 4893486019456886013U;
            aOrbiterH = RotL64((aOrbiterH * 5194746459545610901U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 11264795916303477037U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 16013652139405432608U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14924257021089920495U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 5209743554932653849U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 13160179712987277456U;
            aOrbiterK = RotL64((aOrbiterK * 5003755912040281427U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 12440615920191945386U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 2177539223979303669U;
            aOrbiterJ = RotL64((aOrbiterJ * 3565122523239344029U), 21U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 5U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 39U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 34U));
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterB, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 35U)) + aOrbiterE) + RotL64(aCarry, 41U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 58U) + RotL64(aOrbiterG, 10U)) + aOrbiterK);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterG, 23U)) + aWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 41U)) + aOrbiterG) + aNonceWordG) + aWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterD, 29U)) + aOrbiterG);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 26U) + aOrbiterB) + RotL64(aOrbiterD, 39U));
            aWandererE = aWandererE + ((RotL64(aScatter, 35U) + RotL64(aOrbiterJ, 5U)) + aOrbiterF);
            aWandererG = aWandererG ^ ((RotL64(aCross, 3U) + aOrbiterE) + RotL64(aOrbiterI, 21U));
            aWandererC = aWandererC + (((RotL64(aScatter, 37U) + aOrbiterJ) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 39U) + aOrbiterA) + RotL64(aOrbiterJ, 57U)) + aNonceWordP);
            aWandererD = aWandererD + ((RotL64(aPrevious, 5U) + aOrbiterH) + RotL64(aOrbiterF, 50U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 14U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 10U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 3
        // ingress from: aOperationLaneB, aExpandLaneD, aFireLaneA
        // ingress directions: aOperationLaneB forward forced, aExpandLaneD forward forced, aFireLaneA forward/backward random
        // cross from: aOperationLaneA, aExpandLaneB, aWorkLaneD
        // cross directions: aOperationLaneA backward forced, aExpandLaneB backward forced, aWorkLaneD backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 19691U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneD[((aIndex + 18527U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 23143U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23108U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 16879U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 22590U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCarry, 51U)) + (RotL64(aCross, 10U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 14U)) + RotL64(aCarry, 47U)) + 17454559218352016650U;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 23U)) + 8005709669325164803U;
            aOrbiterI = ((aWandererG + RotL64(aCross, 39U)) + 13393741948412816357U) + aNonceWordK;
            aOrbiterA = (aWandererI + RotL64(aIngress, 3U)) + 3665865624348875553U;
            aOrbiterD = (((aWandererF + RotL64(aPrevious, 41U)) + RotL64(aCarry, 19U)) + 8334142570031883436U) + aOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aCross, 21U)) + RotL64(aCarry, 27U)) + 17226066128706139657U;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 11U)) + 3319093033121522613U) + aNonceWordA;
            aOrbiterB = (((aWandererH + RotL64(aIngress, 28U)) + 6657535603401588798U) + aOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1]) + aNonceWordH;
            aOrbiterF = (aWandererK + RotL64(aPrevious, 35U)) + 5469746182326331147U;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 53U)) + 17846791786050221418U) + aNonceWordF;
            aOrbiterC = (aWandererA + RotL64(aIngress, 5U)) + 15939541003714896288U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 12076763190461077406U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 3594038213596405284U;
            aOrbiterI = RotL64((aOrbiterI * 10244002692575821495U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 8301291631324464622U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 8460406137668390582U) ^ aOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9117147929757711595U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 7612394867020871200U) + aNonceWordO;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 8525076134853103975U;
            aOrbiterB = RotL64((aOrbiterB * 5790440201072204659U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 11929899088215090379U) + aNonceWordL;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 7119509166360685726U;
            aOrbiterH = RotL64((aOrbiterH * 1662341427992528823U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 5081078459225240607U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 17149991983909906705U;
            aOrbiterE = RotL64((aOrbiterE * 950223374568067343U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 8817303295675241994U) + aOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 7962039282652745113U;
            aOrbiterF = RotL64((aOrbiterF * 12773588587795522121U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 13596273086338032370U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 8186297702278180956U;
            aOrbiterA = RotL64((aOrbiterA * 6226504769888753861U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 1696277861691580263U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 17360461831507082959U;
            aOrbiterK = RotL64((aOrbiterK * 1651378456022210983U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 1384868996572650981U) + aNonceWordP;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 2039624849777183290U) ^ aNonceWordD;
            aOrbiterC = RotL64((aOrbiterC * 13148024378138271937U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 14530407348595669913U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 18023931565754525034U;
            aOrbiterJ = RotL64((aOrbiterJ * 18025122652259338105U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 11245556671533878373U) + aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 17454559218352016650U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15665798947106818229U), 37U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterF, 43U);
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterA, 41U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 39U));
            aIngress = aIngress + RotL64(aOrbiterD, 20U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 37U) + aOrbiterI) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 21U) + aOrbiterE) + RotL64(aOrbiterJ, 27U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 58U) + RotL64(aOrbiterD, 20U)) + aOrbiterE) + aWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterA, 41U)) + aOrbiterC) + aNonceWordC);
            aWandererK = aWandererK + (((RotL64(aScatter, 43U) + RotL64(aOrbiterB, 23U)) + aOrbiterF) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 29U)) + aOrbiterD);
            aWandererA = aWandererA + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterA, 51U)) + aOrbiterB) + aNonceWordJ);
            aWandererF = aWandererF ^ ((((RotL64(aCross, 10U) + aOrbiterE) + RotL64(aOrbiterG, 58U)) + aNonceWordB) + aWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 37U)) + aOrbiterH);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterE, 43U));
            aWandererI = aWandererI + ((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 39U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 60U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 46U));
            aCarry = aCarry + RotL64(aWandererD, 43U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 4
        // ingress from: aOperationLaneC, aOperationLaneA, aWorkLaneB
        // ingress directions: aOperationLaneC forward forced, aOperationLaneA forward forced, aWorkLaneB forward/backward random
        // cross from: aOperationLaneB, aExpandLaneC, aWorkLaneA
        // cross directions: aOperationLaneB backward forced, aExpandLaneC backward forced, aWorkLaneA backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 27947U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((aIndex + 32277U)) & S_BLOCK1], 24U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 30165U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29696U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 27123U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26488U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 40U) + RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterK = ((aWandererK + RotL64(aCross, 21U)) + 6024062041314952357U) + aOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = (aWandererD + RotL64(aIngress, 37U)) + 18340757093658015585U;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 3U)) + 11911120493880346751U) + aNonceWordE;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 52U)) + 17428074353884654439U) + aNonceWordM;
            aOrbiterJ = (aWandererI + RotL64(aCross, 57U)) + 12790849760814795936U;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 47U)) + RotL64(aCarry, 47U)) + 12633397052172117800U;
            aOrbiterF = (((aWandererF + RotL64(aIngress, 11U)) + RotL64(aCarry, 37U)) + 11946150433665237945U) + aOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aScatter, 29U)) + 16842157900909419285U;
            aOrbiterG = ((aWandererB + RotL64(aIngress, 19U)) + 14186235783224155962U) + aNonceWordJ;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 13U)) + 13284904542579767591U;
            aOrbiterI = ((aWandererE + RotL64(aCross, 42U)) + RotL64(aCarry, 11U)) + 11609181965078844357U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 9628562297095374984U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 7850281529011259759U;
            aOrbiterA = RotL64((aOrbiterA * 17611485102925470357U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 257458718073794527U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 10693404545773519306U;
            aOrbiterH = RotL64((aOrbiterH * 14821443722828498323U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 3430519236533871460U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 6183054506953198055U) ^ aNonceWordF;
            aOrbiterF = RotL64((aOrbiterF * 6121082743789970911U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 2905610989884221654U) + aNonceWordK;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 4472163910775333862U;
            aOrbiterC = RotL64((aOrbiterC * 7770678426310856745U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 16870142883133769663U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 1403692060594816451U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9740854430251597879U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 16904169913507057108U) + aNonceWordI;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 4773518591580333357U;
            aOrbiterB = RotL64((aOrbiterB * 5306070307776061267U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 6528141733853494275U) + aOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = (((aOrbiterI ^ aOrbiterF) ^ 11254806909313951442U) ^ aOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterI = RotL64((aOrbiterI * 6316669786405548827U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 6857506858448143407U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 2855763534355983644U;
            aOrbiterJ = RotL64((aOrbiterJ * 16881334940165182415U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 12328391751024624740U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 16475072086109949522U;
            aOrbiterD = RotL64((aOrbiterD * 15218626930666825883U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 15505670341076785424U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 6972128419331939330U;
            aOrbiterG = RotL64((aOrbiterG * 12206069109180246067U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 7151546362283646210U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 6024062041314952357U;
            aOrbiterK = RotL64((aOrbiterK * 10243806128059850493U), 23U);
            //
            aIngress = RotL64(aOrbiterH, 47U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + (RotL64(aOrbiterD, 52U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aCross, 5U) + RotL64(aOrbiterC, 21U)) + aOrbiterE) + RotL64(aCarry, 13U)) + aWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 18U) + aOrbiterH) + RotL64(aOrbiterE, 41U));
            aWandererG = aWandererG + ((RotL64(aIngress, 23U) + aOrbiterF) + RotL64(aOrbiterH, 13U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 58U)) + aOrbiterA);
            aWandererB = aWandererB + (((RotL64(aIngress, 13U) + aOrbiterB) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterK, 5U)) + aOrbiterJ);
            aWandererH = aWandererH + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterF, 53U)) + aOrbiterA) + aNonceWordA);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 26U) + aOrbiterB) + RotL64(aOrbiterG, 37U)) + aNonceWordG);
            aWandererI = aWandererI + ((RotL64(aIngress, 21U) + aOrbiterC) + RotL64(aOrbiterI, 11U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterG, 44U)) + aOrbiterI);
            aWandererE = aWandererE + ((((RotL64(aCross, 43U) + aOrbiterE) + RotL64(aOrbiterJ, 47U)) + aNonceWordD) + aWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 18U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 60U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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

void TwistExpander_Karate_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xA3ABB8B58DD29A49ULL + 0xB1937B4B506EDEB5ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xCB262ED678A210F1ULL + 0xE76119C267238D87ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xBC9237983B0DEDEDULL + 0xC9AEF0CCF103A32FULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x8732A272E4976D61ULL + 0xD093CA76E59A758AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xB95FCFB05D2FE5D1ULL + 0xE7AD815BD24DE926ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x98FF5E6BE907DB0DULL + 0x8A84E1C4181A1C84ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x8B2C854461DBB1B1ULL + 0x9C6FFA1A899ED90CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xE50DE590ED5A28E7ULL + 0xA8A04B84E6345556ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xEE5CAF33CF39B93FULL + 0xFC43554697F805AFULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x8CA8380CE31A2C05ULL + 0x99DDBAA9B1EDC9A1ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xF55A4FBEB7D64E5FULL + 0x87131DA33B51EA87ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x97BD8CF74BE1EA81ULL + 0xED89CC2DBFA947E1ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xC752CF9ABFD0A7EBULL + 0xF6946C56369F224BULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xC3A58A7DA8552197ULL + 0x85B79DB61AE733C5ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xD534A55DD45DCC87ULL + 0x9A9BB4635AFD1E69ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x9C598CC5D942F3BDULL + 0xB7FC9742A912035FULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aWorkLaneC, aOperationLaneC, aOperationLaneD, aFireLaneB, aExpandLaneA, aFireLaneD, aWorkLaneB, aExpandLaneB, aWorkLaneD, aFireLaneA, aExpandLaneC, aWorkLaneA, aFireLaneC
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aWorkLaneC
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aWorkLaneC forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aFireLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 5661U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((aIndex + 4727U)) & S_BLOCK1], 46U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 4000U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1586U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 2134U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 2726U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 38U) + RotL64(aPrevious, 11U)) ^ (RotL64(aCarry, 23U) ^ RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 52U)) + 9133751643283278896U) + aNonceWordB;
            aOrbiterD = ((aWandererE + RotL64(aCross, 19U)) + RotL64(aCarry, 41U)) + 8971581804375380408U;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 43U)) + RotL64(aCarry, 11U)) + 12559650383714566592U;
            aOrbiterE = ((((aWandererK + RotL64(aIngress, 57U)) + RotL64(aCarry, 3U)) + 15753206088872859163U) + aOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1]) + aNonceWordP;
            aOrbiterG = (aWandererG + RotL64(aPrevious, 47U)) + 7640756270450762350U;
            aOrbiterH = (((aWandererF + RotL64(aIngress, 29U)) + 7340073357551376125U) + aOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordD;
            aOrbiterC = (aWandererB + RotL64(aCross, 34U)) + 5270256573644196046U;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 39U)) + 3567367996479995928U) + aNonceWordN;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 5U)) + 11939634537492733738U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 7051817732424527120U) + aNonceWordI;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 1730487669951837941U;
            aOrbiterJ = RotL64((aOrbiterJ * 15191634337956285841U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 18009252467909454817U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 2361024272031696442U;
            aOrbiterD = RotL64((aOrbiterD * 15215151562500226027U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 15902755877642960397U) + aNonceWordC;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 12243517544704116184U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2576071074148141447U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 16846181962302186187U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 636121425116506681U;
            aOrbiterH = RotL64((aOrbiterH * 17075030673338779993U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 6887385655828217318U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 3705834550934775862U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11275428284929594435U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 11165142437077969438U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 6426659930331618269U;
            aOrbiterE = RotL64((aOrbiterE * 17170640810530893705U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 12629082390899315789U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 4277510580069574724U;
            aOrbiterK = RotL64((aOrbiterK * 9829125163412708305U), 29U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterH) + 13814834144170469978U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordM;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 3698381854100295826U;
            aOrbiterG = RotL64((aOrbiterG * 5126359230872258015U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 11623170635983579937U) + aNonceWordG;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 7247413650388803796U;
            aOrbiterB = RotL64((aOrbiterB * 3403219499465560059U), 53U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterH, 50U);
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterC, 12U)) + aNonceWordO) + aWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 6U) + aOrbiterE) + RotL64(aOrbiterJ, 23U)) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 29U) + aOrbiterJ) + RotL64(aOrbiterC, 41U));
            aWandererD = aWandererD + (((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 57U)) + aOrbiterG) + aNonceWordJ);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 11U) + aOrbiterG) + RotL64(aOrbiterI, 29U)) + aNonceWordA);
            aWandererB = aWandererB + (((RotL64(aCross, 51U) + RotL64(aOrbiterK, 5U)) + aOrbiterE) + aWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 53U)) + aOrbiterE);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 36U) + RotL64(aOrbiterH, 19U)) + aOrbiterC) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 21U) + aOrbiterE) + RotL64(aOrbiterB, 34U)) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererA, 14U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 2
        // ingress from: aExpandLaneA, aOperationLaneC, aFireLaneD
        // ingress directions: aExpandLaneA forward forced, aOperationLaneC forward forced, aFireLaneD forward/backward random
        // cross from: aOperationLaneA, aOperationLaneD, aWorkLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneD backward forced, aWorkLaneB backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 11866U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((aIndex + 8658U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 15323U)) & S_BLOCK1], 22U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 11217U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 8614U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 9249U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aPrevious, 39U)) ^ (RotL64(aCarry, 5U) + RotL64(aIngress, 54U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterF = (((aWandererH + RotL64(aCross, 39U)) + RotL64(aCarry, 19U)) + 12849591986267890852U) + aNonceWordB;
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 27U)) + RotL64(aCarry, 5U)) + 8232614804696815750U;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 57U)) + 12141567259210877281U) + aNonceWordI;
            aOrbiterI = (aWandererI + RotL64(aScatter, 43U)) + 2928641981037885644U;
            aOrbiterE = ((aWandererB + RotL64(aCross, 22U)) + 980733350554783938U) + aOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = (aWandererG + RotL64(aIngress, 13U)) + 2683985177993350746U;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 35U)) + 14532148403815527355U) + aOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (((aWandererK + RotL64(aPrevious, 5U)) + RotL64(aCarry, 47U)) + 7736296629433884203U) + aNonceWordG;
            aOrbiterD = (aWandererA + RotL64(aScatter, 18U)) + 10428437770166310549U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 18327174144859461029U) + aOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 6810436935194432002U) ^ aNonceWordN;
            aOrbiterA = RotL64((aOrbiterA * 2715987179577753597U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 12606153309690753435U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 17123256945895150555U;
            aOrbiterE = RotL64((aOrbiterE * 13469111258504672565U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 9057777759026189541U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 16478485918911194442U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11054247078884894131U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 18064460487552100483U) + aOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 11477276762421684083U;
            aOrbiterB = RotL64((aOrbiterB * 3886501230380184395U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 18318375441973295081U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 13849305985380030986U;
            aOrbiterJ = RotL64((aOrbiterJ * 12962140243967824959U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 10240409420338313641U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 18360586077779529086U;
            aOrbiterH = RotL64((aOrbiterH * 18196875422391501927U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 16801797158622424257U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 4950305991208513887U) ^ aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4437082499761416951U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 15790878572843321918U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 9808781805065559728U;
            aOrbiterD = RotL64((aOrbiterD * 9394280083159162953U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 11974996650410830731U) + aNonceWordC;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 4955004489435232515U;
            aOrbiterK = RotL64((aOrbiterK * 13301966529515483085U), 21U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterD, 24U);
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 4U) + aOrbiterI) + RotL64(aOrbiterF, 29U)) + aNonceWordD);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterB, 22U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterJ, 11U)) + aOrbiterI) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ ((((RotL64(aCross, 39U) + aOrbiterK) + RotL64(aOrbiterH, 43U)) + aNonceWordK) + aWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 56U) + aOrbiterH) + RotL64(aOrbiterA, 53U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 29U) + aOrbiterE) + RotL64(aOrbiterA, 39U));
            aWandererG = aWandererG + ((((RotL64(aCross, 19U) + aOrbiterI) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 5U)) + aNonceWordP);
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 60U)) + aOrbiterH) + aNonceWordM) + aWandererUpdateSaltF[((aIndex + 26U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 3U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 10U));
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 3
        // ingress from: aExpandLaneB, aOperationLaneD, aWorkLaneD
        // ingress directions: aExpandLaneB forward forced, aOperationLaneD forward forced, aWorkLaneD forward/backward random
        // cross from: aExpandLaneA, aOperationLaneB, aFireLaneA
        // cross directions: aExpandLaneA backward forced, aOperationLaneB backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 19445U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneD[((aIndex + 23815U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 17964U)) & S_BLOCK1], 40U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 16752U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 23174U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 21593U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aPrevious, 54U)) ^ (RotL64(aIngress, 41U) + RotL64(aCross, 29U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 5U)) + RotL64(aCarry, 11U)) + 3236820517816085022U;
            aOrbiterE = ((aWandererA + RotL64(aCross, 47U)) + 741288875914097926U) + aNonceWordA;
            aOrbiterI = (aWandererI + RotL64(aPrevious, 43U)) + 8417246926007729580U;
            aOrbiterC = (aWandererD + RotL64(aScatter, 60U)) + 9715717805774537170U;
            aOrbiterF = (aWandererF + RotL64(aIngress, 51U)) + 14360243844821619482U;
            aOrbiterG = (((aWandererE + RotL64(aCross, 27U)) + 10760908100206775334U) + aOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1]) + aNonceWordO;
            aOrbiterA = (((aWandererH + RotL64(aPrevious, 11U)) + RotL64(aCarry, 53U)) + 3434641779946167811U) + aOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aScatter, 36U)) + 7885568822756234567U;
            aOrbiterD = ((aWandererC + RotL64(aCross, 23U)) + RotL64(aCarry, 41U)) + 3041563437672051294U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 15761355327564963516U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 1158633562785937421U;
            aOrbiterI = RotL64((aOrbiterI * 15511324886867188235U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 9338581575871970653U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 9172038894262857354U;
            aOrbiterF = RotL64((aOrbiterF * 3110871165285625807U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 14653924713599790081U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 3854497592598563309U;
            aOrbiterA = RotL64((aOrbiterA * 11737111068815795303U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 16286980180327600557U) + aNonceWordI;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 5092583772591249756U) ^ aNonceWordN;
            aOrbiterE = RotL64((aOrbiterE * 13955105624639442903U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 4288397994175567333U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 15584236478994873104U) ^ aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1860480595862755379U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 5557463939827483792U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 2659814275753280856U;
            aOrbiterD = RotL64((aOrbiterD * 17702430405693184643U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 6941807963525063449U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 2040598555191211307U) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 14750544987531722765U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 347572666231116258U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 779304821185302523U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14180254150318109855U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 10632524582873079742U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 9761308771280517212U;
            aOrbiterG = RotL64((aOrbiterG * 13926235411726048921U), 51U);
            //
            aIngress = RotL64(aOrbiterC, 53U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 14U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + RotL64(aOrbiterD, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterE, 37U)) + aOrbiterG);
            aWandererH = aWandererH + ((RotL64(aIngress, 11U) + aOrbiterB) + RotL64(aOrbiterA, 4U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterF, 41U)) + aNonceWordH);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 6U) + RotL64(aOrbiterI, 27U)) + aOrbiterG) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 53U) + aOrbiterD) + RotL64(aOrbiterC, 19U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterJ, 23U)) + aNonceWordG) + aWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 56U)) + aOrbiterA) + aNonceWordM);
            aWandererE = aWandererE + (((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterJ, 51U)) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 30U) + RotL64(aOrbiterE, 13U)) + aOrbiterC) + aWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (RotL64(aWandererE, 30U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + RotL64(aWandererI, 35U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aWorkLaneA
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aWorkLaneA forward/backward random
        // cross from: aExpandLaneB, aOperationLaneC, aFireLaneC
        // cross directions: aExpandLaneB backward forced, aOperationLaneC backward forced, aFireLaneC backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 31453U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 31217U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25075U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25201U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 27410U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 26693U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 43U) ^ RotL64(aIngress, 57U)) + (RotL64(aPrevious, 5U) + RotL64(aCarry, 30U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterB = (((aWandererE + RotL64(aIngress, 43U)) + RotL64(aCarry, 5U)) + 5568146815535263910U) + aOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = (((aWandererH + RotL64(aScatter, 38U)) + RotL64(aCarry, 51U)) + 7736084960873834666U) + aNonceWordJ;
            aOrbiterI = (aWandererJ + RotL64(aCross, 27U)) + 1336413621817562093U;
            aOrbiterD = (aWandererF + RotL64(aPrevious, 51U)) + 5218462026934984692U;
            aOrbiterE = (aWandererK + RotL64(aCross, 11U)) + 7048890985969555935U;
            aOrbiterA = (aWandererA + RotL64(aIngress, 5U)) + 13415955213864702118U;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 34U)) + 5657023257021528548U) + aOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = (((aWandererC + RotL64(aPrevious, 23U)) + RotL64(aCarry, 41U)) + 14338310943137497116U) + aNonceWordA;
            aOrbiterG = (aWandererB + RotL64(aScatter, 19U)) + 12305161641833950473U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 14514226578370459131U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 12692904083266024340U;
            aOrbiterI = RotL64((aOrbiterI * 14800805065279908839U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 11012959130001327964U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 7106471380403489078U;
            aOrbiterE = RotL64((aOrbiterE * 515626559384817223U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 3718101961355280891U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 13364192077222322664U;
            aOrbiterC = RotL64((aOrbiterC * 1411328915372590283U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 6720867800318913440U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 14497243926965866546U) ^ aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13595058589060114653U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 5789056168233262435U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 14438482587495779937U;
            aOrbiterK = RotL64((aOrbiterK * 10593535547917767263U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 313917798940179945U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 15241845511889502917U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16483477103771326107U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 3591957424821693032U) + aNonceWordE;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 1559050939014453558U;
            aOrbiterG = RotL64((aOrbiterG * 17933346117866604725U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 15340590914441451383U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 5538037287390050110U) ^ aOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4082576643144951473U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 4151270491894969214U) + aNonceWordI;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 263593701314144898U) ^ aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10372046955804512457U), 39U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 37U);
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + (RotL64(aOrbiterA, 10U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 39U) + RotL64(aOrbiterJ, 19U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 29U) + aOrbiterD) + RotL64(aOrbiterI, 23U)) + aNonceWordN);
            aWandererC = aWandererC + (((RotL64(aIngress, 53U) + aOrbiterC) + RotL64(aOrbiterK, 5U)) + RotL64(aCarry, 23U));
            aWandererF = aWandererF ^ ((((RotL64(aCross, 20U) + RotL64(aOrbiterG, 60U)) + aOrbiterA) + aNonceWordF) + aWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterI, 29U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterK, 47U)) + aNonceWordC);
            aWandererH = aWandererH + (((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 41U)) + aOrbiterD) + RotL64(aCarry, 13U));
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterC, 36U)) + aNonceWordG) + aWandererUpdateSaltE[((aIndex + 26U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 60U) + RotL64(aOrbiterG, 13U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 60U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + RotL64(aWandererI, 19U);
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

void TwistExpander_Karate_Arx::KDF_B_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x9D759F5C73800263ULL + 0xCDA4A7F342BA3F8FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xC91ECCF814FEA0ABULL + 0x876C6A3C7724C043ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xF82AC1736B5F5849ULL + 0x887E0266B9EC6513ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x898233598B5160C1ULL + 0x80E4F7F4B01B2C01ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xCEB2DA647CF691ABULL + 0x881E7E289E8F411EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xD95CC4781467672BULL + 0xC8C59B56ADA9B4B4ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x9C4CAA6690FAACD1ULL + 0xDD2FA6BD29D64BCCULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x84556BB61E81BC77ULL + 0x90447CE01C59E6FCULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x9A4F9BF6C5082F45ULL + 0xE67A3B9025CDA3C7ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xC07C78F5F7384889ULL + 0xD8DD1A657D58F464ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xA768D31E342D9BA5ULL + 0xCB7F291BCCBB8E58ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xDE6892F85324E80FULL + 0xCC81B86CDADF1B05ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xFE10F2DF0AC43697ULL + 0xE0AE778318B59D39ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x822EA17A482D123BULL + 0xDF5C2F43B5E7157EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xCC89524E0881D08DULL + 0x87ED671803B1F1D9ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xFE161F2DE297E2FFULL + 0xE25CF5BB4BF40809ULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aOperationLaneD, aWorkLaneC, aWorkLaneD, aFireLaneA, aExpandLaneA, aOperationLaneB, aOperationLaneA, aExpandLaneB, aFireLaneC, aOperationLaneC, aExpandLaneC, aFireLaneD, aFireLaneB
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_d loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aOperationLaneD
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aOperationLaneD forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aFireLaneA
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 2916U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 492U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 1385U)) & S_BLOCK1], 30U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 3848U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 2906U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 1835U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aPrevious, 53U)) + (RotL64(aCarry, 21U) ^ RotL64(aIngress, 38U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterA = ((aWandererK + RotL64(aCross, 3U)) + RotL64(aCarry, 53U)) + 15726877954695761686U;
            aOrbiterI = ((((aWandererC + RotL64(aIngress, 58U)) + RotL64(aCarry, 41U)) + 14187652171881943587U) + aOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1]) + aNonceWordL;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 41U)) + RotL64(aCarry, 19U)) + 8420423151313882782U;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 35U)) + 14942322692433259283U) + aNonceWordH;
            aOrbiterE = (aWandererE + RotL64(aCross, 51U)) + 7272331475919796255U;
            aOrbiterK = (aWandererH + RotL64(aScatter, 29U)) + 154504365041805840U;
            aOrbiterH = (((aWandererA + RotL64(aPrevious, 13U)) + 17475491222554948786U) + aOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1]) + aNonceWordF;
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 5759181483165339605U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 5993060214499322845U;
            aOrbiterD = RotL64((aOrbiterD * 10799489831896153301U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 10901786237875941844U) + aNonceWordA;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 17135786595614068473U) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 15923538730142047043U), 43U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterK) + 5208202073886811165U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordM;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 6821452921018900631U;
            aOrbiterH = RotL64((aOrbiterH * 13119330055184115669U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 13348064837402206969U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 8967943922403445136U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 300168481725373093U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 8130283784171430891U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 6351113882502502876U;
            aOrbiterK = RotL64((aOrbiterK * 15960622823993072903U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 6894708729226455769U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 12065058511247133944U;
            aOrbiterA = RotL64((aOrbiterA * 5432601727436935831U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 17138279326229372741U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterH) ^ 12987698199066890628U) ^ aOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterI = RotL64((aOrbiterI * 12665716655177320977U), 19U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 11U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 28U));
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 43U) + aOrbiterE) + RotL64(aOrbiterF, 35U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterD, 57U)) + aOrbiterI) + RotL64(aCarry, 27U)) + aNonceWordO);
            aWandererA = aWandererA ^ (((RotL64(aCross, 51U) + aOrbiterI) + RotL64(aOrbiterH, 13U)) + aNonceWordC);
            aWandererF = aWandererF + (((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterA, 21U)) + aWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterK, 43U)) + aOrbiterA) + aNonceWordK);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 58U) + RotL64(aOrbiterI, 6U)) + aOrbiterK) + RotL64(aCarry, 57U)) + aWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterE, 51U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 18U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aOperationLaneB
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aOperationLaneB forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aOperationLaneA
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 13921U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneC[((aIndex + 12918U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 9317U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14543U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 10041U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 11077U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aPrevious, 23U)) + (RotL64(aCarry, 11U) ^ RotL64(aIngress, 36U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterB = ((aWandererD + RotL64(aScatter, 47U)) + RotL64(aCarry, 29U)) + 16200278595895089008U;
            aOrbiterK = ((aWandererB + RotL64(aCross, 11U)) + 1029614154810465897U) + aOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aIngress, 27U)) + RotL64(aCarry, 5U)) + 7129562468705441295U;
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 37U)) + 14388903902433951274U) + aOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aIngress, 21U)) + 1013568949315967455U) + aNonceWordO;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 58U)) + RotL64(aCarry, 57U)) + 3128823373497815651U;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 5U)) + 14525694606889470589U) + aNonceWordK;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 14443983602196782887U) + aNonceWordE;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 12244220415328641190U;
            aOrbiterH = RotL64((aOrbiterH * 15052949098014803181U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 10477159225338766614U) + aOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 2842870123078131566U;
            aOrbiterD = RotL64((aOrbiterD * 11522265477555954071U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 8621138818955849917U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 5038396344400303181U;
            aOrbiterK = RotL64((aOrbiterK * 14636756322207385447U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 2768613802894372496U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 2027754864051410015U) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 2461322540050569287U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 2848088309172056399U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 15017458513904884651U) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 9926904679902843055U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 9079797279596336139U) + aOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 15424866642305110811U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12912331089970158845U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 13751764050290602740U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 7694557131324740282U;
            aOrbiterE = RotL64((aOrbiterE * 14980807690491467023U), 29U);
            //
            aIngress = RotL64(aOrbiterB, 11U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 53U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 60U));
            aIngress = aIngress + RotL64(aOrbiterF, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 41U) + aOrbiterK) + RotL64(aOrbiterB, 51U)) + aWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 21U) + aOrbiterB) + RotL64(aOrbiterF, 30U));
            aWandererB = aWandererB + (((RotL64(aIngress, 13U) + aOrbiterB) + RotL64(aOrbiterC, 43U)) + aWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 21U)) + aOrbiterB);
            aWandererA = aWandererA + (((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterK, 13U)) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterF, 5U)) + aNonceWordB);
            aWandererI = aWandererI + ((((RotL64(aCross, 28U) + RotL64(aOrbiterD, 57U)) + aOrbiterF) + RotL64(aCarry, 41U)) + aNonceWordC);
            //
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + RotL64(aWandererE, 18U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aFireLaneC
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aOperationLaneC
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 21692U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneD[((aIndex + 18320U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 21793U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20675U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16847U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 17667U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 29U) ^ RotL64(aPrevious, 60U)) + (RotL64(aIngress, 13U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterD = ((((aWandererD + RotL64(aCross, 41U)) + RotL64(aCarry, 39U)) + 17225673071833726819U) + aOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 21U)) + RotL64(aCarry, 57U)) + 10301458382103627331U;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 29U)) + 3960233050857362414U;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 60U)) + RotL64(aCarry, 13U)) + 17768665685046605837U;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 3U)) + 14471018461213959767U;
            aOrbiterF = ((aWandererH + RotL64(aIngress, 13U)) + 10730597892721340453U) + aNonceWordH;
            aOrbiterJ = (((aWandererE + RotL64(aScatter, 51U)) + 14863394003122760542U) + aOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1]) + aNonceWordP;
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 9948587274816688296U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 3573569431435100993U;
            aOrbiterK = RotL64((aOrbiterK * 2303922230056523077U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 8153670675740450590U) + aOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 16438856577722561424U) ^ aNonceWordB;
            aOrbiterF = RotL64((aOrbiterF * 4689247488336908827U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 15765587867581925041U) + aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 1082039522061775213U) ^ aNonceWordF;
            aOrbiterG = RotL64((aOrbiterG * 17023740047246402641U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 4202521649260798876U) + aNonceWordN;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 15877659681260461141U;
            aOrbiterJ = RotL64((aOrbiterJ * 11369910758551088173U), 11U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterJ) + 2551560426129646123U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordM;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 3005102326163906320U;
            aOrbiterE = RotL64((aOrbiterE * 4241583192662435107U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 1675501058857208089U) + aOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 12774812270956702043U;
            aOrbiterC = RotL64((aOrbiterC * 5488437008504905105U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 1044886020922563597U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 4857445127457225171U;
            aOrbiterD = RotL64((aOrbiterD * 13223560654459705259U), 57U);
            //
            aIngress = RotL64(aOrbiterF, 5U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 60U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterG, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterG, 13U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 41U) + RotL64(aOrbiterD, 23U)) + aOrbiterC);
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 5U) + RotL64(aOrbiterJ, 29U)) + aOrbiterE) + aNonceWordG) + aWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 53U) + aOrbiterG) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 38U)) + aOrbiterE) + aNonceWordO) + aWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 47U)) + aOrbiterE) + RotL64(aCarry, 39U)) + aNonceWordL);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterF, 53U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (RotL64(aWandererF, 42U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneD
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aFireLaneB
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 32444U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 29705U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 24726U)) & S_BLOCK1], 44U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29703U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 27856U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 25845U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aPrevious, 18U)) ^ (RotL64(aIngress, 3U) + RotL64(aCarry, 47U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterD = (aWandererK + RotL64(aScatter, 3U)) + 18191288703716505885U;
            aOrbiterE = (((aWandererH + RotL64(aPrevious, 47U)) + RotL64(aCarry, 47U)) + 9824014524910417136U) + aOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 37U)) + 11953012029254917548U) + aNonceWordF;
            aOrbiterA = ((aWandererI + RotL64(aCross, 60U)) + RotL64(aCarry, 13U)) + 6297568011027199089U;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 53U)) + 2576999400457367975U) + aOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aCross, 29U)) + 13176139160575558254U;
            aOrbiterB = (((aWandererG + RotL64(aScatter, 19U)) + RotL64(aCarry, 27U)) + 9978408174563621810U) + aNonceWordP;
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 16765834875061607142U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 16534507305459121344U;
            aOrbiterJ = RotL64((aOrbiterJ * 8943988574248229067U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 3114710944346151807U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 10240517868726718592U;
            aOrbiterF = RotL64((aOrbiterF * 4645691562915606463U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 10721450637990777883U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 16689590768796583952U;
            aOrbiterE = RotL64((aOrbiterE * 3046344179729901637U), 3U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterF) + 2427422768928450209U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordO;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 13495584061816457831U;
            aOrbiterD = RotL64((aOrbiterD * 6670984773768885119U), 35U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterB) + 7058636403765106682U) + aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1]) + aNonceWordC;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 9897341853944713767U;
            aOrbiterA = RotL64((aOrbiterA * 14286816859999869231U), 21U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterA) + 17749559755733386064U) + aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1]) + aNonceWordE;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 12515645083926326659U;
            aOrbiterK = RotL64((aOrbiterK * 6582878478865838245U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 2625692458813609962U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 10596240255026143019U;
            aOrbiterB = RotL64((aOrbiterB * 11605800195771080135U), 47U);
            //
            aIngress = RotL64(aOrbiterD, 53U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 60U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 13U)) + aOrbiterB) + RotL64(aCarry, 11U)) + aNonceWordL) + aWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterK, 47U)) + aOrbiterF);
            aWandererH = aWandererH + (((RotL64(aScatter, 43U) + RotL64(aOrbiterJ, 29U)) + aOrbiterA) + aNonceWordJ);
            aWandererG = aWandererG ^ ((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterD, 23U));
            aWandererB = aWandererB + ((RotL64(aIngress, 50U) + RotL64(aOrbiterE, 56U)) + aOrbiterD);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 29U) + aOrbiterD) + RotL64(aOrbiterK, 5U)) + aNonceWordN);
            aWandererE = aWandererE + ((((RotL64(aCross, 5U) + RotL64(aOrbiterD, 37U)) + aOrbiterJ) + RotL64(aCarry, 23U)) + aWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 44U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void TwistExpander_Karate_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF;
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
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xF25E15CDF916044FULL + 0xBB2C845020D51851ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x83C178E94E872021ULL + 0xCA730B78DD3573C7ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xF471FB97910106F1ULL + 0xB42B321E66AE6D76ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xB352AD28D8765B45ULL + 0xF036B1D97234B469ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x9EAD36C431EC7D39ULL + 0x92DB57711FCC7E8AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xAD4910C316A3568BULL + 0xE77FD02F94571B11ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x91D82E6C65BFFB97ULL + 0xE199177A172CC5FFULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xDDCAAF6373D603B9ULL + 0x9D481EB584F5B4A4ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xC5915932114FA649ULL + 0xD6026ADE84047EAEULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xB3C883EA19D119AFULL + 0xA8B2764656CC6706ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x8692195EA86C0D69ULL + 0xE9A3CEF8350BCA44ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xE4551CF0955E9149ULL + 0xD1F1E4AD524FAD8AULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x9CBA60D732AB51FBULL + 0xCB1E07F7369D9AC8ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xB2BE536E0DD51495ULL + 0xE4F5EC873CBD2BF4ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xA9AA67A07F3FF0D5ULL + 0x986DB9002409DB32ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xA6B70E635F7F2681ULL + 0xC1E82F94E139E218ULL);
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 1009U)) & W_KEY1], 57U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 1601U)) & W_KEY1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 2322U)) & W_KEY1], 51U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 1365U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aIngress, 6U)) ^ (RotL64(aCross, 57U) + RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterI = ((aWandererK + RotL64(aScatter, 5U)) + 13442819395490639310U) + aNonceWordB;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 35U)) + RotL64(aCarry, 39U)) + 8187292523194120936U;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 41U)) + 11469697159823131388U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aCross, 23U)) + RotL64(aCarry, 57U)) + 13414083692375929653U;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 60U)) + RotL64(aCarry, 21U)) + 11404010733687907517U;
            aOrbiterC = (((aWandererB + RotL64(aCross, 29U)) + 6783212827186218247U) + aPhaseEOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1]) + aNonceWordF;
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 13U)) + 8561131439340372614U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 6252609642004429113U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 12804867444200448952U;
            aOrbiterF = RotL64((aOrbiterF * 3114688959081972615U), 11U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterI) + 2739648749603690781U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordA;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 14808861217017399752U;
            aOrbiterD = RotL64((aOrbiterD * 373911885694012101U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 17588866502571268888U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 5882260142735642980U) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 7688252946143263869U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 15493099088132862949U) + aNonceWordH;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 5175647411532429582U;
            aOrbiterC = RotL64((aOrbiterC * 15226544495598541883U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 14279707376173642767U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 6826363572161275158U;
            aOrbiterJ = RotL64((aOrbiterJ * 5263708315440161809U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 13267185753040999992U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 9980987858092888720U;
            aOrbiterI = RotL64((aOrbiterI * 13210290848800728635U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 3582972937645514549U) + aNonceWordP;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 10140409019562890804U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6944490201647678479U), 35U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 51U);
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 4U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 47U)) + aOrbiterB);
            aWandererB = aWandererB + ((RotL64(aIngress, 13U) + RotL64(aOrbiterC, 41U)) + aOrbiterD);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 60U) + RotL64(aOrbiterC, 11U)) + aOrbiterI) + aNonceWordJ);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 53U) + aOrbiterI) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 21U)) + aNonceWordM);
            aWandererE = aWandererE ^ (((RotL64(aCross, 41U) + aOrbiterB) + RotL64(aOrbiterD, 24U)) + aNonceWordI);
            aWandererD = aWandererD + ((((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 5U)) + aPhaseEWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 35U)) + aOrbiterI) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (RotL64(aWandererF, 38U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 3622U)) & S_BLOCK1], 27U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 2847U)) & W_KEY1], 44U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 4832U)) & W_KEY1], 21U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 4431U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 56U) ^ RotL64(aPrevious, 29U)) ^ (RotL64(aIngress, 11U) + RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterA = ((aWandererC + RotL64(aIngress, 21U)) + RotL64(aCarry, 51U)) + 13880995121909552664U;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 47U)) + RotL64(aCarry, 37U)) + 14534942818069300546U;
            aOrbiterJ = (((aWandererD + RotL64(aCross, 53U)) + 17745973100886007133U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordD;
            aOrbiterD = ((aWandererI + RotL64(aScatter, 13U)) + 2249805580771946872U) + aNonceWordF;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 3U)) + 4460116116396439410U) + aPhaseEOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aCross, 41U)) + 3378683994078106878U) + aNonceWordN;
            aOrbiterI = ((aWandererG + RotL64(aScatter, 34U)) + RotL64(aCarry, 19U)) + 3992996501048809123U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 12057768808864451929U) + aNonceWordM;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterA) ^ 4115362079047921130U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 12263015903331031345U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 15297384955502206698U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 17623548383481905636U;
            aOrbiterA = RotL64((aOrbiterA * 7487278217901483685U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 3559213898000162417U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 12311605719074507335U;
            aOrbiterI = RotL64((aOrbiterI * 3982199462062847697U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 14807313864347885885U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 11222085523291581822U;
            aOrbiterK = RotL64((aOrbiterK * 12580941911587215653U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 916681229436292462U) + aNonceWordC;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 2441350114032314686U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7336079498999018067U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 7361470539894653271U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 12153585147213579808U;
            aOrbiterC = RotL64((aOrbiterC * 3040327545467672961U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 13566300726101613579U) + aNonceWordH;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 14875254144748509128U;
            aOrbiterB = RotL64((aOrbiterB * 13699179902908972403U), 29U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 29U);
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + RotL64(aOrbiterK, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 14U) + aOrbiterC) + RotL64(aOrbiterA, 11U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterI, 29U)) + aOrbiterK) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterC, 19U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterA, 35U)) + aNonceWordE);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 47U)) + aOrbiterD) + aNonceWordO);
            aWandererG = aWandererG + (((RotL64(aCross, 53U) + aOrbiterI) + RotL64(aOrbiterC, 41U)) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 23U) + aOrbiterB) + RotL64(aOrbiterK, 4U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 38U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 5911U)) & S_BLOCK1], 37U) ^ RotL64(aKeyRowReadB[((aIndex + 7532U)) & W_KEY1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6107U)) & W_KEY1], 23U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6563U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 6225U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 41U)) + (RotL64(aCross, 10U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterC = (((aWandererC + RotL64(aPrevious, 11U)) + RotL64(aCarry, 23U)) + 13650869943246163567U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = (((aWandererA + RotL64(aIngress, 57U)) + RotL64(aCarry, 53U)) + 3435284932011770999U) + aPhaseEOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aScatter, 44U)) + 12388155658186776579U) + aNonceWordL;
            aOrbiterB = (aWandererB + RotL64(aCross, 51U)) + 2374345913955712039U;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 37U)) + 6095094526980292156U) + aNonceWordK;
            aOrbiterG = (((aWandererI + RotL64(aCross, 23U)) + RotL64(aCarry, 35U)) + 4965147025852444174U) + aNonceWordJ;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 3U)) + 3261881216269075298U) + aNonceWordE;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 4939780217097329222U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterC) ^ 3019862009792676287U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterD = RotL64((aOrbiterD * 2452316208025448747U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 901910626217143974U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 3647055146712366383U;
            aOrbiterB = RotL64((aOrbiterB * 1792602402476450009U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 7731765438957392967U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 13409819457393479741U;
            aOrbiterA = RotL64((aOrbiterA * 3345078200262410715U), 43U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterA) + 5415832109107794258U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordC;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 8876738832313114471U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1304277600444504135U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 17135570542519390359U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 2373193062766802082U;
            aOrbiterE = RotL64((aOrbiterE * 4213691513185791519U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 16318403285501718552U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 8456043288604687045U) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 10556964529144571683U), 57U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterG) + 10572534930284516528U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1]) + aNonceWordF;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 14616251186735204677U;
            aOrbiterK = RotL64((aOrbiterK * 2048651204265459805U), 19U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterA, 57U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterC, 43U)) + aNonceWordG) + aPhaseEWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 4U) + RotL64(aOrbiterD, 3U)) + aOrbiterE);
            aWandererA = aWandererA + ((RotL64(aScatter, 19U) + RotL64(aOrbiterG, 60U)) + aOrbiterB);
            aWandererK = aWandererK ^ ((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterC, 27U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 37U) + aOrbiterA) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 27U)) + aNonceWordI);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterK, 37U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 47U) + RotL64(aOrbiterG, 53U)) + aOrbiterA) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + RotL64(aWandererB, 34U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 10839U)) & S_BLOCK1], 47U) ^ RotL64(aKeyRowReadB[((aIndex + 9806U)) & W_KEY1], 5U));
            aIngress ^= (RotL64(mSource[((aIndex + 10002U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9533U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 10104U)) & W_KEY1], 37U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 9450U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aIngress, 35U)) + (RotL64(aCarry, 53U) + RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 3U)) + 3684295017013759987U) + aNonceWordI;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 10U)) + RotL64(aCarry, 5U)) + 6740408842457292881U;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 27U)) + RotL64(aCarry, 23U)) + 4563975890702399441U;
            aOrbiterH = ((aWandererI + RotL64(aIngress, 21U)) + 797804144825287940U) + aNonceWordE;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 43U)) + 2763779540450101303U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = (((aWandererA + RotL64(aIngress, 51U)) + RotL64(aCarry, 39U)) + 13211846164102089685U) + aPhaseFOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 35U)) + 15214578447281401982U) + aNonceWordH;
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 13745208628754232427U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 17358621225969190747U;
            aOrbiterD = RotL64((aOrbiterD * 5325024317338823061U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 779739369960480023U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 4370963533701407813U;
            aOrbiterH = RotL64((aOrbiterH * 3123135216876641039U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 6061333005507739975U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 3589705340762734456U;
            aOrbiterI = RotL64((aOrbiterI * 16499293983611196967U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 10607697666369230567U) + aNonceWordJ;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 9356757995305239271U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 10945513661439954731U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 10093033335903048138U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 11037328061699834100U;
            aOrbiterE = RotL64((aOrbiterE * 11189760551792389605U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 558431161176115540U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 17795680919453449358U;
            aOrbiterF = RotL64((aOrbiterF * 3910117359996283803U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 6096779391116214109U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterI) ^ 17594243286880690775U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 12655610181937429915U), 13U);
            //
            aIngress = RotL64(aOrbiterH, 5U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 46U));
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 56U) + aOrbiterK) + RotL64(aOrbiterI, 6U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 27U) + aOrbiterH) + RotL64(aOrbiterD, 21U));
            aWandererC = aWandererC + ((((RotL64(aCross, 47U) + aOrbiterH) + RotL64(aOrbiterE, 35U)) + RotL64(aCarry, 23U)) + aNonceWordO);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 21U) + aOrbiterF) + RotL64(aOrbiterK, 51U)) + aNonceWordG);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 39U) + aOrbiterK) + RotL64(aOrbiterD, 57U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterH, 29U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 41U)) + aOrbiterE) + RotL64(aCarry, 43U)) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + RotL64(aWandererJ, 60U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 13500U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadA[((aIndex + 11441U)) & W_KEY1], 3U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 13034U)) & W_KEY1], 27U) ^ RotL64(mSource[((aIndex + 13288U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 13270U)) & S_BLOCK1], 48U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13205U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneC[((aIndex + 13016U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCarry, 26U)) ^ (RotL64(aCross, 39U) + RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterE = (aWandererC + RotL64(aCross, 12U)) + 12222235191147985484U;
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 5U)) + RotL64(aCarry, 57U)) + 16367317014523328414U;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 27U)) + 3511378091284703789U) + aNonceWordD;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 47U)) + 15247492830966725949U) + aNonceWordK;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 53U)) + 7745995913390407897U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aCross, 37U)) + RotL64(aCarry, 37U)) + 6463593307540108810U;
            aOrbiterD = (((aWandererB + RotL64(aScatter, 19U)) + RotL64(aCarry, 5U)) + 1101669311005268630U) + aPhaseFOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 12988052764067518580U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 17717179747434679772U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10820310705487638793U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 11662190906682400416U) + aNonceWordA;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 6563014073547628748U;
            aOrbiterC = RotL64((aOrbiterC * 16967910471722117761U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 13099094932059419219U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 16342730862261868847U;
            aOrbiterE = RotL64((aOrbiterE * 10988124108686164829U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 16855346813127524624U) + aNonceWordH;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 6570063128502306944U;
            aOrbiterG = RotL64((aOrbiterG * 4571570049463124831U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 11328352033809240501U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 11640986648833160901U;
            aOrbiterF = RotL64((aOrbiterF * 2895830492089678919U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 2675226158571501666U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 17700531248266458165U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2231403813970188657U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 7729597396731910874U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 15172374484412053756U;
            aOrbiterD = RotL64((aOrbiterD * 149009041406406517U), 51U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 19U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 43U));
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 35U)) + aOrbiterC) + aNonceWordJ) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 11U)) + aNonceWordC);
            aWandererB = aWandererB ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterC, 29U)) + aOrbiterI) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 51U)) + aOrbiterD) + RotL64(aCarry, 27U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterE, 19U)) + aOrbiterK) + aNonceWordG);
            aWandererG = aWandererG + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterG, 58U)) + aOrbiterD);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 20U) + aOrbiterF) + RotL64(aOrbiterG, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 44U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + RotL64(aWandererB, 21U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 14107U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneC[((aIndex + 15519U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 13856U)) & W_KEY1], 3U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 13897U)) & W_KEY1], 11U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 13746U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16031U)) & S_BLOCK1], 34U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 14315U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCross, 29U)) ^ (RotL64(aPrevious, 14U) ^ RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 3U)) + 17019646486641172469U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aIngress, 35U)) + RotL64(aCarry, 57U)) + 12276141179299971572U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 51U)) + RotL64(aCarry, 13U)) + 3617241694029841555U;
            aOrbiterI = ((aWandererE + RotL64(aCross, 43U)) + 6967963401259371737U) + aNonceWordC;
            aOrbiterC = (aWandererG + RotL64(aIngress, 18U)) + 6340709284279891017U;
            aOrbiterF = (((aWandererK + RotL64(aPrevious, 27U)) + RotL64(aCarry, 39U)) + 456065368903896482U) + aPhaseFOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = ((aWandererF + RotL64(aScatter, 11U)) + 17686765719908116203U) + aNonceWordH;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 1322045955429785736U) + aNonceWordL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 5163772703302372887U;
            aOrbiterJ = RotL64((aOrbiterJ * 3193272189179082313U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 13268431135020363252U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 6538789950366849332U;
            aOrbiterC = RotL64((aOrbiterC * 5352960308459065837U), 29U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterC) + 10390344544314544893U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1]) + aNonceWordN;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 5087084271300584267U;
            aOrbiterF = RotL64((aOrbiterF * 15149302947570776165U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 13423071121590981727U) + aNonceWordM;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 18324443012024134729U;
            aOrbiterI = RotL64((aOrbiterI * 15814349432207734533U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 4129091815978464507U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 17024797553831962245U;
            aOrbiterD = RotL64((aOrbiterD * 3137753479364378175U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 6501545108779991661U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 11930037791867597447U;
            aOrbiterE = RotL64((aOrbiterE * 4904739567549702851U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 4667298703308315851U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 6315980380900062127U) ^ aNonceWordK;
            aOrbiterK = RotL64((aOrbiterK * 12080555704907924637U), 35U);
            //
            aIngress = RotL64(aOrbiterJ, 57U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + (RotL64(aOrbiterI, 14U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 39U) + RotL64(aOrbiterC, 23U)) + aOrbiterJ) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterF, 41U)) + aOrbiterK) + aNonceWordE);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterE, 35U)) + aOrbiterK) + aNonceWordB);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 5U) + aOrbiterC) + RotL64(aOrbiterD, 13U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 51U) + aOrbiterJ) + RotL64(aOrbiterI, 29U)) + aNonceWordD) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((((RotL64(aCross, 30U) + aOrbiterE) + RotL64(aOrbiterF, 60U)) + aNonceWordG) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterD, 47U)) + aOrbiterI) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (RotL64(aWandererK, 50U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 17820U)) & S_BLOCK1], 60U) ^ RotL64(aKeyRowReadA[((aIndex + 17021U)) & W_KEY1], 11U));
            aIngress ^= (RotL64(mSource[((aIndex + 16734U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((aIndex + 17709U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 18561U)) & W_KEY1], 19U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 17281U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 18425U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aIngress, 39U)) + (RotL64(aCarry, 5U) + RotL64(aPrevious, 56U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterB = ((aWandererE + RotL64(aCross, 11U)) + 18255347001097480328U) + aNonceWordF;
            aOrbiterH = (aWandererG + RotL64(aPrevious, 43U)) + 13679246790311505735U;
            aOrbiterK = (((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 53U)) + 10565839529765027116U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (((aWandererC + RotL64(aIngress, 5U)) + RotL64(aCarry, 11U)) + 14327172566224769901U) + aPhaseGOrbiterAssignSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aScatter, 23U)) + 16239024612038195174U;
            aOrbiterC = ((aWandererF + RotL64(aCross, 36U)) + 13800012174212131890U) + aNonceWordA;
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 51U)) + RotL64(aCarry, 27U)) + 13900288860157577583U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 4144386119777112740U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 3154558262670631372U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13236911910092437063U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 7456728543137614001U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 11709519851158935384U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7016689518570071587U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 15607438907832240304U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 9276575329661725624U;
            aOrbiterI = RotL64((aOrbiterI * 8879744070762412745U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 6459435969129449226U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 6442382118416542275U) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 2921027306686588233U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 12117432107282150865U) + aNonceWordD;
            aOrbiterA = (((aOrbiterA ^ aOrbiterJ) ^ 6831279293184793243U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 2435360641135249073U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 9520022957804572889U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 8322178689474588679U;
            aOrbiterJ = RotL64((aOrbiterJ * 1627707191467537115U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 4162401591586869316U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 8994015844714895961U) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 15421910378057951895U), 41U);
            //
            aIngress = RotL64(aOrbiterA, 41U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 34U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterH, 60U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterB, 5U)) + aOrbiterK) + aNonceWordC);
            aWandererG = aWandererG + (((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterB, 11U)) + RotL64(aCarry, 21U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 27U)) + aOrbiterB) + aPhaseGWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 53U)) + aOrbiterI) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterJ, 21U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 60U) + RotL64(aOrbiterB, 37U)) + aOrbiterA) + aNonceWordB) + aPhaseGWandererUpdateSaltC[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 18U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 35U);
            aCarry = aCarry + RotL64(aIngress, 50U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 20428U)) & S_BLOCK1], 20U) ^ RotL64(mSource[((aIndex + 20146U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 20398U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20566U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20434U)) & W_KEY1], 19U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 19619U)) & W_KEY1], 27U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21099U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((aIndex + 21432U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 23U)) ^ (RotL64(aCross, 42U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterH = (((aWandererB + RotL64(aIngress, 11U)) + RotL64(aCarry, 51U)) + 6243113109470883144U) + aPhaseGOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = (aWandererJ + RotL64(aCross, 21U)) + 3891552123999605832U;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 27U)) + 8758797898587019128U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 35U)) + RotL64(aCarry, 21U)) + 1005891374086408851U;
            aOrbiterB = (((aWandererG + RotL64(aCross, 47U)) + RotL64(aCarry, 5U)) + 3713426782180050764U) + aNonceWordM;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 57U)) + 18358143862391573534U) + aNonceWordI;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 4U)) + 17504394029693712404U) + aNonceWordP;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 5312729289027417014U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 2560873623431186029U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16843728573219210173U), 37U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterH) + 16309322822806704211U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1]) + aNonceWordE;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 10195513918020652600U;
            aOrbiterB = RotL64((aOrbiterB * 14569219741824123715U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 2552116263258744287U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterC) ^ 7732784879810980089U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 15041929399477790999U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 16499127570665381507U) + aNonceWordJ;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 10890036715535519036U;
            aOrbiterK = RotL64((aOrbiterK * 9065115450010475187U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 16288944603478791554U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 14542766121469312846U) ^ aNonceWordH;
            aOrbiterH = RotL64((aOrbiterH * 8435383464425875209U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 5973595239494084696U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 1820492719977197097U;
            aOrbiterC = RotL64((aOrbiterC * 16164917159141304405U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 10489529555776381736U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 6392552206958240484U;
            aOrbiterD = RotL64((aOrbiterD * 11761477994533503307U), 43U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 27U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 20U));
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterB, 41U)) + aNonceWordB);
            aWandererK = aWandererK + ((RotL64(aScatter, 41U) + RotL64(aOrbiterJ, 27U)) + aOrbiterC);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 12U) + aOrbiterH) + RotL64(aOrbiterK, 51U)) + aNonceWordN);
            aWandererF = aWandererF + ((((RotL64(aCross, 47U) + RotL64(aOrbiterB, 35U)) + aOrbiterC) + RotL64(aCarry, 3U)) + aNonceWordO);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterK, 3U)) + aNonceWordK);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 21U)) + aOrbiterJ) + RotL64(aCarry, 39U)) + aPhaseGWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 60U)) + aOrbiterG) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 12U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + RotL64(aWandererE, 37U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 22454U)) & S_BLOCK1], 35U) ^ RotL64(aKeyRowReadA[((aIndex + 22251U)) & W_KEY1], 56U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 23605U)) & W_KEY1], 11U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 24465U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 23982U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 24574U)) & S_BLOCK1], 11U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 24106U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneD[((aIndex + 22515U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 27U) + RotL64(aIngress, 5U)) + (RotL64(aCross, 52U) ^ RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterJ = ((aWandererF + RotL64(aCross, 3U)) + RotL64(aCarry, 3U)) + 8988572360732005217U;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 51U)) + 17889613225105985335U) + aNonceWordF;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 11U)) + RotL64(aCarry, 23U)) + 15563478320513948626U;
            aOrbiterI = ((((aWandererB + RotL64(aScatter, 21U)) + RotL64(aCarry, 41U)) + 3441351228410524816U) + aPhaseGOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1]) + aNonceWordE;
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 41U)) + 4425592689451435346U;
            aOrbiterG = (((aWandererE + RotL64(aCross, 60U)) + 12733160231627305928U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 27U)) + 3574152157304607854U) + aNonceWordC;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 15167631896729808783U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 15822667973915417055U;
            aOrbiterF = RotL64((aOrbiterF * 5155661648455308057U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 17181685481076577637U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 9979204751408873468U) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 8244434774754786565U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 1334240485667164762U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 9190066751460137016U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14585141844653660363U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 15465215829109246336U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 2305208282453624419U;
            aOrbiterG = RotL64((aOrbiterG * 10257861974108363283U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 16951510027310993926U) + aNonceWordP;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 11117938943423526901U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7805486716716924787U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 12461379120662979432U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 11719697049048823897U;
            aOrbiterE = RotL64((aOrbiterE * 14880996802304818757U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 6843357278142933570U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 12727898578324702374U;
            aOrbiterI = RotL64((aOrbiterI * 9786435451654365097U), 13U);
            //
            aIngress = RotL64(aOrbiterJ, 60U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 51U) + aOrbiterA) + RotL64(aOrbiterG, 27U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterE, 58U)) + RotL64(aCarry, 21U)) + aNonceWordG);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 21U)) + aOrbiterI);
            aWandererB = aWandererB + (((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterA, 41U)) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 10U) + RotL64(aOrbiterF, 3U)) + aOrbiterI) + aNonceWordN);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterE, 51U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterK, 11U)) + aOrbiterG) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererG, 34U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + RotL64(aWandererJ, 39U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 26119U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadA[((aIndex + 25672U)) & W_KEY1], 11U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 25761U)) & S_BLOCK1], 23U) ^ RotL64(aFireLaneB[((aIndex + 26577U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 26326U)) & W_KEY1], 60U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26441U)) & S_BLOCK1], 47U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 24856U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 26699U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 26U) + RotL64(aCarry, 43U)) ^ (RotL64(aCross, 57U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterF = ((aWandererE + RotL64(aIngress, 51U)) + 7896237440058555694U) + aNonceWordP;
            aOrbiterK = (((aWandererB + RotL64(aCross, 3U)) + RotL64(aCarry, 37U)) + 11870529476037558635U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = (((aWandererC + RotL64(aScatter, 21U)) + 9158983227801569448U) + aPhaseHOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1]) + aNonceWordL;
            aOrbiterG = (((aWandererJ + RotL64(aPrevious, 11U)) + RotL64(aCarry, 21U)) + 4710172270996950329U) + aNonceWordC;
            aOrbiterD = (((aWandererG + RotL64(aIngress, 27U)) + RotL64(aCarry, 3U)) + 14634482800356647630U) + aNonceWordE;
            aOrbiterH = (aWandererK + RotL64(aScatter, 60U)) + 8822207952170610891U;
            aOrbiterI = (aWandererA + RotL64(aCross, 39U)) + 13755891414028982553U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 4555293067488040719U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 2816805148093762081U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 16838149138341713943U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 2122631477965135190U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 4592922416380416071U;
            aOrbiterK = RotL64((aOrbiterK * 11644507904538573165U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 7102471666524164715U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 17274623547879474204U;
            aOrbiterF = RotL64((aOrbiterF * 5443572270546181789U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 938587316977094680U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterH) ^ 18258015823797023523U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 6068819567674605919U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 5809987756043471595U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 5083075160112581620U;
            aOrbiterD = RotL64((aOrbiterD * 3313957222154937503U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 5960021727750946496U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 5967477320950630150U;
            aOrbiterI = RotL64((aOrbiterI * 330964768256424655U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 6578428711689296132U) + aNonceWordM;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 5601728218197771276U;
            aOrbiterH = RotL64((aOrbiterH * 9552559022315971847U), 53U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterG, 3U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + RotL64(aOrbiterD, 58U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 39U) + RotL64(aOrbiterH, 3U)) + aOrbiterD) + aNonceWordA);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 13U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterH, 21U)) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterG, 58U)) + aOrbiterF) + aNonceWordG);
            aWandererA = aWandererA + ((((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 23U)) + aPhaseHWandererUpdateSaltD[((aIndex + 6U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterG, 27U)) + aOrbiterK) + aPhaseHWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 10U) + RotL64(aOrbiterF, 35U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 50U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + RotL64(aWandererC, 11U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 27823U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneD[((aIndex + 29081U)) & S_BLOCK1], 58U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 29611U)) & W_KEY1], 47U) ^ RotL64(aFireLaneC[((aIndex + 28449U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 29896U)) & W_KEY1], 53U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29620U)) & S_BLOCK1], 35U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27371U)) & S_BLOCK1], 22U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 27891U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 34U) ^ RotL64(aCross, 3U)) ^ (RotL64(aCarry, 47U) + RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 11U)) + 3448371607470865612U) + aPhaseHOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aScatter, 21U)) + 3743742913651580573U) + aNonceWordF;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 5U)) + 13069491287948807280U) + aNonceWordP;
            aOrbiterA = (((aWandererF + RotL64(aCross, 37U)) + RotL64(aCarry, 19U)) + 16872779275586545632U) + aNonceWordK;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 51U)) + 17945792656755062795U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 57U)) + RotL64(aCarry, 5U)) + 18199747196793731853U;
            aOrbiterB = (((aWandererD + RotL64(aPrevious, 28U)) + RotL64(aCarry, 39U)) + 15953311878379809513U) + aNonceWordC;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 941268763494588338U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 10090221530365796809U;
            aOrbiterD = RotL64((aOrbiterD * 14035236086292997613U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 8335698093307607001U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 6147498804734306100U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6904444049941211327U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 5980246079567570090U) + aNonceWordO;
            aOrbiterH = (((aOrbiterH ^ aOrbiterI) ^ 4152167624425912978U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterH = RotL64((aOrbiterH * 10019421651535123573U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 14990418790239735916U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 3418668387496597219U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12814077238529863119U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 4206650904177199425U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 3905470780938996069U;
            aOrbiterI = RotL64((aOrbiterI * 16030122739273137005U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 9968672788233080924U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterD) ^ 602258075661864866U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 2615726693066300065U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 17751667243048041383U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 2414054413585296027U) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 1049512574773201893U), 11U);
            //
            aIngress = RotL64(aOrbiterI, 3U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + RotL64(aOrbiterD, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 11U) + RotL64(aOrbiterJ, 57U)) + aOrbiterB) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 37U) + aOrbiterB) + RotL64(aOrbiterK, 29U));
            aWandererC = aWandererC + ((((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterB, 39U)) + RotL64(aCarry, 41U)) + aNonceWordB);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 27U) + aOrbiterD) + RotL64(aOrbiterA, 50U)) + aPhaseHWandererUpdateSaltB[((aIndex + 8U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 19U) + aOrbiterH) + RotL64(aOrbiterJ, 11U)) + aNonceWordE);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 5U)) + aOrbiterI) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 56U) + RotL64(aOrbiterD, 21U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 56U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 32336U)) & S_BLOCK1], 60U) ^ RotL64(aKeyRowReadA[((aIndex + 31052U)) & W_KEY1], 5U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 31816U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31887U)) & S_BLOCK1], 27U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31446U)) & S_BLOCK1], 43U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 30358U)) & W_KEY1], 13U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 27U)) ^ (RotL64(aCarry, 44U) + RotL64(aIngress, 13U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterC = (((aWandererD + RotL64(aCross, 39U)) + RotL64(aCarry, 11U)) + 2558105147674438050U) + aNonceWordL;
            aOrbiterG = (((aWandererE + RotL64(aScatter, 58U)) + RotL64(aCarry, 27U)) + 15856662514774702561U) + aNonceWordN;
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 13U)) + RotL64(aCarry, 43U)) + 13346869226246584582U;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 3U)) + 7632111846116243973U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aScatter, 21U)) + 2102101361626976279U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aPrevious, 29U)) + 5605968705067851563U;
            aOrbiterK = (aWandererB + RotL64(aIngress, 47U)) + 6842483186584326681U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 5559797213819425064U) + aNonceWordD;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 12422313931331576759U;
            aOrbiterE = RotL64((aOrbiterE * 7399849122565913401U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 2751024420047872601U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 11031320239359798610U) ^ aNonceWordO;
            aOrbiterD = RotL64((aOrbiterD * 8607639453141148025U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 14366375309473793217U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 11971479429768505316U;
            aOrbiterC = RotL64((aOrbiterC * 10063001532313098203U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 3947595951884469542U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterK) ^ 17882767922372770896U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 3361906348965810211U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 513871456983509223U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 5951677013597794294U;
            aOrbiterK = RotL64((aOrbiterK * 8508629569649935293U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 437626309049021931U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 466674061172005705U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1310502572084891157U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 12362602809233133718U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 10525852878882195702U;
            aOrbiterG = RotL64((aOrbiterG * 17755022180514914325U), 57U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 37U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterG, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterE, 47U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 23U) + RotL64(aOrbiterD, 3U)) + aOrbiterG) + aNonceWordK) + aPhaseHWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 41U) + aOrbiterG) + RotL64(aOrbiterC, 29U)) + aNonceWordH);
            aWandererD = aWandererD + (((RotL64(aPrevious, 58U) + RotL64(aOrbiterE, 57U)) + aOrbiterC) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 13U) + RotL64(aOrbiterC, 37U)) + aOrbiterK) + aNonceWordE) + aPhaseHWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterE, 11U)) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 20U)) + aOrbiterB) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 58U));
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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

void TwistExpander_Karate_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xF442DBF57F02B549ULL + 0xE845BF19D4A755A6ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xB25ABA5C27930427ULL + 0xF55B95D4F77B4160ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xBD851444EE261B63ULL + 0xB751DB0B7E0D91FAULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xC634E4698933D057ULL + 0xA478A39DD835FFD5ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xE63455DF707C2B7BULL + 0xC0A68EBB59C1D082ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xABE422FA5DD1B919ULL + 0xA7ED9C5D3CD5DA6AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xACB66A98E2500599ULL + 0x85D2D1E30847E93FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xB27C33219F7CAAEFULL + 0xC974A694309523C8ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x8768637ACAD4A017ULL + 0xB86939D9AFAC5F61ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xCA71BDB89D678777ULL + 0xC7A9115629C349CBULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xB44318E678F01273ULL + 0xE6508A0DE3DD28A2ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xCD044329E10059F7ULL + 0xC140BF5383EDD7B6ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xFBF3D1D507D36793ULL + 0xB801F62BA259C6F5ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x9A00D63969497E69ULL + 0x86B83940C1F81287ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xE9D7A6FFA33BDAD1ULL + 0x98E5341A4E36EEE4ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xEDDC321635C1345FULL + 0xF19230F49A3BC5F5ULL);
    // GSeedRunSeed_B seed_loop_a (start)
    {
        // GSeedRunSeed_B seed_loop_a lane group
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneC, aExpandLaneC, aExpandLaneD, aInvestLaneA, aFireLaneA, aInvestLaneB, aFireLaneD, aOperationLaneA, aFireLaneB, aOperationLaneB, aOperationLaneC
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 145U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneB[((aIndex + 3055U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 3382U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1749U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneD[((aIndex + 2320U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCarry, 27U)) + (RotL64(aIngress, 39U) ^ RotL64(aCross, 52U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterG = ((((aWandererD + RotL64(aPrevious, 11U)) + RotL64(aCarry, 51U)) + 9630214189402543339U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordB;
            aOrbiterF = ((((aWandererA + RotL64(aCross, 26U)) + RotL64(aCarry, 35U)) + 4072576573737526819U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordK;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 47U)) + 15994787452709618869U) + aNonceWordC;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 57U)) + RotL64(aCarry, 3U)) + 6403240137132259482U;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 37U)) + 10229266900170507720U) + aNonceWordN;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 5025294577989748989U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 16696461238217956883U;
            aOrbiterH = RotL64((aOrbiterH * 15993828976234917577U), 3U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterH) + 9878318855341719119U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1]) + aNonceWordI;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 16086635438116177346U) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 5585682357395705671U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 12295437783084203730U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 7681150419912842402U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7289497379725191451U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 2639104034287637448U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 12298170009332243573U;
            aOrbiterA = RotL64((aOrbiterA * 9397919591171238575U), 29U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterA) + 3485932317267669626U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordM;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 16569551670038752475U;
            aOrbiterG = RotL64((aOrbiterG * 8139802826402217631U), 57U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 47U);
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((((RotL64(aCross, 37U) + aOrbiterA) + RotL64(aOrbiterH, 26U)) + aNonceWordA) + aPhaseAWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterG, 13U)) + aOrbiterI) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 48U) + RotL64(aOrbiterF, 35U)) + aOrbiterA) + aNonceWordO);
            aWandererH = aWandererH + ((((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterA, 47U)) + RotL64(aCarry, 3U)) + aPhaseAWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterG, 5U)) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 9107U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneC[((aIndex + 9873U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 10027U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 10690U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneD[((aIndex + 10062U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCross, 11U)) ^ (RotL64(aPrevious, 37U) + RotL64(aCarry, 58U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterI = (((aWandererI + RotL64(aCross, 52U)) + RotL64(aCarry, 37U)) + 1952750591494698524U) + aNonceWordL;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 35U)) + 4488270851303332830U) + aNonceWordM;
            aOrbiterK = (((aWandererD + RotL64(aIngress, 27U)) + RotL64(aCarry, 57U)) + 2738763375328927635U) + aPhaseAOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = (((aWandererJ + RotL64(aScatter, 19U)) + RotL64(aCarry, 23U)) + 6728843649480454340U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = (aWandererC + RotL64(aPrevious, 11U)) + 10490717875258865358U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 1429288737812910205U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 2761375016998907636U) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 16589197409983023283U), 57U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterJ) + 1088988605204499835U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1]) + aNonceWordA;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 6829840407300289709U;
            aOrbiterB = RotL64((aOrbiterB * 13101432880030791787U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 9267240337867690471U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 8120113021183975703U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14296504593187173107U), 5U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterI) + 1340980511302566784U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1]) + aNonceWordF;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 11874452169979878835U;
            aOrbiterJ = RotL64((aOrbiterJ * 8638486178860092537U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 1872314794140971426U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 6013952618696225751U;
            aOrbiterC = RotL64((aOrbiterC * 7994863587373565715U), 21U);
            //
            aIngress = RotL64(aOrbiterJ, 13U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterB, 54U)) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 24U) + aOrbiterJ) + RotL64(aOrbiterK, 43U)) + aPhaseAWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 53U) + aOrbiterJ) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 51U)) + aNonceWordI);
            aWandererF = aWandererF ^ (((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterC, 5U)) + aNonceWordB);
            aWandererI = aWandererI + (((RotL64(aScatter, 5U) + RotL64(aOrbiterC, 29U)) + aOrbiterB) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + RotL64(aWandererI, 5U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 11517U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((aIndex + 14524U)) & S_BLOCK1], 48U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 14180U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 11256U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 12411U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aExpandLaneA[((aIndex + 11631U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCross, 52U)) + (RotL64(aCarry, 35U) ^ RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterG = (((aWandererG + RotL64(aPrevious, 3U)) + RotL64(aCarry, 43U)) + 7893287783892523139U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = (((aWandererF + RotL64(aScatter, 23U)) + 10257331997383491153U) + aPhaseAOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1]) + aNonceWordH;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 39U)) + RotL64(aCarry, 29U)) + 14562226733652231753U;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 11U)) + 14320342577110737851U) + aNonceWordA;
            aOrbiterF = (((aWandererE + RotL64(aScatter, 48U)) + RotL64(aCarry, 57U)) + 9816717579822880756U) + aNonceWordE;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 9558926960095881953U) + aNonceWordP;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 9230371862654338324U;
            aOrbiterH = RotL64((aOrbiterH * 8842712825810461561U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 6414274291252913420U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 13868546184398350849U) ^ aNonceWordB;
            aOrbiterJ = RotL64((aOrbiterJ * 1547986864837497409U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 16940736952569949038U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 2866957764814864371U;
            aOrbiterF = RotL64((aOrbiterF * 3554702178644797003U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 7916721976073979724U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 1602444214978842275U;
            aOrbiterE = RotL64((aOrbiterE * 11072503711308122385U), 57U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterE) + 9529061385251008037U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1]) + aNonceWordF;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 8402775110887376588U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13980225144628227381U), 47U);
            //
            aIngress = RotL64(aOrbiterJ, 37U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + RotL64(aOrbiterH, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 13U) + aOrbiterE) + RotL64(aOrbiterG, 3U));
            aWandererC = aWandererC + (((((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 39U)) + aOrbiterJ) + RotL64(aCarry, 47U)) + aNonceWordN) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 27U)) + aOrbiterE) + aNonceWordO);
            aWandererE = aWandererE + (((((RotL64(aCross, 21U) + RotL64(aOrbiterE, 18U)) + aOrbiterJ) + RotL64(aCarry, 27U)) + aNonceWordL) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 30U) + aOrbiterJ) + RotL64(aOrbiterG, 51U)) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + RotL64(aWandererE, 19U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 16979U)) & S_BLOCK1], 21U) ^ RotL64(aInvestLaneA[((aIndex + 20430U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 20914U)) & S_BLOCK1], 46U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 19861U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20814U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 17870U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aIngress, 53U)) ^ (RotL64(aPrevious, 3U) + RotL64(aCarry, 38U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterJ = (((aWandererH + RotL64(aScatter, 60U)) + RotL64(aCarry, 51U)) + 3238389262925516513U) + aNonceWordN;
            aOrbiterA = ((((aWandererJ + RotL64(aCross, 51U)) + RotL64(aCarry, 3U)) + 12381787182611386995U) + aPhaseAOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1]) + aNonceWordL;
            aOrbiterG = ((aWandererC + RotL64(aIngress, 39U)) + 7883885539305181549U) + aNonceWordK;
            aOrbiterF = ((((aWandererB + RotL64(aPrevious, 19U)) + RotL64(aCarry, 29U)) + 1185413044597727092U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordO;
            aOrbiterI = (aWandererG + RotL64(aIngress, 29U)) + 15219353497204773135U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 7533774715626734082U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 2599930450937763464U) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 13207380361960949159U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 16074720663961214284U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 15483613196360051221U;
            aOrbiterJ = RotL64((aOrbiterJ * 11717479088020532861U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 9396557867081376268U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 9668459976852660245U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11748505665890567063U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 9037269914643207212U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (((aOrbiterF ^ aOrbiterA) ^ 16936742640861088240U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 1040172193161012227U), 37U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterJ) + 16481274825758546398U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordF;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 481851372837611166U) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 2225030139210599207U), 57U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 14U);
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterI, 56U)) + aNonceWordP);
            aWandererH = aWandererH + (((((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 29U)) + aOrbiterG) + RotL64(aCarry, 51U)) + aNonceWordH) + aPhaseAWandererUpdateSaltA[((aIndex + 8U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 37U)) + aOrbiterI) + aNonceWordG) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 47U) + RotL64(aOrbiterJ, 3U)) + aOrbiterF) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 4U) + aOrbiterJ) + RotL64(aOrbiterA, 13U)) + aNonceWordB);
            //
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 22224U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneA[((aIndex + 24836U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 22917U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 22982U)) & S_BLOCK1], 47U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 22690U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 22195U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 13U) ^ RotL64(aPrevious, 43U)) ^ (RotL64(aIngress, 27U) + RotL64(aCarry, 56U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterH = ((aWandererK + RotL64(aScatter, 11U)) + 6361545377408870615U) + aNonceWordE;
            aOrbiterB = (((aWandererH + RotL64(aIngress, 57U)) + RotL64(aCarry, 39U)) + 2967245486744774933U) + aPhaseAOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aCross, 47U)) + 3836634268482850139U) + aNonceWordP;
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 34U)) + RotL64(aCarry, 51U)) + 7691642115360086297U;
            aOrbiterD = ((((aWandererE + RotL64(aScatter, 19U)) + RotL64(aCarry, 3U)) + 16479280384178279281U) + aPhaseAOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1]) + aNonceWordO;
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 2901468732552539249U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 2600353867755647475U;
            aOrbiterI = RotL64((aOrbiterI * 1140827276372862433U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 5666596904781510956U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 16108791609267427553U;
            aOrbiterD = RotL64((aOrbiterD * 8904649663479834199U), 43U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterD) + 8389926875737312112U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1]) + aNonceWordB;
            aOrbiterB = (((aOrbiterB ^ aOrbiterI) ^ 1689501721163024426U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 6517194895779049139U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 11721701506949917719U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 3963842745030140473U) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 6692473494944919373U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 8510538243472109368U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterC) ^ 18281865214102080387U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterH = RotL64((aOrbiterH * 1351546966368884609U), 21U);
            //
            aIngress = RotL64(aOrbiterI, 30U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 57U)) + aOrbiterB) + aNonceWordJ) + aPhaseAWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aIngress, 47U) + aOrbiterH) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 19U)) + aNonceWordF);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 38U) + aOrbiterC) + RotL64(aOrbiterB, 20U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aCross, 27U) + RotL64(aOrbiterI, 3U)) + aOrbiterC) + RotL64(aCarry, 41U)) + aNonceWordI);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterD, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererK, 27U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 32514U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((aIndex + 28883U)) & S_BLOCK1], 14U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 31532U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28533U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31931U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 31185U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aIngress, 19U)) ^ (RotL64(aPrevious, 50U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterJ = (((aWandererI + RotL64(aPrevious, 5U)) + RotL64(aCarry, 11U)) + 11039986441331892533U) + aNonceWordK;
            aOrbiterB = (((aWandererC + RotL64(aScatter, 53U)) + RotL64(aCarry, 39U)) + 6256024955965426119U) + aNonceWordF;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 27U)) + 9857443189988995666U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aCross, 13U)) + RotL64(aCarry, 53U)) + 11900944813380998208U;
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 36U)) + 8422577734978875541U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 3100835100713928724U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 11871553509810206993U) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 15501681886909921677U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 17614749493763417027U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 3638372131856199916U;
            aOrbiterB = RotL64((aOrbiterB * 480683274898147025U), 29U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterF) + 6582275259281025770U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordG;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 17016882418498941958U) ^ aNonceWordC;
            aOrbiterJ = RotL64((aOrbiterJ * 4269869255230867823U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 1747214688658984715U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 9356088987044015278U) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 16221733545319753695U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 4056238112133473456U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 16013150119949532998U;
            aOrbiterK = RotL64((aOrbiterK * 12913648646318115315U), 39U);
            //
            aIngress = RotL64(aOrbiterK, 39U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + RotL64(aOrbiterJ, 50U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 11U) + aOrbiterI) + RotL64(aOrbiterB, 43U)) + aNonceWordN);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 56U) + RotL64(aOrbiterI, 30U)) + aOrbiterJ);
            aWandererC = aWandererC + (((((RotL64(aPrevious, 19U) + aOrbiterB) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 53U)) + aNonceWordI) + aPhaseAWandererUpdateSaltF[((aIndex + 10U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterI, 13U)) + aNonceWordA) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterK, 5U)) + RotL64(aCarry, 19U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 48U));
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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

void TwistExpander_Karate_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x9D01217F0F1E7513ULL + 0xB9906D33288A9E11ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xDBA206105B1BADD1ULL + 0xBB39ABD16C52B052ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xB0787A7114492E7BULL + 0x9190098FA2E0B5AFULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xD9552E96A1C2F803ULL + 0xA0CF3D31C0164647ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xF43762876D3BCB87ULL + 0xB6A4E13D33751971ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x9C4A82A455D7CB35ULL + 0x988F18C29F8B42D2ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xDF94254DBF1B5D5DULL + 0xB2B7F98C0BC5A017ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xCF437C4D8AE8A509ULL + 0x970C3F0C60D72F0EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x9E254DEADA50EB97ULL + 0xA87A8DA635E0D367ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xCE2085C9741DE8DFULL + 0xEBE1BBAE20143458ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xE6F28AF9DBAA4DDBULL + 0xAC1EBF2F4BC5B275ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xE50B4DE533B4A02FULL + 0xDBF7072309A423A7ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x86E88C5FB4D05D41ULL + 0x9636862B6B2E48B2ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x820963643756E1C7ULL + 0xB3D0EE96A6523BC5ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xDCDAF4C1EE84F6A1ULL + 0xD682788D8D6466C6ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xC7455B2219AAF079ULL + 0xA6FE6212088BDD20ULL);
    // GSeedRunSeed_C seed_loop_b (start)
    {
        // GSeedRunSeed_C seed_loop_b lane group
        // read from: aOperationLaneA, aOperationLaneB, aExpandLaneA, aOperationLaneC, aOperationLaneD, aExpandLaneD, aInvestLaneC, aExpandLaneC, aFireLaneB, aInvestLaneD, aExpandLaneB, aWorkLaneA, aFireLaneD, aWorkLaneB, aFireLaneA, aWorkLaneC, aFireLaneC
        // write to: aInvestLaneC, aInvestLaneD, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // seed_loop_b loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aExpandLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aExpandLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aExpandLaneD
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 4192U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((aIndex + 61U)) & S_BLOCK1], 18U));
            aIngress ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 751U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3328U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 4618U)) & S_BLOCK1], 30U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 4429U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 18U) ^ RotL64(aPrevious, 43U)) + (RotL64(aIngress, 57U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterJ = (((aWandererJ + RotL64(aCross, 35U)) + RotL64(aCarry, 19U)) + 4773124477323378268U) + aPhaseBOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aScatter, 53U)) + RotL64(aCarry, 37U)) + 16848723289435796005U;
            aOrbiterF = (((aWandererB + RotL64(aPrevious, 57U)) + RotL64(aCarry, 3U)) + 13846642134917107058U) + aNonceWordD;
            aOrbiterB = (aWandererA + RotL64(aIngress, 12U)) + 6472057872482789939U;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 3U)) + 2747019500690707226U) + aNonceWordN;
            aOrbiterE = ((aWandererI + RotL64(aScatter, 29U)) + 9003965289739733880U) + aNonceWordE;
            aOrbiterI = (aWandererC + RotL64(aIngress, 47U)) + 3013390651936257377U;
            aOrbiterC = ((aWandererG + RotL64(aCross, 41U)) + 3331004709895625067U) + aPhaseBOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aIngress, 22U)) + 15355010435553517129U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 7709870658004280052U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 13568728443963926564U;
            aOrbiterF = RotL64((aOrbiterF * 6736090830113688981U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 12409548853419307131U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 969183352023661537U;
            aOrbiterE = RotL64((aOrbiterE * 5549220554838837145U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 15370309834426476775U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 3896803894396631184U) ^ aNonceWordK;
            aOrbiterD = RotL64((aOrbiterD * 11018830202891911603U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 10848873633291935766U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 12885336509190543440U) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 1487357252619221365U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 8252290890093788010U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 9201553615601641350U) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 420321130559162915U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 14014209645503188472U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 4015071464301844550U;
            aOrbiterJ = RotL64((aOrbiterJ * 17444195018239904971U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 16173085647514027347U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 16916627014974363360U;
            aOrbiterK = RotL64((aOrbiterK * 7699587344277490953U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 1591680303404522110U) + aNonceWordH;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 16499606051269327916U;
            aOrbiterC = RotL64((aOrbiterC * 814405848002794813U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 6932673635509444619U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 8745681160108707944U;
            aOrbiterA = RotL64((aOrbiterA * 14565255558668084787U), 19U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterB, 23U);
            aIngress = aIngress + (RotL64(aOrbiterK, 20U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterJ, 13U)) + aOrbiterB);
            aWandererC = aWandererC + ((((RotL64(aScatter, 58U) + RotL64(aOrbiterE, 41U)) + aOrbiterF) + RotL64(aCarry, 43U)) + aPhaseBWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterJ, 46U)) + aNonceWordP);
            aWandererG = aWandererG + ((((RotL64(aCross, 53U) + aOrbiterJ) + RotL64(aOrbiterF, 19U)) + RotL64(aCarry, 11U)) + aNonceWordM);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 29U)) + aOrbiterK);
            aWandererA = aWandererA + ((RotL64(aCross, 41U) + RotL64(aOrbiterD, 3U)) + aOrbiterA);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterE, 53U)) + aOrbiterA) + aPhaseBWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 48U) + RotL64(aOrbiterK, 24U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterJ, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + (RotL64(aWandererD, 60U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + RotL64(aWandererF, 35U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 2
        // ingress from: aInvestLaneC, aOperationLaneC, aOperationLaneD, aExpandLaneC
        // ingress directions: aInvestLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aExpandLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aFireLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aFireLaneB backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 10518U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((aIndex + 10916U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 5802U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8945U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 5613U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6171U)) & S_BLOCK1], 14U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 9248U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 13U) ^ RotL64(aIngress, 60U)) + (RotL64(aPrevious, 47U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterH = (aWandererC + RotL64(aScatter, 41U)) + 13053031069776604052U;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 51U)) + RotL64(aCarry, 37U)) + 1331396630251085122U;
            aOrbiterD = (aWandererB + RotL64(aIngress, 18U)) + 15879286043343942393U;
            aOrbiterK = ((aWandererE + RotL64(aCross, 27U)) + RotL64(aCarry, 47U)) + 13590365633321406830U;
            aOrbiterE = ((((aWandererK + RotL64(aScatter, 47U)) + RotL64(aCarry, 23U)) + 14569235423040242618U) + aPhaseBOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1]) + aNonceWordK;
            aOrbiterG = (aWandererG + RotL64(aPrevious, 35U)) + 11397370636618371560U;
            aOrbiterI = (((aWandererA + RotL64(aCross, 3U)) + 3455933494593971847U) + aPhaseBOrbiterAssignSaltD[((aIndex + 26U)) & S_SALT1]) + aNonceWordM;
            aOrbiterJ = (aWandererH + RotL64(aIngress, 22U)) + 1307153376443784593U;
            aOrbiterB = ((aWandererJ + RotL64(aCross, 13U)) + 10688618762584786871U) + aNonceWordL;
            //
            aOrbiterH = (((aOrbiterH + aOrbiterC) + 17746248451153600096U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordD;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 8512568600755410158U) ^ aNonceWordF;
            aOrbiterD = RotL64((aOrbiterD * 16648320170768234063U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 8950230550112591092U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 17790968369472845496U;
            aOrbiterE = RotL64((aOrbiterE * 5104988920132008913U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 12583323865381967534U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 11243927099685293887U;
            aOrbiterG = RotL64((aOrbiterG * 12867003042486433971U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 9690268715525781389U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 7466066217365074653U;
            aOrbiterK = RotL64((aOrbiterK * 17565696765505320889U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 3673528673209875118U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 14079103852360952255U;
            aOrbiterB = RotL64((aOrbiterB * 17449228863409999629U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 6747836856132250630U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 5027692924422297153U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2492421273167124437U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 11370341866003395776U) + aNonceWordO;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 14013204893442579282U;
            aOrbiterC = RotL64((aOrbiterC * 6602239957997240785U), 39U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterD) + 3436953430697936790U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordC;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 6399073534839993637U;
            aOrbiterJ = RotL64((aOrbiterJ * 14186050072610021241U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 7054057507823631422U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 5752085719673338095U;
            aOrbiterH = RotL64((aOrbiterH * 13252660162476029593U), 35U);
            //
            aIngress = RotL64(aOrbiterE, 11U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterD, 18U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + RotL64(aOrbiterB, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 19U) + aOrbiterH) + RotL64(aOrbiterK, 57U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterB, 51U)) + aOrbiterD);
            aWandererE = aWandererE ^ (((RotL64(aCross, 57U) + aOrbiterK) + RotL64(aOrbiterB, 12U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 24U) + aOrbiterI) + RotL64(aOrbiterJ, 41U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 11U) + aOrbiterC) + RotL64(aOrbiterG, 23U));
            aWandererI = aWandererI + (((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 53U) + aOrbiterI) + RotL64(aOrbiterG, 4U)) + aNonceWordH);
            aWandererC = aWandererC + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 29U)) + aOrbiterD) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 6U) + RotL64(aOrbiterE, 47U)) + aOrbiterC) + aNonceWordA);
            //
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 54U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererA, 23U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aInvestLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 3
        // ingress from: aInvestLaneD, aOperationLaneA, aExpandLaneB
        // ingress directions: aInvestLaneD forward forced, aOperationLaneA forward forced, aExpandLaneB forward/backward random
        // cross from: aInvestLaneC, aOperationLaneC
        // cross directions: aInvestLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneD[((aIndex + 15854U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((aIndex + 11120U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 14229U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 15297U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneC[((aIndex + 15629U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aIngress, 57U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCross, 26U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterA = (((aWandererH + RotL64(aIngress, 35U)) + 4980738603982643969U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordM;
            aOrbiterB = ((aWandererB + RotL64(aCross, 20U)) + 17660278413018470020U) + aNonceWordO;
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 51U)) + 17598114429859543466U) + aNonceWordA;
            aOrbiterF = (aWandererD + RotL64(aScatter, 39U)) + 10993929335279994739U;
            aOrbiterD = ((aWandererG + RotL64(aCross, 47U)) + 17967203122976322481U) + aNonceWordL;
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 13U)) + 1872290205549034384U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = ((aWandererI + RotL64(aScatter, 57U)) + RotL64(aCarry, 5U)) + 16607778671782810797U;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 26U)) + RotL64(aCarry, 29U)) + 4895226930754394376U;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 43U)) + RotL64(aCarry, 13U)) + 14960359005982301383U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 9921642352377700630U) + aNonceWordK;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 893281964367208693U;
            aOrbiterK = RotL64((aOrbiterK * 2345509157333444217U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 8232519988397858732U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 4433022122758913407U;
            aOrbiterD = RotL64((aOrbiterD * 834240393225479419U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 12689609831247168353U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 404535388957472176U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14534020545479806593U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 3349108201964013155U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 4386449511297371730U;
            aOrbiterE = RotL64((aOrbiterE * 9596273264321140229U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 14314587717949070586U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 10923886625271054985U;
            aOrbiterA = RotL64((aOrbiterA * 7838969002623486809U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 17634909585329833520U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 2021301459918350372U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1388242915918642741U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 5219599112498224367U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 10641339455385046206U;
            aOrbiterH = RotL64((aOrbiterH * 1022283727595400719U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 5003342156562330058U) + aNonceWordP;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 10951027475628404336U;
            aOrbiterI = RotL64((aOrbiterI * 17836928292555158461U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 13040991872592235460U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 11149099984302782267U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4248667283139686251U), 57U);
            //
            aIngress = RotL64(aOrbiterG, 27U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 24U));
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterB, 23U));
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 5U)) + aOrbiterK) + aNonceWordH) + aPhaseBWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 37U) + aOrbiterH) + RotL64(aOrbiterB, 51U)) + RotL64(aCarry, 21U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 53U) + aOrbiterI) + RotL64(aOrbiterG, 58U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 46U) + RotL64(aOrbiterA, 19U)) + aOrbiterF) + aNonceWordN);
            aWandererI = aWandererI ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterK, 41U)) + aOrbiterD);
            aWandererD = aWandererD + (((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 14U)) + aOrbiterG) + aNonceWordF);
            aWandererF = aWandererF + ((((RotL64(aCross, 24U) + RotL64(aOrbiterG, 35U)) + aOrbiterF) + aNonceWordJ) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 44U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 18710U)) & S_BLOCK1], 37U) ^ RotL64(aInvestLaneC[((aIndex + 20755U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 20305U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 16432U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneD[((aIndex + 18013U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 44U) ^ RotL64(aCarry, 13U)) + (RotL64(aPrevious, 27U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterD = (aWandererH + RotL64(aPrevious, 39U)) + 1952750591494698524U;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 19U)) + 4488270851303332830U) + aNonceWordC;
            aOrbiterK = (((aWandererG + RotL64(aCross, 60U)) + 2738763375328927635U) + aPhaseBOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1]) + aNonceWordK;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 57U)) + 6728843649480454340U;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 11U)) + RotL64(aCarry, 13U)) + 10490717875258865358U;
            aOrbiterJ = (aWandererF + RotL64(aScatter, 47U)) + 1429288737812910205U;
            aOrbiterI = (((aWandererJ + RotL64(aIngress, 51U)) + 2761375016998907636U) + aPhaseBOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1]) + aNonceWordM;
            aOrbiterE = ((aWandererB + RotL64(aCross, 29U)) + RotL64(aCarry, 41U)) + 1088988605204499835U;
            aOrbiterA = ((aWandererA + RotL64(aIngress, 24U)) + 6829840407300289709U) + aNonceWordE;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 9267240337867690471U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 8120113021183975703U;
            aOrbiterK = RotL64((aOrbiterK * 14296504593187173107U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 1340980511302566784U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 11874452169979878835U;
            aOrbiterB = RotL64((aOrbiterB * 8638486178860092537U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 1872314794140971426U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 6013952618696225751U) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 7994863587373565715U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 3644011378086236002U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 8501867691997891731U;
            aOrbiterG = RotL64((aOrbiterG * 7115282675461711509U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 2493546555198066143U) + aNonceWordH;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 5179240189571799179U;
            aOrbiterJ = RotL64((aOrbiterJ * 1267579130962756135U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 11273348247858394197U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 4577476419423118925U) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 8427261005061162673U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 6201955123046621919U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 3930651302557530185U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1563512534463027965U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 7571426325227856019U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 11098508505512361002U;
            aOrbiterE = RotL64((aOrbiterE * 9229352429618815089U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 6154830144380484305U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 4282054616147137364U;
            aOrbiterI = RotL64((aOrbiterI * 14984813139796280171U), 35U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 51U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + (RotL64(aOrbiterI, 54U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 47U)) + aOrbiterA) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterD, 57U)) + aOrbiterF);
            aWandererD = aWandererD + ((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterA, 35U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 21U) + aOrbiterF) + RotL64(aOrbiterJ, 10U)) + aPhaseBWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 58U) + aOrbiterG) + RotL64(aOrbiterI, 3U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 43U)) + aOrbiterB) + aNonceWordL);
            aWandererG = aWandererG + ((((RotL64(aCross, 29U) + aOrbiterJ) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 5U)) + aNonceWordN);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterB, 20U)) + aNonceWordB);
            aWandererE = aWandererE + ((((RotL64(aScatter, 10U) + aOrbiterJ) + RotL64(aOrbiterE, 39U)) + RotL64(aCarry, 39U)) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 58U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 5
        // ingress from: aWorkLaneB, aInvestLaneD, aFireLaneA
        // ingress directions: aWorkLaneB forward forced, aInvestLaneD forward forced, aFireLaneA forward/backward random
        // cross from: aWorkLaneA, aInvestLaneC
        // cross directions: aWorkLaneA backward forced, aInvestLaneC backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 24957U)) & S_BLOCK1], 41U) ^ RotL64(aInvestLaneD[((aIndex + 27076U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 26532U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23088U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneC[((aIndex + 24120U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 53U)) + (RotL64(aCross, 3U) + RotL64(aIngress, 36U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterI = (aWandererC + RotL64(aScatter, 30U)) + 12262991801139086177U;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 23U)) + 7963038771924890197U) + aNonceWordI;
            aOrbiterD = (aWandererA + RotL64(aIngress, 11U)) + 15540520327933568896U;
            aOrbiterC = (((aWandererF + RotL64(aCross, 3U)) + 8745565892055020722U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterG = (aWandererH + RotL64(aPrevious, 51U)) + 16619329199683755286U;
            aOrbiterF = (aWandererB + RotL64(aCross, 41U)) + 10865705026433867260U;
            aOrbiterA = (((aWandererK + RotL64(aScatter, 19U)) + RotL64(aCarry, 39U)) + 2743368697984518059U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aIngress, 46U)) + RotL64(aCarry, 11U)) + 5556006271515473135U;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 37U)) + RotL64(aCarry, 57U)) + 5355833281353498588U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 8313616108963479829U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 16657121016801866434U;
            aOrbiterD = RotL64((aOrbiterD * 331533349428472477U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 16532226425013000833U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 5800465874932467232U;
            aOrbiterG = RotL64((aOrbiterG * 5966395771690704577U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 17882948163883121328U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 15029375310296563175U;
            aOrbiterC = RotL64((aOrbiterC * 17021415832288477713U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 10170682648007918739U) + aNonceWordH;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 11829089574189398773U) ^ aNonceWordM;
            aOrbiterE = RotL64((aOrbiterE * 15755874363488568849U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 1746524867389196322U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 10217423427886742775U;
            aOrbiterA = RotL64((aOrbiterA * 9166162099575333519U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 1338457710729082656U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 1319981417675542556U;
            aOrbiterH = RotL64((aOrbiterH * 9518448254565489715U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 3985281993069194761U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 7281264481139915593U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13498446162967276739U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 17394503335338855566U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 1430703546991948227U;
            aOrbiterI = RotL64((aOrbiterI * 1623206122475721175U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 472559435062214929U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 8065899137826178995U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13287499768933229539U), 3U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterF, 43U);
            aIngress = aIngress + (RotL64(aOrbiterI, 39U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterG, 34U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 47U)) + aOrbiterF) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterC, 11U)) + aOrbiterF) + aNonceWordD) + aPhaseBWandererUpdateSaltA[((aIndex + 12U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 42U) + aOrbiterF) + RotL64(aOrbiterA, 43U)) + RotL64(aCarry, 35U)) + aNonceWordG);
            aWandererG = aWandererG ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterC, 60U)) + aOrbiterB);
            aWandererF = aWandererF + ((RotL64(aIngress, 37U) + aOrbiterE) + RotL64(aOrbiterI, 27U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 23U) + aOrbiterC) + RotL64(aOrbiterG, 35U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 6U) + RotL64(aOrbiterH, 23U)) + aOrbiterD) + aNonceWordL);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 51U)) + aOrbiterD);
            aWandererJ = aWandererJ + (((RotL64(aCross, 27U) + aOrbiterH) + RotL64(aOrbiterE, 18U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 42U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 19U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 6
        // ingress from: aWorkLaneC, aWorkLaneA, aFireLaneC
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aFireLaneC forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 29043U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneA[((aIndex + 32558U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 29493U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30595U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32068U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 18U) ^ RotL64(aCarry, 5U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterJ = (((aWandererC + RotL64(aCross, 11U)) + RotL64(aCarry, 13U)) + 7722279280863371124U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aIngress, 29U)) + RotL64(aCarry, 39U)) + 11584220561732385598U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 56U)) + 7834679350105534657U;
            aOrbiterB = (((aWandererJ + RotL64(aPrevious, 47U)) + RotL64(aCarry, 57U)) + 11347994382444180879U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aCross, 21U)) + 9449903188047063431U;
            aOrbiterH = (aWandererB + RotL64(aScatter, 3U)) + 6516243976652795170U;
            aOrbiterF = (aWandererK + RotL64(aPrevious, 51U)) + 8420815253991184777U;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 41U)) + 9081386852515170937U) + aNonceWordB;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 34U)) + 14375955191735286867U) + aNonceWordO;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 880757589768436072U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 3349856625725164229U;
            aOrbiterA = RotL64((aOrbiterA * 681514212582331781U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 7826309957607577207U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 8057435761214313635U;
            aOrbiterC = RotL64((aOrbiterC * 4718430712767038607U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 9565237500443303103U) + aNonceWordP;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 15893066735310588501U;
            aOrbiterF = RotL64((aOrbiterF * 8457633439171452397U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 3276844534476430842U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 6828644383891274120U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 979580351653410157U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 2815676923011504251U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 5030251870850928417U;
            aOrbiterJ = RotL64((aOrbiterJ * 7075653570570819253U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 13464083008377887034U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 8994560761846897590U;
            aOrbiterK = RotL64((aOrbiterK * 9892839554658865143U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 8398813387154468736U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 8136429428340910892U;
            aOrbiterH = RotL64((aOrbiterH * 3348811490733577295U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 418587250696862341U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 4111667833838312094U;
            aOrbiterE = RotL64((aOrbiterE * 860949442143849147U), 57U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterK) + 6075478294190926371U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 2208124955874142264U;
            aOrbiterB = RotL64((aOrbiterB * 15741988616251072075U), 47U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 47U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 54U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 43U));
            aIngress = aIngress + RotL64(aOrbiterB, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 19U)) + aNonceWordC);
            aWandererE = aWandererE ^ ((RotL64(aCross, 47U) + aOrbiterC) + RotL64(aOrbiterK, 39U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 43U) + RotL64(aOrbiterI, 30U)) + aOrbiterK);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterB, 11U)) + aOrbiterC);
            aWandererC = aWandererC + ((((RotL64(aScatter, 18U) + RotL64(aOrbiterE, 23U)) + aOrbiterA) + aNonceWordH) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterC, 43U)) + aOrbiterJ) + aNonceWordF);
            aWandererF = aWandererF + ((RotL64(aPrevious, 39U) + aOrbiterA) + RotL64(aOrbiterB, 57U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 23U) + aOrbiterH) + RotL64(aOrbiterC, 52U));
            aWandererH = aWandererH + ((((RotL64(aScatter, 58U) + RotL64(aOrbiterH, 3U)) + aOrbiterF) + RotL64(aCarry, 43U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 20U));
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererF, 39U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_Karate_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xC1F7B3DDE51D3A99ULL + 0xFD0B6F6BAA51DDF2ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xB323AEF9F5739137ULL + 0x8596E79AB0828024ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xE639B881FB090505ULL + 0xC12CACC93F296F4AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xB7DAF6477D160379ULL + 0xDB0B7231D5FB0AA2ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xB4003D1CB0058C6FULL + 0xDADB727CD7219749ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xA23A1578AD2FA013ULL + 0xC305D9F4D572D99BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xA385680415B92DC1ULL + 0xB1218E6C14F4FECAULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x8CEF7C10E953C7A9ULL + 0xABBD47FA8F6C89BAULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xD34D1ADEB0F2B0DBULL + 0xB00FF3ECE005EE5BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xDA076E5ABD5D5011ULL + 0xB9A2EAE3996703B5ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x983EB5628B5596A7ULL + 0xA2E1C200DD6F279FULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xB21E73D1FA41371BULL + 0xF10C7EEBC997B0ADULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x8BD8FAAA686D817DULL + 0xD2BC891061E86681ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xE1CFD9486FB58551ULL + 0xB670A359FC005017ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xF7DC7081832E8167ULL + 0xF0729B9F0977C7ADULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x96004BF7CFD1D451ULL + 0xE93A45C8C29F187BULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 423U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneB[((aIndex + 3693U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 1205U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4394U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 2758U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 4567U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aIngress, 38U)) + (RotL64(aCross, 51U) ^ RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterD = (aWandererA + RotL64(aIngress, 12U)) + 3621877681473089725U;
            aOrbiterE = (((aWandererC + RotL64(aPrevious, 57U)) + RotL64(aCarry, 29U)) + 4451752751536414717U) + aNonceWordE;
            aOrbiterI = ((aWandererG + RotL64(aCross, 3U)) + RotL64(aCarry, 3U)) + 11371625415377772117U;
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 37U)) + RotL64(aCarry, 43U)) + 6046792758881150619U;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 21U)) + 8213166120394461682U;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 47U)) + 4343156661140422645U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = (((aWandererK + RotL64(aScatter, 29U)) + 11105271483234947905U) + aPhaseDOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1]) + aNonceWordD;
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 348904609985341372U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 12924652822526858767U) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 2801892489296408735U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 7461211697358520287U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 16551553555297890558U;
            aOrbiterG = RotL64((aOrbiterG * 16432952324635746293U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 11908056404140782995U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 9147367258259948715U) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 10777628928376261667U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 8876461054692728610U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 10546855952702525404U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10071104785895309677U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 4748636139110443794U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 783046909529525098U;
            aOrbiterB = RotL64((aOrbiterB * 8969157702460927215U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 16683965945838696665U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 12385412690177109575U;
            aOrbiterE = RotL64((aOrbiterE * 10795062772707143187U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 8210546822184469023U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 13146493623236979963U;
            aOrbiterJ = RotL64((aOrbiterJ * 13199947810161148155U), 43U);
            //
            aIngress = RotL64(aOrbiterI, 60U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + RotL64(aOrbiterG, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 46U) + RotL64(aOrbiterE, 60U)) + aOrbiterD) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterE, 39U));
            aWandererK = aWandererK + (((((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 3U)) + aOrbiterH) + RotL64(aCarry, 41U)) + aNonceWordL) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 39U) + aOrbiterH) + RotL64(aOrbiterE, 13U)) + aNonceWordP);
            aWandererE = aWandererE + ((RotL64(aScatter, 53U) + aOrbiterE) + RotL64(aOrbiterB, 19U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 47U)) + aOrbiterI) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 21U) + aOrbiterD) + RotL64(aOrbiterI, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 60U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 5974U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((aIndex + 10394U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 7246U)) & S_BLOCK1], 57U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 6254U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 5979U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10758U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 9982U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 6U) + RotL64(aCarry, 21U)) ^ (RotL64(aCross, 35U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterK = ((aWandererD + RotL64(aCross, 21U)) + RotL64(aCarry, 57U)) + 5171470532667965920U;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 27U)) + 750549462358682403U) + aNonceWordO;
            aOrbiterA = (((aWandererB + RotL64(aScatter, 41U)) + RotL64(aCarry, 43U)) + 3325689257577120525U) + aPhaseDOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = (((aWandererG + RotL64(aPrevious, 57U)) + RotL64(aCarry, 19U)) + 18031575461559790826U) + aPhaseDOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = (aWandererC + RotL64(aCross, 13U)) + 13874739537012288677U;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 48U)) + 4250029868785016865U) + aNonceWordH;
            aOrbiterB = (aWandererI + RotL64(aIngress, 3U)) + 8211158803112611161U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 1083939790236786027U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 3446525462376962464U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13603702473750888213U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 6973817815000417325U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 15230876489676945543U) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 7737039082964537651U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 9359727659738755880U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 8775170107816327654U;
            aOrbiterD = RotL64((aOrbiterD * 6910680458261008653U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 11958941755525038545U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 16966819714283167348U;
            aOrbiterB = RotL64((aOrbiterB * 16363457661846050749U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 14556087985619763243U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 17915047508377045221U;
            aOrbiterE = RotL64((aOrbiterE * 6727635453185130109U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 8578745677485367222U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 7002181668717618866U) ^ aNonceWordE;
            aOrbiterF = RotL64((aOrbiterF * 12329703532414955235U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 3569939503066735457U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 2956247934282522184U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9946650822131152531U), 29U);
            //
            aIngress = RotL64(aOrbiterB, 35U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterA, 28U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 37U) + aOrbiterC) + RotL64(aOrbiterA, 44U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 11U) + aOrbiterK) + RotL64(aOrbiterD, 5U));
            aWandererI = aWandererI + (((RotL64(aIngress, 4U) + RotL64(aOrbiterB, 23U)) + aOrbiterC) + RotL64(aCarry, 37U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 53U) + aOrbiterB) + RotL64(aOrbiterD, 53U)) + aNonceWordL);
            aWandererB = aWandererB + (((RotL64(aCross, 47U) + RotL64(aOrbiterA, 35U)) + aOrbiterB) + aNonceWordK);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 23U) + aOrbiterE) + RotL64(aOrbiterF, 13U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 53U)) + aPhaseDWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 6U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + RotL64(aWandererD, 43U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 12001U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((aIndex + 14763U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 13207U)) & S_BLOCK1], 10U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 13199U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15788U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCarry, 54U)) ^ (RotL64(aPrevious, 41U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterG = (((aWandererE + RotL64(aCross, 57U)) + RotL64(aCarry, 19U)) + 8975885703279267062U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aIngress, 43U)) + RotL64(aCarry, 57U)) + 8664844915562660637U;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 13U)) + 12281774799736296726U) + aNonceWordP;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 29U)) + 15347461352311329726U;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 20U)) + RotL64(aCarry, 5U)) + 12967500561828907834U;
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 3U)) + 5002833859280402726U;
            aOrbiterC = (((aWandererK + RotL64(aCross, 35U)) + 11908257536954668983U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 17017174811949227162U) + aNonceWordH;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 16851323125613931180U;
            aOrbiterK = RotL64((aOrbiterK * 12446990992858763577U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 13469326957728686706U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 5228638551056105241U;
            aOrbiterJ = RotL64((aOrbiterJ * 13369947664646167255U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 11945166198089308564U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 16268645041872996022U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5391448793718370911U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 14781204627695095701U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 5365325354838101092U;
            aOrbiterI = RotL64((aOrbiterI * 8017284997946310807U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 563147416025715953U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 14660867395395625851U;
            aOrbiterE = RotL64((aOrbiterE * 4769458126865307103U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 3168989056355712105U) + aNonceWordM;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 16179131669773665579U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5641461617066671723U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 4160220074225527179U) + aNonceWordL;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 8597134686962559111U;
            aOrbiterC = RotL64((aOrbiterC * 639572585431474015U), 13U);
            //
            aIngress = RotL64(aOrbiterJ, 57U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 27U) + aOrbiterJ) + RotL64(aOrbiterH, 5U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 3U) + RotL64(aOrbiterI, 47U)) + aOrbiterH) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 37U) + aOrbiterJ) + RotL64(aOrbiterE, 29U)) + aNonceWordJ);
            aWandererD = aWandererD + (((((RotL64(aScatter, 13U) + aOrbiterE) + RotL64(aOrbiterC, 23U)) + RotL64(aCarry, 3U)) + aNonceWordG) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterE, 37U)) + aOrbiterK);
            aWandererG = aWandererG + (((RotL64(aIngress, 52U) + aOrbiterH) + RotL64(aOrbiterG, 53U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterI, 12U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 46U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 5U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 20236U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneA[((aIndex + 16621U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 18052U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 20405U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((aIndex + 20761U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aIngress, 4U)) ^ (RotL64(aCarry, 37U) + RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterJ = (((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 51U)) + 18255347001097480328U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = (((aWandererK + RotL64(aScatter, 41U)) + RotL64(aCarry, 23U)) + 13679246790311505735U) + aNonceWordL;
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 60U)) + 10565839529765027116U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 35U)) + RotL64(aCarry, 11U)) + 14327172566224769901U;
            aOrbiterG = (aWandererE + RotL64(aPrevious, 53U)) + 16239024612038195174U;
            aOrbiterE = ((aWandererI + RotL64(aScatter, 19U)) + 13800012174212131890U) + aNonceWordA;
            aOrbiterH = (((aWandererH + RotL64(aIngress, 13U)) + 13900288860157577583U) + aPhaseDOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1]) + aNonceWordF;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 4144386119777112740U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 3154558262670631372U;
            aOrbiterD = RotL64((aOrbiterD * 13236911910092437063U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 7456728543137614001U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 11709519851158935384U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7016689518570071587U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 15607438907832240304U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 9276575329661725624U;
            aOrbiterB = RotL64((aOrbiterB * 8879744070762412745U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 6459435969129449226U) + aNonceWordM;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 6442382118416542275U;
            aOrbiterJ = RotL64((aOrbiterJ * 2921027306686588233U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 12117432107282150865U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 6831279293184793243U) ^ aNonceWordN;
            aOrbiterG = RotL64((aOrbiterG * 2435360641135249073U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 9520022957804572889U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 8322178689474588679U;
            aOrbiterH = RotL64((aOrbiterH * 1627707191467537115U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 4162401591586869316U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 8994015844714895961U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15421910378057951895U), 39U);
            //
            aIngress = RotL64(aOrbiterG, 23U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + RotL64(aOrbiterE, 52U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 41U)) + aOrbiterG) + aPhaseDWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 57U)) + aOrbiterJ) + aPhaseDWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 37U) + aOrbiterF) + RotL64(aOrbiterE, 5U)) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 26U) + RotL64(aOrbiterF, 51U)) + aOrbiterB) + aNonceWordE);
            aWandererI = aWandererI + ((((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 12U)) + aOrbiterH) + RotL64(aCarry, 37U)) + aNonceWordP);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 11U) + aOrbiterG) + RotL64(aOrbiterB, 27U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 43U) + aOrbiterH) + RotL64(aOrbiterG, 21U)) + aNonceWordO);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 34U));
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererI, 51U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 23027U)) & S_BLOCK1], 35U) ^ RotL64(aSnowLaneB[((aIndex + 24116U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 24182U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 23719U)) & S_BLOCK1], 39U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 22681U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 34U) ^ RotL64(aPrevious, 3U)) + (RotL64(aCross, 19U) + RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterG = (aWandererJ + RotL64(aScatter, 5U)) + 12775735908960052604U;
            aOrbiterI = (((aWandererD + RotL64(aIngress, 29U)) + RotL64(aCarry, 53U)) + 11791373812080296887U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = ((((aWandererC + RotL64(aPrevious, 11U)) + RotL64(aCarry, 19U)) + 5537362877706057303U) + aPhaseDOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1]) + aNonceWordC;
            aOrbiterE = (((aWandererG + RotL64(aCross, 47U)) + RotL64(aCarry, 39U)) + 2023912048504189380U) + aNonceWordM;
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 35U)) + 17668828109963766893U;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 53U)) + 558908629933941224U) + aNonceWordI;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 60U)) + 1479633119685446888U) + aNonceWordD;
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 15460320397843364063U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 10059749397555469054U) ^ aNonceWordP;
            aOrbiterH = RotL64((aOrbiterH * 8671817118586065469U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 9987633811929693924U) + aNonceWordN;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 10087337844580228269U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13817142288940843815U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 4446204415503364254U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 15106063243302192717U;
            aOrbiterD = RotL64((aOrbiterD * 13273756657334709803U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 9430197906134676162U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 1226048679997253363U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14247538885252664127U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 10611580584157624739U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 3137391249289641509U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5462682413239873181U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 9327201928815412810U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 7890659377013147073U;
            aOrbiterE = RotL64((aOrbiterE * 13827717178378062047U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 10675114832750356941U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 8804440385852327267U;
            aOrbiterK = RotL64((aOrbiterK * 8520671775587260601U), 39U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 57U);
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + RotL64(aOrbiterE, 50U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 21U) + aOrbiterJ) + RotL64(aOrbiterE, 3U));
            aWandererH = aWandererH + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 47U)) + aOrbiterG) + RotL64(aCarry, 21U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 47U) + aOrbiterI) + RotL64(aOrbiterD, 60U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 6U) + aOrbiterG) + RotL64(aOrbiterH, 23U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 29U)) + aOrbiterG) + aNonceWordL);
            aWandererG = aWandererG + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 13U)) + aOrbiterI) + RotL64(aCarry, 43U)) + aNonceWordF);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterD, 35U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 36U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 32691U)) & S_BLOCK1], 29U) ^ RotL64(aInvestLaneA[((aIndex + 29087U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 30174U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 29470U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32730U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCross, 60U)) + (RotL64(aCarry, 47U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterF = (((aWandererB + RotL64(aCross, 35U)) + 17912271996338180948U) + aPhaseDOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1]) + aNonceWordI;
            aOrbiterI = (((aWandererG + RotL64(aPrevious, 19U)) + RotL64(aCarry, 57U)) + 13259276608841847058U) + aNonceWordC;
            aOrbiterH = (((aWandererE + RotL64(aScatter, 11U)) + RotL64(aCarry, 5U)) + 16225936008657276089U) + aPhaseDOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = (((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 35U)) + 2243058962151834071U) + aNonceWordN;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 51U)) + 10637439274127347861U) + aNonceWordD;
            aOrbiterE = (aWandererD + RotL64(aScatter, 27U)) + 15312219216405992627U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 42U)) + 2393933972129878613U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 4327069337247976513U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 8307656353434167837U;
            aOrbiterH = RotL64((aOrbiterH * 11386588389133096705U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 17299145556933889336U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 14458100581172798164U) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 16543734663677070509U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 6410095654927998067U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 6168964796264687686U) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 16218071040190475953U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 3667999465041020730U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterB) ^ 16021552859323602007U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterG = RotL64((aOrbiterG * 6427266472526362663U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 12941668202330045095U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 4222032891850449934U;
            aOrbiterE = RotL64((aOrbiterE * 17292856787431308097U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 1346342592002730785U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 16860611785008118820U;
            aOrbiterB = RotL64((aOrbiterB * 384963420804756607U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 3193572711804730241U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 5866881282680588589U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9226331800853634597U), 3U);
            //
            aIngress = RotL64(aOrbiterB, 11U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + (RotL64(aOrbiterF, 44U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterH, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 3U)) + aOrbiterH) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 27U) + aOrbiterE) + RotL64(aOrbiterG, 37U)) + RotL64(aCarry, 47U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterK, 19U)) + aOrbiterI) + aNonceWordO);
            aWandererE = aWandererE + (((RotL64(aCross, 50U) + RotL64(aOrbiterF, 43U)) + aOrbiterH) + RotL64(aCarry, 21U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 21U) + aOrbiterE) + RotL64(aOrbiterB, 27U)) + aNonceWordL);
            aWandererF = aWandererF + (((RotL64(aCross, 5U) + RotL64(aOrbiterE, 57U)) + aOrbiterI) + aNonceWordB);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterG, 12U)) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 52U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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

void TwistExpander_Karate_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x9F7F13846D8E12BBULL + 0xB17AB7D6374D4F19ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xFD81CC302F631BD5ULL + 0x91162E5B546B7DB5ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xDEC0A3F19F966B7FULL + 0xBA61B3DF446E85A4ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xA12F3800BF3ED43BULL + 0x8FBC51B55FC37D39ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x9ACBF339B7DCB1FBULL + 0x8BFE8DD37FEEA153ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xAAB34474EB7AB673ULL + 0x9C46CC1C01C1A374ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x903EE9489E6B9EA7ULL + 0x859E52911BF9BC09ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xBACE9742E9A23BB5ULL + 0x8DD83BC8C8AAE6B9ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xF47D090278927085ULL + 0xDAA2F9A30FF49FE2ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x8FBEAFC503394015ULL + 0x869A116A115CEB87ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xCFE9900B596E4B45ULL + 0xD98B604B6933B20AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x829A7D045DEF15DDULL + 0x8ECAE9B462D8848EULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xB49EF1D976BA2A03ULL + 0xB7904B16C7358765ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x9A28D7C647991CB1ULL + 0xC7A8B7E6ED9D60F6ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xB3A996FC3D5179DDULL + 0xCAD8EDD7D64ACEB7ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xC29B991A8A6E992DULL + 0xC99610F45A505EFDULL);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 2460U)) & S_BLOCK1], 30U) ^ RotL64(aInvestLaneB[((aIndex + 4123U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 5425U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 3899U)) & S_BLOCK1], 27U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 3698U)) & S_BLOCK1], 12U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 2516U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 48U) ^ RotL64(aIngress, 5U)) + (RotL64(aPrevious, 35U) + RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 39U)) + 4970414922752555648U) + aPhaseEOrbiterAssignSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = ((aWandererC + RotL64(aIngress, 27U)) + RotL64(aCarry, 27U)) + 9462756592787669327U;
            aOrbiterE = (aWandererF + RotL64(aCross, 51U)) + 3948790686662213095U;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 34U)) + 14542857212241578311U) + aNonceWordO;
            aOrbiterF = ((aWandererH + RotL64(aCross, 11U)) + 3387479009827029547U) + aNonceWordH;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 19U)) + 1411421370057797877U) + aNonceWordD;
            aOrbiterA = (aWandererB + RotL64(aIngress, 37U)) + 16894451466895681236U;
            aOrbiterH = (aWandererG + RotL64(aScatter, 14U)) + 12727136462290223542U;
            aOrbiterG = (((aWandererA + RotL64(aCross, 29U)) + RotL64(aCarry, 19U)) + 4625389198191960525U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 47U)) + RotL64(aCarry, 43U)) + 3471881403786164913U;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 23U)) + 6433115856048534831U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 9825592965466157982U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 1553125767261293088U;
            aOrbiterE = RotL64((aOrbiterE * 411535191177308781U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 9951616357109647617U) + aNonceWordF;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 11231080382787286889U;
            aOrbiterI = RotL64((aOrbiterI * 14024961994986659187U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 13419663264017317947U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 4835055642466215566U;
            aOrbiterH = RotL64((aOrbiterH * 17898065852351759171U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 14558747666410946768U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 13120938960926874504U;
            aOrbiterG = RotL64((aOrbiterG * 5681766019285559739U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 11910501376797343986U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 15074100100781785300U;
            aOrbiterB = RotL64((aOrbiterB * 228976960937473851U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 12415377930578091821U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 14882039078390681802U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13855446647753150713U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 8094338361713756895U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 5478280604704108822U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 18062931724700600993U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 6977017654546871841U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterI) ^ 4131602217285988962U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 11865422227883712419U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 9619228479582032318U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 13506679497441415586U;
            aOrbiterK = RotL64((aOrbiterK * 5789932662418992799U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 10180259475831448124U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 4721628773773094283U;
            aOrbiterD = RotL64((aOrbiterD * 10834196399754443771U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 7898137727558813688U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 4970414922752555648U;
            aOrbiterF = RotL64((aOrbiterF * 6651835668618579479U), 29U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterC, 60U);
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 21U) + aOrbiterJ) + RotL64(aOrbiterD, 5U)) + aNonceWordK);
            aWandererB = aWandererB + (((RotL64(aCross, 53U) + aOrbiterH) + RotL64(aOrbiterK, 60U)) + aNonceWordB);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 23U) + aOrbiterH) + RotL64(aOrbiterC, 53U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 39U)) + aOrbiterD) + aPhaseEWandererUpdateSaltA[((aIndex + 12U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterG, 19U)) + aOrbiterH) + aNonceWordA);
            aWandererC = aWandererC + (((RotL64(aPrevious, 46U) + RotL64(aOrbiterE, 44U)) + aOrbiterA) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 51U) + aOrbiterB) + RotL64(aOrbiterF, 37U));
            aWandererF = aWandererF + ((RotL64(aScatter, 41U) + RotL64(aOrbiterK, 13U)) + aOrbiterB);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 47U)) + aOrbiterJ);
            aWandererG = aWandererG + ((((RotL64(aCross, 12U) + aOrbiterJ) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 21U)) + aNonceWordJ);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterF, 51U)) + aPhaseEWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 44U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererA, 42U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aFireLaneA[((aIndex + 9542U)) & S_BLOCK1], 21U) ^ RotL64(aInvestLaneC[((aIndex + 8272U)) & S_BLOCK1], 39U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 6252U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10876U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 10598U)) & S_BLOCK1], 28U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 7822U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 6512U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 37U) ^ RotL64(aCarry, 5U)) ^ (RotL64(aCross, 51U) + RotL64(aPrevious, 22U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterK = ((aWandererG + RotL64(aScatter, 54U)) + RotL64(aCarry, 19U)) + 7075016829833562104U;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 39U)) + 8783765886115517036U;
            aOrbiterG = ((aWandererC + RotL64(aCross, 5U)) + 2996723892384565829U) + aNonceWordP;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 57U)) + 9494134707342189476U;
            aOrbiterF = ((aWandererI + RotL64(aCross, 11U)) + 5052642981395679904U) + aPhaseEOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = (((aWandererB + RotL64(aIngress, 3U)) + RotL64(aCarry, 43U)) + 8766787055127962238U) + aNonceWordB;
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 60U)) + RotL64(aCarry, 3U)) + 4467211954388738079U;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 19U)) + 8030255604633658608U) + aNonceWordI;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 43U)) + 16962408063455702251U) + aNonceWordN;
            aOrbiterA = (aWandererK + RotL64(aCross, 27U)) + 3768222186567699076U;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 13U)) + 14930990410207899871U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 14179761938395502502U) + aNonceWordF;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 1879084742719898108U;
            aOrbiterG = RotL64((aOrbiterG * 16783034788172670121U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 5535012408925981515U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 12792553516710295939U;
            aOrbiterF = RotL64((aOrbiterF * 8577530993755159329U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 8979253163346099252U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 5559189896063990740U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8832485423727331621U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 13937564337299044079U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 2393376759689394948U;
            aOrbiterB = RotL64((aOrbiterB * 2352815657830413941U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 12647519563697356479U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 10946871249960389549U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6272580371881237173U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 13376798695582123147U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 10958115913599631271U) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 18233981473003345217U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 4283914227806672773U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 910842005516235816U;
            aOrbiterJ = RotL64((aOrbiterJ * 6722229871617873429U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 1509644316619370324U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 165987596716078174U;
            aOrbiterC = RotL64((aOrbiterC * 13600064054240185123U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 12491315345199091186U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 5982431705686495125U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2547243804779022665U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 231183123382412440U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 2872632389683254396U) ^ aNonceWordH;
            aOrbiterI = RotL64((aOrbiterI * 1972278820468847241U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 15259314110008210315U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 7075016829833562104U;
            aOrbiterE = RotL64((aOrbiterE * 8350093877370898869U), 51U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 11U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 14U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 53U)) + aOrbiterE) + aNonceWordK);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterB, 37U));
            aWandererK = aWandererK + (((((RotL64(aScatter, 53U) + aOrbiterJ) + RotL64(aOrbiterK, 20U)) + RotL64(aCarry, 21U)) + aNonceWordO) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 50U) + aOrbiterF) + RotL64(aOrbiterJ, 41U));
            aWandererI = aWandererI + ((RotL64(aScatter, 21U) + aOrbiterB) + RotL64(aOrbiterJ, 27U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterF, 3U)) + aOrbiterD);
            aWandererC = aWandererC + ((((RotL64(aCross, 41U) + RotL64(aOrbiterE, 5U)) + aOrbiterG) + RotL64(aCarry, 53U)) + aNonceWordA);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 39U) + aOrbiterD) + RotL64(aOrbiterC, 24U));
            aWandererB = aWandererB + (((RotL64(aIngress, 19U) + RotL64(aOrbiterA, 51U)) + aOrbiterD) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 30U) + RotL64(aOrbiterA, 13U)) + aOrbiterF);
            aWandererE = aWandererE + ((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 35U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 54U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererD, 39U);
            aCarry = aCarry + RotL64(aIngress, 24U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 13900U)) & S_BLOCK1], 27U) ^ RotL64(aInvestLaneA[((aIndex + 11098U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 15708U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 14531U)) & S_BLOCK1], 12U) ^ RotL64(aInvestLaneC[((aIndex + 13419U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 43U) ^ RotL64(aIngress, 27U)) + (RotL64(aPrevious, 13U) + RotL64(aCarry, 60U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterD = ((aWandererI + RotL64(aIngress, 11U)) + RotL64(aCarry, 57U)) + 17081642665820489793U;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 19U)) + 14468854040067229623U) + aNonceWordB;
            aOrbiterE = (((aWandererH + RotL64(aCross, 24U)) + 2249450222593057429U) + aPhaseEOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1]) + aNonceWordA;
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 5U)) + 14964389079511378664U) + aNonceWordP;
            aOrbiterK = (aWandererB + RotL64(aIngress, 51U)) + 17003491054252360650U;
            aOrbiterA = ((aWandererF + RotL64(aCross, 47U)) + RotL64(aCarry, 35U)) + 12710882240582032588U;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 41U)) + RotL64(aCarry, 47U)) + 9887078182156755359U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 29U)) + 7665284531810584704U) + aPhaseEOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = (aWandererA + RotL64(aIngress, 43U)) + 7304284015511876717U;
            aOrbiterC = (aWandererG + RotL64(aScatter, 39U)) + 5517927023543751734U;
            aOrbiterF = (aWandererD + RotL64(aPrevious, 60U)) + 17704756310857362759U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 11347400363019508578U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 11696395232760991243U;
            aOrbiterE = RotL64((aOrbiterE * 9725231749679442003U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 10875780291242873583U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 7808740614343437672U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8889516201913716283U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 3145390996141902032U) + aNonceWordJ;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 16080636485642732615U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7445756373012217305U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 3929263288176983844U) + aNonceWordF;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 18210228766683996806U;
            aOrbiterK = RotL64((aOrbiterK * 13178080076505449091U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 13948962323541421431U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 3037683309790156893U;
            aOrbiterH = RotL64((aOrbiterH * 13406672352222636739U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 17827265198532699474U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 7270895262023504864U;
            aOrbiterJ = RotL64((aOrbiterJ * 13467417362477308167U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 6431243064980879185U) + aNonceWordD;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 6680205390976259885U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10421386694108590789U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 15910655919164357152U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 8046213498216027383U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 18061867495824063553U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 2521111689480478597U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 13892876610454681741U;
            aOrbiterG = RotL64((aOrbiterG * 17776392934374483875U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 16009217514890880809U) + aNonceWordH;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 1221573458193626679U;
            aOrbiterB = RotL64((aOrbiterB * 73477765605619369U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 9275704218554025797U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 17081642665820489793U;
            aOrbiterC = RotL64((aOrbiterC * 5613316790159527375U), 23U);
            //
            aIngress = RotL64(aOrbiterK, 39U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 48U));
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterG, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 56U) + RotL64(aOrbiterK, 19U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 21U)) + aOrbiterG) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 37U)) + aOrbiterF);
            aWandererD = aWandererD + ((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterF, 14U));
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterG, 3U)) + aNonceWordN) + aPhaseEWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aCross, 13U) + RotL64(aOrbiterG, 11U)) + aOrbiterC) + RotL64(aCarry, 13U)) + aPhaseEWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 21U) + aOrbiterH) + RotL64(aOrbiterD, 35U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterC, 47U)) + aOrbiterJ);
            aWandererB = aWandererB ^ ((RotL64(aCross, 40U) + aOrbiterK) + RotL64(aOrbiterE, 26U));
            aWandererF = aWandererF + (((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 29U)) + aOrbiterF) + aNonceWordK);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 11U) + aOrbiterI) + RotL64(aOrbiterA, 23U)) + aNonceWordG);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (RotL64(aWandererI, 52U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 46U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 19290U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneA[((aIndex + 18392U)) & S_BLOCK1], 20U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 18240U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 18975U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 16911U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCross, 4U)) ^ (RotL64(aCarry, 51U) + RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterI = (aWandererD + RotL64(aIngress, 53U)) + 12262991801139086177U;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 58U)) + 7963038771924890197U) + aNonceWordE;
            aOrbiterH = (aWandererB + RotL64(aCross, 41U)) + 15540520327933568896U;
            aOrbiterK = (((aWandererE + RotL64(aScatter, 29U)) + RotL64(aCarry, 41U)) + 8745565892055020722U) + aNonceWordI;
            aOrbiterF = ((aWandererH + RotL64(aCross, 43U)) + RotL64(aCarry, 13U)) + 16619329199683755286U;
            aOrbiterA = ((aWandererF + RotL64(aScatter, 37U)) + 10865705026433867260U) + aNonceWordH;
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 3U)) + 2743368697984518059U) + aPhaseEOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aPrevious, 50U)) + 5556006271515473135U;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 13U)) + 5355833281353498588U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 21U)) + RotL64(aCarry, 57U)) + 8313616108963479829U;
            aOrbiterC = (aWandererK + RotL64(aIngress, 35U)) + 16657121016801866434U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 16532226425013000833U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 5800465874932467232U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5966395771690704577U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 17882948163883121328U) + aNonceWordO;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 15029375310296563175U;
            aOrbiterA = RotL64((aOrbiterA * 17021415832288477713U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 10170682648007918739U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 11829089574189398773U;
            aOrbiterG = RotL64((aOrbiterG * 15755874363488568849U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 1746524867389196322U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 10217423427886742775U;
            aOrbiterE = RotL64((aOrbiterE * 9166162099575333519U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 1338457710729082656U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 1319981417675542556U;
            aOrbiterB = RotL64((aOrbiterB * 9518448254565489715U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 3985281993069194761U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 7281264481139915593U;
            aOrbiterD = RotL64((aOrbiterD * 13498446162967276739U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 17394503335338855566U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 1430703546991948227U;
            aOrbiterF = RotL64((aOrbiterF * 1623206122475721175U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 472559435062214929U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 8065899137826178995U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13287499768933229539U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 3377996409668333322U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 10456089146891981998U;
            aOrbiterJ = RotL64((aOrbiterJ * 12037044781049717633U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 5246784368779537905U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 8518987022368391332U;
            aOrbiterI = RotL64((aOrbiterI * 4046763804695058779U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 7791883487780325967U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 12262991801139086177U) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 3409890579914160747U), 13U);
            //
            aIngress = RotL64(aOrbiterI, 4U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 44U) + RotL64(aOrbiterB, 20U)) + aOrbiterG);
            aWandererK = aWandererK + ((RotL64(aScatter, 53U) + aOrbiterA) + RotL64(aOrbiterG, 41U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterJ, 51U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 23U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterD, 27U)) + aOrbiterK) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 6U) + aOrbiterC) + RotL64(aOrbiterF, 35U)) + RotL64(aCarry, 3U)) + aNonceWordL);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterE, 14U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 39U) + aOrbiterI) + RotL64(aOrbiterD, 53U)) + aNonceWordK);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 21U) + aOrbiterF) + RotL64(aOrbiterE, 29U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterD, 47U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 37U) + aOrbiterC) + RotL64(aOrbiterH, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 50U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 48U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 23163U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneB[((aIndex + 23938U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 24461U)) & S_BLOCK1], 18U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25277U)) & S_BLOCK1], 42U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 24960U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aInvestLaneA[((aIndex + 24176U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aIngress, 53U)) ^ (RotL64(aPrevious, 37U) + RotL64(aCross, 4U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterA = ((aWandererE + RotL64(aScatter, 13U)) + RotL64(aCarry, 47U)) + 2617613537256538553U;
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 47U)) + RotL64(aCarry, 3U)) + 16642868916835132715U;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 3U)) + 10860291124337073254U;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 35U)) + 6432511273906902472U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aIngress, 27U)) + 7505375005848241910U;
            aOrbiterG = (aWandererI + RotL64(aScatter, 60U)) + 11086616004678821329U;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 11U)) + RotL64(aCarry, 11U)) + 3298830587569881951U;
            aOrbiterH = (aWandererB + RotL64(aCross, 41U)) + 9775143140064220979U;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 19U)) + 4147601326580823120U) + aNonceWordN;
            aOrbiterI = (((aWandererG + RotL64(aIngress, 29U)) + 12245920269898100415U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordP;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 54U)) + 8391940489176734499U) + aNonceWordD;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 17876893379544668477U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 18301882058180370541U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16680384667098921309U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 6869225862715140102U) + aNonceWordL;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 15404118372589259800U;
            aOrbiterG = RotL64((aOrbiterG * 5766851935950389915U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 17757381020518233814U) + aNonceWordJ;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 17677969146092374455U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3469432916562405063U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 15783378556632870114U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 5792858258663697864U;
            aOrbiterD = RotL64((aOrbiterD * 12008981883482080427U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 11737803388202260296U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 16001927091970715330U;
            aOrbiterJ = RotL64((aOrbiterJ * 3062030309852922061U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 1749586939123286632U) + aNonceWordM;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 6169421068855905938U) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 12374789910763348695U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 10073586820719728062U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 17744171227198661555U;
            aOrbiterC = RotL64((aOrbiterC * 10658375268803957647U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 1149819647337612792U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 7725598665625892006U;
            aOrbiterK = RotL64((aOrbiterK * 15097586655234391559U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 13930096050550704122U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 3632241034947389647U;
            aOrbiterH = RotL64((aOrbiterH * 8442222389196610427U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 17933893495867517142U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 7888594392078082482U;
            aOrbiterF = RotL64((aOrbiterF * 9809847720610861237U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 10805303827043372168U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 2617613537256538553U;
            aOrbiterA = RotL64((aOrbiterA * 3940471942234248791U), 43U);
            //
            aIngress = RotL64(aOrbiterK, 46U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 11U) + RotL64(aOrbiterG, 5U)) + aOrbiterE);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 37U) + aOrbiterJ) + RotL64(aOrbiterD, 54U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 56U) + RotL64(aOrbiterB, 51U)) + aOrbiterI) + aNonceWordA);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 51U) + aOrbiterA) + RotL64(aOrbiterB, 57U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 37U)) + aOrbiterD) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterF, 19U)) + aOrbiterI);
            aWandererE = aWandererE + (((((RotL64(aIngress, 19U) + RotL64(aOrbiterA, 41U)) + aOrbiterD) + RotL64(aCarry, 37U)) + aNonceWordI) + aPhaseEWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 5U) + aOrbiterI) + RotL64(aOrbiterH, 13U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterE, 21U)) + aNonceWordC);
            aWandererH = aWandererH ^ (((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterA, 48U)) + aNonceWordK);
            aWandererG = aWandererG + ((RotL64(aPrevious, 60U) + aOrbiterD) + RotL64(aOrbiterI, 27U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 4U));
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + RotL64(aWandererG, 35U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 30234U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 29224U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 31416U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29864U)) & S_BLOCK1], 22U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 29629U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 28U) ^ RotL64(aCarry, 57U)) + (RotL64(aCross, 43U) + RotL64(aIngress, 13U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterJ = (((aWandererF + RotL64(aPrevious, 47U)) + RotL64(aCarry, 51U)) + 13714409587461539863U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aIngress, 57U)) + 14101156723903265839U;
            aOrbiterK = (aWandererD + RotL64(aCross, 3U)) + 7063754562895369001U;
            aOrbiterE = (aWandererI + RotL64(aScatter, 44U)) + 12320578575245519386U;
            aOrbiterD = (((aWandererA + RotL64(aIngress, 37U)) + RotL64(aCarry, 29U)) + 11744826789631008424U) + aNonceWordE;
            aOrbiterC = (((aWandererC + RotL64(aCross, 19U)) + RotL64(aCarry, 23U)) + 8744816505096675597U) + aPhaseEOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 35U)) + 10405435520084528645U) + aNonceWordC;
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 52U)) + 1463157688070683543U) + aNonceWordH;
            aOrbiterI = (aWandererB + RotL64(aIngress, 41U)) + 12379603577919617703U;
            aOrbiterA = (aWandererH + RotL64(aScatter, 21U)) + 1343439118031348146U;
            aOrbiterH = ((aWandererK + RotL64(aCross, 39U)) + 16118850268070235540U) + aNonceWordO;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 14116264435819277136U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 5251698273012432109U;
            aOrbiterK = RotL64((aOrbiterK * 1495818611622063967U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 14806408656041403829U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 11569345414052398227U;
            aOrbiterD = RotL64((aOrbiterD * 9913158908301414861U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 17063874769147888574U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 9927420478679581917U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9042782809534196563U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 2550285599827162167U) + aNonceWordD;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 17801534123304996448U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2160836889363614721U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 6456685241021762041U) + aNonceWordK;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 17064208177372969289U;
            aOrbiterH = RotL64((aOrbiterH * 13726627607233302493U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 18279938244131982650U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 8211002229712129419U) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 12931373380977640645U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 12795832560781931767U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 286378504074349650U;
            aOrbiterA = RotL64((aOrbiterA * 85453101173293509U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 5835304250436889513U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 12704972686724379659U;
            aOrbiterC = RotL64((aOrbiterC * 1198789639656336053U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 12555700587254295099U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 6740149669657971715U;
            aOrbiterJ = RotL64((aOrbiterJ * 9376048577305482691U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 1541392147096889431U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 16891341703173286949U;
            aOrbiterB = RotL64((aOrbiterB * 697452963711223355U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 8811637585092392653U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 13714409587461539863U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2578939920876994763U), 37U);
            //
            aIngress = RotL64(aOrbiterJ, 43U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterD, 39U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterF, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 10U) + aOrbiterK) + RotL64(aOrbiterC, 19U));
            aWandererH = aWandererH + (((RotL64(aScatter, 29U) + aOrbiterD) + RotL64(aOrbiterG, 46U)) + aNonceWordI);
            aWandererF = aWandererF ^ ((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterE, 21U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 3U)) + aOrbiterI) + RotL64(aCarry, 51U)) + aPhaseEWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 39U) + aOrbiterH) + RotL64(aOrbiterB, 39U));
            aWandererA = aWandererA + (((RotL64(aIngress, 6U) + RotL64(aOrbiterH, 53U)) + aOrbiterK) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 5U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterF, 51U)) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterA, 42U)) + aOrbiterC);
            aWandererC = aWandererC + ((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterB, 27U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterA, 35U)) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererK, 48U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 60U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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

void TwistExpander_Karate_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xFDC07022A963F68FULL + 0xBD1C6B98B423EB38ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x95423325C94A7829ULL + 0xCDA5D65914872E58ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xCBFEC0E4C9239339ULL + 0xAA537D881B252084ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xBE361BFC3FD73CC3ULL + 0x943DDEA5C024570FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xDFE6880331065B19ULL + 0xCF652E07D2150290ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x80C19E2C586AB165ULL + 0x920D6B9046EA366AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xE3EC5C3B68D0391BULL + 0xFCBFB7D31C85430BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x96B4AFB0648C73FBULL + 0xEC35C865E92DA1A9ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xD25D367A2048813BULL + 0x93D5E7D7DF04E7F4ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x9D9C0B2E6598AF33ULL + 0xC1D2F79C37D96D33ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xF1D9E13E4BD3B6FFULL + 0xFAC3F094DC562536ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xBD0EE852D3B38A61ULL + 0xD7E97D427D42B5D7ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xB2BC1C08AFC38633ULL + 0x99124CCDB11430E9ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xE2EDC08C544E4579ULL + 0xF0F4E664389B4EEDULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xE0200D55299640C9ULL + 0x8FD0BB996DABEE62ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xAEE5A89579D8C7F5ULL + 0x83A8598511C8407EULL);
    // GSeedRunSeed_F seed_loop_f (start)
    {
        // GSeedRunSeed_F seed_loop_f lane group
        // read from: aOperationLaneA, aOperationLaneB, aInvestLaneD, aOperationLaneC, aOperationLaneD, aInvestLaneA, aSnowLaneC, aWorkLaneC, aSnowLaneB, aSnowLaneD, aWorkLaneD, aExpandLaneA, aInvestLaneC, aExpandLaneB, aInvestLaneB, aExpandLaneC, aSnowLaneA
        // write to: aSnowLaneC, aSnowLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_f loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aInvestLaneD
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aInvestLaneD forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aInvestLaneA
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aInvestLaneA backward/forward random
        // write to: aSnowLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 4791U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((aIndex + 3349U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 311U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 435U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 216U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 2534U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aIngress, 22U)) + (RotL64(aPrevious, 35U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterB = ((aWandererD + RotL64(aScatter, 60U)) + 3339283916456813609U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 47U)) + 11339086426180649584U) + aNonceWordF;
            aOrbiterC = ((aWandererC + RotL64(aIngress, 29U)) + 16819191669329316585U) + aNonceWordK;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 5U)) + RotL64(aCarry, 43U)) + 8361916937762630725U;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 11U)) + RotL64(aCarry, 11U)) + 18031328374429899857U;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 51U)) + 18261756894092897276U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aIngress, 37U)) + 4250319792907645666U;
            aOrbiterE = ((aWandererF + RotL64(aCross, 24U)) + 1492411503643460886U) + aNonceWordL;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 43U)) + RotL64(aCarry, 21U)) + 17369549067879344180U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 7301713524358676722U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 2985193736033012535U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7473297294949338265U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 14086975808140927408U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 10390516547834639800U;
            aOrbiterA = RotL64((aOrbiterA * 11441293212275890819U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 18205555540941493267U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 16967799565443938873U;
            aOrbiterJ = RotL64((aOrbiterJ * 3009081009044782443U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 9209505304067579944U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 3522631966146762306U;
            aOrbiterE = RotL64((aOrbiterE * 3441982898533162599U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 8811497120829041188U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 14707301680850257294U;
            aOrbiterB = RotL64((aOrbiterB * 11383709499376464085U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 10080595991787801029U) + aNonceWordJ;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 6822892187784299166U) ^ aNonceWordE;
            aOrbiterH = RotL64((aOrbiterH * 7417016898027778287U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 1981637172055758689U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 16463077485583119324U;
            aOrbiterF = RotL64((aOrbiterF * 2876782050665869121U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 8383837717361569465U) + aNonceWordN;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 2788511294985017326U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2809163242875130677U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 3529607472855930041U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 8850940802020173766U) ^ aNonceWordC;
            aOrbiterI = RotL64((aOrbiterI * 7821450253655655943U), 3U);
            //
            aIngress = RotL64(aOrbiterA, 48U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + RotL64(aOrbiterI, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterA, 23U)) + aOrbiterC);
            aWandererA = aWandererA + (((((RotL64(aIngress, 53U) + aOrbiterB) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 51U)) + aNonceWordO) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterI, 57U)) + aOrbiterC) + aNonceWordA);
            aWandererD = aWandererD + ((RotL64(aPrevious, 42U) + RotL64(aOrbiterJ, 43U)) + aOrbiterE);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterC, 50U));
            aWandererI = aWandererI + ((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterH, 27U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterA, 5U)) + aOrbiterJ);
            aWandererK = aWandererK + (((((RotL64(aPrevious, 30U) + RotL64(aOrbiterH, 37U)) + aOrbiterE) + RotL64(aCarry, 37U)) + aNonceWordI) + aPhaseFWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 11U) + aOrbiterA) + RotL64(aOrbiterF, 12U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 30U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + RotL64(aWandererE, 19U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aSnowLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 2
        // ingress from: aSnowLaneC, aOperationLaneC, aOperationLaneD, aWorkLaneC
        // ingress directions: aSnowLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aWorkLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aSnowLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aSnowLaneB backward/forward random
        // write to: aSnowLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneC[((aIndex + 7648U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((aIndex + 8060U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 7775U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 10518U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 10649U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10592U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aSnowLaneB[((aIndex + 6561U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aPrevious, 23U)) ^ (RotL64(aIngress, 4U) + RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterI = (((aWandererH + RotL64(aPrevious, 41U)) + RotL64(aCarry, 19U)) + 5480870806135400132U) + aNonceWordA;
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 60U)) + 8034874599430768743U) + aNonceWordC;
            aOrbiterG = ((aWandererI + RotL64(aCross, 35U)) + 4006919843736863767U) + aNonceWordN;
            aOrbiterK = ((aWandererG + RotL64(aScatter, 19U)) + RotL64(aCarry, 5U)) + 2988069748674633718U;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 51U)) + 12347295651973135786U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aCross, 46U)) + 14152683894431568192U) + aPhaseFOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aScatter, 23U)) + 15765143815254196598U;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 13U)) + RotL64(aCarry, 27U)) + 10473067082331244233U;
            aOrbiterF = (aWandererC + RotL64(aPrevious, 5U)) + 1089466925383677249U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 13215039929873682230U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 3957997712247961479U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7631186240013784703U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 10023907397941685546U) + aNonceWordE;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 14593012591254614353U) ^ aNonceWordD;
            aOrbiterE = RotL64((aOrbiterE * 17111300092082154687U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 13353797968154036726U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 9259966668512102858U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8326732574268308221U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 10757861831070349321U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 10530223113483866178U;
            aOrbiterB = RotL64((aOrbiterB * 11269177745265396583U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 7554320926405521865U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 6978052067277966996U;
            aOrbiterC = RotL64((aOrbiterC * 18020134738536217801U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 1053695861967171420U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 15980734683539854451U;
            aOrbiterK = RotL64((aOrbiterK * 3208466640010555357U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 17041258393808061556U) + aNonceWordO;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 12846551858751995530U;
            aOrbiterH = RotL64((aOrbiterH * 9303891433380993639U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 14617434286683320666U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 3999309956180741302U;
            aOrbiterF = RotL64((aOrbiterF * 15037707937050015205U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 13452627760403094126U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 2633241575260427158U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2638570213290747581U), 53U);
            //
            aIngress = RotL64(aOrbiterK, 51U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 38U));
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 60U) + aOrbiterB) + RotL64(aOrbiterG, 46U)) + aNonceWordI);
            aWandererC = aWandererC + (((RotL64(aScatter, 51U) + RotL64(aOrbiterH, 51U)) + aOrbiterI) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterE, 23U)) + aNonceWordG) + aPhaseFWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 27U) + RotL64(aOrbiterK, 35U)) + aOrbiterJ) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 39U) + aOrbiterB) + RotL64(aOrbiterC, 13U));
            aWandererB = aWandererB + ((RotL64(aCross, 46U) + RotL64(aOrbiterK, 39U)) + aOrbiterE);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 23U) + aOrbiterI) + RotL64(aOrbiterF, 19U)) + aNonceWordP);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterH, 58U)) + aNonceWordK) + aPhaseFWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterI, 5U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 26U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aSnowLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 3
        // ingress from: aSnowLaneD, aOperationLaneA, aWorkLaneD
        // ingress directions: aSnowLaneD forward forced, aOperationLaneA forward forced, aWorkLaneD forward/backward random
        // cross from: aSnowLaneC, aOperationLaneC
        // cross directions: aSnowLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneD[((aIndex + 13214U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneA[((aIndex + 13596U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 13543U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 11005U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneC[((aIndex + 13592U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCross, 23U)) ^ (RotL64(aPrevious, 6U) ^ RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterI = ((aWandererG + RotL64(aIngress, 47U)) + RotL64(aCarry, 39U)) + 7896237440058555694U;
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 24U)) + 11870529476037558635U;
            aOrbiterF = ((aWandererH + RotL64(aCross, 53U)) + RotL64(aCarry, 21U)) + 9158983227801569448U;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 43U)) + 4710172270996950329U) + aNonceWordF;
            aOrbiterJ = ((((aWandererA + RotL64(aPrevious, 13U)) + RotL64(aCarry, 51U)) + 14634482800356647630U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordA;
            aOrbiterK = (aWandererC + RotL64(aCross, 3U)) + 8822207952170610891U;
            aOrbiterB = (aWandererE + RotL64(aIngress, 19U)) + 13755891414028982553U;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 57U)) + 4555293067488040719U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = (aWandererB + RotL64(aIngress, 38U)) + 2816805148093762081U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 2122631477965135190U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 4592922416380416071U;
            aOrbiterF = RotL64((aOrbiterF * 11644507904538573165U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 7102471666524164715U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 17274623547879474204U;
            aOrbiterJ = RotL64((aOrbiterJ * 5443572270546181789U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 938587316977094680U) + aNonceWordH;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 18258015823797023523U;
            aOrbiterB = RotL64((aOrbiterB * 6068819567674605919U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 5809987756043471595U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 5083075160112581620U;
            aOrbiterI = RotL64((aOrbiterI * 3313957222154937503U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 5960021727750946496U) + aNonceWordO;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 5967477320950630150U;
            aOrbiterK = RotL64((aOrbiterK * 330964768256424655U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 6578428711689296132U) + aNonceWordP;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 5601728218197771276U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9552559022315971847U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 7923809409017855241U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 16479366540906497019U;
            aOrbiterA = RotL64((aOrbiterA * 7118578387798460919U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 17000467091738009736U) + aNonceWordM;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 6801634573655508028U;
            aOrbiterG = RotL64((aOrbiterG * 10584635770060137089U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 123668445682719574U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 14462802805503986316U;
            aOrbiterH = RotL64((aOrbiterH * 12398236364304875941U), 47U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 19U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 58U));
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aPrevious, 58U) + aOrbiterH) + RotL64(aOrbiterI, 3U));
            aWandererE = aWandererE ^ ((((RotL64(aCross, 47U) + aOrbiterH) + RotL64(aOrbiterJ, 57U)) + aNonceWordN) + aPhaseFWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 43U) + aOrbiterB) + RotL64(aOrbiterH, 35U)) + aNonceWordI);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterG, 44U)) + aOrbiterE);
            aWandererJ = aWandererJ + (((RotL64(aCross, 34U) + aOrbiterF) + RotL64(aOrbiterJ, 51U)) + aNonceWordL);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 11U)) + aOrbiterJ);
            aWandererB = aWandererB + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 29U)) + aOrbiterK) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 27U) + aOrbiterE) + RotL64(aOrbiterI, 39U)) + aNonceWordG) + aPhaseFWandererUpdateSaltB[((aIndex + 4U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 13U) + RotL64(aOrbiterG, 24U)) + aOrbiterB) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 30U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 40U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 21044U)) & S_BLOCK1], 56U) ^ RotL64(aSnowLaneC[((aIndex + 20922U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 19902U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 18607U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 19910U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 54U) + RotL64(aCross, 29U)) ^ (RotL64(aIngress, 41U) ^ RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 27U)) + 16922357079016918108U;
            aOrbiterI = (((aWandererD + RotL64(aIngress, 12U)) + 11771749797137599131U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordI;
            aOrbiterD = (aWandererC + RotL64(aCross, 23U)) + 4635668433708036077U;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 39U)) + RotL64(aCarry, 11U)) + 15827952719230577008U;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 3U)) + RotL64(aCarry, 47U)) + 1495675306110023086U;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 35U)) + 7294835466949728365U) + aNonceWordC;
            aOrbiterE = ((aWandererI + RotL64(aCross, 58U)) + RotL64(aCarry, 29U)) + 179122461212041978U;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 47U)) + 545981421632236251U) + aPhaseFOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (aWandererK + RotL64(aCross, 53U)) + 15338259639814630535U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 12924313840290895215U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 17846785921286020610U) ^ aNonceWordO;
            aOrbiterD = RotL64((aOrbiterD * 18309347016029917133U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 5721472794107057875U) + aNonceWordE;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 16359630793856870319U;
            aOrbiterK = RotL64((aOrbiterK * 14186771515526698907U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 10614102110239037308U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 16421992251278236531U;
            aOrbiterB = RotL64((aOrbiterB * 2561232904676068089U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 8668149834861244963U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 12699331834360948734U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2249360824172616357U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 4470693178142950471U) + aNonceWordP;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 526000656022724741U;
            aOrbiterC = RotL64((aOrbiterC * 16688501462334673493U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 6880246132270094141U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 7126466778855297013U;
            aOrbiterE = RotL64((aOrbiterE * 5692237926830293205U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 6436404501390442054U) + aNonceWordF;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 1213633065612242699U;
            aOrbiterG = RotL64((aOrbiterG * 17604454985534439259U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 8186529105901185854U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 10607460957358250935U;
            aOrbiterI = RotL64((aOrbiterI * 17172191011625677861U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 9743278964993305169U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 14007577681873418075U;
            aOrbiterF = RotL64((aOrbiterF * 4231122580398039133U), 27U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterB, 19U);
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterC, 44U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aCross, 35U) + RotL64(aOrbiterA, 47U)) + aOrbiterG) + RotL64(aCarry, 13U)) + aNonceWordA);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 58U) + RotL64(aOrbiterB, 42U)) + aOrbiterI) + aPhaseFWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 13U)) + aOrbiterC) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 39U) + aOrbiterD) + RotL64(aOrbiterB, 3U));
            aWandererD = aWandererD + (((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 27U)) + aOrbiterD) + aNonceWordG);
            aWandererE = aWandererE ^ (((RotL64(aCross, 26U) + RotL64(aOrbiterB, 57U)) + aOrbiterC) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 52U)) + aOrbiterC) + aNonceWordD);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterK, 35U)) + aOrbiterE);
            aWandererC = aWandererC + ((RotL64(aCross, 13U) + aOrbiterK) + RotL64(aOrbiterG, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 42U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 5
        // ingress from: aExpandLaneB, aSnowLaneD, aInvestLaneB
        // ingress directions: aExpandLaneB forward forced, aSnowLaneD forward forced, aInvestLaneB forward/backward random
        // cross from: aExpandLaneA, aSnowLaneC
        // cross directions: aExpandLaneA backward forced, aSnowLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 23247U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneD[((aIndex + 27035U)) & S_BLOCK1], 36U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 26131U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25229U)) & S_BLOCK1], 19U) ^ RotL64(aSnowLaneC[((aIndex + 27143U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aPrevious, 19U) + RotL64(aCross, 4U)) ^ (RotL64(aIngress, 35U) ^ RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterD = (aWandererJ + RotL64(aCross, 40U)) + 6342299552323486695U;
            aOrbiterB = ((((aWandererC + RotL64(aIngress, 35U)) + RotL64(aCarry, 29U)) + 12692748514781367538U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordE;
            aOrbiterC = ((((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 37U)) + 8202639945493229155U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordO;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 19U)) + 4439975701793231639U;
            aOrbiterK = ((aWandererG + RotL64(aCross, 13U)) + 16774235182859553759U) + aNonceWordF;
            aOrbiterI = (aWandererE + RotL64(aIngress, 29U)) + 8764155413335405667U;
            aOrbiterE = (aWandererH + RotL64(aScatter, 3U)) + 7167848811974967685U;
            aOrbiterH = (((aWandererF + RotL64(aPrevious, 51U)) + RotL64(aCarry, 11U)) + 16768278912125334220U) + aNonceWordN;
            aOrbiterA = (aWandererD + RotL64(aScatter, 44U)) + 9090838954826296201U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 7644075729758006298U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 17326182797908071215U;
            aOrbiterC = RotL64((aOrbiterC * 2408330168749256075U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 16158809721888137555U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 8029938783858263694U;
            aOrbiterB = RotL64((aOrbiterB * 12628072435324195483U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 8716553521415553404U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 7012599977009208840U;
            aOrbiterE = RotL64((aOrbiterE * 8775355876188948851U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 13250558696578541499U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 13705957059101025396U;
            aOrbiterI = RotL64((aOrbiterI * 16889495686487056367U), 47U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterH) + 2796775206291902461U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1]) + aNonceWordA;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 13741676263512390669U;
            aOrbiterK = RotL64((aOrbiterK * 10455782033465595947U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 1691908360612389252U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 4114939415206031540U;
            aOrbiterH = RotL64((aOrbiterH * 2797401802892718297U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 2374911514440738727U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 12377616933668803091U) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 2505164835116651215U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 681094033415259645U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 13841322124900463362U;
            aOrbiterD = RotL64((aOrbiterD * 4210414203856902329U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 18082983557580381338U) + aNonceWordI;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 15731122225678626778U;
            aOrbiterJ = RotL64((aOrbiterJ * 7785999919955613789U), 23U);
            //
            aIngress = RotL64(aOrbiterK, 12U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aCross, 27U) + RotL64(aOrbiterB, 48U)) + aOrbiterD) + aPhaseFWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 21U) + aOrbiterJ) + RotL64(aOrbiterK, 39U)) + aNonceWordD);
            aWandererH = aWandererH + ((RotL64(aScatter, 56U) + RotL64(aOrbiterB, 29U)) + aOrbiterH);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterH, 5U)) + aNonceWordJ);
            aWandererK = aWandererK + (((RotL64(aScatter, 43U) + aOrbiterH) + RotL64(aOrbiterJ, 19U)) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterC, 35U));
            aWandererE = aWandererE + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterJ, 10U)) + aOrbiterE) + RotL64(aCarry, 21U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 6U) + aOrbiterA) + RotL64(aOrbiterJ, 53U));
            aWandererD = aWandererD + (((RotL64(aScatter, 39U) + RotL64(aOrbiterJ, 43U)) + aOrbiterB) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererB, 56U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + RotL64(aWandererH, 39U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aSnowLaneA
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aSnowLaneA forward/backward random
        // cross from: aExpandLaneB, aOperationLaneB
        // cross directions: aExpandLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 32183U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((aIndex + 31430U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aSnowLaneA[((aIndex + 30306U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31844U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27354U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCross, 36U)) + (RotL64(aPrevious, 11U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterE = (((aWandererF + RotL64(aPrevious, 19U)) + RotL64(aCarry, 23U)) + 6318740973868639425U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aIngress, 46U)) + RotL64(aCarry, 53U)) + 5487840061430920881U;
            aOrbiterG = (aWandererI + RotL64(aCross, 35U)) + 10258706763248072672U;
            aOrbiterI = (((aWandererJ + RotL64(aScatter, 23U)) + RotL64(aCarry, 13U)) + 18356875269730338208U) + aNonceWordD;
            aOrbiterB = (aWandererA + RotL64(aIngress, 5U)) + 12883160282903147010U;
            aOrbiterD = ((aWandererK + RotL64(aCross, 29U)) + 1010140474942697730U) + aNonceWordA;
            aOrbiterA = (aWandererG + RotL64(aScatter, 57U)) + 17733939421700898293U;
            aOrbiterF = (((aWandererD + RotL64(aPrevious, 40U)) + 13693055887924981201U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordL;
            aOrbiterC = (aWandererC + RotL64(aCross, 51U)) + 14574732452793385269U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 10832873941223609012U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 8212600587135328040U;
            aOrbiterG = RotL64((aOrbiterG * 5334613996794796145U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 5312744319781971178U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 6173741211706546923U;
            aOrbiterB = RotL64((aOrbiterB * 12854414066390848249U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 3693249147883790810U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 18365859989736602556U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3348463719324104997U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 10645056678337549771U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 1175668356822251045U;
            aOrbiterI = RotL64((aOrbiterI * 6579675292775345579U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 13556844570541823717U) + aNonceWordG;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 4790355739411849736U;
            aOrbiterC = RotL64((aOrbiterC * 4083544011788850307U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 14905575502272644116U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterB) ^ 17047244574558476634U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterH = RotL64((aOrbiterH * 2356386971503880047U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 10161614295718414869U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 13413914082651612468U;
            aOrbiterD = RotL64((aOrbiterD * 16224039093981079491U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 6072693130156927774U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 4333656233793103787U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9374745547133955709U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 17209776289202130250U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 11752001118070361543U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4416523594812872339U), 47U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterD, 5U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 30U));
            aIngress = aIngress + (RotL64(aOrbiterF, 39U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + RotL64(aOrbiterI, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterE, 37U));
            aWandererD = aWandererD + (((((RotL64(aCross, 29U) + aOrbiterE) + RotL64(aOrbiterG, 23U)) + RotL64(aCarry, 35U)) + aNonceWordM) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 12U)) + aOrbiterF);
            aWandererF = aWandererF + (((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 60U) + RotL64(aOrbiterB, 43U)) + aOrbiterG) + aPhaseFWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 19U) + RotL64(aOrbiterD, 3U)) + aOrbiterA) + aNonceWordO);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 19U)) + aOrbiterD) + aNonceWordC);
            aWandererC = aWandererC + ((RotL64(aPrevious, 11U) + aOrbiterD) + RotL64(aOrbiterC, 58U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 36U) + RotL64(aOrbiterI, 51U)) + aOrbiterG) + aNonceWordI);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 6U));
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 19U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_Karate_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x8329858C2C25E073ULL + 0x8C032D55A10213F3ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x9E6BA7F0E77ED8E5ULL + 0xAFD2564269702A4BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x864BBD93F2ACAB79ULL + 0xF721DBC77D656BB9ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xC535BCB8F31DC603ULL + 0x8D181E0D7D6D7A51ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x9AB84C14B249BFF9ULL + 0x835FE57E2202E065ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xF2E092F661FBEE65ULL + 0xC2371D112F162AB0ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xA8939E8AE66F08DDULL + 0xAEBF89850F738EEDULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xC05AE07E5251DD81ULL + 0xCD1A26B9E6ABCAB8ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x98C99EF2E3290239ULL + 0xD8E154EFABCB9B42ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xC2E20CA546504CE9ULL + 0x85DE64AE48508BE1ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xD63FC97169B97285ULL + 0xE347402BAC3DF3C0ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xEAEAA03D96725CCBULL + 0x9548E7534318257FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xD598612E7CF1E5F3ULL + 0xDB3FC0F1FA69D773ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xE7FA7E33270062CBULL + 0xBC60C2C30F47ED0FULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xA23453A88C0A9491ULL + 0xF09C19BB485F1D26ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xB336F758D22820CDULL + 0xD0A03184B8110814ULL);
    // GSeedRunSeed_G seed_loop_h (start)
    {
        // GSeedRunSeed_G seed_loop_h lane group
        // read from: aSnowLaneA, aSnowLaneB, aFireLaneD, aSnowLaneC, aSnowLaneD, aInvestLaneA, aWorkLaneA, aFireLaneA, aInvestLaneD, aWorkLaneB, aInvestLaneC, aExpandLaneA, aFireLaneC, aExpandLaneB, aFireLaneB, aExpandLaneC, aInvestLaneB
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_h loop 1
        // ingress from: aSnowLaneA, aSnowLaneB, aFireLaneD
        // ingress directions: aSnowLaneA forward forced, aSnowLaneB forward forced, aFireLaneD forward/backward random
        // cross from: aSnowLaneC, aSnowLaneD, aInvestLaneA
        // cross directions: aSnowLaneC backward forced, aSnowLaneD backward forced, aInvestLaneA backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 5309U)) & S_BLOCK1], 47U) ^ RotL64(aSnowLaneB[((aIndex + 5015U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 4649U)) & S_BLOCK1], 10U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 332U)) & S_BLOCK1], 29U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 3791U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aInvestLaneA[((aIndex + 604U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCross, 18U)) + (RotL64(aCarry, 35U) + RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterB = ((((aWandererJ + RotL64(aScatter, 41U)) + RotL64(aCarry, 27U)) + 12615321415808640429U) + aPhaseHOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1]) + aNonceWordM;
            aOrbiterI = (aWandererA + RotL64(aPrevious, 11U)) + 15712784676459931207U;
            aOrbiterE = ((((aWandererF + RotL64(aIngress, 60U)) + RotL64(aCarry, 39U)) + 11013335427004930046U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordC;
            aOrbiterA = (aWandererH + RotL64(aCross, 53U)) + 8298733856304768806U;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 27U)) + 6207732959150824216U;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 3U)) + 9769864876127544038U) + aNonceWordL;
            aOrbiterD = ((aWandererI + RotL64(aCross, 21U)) + RotL64(aCarry, 3U)) + 10782181918651152563U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 5790454015845620939U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 15606578025386733803U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7079287329365566355U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 5522352539991175304U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 5993355818572869649U;
            aOrbiterI = RotL64((aOrbiterI * 15221467311057431139U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 10864534396947622047U) + aNonceWordP;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 12090053126235913528U;
            aOrbiterD = RotL64((aOrbiterD * 7250801471645972261U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 14191181677234981396U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = (((aOrbiterF ^ aOrbiterC) ^ 2258570108233924592U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 8307541155393855209U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 8448114811381534603U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 2702389315763499817U) ^ aNonceWordD;
            aOrbiterC = RotL64((aOrbiterC * 6710443836432274393U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 17202184076718780200U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 150549910056015002U) ^ aNonceWordF;
            aOrbiterA = RotL64((aOrbiterA * 195034681254956335U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 4910512055808124967U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 4783477997418403079U;
            aOrbiterB = RotL64((aOrbiterB * 861977492146512865U), 43U);
            //
            aIngress = RotL64(aOrbiterA, 3U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterB, 60U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aPrevious, 44U) + aOrbiterD) + RotL64(aOrbiterB, 27U)) + aNonceWordE);
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 20U)) + aOrbiterI) + aNonceWordH) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 21U) + RotL64(aOrbiterI, 41U)) + aOrbiterD) + aNonceWordN);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 53U) + aOrbiterC) + RotL64(aOrbiterA, 3U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 27U) + aOrbiterI) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 13U)) + aPhaseHWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterA, 57U));
            aWandererK = aWandererK + (((RotL64(aCross, 13U) + RotL64(aOrbiterE, 35U)) + aOrbiterC) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 36U));
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererF, 19U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 2
        // ingress from: aWorkLaneA, aSnowLaneC, aSnowLaneD, aFireLaneA
        // ingress directions: aWorkLaneA forward forced, aSnowLaneC forward forced, aSnowLaneD forward forced, aFireLaneA forward/backward random
        // cross from: aSnowLaneA, aSnowLaneB, aInvestLaneD
        // cross directions: aSnowLaneA backward forced, aSnowLaneB backward forced, aInvestLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 10379U)) & S_BLOCK1], 46U) ^ RotL64(aSnowLaneC[((aIndex + 6957U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 7642U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneA[((aIndex + 9008U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 8659U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 8532U)) & S_BLOCK1], 20U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 7221U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 27U) + RotL64(aCarry, 13U)) ^ (RotL64(aCross, 39U) + RotL64(aPrevious, 56U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterD = (((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 51U)) + 13924571355038625040U) + aNonceWordH;
            aOrbiterK = ((aWandererD + RotL64(aScatter, 5U)) + RotL64(aCarry, 35U)) + 16328300979357156658U;
            aOrbiterG = (((aWandererJ + RotL64(aCross, 27U)) + RotL64(aCarry, 23U)) + 3947771961206012461U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 51U)) + 15428284250569311285U;
            aOrbiterE = (aWandererE + RotL64(aIngress, 19U)) + 5777369485254032486U;
            aOrbiterH = (((aWandererF + RotL64(aCross, 42U)) + 16813320300717644673U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordI;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 35U)) + 16689933050200758251U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 1856422419049390708U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 18214498743831925517U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10744120577560529379U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 18278550878494094923U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 797712062039591797U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7212998747080137625U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 15854849439012341347U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 996882939768167773U;
            aOrbiterJ = RotL64((aOrbiterJ * 14936703950807908575U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 3005829974130671692U) + aNonceWordK;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 8793495343509953906U;
            aOrbiterE = RotL64((aOrbiterE * 14065479348374612031U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 7710453029930631112U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 9511995836117707047U) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 7250766204781428201U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 670902975693341744U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 9045820304668279777U;
            aOrbiterH = RotL64((aOrbiterH * 18373074917532639027U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 12417212387607119470U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 12816983560669985622U) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 8406003970221889847U), 5U);
            //
            aIngress = RotL64(aOrbiterE, 3U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + RotL64(aOrbiterJ, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterC, 53U)) + aOrbiterG) + aPhaseHWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 41U) + aOrbiterK) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 48U) + aOrbiterD) + RotL64(aOrbiterJ, 13U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterH, 47U)) + aOrbiterK) + RotL64(aCarry, 51U)) + aNonceWordE);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterC, 38U)) + aOrbiterH) + aNonceWordA);
            aWandererB = aWandererB + (((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterJ, 5U)) + aPhaseHWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 19U)) + aOrbiterJ) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererF, 60U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_h loop 3
        // ingress from: aWorkLaneB, aSnowLaneA, aInvestLaneC
        // ingress directions: aWorkLaneB forward forced, aSnowLaneA forward forced, aInvestLaneC forward/backward random
        // cross from: aWorkLaneA, aSnowLaneC
        // cross directions: aWorkLaneA backward forced, aSnowLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 15597U)) & S_BLOCK1], 30U) ^ RotL64(aSnowLaneA[((aIndex + 14676U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 11188U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15388U)) & S_BLOCK1], 11U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 13336U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 4U) + RotL64(aCarry, 21U)) ^ (RotL64(aCross, 37U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterC = (((aWandererB + RotL64(aScatter, 35U)) + RotL64(aCarry, 43U)) + 13960289014350612206U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = (((aWandererC + RotL64(aCross, 21U)) + RotL64(aCarry, 57U)) + 3483331015269589730U) + aPhaseHOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 52U)) + 6873299241002444518U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 29U)) + 3562094007125534229U) + aNonceWordO;
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 13U)) + 11422367439932782705U) + aNonceWordI;
            aOrbiterA = (aWandererE + RotL64(aIngress, 3U)) + 532453428514259816U;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 41U)) + RotL64(aCarry, 21U)) + 17810941465810193088U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 11869759058631106331U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 8837581071876177566U;
            aOrbiterH = RotL64((aOrbiterH * 15329827515970522213U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 17185378327053837778U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 7578253375676981500U;
            aOrbiterA = RotL64((aOrbiterA * 13371647568758721729U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 17112646434432814442U) + aNonceWordA;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 14949096407295697881U) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 14770977858283051753U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 4259590620758467836U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 6534899413644542303U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7987609419215568661U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 2637407498893694243U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 15819295597921425711U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5202015597375051399U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 6373559542002699718U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 11694562937392022505U;
            aOrbiterE = RotL64((aOrbiterE * 9311557972331218597U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 3308736483775453062U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 12749929710650475901U;
            aOrbiterJ = RotL64((aOrbiterJ * 248428400724560945U), 5U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 19U);
            aIngress = aIngress + (RotL64(aOrbiterC, 51U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterJ, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 39U) + RotL64(aOrbiterG, 47U)) + aOrbiterE) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 60U) + RotL64(aOrbiterI, 54U)) + aOrbiterH) + aNonceWordK);
            aWandererJ = aWandererJ + (((RotL64(aCross, 5U) + aOrbiterC) + RotL64(aOrbiterJ, 21U)) + aNonceWordB);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterI, 11U)) + aOrbiterC);
            aWandererC = aWandererC + (((RotL64(aCross, 21U) + RotL64(aOrbiterC, 41U)) + aOrbiterA) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 27U)) + aOrbiterA) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 35U)) + aOrbiterJ) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 58U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + RotL64(aWandererE, 35U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 4
        // ingress from: aExpandLaneA, aWorkLaneA, aFireLaneC
        // ingress directions: aExpandLaneA forward forced, aWorkLaneA forward forced, aFireLaneC forward/backward random
        // cross from: aWorkLaneB, aSnowLaneD
        // cross directions: aWorkLaneB backward forced, aSnowLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 16819U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 18600U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 19615U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21239U)) & S_BLOCK1], 13U) ^ RotL64(aSnowLaneD[((aIndex + 21707U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 4U) + RotL64(aCross, 53U)) ^ (RotL64(aCarry, 39U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterI = (aWandererI + RotL64(aCross, 5U)) + 15383045568644941552U;
            aOrbiterA = (((aWandererA + RotL64(aScatter, 13U)) + 17452811657750910067U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordE;
            aOrbiterE = (aWandererC + RotL64(aIngress, 19U)) + 15660117718455155603U;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 27U)) + 10396441207743665753U) + aNonceWordD;
            aOrbiterC = (((aWandererJ + RotL64(aCross, 37U)) + RotL64(aCarry, 11U)) + 3708971058200841442U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aIngress, 47U)) + RotL64(aCarry, 41U)) + 7000673057768598750U;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 56U)) + RotL64(aCarry, 29U)) + 9886354469011131596U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 16018065329058043467U) + aNonceWordO;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 5024756166109352320U) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 11660932185479046483U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 6587818720728886652U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 3652672354944162319U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10807121230791716109U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 6307315649915348048U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 16405347331742979258U;
            aOrbiterI = RotL64((aOrbiterI * 7183142442906743699U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 5427299664054601957U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 4983381733483185898U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14646556236306407673U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 10182995521328377487U) + aNonceWordF;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterE) ^ 8694282877540593550U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterJ = RotL64((aOrbiterJ * 14614602561910403893U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 4085927978153269932U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 6176195962815240877U;
            aOrbiterA = RotL64((aOrbiterA * 16792916528959579875U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 6966742100601433005U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 9920952446921247521U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1879821050131820933U), 3U);
            //
            aIngress = RotL64(aOrbiterA, 19U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 47U) + aOrbiterJ) + RotL64(aOrbiterF, 29U)) + aNonceWordG);
            aWandererC = aWandererC + ((((RotL64(aIngress, 21U) + aOrbiterF) + RotL64(aOrbiterI, 11U)) + RotL64(aCarry, 53U)) + aNonceWordN);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 41U) + aOrbiterA) + RotL64(aOrbiterI, 35U)) + aNonceWordC);
            aWandererH = aWandererH + ((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterI, 60U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 19U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 54U) + aOrbiterC) + RotL64(aOrbiterH, 53U)) + RotL64(aCarry, 41U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterA, 3U)) + aNonceWordJ) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 36U));
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_h loop 5
        // ingress from: aExpandLaneB, aWorkLaneB, aFireLaneB
        // ingress directions: aExpandLaneB forward forced, aWorkLaneB forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneA, aWorkLaneA
        // cross directions: aExpandLaneA backward forced, aWorkLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 23285U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneB[((aIndex + 24299U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 25151U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22494U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneA[((aIndex + 24288U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 58U) + RotL64(aCross, 41U)) + (RotL64(aCarry, 23U) ^ RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterC = (((aWandererG + RotL64(aCross, 5U)) + RotL64(aCarry, 29U)) + 8375305456876489425U) + aNonceWordA;
            aOrbiterA = (aWandererF + RotL64(aScatter, 53U)) + 16193562952772453047U;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 23U)) + RotL64(aCarry, 3U)) + 18088652458594816223U;
            aOrbiterJ = (aWandererH + RotL64(aIngress, 35U)) + 767344788620249944U;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 43U)) + RotL64(aCarry, 47U)) + 7705194930396368752U;
            aOrbiterI = (((aWandererD + RotL64(aIngress, 60U)) + 3829736891311272834U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordB;
            aOrbiterK = ((aWandererI + RotL64(aCross, 11U)) + 9881681671347640061U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 1721196560190164264U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 3002652618388454213U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15289749311593032657U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 9811621464004005202U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 5652598941069986530U) ^ aNonceWordJ;
            aOrbiterG = RotL64((aOrbiterG * 4797973356708091621U), 13U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterG) + 6250499348327316328U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordD;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 16025054277615264530U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16446892258704281903U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 13800298546867243172U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 12256104592865905782U;
            aOrbiterJ = RotL64((aOrbiterJ * 16983140179497142713U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 17817225416918329229U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 17738671327352776217U;
            aOrbiterA = RotL64((aOrbiterA * 393488251327705063U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 6816031224188400541U) + aNonceWordP;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 16989563985059237014U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8677884225771717797U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 16891524847268207549U) + aNonceWordF;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 1833508573940405571U;
            aOrbiterC = RotL64((aOrbiterC * 9709196587703979539U), 29U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 29U);
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + RotL64(aOrbiterI, 4U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aPrevious, 36U) + aOrbiterB) + RotL64(aOrbiterJ, 47U)) + RotL64(aCarry, 43U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 35U)) + aOrbiterI) + aNonceWordE);
            aWandererH = aWandererH + (((((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 3U)) + aOrbiterK) + RotL64(aCarry, 11U)) + aNonceWordM) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterA, 41U));
            aWandererA = aWandererA + (((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterC, 11U)) + aNonceWordH);
            aWandererI = aWandererI ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterG, 29U)) + aOrbiterC) + aNonceWordI);
            aWandererF = aWandererF + ((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterJ, 58U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererF, 46U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28085U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneA[((aIndex + 28504U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 27369U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31753U)) & S_BLOCK1], 37U) ^ RotL64(aSnowLaneB[((aIndex + 28943U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCross, 56U)) + (RotL64(aCarry, 41U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterF = (aWandererH + RotL64(aCross, 11U)) + 3550722402315312207U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 51U)) + RotL64(aCarry, 53U)) + 16724184551669522754U;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 43U)) + 981751330116773021U) + aPhaseHOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = ((aWandererG + RotL64(aScatter, 29U)) + 7891159229704944868U) + aNonceWordA;
            aOrbiterG = (((aWandererA + RotL64(aCross, 57U)) + RotL64(aCarry, 13U)) + 13618396711464799841U) + aNonceWordL;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 19U)) + RotL64(aCarry, 27U)) + 5969291018449003648U;
            aOrbiterJ = (((aWandererJ + RotL64(aPrevious, 4U)) + 14595540413313640042U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordC;
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 3287990436916111762U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 12534369400200483704U;
            aOrbiterD = RotL64((aOrbiterD * 2345945228434740707U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 2277312067930392274U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 10026320559261334353U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11020464940995912637U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 11258082063135659551U) + aNonceWordI;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 1445958517675746990U;
            aOrbiterH = RotL64((aOrbiterH * 10062265337488757971U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 1011298251290970844U) + aNonceWordB;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 6487834862470043744U;
            aOrbiterB = RotL64((aOrbiterB * 15477913837027179675U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 9966279022928268335U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 10285993486057704393U;
            aOrbiterC = RotL64((aOrbiterC * 15965714363201157535U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 16005362468813966136U) + aNonceWordM;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 223843444699390781U;
            aOrbiterF = RotL64((aOrbiterF * 665392038954573081U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 18178876294968532775U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 12490136112181806806U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16380841616662993709U), 13U);
            //
            aIngress = RotL64(aOrbiterC, 27U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterB, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 13U) + aOrbiterD) + RotL64(aOrbiterH, 20U)) + RotL64(aCarry, 41U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 11U)) + aOrbiterJ);
            aWandererA = aWandererA + (((RotL64(aScatter, 21U) + RotL64(aOrbiterG, 3U)) + aOrbiterH) + aNonceWordO);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 41U)) + aOrbiterG);
            aWandererH = aWandererH + ((((RotL64(aScatter, 37U) + aOrbiterB) + RotL64(aOrbiterJ, 47U)) + RotL64(aCarry, 29U)) + aPhaseHWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 28U) + RotL64(aOrbiterC, 57U)) + aOrbiterD) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 43U) + RotL64(aOrbiterH, 27U)) + aOrbiterJ) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 22U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_Karate_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF;
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
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA;
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
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE;
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 2098U)) & W_KEY1], 27U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 849U)) & W_KEY1], 50U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 1396U)) & W_KEY1], 5U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 751U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aPrevious, 41U)) + (RotL64(aCarry, 56U) ^ RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 5U)) + 18319689184146942855U;
            aOrbiterC = (aWandererI + RotL64(aCross, 50U)) + 8041304130090501019U;
            aOrbiterK = (aWandererA + RotL64(aIngress, 41U)) + 11347064191990897738U;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 57U)) + 15242243470024447468U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aCross, 35U)) + RotL64(aCarry, 27U)) + 10619749107163611105U;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 23U)) + RotL64(aCarry, 47U)) + 14795614276221947128U;
            aOrbiterF = (aWandererF + RotL64(aPrevious, 29U)) + 1578095288886372393U;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 18U)) + 13593906305770501684U) + aPhaseAOrbiterAssignSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = (aWandererC + RotL64(aCross, 3U)) + 8919815528334599172U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 17425548324720065145U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 11125018338392347335U;
            aOrbiterK = RotL64((aOrbiterK * 4377887040461528587U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 3779189180734244399U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 10958224663276134041U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6206963519509783781U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 4317305352561612995U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 4891139433808505355U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11507024985663120317U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 5166074784835930965U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 10080890270621589202U;
            aOrbiterD = RotL64((aOrbiterD * 13170894418184288695U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 4501071771615514619U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 6486573807774431753U;
            aOrbiterC = RotL64((aOrbiterC * 324029625116648669U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 15714881857668975753U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 3506619392820235900U;
            aOrbiterH = RotL64((aOrbiterH * 5707033870161224499U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 5295711072762443783U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 11192836530396570648U;
            aOrbiterI = RotL64((aOrbiterI * 4361810118382207039U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 7993389678399774574U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 12551394763541226695U;
            aOrbiterJ = RotL64((aOrbiterJ * 11903486656172026403U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 11553674370322129668U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 4459881583199320245U;
            aOrbiterF = RotL64((aOrbiterF * 2805857426321555685U), 21U);
            //
            aIngress = RotL64(aOrbiterC, 40U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterH, 23U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + (RotL64(aOrbiterF, 51U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 41U) + aOrbiterI) + RotL64(aOrbiterD, 44U)) + aPhaseAWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 34U) + RotL64(aOrbiterD, 11U)) + aOrbiterC);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 53U)) + aOrbiterC);
            aWandererB = aWandererB + ((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 57U)) + aOrbiterK);
            aWandererK = aWandererK ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterI, 23U)) + aOrbiterK);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterH, 35U)) + aOrbiterC) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterD, 18U)) + aOrbiterE);
            aWandererC = aWandererC + ((((RotL64(aScatter, 27U) + aOrbiterD) + RotL64(aOrbiterA, 27U)) + RotL64(aCarry, 37U)) + aPhaseAWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 12U) + aOrbiterF) + RotL64(aOrbiterE, 3U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (RotL64(aWandererB, 40U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 4901U)) & S_BLOCK1], 6U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 3325U)) & W_KEY1], 27U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 3981U)) & W_KEY1], 22U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 3705U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aPrevious, 56U)) ^ (RotL64(aIngress, 37U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 47U)) + 3339283916456813609U;
            aOrbiterA = (((aWandererI + RotL64(aIngress, 37U)) + RotL64(aCarry, 57U)) + 11339086426180649584U) + aPhaseAOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aCross, 4U)) + 16819191669329316585U;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 41U)) + RotL64(aCarry, 35U)) + 8361916937762630725U;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 19U)) + 18031328374429899857U) + aPhaseAOrbiterAssignSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = (aWandererG + RotL64(aCross, 29U)) + 18261756894092897276U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 51U)) + RotL64(aCarry, 3U)) + 4250319792907645666U;
            aOrbiterI = (aWandererC + RotL64(aScatter, 23U)) + 1492411503643460886U;
            aOrbiterF = (aWandererF + RotL64(aIngress, 12U)) + 17369549067879344180U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 7301713524358676722U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 2985193736033012535U;
            aOrbiterJ = RotL64((aOrbiterJ * 7473297294949338265U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 14086975808140927408U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 10390516547834639800U;
            aOrbiterA = RotL64((aOrbiterA * 11441293212275890819U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 18205555540941493267U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 16967799565443938873U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3009081009044782443U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 9209505304067579944U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 3522631966146762306U;
            aOrbiterC = RotL64((aOrbiterC * 3441982898533162599U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 8811497120829041188U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 14707301680850257294U;
            aOrbiterI = RotL64((aOrbiterI * 11383709499376464085U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 10080595991787801029U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 6822892187784299166U;
            aOrbiterF = RotL64((aOrbiterF * 7417016898027778287U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 1981637172055758689U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 16463077485583119324U;
            aOrbiterE = RotL64((aOrbiterE * 2876782050665869121U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 8383837717361569465U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 2788511294985017326U;
            aOrbiterG = RotL64((aOrbiterG * 2809163242875130677U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 3529607472855930041U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 8850940802020173766U;
            aOrbiterB = RotL64((aOrbiterB * 7821450253655655943U), 5U);
            //
            aIngress = RotL64(aOrbiterG, 11U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + RotL64(aOrbiterI, 36U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 58U) + RotL64(aOrbiterE, 56U)) + aOrbiterG) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 23U)) + aOrbiterD) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 47U) + RotL64(aOrbiterJ, 47U)) + aOrbiterE);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 39U)) + aOrbiterI);
            aWandererI = aWandererI + ((((RotL64(aCross, 39U) + aOrbiterC) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 11U)) + aPhaseAWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 5U) + aOrbiterJ) + RotL64(aOrbiterB, 34U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterB, 13U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 34U) + aOrbiterA) + RotL64(aOrbiterI, 19U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 21U) + aOrbiterI) + RotL64(aOrbiterD, 3U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 34U));
            aCarry = aCarry + RotL64(aWandererA, 23U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 6323U)) & S_BLOCK1], 52U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 5840U)) & W_KEY1], 11U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6362U)) & W_KEY1], 3U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 8009U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 5620U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aIngress, 36U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = ((aWandererA + RotL64(aCross, 57U)) + RotL64(aCarry, 47U)) + 2168513956284366370U;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 11U)) + 10290361969974613111U) + aPhaseAOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aIngress, 3U)) + 15673836275828498050U;
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 24U)) + RotL64(aCarry, 57U)) + 16600540024145812236U;
            aOrbiterE = (aWandererK + RotL64(aCross, 29U)) + 9428052101528111892U;
            aOrbiterA = (aWandererE + RotL64(aIngress, 35U)) + 12763657928312763377U;
            aOrbiterF = (aWandererC + RotL64(aPrevious, 53U)) + 10751286982008662485U;
            aOrbiterD = (((aWandererB + RotL64(aScatter, 41U)) + RotL64(aCarry, 39U)) + 1708230173038057979U) + aPhaseAOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (aWandererG + RotL64(aCross, 20U)) + 4011389705422783816U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 11704428328093077714U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 2055336619674699284U;
            aOrbiterC = RotL64((aOrbiterC * 6374289210096410907U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 1870865272102705804U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 3574214263751923179U;
            aOrbiterI = RotL64((aOrbiterI * 13132083406834413563U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 984611970726966186U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 15207945449947643672U;
            aOrbiterF = RotL64((aOrbiterF * 9539470161576639981U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 4181398506373973169U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 15222345431506025949U;
            aOrbiterA = RotL64((aOrbiterA * 6925143692628659467U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 15023513452326240962U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 14965669361708810699U;
            aOrbiterD = RotL64((aOrbiterD * 587008860996713147U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 7985755518735406360U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 225592097619240187U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2313509354133400439U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 3659537916566939383U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 17043668033610689611U;
            aOrbiterJ = RotL64((aOrbiterJ * 10797634709118100773U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 10217321522161675848U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 8013663869536146842U;
            aOrbiterE = RotL64((aOrbiterE * 2293233079384777175U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 13762445330867496042U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 2692400019659269106U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 167704184292219399U), 5U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 39U);
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterB, 26U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 4U) + aOrbiterJ) + RotL64(aOrbiterE, 6U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterE, 41U)) + aPhaseAWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 27U) + aOrbiterE) + RotL64(aOrbiterI, 57U));
            aWandererE = aWandererE + (((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 47U)) + aOrbiterJ) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterJ, 29U));
            aWandererK = aWandererK + (((RotL64(aCross, 40U) + aOrbiterH) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterF, 24U)) + aOrbiterC);
            aWandererD = aWandererD + ((RotL64(aIngress, 57U) + RotL64(aOrbiterA, 13U)) + aOrbiterI);
            aWandererC = aWandererC ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 37U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + (RotL64(aWandererG, 4U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererJ, 53U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 8380U)) & S_BLOCK1], 21U) ^ RotL64(aKeyRowReadB[((aIndex + 9775U)) & W_KEY1], 40U));
            aIngress ^= (RotL64(mSource[((aIndex + 8625U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9202U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 8263U)) & W_KEY1], 10U) ^ RotL64(aWorkLaneB[((aIndex + 10044U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCarry, 4U)) ^ (RotL64(aPrevious, 51U) + RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = (aWandererD + RotL64(aPrevious, 53U)) + 9133751643283278896U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 22U)) + 8971581804375380408U;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 35U)) + 12559650383714566592U) + aPhaseBOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aCross, 43U)) + 15753206088872859163U;
            aOrbiterE = (aWandererJ + RotL64(aIngress, 3U)) + 7640756270450762350U;
            aOrbiterG = ((aWandererC + RotL64(aCross, 39U)) + RotL64(aCarry, 51U)) + 7340073357551376125U;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 47U)) + 5270256573644196046U;
            aOrbiterK = (((aWandererB + RotL64(aScatter, 27U)) + RotL64(aCarry, 43U)) + 3567367996479995928U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 60U)) + RotL64(aCarry, 13U)) + 11939634537492733738U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 7051817732424527120U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 1730487669951837941U;
            aOrbiterH = RotL64((aOrbiterH * 15191634337956285841U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 18009252467909454817U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 2361024272031696442U;
            aOrbiterE = RotL64((aOrbiterE * 15215151562500226027U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 15902755877642960397U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 12243517544704116184U;
            aOrbiterA = RotL64((aOrbiterA * 2576071074148141447U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 16846181962302186187U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 636121425116506681U;
            aOrbiterG = RotL64((aOrbiterG * 17075030673338779993U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6887385655828217318U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 3705834550934775862U;
            aOrbiterK = RotL64((aOrbiterK * 11275428284929594435U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 11165142437077969438U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 6426659930331618269U;
            aOrbiterB = RotL64((aOrbiterB * 17170640810530893705U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 12629082390899315789U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 4277510580069574724U;
            aOrbiterF = RotL64((aOrbiterF * 9829125163412708305U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 13814834144170469978U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 3698381854100295826U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5126359230872258015U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 11623170635983579937U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 7247413650388803796U;
            aOrbiterC = RotL64((aOrbiterC * 3403219499465560059U), 35U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 36U);
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + (RotL64(aOrbiterC, 51U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterH, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 38U) + aOrbiterK) + RotL64(aOrbiterH, 47U));
            aWandererB = aWandererB + ((RotL64(aScatter, 51U) + aOrbiterK) + RotL64(aOrbiterB, 19U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterH, 13U)) + aOrbiterE);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterA, 4U)) + RotL64(aCarry, 41U)) + aPhaseBWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterC, 23U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 43U)) + aOrbiterC);
            aWandererE = aWandererE ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterF, 27U)) + aOrbiterI);
            aWandererD = aWandererD + (((RotL64(aIngress, 10U) + aOrbiterK) + RotL64(aOrbiterG, 39U)) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 57U) + aOrbiterE) + RotL64(aOrbiterC, 60U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (RotL64(aWandererH, 22U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 11655U)) & S_BLOCK1], 44U) ^ RotL64(aKeyRowReadA[((aIndex + 12618U)) & W_KEY1], 57U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 11859U)) & W_KEY1], 29U) ^ RotL64(mSource[((aIndex + 13345U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 12470U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11443U)) & S_BLOCK1], 29U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 13422U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 6U)) ^ (RotL64(aIngress, 23U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = (aWandererE + RotL64(aPrevious, 57U)) + 8402620908307642697U;
            aOrbiterH = (aWandererG + RotL64(aIngress, 39U)) + 11347672014525086047U;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 4U)) + 2816462912503401876U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (aWandererJ + RotL64(aCross, 47U)) + 6940159795470696093U;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 19U)) + 9134692490095883851U) + aPhaseBOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 13U)) + RotL64(aCarry, 43U)) + 4999455497008026526U;
            aOrbiterF = (aWandererD + RotL64(aScatter, 43U)) + 5992451460350651332U;
            aOrbiterI = ((aWandererK + RotL64(aCross, 26U)) + RotL64(aCarry, 53U)) + 3417087346651371924U;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 51U)) + RotL64(aCarry, 11U)) + 3612773820086198270U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 463398077083428570U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 11249391303705089012U;
            aOrbiterC = RotL64((aOrbiterC * 7106735772303292983U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 17027535139825739501U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 568131384979596481U;
            aOrbiterB = RotL64((aOrbiterB * 5683451044852895957U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 4793712537158004047U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 10415170179135963622U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13729564030210361415U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 2391473979460065630U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 4240058362680064261U;
            aOrbiterK = RotL64((aOrbiterK * 12375884373396400889U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 9963957011090031698U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 3325305624067445525U;
            aOrbiterD = RotL64((aOrbiterD * 3128542681461806309U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 2094945647665114693U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 10703615640774042674U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12641986098450423751U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 3768738815518590289U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 15021301790376706827U;
            aOrbiterG = RotL64((aOrbiterG * 14445850924223550339U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 10571246886181608316U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 5130325144599151793U;
            aOrbiterH = RotL64((aOrbiterH * 3185251943547657467U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 8617523421720966373U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 16574597770835250074U;
            aOrbiterJ = RotL64((aOrbiterJ * 1759209403428937799U), 19U);
            //
            aIngress = RotL64(aOrbiterF, 35U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterH, 30U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + RotL64(aOrbiterC, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 23U) + aOrbiterD) + RotL64(aOrbiterI, 29U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 57U) + aOrbiterG) + RotL64(aOrbiterD, 52U)) + RotL64(aCarry, 39U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterG, 47U)) + aOrbiterH);
            aWandererD = aWandererD + ((RotL64(aIngress, 38U) + RotL64(aOrbiterF, 57U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterK, 23U)) + aPhaseBWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 4U)) + aOrbiterG);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterH, 19U)) + aOrbiterF);
            aWandererK = aWandererK + (((RotL64(aCross, 42U) + RotL64(aOrbiterF, 35U)) + aOrbiterC) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 13U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + RotL64(aWandererE, 6U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 14233U)) & S_BLOCK1], 39U) ^ RotL64(aInvestLaneA[((aIndex + 15799U)) & S_BLOCK1], 18U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15034U)) & W_KEY1], 5U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 16005U)) & W_KEY1], 60U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 15706U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 14155U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15681U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 13U) ^ RotL64(aCarry, 26U)) ^ (RotL64(aIngress, 41U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = (aWandererJ + RotL64(aCross, 3U)) + 7632760812370906911U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 24U)) + 6007174525479723089U;
            aOrbiterE = (aWandererK + RotL64(aIngress, 43U)) + 3362829642521821048U;
            aOrbiterC = (((aWandererE + RotL64(aPrevious, 35U)) + RotL64(aCarry, 41U)) + 18009548556107978286U) + aPhaseBOrbiterAssignSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aIngress, 57U)) + RotL64(aCarry, 5U)) + 17880909432272697327U;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 48U)) + 15961567935420752568U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aCross, 11U)) + 10136559064656837921U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 29U)) + RotL64(aCarry, 27U)) + 17622019364405410277U;
            aOrbiterI = (aWandererH + RotL64(aIngress, 39U)) + 6927494824421416306U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 7125170407794874847U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 12342273503071032250U;
            aOrbiterE = RotL64((aOrbiterE * 867417849555857179U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 14997696377476124836U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 14874498694181230698U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4026127545746010937U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 2549397729130885686U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 4217995818662767955U;
            aOrbiterD = RotL64((aOrbiterD * 5525525344485251063U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 4706089044415442525U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 17983900172670031015U;
            aOrbiterF = RotL64((aOrbiterF * 541552737180932879U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 1904937798143929988U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 10620877287033139483U;
            aOrbiterB = RotL64((aOrbiterB * 16711012562024287213U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 15681091173163181525U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 2655543246639000084U;
            aOrbiterC = RotL64((aOrbiterC * 16686375598149755947U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 2647895110857289213U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 5581609212017175954U;
            aOrbiterI = RotL64((aOrbiterI * 15330263616699031311U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 13609076329627787987U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 6244266279516622070U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12488345779236971095U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 5289624364508923581U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 16351476803965903112U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9012522724650442597U), 47U);
            //
            aIngress = RotL64(aOrbiterE, 18U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 51U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterH, 50U)) + aOrbiterE) + aPhaseBWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterD, 39U)) + aOrbiterC);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 54U) + aOrbiterD) + RotL64(aOrbiterG, 35U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 39U) + aOrbiterI) + RotL64(aOrbiterB, 57U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterE, 43U)) + aOrbiterG) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterA, 21U));
            aWandererF = aWandererF + ((RotL64(aIngress, 13U) + aOrbiterC) + RotL64(aOrbiterE, 28U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterH, 3U));
            aWandererB = aWandererB + ((((RotL64(aCross, 30U) + aOrbiterB) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 13U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererK, 12U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 19031U)) & S_BLOCK1], 18U) ^ RotL64(aKeyRowReadA[((aIndex + 17503U)) & W_KEY1], 43U));
            aIngress ^= (RotL64(mSource[((aIndex + 17942U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18205U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 17342U)) & W_KEY1], 43U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 17314U)) & S_BLOCK1], 18U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 18604U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 11U)) ^ (RotL64(aCross, 60U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = (aWandererE + RotL64(aIngress, 47U)) + 12222235191147985484U;
            aOrbiterD = (aWandererD + RotL64(aScatter, 28U)) + 16367317014523328414U;
            aOrbiterB = (aWandererJ + RotL64(aCross, 11U)) + 3511378091284703789U;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 53U)) + 15247492830966725949U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aIngress, 5U)) + RotL64(aCarry, 23U)) + 7745995913390407897U;
            aOrbiterA = ((aWandererF + RotL64(aScatter, 19U)) + 6463593307540108810U) + aPhaseCOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aCross, 35U)) + 1101669311005268630U;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 57U)) + RotL64(aCarry, 35U)) + 12988052764067518580U;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 24U)) + RotL64(aCarry, 5U)) + 17717179747434679772U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 11662190906682400416U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 6563014073547628748U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16967910471722117761U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 13099094932059419219U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 16342730862261868847U;
            aOrbiterG = RotL64((aOrbiterG * 10988124108686164829U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 16855346813127524624U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 6570063128502306944U;
            aOrbiterD = RotL64((aOrbiterD * 4571570049463124831U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 11328352033809240501U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 11640986648833160901U;
            aOrbiterF = RotL64((aOrbiterF * 2895830492089678919U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 2675226158571501666U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 17700531248266458165U;
            aOrbiterH = RotL64((aOrbiterH * 2231403813970188657U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 7729597396731910874U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 15172374484412053756U;
            aOrbiterE = RotL64((aOrbiterE * 149009041406406517U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 9178769489257842683U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 9020154972097834926U;
            aOrbiterA = RotL64((aOrbiterA * 8910504667566521429U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 1317403761217790562U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 17151528554929201571U;
            aOrbiterJ = RotL64((aOrbiterJ * 3735945655450625203U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 11621882033959669977U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 10289504450815075623U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13365982786836243195U), 19U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 53U);
            aIngress = aIngress + (RotL64(aOrbiterG, 37U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 10U));
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aCross, 23U) + RotL64(aOrbiterK, 38U)) + aOrbiterF) + RotL64(aCarry, 5U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterG, 43U));
            aWandererF = aWandererF + (((RotL64(aIngress, 42U) + RotL64(aOrbiterE, 23U)) + aOrbiterK) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 53U) + aOrbiterB) + RotL64(aOrbiterG, 5U)) + aPhaseCWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterJ, 19U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 53U)) + aOrbiterE);
            aWandererG = aWandererG + ((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterG, 27U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterH, 11U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 60U) + RotL64(aOrbiterG, 34U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 10U));
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 21474U)) & S_BLOCK1], 37U) ^ RotL64(mSource[((aIndex + 21112U)) & S_BLOCK1], 23U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 20074U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneA[((aIndex + 20399U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 19440U)) & W_KEY1], 53U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 21525U)) & W_KEY1], 13U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21320U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneB[((aIndex + 19385U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCross, 6U)) + (RotL64(aCarry, 19U) ^ RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = (aWandererH + RotL64(aIngress, 29U)) + 8101351470141807662U;
            aOrbiterB = (aWandererA + RotL64(aCross, 3U)) + 6965474099521076705U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 10U)) + 6803828268885684784U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aScatter, 35U)) + 13454235922950972488U) + aPhaseCOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aIngress, 39U)) + 11678091885751244777U;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 57U)) + RotL64(aCarry, 23U)) + 5307134544628507141U;
            aOrbiterI = ((aWandererG + RotL64(aCross, 53U)) + RotL64(aCarry, 43U)) + 4873703518950429353U;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 19U)) + RotL64(aCarry, 3U)) + 8542156221858586039U;
            aOrbiterH = (aWandererC + RotL64(aIngress, 46U)) + 3993726182905296513U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 12113047622035464386U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 1944244448665721151U;
            aOrbiterD = RotL64((aOrbiterD * 7010050836758762003U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 12914188029425467576U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 2486762763475327024U;
            aOrbiterA = RotL64((aOrbiterA * 12319769994433811617U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 14580191602982245481U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 12093414832400135066U;
            aOrbiterB = RotL64((aOrbiterB * 12720286833215690663U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 13623906997320021065U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 9977356009806428696U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2005536391712733499U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 3694954095397810851U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 11453812627797091638U;
            aOrbiterC = RotL64((aOrbiterC * 13730420725113907161U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 542311345544726351U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 3024285045990499484U;
            aOrbiterJ = RotL64((aOrbiterJ * 5153745952148205645U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 15397664082460849530U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 10716856680110815056U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13947203772929252823U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 833342121331428547U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 1111339940097269219U;
            aOrbiterG = RotL64((aOrbiterG * 17991642769781175473U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 9312963978841402871U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 8225496710723213204U;
            aOrbiterH = RotL64((aOrbiterH * 894499195498817065U), 47U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 13U);
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterC, 10U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 53U) + RotL64(aOrbiterD, 26U)) + aOrbiterG) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterA, 47U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 47U) + aOrbiterH) + RotL64(aOrbiterC, 43U)) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 14U) + aOrbiterJ) + RotL64(aOrbiterB, 35U));
            aWandererH = aWandererH + ((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterB, 57U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 39U)) + aOrbiterK);
            aWandererG = aWandererG + (((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 22U)) + aOrbiterD) + RotL64(aCarry, 39U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 10U) + RotL64(aOrbiterD, 11U)) + aOrbiterI);
            aWandererA = aWandererA + ((RotL64(aCross, 27U) + aOrbiterC) + RotL64(aOrbiterA, 53U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (RotL64(aWandererG, 44U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 21U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 23391U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadA[((aIndex + 23113U)) & W_KEY1], 38U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 21865U)) & W_KEY1], 47U) ^ RotL64(aFireLaneC[((aIndex + 24434U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 23784U)) & S_BLOCK1], 56U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 22182U)) & S_BLOCK1], 43U));
            aCross ^= (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 22171U)) & S_BLOCK1], 27U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 23318U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 40U)) + (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = (aWandererA + RotL64(aPrevious, 23U)) + 15910560457440369082U;
            aOrbiterD = ((aWandererF + RotL64(aIngress, 47U)) + RotL64(aCarry, 29U)) + 17953072986407436888U;
            aOrbiterH = (aWandererD + RotL64(aScatter, 19U)) + 15446940721193538669U;
            aOrbiterK = (((aWandererE + RotL64(aCross, 12U)) + RotL64(aCarry, 21U)) + 3020785262774422009U) + aPhaseCOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = (aWandererI + RotL64(aPrevious, 51U)) + 7001288645424994404U;
            aOrbiterA = (aWandererK + RotL64(aIngress, 41U)) + 13385250665458462689U;
            aOrbiterB = (aWandererB + RotL64(aCross, 35U)) + 4841895644623005949U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 58U)) + RotL64(aCarry, 37U)) + 13053476783239482065U;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 27U)) + 641996979335975244U) + aPhaseCOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 16211238020928688299U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 12715448751323279480U;
            aOrbiterH = RotL64((aOrbiterH * 2116880429675303291U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 17784406727699995290U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 16626339815786580778U;
            aOrbiterI = RotL64((aOrbiterI * 13940754474750138041U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 9035070625716345139U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 6085848172494001945U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10405728912339646693U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 1177103851507561053U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 2281901691017816407U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3142197009403602497U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 9040984343694325070U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 13334258224023902365U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4782523727707164869U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 1079824790138592518U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 14024082692012948652U;
            aOrbiterJ = RotL64((aOrbiterJ * 3219489374333737903U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 2966776524421278970U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 5510281854029308547U;
            aOrbiterC = RotL64((aOrbiterC * 9275402927591867297U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 7126632329316720048U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 1476827035602733472U;
            aOrbiterK = RotL64((aOrbiterK * 2217671289726794033U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 6470212302133184965U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 4172257438373147415U;
            aOrbiterE = RotL64((aOrbiterE * 4449314239630366533U), 57U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterC, 29U);
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterB, 56U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 18U) + RotL64(aOrbiterK, 18U)) + aOrbiterB);
            aWandererB = aWandererB + ((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 23U)) + aOrbiterC);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 39U) + aOrbiterA) + RotL64(aOrbiterB, 57U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 23U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterK, 44U)) + aOrbiterI);
            aWandererA = aWandererA + (((RotL64(aPrevious, 23U) + aOrbiterH) + RotL64(aOrbiterA, 39U)) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 48U) + RotL64(aOrbiterE, 29U)) + aOrbiterD) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 5U) + RotL64(aOrbiterJ, 51U)) + aOrbiterD);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 29U) + aOrbiterI) + RotL64(aOrbiterH, 13U)) + aPhaseCWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + (RotL64(aWandererG, 24U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 29U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 26122U)) & S_BLOCK1], 4U) ^ RotL64(aKeyRowReadA[((aIndex + 25221U)) & W_KEY1], 47U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 26229U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneB[((aIndex + 24581U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 25988U)) & W_KEY1], 27U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26796U)) & S_BLOCK1], 47U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 26482U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 26230U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 29U) + RotL64(aPrevious, 13U)) ^ (RotL64(aCarry, 54U) ^ RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 23U)) + 5576732410244514238U;
            aOrbiterK = (((aWandererI + RotL64(aScatter, 57U)) + RotL64(aCarry, 27U)) + 2833808925935929629U) + aPhaseDOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aCross, 14U)) + 3670188682914544792U;
            aOrbiterD = (aWandererD + RotL64(aIngress, 47U)) + 15759072378887814995U;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 41U)) + RotL64(aCarry, 13U)) + 13934007231137439994U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 27U)) + RotL64(aCarry, 51U)) + 11022225696007690512U;
            aOrbiterB = (aWandererH + RotL64(aIngress, 53U)) + 16989177104453635790U;
            aOrbiterG = (aWandererG + RotL64(aScatter, 34U)) + 9256930045263527091U;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 19U)) + 17788596104417068290U) + aPhaseDOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 17044369456673337625U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 1310908395523250343U;
            aOrbiterI = RotL64((aOrbiterI * 16305084373037705921U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 12067065689034065422U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 15130844248737512262U;
            aOrbiterF = RotL64((aOrbiterF * 9409499577465934107U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 14532689204495587494U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 8198147292120244178U;
            aOrbiterJ = RotL64((aOrbiterJ * 1418356389507740991U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 5485494458627163347U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 10830008207150307611U;
            aOrbiterK = RotL64((aOrbiterK * 6526039534042499457U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 17770065502486618029U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 6397859353395335459U;
            aOrbiterC = RotL64((aOrbiterC * 14286997752368893825U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 5128700697381508319U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 7103394110057060499U;
            aOrbiterB = RotL64((aOrbiterB * 5053680689949149633U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 16024401282261796979U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 12818445221897253410U;
            aOrbiterG = RotL64((aOrbiterG * 11450004517784155405U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 13386978409145916350U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 16740821954556699503U;
            aOrbiterH = RotL64((aOrbiterH * 5376430209628515105U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 313978038530994953U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 1355733685461795345U;
            aOrbiterD = RotL64((aOrbiterD * 15955927322082619735U), 35U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterC, 60U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 12U) + RotL64(aOrbiterK, 35U)) + aOrbiterI) + aPhaseDWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 48U)) + aOrbiterH) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 39U) + aOrbiterB) + RotL64(aOrbiterJ, 19U));
            aWandererH = aWandererH + ((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterF, 5U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterF, 29U));
            aWandererB = aWandererB + ((((RotL64(aCross, 3U) + RotL64(aOrbiterC, 53U)) + aOrbiterG) + RotL64(aCarry, 13U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 53U) + aOrbiterH) + RotL64(aOrbiterD, 39U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 19U) + aOrbiterB) + RotL64(aOrbiterK, 23U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterG, 14U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererI, 4U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + RotL64(aWandererK, 43U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 27761U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneD[((aIndex + 27899U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 29893U)) & W_KEY1], 48U) ^ RotL64(aFireLaneC[((aIndex + 28682U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 27535U)) & W_KEY1], 37U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 27380U)) & S_BLOCK1], 26U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28791U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 28790U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCross, 40U)) ^ (RotL64(aCarry, 57U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = (aWandererB + RotL64(aCross, 43U)) + 11450949896247900941U;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 21U)) + RotL64(aCarry, 53U)) + 3905542253538116335U;
            aOrbiterD = (aWandererF + RotL64(aPrevious, 29U)) + 9529740545977785305U;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 60U)) + 1856876631533143492U;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 13U)) + 84253466320181686U) + aPhaseDOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 35U)) + 12577480918745432444U;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 51U)) + 5625703170397704029U) + aPhaseDOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 34U)) + RotL64(aCarry, 43U)) + 694608607323629282U;
            aOrbiterC = (aWandererH + RotL64(aCross, 47U)) + 3993981243536262204U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 4119215953484892051U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 8785040118556157146U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17113521266125471625U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 16234403619456882890U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 10398727475672860610U;
            aOrbiterG = RotL64((aOrbiterG * 5086871400049644715U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 18327987141759096769U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 2645964788056875452U;
            aOrbiterH = RotL64((aOrbiterH * 8778681366114628045U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 2859452497983106129U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 7196557924940881076U;
            aOrbiterA = RotL64((aOrbiterA * 14415389907490256711U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 930127943984174668U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 15673596916054795749U;
            aOrbiterI = RotL64((aOrbiterI * 7505660488733199479U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 16673140529110941163U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 2258448294877833760U;
            aOrbiterF = RotL64((aOrbiterF * 1821550319748977445U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 6870209259643931219U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 12749790107942194104U;
            aOrbiterC = RotL64((aOrbiterC * 4871407285968611725U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 17131374134617173866U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 6426448390733751612U;
            aOrbiterJ = RotL64((aOrbiterJ * 12490559588384058417U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 15592826434339731146U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 14182944418026376183U;
            aOrbiterE = RotL64((aOrbiterE * 7218860482893476233U), 57U);
            //
            aIngress = RotL64(aOrbiterJ, 39U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 42U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 12U) + RotL64(aOrbiterJ, 57U)) + aOrbiterD);
            aWandererF = aWandererF + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterE, 47U)) + aOrbiterC) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 51U) + aOrbiterH) + RotL64(aOrbiterD, 29U));
            aWandererG = aWandererG + ((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterI, 53U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 29U) + aOrbiterI) + RotL64(aOrbiterG, 12U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 23U) + aOrbiterI) + RotL64(aOrbiterJ, 23U)) + aPhaseDWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterF, 19U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 39U)) + aOrbiterD) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 60U) + aOrbiterI) + RotL64(aOrbiterE, 4U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 14U));
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 30505U)) & S_BLOCK1], 23U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 32574U)) & W_KEY1], 36U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 32638U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32258U)) & S_BLOCK1], 41U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31636U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadB[((aIndex + 32040U)) & W_KEY1], 11U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 37U) + RotL64(aCross, 6U)) ^ (RotL64(aCarry, 19U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = ((aWandererF + RotL64(aScatter, 39U)) + RotL64(aCarry, 3U)) + 9774364261626083532U;
            aOrbiterC = (aWandererJ + RotL64(aCross, 43U)) + 18059001521926116420U;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 4U)) + 10615626210406381148U;
            aOrbiterD = ((aWandererH + RotL64(aIngress, 47U)) + RotL64(aCarry, 21U)) + 10536484278007898620U;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 51U)) + RotL64(aCarry, 39U)) + 13320663045139972700U;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 19U)) + 17127001787268166583U) + aPhaseDOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aCross, 29U)) + 16742574590844166551U) + aPhaseDOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aScatter, 34U)) + 8347719720758228053U;
            aOrbiterH = (aWandererI + RotL64(aCross, 23U)) + 13502468705946051986U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 3512687886188904904U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 495660316165795934U;
            aOrbiterI = RotL64((aOrbiterI * 6724596801190194913U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 5092722552034477356U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 15641128019608284015U;
            aOrbiterB = RotL64((aOrbiterB * 3621036395703527059U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 15421873776811085458U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 17978775513204574125U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 18359600395119440183U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 16617179197537669849U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 1931805387534012528U;
            aOrbiterA = RotL64((aOrbiterA * 3400139345857733775U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 9544923119559308431U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 12930999400470173353U;
            aOrbiterF = RotL64((aOrbiterF * 16791006919271490005U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 13673733276226249890U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 2032263473309124738U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3088728329261360607U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 14868502349358414206U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 10116495537187552321U;
            aOrbiterC = RotL64((aOrbiterC * 1380512121796709469U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 5341113995358179244U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 8415417980279705731U;
            aOrbiterG = RotL64((aOrbiterG * 8521501372683793821U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 2462819265072352463U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 7657062767608441931U;
            aOrbiterD = RotL64((aOrbiterD * 15554638801273540163U), 3U);
            //
            aIngress = RotL64(aOrbiterB, 43U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 18U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 21U));
            aIngress = aIngress + RotL64(aOrbiterC, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 52U) + RotL64(aOrbiterH, 57U)) + aOrbiterA);
            aWandererI = aWandererI + (((RotL64(aIngress, 13U) + RotL64(aOrbiterC, 41U)) + aOrbiterE) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 39U) + aOrbiterB) + RotL64(aOrbiterD, 10U)) + aPhaseDWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 29U) + RotL64(aOrbiterH, 47U)) + aOrbiterG) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 18U) + RotL64(aOrbiterB, 51U)) + aOrbiterE) + aPhaseDWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 5U) + aOrbiterB) + RotL64(aOrbiterA, 3U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 27U)) + aOrbiterF);
            aWandererA = aWandererA + ((RotL64(aIngress, 23U) + aOrbiterA) + RotL64(aOrbiterG, 35U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterA, 14U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (RotL64(aWandererE, 30U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 53U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_Karate_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneC, aExpandLaneC, aExpandLaneD, aInvestLaneC, aFireLaneD, aInvestLaneD, aFireLaneA, aOperationLaneA, aFireLaneB, aOperationLaneB, aOperationLaneC
        // write to: aInvestLaneC, aInvestLaneD, aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // twist_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneC
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 2476U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((aIndex + 4649U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 575U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3578U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneD[((aIndex + 3510U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 26U) + RotL64(aCross, 43U)) ^ (RotL64(aIngress, 57U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = (aWandererF + RotL64(aCross, 57U)) + 3612110001869385068U;
            aOrbiterF = (aWandererK + RotL64(aScatter, 23U)) + 16340824141280225936U;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 3U)) + 15222338965130765231U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = (((aWandererG + RotL64(aIngress, 41U)) + RotL64(aCarry, 3U)) + 6649270508107155041U) + aPhaseEOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aScatter, 35U)) + RotL64(aCarry, 21U)) + 768217258655426384U;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 10U)) + RotL64(aCarry, 53U)) + 4481855259658861851U;
            aOrbiterE = (aWandererD + RotL64(aIngress, 47U)) + 18318041934562434016U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 4212457153804401807U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 16143621095636987628U;
            aOrbiterG = RotL64((aOrbiterG * 6576072860505961427U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 2095664232866642086U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 4339527736737366572U;
            aOrbiterK = RotL64((aOrbiterK * 17503569508822244125U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 13679353177869884790U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 11582168502846418236U;
            aOrbiterE = RotL64((aOrbiterE * 135539430034462861U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 10451330452898542191U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 12951448817640617841U;
            aOrbiterH = RotL64((aOrbiterH * 4141870904192742091U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 15389161934419370747U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 4754886272708253014U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16638243718191281597U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 11746389873929280688U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 12042680172517298768U;
            aOrbiterF = RotL64((aOrbiterF * 3814780289755857543U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 2648103752465009244U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 451594673632597973U;
            aOrbiterB = RotL64((aOrbiterB * 8496763663271072425U), 35U);
            //
            aIngress = RotL64(aOrbiterE, 3U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterB, 35U));
            aWandererF = aWandererF + (((RotL64(aCross, 41U) + RotL64(aOrbiterG, 23U)) + aOrbiterC) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 4U)) + aOrbiterE);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 35U) + aOrbiterF) + RotL64(aOrbiterH, 51U)) + RotL64(aCarry, 47U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterB, 29U));
            aWandererB = aWandererB + ((RotL64(aScatter, 51U) + RotL64(aOrbiterK, 13U)) + aOrbiterH);
            aWandererG = aWandererG ^ (((RotL64(aCross, 58U) + aOrbiterC) + RotL64(aOrbiterF, 57U)) + aPhaseEWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (RotL64(aWandererK, 4U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_b loop 2
        // ingress from: aInvestLaneC, aExpandLaneC, aFireLaneD
        // ingress directions: aInvestLaneC forward forced, aExpandLaneC forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 9031U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((aIndex + 5926U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 10781U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8743U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((aIndex + 8960U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 50U) + RotL64(aCross, 19U)) + (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = ((aWandererF + RotL64(aCross, 35U)) + 5697928251815176134U) + aPhaseEOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = (aWandererD + RotL64(aScatter, 5U)) + 337587740689259575U;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 29U)) + RotL64(aCarry, 41U)) + 4927686903263973950U;
            aOrbiterG = (aWandererJ + RotL64(aIngress, 21U)) + 3742409032569801033U;
            aOrbiterE = (aWandererC + RotL64(aCross, 13U)) + 1608092659172197650U;
            aOrbiterC = (((aWandererG + RotL64(aIngress, 51U)) + RotL64(aCarry, 11U)) + 15848744267145717509U) + aPhaseEOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = ((aWandererA + RotL64(aScatter, 44U)) + RotL64(aCarry, 53U)) + 15300174177963339253U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 14162868453323648628U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 12020167069983729869U;
            aOrbiterJ = RotL64((aOrbiterJ * 2071080217680099017U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 16259538291658723956U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 8516686212464112245U;
            aOrbiterE = RotL64((aOrbiterE * 4731296903548893627U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 3722184575520553132U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 5663609293306386784U;
            aOrbiterB = RotL64((aOrbiterB * 14364218128780764749U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 15265344442454471986U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 3050323350098829515U;
            aOrbiterC = RotL64((aOrbiterC * 5890624677162388135U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 1093356813820599238U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 15167726103772238440U;
            aOrbiterD = RotL64((aOrbiterD * 5719466863561311069U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 15170797965325981472U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 17826286701992981628U;
            aOrbiterG = RotL64((aOrbiterG * 11186808881726573677U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 14710892030473425181U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 397194787697553904U;
            aOrbiterI = RotL64((aOrbiterI * 14368930300818752833U), 13U);
            //
            aIngress = RotL64(aOrbiterE, 35U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterB, 28U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterD, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aCross, 57U) + aOrbiterB) + RotL64(aOrbiterG, 19U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 30U) + aOrbiterD) + RotL64(aOrbiterE, 41U));
            aWandererA = aWandererA + ((RotL64(aIngress, 39U) + aOrbiterC) + RotL64(aOrbiterE, 48U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterD, 5U)) + aOrbiterC);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterI, 57U)) + RotL64(aCarry, 57U)) + aPhaseEWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 51U) + aOrbiterI) + RotL64(aOrbiterG, 27U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterJ, 11U)) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 26U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + RotL64(aWandererF, 39U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aInvestLaneD[((aIndex + 12440U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((aIndex + 13881U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 11938U)) & S_BLOCK1], 6U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 13938U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 12770U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 13812U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 43U) ^ RotL64(aPrevious, 23U)) ^ (RotL64(aIngress, 57U) + RotL64(aCarry, 10U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = ((aWandererF + RotL64(aCross, 14U)) + RotL64(aCarry, 13U)) + 3448371607470865612U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 27U)) + 3743742913651580573U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = ((aWandererC + RotL64(aScatter, 3U)) + 13069491287948807280U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aIngress, 47U)) + RotL64(aCarry, 29U)) + 16872779275586545632U;
            aOrbiterH = (aWandererE + RotL64(aScatter, 37U)) + 17945792656755062795U;
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 57U)) + RotL64(aCarry, 57U)) + 18199747196793731853U;
            aOrbiterI = (aWandererJ + RotL64(aIngress, 21U)) + 15953311878379809513U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 941268763494588338U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 10090221530365796809U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14035236086292997613U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 8335698093307607001U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 6147498804734306100U;
            aOrbiterE = RotL64((aOrbiterE * 6904444049941211327U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 5980246079567570090U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 4152167624425912978U;
            aOrbiterH = RotL64((aOrbiterH * 10019421651535123573U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 14990418790239735916U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 3418668387496597219U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12814077238529863119U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 4206650904177199425U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 3905470780938996069U;
            aOrbiterI = RotL64((aOrbiterI * 16030122739273137005U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 9968672788233080924U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 602258075661864866U;
            aOrbiterD = RotL64((aOrbiterD * 2615726693066300065U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 17751667243048041383U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 2414054413585296027U;
            aOrbiterJ = RotL64((aOrbiterJ * 1049512574773201893U), 51U);
            //
            aIngress = RotL64(aOrbiterJ, 29U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + (RotL64(aOrbiterH, 46U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 36U) + RotL64(aOrbiterA, 11U)) + aOrbiterE);
            aWandererK = aWandererK + ((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterG, 3U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterJ, 29U)) + aPhaseEWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterJ, 60U)) + aOrbiterG) + RotL64(aCarry, 5U)) + aPhaseEWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 37U)) + aOrbiterE);
            aWandererC = aWandererC + (((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 53U)) + aOrbiterI) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterA, 47U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 14U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererF, 39U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 19506U)) & S_BLOCK1], 13U) ^ RotL64(aInvestLaneC[((aIndex + 17312U)) & S_BLOCK1], 40U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 18171U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 18916U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17429U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 18603U)) & S_BLOCK1], 46U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCross, 39U)) + (RotL64(aIngress, 56U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 5U)) + RotL64(aCarry, 53U)) + 18144572925667544139U;
            aOrbiterK = (aWandererD + RotL64(aIngress, 29U)) + 5659758077574059728U;
            aOrbiterG = (((aWandererB + RotL64(aCross, 60U)) + RotL64(aCarry, 37U)) + 6343330616999166392U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 41U)) + 17754639838410839447U) + aPhaseEOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aCross, 47U)) + 9451843819849581729U;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 11U)) + RotL64(aCarry, 13U)) + 7957854457197462212U;
            aOrbiterH = (aWandererF + RotL64(aScatter, 23U)) + 1461994799722205010U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 18002214276252170177U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 14689869073147027164U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12242482963989582191U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 3978104368003440293U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 8512135845221335386U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10506667163729414667U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 1477533446382953439U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 2166717790929947990U;
            aOrbiterK = RotL64((aOrbiterK * 6538884492418324461U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 8082437060686606995U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 4363687722464700362U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7199165810993478887U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 15782763348014924206U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 8572509150015960728U;
            aOrbiterF = RotL64((aOrbiterF * 3340528604891897779U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 12248271773316742521U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 9602078627638561949U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1860631869877427405U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 17244849374768558859U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 1030743048280579012U;
            aOrbiterE = RotL64((aOrbiterE * 10858949914285817051U), 21U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterE, 5U);
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterB, 51U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterG, 13U));
            aWandererF = aWandererF + (((RotL64(aIngress, 53U) + RotL64(aOrbiterJ, 37U)) + aOrbiterF) + aPhaseEWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterH, 29U)) + aOrbiterB);
            aWandererA = aWandererA + (((RotL64(aPrevious, 46U) + RotL64(aOrbiterE, 43U)) + aOrbiterG) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 23U)) + aOrbiterK);
            aWandererE = aWandererE + (((RotL64(aScatter, 5U) + aOrbiterH) + RotL64(aOrbiterE, 6U)) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 28U));
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 26170U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((aIndex + 22558U)) & S_BLOCK1], 12U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 25570U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 23697U)) & S_BLOCK1], 6U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 25969U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 23469U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 54U) + RotL64(aPrevious, 3U)) ^ (RotL64(aCross, 27U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = (((aWandererA + RotL64(aScatter, 40U)) + RotL64(aCarry, 23U)) + 5173905450211892891U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = ((aWandererC + RotL64(aIngress, 21U)) + RotL64(aCarry, 39U)) + 3555542451908039957U;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 47U)) + 11559884700283861559U;
            aOrbiterE = ((aWandererH + RotL64(aCross, 57U)) + RotL64(aCarry, 5U)) + 1352524329968738673U;
            aOrbiterD = (aWandererE + RotL64(aIngress, 29U)) + 8914206450420616349U;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 3U)) + 2251523378498463946U;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 13U)) + 9541575923299247038U) + aPhaseEOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 1239854507907214595U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 17698101462598498934U;
            aOrbiterC = RotL64((aOrbiterC * 2304948713665996433U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 12305566971683256060U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 13804545036303215569U;
            aOrbiterD = RotL64((aOrbiterD * 10359543704152744971U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 10239749097704329264U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 4212214906286320308U;
            aOrbiterB = RotL64((aOrbiterB * 3661436621615751071U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 12192418916967430783U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 4475514289326450361U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17497164630368757887U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 17376102613298827459U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 18129393209955439341U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6404089025014118979U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 4014763724300253568U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 17325007199676828814U;
            aOrbiterI = RotL64((aOrbiterI * 1420888274815627083U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 15480474849292388685U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 14357924730184375449U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16723492259068034209U), 21U);
            //
            aIngress = RotL64(aOrbiterI, 29U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + RotL64(aOrbiterB, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 51U) + aOrbiterE) + RotL64(aOrbiterC, 51U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterK, 37U)) + RotL64(aCarry, 5U)) + aPhaseEWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 10U) + RotL64(aOrbiterI, 3U)) + aOrbiterH);
            aWandererA = aWandererA + ((((RotL64(aCross, 21U) + RotL64(aOrbiterB, 21U)) + aOrbiterC) + RotL64(aCarry, 41U)) + aPhaseEWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 43U) + aOrbiterK) + RotL64(aOrbiterI, 11U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterD, 29U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterC, 58U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 48U));
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererC, 53U);
            aCarry = aCarry + RotL64(aIngress, 12U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28713U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneA[((aIndex + 31621U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30140U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29474U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 32288U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 27559U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 19U)) ^ (RotL64(aCross, 35U) + RotL64(aIngress, 52U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (aWandererJ + RotL64(aCross, 11U)) + 12262991801139086177U;
            aOrbiterJ = (((aWandererF + RotL64(aScatter, 21U)) + RotL64(aCarry, 5U)) + 7963038771924890197U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 30U)) + RotL64(aCarry, 39U)) + 15540520327933568896U;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 51U)) + 8745565892055020722U) + aPhaseEOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aCross, 37U)) + RotL64(aCarry, 21U)) + 16619329199683755286U;
            aOrbiterG = (aWandererE + RotL64(aScatter, 43U)) + 10865705026433867260U;
            aOrbiterE = (aWandererA + RotL64(aPrevious, 57U)) + 2743368697984518059U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 5556006271515473135U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 5355833281353498588U;
            aOrbiterD = RotL64((aOrbiterD * 4190140212757841511U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 8313616108963479829U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 16657121016801866434U;
            aOrbiterI = RotL64((aOrbiterI * 331533349428472477U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 16532226425013000833U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 5800465874932467232U;
            aOrbiterB = RotL64((aOrbiterB * 5966395771690704577U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 17882948163883121328U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 15029375310296563175U;
            aOrbiterE = RotL64((aOrbiterE * 17021415832288477713U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 10170682648007918739U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 11829089574189398773U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15755874363488568849U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 1746524867389196322U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 10217423427886742775U;
            aOrbiterF = RotL64((aOrbiterF * 9166162099575333519U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 1338457710729082656U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 1319981417675542556U;
            aOrbiterG = RotL64((aOrbiterG * 9518448254565489715U), 21U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 19U);
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 4U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterB, 41U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterJ, 5U)) + aOrbiterD) + RotL64(aCarry, 51U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 27U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((RotL64(aCross, 37U) + aOrbiterF) + RotL64(aOrbiterJ, 47U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 34U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltA[((aIndex + 24U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 22U) + aOrbiterE) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterI, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 60U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + RotL64(aWandererB, 27U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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

void TwistExpander_Karate_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
        // read from: aOperationLaneA, aOperationLaneB, aExpandLaneC, aOperationLaneC, aOperationLaneD, aExpandLaneD, aSnowLaneA, aInvestLaneC, aInvestLaneB, aSnowLaneB, aInvestLaneD, aWorkLaneA, aInvestLaneA, aWorkLaneB, aExpandLaneA, aWorkLaneC, aExpandLaneB
        // write to: aSnowLaneA, aSnowLaneB, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // twist_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aExpandLaneC
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aExpandLaneC forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aExpandLaneD
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aExpandLaneD backward/forward random
        // write to: aSnowLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 183U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneB[((aIndex + 576U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 3192U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1209U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 730U)) & S_BLOCK1], 28U));
            aCross ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 1472U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aIngress, 39U)) ^ (RotL64(aPrevious, 11U) + RotL64(aCarry, 60U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 18U)) + 12046647397183218524U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 27U)) + RotL64(aCarry, 11U)) + 2760779375026461991U;
            aOrbiterA = (aWandererC + RotL64(aIngress, 5U)) + 13735454443176855650U;
            aOrbiterE = ((aWandererK + RotL64(aCross, 21U)) + RotL64(aCarry, 57U)) + 4370377000586647724U;
            aOrbiterB = (aWandererE + RotL64(aScatter, 60U)) + 14566322384189969094U;
            aOrbiterK = (aWandererA + RotL64(aCross, 47U)) + 5056565959818422786U;
            aOrbiterF = (aWandererD + RotL64(aPrevious, 13U)) + 8795403810686579209U;
            aOrbiterI = (aWandererF + RotL64(aIngress, 43U)) + 9625947666256011567U;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 11U)) + 1703669290934254701U) + aPhaseFOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aIngress, 41U)) + 6664070663184147951U;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 57U)) + RotL64(aCarry, 41U)) + 2104148316797553431U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 1197910004222596145U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 9922977170060903197U;
            aOrbiterA = RotL64((aOrbiterA * 13047828062605568603U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 2048376210852567829U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 12568990647075931409U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9860242601194210927U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 15026894775772902751U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 3439447160137900629U;
            aOrbiterC = RotL64((aOrbiterC * 1813754963043785165U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 6532671388552829796U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 17261098369835997661U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 568292591215203521U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 3171300991007459947U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 5935563269327662024U;
            aOrbiterB = RotL64((aOrbiterB * 11271790283157765003U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 14290941734320455612U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 12371794745736518824U;
            aOrbiterI = RotL64((aOrbiterI * 12208762336145168647U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 8782840145467637373U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 4067525421190366741U;
            aOrbiterE = RotL64((aOrbiterE * 6671002797916227485U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 11854812920571789853U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 17564890418553131451U;
            aOrbiterG = RotL64((aOrbiterG * 16657184504366731805U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 6250004085193517531U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 2362659992682660827U;
            aOrbiterF = RotL64((aOrbiterF * 4365619310373869859U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 4597159873252831182U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 13197238269207675773U;
            aOrbiterH = RotL64((aOrbiterH * 379653377172816575U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 8552479493772820372U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 12046647397183218524U;
            aOrbiterD = RotL64((aOrbiterD * 17918033655125400323U), 53U);
            //
            aIngress = RotL64(aOrbiterB, 51U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 21U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 60U));
            aIngress = aIngress + RotL64(aOrbiterC, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 35U)) + aOrbiterC);
            aWandererD = aWandererD + (((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterE, 38U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterH, 3U)) + aOrbiterD);
            aWandererC = aWandererC + ((RotL64(aPrevious, 39U) + aOrbiterH) + RotL64(aOrbiterJ, 19U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 12U) + RotL64(aOrbiterA, 23U)) + aOrbiterE);
            aWandererA = aWandererA + (((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 11U)) + aOrbiterK) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterI, 13U)) + aPhaseFWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterH, 56U)) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 51U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((RotL64(aCross, 14U) + RotL64(aOrbiterC, 27U)) + aOrbiterK);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 43U) + aOrbiterG) + RotL64(aOrbiterK, 29U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 28U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 24U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aSnowLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 2
        // ingress from: aSnowLaneA, aOperationLaneC, aOperationLaneD, aInvestLaneC
        // ingress directions: aSnowLaneA forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aInvestLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aInvestLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aInvestLaneB backward/forward random
        // write to: aSnowLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 6617U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneC[((aIndex + 8151U)) & S_BLOCK1], 50U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 10705U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 9736U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 10783U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5489U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 8881U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCross, 23U)) + (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 56U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 41U)) + 18144572925667544139U) + aPhaseFOrbiterAssignSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aCross, 46U)) + RotL64(aCarry, 29U)) + 5659758077574059728U;
            aOrbiterG = (aWandererF + RotL64(aScatter, 53U)) + 6343330616999166392U;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 27U)) + RotL64(aCarry, 41U)) + 17754639838410839447U;
            aOrbiterK = (aWandererC + RotL64(aPrevious, 39U)) + 9451843819849581729U;
            aOrbiterC = (aWandererH + RotL64(aIngress, 21U)) + 7957854457197462212U;
            aOrbiterI = (aWandererK + RotL64(aCross, 43U)) + 1461994799722205010U;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 3U)) + 18002214276252170177U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (aWandererE + RotL64(aIngress, 37U)) + 14689869073147027164U;
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 51U)) + RotL64(aCarry, 35U)) + 3978104368003440293U;
            aOrbiterF = (aWandererJ + RotL64(aScatter, 58U)) + 8512135845221335386U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 1477533446382953439U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 2166717790929947990U;
            aOrbiterG = RotL64((aOrbiterG * 6538884492418324461U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 8082437060686606995U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 4363687722464700362U;
            aOrbiterK = RotL64((aOrbiterK * 7199165810993478887U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 15782763348014924206U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 8572509150015960728U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3340528604891897779U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 12248271773316742521U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 9602078627638561949U;
            aOrbiterJ = RotL64((aOrbiterJ * 1860631869877427405U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 17244849374768558859U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 1030743048280579012U;
            aOrbiterH = RotL64((aOrbiterH * 10858949914285817051U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 17722342363541914280U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 15667504059789880034U;
            aOrbiterA = RotL64((aOrbiterA * 15872269872168533709U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 12645332941998550794U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 9938135244509986497U;
            aOrbiterD = RotL64((aOrbiterD * 16548185968987392957U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 4024609904162105979U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 6732064218696157303U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3815409766145891393U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 14314117137220703583U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 15244765904057473814U;
            aOrbiterE = RotL64((aOrbiterE * 4034571710808047959U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 17441241682018169245U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 11958974379114644873U;
            aOrbiterC = RotL64((aOrbiterC * 11315689206845170303U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 8310839846793796473U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 18144572925667544139U;
            aOrbiterF = RotL64((aOrbiterF * 11668203295511168011U), 39U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterC, 21U);
            aIngress = aIngress + (RotL64(aOrbiterI, 41U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 51U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 60U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aIngress, 13U) + aOrbiterK) + RotL64(aOrbiterG, 41U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterB, 60U)) + aOrbiterF);
            aWandererG = aWandererG + (((RotL64(aPrevious, 53U) + aOrbiterC) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 29U) + aOrbiterF) + RotL64(aOrbiterH, 43U));
            aWandererC = aWandererC + ((RotL64(aCross, 26U) + RotL64(aOrbiterA, 21U)) + aOrbiterK);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 53U)) + aOrbiterD) + aPhaseFWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 39U) + RotL64(aOrbiterB, 27U)) + aOrbiterI) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 18U)) + aOrbiterG);
            aWandererK = aWandererK + (((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterB, 37U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 42U) + RotL64(aOrbiterD, 51U)) + aOrbiterC);
            aWandererE = aWandererE + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 13U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 60U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererG, 41U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aSnowLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 3
        // ingress from: aSnowLaneB, aOperationLaneA, aInvestLaneD
        // ingress directions: aSnowLaneB forward forced, aOperationLaneA forward forced, aInvestLaneD forward/backward random
        // cross from: aSnowLaneA, aOperationLaneC
        // cross directions: aSnowLaneA backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneB[((aIndex + 11867U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneA[((aIndex + 13555U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 15484U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 13429U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneC[((aIndex + 14122U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aIngress, 37U)) + (RotL64(aCross, 10U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = ((aWandererB + RotL64(aIngress, 14U)) + RotL64(aCarry, 39U)) + 13296600294247799698U;
            aOrbiterA = (aWandererE + RotL64(aCross, 29U)) + 5818503518080877515U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 37U)) + RotL64(aCarry, 13U)) + 6735784238734173597U;
            aOrbiterH = (aWandererD + RotL64(aPrevious, 27U)) + 7368398209488856201U;
            aOrbiterD = (aWandererA + RotL64(aScatter, 39U)) + 961734029066455638U;
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 43U)) + RotL64(aCarry, 53U)) + 797011946660892011U;
            aOrbiterB = (aWandererI + RotL64(aCross, 23U)) + 12841876018396622350U;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 60U)) + 16213253970483895623U) + aPhaseFOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = (aWandererK + RotL64(aPrevious, 21U)) + 15186950557113470375U;
            aOrbiterG = (aWandererF + RotL64(aIngress, 11U)) + 5117930310827477341U;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 47U)) + 12265429373166094162U) + aPhaseFOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 13920531346698601568U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 14695405206998211456U;
            aOrbiterK = RotL64((aOrbiterK * 13950964363414164279U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 7851960904825938443U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 9501511171732550190U;
            aOrbiterI = RotL64((aOrbiterI * 5614164120361489613U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 5663365182245722077U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 9607860124321315555U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3461820361914280601U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 18171052650586819280U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 3442698321538580861U;
            aOrbiterC = RotL64((aOrbiterC * 6317525514963824829U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 1491052813469258970U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 3956599824067616133U;
            aOrbiterE = RotL64((aOrbiterE * 2928600779267623085U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 10963841237346073453U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 2303020125591252534U;
            aOrbiterH = RotL64((aOrbiterH * 9969099842343321981U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 14503856057958162356U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 11147548150090597694U;
            aOrbiterD = RotL64((aOrbiterD * 11856382308792700441U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 9191681438318311481U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 13556072770381999852U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 18316231099054203683U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 10103207278550444685U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 10415809965217261104U;
            aOrbiterB = RotL64((aOrbiterB * 16562732599511350217U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 17435033201864058457U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 5540494424887364682U;
            aOrbiterF = RotL64((aOrbiterF * 18230910315317249045U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 18020151683897013854U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 13296600294247799698U;
            aOrbiterG = RotL64((aOrbiterG * 10000194329456668845U), 3U);
            //
            aIngress = RotL64(aOrbiterB, 14U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 23U));
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 21U) + aOrbiterF) + RotL64(aOrbiterB, 18U));
            aWandererG = aWandererG + ((RotL64(aCross, 53U) + aOrbiterK) + RotL64(aOrbiterE, 11U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 13U) + aOrbiterE) + RotL64(aOrbiterA, 51U));
            aWandererA = aWandererA + (((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterC, 37U)) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 42U) + aOrbiterJ) + RotL64(aOrbiterC, 13U));
            aWandererK = aWandererK + (((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterC, 29U)) + aPhaseFWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 53U)) + aOrbiterA);
            aWandererD = aWandererD + (((RotL64(aPrevious, 23U) + aOrbiterD) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterK, 23U));
            aWandererB = aWandererB + ((RotL64(aScatter, 50U) + aOrbiterG) + RotL64(aOrbiterE, 44U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterE, 5U)) + aOrbiterB) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 38U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + (RotL64(aWandererH, 40U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererK, 27U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 19856U)) & S_BLOCK1], 11U) ^ RotL64(aSnowLaneA[((aIndex + 21062U)) & S_BLOCK1], 52U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 18869U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 18650U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneD[((aIndex + 19869U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aPrevious, 19U)) ^ (RotL64(aCarry, 4U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = (aWandererD + RotL64(aIngress, 5U)) + 13333509828310369865U;
            aOrbiterI = (aWandererC + RotL64(aScatter, 56U)) + 7645352517103840797U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 37U)) + 5310766306660062655U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 21U)) + 5165635069832352932U;
            aOrbiterK = ((aWandererE + RotL64(aScatter, 35U)) + RotL64(aCarry, 5U)) + 15684141764734281849U;
            aOrbiterF = (aWandererJ + RotL64(aCross, 39U)) + 3327963374225061738U;
            aOrbiterB = (aWandererK + RotL64(aIngress, 10U)) + 8625811794878848871U;
            aOrbiterG = (aWandererG + RotL64(aPrevious, 29U)) + 7598657468430485291U;
            aOrbiterE = (aWandererA + RotL64(aCross, 41U)) + 2881171216276746485U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 23U)) + RotL64(aCarry, 57U)) + 10237691227222918101U;
            aOrbiterD = (((aWandererH + RotL64(aPrevious, 27U)) + RotL64(aCarry, 23U)) + 6419254255884834497U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 4238455444646479956U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 14936613353493061492U;
            aOrbiterC = RotL64((aOrbiterC * 3544216916806292273U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 15324699725208372627U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 9506640480601832011U;
            aOrbiterK = RotL64((aOrbiterK * 12819564111348390227U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 3709149613660215641U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 1724290199312754307U;
            aOrbiterF = RotL64((aOrbiterF * 12597580418257897965U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 13191172833570139194U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 3686087945377837886U;
            aOrbiterB = RotL64((aOrbiterB * 10883609557429936283U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 10418330386245397022U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 5383531313632347245U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2987755379396160073U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 7414716553072652212U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 11301761123966206201U;
            aOrbiterG = RotL64((aOrbiterG * 1546727321088592187U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 8570229732236388847U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 8773754460060264773U;
            aOrbiterJ = RotL64((aOrbiterJ * 3251360788932563495U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 13636929800504199371U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 5486599841558573720U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2867914211589815153U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 13277541451512422776U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 10409779509190185921U;
            aOrbiterA = RotL64((aOrbiterA * 1926650154570961573U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 7268295836403414306U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 13815969853235433830U;
            aOrbiterD = RotL64((aOrbiterD * 11603750346752441535U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 9353249174240162324U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 13333509828310369865U;
            aOrbiterE = RotL64((aOrbiterE * 10381405217943841655U), 11U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterE, 53U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 20U));
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 30U) + RotL64(aOrbiterJ, 51U)) + aOrbiterI);
            aWandererK = aWandererK + (((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterK, 54U)) + aPhaseFWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 19U)) + aOrbiterE);
            aWandererF = aWandererF + ((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterD, 37U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 27U)) + aOrbiterJ);
            aWandererG = aWandererG + ((((RotL64(aCross, 41U) + RotL64(aOrbiterA, 29U)) + aOrbiterJ) + RotL64(aCarry, 5U)) + aPhaseFWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 47U)) + aOrbiterC);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterK, 40U)) + aOrbiterG);
            aWandererH = aWandererH + ((RotL64(aIngress, 44U) + aOrbiterF) + RotL64(aOrbiterC, 35U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterH, 21U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererB, 34U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 5
        // ingress from: aWorkLaneB, aSnowLaneB, aExpandLaneA
        // ingress directions: aWorkLaneB forward forced, aSnowLaneB forward forced, aExpandLaneA forward/backward random
        // cross from: aWorkLaneA, aSnowLaneA
        // cross directions: aWorkLaneA backward forced, aSnowLaneA backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 22639U)) & S_BLOCK1], 44U) ^ RotL64(aSnowLaneB[((aIndex + 23781U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aExpandLaneA[((aIndex + 22869U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24440U)) & S_BLOCK1], 5U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 24573U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 36U)) + (RotL64(aCarry, 51U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 46U)) + 8793908991006073956U) + aPhaseFOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aScatter, 39U)) + 2932916283348441943U;
            aOrbiterK = ((aWandererE + RotL64(aCross, 3U)) + 11069042087940968262U) + aPhaseFOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aIngress, 57U)) + RotL64(aCarry, 43U)) + 14369628676782894441U;
            aOrbiterE = (aWandererG + RotL64(aScatter, 41U)) + 8602903272780978282U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 43U)) + RotL64(aCarry, 35U)) + 3827036107178568820U;
            aOrbiterH = (aWandererB + RotL64(aIngress, 37U)) + 8905245209036772489U;
            aOrbiterG = (aWandererH + RotL64(aPrevious, 10U)) + 13331387530760017893U;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 23U)) + 9880107580289737823U;
            aOrbiterB = (aWandererK + RotL64(aPrevious, 21U)) + 10199619040626900278U;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 53U)) + RotL64(aCarry, 29U)) + 2466307560891374281U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 13973403407981259448U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 2851460278409385243U;
            aOrbiterK = RotL64((aOrbiterK * 11226902976321781743U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 10365453393815690776U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 2382382358987358791U;
            aOrbiterE = RotL64((aOrbiterE * 481563628980705781U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 5058198848163792422U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 10500434740387593487U;
            aOrbiterA = RotL64((aOrbiterA * 5946747708776079787U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 11289798395177667084U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 14327152153231286666U;
            aOrbiterF = RotL64((aOrbiterF * 18155778059595245561U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 8065137263811956313U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 3865153574847924816U;
            aOrbiterJ = RotL64((aOrbiterJ * 9495741102667755161U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 18102279969722473375U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 6306428427188742325U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17826782872351406167U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 16953348204663693724U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 11950791817032898613U;
            aOrbiterI = RotL64((aOrbiterI * 1498946055469611133U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 11980823193543752994U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 17845490308799454871U;
            aOrbiterD = RotL64((aOrbiterD * 16385153013485463791U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 5566398755702887071U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 10308378271388889968U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 142732084484961281U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 6717846700455219260U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 8297225372883997017U;
            aOrbiterH = RotL64((aOrbiterH * 14102812043481327907U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 12249337046267666603U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 8793908991006073956U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5851229209188473467U), 23U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 47U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + (RotL64(aOrbiterH, 60U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterE, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterB, 60U)) + aOrbiterF);
            aWandererG = aWandererG + ((RotL64(aScatter, 10U) + aOrbiterF) + RotL64(aOrbiterG, 51U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 23U) + aOrbiterE) + RotL64(aOrbiterB, 23U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 13U) + aOrbiterD) + RotL64(aOrbiterA, 53U)) + RotL64(aCarry, 11U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterB, 34U)) + aOrbiterG);
            aWandererH = aWandererH + ((RotL64(aIngress, 60U) + aOrbiterG) + RotL64(aOrbiterK, 3U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 51U) + aOrbiterI) + RotL64(aOrbiterH, 27U));
            aWandererF = aWandererF + (((RotL64(aCross, 47U) + RotL64(aOrbiterJ, 41U)) + aOrbiterE) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterD, 43U));
            aWandererK = aWandererK + (((RotL64(aCross, 3U) + RotL64(aOrbiterI, 11U)) + aOrbiterF) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterC, 21U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 6U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 14U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 35U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 32232U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneA[((aIndex + 30741U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28190U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30741U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31673U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCross, 18U)) ^ (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererC + RotL64(aCross, 5U)) + 1457104756581596530U) + aPhaseFOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aScatter, 40U)) + 6127240317844622874U;
            aOrbiterD = (aWandererB + RotL64(aIngress, 11U)) + 16492290056044189421U;
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 53U)) + 10963676850938416468U;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 19U)) + RotL64(aCarry, 35U)) + 4872917367399752405U;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 57U)) + 15218882377875616148U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 43U)) + RotL64(aCarry, 47U)) + 5934166612122118251U;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 29U)) + RotL64(aCarry, 51U)) + 14215280930872003003U;
            aOrbiterG = (aWandererA + RotL64(aIngress, 36U)) + 11428034799044600979U;
            aOrbiterB = (aWandererE + RotL64(aPrevious, 3U)) + 5453003654321728726U;
            aOrbiterC = (aWandererI + RotL64(aScatter, 47U)) + 14273775120265649389U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 328723770018440271U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 13032190719588211088U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13363368478932798315U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 2386881543033598494U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 1649501123340887116U;
            aOrbiterE = RotL64((aOrbiterE * 11148976582360499033U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 16462401546754210583U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 1510579201823042227U;
            aOrbiterF = RotL64((aOrbiterF * 16287912400104043275U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 6889066000014251983U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 11324594596597724357U;
            aOrbiterJ = RotL64((aOrbiterJ * 15344987814648586023U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 12237796033168436537U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 17306069670330000343U;
            aOrbiterH = RotL64((aOrbiterH * 3167451351403385259U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 14197284538008811658U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 4754134852883071927U;
            aOrbiterA = RotL64((aOrbiterA * 3484427259538998699U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 17201907781639753736U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 8318419319239859855U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10320390501983802091U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 16012488623961565780U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 15583721012865354925U;
            aOrbiterC = RotL64((aOrbiterC * 10656414363201743961U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 14680351201973315018U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 14483973292275372321U;
            aOrbiterK = RotL64((aOrbiterK * 9279222721410811027U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 16324317860030681248U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 7038506963317910910U;
            aOrbiterG = RotL64((aOrbiterG * 2960451734542956767U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 12767672960346001218U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 1457104756581596530U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1560375242310194691U), 51U);
            //
            aIngress = RotL64(aOrbiterC, 30U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 21U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + RotL64(aOrbiterK, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterG, 43U)) + aPhaseFWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 21U) + RotL64(aOrbiterA, 12U)) + aOrbiterF) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 23U) + aOrbiterB) + RotL64(aOrbiterJ, 3U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 11U) + aOrbiterI) + RotL64(aOrbiterD, 41U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 53U) + aOrbiterI) + RotL64(aOrbiterA, 21U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 36U) + RotL64(aOrbiterH, 47U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterC, 39U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aScatter, 51U) + aOrbiterB) + RotL64(aOrbiterH, 18U)) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterG, 23U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 14U) + aOrbiterC) + RotL64(aOrbiterE, 51U)) + aPhaseFWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 57U) + aOrbiterG) + RotL64(aOrbiterF, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 10U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + RotL64(aWandererC, 21U);
            aCarry = aCarry + RotL64(aIngress, 40U);
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

void TwistExpander_Karate_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
        // ingress from: aWorkLaneA, aWorkLaneB, aWorkLaneC
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aWorkLaneC forward/backward random
        // cross from: aWorkLaneB, aWorkLaneC, aWorkLaneD
        // cross directions: aWorkLaneB backward forced, aWorkLaneC backward forced, aWorkLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 1126U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((aIndex + 8104U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 7026U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 7776U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 1434U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 3604U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 47U) ^ RotL64(aPrevious, 18U)) + (RotL64(aIngress, 3U) ^ RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = ((aWandererC + RotL64(aIngress, 58U)) + RotL64(aCarry, 3U)) + 7790166497945719700U;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 11U)) + 7136208896846119188U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 35U)) + RotL64(aCarry, 23U)) + 12123156943355100886U;
            aOrbiterE = ((aWandererA + RotL64(aCross, 43U)) + RotL64(aCarry, 37U)) + 5095546037880875199U;
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 3U)) + 17642705393916765992U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 9918479837334416990U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 4890009823843176466U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16898633181256061239U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 17652590786213674124U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 870002527644696135U;
            aOrbiterC = RotL64((aOrbiterC * 915408393979165539U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 12545429703552643682U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 5310272867406182581U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10420003334833925011U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 3264719049050179440U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 1967241238180278937U;
            aOrbiterE = RotL64((aOrbiterE * 13004319774269457957U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 773883832927040736U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 12766817190261232485U;
            aOrbiterJ = RotL64((aOrbiterJ * 7448864556802318431U), 23U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 53U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterE, 24U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aScatter, 21U) + aOrbiterJ) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 57U)) + aPhaseGWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterD, 3U));
            aWandererD = aWandererD + ((RotL64(aIngress, 6U) + aOrbiterH) + RotL64(aOrbiterJ, 21U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 58U)) + aOrbiterE) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 39U) + RotL64(aOrbiterC, 11U)) + aOrbiterJ) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 52U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 9121U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneB[((aIndex + 10216U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 14705U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 15583U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 12879U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 14544U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aPrevious, 11U)) ^ (RotL64(aCarry, 50U) + RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 13U)) + RotL64(aCarry, 21U)) + 1087148170018530502U;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 3U)) + RotL64(aCarry, 41U)) + 15530846874509311414U;
            aOrbiterI = (((aWandererG + RotL64(aIngress, 57U)) + RotL64(aCarry, 5U)) + 16987358651515511212U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aCross, 44U)) + 12504143181007924259U) + aPhaseGOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aPrevious, 23U)) + 393322117322732418U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 14325937299241887166U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 9395262907017475742U;
            aOrbiterI = RotL64((aOrbiterI * 3442643798173589117U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 13658510441418344769U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 6410754322737005336U;
            aOrbiterA = RotL64((aOrbiterA * 6932217611373076391U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 9257290738538818434U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 7489828960857692286U;
            aOrbiterE = RotL64((aOrbiterE * 16519674788777989043U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 4118778591214588387U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 16619215231168796563U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14876884956536265157U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 11326283811003573430U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 1865401866017614604U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8378326058282460073U), 23U);
            //
            aIngress = RotL64(aOrbiterK, 3U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 24U));
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 24U) + RotL64(aOrbiterE, 51U)) + aOrbiterC) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 3U)) + aOrbiterK) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterI, 14U)) + aOrbiterE);
            aWandererF = aWandererF + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 23U)) + aOrbiterC) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 53U) + aOrbiterI) + RotL64(aOrbiterA, 43U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 35U);
            aCarry = aCarry + RotL64(aIngress, 4U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 17548U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((aIndex + 17666U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 18213U)) & S_BLOCK1], 44U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23767U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16878U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 23500U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aIngress, 60U)) + (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = (((aWandererH + RotL64(aIngress, 48U)) + RotL64(aCarry, 57U)) + 12029393034357490020U) + aPhaseGOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 19U)) + 4526754731580694987U;
            aOrbiterG = (((aWandererF + RotL64(aPrevious, 5U)) + RotL64(aCarry, 23U)) + 17060419646421271853U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aCross, 29U)) + 4128488893837059683U;
            aOrbiterK = ((aWandererI + RotL64(aScatter, 57U)) + RotL64(aCarry, 35U)) + 12706894827547160110U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 12506324593645825056U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 12581344490649250025U;
            aOrbiterG = RotL64((aOrbiterG * 16311882267466003291U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 14357032418199130132U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 15341977701796331249U;
            aOrbiterD = RotL64((aOrbiterD * 6332369248718076031U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 7086602307544733241U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 12398300065276832486U;
            aOrbiterC = RotL64((aOrbiterC * 18157408831225635333U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 2499745046076601988U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 7249361592814001829U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14597139848072319685U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 3254456186337366437U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 3472973415969046680U;
            aOrbiterK = RotL64((aOrbiterK * 14583566953969168353U), 23U);
            //
            aIngress = RotL64(aOrbiterG, 13U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterC, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 13U) + aOrbiterC) + RotL64(aOrbiterG, 57U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 43U) + aOrbiterK) + RotL64(aOrbiterC, 23U)) + RotL64(aCarry, 51U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterD, 41U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 56U) + aOrbiterJ) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 35U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 14U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 46U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + RotL64(aWandererH, 21U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 25292U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneB[((aIndex + 29284U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aExpandLaneA[((aIndex + 28988U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32047U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31455U)) & S_BLOCK1], 18U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 27679U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 13U) + RotL64(aCarry, 60U)) ^ (RotL64(aCross, 27U) + RotL64(aPrevious, 47U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = ((aWandererI + RotL64(aScatter, 19U)) + RotL64(aCarry, 23U)) + 8793908991006073956U;
            aOrbiterK = (aWandererA + RotL64(aCross, 47U)) + 2932916283348441943U;
            aOrbiterA = (((aWandererB + RotL64(aPrevious, 5U)) + RotL64(aCarry, 35U)) + 11069042087940968262U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = (((aWandererH + RotL64(aIngress, 27U)) + RotL64(aCarry, 53U)) + 14369628676782894441U) + aPhaseGOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = (aWandererC + RotL64(aCross, 56U)) + 8602903272780978282U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 3827036107178568820U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 8905245209036772489U;
            aOrbiterA = RotL64((aOrbiterA * 5744017326197157667U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 13331387530760017893U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 9880107580289737823U;
            aOrbiterB = RotL64((aOrbiterB * 10302652857542703753U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 10199619040626900278U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 2466307560891374281U;
            aOrbiterK = RotL64((aOrbiterK * 6295342978834217571U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 13973403407981259448U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 2851460278409385243U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11226902976321781743U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 10365453393815690776U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 2382382358987358791U;
            aOrbiterC = RotL64((aOrbiterC * 481563628980705781U), 5U);
            //
            aIngress = RotL64(aOrbiterC, 51U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterC, 21U)) + aOrbiterG) + aPhaseGWandererUpdateSaltC[((aIndex + 24U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 51U) + RotL64(aOrbiterK, 29U)) + aOrbiterA) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterB, 48U)) + aOrbiterK);
            aWandererC = aWandererC + (((RotL64(aPrevious, 10U) + RotL64(aOrbiterA, 5U)) + aOrbiterB) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterB, 39U)) + aOrbiterG) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 12U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 21U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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

void TwistExpander_Karate_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 871U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((aIndex + 173U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 862U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4859U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2169U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 2109U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 23U)) ^ (RotL64(aCross, 4U) + RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = ((aWandererH + RotL64(aCross, 27U)) + RotL64(aCarry, 51U)) + 11998579547770778580U;
            aOrbiterA = (((aWandererJ + RotL64(aPrevious, 39U)) + RotL64(aCarry, 29U)) + 8409465187298704610U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = (((aWandererA + RotL64(aScatter, 54U)) + RotL64(aCarry, 5U)) + 3470222286110333500U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (aWandererK + RotL64(aIngress, 11U)) + 5704486785203069994U;
            aOrbiterC = (aWandererG + RotL64(aScatter, 3U)) + 10334944660253279633U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 7626852700722567477U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 14631310754943209743U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1958866541508493967U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 807160297237854120U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 5624154783624196107U;
            aOrbiterK = RotL64((aOrbiterK * 2404066593958052159U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 4971444394698940423U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 6340057638461027062U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12027586111086798629U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 9003019862787819481U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 13632057463595873033U;
            aOrbiterA = RotL64((aOrbiterA * 12575202147280216765U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 12766104026871797746U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 4062118445824915939U;
            aOrbiterI = RotL64((aOrbiterI * 13130770039048080701U), 27U);
            //
            aIngress = RotL64(aOrbiterH, 54U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aCross, 21U) + RotL64(aOrbiterH, 56U)) + aOrbiterC);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 10U) + RotL64(aOrbiterI, 13U)) + aOrbiterH) + aPhaseHWandererUpdateSaltC[((aIndex + 28U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterA, 43U)) + RotL64(aCarry, 5U)) + aPhaseHWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 35U)) + aOrbiterK);
            aWandererG = aWandererG + (((RotL64(aCross, 57U) + RotL64(aOrbiterC, 5U)) + aOrbiterK) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (RotL64(aWandererH, 34U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 21U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 8226U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((aIndex + 14764U)) & S_BLOCK1], 20U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8217U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9450U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10511U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9654U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCross, 40U)) + (RotL64(aCarry, 3U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = (aWandererB + RotL64(aPrevious, 29U)) + 12222235191147985484U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 57U)) + RotL64(aCarry, 57U)) + 16367317014523328414U;
            aOrbiterJ = (((aWandererH + RotL64(aCross, 12U)) + RotL64(aCarry, 37U)) + 3511378091284703789U) + aPhaseHOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = (((aWandererA + RotL64(aScatter, 43U)) + RotL64(aCarry, 23U)) + 15247492830966725949U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aCross, 3U)) + 7745995913390407897U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 6463593307540108810U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 1101669311005268630U;
            aOrbiterJ = RotL64((aOrbiterJ * 10550146460887359369U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 12988052764067518580U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 17717179747434679772U;
            aOrbiterF = RotL64((aOrbiterF * 10820310705487638793U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 11662190906682400416U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 6563014073547628748U;
            aOrbiterG = RotL64((aOrbiterG * 16967910471722117761U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 13099094932059419219U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 16342730862261868847U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10988124108686164829U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 16855346813127524624U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 6570063128502306944U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4571570049463124831U), 29U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 19U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 13U)) + aOrbiterG) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 37U) + RotL64(aOrbiterI, 29U)) + aOrbiterE) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 60U) + aOrbiterF) + RotL64(aOrbiterE, 44U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 21U)) + aOrbiterG) + RotL64(aCarry, 13U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterG, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 30U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 21U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 19731U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 21908U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 22930U)) & S_BLOCK1], 42U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17048U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 24353U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 17395U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCarry, 35U)) + (RotL64(aCross, 52U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 13U)) + 9855743441035905047U) + aPhaseHOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aScatter, 5U)) + 8426286937143990276U) + aPhaseHOrbiterAssignSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 37U)) + RotL64(aCarry, 5U)) + 7146752367170267002U;
            aOrbiterH = ((aWandererK + RotL64(aCross, 56U)) + RotL64(aCarry, 57U)) + 12947210066678101726U;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 23U)) + RotL64(aCarry, 37U)) + 15902163559925328965U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 8506649889346449469U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 8226286036430263052U;
            aOrbiterF = RotL64((aOrbiterF * 7264199281303956141U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 2703047093452420216U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 6769351326360139560U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5318104980014706265U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 9857025533281333281U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 238297452132277585U;
            aOrbiterB = RotL64((aOrbiterB * 12974709749856065985U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 7203572312072908931U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 12497027346166575632U;
            aOrbiterA = RotL64((aOrbiterA * 1703586436725662307U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 473851890609048879U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 1664484956453886047U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8566500756326590209U), 11U);
            //
            aIngress = RotL64(aOrbiterG, 19U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + RotL64(aOrbiterA, 4U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 18U) + RotL64(aOrbiterG, 11U)) + aOrbiterH) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterG, 44U)) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 5U) + aOrbiterA) + RotL64(aOrbiterB, 29U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 39U) + aOrbiterF) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 19U)) + aPhaseHWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterH, 57U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 30693U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneB[((aIndex + 25774U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aWorkLaneA[((aIndex + 26498U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29322U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32642U)) & S_BLOCK1], 36U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 25827U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aPrevious, 41U)) ^ (RotL64(aIngress, 5U) + RotL64(aCarry, 18U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = (((aWandererJ + RotL64(aCross, 27U)) + RotL64(aCarry, 13U)) + 12029393034357490020U) + aPhaseHOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = ((aWandererA + RotL64(aScatter, 13U)) + RotL64(aCarry, 27U)) + 4526754731580694987U;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 4U)) + 17060419646421271853U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 47U)) + RotL64(aCarry, 51U)) + 4128488893837059683U;
            aOrbiterA = (aWandererC + RotL64(aScatter, 39U)) + 12706894827547160110U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 12506324593645825056U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 12581344490649250025U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16311882267466003291U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 14357032418199130132U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 15341977701796331249U;
            aOrbiterJ = RotL64((aOrbiterJ * 6332369248718076031U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 7086602307544733241U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 12398300065276832486U;
            aOrbiterA = RotL64((aOrbiterA * 18157408831225635333U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 2499745046076601988U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 7249361592814001829U;
            aOrbiterC = RotL64((aOrbiterC * 14597139848072319685U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 3254456186337366437U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 3472973415969046680U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14583566953969168353U), 43U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 13U);
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 11U) + aOrbiterF) + RotL64(aOrbiterJ, 3U)) + aPhaseHWandererUpdateSaltC[((aIndex + 24U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 21U) + aOrbiterC) + RotL64(aOrbiterD, 46U)) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 29U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 36U) + RotL64(aOrbiterC, 19U)) + aOrbiterJ) + RotL64(aCarry, 5U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 51U) + aOrbiterA) + RotL64(aOrbiterC, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + RotL64(aWandererF, 5U);
            aCarry = aCarry + RotL64(aIngress, 56U);
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
