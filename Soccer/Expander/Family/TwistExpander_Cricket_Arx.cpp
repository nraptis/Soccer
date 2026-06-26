#include "TwistExpander_Cricket_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Cricket_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xAA11E38914CD836FULL + 0x9A2EB96B40FA5F39ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xF3C70B0EBC284F07ULL + 0xEE93B21ECA7B9CE8ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xCB0302CE91CC8E0DULL + 0xC41BDF7A5800FDE8ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xA72FFFEEB31E62F3ULL + 0x8DE29ACC4EA7004CULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x97C418248E9AF11FULL + 0xC4EAFA896F72BD3BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xA5C6C3672E419DB9ULL + 0x8D3E9A6475B71B2DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xADC95EE5A30BB95DULL + 0x958B942033FDAD07ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF134F654D9C138E9ULL + 0xA450D1076A65D536ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 19U) ^ RotL64(aNonceWordC, 43U)) ^ RotL64(aNonceWordH, 51U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 2124U)) & S_BLOCK1], 60U) ^ RotL64(mSnow[((aIndex + 2274U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 56U) ^ RotL64(aNonceWordD, 13U)) ^ RotL64(aNonceWordG, 47U));
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 2647U)) & S_BLOCK1], 5U) ^ RotL64(mSnow[((S_BLOCK1 - aIndex + 3776U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 37U)) + (RotL64(aPrevious, 53U) + RotL64(aCross, 18U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererJ + RotL64(aCross, 44U)) + 3248574644570178787U;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 53U)) + 4506961512959200024U;
            aOrbiterB = (aWandererB + RotL64(aScatter, 5U)) + 8423739774540738590U;
            aOrbiterJ = (((aWandererG + RotL64(aIngress, 41U)) + 6593975869641735337U) + aOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1]) + RotL64(aNonceWordG, 3U);
            aOrbiterG = ((aWandererI + RotL64(aCross, 51U)) + 16441716090557369103U) + aOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 29U)) + RotL64(aCarry, 39U)) + 7936601450453207914U;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 26U)) + RotL64(aCarry, 19U)) + 13333752583560167065U;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 19U)) + 8013703284795432973U) + RotL64(aNonceWordF, 9U);
            aOrbiterH = ((aWandererF + RotL64(aCross, 39U)) + RotL64(aCarry, 13U)) + 2349852779887439236U;
            aOrbiterA = (aWandererC + RotL64(aScatter, 21U)) + 5318539364763284138U;
            aOrbiterF = (aWandererK + RotL64(aPrevious, 57U)) + 11450957608502944376U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 9058992558327552687U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 632095686920230926U;
            aOrbiterB = RotL64((aOrbiterB * 12460364388358520799U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 14734218428913777098U) + aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 16344357661370784442U;
            aOrbiterK = RotL64((aOrbiterK * 15049472842002138369U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 2981145363531184308U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 14176472085175714494U;
            aOrbiterC = RotL64((aOrbiterC * 2584623327412130939U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 11198457590069700889U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 952584436750426828U;
            aOrbiterJ = RotL64((aOrbiterJ * 1165713888651280355U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 4311591763498985972U) + aOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 16194341833989936369U;
            aOrbiterI = RotL64((aOrbiterI * 9997934560195932575U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 7560794022401107431U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 10683789740265711603U;
            aOrbiterH = RotL64((aOrbiterH * 15637823045351977883U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 11614366395125937178U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 10750771385100564416U;
            aOrbiterF = RotL64((aOrbiterF * 4987921274272444283U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 2934697034132204529U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 4646873794658020363U;
            aOrbiterD = RotL64((aOrbiterD * 10555456865641580175U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 7913681837683568905U) + RotL64(aNonceWordH, 10U);
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 17603563535330106340U;
            aOrbiterG = RotL64((aOrbiterG * 17882943067522319671U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 15375641415139193079U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 17059712718085411887U;
            aOrbiterE = RotL64((aOrbiterE * 13722089235751208215U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 14022558453716067200U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 3248574644570178787U) ^ RotL64(aNonceWordB, 21U);
            aOrbiterA = RotL64((aOrbiterA * 15249135451439374621U), 39U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 47U);
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterH, 28U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aIngress, 39U) + RotL64(aOrbiterH, 11U)) + aOrbiterD) + RotL64(aCarry, 37U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterK, 52U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 37U) + RotL64(aOrbiterF, 19U)) + aOrbiterB) + RotL64(aCarry, 53U)) + RotL64(aNonceWordC, 29U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 53U) + aOrbiterE) + RotL64(aOrbiterK, 41U)) + aWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterC, 39U)) + RotL64(aNonceWordD, 59U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 28U) + aOrbiterI) + RotL64(aOrbiterF, 29U));
            aWandererH = aWandererH + ((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 50U)) + aOrbiterH);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 35U)) + aOrbiterI);
            aWandererE = aWandererE + (((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 5U)) + aOrbiterC) + aWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 23U) + aOrbiterJ) + RotL64(aOrbiterI, 21U));
            aWandererD = aWandererD + ((RotL64(aCross, 48U) + RotL64(aOrbiterG, 27U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 34U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 3U) ^ RotL64(aNonceWordF, 47U)) ^ RotL64(aNonceWordC, 57U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 5470U)) & S_BLOCK1], 22U) ^ RotL64(mSnow[((S_BLOCK1 - aIndex + 10403U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 21U) ^ RotL64(aNonceWordB, 29U)) ^ RotL64(aNonceWordH, 5U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10098U)) & S_BLOCK1], 41U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 10214U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 22U) + RotL64(aIngress, 57U)) ^ (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererA + RotL64(aIngress, 53U)) + 11210042748013785976U;
            aOrbiterF = (aWandererH + RotL64(aScatter, 60U)) + 4584747303233477454U;
            aOrbiterD = (aWandererF + RotL64(aCross, 23U)) + 8878765929792969517U;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 19U)) + 2172232330280041122U;
            aOrbiterJ = (aWandererI + RotL64(aScatter, 43U)) + 8378937026022264016U;
            aOrbiterC = (((aWandererE + RotL64(aCross, 41U)) + RotL64(aCarry, 57U)) + 8683007464695824208U) + aOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aIngress, 3U)) + 9564352997357118134U;
            aOrbiterH = ((((aWandererK + RotL64(aPrevious, 47U)) + RotL64(aCarry, 13U)) + 11713878436769887528U) + aOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1]) + RotL64(aNonceWordB, 53U);
            aOrbiterA = (aWandererB + RotL64(aIngress, 5U)) + 8052917623074021077U;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 30U)) + 7720597162792145185U;
            aOrbiterI = (((aWandererJ + RotL64(aScatter, 13U)) + RotL64(aCarry, 51U)) + 2602847785328475621U) + RotL64(aNonceWordH, 38U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 17813669222300509724U) + aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 8724263063156573013U;
            aOrbiterD = RotL64((aOrbiterD * 3632927017737834359U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 6882429835961613492U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 13213313479525717359U) ^ RotL64(aNonceWordC, 45U);
            aOrbiterF = RotL64((aOrbiterF * 2411431247725974895U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 2401526093648669573U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 3616448566579979749U;
            aOrbiterJ = RotL64((aOrbiterJ * 13323155103752121393U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 18268262471839710401U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 5116424918948694752U;
            aOrbiterK = RotL64((aOrbiterK * 7641143782996332069U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 11405305689555640431U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 12427591396711015574U) ^ RotL64(aNonceWordD, 17U);
            aOrbiterA = RotL64((aOrbiterA * 8112834135715541223U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 16960781161508084626U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 12382604781005282628U;
            aOrbiterE = RotL64((aOrbiterE * 17196168631120103115U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 10054839091354729292U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 4167641616532985407U) ^ aOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 919291747187787625U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 14383737233143309039U) + aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 16258779988369405932U;
            aOrbiterC = RotL64((aOrbiterC * 8348773195366160215U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 4777263172049970723U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 12498046021142146499U;
            aOrbiterH = RotL64((aOrbiterH * 5941015011162130901U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 7435001955334177144U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 4100235545173125433U;
            aOrbiterG = RotL64((aOrbiterG * 5046572784117638909U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 1981704568071298614U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 11210042748013785976U;
            aOrbiterI = RotL64((aOrbiterI * 17889749044418386565U), 51U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterD, 60U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + (RotL64(aOrbiterH, 21U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 39U) + RotL64(aOrbiterH, 19U)) + aOrbiterD) + aWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterI, 53U));
            aWandererA = aWandererA + ((RotL64(aIngress, 37U) + aOrbiterA) + RotL64(aOrbiterC, 28U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterF, 21U)) + aOrbiterH);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 21U) + aOrbiterG) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 26U) + aOrbiterF) + RotL64(aOrbiterE, 23U)) + RotL64(aNonceWordA, 37U)) + aWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterG, 26U)) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 37U)) + aOrbiterK);
            aWandererH = aWandererH + ((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterI, 41U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterB, 43U)) + RotL64(aNonceWordE, 51U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 54U) + RotL64(aOrbiterA, 35U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 60U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + RotL64(aWandererB, 34U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 27U) ^ RotL64(aNonceWordE, 43U)) ^ RotL64(aNonceWordD, 51U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 14751U)) & S_BLOCK1], 14U) ^ RotL64(mSnow[((S_BLOCK1 - aIndex + 11371U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 50U) ^ RotL64(aNonceWordF, 27U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13139U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((aIndex + 11982U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aIngress, 37U)) ^ (RotL64(aPrevious, 51U) ^ RotL64(aCarry, 6U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 52U)) + RotL64(aCarry, 11U)) + 17019646486641172469U;
            aOrbiterB = (aWandererC + RotL64(aScatter, 27U)) + 12276141179299971572U;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 3U)) + 3617241694029841555U;
            aOrbiterG = ((aWandererI + RotL64(aCross, 13U)) + 6967963401259371737U) + RotL64(aNonceWordG, 51U);
            aOrbiterA = (aWandererH + RotL64(aPrevious, 21U)) + 6340709284279891017U;
            aOrbiterD = (aWandererE + RotL64(aCross, 30U)) + 456065368903896482U;
            aOrbiterE = (((aWandererD + RotL64(aScatter, 57U)) + 17686765719908116203U) + aOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1]) + RotL64(aNonceWordA, 31U);
            aOrbiterH = ((aWandererK + RotL64(aIngress, 5U)) + 1322045955429785736U) + aOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = (aWandererF + RotL64(aScatter, 11U)) + 5163772703302372887U;
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 43U)) + RotL64(aCarry, 57U)) + 13268431135020363252U;
            aOrbiterF = ((aWandererB + RotL64(aCross, 41U)) + RotL64(aCarry, 37U)) + 6538789950366849332U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 10390344544314544893U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 5087084271300584267U) ^ aOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15149302947570776165U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 13423071121590981727U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 18324443012024134729U;
            aOrbiterD = RotL64((aOrbiterD * 15814349432207734533U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 4129091815978464507U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 17024797553831962245U) ^ aOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3137753479364378175U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 6501545108779991661U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 11930037791867597447U) ^ RotL64(aNonceWordE, 22U);
            aOrbiterA = RotL64((aOrbiterA * 4904739567549702851U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 4667298703308315851U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 6315980380900062127U;
            aOrbiterH = RotL64((aOrbiterH * 12080555704907924637U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 12732382340390769888U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 7792095326183864547U;
            aOrbiterI = RotL64((aOrbiterI * 12645556660611824631U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 17428384983571405782U) + aOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 3193205313177048443U;
            aOrbiterJ = RotL64((aOrbiterJ * 14488006565106259731U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 2813743367131107264U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 2742138679703780981U) ^ RotL64(aNonceWordH, 23U);
            aOrbiterG = RotL64((aOrbiterG * 18356569025783532225U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 6270291142961043031U) + aOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 3490174937775044998U;
            aOrbiterE = RotL64((aOrbiterE * 13879285210885619613U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 13182535825771438942U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 13047228760732694484U;
            aOrbiterC = RotL64((aOrbiterC * 10365428317468779549U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 17926326514553542739U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 17019646486641172469U;
            aOrbiterF = RotL64((aOrbiterF * 13978838314848228053U), 5U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 23U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 10U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + (RotL64(aOrbiterG, 39U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 42U) + RotL64(aOrbiterE, 41U)) + aOrbiterB);
            aWandererH = aWandererH + ((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 43U)) + aOrbiterH);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 11U) + aOrbiterA) + RotL64(aOrbiterE, 22U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterG, 13U)) + aWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterH, 27U)) + aOrbiterG);
            aWandererA = aWandererA + (((RotL64(aCross, 19U) + RotL64(aOrbiterI, 3U)) + aOrbiterK) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 26U) + aOrbiterE) + RotL64(aOrbiterC, 58U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterA, 29U)) + RotL64(aNonceWordD, 29U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 39U)) + aOrbiterD) + aWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterH, 53U)) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 23U) + aOrbiterJ) + RotL64(aOrbiterA, 51U)) + RotL64(aNonceWordB, 55U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 24U));
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 58U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 35U) ^ RotL64(aNonceWordH, 51U)) ^ RotL64(aNonceWordG, 27U));
            aIngress = aIngress ^ (RotL64(mSnow[((aIndex + 17690U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17195U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 24U) ^ RotL64(aNonceWordD, 51U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18481U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20603U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 24U) + RotL64(aCarry, 37U)) ^ (RotL64(aPrevious, 51U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererJ + RotL64(aIngress, 41U)) + 9446153639709651566U;
            aOrbiterB = (aWandererI + RotL64(aCross, 47U)) + 10550762260670758167U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 43U)) + 7062634922142578383U) + aOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 50U)) + 9178499097812764515U) + RotL64(aNonceWordH, 41U);
            aOrbiterD = ((aWandererE + RotL64(aScatter, 39U)) + 6887103379773525538U) + aOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 23U)) + 6239750312052010257U) + RotL64(aNonceWordF, 7U);
            aOrbiterE = ((aWandererG + RotL64(aIngress, 19U)) + RotL64(aCarry, 21U)) + 17645022614523287959U;
            aOrbiterH = ((aWandererK + RotL64(aCross, 29U)) + RotL64(aCarry, 37U)) + 3639618183259408272U;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 27U)) + RotL64(aCarry, 53U)) + 3131737117548745095U;
            aOrbiterA = (aWandererB + RotL64(aIngress, 35U)) + 7253994382396406554U;
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 10U)) + 15217993711938379561U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 12594152227603630033U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 11250170200489647869U;
            aOrbiterK = RotL64((aOrbiterK * 546800378327864723U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 12936942656624279424U) + RotL64(aNonceWordB, 61U);
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 10990736056052106149U;
            aOrbiterD = RotL64((aOrbiterD * 7123916809953459187U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 12787293075893090465U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 17154990205620778151U;
            aOrbiterG = RotL64((aOrbiterG * 10031369940028159521U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 1270827262969060301U) + RotL64(aNonceWordA, 23U);
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 17337623431665013136U;
            aOrbiterE = RotL64((aOrbiterE * 1517262088236356107U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 830330490987911853U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 6828309232554560547U;
            aOrbiterH = RotL64((aOrbiterH * 9742464176986145819U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 11470087853413986203U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 10470148870747884420U;
            aOrbiterI = RotL64((aOrbiterI * 6766079738799967443U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 18315536891901859637U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 12264670822285914271U;
            aOrbiterA = RotL64((aOrbiterA * 5841574505408674119U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 10931842095884524879U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 11134871340959676257U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11714837622285605745U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 11484168476761306078U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 5964766416973454097U;
            aOrbiterC = RotL64((aOrbiterC * 14721123403032510803U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 10646362765367117994U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 8994267196877016381U;
            aOrbiterB = RotL64((aOrbiterB * 17386417559346134797U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 16797547458402042464U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 9446153639709651566U) ^ aOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 567585472220695323U), 39U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 39U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterB, 34U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterJ, 41U)) + aOrbiterG) + aWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterI, 19U)) + aWandererUpdateSaltF[((aIndex + 8U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 4U) + RotL64(aOrbiterD, 58U)) + aOrbiterJ);
            aWandererJ = aWandererJ + (((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterG, 37U)) + RotL64(aNonceWordC, 11U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 21U)) + aOrbiterH);
            aWandererD = aWandererD + (((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 13U)) + aOrbiterF) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterI, 27U)) + aOrbiterC);
            aWandererH = aWandererH + ((RotL64(aPrevious, 52U) + RotL64(aOrbiterE, 6U)) + aOrbiterG);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterI, 43U)) + aOrbiterA);
            aWandererG = aWandererG + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 39U)) + aOrbiterE) + RotL64(aCarry, 11U)) + RotL64(aNonceWordE, 6U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 21U) + aOrbiterB) + RotL64(aOrbiterE, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 18U));
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 4U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 40U) ^ RotL64(aNonceWordG, 5U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 22044U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((aIndex + 23677U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 13U) ^ RotL64(aNonceWordA, 24U)) ^ RotL64(aNonceWordB, 39U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26116U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27278U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCross, 53U)) ^ (RotL64(aIngress, 6U) ^ RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererH + RotL64(aCross, 53U)) + 12669015908335980355U) + RotL64(aNonceWordC, 61U);
            aOrbiterH = (((aWandererD + RotL64(aIngress, 27U)) + RotL64(aCarry, 13U)) + 5438715179868613192U) + RotL64(aNonceWordH, 34U);
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 47U)) + 13172104448184536460U) + aOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aScatter, 13U)) + 13421421503244744803U;
            aOrbiterI = (aWandererJ + RotL64(aIngress, 19U)) + 13327113302994856582U;
            aOrbiterF = ((aWandererI + RotL64(aCross, 30U)) + RotL64(aCarry, 51U)) + 4671768205922454413U;
            aOrbiterJ = (((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 39U)) + 5355759962838579929U) + aOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aPrevious, 21U)) + 6691720614265406851U;
            aOrbiterC = (aWandererE + RotL64(aIngress, 57U)) + 7063906424700911378U;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 10U)) + 17328616394166672263U;
            aOrbiterA = (aWandererC + RotL64(aCross, 41U)) + 1542940602574207068U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 7203866278803132454U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 993485696233139264U;
            aOrbiterE = RotL64((aOrbiterE * 11609009908810366447U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 15659679028507488331U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 18321361454094675842U;
            aOrbiterF = RotL64((aOrbiterF * 3966860765622641843U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 9633319822696783352U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 3496559332232402963U) ^ RotL64(aNonceWordD, 5U);
            aOrbiterB = RotL64((aOrbiterB * 7772060229838162977U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 1918349708324205526U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 7701088402761359134U;
            aOrbiterG = RotL64((aOrbiterG * 9649485438465644795U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 6006824348814439686U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 18088375375347012557U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12801082943086128385U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 12816533373478543584U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 17951880253818836433U;
            aOrbiterD = RotL64((aOrbiterD * 8935839101517220201U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 11311632024372748238U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 9891349164779752351U;
            aOrbiterJ = RotL64((aOrbiterJ * 11405973752233193209U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 711130292000437038U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 17818800917771709681U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10567029732245868263U), 35U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterJ) + 10188714200240109442U) + aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1]) + RotL64(aNonceWordF, 11U);
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 9745615081760948652U;
            aOrbiterA = RotL64((aOrbiterA * 9321909462220134035U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 6508703788527163965U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 7536038073603467381U) ^ aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12015514242701199813U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 2793951597846756844U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 12669015908335980355U;
            aOrbiterI = RotL64((aOrbiterI * 7355285540199760689U), 5U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 29U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 14U));
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + RotL64(aOrbiterG, 60U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterH, 30U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 43U)) + aOrbiterJ) + RotL64(aCarry, 41U)) + RotL64(aNonceWordB, 39U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 41U) + aOrbiterF) + RotL64(aOrbiterC, 19U)) + aWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 14U) + RotL64(aOrbiterC, 41U)) + aOrbiterA);
            aWandererH = aWandererH ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterE, 46U)) + aOrbiterA) + aWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 21U)) + aOrbiterA);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 51U)) + aOrbiterE);
            aWandererG = aWandererG + (((RotL64(aIngress, 43U) + RotL64(aOrbiterI, 53U)) + aOrbiterB) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 6U) + aOrbiterD) + RotL64(aOrbiterK, 5U)) + RotL64(aNonceWordE, 57U));
            aWandererA = aWandererA + ((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterF, 23U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterJ, 13U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 22U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + RotL64(aWandererA, 29U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 51U) ^ RotL64(aNonceWordH, 11U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 30516U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((aIndex + 31331U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 29U) ^ RotL64(aNonceWordA, 41U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29080U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneC[((aIndex + 32705U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 56U) ^ RotL64(aCross, 5U)) ^ (RotL64(aCarry, 39U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 11U)) + RotL64(aCarry, 53U)) + 12029393034357490020U;
            aOrbiterE = ((aWandererB + RotL64(aCross, 41U)) + 4526754731580694987U) + aOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aScatter, 5U)) + 17060419646421271853U) + RotL64(aNonceWordC, 49U);
            aOrbiterI = ((aWandererE + RotL64(aIngress, 44U)) + RotL64(aCarry, 23U)) + 4128488893837059683U;
            aOrbiterF = ((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 19U)) + 12706894827547160110U;
            aOrbiterD = (aWandererD + RotL64(aScatter, 51U)) + 12506324593645825056U;
            aOrbiterB = (aWandererJ + RotL64(aIngress, 47U)) + 12581344490649250025U;
            aOrbiterA = (aWandererH + RotL64(aPrevious, 19U)) + 14357032418199130132U;
            aOrbiterC = (aWandererF + RotL64(aCross, 22U)) + 15341977701796331249U;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 29U)) + 7086602307544733241U) + RotL64(aNonceWordG, 25U);
            aOrbiterH = ((aWandererA + RotL64(aScatter, 39U)) + 12398300065276832486U) + aOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 2499745046076601988U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 7249361592814001829U;
            aOrbiterK = RotL64((aOrbiterK * 14597139848072319685U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 3254456186337366437U) + RotL64(aNonceWordD, 58U);
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 3472973415969046680U;
            aOrbiterF = RotL64((aOrbiterF * 14583566953969168353U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 7905718972111691591U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 15941413652144021522U;
            aOrbiterD = RotL64((aOrbiterD * 3473779492962783565U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 10583964125960308762U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 13659925272340853715U;
            aOrbiterB = RotL64((aOrbiterB * 16708294803316630743U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 9487054537489454887U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 13287757570441887517U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17351439045329892107U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 15279245465808571942U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 12424999114621745879U;
            aOrbiterC = RotL64((aOrbiterC * 2274918760256527137U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 13915392738892970475U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 13797668053788805126U) ^ RotL64(aNonceWordB, 23U);
            aOrbiterJ = RotL64((aOrbiterJ * 13752161103680525317U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 14344766585550401077U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 13727554194373146727U;
            aOrbiterH = RotL64((aOrbiterH * 17164450431362670223U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 1332966642432651232U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 938583742533681467U;
            aOrbiterG = RotL64((aOrbiterG * 13323340043936037549U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 5659239372701978244U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 8501778564909302938U;
            aOrbiterE = RotL64((aOrbiterE * 15629932660749672503U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 1698500835332753591U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 12029393034357490020U;
            aOrbiterI = RotL64((aOrbiterI * 18176507271635640153U), 13U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterK, 35U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + (RotL64(aOrbiterG, 37U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 42U));
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterB, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterA, 39U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterB, 3U)) + aOrbiterK);
            aWandererE = aWandererE + ((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 11U)) + aOrbiterH);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 56U) + RotL64(aOrbiterE, 13U)) + aOrbiterA);
            aWandererF = aWandererF + ((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterJ, 46U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 43U)) + aOrbiterF);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 37U) + RotL64(aOrbiterC, 29U)) + aOrbiterI) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterB, 19U)) + aOrbiterG) + RotL64(aNonceWordH, 7U)) + aWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 51U) + RotL64(aOrbiterC, 52U)) + aOrbiterD);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 24U) + RotL64(aOrbiterF, 37U)) + aOrbiterG) + aWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 11U) + aOrbiterE) + RotL64(aOrbiterB, 41U)) + RotL64(aCarry, 3U)) + RotL64(aNonceWordF, 61U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 4U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 41U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + RotL64(aWandererG, 6U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_Cricket_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xCF4DB3CD8B9BE3DFULL + 0xF9B77DCF6470EEB2ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xA39B097BF92542A9ULL + 0x9542CC6978B2B49EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x9EE6BA3731CF71EBULL + 0xAE088E1A93097394ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x8F8ED88C556734B3ULL + 0xE9B228FF150043B7ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x9468ADF862E068F3ULL + 0xDF1E1349DDB23435ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB2B7546C1C1D6439ULL + 0xF9615D4BAF043EDEULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x8AF652DEC397398FULL + 0xC1E01B3648C0F488ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xE67A6971D1C9AF5BULL + 0xE6074D6032DD12FFULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 58U) ^ RotL64(aNonceWordE, 19U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4288U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7161U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 19U) ^ RotL64(aNonceWordD, 41U)) ^ RotL64(aNonceWordB, 57U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7133U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 6939U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aPrevious, 53U)) ^ (RotL64(aCarry, 35U) + RotL64(aIngress, 4U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 3U)) + RotL64(aCarry, 29U)) + 9446153639709651566U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 23U)) + 10550762260670758167U;
            aOrbiterH = (aWandererB + RotL64(aScatter, 18U)) + 7062634922142578383U;
            aOrbiterA = ((aWandererE + RotL64(aCross, 27U)) + 9178499097812764515U) + RotL64(aNonceWordA, 13U);
            aOrbiterI = ((aWandererF + RotL64(aScatter, 41U)) + 6887103379773525538U) + aOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = (((aWandererK + RotL64(aCross, 51U)) + RotL64(aCarry, 13U)) + 6239750312052010257U) + RotL64(aNonceWordE, 49U);
            aOrbiterE = (aWandererC + RotL64(aPrevious, 11U)) + 17645022614523287959U;
            aOrbiterB = (((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 5U)) + 3639618183259408272U) + aOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (aWandererG + RotL64(aCross, 56U)) + 3131737117548745095U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 7253994382396406554U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 15217993711938379561U;
            aOrbiterH = RotL64((aOrbiterH * 17853313384747259923U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 12594152227603630033U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 11250170200489647869U) ^ aOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 546800378327864723U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 12936942656624279424U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 10990736056052106149U;
            aOrbiterB = RotL64((aOrbiterB * 7123916809953459187U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 12787293075893090465U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 17154990205620778151U;
            aOrbiterG = RotL64((aOrbiterG * 10031369940028159521U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 1270827262969060301U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 17337623431665013136U) ^ RotL64(aNonceWordG, 39U);
            aOrbiterK = RotL64((aOrbiterK * 1517262088236356107U), 29U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterG) + 830330490987911853U) + aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1]) + RotL64(aNonceWordH, 53U);
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 6828309232554560547U;
            aOrbiterA = RotL64((aOrbiterA * 9742464176986145819U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 11470087853413986203U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 10470148870747884420U;
            aOrbiterE = RotL64((aOrbiterE * 6766079738799967443U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 18315536891901859637U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 12264670822285914271U;
            aOrbiterD = RotL64((aOrbiterD * 5841574505408674119U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 10931842095884524879U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 11134871340959676257U;
            aOrbiterI = RotL64((aOrbiterI * 11714837622285605745U), 43U);
            //
            aIngress = RotL64(aOrbiterB, 23U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterG, 40U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 14U) + aOrbiterB) + RotL64(aOrbiterA, 53U));
            aWandererB = aWandererB + ((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 14U)) + aOrbiterA);
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 35U)) + aOrbiterJ) + RotL64(aNonceWordC, 30U)) + aWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 57U) + aOrbiterE) + RotL64(aOrbiterB, 57U)) + aWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 10U) + aOrbiterD) + RotL64(aOrbiterB, 39U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 39U) + aOrbiterH) + RotL64(aOrbiterI, 21U)) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 51U) + aOrbiterH) + RotL64(aOrbiterA, 5U)) + RotL64(aNonceWordF, 25U));
            aWandererF = aWandererF + (((RotL64(aCross, 27U) + aOrbiterK) + RotL64(aOrbiterH, 29U)) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 23U) + aOrbiterG) + RotL64(aOrbiterE, 46U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 6U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 53U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 60U) ^ RotL64(aNonceWordD, 5U)) ^ RotL64(aNonceWordG, 43U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 13434U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((aIndex + 11449U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 38U) ^ RotL64(aNonceWordB, 21U)) ^ RotL64(aNonceWordE, 29U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11195U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((aIndex + 9455U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 28U) + RotL64(aPrevious, 43U)) ^ (RotL64(aCarry, 13U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((((aWandererA + RotL64(aIngress, 47U)) + RotL64(aCarry, 57U)) + 2225397913940961213U) + aOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1]) + RotL64(aNonceWordB, 14U);
            aOrbiterH = ((aWandererI + RotL64(aCross, 13U)) + RotL64(aCarry, 43U)) + 8342544893601343643U;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 35U)) + 162922186381417187U) + RotL64(aNonceWordA, 53U);
            aOrbiterF = (aWandererK + RotL64(aScatter, 27U)) + 11660218373710972210U;
            aOrbiterD = ((aWandererB + RotL64(aCross, 56U)) + 14909034764605802354U) + aOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aScatter, 43U)) + 16776955237009701511U;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 23U)) + 5834487809188925253U;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 51U)) + 1498492772767040320U;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 4U)) + RotL64(aCarry, 19U)) + 4161765458781579617U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 10511923076962447765U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 8575954471692620021U;
            aOrbiterG = RotL64((aOrbiterG * 12526744988828982731U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 6536325446331340573U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 1790628986900286346U;
            aOrbiterD = RotL64((aOrbiterD * 5262997114200816715U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 2623814807619278590U) + aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 11676970995834706612U;
            aOrbiterE = RotL64((aOrbiterE * 10057461115132434901U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 13836786354224256591U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 6293096163612129260U) ^ aOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8977954126326217153U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 4271144764978661248U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 15938494256992560202U;
            aOrbiterJ = RotL64((aOrbiterJ * 10004841288382726739U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 11038155227307702976U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 12408749795071243930U;
            aOrbiterB = RotL64((aOrbiterB * 5527720475032868855U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 1673665849053496882U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 12866353361497103629U) ^ RotL64(aNonceWordD, 27U);
            aOrbiterF = RotL64((aOrbiterF * 6041125499398924871U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 10673935802381580966U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 8946776538955520352U;
            aOrbiterK = RotL64((aOrbiterK * 12293084177712710021U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 16294935203370452805U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterJ) ^ 4697759331563852212U) ^ aOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1]) ^ RotL64(aNonceWordE, 13U);
            aOrbiterH = RotL64((aOrbiterH * 14407806317275373043U), 51U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 47U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 39U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 58U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterE, 6U)) + aOrbiterH);
            aWandererI = aWandererI + ((RotL64(aPrevious, 44U) + RotL64(aOrbiterB, 23U)) + aOrbiterD);
            aWandererE = aWandererE ^ ((((RotL64(aCross, 19U) + RotL64(aOrbiterE, 19U)) + aOrbiterB) + RotL64(aNonceWordC, 59U)) + aWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 53U)) + aOrbiterE) + RotL64(aNonceWordH, 9U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 53U) + aOrbiterB) + RotL64(aOrbiterG, 11U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 35U)) + aOrbiterJ) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 39U)) + aOrbiterC) + aWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 27U) + aOrbiterK) + RotL64(aOrbiterG, 30U)) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 34U) + RotL64(aOrbiterF, 43U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 50U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererE, 23U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 3U) ^ RotL64(aNonceWordG, 37U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 24524U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((aIndex + 23120U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 54U) ^ RotL64(aNonceWordA, 21U)) ^ RotL64(aNonceWordC, 5U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 24407U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 22635U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 48U) ^ RotL64(aIngress, 35U)) + (RotL64(aCarry, 19U) ^ RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererI + RotL64(aCross, 20U)) + 6521330037475130256U;
            aOrbiterE = (aWandererA + RotL64(aIngress, 47U)) + 12611880456055428940U;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 57U)) + 12061611078130934708U) + RotL64(aNonceWordB, 29U);
            aOrbiterK = (aWandererF + RotL64(aPrevious, 29U)) + 1558112410801116984U;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 5U)) + 10509115227850160786U) + aOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = (((aWandererB + RotL64(aScatter, 51U)) + RotL64(aCarry, 21U)) + 4045915960688792066U) + RotL64(aNonceWordC, 5U);
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 24U)) + RotL64(aCarry, 11U)) + 1196541286513243082U;
            aOrbiterG = (((aWandererK + RotL64(aCross, 41U)) + RotL64(aCarry, 57U)) + 15564991032722373702U) + aOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (aWandererG + RotL64(aIngress, 37U)) + 4897765238703641798U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 12327429514907752733U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 6189189797708711636U;
            aOrbiterF = RotL64((aOrbiterF * 9017615866338877651U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 6374267075282018852U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 1888758503831341439U) ^ aOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 74387714918264257U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 14956857689299491800U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 14879361107223331957U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9166712966729591953U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 16086885494838105042U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 8069724185844303923U) ^ RotL64(aNonceWordF, 41U);
            aOrbiterE = RotL64((aOrbiterE * 8878470736758734353U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 10854345917959911439U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 7078313614360332089U;
            aOrbiterC = RotL64((aOrbiterC * 9864025732292844871U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 15083669236062255011U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 594879695916679116U;
            aOrbiterI = RotL64((aOrbiterI * 9852515479152735283U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 6721466068234534523U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 475816724162626782U;
            aOrbiterD = RotL64((aOrbiterD * 4799725182757588407U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 4341655358154605899U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 15477254302340298586U) ^ RotL64(aNonceWordH, 20U);
            aOrbiterG = RotL64((aOrbiterG * 13961520225881974201U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 10179091913200895775U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 6310490897546909571U;
            aOrbiterB = RotL64((aOrbiterB * 15080621088825477613U), 53U);
            //
            aIngress = RotL64(aOrbiterK, 57U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterB, 34U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + (RotL64(aOrbiterE, 23U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 53U) + aOrbiterK) + RotL64(aOrbiterE, 10U)) + aWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterD, 41U)) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 38U) + aOrbiterJ) + RotL64(aOrbiterF, 19U)) + RotL64(aNonceWordE, 47U));
            aWandererH = aWandererH + ((RotL64(aCross, 57U) + aOrbiterK) + RotL64(aOrbiterB, 47U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterG, 57U)) + RotL64(aNonceWordA, 61U));
            aWandererC = aWandererC + (((RotL64(aCross, 23U) + aOrbiterG) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 46U) + aOrbiterF) + RotL64(aOrbiterB, 14U));
            aWandererK = aWandererK + ((RotL64(aIngress, 19U) + RotL64(aOrbiterI, 23U)) + aOrbiterD);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterE, 3U)) + aWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 26U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 60U) ^ RotL64(aNonceWordB, 41U)) ^ RotL64(aNonceWordC, 27U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 26373U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((aIndex + 31449U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 57U) ^ RotL64(aNonceWordG, 24U)) ^ RotL64(aNonceWordE, 3U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29024U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 25920U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCross, 50U)) + (RotL64(aIngress, 35U) ^ RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererA + RotL64(aScatter, 19U)) + 4068921616130916949U) + aOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 58U)) + RotL64(aCarry, 47U)) + 12077715273915151726U;
            aOrbiterH = (aWandererK + RotL64(aCross, 13U)) + 16047546802670596833U;
            aOrbiterB = (((aWandererF + RotL64(aIngress, 23U)) + RotL64(aCarry, 57U)) + 9690277462716999763U) + RotL64(aNonceWordF, 17U);
            aOrbiterJ = (((aWandererB + RotL64(aCross, 41U)) + RotL64(aCarry, 27U)) + 14484814700447992628U) + RotL64(aNonceWordH, 11U);
            aOrbiterF = ((aWandererI + RotL64(aIngress, 53U)) + 17089267243053958210U) + aOrbiterAssignSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aScatter, 37U)) + 9138746214446211147U;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 48U)) + 10181001536979097045U;
            aOrbiterA = (aWandererH + RotL64(aCross, 3U)) + 6657458969093373191U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 7515983477876590988U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 3039935555863947600U;
            aOrbiterH = RotL64((aOrbiterH * 12511160550780270119U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 16209389224740851136U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 725253312098083182U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17535989492095522597U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 13307041115748941383U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 7159572004825238263U) ^ aOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4855009895002398449U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 12027236743251643820U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 8717826175991286553U;
            aOrbiterE = RotL64((aOrbiterE * 1175614802543098451U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 4769096034227659937U) + aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 11201226563992939616U;
            aOrbiterB = RotL64((aOrbiterB * 15595355978388159931U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 17295978531215563256U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 11850923890626719833U;
            aOrbiterF = RotL64((aOrbiterF * 3854851059897397075U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 14139441565288097706U) + aOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 988684899382304485U;
            aOrbiterD = RotL64((aOrbiterD * 11929090869999700891U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 6159251276942253175U) + RotL64(aNonceWordC, 16U);
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 4849529993914550651U;
            aOrbiterA = RotL64((aOrbiterA * 18240712676783671317U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 6679745455842119497U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 15838404437552215214U) ^ RotL64(aNonceWordG, 27U);
            aOrbiterG = RotL64((aOrbiterG * 17357853511591350887U), 29U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 60U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterI, 29U)) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterH, 5U)) + aOrbiterG);
            aWandererI = aWandererI + (((RotL64(aCross, 44U) + aOrbiterB) + RotL64(aOrbiterG, 14U)) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 37U) + RotL64(aOrbiterD, 19U)) + aOrbiterJ) + RotL64(aNonceWordA, 13U)) + aWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 57U) + aOrbiterA) + RotL64(aOrbiterG, 57U)) + RotL64(aNonceWordD, 57U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 35U)) + aOrbiterD);
            aWandererE = aWandererE + ((RotL64(aScatter, 53U) + aOrbiterJ) + RotL64(aOrbiterB, 23U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterD, 43U)) + aOrbiterE);
            aWandererH = aWandererH + (((RotL64(aCross, 48U) + RotL64(aOrbiterJ, 10U)) + aOrbiterI) + aWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 56U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + RotL64(aWandererB, 53U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xCBBA62A3ACA3EC29ULL + 0xA70C57AEA41A1B61ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xF08A22FF991D87EDULL + 0xC12AE231BAF8060DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xACE3F34A5E6D98B1ULL + 0xCAB681704507F35BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xAA8B14A5FBA8B857ULL + 0x8084A14943FA1385ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x90EE1E34615A25CDULL + 0x8030D1E23155EFD7ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xC7C913B76A72C089ULL + 0xC2ED596574C0D540ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x8546C00AEE711135ULL + 0xDD154D4920EE33F0ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE82028F6F38C01B1ULL + 0xDCAC4F7E5FADBC09ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 44U) ^ RotL64(aNonceWordF, 3U)) ^ RotL64(aNonceWordA, 23U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 5901U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((aIndex + 5287U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 27U) ^ RotL64(aNonceWordC, 43U)) ^ RotL64(aNonceWordG, 53U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7236U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 1338U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 58U) ^ RotL64(aCarry, 29U)) ^ (RotL64(aCross, 43U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (((aWandererH + RotL64(aIngress, 60U)) + RotL64(aCarry, 29U)) + 14249093584376402677U) + aOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 23U)) + RotL64(aCarry, 53U)) + 8756965951816492264U;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 11U)) + 11221139480258176330U;
            aOrbiterF = (((aWandererE + RotL64(aScatter, 35U)) + RotL64(aCarry, 41U)) + 17218894445564194851U) + RotL64(aNonceWordA, 27U);
            aOrbiterH = (((aWandererK + RotL64(aPrevious, 43U)) + 8064642692524949490U) + aOrbiterAssignSaltA[((aIndex + 26U)) & S_SALT1]) + RotL64(aNonceWordD, 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 5822093203710704646U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 3217799620158102238U) ^ aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2806328682494910635U), 27U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterH) + 2613757677892120843U) + aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1]) + RotL64(aNonceWordB, 37U);
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 13647481499551657237U;
            aOrbiterE = RotL64((aOrbiterE * 5517563514031899891U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 3545714196663685016U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 9735422670576621521U;
            aOrbiterF = RotL64((aOrbiterF * 7276207208162697249U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 3911046580637583767U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 9315984027042049203U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12568550776487242469U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 8926367674641729058U) + RotL64(aNonceWordE, 11U);
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 11035347490524961446U) ^ aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10948288997163592463U), 41U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 3U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 24U));
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 58U)) + aOrbiterJ) + RotL64(aCarry, 13U)) + aWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterH, 39U)) + aOrbiterE);
            aWandererC = aWandererC + (((RotL64(aIngress, 48U) + aOrbiterD) + RotL64(aOrbiterE, 29U)) + RotL64(aNonceWordF, 61U));
            aWandererE = aWandererE ^ ((((RotL64(aCross, 3U) + RotL64(aOrbiterH, 47U)) + aOrbiterD) + RotL64(aNonceWordH, 28U)) + aWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterJ, 19U)) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (RotL64(aWandererK, 58U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 21U) ^ RotL64(aNonceWordE, 29U)) ^ RotL64(aNonceWordA, 53U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 11867U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneD[((aIndex + 15425U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 14U) ^ RotL64(aNonceWordH, 57U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 10156U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((aIndex + 10361U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 40U) ^ RotL64(aCross, 53U)) + (RotL64(aIngress, 3U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 14U)) + RotL64(aCarry, 57U)) + 785861751704720606U;
            aOrbiterK = (((aWandererC + RotL64(aIngress, 5U)) + 15968088718435606299U) + aOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1]) + RotL64(aNonceWordH, 47U);
            aOrbiterH = ((aWandererE + RotL64(aCross, 51U)) + 1393976526590347151U) + aOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 27U)) + RotL64(aCarry, 29U)) + 17240750947292745884U;
            aOrbiterJ = (((aWandererA + RotL64(aIngress, 35U)) + RotL64(aCarry, 13U)) + 4921576136163183137U) + RotL64(aNonceWordF, 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 3334047873553153032U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 15086509978458408698U;
            aOrbiterH = RotL64((aOrbiterH * 2162818176367899893U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 892391205397581998U) + aOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 2965686403183767521U) ^ RotL64(aNonceWordE, 6U);
            aOrbiterJ = RotL64((aOrbiterJ * 709160942482770225U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 14632215393655706170U) + aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterB) ^ 15740589515342377322U) ^ aOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1]) ^ RotL64(aNonceWordB, 23U);
            aOrbiterG = RotL64((aOrbiterG * 15677716942904794913U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 11131164813943086445U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 6988080581278900960U;
            aOrbiterK = RotL64((aOrbiterK * 6412189142344044255U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 16021254613117657178U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 6183615599897921154U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9976411093264211033U), 57U);
            //
            aIngress = RotL64(aOrbiterJ, 57U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterB, 28U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 51U) + aOrbiterJ) + RotL64(aOrbiterH, 43U)) + RotL64(aNonceWordC, 29U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 5U)) + aOrbiterH) + RotL64(aCarry, 29U)) + aWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterG, 26U)) + aOrbiterK) + RotL64(aNonceWordG, 39U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 57U)) + aOrbiterB) + RotL64(aCarry, 13U)) + aWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 12U) + RotL64(aOrbiterH, 13U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + RotL64(aWandererK, 46U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 44U) ^ RotL64(aNonceWordF, 13U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 16876U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 17389U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 5U) ^ RotL64(aNonceWordD, 19U)) ^ RotL64(aNonceWordA, 43U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 21282U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneC[((aIndex + 21805U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 43U) ^ RotL64(aPrevious, 57U)) ^ (RotL64(aCross, 29U) + RotL64(aIngress, 10U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (((aWandererB + RotL64(aScatter, 41U)) + RotL64(aCarry, 19U)) + 15910560457440369082U) + aOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = ((((aWandererE + RotL64(aCross, 27U)) + RotL64(aCarry, 3U)) + 17953072986407436888U) + aOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1]) + RotL64(aNonceWordA, 45U);
            aOrbiterE = (aWandererC + RotL64(aIngress, 51U)) + 15446940721193538669U;
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 19U)) + RotL64(aCarry, 41U)) + 3020785262774422009U;
            aOrbiterC = ((aWandererG + RotL64(aCross, 6U)) + 7001288645424994404U) + RotL64(aNonceWordE, 28U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 13385250665458462689U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 4841895644623005949U;
            aOrbiterE = RotL64((aOrbiterE * 3898487345974386945U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 13053476783239482065U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 641996979335975244U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3697673197256549833U), 37U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterB) + 16211238020928688299U) + aOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1]) + RotL64(aNonceWordC, 11U);
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 12715448751323279480U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2116880429675303291U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 17784406727699995290U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 16626339815786580778U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13940754474750138041U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 9035070625716345139U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 6085848172494001945U) ^ RotL64(aNonceWordD, 51U);
            aOrbiterC = RotL64((aOrbiterC * 10405728912339646693U), 13U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 3U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 37U)) + aOrbiterE) + RotL64(aNonceWordB, 19U)) + aWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterF, 3U)) + aOrbiterD);
            aWandererB = aWandererB + (((((RotL64(aIngress, 4U) + aOrbiterB) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 19U)) + RotL64(aNonceWordH, 23U)) + aWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterC, 52U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterC, 29U)) + aOrbiterB) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 23U) ^ RotL64(aNonceWordA, 35U)) ^ RotL64(aNonceWordH, 5U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 32102U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29347U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 13U) ^ RotL64(aNonceWordC, 35U)) ^ RotL64(aNonceWordG, 5U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30285U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 28353U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 37U) ^ RotL64(aCarry, 21U)) + (RotL64(aPrevious, 3U) ^ RotL64(aCross, 52U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererA + RotL64(aCross, 13U)) + 13053031069776604052U;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 35U)) + RotL64(aCarry, 53U)) + 1331396630251085122U;
            aOrbiterI = ((((aWandererG + RotL64(aPrevious, 48U)) + RotL64(aCarry, 41U)) + 15879286043343942393U) + aOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1]) + RotL64(aNonceWordC, 23U);
            aOrbiterD = ((((aWandererC + RotL64(aIngress, 27U)) + RotL64(aCarry, 3U)) + 13590365633321406830U) + aOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1]) + RotL64(aNonceWordF, 57U);
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 5U)) + 14569235423040242618U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 11397370636618371560U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 3455933494593971847U) ^ RotL64(aNonceWordG, 41U);
            aOrbiterI = RotL64((aOrbiterI * 13051161161405358793U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 1307153376443784593U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 10688618762584786871U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9503823896874842411U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 17746248451153600096U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 8512568600755410158U) ^ aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16648320170768234063U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 8950230550112591092U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 17790968369472845496U;
            aOrbiterB = RotL64((aOrbiterB * 5104988920132008913U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 12583323865381967534U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterI) ^ 11243927099685293887U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]) ^ RotL64(aNonceWordE, 26U);
            aOrbiterJ = RotL64((aOrbiterJ * 12867003042486433971U), 23U);
            //
            aIngress = RotL64(aOrbiterI, 58U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterB, 23U)) + aOrbiterG);
            aWandererA = aWandererA + (((((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 42U)) + aOrbiterB) + RotL64(aCarry, 29U)) + RotL64(aNonceWordB, 47U)) + aWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 38U) + RotL64(aOrbiterD, 53U)) + aOrbiterI);
            aWandererG = aWandererG + (((RotL64(aCross, 29U) + aOrbiterJ) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 13U)) + aOrbiterD) + RotL64(aNonceWordH, 19U)) + aWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererG, 13U);
            aCarry = aCarry + RotL64(aIngress, 30U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xE3BC83EC29A098ABULL + 0x81080CC8D00F92E3ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x8DC9F3B1334C47F9ULL + 0xD5ABE541AC95541DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xAA4F661B3ABB5C8FULL + 0xB36CCC4AC9AFC4DEULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x9376FEE9365FE823ULL + 0x94DA6EECE4257F0BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xC93DCB961F799CEFULL + 0xC767E92DB48FE274ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xDBA03BB787655339ULL + 0x9F8E676212FF50AAULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xA67AEB15848DF53BULL + 0x9100B37AE367C24FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xA8687189B4A32071ULL + 0xFE7B9F686DB5B024ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 39U) ^ RotL64(aNonceWordD, 19U)) ^ RotL64(aNonceWordH, 29U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4712U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneC[((aIndex + 1243U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 19U) ^ RotL64(aNonceWordG, 5U)) ^ RotL64(aNonceWordC, 47U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7996U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 1426U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 57U)) + (RotL64(aCross, 12U) + RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 43U)) + 6068543441070417854U) + RotL64(aNonceWordB, 37U);
            aOrbiterB = ((aWandererF + RotL64(aIngress, 29U)) + RotL64(aCarry, 5U)) + 2995980468193441856U;
            aOrbiterG = (aWandererA + RotL64(aCross, 51U)) + 18020277482171594003U;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 13U)) + 4293807434721230702U) + aOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = ((((aWandererD + RotL64(aPrevious, 21U)) + RotL64(aCarry, 51U)) + 7980599111583893156U) + aOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1]) + RotL64(aNonceWordF, 27U);
            aOrbiterK = (aWandererJ + RotL64(aIngress, 60U)) + 8593141111851052016U;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 5U)) + RotL64(aCarry, 27U)) + 5903487523900084325U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 15112035513447930209U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 9854037263057006439U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 396276470208637283U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 16759760289688823193U) + aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 12622628933030601390U;
            aOrbiterE = RotL64((aOrbiterE * 2151912984825538321U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 1264668857268123425U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 16302812053619101593U) ^ RotL64(aNonceWordE, 4U);
            aOrbiterK = RotL64((aOrbiterK * 18291400055836111547U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 16087995784896123610U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 7970269262800468363U) ^ RotL64(aNonceWordD, 15U);
            aOrbiterC = RotL64((aOrbiterC * 14924752223305807461U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 5331477046030959632U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 16534913204255550893U;
            aOrbiterI = RotL64((aOrbiterI * 1013433634373673565U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 11042821902537871209U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 8069677512345031660U;
            aOrbiterD = RotL64((aOrbiterD * 13622218526054132397U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 5737130058129936372U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 1076627182956662997U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14342191224014199929U), 47U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 29U);
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 29U)) + aOrbiterC) + RotL64(aNonceWordG, 9U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 21U) + aOrbiterI) + RotL64(aOrbiterG, 23U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterK, 47U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 60U)) + aOrbiterE) + RotL64(aCarry, 43U)) + RotL64(aNonceWordA, 49U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 46U) + aOrbiterB) + RotL64(aOrbiterC, 3U)) + aWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 41U)) + aOrbiterI) + aWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + (RotL64(aWandererA, 60U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + RotL64(aWandererB, 23U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 13U) ^ RotL64(aNonceWordH, 57U)) ^ RotL64(aNonceWordG, 42U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8342U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14530U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 23U) ^ RotL64(aNonceWordC, 5U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13155U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9523U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 26U) + RotL64(aIngress, 53U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererA + RotL64(aScatter, 18U)) + 479672811032092393U) + RotL64(aNonceWordE, 21U);
            aOrbiterI = (aWandererK + RotL64(aCross, 47U)) + 18061121631394564425U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 53U)) + 14237400452740566065U) + aOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = (((aWandererF + RotL64(aIngress, 11U)) + RotL64(aCarry, 53U)) + 6723123812257706134U) + RotL64(aNonceWordD, 45U);
            aOrbiterH = ((aWandererH + RotL64(aCross, 5U)) + RotL64(aCarry, 29U)) + 4247997188026499248U;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 29U)) + 1939107415066134869U) + aOrbiterAssignSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 41U)) + RotL64(aCarry, 3U)) + 3912640123546395979U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 8295478436553964298U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 3218960600711526885U;
            aOrbiterK = RotL64((aOrbiterK * 15443507655470278069U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 5874096203353388890U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 10294536533673023358U) ^ RotL64(aNonceWordC, 19U);
            aOrbiterG = RotL64((aOrbiterG * 15561710414949058923U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 11268561953904130747U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 16693201256788898423U;
            aOrbiterB = RotL64((aOrbiterB * 16291987237693567209U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 7550969634681894654U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 9501647424602245869U;
            aOrbiterI = RotL64((aOrbiterI * 11265865222096866605U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 8881869255994319423U) + RotL64(aNonceWordB, 9U);
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 16770136406906800016U;
            aOrbiterH = RotL64((aOrbiterH * 1782039587385512923U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 16185384746435761363U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 13841034186650721627U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12000155593277035447U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 15229062695864608309U) + aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 3576122704615303733U;
            aOrbiterC = RotL64((aOrbiterC * 2433987493885779279U), 51U);
            //
            aIngress = RotL64(aOrbiterG, 41U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 47U)) + aOrbiterD);
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 37U) + aOrbiterD) + RotL64(aOrbiterI, 41U)) + RotL64(aNonceWordF, 39U)) + aWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 23U) + RotL64(aOrbiterC, 3U)) + aOrbiterK) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 53U)) + aOrbiterK);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterH, 60U)) + RotL64(aCarry, 5U)) + aWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 14U) + RotL64(aOrbiterG, 27U)) + aOrbiterD) + RotL64(aNonceWordG, 24U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterD, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 12U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 53U) ^ RotL64(aNonceWordH, 37U)) ^ RotL64(aNonceWordD, 24U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 17397U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 23133U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 23U) ^ RotL64(aNonceWordB, 60U)) ^ RotL64(aNonceWordE, 13U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 22776U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((aIndex + 23864U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCross, 10U)) ^ (RotL64(aCarry, 57U) + RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererF + RotL64(aIngress, 51U)) + RotL64(aCarry, 21U)) + 9446153639709651566U;
            aOrbiterA = (((aWandererH + RotL64(aPrevious, 57U)) + RotL64(aCarry, 5U)) + 10550762260670758167U) + aOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 57U)) + 7062634922142578383U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 21U)) + 9178499097812764515U) + RotL64(aNonceWordF, 15U);
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 27U)) + 6887103379773525538U) + aOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = (aWandererB + RotL64(aScatter, 42U)) + 6239750312052010257U;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 35U)) + 17645022614523287959U) + RotL64(aNonceWordA, 9U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 3639618183259408272U) + aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 3131737117548745095U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6585057380704940395U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 7253994382396406554U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 15217993711938379561U;
            aOrbiterA = RotL64((aOrbiterA * 17853313384747259923U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 12594152227603630033U) + RotL64(aNonceWordG, 21U);
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 11250170200489647869U;
            aOrbiterB = RotL64((aOrbiterB * 546800378327864723U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 12936942656624279424U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 10990736056052106149U;
            aOrbiterG = RotL64((aOrbiterG * 7123916809953459187U), 5U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterJ) + 12787293075893090465U) + aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1]) + RotL64(aNonceWordD, 59U);
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 17154990205620778151U;
            aOrbiterH = RotL64((aOrbiterH * 10031369940028159521U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 1270827262969060301U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 17337623431665013136U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1517262088236356107U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 830330490987911853U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 6828309232554560547U;
            aOrbiterI = RotL64((aOrbiterI * 9742464176986145819U), 47U);
            //
            aIngress = RotL64(aOrbiterI, 5U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 41U) + aOrbiterK) + RotL64(aOrbiterJ, 23U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 11U)) + aOrbiterI) + RotL64(aCarry, 23U)) + RotL64(aNonceWordH, 51U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterK, 29U)) + RotL64(aNonceWordC, 30U));
            aWandererI = aWandererI + ((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterH, 53U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 23U) + aOrbiterK) + RotL64(aOrbiterG, 36U)) + aWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 12U) + RotL64(aOrbiterG, 43U)) + aOrbiterA) + RotL64(aCarry, 35U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterG, 3U)) + aWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 42U));
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 14U) ^ RotL64(aNonceWordA, 37U)) ^ RotL64(aNonceWordC, 29U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 29900U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((aIndex + 32397U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 11U) ^ RotL64(aNonceWordG, 41U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30017U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((aIndex + 29401U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCross, 34U)) ^ (RotL64(aCarry, 5U) + RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 53U)) + 12029393034357490020U) + aOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aIngress, 35U)) + 4526754731580694987U) + RotL64(aNonceWordF, 6U);
            aOrbiterE = ((aWandererB + RotL64(aCross, 10U)) + RotL64(aCarry, 19U)) + 17060419646421271853U;
            aOrbiterC = (((aWandererC + RotL64(aPrevious, 3U)) + RotL64(aCarry, 35U)) + 4128488893837059683U) + RotL64(aNonceWordC, 43U);
            aOrbiterJ = (aWandererI + RotL64(aIngress, 27U)) + 12706894827547160110U;
            aOrbiterB = ((aWandererE + RotL64(aScatter, 47U)) + RotL64(aCarry, 57U)) + 12506324593645825056U;
            aOrbiterH = ((aWandererD + RotL64(aCross, 41U)) + 12581344490649250025U) + aOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 14357032418199130132U) + RotL64(aNonceWordD, 31U);
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 15341977701796331249U;
            aOrbiterE = RotL64((aOrbiterE * 6332369248718076031U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 7086602307544733241U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 12398300065276832486U;
            aOrbiterB = RotL64((aOrbiterB * 18157408831225635333U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 2499745046076601988U) + aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 7249361592814001829U;
            aOrbiterI = RotL64((aOrbiterI * 14597139848072319685U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 3254456186337366437U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 3472973415969046680U;
            aOrbiterJ = RotL64((aOrbiterJ * 14583566953969168353U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 7905718972111691591U) + aOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 15941413652144021522U) ^ RotL64(aNonceWordB, 15U);
            aOrbiterF = RotL64((aOrbiterF * 3473779492962783565U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 10583964125960308762U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 13659925272340853715U;
            aOrbiterC = RotL64((aOrbiterC * 16708294803316630743U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 9487054537489454887U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 13287757570441887517U;
            aOrbiterH = RotL64((aOrbiterH * 17351439045329892107U), 57U);
            //
            aIngress = RotL64(aOrbiterJ, 5U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterH, 43U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + RotL64(aOrbiterF, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterH, 21U)) + aOrbiterJ);
            aWandererE = aWandererE + (((RotL64(aPrevious, 60U) + RotL64(aOrbiterF, 60U)) + aOrbiterH) + aWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 29U)) + aOrbiterF);
            aWandererB = aWandererB + ((((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterB, 11U)) + RotL64(aCarry, 3U)) + aWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterC, 39U)) + aOrbiterI) + RotL64(aNonceWordH, 37U));
            aWandererD = aWandererD + (((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 5U)) + aOrbiterB) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 47U)) + aOrbiterB) + RotL64(aNonceWordE, 53U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 24U));
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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

void TwistExpander_Cricket_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xF15623C7A53E397FULL + 0xD05FBEECBF19DE4AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xC4D1BB0CBC5B01D3ULL + 0xD0CF70D49F9EB2BFULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x9AEA098E32ED1AE5ULL + 0xDFBF08DA8CC511F8ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xADCE92426C7EA07BULL + 0xE545A77C09D8726FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xC228DB95606981A5ULL + 0xE592D47DF2319E48ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB59612E97D6AC34FULL + 0xE5D457648A7C8814ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x980087F3797AC32BULL + 0xFE3D2E5F78456628ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xCD082863AF52681FULL + 0x9F39D7C1C76378C8ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 29U) ^ RotL64(aNonceWordF, 19U)) ^ RotL64(aNonceWordH, 5U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 7718U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneC[((aIndex + 6823U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 43U) ^ RotL64(aNonceWordE, 60U)) ^ RotL64(aNonceWordB, 51U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 5944U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 4311U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCross, 4U)) ^ (RotL64(aCarry, 51U) + RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererJ + RotL64(aCross, 19U)) + 1708250618750199233U) + RotL64(aNonceWordF, 23U);
            aOrbiterB = (aWandererD + RotL64(aScatter, 27U)) + 12009147777553691142U;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 11U)) + RotL64(aCarry, 3U)) + 8393982703399156592U;
            aOrbiterF = (aWandererA + RotL64(aPrevious, 41U)) + 3247327098356831221U;
            aOrbiterH = ((((aWandererB + RotL64(aScatter, 53U)) + RotL64(aCarry, 23U)) + 3403590155376353737U) + aOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1]) + RotL64(aNonceWordG, 25U);
            aOrbiterC = (((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 47U)) + 18197244558104735044U) + aOrbiterAssignSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aCross, 34U)) + 3096253642040701606U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 8012692688785412179U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 17531946907545680745U;
            aOrbiterA = RotL64((aOrbiterA * 16510602981731506381U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 17687695944270225817U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 16147773866007628769U;
            aOrbiterH = RotL64((aOrbiterH * 16926442582711557877U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 18244641303026196497U) + aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 8839160526348897457U;
            aOrbiterC = RotL64((aOrbiterC * 14268021129087663397U), 47U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterC) + 10599266240854068246U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]) + RotL64(aNonceWordD, 35U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 2056723540756216155U;
            aOrbiterJ = RotL64((aOrbiterJ * 13311591601230386375U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 4629354220460621284U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 9505955649473204942U;
            aOrbiterG = RotL64((aOrbiterG * 17775391885312236187U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 17078153810088721310U) + aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 9470436761716263000U;
            aOrbiterF = RotL64((aOrbiterF * 5431855497250357229U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 3305863413630104742U) + RotL64(aNonceWordB, 6U);
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 14377172434239576161U) ^ aOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6880176890091033423U), 41U);
            //
            aIngress = RotL64(aOrbiterF, 53U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 28U));
            aIngress = aIngress + RotL64(aOrbiterH, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aScatter, 53U) + aOrbiterC) + RotL64(aOrbiterG, 20U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterG, 43U)) + aOrbiterB);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 41U) + aOrbiterJ) + RotL64(aOrbiterA, 27U));
            aWandererK = aWandererK + (((RotL64(aIngress, 28U) + aOrbiterC) + RotL64(aOrbiterB, 13U)) + aWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((((RotL64(aCross, 21U) + RotL64(aOrbiterJ, 53U)) + aOrbiterG) + RotL64(aNonceWordC, 3U)) + aWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aScatter, 13U) + aOrbiterJ) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 35U)) + RotL64(aNonceWordE, 31U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 6U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + RotL64(aWandererB, 41U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 37U) ^ RotL64(aNonceWordH, 13U)) ^ RotL64(aNonceWordA, 46U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 9093U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 11753U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 11U) ^ RotL64(aNonceWordE, 56U)) ^ RotL64(aNonceWordG, 21U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 12735U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 10808U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aPrevious, 37U)) ^ (RotL64(aCross, 5U) + RotL64(aIngress, 50U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (((aWandererH + RotL64(aCross, 53U)) + RotL64(aCarry, 35U)) + 16802219662864902427U) + aOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = ((((aWandererB + RotL64(aScatter, 13U)) + RotL64(aCarry, 3U)) + 14332033461409490629U) + aOrbiterAssignSaltA[((aIndex + 6U)) & S_SALT1]) + RotL64(aNonceWordA, 38U);
            aOrbiterE = ((aWandererK + RotL64(aIngress, 41U)) + RotL64(aCarry, 53U)) + 8781794298640286845U;
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 6U)) + 8459933908074937264U;
            aOrbiterD = (aWandererI + RotL64(aCross, 35U)) + 1883580287986004426U;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 19U)) + 17500258188004626118U;
            aOrbiterA = ((aWandererA + RotL64(aIngress, 27U)) + 7934811305150872870U) + RotL64(aNonceWordF, 49U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 6380363892361098905U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 12623079132626676910U;
            aOrbiterE = RotL64((aOrbiterE * 12406671746344127399U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 10455208121949202703U) + RotL64(aNonceWordH, 57U);
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 8805532707916767629U;
            aOrbiterI = RotL64((aOrbiterI * 666082374369701881U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9161544391400377699U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 3501434325829663268U;
            aOrbiterH = RotL64((aOrbiterH * 7933545151293799637U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 651783304096081996U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 441505031509930622U) ^ aOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8045355432310956143U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 1771159983581326424U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 15227946417377695989U;
            aOrbiterD = RotL64((aOrbiterD * 1563141188972797601U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 4153717524193279095U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 4404521756523902829U;
            aOrbiterJ = RotL64((aOrbiterJ * 1410342912973206203U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 6231945075461813285U) + aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = (((aOrbiterA ^ aOrbiterE) ^ 3864780227164426690U) ^ aOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1]) ^ RotL64(aNonceWordB, 59U);
            aOrbiterA = RotL64((aOrbiterA * 18031353247480673617U), 57U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 53U);
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterI, 50U)) + RotL64(aCarry, 41U)) + RotL64(aNonceWordG, 61U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 35U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aPrevious, 53U) + aOrbiterJ) + RotL64(aOrbiterB, 21U)) + RotL64(aCarry, 3U));
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 27U) + aOrbiterE) + RotL64(aOrbiterH, 11U)) + RotL64(aNonceWordC, 53U)) + aWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterJ, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 12U) + aOrbiterJ) + RotL64(aOrbiterE, 41U));
            aWandererC = aWandererC + (((RotL64(aScatter, 41U) + RotL64(aOrbiterI, 27U)) + aOrbiterE) + aWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 36U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererI, 41U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 23U) ^ RotL64(aNonceWordC, 41U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22917U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21987U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 56U) ^ RotL64(aNonceWordE, 3U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 23610U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 19394U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 27U) + RotL64(aCross, 42U)) + (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererJ + RotL64(aCross, 27U)) + RotL64(aCarry, 39U)) + 9041099828460168106U;
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 41U)) + RotL64(aCarry, 5U)) + 12883711604096848454U;
            aOrbiterD = (aWandererB + RotL64(aScatter, 20U)) + 17420968786226443079U;
            aOrbiterA = (aWandererC + RotL64(aIngress, 3U)) + 3448213891716125104U;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 47U)) + 11866455977445336560U;
            aOrbiterJ = (((aWandererK + RotL64(aScatter, 35U)) + 4119356835384495905U) + aOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1]) + RotL64(aNonceWordB, 37U);
            aOrbiterI = ((((aWandererA + RotL64(aIngress, 13U)) + RotL64(aCarry, 57U)) + 2186212599698637068U) + aOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1]) + RotL64(aNonceWordG, 14U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 6506144898969301620U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 12556800923644051626U;
            aOrbiterD = RotL64((aOrbiterD * 15961043406612913121U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 4075551535185182945U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterA) ^ 17877694808492008749U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]) ^ RotL64(aNonceWordC, 61U);
            aOrbiterB = RotL64((aOrbiterB * 901315308379887473U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 5553428900598223316U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 14362304852277160675U;
            aOrbiterF = RotL64((aOrbiterF * 11415103199856419303U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 9174200302876075831U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 16110739511917638547U) ^ aOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7004356839428657949U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 10189881974519849402U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 2128076632642616677U;
            aOrbiterH = RotL64((aOrbiterH * 8860453653433114929U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 18133523799074400083U) + RotL64(aNonceWordD, 15U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 9916472958834153766U;
            aOrbiterJ = RotL64((aOrbiterJ * 3454601168808001733U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 10274457562795569227U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 14134814273275356425U;
            aOrbiterI = RotL64((aOrbiterI * 15912501063665343159U), 37U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterD, 29U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 60U));
            aIngress = aIngress + RotL64(aOrbiterI, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 53U) + RotL64(aOrbiterB, 13U)) + aOrbiterI) + RotL64(aCarry, 27U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 23U) + aOrbiterJ) + RotL64(aOrbiterD, 5U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 41U) + aOrbiterB) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 41U)) + RotL64(aNonceWordF, 31U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterD, 47U)) + aOrbiterI) + RotL64(aNonceWordH, 13U));
            aWandererA = aWandererA + (((RotL64(aIngress, 3U) + RotL64(aOrbiterA, 29U)) + aOrbiterF) + aWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 47U) + aOrbiterH) + RotL64(aOrbiterA, 35U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 60U) + aOrbiterB) + RotL64(aOrbiterA, 22U)) + aWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 36U));
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + RotL64(aWandererB, 41U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 37U) ^ RotL64(aNonceWordH, 51U)) ^ RotL64(aNonceWordD, 3U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29001U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25523U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 3U) ^ RotL64(aNonceWordB, 19U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24632U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneD[((aIndex + 25539U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCross, 19U)) ^ (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 56U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (((aWandererB + RotL64(aIngress, 60U)) + RotL64(aCarry, 13U)) + 18255347001097480328U) + aOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = ((aWandererG + RotL64(aCross, 27U)) + 13679246790311505735U) + aOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = (((aWandererH + RotL64(aScatter, 41U)) + RotL64(aCarry, 41U)) + 10565839529765027116U) + RotL64(aNonceWordG, 47U);
            aOrbiterB = (aWandererA + RotL64(aPrevious, 13U)) + 14327172566224769901U;
            aOrbiterC = (aWandererI + RotL64(aIngress, 5U)) + 16239024612038195174U;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 51U)) + 13800012174212131890U) + RotL64(aNonceWordD, 16U);
            aOrbiterD = ((aWandererE + RotL64(aCross, 19U)) + RotL64(aCarry, 29U)) + 13900288860157577583U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 4144386119777112740U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 3154558262670631372U;
            aOrbiterE = RotL64((aOrbiterE * 13236911910092437063U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 7456728543137614001U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 11709519851158935384U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7016689518570071587U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 15607438907832240304U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 9276575329661725624U) ^ RotL64(aNonceWordC, 15U);
            aOrbiterG = RotL64((aOrbiterG * 8879744070762412745U), 29U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterB) + 6459435969129449226U) + aOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1]) + RotL64(aNonceWordF, 9U);
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 6442382118416542275U;
            aOrbiterC = RotL64((aOrbiterC * 2921027306686588233U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 12117432107282150865U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 6831279293184793243U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2435360641135249073U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 9520022957804572889U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 8322178689474588679U;
            aOrbiterB = RotL64((aOrbiterB * 1627707191467537115U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 4162401591586869316U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 8994015844714895961U;
            aOrbiterD = RotL64((aOrbiterD * 15421910378057951895U), 21U);
            //
            aIngress = RotL64(aOrbiterF, 23U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 44U));
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterG, 27U)) + RotL64(aNonceWordB, 11U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterB, 19U)) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 13U) + aOrbiterC) + RotL64(aOrbiterD, 37U)) + RotL64(aNonceWordA, 57U));
            aWandererH = aWandererH + ((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 11U)) + aOrbiterF);
            aWandererG = aWandererG ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterE, 43U)) + aOrbiterB);
            aWandererE = aWandererE + ((((RotL64(aScatter, 37U) + RotL64(aOrbiterG, 3U)) + aOrbiterA) + RotL64(aCarry, 47U)) + aWandererUpdateSaltD[((aIndex + 6U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 20U) + aOrbiterE) + RotL64(aOrbiterG, 50U)) + aWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 14U));
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + RotL64(aWandererH, 43U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xE48510374794776FULL + 0xDAC68DAD7F5692A2ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xA87D5CA813A830E5ULL + 0xD4F650B0F85471DFULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xDF5D76A3F7011097ULL + 0xC40B858FECA63024ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xB6AE4D29045A082BULL + 0xA6EBC2EEFC63CD5AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xED8D90EAE71F2A27ULL + 0xD018CF82C66A8110ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xDD32196F168B3065ULL + 0xB491D5F7226431F0ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xFABB439BD4A918F7ULL + 0xD0BBDC771E3E4392ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE0BE443D47E6DC3BULL + 0xCE49E360E05E0FF0ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 13U) ^ RotL64(aNonceWordG, 3U)) ^ RotL64(aNonceWordE, 39U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1920U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((aIndex + 8177U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 23U) ^ RotL64(aNonceWordA, 11U)) ^ RotL64(aNonceWordD, 60U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3767U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 5184U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCarry, 54U)) ^ (RotL64(aIngress, 11U) ^ RotL64(aCross, 29U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererE + RotL64(aIngress, 26U)) + RotL64(aCarry, 35U)) + 14624277139785904404U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 29U)) + 6966977309498165611U) + aOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 41U)) + 205536824352530761U) + RotL64(aNonceWordF, 53U);
            aOrbiterF = (aWandererG + RotL64(aCross, 3U)) + 16629575265808255692U;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 47U)) + 596881340147972746U;
            aOrbiterK = (((aWandererJ + RotL64(aScatter, 11U)) + RotL64(aCarry, 11U)) + 11944412799107412650U) + RotL64(aNonceWordH, 9U);
            aOrbiterH = (aWandererK + RotL64(aCross, 35U)) + 4615021315668210206U;
            aOrbiterD = (((aWandererA + RotL64(aPrevious, 44U)) + RotL64(aCarry, 23U)) + 8497630055977606216U) + aOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aScatter, 5U)) + 11131601107309336885U;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 53U)) + 5935883479805510099U;
            aOrbiterG = (aWandererF + RotL64(aCross, 23U)) + 15629346719765798174U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 5279128339113651273U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 16778365912440331821U) ^ RotL64(aNonceWordA, 13U);
            aOrbiterA = RotL64((aOrbiterA * 705421028266789241U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 16003052937645491524U) + RotL64(aNonceWordC, 11U);
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 6723226158737614764U;
            aOrbiterK = RotL64((aOrbiterK * 16690657664909260573U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 9785784358981219543U) + aOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 10055457337292292710U;
            aOrbiterB = RotL64((aOrbiterB * 17919129940751761111U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 11779163108592974175U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 1177999477942202687U;
            aOrbiterF = RotL64((aOrbiterF * 13475069421684114643U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 9190694445141492214U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 15605342360346353457U;
            aOrbiterH = RotL64((aOrbiterH * 14547769706392595647U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 14877565450677523492U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 1074095623308025684U;
            aOrbiterC = RotL64((aOrbiterC * 7884068939436891093U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 12803174154216941583U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 8813356463693637033U;
            aOrbiterG = RotL64((aOrbiterG * 4898237214617563167U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 6063909634038581414U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 15112191502834052566U;
            aOrbiterE = RotL64((aOrbiterE * 6780741782103553485U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 13926459034757240311U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 4324555954703597591U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 18068922072149745351U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 7183063131331255506U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 18072787091203847052U) ^ aOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12530396154012878153U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 10143386327707219710U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 14624277139785904404U;
            aOrbiterI = RotL64((aOrbiterI * 12100828883424264587U), 11U);
            //
            aIngress = RotL64(aOrbiterE, 53U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterF, 56U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aCross, 35U) + RotL64(aOrbiterB, 21U)) + aOrbiterC);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 44U) + RotL64(aOrbiterJ, 11U)) + aOrbiterB);
            aWandererD = aWandererD + (((RotL64(aIngress, 27U) + aOrbiterA) + RotL64(aOrbiterB, 37U)) + RotL64(aNonceWordB, 15U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 39U) + aOrbiterE) + RotL64(aOrbiterD, 60U));
            aWandererE = aWandererE + ((((RotL64(aCross, 13U) + RotL64(aOrbiterB, 19U)) + aOrbiterD) + RotL64(aCarry, 41U)) + aWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterF, 27U));
            aWandererA = aWandererA + (((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 47U)) + aOrbiterG) + aWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterH, 23U));
            aWandererI = aWandererI + (((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 11U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 52U) + RotL64(aOrbiterA, 29U)) + aOrbiterI) + RotL64(aNonceWordE, 58U));
            aWandererB = aWandererB + ((RotL64(aCross, 19U) + RotL64(aOrbiterH, 34U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 56U));
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 41U);
            aCarry = aCarry + RotL64(aIngress, 48U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 37U) ^ RotL64(aNonceWordA, 58U)) ^ RotL64(aNonceWordH, 27U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 15728U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14836U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 5U) ^ RotL64(aNonceWordB, 54U)) ^ RotL64(aNonceWordC, 19U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9214U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10314U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 42U) ^ RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 47U)) + RotL64(aCarry, 47U)) + 4739486756133131180U;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 29U)) + 16089707555501328184U) + RotL64(aNonceWordA, 17U);
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 53U)) + 15310047330238536453U;
            aOrbiterI = (aWandererB + RotL64(aCross, 21U)) + 7901411596386834955U;
            aOrbiterF = ((((aWandererA + RotL64(aIngress, 14U)) + RotL64(aCarry, 57U)) + 4357555491060982163U) + aOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1]) + RotL64(aNonceWordD, 36U);
            aOrbiterH = ((aWandererF + RotL64(aCross, 41U)) + RotL64(aCarry, 11U)) + 15667085602825720102U;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 19U)) + 8520635334382269253U) + aOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aScatter, 57U)) + 1772509779231068315U;
            aOrbiterC = (aWandererG + RotL64(aCross, 43U)) + 15336170957886025677U;
            aOrbiterE = (aWandererI + RotL64(aScatter, 36U)) + 8628770833489469980U;
            aOrbiterD = (aWandererK + RotL64(aIngress, 39U)) + 15469234024247246228U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 10796430900884288328U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 10660110397012853289U;
            aOrbiterJ = RotL64((aOrbiterJ * 9140007610912037461U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 11202284258711214794U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 17509491802893182994U;
            aOrbiterG = RotL64((aOrbiterG * 9329107599972703671U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 16212572740740103554U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 2190030203761579226U;
            aOrbiterF = RotL64((aOrbiterF * 3101886685668871045U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 12014337082293041909U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 3733531010807001506U;
            aOrbiterK = RotL64((aOrbiterK * 5797362244066062299U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 7100994963061975529U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 17837541162838600258U;
            aOrbiterC = RotL64((aOrbiterC * 8745987361678166553U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 3311518938023146951U) + RotL64(aNonceWordG, 31U);
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 7709505172646831553U;
            aOrbiterA = RotL64((aOrbiterA * 7121143171245765213U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 4979968094554018443U) + RotL64(aNonceWordB, 19U);
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 16822214821463034107U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8618262120451291765U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 8376124175020587079U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 11084586282092424876U) ^ aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5835632742522563537U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 7816368455027681621U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 10893292019060642422U;
            aOrbiterB = RotL64((aOrbiterB * 3995821210667317677U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 13602875505184178486U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 5425735673005681983U) ^ aOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12667085597129312079U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 5995385043278810987U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 4739486756133131180U;
            aOrbiterD = RotL64((aOrbiterD * 15709273328685013399U), 39U);
            //
            aIngress = RotL64(aOrbiterC, 11U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterG, 26U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + RotL64(aOrbiterJ, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aCross, 21U) + RotL64(aOrbiterJ, 35U)) + aOrbiterD);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 23U) + aOrbiterF) + RotL64(aOrbiterA, 39U));
            aWandererB = aWandererB + ((RotL64(aScatter, 27U) + aOrbiterD) + RotL64(aOrbiterE, 14U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterG, 21U)) + RotL64(aNonceWordE, 59U));
            aWandererH = aWandererH + ((((RotL64(aCross, 40U) + aOrbiterC) + RotL64(aOrbiterK, 51U)) + RotL64(aCarry, 5U)) + aWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 53U) + aOrbiterK) + RotL64(aOrbiterD, 41U)) + RotL64(aNonceWordF, 27U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 23U)) + aOrbiterJ);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterI, 5U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 48U) + RotL64(aOrbiterG, 48U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 3U)) + aOrbiterF) + aWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterD, 53U)) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 34U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 44U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 35U) ^ RotL64(aNonceWordH, 13U)) ^ RotL64(aNonceWordD, 53U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 22835U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22942U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 11U) ^ RotL64(aNonceWordC, 35U)) ^ RotL64(aNonceWordE, 22U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21267U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 17319U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aPrevious, 21U)) ^ (RotL64(aCross, 6U) + RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererF + RotL64(aIngress, 11U)) + 9471546960258473684U;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 22U)) + 18050235435948942244U;
            aOrbiterH = ((aWandererH + RotL64(aCross, 27U)) + RotL64(aCarry, 13U)) + 3005107102671544641U;
            aOrbiterD = (aWandererE + RotL64(aPrevious, 37U)) + 17898396434573801850U;
            aOrbiterF = ((aWandererA + RotL64(aCross, 13U)) + 15071602525497771648U) + RotL64(aNonceWordG, 45U);
            aOrbiterE = ((aWandererK + RotL64(aScatter, 43U)) + RotL64(aCarry, 5U)) + 5780119462702672108U;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 57U)) + RotL64(aCarry, 47U)) + 13301326224151025687U;
            aOrbiterG = (aWandererD + RotL64(aIngress, 39U)) + 18129323022260575961U;
            aOrbiterI = (((aWandererB + RotL64(aScatter, 34U)) + 1199228670638790709U) + aOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1]) + RotL64(aNonceWordF, 14U);
            aOrbiterK = (aWandererG + RotL64(aCross, 47U)) + 1839199978088021020U;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 5U)) + 4999517042246790165U) + aOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 8788607633376516299U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 15143903839930468749U;
            aOrbiterH = RotL64((aOrbiterH * 12735914889325422675U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 16674732686428431869U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 15908873150953195581U;
            aOrbiterE = RotL64((aOrbiterE * 18049755517524334107U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 11204775359756474667U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterJ) ^ 2525984309543939465U) ^ aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1]) ^ RotL64(aNonceWordE, 35U);
            aOrbiterB = RotL64((aOrbiterB * 3988529812023791571U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 4566345170476825512U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 14876612901557406267U;
            aOrbiterF = RotL64((aOrbiterF * 9047956948845135339U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 14926290877038883931U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 12710203178186614846U;
            aOrbiterG = RotL64((aOrbiterG * 14841163494801662515U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 7315094513967387996U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 11050116830482816766U) ^ RotL64(aNonceWordH, 27U);
            aOrbiterK = RotL64((aOrbiterK * 3702999495721152019U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 4505368486032503953U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 17905748055257551092U;
            aOrbiterC = RotL64((aOrbiterC * 14775870175093453197U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 5728886950801376350U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 17998141690182325170U;
            aOrbiterD = RotL64((aOrbiterD * 16008599930125391379U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 4325978018819134558U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 13526905108565989379U;
            aOrbiterJ = RotL64((aOrbiterJ * 14121321495714166291U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 10597169665474269506U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 7500801022830471869U;
            aOrbiterI = RotL64((aOrbiterI * 3702717219742363777U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 17063616328548689935U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 9471546960258473684U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3029748230803396737U), 47U);
            //
            aIngress = RotL64(aOrbiterE, 54U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 46U) + aOrbiterE) + RotL64(aOrbiterD, 21U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterB, 18U)) + RotL64(aNonceWordB, 11U)) + aWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 27U)) + aOrbiterD);
            aWandererA = aWandererA + ((RotL64(aCross, 51U) + RotL64(aOrbiterG, 43U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 43U) + aOrbiterA) + RotL64(aOrbiterD, 5U)) + aWandererUpdateSaltA[((aIndex + 14U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 18U) + RotL64(aOrbiterJ, 29U)) + aOrbiterH) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterF, 3U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aScatter, 27U) + RotL64(aOrbiterE, 39U)) + aOrbiterJ) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 39U) + aOrbiterI) + RotL64(aOrbiterA, 12U));
            aWandererI = aWandererI + (((RotL64(aIngress, 13U) + RotL64(aOrbiterF, 35U)) + aOrbiterJ) + RotL64(aNonceWordD, 29U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 57U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 24U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 18U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererG, 35U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 37U) ^ RotL64(aNonceWordH, 19U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 31436U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28421U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 26U) ^ RotL64(aNonceWordE, 53U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29227U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((aIndex + 27054U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 19U) + RotL64(aCross, 51U)) ^ (RotL64(aCarry, 35U) ^ RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (((aWandererG + RotL64(aScatter, 40U)) + 2571116506511057880U) + aOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1]) + RotL64(aNonceWordB, 5U);
            aOrbiterI = (aWandererK + RotL64(aPrevious, 51U)) + 13112435411509707292U;
            aOrbiterC = (aWandererF + RotL64(aCross, 27U)) + 10403251762787357256U;
            aOrbiterF = (aWandererE + RotL64(aIngress, 29U)) + 8461951095541400405U;
            aOrbiterH = (aWandererJ + RotL64(aScatter, 5U)) + 9890793478557463815U;
            aOrbiterD = (aWandererH + RotL64(aCross, 57U)) + 3030229465991783707U;
            aOrbiterA = (aWandererC + RotL64(aIngress, 54U)) + 7273848154043719247U;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 37U)) + RotL64(aCarry, 5U)) + 10681774862516028276U;
            aOrbiterJ = (((aWandererA + RotL64(aScatter, 19U)) + RotL64(aCarry, 23U)) + 7105082755586853104U) + aOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = (((aWandererD + RotL64(aCross, 47U)) + RotL64(aCarry, 47U)) + 6588579345319551129U) + RotL64(aNonceWordC, 35U);
            aOrbiterE = (aWandererB + RotL64(aIngress, 23U)) + 14616333550242386092U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 15439666290229654921U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 3360304356760164799U;
            aOrbiterC = RotL64((aOrbiterC * 5164191920584106237U), 21U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterF) + 14438730801970761889U) + aOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1]) + RotL64(aNonceWordF, 23U);
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 14515616787452085729U) ^ aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2041601927968559821U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 4167853822635132419U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 8950982233003320239U;
            aOrbiterD = RotL64((aOrbiterD * 887144270884244907U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 12391327853728029953U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 7100871010552394421U;
            aOrbiterA = RotL64((aOrbiterA * 16552349374101955967U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 15381697462381887944U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 6801677551341079401U;
            aOrbiterK = RotL64((aOrbiterK * 13325954438427340703U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 947011315719204867U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 6356920162398333481U;
            aOrbiterJ = RotL64((aOrbiterJ * 5566721941682667419U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 8910262020598577378U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 8778455415977526457U;
            aOrbiterG = RotL64((aOrbiterG * 4092470497616637283U), 39U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterJ) + 5585696961453127223U) + aOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1]) + RotL64(aNonceWordG, 47U);
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 9670655481681494412U;
            aOrbiterE = RotL64((aOrbiterE * 7863197168965036383U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 10713004007087085729U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 4036355047492922339U;
            aOrbiterB = RotL64((aOrbiterB * 6923922258047667173U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 14580156873863533497U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 7049502932205025182U;
            aOrbiterI = RotL64((aOrbiterI * 8665428649262370727U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 12707521269341941677U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 2571116506511057880U;
            aOrbiterF = RotL64((aOrbiterF * 2388236789245943699U), 5U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 37U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterB, 24U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 22U) + aOrbiterC) + RotL64(aOrbiterH, 5U));
            aWandererB = aWandererB + (((RotL64(aCross, 13U) + RotL64(aOrbiterA, 11U)) + aOrbiterD) + aWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterG, 46U)) + aOrbiterH) + RotL64(aNonceWordH, 9U));
            aWandererK = aWandererK + (((RotL64(aScatter, 5U) + aOrbiterK) + RotL64(aOrbiterB, 51U)) + aWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterE, 43U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 52U) + aOrbiterH) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 20U)) + aOrbiterJ);
            aWandererH = aWandererH + (((RotL64(aCross, 43U) + RotL64(aOrbiterI, 3U)) + aOrbiterG) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterA, 41U)) + aOrbiterE);
            aWandererI = aWandererI + (((RotL64(aScatter, 41U) + RotL64(aOrbiterF, 29U)) + aOrbiterD) + RotL64(aNonceWordA, 46U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterE, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 60U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 3U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xDC784D27ABE99FDBULL + 0xEE9574CABA0377AEULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xC049E0C012FB9073ULL + 0xAEFEA10EA6D48BB1ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x98D73DA27331512BULL + 0xA03405224B3EF99BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xC490D3D14A1E559BULL + 0xB2CBB0932361C6A3ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xC9505FD96584A6BDULL + 0x953B7379EEB13F95ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xEA3FA09B9B974DB1ULL + 0xCC0D031A2FD1B67FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xAF0BF4B6C877CF0DULL + 0xA2DA4621159EFE5FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xA625E5E23578F4FDULL + 0xCCA8EBFFF2CBEC31ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 21U) ^ RotL64(aNonceWordG, 29U)) ^ RotL64(aNonceWordF, 57U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 1623U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2005U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 27U) ^ RotL64(aNonceWordE, 60U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 289U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((aIndex + 1094U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aIngress, 13U)) ^ (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 26U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererA + RotL64(aScatter, 29U)) + 5510690816044082200U;
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 58U)) + RotL64(aCarry, 41U)) + 15967820875033940530U;
            aOrbiterF = (aWandererK + RotL64(aCross, 23U)) + 539348720848176221U;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 11U)) + 15779318183635560817U) + aOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aScatter, 3U)) + 14511058534424187469U;
            aOrbiterD = (aWandererE + RotL64(aPrevious, 47U)) + 5811130556873428391U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 37U)) + 1085928476499444025U) + RotL64(aNonceWordC, 25U);
            aOrbiterB = (((aWandererJ + RotL64(aIngress, 18U)) + RotL64(aCarry, 53U)) + 6973335316600768130U) + aOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = (((aWandererC + RotL64(aCross, 43U)) + RotL64(aCarry, 27U)) + 10747243745475009744U) + RotL64(aNonceWordG, 31U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 1072260008981349754U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 2018772405352495753U;
            aOrbiterF = RotL64((aOrbiterF * 10840562112080574241U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 1092091597048996547U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 15103140149542167197U;
            aOrbiterD = RotL64((aOrbiterD * 621856991658027989U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 13194619321108681542U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 16749188603268621850U;
            aOrbiterB = RotL64((aOrbiterB * 9575408950550922039U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 7427959503086895166U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 9895804051379551393U) ^ aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2701997336201570715U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 4526020800679774259U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 4484850928870048176U;
            aOrbiterG = RotL64((aOrbiterG * 17556987520625677313U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 1837404844299040155U) + RotL64(aNonceWordF, 42U);
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 15213208978489570694U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7062740584650274133U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 9615231781751396800U) + RotL64(aNonceWordB, 35U);
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 15872192167825648096U;
            aOrbiterH = RotL64((aOrbiterH * 2900526493682580729U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 12530672039655918903U) + aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 10617836782870315804U;
            aOrbiterA = RotL64((aOrbiterA * 9716778004909794973U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 550750725406860977U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 3498554352021622907U;
            aOrbiterK = RotL64((aOrbiterK * 9846933294851238495U), 51U);
            //
            aIngress = RotL64(aOrbiterD, 30U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + RotL64(aOrbiterK, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aCross, 34U) + RotL64(aOrbiterG, 53U)) + aOrbiterB);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 41U) + aOrbiterA) + RotL64(aOrbiterG, 5U));
            aWandererK = aWandererK + (((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterK, 20U)) + aWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 39U)) + aOrbiterD);
            aWandererD = aWandererD + (((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 13U) + aOrbiterB) + RotL64(aOrbiterD, 29U)) + RotL64(aNonceWordD, 7U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 5U) + aOrbiterA) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterG, 34U)) + aOrbiterJ) + aWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 28U) + aOrbiterH) + RotL64(aOrbiterI, 13U)) + RotL64(aNonceWordH, 17U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + RotL64(aWandererD, 60U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 54U) ^ RotL64(aNonceWordF, 23U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 7063U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 7141U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 6U) ^ RotL64(aNonceWordG, 51U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 9143U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8722U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 54U)) + (RotL64(aCross, 27U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererF + RotL64(aPrevious, 10U)) + 13960289014350612206U;
            aOrbiterI = (((aWandererK + RotL64(aIngress, 35U)) + RotL64(aCarry, 5U)) + 3483331015269589730U) + RotL64(aNonceWordH, 59U);
            aOrbiterE = (((aWandererI + RotL64(aScatter, 5U)) + RotL64(aCarry, 13U)) + 6873299241002444518U) + aOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aCross, 39U)) + 3562094007125534229U;
            aOrbiterF = (aWandererC + RotL64(aIngress, 57U)) + 11422367439932782705U;
            aOrbiterA = (aWandererD + RotL64(aPrevious, 18U)) + 532453428514259816U;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 47U)) + RotL64(aCarry, 51U)) + 17810941465810193088U;
            aOrbiterB = (((aWandererA + RotL64(aScatter, 43U)) + 11869759058631106331U) + aOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1]) + RotL64(aNonceWordB, 53U);
            aOrbiterC = (aWandererH + RotL64(aIngress, 27U)) + 8837581071876177566U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 17185378327053837778U) + aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 7578253375676981500U) ^ aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13371647568758721729U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 17112646434432814442U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 14949096407295697881U;
            aOrbiterF = RotL64((aOrbiterF * 14770977858283051753U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 4259590620758467836U) + aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 6534899413644542303U;
            aOrbiterJ = RotL64((aOrbiterJ * 7987609419215568661U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 2637407498893694243U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 15819295597921425711U;
            aOrbiterB = RotL64((aOrbiterB * 5202015597375051399U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 6373559542002699718U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 11694562937392022505U;
            aOrbiterC = RotL64((aOrbiterC * 9311557972331218597U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 3308736483775453062U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 12749929710650475901U) ^ RotL64(aNonceWordG, 54U);
            aOrbiterH = RotL64((aOrbiterH * 248428400724560945U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 1569528215675579656U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 1044077933631689572U;
            aOrbiterD = RotL64((aOrbiterD * 6443796233912755143U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 8393422728124537471U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 2002732612516530754U;
            aOrbiterA = RotL64((aOrbiterA * 13702146823622364279U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 13469191942843147943U) + RotL64(aNonceWordD, 47U);
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 7633171368709520560U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9713514012478203047U), 23U);
            //
            aIngress = RotL64(aOrbiterE, 57U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 36U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 41U));
            aIngress = aIngress + RotL64(aOrbiterJ, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 47U)) + aOrbiterA) + RotL64(aNonceWordE, 49U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 51U) + aOrbiterH) + RotL64(aOrbiterE, 18U)) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 4U) + RotL64(aOrbiterF, 35U)) + aOrbiterI);
            aWandererD = aWandererD + (((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 5U)) + aOrbiterA) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterJ, 43U)) + aOrbiterH);
            aWandererB = aWandererB + ((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 27U)) + aOrbiterB);
            aWandererI = aWandererI ^ ((((RotL64(aCross, 39U) + aOrbiterC) + RotL64(aOrbiterD, 13U)) + RotL64(aNonceWordC, 21U)) + aWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 27U) + aOrbiterI) + RotL64(aOrbiterB, 23U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 60U) + aOrbiterF) + RotL64(aOrbiterC, 52U)) + aWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 58U));
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 43U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 43U) ^ RotL64(aNonceWordH, 21U)) ^ RotL64(aNonceWordB, 35U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12992U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 14122U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 35U) ^ RotL64(aNonceWordA, 3U)) ^ RotL64(aNonceWordC, 57U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 14576U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneC[((aIndex + 15523U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aPrevious, 39U)) ^ (RotL64(aCross, 19U) ^ RotL64(aIngress, 4U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((((aWandererK + RotL64(aCross, 41U)) + RotL64(aCarry, 47U)) + 18144572925667544139U) + aOrbiterAssignSaltF[(((31U - aIndex) + 8U)) & S_SALT1]) + RotL64(aNonceWordE, 21U);
            aOrbiterH = (aWandererD + RotL64(aPrevious, 5U)) + 5659758077574059728U;
            aOrbiterD = (aWandererE + RotL64(aIngress, 53U)) + 6343330616999166392U;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 12U)) + 17754639838410839447U) + aOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aCross, 47U)) + 9451843819849581729U) + RotL64(aNonceWordB, 14U);
            aOrbiterB = (aWandererH + RotL64(aPrevious, 29U)) + 7957854457197462212U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 21U)) + RotL64(aCarry, 23U)) + 1461994799722205010U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 57U)) + RotL64(aCarry, 39U)) + 18002214276252170177U;
            aOrbiterK = (aWandererA + RotL64(aPrevious, 34U)) + 14689869073147027164U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 3978104368003440293U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterA) ^ 8512135845221335386U) ^ aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1]) ^ RotL64(aNonceWordD, 9U);
            aOrbiterD = RotL64((aOrbiterD * 10506667163729414667U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 1477533446382953439U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 2166717790929947990U;
            aOrbiterA = RotL64((aOrbiterA * 6538884492418324461U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 8082437060686606995U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 4363687722464700362U;
            aOrbiterF = RotL64((aOrbiterF * 7199165810993478887U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 15782763348014924206U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 8572509150015960728U;
            aOrbiterH = RotL64((aOrbiterH * 3340528604891897779U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 12248271773316742521U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 9602078627638561949U;
            aOrbiterG = RotL64((aOrbiterG * 1860631869877427405U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 17244849374768558859U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 1030743048280579012U;
            aOrbiterB = RotL64((aOrbiterB * 10858949914285817051U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 17722342363541914280U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 15667504059789880034U) ^ RotL64(aNonceWordF, 19U);
            aOrbiterJ = RotL64((aOrbiterJ * 15872269872168533709U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 12645332941998550794U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 9938135244509986497U;
            aOrbiterI = RotL64((aOrbiterI * 16548185968987392957U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 4024609904162105979U) + aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 6732064218696157303U;
            aOrbiterK = RotL64((aOrbiterK * 3815409766145891393U), 41U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 18U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterF, 26U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterA, 38U)) + RotL64(aNonceWordH, 3U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 11U)) + aOrbiterG) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 47U)) + aOrbiterI);
            aWandererF = aWandererF + (((RotL64(aCross, 12U) + RotL64(aOrbiterK, 19U)) + aOrbiterF) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterK, 3U)) + aOrbiterB) + aWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 57U)) + aOrbiterA);
            aWandererC = aWandererC ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterI, 42U)) + aOrbiterK);
            aWandererE = aWandererE + ((((RotL64(aIngress, 51U) + aOrbiterJ) + RotL64(aOrbiterH, 51U)) + RotL64(aNonceWordC, 55U)) + aWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 4U) + aOrbiterK) + RotL64(aOrbiterJ, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 60U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 53U) ^ RotL64(aNonceWordB, 19U)) ^ RotL64(aNonceWordF, 43U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 21018U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((aIndex + 18734U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 11U) ^ RotL64(aNonceWordA, 22U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20554U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 16909U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 47U) ^ RotL64(aCross, 35U)) + (RotL64(aCarry, 19U) ^ RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererG + RotL64(aIngress, 19U)) + RotL64(aCarry, 57U)) + 15652862298542575895U;
            aOrbiterJ = (aWandererI + RotL64(aScatter, 52U)) + 16925323928418184554U;
            aOrbiterB = ((aWandererB + RotL64(aCross, 35U)) + RotL64(aCarry, 29U)) + 4413861484961668394U;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 13U)) + 2215946422098155969U) + RotL64(aNonceWordB, 11U);
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 43U)) + 14975185533513111110U) + aOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = ((((aWandererH + RotL64(aScatter, 39U)) + RotL64(aCarry, 47U)) + 9711613814905834552U) + aOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1]) + RotL64(aNonceWordH, 25U);
            aOrbiterC = (aWandererC + RotL64(aCross, 60U)) + 13154957291850149471U;
            aOrbiterK = (aWandererA + RotL64(aPrevious, 5U)) + 5058313016418534840U;
            aOrbiterI = (aWandererF + RotL64(aCross, 47U)) + 15011423472941211620U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 2030053257469580168U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 150530795186791193U;
            aOrbiterB = RotL64((aOrbiterB * 11106050063717096073U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 10878237472104183427U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 11724672539469573109U) ^ aOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16158741837357985395U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 9589700906445846956U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 1367381624958248949U) ^ RotL64(aNonceWordF, 45U);
            aOrbiterC = RotL64((aOrbiterC * 8459515089081211977U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 12003215666757518106U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 11232479330848006729U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10993290955464593033U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 13013910456628561621U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 6092509838924105265U;
            aOrbiterA = RotL64((aOrbiterA * 805601154718006061U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 11999225836250312801U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 14421271973875748413U;
            aOrbiterH = RotL64((aOrbiterH * 9529010940887430157U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 15536288285741825272U) + aOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 2071793889925436679U;
            aOrbiterK = RotL64((aOrbiterK * 1526376970151714589U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 5622386476463436967U) + aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 16147972771639168516U;
            aOrbiterI = RotL64((aOrbiterI * 11826916832825159095U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 4519892856053952290U) + RotL64(aNonceWordC, 54U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 12059500374938843538U;
            aOrbiterJ = RotL64((aOrbiterJ * 14987533625537956299U), 39U);
            //
            aIngress = RotL64(aOrbiterE, 46U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterC, 27U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterB, 35U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterC, 19U)) + RotL64(aCarry, 5U)) + RotL64(aNonceWordD, 35U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 43U)) + aOrbiterK) + aWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterE, 12U)) + aOrbiterK) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 38U) + aOrbiterI) + RotL64(aOrbiterJ, 57U)) + RotL64(aNonceWordE, 57U));
            aWandererB = aWandererB + (((RotL64(aCross, 57U) + RotL64(aOrbiterE, 5U)) + aOrbiterC) + aWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterA, 27U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterJ, 47U)) + aOrbiterG);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 34U) + aOrbiterH) + RotL64(aOrbiterB, 52U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 40U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 13U) ^ RotL64(aNonceWordA, 30U)) ^ RotL64(aNonceWordH, 39U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24737U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25791U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 47U) ^ RotL64(aNonceWordB, 29U)) ^ RotL64(aNonceWordE, 57U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22281U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 22470U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aPrevious, 27U)) ^ (RotL64(aIngress, 13U) + RotL64(aCross, 56U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (((aWandererI + RotL64(aCross, 52U)) + 15316464782468770057U) + aOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1]) + RotL64(aNonceWordG, 45U);
            aOrbiterA = (((aWandererA + RotL64(aIngress, 39U)) + RotL64(aCarry, 3U)) + 6642872057476351588U) + RotL64(aNonceWordA, 11U);
            aOrbiterD = (((aWandererF + RotL64(aScatter, 35U)) + RotL64(aCarry, 27U)) + 660732654689529192U) + aOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = (aWandererD + RotL64(aPrevious, 19U)) + 7235418086884000655U;
            aOrbiterB = (aWandererE + RotL64(aScatter, 28U)) + 14784518476694580493U;
            aOrbiterC = (aWandererB + RotL64(aCross, 57U)) + 12222433977933449375U;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 5U)) + RotL64(aCarry, 39U)) + 8573001207708329927U;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 13U)) + 16035256260815013172U;
            aOrbiterJ = (aWandererG + RotL64(aCross, 47U)) + 15767726974121910203U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 17712217935322939971U) + aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 13488963456923357159U;
            aOrbiterD = RotL64((aOrbiterD * 16785285630840310405U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 10222949131965611079U) + aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 1495561412321657209U;
            aOrbiterC = RotL64((aOrbiterC * 9706305581868526265U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 16156530750584361434U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 7773792489045606309U) ^ aOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10730624207715601393U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 11544578291333360613U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 3665587867634242865U;
            aOrbiterJ = RotL64((aOrbiterJ * 4840528190844842595U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 15248434984650998090U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 15487979645426567581U;
            aOrbiterI = RotL64((aOrbiterI * 10868107809356766183U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 6972347795052712690U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 16074994810010431338U;
            aOrbiterH = RotL64((aOrbiterH * 1262655238856775853U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 16851139687900415292U) + RotL64(aNonceWordB, 15U);
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 14630026837021552812U) ^ RotL64(aNonceWordC, 27U);
            aOrbiterE = RotL64((aOrbiterE * 9577900853521254603U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 14236330619137368169U) + aOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 17778707026111136216U;
            aOrbiterA = RotL64((aOrbiterA * 16239561893843454747U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 9390961969105999083U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 1174881758316573228U;
            aOrbiterB = RotL64((aOrbiterB * 6602061268277529311U), 43U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterD, 47U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + (RotL64(aOrbiterK, 26U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 26U) + RotL64(aOrbiterC, 44U)) + aOrbiterA) + RotL64(aNonceWordF, 14U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 35U) + aOrbiterE) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 51U) + aOrbiterE) + RotL64(aOrbiterC, 29U));
            aWandererD = aWandererD + ((RotL64(aCross, 47U) + RotL64(aOrbiterD, 51U)) + aOrbiterB);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterK, 23U)) + aOrbiterH) + aWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 43U) + RotL64(aOrbiterD, 5U)) + aOrbiterC) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 56U) + aOrbiterI) + RotL64(aOrbiterC, 12U));
            aWandererI = aWandererI + ((RotL64(aScatter, 11U) + RotL64(aOrbiterC, 39U)) + aOrbiterJ);
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterD, 57U)) + RotL64(aNonceWordH, 29U)) + aWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 50U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 27U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 35U) ^ RotL64(aNonceWordE, 14U)) ^ RotL64(aNonceWordF, 43U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31047U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28791U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 53U) ^ RotL64(aNonceWordG, 37U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27445U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31012U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aIngress, 58U)) ^ (RotL64(aCross, 23U) + RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererE + RotL64(aScatter, 60U)) + 13499155707765393469U;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 13U)) + RotL64(aCarry, 43U)) + 3740324981823726185U;
            aOrbiterH = (aWandererK + RotL64(aCross, 3U)) + 5470765363949735652U;
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 23U)) + 3446436171274452326U) + aOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 51U)) + RotL64(aCarry, 57U)) + 1778929412631211933U;
            aOrbiterK = (aWandererG + RotL64(aIngress, 47U)) + 14666308799855220954U;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 41U)) + 4548410236791175055U) + RotL64(aNonceWordH, 42U);
            aOrbiterI = ((((aWandererC + RotL64(aCross, 27U)) + RotL64(aCarry, 11U)) + 5829739767694190372U) + aOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1]) + RotL64(aNonceWordA, 45U);
            aOrbiterA = (aWandererD + RotL64(aScatter, 34U)) + 14319231414903675748U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 1513851750246111405U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 1685620217748986019U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9286548037413609445U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 16284162182006054402U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 6271539598462003309U;
            aOrbiterJ = RotL64((aOrbiterJ * 13923286694131331137U), 13U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterJ) + 12669312437565969473U) + aOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1]) + RotL64(aNonceWordC, 9U);
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 11894755313393001665U;
            aOrbiterF = RotL64((aOrbiterF * 12556759675372354075U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 6315983824634946566U) + RotL64(aNonceWordE, 11U);
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 17106616474222892782U;
            aOrbiterI = RotL64((aOrbiterI * 167205520766791073U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 13350266700180455548U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 4608846311203767162U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2504857468837437365U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 14195866746143604365U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 7917977448256795054U;
            aOrbiterE = RotL64((aOrbiterE * 5927771378657284557U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 10707336923305131629U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 17122696159336995392U;
            aOrbiterC = RotL64((aOrbiterC * 13953518568670659191U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 5182322763573586116U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 6503754948502556246U;
            aOrbiterK = RotL64((aOrbiterK * 14749002194140663519U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 14907832047832987341U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 6258064448676621346U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4407960312705621487U), 5U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 27U);
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 30U));
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterC, 19U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 26U) + aOrbiterK) + RotL64(aOrbiterI, 28U));
            aWandererC = aWandererC + (((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterH, 43U)) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterH, 5U)) + aOrbiterA);
            aWandererA = aWandererA + ((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterH, 23U));
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 57U) + aOrbiterI) + RotL64(aOrbiterB, 47U)) + RotL64(aNonceWordB, 21U)) + aWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 13U)) + aOrbiterI) + RotL64(aNonceWordD, 47U)) + aWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 37U) + aOrbiterJ) + RotL64(aOrbiterC, 58U));
            aWandererG = aWandererG + (((RotL64(aCross, 52U) + RotL64(aOrbiterE, 39U)) + aOrbiterC) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 34U));
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xF33A9755FE01CA31ULL + 0xDED360F7A0B4C6F6ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xCAA3F9AF1826EBCFULL + 0xFFDC87068E9BBE45ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x8B29CCD1C7E2BFE5ULL + 0xFF45D59F97EE0375ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xF70220B3EFD97C75ULL + 0xA9142BDC7B2AEB3FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xBEFB23D22C6AC309ULL + 0xCF79582D86534E7CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x8BCC8BC81F68DD41ULL + 0xEA02988D9A98CD8EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xC12881DD094AEA2FULL + 0xE0B4B3E03C4F564BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x90AFDD158123ADC9ULL + 0xD736442362A62449ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 53U) ^ RotL64(aNonceWordA, 40U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 123U)) & S_BLOCK1], 21U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 5172U)) & W_KEY1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 27U) ^ RotL64(aNonceWordH, 3U));
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 177U)) & W_KEY1], 57U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 573U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 37U) + RotL64(aIngress, 22U)) ^ (RotL64(aCarry, 57U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterB = ((aWandererE + RotL64(aCross, 34U)) + RotL64(aCarry, 37U)) + 2915859148137000694U;
            aOrbiterA = (((aWandererK + RotL64(aIngress, 57U)) + RotL64(aCarry, 3U)) + 210680583721444425U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 51U)) + 6668118118775650387U) + RotL64(aNonceWordE, 51U);
            aOrbiterE = (aWandererD + RotL64(aScatter, 43U)) + 15794200818099010989U;
            aOrbiterK = (((aWandererF + RotL64(aPrevious, 27U)) + RotL64(aCarry, 21U)) + 6565076707062828369U) + RotL64(aNonceWordG, 9U);
            aOrbiterI = ((aWandererH + RotL64(aCross, 21U)) + 16323164497808856719U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aScatter, 13U)) + 7965435318816716560U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 7390281030573369017U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 2269738866911824875U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1198697877998135567U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 9664014216039993873U) + RotL64(aNonceWordH, 31U);
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 18284857398028357633U;
            aOrbiterK = RotL64((aOrbiterK * 8402008251343393737U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 367667619795303009U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 7935945060956274197U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5481786693511955209U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 16683666162337789540U) + RotL64(aNonceWordB, 18U);
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 10655658270998102390U;
            aOrbiterG = RotL64((aOrbiterG * 15231596813382239841U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 8307037916581540297U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 3247742749860703524U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15052136713218656641U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 10446792483683818139U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 16374602929344972364U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12599903932725787599U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 2411334498322777183U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 1093701164116833765U;
            aOrbiterA = RotL64((aOrbiterA * 13129220206835381729U), 35U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 41U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 14U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + RotL64(aOrbiterI, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 54U) + RotL64(aOrbiterG, 19U)) + aOrbiterE);
            aWandererB = aWandererB + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 36U)) + aOrbiterI) + RotL64(aCarry, 11U)) + aPhaseAWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 53U)) + aOrbiterG) + RotL64(aNonceWordD, 57U));
            aWandererH = aWandererH + ((RotL64(aCross, 23U) + RotL64(aOrbiterA, 3U)) + aOrbiterK);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 37U) + aOrbiterG) + RotL64(aOrbiterK, 11U));
            aWandererF = aWandererF + ((((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterH, 43U)) + RotL64(aCarry, 53U)) + aPhaseAWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 27U)) + aOrbiterK) + RotL64(aNonceWordC, 15U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 18U));
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 21U) ^ RotL64(aNonceWordF, 30U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 6452U)) & S_BLOCK1], 39U) ^ RotL64(mSource[((aIndex + 7081U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 21U) ^ RotL64(aNonceWordD, 35U));
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 8958U)) & W_KEY1], 5U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 10748U)) & W_KEY1], 58U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 21U)) ^ (RotL64(aCross, 38U) + RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 41U)) + 2177539223979303669U;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 22U)) + RotL64(aCarry, 35U)) + 3962004686551521471U;
            aOrbiterG = ((aWandererH + RotL64(aCross, 57U)) + 8457602312617147662U) + RotL64(aNonceWordG, 37U);
            aOrbiterD = ((aWandererE + RotL64(aIngress, 51U)) + RotL64(aCarry, 19U)) + 18011802451816510632U;
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 35U)) + 9046101759168876832U) + RotL64(aNonceWordE, 46U);
            aOrbiterA = ((aWandererF + RotL64(aScatter, 29U)) + 11135620637431969597U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = (((aWandererB + RotL64(aCross, 11U)) + RotL64(aCarry, 3U)) + 15913029940697999701U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 16304193109948135982U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 13208892298820080981U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15093751072618884859U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 4182377898949419225U) + RotL64(aNonceWordC, 55U);
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 13970137023071326151U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9075061559681739865U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 8402396284835248583U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 8859190834060657829U;
            aOrbiterD = RotL64((aOrbiterD * 13552418608113716117U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 9760005337757990392U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 14108277760135744897U;
            aOrbiterF = RotL64((aOrbiterF * 4474681104256093885U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 12226316121949012350U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 3456392186754113960U;
            aOrbiterB = RotL64((aOrbiterB * 8704729827929941215U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 5004087958637038973U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterC) ^ 7176881295123125567U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1]) ^ RotL64(aNonceWordB, 7U);
            aOrbiterA = RotL64((aOrbiterA * 15272157962928021009U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 10889800478505074438U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 13728832441482547824U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17588477761978646139U), 43U);
            //
            aIngress = RotL64(aOrbiterA, 29U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterF, 4U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 47U)) + aOrbiterB);
            aWandererD = aWandererD + ((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterD, 6U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 43U) + aOrbiterJ) + RotL64(aOrbiterC, 57U));
            aWandererF = aWandererF + ((((RotL64(aCross, 29U) + RotL64(aOrbiterF, 41U)) + aOrbiterA) + RotL64(aCarry, 27U)) + RotL64(aNonceWordH, 29U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 13U) + aOrbiterJ) + RotL64(aOrbiterD, 35U));
            aWandererH = aWandererH + ((((RotL64(aScatter, 20U) + aOrbiterJ) + RotL64(aOrbiterG, 13U)) + RotL64(aCarry, 5U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((((RotL64(aCross, 57U) + RotL64(aOrbiterC, 19U)) + aOrbiterA) + RotL64(aNonceWordF, 17U)) + aPhaseAWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 42U));
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 53U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 43U) ^ RotL64(aNonceWordF, 21U)) ^ RotL64(aNonceWordH, 13U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13071U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14305U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 21U) ^ RotL64(aNonceWordG, 5U));
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 11027U)) & W_KEY1], 58U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 12213U)) & W_KEY1], 43U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCarry, 35U)) ^ (RotL64(aCross, 57U) + RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 37U)) + 18302975933754610273U) + RotL64(aNonceWordC, 21U);
            aOrbiterI = ((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 11U)) + 16736972646771456082U;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 21U)) + 17389406266488137442U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aCross, 47U)) + RotL64(aCarry, 27U)) + 5252511566486165539U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 11U)) + 5730715427422747640U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 53U)) + 6412695646456045825U) + aPhaseAOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (((aWandererB + RotL64(aPrevious, 28U)) + RotL64(aCarry, 43U)) + 9539701605708994494U) + RotL64(aNonceWordD, 34U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 18355107116412945722U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 11735742491750132942U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 18129835093627763685U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 12363819388562658842U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 5861430292304371543U;
            aOrbiterI = RotL64((aOrbiterI * 12989055611235382695U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 15027487084595017708U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 7012850020745791926U;
            aOrbiterK = RotL64((aOrbiterK * 15952928839355613939U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 11904871669287886120U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 11199760114477343208U) ^ RotL64(aNonceWordG, 31U);
            aOrbiterE = RotL64((aOrbiterE * 7156374911847525867U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 3856004502263742700U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 3705931243173921893U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10334871178498711485U), 23U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterC) + 12305785390539209389U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1]) + RotL64(aNonceWordB, 11U);
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 18057980996551978823U;
            aOrbiterA = RotL64((aOrbiterA * 4850564181113470859U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 3229431819292153014U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 2994716629242460094U;
            aOrbiterC = RotL64((aOrbiterC * 1029427328395257917U), 29U);
            //
            aIngress = RotL64(aOrbiterI, 29U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + RotL64(aOrbiterG, 36U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aScatter, 13U) + aOrbiterG) + RotL64(aOrbiterE, 51U)) + RotL64(aCarry, 43U)) + aPhaseAWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 21U) + aOrbiterI) + RotL64(aOrbiterK, 29U));
            aWandererD = aWandererD + (((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 5U)) + aOrbiterE) + RotL64(aNonceWordH, 35U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterC, 13U)) + aOrbiterG);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterC, 43U)) + RotL64(aCarry, 23U)) + aPhaseAWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterI, 36U)) + aOrbiterE);
            aWandererC = aWandererC + (((RotL64(aIngress, 41U) + RotL64(aOrbiterE, 21U)) + aOrbiterK) + RotL64(aNonceWordE, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 40U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + RotL64(aWandererI, 35U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 50U) ^ RotL64(aNonceWordC, 13U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 19689U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((aIndex + 20266U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 56U) ^ RotL64(aNonceWordA, 19U)) ^ RotL64(aNonceWordB, 35U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21517U)) & S_BLOCK1], 5U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 20082U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 13U) ^ RotL64(aCross, 27U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 40U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 11U)) + 9914837590440975587U) + aPhaseAOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aCross, 57U)) + 6706125076401958051U) + RotL64(aNonceWordG, 7U);
            aOrbiterD = (aWandererI + RotL64(aPrevious, 47U)) + 16570817772679258409U;
            aOrbiterA = ((((aWandererK + RotL64(aScatter, 41U)) + RotL64(aCarry, 11U)) + 6843705658115186948U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1]) + RotL64(aNonceWordE, 5U);
            aOrbiterE = (aWandererA + RotL64(aCross, 19U)) + 16099930446791572351U;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 3U)) + RotL64(aCarry, 27U)) + 5420550009556030459U;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 34U)) + RotL64(aCarry, 57U)) + 5729549069420177477U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 15590601126188675834U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 13044027390998620029U;
            aOrbiterD = RotL64((aOrbiterD * 16845199115313444123U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 11068338135659636772U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 6584988841809544332U;
            aOrbiterB = RotL64((aOrbiterB * 1683336180438945439U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 8516813219883915404U) + RotL64(aNonceWordD, 6U);
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 10647314042912492785U;
            aOrbiterG = RotL64((aOrbiterG * 15559481057047148785U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 201691689889605304U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 15512161798401184003U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11473219183982564709U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 3883760518944464145U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 13861805129175491145U;
            aOrbiterJ = RotL64((aOrbiterJ * 17194438894492581181U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 12019138626550801486U) + RotL64(aNonceWordH, 11U);
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 13030350224959652248U;
            aOrbiterA = RotL64((aOrbiterA * 11724200983306280107U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 2643807255422544248U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 4127143302485631794U;
            aOrbiterK = RotL64((aOrbiterK * 5441038881111578487U), 41U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 27U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 35U) + RotL64(aOrbiterJ, 11U)) + aOrbiterD) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 6U) + aOrbiterG) + RotL64(aOrbiterK, 19U)) + RotL64(aNonceWordF, 19U));
            aWandererC = aWandererC + ((((RotL64(aCross, 29U) + RotL64(aOrbiterA, 35U)) + aOrbiterE) + RotL64(aCarry, 39U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterE, 27U)) + aOrbiterK);
            aWandererA = aWandererA + ((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterD, 42U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 41U) + aOrbiterE) + RotL64(aOrbiterG, 53U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 5U)) + aOrbiterB) + RotL64(aNonceWordA, 35U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 34U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 35U) ^ RotL64(aNonceWordB, 5U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 27081U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((aIndex + 26942U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 27U) ^ RotL64(aNonceWordA, 43U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25741U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((aIndex + 23799U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 19U) + RotL64(aCarry, 35U)) + (RotL64(aCross, 51U) ^ RotL64(aIngress, 4U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterA = (((aWandererG + RotL64(aScatter, 53U)) + 17074147006464019918U) + aPhaseAOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1]) + RotL64(aNonceWordG, 39U);
            aOrbiterG = (((aWandererF + RotL64(aPrevious, 29U)) + RotL64(aCarry, 47U)) + 10559516626129419928U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aIngress, 18U)) + RotL64(aCarry, 35U)) + 13280363679503946221U;
            aOrbiterE = (aWandererJ + RotL64(aCross, 41U)) + 17657115422132457413U;
            aOrbiterI = (aWandererD + RotL64(aIngress, 35U)) + 13325837013304973008U;
            aOrbiterD = ((aWandererI + RotL64(aCross, 3U)) + 3059707750486106037U) + RotL64(aNonceWordC, 49U);
            aOrbiterF = ((aWandererH + RotL64(aScatter, 47U)) + RotL64(aCarry, 21U)) + 4529045702503050852U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 10726578475550904292U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 14832537837996659885U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 808060368961520519U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 220094417441809246U) + RotL64(aNonceWordF, 59U);
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 15343130035105342194U;
            aOrbiterA = RotL64((aOrbiterA * 7984652435043810845U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 16592263353426409884U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 15649290906447931918U;
            aOrbiterE = RotL64((aOrbiterE * 8405875177836650731U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 11437410545843708269U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 5859769136073011444U;
            aOrbiterG = RotL64((aOrbiterG * 1065016088086441107U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 15188064100307340341U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 4367466521843260049U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15916715854192820923U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 8482617283860566845U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 2585745804937342972U) ^ RotL64(aNonceWordH, 15U);
            aOrbiterD = RotL64((aOrbiterD * 8267269625632139809U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 1687641344403425541U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 13667916445979421400U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8191322670355590027U), 47U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterI, 5U);
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 58U));
            aIngress = aIngress + RotL64(aOrbiterD, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 57U) + aOrbiterI) + RotL64(aOrbiterE, 35U)) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 4U) + RotL64(aOrbiterA, 57U)) + aOrbiterG) + aPhaseAWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 21U) + RotL64(aOrbiterI, 21U)) + aOrbiterG) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 11U) + aOrbiterF) + RotL64(aOrbiterD, 41U)) + RotL64(aNonceWordE, 26U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterF, 50U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterI, 29U)) + aPhaseAWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 37U) + aOrbiterA) + RotL64(aOrbiterB, 11U)) + RotL64(aNonceWordA, 43U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 34U));
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 53U) ^ RotL64(aNonceWordF, 43U)) ^ RotL64(aNonceWordD, 10U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31246U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30107U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 36U) ^ RotL64(aNonceWordC, 5U)) ^ RotL64(aNonceWordA, 19U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28062U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30634U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 29U) + RotL64(aIngress, 13U)) ^ (RotL64(aCarry, 41U) + RotL64(aPrevious, 56U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterC = ((((aWandererI + RotL64(aIngress, 35U)) + RotL64(aCarry, 19U)) + 12027839670755583592U) + aPhaseAOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1]) + RotL64(aNonceWordC, 39U);
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 5U)) + 15380130703509859843U;
            aOrbiterA = ((aWandererA + RotL64(aCross, 41U)) + 4590907433867798074U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = (aWandererF + RotL64(aScatter, 19U)) + 1754574023602519724U;
            aOrbiterH = ((aWandererE + RotL64(aCross, 11U)) + RotL64(aCarry, 3U)) + 9832756659564903767U;
            aOrbiterG = (((aWandererC + RotL64(aPrevious, 54U)) + RotL64(aCarry, 53U)) + 5035088494491470403U) + RotL64(aNonceWordG, 28U);
            aOrbiterJ = (aWandererB + RotL64(aScatter, 29U)) + 14199170923323644638U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 8325619421264440438U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 969534320779067977U;
            aOrbiterA = RotL64((aOrbiterA * 17767548306355264705U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 270575869402913847U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 13344806516599578910U;
            aOrbiterH = RotL64((aOrbiterH * 10193544126281901579U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 15143147951139409101U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 14425582489214169238U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16893787086337916355U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 13951127523239064584U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 14177925225918293579U;
            aOrbiterJ = RotL64((aOrbiterJ * 13079514031864998485U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 8258920744278218901U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 7408161179397242453U;
            aOrbiterC = RotL64((aOrbiterC * 975737128100519169U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 8581481606764773468U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 10078416198417433133U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1102721083915858247U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 18299772198826189580U) + RotL64(aNonceWordA, 35U);
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 18304668908084397946U) ^ RotL64(aNonceWordB, 7U);
            aOrbiterE = RotL64((aOrbiterE * 10589455451200578687U), 13U);
            //
            aIngress = RotL64(aOrbiterG, 27U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterC, 38U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aScatter, 27U) + aOrbiterE) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 47U)) + RotL64(aNonceWordH, 5U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterC, 41U)) + aOrbiterG);
            aWandererB = aWandererB + (((RotL64(aIngress, 19U) + aOrbiterH) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 56U)) + aOrbiterA);
            aWandererF = aWandererF + ((((RotL64(aIngress, 37U) + aOrbiterH) + RotL64(aOrbiterG, 3U)) + RotL64(aNonceWordE, 25U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterE, 29U)) + aOrbiterH) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 60U) + RotL64(aOrbiterJ, 23U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererA, 46U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + RotL64(aWandererJ, 21U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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

void TwistExpander_Cricket_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xA4749D5E44FDD177ULL + 0xEEC35DB6DAF0BAB1ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xD73653E04C1BD95FULL + 0xFD583FA9D0217498ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xB45A7E94C58766C1ULL + 0xB3072A8DD03A3313ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE325D66E057A9E63ULL + 0x9E66D399BB71DE24ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA4C4AA8891FB2CDFULL + 0xE4B05C31259BC17AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xE4ED3726000734B1ULL + 0xFDAD6CF54A72CADDULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xF64605C897CF4DFDULL + 0xE5B3C234EEAD7A7EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xAE3037967A804863ULL + 0x80DDD345593AF160ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 13U) ^ RotL64(aNonceWordB, 43U)) ^ RotL64(aNonceWordG, 3U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 738U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneC[((aIndex + 4062U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 56U) ^ RotL64(aNonceWordF, 27U)) ^ RotL64(aNonceWordD, 5U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 862U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 2416U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCarry, 4U)) ^ (RotL64(aPrevious, 53U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 47U)) + 9630214189402543339U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = (((aWandererE + RotL64(aScatter, 58U)) + RotL64(aCarry, 11U)) + 4072576573737526819U) + aPhaseBOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aCross, 39U)) + 15994787452709618869U) + RotL64(aNonceWordC, 49U);
            aOrbiterK = ((aWandererI + RotL64(aIngress, 13U)) + RotL64(aCarry, 43U)) + 6403240137132259482U;
            aOrbiterF = (((aWandererH + RotL64(aCross, 29U)) + RotL64(aCarry, 23U)) + 10229266900170507720U) + RotL64(aNonceWordB, 17U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 5025294577989748989U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 16696461238217956883U;
            aOrbiterI = RotL64((aOrbiterI * 15993828976234917577U), 13U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterF) + 9878318855341719119U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1]) + RotL64(aNonceWordH, 46U);
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 16086635438116177346U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5585682357395705671U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 12295437783084203730U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 7681150419912842402U) ^ RotL64(aNonceWordF, 35U);
            aOrbiterK = RotL64((aOrbiterK * 7289497379725191451U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 2639104034287637448U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 12298170009332243573U;
            aOrbiterC = RotL64((aOrbiterC * 9397919591171238575U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 3485932317267669626U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 16569551670038752475U;
            aOrbiterF = RotL64((aOrbiterF * 8139802826402217631U), 39U);
            //
            aIngress = RotL64(aOrbiterC, 53U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 14U));
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 47U)) + aOrbiterF) + RotL64(aCarry, 5U)) + RotL64(aNonceWordE, 7U));
            aWandererH = aWandererH ^ ((((RotL64(aCross, 29U) + RotL64(aOrbiterD, 19U)) + aOrbiterK) + RotL64(aNonceWordA, 53U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterC, 5U)) + aOrbiterK);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 38U) + aOrbiterC) + RotL64(aOrbiterF, 29U)) + aPhaseBWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterI, 38U)) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 40U));
            aCarry = aCarry + RotL64(aWandererK, 27U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 35U) ^ RotL64(aNonceWordB, 56U)) ^ RotL64(aNonceWordD, 3U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 6252U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((aIndex + 5606U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 43U) ^ RotL64(aNonceWordF, 3U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9805U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((aIndex + 9999U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 22U) + RotL64(aIngress, 3U)) ^ (RotL64(aPrevious, 51U) + RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterC = (((aWandererH + RotL64(aCross, 27U)) + RotL64(aCarry, 53U)) + 2225397913940961213U) + aPhaseBOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = (aWandererD + RotL64(aIngress, 19U)) + 8342544893601343643U;
            aOrbiterH = (((aWandererG + RotL64(aScatter, 5U)) + RotL64(aCarry, 37U)) + 162922186381417187U) + RotL64(aNonceWordD, 48U);
            aOrbiterF = (((aWandererK + RotL64(aPrevious, 37U)) + 11660218373710972210U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1]) + RotL64(aNonceWordC, 45U);
            aOrbiterD = ((aWandererI + RotL64(aIngress, 50U)) + RotL64(aCarry, 19U)) + 14909034764605802354U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 16776955237009701511U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 5834487809188925253U;
            aOrbiterH = RotL64((aOrbiterH * 4458820879204327709U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 1498492772767040320U) + RotL64(aNonceWordE, 27U);
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 4161765458781579617U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15535994410289065281U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 10511923076962447765U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 8575954471692620021U;
            aOrbiterC = RotL64((aOrbiterC * 12526744988828982731U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 6536325446331340573U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 1790628986900286346U;
            aOrbiterE = RotL64((aOrbiterE * 5262997114200816715U), 21U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterC) + 2623814807619278590U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]) + RotL64(aNonceWordA, 5U);
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 11676970995834706612U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10057461115132434901U), 43U);
            //
            aIngress = RotL64(aOrbiterD, 19U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterH, 29U)) + RotL64(aCarry, 47U)) + RotL64(aNonceWordF, 7U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 30U) + aOrbiterE) + RotL64(aOrbiterF, 19U)) + aPhaseBWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 37U)) + aOrbiterC) + RotL64(aCarry, 19U)) + aPhaseBWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 43U) + aOrbiterF) + RotL64(aOrbiterH, 4U)) + RotL64(aNonceWordB, 31U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 51U) + aOrbiterC) + RotL64(aOrbiterE, 57U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 51U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 43U) ^ RotL64(aNonceWordC, 4U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15693U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13353U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 56U) ^ RotL64(aNonceWordG, 3U)) ^ RotL64(aNonceWordA, 29U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15187U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13266U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 14U) + RotL64(aCarry, 41U)) ^ (RotL64(aCross, 29U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterA = ((aWandererA + RotL64(aScatter, 52U)) + 15045917390223766480U) + RotL64(aNonceWordD, 31U);
            aOrbiterG = ((aWandererF + RotL64(aIngress, 3U)) + RotL64(aCarry, 39U)) + 10763054007033668758U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 27U)) + RotL64(aCarry, 53U)) + 13190170142593666607U;
            aOrbiterH = ((aWandererB + RotL64(aCross, 13U)) + 9657025731441167065U) + aPhaseBOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = ((((aWandererK + RotL64(aScatter, 35U)) + RotL64(aCarry, 13U)) + 11433367178975954211U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 20U)) & S_SALT1]) + RotL64(aNonceWordC, 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 17904920143996810366U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 3244383020512113283U;
            aOrbiterK = RotL64((aOrbiterK * 552521443123433353U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 6538815775171139091U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterH) ^ 7195368312757976343U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]) ^ RotL64(aNonceWordE, 47U);
            aOrbiterG = RotL64((aOrbiterG * 10515679176134176565U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 18134430713910279374U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 6571776588427107976U;
            aOrbiterA = RotL64((aOrbiterA * 11916502085252589161U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 11830778129647517758U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 9793702760907767365U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4096246227968677179U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 2287235876793192036U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 8951959188326141794U) ^ RotL64(aNonceWordB, 7U);
            aOrbiterD = RotL64((aOrbiterD * 9968356718110753845U), 19U);
            //
            aIngress = RotL64(aOrbiterH, 47U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterG, 57U)) + aOrbiterA) + RotL64(aNonceWordF, 29U));
            aWandererA = aWandererA ^ ((((RotL64(aCross, 3U) + RotL64(aOrbiterD, 14U)) + aOrbiterK) + RotL64(aNonceWordA, 12U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 47U)) + aOrbiterH) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterH, 23U)) + aOrbiterK) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 40U) + RotL64(aOrbiterG, 39U)) + aOrbiterK) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 5U) ^ RotL64(aNonceWordC, 13U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 18062U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 19893U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 53U) ^ RotL64(aNonceWordD, 11U)) ^ RotL64(aNonceWordE, 3U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20243U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneD[((aIndex + 20423U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCarry, 11U)) + (RotL64(aPrevious, 37U) + RotL64(aCross, 52U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterJ = (((aWandererJ + RotL64(aCross, 5U)) + RotL64(aCarry, 51U)) + 3684295017013759987U) + RotL64(aNonceWordF, 29U);
            aOrbiterB = (((aWandererC + RotL64(aPrevious, 39U)) + RotL64(aCarry, 39U)) + 6740408842457292881U) + RotL64(aNonceWordB, 18U);
            aOrbiterG = ((aWandererD + RotL64(aIngress, 51U)) + 4563975890702399441U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aScatter, 13U)) + 797804144825287940U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aIngress, 24U)) + RotL64(aCarry, 13U)) + 2763779540450101303U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 13211846164102089685U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 15214578447281401982U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12107189619131483661U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 13745208628754232427U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 17358621225969190747U;
            aOrbiterJ = RotL64((aOrbiterJ * 5325024317338823061U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 779739369960480023U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 4370963533701407813U) ^ RotL64(aNonceWordG, 21U);
            aOrbiterE = RotL64((aOrbiterE * 3123135216876641039U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 6061333005507739975U) + RotL64(aNonceWordE, 11U);
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 3589705340762734456U;
            aOrbiterB = RotL64((aOrbiterB * 16499293983611196967U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 10607697666369230567U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 9356757995305239271U;
            aOrbiterA = RotL64((aOrbiterA * 10945513661439954731U), 43U);
            //
            aIngress = RotL64(aOrbiterG, 14U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + RotL64(aOrbiterB, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 19U)) + aOrbiterE) + RotL64(aNonceWordH, 17U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterG, 27U)) + RotL64(aNonceWordD, 43U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 13U) + aOrbiterB) + RotL64(aOrbiterJ, 11U)) + RotL64(aCarry, 23U)) + aPhaseBWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 36U) + RotL64(aOrbiterE, 37U)) + aOrbiterJ) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterE, 60U)) + aOrbiterB) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 56U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 10U) ^ RotL64(aNonceWordD, 43U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 25352U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27257U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 52U) ^ RotL64(aNonceWordB, 11U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22059U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((aIndex + 26869U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 37U) + RotL64(aCarry, 57U)) + (RotL64(aCross, 24U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterK = ((aWandererI + RotL64(aCross, 23U)) + 10805654776556844351U) + RotL64(aNonceWordD, 47U);
            aOrbiterG = ((((aWandererC + RotL64(aPrevious, 47U)) + RotL64(aCarry, 39U)) + 582794182442795335U) + aPhaseBOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1]) + RotL64(aNonceWordA, 15U);
            aOrbiterE = ((aWandererA + RotL64(aScatter, 39U)) + RotL64(aCarry, 27U)) + 2858343650974681068U;
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 3U)) + RotL64(aCarry, 5U)) + 8189584049022064284U;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 12U)) + 1565100751996962893U) + aPhaseBOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 8062028016947611891U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 8280504280578451745U;
            aOrbiterE = RotL64((aOrbiterE * 5212851648135050483U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 11326869194491655350U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 1671695656567777163U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7511554500524257921U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 2349843105293943452U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 13015545152052004254U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1316662811685429983U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 16703354404749291869U) + RotL64(aNonceWordH, 49U);
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 8713231044374305801U) ^ RotL64(aNonceWordF, 54U);
            aOrbiterG = RotL64((aOrbiterG * 9242480982197688625U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 11118401674497783533U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 14857556493734710364U;
            aOrbiterB = RotL64((aOrbiterB * 3452566050389715195U), 53U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 47U);
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterB, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aPrevious, 37U) + aOrbiterK) + RotL64(aOrbiterG, 3U));
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 11U) + aOrbiterH) + RotL64(aOrbiterE, 30U)) + RotL64(aNonceWordC, 13U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aCross, 29U) + RotL64(aOrbiterG, 39U)) + aOrbiterH) + RotL64(aCarry, 3U)) + aPhaseBWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterB, 13U)) + RotL64(aNonceWordE, 27U));
            aWandererG = aWandererG + (((RotL64(aScatter, 48U) + aOrbiterH) + RotL64(aOrbiterK, 51U)) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (RotL64(aWandererI, 58U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 3U) ^ RotL64(aNonceWordB, 11U)) ^ RotL64(aNonceWordA, 20U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 28535U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((aIndex + 31666U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 51U) ^ RotL64(aNonceWordD, 4U)) ^ RotL64(aNonceWordF, 43U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29970U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31996U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 34U) + RotL64(aCarry, 53U)) ^ (RotL64(aCross, 19U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterG = ((((aWandererK + RotL64(aCross, 5U)) + RotL64(aCarry, 37U)) + 17936518874386450467U) + aPhaseBOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1]) + RotL64(aNonceWordD, 49U);
            aOrbiterC = (((aWandererG + RotL64(aScatter, 47U)) + RotL64(aCarry, 53U)) + 13722737841589910344U) + RotL64(aNonceWordA, 43U);
            aOrbiterD = (aWandererA + RotL64(aIngress, 57U)) + 11774969167948715796U;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 34U)) + RotL64(aCarry, 13U)) + 3640101505680493777U;
            aOrbiterH = ((aWandererH + RotL64(aCross, 13U)) + 1369495382725650822U) + aPhaseBOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 11827310354654653345U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 186037671377175394U;
            aOrbiterD = RotL64((aOrbiterD * 829791264853993897U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 11428829344234627340U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 2275016369870029068U) ^ RotL64(aNonceWordH, 15U);
            aOrbiterC = RotL64((aOrbiterC * 14936799202145280833U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 15471646673734798328U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 12172082573115640145U;
            aOrbiterG = RotL64((aOrbiterG * 9629417882787847753U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 6626736341348283154U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 12220614992483863623U) ^ RotL64(aNonceWordG, 29U);
            aOrbiterJ = RotL64((aOrbiterJ * 8137086205714097487U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 13157102324253760215U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 4143587482368093601U;
            aOrbiterH = RotL64((aOrbiterH * 5060677690991506895U), 43U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 53U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aIngress, 60U) + aOrbiterG) + RotL64(aOrbiterC, 11U)) + RotL64(aNonceWordB, 38U));
            aWandererH = aWandererH + (((RotL64(aCross, 39U) + aOrbiterC) + RotL64(aOrbiterH, 21U)) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 38U)) + aOrbiterJ);
            aWandererK = aWandererK + (((((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 53U)) + aOrbiterG) + RotL64(aCarry, 57U)) + RotL64(aNonceWordE, 61U)) + aPhaseBWandererUpdateSaltF[((aIndex + 8U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 29U)) + aOrbiterD) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererK, 28U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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

void TwistExpander_Cricket_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xD3F0952DED4FBD03ULL + 0xDB594DE925A5E49CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x869D96B6BFF7B3F3ULL + 0x928EE46DC3563214ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x9F0B82A3AC44816BULL + 0xD08EBD4DD948A86FULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x8407FB9BEB862AA1ULL + 0xA53B3A8709ABE3E2ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xB39E8FC91DA7DEB7ULL + 0xCF7F3DAA66E4E313ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xBF119BA2F63B82FFULL + 0xF3CE19D075B6D975ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xD91047B966110D65ULL + 0xC13AC0F788468B97ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x9346427562E9715BULL + 0x98DC10793D61790CULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 23U) ^ RotL64(aNonceWordH, 3U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 7577U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2803U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 3U) ^ RotL64(aNonceWordF, 57U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5614U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneA[((aIndex + 4692U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 13U) ^ RotL64(aIngress, 27U)) + (RotL64(aCarry, 56U) ^ RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterH = (aWandererD + RotL64(aScatter, 58U)) + 16160838483846078448U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 5U)) + 15404960896190227946U;
            aOrbiterK = (aWandererF + RotL64(aCross, 19U)) + 16904160594024977199U;
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 47U)) + RotL64(aCarry, 19U)) + 17790460246821031802U;
            aOrbiterG = (((aWandererA + RotL64(aIngress, 14U)) + RotL64(aCarry, 11U)) + 16395168254086971959U) + RotL64(aNonceWordD, 23U);
            aOrbiterB = (aWandererI + RotL64(aPrevious, 37U)) + 7484373204039901786U;
            aOrbiterI = ((((aWandererC + RotL64(aCross, 27U)) + RotL64(aCarry, 27U)) + 18026814691322913510U) + aPhaseCOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1]) + RotL64(aNonceWordG, 11U);
            aOrbiterJ = (aWandererG + RotL64(aScatter, 23U)) + 15244817793136966450U;
            aOrbiterE = ((aWandererE + RotL64(aCross, 51U)) + 5795491730356335666U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 3163873518027801504U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 2690791759507349172U;
            aOrbiterK = RotL64((aOrbiterK * 16677948635136515083U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 17898067251167087906U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 8028010015006604239U;
            aOrbiterB = RotL64((aOrbiterB * 5601629670521300241U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 7304739457289910555U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 6476837815096530043U;
            aOrbiterJ = RotL64((aOrbiterJ * 16380545138701113267U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 14242499233467960602U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 17305645693017634630U;
            aOrbiterE = RotL64((aOrbiterE * 14442976693206929569U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 9772864059444171908U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 7897200728282156408U) ^ RotL64(aNonceWordE, 19U);
            aOrbiterH = RotL64((aOrbiterH * 816306719390807411U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 4890999319172950996U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 8165132649356094963U) ^ RotL64(aNonceWordF, 46U);
            aOrbiterC = RotL64((aOrbiterC * 17297706071263690189U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 9342923520083533265U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 7213639583505088067U;
            aOrbiterI = RotL64((aOrbiterI * 1349251979649428909U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 4079475132684197272U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 3350998022472827283U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 948841791460066265U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 2479140576609216238U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 7703147534931674972U;
            aOrbiterG = RotL64((aOrbiterG * 11419116495223970801U), 39U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 27U);
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 48U));
            aIngress = aIngress + RotL64(aOrbiterD, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aScatter, 14U) + aOrbiterB) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 39U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterI, 47U)) + aOrbiterE) + RotL64(aNonceWordB, 51U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterI, 28U)) + RotL64(aNonceWordA, 27U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterC, 5U)) + aOrbiterK);
            aWandererA = aWandererA + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 35U)) + aOrbiterJ) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 5U) + aOrbiterI) + RotL64(aOrbiterC, 53U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 47U) + RotL64(aOrbiterH, 23U)) + aOrbiterG);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 22U) + aOrbiterB) + RotL64(aOrbiterH, 39U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 12U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + RotL64(aWandererD, 36U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 53U) ^ RotL64(aNonceWordB, 39U)) ^ RotL64(aNonceWordC, 19U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10228U)) & S_BLOCK1], 28U) ^ RotL64(aOperationLaneD[((aIndex + 8516U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 43U) ^ RotL64(aNonceWordE, 14U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 9781U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 14695U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCross, 19U)) + (RotL64(aPrevious, 54U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterG = ((aWandererA + RotL64(aIngress, 23U)) + RotL64(aCarry, 57U)) + 15920462086654025436U;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 19U)) + RotL64(aCarry, 47U)) + 487844076858004017U;
            aOrbiterE = (((aWandererD + RotL64(aPrevious, 58U)) + RotL64(aCarry, 11U)) + 14502883786442630566U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aCross, 27U)) + 3787107318658233674U;
            aOrbiterK = (aWandererH + RotL64(aScatter, 47U)) + 12548777544693755491U;
            aOrbiterI = (aWandererC + RotL64(aIngress, 43U)) + 4907309444075181683U;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 13U)) + 18342396700266492072U) + RotL64(aNonceWordE, 47U);
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 35U)) + 13503051997624242670U) + RotL64(aNonceWordG, 13U);
            aOrbiterF = ((aWandererK + RotL64(aScatter, 54U)) + 17845742460521374571U) + aPhaseCOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 8640887211877858169U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 5273913123709097537U;
            aOrbiterE = RotL64((aOrbiterE * 1661149444148461791U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 17756844173695563883U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 6713055830729302951U;
            aOrbiterK = RotL64((aOrbiterK * 2832836748513174311U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 5106468334224035972U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 10228769728713526172U;
            aOrbiterJ = RotL64((aOrbiterJ * 9760310686414358435U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 7687649520668883142U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 7757480627354711605U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7222553727737349209U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 10876291698508634557U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 8149278085586014186U) ^ RotL64(aNonceWordF, 29U);
            aOrbiterF = RotL64((aOrbiterF * 8577133863470695381U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 15592893988925610485U) + RotL64(aNonceWordA, 41U);
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 8639028256640537165U;
            aOrbiterG = RotL64((aOrbiterG * 1880655276432963955U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 475660347892196219U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 1903736092401853832U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8486318978769094799U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 12463250192809450953U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 7253918448601703982U;
            aOrbiterI = RotL64((aOrbiterI * 3821034106528009129U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 5171661020093804486U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 11627344933828324146U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5388047063152043277U), 23U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterF, 27U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 50U));
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterE, 27U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterI, 18U)) + RotL64(aNonceWordH, 42U));
            aWandererB = aWandererB + (((RotL64(aScatter, 23U) + aOrbiterD) + RotL64(aOrbiterJ, 47U)) + aPhaseCWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 11U)) + aOrbiterF);
            aWandererG = aWandererG + (((RotL64(aScatter, 12U) + RotL64(aOrbiterJ, 37U)) + aOrbiterF) + RotL64(aCarry, 11U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterH, 41U)) + aOrbiterA) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterJ, 57U)) + aOrbiterE) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 37U) + aOrbiterF) + RotL64(aOrbiterA, 52U)) + RotL64(aNonceWordD, 25U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 30U) + aOrbiterJ) + RotL64(aOrbiterH, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 40U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + RotL64(aWandererJ, 35U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 53U) ^ RotL64(aNonceWordB, 27U)) ^ RotL64(aNonceWordE, 19U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 19763U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 18915U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 24U) ^ RotL64(aNonceWordF, 37U)) ^ RotL64(aNonceWordD, 51U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20504U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((aIndex + 20630U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aIngress, 24U)) + (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterF = (aWandererC + RotL64(aCross, 4U)) + 12029393034357490020U;
            aOrbiterK = ((aWandererD + RotL64(aScatter, 41U)) + RotL64(aCarry, 29U)) + 4526754731580694987U;
            aOrbiterE = (aWandererH + RotL64(aPrevious, 47U)) + 17060419646421271853U;
            aOrbiterB = ((aWandererI + RotL64(aIngress, 57U)) + 4128488893837059683U) + RotL64(aNonceWordA, 57U);
            aOrbiterH = (aWandererK + RotL64(aPrevious, 52U)) + 12706894827547160110U;
            aOrbiterJ = (((aWandererB + RotL64(aIngress, 11U)) + RotL64(aCarry, 57U)) + 12506324593645825056U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aScatter, 23U)) + 12581344490649250025U;
            aOrbiterG = (aWandererA + RotL64(aCross, 19U)) + 14357032418199130132U;
            aOrbiterA = ((((aWandererE + RotL64(aPrevious, 37U)) + RotL64(aCarry, 43U)) + 15341977701796331249U) + aPhaseCOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1]) + RotL64(aNonceWordG, 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 7086602307544733241U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 12398300065276832486U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 18157408831225635333U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 2499745046076601988U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 7249361592814001829U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14597139848072319685U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 3254456186337366437U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 3472973415969046680U;
            aOrbiterB = RotL64((aOrbiterB * 14583566953969168353U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 7905718972111691591U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 15941413652144021522U;
            aOrbiterK = RotL64((aOrbiterK * 3473779492962783565U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 10583964125960308762U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 13659925272340853715U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16708294803316630743U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 9487054537489454887U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 13287757570441887517U) ^ RotL64(aNonceWordE, 41U);
            aOrbiterJ = RotL64((aOrbiterJ * 17351439045329892107U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 15279245465808571942U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 12424999114621745879U) ^ RotL64(aNonceWordH, 15U);
            aOrbiterI = RotL64((aOrbiterI * 2274918760256527137U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 13915392738892970475U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 13797668053788805126U;
            aOrbiterG = RotL64((aOrbiterG * 13752161103680525317U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 14344766585550401077U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 13727554194373146727U;
            aOrbiterA = RotL64((aOrbiterA * 17164450431362670223U), 57U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 4U);
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterF, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterK, 35U)) + aOrbiterE);
            aWandererB = aWandererB + ((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 28U)) + aOrbiterK);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 6U) + aOrbiterA) + RotL64(aOrbiterE, 3U)) + RotL64(aNonceWordB, 59U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 39U)) + aOrbiterG) + aPhaseCWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterE, 51U)) + aOrbiterI);
            aWandererA = aWandererA + ((((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 37U)) + RotL64(aNonceWordF, 42U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterK, 13U)) + aOrbiterH);
            aWandererH = aWandererH + (((RotL64(aPrevious, 56U) + RotL64(aOrbiterB, 43U)) + aOrbiterJ) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterF, 24U)) + aPhaseCWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 60U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 38U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 13U) ^ RotL64(aNonceWordF, 21U)) ^ RotL64(aNonceWordC, 30U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 30955U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30395U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 51U) ^ RotL64(aNonceWordH, 21U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25603U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneD[((aIndex + 27412U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCross, 51U)) ^ (RotL64(aIngress, 22U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 11U)) + RotL64(aCarry, 29U)) + 12311607308490066301U;
            aOrbiterD = ((aWandererF + RotL64(aIngress, 34U)) + 13100864684740679846U) + RotL64(aNonceWordF, 7U);
            aOrbiterB = (((aWandererB + RotL64(aScatter, 47U)) + RotL64(aCarry, 47U)) + 13697304189274329704U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = (aWandererC + RotL64(aCross, 53U)) + 9047976902871216732U;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 19U)) + 2147897579538537888U) + RotL64(aNonceWordC, 37U);
            aOrbiterA = (aWandererG + RotL64(aCross, 6U)) + 2072444829390996142U;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 23U)) + RotL64(aCarry, 11U)) + 2129307836981020908U;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 27U)) + 10663145333751112064U) + aPhaseCOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aCross, 41U)) + 15019844390503785459U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 5460865577557928142U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 15806522559993224197U;
            aOrbiterB = RotL64((aOrbiterB * 8722932687972240099U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 6361113778657833389U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 8306013884615042570U;
            aOrbiterF = RotL64((aOrbiterF * 8234258702656728667U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 4038420580499706912U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 11908091484457158973U;
            aOrbiterG = RotL64((aOrbiterG * 3964111175645156719U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 11133912466611921250U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 2469227904206936928U) ^ RotL64(aNonceWordE, 11U);
            aOrbiterK = RotL64((aOrbiterK * 2704438771198001599U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 13234017916788297295U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 9061117693840451988U;
            aOrbiterC = RotL64((aOrbiterC * 3637440416741459419U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 12013423690843812324U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 14371779015144617412U;
            aOrbiterA = RotL64((aOrbiterA * 3359568073302062667U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 10044883414565441442U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 14334898081890462218U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4878939077928220019U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 13788962593988366125U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterF) ^ 8377887372059713516U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]) ^ RotL64(aNonceWordD, 16U);
            aOrbiterH = RotL64((aOrbiterH * 1925913354197206851U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 4584439257847749371U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 13335592911357756498U;
            aOrbiterD = RotL64((aOrbiterD * 6515028218115896375U), 51U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterC, 26U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 60U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 5U) + aOrbiterF) + RotL64(aOrbiterA, 58U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 24U) + aOrbiterD) + RotL64(aOrbiterK, 29U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 29U) + aOrbiterA) + RotL64(aOrbiterG, 13U)) + RotL64(aNonceWordH, 57U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterD, 53U)) + aOrbiterB) + aPhaseCWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 39U) + aOrbiterA) + RotL64(aOrbiterB, 39U)) + RotL64(aNonceWordA, 59U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterC, 24U)) + aOrbiterH) + RotL64(aCarry, 13U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 18U) + RotL64(aOrbiterA, 3U)) + aOrbiterK);
            aWandererK = aWandererK + (((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterC, 43U)) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterE, 35U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 4U));
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + RotL64(aWandererK, 27U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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

void TwistExpander_Cricket_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x945B017C5669F869ULL + 0xBEB8CEA0F64B6BDDULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xC685C1D64DF4600DULL + 0xF36B5A7BB6CDDC9BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xE9CB59A7ECFFF6FFULL + 0xC30C46A9D9426BA6ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x860274DD97E8C885ULL + 0xCE072433ACE28C7BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA4ACB19F30E104C5ULL + 0xC02DEC4E8DB691B4ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xAECC45A5FFFC0973ULL + 0xCBE80E033EE81EFDULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xD1039B732080FED7ULL + 0xB322A01DC6DE601AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x800D43D7E3608B9FULL + 0xF2F52A01CBAE0A1DULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 3U) ^ RotL64(aNonceWordG, 21U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2143U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3952U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 27U) ^ RotL64(aNonceWordA, 53U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2394U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 558U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 13U) ^ RotL64(aPrevious, 29U)) ^ (RotL64(aCarry, 43U) + RotL64(aIngress, 60U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterI = (aWandererF + RotL64(aScatter, 14U)) + 4739486756133131180U;
            aOrbiterD = (aWandererK + RotL64(aPrevious, 5U)) + 16089707555501328184U;
            aOrbiterE = (aWandererE + RotL64(aCross, 3U)) + 15310047330238536453U;
            aOrbiterJ = (aWandererD + RotL64(aIngress, 53U)) + 7901411596386834955U;
            aOrbiterG = ((aWandererH + RotL64(aCross, 19U)) + RotL64(aCarry, 35U)) + 4357555491060982163U;
            aOrbiterB = (((aWandererI + RotL64(aPrevious, 38U)) + 15667085602825720102U) + aPhaseDOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1]) + RotL64(aNonceWordD, 17U);
            aOrbiterK = (aWandererG + RotL64(aScatter, 27U)) + 8520635334382269253U;
            aOrbiterF = (((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 39U)) + 1772509779231068315U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aPrevious, 11U)) + 15336170957886025677U;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 47U)) + RotL64(aCarry, 23U)) + 8628770833489469980U;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 21U)) + 15469234024247246228U) + RotL64(aNonceWordF, 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 10796430900884288328U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 10660110397012853289U;
            aOrbiterE = RotL64((aOrbiterE * 9140007610912037461U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 11202284258711214794U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 17509491802893182994U;
            aOrbiterB = RotL64((aOrbiterB * 9329107599972703671U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 16212572740740103554U) + RotL64(aNonceWordC, 38U);
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 2190030203761579226U;
            aOrbiterI = RotL64((aOrbiterI * 3101886685668871045U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 12014337082293041909U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 3733531010807001506U;
            aOrbiterJ = RotL64((aOrbiterJ * 5797362244066062299U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 7100994963061975529U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 17837541162838600258U;
            aOrbiterK = RotL64((aOrbiterK * 8745987361678166553U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 3311518938023146951U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 7709505172646831553U;
            aOrbiterA = RotL64((aOrbiterA * 7121143171245765213U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 4979968094554018443U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 16822214821463034107U;
            aOrbiterC = RotL64((aOrbiterC * 8618262120451291765U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 8376124175020587079U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 11084586282092424876U) ^ RotL64(aNonceWordG, 43U);
            aOrbiterD = RotL64((aOrbiterD * 5835632742522563537U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 7816368455027681621U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 10893292019060642422U;
            aOrbiterG = RotL64((aOrbiterG * 3995821210667317677U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 13602875505184178486U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 5425735673005681983U;
            aOrbiterF = RotL64((aOrbiterF * 12667085597129312079U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 5995385043278810987U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 4739486756133131180U;
            aOrbiterH = RotL64((aOrbiterH * 15709273328685013399U), 11U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 60U);
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + RotL64(aOrbiterA, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 46U)) + aOrbiterH) + aPhaseDWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 35U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 11U)) + aOrbiterC);
            aWandererK = aWandererK + (((RotL64(aCross, 21U) + RotL64(aOrbiterB, 29U)) + aOrbiterE) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 52U) + aOrbiterG) + RotL64(aOrbiterD, 27U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterE, 48U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterJ, 43U)) + aOrbiterA);
            aWandererF = aWandererF + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterF, 53U)) + aOrbiterI);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 41U) + aOrbiterC) + RotL64(aOrbiterD, 51U));
            aWandererC = aWandererC + (((RotL64(aIngress, 23U) + aOrbiterJ) + RotL64(aOrbiterB, 37U)) + RotL64(aNonceWordH, 7U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 10U) + aOrbiterA) + RotL64(aOrbiterK, 21U)) + RotL64(aNonceWordE, 57U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 18U));
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + RotL64(aWandererK, 21U);
            aCarry = aCarry + RotL64(aIngress, 56U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 58U) ^ RotL64(aNonceWordG, 47U)) ^ RotL64(aNonceWordH, 21U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 9334U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10494U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 12U) ^ RotL64(aNonceWordF, 51U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5510U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((aIndex + 6411U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 29U)) + (RotL64(aPrevious, 44U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterB = ((aWandererA + RotL64(aCross, 43U)) + 4476099022490972343U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aIngress, 13U)) + 16836423700375760429U;
            aOrbiterD = (aWandererC + RotL64(aScatter, 46U)) + 8850577488928703557U;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 23U)) + 7091631824560042743U) + RotL64(aNonceWordH, 19U);
            aOrbiterF = ((aWandererI + RotL64(aIngress, 3U)) + RotL64(aCarry, 57U)) + 12560498899956759494U;
            aOrbiterG = ((aWandererG + RotL64(aCross, 53U)) + RotL64(aCarry, 39U)) + 7797973377112012161U;
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 5U)) + 6173820673874805794U) + aPhaseDOrbiterAssignSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = (aWandererK + RotL64(aScatter, 28U)) + 10805025132310245348U;
            aOrbiterE = (aWandererH + RotL64(aIngress, 39U)) + 7139216143268029968U;
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 35U)) + RotL64(aCarry, 53U)) + 8241544862261635722U;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 51U)) + 4735527016563596150U) + RotL64(aNonceWordC, 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 5166171126690294033U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 11117641762075368393U;
            aOrbiterD = RotL64((aOrbiterD * 4980156869201219393U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 6312932356458415421U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 1304139291184508668U;
            aOrbiterA = RotL64((aOrbiterA * 90744653170922319U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 10085025354842771067U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 16745854428789531080U) ^ RotL64(aNonceWordE, 41U);
            aOrbiterF = RotL64((aOrbiterF * 1945983905747274355U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 2497187958708890337U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 16069701876646548995U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16606039730973709495U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 17242004368025978091U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterH) ^ 12334315722243232121U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]) ^ RotL64(aNonceWordG, 8U);
            aOrbiterE = RotL64((aOrbiterE * 16528598396696346719U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 8007042082518126895U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 5665686359038811484U;
            aOrbiterB = RotL64((aOrbiterB * 11289316305875751813U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 3913477186958600592U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 16918984318564170343U;
            aOrbiterJ = RotL64((aOrbiterJ * 5128293326494417281U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 10227611546502931418U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 7187623463085447228U;
            aOrbiterG = RotL64((aOrbiterG * 8479839369622163181U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 16655159122037336519U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 9844145011519243346U;
            aOrbiterC = RotL64((aOrbiterC * 16512883184116277583U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 8660130685326542506U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 16192687259641294851U;
            aOrbiterH = RotL64((aOrbiterH * 2882649237163668499U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 15208432734447317310U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 4476099022490972343U;
            aOrbiterK = RotL64((aOrbiterK * 7447168142776253041U), 27U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterA, 3U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 54U));
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + RotL64(aOrbiterB, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterH, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterI, 34U)) + aOrbiterH);
            aWandererK = aWandererK + ((RotL64(aScatter, 53U) + RotL64(aOrbiterJ, 21U)) + aOrbiterB);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 38U) + RotL64(aOrbiterC, 13U)) + aOrbiterI);
            aWandererE = aWandererE + ((RotL64(aCross, 5U) + RotL64(aOrbiterF, 29U)) + aOrbiterH);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterC, 6U)) + aOrbiterD);
            aWandererG = aWandererG + (((RotL64(aScatter, 13U) + RotL64(aOrbiterD, 23U)) + aOrbiterJ) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 34U) + RotL64(aOrbiterJ, 39U)) + aOrbiterK) + RotL64(aNonceWordD, 3U)) + aPhaseDWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aCross, 21U) + aOrbiterA) + RotL64(aOrbiterJ, 47U)) + RotL64(aCarry, 3U)) + RotL64(aNonceWordA, 45U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 41U)) + aOrbiterA) + aPhaseDWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 53U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 48U));
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 14U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 11U) ^ RotL64(aNonceWordH, 52U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 14755U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 12247U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 57U) ^ RotL64(aNonceWordA, 47U)) ^ RotL64(aNonceWordE, 23U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13803U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((aIndex + 12170U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 51U) ^ RotL64(aCarry, 3U)) + (RotL64(aCross, 20U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 52U)) + RotL64(aCarry, 37U)) + 13915875634607599122U;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 39U)) + 1695770381382411673U) + RotL64(aNonceWordG, 41U);
            aOrbiterA = (aWandererA + RotL64(aCross, 47U)) + 3709105579778295511U;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 5U)) + 7673376335333251804U) + aPhaseDOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 23U)) + RotL64(aCarry, 3U)) + 8814147709738503518U;
            aOrbiterE = ((aWandererF + RotL64(aIngress, 3U)) + RotL64(aCarry, 11U)) + 13451412605350381172U;
            aOrbiterH = (aWandererK + RotL64(aCross, 54U)) + 6447870234069609538U;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 35U)) + 13419487997946496825U;
            aOrbiterD = (aWandererB + RotL64(aIngress, 43U)) + 5478309847615220345U;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 37U)) + 3635184969215610049U) + RotL64(aNonceWordD, 22U);
            aOrbiterC = ((aWandererH + RotL64(aCross, 21U)) + 12527903812035294828U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 1684685110885338814U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 12860354576326835090U;
            aOrbiterA = RotL64((aOrbiterA * 12743745087733307255U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 9081823570147481835U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 14369321778210049109U;
            aOrbiterE = RotL64((aOrbiterE * 17865953349448767035U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 11518132079084873250U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 11893535026126957389U;
            aOrbiterB = RotL64((aOrbiterB * 15751374986135615095U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 7084079180579206226U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 2999676609847603277U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14602698397511266403U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 17683445810614029153U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 11576460512964896969U;
            aOrbiterI = RotL64((aOrbiterI * 5243651036457051155U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 13429800604736567949U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 14661785761747367546U;
            aOrbiterJ = RotL64((aOrbiterJ * 4765843989277333421U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 12837164345582888950U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 6222666313184669392U;
            aOrbiterG = RotL64((aOrbiterG * 17402483466567712319U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 5358647039491079457U) + RotL64(aNonceWordC, 51U);
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 12459911673401497180U;
            aOrbiterF = RotL64((aOrbiterF * 13605465035256188065U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 3333017644772803587U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 15501587702102554928U) ^ RotL64(aNonceWordA, 55U);
            aOrbiterH = RotL64((aOrbiterH * 4921693371641768339U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 8492287653837766613U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 3432736785678875404U;
            aOrbiterD = RotL64((aOrbiterD * 7326419883291516513U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 2841486107704281869U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 13915875634607599122U;
            aOrbiterC = RotL64((aOrbiterC * 707861617246345083U), 35U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 18U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 53U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterE, 11U)) + aOrbiterF) + RotL64(aNonceWordE, 61U));
            aWandererK = aWandererK + ((RotL64(aScatter, 21U) + RotL64(aOrbiterA, 53U)) + aOrbiterG);
            aWandererE = aWandererE ^ ((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterE, 23U));
            aWandererF = aWandererF + (((((RotL64(aIngress, 28U) + RotL64(aOrbiterE, 37U)) + aOrbiterG) + RotL64(aCarry, 11U)) + RotL64(aNonceWordF, 59U)) + aPhaseDWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 13U)) + aOrbiterG);
            aWandererH = aWandererH + ((RotL64(aCross, 5U) + aOrbiterK) + RotL64(aOrbiterC, 40U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 53U) + aOrbiterB) + RotL64(aOrbiterJ, 43U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterJ, 47U)) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 56U) + RotL64(aOrbiterH, 5U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 51U) + aOrbiterH) + RotL64(aOrbiterD, 35U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterD, 50U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 34U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + RotL64(aWandererI, 13U);
            aCarry = aCarry + RotL64(aIngress, 36U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 36U) ^ RotL64(aNonceWordA, 11U)) ^ RotL64(aNonceWordH, 19U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 17924U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 19298U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 19U) ^ RotL64(aNonceWordD, 57U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 16700U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16715U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aPrevious, 57U)) + (RotL64(aCross, 19U) ^ RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterI = ((aWandererE + RotL64(aScatter, 14U)) + 3650233661228036955U) + aPhaseDOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aIngress, 43U)) + 11607036400067735729U;
            aOrbiterD = ((aWandererG + RotL64(aCross, 37U)) + RotL64(aCarry, 53U)) + 3899614406903883035U;
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 39U)) + 8159156925629965143U;
            aOrbiterG = (aWandererF + RotL64(aIngress, 51U)) + 7148903913967261270U;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 5U)) + 9161665622287517848U) + RotL64(aNonceWordE, 19U);
            aOrbiterC = (aWandererK + RotL64(aCross, 34U)) + 2981535013474059469U;
            aOrbiterE = (((aWandererA + RotL64(aPrevious, 53U)) + RotL64(aCarry, 23U)) + 15812469008200319549U) + RotL64(aNonceWordC, 25U);
            aOrbiterB = ((aWandererD + RotL64(aScatter, 29U)) + RotL64(aCarry, 43U)) + 14687469489893270300U;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 19U)) + 6025209349511417063U;
            aOrbiterF = ((aWandererH + RotL64(aIngress, 21U)) + 12964750392311112676U) + aPhaseDOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 6572355895765394340U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 3542300121890027981U;
            aOrbiterD = RotL64((aOrbiterD * 11201491178181273935U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 6477175684045398359U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 1081388388827929314U;
            aOrbiterG = RotL64((aOrbiterG * 8752188637514143529U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 13754328481584620771U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 3684673342659575917U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6139923312873039143U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 6542045150319909445U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 5352102692424060388U;
            aOrbiterC = RotL64((aOrbiterC * 7385758355501860261U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 9110100774657340354U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 2813273684436269057U;
            aOrbiterE = RotL64((aOrbiterE * 10468759062594022273U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 5860425751137403755U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 1598622981888978548U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 651816500461718345U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 14710305692377606725U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 16280545617802383463U;
            aOrbiterA = RotL64((aOrbiterA * 12541767206978802063U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 6849565243667718750U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 12152381961996750050U;
            aOrbiterF = RotL64((aOrbiterF * 11185935780063403807U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 1318947876257794796U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterB) ^ 5447559252769140391U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1]) ^ RotL64(aNonceWordH, 37U);
            aOrbiterI = RotL64((aOrbiterI * 13683733413554766327U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 2766869582494246454U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 15757729967222729304U) ^ RotL64(aNonceWordG, 16U);
            aOrbiterK = RotL64((aOrbiterK * 1858683399257513171U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 13063432816787882618U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 3650233661228036955U;
            aOrbiterJ = RotL64((aOrbiterJ * 16230564672533821641U), 35U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 41U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 54U));
            aIngress = aIngress + RotL64(aOrbiterF, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 21U) + aOrbiterC) + RotL64(aOrbiterD, 13U));
            aWandererK = aWandererK + (((RotL64(aScatter, 19U) + aOrbiterD) + RotL64(aOrbiterG, 27U)) + aPhaseDWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((((RotL64(aCross, 53U) + aOrbiterD) + RotL64(aOrbiterB, 43U)) + RotL64(aNonceWordB, 15U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 39U) + aOrbiterH) + RotL64(aOrbiterI, 57U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterB, 47U)) + aOrbiterJ);
            aWandererD = aWandererD + ((RotL64(aIngress, 37U) + aOrbiterE) + RotL64(aOrbiterD, 24U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 23U) + aOrbiterK) + RotL64(aOrbiterB, 39U)) + RotL64(aNonceWordF, 43U));
            aWandererG = aWandererG + (((RotL64(aCross, 43U) + RotL64(aOrbiterH, 3U)) + aOrbiterA) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 6U) + aOrbiterH) + RotL64(aOrbiterC, 19U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 51U) + RotL64(aOrbiterF, 6U)) + aOrbiterH) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 51U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 22U));
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + RotL64(aWandererD, 58U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 43U) ^ RotL64(aNonceWordE, 35U)) ^ RotL64(aNonceWordC, 58U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 23889U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26139U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 43U) ^ RotL64(aNonceWordA, 57U)) ^ RotL64(aNonceWordH, 22U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26750U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22155U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aIngress, 19U)) + (RotL64(aCross, 53U) ^ RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterC = ((aWandererE + RotL64(aScatter, 19U)) + 3339283916456813609U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (aWandererD + RotL64(aPrevious, 51U)) + 11339086426180649584U;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 4U)) + 16819191669329316585U) + RotL64(aNonceWordG, 41U);
            aOrbiterG = (aWandererA + RotL64(aCross, 29U)) + 8361916937762630725U;
            aOrbiterA = (aWandererJ + RotL64(aScatter, 21U)) + 18031328374429899857U;
            aOrbiterD = ((aWandererH + RotL64(aCross, 39U)) + RotL64(aCarry, 53U)) + 18261756894092897276U;
            aOrbiterJ = (aWandererG + RotL64(aIngress, 11U)) + 4250319792907645666U;
            aOrbiterB = (((aWandererI + RotL64(aPrevious, 35U)) + RotL64(aCarry, 13U)) + 1492411503643460886U) + aPhaseDOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aIngress, 23U)) + 17369549067879344180U) + RotL64(aNonceWordD, 25U);
            aOrbiterK = ((aWandererC + RotL64(aScatter, 57U)) + RotL64(aCarry, 35U)) + 7301713524358676722U;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 26U)) + 2985193736033012535U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 14086975808140927408U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 10390516547834639800U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11441293212275890819U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 18205555540941493267U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 16967799565443938873U;
            aOrbiterD = RotL64((aOrbiterD * 3009081009044782443U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 9209505304067579944U) + RotL64(aNonceWordC, 27U);
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 3522631966146762306U) ^ RotL64(aNonceWordF, 45U);
            aOrbiterB = RotL64((aOrbiterB * 3441982898533162599U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 8811497120829041188U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 14707301680850257294U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11383709499376464085U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 10080595991787801029U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 6822892187784299166U;
            aOrbiterC = RotL64((aOrbiterC * 7417016898027778287U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 1981637172055758689U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 16463077485583119324U;
            aOrbiterG = RotL64((aOrbiterG * 2876782050665869121U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 8383837717361569465U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 2788511294985017326U;
            aOrbiterJ = RotL64((aOrbiterJ * 2809163242875130677U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 3529607472855930041U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 8850940802020173766U;
            aOrbiterF = RotL64((aOrbiterF * 7821450253655655943U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 7469160295100147267U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 16973986572163482061U;
            aOrbiterE = RotL64((aOrbiterE * 15660743778376905023U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 12371372942863279718U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 12098525148034303633U;
            aOrbiterH = RotL64((aOrbiterH * 11234127652230231751U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 5138683482859889480U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 3339283916456813609U;
            aOrbiterA = RotL64((aOrbiterA * 10975353228235695455U), 21U);
            //
            aIngress = RotL64(aOrbiterK, 43U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + (RotL64(aOrbiterB, 30U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 34U) + RotL64(aOrbiterB, 21U)) + aOrbiterK);
            aWandererC = aWandererC + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterJ, 56U)) + aOrbiterG);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterI, 29U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aCross, 51U) + RotL64(aOrbiterJ, 43U)) + aOrbiterB) + RotL64(aCarry, 23U)) + RotL64(aNonceWordB, 8U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterH, 19U)) + aOrbiterD);
            aWandererB = aWandererB + ((RotL64(aScatter, 27U) + RotL64(aOrbiterC, 27U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterH, 51U)) + aOrbiterF);
            aWandererH = aWandererH + (((RotL64(aPrevious, 10U) + RotL64(aOrbiterA, 41U)) + aOrbiterB) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterF, 53U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterJ, 4U)) + aOrbiterD) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 37U)) + aOrbiterG) + RotL64(aNonceWordH, 49U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 54U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + RotL64(aWandererB, 26U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 3U) ^ RotL64(aNonceWordC, 13U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 30253U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30718U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 13U) ^ RotL64(aNonceWordA, 53U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31052U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((aIndex + 30845U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aIngress, 11U)) + (RotL64(aPrevious, 39U) + RotL64(aCross, 24U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterD = (aWandererA + RotL64(aScatter, 41U)) + 12669015908335980355U;
            aOrbiterI = (aWandererB + RotL64(aIngress, 51U)) + 5438715179868613192U;
            aOrbiterB = (aWandererF + RotL64(aCross, 53U)) + 13172104448184536460U;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 6U)) + 13421421503244744803U;
            aOrbiterE = (((aWandererH + RotL64(aScatter, 47U)) + 13327113302994856582U) + aPhaseDOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1]) + RotL64(aNonceWordD, 31U);
            aOrbiterF = (aWandererC + RotL64(aPrevious, 43U)) + 4671768205922454413U;
            aOrbiterK = (aWandererE + RotL64(aCross, 21U)) + 5355759962838579929U;
            aOrbiterH = (((aWandererJ + RotL64(aIngress, 30U)) + RotL64(aCarry, 11U)) + 6691720614265406851U) + aPhaseDOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aCross, 35U)) + 7063906424700911378U;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 3U)) + RotL64(aCarry, 43U)) + 17328616394166672263U;
            aOrbiterA = (((aWandererD + RotL64(aScatter, 37U)) + RotL64(aCarry, 53U)) + 1542940602574207068U) + RotL64(aNonceWordG, 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 7203866278803132454U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 993485696233139264U;
            aOrbiterB = RotL64((aOrbiterB * 11609009908810366447U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 15659679028507488331U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 18321361454094675842U;
            aOrbiterE = RotL64((aOrbiterE * 3966860765622641843U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 9633319822696783352U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 3496559332232402963U;
            aOrbiterF = RotL64((aOrbiterF * 7772060229838162977U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 1918349708324205526U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 7701088402761359134U;
            aOrbiterK = RotL64((aOrbiterK * 9649485438465644795U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 6006824348814439686U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 18088375375347012557U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12801082943086128385U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 12816533373478543584U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 17951880253818836433U;
            aOrbiterG = RotL64((aOrbiterG * 8935839101517220201U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 11311632024372748238U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 9891349164779752351U;
            aOrbiterJ = RotL64((aOrbiterJ * 11405973752233193209U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 711130292000437038U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 17818800917771709681U;
            aOrbiterA = RotL64((aOrbiterA * 10567029732245868263U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 10188714200240109442U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterG) ^ 9745615081760948652U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1]) ^ RotL64(aNonceWordH, 15U);
            aOrbiterD = RotL64((aOrbiterD * 9321909462220134035U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 6508703788527163965U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 7536038073603467381U;
            aOrbiterI = RotL64((aOrbiterI * 12015514242701199813U), 23U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterD) + 2793951597846756844U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]) + RotL64(aNonceWordF, 13U);
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 12669015908335980355U;
            aOrbiterC = RotL64((aOrbiterC * 7355285540199760689U), 19U);
            //
            aIngress = RotL64(aOrbiterJ, 13U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 30U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + RotL64(aOrbiterF, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterA, 23U)) + aOrbiterC) + RotL64(aNonceWordA, 4U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 60U) + RotL64(aOrbiterC, 39U)) + aOrbiterI) + RotL64(aCarry, 51U)) + aPhaseDWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterB, 50U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 53U) + aOrbiterA) + RotL64(aOrbiterH, 27U)) + RotL64(aNonceWordE, 21U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterE, 21U));
            aWandererI = aWandererI + (((RotL64(aCross, 57U) + aOrbiterK) + RotL64(aOrbiterC, 53U)) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 11U) + aOrbiterF) + RotL64(aOrbiterK, 29U)) + aPhaseDWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 18U) + aOrbiterD) + RotL64(aOrbiterE, 14U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 23U) + aOrbiterC) + RotL64(aOrbiterB, 47U));
            aWandererK = aWandererK + ((RotL64(aIngress, 41U) + RotL64(aOrbiterF, 19U)) + aOrbiterD);
            aWandererB = aWandererB ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterH, 37U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 12U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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

void TwistExpander_Cricket_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x84F03EBCFFC8D9F9ULL + 0xF58B634252810660ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xAD40F9F038F62903ULL + 0xD01B3B6A7732B1E1ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xD0836C7C6DA2F4E1ULL + 0xBF6970662048E7BEULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xA980DBF25BFE178DULL + 0xEBAEB0B1E2EEFD70ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x92EBF88F4F163767ULL + 0xD7F29499670C0F2AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xCFFA5F84629443D9ULL + 0x863122389299B9B7ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xAC8AA9BC90D28D77ULL + 0xEED89A93E8F277F2ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xE7318C828DB0A963ULL + 0xE889A26072C8FAFDULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 3U) ^ RotL64(aNonceWordH, 19U)) ^ RotL64(aNonceWordA, 51U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 3033U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneC[((aIndex + 3455U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 51U) ^ RotL64(aNonceWordE, 43U)) ^ RotL64(aNonceWordG, 11U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 1723U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 906U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 52U) ^ RotL64(aIngress, 39U)) + (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 21U)) + RotL64(aCarry, 43U)) + 13880995121909552664U;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 26U)) + RotL64(aCarry, 37U)) + 14534942818069300546U;
            aOrbiterK = (aWandererJ + RotL64(aScatter, 53U)) + 17745973100886007133U;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 37U)) + 2249805580771946872U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aIngress, 39U)) + 4460116116396439410U) + RotL64(aNonceWordE, 58U);
            aOrbiterB = (aWandererE + RotL64(aCross, 51U)) + 3378683994078106878U;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 19U)) + 3992996501048809123U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aScatter, 35U)) + RotL64(aCarry, 13U)) + 12057768808864451929U;
            aOrbiterA = (aWandererF + RotL64(aCross, 41U)) + 4115362079047921130U;
            aOrbiterC = (aWandererG + RotL64(aScatter, 3U)) + 15297384955502206698U;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 60U)) + 17623548383481905636U) + RotL64(aNonceWordC, 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 3559213898000162417U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 12311605719074507335U;
            aOrbiterK = RotL64((aOrbiterK * 3982199462062847697U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 14807313864347885885U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 11222085523291581822U;
            aOrbiterB = RotL64((aOrbiterB * 12580941911587215653U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 916681229436292462U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 2441350114032314686U) ^ RotL64(aNonceWordB, 59U);
            aOrbiterE = RotL64((aOrbiterE * 7336079498999018067U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 7361470539894653271U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 12153585147213579808U;
            aOrbiterJ = RotL64((aOrbiterJ * 3040327545467672961U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 13566300726101613579U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 14875254144748509128U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13699179902908972403U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 9268158535644002904U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 14144295981814993491U;
            aOrbiterA = RotL64((aOrbiterA * 12739937231684038161U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 13861225650900541642U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 12620513474052058164U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 18141974182442267181U), 37U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterJ) + 14163773386433257965U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]) + RotL64(aNonceWordG, 47U);
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 5725700029399455855U;
            aOrbiterG = RotL64((aOrbiterG * 10446930901088908809U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 16644838246877860102U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 6611825438224873117U;
            aOrbiterI = RotL64((aOrbiterI * 5336239588054125897U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 9408958265247071226U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 16980073477599191801U;
            aOrbiterD = RotL64((aOrbiterD * 7985839560318985205U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 6513029242607881518U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 13880995121909552664U;
            aOrbiterC = RotL64((aOrbiterC * 17463079726765044639U), 23U);
            //
            aIngress = RotL64(aOrbiterF, 5U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 46U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aScatter, 14U) + aOrbiterD) + RotL64(aOrbiterH, 39U)) + RotL64(aCarry, 19U)) + aPhaseEWandererUpdateSaltD[((aIndex + 12U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 3U)) + aOrbiterB);
            aWandererC = aWandererC + ((RotL64(aCross, 51U) + RotL64(aOrbiterB, 11U)) + aOrbiterC);
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterG, 57U)) + RotL64(aNonceWordF, 5U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 41U) + RotL64(aOrbiterB, 54U)) + aOrbiterK);
            aWandererI = aWandererI ^ (((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterA, 41U)) + RotL64(aNonceWordD, 29U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 39U) + aOrbiterA) + RotL64(aOrbiterC, 51U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 22U) + RotL64(aOrbiterI, 13U)) + aOrbiterG);
            aWandererG = aWandererG + (((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterA, 46U)) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterE, 19U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 43U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 20U));
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + RotL64(aWandererC, 27U);
            aCarry = aCarry + RotL64(aIngress, 30U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 43U) ^ RotL64(aNonceWordH, 35U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 7448U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8809U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 46U) ^ RotL64(aNonceWordE, 21U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7090U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 7045U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aIngress, 27U)) + (RotL64(aPrevious, 60U) + RotL64(aCarry, 13U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterK = (aWandererA + RotL64(aCross, 3U)) + 5160910997561396461U;
            aOrbiterB = (aWandererE + RotL64(aIngress, 51U)) + 14920764751058512062U;
            aOrbiterI = (aWandererG + RotL64(aScatter, 44U)) + 6080952401749660022U;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 23U)) + RotL64(aCarry, 51U)) + 17667234330526298627U;
            aOrbiterE = ((((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 3U)) + 760630072638686756U) + aPhaseEOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1]) + RotL64(aNonceWordF, 36U);
            aOrbiterG = ((aWandererF + RotL64(aScatter, 5U)) + RotL64(aCarry, 27U)) + 3504157162816997476U;
            aOrbiterA = (((aWandererK + RotL64(aPrevious, 35U)) + 9489022223422585882U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1]) + RotL64(aNonceWordC, 27U);
            aOrbiterF = (aWandererB + RotL64(aIngress, 39U)) + 1149898536879968964U;
            aOrbiterH = (aWandererC + RotL64(aCross, 11U)) + 10492284328940025310U;
            aOrbiterC = (aWandererH + RotL64(aIngress, 20U)) + 13213275606286399312U;
            aOrbiterJ = (aWandererD + RotL64(aScatter, 37U)) + 10557118912847180413U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 15618980209023994776U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 5268600749854045564U;
            aOrbiterI = RotL64((aOrbiterI * 3849660559223919613U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 8011552687609649990U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 3148133096349525066U;
            aOrbiterB = RotL64((aOrbiterB * 5245156554959620007U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 12032847944237867285U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 14999005703490824673U;
            aOrbiterE = RotL64((aOrbiterE * 6631584955208646049U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 5426735969392906710U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 3593177531650386729U;
            aOrbiterA = RotL64((aOrbiterA * 12997284886192717043U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 1701444719333347373U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 15928731228196894960U;
            aOrbiterH = RotL64((aOrbiterH * 1919318226904213433U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 5960179456039157036U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 5716434224061596483U;
            aOrbiterK = RotL64((aOrbiterK * 3731976564761202801U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 2136841536293340279U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 12969550408652728526U) ^ RotL64(aNonceWordD, 39U);
            aOrbiterD = RotL64((aOrbiterD * 7612191387451455137U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 3641997570461447114U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 4677572491523684525U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2730358077882211651U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 2741372094325164504U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 4998631511811832690U;
            aOrbiterF = RotL64((aOrbiterF * 10619395395977372695U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 6260464862798783617U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 16489087874167346533U;
            aOrbiterC = RotL64((aOrbiterC * 11278053967185244867U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 7043760915859224327U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 5160910997561396461U) ^ RotL64(aNonceWordH, 49U);
            aOrbiterJ = RotL64((aOrbiterJ * 15260149870590431675U), 39U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterA, 39U);
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterJ, 51U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 14U));
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aScatter, 24U) + RotL64(aOrbiterG, 46U)) + aOrbiterJ) + RotL64(aNonceWordG, 35U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterK, 23U)) + aOrbiterI) + RotL64(aCarry, 35U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 11U) + aOrbiterK) + RotL64(aOrbiterB, 43U)) + RotL64(aNonceWordA, 5U));
            aWandererD = aWandererD + (((RotL64(aCross, 57U) + RotL64(aOrbiterJ, 57U)) + aOrbiterC) + aPhaseEWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 18U) + aOrbiterE) + RotL64(aOrbiterK, 41U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 13U) + aOrbiterB) + RotL64(aOrbiterD, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterI, 13U));
            aWandererH = aWandererH + (((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterH, 39U)) + RotL64(aCarry, 41U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterA, 26U));
            aWandererC = aWandererC + ((RotL64(aScatter, 53U) + RotL64(aOrbiterC, 35U)) + aOrbiterG);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 37U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererB, 10U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 6U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 52U) ^ RotL64(aNonceWordB, 19U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 11681U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 12372U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 19U) ^ RotL64(aNonceWordF, 5U)) ^ RotL64(aNonceWordH, 51U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 14338U)) & S_BLOCK1], 40U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 11531U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 54U) + RotL64(aIngress, 41U)) ^ (RotL64(aPrevious, 29U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterA = ((aWandererK + RotL64(aScatter, 56U)) + RotL64(aCarry, 23U)) + 11039986441331892533U;
            aOrbiterK = (aWandererI + RotL64(aIngress, 53U)) + 6256024955965426119U;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 19U)) + RotL64(aCarry, 29U)) + 9857443189988995666U;
            aOrbiterC = ((aWandererC + RotL64(aCross, 3U)) + 11900944813380998208U) + RotL64(aNonceWordC, 17U);
            aOrbiterI = (aWandererA + RotL64(aScatter, 47U)) + 8422577734978875541U;
            aOrbiterD = ((((aWandererH + RotL64(aIngress, 44U)) + RotL64(aCarry, 53U)) + 3100835100713928724U) + aPhaseEOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1]) + RotL64(aNonceWordH, 25U);
            aOrbiterB = (aWandererB + RotL64(aCross, 21U)) + 11871553509810206993U;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 13U)) + 17614749493763417027U;
            aOrbiterF = (aWandererD + RotL64(aCross, 23U)) + 3638372131856199916U;
            aOrbiterE = (aWandererE + RotL64(aIngress, 39U)) + 6582275259281025770U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 29U)) + 17016882418498941958U) + aPhaseEOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 1747214688658984715U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 9356088987044015278U;
            aOrbiterH = RotL64((aOrbiterH * 16221733545319753695U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 4056238112133473456U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 16013150119949532998U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12913648646318115315U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 16076621211111834889U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 9940824359571581765U;
            aOrbiterK = RotL64((aOrbiterK * 11624767861336495331U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 15624084004784515753U) + RotL64(aNonceWordA, 34U);
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 7630989544834680335U;
            aOrbiterI = RotL64((aOrbiterI * 12261063237156822067U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 18003586430673313786U) + RotL64(aNonceWordG, 49U);
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 1654118743290334161U;
            aOrbiterG = RotL64((aOrbiterG * 1153250137357176071U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 3254189676528343910U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 15629083361573065165U;
            aOrbiterE = RotL64((aOrbiterE * 17024833368570949107U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 10056859810555674806U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 15976683222786846254U;
            aOrbiterA = RotL64((aOrbiterA * 2801754232182942635U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 11872378594829637933U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 7633773773528713489U;
            aOrbiterC = RotL64((aOrbiterC * 8218288492011593353U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 16305188578382203720U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 13293036594949754170U;
            aOrbiterB = RotL64((aOrbiterB * 1300645662609848183U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 15185013801659166674U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 11562899709899198100U;
            aOrbiterF = RotL64((aOrbiterF * 9115495024409604629U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 1525205566739385260U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 11039986441331892533U;
            aOrbiterJ = RotL64((aOrbiterJ * 9802284050237622047U), 27U);
            //
            aIngress = RotL64(aOrbiterA, 35U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 44U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterK, 23U)) + aOrbiterC) + RotL64(aCarry, 21U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterH, 21U)) + aOrbiterG);
            aWandererI = aWandererI + (((RotL64(aIngress, 6U) + aOrbiterH) + RotL64(aOrbiterE, 35U)) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 11U) + aOrbiterJ) + RotL64(aOrbiterB, 47U)) + aPhaseEWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 27U)) + aOrbiterA);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterH, 10U));
            aWandererH = aWandererH + (((RotL64(aIngress, 29U) + RotL64(aOrbiterK, 41U)) + aOrbiterB) + RotL64(aNonceWordD, 19U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 23U) + aOrbiterC) + RotL64(aOrbiterB, 57U)) + RotL64(aNonceWordF, 9U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 39U) + aOrbiterI) + RotL64(aOrbiterF, 5U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterK, 51U));
            aWandererG = aWandererG + ((RotL64(aScatter, 46U) + aOrbiterJ) + RotL64(aOrbiterG, 18U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 58U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 36U) ^ RotL64(aNonceWordA, 11U)) ^ RotL64(aNonceWordC, 3U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 18374U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 19915U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 41U) ^ RotL64(aNonceWordG, 4U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18391U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 18081U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 60U) + RotL64(aPrevious, 13U)) ^ (RotL64(aIngress, 47U) ^ RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterF = (aWandererK + RotL64(aScatter, 60U)) + 7790166497945719700U;
            aOrbiterC = (((aWandererE + RotL64(aPrevious, 27U)) + 7136208896846119188U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1]) + RotL64(aNonceWordA, 25U);
            aOrbiterB = ((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 35U)) + 12123156943355100886U;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 37U)) + RotL64(aCarry, 13U)) + 5095546037880875199U;
            aOrbiterE = (aWandererH + RotL64(aPrevious, 43U)) + 17642705393916765992U;
            aOrbiterK = (((aWandererJ + RotL64(aCross, 39U)) + 9918479837334416990U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1]) + RotL64(aNonceWordB, 58U);
            aOrbiterJ = (aWandererG + RotL64(aScatter, 29U)) + 4890009823843176466U;
            aOrbiterG = (aWandererA + RotL64(aIngress, 19U)) + 17652590786213674124U;
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 11U)) + RotL64(aCarry, 47U)) + 870002527644696135U;
            aOrbiterH = (aWandererF + RotL64(aCross, 54U)) + 12545429703552643682U;
            aOrbiterI = (aWandererD + RotL64(aIngress, 41U)) + 5310272867406182581U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 3264719049050179440U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 1967241238180278937U;
            aOrbiterB = RotL64((aOrbiterB * 13004319774269457957U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 773883832927040736U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 12766817190261232485U;
            aOrbiterE = RotL64((aOrbiterE * 7448864556802318431U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 260069382395598265U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 15462103891287350123U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5029268763635635753U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 4072032867513289827U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 17153061419083897076U;
            aOrbiterJ = RotL64((aOrbiterJ * 11934532169271718913U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 6207264270332656966U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 18048064697837314947U;
            aOrbiterG = RotL64((aOrbiterG * 13632594619404208489U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 14484617445340272026U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 16160443600497652026U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1988599349457831597U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 5873314228291583482U) + RotL64(aNonceWordH, 3U);
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 16418290052752166515U;
            aOrbiterH = RotL64((aOrbiterH * 18270363452003213317U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 9158414409987627714U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 8205937960146492168U;
            aOrbiterI = RotL64((aOrbiterI * 14008398661393344261U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 16386126219854809263U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 12418021156683187869U;
            aOrbiterF = RotL64((aOrbiterF * 13897930566207284517U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 5427232681451476584U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 18237670074497382745U;
            aOrbiterC = RotL64((aOrbiterC * 15528665160297906195U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 8330262458028468513U) + RotL64(aNonceWordE, 35U);
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 7790166497945719700U;
            aOrbiterA = RotL64((aOrbiterA * 6001280767763971107U), 27U);
            //
            aIngress = RotL64(aOrbiterB, 51U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + (RotL64(aOrbiterE, 18U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 39U) + aOrbiterK) + RotL64(aOrbiterE, 46U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 52U) + aOrbiterJ) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 23U) + aOrbiterB) + RotL64(aOrbiterH, 11U));
            aWandererB = aWandererB + (((RotL64(aScatter, 21U) + aOrbiterF) + RotL64(aOrbiterD, 41U)) + RotL64(aNonceWordF, 61U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 30U)) + aOrbiterK);
            aWandererD = aWandererD + ((RotL64(aIngress, 50U) + aOrbiterH) + RotL64(aOrbiterJ, 51U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterB, 19U)) + aOrbiterD) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 21U)) + aOrbiterC) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterH, 23U)) + aOrbiterI);
            aWandererA = aWandererA + ((RotL64(aScatter, 41U) + aOrbiterG) + RotL64(aOrbiterB, 13U));
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 27U) + RotL64(aOrbiterK, 35U)) + aOrbiterC) + RotL64(aNonceWordD, 47U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 22U));
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + RotL64(aWandererF, 44U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 29U) ^ RotL64(aNonceWordG, 11U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 25474U)) & S_BLOCK1], 46U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24790U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 23U) ^ RotL64(aNonceWordB, 53U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 22609U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23332U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCross, 51U)) + (RotL64(aCarry, 6U) + RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterH = (aWandererB + RotL64(aScatter, 21U)) + 9914837590440975587U;
            aOrbiterA = (aWandererK + RotL64(aIngress, 57U)) + 6706125076401958051U;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 60U)) + 16570817772679258409U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aCross, 13U)) + RotL64(aCarry, 41U)) + 6843705658115186948U;
            aOrbiterG = (aWandererD + RotL64(aIngress, 39U)) + 16099930446791572351U;
            aOrbiterE = (aWandererE + RotL64(aScatter, 51U)) + 5420550009556030459U;
            aOrbiterK = (aWandererG + RotL64(aCross, 27U)) + 5729549069420177477U;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 43U)) + RotL64(aCarry, 53U)) + 15590601126188675834U;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 46U)) + RotL64(aCarry, 27U)) + 13044027390998620029U;
            aOrbiterD = (((aWandererH + RotL64(aCross, 5U)) + 11068338135659636772U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1]) + RotL64(aNonceWordF, 19U);
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 19U)) + 6584988841809544332U) + RotL64(aNonceWordC, 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 8516813219883915404U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 10647314042912492785U;
            aOrbiterC = RotL64((aOrbiterC * 15559481057047148785U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 201691689889605304U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 15512161798401184003U;
            aOrbiterE = RotL64((aOrbiterE * 11473219183982564709U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 3883760518944464145U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 13861805129175491145U;
            aOrbiterJ = RotL64((aOrbiterJ * 17194438894492581181U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 12019138626550801486U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 13030350224959652248U;
            aOrbiterD = RotL64((aOrbiterD * 11724200983306280107U), 57U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterJ) + 2643807255422544248U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]) + RotL64(aNonceWordA, 3U);
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 4127143302485631794U;
            aOrbiterH = RotL64((aOrbiterH * 5441038881111578487U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 14602951930809633069U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 4555737199162278494U;
            aOrbiterB = RotL64((aOrbiterB * 12415825635220991865U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 6343143902997169834U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 10404783711336491985U;
            aOrbiterK = RotL64((aOrbiterK * 6235474458879439079U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 7406959231434835393U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 6684368109277850196U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8760360417572331159U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 4835889355927954728U) + RotL64(aNonceWordE, 44U);
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 7917682889852676712U;
            aOrbiterI = RotL64((aOrbiterI * 9045350756570117327U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 10268055422944417055U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 5563744562922937643U;
            aOrbiterA = RotL64((aOrbiterA * 12442484191329795173U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 17244672945880141679U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 9914837590440975587U;
            aOrbiterG = RotL64((aOrbiterG * 12269340309792850489U), 29U);
            //
            aIngress = RotL64(aOrbiterD, 37U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterE, 4U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + RotL64(aOrbiterC, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 37U) + aOrbiterI) + RotL64(aOrbiterE, 53U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 57U) + RotL64(aOrbiterA, 56U)) + aOrbiterF);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 13U)) + aOrbiterK) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 39U) + RotL64(aOrbiterJ, 3U)) + aOrbiterI) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 34U) + aOrbiterD) + RotL64(aOrbiterF, 21U));
            aWandererI = aWandererI + ((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterG, 41U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 19U)) + aOrbiterJ);
            aWandererH = aWandererH + ((RotL64(aCross, 27U) + RotL64(aOrbiterB, 28U)) + aOrbiterC);
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 53U) + aOrbiterC) + RotL64(aOrbiterE, 5U)) + RotL64(aNonceWordH, 29U)) + aPhaseEWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aScatter, 44U) + RotL64(aOrbiterA, 39U)) + aOrbiterK) + RotL64(aCarry, 23U)) + RotL64(aNonceWordB, 21U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterH, 51U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 40U));
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 38U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 27U) ^ RotL64(aNonceWordB, 19U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 31526U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28157U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 39U) ^ RotL64(aNonceWordA, 3U)) ^ RotL64(aNonceWordC, 47U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31584U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29172U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 13U) ^ RotL64(aCross, 29U)) + (RotL64(aIngress, 41U) + RotL64(aCarry, 58U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterJ = (aWandererG + RotL64(aIngress, 56U)) + 8604208734152026945U;
            aOrbiterF = (((aWandererB + RotL64(aCross, 47U)) + RotL64(aCarry, 29U)) + 1374329953253889829U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aPrevious, 41U)) + 5779278910548228339U;
            aOrbiterI = (aWandererH + RotL64(aScatter, 19U)) + 17670451230882805140U;
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 21U)) + 8193848740764866860U) + RotL64(aNonceWordH, 57U);
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 5U)) + 15801168428145650104U) + aPhaseEOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aWandererD + RotL64(aCross, 29U)) + 2584718176087499066U;
            aOrbiterC = (aWandererI + RotL64(aIngress, 11U)) + 14950366247822737997U;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 54U)) + RotL64(aCarry, 57U)) + 9779293225265670135U;
            aOrbiterG = (aWandererA + RotL64(aCross, 43U)) + 8688968319288372383U;
            aOrbiterB = (((aWandererK + RotL64(aScatter, 35U)) + RotL64(aCarry, 21U)) + 13665723186950342601U) + RotL64(aNonceWordA, 56U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 9395428688359973510U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 2152719218018108418U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15271961483518392671U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 1350324137411377992U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 8729317951386057921U;
            aOrbiterK = RotL64((aOrbiterK * 6008790836417785083U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 6317310451893678411U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 10175620379041384281U;
            aOrbiterA = RotL64((aOrbiterA * 14079679617394330781U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 1203082119358827708U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 523869107818193101U;
            aOrbiterD = RotL64((aOrbiterD * 4629501113595689157U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 4028324959540432983U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 15447631947468213912U;
            aOrbiterC = RotL64((aOrbiterC * 6037306615787729185U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 14225888694733041031U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 11925000696281947629U;
            aOrbiterH = RotL64((aOrbiterH * 4337022940520411253U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 15015531024930608745U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 16752579225076943550U;
            aOrbiterG = RotL64((aOrbiterG * 15551083683579981439U), 3U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterH) + 2432733494869267901U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]) + RotL64(aNonceWordG, 3U);
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 10103430321388601485U;
            aOrbiterB = RotL64((aOrbiterB * 18372919379972432569U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 15943360147468638325U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterH) ^ 9782703760233558733U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1]) ^ RotL64(aNonceWordE, 13U);
            aOrbiterJ = RotL64((aOrbiterJ * 685056980418243879U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 18345087852012669037U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 8897505040792027675U;
            aOrbiterF = RotL64((aOrbiterF * 14333687539092412967U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 7402581293947129667U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 8604208734152026945U;
            aOrbiterI = RotL64((aOrbiterI * 9965525485538037673U), 57U);
            //
            aIngress = RotL64(aOrbiterF, 27U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + (RotL64(aOrbiterE, 12U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 54U) + RotL64(aOrbiterB, 21U)) + aOrbiterE) + RotL64(aNonceWordF, 9U));
            aWandererD = aWandererD + ((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 58U)) + aOrbiterK);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterC, 39U)) + RotL64(aNonceWordB, 29U));
            aWandererE = aWandererE + ((((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterG, 53U)) + RotL64(aCarry, 19U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 39U) + aOrbiterJ) + RotL64(aOrbiterA, 35U));
            aWandererH = aWandererH + (((RotL64(aIngress, 11U) + RotL64(aOrbiterA, 3U)) + aOrbiterI) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterG, 19U)) + aOrbiterF) + aPhaseEWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 21U) + RotL64(aOrbiterB, 37U)) + aOrbiterI);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterH, 11U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 18U) + RotL64(aOrbiterG, 44U)) + aOrbiterI);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 29U) + aOrbiterD) + RotL64(aOrbiterJ, 41U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 50U));
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 30U);
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

void TwistExpander_Cricket_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xD5289D8D846D5127ULL + 0xDB549DB70C2AFB47ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x89E46A4E6DE70355ULL + 0xA43A8F8E9561FDF5ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xA55BE0474B8FDC6FULL + 0xE4814E7D2E20CA49ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x87A16BB6A80B2B99ULL + 0x9496F8A7CAB21B25ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xC79A6E5D76C1E1C9ULL + 0xAF2D080D359C272EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x83D50957BAF54DDFULL + 0x972940D5AE1EFA3FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x8D3E06C45909C169ULL + 0xC3AB15FA1C116917ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xD0ADE34FC775A06BULL + 0x883E4B8C8F360CD2ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 37U) ^ RotL64(aNonceWordH, 53U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 554U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneC[((aIndex + 5207U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 13U) ^ RotL64(aNonceWordF, 5U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 1015U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 3110U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 50U) ^ RotL64(aCross, 23U)) + (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = ((aWandererE + RotL64(aCross, 13U)) + RotL64(aCarry, 47U)) + 9023059520606551446U;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 43U)) + 662441755115638133U) + aPhaseFOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aIngress, 50U)) + 16957253361196144712U;
            aOrbiterD = (aWandererJ + RotL64(aScatter, 41U)) + 7840955025765308605U;
            aOrbiterI = (aWandererG + RotL64(aCross, 5U)) + 346855809270395799U;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 19U)) + 16099139781586668343U) + aPhaseFOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = (aWandererI + RotL64(aPrevious, 53U)) + 3706457327118322098U;
            aOrbiterG = (aWandererD + RotL64(aScatter, 57U)) + 12166825885547622870U;
            aOrbiterC = (((aWandererA + RotL64(aPrevious, 47U)) + RotL64(aCarry, 5U)) + 7792658665720344200U) + RotL64(aNonceWordD, 13U);
            aOrbiterA = (aWandererH + RotL64(aCross, 36U)) + 7128477606152986326U;
            aOrbiterE = (((aWandererB + RotL64(aScatter, 23U)) + RotL64(aCarry, 51U)) + 11116533962780290084U) + RotL64(aNonceWordA, 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 10443889548568288532U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 4402387036946561017U;
            aOrbiterB = RotL64((aOrbiterB * 9032964741841833277U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 13002706161178447654U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 13929727277530310708U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7005639090871200285U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 10949073760696935106U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 15405923432006783533U;
            aOrbiterK = RotL64((aOrbiterK * 17989565878445202495U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 18096057968822208905U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 3032155040484574973U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 448597307502544605U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 17462076466907467134U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 15471015427013701406U;
            aOrbiterH = RotL64((aOrbiterH * 6113474000571976139U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 3549031751266594344U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 14243218483842508113U;
            aOrbiterC = RotL64((aOrbiterC * 9041601306479302047U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 5803147589312920032U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 5549470512227427855U) ^ RotL64(aNonceWordB, 27U);
            aOrbiterE = RotL64((aOrbiterE * 12592362489263862879U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 10076661824293832189U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 3196799148974716550U) ^ RotL64(aNonceWordC, 8U);
            aOrbiterF = RotL64((aOrbiterF * 8183276968961467775U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 5245559903456662243U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 5907555542861339984U;
            aOrbiterI = RotL64((aOrbiterI * 10224549416454347583U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 12670710096595941569U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 655047039452620836U;
            aOrbiterG = RotL64((aOrbiterG * 9717552134857988153U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 2654837870443908572U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 9023059520606551446U;
            aOrbiterA = RotL64((aOrbiterA * 170905364378771841U), 29U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 58U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 56U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterD, 23U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 50U) + aOrbiterA) + RotL64(aOrbiterB, 37U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterJ, 5U)) + RotL64(aNonceWordE, 31U));
            aWandererA = aWandererA + ((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 12U)) + aOrbiterB);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterK, 29U)) + aPhaseFWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 53U) + aOrbiterF) + RotL64(aOrbiterK, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 23U) + aOrbiterC) + RotL64(aOrbiterK, 3U));
            aWandererD = aWandererD + (((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 18U)) + aOrbiterJ) + RotL64(aCarry, 35U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterI, 51U)) + aOrbiterG);
            aWandererB = aWandererB + ((((RotL64(aIngress, 36U) + RotL64(aOrbiterK, 43U)) + aOrbiterA) + RotL64(aCarry, 29U)) + RotL64(aNonceWordG, 25U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 11U) + aOrbiterK) + RotL64(aOrbiterH, 53U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (RotL64(aWandererD, 30U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 53U);
            aCarry = aCarry + RotL64(aIngress, 46U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 43U) ^ RotL64(aNonceWordF, 4U)) ^ RotL64(aNonceWordG, 13U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8201U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 7737U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 27U) ^ RotL64(aNonceWordE, 19U)) ^ RotL64(aNonceWordD, 3U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 10244U)) & S_BLOCK1], 46U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 9859U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCross, 24U)) + (RotL64(aPrevious, 37U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = (aWandererC + RotL64(aScatter, 5U)) + 12122689833405846292U;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 35U)) + 9640400270962766788U) + RotL64(aNonceWordE, 41U);
            aOrbiterF = (aWandererF + RotL64(aCross, 50U)) + 9141937998266739071U;
            aOrbiterC = (aWandererH + RotL64(aIngress, 47U)) + 12899395770434090537U;
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 37U)) + 13457918115408031842U;
            aOrbiterE = (aWandererD + RotL64(aCross, 29U)) + 15134784483576000943U;
            aOrbiterA = (((aWandererE + RotL64(aScatter, 41U)) + 12540961268790055438U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1]) + RotL64(aNonceWordG, 25U);
            aOrbiterD = ((aWandererA + RotL64(aIngress, 53U)) + 6306886773092764230U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 14U)) + RotL64(aCarry, 39U)) + 13573343491337243121U;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 43U)) + RotL64(aCarry, 13U)) + 8545588657348974413U;
            aOrbiterG = ((aWandererK + RotL64(aCross, 27U)) + RotL64(aCarry, 47U)) + 10891410570357275120U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 2877137119767060151U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 9178097682386595144U) ^ RotL64(aNonceWordH, 59U);
            aOrbiterF = RotL64((aOrbiterF * 3524486002084427513U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 15528007881855616978U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 11368419529245281435U) ^ RotL64(aNonceWordF, 57U);
            aOrbiterJ = RotL64((aOrbiterJ * 12433207037378339309U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 5932738914934356645U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 5551842263864055419U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16093776759971522681U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 3824433359595690603U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 17184628855571662441U;
            aOrbiterA = RotL64((aOrbiterA * 691208053136187317U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 8724462245014132623U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 7481349499528092352U;
            aOrbiterB = RotL64((aOrbiterB * 8212182934509617583U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 6908362960248294718U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 5354057969992655314U;
            aOrbiterH = RotL64((aOrbiterH * 16586084885820679343U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 11138301629323903147U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 14164180536320940750U;
            aOrbiterC = RotL64((aOrbiterC * 9099767681053390287U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 709942920176922902U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 17128241237359414945U;
            aOrbiterE = RotL64((aOrbiterE * 14063385518459963529U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 6760410778228957309U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 15333948259759012363U;
            aOrbiterD = RotL64((aOrbiterD * 3685416414008280787U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 6929136132517755104U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 13833415487953533365U;
            aOrbiterI = RotL64((aOrbiterI * 14860437994758579635U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 16143046377679975216U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 12122689833405846292U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 227699085983424155U), 51U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 13U);
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterC, 48U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterH, 3U)) + aOrbiterK) + aPhaseFWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterA, 39U)) + aOrbiterC);
            aWandererF = aWandererF + (((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterI, 60U)) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 56U) + aOrbiterF) + RotL64(aOrbiterB, 27U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 51U) + aOrbiterF) + RotL64(aOrbiterJ, 21U)) + RotL64(aCarry, 3U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 3U) + aOrbiterD) + RotL64(aOrbiterH, 19U)) + RotL64(aNonceWordB, 27U));
            aWandererD = aWandererD + (((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterK, 11U)) + RotL64(aNonceWordA, 28U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 36U) + aOrbiterI) + RotL64(aOrbiterJ, 41U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 21U) + aOrbiterF) + RotL64(aOrbiterG, 13U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterG, 57U));
            aWandererH = aWandererH + ((RotL64(aIngress, 41U) + aOrbiterE) + RotL64(aOrbiterK, 50U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 60U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + RotL64(aWandererB, 37U);
            aCarry = aCarry + RotL64(aIngress, 26U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 35U) ^ RotL64(aNonceWordB, 54U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 16065U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13612U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 3U) ^ RotL64(aNonceWordA, 13U)) ^ RotL64(aNonceWordC, 39U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 11483U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneC[((aIndex + 15806U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 24U) + RotL64(aCarry, 37U)) + (RotL64(aCross, 57U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = (aWandererI + RotL64(aCross, 35U)) + 7825479804710770560U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 18U)) + RotL64(aCarry, 41U)) + 5298124167101358123U;
            aOrbiterF = (aWandererA + RotL64(aIngress, 51U)) + 17774541024369233726U;
            aOrbiterJ = (aWandererD + RotL64(aScatter, 39U)) + 7679371833537454082U;
            aOrbiterK = (aWandererK + RotL64(aPrevious, 29U)) + 5385914900748772224U;
            aOrbiterD = (aWandererB + RotL64(aCross, 43U)) + 3879781930908486531U;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 11U)) + RotL64(aCarry, 51U)) + 659110346638873236U;
            aOrbiterI = (((aWandererE + RotL64(aIngress, 41U)) + 10749021728538539749U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1]) + RotL64(aNonceWordE, 9U);
            aOrbiterA = (aWandererC + RotL64(aPrevious, 13U)) + 3631252455767429457U;
            aOrbiterE = ((aWandererF + RotL64(aIngress, 47U)) + 2271978810960685021U) + aPhaseFOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = (((aWandererJ + RotL64(aCross, 22U)) + RotL64(aCarry, 21U)) + 5963558780692551176U) + RotL64(aNonceWordF, 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 974909966119198104U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 9296998242911152296U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2613629915877957661U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 2245318466901521959U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 13391076374843288568U;
            aOrbiterD = RotL64((aOrbiterD * 18094558036982107419U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 6184487746594236737U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 1563385912137291418U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4805455299959232321U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 1744840092006498629U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 2100927276837188416U;
            aOrbiterK = RotL64((aOrbiterK * 3541788262067077997U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 9998911862807246338U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 12239948725635220096U;
            aOrbiterI = RotL64((aOrbiterI * 7098620484129489129U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 3307447094994950246U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 12746613971448298932U;
            aOrbiterE = RotL64((aOrbiterE * 9463975886346934681U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 11577488293733790649U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 191108997585598809U) ^ RotL64(aNonceWordH, 31U);
            aOrbiterG = RotL64((aOrbiterG * 9574978681405356871U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 18096145693841273722U) + RotL64(aNonceWordG, 45U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 10026281133603934071U;
            aOrbiterJ = RotL64((aOrbiterJ * 17261343107314203471U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 2346682418062064668U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 2996178204018644206U;
            aOrbiterB = RotL64((aOrbiterB * 2552965800703390909U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 15085425896818988223U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 1589593231782852588U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1535556765195388675U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 17170695588248383518U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 7825479804710770560U;
            aOrbiterH = RotL64((aOrbiterH * 7434218282170150533U), 35U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterD, 23U);
            aIngress = aIngress + (RotL64(aOrbiterB, 46U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + (RotL64(aOrbiterE, 37U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aScatter, 24U) + RotL64(aOrbiterH, 13U)) + aOrbiterA);
            aWandererK = aWandererK ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterK, 47U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterF, 54U)) + aOrbiterG) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterJ, 43U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 11U) + aOrbiterI) + RotL64(aOrbiterE, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterF, 35U)) + aOrbiterJ);
            aWandererH = aWandererH + (((RotL64(aScatter, 13U) + aOrbiterK) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterI, 23U)) + aOrbiterK);
            aWandererA = aWandererA + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 20U)) + aOrbiterB) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterH, 39U)) + aOrbiterE) + RotL64(aNonceWordD, 26U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 60U) + aOrbiterG) + RotL64(aOrbiterD, 5U)) + RotL64(aNonceWordB, 53U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 24U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 6U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 43U) ^ RotL64(aNonceWordD, 14U)) ^ RotL64(aNonceWordA, 27U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 17842U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((aIndex + 20883U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 39U) ^ RotL64(aNonceWordH, 27U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17309U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 18227U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 38U) + RotL64(aPrevious, 11U)) ^ (RotL64(aCarry, 51U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = (aWandererD + RotL64(aCross, 29U)) + 14249093584376402677U;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 51U)) + 8756965951816492264U) + aPhaseFOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aWandererG + RotL64(aScatter, 43U)) + 11221139480258176330U;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 48U)) + RotL64(aCarry, 5U)) + 17218894445564194851U;
            aOrbiterE = (aWandererA + RotL64(aPrevious, 19U)) + 8064642692524949490U;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 21U)) + 5822093203710704646U;
            aOrbiterI = ((aWandererH + RotL64(aCross, 35U)) + RotL64(aCarry, 51U)) + 3217799620158102238U;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 53U)) + RotL64(aCarry, 41U)) + 2613757677892120843U;
            aOrbiterK = (aWandererI + RotL64(aPrevious, 10U)) + 13647481499551657237U;
            aOrbiterB = ((aWandererF + RotL64(aIngress, 41U)) + 3545714196663685016U) + RotL64(aNonceWordB, 45U);
            aOrbiterF = (((aWandererJ + RotL64(aCross, 3U)) + 9735422670576621521U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1]) + RotL64(aNonceWordC, 9U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 3911046580637583767U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 9315984027042049203U;
            aOrbiterG = RotL64((aOrbiterG * 12568550776487242469U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 8926367674641729058U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterD) ^ 11035347490524961446U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]) ^ RotL64(aNonceWordF, 29U);
            aOrbiterE = RotL64((aOrbiterE * 10948288997163592463U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 10748158733051120339U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 2467801787989056455U) ^ RotL64(aNonceWordE, 41U);
            aOrbiterJ = RotL64((aOrbiterJ * 12621934274702358977U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 9244415080474351390U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 8517784887959492079U;
            aOrbiterI = RotL64((aOrbiterI * 17022899813765884147U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 8409307332803038455U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 11043806021873232950U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8294888329708842989U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 17512395828450251457U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 16849067939795823992U;
            aOrbiterK = RotL64((aOrbiterK * 9361991804481514337U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 17541946638063238056U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 11430501673960586718U;
            aOrbiterB = RotL64((aOrbiterB * 15074409630605450091U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 78307505705383302U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 4834528975263832983U;
            aOrbiterF = RotL64((aOrbiterF * 17245673681686752861U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 9647985402149698269U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 6610247710757518931U;
            aOrbiterH = RotL64((aOrbiterH * 8672486173272686859U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 2706696306041774372U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 9519896513600816252U;
            aOrbiterD = RotL64((aOrbiterD * 7468605169665549731U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 14647351223431646222U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 14249093584376402677U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8296105266618697281U), 57U);
            //
            aIngress = RotL64(aOrbiterD, 23U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterA, 39U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 34U) + RotL64(aOrbiterB, 51U)) + aOrbiterD);
            aWandererH = aWandererH + (((RotL64(aCross, 19U) + RotL64(aOrbiterK, 23U)) + aOrbiterC) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 39U) + aOrbiterE) + RotL64(aOrbiterH, 39U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterF, 37U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterH, 48U)) + aOrbiterI);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 27U) + aOrbiterK) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 27U)) + aPhaseFWandererUpdateSaltC[((aIndex + 12U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterB, 53U)) + RotL64(aNonceWordG, 21U));
            aWandererA = aWandererA + (((RotL64(aIngress, 51U) + aOrbiterH) + RotL64(aOrbiterG, 21U)) + aPhaseFWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 30U) + RotL64(aOrbiterH, 46U)) + aOrbiterF) + RotL64(aNonceWordD, 6U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterG, 41U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 41U) + aOrbiterC) + RotL64(aOrbiterI, 43U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 12U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + RotL64(aWandererD, 18U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 13U) ^ RotL64(aNonceWordA, 51U)) ^ RotL64(aNonceWordH, 39U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24172U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27236U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 21U) ^ RotL64(aNonceWordD, 51U)) ^ RotL64(aNonceWordE, 38U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25839U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 26508U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 54U) ^ RotL64(aCarry, 5U)) + (RotL64(aIngress, 29U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = (aWandererH + RotL64(aIngress, 35U)) + 9446153639709651566U;
            aOrbiterE = (aWandererA + RotL64(aPrevious, 23U)) + 10550762260670758167U;
            aOrbiterA = (aWandererG + RotL64(aScatter, 13U)) + 7062634922142578383U;
            aOrbiterB = (((aWandererF + RotL64(aCross, 41U)) + RotL64(aCarry, 29U)) + 9178499097812764515U) + RotL64(aNonceWordB, 13U);
            aOrbiterG = (((aWandererC + RotL64(aScatter, 44U)) + RotL64(aCarry, 35U)) + 6887103379773525538U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = (((aWandererJ + RotL64(aIngress, 39U)) + RotL64(aCarry, 51U)) + 6239750312052010257U) + RotL64(aNonceWordG, 49U);
            aOrbiterI = (aWandererD + RotL64(aCross, 53U)) + 17645022614523287959U;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 19U)) + 3639618183259408272U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (aWandererB + RotL64(aCross, 46U)) + 3131737117548745095U;
            aOrbiterH = (aWandererK + RotL64(aIngress, 57U)) + 7253994382396406554U;
            aOrbiterJ = (aWandererE + RotL64(aScatter, 11U)) + 15217993711938379561U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 12594152227603630033U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 11250170200489647869U;
            aOrbiterA = RotL64((aOrbiterA * 546800378327864723U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 12936942656624279424U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 10990736056052106149U;
            aOrbiterF = RotL64((aOrbiterF * 7123916809953459187U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 12787293075893090465U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 17154990205620778151U;
            aOrbiterK = RotL64((aOrbiterK * 10031369940028159521U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 1270827262969060301U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 17337623431665013136U;
            aOrbiterH = RotL64((aOrbiterH * 1517262088236356107U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 830330490987911853U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 6828309232554560547U) ^ RotL64(aNonceWordC, 19U);
            aOrbiterD = RotL64((aOrbiterD * 9742464176986145819U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 11470087853413986203U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 10470148870747884420U;
            aOrbiterB = RotL64((aOrbiterB * 6766079738799967443U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 18315536891901859637U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 12264670822285914271U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5841574505408674119U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 10931842095884524879U) + RotL64(aNonceWordE, 3U);
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 11134871340959676257U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11714837622285605745U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 11484168476761306078U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 5964766416973454097U;
            aOrbiterJ = RotL64((aOrbiterJ * 14721123403032510803U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 10646362765367117994U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 8994267196877016381U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17386417559346134797U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 16797547458402042464U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 9446153639709651566U;
            aOrbiterG = RotL64((aOrbiterG * 567585472220695323U), 37U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 18U);
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterC, 39U));
            aWandererH = aWandererH + (((RotL64(aIngress, 27U) + aOrbiterA) + RotL64(aOrbiterI, 43U)) + RotL64(aNonceWordH, 53U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterJ, 5U)) + aOrbiterB);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 23U) + aOrbiterE) + RotL64(aOrbiterD, 41U)) + RotL64(aCarry, 3U)) + aPhaseFWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 54U) + RotL64(aOrbiterI, 24U)) + aOrbiterE);
            aWandererF = aWandererF + ((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterG, 3U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 35U)) + aOrbiterD);
            aWandererC = aWandererC + (((RotL64(aScatter, 51U) + aOrbiterF) + RotL64(aOrbiterC, 37U)) + RotL64(aNonceWordF, 38U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterJ, 53U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 48U) + RotL64(aOrbiterG, 27U)) + aOrbiterH) + RotL64(aCarry, 43U)) + aPhaseFWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterC, 46U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 26U));
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 5U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 35U) ^ RotL64(aNonceWordC, 12U)) ^ RotL64(aNonceWordG, 21U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29258U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((aIndex + 32492U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 57U) ^ RotL64(aNonceWordE, 34U)) ^ RotL64(aNonceWordD, 5U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31133U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((aIndex + 29577U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 40U) + RotL64(aIngress, 53U)) + (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = (aWandererA + RotL64(aPrevious, 43U)) + 18302975933754610273U;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 13U)) + 16736972646771456082U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aCross, 22U)) + 17389406266488137442U;
            aOrbiterB = (aWandererE + RotL64(aScatter, 53U)) + 5252511566486165539U;
            aOrbiterI = (((aWandererJ + RotL64(aCross, 35U)) + RotL64(aCarry, 41U)) + 5730715427422747640U) + RotL64(aNonceWordA, 19U);
            aOrbiterE = (aWandererB + RotL64(aScatter, 29U)) + 6412695646456045825U;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 60U)) + 9539701605708994494U;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 11U)) + 18355107116412945722U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aCross, 3U)) + 11735742491750132942U) + RotL64(aNonceWordC, 3U);
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 5U)) + RotL64(aCarry, 47U)) + 12363819388562658842U;
            aOrbiterK = ((aWandererI + RotL64(aScatter, 41U)) + RotL64(aCarry, 51U)) + 5861430292304371543U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 15027487084595017708U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 7012850020745791926U;
            aOrbiterD = RotL64((aOrbiterD * 15952928839355613939U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 11904871669287886120U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 11199760114477343208U;
            aOrbiterI = RotL64((aOrbiterI * 7156374911847525867U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 3856004502263742700U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 3705931243173921893U;
            aOrbiterE = RotL64((aOrbiterE * 10334871178498711485U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 12305785390539209389U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 18057980996551978823U;
            aOrbiterC = RotL64((aOrbiterC * 4850564181113470859U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 3229431819292153014U) + RotL64(aNonceWordB, 25U);
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 2994716629242460094U;
            aOrbiterG = RotL64((aOrbiterG * 1029427328395257917U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 9796307843453735512U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 2957260393651252432U;
            aOrbiterH = RotL64((aOrbiterH * 7261055869794739609U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 4060469664218866340U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 17462081697889685330U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7712009170974461225U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 13638660073917821172U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 15202349592659062565U;
            aOrbiterK = RotL64((aOrbiterK * 4514326257446024301U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 12071949111168967041U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 11930843273199806728U;
            aOrbiterF = RotL64((aOrbiterF * 16229663295689525137U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 11294220104731500296U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 440743185210586759U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14810195235168807229U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 8514240764798061804U) + RotL64(aNonceWordE, 57U);
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 18302975933754610273U;
            aOrbiterB = RotL64((aOrbiterB * 1972439346780950873U), 37U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 60U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterD, 47U)) + RotL64(aNonceWordD, 41U));
            aWandererA = aWandererA + ((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterE, 3U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 10U) + RotL64(aOrbiterA, 43U)) + aOrbiterH);
            aWandererK = aWandererK + ((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterC, 29U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterA, 18U)) + aOrbiterK) + RotL64(aNonceWordF, 6U));
            aWandererI = aWandererI + (((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 11U)) + aOrbiterI) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 53U)) + aOrbiterB);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 43U) + aOrbiterE) + RotL64(aOrbiterC, 56U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 54U) + RotL64(aOrbiterF, 21U)) + aOrbiterJ) + RotL64(aCarry, 51U)) + aPhaseFWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 5U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererG, 48U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + (RotL64(aWandererJ, 40U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 51U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xDFFA1701268FE67FULL + 0xCABDEDB03410C181ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xEBB616C7B66698B1ULL + 0xAEA53FC15B89ADEAULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xB0033E0077DCDA61ULL + 0xC4BDAFD25E426C7BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xB7EF049FCA9D29DBULL + 0xB4EC5A4D2E9A1603ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xD714D0C8BDDE4471ULL + 0xC9D633C0A4991671ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x9A4157A7B05799D7ULL + 0xFA45BC64043158F5ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xA97A51D2C135A873ULL + 0x964DA100D4C7A05CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xFE26834CC6CAA6EBULL + 0xF95BB1A985A483E2ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 3U) ^ RotL64(aNonceWordF, 50U)) ^ RotL64(aNonceWordC, 11U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 3412U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 2292U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 60U) ^ RotL64(aNonceWordG, 11U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 2708U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 4690U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 24U) + RotL64(aPrevious, 57U)) + (RotL64(aCarry, 39U) ^ RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 48U)) + RotL64(aCarry, 37U)) + 13481227414590594621U;
            aOrbiterC = (((aWandererK + RotL64(aPrevious, 43U)) + 17425964381118918026U) + aPhaseFOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1]) + RotL64(aNonceWordB, 53U);
            aOrbiterJ = ((aWandererC + RotL64(aCross, 51U)) + RotL64(aCarry, 19U)) + 4792004356135956581U;
            aOrbiterD = (aWandererE + RotL64(aIngress, 27U)) + 11926849936000639098U;
            aOrbiterG = (aWandererB + RotL64(aScatter, 57U)) + 990697329347742142U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 19U)) + 9307721505373076588U) + RotL64(aNonceWordD, 31U);
            aOrbiterK = (aWandererH + RotL64(aIngress, 46U)) + 17605732738841908719U;
            aOrbiterE = (aWandererF + RotL64(aCross, 29U)) + 13110764518634187439U;
            aOrbiterB = (((aWandererI + RotL64(aPrevious, 41U)) + RotL64(aCarry, 23U)) + 17970109897810645911U) + aPhaseFOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aCross, 37U)) + 10273133817644703654U;
            aOrbiterF = (aWandererA + RotL64(aIngress, 5U)) + 11239046688920468137U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 8355821483275763145U) + RotL64(aNonceWordF, 21U);
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 15522151127786049345U) ^ RotL64(aNonceWordE, 59U);
            aOrbiterJ = RotL64((aOrbiterJ * 4844278537850520413U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 5381663179722418112U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 9551368011768104906U;
            aOrbiterH = RotL64((aOrbiterH * 14202470972121732997U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 16264476585232221270U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 7721417776432288282U;
            aOrbiterA = RotL64((aOrbiterA * 10267770327791051869U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 339418090653475277U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 3247926250495935511U;
            aOrbiterD = RotL64((aOrbiterD * 16824669543765729097U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 3390560045236418590U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 3894024951542543635U;
            aOrbiterK = RotL64((aOrbiterK * 10599637790900418767U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 3878539166189668154U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 5617705593218220843U;
            aOrbiterB = RotL64((aOrbiterB * 82771190372750823U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 12320861089148474544U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 14943790251625519550U;
            aOrbiterF = RotL64((aOrbiterF * 13758322022902008313U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 18119213517612562775U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 1413193144229486646U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14562375280658115687U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 14810150213456844196U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 8468712395797520201U;
            aOrbiterG = RotL64((aOrbiterG * 8167911669632436949U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 13501570100536254566U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 15409772061478100850U;
            aOrbiterE = RotL64((aOrbiterE * 955182899606655851U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 8621805947309982779U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 13481227414590594621U;
            aOrbiterI = RotL64((aOrbiterI * 9591362493722704105U), 53U);
            //
            aIngress = RotL64(aOrbiterK, 43U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + (RotL64(aOrbiterA, 60U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterA, 13U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterG, 44U)) + aOrbiterH);
            aWandererK = aWandererK + (((RotL64(aIngress, 39U) + aOrbiterJ) + RotL64(aOrbiterK, 47U)) + RotL64(aNonceWordA, 16U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterE, 21U)) + aPhaseFWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 5U) + RotL64(aOrbiterB, 53U)) + aOrbiterD) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 48U) + RotL64(aOrbiterI, 41U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((RotL64(aCross, 53U) + RotL64(aOrbiterA, 5U)) + aOrbiterK);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 11U)) + aOrbiterC);
            aWandererD = aWandererD + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterK, 18U)) + aOrbiterD) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterD, 29U)) + aOrbiterJ) + RotL64(aNonceWordH, 25U));
            aWandererI = aWandererI + (((RotL64(aScatter, 60U) + RotL64(aOrbiterF, 27U)) + aOrbiterD) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 46U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 29U) ^ RotL64(aNonceWordD, 42U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 9709U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 5875U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 13U) ^ RotL64(aNonceWordC, 35U)) ^ RotL64(aNonceWordE, 22U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 9870U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 6723U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aIngress, 53U)) ^ (RotL64(aPrevious, 40U) + RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = (aWandererB + RotL64(aIngress, 51U)) + 7270044678408187242U;
            aOrbiterH = (((aWandererG + RotL64(aScatter, 57U)) + 10192278965379756766U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1]) + RotL64(aNonceWordG, 5U);
            aOrbiterK = (aWandererD + RotL64(aCross, 60U)) + 17568666746676060748U;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 19U)) + 14312927531124963037U) + RotL64(aNonceWordB, 49U);
            aOrbiterA = ((aWandererE + RotL64(aCross, 35U)) + RotL64(aCarry, 27U)) + 9825825726152087706U;
            aOrbiterB = (aWandererH + RotL64(aPrevious, 27U)) + 9696778570255265896U;
            aOrbiterI = (((aWandererC + RotL64(aScatter, 12U)) + RotL64(aCarry, 57U)) + 17657841352013417228U) + aPhaseFOrbiterAssignSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = (aWandererF + RotL64(aIngress, 43U)) + 16207815085909628439U;
            aOrbiterE = (aWandererI + RotL64(aScatter, 21U)) + 1752979206374514227U;
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 53U)) + RotL64(aCarry, 41U)) + 10456310689643905854U;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 41U)) + 16127830548663742550U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 2940917376003930842U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 7353596864777649953U;
            aOrbiterK = RotL64((aOrbiterK * 7499468723171042005U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 12725092740446150705U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 5791296650856037010U;
            aOrbiterH = RotL64((aOrbiterH * 760379251950502133U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 1200130368046206150U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 16689604428598558547U;
            aOrbiterA = RotL64((aOrbiterA * 13815324235939996623U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 14359561591103730856U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 3975025843599045263U;
            aOrbiterI = RotL64((aOrbiterI * 5025047888533298617U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 14017901732955607601U) + RotL64(aNonceWordC, 7U);
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 10431526786489555196U;
            aOrbiterE = RotL64((aOrbiterE * 10181915874476132407U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 7320527073559849223U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 15333411223710709907U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3488684905528068775U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 14302474063321663801U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 2104154521019935187U;
            aOrbiterD = RotL64((aOrbiterD * 12944382959742278055U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 5167600586916325228U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 4566823109447208716U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9997799807454267443U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 12475580453805083495U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 15461491763911887974U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13548865386159287481U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 11000532703581114393U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 7815822789941347770U) ^ RotL64(aNonceWordF, 46U);
            aOrbiterJ = RotL64((aOrbiterJ * 1476638214324946775U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 2166336159928211562U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 7270044678408187242U;
            aOrbiterC = RotL64((aOrbiterC * 10648564933168714815U), 35U);
            //
            aIngress = RotL64(aOrbiterJ, 11U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterG, 28U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 19U) + aOrbiterA) + RotL64(aOrbiterF, 37U));
            aWandererC = aWandererC + (((RotL64(aCross, 57U) + aOrbiterA) + RotL64(aOrbiterJ, 27U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 48U) + aOrbiterE) + RotL64(aOrbiterC, 51U));
            aWandererF = aWandererF + ((RotL64(aScatter, 43U) + RotL64(aOrbiterI, 60U)) + aOrbiterK);
            aWandererI = aWandererI ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterC, 47U)) + aOrbiterA);
            aWandererB = aWandererB + (((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 43U)) + aOrbiterK) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 39U) + aOrbiterH) + RotL64(aOrbiterF, 11U)) + RotL64(aNonceWordH, 61U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 23U) + aOrbiterG) + RotL64(aOrbiterK, 39U)) + RotL64(aNonceWordA, 21U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 54U) + aOrbiterD) + RotL64(aOrbiterJ, 41U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterB, 20U)) + aOrbiterJ) + RotL64(aCarry, 37U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 21U) + aOrbiterK) + RotL64(aOrbiterB, 5U)) + aPhaseFWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 54U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 6U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 43U) ^ RotL64(aNonceWordH, 5U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 11560U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 14982U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 3U) ^ RotL64(aNonceWordG, 29U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 12867U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneC[((aIndex + 12931U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 13U) + RotL64(aCarry, 27U)) + (RotL64(aCross, 54U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = (aWandererE + RotL64(aIngress, 50U)) + 12222235191147985484U;
            aOrbiterH = (aWandererI + RotL64(aScatter, 13U)) + 16367317014523328414U;
            aOrbiterK = (aWandererH + RotL64(aCross, 5U)) + 3511378091284703789U;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 39U)) + RotL64(aCarry, 29U)) + 15247492830966725949U;
            aOrbiterG = (aWandererK + RotL64(aCross, 43U)) + 7745995913390407897U;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 47U)) + 6463593307540108810U;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 57U)) + 1101669311005268630U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aIngress, 29U)) + RotL64(aCarry, 35U)) + 12988052764067518580U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 41U)) + 17717179747434679772U) + RotL64(aNonceWordD, 37U);
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 37U)) + RotL64(aCarry, 13U)) + 11662190906682400416U;
            aOrbiterC = (((aWandererG + RotL64(aPrevious, 26U)) + 6563014073547628748U) + aPhaseFOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1]) + RotL64(aNonceWordC, 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 13099094932059419219U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 16342730862261868847U;
            aOrbiterK = RotL64((aOrbiterK * 10988124108686164829U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 16855346813127524624U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 6570063128502306944U;
            aOrbiterA = RotL64((aOrbiterA * 4571570049463124831U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 11328352033809240501U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 11640986648833160901U;
            aOrbiterH = RotL64((aOrbiterH * 2895830492089678919U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 2675226158571501666U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 17700531248266458165U;
            aOrbiterG = RotL64((aOrbiterG * 2231403813970188657U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 7729597396731910874U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 15172374484412053756U;
            aOrbiterB = RotL64((aOrbiterB * 149009041406406517U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 9178769489257842683U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 9020154972097834926U) ^ RotL64(aNonceWordF, 57U);
            aOrbiterJ = RotL64((aOrbiterJ * 8910504667566521429U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 1317403761217790562U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 17151528554929201571U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3735945655450625203U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 11621882033959669977U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 10289504450815075623U) ^ RotL64(aNonceWordG, 55U);
            aOrbiterF = RotL64((aOrbiterF * 13365982786836243195U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 16178772981106335703U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 16896130772325866910U;
            aOrbiterD = RotL64((aOrbiterD * 6993524735412868965U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 9573223644675562575U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 17552463713786507189U;
            aOrbiterI = RotL64((aOrbiterI * 16103431656424881779U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 4801852246698369631U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 12222235191147985484U;
            aOrbiterC = RotL64((aOrbiterC * 2835204872125428065U), 37U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 39U);
            aIngress = aIngress + (RotL64(aOrbiterI, 41U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 10U));
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterB, 37U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aScatter, 20U) + RotL64(aOrbiterH, 14U)) + aOrbiterJ);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterI, 5U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 13U) + RotL64(aOrbiterD, 57U)) + aOrbiterJ) + RotL64(aNonceWordA, 12U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterD, 3U));
            aWandererH = aWandererH + (((RotL64(aScatter, 27U) + RotL64(aOrbiterC, 39U)) + aOrbiterE) + RotL64(aNonceWordB, 7U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterI, 53U)) + aOrbiterA);
            aWandererA = aWandererA + (((RotL64(aIngress, 56U) + RotL64(aOrbiterF, 21U)) + aOrbiterE) + RotL64(aCarry, 11U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterF, 35U)) + aOrbiterK) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 43U)) + aOrbiterA) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterB, 18U)) + aOrbiterA);
            aWandererB = aWandererB + ((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterH, 47U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 14U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + RotL64(aWandererD, 38U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 51U) ^ RotL64(aNonceWordB, 41U)) ^ RotL64(aNonceWordE, 10U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 20157U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((aIndex + 17163U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 53U) ^ RotL64(aNonceWordF, 5U)) ^ RotL64(aNonceWordA, 24U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 20920U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneD[((aIndex + 21602U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aPrevious, 35U)) + (RotL64(aIngress, 21U) + RotL64(aCarry, 6U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = (aWandererG + RotL64(aIngress, 36U)) + 9133751643283278896U;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 41U)) + 8971581804375380408U;
            aOrbiterD = (aWandererA + RotL64(aCross, 57U)) + 12559650383714566592U;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 29U)) + 15753206088872859163U;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 13U)) + RotL64(aCarry, 13U)) + 7640756270450762350U;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 21U)) + RotL64(aCarry, 29U)) + 7340073357551376125U;
            aOrbiterA = (((aWandererJ + RotL64(aCross, 39U)) + RotL64(aCarry, 39U)) + 5270256573644196046U) + RotL64(aNonceWordE, 37U);
            aOrbiterK = ((aWandererI + RotL64(aIngress, 53U)) + 3567367996479995928U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 11U)) + 11939634537492733738U) + RotL64(aNonceWordB, 55U);
            aOrbiterB = (aWandererB + RotL64(aIngress, 3U)) + 7051817732424527120U;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 18U)) + 1730487669951837941U) + aPhaseFOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 18009252467909454817U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 2361024272031696442U;
            aOrbiterD = RotL64((aOrbiterD * 15215151562500226027U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 15902755877642960397U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 12243517544704116184U;
            aOrbiterF = RotL64((aOrbiterF * 2576071074148141447U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 16846181962302186187U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 636121425116506681U;
            aOrbiterI = RotL64((aOrbiterI * 17075030673338779993U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 6887385655828217318U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 3705834550934775862U;
            aOrbiterA = RotL64((aOrbiterA * 11275428284929594435U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 11165142437077969438U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 6426659930331618269U;
            aOrbiterK = RotL64((aOrbiterK * 17170640810530893705U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 12629082390899315789U) + RotL64(aNonceWordG, 31U);
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 4277510580069574724U;
            aOrbiterH = RotL64((aOrbiterH * 9829125163412708305U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 13814834144170469978U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 3698381854100295826U;
            aOrbiterB = RotL64((aOrbiterB * 5126359230872258015U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 11623170635983579937U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 7247413650388803796U;
            aOrbiterC = RotL64((aOrbiterC * 3403219499465560059U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 3129755194359521145U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 4081016725582134919U;
            aOrbiterG = RotL64((aOrbiterG * 11564414998539605389U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 15878346077922215753U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 2974440187796944059U;
            aOrbiterJ = RotL64((aOrbiterJ * 783253926537018373U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 3922344163443096356U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 9133751643283278896U) ^ RotL64(aNonceWordD, 25U);
            aOrbiterE = RotL64((aOrbiterE * 16887991698415418429U), 5U);
            //
            aIngress = RotL64(aOrbiterH, 19U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (RotL64(aOrbiterB, 40U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterI, 5U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 23U) + aOrbiterF) + RotL64(aOrbiterI, 39U)) + aPhaseFWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterC, 13U)) + aOrbiterA) + RotL64(aNonceWordH, 27U));
            aWandererB = aWandererB + ((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterF, 46U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 30U) + RotL64(aOrbiterG, 27U)) + aOrbiterA) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 41U)) + aOrbiterD) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterH, 53U)) + aOrbiterG);
            aWandererC = aWandererC + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 23U)) + aOrbiterJ) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 56U) + RotL64(aOrbiterG, 60U)) + aOrbiterI);
            aWandererK = aWandererK + (((RotL64(aCross, 41U) + aOrbiterG) + RotL64(aOrbiterC, 3U)) + RotL64(aNonceWordF, 30U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 35U) + aOrbiterG) + RotL64(aOrbiterJ, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 58U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 14U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 60U) ^ RotL64(aNonceWordB, 21U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 26987U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25167U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 4U) ^ RotL64(aNonceWordC, 47U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 23945U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((aIndex + 22219U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 51U) + RotL64(aCarry, 3U)) + (RotL64(aIngress, 35U) ^ RotL64(aCross, 18U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = ((aWandererC + RotL64(aCross, 27U)) + 5697928251815176134U) + RotL64(aNonceWordD, 15U);
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 24U)) + RotL64(aCarry, 5U)) + 337587740689259575U;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 41U)) + 4927686903263973950U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aScatter, 51U)) + 3742409032569801033U;
            aOrbiterG = (aWandererJ + RotL64(aCross, 47U)) + 1608092659172197650U;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 22U)) + 15848744267145717509U;
            aOrbiterC = (aWandererG + RotL64(aIngress, 53U)) + 15300174177963339253U;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 3U)) + RotL64(aCarry, 51U)) + 14162868453323648628U;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 57U)) + 12020167069983729869U) + RotL64(aNonceWordC, 53U);
            aOrbiterK = (aWandererD + RotL64(aPrevious, 43U)) + 16259538291658723956U;
            aOrbiterB = (((aWandererI + RotL64(aCross, 39U)) + RotL64(aCarry, 35U)) + 8516686212464112245U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 3722184575520553132U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 5663609293306386784U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14364218128780764749U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 15265344442454471986U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 3050323350098829515U;
            aOrbiterI = RotL64((aOrbiterI * 5890624677162388135U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 1093356813820599238U) + RotL64(aNonceWordG, 13U);
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 15167726103772238440U) ^ RotL64(aNonceWordE, 37U);
            aOrbiterH = RotL64((aOrbiterH * 5719466863561311069U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 15170797965325981472U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 17826286701992981628U;
            aOrbiterK = RotL64((aOrbiterK * 11186808881726573677U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 14710892030473425181U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 397194787697553904U;
            aOrbiterE = RotL64((aOrbiterE * 14368930300818752833U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 1273724124862533034U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 13018397560392545616U;
            aOrbiterF = RotL64((aOrbiterF * 4644812473262395329U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 9638716186445643730U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 7255587739807843785U;
            aOrbiterC = RotL64((aOrbiterC * 6055682981584011189U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 9272350563697399628U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 1040729335295009339U;
            aOrbiterA = RotL64((aOrbiterA * 17825687660830291443U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 12128124729613601747U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 2285238815562202219U;
            aOrbiterB = RotL64((aOrbiterB * 15398840993074390573U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 6339113298619163493U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 5911895708485037040U;
            aOrbiterJ = RotL64((aOrbiterJ * 3271006139923200439U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 7601399508218901328U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 5697928251815176134U;
            aOrbiterG = RotL64((aOrbiterG * 8184257916861355735U), 29U);
            //
            aIngress = RotL64(aOrbiterE, 19U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterC, 44U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 56U) + RotL64(aOrbiterG, 60U)) + aOrbiterH);
            aWandererI = aWandererI + (((RotL64(aIngress, 19U) + RotL64(aOrbiterA, 5U)) + aOrbiterD) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterI, 27U)) + aOrbiterH);
            aWandererB = aWandererB + (((RotL64(aScatter, 53U) + aOrbiterK) + RotL64(aOrbiterA, 51U)) + RotL64(aNonceWordF, 47U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 43U) + aOrbiterH) + RotL64(aOrbiterF, 23U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 51U) + aOrbiterB) + RotL64(aOrbiterE, 43U)) + RotL64(aNonceWordH, 34U)) + aPhaseFWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterG, 11U)) + aOrbiterC);
            aWandererC = aWandererC + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterA, 40U)) + aOrbiterH) + RotL64(aCarry, 41U)) + aPhaseFWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 13U) + aOrbiterB) + RotL64(aOrbiterK, 29U));
            aWandererE = aWandererE + ((RotL64(aCross, 24U) + aOrbiterH) + RotL64(aOrbiterJ, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 41U) + aOrbiterC) + RotL64(aOrbiterD, 13U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 30U));
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 28U));
            aCarry = aCarry + RotL64(aWandererJ, 37U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 13U) ^ RotL64(aNonceWordF, 29U)) ^ RotL64(aNonceWordE, 21U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29868U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32001U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 50U) ^ RotL64(aNonceWordG, 11U)) ^ RotL64(aNonceWordA, 3U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32325U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((aIndex + 31362U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCross, 54U)) ^ (RotL64(aCarry, 35U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = (((aWandererC + RotL64(aScatter, 34U)) + RotL64(aCarry, 5U)) + 7825479804710770560U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aCross, 39U)) + 5298124167101358123U) + RotL64(aNonceWordD, 17U);
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 13U)) + 17774541024369233726U;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 43U)) + 7679371833537454082U) + RotL64(aNonceWordH, 45U);
            aOrbiterG = (((aWandererE + RotL64(aPrevious, 21U)) + RotL64(aCarry, 23U)) + 5385914900748772224U) + aPhaseFOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = (aWandererI + RotL64(aScatter, 37U)) + 3879781930908486531U;
            aOrbiterB = (aWandererD + RotL64(aCross, 41U)) + 659110346638873236U;
            aOrbiterI = (aWandererF + RotL64(aIngress, 30U)) + 10749021728538539749U;
            aOrbiterC = (aWandererB + RotL64(aScatter, 3U)) + 3631252455767429457U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 47U)) + 2271978810960685021U;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 5U)) + RotL64(aCarry, 53U)) + 5963558780692551176U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 974909966119198104U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 9296998242911152296U;
            aOrbiterE = RotL64((aOrbiterE * 2613629915877957661U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 2245318466901521959U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 13391076374843288568U;
            aOrbiterG = RotL64((aOrbiterG * 18094558036982107419U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 6184487746594236737U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 1563385912137291418U;
            aOrbiterK = RotL64((aOrbiterK * 4805455299959232321U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 1744840092006498629U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 2100927276837188416U;
            aOrbiterB = RotL64((aOrbiterB * 3541788262067077997U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 9998911862807246338U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 12239948725635220096U;
            aOrbiterI = RotL64((aOrbiterI * 7098620484129489129U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 3307447094994950246U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 12746613971448298932U;
            aOrbiterC = RotL64((aOrbiterC * 9463975886346934681U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 11577488293733790649U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 191108997585598809U;
            aOrbiterJ = RotL64((aOrbiterJ * 9574978681405356871U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 18096145693841273722U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 10026281133603934071U;
            aOrbiterD = RotL64((aOrbiterD * 17261343107314203471U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 2346682418062064668U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 2996178204018644206U) ^ RotL64(aNonceWordC, 22U);
            aOrbiterH = RotL64((aOrbiterH * 2552965800703390909U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 15085425896818988223U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (((aOrbiterF ^ aOrbiterJ) ^ 1589593231782852588U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1]) ^ RotL64(aNonceWordG, 43U);
            aOrbiterF = RotL64((aOrbiterF * 1535556765195388675U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 17170695588248383518U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 7825479804710770560U;
            aOrbiterA = RotL64((aOrbiterA * 7434218282170150533U), 27U);
            //
            aIngress = RotL64(aOrbiterF, 42U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterA, 50U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 21U)) + aOrbiterH) + RotL64(aNonceWordB, 47U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterH, 11U));
            aWandererG = aWandererG + ((RotL64(aCross, 53U) + RotL64(aOrbiterE, 54U)) + aOrbiterD);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 23U) + aOrbiterB) + RotL64(aOrbiterK, 43U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterD, 27U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterI, 51U)) + aOrbiterE);
            aWandererF = aWandererF + (((RotL64(aCross, 37U) + RotL64(aOrbiterG, 13U)) + aOrbiterE) + aPhaseFWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterE, 18U));
            aWandererC = aWandererC + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 37U)) + aOrbiterF) + RotL64(aCarry, 11U)) + RotL64(aNonceWordF, 51U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterD, 3U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 42U) + aOrbiterD) + RotL64(aOrbiterA, 5U)) + RotL64(aCarry, 37U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 54U));
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + RotL64(aWandererB, 27U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 4788U)) & S_BLOCK1], 58U) ^ RotL64(aKeyRowReadA[((aIndex + 1377U)) & W_KEY1], 29U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 3693U)) & W_KEY1], 44U) ^ RotL64(mSource[((aIndex + 961U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 56U) + RotL64(aIngress, 43U)) ^ (RotL64(aPrevious, 11U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 57U)) + 5960680319644404115U) + aPhaseCOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = (aWandererG + RotL64(aScatter, 13U)) + 16050752633567034185U;
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 35U)) + RotL64(aCarry, 39U)) + 8447503223226854741U;
            aOrbiterJ = (((aWandererC + RotL64(aCross, 28U)) + RotL64(aCarry, 47U)) + 14176813813397917591U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aPrevious, 43U)) + 10534915376130006644U;
            aOrbiterK = ((aWandererB + RotL64(aIngress, 5U)) + RotL64(aCarry, 3U)) + 6866224454375302514U;
            aOrbiterE = (aWandererD + RotL64(aScatter, 19U)) + 16506374165041008396U;
            aOrbiterI = (aWandererI + RotL64(aCross, 39U)) + 7167814023968794098U;
            aOrbiterA = (aWandererE + RotL64(aScatter, 50U)) + 13870852197416596664U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 18064038854848993105U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 9869630811507771691U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13723164383800461387U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 863613100452759380U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 16597969741225436529U;
            aOrbiterK = RotL64((aOrbiterK * 2680793528887208903U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 6575347108051310653U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 17062262265485019063U;
            aOrbiterI = RotL64((aOrbiterI * 7601045488473620019U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 7193399224636409133U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 14146747818810433849U;
            aOrbiterA = RotL64((aOrbiterA * 5273185769989530041U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 9441449106442431427U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 4303295336545399503U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8829695296836242587U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 12604760768543193458U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 15779327512379787715U;
            aOrbiterJ = RotL64((aOrbiterJ * 14000905201441272597U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 15553000781122708728U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 17162740616060079717U;
            aOrbiterE = RotL64((aOrbiterE * 9458662233556750239U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 1032374679817715156U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 16413393156165548232U;
            aOrbiterF = RotL64((aOrbiterF * 549659738811935015U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 14056855000013992045U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 7399202019042538829U;
            aOrbiterG = RotL64((aOrbiterG * 6103508549612077695U), 57U);
            //
            aIngress = RotL64(aOrbiterF, 51U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 34U));
            aIngress = aIngress + RotL64(aOrbiterE, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aIngress, 47U) + RotL64(aOrbiterK, 58U)) + aOrbiterC);
            aWandererD = aWandererD ^ (((RotL64(aCross, 6U) + RotL64(aOrbiterI, 47U)) + aOrbiterJ) + aPhaseCWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 19U) + aOrbiterK) + RotL64(aOrbiterE, 41U)) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 39U) + aOrbiterH) + RotL64(aOrbiterG, 35U));
            aWandererF = aWandererF + (((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterE, 23U)) + RotL64(aCarry, 23U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterC, 18U)) + aOrbiterG) + aPhaseCWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 58U) + aOrbiterE) + RotL64(aOrbiterI, 13U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 51U) + aOrbiterF) + RotL64(aOrbiterG, 53U));
            aWandererI = aWandererI + ((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 5U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + RotL64(aWandererJ, 6U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 14603U)) & S_BLOCK1], 39U) ^ RotL64(mSource[((aIndex + 14996U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 12099U)) & W_KEY1], 24U) ^ RotL64(aKeyRowReadB[((aIndex + 10105U)) & W_KEY1], 13U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCarry, 3U)) ^ (RotL64(aPrevious, 37U) + RotL64(aCross, 24U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 43U)) + 11698283336767769359U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = (aWandererA + RotL64(aCross, 39U)) + 13297826354831483872U;
            aOrbiterH = (aWandererH + RotL64(aScatter, 52U)) + 15254999058287530795U;
            aOrbiterB = (aWandererE + RotL64(aIngress, 57U)) + 17474166585085346567U;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 19U)) + 15684783498452840289U) + aPhaseCOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aScatter, 5U)) + RotL64(aCarry, 35U)) + 5061229733465216486U;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 11U)) + 15370981279168377944U;
            aOrbiterI = ((aWandererB + RotL64(aCross, 34U)) + RotL64(aCarry, 23U)) + 17966672773619554092U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 27U)) + RotL64(aCarry, 11U)) + 14685092893994491068U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 12798804186209406389U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 2848444181474221574U;
            aOrbiterH = RotL64((aOrbiterH * 13730480364920876877U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 8551142075919636146U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 8833198159158950723U;
            aOrbiterC = RotL64((aOrbiterC * 7650289040764974737U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 7351473160893666232U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 14204899612487622222U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6317485031956448029U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 7008985178526543258U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 13576796403863120356U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13745839827679114077U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 5769784656937900699U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 14075925808204936705U;
            aOrbiterG = RotL64((aOrbiterG * 5844894088757604713U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 17818667502858010896U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 16016922065572683130U;
            aOrbiterE = RotL64((aOrbiterE * 7525645833898085373U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 1582458237855075977U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 10830440354527138227U;
            aOrbiterB = RotL64((aOrbiterB * 10499386926982228251U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 10653964151654643772U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 11218475491129483859U;
            aOrbiterA = RotL64((aOrbiterA * 3338108067044357141U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 9863649760189649255U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 13790281439048354358U;
            aOrbiterD = RotL64((aOrbiterD * 4682098083538482849U), 21U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 36U);
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + RotL64(aOrbiterD, 6U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 30U) + aOrbiterH) + RotL64(aOrbiterG, 46U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 3U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 41U)) + aOrbiterD);
            aWandererI = aWandererI + (((RotL64(aCross, 23U) + aOrbiterJ) + RotL64(aOrbiterH, 51U)) + RotL64(aCarry, 51U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 34U) + aOrbiterE) + RotL64(aOrbiterD, 57U));
            aWandererH = aWandererH + ((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterC, 23U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 47U) + aOrbiterH) + RotL64(aOrbiterI, 12U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterG, 29U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterE, 19U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 52U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 18650U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((aIndex + 16868U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 24110U)) & W_KEY1], 53U) ^ RotL64(aKeyRowReadB[((aIndex + 17140U)) & W_KEY1], 24U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 22U) + RotL64(aIngress, 57U)) ^ (RotL64(aPrevious, 5U) ^ RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = (aWandererB + RotL64(aPrevious, 5U)) + 9914837590440975587U;
            aOrbiterA = ((aWandererD + RotL64(aCross, 52U)) + RotL64(aCarry, 3U)) + 6706125076401958051U;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 47U)) + RotL64(aCarry, 57U)) + 16570817772679258409U;
            aOrbiterE = (aWandererC + RotL64(aScatter, 13U)) + 6843705658115186948U;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 27U)) + 16099930446791572351U;
            aOrbiterB = (aWandererE + RotL64(aCross, 56U)) + 5420550009556030459U;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 19U)) + 5729549069420177477U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aScatter, 43U)) + RotL64(aCarry, 23U)) + 15590601126188675834U;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 39U)) + 13044027390998620029U) + aPhaseCOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 11068338135659636772U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 6584988841809544332U;
            aOrbiterF = RotL64((aOrbiterF * 1683336180438945439U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 8516813219883915404U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 10647314042912492785U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15559481057047148785U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 201691689889605304U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 15512161798401184003U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11473219183982564709U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 3883760518944464145U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 13861805129175491145U;
            aOrbiterA = RotL64((aOrbiterA * 17194438894492581181U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 12019138626550801486U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 13030350224959652248U;
            aOrbiterJ = RotL64((aOrbiterJ * 11724200983306280107U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 2643807255422544248U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 4127143302485631794U;
            aOrbiterB = RotL64((aOrbiterB * 5441038881111578487U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 14602951930809633069U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 4555737199162278494U;
            aOrbiterH = RotL64((aOrbiterH * 12415825635220991865U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 6343143902997169834U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 10404783711336491985U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6235474458879439079U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 7406959231434835393U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 6684368109277850196U;
            aOrbiterI = RotL64((aOrbiterI * 8760360417572331159U), 43U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 51U);
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 38U));
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterE, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 36U) + RotL64(aOrbiterF, 19U)) + aOrbiterD) + aPhaseCWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 41U)) + aOrbiterH) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterA, 27U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterJ, 3U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterA, 52U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterE, 35U)) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 47U)) + aOrbiterI) + aPhaseCWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterF, 57U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 46U) + RotL64(aOrbiterF, 10U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 21U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + RotL64(aWandererA, 28U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28542U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneB[((aIndex + 27071U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30422U)) & S_BLOCK1], 3U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 32475U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aIngress, 39U)) + (RotL64(aPrevious, 10U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = (aWandererC + RotL64(aIngress, 41U)) + 17711946802293254150U;
            aOrbiterF = (aWandererK + RotL64(aCross, 6U)) + 16652362590489569378U;
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 11U)) + 6972810344198183097U;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 23U)) + RotL64(aCarry, 3U)) + 13117100889782940546U;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 37U)) + RotL64(aCarry, 19U)) + 13199305696782626591U;
            aOrbiterA = ((aWandererI + RotL64(aCross, 51U)) + RotL64(aCarry, 43U)) + 992156184392760945U;
            aOrbiterG = (aWandererE + RotL64(aIngress, 47U)) + 13791265442074543880U;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 58U)) + 17057087245252294859U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aCross, 29U)) + 13444195995883541046U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 6723678233676059420U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 7913379431208430475U;
            aOrbiterC = RotL64((aOrbiterC * 2295062944289127123U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 4481887195529300665U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 11892724101424384078U;
            aOrbiterE = RotL64((aOrbiterE * 3468639499716604111U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 7700902083270424194U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 1888001433557140271U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8975562955027025349U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 14996753906788986929U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 939004845422123765U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2507090308972292313U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 11922230289291941807U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 15681187459741147199U;
            aOrbiterH = RotL64((aOrbiterH * 10124947739653819101U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 9119043713532718155U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 8327697433992362166U;
            aOrbiterA = RotL64((aOrbiterA * 11157657162184304567U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 13630755116592440359U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 771252613886022889U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2958918915223536519U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 8524239721467527770U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 17732617735422435572U;
            aOrbiterJ = RotL64((aOrbiterJ * 13992947983987668631U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 5265753270696005619U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 14456128349522985053U;
            aOrbiterF = RotL64((aOrbiterF * 5406509991740849617U), 35U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterK, 37U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 46U));
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + RotL64(aOrbiterE, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 5U) + RotL64(aOrbiterG, 47U)) + aOrbiterA) + RotL64(aCarry, 23U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 30U) + aOrbiterE) + RotL64(aOrbiterC, 26U)) + aPhaseCWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 23U) + aOrbiterG) + RotL64(aOrbiterK, 5U)) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterF, 39U));
            aWandererB = aWandererB + ((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterH, 35U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 39U) + aOrbiterC) + RotL64(aOrbiterH, 60U));
            aWandererE = aWandererE + ((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterI, 51U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 60U) + aOrbiterH) + RotL64(aOrbiterE, 13U));
            aWandererD = aWandererD + (((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 19U)) + aOrbiterF) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 40U));
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + RotL64(aWandererJ, 29U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5403U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4531U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 8081U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneA[S_BLOCK1 - aIndex], 23U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 52U) + RotL64(aIngress, 3U)) ^ (RotL64(aPrevious, 21U) ^ RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = (((aWandererH + RotL64(aScatter, 19U)) + RotL64(aCarry, 57U)) + 1708250618750199233U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = (((aWandererE + RotL64(aPrevious, 52U)) + RotL64(aCarry, 43U)) + 12009147777553691142U) + aPhaseDOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = ((aWandererI + RotL64(aIngress, 43U)) + RotL64(aCarry, 23U)) + 8393982703399156592U;
            aOrbiterF = (aWandererF + RotL64(aCross, 11U)) + 3247327098356831221U;
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 35U)) + 3403590155376353737U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 18197244558104735044U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 3096253642040701606U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6656168712438620783U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 8012692688785412179U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 17531946907545680745U;
            aOrbiterI = RotL64((aOrbiterI * 16510602981731506381U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 17687695944270225817U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 16147773866007628769U;
            aOrbiterF = RotL64((aOrbiterF * 16926442582711557877U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 18244641303026196497U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 8839160526348897457U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14268021129087663397U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 10599266240854068246U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 2056723540756216155U;
            aOrbiterE = RotL64((aOrbiterE * 13311591601230386375U), 21U);
            //
            aIngress = RotL64(aOrbiterF, 3U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 19U)) + aOrbiterE) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 35U) + RotL64(aOrbiterF, 3U)) + aOrbiterH) + RotL64(aCarry, 29U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterK, 34U));
            aWandererI = aWandererI + (((RotL64(aScatter, 13U) + aOrbiterE) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 60U) + aOrbiterI) + RotL64(aOrbiterE, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererH, 37U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 13781U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneD[((aIndex + 11415U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15621U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((aIndex + 11194U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 22U) ^ RotL64(aCarry, 53U)) + (RotL64(aCross, 5U) + RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (((aWandererI + RotL64(aCross, 35U)) + RotL64(aCarry, 5U)) + 8367680518550579791U) + aPhaseDOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 53U)) + RotL64(aCarry, 21U)) + 11491674725611181241U;
            aOrbiterC = (aWandererC + RotL64(aScatter, 44U)) + 16673861720782164214U;
            aOrbiterA = (((aWandererB + RotL64(aIngress, 21U)) + RotL64(aCarry, 43U)) + 9786610124108350855U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = (aWandererD + RotL64(aCross, 13U)) + 5745080601557577637U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 1959402215131684684U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 6121650036079196522U;
            aOrbiterC = RotL64((aOrbiterC * 13375345606276198671U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 12016309761037342392U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 5986936646177049603U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3585650475703294895U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 1000367700904043468U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 17425288243569101032U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2174614006719048535U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 4856917474950325209U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 16312111093223166419U;
            aOrbiterK = RotL64((aOrbiterK * 11046477664487805241U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 456110002032422270U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 11393724374787795662U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1176984359123668389U), 11U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 19U);
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 56U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 56U) + RotL64(aOrbiterD, 26U)) + aOrbiterF);
            aWandererI = aWandererI + ((((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 51U)) + aPhaseDWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterD, 5U)) + aOrbiterK) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterC, 13U)) + aOrbiterK) + RotL64(aCarry, 37U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterC, 39U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererG, 56U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + RotL64(aWandererD, 13U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 20145U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24172U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21193U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 21092U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCross, 57U)) ^ (RotL64(aCarry, 40U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = (aWandererD + RotL64(aIngress, 39U)) + 2225397913940961213U;
            aOrbiterF = (((aWandererC + RotL64(aScatter, 19U)) + RotL64(aCarry, 3U)) + 8342544893601343643U) + aPhaseDOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aCross, 6U)) + RotL64(aCarry, 29U)) + 162922186381417187U;
            aOrbiterI = (((aWandererK + RotL64(aPrevious, 47U)) + RotL64(aCarry, 41U)) + 11660218373710972210U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = (aWandererH + RotL64(aIngress, 29U)) + 14909034764605802354U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 16776955237009701511U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 5834487809188925253U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4458820879204327709U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 1498492772767040320U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 4161765458781579617U;
            aOrbiterF = RotL64((aOrbiterF * 15535994410289065281U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 10511923076962447765U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 8575954471692620021U;
            aOrbiterA = RotL64((aOrbiterA * 12526744988828982731U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 6536325446331340573U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 1790628986900286346U;
            aOrbiterI = RotL64((aOrbiterI * 5262997114200816715U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 2623814807619278590U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 11676970995834706612U;
            aOrbiterE = RotL64((aOrbiterE * 10057461115132434901U), 21U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 13U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 23U));
            aIngress = aIngress + RotL64(aOrbiterI, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aPrevious, 40U) + RotL64(aOrbiterE, 19U)) + aOrbiterH) + RotL64(aCarry, 51U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 5U)) + aOrbiterI) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 53U) + RotL64(aOrbiterH, 29U)) + aOrbiterF) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterI, 52U)) + aOrbiterE);
            aWandererH = aWandererH + ((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterI, 37U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 50U));
            aCarry = aCarry + RotL64(aWandererD, 3U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 29599U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((aIndex + 30219U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24689U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((aIndex + 27592U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aPrevious, 4U)) + (RotL64(aCarry, 23U) + RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 5U)) + RotL64(aCarry, 53U)) + 8020711767807230555U;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 29U)) + RotL64(aCarry, 11U)) + 15368693777246341570U;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 47U)) + 5117523734225562401U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aCross, 58U)) + 13155269151097507808U;
            aOrbiterJ = (((aWandererF + RotL64(aIngress, 39U)) + RotL64(aCarry, 35U)) + 9879303753623578272U) + aPhaseDOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 1165799257173794826U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 930641942062732091U;
            aOrbiterK = RotL64((aOrbiterK * 17151944851548731159U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 11330571332221123153U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 2862963158282518899U;
            aOrbiterA = RotL64((aOrbiterA * 13782195862525974199U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 6019186399361476659U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 1924419843785161958U;
            aOrbiterH = RotL64((aOrbiterH * 9485557122500346869U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 12618629043591380461U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 9334176504266512405U;
            aOrbiterI = RotL64((aOrbiterI * 18239109235362925739U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 16829692481030013551U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 5604784396927022709U;
            aOrbiterJ = RotL64((aOrbiterJ * 2833893610883508353U), 37U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterI, 18U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + RotL64(aOrbiterJ, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterA, 27U)) + aOrbiterH) + aPhaseDWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 23U) + aOrbiterJ) + RotL64(aOrbiterA, 5U)) + RotL64(aCarry, 11U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 44U)) + aOrbiterH) + aPhaseDWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 60U) + aOrbiterI) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterK, 19U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + RotL64(aWandererH, 43U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 3095U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneC[((aIndex + 385U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 1076U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((aIndex + 5270U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 58U) ^ RotL64(aPrevious, 27U)) + (RotL64(aCarry, 43U) + RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererD + RotL64(aScatter, 58U)) + RotL64(aCarry, 3U)) + 14179205183062705133U;
            aOrbiterD = (aWandererE + RotL64(aPrevious, 27U)) + 210032324058740920U;
            aOrbiterH = ((aWandererG + RotL64(aCross, 11U)) + 7387115089142500152U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = ((aWandererA + RotL64(aIngress, 5U)) + 17583362781238061430U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aScatter, 21U)) + 4991442849150005943U;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 51U)) + RotL64(aCarry, 19U)) + 2891376254689854555U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 41U)) + RotL64(aCarry, 39U)) + 10523274382407446239U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 3861893764676218667U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 3366674459852093746U;
            aOrbiterH = RotL64((aOrbiterH * 14005994095369483813U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 5898492634386601145U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 7047353571244768721U;
            aOrbiterA = RotL64((aOrbiterA * 2257518291062508467U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 14374108805453186316U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 8763667021501226510U;
            aOrbiterE = RotL64((aOrbiterE * 7694695426430267863U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 18261523829316379575U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 650477532238860965U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8291758490821819851U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 2162326554604894042U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 5776546692501825278U;
            aOrbiterK = RotL64((aOrbiterK * 14911545784585246537U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 3501863793638415049U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 14853789267425352958U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10590325397179928739U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 15399673014671329743U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 12253428583438990426U;
            aOrbiterD = RotL64((aOrbiterD * 12052855472196447849U), 21U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 27U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterE, 58U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterI, 37U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 44U) + RotL64(aOrbiterK, 43U)) + aOrbiterA);
            aWandererA = aWandererA + ((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterD, 23U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterE, 10U)) + aOrbiterH);
            aWandererD = aWandererD + (((RotL64(aPrevious, 53U) + aOrbiterA) + RotL64(aOrbiterG, 51U)) + RotL64(aCarry, 19U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterI, 3U)) + aOrbiterA);
            aWandererB = aWandererB + ((((RotL64(aCross, 11U) + RotL64(aOrbiterG, 57U)) + aOrbiterH) + RotL64(aCarry, 39U)) + aPhaseEWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 54U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererG, 27U);
            aCarry = aCarry + RotL64(aIngress, 40U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 16244U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneD[((aIndex + 12807U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15999U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10748U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 37U)) + (RotL64(aIngress, 57U) ^ RotL64(aCross, 18U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (aWandererG + RotL64(aIngress, 6U)) + 10726035965553989335U;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 53U)) + RotL64(aCarry, 53U)) + 967354339530195662U;
            aOrbiterF = (((aWandererC + RotL64(aPrevious, 43U)) + RotL64(aCarry, 41U)) + 10834593005478605624U) + aPhaseEOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = ((aWandererD + RotL64(aCross, 35U)) + RotL64(aCarry, 21U)) + 1012888282838656933U;
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 29U)) + 15283530351725183253U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aIngress, 19U)) + 11724495956731703750U;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 13U)) + 4288330117317505776U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 10894778070022873473U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 15563886747621617467U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17884709931569040065U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 11182488628562891937U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 10420140066310588580U;
            aOrbiterB = RotL64((aOrbiterB * 13898299782819948719U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 11775138062167543111U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 16545391898578161683U;
            aOrbiterH = RotL64((aOrbiterH * 14588306527161321535U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 1550144656312299266U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 14903504853138279883U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8003033561266164387U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 309935535526750396U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 13991265868040011411U;
            aOrbiterJ = RotL64((aOrbiterJ * 2887531132228588441U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 1755976294857114222U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 2259275858478396846U;
            aOrbiterC = RotL64((aOrbiterC * 7416165760067878161U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 4838175912944552936U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 12307900457200936013U;
            aOrbiterA = RotL64((aOrbiterA * 14719363144850838805U), 35U);
            //
            aIngress = RotL64(aOrbiterF, 51U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + (RotL64(aOrbiterG, 12U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 4U) + RotL64(aOrbiterJ, 53U)) + aOrbiterC);
            aWandererH = aWandererH + ((((RotL64(aIngress, 11U) + aOrbiterH) + RotL64(aOrbiterJ, 23U)) + RotL64(aCarry, 13U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterB, 3U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterG, 47U)) + RotL64(aCarry, 43U)) + aPhaseEWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterA, 13U)) + aOrbiterF);
            aWandererF = aWandererF + ((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 39U)) + aOrbiterA);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterB, 60U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererG, 56U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + RotL64(aWandererH, 43U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 20551U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneA[((aIndex + 21369U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 18644U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 19180U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCross, 23U)) + (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 6U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = ((aWandererK + RotL64(aIngress, 37U)) + RotL64(aCarry, 5U)) + 15910560457440369082U;
            aOrbiterJ = (aWandererI + RotL64(aScatter, 13U)) + 17953072986407436888U;
            aOrbiterH = (aWandererE + RotL64(aCross, 19U)) + 15446940721193538669U;
            aOrbiterK = (aWandererC + RotL64(aPrevious, 60U)) + 3020785262774422009U;
            aOrbiterC = (((aWandererD + RotL64(aScatter, 5U)) + RotL64(aCarry, 37U)) + 7001288645424994404U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aIngress, 29U)) + 13385250665458462689U;
            aOrbiterE = (((aWandererJ + RotL64(aPrevious, 43U)) + RotL64(aCarry, 21U)) + 4841895644623005949U) + aPhaseEOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 13053476783239482065U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 641996979335975244U;
            aOrbiterH = RotL64((aOrbiterH * 3697673197256549833U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 16211238020928688299U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 12715448751323279480U;
            aOrbiterJ = RotL64((aOrbiterJ * 2116880429675303291U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 17784406727699995290U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 16626339815786580778U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13940754474750138041U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 9035070625716345139U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 6085848172494001945U;
            aOrbiterK = RotL64((aOrbiterK * 10405728912339646693U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 1177103851507561053U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 2281901691017816407U;
            aOrbiterC = RotL64((aOrbiterC * 3142197009403602497U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 9040984343694325070U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 13334258224023902365U;
            aOrbiterD = RotL64((aOrbiterD * 4782523727707164869U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 1079824790138592518U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 14024082692012948652U;
            aOrbiterE = RotL64((aOrbiterE * 3219489374333737903U), 47U);
            //
            aIngress = RotL64(aOrbiterC, 5U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + RotL64(aOrbiterJ, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterK, 26U)) + aOrbiterB) + aPhaseEWandererUpdateSaltA[((aIndex + 12U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 48U) + RotL64(aOrbiterC, 19U)) + aOrbiterD) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 53U)) + aOrbiterH);
            aWandererC = aWandererC + (((RotL64(aScatter, 11U) + RotL64(aOrbiterK, 37U)) + aOrbiterH) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterC, 3U)) + aOrbiterB);
            aWandererE = aWandererE + ((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterE, 47U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterE, 13U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + (RotL64(aWandererI, 60U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + RotL64(aWandererE, 35U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 28803U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((aIndex + 26463U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28104U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 30394U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 13U) ^ RotL64(aCarry, 56U)) + (RotL64(aPrevious, 43U) + RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = (aWandererG + RotL64(aIngress, 51U)) + 13960289014350612206U;
            aOrbiterK = ((aWandererI + RotL64(aCross, 35U)) + RotL64(aCarry, 43U)) + 3483331015269589730U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 58U)) + 6873299241002444518U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = (aWandererK + RotL64(aScatter, 5U)) + 3562094007125534229U;
            aOrbiterD = ((aWandererD + RotL64(aCross, 29U)) + 11422367439932782705U) + aPhaseEOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 19U)) + RotL64(aCarry, 11U)) + 532453428514259816U;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 41U)) + RotL64(aCarry, 23U)) + 17810941465810193088U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 11869759058631106331U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 8837581071876177566U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15329827515970522213U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 17185378327053837778U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 7578253375676981500U;
            aOrbiterF = RotL64((aOrbiterF * 13371647568758721729U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 17112646434432814442U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 14949096407295697881U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14770977858283051753U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 4259590620758467836U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 6534899413644542303U;
            aOrbiterD = RotL64((aOrbiterD * 7987609419215568661U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 2637407498893694243U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 15819295597921425711U;
            aOrbiterI = RotL64((aOrbiterI * 5202015597375051399U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 6373559542002699718U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 11694562937392022505U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9311557972331218597U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 3308736483775453062U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 12749929710650475901U;
            aOrbiterA = RotL64((aOrbiterA * 248428400724560945U), 53U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterK, 57U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterB, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aCross, 3U) + aOrbiterK) + RotL64(aOrbiterE, 29U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 41U)) + aOrbiterI);
            aWandererE = aWandererE + (((RotL64(aIngress, 54U) + RotL64(aOrbiterA, 12U)) + aOrbiterD) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 27U) + aOrbiterA) + RotL64(aOrbiterF, 47U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterE, 19U)) + aOrbiterB) + RotL64(aCarry, 39U)) + aPhaseEWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterK, 35U)) + aOrbiterB);
            aWandererK = aWandererK + (((RotL64(aCross, 43U) + RotL64(aOrbiterF, 57U)) + aOrbiterI) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 54U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + RotL64(aWandererG, 43U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0;

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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2281U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7080U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7923U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 3641U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 37U) ^ RotL64(aIngress, 3U)) + (RotL64(aPrevious, 53U) + RotL64(aCross, 22U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = ((aWandererA + RotL64(aCross, 19U)) + RotL64(aCarry, 57U)) + 2168513956284366370U;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 37U)) + 10290361969974613111U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = (((aWandererI + RotL64(aIngress, 47U)) + RotL64(aCarry, 29U)) + 15673836275828498050U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 28U)) + RotL64(aCarry, 5U)) + 16600540024145812236U;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 3U)) + 9428052101528111892U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 12763657928312763377U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 10751286982008662485U;
            aOrbiterI = RotL64((aOrbiterI * 6169084301655877217U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 1708230173038057979U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 4011389705422783816U;
            aOrbiterA = RotL64((aOrbiterA * 11692237130784795961U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 11704428328093077714U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 2055336619674699284U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6374289210096410907U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 1870865272102705804U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 3574214263751923179U;
            aOrbiterJ = RotL64((aOrbiterJ * 13132083406834413563U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 984611970726966186U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 15207945449947643672U;
            aOrbiterC = RotL64((aOrbiterC * 9539470161576639981U), 23U);
            //
            aIngress = RotL64(aOrbiterE, 37U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterI, 18U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 13U) + aOrbiterJ) + RotL64(aOrbiterC, 57U));
            aWandererE = aWandererE + ((((RotL64(aCross, 42U) + RotL64(aOrbiterC, 21U)) + aOrbiterI) + RotL64(aCarry, 5U)) + aPhaseFWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterE, 47U)) + aOrbiterA);
            aWandererB = aWandererB + (((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterJ, 12U)) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 27U) + aOrbiterE) + RotL64(aOrbiterC, 37U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 54U));
            aCarry = aCarry + RotL64(aWandererB, 21U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 12825U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneD[((aIndex + 10719U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11061U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneB[((aIndex + 10742U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCarry, 43U)) ^ (RotL64(aIngress, 27U) ^ RotL64(aCross, 12U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = ((aWandererB + RotL64(aIngress, 60U)) + RotL64(aCarry, 41U)) + 3238389262925516513U;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 13U)) + 12381787182611386995U) + aPhaseFOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aCross, 29U)) + RotL64(aCarry, 53U)) + 7883885539305181549U;
            aOrbiterG = (((aWandererG + RotL64(aPrevious, 47U)) + RotL64(aCarry, 29U)) + 1185413044597727092U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aScatter, 21U)) + 15219353497204773135U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 7533774715626734082U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 2599930450937763464U;
            aOrbiterB = RotL64((aOrbiterB * 13207380361960949159U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 16074720663961214284U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 15483613196360051221U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11717479088020532861U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 9396557867081376268U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 9668459976852660245U;
            aOrbiterC = RotL64((aOrbiterC * 11748505665890567063U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 9037269914643207212U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 16936742640861088240U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1040172193161012227U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 16481274825758546398U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 481851372837611166U;
            aOrbiterG = RotL64((aOrbiterG * 2225030139210599207U), 47U);
            //
            aIngress = RotL64(aOrbiterG, 13U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterB, 26U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 60U) + RotL64(aOrbiterG, 27U)) + aOrbiterB) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterD, 11U)) + aOrbiterC) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 13U) + aOrbiterE) + RotL64(aOrbiterB, 52U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 21U) + aOrbiterC) + RotL64(aOrbiterE, 19U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterD, 39U)) + aOrbiterG) + RotL64(aCarry, 41U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 37U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 17197U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18134U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 24495U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 24270U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aPrevious, 3U)) + (RotL64(aCarry, 48U) ^ RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (aWandererJ + RotL64(aIngress, 5U)) + 12131317914288566437U;
            aOrbiterB = ((aWandererG + RotL64(aCross, 19U)) + 5672805657999385496U) + aPhaseFOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = (((aWandererK + RotL64(aPrevious, 41U)) + RotL64(aCarry, 21U)) + 3581710244233124197U) + aPhaseFOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aScatter, 50U)) + RotL64(aCarry, 5U)) + 15251296040538489436U;
            aOrbiterE = ((aWandererB + RotL64(aCross, 27U)) + RotL64(aCarry, 53U)) + 11295008604679904153U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 2230897493419504490U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 7109600123297458999U;
            aOrbiterF = RotL64((aOrbiterF * 8267799351136506307U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 13119156643107683803U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 14755160867807355250U;
            aOrbiterB = RotL64((aOrbiterB * 10007087518844899239U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 16829363373287496832U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 16981122946707720883U;
            aOrbiterC = RotL64((aOrbiterC * 5394974422201576627U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 8806000776958603317U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 16810923047720876014U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17872735050219539145U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 8129657889554436328U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 8653100378491974463U;
            aOrbiterE = RotL64((aOrbiterE * 11395283153912468661U), 37U);
            //
            aIngress = RotL64(aOrbiterG, 3U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + RotL64(aOrbiterB, 42U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 5U)) + aOrbiterF);
            aWandererE = aWandererE + (((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 39U) + aOrbiterB) + RotL64(aOrbiterF, 41U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 50U) + RotL64(aOrbiterC, 57U)) + aOrbiterB) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterF, 14U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 25586U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26389U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26147U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneD[((aIndex + 26687U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 50U) ^ RotL64(aIngress, 37U)) + (RotL64(aCross, 21U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 50U)) + RotL64(aCarry, 21U)) + 13714409587461539863U;
            aOrbiterJ = (((aWandererI + RotL64(aIngress, 3U)) + RotL64(aCarry, 37U)) + 14101156723903265839U) + aPhaseFOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = ((aWandererB + RotL64(aCross, 23U)) + RotL64(aCarry, 5U)) + 7063754562895369001U;
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 35U)) + 12320578575245519386U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aIngress, 13U)) + 11744826789631008424U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 8744816505096675597U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 10405435520084528645U;
            aOrbiterI = RotL64((aOrbiterI * 13279521344071568023U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 1463157688070683543U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 12379603577919617703U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14858901470015109311U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 1343439118031348146U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 16118850268070235540U;
            aOrbiterF = RotL64((aOrbiterF * 11184386483735388257U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 14116264435819277136U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 5251698273012432109U;
            aOrbiterJ = RotL64((aOrbiterJ * 1495818611622063967U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 14806408656041403829U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 11569345414052398227U;
            aOrbiterG = RotL64((aOrbiterG * 9913158908301414861U), 5U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterI, 24U);
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 51U) + aOrbiterF) + RotL64(aOrbiterG, 13U)) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 36U)) + aOrbiterF);
            aWandererK = aWandererK + ((((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 37U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 28U) + RotL64(aOrbiterI, 21U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 47U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 5327U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 7658U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 1451U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 6663U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 42U) + RotL64(aCross, 11U)) ^ (RotL64(aIngress, 57U) + RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = (aWandererC + RotL64(aPrevious, 13U)) + 3236820517816085022U;
            aOrbiterA = (((aWandererF + RotL64(aCross, 50U)) + RotL64(aCarry, 13U)) + 741288875914097926U) + aPhaseGOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aIngress, 5U)) + RotL64(aCarry, 27U)) + 8417246926007729580U;
            aOrbiterB = (((aWandererJ + RotL64(aScatter, 29U)) + RotL64(aCarry, 41U)) + 9715717805774537170U) + aPhaseGOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 37U)) + 14360243844821619482U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 10760908100206775334U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 3434641779946167811U;
            aOrbiterK = RotL64((aOrbiterK * 3305698324169010803U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 7885568822756234567U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 3041563437672051294U;
            aOrbiterF = RotL64((aOrbiterF * 11440300917533482297U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 15761355327564963516U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 1158633562785937421U;
            aOrbiterB = RotL64((aOrbiterB * 15511324886867188235U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 9338581575871970653U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 9172038894262857354U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3110871165285625807U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 14653924713599790081U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 3854497592598563309U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11737111068815795303U), 5U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 13U);
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 38U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 37U) + aOrbiterA) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 19U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterF, 3U)) + aOrbiterK);
            aWandererC = aWandererC + (((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 57U)) + aOrbiterF) + aPhaseGWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterJ, 12U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 50U) + aOrbiterJ) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererC, 41U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 14880U)) & S_BLOCK1], 40U) ^ RotL64(aWorkLaneC[((aIndex + 8549U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 13623U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneA[((aIndex + 10680U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCarry, 37U)) ^ (RotL64(aCross, 51U) + RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 11U)) + RotL64(aCarry, 53U)) + 17225673071833726819U;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 3U)) + 10301458382103627331U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (((aWandererE + RotL64(aScatter, 35U)) + RotL64(aCarry, 41U)) + 3960233050857362414U) + aPhaseGOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = ((aWandererG + RotL64(aCross, 50U)) + RotL64(aCarry, 29U)) + 17768665685046605837U;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 21U)) + 14471018461213959767U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 10730597892721340453U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 14863394003122760542U;
            aOrbiterA = RotL64((aOrbiterA * 17731557030589257169U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 9948587274816688296U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 3573569431435100993U;
            aOrbiterJ = RotL64((aOrbiterJ * 2303922230056523077U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 8153670675740450590U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 16438856577722561424U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4689247488336908827U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 15765587867581925041U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 1082039522061775213U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17023740047246402641U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 4202521649260798876U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 15877659681260461141U;
            aOrbiterG = RotL64((aOrbiterG * 11369910758551088173U), 51U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterG, 57U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + RotL64(aOrbiterJ, 36U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 43U) + aOrbiterJ) + RotL64(aOrbiterH, 4U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 23U)) + aOrbiterB) + RotL64(aCarry, 23U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 53U)) + aOrbiterH) + aPhaseGWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 27U) + aOrbiterG) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 3U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 58U) + RotL64(aOrbiterH, 37U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (RotL64(aWandererE, 46U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 18392U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneD[((aIndex + 16832U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23553U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneB[((aIndex + 20113U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aIngress, 51U)) + (RotL64(aCarry, 38U) ^ RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = (aWandererC + RotL64(aCross, 38U)) + 898812731947995389U;
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 29U)) + RotL64(aCarry, 11U)) + 8677347622525527167U;
            aOrbiterI = (((aWandererI + RotL64(aScatter, 53U)) + RotL64(aCarry, 51U)) + 770321564027567654U) + aPhaseGOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 11U)) + RotL64(aCarry, 29U)) + 11020474858081526395U;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 19U)) + 17289793580414993470U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 10111912559295118444U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 8083622125544542011U;
            aOrbiterI = RotL64((aOrbiterI * 3610772128071340341U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 7149858558922988240U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 5919683821379905699U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16705119888884231567U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 6860902846079238714U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 15083517836867542075U;
            aOrbiterC = RotL64((aOrbiterC * 4686657139237578325U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 14852868368708376381U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 9860233289028878323U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13418143547952204667U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 772406119079116272U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 7971141501337627589U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10168120622976358617U), 5U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterH, 56U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + RotL64(aOrbiterC, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterH, 6U)) + aPhaseGWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 21U) + aOrbiterI) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 47U)) + aOrbiterC);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 37U)) + aOrbiterC) + RotL64(aCarry, 57U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 58U) + RotL64(aOrbiterJ, 19U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + RotL64(aWandererH, 38U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 27560U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31859U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27339U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 32094U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCarry, 51U)) ^ (RotL64(aCross, 11U) ^ RotL64(aIngress, 36U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 36U)) + 2672739400294801233U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aScatter, 13U)) + RotL64(aCarry, 27U)) + 8475624545015101850U;
            aOrbiterH = (((aWandererA + RotL64(aIngress, 23U)) + RotL64(aCarry, 39U)) + 1252755112289831257U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = ((aWandererB + RotL64(aCross, 51U)) + RotL64(aCarry, 53U)) + 7938039507649183387U;
            aOrbiterC = (aWandererD + RotL64(aPrevious, 3U)) + 8167413146948861022U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 17712313989694374353U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 7637042279892596975U;
            aOrbiterH = RotL64((aOrbiterH * 13056020836704050293U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 15770412950033467341U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 3951812021898608685U;
            aOrbiterF = RotL64((aOrbiterF * 6623127125223204737U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 8656983621098246507U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 17943342344730687317U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16495519451034883813U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 3087677463651608668U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 16493240011924342788U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16898479041530771871U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 7750923317452683057U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 2185924841611106546U;
            aOrbiterC = RotL64((aOrbiterC * 708072658250726381U), 29U);
            //
            aIngress = RotL64(aOrbiterH, 29U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterE, 19U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterI, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aCross, 56U) + aOrbiterH) + RotL64(aOrbiterE, 53U)) + RotL64(aCarry, 43U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 13U)) + aOrbiterI) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 21U) + aOrbiterF) + RotL64(aOrbiterC, 43U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterC, 34U));
            aWandererD = aWandererD + (((RotL64(aScatter, 11U) + RotL64(aOrbiterH, 23U)) + aOrbiterC) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererD, 53U);
            aCarry = aCarry + RotL64(aIngress, 34U);
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterJ = 0;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 2547U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7592U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1654U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 392U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 29U) ^ RotL64(aCross, 43U)) ^ (RotL64(aCarry, 56U) + RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = ((aWandererK + RotL64(aCross, 37U)) + RotL64(aCarry, 27U)) + 3917730204724097072U;
            aOrbiterC = (((aWandererG + RotL64(aScatter, 12U)) + RotL64(aCarry, 3U)) + 1874642340716212824U) + aPhaseHOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = (((aWandererE + RotL64(aPrevious, 27U)) + RotL64(aCarry, 43U)) + 6900165757434854160U) + aPhaseHOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aIngress, 3U)) + 12750946097023807161U;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 53U)) + 6563216048479513594U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 14960240191349450795U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 16306180275951788289U;
            aOrbiterK = RotL64((aOrbiterK * 12077366095522790283U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 6502066618271045547U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 6219852857850888738U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10892297250334325283U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 2272931312452845850U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 3028929882263199463U;
            aOrbiterH = RotL64((aOrbiterH * 11005324285856805069U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 6067393030073568112U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 10094809900437037258U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 18095564940730322769U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 5962414178157074575U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 15755563045799129417U;
            aOrbiterA = RotL64((aOrbiterA * 3692603590609922031U), 39U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterK, 23U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 12U));
            aIngress = aIngress + RotL64(aOrbiterH, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterE, 58U));
            aWandererK = aWandererK + (((RotL64(aIngress, 41U) + aOrbiterA) + RotL64(aOrbiterK, 13U)) + RotL64(aCarry, 41U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterA, 3U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 57U) + RotL64(aOrbiterE, 39U)) + aOrbiterH) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 30U) + RotL64(aOrbiterC, 23U)) + aOrbiterH) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 58U));
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 8705U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14560U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14811U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11772U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 18U) ^ RotL64(aPrevious, 3U)) + (RotL64(aCross, 39U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = ((aWandererC + RotL64(aCross, 14U)) + RotL64(aCarry, 53U)) + 2974056819475622600U;
            aOrbiterB = (((aWandererI + RotL64(aScatter, 35U)) + RotL64(aCarry, 39U)) + 7345051759236356098U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aPrevious, 23U)) + 12738468816846628882U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 43U)) + RotL64(aCarry, 21U)) + 7694520596043297922U;
            aOrbiterH = ((aWandererH + RotL64(aCross, 53U)) + 5530753590015084774U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 3776309161718383105U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 784780304358106404U;
            aOrbiterD = RotL64((aOrbiterD * 1503119308251871519U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 8999942326995036509U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 5194986506064092779U;
            aOrbiterH = RotL64((aOrbiterH * 15070787038006135963U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 7920040007459652762U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 11311997270710107937U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6227571709361790209U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 5365231114813547251U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 8630110234623825263U;
            aOrbiterB = RotL64((aOrbiterB * 2735881715888325759U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 2358235238039571072U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 18059414891616491807U;
            aOrbiterE = RotL64((aOrbiterE * 17150786106857185467U), 35U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterD, 41U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 4U));
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 53U)) + aOrbiterA) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 4U) + aOrbiterA) + RotL64(aOrbiterH, 43U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 41U) + aOrbiterE) + RotL64(aOrbiterB, 29U)) + RotL64(aCarry, 43U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 3U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aPrevious, 51U) + aOrbiterD) + RotL64(aOrbiterE, 18U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 34U));
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 23299U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18242U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23665U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneB[((aIndex + 17910U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aIngress, 35U)) + (RotL64(aCarry, 22U) ^ RotL64(aPrevious, 47U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = (((aWandererB + RotL64(aScatter, 60U)) + RotL64(aCarry, 53U)) + 18319689184146942855U) + aPhaseHOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 39U)) + RotL64(aCarry, 23U)) + 8041304130090501019U;
            aOrbiterH = (aWandererD + RotL64(aCross, 13U)) + 11347064191990897738U;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 29U)) + 15242243470024447468U;
            aOrbiterE = (((aWandererF + RotL64(aCross, 51U)) + RotL64(aCarry, 3U)) + 10619749107163611105U) + aPhaseHOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 14795614276221947128U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 1578095288886372393U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9953192041564147241U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 13593906305770501684U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 8919815528334599172U;
            aOrbiterA = RotL64((aOrbiterA * 2033810402808238127U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 17425548324720065145U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 11125018338392347335U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4377887040461528587U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 3779189180734244399U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 10958224663276134041U;
            aOrbiterJ = RotL64((aOrbiterJ * 6206963519509783781U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 4317305352561612995U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 4891139433808505355U;
            aOrbiterE = RotL64((aOrbiterE * 11507024985663120317U), 3U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 41U);
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 22U) + aOrbiterJ) + RotL64(aOrbiterH, 39U)) + aPhaseHWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterH, 48U)) + aOrbiterE) + RotL64(aCarry, 3U)) + aPhaseHWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 51U) + aOrbiterJ) + RotL64(aOrbiterE, 5U));
            aWandererB = aWandererB + (((RotL64(aCross, 35U) + RotL64(aOrbiterA, 21U)) + aOrbiterK) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 57U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + RotL64(aWandererD, 42U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 32131U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28430U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29457U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneC[((aIndex + 32102U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aPrevious, 3U)) ^ (RotL64(aIngress, 47U) ^ RotL64(aCarry, 18U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = ((aWandererF + RotL64(aCross, 13U)) + RotL64(aCarry, 11U)) + 6243113109470883144U;
            aOrbiterF = ((aWandererH + RotL64(aIngress, 5U)) + 3891552123999605832U) + aPhaseHOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 22U)) + 8758797898587019128U) + aPhaseHOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 51U)) + RotL64(aCarry, 47U)) + 1005891374086408851U;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 41U)) + RotL64(aCarry, 23U)) + 3713426782180050764U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 18358143862391573534U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 17504394029693712404U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3391716204095092531U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 5312729289027417014U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 2560873623431186029U;
            aOrbiterC = RotL64((aOrbiterC * 16843728573219210173U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 16309322822806704211U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 10195513918020652600U;
            aOrbiterE = RotL64((aOrbiterE * 14569219741824123715U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 2552116263258744287U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 7732784879810980089U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15041929399477790999U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 16499127570665381507U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 10890036715535519036U;
            aOrbiterK = RotL64((aOrbiterK * 9065115450010475187U), 29U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 28U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + RotL64(aOrbiterF, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 27U)) + aOrbiterE) + aPhaseHWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 28U) + aOrbiterC) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 13U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 41U) + aOrbiterB) + RotL64(aOrbiterF, 3U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 35U)) + aOrbiterK) + RotL64(aCarry, 37U)) + aPhaseHWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterK, 56U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
