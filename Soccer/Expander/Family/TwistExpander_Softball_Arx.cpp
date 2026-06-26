#include "TwistExpander_Softball_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Softball_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xA73620F7B4EF8BCFULL + 0xCA837341B18C6294ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xFA961A4E80A03261ULL + 0xB02CF5DC377B5F41ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xCCF5BD20983CC371ULL + 0xA713040788D65B71ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xBED72501897804ADULL + 0xC221FEE51AB82684ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x919DD26C5DC6BF2DULL + 0x905ABB8A3F0909DDULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x8CEE6F1225D17831ULL + 0x801595FFA7223F39ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xFEDD0FCE5774FA6BULL + 0xA11AB4675C08F875ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xC2153B4D928F5B53ULL + 0xF95D0E268012B085ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xC0682C3042D6F0C5ULL + 0xDB3EDB19DC6EAF1CULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xE436347AD4D2FB5FULL + 0xB64D54D929085071ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x919B6DAD93F46465ULL + 0x96C119AC95349705ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xA9C1ACBF2C3B31B3ULL + 0xDAED9C6DE8E6B9F0ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xBBA239005EEF5DABULL + 0xCF629C7CF2F11B01ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x8275A364ED868A61ULL + 0x8267C13BF0D46E86ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xA999CBBFDC280821ULL + 0xC55B846CD9D7B1BBULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xFC5036FE442A84A1ULL + 0x955C57C8E97D5D96ULL);
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 5194U)) & S_BLOCK1], 51U) ^ RotL64(pSnow[((aIndex + 3080U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 1812U)) & S_BLOCK1], 5U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 4161U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aIngress, 38U)) ^ (RotL64(aCross, 5U) + RotL64(aPrevious, 53U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 43U)) + RotL64(aCarry, 43U)) + 3105313968748067810U;
            aOrbiterA = ((((aWandererE + RotL64(aCross, 21U)) + RotL64(aCarry, 11U)) + 9977249451119627064U) + aOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordB;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 36U)) + RotL64(aCarry, 3U)) + 17941392803495349366U;
            aOrbiterC = (aWandererF + RotL64(aIngress, 51U)) + 4279533326705471133U;
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 27U)) + 13983828966811580039U) + aNonceWordH;
            aOrbiterI = (aWandererG + RotL64(aCross, 29U)) + 3983490984234810378U;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 3U)) + 308786542215259956U;
            aOrbiterF = (aWandererI + RotL64(aScatter, 47U)) + 8443607695364427037U;
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 39U)) + 14939626441464340668U) + aOrbiterAssignSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aCross, 12U)) + 9350693577306121110U;
            aOrbiterK = (aWandererH + RotL64(aIngress, 53U)) + 1717071159396961752U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 15911765265202100610U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 14898546272333182767U;
            aOrbiterE = RotL64((aOrbiterE * 2674900543810733067U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 3560903518513465868U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 5367062725726860234U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8521908836601319553U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 15233321480618877327U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 9288449812290126074U;
            aOrbiterG = RotL64((aOrbiterG * 6815298520404038519U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 5504840529511585676U) + aNonceWordA;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 6825598386801620046U;
            aOrbiterC = RotL64((aOrbiterC * 11666542445846250077U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 6433024450721339470U) + aNonceWordE;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 97934156644929458U;
            aOrbiterJ = RotL64((aOrbiterJ * 8630530773006923215U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 3260053604798744515U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 16539416623243059076U;
            aOrbiterH = RotL64((aOrbiterH * 12199577351166064503U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 9814290051339038920U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterB) ^ 13280156404507444041U) ^ aOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterK = RotL64((aOrbiterK * 15269010043398910061U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 11853942590993546833U) + aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 13207869904312989977U;
            aOrbiterA = RotL64((aOrbiterA * 15503461937625795969U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 14536032167989376750U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 3693282775047432356U;
            aOrbiterB = RotL64((aOrbiterB * 5290349323647887877U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 5803176485246280271U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 16702526675475954730U;
            aOrbiterF = RotL64((aOrbiterF * 13695676754973145769U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 16454171963808313625U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 3105313968748067810U;
            aOrbiterD = RotL64((aOrbiterD * 16572687178789102843U), 19U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterC, 39U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 10U));
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + RotL64(aOrbiterK, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterD, 11U)) + aOrbiterH) + aNonceWordF) + aWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 50U) + RotL64(aOrbiterJ, 57U)) + aOrbiterG);
            aWandererA = aWandererA + ((RotL64(aScatter, 35U) + aOrbiterJ) + RotL64(aOrbiterC, 14U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 47U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((RotL64(aCross, 47U) + RotL64(aOrbiterE, 27U)) + aOrbiterG);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 39U)) + aOrbiterA);
            aWandererH = aWandererH + ((RotL64(aPrevious, 44U) + aOrbiterD) + RotL64(aOrbiterI, 21U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterF, 41U)) + aWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 39U) + aOrbiterB) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 3U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterB, 23U)) + aOrbiterI) + aNonceWordD);
            aWandererE = aWandererE + (((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 60U)) + aOrbiterI) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 56U));
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + (RotL64(aWandererH, 14U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererC, 41U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordG);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 7542U)) & S_BLOCK1], 50U) ^ RotL64(mSource[((aIndex + 7328U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(pSnow[((S_BLOCK1 - aIndex + 6987U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10635U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 21U)) + (RotL64(aIngress, 6U) ^ RotL64(aCarry, 43U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererJ + RotL64(aIngress, 36U)) + 7722279280863371124U;
            aOrbiterI = ((aWandererB + RotL64(aScatter, 39U)) + RotL64(aCarry, 37U)) + 11584220561732385598U;
            aOrbiterE = ((aWandererE + RotL64(aCross, 51U)) + 7834679350105534657U) + aNonceWordG;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 21U)) + 11347994382444180879U;
            aOrbiterG = (aWandererG + RotL64(aCross, 5U)) + 9449903188047063431U;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 41U)) + 6516243976652795170U) + aNonceWordB;
            aOrbiterB = (aWandererA + RotL64(aIngress, 13U)) + 8420815253991184777U;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 19U)) + RotL64(aCarry, 3U)) + 9081386852515170937U;
            aOrbiterK = (aWandererD + RotL64(aCross, 46U)) + 14375955191735286867U;
            aOrbiterH = (((aWandererI + RotL64(aIngress, 53U)) + RotL64(aCarry, 27U)) + 880757589768436072U) + aOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 29U)) + 3349856625725164229U) + aOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 7826309957607577207U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 8057435761214313635U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4718430712767038607U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 9565237500443303103U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 15893066735310588501U;
            aOrbiterI = RotL64((aOrbiterI * 8457633439171452397U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 3276844534476430842U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 6828644383891274120U;
            aOrbiterG = RotL64((aOrbiterG * 979580351653410157U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 2815676923011504251U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 5030251870850928417U) ^ aOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7075653570570819253U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 13464083008377887034U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 8994560761846897590U;
            aOrbiterK = RotL64((aOrbiterK * 9892839554658865143U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 8398813387154468736U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 8136429428340910892U;
            aOrbiterC = RotL64((aOrbiterC * 3348811490733577295U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 418587250696862341U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 4111667833838312094U;
            aOrbiterJ = RotL64((aOrbiterJ * 860949442143849147U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 6075478294190926371U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 2208124955874142264U) ^ aNonceWordD;
            aOrbiterD = RotL64((aOrbiterD * 15741988616251072075U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 4726538724576443010U) + aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 6524078248882840425U) ^ aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9784875566721689069U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 14521003220464811621U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 16916247868211621303U;
            aOrbiterH = RotL64((aOrbiterH * 1911638054294853877U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 18207293125461843123U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 7722279280863371124U) ^ aNonceWordK;
            aOrbiterA = RotL64((aOrbiterA * 14303108475807941791U), 29U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterD, 53U);
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 24U));
            aIngress = aIngress + RotL64(aOrbiterJ, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 3U)) + aOrbiterC) + aNonceWordP);
            aWandererB = aWandererB + ((RotL64(aPrevious, 30U) + aOrbiterH) + RotL64(aOrbiterC, 21U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterA, 14U));
            aWandererC = aWandererC + ((((RotL64(aCross, 21U) + aOrbiterG) + RotL64(aOrbiterE, 11U)) + RotL64(aCarry, 41U)) + aWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterI, 41U)) + aOrbiterF);
            aWandererE = aWandererE + ((RotL64(aCross, 51U) + RotL64(aOrbiterK, 29U)) + aOrbiterE);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterG, 37U)) + aOrbiterJ);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterH, 47U)) + aOrbiterJ) + RotL64(aCarry, 35U)) + aWandererUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 11U) + aOrbiterD) + RotL64(aOrbiterG, 23U)) + aNonceWordF);
            aWandererF = aWandererF + ((RotL64(aCross, 58U) + aOrbiterI) + RotL64(aOrbiterE, 5U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterB, 34U)) + aOrbiterA) + aNonceWordA);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 24U));
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 53U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 14744U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((aIndex + 13381U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 11028U)) & S_BLOCK1], 12U) ^ RotL64(pSnow[((aIndex + 13121U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 20U) + RotL64(aPrevious, 51U)) ^ (RotL64(aIngress, 3U) ^ RotL64(aCross, 37U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererK + RotL64(aCross, 35U)) + RotL64(aCarry, 51U)) + 12029393034357490020U;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 13U)) + 4526754731580694987U) + aOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aIngress, 5U)) + 17060419646421271853U;
            aOrbiterJ = (aWandererG + RotL64(aScatter, 54U)) + 4128488893837059683U;
            aOrbiterG = (aWandererC + RotL64(aCross, 29U)) + 12706894827547160110U;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 51U)) + RotL64(aCarry, 57U)) + 12506324593645825056U;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 37U)) + 12581344490649250025U) + aOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 11U)) + 14357032418199130132U) + aNonceWordM;
            aOrbiterE = (aWandererE + RotL64(aPrevious, 40U)) + 15341977701796331249U;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 3U)) + RotL64(aCarry, 43U)) + 7086602307544733241U;
            aOrbiterC = (aWandererD + RotL64(aCross, 27U)) + 12398300065276832486U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 2499745046076601988U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 7249361592814001829U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14597139848072319685U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 3254456186337366437U) + aOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 3472973415969046680U;
            aOrbiterK = RotL64((aOrbiterK * 14583566953969168353U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 7905718972111691591U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 15941413652144021522U;
            aOrbiterI = RotL64((aOrbiterI * 3473779492962783565U), 13U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterA) + 10583964125960308762U) + aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1]) + aNonceWordB;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 13659925272340853715U;
            aOrbiterG = RotL64((aOrbiterG * 16708294803316630743U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 9487054537489454887U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 13287757570441887517U;
            aOrbiterH = RotL64((aOrbiterH * 17351439045329892107U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 15279245465808571942U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 12424999114621745879U;
            aOrbiterA = RotL64((aOrbiterA * 2274918760256527137U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 13915392738892970475U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 13797668053788805126U;
            aOrbiterD = RotL64((aOrbiterD * 13752161103680525317U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 14344766585550401077U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 13727554194373146727U;
            aOrbiterJ = RotL64((aOrbiterJ * 17164450431362670223U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 1332966642432651232U) + aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 938583742533681467U;
            aOrbiterB = RotL64((aOrbiterB * 13323340043936037549U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 5659239372701978244U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 8501778564909302938U;
            aOrbiterE = RotL64((aOrbiterE * 15629932660749672503U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 1698500835332753591U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 12029393034357490020U;
            aOrbiterC = RotL64((aOrbiterC * 18176507271635640153U), 11U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 51U);
            aIngress = aIngress + (RotL64(aOrbiterH, 60U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + (RotL64(aOrbiterD, 39U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterC, 19U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 54U) + aOrbiterG) + RotL64(aOrbiterF, 24U)) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterK, 43U)) + aOrbiterH);
            aWandererA = aWandererA + (((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterC, 53U)) + aNonceWordL);
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 3U) + aOrbiterE) + RotL64(aOrbiterI, 5U)) + aNonceWordE) + aWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aScatter, 37U) + RotL64(aOrbiterK, 14U)) + aOrbiterI) + RotL64(aCarry, 3U)) + aWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterD, 37U));
            aWandererG = aWandererG + ((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 35U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterG, 11U)) + aOrbiterH);
            aWandererC = aWandererC + ((RotL64(aIngress, 44U) + RotL64(aOrbiterE, 39U)) + aOrbiterB);
            aWandererD = aWandererD ^ ((RotL64(aCross, 51U) + aOrbiterF) + RotL64(aOrbiterC, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 24U));
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 30U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordF);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 17053U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18102U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21560U)) & S_BLOCK1], 51U) ^ RotL64(mSource[((aIndex + 17780U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 50U) ^ RotL64(aCross, 11U)) ^ (RotL64(aCarry, 23U) + RotL64(aPrevious, 37U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererD + RotL64(aCross, 21U)) + 6521330037475130256U;
            aOrbiterH = (aWandererE + RotL64(aIngress, 57U)) + 12611880456055428940U;
            aOrbiterA = (((aWandererK + RotL64(aPrevious, 37U)) + RotL64(aCarry, 3U)) + 12061611078130934708U) + aOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = ((aWandererG + RotL64(aScatter, 5U)) + 1558112410801116984U) + aNonceWordD;
            aOrbiterG = (aWandererH + RotL64(aIngress, 30U)) + 10509115227850160786U;
            aOrbiterF = (aWandererF + RotL64(aPrevious, 51U)) + 4045915960688792066U;
            aOrbiterD = (aWandererA + RotL64(aScatter, 35U)) + 1196541286513243082U;
            aOrbiterC = (aWandererJ + RotL64(aCross, 39U)) + 15564991032722373702U;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 3U)) + RotL64(aCarry, 27U)) + 4897765238703641798U;
            aOrbiterJ = (((aWandererI + RotL64(aCross, 19U)) + RotL64(aCarry, 23U)) + 12327429514907752733U) + aOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = (aWandererC + RotL64(aPrevious, 60U)) + 6189189797708711636U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 6374267075282018852U) + aOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 1888758503831341439U;
            aOrbiterA = RotL64((aOrbiterA * 74387714918264257U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 14956857689299491800U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 14879361107223331957U;
            aOrbiterG = RotL64((aOrbiterG * 9166712966729591953U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 16086885494838105042U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 8069724185844303923U;
            aOrbiterF = RotL64((aOrbiterF * 8878470736758734353U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 10854345917959911439U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 7078313614360332089U;
            aOrbiterD = RotL64((aOrbiterD * 9864025732292844871U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 15083669236062255011U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 594879695916679116U;
            aOrbiterC = RotL64((aOrbiterC * 9852515479152735283U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 6721466068234534523U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 475816724162626782U;
            aOrbiterE = RotL64((aOrbiterE * 4799725182757588407U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 4341655358154605899U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 15477254302340298586U;
            aOrbiterJ = RotL64((aOrbiterJ * 13961520225881974201U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 10179091913200895775U) + aNonceWordK;
            aOrbiterB = (((aOrbiterB ^ aOrbiterC) ^ 6310490897546909571U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 15080621088825477613U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 13462682513035460711U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 16739138858084100385U;
            aOrbiterK = RotL64((aOrbiterK * 16386371811268298031U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 13608837667062268989U) + aOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 12902415667552110103U;
            aOrbiterH = RotL64((aOrbiterH * 16398790854093048017U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 16596211634603915761U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 6521330037475130256U;
            aOrbiterI = RotL64((aOrbiterI * 631958426544321145U), 39U);
            //
            aIngress = RotL64(aOrbiterA, 37U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 39U));
            aIngress = aIngress + (RotL64(aOrbiterE, 23U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 21U));
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 48U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aScatter, 14U) + RotL64(aOrbiterB, 6U)) + aOrbiterI);
            aWandererA = aWandererA ^ ((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterB, 35U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterC, 57U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterE, 53U)) + aOrbiterG);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterH, 60U)) + aOrbiterD) + RotL64(aCarry, 47U)) + aNonceWordE);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterB, 21U)) + aOrbiterJ) + aNonceWordH);
            aWandererK = aWandererK + ((RotL64(aCross, 41U) + aOrbiterC) + RotL64(aOrbiterH, 19U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterE, 43U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 19U) + aOrbiterE) + RotL64(aOrbiterJ, 37U)) + RotL64(aCarry, 29U)) + aWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 23U) + aOrbiterD) + RotL64(aOrbiterK, 11U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 47U) + aOrbiterI) + RotL64(aOrbiterH, 39U)) + aWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 30U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 42U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordL);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 25740U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneA[((aIndex + 26549U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23371U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((aIndex + 26526U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 6U) + RotL64(aCross, 41U)) + (RotL64(aIngress, 29U) ^ RotL64(aCarry, 53U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 21U)) + RotL64(aCarry, 47U)) + 9133751643283278896U;
            aOrbiterG = (aWandererG + RotL64(aCross, 56U)) + 8971581804375380408U;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 23U)) + 12559650383714566592U) + aNonceWordH;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 29U)) + 15753206088872859163U) + aOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = (aWandererA + RotL64(aCross, 53U)) + 7640756270450762350U;
            aOrbiterI = (aWandererI + RotL64(aIngress, 39U)) + 7340073357551376125U;
            aOrbiterB = (aWandererF + RotL64(aPrevious, 60U)) + 5270256573644196046U;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 47U)) + RotL64(aCarry, 57U)) + 3567367996479995928U;
            aOrbiterH = (aWandererE + RotL64(aCross, 5U)) + 11939634537492733738U;
            aOrbiterC = ((((aWandererJ + RotL64(aIngress, 35U)) + RotL64(aCarry, 29U)) + 7051817732424527120U) + aOrbiterAssignSaltD[((aIndex + 24U)) & S_SALT1]) + aNonceWordC;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 27U)) + 1730487669951837941U) + aNonceWordE;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 18009252467909454817U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 2361024272031696442U) ^ aOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15215151562500226027U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 15902755877642960397U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 12243517544704116184U;
            aOrbiterI = RotL64((aOrbiterI * 2576071074148141447U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 16846181962302186187U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 636121425116506681U;
            aOrbiterA = RotL64((aOrbiterA * 17075030673338779993U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 6887385655828217318U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 3705834550934775862U;
            aOrbiterC = RotL64((aOrbiterC * 11275428284929594435U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 11165142437077969438U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 6426659930331618269U) ^ aNonceWordA;
            aOrbiterJ = RotL64((aOrbiterJ * 17170640810530893705U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 12629082390899315789U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 4277510580069574724U) ^ aNonceWordF;
            aOrbiterD = RotL64((aOrbiterD * 9829125163412708305U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 13814834144170469978U) + aOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 3698381854100295826U;
            aOrbiterB = RotL64((aOrbiterB * 5126359230872258015U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 11623170635983579937U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 7247413650388803796U;
            aOrbiterH = RotL64((aOrbiterH * 3403219499465560059U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 3129755194359521145U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 4081016725582134919U) ^ aNonceWordM;
            aOrbiterE = RotL64((aOrbiterE * 11564414998539605389U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 15878346077922215753U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 2974440187796944059U;
            aOrbiterG = RotL64((aOrbiterG * 783253926537018373U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 3922344163443096356U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 9133751643283278896U;
            aOrbiterK = RotL64((aOrbiterK * 16887991698415418429U), 51U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 53U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 23U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 56U));
            aIngress = aIngress + RotL64(aOrbiterJ, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterD, 23U)) + aOrbiterA);
            aWandererC = aWandererC + ((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterB, 50U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterD, 3U)) + aOrbiterE);
            aWandererD = aWandererD + ((RotL64(aCross, 27U) + RotL64(aOrbiterK, 43U)) + aOrbiterJ);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterC, 39U)) + aOrbiterB);
            aWandererK = aWandererK + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterG, 13U)) + aOrbiterB) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterH, 47U)) + aWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 39U)) + aWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 22U) + aOrbiterG) + RotL64(aOrbiterE, 29U)) + aNonceWordP);
            aWandererF = aWandererF + ((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterG, 36U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 13U) + aOrbiterJ) + RotL64(aOrbiterC, 41U)) + aNonceWordN);
            //
            aCarry = aCarry + (RotL64(aWandererK, 28U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 60U));
            aCarry = aCarry + RotL64(aWandererE, 51U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29939U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27612U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30303U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 31068U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCarry, 36U)) ^ (RotL64(aCross, 51U) ^ RotL64(aPrevious, 19U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererD + RotL64(aCross, 48U)) + 9630214189402543339U;
            aOrbiterK = (((aWandererG + RotL64(aPrevious, 43U)) + RotL64(aCarry, 43U)) + 4072576573737526819U) + aOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = (((aWandererH + RotL64(aScatter, 53U)) + RotL64(aCarry, 27U)) + 15994787452709618869U) + aOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aIngress, 39U)) + 6403240137132259482U) + aNonceWordH;
            aOrbiterC = (aWandererK + RotL64(aCross, 11U)) + 10229266900170507720U;
            aOrbiterE = (((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 23U)) + 5025294577989748989U) + aNonceWordG;
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 46U)) + 16696461238217956883U;
            aOrbiterB = (aWandererF + RotL64(aScatter, 27U)) + 9878318855341719119U;
            aOrbiterG = (aWandererJ + RotL64(aIngress, 3U)) + 16086635438116177346U;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 35U)) + 12295437783084203730U;
            aOrbiterH = (aWandererC + RotL64(aScatter, 5U)) + 7681150419912842402U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 2639104034287637448U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 12298170009332243573U) ^ aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9397919591171238575U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 3485932317267669626U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 16569551670038752475U;
            aOrbiterC = RotL64((aOrbiterC * 8139802826402217631U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 4448490103784103954U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 14510534073046885941U;
            aOrbiterE = RotL64((aOrbiterE * 7777192047386438305U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 4286195398675733451U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 15790355933840266463U;
            aOrbiterJ = RotL64((aOrbiterJ * 13342257823027075501U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 6362891510370156055U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 15121822034579983174U) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 7268045994574844937U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 13817341015719915628U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 14113474087906143783U;
            aOrbiterG = RotL64((aOrbiterG * 12838910141533126059U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 9988301252236121106U) + aNonceWordK;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 11287477288382171758U;
            aOrbiterD = RotL64((aOrbiterD * 4979297247881426383U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 9491727010910328644U) + aNonceWordL;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 7961202721830514030U;
            aOrbiterH = RotL64((aOrbiterH * 16300364540313620767U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 10058066852293995222U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 541563830282750968U) ^ aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1516823517052019845U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 7791201128863372861U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 8334318157449352359U;
            aOrbiterK = RotL64((aOrbiterK * 2924838607279239375U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 6861081455774799715U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 9630214189402543339U;
            aOrbiterA = RotL64((aOrbiterA * 10837610668580336781U), 57U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 37U);
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterA, 6U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 37U)) + aOrbiterD) + aWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 60U) + RotL64(aOrbiterI, 6U)) + aOrbiterJ);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 41U) + aOrbiterK) + RotL64(aOrbiterF, 53U));
            aWandererK = aWandererK + (((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterB, 11U)) + RotL64(aCarry, 51U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterK, 13U)) + aOrbiterE);
            aWandererA = aWandererA + (((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterC, 39U)) + RotL64(aCarry, 41U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 50U) + RotL64(aOrbiterG, 21U)) + aOrbiterE) + aNonceWordJ);
            aWandererH = aWandererH + ((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 19U)) + aOrbiterI);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 48U)) + aOrbiterA);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterJ, 3U)) + aOrbiterH) + aNonceWordI) + aWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterF, 43U)) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererA, 34U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + RotL64(aWandererB, 56U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ aNonceWordM;
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

void TwistExpander_Softball_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xEDC0A206248C889DULL + 0x8581F0C96302A4FFULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xF9E3A9E542C33D51ULL + 0xD9BB48D41A3B0A48ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x8661BCFEAA47C1F5ULL + 0xE63BDFCEFC0905C1ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xB5F591719842F25FULL + 0xB2FEF11D5148909CULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xE0AB8E64F1DBDD0BULL + 0xE61DDB5A06EE99ACULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x9ACDD5330BDBA24BULL + 0xBE706B5FBAE9B92CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xBCCAF718A3D56F89ULL + 0x9C0CA9ED3426FF5CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xFCF6FED81BDACAA5ULL + 0xC07A844BC613E058ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xC2DD8DF1465C0D49ULL + 0xE8201C2EC98D3958ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xB319DE30F8B768E1ULL + 0xD71606037C3774D5ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xC3A72DD1446C563FULL + 0xA8120D5C29E03AFCULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x85C2F983C3F07BF5ULL + 0xAAE70D27E9A110EEULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xEB0D813626075985ULL + 0xBA745E6A7944FE7CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xA4283C5A2E4F29B9ULL + 0xD7560D26D3516E9CULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xABBBE62F6D8EDFFBULL + 0xC1B5682B2BF9B725ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xF24E42635168F855ULL + 0xBBE80CE70D7AA81EULL);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 8180U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneC[((aIndex + 6334U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 8184U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneA[((aIndex + 1278U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCarry, 53U)) ^ (RotL64(aPrevious, 4U) ^ RotL64(aCross, 21U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererC + RotL64(aIngress, 21U)) + RotL64(aCarry, 19U)) + 5568146815535263910U;
            aOrbiterK = (((aWandererG + RotL64(aScatter, 39U)) + RotL64(aCarry, 51U)) + 7736084960873834666U) + aOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = (aWandererB + RotL64(aCross, 28U)) + 1336413621817562093U;
            aOrbiterB = (((aWandererA + RotL64(aPrevious, 5U)) + RotL64(aCarry, 11U)) + 5218462026934984692U) + aNonceWordJ;
            aOrbiterG = (aWandererD + RotL64(aScatter, 47U)) + 7048890985969555935U;
            aOrbiterH = ((aWandererH + RotL64(aCross, 51U)) + 13415955213864702118U) + aNonceWordC;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 56U)) + 5657023257021528548U) + aNonceWordB;
            aOrbiterF = (aWandererE + RotL64(aPrevious, 35U)) + 14338310943137497116U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 13U)) + 12305161641833950473U) + aOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 14514226578370459131U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 12692904083266024340U) ^ aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14800805065279908839U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 11012959130001327964U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 7106471380403489078U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 515626559384817223U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 3718101961355280891U) + aOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 13364192077222322664U;
            aOrbiterF = RotL64((aOrbiterF * 1411328915372590283U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 6720867800318913440U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 14497243926965866546U;
            aOrbiterA = RotL64((aOrbiterA * 13595058589060114653U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 5789056168233262435U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 14438482587495779937U;
            aOrbiterE = RotL64((aOrbiterE * 10593535547917767263U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 313917798940179945U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 15241845511889502917U) ^ aOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16483477103771326107U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 3591957424821693032U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 1559050939014453558U) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 17933346117866604725U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 15340590914441451383U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 5538037287390050110U;
            aOrbiterK = RotL64((aOrbiterK * 4082576643144951473U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 4151270491894969214U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 263593701314144898U;
            aOrbiterG = RotL64((aOrbiterG * 10372046955804512457U), 47U);
            //
            aIngress = RotL64(aOrbiterC, 19U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + (RotL64(aOrbiterH, 37U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterA, 26U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 43U)) + aOrbiterA) + aNonceWordF);
            aWandererE = aWandererE + (((RotL64(aIngress, 26U) + aOrbiterG) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterE, 56U)) + aOrbiterH);
            aWandererH = aWandererH + ((RotL64(aCross, 47U) + RotL64(aOrbiterI, 23U)) + aOrbiterB);
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterG, 19U)) + aNonceWordL) + aWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 22U) + aOrbiterC) + RotL64(aOrbiterF, 29U)) + aWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterI, 3U)) + aOrbiterH);
            aWandererG = aWandererG + (((RotL64(aScatter, 39U) + aOrbiterK) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 51U) + aOrbiterF) + RotL64(aOrbiterE, 36U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 56U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + RotL64(aWandererD, 39U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 14236U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((aIndex + 12889U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14736U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10799U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 54U) + RotL64(aIngress, 3U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCross, 27U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererK + RotL64(aPrevious, 47U)) + 1866656689936219099U;
            aOrbiterC = (aWandererA + RotL64(aIngress, 23U)) + 2312314528139448289U;
            aOrbiterH = (((aWandererI + RotL64(aScatter, 3U)) + RotL64(aCarry, 23U)) + 3554037526469185237U) + aOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (((aWandererB + RotL64(aCross, 18U)) + 405707755060974111U) + aOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordG;
            aOrbiterA = (aWandererG + RotL64(aPrevious, 51U)) + 1862976326004007697U;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 37U)) + RotL64(aCarry, 5U)) + 12992483065443288263U;
            aOrbiterG = (aWandererF + RotL64(aScatter, 43U)) + 3793854946371595197U;
            aOrbiterK = (aWandererH + RotL64(aCross, 58U)) + 4244007978867369382U;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 11U)) + RotL64(aCarry, 39U)) + 10280867500312580308U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 472563452959164242U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 12041770406895816553U;
            aOrbiterH = RotL64((aOrbiterH * 17811798500132002631U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 6118634015704900486U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 13637107920449233307U;
            aOrbiterA = RotL64((aOrbiterA * 17712028184714868053U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 16673735670669318830U) + aNonceWordJ;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 8602681273646630496U) ^ aOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6995213887710749241U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 7683264695930369476U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 9146674871199188218U;
            aOrbiterK = RotL64((aOrbiterK * 7403427067419261981U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 3012935612827493084U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 1259789268731661945U;
            aOrbiterE = RotL64((aOrbiterE * 2372843620327050137U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 5623690455471160780U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 18355567776031865462U;
            aOrbiterB = RotL64((aOrbiterB * 9553862670107886679U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 7705134893833304792U) + aOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 4435192506444773834U;
            aOrbiterI = RotL64((aOrbiterI * 5249651218395299501U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 6204683785806409075U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 17886971535016484255U) ^ aOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6047216474762933535U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 4430578901091376829U) + aOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 607557685798141547U;
            aOrbiterC = RotL64((aOrbiterC * 12342665567201483107U), 5U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterI, 37U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 34U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterB, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterE, 5U)) + RotL64(aCarry, 39U)) + aWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 13U) + aOrbiterE) + RotL64(aOrbiterG, 24U));
            aWandererK = aWandererK + ((RotL64(aCross, 4U) + RotL64(aOrbiterE, 57U)) + aOrbiterC);
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 43U)) + aOrbiterK) + aNonceWordM) + aWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 39U) + RotL64(aOrbiterB, 11U)) + aOrbiterH) + RotL64(aCarry, 3U)) + aNonceWordO);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 43U) + aOrbiterK) + RotL64(aOrbiterH, 51U));
            aWandererG = aWandererG + ((RotL64(aCross, 58U) + RotL64(aOrbiterJ, 19U)) + aOrbiterH);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 53U) + aOrbiterI) + RotL64(aOrbiterC, 36U)) + aNonceWordF);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 29U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 26U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordM);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 18176U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18298U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18053U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((aIndex + 20369U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aIngress, 51U)) + (RotL64(aCarry, 37U) ^ RotL64(aPrevious, 18U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (((aWandererE + RotL64(aIngress, 35U)) + RotL64(aCarry, 19U)) + 11480359716598965890U) + aNonceWordJ;
            aOrbiterA = ((aWandererD + RotL64(aCross, 30U)) + RotL64(aCarry, 43U)) + 15431182525482873419U;
            aOrbiterD = (aWandererK + RotL64(aScatter, 47U)) + 11360504974812776707U;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 5U)) + 9292576416573382769U) + aNonceWordN;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 11U)) + 1549257414531028975U) + aOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = ((aWandererA + RotL64(aScatter, 60U)) + 5347769463033129317U) + aOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aCross, 23U)) + 17019199177478377234U;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 39U)) + RotL64(aCarry, 57U)) + 16558106007323125094U;
            aOrbiterE = (aWandererJ + RotL64(aIngress, 19U)) + 3976182233825939422U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 2889047161195954395U) + aNonceWordD;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 2241831345026962605U;
            aOrbiterD = RotL64((aOrbiterD * 5757458560979927857U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 12850802412140579294U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 13541744735436450160U;
            aOrbiterF = RotL64((aOrbiterF * 906089290000537439U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 2085863085516538212U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 2969034221711544086U;
            aOrbiterB = RotL64((aOrbiterB * 7768528124408400403U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 6482666944512391472U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 16969153556875844613U;
            aOrbiterA = RotL64((aOrbiterA * 9483462388353216219U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 5161314086757363678U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 7150282484670673211U;
            aOrbiterK = RotL64((aOrbiterK * 8522427002337918663U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 5465304381272305847U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterH) ^ 2344610773390354017U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 17010258514288089191U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 8335906578006588582U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 13668796013474193793U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8228000547141147777U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 9663362594301419686U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 3683773739120343413U;
            aOrbiterJ = RotL64((aOrbiterJ * 8319320803406104749U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 2538583190438044942U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 4454069062219406996U;
            aOrbiterE = RotL64((aOrbiterE * 16329554225309389599U), 39U);
            //
            aIngress = RotL64(aOrbiterH, 50U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterE, 4U)) + aWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 24U) + RotL64(aOrbiterD, 41U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aPrevious, 51U) + aOrbiterK) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 53U)) + aOrbiterH);
            aWandererC = aWandererC + (((RotL64(aCross, 39U) + RotL64(aOrbiterK, 10U)) + aOrbiterJ) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterJ, 57U)) + aOrbiterD) + aNonceWordL);
            aWandererB = aWandererB + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 47U)) + aOrbiterA) + aWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterF, 23U)) + aOrbiterB);
            aWandererD = aWandererD + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterJ, 19U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (RotL64(aWandererE, 36U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + RotL64(aWandererB, 41U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordN;
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 26570U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneB[((aIndex + 30037U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27577U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 29526U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCross, 56U)) + (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 23U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererA + RotL64(aCross, 19U)) + RotL64(aCarry, 51U)) + 18319689184146942855U;
            aOrbiterD = (((aWandererJ + RotL64(aPrevious, 56U)) + RotL64(aCarry, 21U)) + 8041304130090501019U) + aOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (aWandererC + RotL64(aScatter, 41U)) + 11347064191990897738U;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 23U)) + RotL64(aCarry, 41U)) + 15242243470024447468U;
            aOrbiterH = (aWandererE + RotL64(aCross, 51U)) + 10619749107163611105U;
            aOrbiterG = (aWandererI + RotL64(aIngress, 13U)) + 14795614276221947128U;
            aOrbiterF = (aWandererF + RotL64(aScatter, 29U)) + 1578095288886372393U;
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 46U)) + 13593906305770501684U) + aNonceWordA;
            aOrbiterI = ((aWandererH + RotL64(aCross, 37U)) + 8919815528334599172U) + aOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 17425548324720065145U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 11125018338392347335U) ^ aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4377887040461528587U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 3779189180734244399U) + aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 10958224663276134041U;
            aOrbiterH = RotL64((aOrbiterH * 6206963519509783781U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 4317305352561612995U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 4891139433808505355U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11507024985663120317U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 5166074784835930965U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 10080890270621589202U;
            aOrbiterE = RotL64((aOrbiterE * 13170894418184288695U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 4501071771615514619U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 6486573807774431753U;
            aOrbiterC = RotL64((aOrbiterC * 324029625116648669U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 15714881857668975753U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 3506619392820235900U;
            aOrbiterG = RotL64((aOrbiterG * 5707033870161224499U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 5295711072762443783U) + aNonceWordE;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 11192836530396570648U) ^ aNonceWordG;
            aOrbiterA = RotL64((aOrbiterA * 4361810118382207039U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 7993389678399774574U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 12551394763541226695U;
            aOrbiterI = RotL64((aOrbiterI * 11903486656172026403U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 11553674370322129668U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterF) ^ 4459881583199320245U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterD = RotL64((aOrbiterD * 2805857426321555685U), 19U);
            //
            aIngress = RotL64(aOrbiterF, 19U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + (RotL64(aOrbiterA, 30U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterB, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aCross, 43U) + RotL64(aOrbiterH, 57U)) + aOrbiterG);
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 23U) + aOrbiterE) + RotL64(aOrbiterF, 47U)) + aNonceWordO) + aWandererUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 30U) + RotL64(aOrbiterC, 19U)) + aOrbiterG) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 28U)) + aOrbiterF);
            aWandererA = aWandererA + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 43U)) + aOrbiterI);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterC, 35U)) + aOrbiterE);
            aWandererB = aWandererB + ((((RotL64(aCross, 51U) + aOrbiterA) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 47U)) + aWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 4U) + RotL64(aOrbiterE, 39U)) + aOrbiterA);
            aWandererG = aWandererG + ((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 12U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 24U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordC);
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

void TwistExpander_Softball_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xEBCC59EA5DCFAE8BULL + 0xC2DF4C2AD996F3D0ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xFBE8BD5BDFC2D5ADULL + 0xF1424918E0C188D8ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC3C6DB61A7D713ABULL + 0xF02455C97D3A9009ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xB72ED6CAFA5F1DF1ULL + 0xC8471E5AC11E961BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x959B460D9F54D747ULL + 0x8CA54CC806F92594ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xDE93914DF093BCF9ULL + 0x8E3CC37C7CDBEE58ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xD9D469DA17A37BF9ULL + 0xE7D64F063C6688E6ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF8C24EAE127189DBULL + 0xC2DADE349D2E1D2FULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xED968CB9B2218C9DULL + 0x975522DD84144B21ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x97A590B81FE2F23DULL + 0xD574F032C2D024C3ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xB1CEBC8F128EA03BULL + 0xF5E6651133849380ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xABC0E573B1DC8ABBULL + 0xFC5223053D6A5318ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x8E2B817C5357309FULL + 0xF0E15C01E211A284ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x875D712C2BDA311FULL + 0x95967F0CBB11C1CFULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xBBE98FBA4BEE68E9ULL + 0xE74FCDC2F51AB0E3ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xFA9DAF04A63D3947ULL + 0xCBFA327925612769ULL);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 6320U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1373U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8050U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneA[((aIndex + 3164U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCross, 39U)) + (RotL64(aPrevious, 22U) ^ RotL64(aCarry, 5U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (((aWandererI + RotL64(aPrevious, 47U)) + RotL64(aCarry, 57U)) + 6381335981879993247U) + aOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aScatter, 13U)) + 15595429101600023172U) + aNonceWordA;
            aOrbiterH = ((((aWandererF + RotL64(aCross, 29U)) + RotL64(aCarry, 21U)) + 5449234297249826461U) + aOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordF;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 58U)) + 11213734849329731168U) + aNonceWordI;
            aOrbiterD = ((aWandererH + RotL64(aScatter, 21U)) + RotL64(aCarry, 39U)) + 16438473952464514248U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 7357872882115186976U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 394402075160738643U) ^ aNonceWordH;
            aOrbiterH = RotL64((aOrbiterH * 11961225338735982661U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 11112941985410283532U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 14955125011182736212U;
            aOrbiterE = RotL64((aOrbiterE * 10711684773326395603U), 3U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterH) + 14770727009821304070U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordK;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 11286366598129204910U) ^ aOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15884310771003021989U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 7358400908565425780U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 15635109923749114761U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12415152149408700329U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 13826842523738623579U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 1072811298828325231U) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 9662800288646215083U), 39U);
            //
            aIngress = RotL64(aOrbiterC, 57U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterF, 21U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 42U) + aOrbiterE) + RotL64(aOrbiterH, 39U)) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterE, 60U)) + aWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 5U)) + aOrbiterC) + RotL64(aCarry, 19U)) + aWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterD, 51U)) + aOrbiterE);
            aWandererH = aWandererH + (((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterD, 23U)) + aNonceWordG);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (RotL64(aWandererH, 52U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 39U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9163U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneD[((aIndex + 11697U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12382U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((aIndex + 8328U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 36U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 21U) ^ RotL64(aIngress, 51U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 24U)) + 17264605017518259932U) + aNonceWordA;
            aOrbiterF = ((((aWandererJ + RotL64(aCross, 51U)) + RotL64(aCarry, 51U)) + 15209184354580778643U) + aOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1]) + aNonceWordC;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 41U)) + RotL64(aCarry, 3U)) + 3299527965014731384U;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 5U)) + RotL64(aCarry, 39U)) + 16293096431816127821U;
            aOrbiterB = (((aWandererG + RotL64(aPrevious, 13U)) + 11031983436878828337U) + aOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordG;
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 9188018632448236358U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 13420816400363406556U) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 10958221259662190519U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 2485063384097917101U) + aOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 3089135816938128264U;
            aOrbiterB = RotL64((aOrbiterB * 8813152992957361153U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 10730544971770435788U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 10431767565618874806U) ^ aNonceWordE;
            aOrbiterE = RotL64((aOrbiterE * 4723078464590561545U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 14883796491656899074U) + aNonceWordI;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 13465877783538483706U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14311686051108108503U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 13322163435314643713U) + aOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 3307316600284371955U) ^ aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12337846092069506365U), 43U);
            //
            aIngress = RotL64(aOrbiterE, 3U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + RotL64(aOrbiterH, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 53U) + aOrbiterB) + RotL64(aOrbiterE, 54U));
            aWandererJ = aWandererJ + (((((RotL64(aIngress, 24U) + aOrbiterF) + RotL64(aOrbiterE, 43U)) + RotL64(aCarry, 5U)) + aNonceWordK) + aWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 39U) + aOrbiterH) + RotL64(aOrbiterA, 13U));
            aWandererE = aWandererE + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 29U)) + aOrbiterA) + RotL64(aCarry, 21U)) + aWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterE, 21U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (RotL64(aWandererG, 54U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 29U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordP);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 20279U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23224U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 22148U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 21801U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCross, 23U)) + (RotL64(aCarry, 37U) ^ RotL64(aIngress, 50U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 35U)) + 1364174714924216027U) + aNonceWordA;
            aOrbiterC = (((aWandererA + RotL64(aIngress, 13U)) + RotL64(aCarry, 51U)) + 13561796874229506613U) + aOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aCross, 24U)) + RotL64(aCarry, 27U)) + 11845572344206238305U;
            aOrbiterG = (((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 3U)) + 15762708240326773763U) + aOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aCross, 43U)) + 1157119665207900473U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 6823546624372055260U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterI) ^ 14465564210523945121U) ^ aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterJ = RotL64((aOrbiterJ * 10957323253786161255U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 10667464548080807531U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 13445737493224316575U;
            aOrbiterC = RotL64((aOrbiterC * 12137295000900795711U), 27U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterG) + 3009837893785957665U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordO;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 2886920524111083752U;
            aOrbiterI = RotL64((aOrbiterI * 15308180928967762543U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 10886177449328249656U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 15067759884678100433U;
            aOrbiterG = RotL64((aOrbiterG * 5724566815989860041U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 18307930462682331536U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 8791864377579255801U;
            aOrbiterA = RotL64((aOrbiterA * 9265158882471421767U), 19U);
            //
            aIngress = RotL64(aOrbiterI, 57U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterI, 13U));
            aWandererE = aWandererE + (((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterJ, 53U)) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterG, 35U)) + aOrbiterJ) + aWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aIngress, 58U) + RotL64(aOrbiterA, 5U)) + aOrbiterG) + RotL64(aCarry, 3U)) + aWandererUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterI, 44U)) + aOrbiterG) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererE, 48U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 25293U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28104U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31127U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 24864U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 51U)) ^ (RotL64(aCarry, 24U) + RotL64(aPrevious, 39U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (((aWandererI + RotL64(aCross, 27U)) + 18180797995100240808U) + aOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1]) + aNonceWordM;
            aOrbiterD = (((aWandererK + RotL64(aIngress, 19U)) + RotL64(aCarry, 43U)) + 6585906608223552885U) + aNonceWordG;
            aOrbiterJ = ((((aWandererB + RotL64(aPrevious, 36U)) + RotL64(aCarry, 11U)) + 14088708930575939855U) + aOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordF;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 11U)) + RotL64(aCarry, 57U)) + 468974153311516044U;
            aOrbiterI = (aWandererF + RotL64(aCross, 3U)) + 12481951025619894110U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 17227987923860711763U) + aNonceWordK;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 4373962756657477139U) ^ aOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6069068316234356267U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 2077576476565420951U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 17435011300234663764U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8910133867294004711U), 11U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterJ) + 4118039398293246896U) + aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1]) + aNonceWordP;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 13724716599855216683U) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 17556333902751079677U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 12391461204689596339U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 9900605191533799627U;
            aOrbiterD = RotL64((aOrbiterD * 13553565332531046301U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 972946858824366125U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 17247681919694541215U;
            aOrbiterI = RotL64((aOrbiterI * 2974639094630445643U), 47U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterB, 23U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + RotL64(aOrbiterD, 46U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aScatter, 41U) + RotL64(aOrbiterJ, 52U)) + aOrbiterG);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 30U) + RotL64(aOrbiterI, 5U)) + aOrbiterG) + aNonceWordB);
            aWandererH = aWandererH + ((((RotL64(aCross, 19U) + RotL64(aOrbiterI, 43U)) + aOrbiterB) + RotL64(aCarry, 11U)) + aWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterD, 13U)) + aOrbiterB) + aWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 51U) + RotL64(aOrbiterG, 27U)) + aOrbiterB) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = aCarry ^ aNonceWordC;
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

void TwistExpander_Softball_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xA2DEDE3551ED711FULL + 0xCB7CCDCD1AA9264FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xB5144673DE3E60F9ULL + 0xA7740E3F79C9AABBULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xC97C26BD4E5F2681ULL + 0xEEECAADD6BC4DE4DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xE62308FCC7A74EA3ULL + 0xDF8BFACC6E22B5EDULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x99196E995510B1D1ULL + 0xA36CE3BE7560CA22ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xF34518679621158DULL + 0x83A06D48A08E6A9EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xE5E754E2C70C0A77ULL + 0x9152AC1422DB978DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE93DEC8277B6DA93ULL + 0xF67DFB454358E5E4ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xB58927EF8A808F3FULL + 0xD56A56AC7C17009CULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xD84FE93071F00259ULL + 0xCC0D664E1385F7C2ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xC03B3EF271BD1CFDULL + 0xE867AD657EEDA012ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xE1AB71B6BC9028B3ULL + 0x962D45B5CF4ACA0CULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x994A6AC91B0C8017ULL + 0xE0D0AB881A1E34B2ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xA162EC0DADBFB43DULL + 0xDF4B62EF2C54E50DULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xF47C97B3ACA46281ULL + 0xD07F5FDCFDD16AEDULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xE0D193BEDD3BE375ULL + 0xE3D26B09D78C97FFULL);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 6367U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((aIndex + 1722U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2969U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 3622U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aIngress, 51U)) + (RotL64(aCross, 36U) + RotL64(aPrevious, 23U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 50U)) + RotL64(aCarry, 57U)) + 16183871922837164759U;
            aOrbiterC = ((aWandererC + RotL64(aCross, 57U)) + 7002058258090219055U) + aNonceWordN;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 3U)) + 5650868611888303705U) + aOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aScatter, 41U)) + 11899839660943876690U;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 23U)) + RotL64(aCarry, 23U)) + 15349649504488111111U;
            aOrbiterI = (((aWandererI + RotL64(aScatter, 35U)) + RotL64(aCarry, 41U)) + 14060149569086744970U) + aNonceWordB;
            aOrbiterB = (((aWandererH + RotL64(aCross, 13U)) + 12920917574225030112U) + aOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordK;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 2831994965175330135U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 18312543585028439192U;
            aOrbiterF = RotL64((aOrbiterF * 11618182708195744321U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 11657562205118394239U) + aOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 10850792819281246052U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10663100544207879337U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 17810371216216125323U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterC) ^ 7963413941144223128U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 534217972450595401U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 5498715358793875584U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 9256727548911651373U) ^ aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10498848323914000989U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 17246360111302191699U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 18309978718113983369U;
            aOrbiterK = RotL64((aOrbiterK * 18267472694666221077U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 3100998994319502921U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 8129301860291235970U;
            aOrbiterG = RotL64((aOrbiterG * 17847033539279176187U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 1889641029473279114U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 16538494307002917945U;
            aOrbiterC = RotL64((aOrbiterC * 8081488217920885783U), 11U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterI, 21U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterF, 58U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterF, 53U));
            aWandererD = aWandererD ^ ((((RotL64(aCross, 37U) + aOrbiterE) + RotL64(aOrbiterG, 13U)) + aNonceWordG) + aWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aIngress, 20U) + aOrbiterI) + RotL64(aOrbiterG, 60U)) + RotL64(aCarry, 11U)) + aNonceWordA);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 41U)) + aOrbiterI) + aNonceWordC);
            aWandererE = aWandererE + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterG, 35U)) + aOrbiterF);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 5U)) + aOrbiterC) + aWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 47U) + aOrbiterF) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 56U));
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 43U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ aNonceWordJ;
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 15371U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((aIndex + 10951U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12556U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 12683U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 54U)) ^ (RotL64(aIngress, 23U) + RotL64(aCross, 35U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((((aWandererF + RotL64(aCross, 26U)) + RotL64(aCarry, 29U)) + 12206125048349568300U) + aOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordI;
            aOrbiterI = (aWandererB + RotL64(aScatter, 19U)) + 5843520589343188818U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 5U)) + RotL64(aCarry, 41U)) + 12195046124287121687U;
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 13U)) + RotL64(aCarry, 53U)) + 16769779119214020640U;
            aOrbiterJ = (aWandererA + RotL64(aIngress, 35U)) + 5257603646260695833U;
            aOrbiterD = (aWandererG + RotL64(aCross, 43U)) + 8523523946234886745U;
            aOrbiterC = (((aWandererC + RotL64(aPrevious, 57U)) + 7316024684200084096U) + aOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1]) + aNonceWordF;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 11996978575084115207U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 15491711479085513628U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15136690392026011819U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 6036648530996821484U) + aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 926323222234121863U;
            aOrbiterH = RotL64((aOrbiterH * 6639661141258803779U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 2700323841295743492U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 5852273765810284935U;
            aOrbiterF = RotL64((aOrbiterF * 16665696735016345215U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 11697397483133538067U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 17777142964957007194U) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 6338967222543284999U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 10892176201151170298U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 11759700374509499684U) ^ aNonceWordL;
            aOrbiterJ = RotL64((aOrbiterJ * 14247697264744736081U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 11343756773329590643U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 15785048929757652350U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17208103574389502597U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 7508839228498497238U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 13088508510402094665U) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 15730279447009669103U), 13U);
            //
            aIngress = RotL64(aOrbiterI, 50U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterH, 21U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterF, 10U)) + aOrbiterI);
            aWandererF = aWandererF + ((RotL64(aPrevious, 37U) + aOrbiterC) + RotL64(aOrbiterK, 41U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterJ, 21U));
            aWandererC = aWandererC + ((((RotL64(aIngress, 26U) + aOrbiterF) + RotL64(aOrbiterJ, 47U)) + RotL64(aCarry, 53U)) + aNonceWordE);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterH, 53U)) + aOrbiterD);
            aWandererG = aWandererG + ((((RotL64(aCross, 19U) + RotL64(aOrbiterC, 35U)) + aOrbiterH) + RotL64(aCarry, 11U)) + aWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 5U) + aOrbiterC) + RotL64(aOrbiterJ, 27U)) + aWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 28U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ aNonceWordD;
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 17833U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24185U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16563U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((aIndex + 17505U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 21U)) ^ (RotL64(aIngress, 54U) + RotL64(aCarry, 39U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererG + RotL64(aScatter, 57U)) + 14008824488073394623U) + aNonceWordD;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 3U)) + RotL64(aCarry, 29U)) + 13317978415866411468U;
            aOrbiterH = ((aWandererH + RotL64(aIngress, 11U)) + RotL64(aCarry, 13U)) + 13209180141897453900U;
            aOrbiterE = (aWandererA + RotL64(aCross, 39U)) + 11870521586865233578U;
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 50U)) + 8052156380448047385U) + aOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = (aWandererK + RotL64(aIngress, 27U)) + 12158131176743680605U;
            aOrbiterC = (((aWandererI + RotL64(aCross, 21U)) + RotL64(aCarry, 53U)) + 14674467487607719347U) + aOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 18055496790566231147U) + aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 3838105585041578784U;
            aOrbiterH = RotL64((aOrbiterH * 1075709247574580091U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 2839568255183054418U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 11933612922864258179U;
            aOrbiterI = RotL64((aOrbiterI * 7571964469321160347U), 29U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterE) + 6289849094151630580U) + aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1]) + aNonceWordA;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 2640344350528492271U;
            aOrbiterA = RotL64((aOrbiterA * 16197726750829369365U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 16306175266267657791U) + aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 3339898380394883600U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7105436590182982373U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 15017076663742800002U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 8973064296077602496U) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 9309462227233615761U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 17580319233338139859U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 14063208878807603874U;
            aOrbiterK = RotL64((aOrbiterK * 16601475239075164585U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 13326130855721009942U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 12843186026737544416U;
            aOrbiterC = RotL64((aOrbiterC * 4975848122837321619U), 11U);
            //
            aIngress = RotL64(aOrbiterE, 4U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterI, 35U)) + aWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aIngress, 51U) + RotL64(aOrbiterH, 53U)) + aOrbiterI) + RotL64(aCarry, 57U)) + aNonceWordJ);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 26U) + aOrbiterH) + RotL64(aOrbiterK, 60U)) + aWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterH, 5U)) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterF, 47U)) + aOrbiterK);
            aWandererI = aWandererI + (((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 41U)) + aOrbiterI) + aNonceWordH);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterF, 19U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 44U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + RotL64(aWandererJ, 39U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 29178U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31156U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32136U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneD[((aIndex + 32279U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCross, 6U)) ^ (RotL64(aCarry, 47U) + RotL64(aIngress, 19U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 37U)) + 13880995121909552664U;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 50U)) + RotL64(aCarry, 5U)) + 14534942818069300546U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 21U)) + 17745973100886007133U) + aNonceWordG;
            aOrbiterG = (aWandererH + RotL64(aScatter, 57U)) + 2249805580771946872U;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 35U)) + 4460116116396439410U;
            aOrbiterB = (((aWandererA + RotL64(aPrevious, 41U)) + 3378683994078106878U) + aOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordP;
            aOrbiterH = (((aWandererC + RotL64(aScatter, 13U)) + RotL64(aCarry, 21U)) + 3992996501048809123U) + aOrbiterAssignSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 12057768808864451929U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 4115362079047921130U;
            aOrbiterD = RotL64((aOrbiterD * 12263015903331031345U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 15297384955502206698U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 17623548383481905636U;
            aOrbiterB = RotL64((aOrbiterB * 7487278217901483685U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 3559213898000162417U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 12311605719074507335U;
            aOrbiterC = RotL64((aOrbiterC * 3982199462062847697U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 14807313864347885885U) + aOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 11222085523291581822U;
            aOrbiterJ = RotL64((aOrbiterJ * 12580941911587215653U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 916681229436292462U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 2441350114032314686U;
            aOrbiterA = RotL64((aOrbiterA * 7336079498999018067U), 27U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterD) + 7361470539894653271U) + aOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1]) + aNonceWordA;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 12153585147213579808U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3040327545467672961U), 21U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterB) + 13566300726101613579U) + aOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1]) + aNonceWordM;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 14875254144748509128U;
            aOrbiterH = RotL64((aOrbiterH * 13699179902908972403U), 5U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterA, 57U);
            aIngress = aIngress + (RotL64(aOrbiterG, 50U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 43U) + aOrbiterH) + RotL64(aOrbiterC, 21U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 11U)) + aOrbiterG) + RotL64(aCarry, 11U)) + aWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 29U)) + aOrbiterG) + aWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 58U) + RotL64(aOrbiterB, 53U)) + aOrbiterH) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterA, 35U)) + aNonceWordD);
            aWandererC = aWandererC + ((RotL64(aScatter, 51U) + aOrbiterB) + RotL64(aOrbiterJ, 3U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterC, 44U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererC, 34U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordH;
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

void TwistExpander_Softball_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xE113530210B653ABULL + 0xDBE691A7AA8B5C33ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xEBF989923B6D5B01ULL + 0xC348CD0390684BAFULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x8F819D456636135DULL + 0xDB894BF0ABA28A35ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x8DC7CE08A1E6EC73ULL + 0xDB03A138EABD9074ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xAA9D6DC648165695ULL + 0xC2926C34E3D97511ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x853085D54DFB6EE9ULL + 0xAD61A29587389B75ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xEB84551D3F19AB65ULL + 0xB3B21379DBFFD5ABULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xC62F9613A9CB52F1ULL + 0xE4342FFA722F315BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x9E3CB9B2BBE2EB7FULL + 0x8BF3FD251A5D6ABEULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xCB53CC4940DA7F4FULL + 0xA557FA8EEA6F0623ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xF20E0CE7B9828A07ULL + 0x91CEBA159AD368CDULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xE9C8682896AAEC99ULL + 0xC2246D60D469EDD6ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xDA8C40477B00987DULL + 0xA930760D5FFA55DAULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xADC9FBAD681B45B7ULL + 0x9FF43CBAECA914FDULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xA70044E8FD405449ULL + 0xDB42B9BBB9FC5303ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xC664BA548E993753ULL + 0xFE2AA98EAF7C2A5EULL);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 1416U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 3897U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 6360U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 3773U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aPrevious, 5U)) + (RotL64(aIngress, 51U) ^ RotL64(aCarry, 38U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 44U)) + RotL64(aCarry, 57U)) + 10805654776556844351U;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 57U)) + 582794182442795335U) + aOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aIngress, 21U)) + 2858343650974681068U) + aOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = ((aWandererF + RotL64(aScatter, 13U)) + RotL64(aCarry, 41U)) + 8189584049022064284U;
            aOrbiterB = (((aWandererE + RotL64(aIngress, 29U)) + RotL64(aCarry, 19U)) + 1565100751996962893U) + aNonceWordB;
            aOrbiterK = (aWandererK + RotL64(aScatter, 3U)) + 8062028016947611891U;
            aOrbiterF = (aWandererI + RotL64(aPrevious, 51U)) + 8280504280578451745U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 11326869194491655350U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 1671695656567777163U;
            aOrbiterE = RotL64((aOrbiterE * 7511554500524257921U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 2349843105293943452U) + aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 13015545152052004254U;
            aOrbiterB = RotL64((aOrbiterB * 1316662811685429983U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 16703354404749291869U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 8713231044374305801U;
            aOrbiterK = RotL64((aOrbiterK * 9242480982197688625U), 47U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterK) + 11118401674497783533U) + aOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1]) + aNonceWordF;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 14857556493734710364U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3452566050389715195U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 12953419670951660965U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 12666121730825089017U) ^ aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14049925256934142519U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 11075249639473053423U) + aNonceWordJ;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 9374217688244187867U;
            aOrbiterD = RotL64((aOrbiterD * 5261156325627117877U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 17608340953291367867U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 13159437499327086340U) ^ aNonceWordA;
            aOrbiterG = RotL64((aOrbiterG * 4882100944453534805U), 27U);
            //
            aIngress = RotL64(aOrbiterJ, 35U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + RotL64(aOrbiterD, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 57U) + aOrbiterF) + RotL64(aOrbiterD, 57U)) + aWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterD, 37U)) + aOrbiterE);
            aWandererF = aWandererF + (((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 20U)) + aOrbiterG) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 30U) + RotL64(aOrbiterB, 11U)) + aOrbiterF) + aNonceWordE);
            aWandererJ = aWandererJ + ((RotL64(aCross, 51U) + RotL64(aOrbiterB, 5U)) + aOrbiterJ);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterB, 29U)) + aOrbiterG) + aNonceWordM);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 47U)) + aOrbiterK) + RotL64(aCarry, 51U)) + aWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 56U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 5U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 9521U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneD[((aIndex + 13441U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 9500U)) & S_BLOCK1], 40U) ^ RotL64(aWorkLaneB[((aIndex + 10308U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 52U) + RotL64(aCarry, 5U)) ^ (RotL64(aCross, 23U) + RotL64(aIngress, 39U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (((aWandererB + RotL64(aIngress, 13U)) + 17470880031634374199U) + aOrbiterAssignSaltF[((aIndex + 20U)) & S_SALT1]) + aNonceWordM;
            aOrbiterC = (aWandererJ + RotL64(aCross, 27U)) + 757565846006937746U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 35U)) + 9419282475801345674U;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 35U)) + 2014248014107898196U) + aNonceWordI;
            aOrbiterJ = (aWandererK + RotL64(aCross, 51U)) + 15113928519446490441U;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 20U)) + RotL64(aCarry, 21U)) + 7346126964886259935U;
            aOrbiterK = (((aWandererG + RotL64(aPrevious, 41U)) + RotL64(aCarry, 53U)) + 5594123113093162359U) + aOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 5659237263369402005U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 11565709683423969703U;
            aOrbiterI = RotL64((aOrbiterI * 16731289017588574671U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 16782863743534856287U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 13499100900072115907U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5567729598873214433U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 11414447651044205242U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 7545993795121430538U) ^ aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10758488381206257261U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 11778229237616454988U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 2544793391976514665U;
            aOrbiterC = RotL64((aOrbiterC * 4021060413798523299U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 9972156716619459164U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 17651030383827445664U;
            aOrbiterJ = RotL64((aOrbiterJ * 6742914240706775487U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 17439147296849134543U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 10021926927948343656U;
            aOrbiterD = RotL64((aOrbiterD * 18139540407315440909U), 35U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterB) + 9309867875882669289U) + aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1]) + aNonceWordD;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 14951424455944346337U) ^ aNonceWordG;
            aOrbiterK = RotL64((aOrbiterK * 10569523948169951309U), 41U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterJ, 20U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterJ, 19U)) + RotL64(aCarry, 3U)) + aWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 53U) + aOrbiterI) + RotL64(aOrbiterK, 29U));
            aWandererK = aWandererK + (((RotL64(aScatter, 39U) + RotL64(aOrbiterC, 3U)) + aOrbiterF) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 60U) + aOrbiterF) + RotL64(aOrbiterB, 48U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 11U) + aOrbiterJ) + RotL64(aOrbiterK, 13U)) + aNonceWordK) + aWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 35U)) + aOrbiterC);
            aWandererG = aWandererG + ((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterD, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 52U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordK;
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 18810U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((aIndex + 21291U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16438U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 19794U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aIngress, 43U)) ^ (RotL64(aPrevious, 60U) ^ RotL64(aCarry, 11U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererE + RotL64(aPrevious, 47U)) + 1708250618750199233U;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 35U)) + 12009147777553691142U;
            aOrbiterG = ((aWandererD + RotL64(aCross, 5U)) + 8393982703399156592U) + aOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aScatter, 13U)) + 3247327098356831221U;
            aOrbiterH = ((((aWandererJ + RotL64(aCross, 34U)) + RotL64(aCarry, 57U)) + 3403590155376353737U) + aOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordE;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 21U)) + RotL64(aCarry, 19U)) + 18197244558104735044U;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 27U)) + 3096253642040701606U) + aNonceWordF;
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 8012692688785412179U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 17531946907545680745U;
            aOrbiterG = RotL64((aOrbiterG * 16510602981731506381U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 17687695944270225817U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 16147773866007628769U;
            aOrbiterK = RotL64((aOrbiterK * 16926442582711557877U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 18244641303026196497U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 8839160526348897457U;
            aOrbiterD = RotL64((aOrbiterD * 14268021129087663397U), 41U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterH) + 10599266240854068246U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordL;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 2056723540756216155U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13311591601230386375U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 4629354220460621284U) + aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 9505955649473204942U;
            aOrbiterH = RotL64((aOrbiterH * 17775391885312236187U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 17078153810088721310U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterG) ^ 9470436761716263000U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 5431855497250357229U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 3305863413630104742U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 14377172434239576161U;
            aOrbiterF = RotL64((aOrbiterF * 6880176890091033423U), 13U);
            //
            aIngress = RotL64(aOrbiterA, 57U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterD, 21U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterA, 34U)) + aOrbiterE) + RotL64(aCarry, 3U)) + aNonceWordB);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterK, 11U)) + aOrbiterE);
            aWandererA = aWandererA + ((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterE, 51U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterA, 57U)) + aWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aIngress, 18U) + RotL64(aOrbiterF, 27U)) + aOrbiterH) + RotL64(aCarry, 39U)) + aWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterD, 3U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 50U));
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 11U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31241U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26249U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31387U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 31949U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 37U) + RotL64(aPrevious, 5U)) + (RotL64(aIngress, 22U) ^ RotL64(aCarry, 57U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (((aWandererF + RotL64(aIngress, 57U)) + RotL64(aCarry, 35U)) + 2168513956284366370U) + aNonceWordF;
            aOrbiterF = (aWandererD + RotL64(aScatter, 13U)) + 10290361969974613111U;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 51U)) + 15673836275828498050U;
            aOrbiterJ = (aWandererG + RotL64(aCross, 3U)) + 16600540024145812236U;
            aOrbiterH = (((aWandererJ + RotL64(aScatter, 19U)) + RotL64(aCarry, 57U)) + 9428052101528111892U) + aOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = ((aWandererH + RotL64(aCross, 44U)) + RotL64(aCarry, 19U)) + 12763657928312763377U;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 35U)) + 10751286982008662485U) + aOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 1708230173038057979U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 4011389705422783816U) ^ aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11692237130784795961U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 11704428328093077714U) + aNonceWordP;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 2055336619674699284U;
            aOrbiterC = RotL64((aOrbiterC * 6374289210096410907U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 1870865272102705804U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 3574214263751923179U;
            aOrbiterF = RotL64((aOrbiterF * 13132083406834413563U), 51U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterJ) + 984611970726966186U) + aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1]) + aNonceWordO;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 15207945449947643672U) ^ aOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9539470161576639981U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 4181398506373973169U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 15222345431506025949U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6925143692628659467U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 15023513452326240962U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 14965669361708810699U;
            aOrbiterJ = RotL64((aOrbiterJ * 587008860996713147U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 7985755518735406360U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 225592097619240187U;
            aOrbiterI = RotL64((aOrbiterI * 2313509354133400439U), 35U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterA, 19U);
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 54U) + RotL64(aOrbiterG, 57U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((RotL64(aCross, 13U) + aOrbiterJ) + RotL64(aOrbiterC, 42U)) + aNonceWordC);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 11U)) + aOrbiterI) + aWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 27U) + aOrbiterG) + RotL64(aOrbiterH, 21U)) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 37U) + aOrbiterA) + RotL64(aOrbiterC, 35U)) + aWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 21U) + RotL64(aOrbiterA, 5U)) + aOrbiterI) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterF, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 44U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + RotL64(aWandererH, 39U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordI;
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

void TwistExpander_Softball_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x9D4A04FEDDA4F7A9ULL + 0xF76FBD045DF019B4ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xE616F2F94F423A29ULL + 0xEC2317FEE9F06A30ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x83AEDF3176BBD4E5ULL + 0x994D4CB4E441EBC8ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x936D56C8AF31CB65ULL + 0xB28B1143FA91C07DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xFB144EC4A91FBE1FULL + 0xA38FA1AB685AFF98ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x9469FB5CC146DDB3ULL + 0x95AC42D20A57E279ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xEAA58A7670D5B651ULL + 0xF697A17B503C84A3ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xBA36C9450ACF39D1ULL + 0xD443AA91D4652230ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x927F4C4A22C92955ULL + 0xC41059CF5CA911C0ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xC3A9C85586C41DCDULL + 0xFAC2F26AEA5C04F7ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xDC8D70786A90D0B5ULL + 0xF396B7249E590025ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xCD5F78EF6BB4E2C7ULL + 0x8A778CC8EEEC0AE0ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x87E5823903F8FB91ULL + 0xBA7A39A0E37C8B44ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xD74E4AA9DEFF26C1ULL + 0xA3161AF0E47ECC6BULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xFF9A37D9800668B7ULL + 0x83A68B358F05C8F3ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xE8C4C69F8347D7A1ULL + 0xFE0A6C2AC4E52ED1ULL);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1238U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((aIndex + 6785U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 13U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7125U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCross, 54U)) + (RotL64(aCarry, 27U) ^ RotL64(aIngress, 41U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererA + RotL64(aIngress, 37U)) + 12583180859826261500U;
            aOrbiterA = ((aWandererD + RotL64(aCross, 57U)) + RotL64(aCarry, 39U)) + 9067093488553721468U;
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 26U)) + 12173106198862881754U) + aOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 53U)) + 11333491014394592654U) + aOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aCross, 5U)) + 3511883526940919554U;
            aOrbiterK = (aWandererI + RotL64(aScatter, 43U)) + 7416810692106273044U;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 23U)) + 8341174972619784110U) + aNonceWordO;
            aOrbiterB = (aWandererF + RotL64(aPrevious, 3U)) + 2220852854836962979U;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 51U)) + RotL64(aCarry, 19U)) + 8090781422229383825U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 28U)) + RotL64(aCarry, 43U)) + 2338801236599102223U;
            aOrbiterF = (aWandererH + RotL64(aCross, 41U)) + 12484514711848308104U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 13684861340589131816U) + aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 12796636819991873058U;
            aOrbiterH = RotL64((aOrbiterH * 5533508014234835669U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 7634198650894837690U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 10240326122201201762U;
            aOrbiterK = RotL64((aOrbiterK * 8758703497719125901U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 4162814763739453934U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 2766504649149048469U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16731843453895178671U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 11051393030148769655U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 17687055068651386665U;
            aOrbiterJ = RotL64((aOrbiterJ * 1042927176246229537U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 3353615315436983420U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 5971640796220306310U;
            aOrbiterD = RotL64((aOrbiterD * 15804313508835034807U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 12299773092762384765U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 7435804907797063411U) ^ aOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9848139805288165965U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 8735783937125735699U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 11903126115475835615U;
            aOrbiterF = RotL64((aOrbiterF * 16942088822124940265U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 4427166023462475475U) + aOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 6011733469446008137U;
            aOrbiterA = RotL64((aOrbiterA * 17298067225913923517U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 18341473946127677319U) + aNonceWordJ;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 5423774915753911947U;
            aOrbiterG = RotL64((aOrbiterG * 14985099502923458523U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 2384393657884193014U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 2650593524388493958U;
            aOrbiterB = RotL64((aOrbiterB * 892985816665547945U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 15991261431384033176U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 12583180859826261500U;
            aOrbiterI = RotL64((aOrbiterI * 14394838775646875599U), 11U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 29U);
            aIngress = aIngress + (RotL64(aOrbiterB, 10U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + (RotL64(aOrbiterI, 39U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterJ, 37U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 18U) + RotL64(aOrbiterA, 50U)) + aOrbiterI);
            aWandererC = aWandererC + (((RotL64(aCross, 39U) + RotL64(aOrbiterA, 43U)) + aOrbiterB) + RotL64(aCarry, 27U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterJ, 39U)) + aOrbiterK);
            aWandererD = aWandererD + ((RotL64(aIngress, 37U) + RotL64(aOrbiterC, 29U)) + aOrbiterH);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 24U) + aOrbiterC) + RotL64(aOrbiterK, 41U)) + aWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterJ, 19U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterG, 47U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 29U) + aOrbiterD) + RotL64(aOrbiterC, 52U)) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterC, 5U)) + aOrbiterF) + aWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterD, 11U)) + aOrbiterE);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 5U) + aOrbiterK) + RotL64(aOrbiterI, 57U)) + aNonceWordD);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 12U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordC);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 12452U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((aIndex + 14267U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12497U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((aIndex + 13666U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCarry, 11U)) ^ (RotL64(aIngress, 43U) + RotL64(aCross, 28U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 57U)) + RotL64(aCarry, 47U)) + 5568146815535263910U;
            aOrbiterK = ((aWandererA + RotL64(aCross, 19U)) + 7736084960873834666U) + aNonceWordJ;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 35U)) + 1336413621817562093U;
            aOrbiterD = (((aWandererK + RotL64(aIngress, 12U)) + RotL64(aCarry, 43U)) + 5218462026934984692U) + aNonceWordI;
            aOrbiterA = (aWandererC + RotL64(aCross, 51U)) + 7048890985969555935U;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 53U)) + 13415955213864702118U) + aOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aIngress, 39U)) + 5657023257021528548U;
            aOrbiterB = (aWandererE + RotL64(aScatter, 21U)) + 14338310943137497116U;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 23U)) + 12305161641833950473U) + aNonceWordM;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 46U)) + RotL64(aCarry, 39U)) + 14514226578370459131U;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 37U)) + 12692904083266024340U) + aOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 11012959130001327964U) + aOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 7106471380403489078U;
            aOrbiterE = RotL64((aOrbiterE * 515626559384817223U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 3718101961355280891U) + aNonceWordB;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 13364192077222322664U;
            aOrbiterK = RotL64((aOrbiterK * 1411328915372590283U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 6720867800318913440U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 14497243926965866546U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13595058589060114653U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 5789056168233262435U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 14438482587495779937U) ^ aOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10593535547917767263U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 313917798940179945U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 15241845511889502917U;
            aOrbiterJ = RotL64((aOrbiterJ * 16483477103771326107U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 3591957424821693032U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 1559050939014453558U;
            aOrbiterI = RotL64((aOrbiterI * 17933346117866604725U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 15340590914441451383U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 5538037287390050110U;
            aOrbiterD = RotL64((aOrbiterD * 4082576643144951473U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 4151270491894969214U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 263593701314144898U;
            aOrbiterC = RotL64((aOrbiterC * 10372046955804512457U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 9025145270653080646U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 6867950904094870056U;
            aOrbiterB = RotL64((aOrbiterB * 9975247022340627751U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 3183454301841252109U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 3054904157641290615U;
            aOrbiterH = RotL64((aOrbiterH * 4092317552439599475U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 1768555574434776135U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 5568146815535263910U;
            aOrbiterF = RotL64((aOrbiterF * 12466957001078663927U), 43U);
            //
            aIngress = RotL64(aOrbiterD, 13U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 50U));
            aIngress = aIngress + RotL64(aOrbiterK, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 47U)) + aOrbiterC) + aNonceWordK);
            aWandererE = aWandererE + (((RotL64(aCross, 39U) + RotL64(aOrbiterJ, 53U)) + aOrbiterH) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 27U) + aOrbiterD) + RotL64(aOrbiterF, 39U));
            aWandererF = aWandererF + (((RotL64(aScatter, 21U) + RotL64(aOrbiterI, 30U)) + aOrbiterE) + aWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterD, 43U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 11U) + RotL64(aOrbiterI, 41U)) + aOrbiterJ);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 23U) + aOrbiterC) + RotL64(aOrbiterH, 37U));
            aWandererK = aWandererK + ((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 58U)) + aOrbiterA);
            aWandererG = aWandererG ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterD, 21U)) + aOrbiterG) + aWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 14U) + RotL64(aOrbiterF, 27U)) + aOrbiterJ) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterG, 19U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 44U));
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + RotL64(aWandererD, 10U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordP);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 17134U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneA[((aIndex + 19347U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17811U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 16666U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aIngress, 34U)) + (RotL64(aCarry, 21U) + RotL64(aPrevious, 3U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererA + RotL64(aIngress, 35U)) + 18255347001097480328U) + aNonceWordC;
            aOrbiterB = (((aWandererF + RotL64(aPrevious, 28U)) + RotL64(aCarry, 57U)) + 13679246790311505735U) + aOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aCross, 37U)) + 10565839529765027116U;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 51U)) + RotL64(aCarry, 29U)) + 14327172566224769901U;
            aOrbiterG = (aWandererB + RotL64(aCross, 19U)) + 16239024612038195174U;
            aOrbiterA = (aWandererJ + RotL64(aScatter, 47U)) + 13800012174212131890U;
            aOrbiterE = (aWandererD + RotL64(aPrevious, 21U)) + 13900288860157577583U;
            aOrbiterC = (aWandererE + RotL64(aIngress, 58U)) + 4144386119777112740U;
            aOrbiterK = (aWandererC + RotL64(aPrevious, 39U)) + 3154558262670631372U;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 41U)) + 7456728543137614001U) + aOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = ((aWandererI + RotL64(aIngress, 11U)) + RotL64(aCarry, 21U)) + 11709519851158935384U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 15607438907832240304U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 9276575329661725624U;
            aOrbiterF = RotL64((aOrbiterF * 8879744070762412745U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 6459435969129449226U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 6442382118416542275U) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 2921027306686588233U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 12117432107282150865U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 6831279293184793243U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2435360641135249073U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 9520022957804572889U) + aNonceWordA;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 8322178689474588679U;
            aOrbiterG = RotL64((aOrbiterG * 1627707191467537115U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 4162401591586869316U) + aNonceWordJ;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 8994015844714895961U;
            aOrbiterC = RotL64((aOrbiterC * 15421910378057951895U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 10038095909727959633U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 17756404450592957616U;
            aOrbiterJ = RotL64((aOrbiterJ * 14255952184627347295U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 3379089265413427719U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 11341713098678108441U) ^ aOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2500587373161411961U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 4030296130743454165U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 6332387792111212064U;
            aOrbiterD = RotL64((aOrbiterD * 16490982218150897861U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 14893209417387662133U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 9265457389326311687U;
            aOrbiterE = RotL64((aOrbiterE * 9778404505547862689U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 13496086915199406901U) + aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 14576555328710787951U;
            aOrbiterK = RotL64((aOrbiterK * 13155395071667672943U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 11482324648071976743U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 18255347001097480328U;
            aOrbiterH = RotL64((aOrbiterH * 10918514878283385643U), 35U);
            //
            aIngress = RotL64(aOrbiterG, 37U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 51U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterF, 44U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 13U)) + aOrbiterH) + aNonceWordG);
            aWandererG = aWandererG + ((RotL64(aCross, 13U) + RotL64(aOrbiterH, 18U)) + aOrbiterJ);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 52U) + aOrbiterI) + RotL64(aOrbiterF, 29U));
            aWandererB = aWandererB + (((RotL64(aScatter, 23U) + RotL64(aOrbiterG, 41U)) + aOrbiterK) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 39U)) + aOrbiterA);
            aWandererA = aWandererA + (((RotL64(aIngress, 39U) + RotL64(aOrbiterG, 21U)) + aOrbiterH) + aWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 37U) + aOrbiterH) + RotL64(aOrbiterK, 58U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 48U) + RotL64(aOrbiterE, 11U)) + aOrbiterC);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterD, 51U)) + aOrbiterH);
            aWandererH = aWandererH + (((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 39U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterF, 37U)) + aWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 50U));
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = aCarry ^ aNonceWordJ;
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 28906U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((aIndex + 27209U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27061U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((aIndex + 28702U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 57U)) + (RotL64(aIngress, 43U) ^ RotL64(aCross, 6U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 5U)) + 14686411261024919129U) + aNonceWordJ;
            aOrbiterH = (aWandererF + RotL64(aCross, 41U)) + 7514582233957632005U;
            aOrbiterD = (aWandererH + RotL64(aScatter, 11U)) + 6520710480103365552U;
            aOrbiterA = (aWandererK + RotL64(aPrevious, 23U)) + 1983621978676188036U;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 37U)) + RotL64(aCarry, 35U)) + 9003524602590749672U;
            aOrbiterB = ((aWandererB + RotL64(aCross, 3U)) + RotL64(aCarry, 47U)) + 6428568234045228995U;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 48U)) + 8656552687136446989U) + aOrbiterAssignSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aScatter, 27U)) + 16916248288415922490U) + aOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = (aWandererG + RotL64(aCross, 19U)) + 9740237548002535784U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 21U)) + RotL64(aCarry, 27U)) + 907561000814618339U;
            aOrbiterK = (aWandererA + RotL64(aPrevious, 60U)) + 4751108900841197631U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 167774899400732287U) + aNonceWordF;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 11907484918310854962U;
            aOrbiterD = RotL64((aOrbiterD * 7213139491146402985U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 14910318613649863924U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 14882888155751455276U;
            aOrbiterI = RotL64((aOrbiterI * 11394136445442060201U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 16175942562693781908U) + aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 11022373758481651102U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6836331461393816027U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 12548405399045031548U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 10850926364556828443U) ^ aNonceWordE;
            aOrbiterF = RotL64((aOrbiterF * 16231561687709867431U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 13391684887911141790U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 14648937281264822988U;
            aOrbiterG = RotL64((aOrbiterG * 6533299316940026059U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 8298658887198526821U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 13822977698661348891U;
            aOrbiterE = RotL64((aOrbiterE * 17769262972278410937U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 7505646847564645719U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 3238749538197209166U;
            aOrbiterC = RotL64((aOrbiterC * 15394286542600778567U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 15853506915123709257U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 8426329899401071248U;
            aOrbiterK = RotL64((aOrbiterK * 1330397096577715113U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 14848635392815613098U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 3549927798350175044U;
            aOrbiterJ = RotL64((aOrbiterJ * 1899044682313056949U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 1798973117197750802U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 13056711228618953977U) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 9102877396419306689U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 1395893547965799281U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 14686411261024919129U;
            aOrbiterA = RotL64((aOrbiterA * 17075377081365066067U), 47U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterI, 13U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 60U));
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterK, 53U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterH, 40U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterC, 23U)) + aOrbiterF);
            aWandererH = aWandererH + (((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 51U)) + aOrbiterC) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterJ, 54U)) + aOrbiterB);
            aWandererE = aWandererE + ((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 5U)) + aOrbiterJ);
            aWandererB = aWandererB ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterF, 47U)) + aOrbiterH) + aWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 19U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterI, 3U)) + aNonceWordD);
            aWandererK = aWandererK + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterC, 21U)) + aOrbiterA) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 39U) + aOrbiterE) + RotL64(aOrbiterB, 27U));
            aWandererI = aWandererI + (((RotL64(aCross, 24U) + RotL64(aOrbiterH, 30U)) + aOrbiterK) + aWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 21U) + aOrbiterE) + RotL64(aOrbiterJ, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 42U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 60U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 13U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordH);
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

void TwistExpander_Softball_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x9D633F36E3FBEA29ULL + 0xE86530100D299887ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xBCE8E8AAFA9C059DULL + 0xDD398657A66F51B4ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xEE3AC5F52E6596D5ULL + 0x8BB8561B9E613C86ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x974E448399B459E9ULL + 0x8DE22E7A7DC37155ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x9F9B2C227DF5608BULL + 0xA33CD8870FEC215FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xAAAEC90A64E35189ULL + 0xA1EE6B0CB9E1C8E5ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xDF49B16A66C9C3D1ULL + 0xCE65A4C641F024DBULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF5CE2F8F78873A27ULL + 0x9F3CD918363EFEC0ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xA474732FC315E161ULL + 0x9A630E4CF47B4676ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xFB17CA60302D77E1ULL + 0x8B514C6EEE9315BFULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xD5DBC9278FE42E55ULL + 0xEF3749DA0DC0C856ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xC6D1E6CBB49CC7D3ULL + 0xA08D528EB11C06ACULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x877F0373484FD05FULL + 0xC1AAF39C147B3E98ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x8D2687A6DE6C0229ULL + 0xC8D0AC71167F50B3ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xDE5F7273DCBFD7ADULL + 0xDFF3A8C6F675ED89ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xB2C0EB0021BB0E45ULL + 0xF80C328CF06EEB20ULL);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 1668U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2770U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5100U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 2609U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 22U) + RotL64(aIngress, 51U)) + (RotL64(aPrevious, 3U) ^ RotL64(aCross, 37U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererE + RotL64(aIngress, 23U)) + 12775735908960052604U) + aNonceWordE;
            aOrbiterI = (((aWandererA + RotL64(aCross, 37U)) + RotL64(aCarry, 51U)) + 11791373812080296887U) + aOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = (((aWandererG + RotL64(aScatter, 52U)) + RotL64(aCarry, 43U)) + 5537362877706057303U) + aOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aPrevious, 47U)) + 2023912048504189380U;
            aOrbiterA = (aWandererH + RotL64(aScatter, 5U)) + 17668828109963766893U;
            aOrbiterH = (aWandererB + RotL64(aCross, 57U)) + 558908629933941224U;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 27U)) + 1479633119685446888U) + aNonceWordA;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 18U)) + RotL64(aCarry, 23U)) + 15460320397843364063U;
            aOrbiterF = (aWandererI + RotL64(aIngress, 41U)) + 10059749397555469054U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 9987633811929693924U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 10087337844580228269U;
            aOrbiterD = RotL64((aOrbiterD * 13817142288940843815U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 4446204415503364254U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 15106063243302192717U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13273756657334709803U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 9430197906134676162U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 1226048679997253363U) ^ aOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14247538885252664127U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 10611580584157624739U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterI) ^ 3137391249289641509U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 5462682413239873181U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 9327201928815412810U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 7890659377013147073U) ^ aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13827717178378062047U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 10675114832750356941U) + aNonceWordD;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 8804440385852327267U;
            aOrbiterK = RotL64((aOrbiterK * 8520671775587260601U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 12871947817782057116U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 11015991745792051390U;
            aOrbiterB = RotL64((aOrbiterB * 17152451500505815031U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 6320437975845673731U) + aNonceWordI;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 702457937087191287U;
            aOrbiterI = RotL64((aOrbiterI * 17491257114676739589U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 16629064896250312921U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 6054107387816339103U;
            aOrbiterA = RotL64((aOrbiterA * 6983767878966747219U), 39U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterA, 34U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + RotL64(aOrbiterK, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((((RotL64(aCross, 57U) + aOrbiterE) + RotL64(aOrbiterI, 19U)) + aNonceWordM) + aWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 53U)) + aOrbiterB) + aWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 29U)) + aOrbiterF);
            aWandererE = aWandererE + (((RotL64(aScatter, 46U) + RotL64(aOrbiterI, 23U)) + aOrbiterA) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterH, 14U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 41U) + RotL64(aOrbiterH, 43U)) + aOrbiterK);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 23U) + aOrbiterI) + RotL64(aOrbiterG, 37U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 13U)) + aNonceWordG);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 10U) + RotL64(aOrbiterF, 6U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + (RotL64(aWandererA, 42U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordF;
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10309U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneD[((aIndex + 9206U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 9815U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneB[((aIndex + 8687U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 6U)) + (RotL64(aCross, 35U) ^ RotL64(aIngress, 19U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererJ + RotL64(aCross, 41U)) + 701291026547470433U) + aOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aScatter, 60U)) + 17283292650462111643U) + aNonceWordF;
            aOrbiterB = (((aWandererC + RotL64(aIngress, 27U)) + RotL64(aCarry, 29U)) + 9969124091931303406U) + aOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 23U)) + 889176772718046988U) + aNonceWordG;
            aOrbiterD = (aWandererE + RotL64(aScatter, 37U)) + 6054541844643748084U;
            aOrbiterI = (aWandererA + RotL64(aPrevious, 19U)) + 14703226235143028132U;
            aOrbiterF = ((aWandererG + RotL64(aCross, 13U)) + RotL64(aCarry, 43U)) + 7977975878522921062U;
            aOrbiterC = (aWandererB + RotL64(aIngress, 56U)) + 16894322614172266274U;
            aOrbiterK = ((aWandererK + RotL64(aScatter, 5U)) + RotL64(aCarry, 3U)) + 12160451749345900570U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 10870847008043897470U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 8159920947172520247U) ^ aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4833194641611011805U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 2440099120969517932U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 2428396147731468007U;
            aOrbiterD = RotL64((aOrbiterD * 9363073341539598441U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2213226274394673479U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 7079731443427765333U;
            aOrbiterF = RotL64((aOrbiterF * 16918930776877030559U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 958896789550478970U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 10788682955708075458U;
            aOrbiterC = RotL64((aOrbiterC * 913321215613559729U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 2003386579317564870U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 8419686358774204999U;
            aOrbiterK = RotL64((aOrbiterK * 6547052526438697621U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 6989167615157578904U) + aOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 17636634003643824148U;
            aOrbiterA = RotL64((aOrbiterA * 11038576417283732937U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 13824962118933907859U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 9543912892587859646U;
            aOrbiterJ = RotL64((aOrbiterJ * 14736710162285997415U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 15729878041027706114U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 9542137475454825463U) ^ aOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11420547128115090491U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 5327302277575009955U) + aNonceWordC;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 2707383132257428583U;
            aOrbiterG = RotL64((aOrbiterG * 6120763309390182129U), 37U);
            //
            aIngress = RotL64(aOrbiterG, 53U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 14U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 4U) + aOrbiterB) + RotL64(aOrbiterI, 47U));
            aWandererC = aWandererC + (((RotL64(aScatter, 11U) + RotL64(aOrbiterF, 5U)) + aOrbiterI) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 21U) + aOrbiterK) + RotL64(aOrbiterG, 30U)) + aWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 19U)) + aOrbiterC) + aNonceWordN);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 60U) + RotL64(aOrbiterK, 39U)) + aOrbiterD) + aWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 53U) + RotL64(aOrbiterC, 23U)) + aOrbiterG) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 27U) + aOrbiterG) + RotL64(aOrbiterD, 51U));
            aWandererF = aWandererF + (((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 12U)) + aOrbiterC) + aNonceWordL);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterD, 57U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (RotL64(aWandererG, 18U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 53U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12743U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15650U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 12237U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneC[((aIndex + 12555U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 53U)) + (RotL64(aCross, 5U) + RotL64(aIngress, 24U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 11U)) + 966899917801652720U) + aOrbiterAssignSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aCross, 3U)) + 10996327672320748649U;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 52U)) + RotL64(aCarry, 13U)) + 4188171566846621107U;
            aOrbiterG = (((aWandererH + RotL64(aScatter, 23U)) + RotL64(aCarry, 21U)) + 5886209243097387959U) + aNonceWordJ;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 39U)) + 14940428957136728111U;
            aOrbiterI = ((aWandererK + RotL64(aCross, 43U)) + 179187285531914832U) + aNonceWordP;
            aOrbiterH = (aWandererG + RotL64(aScatter, 29U)) + 6685351948936817752U;
            aOrbiterA = (((aWandererJ + RotL64(aPrevious, 35U)) + RotL64(aCarry, 47U)) + 1894506461704029700U) + aOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aIngress, 56U)) + 4182760368636977082U) + aNonceWordG;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 12523318028514940790U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 5059306166973366892U;
            aOrbiterF = RotL64((aOrbiterF * 2857409765717296483U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 5890872367917643851U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 17747338389865221534U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5306740664798049267U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 13906227834259884100U) + aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 7152105382899756368U;
            aOrbiterG = RotL64((aOrbiterG * 6772157117358310485U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 17868101884759619240U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 11758843266314148347U;
            aOrbiterB = RotL64((aOrbiterB * 5919135169337501485U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 13950566197090324859U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 17278105609930477854U) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 11431842718945107359U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 9556785965646738355U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 841298436857932987U;
            aOrbiterI = RotL64((aOrbiterI * 15077843186688841797U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 1951515285492133830U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 15775839819330588437U;
            aOrbiterH = RotL64((aOrbiterH * 7902654031401620995U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 5585458468816495436U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 17258586689032223623U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1652050227399194271U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 5254132659445988836U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 15440741734777060925U) ^ aOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17445581079035134067U), 57U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterH, 35U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 39U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 30U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + RotL64(aOrbiterJ, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterB, 47U)) + aOrbiterF) + aWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 34U) + aOrbiterI) + RotL64(aOrbiterB, 52U)) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 53U) + aOrbiterA) + RotL64(aOrbiterC, 39U));
            aWandererF = aWandererF + (((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 19U)) + aOrbiterA) + aNonceWordL);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 23U) + aOrbiterJ) + RotL64(aOrbiterH, 23U));
            aWandererG = aWandererG + (((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterF, 58U)) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterD, 13U));
            aWandererB = aWandererB + (((RotL64(aIngress, 10U) + aOrbiterC) + RotL64(aOrbiterF, 35U)) + aNonceWordI);
            aWandererE = aWandererE ^ (((RotL64(aCross, 27U) + aOrbiterD) + RotL64(aOrbiterA, 27U)) + aWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 54U));
            aCarry = aCarry + RotL64(aWandererG, 13U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 20215U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20746U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16651U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneD[((aIndex + 18519U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 10U) ^ RotL64(aCross, 41U)) + (RotL64(aCarry, 29U) + RotL64(aIngress, 57U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((((aWandererH + RotL64(aCross, 28U)) + RotL64(aCarry, 5U)) + 14823268998003220191U) + aOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1]) + aNonceWordK;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 23U)) + 15295237288788213847U;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 47U)) + 16434853402001133899U) + aOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aScatter, 51U)) + 7555911304407871631U;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 37U)) + RotL64(aCarry, 35U)) + 14977248264994834620U;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 43U)) + RotL64(aCarry, 19U)) + 9707764144919392380U;
            aOrbiterJ = (aWandererE + RotL64(aCross, 56U)) + 1277304385464681529U;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 11U)) + 3089786220465849395U) + aNonceWordJ;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 5U)) + 3700503853358695085U) + aNonceWordL;
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 3240054112993517371U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterK) ^ 16897532076915366859U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 4120874717534309035U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 18167359289798364307U) + aOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 8870819278575769863U;
            aOrbiterE = RotL64((aOrbiterE * 9334066154398059075U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 15363069206212330251U) + aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 14858164441499725158U) ^ aNonceWordF;
            aOrbiterJ = RotL64((aOrbiterJ * 14931933411393847915U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 5357144808788707522U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 2910681277417754860U;
            aOrbiterK = RotL64((aOrbiterK * 13170868582159347059U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 9824408699018165151U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 368370224788793300U) ^ aNonceWordH;
            aOrbiterH = RotL64((aOrbiterH * 14358982366258729959U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 7095398304588825115U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 11418879758164313554U;
            aOrbiterC = RotL64((aOrbiterC * 5983520332639771791U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 2171599720681913272U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 17593730219647495033U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12926053208918563087U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 17755947635188715523U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 14565740605227022106U;
            aOrbiterF = RotL64((aOrbiterF * 15866418354612945335U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 14538017880915584414U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 6174566474851449123U;
            aOrbiterG = RotL64((aOrbiterG * 179569008593475683U), 39U);
            //
            aIngress = RotL64(aOrbiterD, 19U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 56U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 29U)) + aOrbiterC);
            aWandererC = aWandererC ^ ((RotL64(aCross, 46U) + RotL64(aOrbiterA, 23U)) + aOrbiterF);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterC, 60U)) + aOrbiterH) + RotL64(aCarry, 57U)) + aNonceWordM);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 47U)) + aOrbiterA);
            aWandererI = aWandererI + (((RotL64(aPrevious, 23U) + aOrbiterD) + RotL64(aOrbiterC, 53U)) + aNonceWordG);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 3U)) + aOrbiterG) + aWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 35U)) + aOrbiterE) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterG, 41U)) + aOrbiterC);
            aWandererD = aWandererD + ((((RotL64(aIngress, 12U) + aOrbiterD) + RotL64(aOrbiterH, 18U)) + aNonceWordC) + aWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 60U));
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 35U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordA);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24986U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((aIndex + 27301U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23558U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((aIndex + 24773U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 29U) ^ RotL64(aIngress, 41U)) + (RotL64(aCross, 54U) + RotL64(aPrevious, 11U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererJ + RotL64(aCross, 3U)) + 10336802574069791273U;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 13U)) + RotL64(aCarry, 21U)) + 169025388197058936U;
            aOrbiterI = (aWandererB + RotL64(aIngress, 23U)) + 6541354188379168846U;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 34U)) + 16223920526599306104U) + aOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = (aWandererD + RotL64(aScatter, 19U)) + 12756613707692514808U;
            aOrbiterA = (((aWandererH + RotL64(aPrevious, 51U)) + RotL64(aCarry, 47U)) + 5082475548176484035U) + aNonceWordO;
            aOrbiterH = ((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 3U)) + 4907435526952698526U;
            aOrbiterE = ((aWandererF + RotL64(aIngress, 42U)) + 14236627073831834337U) + aOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = (aWandererA + RotL64(aCross, 29U)) + 11502511046130497584U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 3679044835550219497U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 11254838916686736746U) ^ aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8631695922983532915U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 10582608424233200966U) + aNonceWordK;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 10449735026385340313U;
            aOrbiterA = RotL64((aOrbiterA * 7363770199734997411U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 4628253464169957835U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 17664454668473204465U;
            aOrbiterE = RotL64((aOrbiterE * 4234720298731378527U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 3798386391743884889U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 1379331161819246587U;
            aOrbiterD = RotL64((aOrbiterD * 13086160171095077295U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 9816600392407327227U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 16781971616348376878U;
            aOrbiterJ = RotL64((aOrbiterJ * 12503867584828289879U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 4807797577690520554U) + aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 2492057261148595922U;
            aOrbiterG = RotL64((aOrbiterG * 9453302540675483005U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 7909676419643119585U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 256053568910383007U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11965085163352053161U), 47U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterG) + 16179914439220412472U) + aOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1]) + aNonceWordM;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 3968867762761955845U;
            aOrbiterF = RotL64((aOrbiterF * 7473632378251893139U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 7474832923901283742U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 4736994731050735779U;
            aOrbiterC = RotL64((aOrbiterC * 9839654409121414047U), 51U);
            //
            aIngress = RotL64(aOrbiterG, 35U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterA, 44U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 23U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 60U) + aOrbiterE) + RotL64(aOrbiterD, 37U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 21U)) + aOrbiterF) + RotL64(aCarry, 35U)) + aNonceWordG);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterD, 30U));
            aWandererK = aWandererK + ((((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterH, 41U)) + RotL64(aCarry, 43U)) + aWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterG, 3U)) + aOrbiterE) + aWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 43U) + RotL64(aOrbiterI, 53U)) + aOrbiterG);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 34U) + RotL64(aOrbiterJ, 57U)) + aOrbiterE);
            aWandererH = aWandererH + (((RotL64(aScatter, 21U) + RotL64(aOrbiterG, 26U)) + aOrbiterA) + aNonceWordC);
            aWandererI = aWandererI ^ (((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterC, 13U)) + aNonceWordJ);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 50U));
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 41U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29410U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32712U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32530U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneB[((aIndex + 29023U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 54U) ^ RotL64(aPrevious, 11U)) + (RotL64(aIngress, 23U) ^ RotL64(aCarry, 41U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererK + RotL64(aPrevious, 52U)) + 5131645209694953015U;
            aOrbiterJ = (aWandererG + RotL64(aScatter, 3U)) + 12070391048835379854U;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 11U)) + 2604295836242338724U) + aOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aCross, 23U)) + 14042039029284001596U;
            aOrbiterK = (((aWandererA + RotL64(aPrevious, 34U)) + RotL64(aCarry, 37U)) + 8914654543854559327U) + aNonceWordN;
            aOrbiterC = ((aWandererI + RotL64(aCross, 19U)) + RotL64(aCarry, 23U)) + 2185619407969359869U;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 39U)) + 5187406295103352574U) + aOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aIngress, 57U)) + 8022832481290871217U;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 29U)) + RotL64(aCarry, 57U)) + 8783061916740573472U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 10711028365596196301U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 13387065038269133571U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12444578026365205255U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 11187001318931801582U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 14191473173276034019U) ^ aNonceWordP;
            aOrbiterK = RotL64((aOrbiterK * 2491253922434756431U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 16207761776716426435U) + aOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 9677408414452078760U) ^ aOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5487303383095129949U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 17812460332794370649U) + aOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 7736423148554132028U;
            aOrbiterH = RotL64((aOrbiterH * 15588733747232852555U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 17293203944059014763U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 13487243633338010243U;
            aOrbiterA = RotL64((aOrbiterA * 9468688858740539095U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 15979293016815060755U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 17645215484691359547U) ^ aNonceWordO;
            aOrbiterI = RotL64((aOrbiterI * 1449450767288733995U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 11635961468586927692U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 10530136578329059784U;
            aOrbiterB = RotL64((aOrbiterB * 8785021493374398437U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 4900370530116992731U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 15952900504821599445U;
            aOrbiterC = RotL64((aOrbiterC * 5413316082800365261U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 9938000151832814778U) + aNonceWordI;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 14170277411106520726U;
            aOrbiterJ = RotL64((aOrbiterJ * 5058343552974910737U), 19U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 43U);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 54U));
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 48U) + RotL64(aOrbiterH, 21U)) + aOrbiterE) + aNonceWordG) + aWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 39U) + RotL64(aOrbiterE, 41U)) + aOrbiterI) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterB, 5U));
            aWandererD = aWandererD + ((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 48U)) + aOrbiterC);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 29U)) + aOrbiterA);
            aWandererG = aWandererG + ((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 35U)) + aOrbiterJ);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterD, 53U));
            aWandererC = aWandererC + (((RotL64(aCross, 23U) + aOrbiterH) + RotL64(aOrbiterJ, 58U)) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 4U) + aOrbiterA) + RotL64(aOrbiterB, 11U)) + aWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 38U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordB;
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

void TwistExpander_Softball_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x98E2EF04D9119A75ULL + 0x8D5980B4B49B8E62ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xEFC325BF5BA42F25ULL + 0xB4B397EAD6FCD5B3ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xFC3365055372F395ULL + 0xF9194B8858F9C086ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x922A8AC6C273C039ULL + 0xD457072BEBAFE2E9ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xB4DFCB2358C88EC7ULL + 0x97F1F19F644783A1ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xD74D3A4A90348A21ULL + 0xEC5FDF3FC02422A3ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x9C320796E26EBDD7ULL + 0xEC89ECC6E4A79688ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xB61F5F8D7E94FC65ULL + 0x980E336FA7EE9411ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xBD92FDBD098ED559ULL + 0xE7267F97E589AD49ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x931D6F814137135FULL + 0xF3F8BC07963CE880ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xC1D174F6DB893105ULL + 0xCDB40263F5F92A86ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xC8EBF672245C4923ULL + 0xCD861EE2683C3BA5ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xC3BEE7C481F1E74FULL + 0xDAD8690E9FA4A5B0ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xC98C93AB16F24459ULL + 0xE92CCDC472C6076BULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xA29721BA44ED51B9ULL + 0xC3C9874C1453CF9DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x9FAFD07F39C909D3ULL + 0xE35D0F1CAC94B0E6ULL);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 1624U)) & S_BLOCK1], 53U) ^ RotL64(aKeyRowReadA[((aIndex + 743U)) & W_KEY1], 23U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 1744U)) & W_KEY1], 19U) ^ RotL64(mSource[((aIndex + 4918U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 22U) + RotL64(aCarry, 53U)) ^ (RotL64(aCross, 3U) + RotL64(aIngress, 41U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterE = (((aWandererE + RotL64(aPrevious, 51U)) + RotL64(aCarry, 5U)) + 1087148170018530502U) + aNonceWordN;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 43U)) + 15530846874509311414U) + aPhaseAOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aScatter, 27U)) + RotL64(aCarry, 53U)) + 16987358651515511212U;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 21U)) + RotL64(aCarry, 37U)) + 12504143181007924259U;
            aOrbiterB = (aWandererA + RotL64(aIngress, 11U)) + 393322117322732418U;
            aOrbiterK = ((aWandererF + RotL64(aCross, 36U)) + 14325937299241887166U) + aPhaseAOrbiterAssignSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aPrevious, 5U)) + 9395262907017475742U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 13658510441418344769U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 6410754322737005336U;
            aOrbiterH = RotL64((aOrbiterH * 6932217611373076391U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 9257290738538818434U) + aNonceWordF;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 7489828960857692286U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16519674788777989043U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 4118778591214588387U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 16619215231168796563U) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 14876884956536265157U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 11326283811003573430U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterH) ^ 1865401866017614604U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterD = RotL64((aOrbiterD * 8378326058282460073U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 670150121105733604U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 1499331510641068749U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16623742535540383107U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 1116410848560838532U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 2696841341036281779U;
            aOrbiterJ = RotL64((aOrbiterJ * 9598953298074904869U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 5487352391229549881U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 12008243050943342979U;
            aOrbiterC = RotL64((aOrbiterC * 9087261224804582459U), 43U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterC, 57U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 4U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 53U) + aOrbiterE) + RotL64(aOrbiterC, 41U)) + aNonceWordC) + aPhaseAWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterH, 60U)) + RotL64(aCarry, 53U)) + aNonceWordE);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 37U) + aOrbiterJ) + RotL64(aOrbiterK, 47U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterD, 53U)) + aPhaseAWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterJ, 23U)) + aOrbiterH);
            aWandererE = aWandererE + (((RotL64(aIngress, 4U) + RotL64(aOrbiterK, 29U)) + aOrbiterE) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 5U)) + aOrbiterH) + aNonceWordO);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 58U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 5U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ aNonceWordD;
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 6888U)) & S_BLOCK1], 6U) ^ RotL64(mSource[((aIndex + 8920U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 5936U)) & W_KEY1], 40U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 6372U)) & W_KEY1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aPrevious, 23U)) + (RotL64(aCarry, 11U) ^ RotL64(aIngress, 56U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterF = ((aWandererH + RotL64(aCross, 3U)) + 12692813903177772178U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aScatter, 13U)) + 7112496446691277899U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aIngress, 20U)) + 2112247138290568813U) + aNonceWordK;
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 27U)) + 3699421080882855947U) + aNonceWordO;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 47U)) + RotL64(aCarry, 11U)) + 13761832028354380922U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 53U)) + RotL64(aCarry, 27U)) + 9243822514887600214U;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 37U)) + RotL64(aCarry, 53U)) + 6863833516853046129U;
            //
            aOrbiterF = (((aOrbiterF + aOrbiterD) + 8863897995943098018U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 13346785686701467520U;
            aOrbiterE = RotL64((aOrbiterE * 18074843497158380703U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 15309543066305531619U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 17515530938817919111U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16625193986319048245U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 760493237816424254U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 7282586354117620860U;
            aOrbiterK = RotL64((aOrbiterK * 2327153408185290635U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 4129706068526969105U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 7020175432730888755U;
            aOrbiterD = RotL64((aOrbiterD * 10095158356907592239U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 9102258982216515596U) + aNonceWordL;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 10822031305361453690U;
            aOrbiterH = RotL64((aOrbiterH * 2036205056490578491U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 12571477440964330246U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 8436347026653095199U;
            aOrbiterC = RotL64((aOrbiterC * 17930734781213681573U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 14214789872073941940U) + aNonceWordM;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 12915911919403385001U;
            aOrbiterB = RotL64((aOrbiterB * 13161681603528031511U), 37U);
            //
            aIngress = RotL64(aOrbiterD, 41U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterH, 35U)) + aPhaseAWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 13U)) + aOrbiterH) + RotL64(aCarry, 41U)) + aNonceWordH);
            aWandererC = aWandererC ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterE, 41U)) + aOrbiterB) + aNonceWordD);
            aWandererA = aWandererA + (((RotL64(aScatter, 39U) + aOrbiterK) + RotL64(aOrbiterE, 22U)) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterD, 53U)) + aOrbiterH) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 22U) + aOrbiterE) + RotL64(aOrbiterC, 29U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 13U) + aOrbiterF) + RotL64(aOrbiterC, 5U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 56U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = aCarry ^ aNonceWordE;
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13732U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14725U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 12505U)) & W_KEY1], 3U) ^ RotL64(aKeyRowReadB[((aIndex + 11184U)) & W_KEY1], 18U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 34U) + RotL64(aIngress, 51U)) ^ (RotL64(aCross, 21U) + RotL64(aPrevious, 3U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 47U)) + RotL64(aCarry, 53U)) + 6069475454765660321U;
            aOrbiterB = ((aWandererJ + RotL64(aCross, 3U)) + RotL64(aCarry, 23U)) + 11483704742497268068U;
            aOrbiterI = ((aWandererG + RotL64(aScatter, 19U)) + RotL64(aCarry, 5U)) + 11055697447388986418U;
            aOrbiterA = (aWandererC + RotL64(aIngress, 39U)) + 10897095046039997004U;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 11U)) + 4731637118230457840U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aIngress, 60U)) + 13855839187084986751U) + aNonceWordE;
            aOrbiterJ = (((aWandererD + RotL64(aScatter, 29U)) + 5328208115460188239U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordN;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 12479538544291412985U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 10740165998792608231U) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 14046827922294477379U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 6492798157284955373U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 13056825957483891921U;
            aOrbiterB = RotL64((aOrbiterB * 14882112110627751751U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 2068184064919194657U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 5656302738780746294U;
            aOrbiterG = RotL64((aOrbiterG * 16493021179127646345U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 11193756120230763294U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 17306750816837208999U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7949360041241439741U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 12952818800389361804U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 15380412293642628312U;
            aOrbiterE = RotL64((aOrbiterE * 2914662289178925547U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 7706090204767242996U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 14598802276412649570U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4821408736292041399U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 17819762117328075515U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 6481384240915075101U;
            aOrbiterJ = RotL64((aOrbiterJ * 4836701121865783029U), 11U);
            //
            aIngress = RotL64(aOrbiterA, 29U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + RotL64(aOrbiterJ, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aIngress, 11U) + aOrbiterE) + RotL64(aOrbiterJ, 11U)) + RotL64(aCarry, 43U)) + aPhaseAWandererUpdateSaltA[((aIndex + 24U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterJ, 3U)) + aNonceWordC);
            aWandererG = aWandererG + ((RotL64(aCross, 5U) + aOrbiterI) + RotL64(aOrbiterA, 50U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 56U) + RotL64(aOrbiterF, 43U)) + aOrbiterI) + aNonceWordB);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterI, 35U)) + aOrbiterB);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 47U) + aOrbiterJ) + RotL64(aOrbiterF, 27U));
            aWandererD = aWandererD + (((((RotL64(aCross, 41U) + aOrbiterI) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 21U)) + aNonceWordP) + aPhaseAWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 30U));
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordM);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 21004U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneB[((aIndex + 17366U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17039U)) & S_BLOCK1], 37U) ^ RotL64(mSource[((aIndex + 16474U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 29U) ^ RotL64(aCarry, 43U)) + (RotL64(aPrevious, 58U) ^ RotL64(aCross, 11U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterH = ((aWandererG + RotL64(aScatter, 13U)) + RotL64(aCarry, 57U)) + 1364174714924216027U;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 60U)) + 13561796874229506613U) + aPhaseAOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = ((aWandererC + RotL64(aIngress, 37U)) + RotL64(aCarry, 41U)) + 11845572344206238305U;
            aOrbiterF = (aWandererD + RotL64(aCross, 43U)) + 15762708240326773763U;
            aOrbiterB = (aWandererK + RotL64(aScatter, 23U)) + 1157119665207900473U;
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 3U)) + RotL64(aCarry, 21U)) + 6823546624372055260U;
            aOrbiterJ = (((aWandererJ + RotL64(aCross, 29U)) + 14465564210523945121U) + aPhaseAOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1]) + aNonceWordK;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 10667464548080807531U) + aNonceWordA;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 13445737493224316575U;
            aOrbiterG = RotL64((aOrbiterG * 12137295000900795711U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 3009837893785957665U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 2886920524111083752U;
            aOrbiterK = RotL64((aOrbiterK * 15308180928967762543U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 10886177449328249656U) + aNonceWordH;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 15067759884678100433U;
            aOrbiterI = RotL64((aOrbiterI * 5724566815989860041U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 18307930462682331536U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 8791864377579255801U) ^ aNonceWordE;
            aOrbiterB = RotL64((aOrbiterB * 9265158882471421767U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 805797468642992351U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 5743305867058244964U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16263000753351131717U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 17102025528234481273U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 1841579177327486899U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3841603385577825265U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 2189493507896508972U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 18209567010094914374U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3737080408976852351U), 35U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 35U);
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterJ, 44U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterG, 29U)) + aPhaseAWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 18U) + aOrbiterJ) + RotL64(aOrbiterB, 19U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterG, 57U)) + aOrbiterB);
            aWandererK = aWandererK + (((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 13U)) + aOrbiterB) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 37U)) + aOrbiterK) + aNonceWordG);
            aWandererF = aWandererF + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterI, 50U)) + aOrbiterJ) + RotL64(aCarry, 29U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterK, 43U)) + aOrbiterJ) + aNonceWordM);
            //
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 24U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + RotL64(aWandererJ, 35U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24072U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneA[((aIndex + 24237U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22339U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 24461U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 13U) + RotL64(aCross, 29U)) ^ (RotL64(aIngress, 54U) + RotL64(aCarry, 41U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterC = ((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 3U)) + 2786079456995203065U;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 44U)) + 7237256119153857253U) + aNonceWordN;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 57U)) + RotL64(aCarry, 35U)) + 9310834010563647604U;
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 29U)) + 17361734905706517877U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aCross, 51U)) + 15837111231884647451U) + aPhaseAOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 35U)) + RotL64(aCarry, 53U)) + 18065431964418026445U;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 11U)) + 3029123922999952652U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 5166926595573507837U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 1918425684273807598U) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 16616641579714896719U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 4724551751012661440U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 1818014487579644390U;
            aOrbiterC = RotL64((aOrbiterC * 14904092108647864911U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 6670090372241084216U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 8485757110007268693U;
            aOrbiterD = RotL64((aOrbiterD * 11876760095108618363U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 4928130251509514742U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 2528788422725346792U;
            aOrbiterG = RotL64((aOrbiterG * 1855982047967756661U), 39U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterB) + 2860387120895147503U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 12927802338151379368U;
            aOrbiterH = RotL64((aOrbiterH * 8876144125458603029U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 18029699867733207083U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 13361836994951253312U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5349767426256597073U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 11957294454794128079U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 3755417922063414648U;
            aOrbiterJ = RotL64((aOrbiterJ * 13896364063651241401U), 21U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterE, 11U);
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterH, 29U)) + RotL64(aCarry, 27U)) + aNonceWordI);
            aWandererB = aWandererB ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 5U)) + aOrbiterG) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 47U)) + aOrbiterJ) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 26U) + aOrbiterJ) + RotL64(aOrbiterH, 11U));
            aWandererD = aWandererD + (((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 18U)) + aOrbiterE) + aPhaseAWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 41U) + aOrbiterE) + RotL64(aOrbiterB, 53U));
            aWandererC = aWandererC + ((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterH, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 34U));
            aCarry = aCarry + RotL64(aWandererC, 51U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordB;
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32234U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32210U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30886U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneB[((aIndex + 32696U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aPrevious, 38U)) ^ (RotL64(aCarry, 51U) ^ RotL64(aIngress, 3U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterH = ((aWandererC + RotL64(aCross, 5U)) + RotL64(aCarry, 23U)) + 12669015908335980355U;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 11U)) + 5438715179868613192U;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 47U)) + RotL64(aCarry, 53U)) + 13172104448184536460U;
            aOrbiterK = (((aWandererB + RotL64(aIngress, 41U)) + RotL64(aCarry, 5U)) + 13421421503244744803U) + aNonceWordO;
            aOrbiterF = (((aWandererK + RotL64(aPrevious, 35U)) + 13327113302994856582U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordD;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 58U)) + 4671768205922454413U) + aNonceWordM;
            aOrbiterI = ((aWandererG + RotL64(aCross, 19U)) + 5355759962838579929U) + aPhaseAOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 6691720614265406851U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 7063906424700911378U;
            aOrbiterE = RotL64((aOrbiterE * 17091734375516280675U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 17328616394166672263U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 1542940602574207068U;
            aOrbiterF = RotL64((aOrbiterF * 8981679306319627975U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 7203866278803132454U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 993485696233139264U;
            aOrbiterC = RotL64((aOrbiterC * 11609009908810366447U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 15659679028507488331U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 18321361454094675842U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3966860765622641843U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 9633319822696783352U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 3496559332232402963U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7772060229838162977U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 1918349708324205526U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 7701088402761359134U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9649485438465644795U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 6006824348814439686U) + aNonceWordK;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 18088375375347012557U;
            aOrbiterD = RotL64((aOrbiterD * 12801082943086128385U), 51U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterD, 60U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + RotL64(aOrbiterK, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterE, 51U)) + aOrbiterC) + RotL64(aCarry, 3U)) + aPhaseAWandererUpdateSaltA[((aIndex + 14U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterC, 35U)) + aOrbiterF) + aPhaseAWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 3U)) + aOrbiterF) + RotL64(aCarry, 35U)) + aNonceWordF);
            aWandererH = aWandererH ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterF, 41U)) + aOrbiterH);
            aWandererG = aWandererG + (((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterK, 29U)) + aNonceWordB);
            aWandererB = aWandererB ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterI, 12U)) + aOrbiterD) + aNonceWordA);
            aWandererC = aWandererC + ((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 57U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 56U));
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordG);
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

void TwistExpander_Softball_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x88A5B0434E816E63ULL + 0xF8D6F75BDABC995EULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x8BB953613292A187ULL + 0x9CB5D314524F6F2AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x85F645E66170BA57ULL + 0xA1E7E5F44248B867ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xE724244B4165967BULL + 0x91AAD41FEED1DF26ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x989408BB23EE53E5ULL + 0xBAF2EFF7E7CC47B9ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xACE8C767D38AC8D1ULL + 0x83133CDB31882151ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xCD7986C62E89746FULL + 0xE9FC1CD54D2DA483ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xB45FE1AAB1633DA5ULL + 0x8C3B7E65F7B98B70ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xB893F9138ABC3B3FULL + 0xA64A7E7A5542BE24ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xC5A25DD54398974DULL + 0xB2263625C94345D9ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xF550C1BEE3F3D357ULL + 0xE7D64D9ABC90CBEBULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x87D409BA68182893ULL + 0xFA59CD23627B0E54ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xD0697E334AFE2725ULL + 0xBBCD5DB59E4D1C5BULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xB163B8C37591911DULL + 0x9EBA1177AF49CACFULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x83D04B294C189DB5ULL + 0xEE10FE9FA12489D7ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xF1A349A12AF0E5E5ULL + 0xBE7003155207D4A9ULL);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3748U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1577U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 16U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((aIndex + 42U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 42U)) + (RotL64(aIngress, 29U) ^ RotL64(aCarry, 57U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterH = ((aWandererI + RotL64(aCross, 29U)) + RotL64(aCarry, 35U)) + 7948891781097675369U;
            aOrbiterK = ((((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 3U)) + 13928362874228230226U) + aPhaseBOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterG = (((aWandererG + RotL64(aPrevious, 12U)) + RotL64(aCarry, 47U)) + 10776180542602258926U) + aNonceWordF;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 39U)) + 5735115172149470447U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 3U)) + 5353591822981766987U) + aNonceWordA;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 562301708107268570U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterH) ^ 10467810247578364868U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 10449089554007059823U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 14541630141152308564U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 2350076897065139429U;
            aOrbiterH = RotL64((aOrbiterH * 12222554362482034393U), 37U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterG) + 17519109078651162228U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1]) + aNonceWordC;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 6061035173339902910U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10021905773432907835U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 15654836633731000065U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 13723521735153718904U;
            aOrbiterK = RotL64((aOrbiterK * 14459516479283070563U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 2849680038315532197U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 17336102435576647923U;
            aOrbiterD = RotL64((aOrbiterD * 10984689101753586739U), 5U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 57U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 28U));
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((((RotL64(aPrevious, 27U) + aOrbiterG) + RotL64(aOrbiterD, 23U)) + RotL64(aCarry, 57U)) + aNonceWordL) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 36U) + RotL64(aOrbiterD, 3U)) + aOrbiterK);
            aWandererI = aWandererI + ((((RotL64(aCross, 51U) + aOrbiterK) + RotL64(aOrbiterI, 43U)) + RotL64(aCarry, 43U)) + aPhaseBWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 57U)) + aOrbiterH) + aNonceWordP);
            aWandererC = aWandererC + ((RotL64(aScatter, 11U) + RotL64(aOrbiterD, 34U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 28U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 7615U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneD[((aIndex + 6115U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8265U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneB[((aIndex + 10541U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 18U) + RotL64(aIngress, 3U)) ^ (RotL64(aCross, 39U) ^ RotL64(aPrevious, 53U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 53U)) + RotL64(aCarry, 37U)) + 12029393034357490020U;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 35U)) + 4526754731580694987U) + aPhaseBOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = (aWandererC + RotL64(aCross, 3U)) + 17060419646421271853U;
            aOrbiterA = ((((aWandererE + RotL64(aScatter, 13U)) + RotL64(aCarry, 5U)) + 4128488893837059683U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordP;
            aOrbiterE = (((aWandererF + RotL64(aCross, 24U)) + RotL64(aCarry, 57U)) + 12706894827547160110U) + aNonceWordH;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 12506324593645825056U) + aNonceWordM;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 12581344490649250025U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16311882267466003291U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 14357032418199130132U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 15341977701796331249U;
            aOrbiterE = RotL64((aOrbiterE * 6332369248718076031U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 7086602307544733241U) + aNonceWordD;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 12398300065276832486U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 18157408831225635333U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 2499745046076601988U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 7249361592814001829U;
            aOrbiterG = RotL64((aOrbiterG * 14597139848072319685U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 3254456186337366437U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 3472973415969046680U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14583566953969168353U), 13U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterE, 29U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + RotL64(aOrbiterA, 54U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 40U) + aOrbiterI) + RotL64(aOrbiterA, 37U)) + aNonceWordC);
            aWandererD = aWandererD + ((((RotL64(aCross, 27U) + aOrbiterA) + RotL64(aOrbiterG, 47U)) + RotL64(aCarry, 27U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 56U)) + aOrbiterI);
            aWandererF = aWandererF + (((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ ((((RotL64(aScatter, 53U) + aOrbiterH) + RotL64(aOrbiterA, 27U)) + aNonceWordF) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 53U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordD);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12999U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10996U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15615U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12987U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCarry, 23U)) ^ (RotL64(aPrevious, 53U) ^ RotL64(aCross, 6U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterD = (((aWandererJ + RotL64(aPrevious, 53U)) + RotL64(aCarry, 21U)) + 6469584119078165548U) + aNonceWordL;
            aOrbiterK = ((((aWandererA + RotL64(aScatter, 13U)) + RotL64(aCarry, 43U)) + 14329756366517987910U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordI;
            aOrbiterI = (((aWandererB + RotL64(aIngress, 28U)) + RotL64(aCarry, 5U)) + 12890831797059772123U) + aPhaseBOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aCross, 37U)) + 3164503807500018990U;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 3U)) + 177531431387646836U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 3167421392893561015U) + aNonceWordB;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 2813174781844753460U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9760688894575305115U), 11U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterD) + 10953270419153249857U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordD;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 16911518309710356951U;
            aOrbiterK = RotL64((aOrbiterK * 13162785997686570445U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 6616750447844893150U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 10276741398025985982U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6824712685896987133U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 6206043608461213208U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 12021552904553405793U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10023362889960174909U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 15283586234744144846U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 5923238786775948571U;
            aOrbiterB = RotL64((aOrbiterB * 8200882393521882651U), 3U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 21U);
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 4U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 11U)) + aOrbiterD) + aNonceWordK) + aPhaseBWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 4U) + RotL64(aOrbiterI, 56U)) + aOrbiterJ) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 27U)) + aOrbiterJ) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 27U) + aOrbiterI) + RotL64(aOrbiterB, 41U)) + RotL64(aCarry, 39U)) + aNonceWordN);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 35U) + aOrbiterJ) + RotL64(aOrbiterB, 3U)) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 50U));
            aCarry = aCarry + RotL64(aWandererB, 21U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 19173U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneB[((aIndex + 17322U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16627U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19085U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCross, 10U)) + (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 23U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterD = (aWandererC + RotL64(aCross, 11U)) + 13278949403988203974U;
            aOrbiterA = ((((aWandererD + RotL64(aScatter, 19U)) + RotL64(aCarry, 53U)) + 9213599924054673756U) + aPhaseBOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterF = ((((aWandererH + RotL64(aIngress, 28U)) + RotL64(aCarry, 11U)) + 1255746482932381798U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordO;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 53U)) + RotL64(aCarry, 35U)) + 11575321997144516122U;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 3U)) + 15881587525529432437U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 9846195809864862707U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 12319815691858217670U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14271546305640811091U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 16322617427294439587U) + aNonceWordN;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 16332130810525887437U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7588076439690559343U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 4920951156015336794U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 16767126455124552329U;
            aOrbiterG = RotL64((aOrbiterG * 4440352337076842603U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 12553595911087945223U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 1437522202135436142U) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 2001992794165550905U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 12313100454852227143U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 2761983020631055729U;
            aOrbiterJ = RotL64((aOrbiterJ * 3874839760378039509U), 47U);
            //
            aIngress = RotL64(aOrbiterF, 41U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterA, 24U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterJ, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aIngress, 24U) + RotL64(aOrbiterG, 30U)) + aOrbiterD) + aPhaseBWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 51U) + aOrbiterA) + RotL64(aOrbiterD, 13U)) + RotL64(aCarry, 57U)) + aNonceWordB);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterG, 43U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 23U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterG, 21U)) + aOrbiterJ) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 24360U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23157U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23439U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneA[((aIndex + 25456U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 4U) + RotL64(aCross, 21U)) ^ (RotL64(aCarry, 35U) + RotL64(aPrevious, 47U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterJ = (((aWandererK + RotL64(aPrevious, 13U)) + RotL64(aCarry, 41U)) + 15045917390223766480U) + aNonceWordI;
            aOrbiterI = ((aWandererI + RotL64(aCross, 29U)) + 10763054007033668758U) + aNonceWordC;
            aOrbiterB = ((((aWandererH + RotL64(aScatter, 5U)) + RotL64(aCarry, 21U)) + 13190170142593666607U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordO;
            aOrbiterD = ((aWandererF + RotL64(aIngress, 43U)) + RotL64(aCarry, 53U)) + 9657025731441167065U;
            aOrbiterK = ((aWandererG + RotL64(aScatter, 60U)) + 11433367178975954211U) + aPhaseBOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 17904920143996810366U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 3244383020512113283U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 552521443123433353U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 6538815775171139091U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 7195368312757976343U) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 10515679176134176565U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 18134430713910279374U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 6571776588427107976U;
            aOrbiterJ = RotL64((aOrbiterJ * 11916502085252589161U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 11830778129647517758U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 9793702760907767365U;
            aOrbiterI = RotL64((aOrbiterI * 4096246227968677179U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 2287235876793192036U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterK) ^ 8951959188326141794U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 9968356718110753845U), 21U);
            //
            aIngress = RotL64(aOrbiterD, 13U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterD, 46U)) + aOrbiterB) + aNonceWordM);
            aWandererK = aWandererK + (((RotL64(aScatter, 58U) + RotL64(aOrbiterI, 37U)) + aOrbiterD) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterI, 27U)) + aPhaseBWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            aWandererI = aWandererI + (((((RotL64(aIngress, 27U) + aOrbiterB) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 43U)) + aNonceWordG) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterI, 57U)) + aOrbiterK) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 38U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 31739U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32144U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28934U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((aIndex + 28204U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 13U) + RotL64(aPrevious, 39U)) ^ (RotL64(aCarry, 27U) ^ RotL64(aIngress, 54U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterA = ((aWandererH + RotL64(aCross, 43U)) + 16124889768301047791U) + aNonceWordK;
            aOrbiterI = ((((aWandererE + RotL64(aIngress, 19U)) + RotL64(aCarry, 27U)) + 11912338587186717280U) + aPhaseBOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1]) + aNonceWordN;
            aOrbiterG = (((aWandererK + RotL64(aPrevious, 29U)) + 8594012868813114354U) + aPhaseBOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 5U)) + RotL64(aCarry, 11U)) + 18281043566156682815U;
            aOrbiterF = ((aWandererF + RotL64(aCross, 58U)) + RotL64(aCarry, 51U)) + 16853106130200942302U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 2611212958619673086U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 18039472325066855180U;
            aOrbiterG = RotL64((aOrbiterG * 10213999643376367785U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 14495785571345122046U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 4556063793412832418U;
            aOrbiterI = RotL64((aOrbiterI * 13166927543135467627U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 14896419970271244358U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 880028529183500036U;
            aOrbiterA = RotL64((aOrbiterA * 14228281807461251361U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 2379557167489415783U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 11854373946064529806U;
            aOrbiterB = RotL64((aOrbiterB * 150755294320438887U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 1487252775956449964U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = (((aOrbiterF ^ aOrbiterI) ^ 12777924204511625545U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 1366019527386994789U), 21U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 34U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + RotL64(aOrbiterA, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aScatter, 13U) + aOrbiterB) + RotL64(aOrbiterG, 48U)) + RotL64(aCarry, 5U)) + aNonceWordH);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 5U) + aOrbiterF) + RotL64(aOrbiterI, 27U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 29U) + aOrbiterA) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterG, 11U)) + aOrbiterF) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 50U) + RotL64(aOrbiterI, 3U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + RotL64(aWandererH, 13U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordI);
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

void TwistExpander_Softball_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xBCD4E6DC5FFF6E73ULL + 0xE20B27C16A3F8614ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xC5AA4BE36E577071ULL + 0xEFD3C91B46E6315DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x919DCB274F9D35C7ULL + 0xA885FCF3D4925047ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xF56BA9A79993A289ULL + 0xE50C00458760AFEEULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x98D0BAA837296707ULL + 0xD6563D9D0FE3B4E5ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xAD32EAB4B4C9D42FULL + 0xF960794722EC741EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xE9EF7A3D9B0F53EFULL + 0xDA6422D3784D9FA3ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xBF439B3A9214CFBBULL + 0xA48BCB194C249F1BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xAD338615718D1641ULL + 0x83126BE3AD3DDD91ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x958B2A042FC15C6BULL + 0xC69A9AE5F4B1DC93ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xD188362A149E0F9DULL + 0xC336DCF12838D8A6ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xA127A33E5C0B2739ULL + 0xE83671DDA26FD102ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xA7B7DC84CF9F98CBULL + 0x88BB35F095AE75ECULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x9BC15504631EE797ULL + 0xC8A254FBC8558843ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xE08AE6A7D9A6D7C9ULL + 0xA0228164E8DBEE70ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x86A4D6BDF902B62BULL + 0xBAC99F1B88EA1505ULL);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 6136U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneC[((aIndex + 2163U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6869U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneA[((aIndex + 3109U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCross, 56U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCarry, 19U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 18U)) + 3339283916456813609U;
            aOrbiterC = (aWandererH + RotL64(aScatter, 51U)) + 11339086426180649584U;
            aOrbiterB = (aWandererE + RotL64(aCross, 41U)) + 16819191669329316585U;
            aOrbiterK = (((aWandererK + RotL64(aIngress, 37U)) + RotL64(aCarry, 41U)) + 8361916937762630725U) + aNonceWordF;
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 11U)) + RotL64(aCarry, 57U)) + 18031328374429899857U;
            aOrbiterI = (aWandererF + RotL64(aIngress, 47U)) + 18261756894092897276U;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 3U)) + 4250319792907645666U) + aPhaseCOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = ((((aWandererA + RotL64(aCross, 28U)) + RotL64(aCarry, 27U)) + 1492411503643460886U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordH;
            aOrbiterG = (aWandererB + RotL64(aScatter, 57U)) + 17369549067879344180U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 7301713524358676722U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 2985193736033012535U;
            aOrbiterB = RotL64((aOrbiterB * 7473297294949338265U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 14086975808140927408U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 10390516547834639800U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11441293212275890819U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 18205555540941493267U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 16967799565443938873U;
            aOrbiterE = RotL64((aOrbiterE * 3009081009044782443U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 9209505304067579944U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 3522631966146762306U;
            aOrbiterG = RotL64((aOrbiterG * 3441982898533162599U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 8811497120829041188U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 14707301680850257294U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11383709499376464085U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 10080595991787801029U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 6822892187784299166U;
            aOrbiterK = RotL64((aOrbiterK * 7417016898027778287U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 1981637172055758689U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 16463077485583119324U;
            aOrbiterA = RotL64((aOrbiterA * 2876782050665869121U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 8383837717361569465U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 2788511294985017326U) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 2809163242875130677U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 3529607472855930041U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 8850940802020173766U;
            aOrbiterF = RotL64((aOrbiterF * 7821450253655655943U), 13U);
            //
            aIngress = RotL64(aOrbiterC, 26U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterB, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterE, 19U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 34U) + aOrbiterI) + RotL64(aOrbiterB, 34U));
            aWandererK = aWandererK + (((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterF, 3U)) + aPhaseCWandererUpdateSaltC[((aIndex + 24U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 57U)) + aOrbiterJ);
            aWandererH = aWandererH + (((RotL64(aCross, 19U) + RotL64(aOrbiterI, 39U)) + aOrbiterA) + aNonceWordK);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 43U) + aOrbiterC) + RotL64(aOrbiterG, 51U)) + aNonceWordM);
            aWandererF = aWandererF + (((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 47U)) + aOrbiterG) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 11U)) + aOrbiterJ) + aNonceWordD) + aPhaseCWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 58U) + RotL64(aOrbiterK, 24U)) + aOrbiterE) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 41U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 10U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordG);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10673U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneD[((aIndex + 16289U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 13513U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((aIndex + 10483U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 26U) ^ RotL64(aCarry, 39U)) + (RotL64(aCross, 3U) ^ RotL64(aPrevious, 51U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterH = ((aWandererB + RotL64(aScatter, 35U)) + 4848316479321533394U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = (((aWandererC + RotL64(aIngress, 23U)) + RotL64(aCarry, 57U)) + 6919360256662636195U) + aNonceWordI;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 6U)) + 9897013582181108544U;
            aOrbiterB = (((aWandererG + RotL64(aCross, 47U)) + RotL64(aCarry, 11U)) + 7319353809896158678U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aScatter, 43U)) + 2848175435514849859U;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 51U)) + 6967780718720437934U) + aNonceWordN;
            aOrbiterA = (aWandererI + RotL64(aIngress, 60U)) + 10143884766603388136U;
            aOrbiterJ = (aWandererK + RotL64(aCross, 19U)) + 8675965006150972051U;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 29U)) + RotL64(aCarry, 39U)) + 16350117755560994281U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 17976597517118423760U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 1399631141355370237U;
            aOrbiterD = RotL64((aOrbiterD * 16537788276543236833U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 3590613762034716792U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 5134624314245932157U;
            aOrbiterF = RotL64((aOrbiterF * 13077589037975283371U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 10082236952942943654U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 4015535035905433450U;
            aOrbiterA = RotL64((aOrbiterA * 4961808568701908559U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 611474103801573800U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 5786708483794098001U;
            aOrbiterJ = RotL64((aOrbiterJ * 7694007039340089267U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 5201943497363274455U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 9282160506938328489U;
            aOrbiterG = RotL64((aOrbiterG * 5368182164239021367U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 4932320527498940158U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 11576526341731392916U;
            aOrbiterH = RotL64((aOrbiterH * 1712051774729439363U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 10790691517638887125U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 16280649213607464422U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10756733801499471873U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 9553716940667712810U) + aNonceWordF;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 11827518270964003341U;
            aOrbiterI = RotL64((aOrbiterI * 1322489827908132831U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 16777463701235809321U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 3375489084588454149U;
            aOrbiterE = RotL64((aOrbiterE * 3335010977457647307U), 47U);
            //
            aIngress = RotL64(aOrbiterB, 19U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterG, 24U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 22U) + RotL64(aOrbiterJ, 19U)) + aOrbiterE) + aPhaseCWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 29U) + aOrbiterD) + RotL64(aOrbiterJ, 13U));
            aWandererK = aWandererK + (((RotL64(aCross, 57U) + RotL64(aOrbiterJ, 28U)) + aOrbiterF) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 51U) + aOrbiterB) + RotL64(aOrbiterG, 5U)) + aNonceWordA);
            aWandererC = aWandererC + (((RotL64(aIngress, 38U) + aOrbiterI) + RotL64(aOrbiterJ, 37U)) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 53U)) + aOrbiterA) + aNonceWordG);
            aWandererI = aWandererI + (((RotL64(aCross, 47U) + RotL64(aOrbiterJ, 24U)) + aOrbiterA) + aPhaseCWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterG, 57U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterJ, 47U)) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 14U));
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 51U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordD;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 21578U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21048U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 22849U)) & S_BLOCK1], 20U) ^ RotL64(aOperationLaneC[((aIndex + 18998U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCross, 36U)) + (RotL64(aIngress, 11U) + RotL64(aCarry, 23U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterI = (aWandererA + RotL64(aScatter, 29U)) + 9107326720193244489U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 36U)) + 10868585484401664145U) + aNonceWordB;
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 43U)) + RotL64(aCarry, 43U)) + 13637736741437846622U;
            aOrbiterH = (aWandererC + RotL64(aCross, 13U)) + 6130725216183918844U;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 23U)) + 2063834478521338187U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aIngress, 19U)) + RotL64(aCarry, 11U)) + 8564870627911949158U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 3U)) + 6524015751064086390U) + aPhaseCOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aCross, 60U)) + RotL64(aCarry, 29U)) + 9874937766875388236U;
            aOrbiterK = (aWandererE + RotL64(aPrevious, 53U)) + 14723718409522680894U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 13767059954741528279U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 6387608251033722169U;
            aOrbiterF = RotL64((aOrbiterF * 6601902195707980693U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 5391425980008431000U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 11524218415655093779U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12508457981779189389U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 155510463350385905U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 10554591788433641311U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5412084824127934293U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 8662160162966241542U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 5092555636369853727U;
            aOrbiterA = RotL64((aOrbiterA * 433807340167635499U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 7163345798448796101U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 695089002178413267U;
            aOrbiterG = RotL64((aOrbiterG * 17302689458565434475U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 5409173939213468972U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 15349690077393827541U;
            aOrbiterB = RotL64((aOrbiterB * 10984681254001609841U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 12376011890751302027U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 7809614158898158383U;
            aOrbiterC = RotL64((aOrbiterC * 13845113198736843629U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 13031938699536449576U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 3983178190194056516U;
            aOrbiterD = RotL64((aOrbiterD * 1341678482929213405U), 43U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterH) + 5567935037909671790U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordI;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 17137042627663349797U;
            aOrbiterK = RotL64((aOrbiterK * 13535586899620672373U), 23U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 13U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 5U));
            aIngress = aIngress + (RotL64(aOrbiterH, 46U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterB, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 23U) + aOrbiterA) + RotL64(aOrbiterH, 12U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 4U) + RotL64(aOrbiterA, 35U)) + aOrbiterC) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterF, 27U)) + aOrbiterD);
            aWandererE = aWandererE + (((RotL64(aCross, 19U) + RotL64(aOrbiterF, 21U)) + aOrbiterA) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterC, 43U)) + aPhaseCWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 10U) + RotL64(aOrbiterB, 58U)) + aOrbiterC);
            aWandererI = aWandererI ^ (((RotL64(aCross, 27U) + aOrbiterD) + RotL64(aOrbiterC, 53U)) + aNonceWordA);
            aWandererB = aWandererB + (((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 47U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 36U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 39U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordP);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 31316U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28421U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29960U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 25110U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aIngress, 23U)) + (RotL64(aPrevious, 6U) ^ RotL64(aCarry, 37U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterJ = (aWandererC + RotL64(aCross, 28U)) + 2330952702412094686U;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 47U)) + RotL64(aCarry, 53U)) + 7820188225935060799U;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 5U)) + RotL64(aCarry, 39U)) + 9347644591709839145U;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 19U)) + 2288624878446846870U) + aNonceWordN;
            aOrbiterA = (((aWandererD + RotL64(aCross, 58U)) + RotL64(aCarry, 13U)) + 9358977729492824128U) + aNonceWordG;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 35U)) + 1858511275052455039U) + aPhaseCOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aIngress, 23U)) + 13715478509322292552U;
            aOrbiterI = (aWandererJ + RotL64(aScatter, 13U)) + 16413396625604260455U;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 51U)) + 17714322215518432705U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 16188315436202861122U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 5564445841368207813U;
            aOrbiterC = RotL64((aOrbiterC * 14125834616162835983U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 13717068949900594673U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 14143659432287313765U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17281441046722262917U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 5729546141908425670U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 4297827922736712074U;
            aOrbiterH = RotL64((aOrbiterH * 13631630436759768885U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 829520109395163673U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 11547160328525174295U) ^ aNonceWordP;
            aOrbiterJ = RotL64((aOrbiterJ * 4759690159673049775U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 2907177944512117206U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 11100346409065275671U;
            aOrbiterK = RotL64((aOrbiterK * 17927994356809011637U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 1344592529249949068U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 6470438516791143572U;
            aOrbiterB = RotL64((aOrbiterB * 13339390828725370475U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 5217751823741520847U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterC) ^ 5371275223586938039U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 12318403075523724125U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 14218103150268532919U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 1367628876596800571U;
            aOrbiterF = RotL64((aOrbiterF * 13777531272321533137U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 2372041991018455610U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 9870744274890595581U) ^ aNonceWordK;
            aOrbiterE = RotL64((aOrbiterE * 12093443117747395585U), 39U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterC, 41U);
            aIngress = aIngress + (RotL64(aOrbiterK, 20U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 4U) + aOrbiterI) + RotL64(aOrbiterH, 47U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 39U) + aOrbiterH) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 3U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 11U) + aOrbiterH) + RotL64(aOrbiterE, 57U)) + aPhaseCWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterB, 38U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 30U) + RotL64(aOrbiterC, 27U)) + aOrbiterA) + aNonceWordF);
            aWandererB = aWandererB + (((RotL64(aCross, 19U) + RotL64(aOrbiterK, 21U)) + aOrbiterA) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 51U)) + aOrbiterJ);
            aWandererK = aWandererK + (((RotL64(aIngress, 51U) + aOrbiterH) + RotL64(aOrbiterB, 43U)) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterA, 10U)) + aOrbiterF) + aNonceWordE);
            //
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 14U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordD);
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

void TwistExpander_Softball_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x94820DB477E6E3D1ULL + 0xBF69609A2FEAF951ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xD6D4BD98DBD6C67FULL + 0xDF2D4608EF1B878EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xA703927290A94A21ULL + 0xDBF873146F0720A6ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x911193F7A1F16823ULL + 0x98BCE6C199882C13ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xFE31903D327FC2CBULL + 0xE0D4D8E6D77F3380ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE109AE2F4C6A1F69ULL + 0xA7ED8ADBED9340FEULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x87D9FA8A47D669FDULL + 0xCE9D3CB815FF86CEULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x9FBBADF1B2DCCD75ULL + 0xF13E310CA4C7B386ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x88540631F0399AF3ULL + 0xC72D6730FD0BD1E9ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xC105DB31D001C165ULL + 0xF1745F6A67D0CF00ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xA653594F6FF0794DULL + 0xB420DFCDE71638E8ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x815A245013AE0E71ULL + 0xF84F79DC4D40F72BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xC8B3E6A45250805BULL + 0xED7F866386FB3CCAULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x8C72CD6DA7DF3819ULL + 0xA5C08C8006B3D9C5ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xB6F2E0488A7168F1ULL + 0xC4EE81C6966D43A6ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xDB798B3CF3EE9BEFULL + 0xB275902E22590B8CULL);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2801U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((aIndex + 4299U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 914U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneA[((aIndex + 5278U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 13U) + RotL64(aCross, 43U)) + (RotL64(aIngress, 29U) ^ RotL64(aCarry, 58U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterF = (aWandererF + RotL64(aPrevious, 56U)) + 7893287783892523139U;
            aOrbiterG = (aWandererI + RotL64(aIngress, 23U)) + 10257331997383491153U;
            aOrbiterA = ((aWandererC + RotL64(aCross, 47U)) + 14562226733652231753U) + aPhaseDOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = ((((aWandererH + RotL64(aScatter, 35U)) + RotL64(aCarry, 29U)) + 14320342577110737851U) + aPhaseDOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1]) + aNonceWordK;
            aOrbiterH = ((aWandererD + RotL64(aCross, 3U)) + RotL64(aCarry, 21U)) + 9816717579822880756U;
            aOrbiterK = (aWandererB + RotL64(aPrevious, 37U)) + 9558926960095881953U;
            aOrbiterI = (aWandererE + RotL64(aScatter, 29U)) + 9230371862654338324U;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 52U)) + 6414274291252913420U;
            aOrbiterB = (aWandererA + RotL64(aScatter, 19U)) + 13868546184398350849U;
            aOrbiterD = (aWandererG + RotL64(aCross, 21U)) + 16940736952569949038U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 41U)) + RotL64(aCarry, 43U)) + 2866957764814864371U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 7916721976073979724U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 1602444214978842275U;
            aOrbiterA = RotL64((aOrbiterA * 11072503711308122385U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 9529061385251008037U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 8402775110887376588U;
            aOrbiterK = RotL64((aOrbiterK * 13980225144628227381U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 15003592180290390713U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 14195681406520825751U;
            aOrbiterF = RotL64((aOrbiterF * 11455000833788877217U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 3263577002367714202U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 12019422062655581928U;
            aOrbiterE = RotL64((aOrbiterE * 5002313835338447799U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 8508638054582582917U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 6536618106353552880U;
            aOrbiterI = RotL64((aOrbiterI * 6233964121117511885U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 9654542989321430868U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 7019594782797863244U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1234877854354279981U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 8256061220727519919U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 9232754129467036130U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17556001874302369781U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 5608829951337740378U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 12632120498473345701U;
            aOrbiterG = RotL64((aOrbiterG * 6994794653605831925U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 17313364434369677697U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 10147405701828074385U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11544579984323623009U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 16853703086012867980U) + aNonceWordN;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 3591438641820423822U;
            aOrbiterJ = RotL64((aOrbiterJ * 3570430739475340845U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 13974806289212867511U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 7893287783892523139U) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 6648351608953339723U), 23U);
            //
            aIngress = RotL64(aOrbiterB, 3U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterH, 34U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + (RotL64(aOrbiterF, 21U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterE, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterH, 3U));
            aWandererK = aWandererK + (((RotL64(aCross, 41U) + RotL64(aOrbiterH, 27U)) + aOrbiterE) + aNonceWordA);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 18U) + aOrbiterF) + RotL64(aOrbiterK, 29U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterA, 35U)) + aOrbiterD) + aNonceWordP) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterJ, 14U)) + aOrbiterK) + aNonceWordE);
            aWandererF = aWandererF + (((RotL64(aIngress, 21U) + RotL64(aOrbiterE, 53U)) + aOrbiterK) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterD, 23U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterB, 43U)) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterJ, 12U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 57U)) + aOrbiterG);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 30U) + RotL64(aOrbiterA, 41U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererI, 26U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 30U));
            aCarry = aCarry + RotL64(aWandererH, 39U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordE;
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 5570U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneD[((aIndex + 10443U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7746U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneB[((aIndex + 7801U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 6U) ^ RotL64(aCarry, 37U)) + (RotL64(aPrevious, 23U) + RotL64(aCross, 51U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterI = ((aWandererF + RotL64(aScatter, 21U)) + 12426357877879529292U) + aNonceWordM;
            aOrbiterK = (((aWandererK + RotL64(aPrevious, 51U)) + RotL64(aCarry, 53U)) + 12604900366173639176U) + aNonceWordN;
            aOrbiterJ = (aWandererG + RotL64(aIngress, 29U)) + 13511119007338929401U;
            aOrbiterC = (aWandererB + RotL64(aCross, 19U)) + 9878720081166788060U;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 26U)) + 15463195409806395076U;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 47U)) + 6407922778852833423U;
            aOrbiterA = (aWandererH + RotL64(aCross, 39U)) + 7690427254160734016U;
            aOrbiterH = (aWandererE + RotL64(aIngress, 37U)) + 18030974031722143619U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 6U)) + 17983938038322737041U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 53U)) + 16605512170117753884U) + aNonceWordA;
            aOrbiterF = (((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 13U)) + 681802273302348322U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 15550312921312083819U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 17824154101711884508U;
            aOrbiterJ = RotL64((aOrbiterJ * 7358612830654795357U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 1939207786756735430U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 3132864634777826569U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13606281919426730325U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 12822929773923954849U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 16576106045887115660U;
            aOrbiterE = RotL64((aOrbiterE * 16370914370769903051U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 2398825881649235260U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 13700821892926092479U;
            aOrbiterA = RotL64((aOrbiterA * 10830623703416956043U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 2439833784883391606U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 15870638514107637833U) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 3797380922767479287U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 9165457123134229670U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 8736642509192659417U;
            aOrbiterI = RotL64((aOrbiterI * 16219277537523484065U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 9232719746484835693U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 7826680628853322541U) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 12578050118133526187U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 14323652326982518782U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 2254524512851399313U;
            aOrbiterD = RotL64((aOrbiterD * 4119339547645451149U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 14459632243829356472U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 8591197056749497716U;
            aOrbiterH = RotL64((aOrbiterH * 13053836520694721881U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 17220196418897000411U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 7186579019945992185U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12406048515179065691U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 7554005180895698880U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 12426357877879529292U) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 5090046967147694465U), 11U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 41U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 58U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 53U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 14U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 3U)) + aOrbiterG);
            aWandererB = aWandererB + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterK, 13U)) + aOrbiterB) + RotL64(aCarry, 13U)) + aNonceWordD);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterC, 39U)) + aOrbiterE);
            aWandererH = aWandererH + (((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterH, 43U)) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 4U) + aOrbiterE) + RotL64(aOrbiterA, 46U));
            aWandererG = aWandererG + (((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterF, 5U)) + aPhaseDWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 29U)) + aOrbiterI) + aPhaseDWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 21U)) + aOrbiterB) + aNonceWordJ);
            aWandererE = aWandererE ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterF, 23U)) + aOrbiterJ);
            aWandererK = aWandererK + ((RotL64(aIngress, 46U) + RotL64(aOrbiterG, 19U)) + aOrbiterA);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 37U) + aOrbiterD) + RotL64(aOrbiterK, 36U)) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 6U));
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + (RotL64(aWandererB, 50U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 19U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordF);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 12867U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 12309U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15439U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((aIndex + 12147U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aIngress, 19U)) ^ (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 50U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 5U)) + 12131317914288566437U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = ((aWandererG + RotL64(aIngress, 19U)) + RotL64(aCarry, 53U)) + 5672805657999385496U;
            aOrbiterH = ((aWandererB + RotL64(aCross, 3U)) + RotL64(aCarry, 11U)) + 3581710244233124197U;
            aOrbiterB = (aWandererH + RotL64(aScatter, 39U)) + 15251296040538489436U;
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 51U)) + 11295008604679904153U;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 13U)) + 2230897493419504490U) + aNonceWordO;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 44U)) + 7109600123297458999U) + aPhaseDOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aCross, 23U)) + 13119156643107683803U;
            aOrbiterJ = (aWandererD + RotL64(aIngress, 35U)) + 14755160867807355250U;
            aOrbiterA = (aWandererE + RotL64(aCross, 41U)) + 16829363373287496832U;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 58U)) + RotL64(aCarry, 23U)) + 16981122946707720883U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 8806000776958603317U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterG) ^ 16810923047720876014U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterH = RotL64((aOrbiterH * 17872735050219539145U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 8129657889554436328U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 8653100378491974463U;
            aOrbiterD = RotL64((aOrbiterD * 11395283153912468661U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 17048985838727432415U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 10892675550889823573U) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 976298937314081913U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 15960158965421254346U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 12290011578634850001U;
            aOrbiterF = RotL64((aOrbiterF * 9280475585104357745U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 16265047040311479093U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 10312956912303656248U;
            aOrbiterE = RotL64((aOrbiterE * 3012584393253845131U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 16706890352221352779U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 10630955894218491929U;
            aOrbiterA = RotL64((aOrbiterA * 12675937483456206355U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 4009352551041162434U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 3043810773683888556U;
            aOrbiterG = RotL64((aOrbiterG * 4328135390387997315U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 1398071019814944785U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 16689766557488135301U;
            aOrbiterB = RotL64((aOrbiterB * 8403881916549404871U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 15934647144489136524U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 13521276033614992223U;
            aOrbiterI = RotL64((aOrbiterI * 18003640895553609933U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 4281211055727414100U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 11848150507497406421U;
            aOrbiterJ = RotL64((aOrbiterJ * 1107789990317433481U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 12022829841608199449U) + aNonceWordH;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 12131317914288566437U;
            aOrbiterK = RotL64((aOrbiterK * 13275753083882829973U), 47U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterB, 30U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aScatter, 41U) + RotL64(aOrbiterA, 23U)) + aOrbiterI);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 14U) + aOrbiterH) + RotL64(aOrbiterK, 4U));
            aWandererH = aWandererH + (((((RotL64(aIngress, 11U) + RotL64(aOrbiterC, 27U)) + aOrbiterJ) + RotL64(aCarry, 5U)) + aNonceWordL) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 51U) + aOrbiterA) + RotL64(aOrbiterH, 43U)) + aPhaseDWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 53U)) + aOrbiterJ);
            aWandererG = aWandererG ^ ((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterI, 58U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 21U)) + aOrbiterE);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 23U) + aOrbiterG) + RotL64(aOrbiterH, 35U));
            aWandererI = aWandererI + ((RotL64(aCross, 58U) + aOrbiterK) + RotL64(aOrbiterB, 19U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterC, 37U)) + aOrbiterK) + aNonceWordE);
            aWandererC = aWandererC + (((RotL64(aScatter, 37U) + aOrbiterA) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 42U));
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererG, 30U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 16662U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneB[((aIndex + 21227U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18501U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((aIndex + 21157U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aIngress, 23U)) + (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 6U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterG = (aWandererI + RotL64(aCross, 37U)) + 18087125778766689269U;
            aOrbiterK = (aWandererK + RotL64(aIngress, 56U)) + 13710545066503235196U;
            aOrbiterD = (aWandererC + RotL64(aScatter, 43U)) + 1701939704736254645U;
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 3U)) + 8064093611384019909U) + aNonceWordN;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 35U)) + 16623332751533885431U;
            aOrbiterA = ((aWandererA + RotL64(aCross, 6U)) + RotL64(aCarry, 41U)) + 15590129153794910109U;
            aOrbiterB = (((aWandererF + RotL64(aScatter, 23U)) + RotL64(aCarry, 27U)) + 7413312683079107383U) + aPhaseDOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 41U)) + 4186064478651458810U;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 19U)) + 5501191643940735954U) + aNonceWordB;
            aOrbiterF = (((aWandererE + RotL64(aPrevious, 29U)) + RotL64(aCarry, 3U)) + 11064645242200570835U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aCross, 47U)) + 13825922087298055833U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 5944980709887369970U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 8181136916070569646U;
            aOrbiterD = RotL64((aOrbiterD * 395183021205661827U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 15442336949157292482U) + aNonceWordJ;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 11580554435240641337U;
            aOrbiterH = RotL64((aOrbiterH * 6654637892858767739U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 11240018128174598322U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 2027565596050777471U;
            aOrbiterA = RotL64((aOrbiterA * 18048186560314431815U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 16425887196883725233U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 16828683527588834095U;
            aOrbiterB = RotL64((aOrbiterB * 17746289103235902485U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 9923829146479008804U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 6669171007279929454U;
            aOrbiterJ = RotL64((aOrbiterJ * 681823450939955099U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 3902430046523165149U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 6739998149289590041U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2675037435528416821U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 16014401255534234075U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 14741857638680634564U;
            aOrbiterF = RotL64((aOrbiterF * 8723611021403369393U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 5064807861673260054U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 968747317273200299U;
            aOrbiterI = RotL64((aOrbiterI * 14122304002722582329U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 5282686212362051427U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 6902253563196129760U;
            aOrbiterG = RotL64((aOrbiterG * 7682808024658992049U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 4995580401402368332U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 14949762584793646470U;
            aOrbiterK = RotL64((aOrbiterK * 3539183342072953803U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 2378815735788107402U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 18087125778766689269U;
            aOrbiterC = RotL64((aOrbiterC * 16799380528404446281U), 13U);
            //
            aIngress = RotL64(aOrbiterH, 58U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterG, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterJ, 60U)) + aOrbiterH) + RotL64(aCarry, 27U)) + aPhaseDWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 51U) + aOrbiterG) + RotL64(aOrbiterI, 13U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 48U) + aOrbiterK) + RotL64(aOrbiterE, 3U)) + RotL64(aCarry, 19U)) + aNonceWordC);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterB, 5U)) + aOrbiterC);
            aWandererF = aWandererF + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 51U)) + aOrbiterA);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterH, 37U)) + aOrbiterD);
            aWandererE = aWandererE + (((RotL64(aCross, 21U) + aOrbiterI) + RotL64(aOrbiterJ, 41U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterH, 48U)) + aOrbiterG);
            aWandererA = aWandererA + ((RotL64(aPrevious, 46U) + RotL64(aOrbiterA, 21U)) + aOrbiterB);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterF, 23U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterH, 43U)) + aNonceWordE);
            //
            aCarry = aCarry + (RotL64(aWandererD, 48U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 46U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 25228U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 26472U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 23112U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24499U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 18U) + RotL64(aPrevious, 39U)) ^ (RotL64(aCross, 57U) + RotL64(aIngress, 5U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterE = (aWandererI + RotL64(aIngress, 43U)) + 12380376990224645149U;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 22U)) + 18296928500297384014U) + aNonceWordF;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 35U)) + RotL64(aCarry, 11U)) + 3550626816361145100U;
            aOrbiterF = ((aWandererA + RotL64(aCross, 39U)) + RotL64(aCarry, 21U)) + 2667792936946706027U;
            aOrbiterC = (((aWandererK + RotL64(aIngress, 51U)) + RotL64(aCarry, 37U)) + 12020969779370926953U) + aNonceWordN;
            aOrbiterJ = (aWandererG + RotL64(aCross, 11U)) + 737340727886903447U;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 13U)) + 1681797651799760502U) + aPhaseDOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 5U)) + 2956186342689489064U) + aNonceWordC;
            aOrbiterK = (aWandererH + RotL64(aScatter, 47U)) + 1876852870402977177U;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 30U)) + 6433205819353555071U;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 57U)) + 9065076854974222998U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 3254410578766789992U) + aNonceWordG;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 2005081975473815576U) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 9947701153722014085U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 15992999234834560419U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 3458344156815120948U;
            aOrbiterJ = RotL64((aOrbiterJ * 1668460113964608051U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 17069783053664877727U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 1260234710193913099U;
            aOrbiterI = RotL64((aOrbiterI * 4561226779897414381U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 3825186451876061335U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 2905344294992827535U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2469896090698580795U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 18141402347899180617U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 8760129857609925066U;
            aOrbiterE = RotL64((aOrbiterE * 2507999156108123047U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 594052473780678210U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 13216719212966128379U;
            aOrbiterF = RotL64((aOrbiterF * 10691355329696722303U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 10029948739466316169U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 11912428807431992996U;
            aOrbiterH = RotL64((aOrbiterH * 85016510811938307U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 8735634019801417287U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 12785916159063273545U;
            aOrbiterK = RotL64((aOrbiterK * 1161917531260663357U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 367752057919802452U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 3961036242431041564U;
            aOrbiterB = RotL64((aOrbiterB * 16352646009782597315U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 3858415336170090719U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 14325258358254321551U;
            aOrbiterD = RotL64((aOrbiterD * 12080431158781060059U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 16872184337970977180U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 12380376990224645149U) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 16559121155413059221U), 35U);
            //
            aIngress = RotL64(aOrbiterJ, 23U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterA, 14U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + RotL64(aOrbiterD, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 46U) + RotL64(aOrbiterA, 5U)) + aOrbiterJ) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterA, 19U));
            aWandererF = aWandererF + ((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterE, 26U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 41U) + aOrbiterD) + RotL64(aOrbiterG, 3U));
            aWandererE = aWandererE + (((RotL64(aIngress, 24U) + aOrbiterI) + RotL64(aOrbiterK, 57U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterG, 39U)) + aOrbiterE) + aPhaseDWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 22U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 39U) + aOrbiterH) + RotL64(aOrbiterD, 35U)) + aNonceWordI);
            aWandererB = aWandererB + (((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 11U)) + aOrbiterB) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterD, 43U)) + aOrbiterF);
            aWandererG = aWandererG + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterC, 51U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 24U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererI, 38U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordJ);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 32737U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28147U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30332U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((aIndex + 32527U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 10U)) + (RotL64(aCross, 57U) ^ RotL64(aIngress, 39U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterI = ((aWandererB + RotL64(aIngress, 37U)) + RotL64(aCarry, 19U)) + 4204560462077827182U;
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 43U)) + 6572370199668594039U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 35U)) + RotL64(aCarry, 29U)) + 15958999876732622825U;
            aOrbiterC = ((aWandererH + RotL64(aCross, 29U)) + RotL64(aCarry, 3U)) + 9969349486879280377U;
            aOrbiterK = (aWandererK + RotL64(aIngress, 40U)) + 15450238998293956181U;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 23U)) + 9128619863683138259U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aCross, 51U)) + 5691270563628979565U;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 13U)) + 5901029710568933106U) + aPhaseDOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aCross, 18U)) + 10442738941988588834U) + aNonceWordG;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 5U)) + 3508116020325721993U) + aNonceWordO;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 3U)) + 13221917083569767259U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 11627915460377128176U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 17858261365514253433U;
            aOrbiterH = RotL64((aOrbiterH * 7535577636975884641U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 4294837988806295989U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 11242915481585070249U;
            aOrbiterK = RotL64((aOrbiterK * 17540688242763829319U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 13030663829236027109U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 7451948220723185149U;
            aOrbiterG = RotL64((aOrbiterG * 5191778587712222029U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 5575508866505031037U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 5161096033789876794U;
            aOrbiterJ = RotL64((aOrbiterJ * 16843827915802461797U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 3980482740649505122U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 11188906150207270241U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 408550837615188413U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 4435504916461645189U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 9970252853543702833U;
            aOrbiterE = RotL64((aOrbiterE * 5829143716916091997U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 3766347619186305854U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 11004616087340082895U;
            aOrbiterF = RotL64((aOrbiterF * 14469267845747063735U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 17600791542296175812U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 2556224430252009744U;
            aOrbiterA = RotL64((aOrbiterA * 14469426539907112137U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 8575243768637573595U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 9439245636611632007U;
            aOrbiterI = RotL64((aOrbiterI * 7519813655810877223U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 8376104683205641052U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 16877378648551624650U;
            aOrbiterD = RotL64((aOrbiterD * 13806644088125335467U), 43U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterI) + 8060622208866138617U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordA;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 4204560462077827182U) ^ aNonceWordD;
            aOrbiterC = RotL64((aOrbiterC * 8407034104111382011U), 23U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 43U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 34U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + RotL64(aOrbiterH, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 5U) + aOrbiterF) + RotL64(aOrbiterE, 3U));
            aWandererF = aWandererF + ((RotL64(aCross, 54U) + aOrbiterB) + RotL64(aOrbiterJ, 38U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterC, 19U)) + aOrbiterD);
            aWandererA = aWandererA + ((RotL64(aScatter, 21U) + RotL64(aOrbiterF, 35U)) + aOrbiterD);
            aWandererI = aWandererI ^ ((((RotL64(aCross, 13U) + RotL64(aOrbiterH, 21U)) + aOrbiterE) + aNonceWordJ) + aPhaseDWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 53U)) + aOrbiterK) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 6U)) + aOrbiterC);
            aWandererD = aWandererD + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterB, 29U)) + aOrbiterK) + aPhaseDWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 39U) + aOrbiterA) + RotL64(aOrbiterI, 47U));
            aWandererK = aWandererK + (((RotL64(aCross, 56U) + aOrbiterG) + RotL64(aOrbiterJ, 51U)) + RotL64(aCarry, 13U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 41U) + aOrbiterJ) + RotL64(aOrbiterE, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 34U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + RotL64(aWandererF, 50U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordF);
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

void TwistExpander_Softball_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x94A88261C0A51BD9ULL + 0xB1B328E0C20FEF0BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x8252B6E833D3AA03ULL + 0xE46DBB922DC257D4ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xF752A32E345EEBBBULL + 0x8DC34377F2EAF8DAULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xA44A0C31A2A5031DULL + 0x8F046F1D4512F3E2ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xE58E2CDA332857B1ULL + 0x8747D8D474499620ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xBE7E7A97706002FFULL + 0xE6AA99921A9F20F0ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xD82716702BAB5241ULL + 0xCED3D0626C2ECC2CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x98C391B23D39AA85ULL + 0xB33FBFD0170C321DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xFE1AE81A6A3B0E21ULL + 0xC108030EC391709BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xC256ADB23DD901B7ULL + 0xB71DA30067F076F2ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xA5445B7FA9F3D00BULL + 0xD9736B197E405321ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xC4116CDD9022C339ULL + 0xCC54AB79F1F9226EULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xCC73526955469017ULL + 0xF28825FB341DDE46ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xE293DE044033840BULL + 0xEC7932ED0563577EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xAAB4E586B7EBB07BULL + 0xA8D1ABF15665519DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xE326C6AC77D8BFA9ULL + 0x92A7403E6816906CULL);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 3629U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneC[((aIndex + 4147U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 1423U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 1897U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCross, 41U)) + (RotL64(aIngress, 18U) ^ RotL64(aCarry, 53U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterF = (aWandererI + RotL64(aScatter, 41U)) + 18180797995100240808U;
            aOrbiterJ = (aWandererA + RotL64(aCross, 29U)) + 6585906608223552885U;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 24U)) + 14088708930575939855U;
            aOrbiterG = ((((aWandererF + RotL64(aIngress, 13U)) + RotL64(aCarry, 35U)) + 468974153311516044U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordL;
            aOrbiterE = (aWandererK + RotL64(aScatter, 53U)) + 12481951025619894110U;
            aOrbiterC = (((aWandererG + RotL64(aCross, 57U)) + RotL64(aCarry, 41U)) + 17227987923860711763U) + aNonceWordM;
            aOrbiterA = (aWandererH + RotL64(aPrevious, 11U)) + 4373962756657477139U;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 3U)) + 2077576476565420951U;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 27U)) + 17435011300234663764U) + aNonceWordG;
            aOrbiterK = (aWandererE + RotL64(aCross, 35U)) + 4118039398293246896U;
            aOrbiterB = (((aWandererC + RotL64(aScatter, 44U)) + RotL64(aCarry, 27U)) + 13724716599855216683U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 12391461204689596339U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 9900605191533799627U;
            aOrbiterI = RotL64((aOrbiterI * 13553565332531046301U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 972946858824366125U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 17247681919694541215U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2974639094630445643U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 15442851427306771601U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 7303586227288294037U;
            aOrbiterF = RotL64((aOrbiterF * 15406402525021428799U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 12650358753454105119U) + aNonceWordJ;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 1483710933373510492U;
            aOrbiterG = RotL64((aOrbiterG * 6531763256577221891U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 18065810162229740788U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 11311677121338794007U;
            aOrbiterA = RotL64((aOrbiterA * 15116367961682119467U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 2355285311890287611U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 1287783821903407734U;
            aOrbiterH = RotL64((aOrbiterH * 8054011680932255985U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 9282654686791135654U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 15488608017745542551U;
            aOrbiterB = RotL64((aOrbiterB * 7858866274035085123U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 13296835576073421802U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 7127700236018338741U;
            aOrbiterJ = RotL64((aOrbiterJ * 11246173563106014149U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 1365928843264598789U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 7777790578813003657U;
            aOrbiterE = RotL64((aOrbiterE * 10121688100505628161U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 2104270617375082523U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 13363764449819651164U;
            aOrbiterD = RotL64((aOrbiterD * 2685452132715528975U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 2008038686059197988U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 18180797995100240808U;
            aOrbiterK = RotL64((aOrbiterK * 8978998151475372047U), 27U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterA, 40U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 5U)) + aOrbiterJ);
            aWandererE = aWandererE + ((RotL64(aScatter, 30U) + aOrbiterI) + RotL64(aOrbiterD, 50U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterJ, 11U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 21U) + aOrbiterK) + RotL64(aOrbiterF, 27U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterI, 35U)) + aOrbiterB);
            aWandererJ = aWandererJ + (((RotL64(aCross, 4U) + aOrbiterG) + RotL64(aOrbiterK, 3U)) + aNonceWordC);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterF, 40U)) + aOrbiterC);
            aWandererC = aWandererC + (((RotL64(aScatter, 39U) + RotL64(aOrbiterB, 13U)) + aOrbiterE) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 41U) + aOrbiterB) + RotL64(aOrbiterD, 23U));
            aWandererK = aWandererK + ((((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterH, 29U)) + RotL64(aCarry, 21U)) + aPhaseEWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 43U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 40U));
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 35U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 10849U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 7442U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 8730U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 6540U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aIngress, 21U)) + (RotL64(aCross, 54U) + RotL64(aPrevious, 5U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterI = (aWandererF + RotL64(aIngress, 57U)) + 12136097566601676613U;
            aOrbiterH = (aWandererH + RotL64(aCross, 5U)) + 7969431322248040056U;
            aOrbiterD = (aWandererD + RotL64(aScatter, 19U)) + 10530676021510553889U;
            aOrbiterF = (((aWandererC + RotL64(aPrevious, 27U)) + RotL64(aCarry, 37U)) + 8740777303075445264U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = (aWandererA + RotL64(aIngress, 41U)) + 13249434169895564739U;
            aOrbiterG = (aWandererI + RotL64(aCross, 14U)) + 15529577005925628472U;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 35U)) + 344627093687331562U) + aNonceWordP;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 37U)) + 8824277416519988893U;
            aOrbiterB = (((aWandererE + RotL64(aIngress, 39U)) + RotL64(aCarry, 47U)) + 5636276438449709875U) + aNonceWordL;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 29U)) + RotL64(aCarry, 19U)) + 2079413361031851552U;
            aOrbiterE = (((aWandererB + RotL64(aCross, 24U)) + 7807998179168655561U) + aPhaseEOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1]) + aNonceWordG;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 13589392896232029112U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 10733011474804473996U;
            aOrbiterD = RotL64((aOrbiterD * 361749145931578805U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 15934162328347805968U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 7573511217796245232U;
            aOrbiterH = RotL64((aOrbiterH * 10694563909931636155U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 4828475187337891975U) + aNonceWordB;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 13284974329890393113U;
            aOrbiterK = RotL64((aOrbiterK * 10831075817642374287U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 13173869918669643112U) + aNonceWordF;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 15841507674783398167U;
            aOrbiterA = RotL64((aOrbiterA * 15632933198136963277U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 14168272451055700516U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 11134471485501999898U;
            aOrbiterB = RotL64((aOrbiterB * 8019507184494591705U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 2611858916687822610U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 17863271539727513641U;
            aOrbiterI = RotL64((aOrbiterI * 4987884722174985677U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 8874401993454249066U) + aNonceWordK;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 5131480593493950665U;
            aOrbiterF = RotL64((aOrbiterF * 8585874663602346121U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 9366563022381918996U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 7890729519928340296U;
            aOrbiterG = RotL64((aOrbiterG * 11428572374057899517U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 131774386529223292U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 4108356674478240148U;
            aOrbiterC = RotL64((aOrbiterC * 2492753294539081613U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 7651738365157869789U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 2745458108574051004U;
            aOrbiterJ = RotL64((aOrbiterJ * 2175955806036373729U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 10492013124307434604U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 12136097566601676613U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13128652803485742119U), 57U);
            //
            aIngress = RotL64(aOrbiterG, 47U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + (RotL64(aOrbiterH, 4U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + RotL64(aOrbiterK, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 57U)) + aOrbiterA);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterH, 52U)) + aOrbiterB);
            aWandererK = aWandererK + (((RotL64(aPrevious, 43U) + aOrbiterG) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterG, 11U)) + aOrbiterK) + aNonceWordI);
            aWandererC = aWandererC + ((((RotL64(aCross, 12U) + RotL64(aOrbiterJ, 47U)) + aOrbiterG) + RotL64(aCarry, 19U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterE, 19U)) + aOrbiterB) + aPhaseEWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterC, 23U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 5U)) + aOrbiterC);
            aWandererE = aWandererE + (((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterH, 40U)) + aNonceWordM);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 14U) + RotL64(aOrbiterD, 21U)) + aOrbiterH);
            aWandererI = aWandererI + ((RotL64(aScatter, 41U) + RotL64(aOrbiterF, 35U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 54U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererK, 30U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 15703U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 15948U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 12586U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 11691U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 54U) + RotL64(aCarry, 11U)) ^ (RotL64(aIngress, 27U) + RotL64(aCross, 39U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterF = (aWandererE + RotL64(aIngress, 48U)) + 12262991801139086177U;
            aOrbiterD = (aWandererF + RotL64(aCross, 57U)) + 7963038771924890197U;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 23U)) + 15540520327933568896U;
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 29U)) + RotL64(aCarry, 19U)) + 8745565892055020722U;
            aOrbiterC = (((aWandererI + RotL64(aPrevious, 27U)) + RotL64(aCarry, 29U)) + 16619329199683755286U) + aPhaseEOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aCross, 37U)) + RotL64(aCarry, 23U)) + 10865705026433867260U;
            aOrbiterK = ((aWandererG + RotL64(aScatter, 5U)) + 2743368697984518059U) + aNonceWordG;
            aOrbiterA = (((aWandererA + RotL64(aIngress, 39U)) + 5556006271515473135U) + aPhaseEOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1]) + aNonceWordA;
            aOrbiterJ = (aWandererB + RotL64(aCross, 53U)) + 5355833281353498588U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 34U)) + 8313616108963479829U;
            aOrbiterG = (aWandererC + RotL64(aScatter, 3U)) + 16657121016801866434U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 16532226425013000833U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 5800465874932467232U;
            aOrbiterH = RotL64((aOrbiterH * 5966395771690704577U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 17882948163883121328U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 15029375310296563175U;
            aOrbiterE = RotL64((aOrbiterE * 17021415832288477713U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 10170682648007918739U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 11829089574189398773U;
            aOrbiterD = RotL64((aOrbiterD * 15755874363488568849U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 1746524867389196322U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 10217423427886742775U;
            aOrbiterC = RotL64((aOrbiterC * 9166162099575333519U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 1338457710729082656U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 1319981417675542556U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9518448254565489715U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 3985281993069194761U) + aNonceWordN;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 7281264481139915593U;
            aOrbiterB = RotL64((aOrbiterB * 13498446162967276739U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 17394503335338855566U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 1430703546991948227U;
            aOrbiterF = RotL64((aOrbiterF * 1623206122475721175U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 472559435062214929U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 8065899137826178995U;
            aOrbiterI = RotL64((aOrbiterI * 13287499768933229539U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 3377996409668333322U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 10456089146891981998U;
            aOrbiterK = RotL64((aOrbiterK * 12037044781049717633U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 5246784368779537905U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 8518987022368391332U;
            aOrbiterJ = RotL64((aOrbiterJ * 4046763804695058779U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 7791883487780325967U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 12262991801139086177U;
            aOrbiterG = RotL64((aOrbiterG * 3409890579914160747U), 47U);
            //
            aIngress = RotL64(aOrbiterB, 13U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterJ, 37U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + (RotL64(aOrbiterF, 60U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterE, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 30U) + aOrbiterB) + RotL64(aOrbiterD, 21U)) + aNonceWordM);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 51U) + aOrbiterG) + RotL64(aOrbiterH, 38U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterA, 3U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterC, 43U));
            aWandererD = aWandererD + (((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterG, 11U)) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterJ, 35U)) + aOrbiterD) + aNonceWordC);
            aWandererA = aWandererA + (((RotL64(aPrevious, 53U) + aOrbiterK) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterE, 47U)) + aOrbiterB);
            aWandererB = aWandererB + ((RotL64(aScatter, 23U) + RotL64(aOrbiterH, 23U)) + aOrbiterI);
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 18U) + RotL64(aOrbiterF, 19U)) + aOrbiterD) + aNonceWordF) + aPhaseEWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterJ, 54U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 24U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererA, 60U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ aNonceWordK;
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 19423U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 21142U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 19639U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 21732U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCross, 19U)) ^ (RotL64(aIngress, 35U) + RotL64(aCarry, 52U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterJ = (((aWandererJ + RotL64(aScatter, 3U)) + 15726877954695761686U) + aPhaseEOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1]) + aNonceWordL;
            aOrbiterB = (aWandererF + RotL64(aPrevious, 57U)) + 14187652171881943587U;
            aOrbiterI = ((aWandererG + RotL64(aCross, 19U)) + RotL64(aCarry, 3U)) + 8420423151313882782U;
            aOrbiterD = (((aWandererB + RotL64(aIngress, 46U)) + RotL64(aCarry, 35U)) + 14942322692433259283U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aPrevious, 53U)) + 7272331475919796255U;
            aOrbiterK = (aWandererC + RotL64(aScatter, 39U)) + 154504365041805840U;
            aOrbiterC = (aWandererD + RotL64(aCross, 51U)) + 17475491222554948786U;
            aOrbiterG = (aWandererH + RotL64(aIngress, 24U)) + 5759181483165339605U;
            aOrbiterH = (aWandererE + RotL64(aScatter, 11U)) + 5993060214499322845U;
            aOrbiterE = (aWandererK + RotL64(aIngress, 37U)) + 10901786237875941844U;
            aOrbiterA = (((aWandererA + RotL64(aPrevious, 5U)) + RotL64(aCarry, 47U)) + 17135786595614068473U) + aNonceWordK;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 5208202073886811165U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 6821452921018900631U;
            aOrbiterI = RotL64((aOrbiterI * 13119330055184115669U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 13348064837402206969U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 8967943922403445136U;
            aOrbiterF = RotL64((aOrbiterF * 300168481725373093U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 8130283784171430891U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 6351113882502502876U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15960622823993072903U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 6894708729226455769U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 12065058511247133944U;
            aOrbiterC = RotL64((aOrbiterC * 5432601727436935831U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 17138279326229372741U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 12987698199066890628U;
            aOrbiterG = RotL64((aOrbiterG * 12665716655177320977U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 13688833537574196675U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 4211971980434000618U;
            aOrbiterH = RotL64((aOrbiterH * 1374411763361518851U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 10376917117582537592U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 4807742522197923516U;
            aOrbiterE = RotL64((aOrbiterE * 15257251453302090961U), 47U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterH) + 18038296468177121243U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 6879666349379745258U;
            aOrbiterA = RotL64((aOrbiterA * 15819475269715810555U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 5193656664432659624U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 680899397323387963U;
            aOrbiterJ = RotL64((aOrbiterJ * 9857476056194621321U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 1851929589073547860U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 13093101559415170218U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13950928576652143737U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 13695333301427028607U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 15726877954695761686U;
            aOrbiterD = RotL64((aOrbiterD * 960063676226172027U), 51U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 42U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + RotL64(aOrbiterB, 18U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterF, 5U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 48U) + RotL64(aOrbiterF, 23U)) + aOrbiterA) + RotL64(aCarry, 3U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterH, 47U)) + aOrbiterF);
            aWandererH = aWandererH + ((RotL64(aCross, 21U) + aOrbiterI) + RotL64(aOrbiterA, 3U));
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 27U)) + aOrbiterI) + aNonceWordH) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterG, 50U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterK, 35U)) + aOrbiterH);
            aWandererC = aWandererC + (((RotL64(aScatter, 60U) + RotL64(aOrbiterB, 11U)) + aOrbiterF) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterC, 29U)) + aOrbiterB);
            aWandererK = aWandererK + (((RotL64(aPrevious, 27U) + aOrbiterE) + RotL64(aOrbiterF, 39U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterG, 58U)) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererE, 18U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 6U));
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ aNonceWordM;
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 24493U)) & S_BLOCK1], 46U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23265U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 23049U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((aIndex + 26510U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aIngress, 41U)) ^ (RotL64(aCarry, 56U) ^ RotL64(aPrevious, 5U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterA = ((aWandererF + RotL64(aScatter, 13U)) + 5906639480605353429U) + aPhaseEOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aIngress, 48U)) + 5293518570213287605U;
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 27U)) + 15383185501428521377U;
            aOrbiterE = (aWandererB + RotL64(aCross, 3U)) + 15364072512743978902U;
            aOrbiterH = (((aWandererC + RotL64(aIngress, 43U)) + RotL64(aCarry, 19U)) + 4525473357144014271U) + aNonceWordI;
            aOrbiterC = (aWandererI + RotL64(aCross, 30U)) + 10400911938125603074U;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 23U)) + RotL64(aCarry, 35U)) + 16417506293824627550U;
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 5U)) + RotL64(aCarry, 5U)) + 2419329331753341815U;
            aOrbiterD = (aWandererG + RotL64(aIngress, 11U)) + 14929222427923332069U;
            aOrbiterB = (aWandererH + RotL64(aCross, 19U)) + 16771573504983922586U;
            aOrbiterK = ((aWandererE + RotL64(aScatter, 53U)) + 1863466450051787622U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 12895350137096692415U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 3700979086526298327U;
            aOrbiterJ = RotL64((aOrbiterJ * 10279730254867618193U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 1977099106211282426U) + aNonceWordL;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 6144698304096915742U;
            aOrbiterC = RotL64((aOrbiterC * 5039822990560519609U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 3858895556659724975U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 1283646340363435327U;
            aOrbiterF = RotL64((aOrbiterF * 11622421841377018069U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 6240532051889108891U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 757364889381634634U;
            aOrbiterB = RotL64((aOrbiterB * 943852137901972945U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 5272945693977418174U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 6850528198786172283U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1966383079897679953U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 14431587733859573714U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 16124590257870999553U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7755796211433191143U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 14912695018110241411U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 11098623474413346520U;
            aOrbiterG = RotL64((aOrbiterG * 15167688959990872051U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 3484847683376368686U) + aNonceWordO;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 2295388097292719800U;
            aOrbiterD = RotL64((aOrbiterD * 1240808318176106909U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 923199510066894111U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 311875852510926196U;
            aOrbiterK = RotL64((aOrbiterK * 9797881750305289335U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 3543141837224843684U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 12889943043568922084U;
            aOrbiterI = RotL64((aOrbiterI * 8682278766727990427U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 6105656539077757510U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 5906639480605353429U) ^ aNonceWordB;
            aOrbiterH = RotL64((aOrbiterH * 9555916235293954383U), 41U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterI, 35U);
            aIngress = aIngress + (RotL64(aOrbiterF, 4U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 53U) + aOrbiterI) + RotL64(aOrbiterE, 35U)) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 41U) + aOrbiterC) + RotL64(aOrbiterJ, 12U));
            aWandererF = aWandererF + (((RotL64(aIngress, 3U) + RotL64(aOrbiterA, 5U)) + aOrbiterH) + aNonceWordC);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 51U)) + aOrbiterI) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 41U)) + aOrbiterI);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 12U) + RotL64(aOrbiterG, 3U)) + aOrbiterH);
            aWandererB = aWandererB + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 43U)) + aOrbiterD) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterA, 53U)) + aOrbiterI);
            aWandererH = aWandererH + (((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterF, 48U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 30U) + aOrbiterK) + RotL64(aOrbiterJ, 29U)) + aNonceWordP);
            aWandererC = aWandererC + ((RotL64(aScatter, 23U) + RotL64(aOrbiterG, 39U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 46U));
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + RotL64(aWandererJ, 39U);
            aCarry = aCarry + RotL64(aIngress, 42U);
            aCarry = aCarry ^ aNonceWordK;
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 31607U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((aIndex + 31065U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 32403U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30482U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aIngress, 54U)) + (RotL64(aPrevious, 27U) + RotL64(aCarry, 5U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 39U)) + RotL64(aCarry, 13U)) + 6467297102954816305U;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 58U)) + 7921154109831114952U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aIngress, 41U)) + 5701131763215638919U) + aNonceWordG;
            aOrbiterI = ((aWandererB + RotL64(aCross, 13U)) + RotL64(aCarry, 51U)) + 10022999076719002684U;
            aOrbiterB = (aWandererA + RotL64(aIngress, 3U)) + 4367135243038982316U;
            aOrbiterK = ((aWandererK + RotL64(aScatter, 44U)) + RotL64(aCarry, 21U)) + 14445846824810383592U;
            aOrbiterG = (aWandererC + RotL64(aCross, 23U)) + 7683697954545773253U;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 51U)) + 17517006750428030899U;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 29U)) + 2052484792684025476U) + aNonceWordB;
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 53U)) + 6279463052085808926U) + aNonceWordL;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 19U)) + 679280153651813684U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 2939516520188460569U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 1960616434964712325U;
            aOrbiterF = RotL64((aOrbiterF * 15145998415466343039U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 12273819390719947361U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 5685033154709449397U;
            aOrbiterB = RotL64((aOrbiterB * 9845666295874714959U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 9314494172199500653U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 15757631834636427621U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15483543888965744529U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 10878078046389399574U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 3583495913766365232U;
            aOrbiterG = RotL64((aOrbiterG * 2913540984990155225U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 7385544065754622301U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 16839599460207922881U;
            aOrbiterD = RotL64((aOrbiterD * 240651605910592561U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 13038163804940349251U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 2587538594933924000U;
            aOrbiterE = RotL64((aOrbiterE * 3091149760401278671U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 13109518583364738004U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 2447689055742474261U) ^ aNonceWordF;
            aOrbiterA = RotL64((aOrbiterA * 12100180201235703193U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 5752044906692668618U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 6637725371036522120U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6021986525167161115U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 16549229877442298618U) + aNonceWordA;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 12825651879441561108U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9079931351967033993U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 16088338999978085987U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 12584648360998154782U;
            aOrbiterJ = RotL64((aOrbiterJ * 2109996837220975261U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 7526256599938771686U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 6467297102954816305U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9289442676936248653U), 37U);
            //
            aIngress = RotL64(aOrbiterA, 27U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterD, 52U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 5U) + RotL64(aOrbiterF, 39U)) + aOrbiterB) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 60U) + RotL64(aOrbiterA, 21U)) + aOrbiterB) + aNonceWordO);
            aWandererG = aWandererG + ((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 34U)) + aOrbiterC);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 3U)) + aOrbiterB);
            aWandererK = aWandererK + (((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterI, 57U)) + aPhaseEWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 39U) + aOrbiterJ) + RotL64(aOrbiterG, 11U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 11U) + aOrbiterC) + RotL64(aOrbiterH, 27U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 28U) + aOrbiterF) + RotL64(aOrbiterD, 51U));
            aWandererC = aWandererC + (((RotL64(aIngress, 51U) + aOrbiterG) + RotL64(aOrbiterK, 47U)) + aPhaseEWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 37U) + aOrbiterI) + RotL64(aOrbiterE, 6U)) + aNonceWordI);
            aWandererD = aWandererD + (((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + (RotL64(aWandererF, 60U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordP;
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

void TwistExpander_Softball_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xF5E329B59D883C45ULL + 0xC2E4653572B8FB33ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xDFED9DA2DB8C2503ULL + 0xD9E6AB23388738B5ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xB2ED460A68DBA66DULL + 0xE9938ACD6CB91A64ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x8F73FFD2E273420FULL + 0xBECC2E36E4D85421ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xC30985D65A07807BULL + 0xA6E7BE1774DB8157ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x9EF8FA6A35EC188FULL + 0xDAE46E46C78365D1ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xAA5672D0711B326BULL + 0x8A4EF5CDACC232E2ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x8921C1005551FC13ULL + 0xC70F157350210C6CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x81113A3BC47DB167ULL + 0xC62C5AD4FBC7593AULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xC5F7324D6A8A3B9FULL + 0x9FB5D9859112B708ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xE5E1284106F9DB85ULL + 0xC984D6C958181512ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xF4F1F9AF23DC3A85ULL + 0xE8185231ABC354BAULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xB0939DC2F34705A1ULL + 0xECE0B5D45EDFEE45ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x894C8AF0928F9657ULL + 0xC0AB618899BF95FAULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x90FA323666CF42B5ULL + 0xCECC3D33C01A851EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x80B8E9C84CDA50E9ULL + 0xEFF112EEDB18E62BULL);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 4758U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4414U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 3015U)) & S_BLOCK1], 46U) ^ RotL64(aOperationLaneA[((aIndex + 2559U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 37U) ^ RotL64(aIngress, 3U)) ^ (RotL64(aCross, 53U) + RotL64(aPrevious, 22U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterJ = ((aWandererI + RotL64(aCross, 13U)) + 18302975933754610273U) + aNonceWordH;
            aOrbiterK = (aWandererB + RotL64(aPrevious, 29U)) + 16736972646771456082U;
            aOrbiterB = (aWandererH + RotL64(aIngress, 21U)) + 17389406266488137442U;
            aOrbiterC = ((((aWandererD + RotL64(aScatter, 51U)) + RotL64(aCarry, 29U)) + 5252511566486165539U) + aPhaseFOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1]) + aNonceWordK;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 48U)) + RotL64(aCarry, 19U)) + 5730715427422747640U;
            aOrbiterF = ((aWandererA + RotL64(aCross, 27U)) + 6412695646456045825U) + aNonceWordD;
            aOrbiterG = (aWandererG + RotL64(aIngress, 5U)) + 9539701605708994494U;
            aOrbiterH = (aWandererF + RotL64(aScatter, 23U)) + 18355107116412945722U;
            aOrbiterA = (((aWandererJ + RotL64(aCross, 36U)) + RotL64(aCarry, 35U)) + 11735742491750132942U) + aPhaseFOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = (aWandererC + RotL64(aIngress, 41U)) + 12363819388562658842U;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 11U)) + 5861430292304371543U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 15027487084595017708U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 7012850020745791926U;
            aOrbiterB = RotL64((aOrbiterB * 15952928839355613939U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 11904871669287886120U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 11199760114477343208U;
            aOrbiterF = RotL64((aOrbiterF * 7156374911847525867U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 3856004502263742700U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 3705931243173921893U;
            aOrbiterJ = RotL64((aOrbiterJ * 10334871178498711485U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 12305785390539209389U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 18057980996551978823U;
            aOrbiterC = RotL64((aOrbiterC * 4850564181113470859U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 3229431819292153014U) + aNonceWordN;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 2994716629242460094U;
            aOrbiterG = RotL64((aOrbiterG * 1029427328395257917U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 9796307843453735512U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 2957260393651252432U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7261055869794739609U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 4060469664218866340U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 17462081697889685330U;
            aOrbiterI = RotL64((aOrbiterI * 7712009170974461225U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 13638660073917821172U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 15202349592659062565U) ^ aNonceWordO;
            aOrbiterK = RotL64((aOrbiterK * 4514326257446024301U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 12071949111168967041U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 11930843273199806728U;
            aOrbiterE = RotL64((aOrbiterE * 16229663295689525137U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 11294220104731500296U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 440743185210586759U;
            aOrbiterH = RotL64((aOrbiterH * 14810195235168807229U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 8514240764798061804U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 18302975933754610273U;
            aOrbiterD = RotL64((aOrbiterD * 1972439346780950873U), 35U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 34U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + (RotL64(aOrbiterI, 39U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + (RotL64(aOrbiterH, 43U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterC, 10U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterG, 11U)) + RotL64(aCarry, 21U)) + aPhaseFWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 28U) + aOrbiterE) + RotL64(aOrbiterI, 19U));
            aWandererH = aWandererH + ((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterH, 5U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterI, 47U)) + aOrbiterJ);
            aWandererD = aWandererD + (((RotL64(aScatter, 39U) + aOrbiterG) + RotL64(aOrbiterB, 41U)) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 13U) + aOrbiterF) + RotL64(aOrbiterK, 29U));
            aWandererC = aWandererC + (((RotL64(aIngress, 48U) + aOrbiterB) + RotL64(aOrbiterD, 60U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterD, 53U)) + aOrbiterK);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 37U) + aOrbiterD) + RotL64(aOrbiterC, 43U)) + aNonceWordJ);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 11U) + aOrbiterI) + RotL64(aOrbiterF, 27U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterA, 38U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 54U));
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererG, 23U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordN);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10614U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 6896U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 10257U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 9975U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aIngress, 36U)) ^ (RotL64(aPrevious, 11U) ^ RotL64(aCross, 51U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 21U)) + RotL64(aCarry, 39U)) + 13714409587461539863U;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 44U)) + 14101156723903265839U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = (((aWandererK + RotL64(aCross, 37U)) + 7063754562895369001U) + aPhaseFOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1]) + aNonceWordC;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 39U)) + 12320578575245519386U) + aNonceWordO;
            aOrbiterD = (aWandererF + RotL64(aIngress, 47U)) + 11744826789631008424U;
            aOrbiterG = (aWandererG + RotL64(aPrevious, 60U)) + 8744816505096675597U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 13U)) + 10405435520084528645U;
            aOrbiterC = (aWandererC + RotL64(aCross, 11U)) + 1463157688070683543U;
            aOrbiterH = (aWandererH + RotL64(aScatter, 5U)) + 12379603577919617703U;
            aOrbiterK = ((aWandererB + RotL64(aCross, 27U)) + RotL64(aCarry, 19U)) + 1343439118031348146U;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 29U)) + RotL64(aCarry, 43U)) + 16118850268070235540U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 14116264435819277136U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 5251698273012432109U;
            aOrbiterB = RotL64((aOrbiterB * 1495818611622063967U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 14806408656041403829U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 11569345414052398227U;
            aOrbiterJ = RotL64((aOrbiterJ * 9913158908301414861U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 17063874769147888574U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 9927420478679581917U;
            aOrbiterD = RotL64((aOrbiterD * 9042782809534196563U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 2550285599827162167U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 17801534123304996448U;
            aOrbiterI = RotL64((aOrbiterI * 2160836889363614721U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 6456685241021762041U) + aNonceWordH;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 17064208177372969289U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13726627607233302493U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 18279938244131982650U) + aNonceWordL;
            aOrbiterE = (((aOrbiterE ^ aOrbiterF) ^ 8211002229712129419U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterE = RotL64((aOrbiterE * 12931373380977640645U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 12795832560781931767U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 286378504074349650U;
            aOrbiterA = RotL64((aOrbiterA * 85453101173293509U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 5835304250436889513U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 12704972686724379659U;
            aOrbiterG = RotL64((aOrbiterG * 1198789639656336053U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 12555700587254295099U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 6740149669657971715U;
            aOrbiterC = RotL64((aOrbiterC * 9376048577305482691U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 1541392147096889431U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 16891341703173286949U;
            aOrbiterK = RotL64((aOrbiterK * 697452963711223355U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 8811637585092392653U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 13714409587461539863U;
            aOrbiterF = RotL64((aOrbiterF * 2578939920876994763U), 23U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 5U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 46U));
            aIngress = aIngress + RotL64(aOrbiterC, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 56U) + RotL64(aOrbiterJ, 35U)) + aOrbiterH);
            aWandererK = aWandererK + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 3U)) + aOrbiterG) + RotL64(aCarry, 27U)) + aNonceWordD);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 37U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aCross, 41U) + aOrbiterK) + RotL64(aOrbiterG, 54U)) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 37U) + aOrbiterD) + RotL64(aOrbiterI, 13U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 51U)) + aOrbiterF) + aPhaseFWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 20U) + RotL64(aOrbiterF, 21U)) + aOrbiterI);
            aWandererB = aWandererB + ((RotL64(aCross, 39U) + aOrbiterH) + RotL64(aOrbiterC, 11U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 5U) + aOrbiterD) + RotL64(aOrbiterE, 24U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 23U) + RotL64(aOrbiterF, 47U)) + aOrbiterD);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 29U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 56U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 34U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 21U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordM);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12800U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12410U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 12132U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 11957U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 19U) ^ RotL64(aCross, 38U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = (aWandererD + RotL64(aCross, 23U)) + 12809562813316740345U;
            aOrbiterK = (aWandererG + RotL64(aScatter, 53U)) + 17084212535326321199U;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 4U)) + 16074921689983846769U) + aNonceWordO;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 37U)) + 14027986153007120145U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aScatter, 35U)) + 7633455951809250227U;
            aOrbiterB = (((aWandererJ + RotL64(aIngress, 27U)) + 340989348513370174U) + aPhaseFOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1]) + aNonceWordD;
            aOrbiterI = (aWandererC + RotL64(aCross, 43U)) + 5307820377645020116U;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 19U)) + 5605285015771527274U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 47U)) + RotL64(aCarry, 41U)) + 5293500434746182790U;
            aOrbiterG = (((aWandererI + RotL64(aPrevious, 13U)) + RotL64(aCarry, 3U)) + 7263156475892261811U) + aNonceWordF;
            aOrbiterD = ((aWandererK + RotL64(aCross, 40U)) + RotL64(aCarry, 29U)) + 10672879570907433005U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 16659226780900986107U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 9774892622769850665U;
            aOrbiterE = RotL64((aOrbiterE * 7487477727543183211U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 10728057184108279042U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 5032485856947407217U;
            aOrbiterB = RotL64((aOrbiterB * 16651577903809154285U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 14642241075374862345U) + aNonceWordP;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 8386481273395203518U;
            aOrbiterK = RotL64((aOrbiterK * 11649977733867003445U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 2874153265304098104U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 11519900149177261000U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2010158758971864505U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 8885690878540115768U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 4482143389870987714U) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 7105332459437434281U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 17469068567801886615U) + aNonceWordI;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 5121422018622394837U;
            aOrbiterG = RotL64((aOrbiterG * 14823827133212643467U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 3130788210672745618U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 6139244627510113216U;
            aOrbiterA = RotL64((aOrbiterA * 2640754184921507389U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 10488511756324474710U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 1760223670304953696U;
            aOrbiterC = RotL64((aOrbiterC * 4007062295003769311U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 2232708414171096783U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 17497492434939621063U;
            aOrbiterI = RotL64((aOrbiterI * 9850565931511937725U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 8199114561613022892U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 15432482434863050835U;
            aOrbiterH = RotL64((aOrbiterH * 14271143436318169871U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 14991531324947777062U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 12809562813316740345U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4487021480964944879U), 37U);
            //
            aIngress = RotL64(aOrbiterE, 28U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 10U) + aOrbiterF) + RotL64(aOrbiterE, 29U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterD, 41U)) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 3U) + aOrbiterB) + RotL64(aOrbiterH, 11U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 29U) + aOrbiterD) + RotL64(aOrbiterH, 6U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterG, 53U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 23U) + aOrbiterA) + RotL64(aOrbiterC, 57U)) + RotL64(aCarry, 37U)) + aNonceWordG);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 35U) + aOrbiterG) + RotL64(aOrbiterA, 51U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 51U) + RotL64(aOrbiterF, 19U)) + aOrbiterA);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 56U) + RotL64(aOrbiterD, 21U)) + aOrbiterE) + aPhaseFWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 13U) + aOrbiterD) + RotL64(aOrbiterK, 13U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 47U) + aOrbiterI) + RotL64(aOrbiterE, 4U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 34U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 60U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordK);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 19430U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneB[((aIndex + 20767U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17959U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 18275U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 39U)) + (RotL64(aIngress, 26U) ^ RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 51U)) + 6318740973868639425U) + aNonceWordK;
            aOrbiterA = (aWandererJ + RotL64(aScatter, 10U)) + 5487840061430920881U;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 19U)) + RotL64(aCarry, 11U)) + 10258706763248072672U;
            aOrbiterE = ((aWandererA + RotL64(aCross, 21U)) + 18356875269730338208U) + aNonceWordO;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 3U)) + 12883160282903147010U) + aPhaseFOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aScatter, 13U)) + 1010140474942697730U;
            aOrbiterG = ((aWandererF + RotL64(aCross, 23U)) + 17733939421700898293U) + aPhaseFOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aIngress, 47U)) + 13693055887924981201U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 42U)) + RotL64(aCarry, 5U)) + 14574732452793385269U;
            aOrbiterF = ((aWandererB + RotL64(aCross, 29U)) + RotL64(aCarry, 43U)) + 10832873941223609012U;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 5U)) + 8212600587135328040U) + aNonceWordB;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 5312744319781971178U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 6173741211706546923U;
            aOrbiterC = RotL64((aOrbiterC * 12854414066390848249U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 3693249147883790810U) + aNonceWordG;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 18365859989736602556U;
            aOrbiterD = RotL64((aOrbiterD * 3348463719324104997U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 10645056678337549771U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 1175668356822251045U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6579675292775345579U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 13556844570541823717U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 4790355739411849736U;
            aOrbiterG = RotL64((aOrbiterG * 4083544011788850307U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 14905575502272644116U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 17047244574558476634U;
            aOrbiterB = RotL64((aOrbiterB * 2356386971503880047U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 10161614295718414869U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 13413914082651612468U) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 16224039093981079491U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 6072693130156927774U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 4333656233793103787U;
            aOrbiterF = RotL64((aOrbiterF * 9374745547133955709U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 17209776289202130250U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 11752001118070361543U;
            aOrbiterH = RotL64((aOrbiterH * 4416523594812872339U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 15367365111105608277U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 8650687767097460704U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11430451559660578667U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 18074648514448405693U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 10857586858462237581U;
            aOrbiterA = RotL64((aOrbiterA * 3722891011080095849U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 17219932344278345591U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 6318740973868639425U;
            aOrbiterE = RotL64((aOrbiterE * 8846295038878812229U), 35U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 30U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + (RotL64(aOrbiterH, 39U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aCross, 23U) + aOrbiterD) + RotL64(aOrbiterI, 51U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterH, 37U));
            aWandererE = aWandererE + (((RotL64(aIngress, 54U) + RotL64(aOrbiterC, 44U)) + aOrbiterG) + aNonceWordA);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 19U)) + aOrbiterK) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 19U)) + aNonceWordD);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 37U) + aOrbiterF) + RotL64(aOrbiterC, 41U));
            aWandererI = aWandererI + ((RotL64(aScatter, 41U) + aOrbiterB) + RotL64(aOrbiterC, 47U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterF, 60U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 21U)) + aOrbiterB) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 58U) + aOrbiterJ) + RotL64(aOrbiterA, 23U)) + aNonceWordH);
            aWandererB = aWandererB + (((RotL64(aScatter, 51U) + aOrbiterE) + RotL64(aOrbiterI, 27U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 26U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 6U));
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22646U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22820U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26357U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23752U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 56U) ^ RotL64(aPrevious, 35U)) ^ (RotL64(aIngress, 11U) + RotL64(aCross, 23U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 12U)) + RotL64(aCarry, 3U)) + 17470880031634374199U;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 37U)) + 757565846006937746U) + aPhaseFOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 21U)) + RotL64(aCarry, 19U)) + 9419282475801345674U;
            aOrbiterF = ((aWandererE + RotL64(aCross, 47U)) + RotL64(aCarry, 13U)) + 2014248014107898196U;
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 3U)) + 15113928519446490441U) + aNonceWordH;
            aOrbiterG = (aWandererB + RotL64(aCross, 53U)) + 7346126964886259935U;
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 19U)) + 5594123113093162359U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = (aWandererD + RotL64(aIngress, 58U)) + 5659237263369402005U;
            aOrbiterC = (aWandererH + RotL64(aCross, 5U)) + 11565709683423969703U;
            aOrbiterH = (aWandererK + RotL64(aIngress, 41U)) + 16782863743534856287U;
            aOrbiterK = (aWandererF + RotL64(aScatter, 51U)) + 13499100900072115907U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 11414447651044205242U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 7545993795121430538U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10758488381206257261U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 11778229237616454988U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 2544793391976514665U;
            aOrbiterG = RotL64((aOrbiterG * 4021060413798523299U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 9972156716619459164U) + aNonceWordL;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 17651030383827445664U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6742914240706775487U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 17439147296849134543U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 10021926927948343656U;
            aOrbiterH = RotL64((aOrbiterH * 18139540407315440909U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 9309867875882669289U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 14951424455944346337U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10569523948169951309U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 2166343974068770659U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 11386993629011562026U;
            aOrbiterF = RotL64((aOrbiterF * 3091639433512536097U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 5747849744680120960U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 4019290369160113026U;
            aOrbiterB = RotL64((aOrbiterB * 5567515306039646735U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 3820540009554769592U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 8210747198363020939U;
            aOrbiterC = RotL64((aOrbiterC * 16215133106542452509U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 3006494852696036003U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 2736305345451919450U;
            aOrbiterK = RotL64((aOrbiterK * 11993452696344358247U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 6148431711118275178U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 6986633012691940738U;
            aOrbiterD = RotL64((aOrbiterD * 15672039482523804893U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 7837859154831245165U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 17470880031634374199U;
            aOrbiterJ = RotL64((aOrbiterJ * 2153299273348512243U), 35U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 48U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 37U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + RotL64(aOrbiterK, 50U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aScatter, 21U) + RotL64(aOrbiterC, 21U)) + aOrbiterH);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 18U) + RotL64(aOrbiterE, 29U)) + aOrbiterA) + aNonceWordC);
            aWandererK = aWandererK + ((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterA, 48U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterK, 39U)) + aOrbiterD) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterE, 23U)) + RotL64(aCarry, 13U)) + aNonceWordA);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 41U) + aOrbiterF) + RotL64(aOrbiterA, 41U));
            aWandererD = aWandererD + (((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterI, 35U)) + aPhaseFWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterK, 13U)) + aNonceWordI);
            aWandererF = aWandererF + ((RotL64(aPrevious, 23U) + aOrbiterH) + RotL64(aOrbiterB, 3U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 54U) + RotL64(aOrbiterF, 56U)) + aOrbiterI);
            aWandererH = aWandererH + (((RotL64(aScatter, 11U) + RotL64(aOrbiterI, 5U)) + aOrbiterC) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 18U));
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + RotL64(aWandererE, 54U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27820U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28267U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29709U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28230U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 43U)) ^ (RotL64(aIngress, 56U) ^ RotL64(aCarry, 19U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = (aWandererK + RotL64(aCross, 37U)) + 17081642665820489793U;
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 39U)) + 14468854040067229623U) + aNonceWordB;
            aOrbiterH = (aWandererH + RotL64(aScatter, 60U)) + 2249450222593057429U;
            aOrbiterC = (aWandererB + RotL64(aPrevious, 35U)) + 14964389079511378664U;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 11U)) + RotL64(aCarry, 21U)) + 17003491054252360650U;
            aOrbiterK = (((aWandererF + RotL64(aPrevious, 27U)) + RotL64(aCarry, 41U)) + 12710882240582032588U) + aPhaseFOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aCross, 5U)) + RotL64(aCarry, 47U)) + 9887078182156755359U;
            aOrbiterJ = (aWandererG + RotL64(aIngress, 41U)) + 7665284531810584704U;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 51U)) + 7304284015511876717U) + aPhaseFOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aIngress, 19U)) + 5517927023543751734U;
            aOrbiterF = (aWandererA + RotL64(aCross, 14U)) + 17704756310857362759U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 11347400363019508578U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 11696395232760991243U;
            aOrbiterH = RotL64((aOrbiterH * 9725231749679442003U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 10875780291242873583U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 7808740614343437672U;
            aOrbiterD = RotL64((aOrbiterD * 8889516201913716283U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 3145390996141902032U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 16080636485642732615U;
            aOrbiterK = RotL64((aOrbiterK * 7445756373012217305U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 3929263288176983844U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 18210228766683996806U;
            aOrbiterB = RotL64((aOrbiterB * 13178080076505449091U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 13948962323541421431U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 3037683309790156893U;
            aOrbiterJ = RotL64((aOrbiterJ * 13406672352222636739U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 17827265198532699474U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 7270895262023504864U;
            aOrbiterA = RotL64((aOrbiterA * 13467417362477308167U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 6431243064980879185U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 6680205390976259885U;
            aOrbiterI = RotL64((aOrbiterI * 10421386694108590789U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 15910655919164357152U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 8046213498216027383U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 18061867495824063553U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 2521111689480478597U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 13892876610454681741U) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 17776392934374483875U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 16009217514890880809U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 1221573458193626679U;
            aOrbiterE = RotL64((aOrbiterE * 73477765605619369U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 9275704218554025797U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 17081642665820489793U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5613316790159527375U), 29U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 35U);
            aIngress = aIngress + (RotL64(aOrbiterB, 24U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + RotL64(aOrbiterI, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 24U)) + aOrbiterI) + RotL64(aCarry, 23U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterA, 35U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 29U)) + aOrbiterB) + aNonceWordN);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterG, 41U)) + aOrbiterH);
            aWandererI = aWandererI + ((((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterF, 20U)) + aNonceWordJ) + aPhaseFWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 43U) + aOrbiterG) + RotL64(aOrbiterD, 47U));
            aWandererC = aWandererC + (((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterE, 13U)) + aNonceWordD);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 54U) + aOrbiterH) + RotL64(aOrbiterJ, 27U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 21U) + aOrbiterF) + RotL64(aOrbiterK, 37U)) + RotL64(aCarry, 3U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 37U) + aOrbiterE) + RotL64(aOrbiterJ, 57U));
            aWandererE = aWandererE + ((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterD, 5U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 26U));
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 44U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordA;
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

void TwistExpander_Softball_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xE624BB04F6311A35ULL + 0x924154777C253328ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xDB36F18DDF6A6A03ULL + 0xF8FDC5C4E5211D09ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xF473470E701601F3ULL + 0xF9AC78EB33D9271DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x8CB3ED8BBE97FE27ULL + 0xC77157DF602A0F03ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xC9396FB6057E1AF5ULL + 0xADEFDE86094D7D66ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA35EC4E7A6BF61EDULL + 0xF9064BEA6C8DE5A6ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x9CFD4A4C02D740EDULL + 0xAD29DACE192DE2ADULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xE09C1FC763202467ULL + 0xCC31FB8037F5CAB5ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xB3981391D016B5CFULL + 0xF0B2E08C4B52D7D2ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xD5940F7308271AA9ULL + 0xAAC786113CDF0548ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x8A77CA5D0171A685ULL + 0xFC5685A7AD7C03C2ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xD6E3B44AF7457F31ULL + 0x88957C36C730B56FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x91D721C1470D93DFULL + 0x980962270ABBEC5DULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xA8C3C3F965343DF5ULL + 0xBAC6C8DCA0D37608ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x9338198531C4DF03ULL + 0xAAEE84A90960A48BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xEF1D223DE99DC1A1ULL + 0x89158DF267ECF70BULL);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 5230U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneC[((aIndex + 1880U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 1952U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneA[((aIndex + 1432U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 47U) + RotL64(aCross, 35U)) ^ (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 22U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = (aWandererG + RotL64(aScatter, 11U)) + 7651355040951791298U;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 43U)) + RotL64(aCarry, 51U)) + 13988210277931659312U;
            aOrbiterC = ((aWandererH + RotL64(aCross, 35U)) + 9846849412579537783U) + aPhaseFOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aIngress, 21U)) + 12746719939495876158U;
            aOrbiterK = (aWandererA + RotL64(aPrevious, 5U)) + 11498066185182895284U;
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 39U)) + 11101058955193080232U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aCross, 24U)) + 15513734459555672046U) + aNonceWordA;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 13U)) + RotL64(aCarry, 57U)) + 15711108675349394643U;
            aOrbiterG = (((aWandererK + RotL64(aCross, 53U)) + RotL64(aCarry, 23U)) + 4771231759949468556U) + aNonceWordK;
            aOrbiterA = (aWandererB + RotL64(aIngress, 29U)) + 11449258010811305256U;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 18U)) + 17036938391509986723U) + aNonceWordL;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 6999245666776654250U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 2106819066263369528U;
            aOrbiterC = RotL64((aOrbiterC * 13005885810757743129U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 12716183358903477216U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 16752724547046059889U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11475905692393034141U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 17623077680983093163U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 6726003022297274986U;
            aOrbiterE = RotL64((aOrbiterE * 14709385877103232653U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 2842410225096524740U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 9235178377537910514U;
            aOrbiterH = RotL64((aOrbiterH * 11813751114775673845U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 2619888019860844610U) + aNonceWordB;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 6295481948199619613U;
            aOrbiterJ = RotL64((aOrbiterJ * 15429161806953951205U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 9724921158061115570U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 4070976180958458679U;
            aOrbiterG = RotL64((aOrbiterG * 6080566609081811453U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 5864247978960125554U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 7771249710071026757U;
            aOrbiterB = RotL64((aOrbiterB * 4787660062590737657U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 15006900854988166845U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 2755659268987119046U;
            aOrbiterD = RotL64((aOrbiterD * 8043939381186802359U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 1922321482806966418U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 13910818219761929659U;
            aOrbiterK = RotL64((aOrbiterK * 8895973123729951173U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 7540972911473176026U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 5419023469522423893U;
            aOrbiterF = RotL64((aOrbiterF * 1380429266266313945U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 2349651834739320824U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 7651355040951791298U;
            aOrbiterA = RotL64((aOrbiterA * 3713776056028698433U), 19U);
            //
            aIngress = RotL64(aOrbiterF, 3U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 48U));
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aPrevious, 14U) + RotL64(aOrbiterF, 51U)) + aOrbiterD) + aNonceWordC) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterH, 11U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aCross, 47U) + RotL64(aOrbiterA, 18U)) + aOrbiterI) + aNonceWordM);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 41U) + aOrbiterH) + RotL64(aOrbiterB, 21U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterC, 57U)) + aOrbiterG) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 5U)) + aOrbiterE);
            aWandererK = aWandererK + (((RotL64(aIngress, 27U) + aOrbiterE) + RotL64(aOrbiterI, 37U)) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 23U) + aOrbiterB) + RotL64(aOrbiterJ, 43U));
            aWandererG = aWandererG + (((RotL64(aScatter, 37U) + aOrbiterI) + RotL64(aOrbiterD, 13U)) + aPhaseFWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 29U) + aOrbiterD) + RotL64(aOrbiterG, 46U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 60U) + aOrbiterA) + RotL64(aOrbiterD, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 14U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + RotL64(aWandererD, 36U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordJ);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 10782U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 10609U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 9540U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((aIndex + 7498U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 10U) + RotL64(aCross, 57U)) ^ (RotL64(aCarry, 29U) ^ RotL64(aIngress, 41U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterJ = (aWandererA + RotL64(aIngress, 21U)) + 15316464782468770057U;
            aOrbiterH = (aWandererG + RotL64(aPrevious, 24U)) + 6642872057476351588U;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 37U)) + 660732654689529192U) + aNonceWordE;
            aOrbiterE = (aWandererC + RotL64(aCross, 13U)) + 7235418086884000655U;
            aOrbiterG = (((aWandererB + RotL64(aScatter, 39U)) + RotL64(aCarry, 3U)) + 14784518476694580493U) + aNonceWordM;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 5U)) + RotL64(aCarry, 47U)) + 12222433977933449375U;
            aOrbiterB = (aWandererF + RotL64(aCross, 53U)) + 8573001207708329927U;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 43U)) + RotL64(aCarry, 39U)) + 16035256260815013172U;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 48U)) + 15767726974121910203U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = (((aWandererD + RotL64(aScatter, 3U)) + 17712217935322939971U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterK = (aWandererE + RotL64(aCross, 57U)) + 13488963456923357159U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 10222949131965611079U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 1495561412321657209U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9706305581868526265U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 16156530750584361434U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 7773792489045606309U;
            aOrbiterH = RotL64((aOrbiterH * 10730624207715601393U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 11544578291333360613U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 3665587867634242865U) ^ aNonceWordO;
            aOrbiterG = RotL64((aOrbiterG * 4840528190844842595U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 15248434984650998090U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 15487979645426567581U;
            aOrbiterB = RotL64((aOrbiterB * 10868107809356766183U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 6972347795052712690U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 16074994810010431338U) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 1262655238856775853U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 16851139687900415292U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 14630026837021552812U;
            aOrbiterJ = RotL64((aOrbiterJ * 9577900853521254603U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 14236330619137368169U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 17778707026111136216U;
            aOrbiterE = RotL64((aOrbiterE * 16239561893843454747U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 9390961969105999083U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 1174881758316573228U;
            aOrbiterF = RotL64((aOrbiterF * 6602061268277529311U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 3025148570039849574U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 2813499258480831171U;
            aOrbiterC = RotL64((aOrbiterC * 12272555492688861861U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 15397952138592662354U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 10394648143430175275U;
            aOrbiterI = RotL64((aOrbiterI * 18195627209519212303U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 3043205345760158739U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 15316464782468770057U;
            aOrbiterK = RotL64((aOrbiterK * 8162506622688910545U), 13U);
            //
            aIngress = RotL64(aOrbiterI, 21U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterF, 53U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + (RotL64(aOrbiterA, 50U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 60U) + aOrbiterG) + RotL64(aOrbiterJ, 22U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 35U)) + aOrbiterG) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 41U) + aOrbiterD) + RotL64(aOrbiterB, 29U)) + aNonceWordN);
            aWandererG = aWandererG + ((RotL64(aIngress, 13U) + aOrbiterK) + RotL64(aOrbiterA, 3U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 30U) + aOrbiterI) + RotL64(aOrbiterH, 11U));
            aWandererD = aWandererD + (((RotL64(aScatter, 39U) + aOrbiterC) + RotL64(aOrbiterF, 39U)) + aPhaseFWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterC, 37U));
            aWandererC = aWandererC + ((((RotL64(aCross, 43U) + RotL64(aOrbiterF, 47U)) + aOrbiterK) + RotL64(aCarry, 29U)) + aNonceWordB);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 21U) + aOrbiterI) + RotL64(aOrbiterE, 43U));
            aWandererE = aWandererE + (((RotL64(aScatter, 23U) + aOrbiterK) + RotL64(aOrbiterB, 51U)) + aPhaseFWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 27U) + aOrbiterG) + RotL64(aOrbiterF, 26U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 50U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = aCarry ^ aNonceWordE;
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 11566U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 15142U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15244U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 14645U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 58U) ^ RotL64(aPrevious, 27U)) + (RotL64(aCarry, 11U) ^ RotL64(aIngress, 39U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = (aWandererC + RotL64(aScatter, 35U)) + 4848316479321533394U;
            aOrbiterJ = (((aWandererH + RotL64(aIngress, 57U)) + RotL64(aCarry, 19U)) + 6919360256662636195U) + aNonceWordC;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 43U)) + 9897013582181108544U) + aNonceWordJ;
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 29U)) + 7319353809896158678U) + aNonceWordF;
            aOrbiterG = ((aWandererK + RotL64(aCross, 13U)) + RotL64(aCarry, 51U)) + 2848175435514849859U;
            aOrbiterF = (aWandererD + RotL64(aScatter, 24U)) + 6967780718720437934U;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 51U)) + 10143884766603388136U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aIngress, 19U)) + 8675965006150972051U;
            aOrbiterI = ((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 37U)) + 16350117755560994281U;
            aOrbiterC = (aWandererG + RotL64(aCross, 60U)) + 17976597517118423760U;
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 5U)) + 1399631141355370237U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 3590613762034716792U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 5134624314245932157U;
            aOrbiterK = RotL64((aOrbiterK * 13077589037975283371U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 10082236952942943654U) + aNonceWordL;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 4015535035905433450U;
            aOrbiterF = RotL64((aOrbiterF * 4961808568701908559U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 611474103801573800U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 5786708483794098001U) ^ aNonceWordP;
            aOrbiterJ = RotL64((aOrbiterJ * 7694007039340089267U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 5201943497363274455U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 9282160506938328489U;
            aOrbiterG = RotL64((aOrbiterG * 5368182164239021367U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 4932320527498940158U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 11576526341731392916U;
            aOrbiterB = RotL64((aOrbiterB * 1712051774729439363U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 10790691517638887125U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 16280649213607464422U;
            aOrbiterC = RotL64((aOrbiterC * 10756733801499471873U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 9553716940667712810U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 11827518270964003341U) ^ aNonceWordK;
            aOrbiterE = RotL64((aOrbiterE * 1322489827908132831U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 16777463701235809321U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 3375489084588454149U;
            aOrbiterA = RotL64((aOrbiterA * 3335010977457647307U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 8129898095524287632U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 14496406641486541929U;
            aOrbiterD = RotL64((aOrbiterD * 10077246205532940301U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 17968163292907132345U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 2431407778543471402U;
            aOrbiterI = RotL64((aOrbiterI * 407105842057624537U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 18330313613898211889U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 4848316479321533394U;
            aOrbiterH = RotL64((aOrbiterH * 3462735144109152811U), 51U);
            //
            aIngress = RotL64(aOrbiterI, 57U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterB, 22U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterK, 53U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + RotL64(aOrbiterG, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aScatter, 23U) + RotL64(aOrbiterG, 42U)) + aOrbiterK);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 21U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aCross, 21U) + RotL64(aOrbiterK, 37U)) + aOrbiterC) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 54U) + aOrbiterC) + RotL64(aOrbiterH, 13U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 27U) + aOrbiterC) + RotL64(aOrbiterJ, 40U)) + aPhaseFWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 51U)) + aOrbiterG) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterA, 53U)) + aOrbiterG) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 41U) + aOrbiterG) + RotL64(aOrbiterI, 27U)) + aNonceWordO);
            aWandererA = aWandererA + ((RotL64(aCross, 3U) + RotL64(aOrbiterA, 5U)) + aOrbiterE);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterA, 19U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 44U) + RotL64(aOrbiterG, 23U)) + aOrbiterD) + aNonceWordE);
            //
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 60U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 50U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 17328U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 18217U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 21260U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 21824U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aIngress, 5U)) + (RotL64(aPrevious, 18U) ^ RotL64(aCross, 35U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = (aWandererD + RotL64(aIngress, 3U)) + 8020711767807230555U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 37U)) + 15368693777246341570U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aCross, 23U)) + 5117523734225562401U) + aNonceWordM;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 60U)) + RotL64(aCarry, 3U)) + 13155269151097507808U;
            aOrbiterJ = (aWandererE + RotL64(aIngress, 11U)) + 9879303753623578272U;
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 43U)) + 1165799257173794826U) + aNonceWordJ;
            aOrbiterA = (aWandererJ + RotL64(aScatter, 47U)) + 930641942062732091U;
            aOrbiterE = ((aWandererA + RotL64(aCross, 41U)) + 11330571332221123153U) + aNonceWordP;
            aOrbiterB = (((aWandererB + RotL64(aIngress, 52U)) + RotL64(aCarry, 43U)) + 2862963158282518899U) + aPhaseFOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = (aWandererF + RotL64(aCross, 27U)) + 6019186399361476659U;
            aOrbiterF = ((aWandererI + RotL64(aScatter, 13U)) + RotL64(aCarry, 29U)) + 1924419843785161958U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 12618629043591380461U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 9334176504266512405U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 18239109235362925739U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 16829692481030013551U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterG) ^ 5604784396927022709U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterJ = RotL64((aOrbiterJ * 2833893610883508353U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 16124030106598549644U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 16571659812830230677U;
            aOrbiterC = RotL64((aOrbiterC * 4668250364992383549U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 15171089673591843703U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 2826755560293849328U;
            aOrbiterA = RotL64((aOrbiterA * 9397017963457655287U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 9976785768283589291U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 11845100564714691809U;
            aOrbiterE = RotL64((aOrbiterE * 4935139932585319251U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 7318560453127859950U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 3039196878830506712U;
            aOrbiterB = RotL64((aOrbiterB * 3140508261330698717U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 8850992055588337843U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 4219373528176869146U;
            aOrbiterK = RotL64((aOrbiterK * 1310964742529956743U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 1341474458715938799U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 15937557372891732898U;
            aOrbiterF = RotL64((aOrbiterF * 11437307017920192915U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 7512741986101399499U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 4304636545688233645U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1948671766238131953U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 11460886069492094055U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 2019818350627642126U;
            aOrbiterG = RotL64((aOrbiterG * 9802784763505584769U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 3190374588085859096U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 8020711767807230555U;
            aOrbiterI = RotL64((aOrbiterI * 12055760672321414929U), 5U);
            //
            aIngress = RotL64(aOrbiterJ, 26U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 39U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 46U));
            aIngress = aIngress + RotL64(aOrbiterG, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterJ, 27U)) + aOrbiterC);
            aWandererE = aWandererE + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 41U)) + aOrbiterI);
            aWandererA = aWandererA ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterF, 57U)) + aOrbiterG);
            aWandererK = aWandererK + (((RotL64(aIngress, 10U) + RotL64(aOrbiterH, 47U)) + aOrbiterA) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 51U) + aOrbiterH) + RotL64(aOrbiterC, 4U)) + aNonceWordK) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 27U) + aOrbiterH) + RotL64(aOrbiterB, 43U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterI, 39U));
            aWandererG = aWandererG + (((RotL64(aScatter, 37U) + aOrbiterD) + RotL64(aOrbiterK, 53U)) + aPhaseFWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 13U) + aOrbiterJ) + RotL64(aOrbiterD, 35U));
            aWandererF = aWandererF + (((RotL64(aScatter, 34U) + RotL64(aOrbiterD, 23U)) + aOrbiterI) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterF, 50U)) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 18U));
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererE, 46U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 25765U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24702U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 25037U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 22741U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCarry, 27U)) + (RotL64(aPrevious, 39U) ^ RotL64(aCross, 52U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterJ = (aWandererF + RotL64(aCross, 19U)) + 11177787645248006236U;
            aOrbiterE = (aWandererD + RotL64(aIngress, 3U)) + 3808340254579817169U;
            aOrbiterA = (aWandererH + RotL64(aScatter, 39U)) + 828030667598518279U;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 30U)) + 16177835921238398371U;
            aOrbiterH = (((aWandererJ + RotL64(aScatter, 43U)) + RotL64(aCarry, 13U)) + 5518747735458708741U) + aNonceWordM;
            aOrbiterK = (aWandererA + RotL64(aPrevious, 41U)) + 17346319082399995165U;
            aOrbiterD = (aWandererI + RotL64(aIngress, 57U)) + 6397156921893030937U;
            aOrbiterB = ((aWandererK + RotL64(aCross, 53U)) + 15559381654710713582U) + aPhaseFOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = (aWandererG + RotL64(aScatter, 28U)) + 940404446491415088U;
            aOrbiterG = ((aWandererB + RotL64(aIngress, 13U)) + RotL64(aCarry, 19U)) + 8047166032048732645U;
            aOrbiterC = (((aWandererE + RotL64(aCross, 23U)) + RotL64(aCarry, 27U)) + 4688468645859470491U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 3710878044770337260U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 116343189456629220U;
            aOrbiterA = RotL64((aOrbiterA * 5637725064169289339U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 883908030159391659U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 18058691521694880482U;
            aOrbiterK = RotL64((aOrbiterK * 3132200449123497619U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 17521015077103586117U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 3668332225435714918U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12658899101297839881U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 12229480388278883300U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 16206524049491531816U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11122340196620859805U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 5743265849441077466U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 2812293020719282236U;
            aOrbiterJ = RotL64((aOrbiterJ * 8903956475200417109U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 13718364781538837074U) + aNonceWordK;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 861529717259766236U;
            aOrbiterI = RotL64((aOrbiterI * 17019744777211266685U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 4862687502126693872U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 7722024283321020761U;
            aOrbiterD = RotL64((aOrbiterD * 18086944039541060829U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 8205803118233399853U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 15130160926615050422U;
            aOrbiterF = RotL64((aOrbiterF * 1454552751453996765U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 667469191899263617U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 18048970185163843471U;
            aOrbiterC = RotL64((aOrbiterC * 1800698970568737425U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 508102841337488721U) + aNonceWordO;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 3803840516662727630U;
            aOrbiterE = RotL64((aOrbiterE * 8477778555284121637U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 17055028117762299436U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 11177787645248006236U;
            aOrbiterH = RotL64((aOrbiterH * 12457019014051206805U), 41U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 51U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 39U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 21U));
            aIngress = aIngress + (RotL64(aOrbiterA, 46U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + RotL64(aOrbiterC, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 5U)) + aOrbiterF);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterB, 10U)) + aOrbiterI) + RotL64(aCarry, 13U)) + aNonceWordF);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 54U) + RotL64(aOrbiterD, 53U)) + aOrbiterE) + aPhaseFWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 13U) + aOrbiterJ) + RotL64(aOrbiterG, 37U)) + aNonceWordJ);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterJ, 35U));
            aWandererD = aWandererD + (((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterI, 19U)) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterK, 43U)) + aOrbiterF) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 27U) + RotL64(aOrbiterC, 13U)) + aOrbiterB);
            aWandererB = aWandererB ^ ((RotL64(aCross, 5U) + aOrbiterH) + RotL64(aOrbiterA, 23U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 50U) + RotL64(aOrbiterK, 56U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterC, 3U)) + aOrbiterF) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererB, 30U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 50U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29792U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((aIndex + 30037U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31722U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((aIndex + 32337U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 58U) + RotL64(aCross, 43U)) + (RotL64(aIngress, 11U) ^ RotL64(aCarry, 27U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = (aWandererB + RotL64(aCross, 41U)) + 15652862298542575895U;
            aOrbiterB = (aWandererE + RotL64(aIngress, 47U)) + 16925323928418184554U;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 29U)) + 4413861484961668394U) + aPhaseFOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (((aWandererH + RotL64(aPrevious, 60U)) + RotL64(aCarry, 21U)) + 2215946422098155969U) + aNonceWordM;
            aOrbiterD = (aWandererK + RotL64(aIngress, 27U)) + 14975185533513111110U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 11U)) + 9711613814905834552U) + aNonceWordK;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 21U)) + 13154957291850149471U;
            aOrbiterJ = (((aWandererC + RotL64(aScatter, 38U)) + RotL64(aCarry, 47U)) + 5058313016418534840U) + aNonceWordE;
            aOrbiterK = (((aWandererA + RotL64(aCross, 57U)) + RotL64(aCarry, 57U)) + 15011423472941211620U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = (aWandererJ + RotL64(aIngress, 53U)) + 2030053257469580168U;
            aOrbiterE = (aWandererF + RotL64(aScatter, 35U)) + 150530795186791193U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 10878237472104183427U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 11724672539469573109U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16158741837357985395U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 9589700906445846956U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 1367381624958248949U;
            aOrbiterD = RotL64((aOrbiterD * 8459515089081211977U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 12003215666757518106U) + aNonceWordG;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 11232479330848006729U;
            aOrbiterI = RotL64((aOrbiterI * 10993290955464593033U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 13013910456628561621U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 6092509838924105265U;
            aOrbiterF = RotL64((aOrbiterF * 805601154718006061U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 11999225836250312801U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 14421271973875748413U;
            aOrbiterJ = RotL64((aOrbiterJ * 9529010940887430157U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 15536288285741825272U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 2071793889925436679U;
            aOrbiterK = RotL64((aOrbiterK * 1526376970151714589U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 5622386476463436967U) + aNonceWordF;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 16147972771639168516U;
            aOrbiterC = RotL64((aOrbiterC * 11826916832825159095U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 4519892856053952290U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 12059500374938843538U;
            aOrbiterE = RotL64((aOrbiterE * 14987533625537956299U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 4547335128847992282U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 15378473334472216418U;
            aOrbiterA = RotL64((aOrbiterA * 13907560285280544037U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 14644123269581735633U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 6434315615480805381U;
            aOrbiterB = RotL64((aOrbiterB * 4335857173941645355U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 14241680137158382296U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 15652862298542575895U;
            aOrbiterH = RotL64((aOrbiterH * 4190840063924551519U), 29U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterI, 39U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 56U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 5U));
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterB, 57U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterK, 11U)) + aPhaseFWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 13U) + aOrbiterB) + RotL64(aOrbiterJ, 60U)) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 13U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aPrevious, 26U) + RotL64(aOrbiterD, 47U)) + aOrbiterE) + aNonceWordL);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterH, 5U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterC, 27U)) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterG, 54U));
            aWandererA = aWandererA + (((RotL64(aCross, 10U) + aOrbiterG) + RotL64(aOrbiterE, 51U)) + aNonceWordC);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 29U)) + aOrbiterF);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterH, 3U)) + aNonceWordO);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 46U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + RotL64(aWandererI, 48U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordJ;
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

void TwistExpander_Softball_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 7611U)) & S_BLOCK1], 53U) ^ RotL64(aKeyRowReadA[((aIndex + 7147U)) & W_KEY1], 6U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 5801U)) & W_KEY1], 23U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 5425U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aPrevious, 54U)) ^ (RotL64(aIngress, 35U) + RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = (aWandererF + RotL64(aScatter, 20U)) + 12535417189990029950U;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 43U)) + 6204401443676390273U;
            aOrbiterI = ((aWandererI + RotL64(aCross, 5U)) + RotL64(aCarry, 27U)) + 869613505613154672U;
            aOrbiterK = (((aWandererE + RotL64(aPrevious, 43U)) + RotL64(aCarry, 3U)) + 15053590879563855802U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = (aWandererD + RotL64(aCross, 56U)) + 13338989605204591428U;
            aOrbiterB = ((aWandererK + RotL64(aScatter, 13U)) + 18306470022403825392U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aPrevious, 39U)) + 1150696349434090218U;
            aOrbiterD = (aWandererC + RotL64(aIngress, 51U)) + 13549541786420596437U;
            aOrbiterF = (aWandererB + RotL64(aScatter, 35U)) + 14302878430259588461U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 4660437084477165225U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 1653628537860912069U;
            aOrbiterI = RotL64((aOrbiterI * 2624835201155303123U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 5594199757006711631U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 11008472193138708891U;
            aOrbiterB = RotL64((aOrbiterB * 13645764762027798301U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 3668516817279364310U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 128159531749679984U;
            aOrbiterD = RotL64((aOrbiterD * 4523246859249826987U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 6378674346113979108U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 11438762460659123362U;
            aOrbiterF = RotL64((aOrbiterF * 2733309638158283953U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 10624263004446482910U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 12546839706919241411U;
            aOrbiterE = RotL64((aOrbiterE * 11468326687628079347U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 8466639576503293921U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 5828694979857951504U;
            aOrbiterK = RotL64((aOrbiterK * 7835487310289634515U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 16496305151014092976U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 589464613876410567U;
            aOrbiterH = RotL64((aOrbiterH * 13190816610718051897U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 4168532743415647825U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 15944887793736489375U;
            aOrbiterC = RotL64((aOrbiterC * 17273403561158196717U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 11642456814106259483U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 1609897693632334867U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12912773555616819941U), 51U);
            //
            aIngress = RotL64(aOrbiterK, 23U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterE, 6U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterF, 27U)) + aOrbiterC) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterA, 4U)) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 26U) + aOrbiterE) + RotL64(aOrbiterB, 39U));
            aWandererD = aWandererD + (((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterH, 43U)) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterK, 53U));
            aWandererK = aWandererK + ((RotL64(aCross, 21U) + aOrbiterI) + RotL64(aOrbiterB, 58U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 48U) + RotL64(aOrbiterH, 21U)) + aOrbiterC);
            aWandererI = aWandererI + ((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterH, 11U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 53U) + aOrbiterF) + RotL64(aOrbiterE, 47U)) + aPhaseCWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 44U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + RotL64(aWandererE, 35U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 14675U)) & S_BLOCK1], 53U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 15945U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 12604U)) & W_KEY1], 58U) ^ RotL64(aKeyRowReadB[((aIndex + 9965U)) & W_KEY1], 43U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 51U)) + (RotL64(aCross, 23U) ^ RotL64(aIngress, 4U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 39U)) + RotL64(aCarry, 35U)) + 11480359716598965890U;
            aOrbiterE = (aWandererH + RotL64(aScatter, 22U)) + 15431182525482873419U;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 27U)) + 11360504974812776707U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = ((aWandererC + RotL64(aCross, 43U)) + RotL64(aCarry, 47U)) + 9292576416573382769U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 5U)) + 1549257414531028975U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = (aWandererD + RotL64(aCross, 58U)) + 5347769463033129317U;
            aOrbiterF = (aWandererE + RotL64(aPrevious, 35U)) + 17019199177478377234U;
            aOrbiterD = (aWandererJ + RotL64(aScatter, 13U)) + 16558106007323125094U;
            aOrbiterB = ((aWandererI + RotL64(aIngress, 51U)) + RotL64(aCarry, 11U)) + 3976182233825939422U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 2889047161195954395U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 2241831345026962605U;
            aOrbiterH = RotL64((aOrbiterH * 5757458560979927857U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 12850802412140579294U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 13541744735436450160U;
            aOrbiterG = RotL64((aOrbiterG * 906089290000537439U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 2085863085516538212U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 2969034221711544086U;
            aOrbiterF = RotL64((aOrbiterF * 7768528124408400403U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 6482666944512391472U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 16969153556875844613U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9483462388353216219U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 5161314086757363678U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 7150282484670673211U;
            aOrbiterB = RotL64((aOrbiterB * 8522427002337918663U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 5465304381272305847U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 2344610773390354017U;
            aOrbiterJ = RotL64((aOrbiterJ * 17010258514288089191U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 8335906578006588582U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 13668796013474193793U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8228000547141147777U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 9663362594301419686U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 3683773739120343413U;
            aOrbiterC = RotL64((aOrbiterC * 8319320803406104749U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 2538583190438044942U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 4454069062219406996U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16329554225309389599U), 35U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterG, 24U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 21U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + (RotL64(aOrbiterB, 11U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aPrevious, 58U) + RotL64(aOrbiterD, 47U)) + aOrbiterG);
            aWandererG = aWandererG ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterD, 18U)) + aOrbiterJ) + aPhaseCWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 39U)) + aOrbiterF);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 11U) + aOrbiterC) + RotL64(aOrbiterG, 23U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 51U) + aOrbiterJ) + RotL64(aOrbiterG, 5U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 28U) + RotL64(aOrbiterH, 54U)) + aOrbiterF);
            aWandererD = aWandererD + (((RotL64(aPrevious, 41U) + aOrbiterH) + RotL64(aOrbiterI, 27U)) + RotL64(aCarry, 51U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterI, 43U)) + aOrbiterB);
            aWandererJ = aWandererJ + (((RotL64(aCross, 23U) + RotL64(aOrbiterI, 11U)) + aOrbiterE) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 36U));
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 41U);
            aCarry = aCarry + RotL64(aIngress, 46U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22592U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22219U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 23060U)) & W_KEY1], 57U) ^ RotL64(aKeyRowReadB[((aIndex + 24419U)) & W_KEY1], 46U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 57U)) ^ (RotL64(aCarry, 22U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 53U)) + RotL64(aCarry, 39U)) + 16519040829220310189U;
            aOrbiterF = (aWandererB + RotL64(aIngress, 23U)) + 6888002778416941825U;
            aOrbiterB = ((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 23U)) + 1310832187746534025U;
            aOrbiterE = (((aWandererH + RotL64(aScatter, 38U)) + RotL64(aCarry, 5U)) + 5890888009051281674U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = (aWandererK + RotL64(aCross, 5U)) + 5143864838362464857U;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 27U)) + 15591534069452660003U;
            aOrbiterA = (aWandererE + RotL64(aScatter, 19U)) + 1466867671765325096U;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 47U)) + 13931443680107902488U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (aWandererF + RotL64(aIngress, 14U)) + 15400747367673245552U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 2836975369734495759U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 2370720358274970117U;
            aOrbiterB = RotL64((aOrbiterB * 4615571902817575375U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 3470677184188006133U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 7175584278499266723U;
            aOrbiterK = RotL64((aOrbiterK * 10067096593682482345U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 6095078817776863055U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 2176637999243513070U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12215701810843975501U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 5580391239754903129U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 15196125567953871184U;
            aOrbiterF = RotL64((aOrbiterF * 12686361960729564519U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 12787014151503209931U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 1523153207064063495U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3113907543551927561U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 12973289026485937829U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 9087439766232078173U;
            aOrbiterC = RotL64((aOrbiterC * 5817029335999350327U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 16318022893068674015U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 11089160685103562409U;
            aOrbiterA = RotL64((aOrbiterA * 17087834321385147603U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 8680037953925067235U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 3112588943274158119U;
            aOrbiterD = RotL64((aOrbiterD * 9214011370307670371U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 16749015684369649821U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 9419550535891334966U;
            aOrbiterI = RotL64((aOrbiterI * 5421312787569114811U), 23U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterI, 23U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 48U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 12U) + RotL64(aOrbiterD, 4U)) + aOrbiterA) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 27U) + RotL64(aOrbiterK, 11U)) + aOrbiterD);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterA, 47U));
            aWandererK = aWandererK + ((((RotL64(aCross, 47U) + RotL64(aOrbiterE, 27U)) + aOrbiterD) + RotL64(aCarry, 37U)) + aPhaseCWandererUpdateSaltF[((aIndex + 8U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 43U) + aOrbiterE) + RotL64(aOrbiterF, 60U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterA, 23U)) + aOrbiterI) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 34U) + aOrbiterD) + RotL64(aOrbiterH, 43U));
            aWandererF = aWandererF + ((RotL64(aCross, 19U) + RotL64(aOrbiterK, 51U)) + aOrbiterB);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 51U) + aOrbiterC) + RotL64(aOrbiterE, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 34U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32589U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((aIndex + 29966U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26142U)) & S_BLOCK1], 29U) ^ RotL64(mSource[((aIndex + 25908U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aPrevious, 54U)) + (RotL64(aCarry, 3U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (aWandererE + RotL64(aPrevious, 51U)) + 1866656689936219099U;
            aOrbiterH = (aWandererD + RotL64(aIngress, 39U)) + 2312314528139448289U;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 28U)) + RotL64(aCarry, 57U)) + 3554037526469185237U;
            aOrbiterB = (aWandererJ + RotL64(aCross, 11U)) + 405707755060974111U;
            aOrbiterK = (aWandererA + RotL64(aIngress, 57U)) + 1862976326004007697U;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 3U)) + 12992483065443288263U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 35U)) + 3793854946371595197U) + aPhaseCOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aCross, 47U)) + RotL64(aCarry, 13U)) + 4244007978867369382U;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 20U)) + RotL64(aCarry, 27U)) + 10280867500312580308U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 472563452959164242U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 12041770406895816553U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17811798500132002631U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 6118634015704900486U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 13637107920449233307U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17712028184714868053U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 16673735670669318830U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 8602681273646630496U;
            aOrbiterE = RotL64((aOrbiterE * 6995213887710749241U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 7683264695930369476U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 9146674871199188218U;
            aOrbiterD = RotL64((aOrbiterD * 7403427067419261981U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 3012935612827493084U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 1259789268731661945U;
            aOrbiterB = RotL64((aOrbiterB * 2372843620327050137U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 5623690455471160780U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 18355567776031865462U;
            aOrbiterJ = RotL64((aOrbiterJ * 9553862670107886679U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 7705134893833304792U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 4435192506444773834U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5249651218395299501U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 6204683785806409075U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 17886971535016484255U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6047216474762933535U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 4430578901091376829U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 607557685798141547U;
            aOrbiterH = RotL64((aOrbiterH * 12342665567201483107U), 47U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterE, 35U);
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 48U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aIngress, 13U) + aOrbiterB) + RotL64(aOrbiterK, 23U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 51U) + aOrbiterE) + RotL64(aOrbiterD, 19U));
            aWandererF = aWandererF + (((RotL64(aScatter, 27U) + RotL64(aOrbiterE, 5U)) + aOrbiterJ) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 58U) + RotL64(aOrbiterJ, 39U)) + aOrbiterH) + aPhaseCWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterH, 46U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 39U) + aOrbiterB) + RotL64(aOrbiterA, 29U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 41U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 13U)) + aOrbiterK);
            aWandererB = aWandererB + ((RotL64(aCross, 4U) + aOrbiterF) + RotL64(aOrbiterA, 50U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 52U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_Softball_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterK = 0;

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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1794U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneC[((aIndex + 2069U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4641U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8180U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 35U)) ^ (RotL64(aCross, 48U) + RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = (aWandererF + RotL64(aCross, 13U)) + 11521331427196538632U;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 3U)) + RotL64(aCarry, 53U)) + 16653824187682957632U;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 58U)) + RotL64(aCarry, 21U)) + 11654676587350088289U;
            aOrbiterB = (((aWandererE + RotL64(aIngress, 37U)) + RotL64(aCarry, 39U)) + 8010313317412193584U) + aPhaseDOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 21U)) + 1108775560502907471U) + aPhaseDOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 243952321439823521U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 2324945800401240403U;
            aOrbiterA = RotL64((aOrbiterA * 9471328582043504473U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 9257554497543369657U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 16701314607244592540U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8790054741039817107U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 3900445848034341782U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 7652316487347103658U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11480123491361589799U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 14980368605272070578U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 2001165460948764796U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8110980921827107649U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 1911044015666991050U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 11366207111147818339U;
            aOrbiterC = RotL64((aOrbiterC * 17234439040652553865U), 3U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterE, 37U);
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aIngress, 21U) + aOrbiterK) + RotL64(aOrbiterB, 57U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 37U) + aOrbiterE) + RotL64(aOrbiterC, 3U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterC, 27U)) + RotL64(aCarry, 3U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterA, 38U)) + aOrbiterK) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 56U) + RotL64(aOrbiterC, 11U)) + aOrbiterK) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 14497U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((aIndex + 14307U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14179U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneB[((aIndex + 15313U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 29U) ^ RotL64(aPrevious, 11U)) ^ (RotL64(aCross, 41U) + RotL64(aIngress, 58U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = ((aWandererG + RotL64(aCross, 3U)) + 15316464782468770057U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 13U)) + RotL64(aCarry, 21U)) + 6642872057476351588U;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 39U)) + 660732654689529192U;
            aOrbiterI = (((aWandererB + RotL64(aScatter, 51U)) + RotL64(aCarry, 51U)) + 7235418086884000655U) + aPhaseDOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (aWandererF + RotL64(aCross, 26U)) + 14784518476694580493U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 12222433977933449375U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 8573001207708329927U;
            aOrbiterG = RotL64((aOrbiterG * 17771120145431297541U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 16035256260815013172U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 15767726974121910203U;
            aOrbiterK = RotL64((aOrbiterK * 719060452537759331U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 17712217935322939971U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 13488963456923357159U;
            aOrbiterF = RotL64((aOrbiterF * 16785285630840310405U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 10222949131965611079U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 1495561412321657209U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9706305581868526265U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 16156530750584361434U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 7773792489045606309U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10730624207715601393U), 53U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 57U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aCross, 11U) + aOrbiterG) + RotL64(aOrbiterK, 60U)) + RotL64(aCarry, 47U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 52U) + RotL64(aOrbiterD, 11U)) + aOrbiterI);
            aWandererF = aWandererF + (((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 23U)) + aOrbiterD) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 35U) + aOrbiterF) + RotL64(aOrbiterK, 39U));
            aWandererI = aWandererI + (((RotL64(aIngress, 43U) + aOrbiterF) + RotL64(aOrbiterI, 51U)) + aPhaseDWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + RotL64(aWandererB, 29U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 23320U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19173U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19704U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 19197U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCarry, 18U)) + (RotL64(aPrevious, 37U) + RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = ((aWandererH + RotL64(aCross, 41U)) + RotL64(aCarry, 29U)) + 11700815697312060726U;
            aOrbiterI = (((aWandererF + RotL64(aPrevious, 3U)) + RotL64(aCarry, 57U)) + 11808423452327465441U) + aPhaseDOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aScatter, 29U)) + 8670503858631730886U;
            aOrbiterD = ((aWandererE + RotL64(aIngress, 12U)) + RotL64(aCarry, 5U)) + 2400061067991988544U;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 57U)) + 16163118178366229686U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 3280178595904941068U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 3298683600817047727U;
            aOrbiterG = RotL64((aOrbiterG * 9865649058799255343U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 16321624053445183574U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 6730229877611375225U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2022290495153519279U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 10162830636713641322U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 15646771327759599256U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15333053762177144775U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 14841751262270544102U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 9545541117228834895U;
            aOrbiterD = RotL64((aOrbiterD * 11529769874752969377U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 14676615635857599982U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 1231768638470558855U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2716808508509014677U), 27U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterH, 13U);
            aIngress = aIngress + (RotL64(aOrbiterG, 56U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterB, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterD, 50U)) + aOrbiterG) + RotL64(aCarry, 37U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 48U) + aOrbiterI) + RotL64(aOrbiterG, 13U));
            aWandererG = aWandererG + (((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 37U)) + aOrbiterB) + aPhaseDWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 21U)) + aOrbiterD) + aPhaseDWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterI, 29U)) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 12U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + RotL64(aWandererF, 37U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 28479U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28783U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 32527U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((aIndex + 25441U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCross, 35U)) + (RotL64(aIngress, 6U) ^ RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = ((aWandererD + RotL64(aIngress, 18U)) + RotL64(aCarry, 51U)) + 1457104756581596530U;
            aOrbiterB = (aWandererF + RotL64(aScatter, 43U)) + 6127240317844622874U;
            aOrbiterG = (((aWandererE + RotL64(aPrevious, 51U)) + RotL64(aCarry, 35U)) + 16492290056044189421U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aCross, 5U)) + 10963676850938416468U) + aPhaseDOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aScatter, 27U)) + RotL64(aCarry, 21U)) + 4872917367399752405U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 15218882377875616148U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 5934166612122118251U;
            aOrbiterG = RotL64((aOrbiterG * 10365045124180379919U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 14215280930872003003U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 11428034799044600979U;
            aOrbiterC = RotL64((aOrbiterC * 12162528943733976177U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 5453003654321728726U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 14273775120265649389U;
            aOrbiterF = RotL64((aOrbiterF * 5139018128323795309U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 328723770018440271U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 13032190719588211088U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13363368478932798315U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 2386881543033598494U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 1649501123340887116U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11148976582360499033U), 5U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 57U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + RotL64(aOrbiterG, 42U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterF, 52U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterC, 11U)) + aOrbiterD) + aPhaseDWandererUpdateSaltF[((aIndex + 26U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 11U) + aOrbiterG) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 28U) + aOrbiterC) + RotL64(aOrbiterF, 3U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 41U)) + aOrbiterC) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererE, 28U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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

void TwistExpander_Softball_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 952U)) & S_BLOCK1], 28U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2050U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7862U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((aIndex + 1733U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCarry, 11U)) + (RotL64(aCross, 53U) ^ RotL64(aIngress, 24U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = (aWandererE + RotL64(aCross, 60U)) + 3621877681473089725U;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 35U)) + RotL64(aCarry, 57U)) + 4451752751536414717U;
            aOrbiterA = (((aWandererA + RotL64(aPrevious, 53U)) + RotL64(aCarry, 43U)) + 11371625415377772117U) + aPhaseEOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 29U)) + 6046792758881150619U) + aPhaseEOrbiterAssignSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aCross, 13U)) + RotL64(aCarry, 27U)) + 8213166120394461682U;
            aOrbiterH = (aWandererI + RotL64(aIngress, 19U)) + 4343156661140422645U;
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 43U)) + 11105271483234947905U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 348904609985341372U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 12924652822526858767U;
            aOrbiterA = RotL64((aOrbiterA * 2801892489296408735U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 7461211697358520287U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 16551553555297890558U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16432952324635746293U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 11908056404140782995U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 9147367258259948715U;
            aOrbiterH = RotL64((aOrbiterH * 10777628928376261667U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 8876461054692728610U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 10546855952702525404U;
            aOrbiterB = RotL64((aOrbiterB * 10071104785895309677U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 4748636139110443794U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 783046909529525098U;
            aOrbiterE = RotL64((aOrbiterE * 8969157702460927215U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 16683965945838696665U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 12385412690177109575U;
            aOrbiterJ = RotL64((aOrbiterJ * 10795062772707143187U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 8210546822184469023U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 13146493623236979963U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13199947810161148155U), 3U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterB, 43U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 18U));
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 3U)) + aOrbiterD) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterB, 43U)) + aOrbiterE);
            aWandererI = aWandererI + (((RotL64(aPrevious, 37U) + aOrbiterA) + RotL64(aOrbiterJ, 23U)) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 11U)) + aOrbiterH) + aPhaseEWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterJ, 30U)) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 44U) + aOrbiterE) + RotL64(aOrbiterH, 37U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 51U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + RotL64(aWandererA, 24U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 16168U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 15922U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15495U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneB[((aIndex + 12007U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 37U) + RotL64(aCarry, 10U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = (aWandererB + RotL64(aCross, 35U)) + 11410829607777684449U;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 57U)) + RotL64(aCarry, 39U)) + 7502698839700975347U;
            aOrbiterG = (aWandererH + RotL64(aPrevious, 5U)) + 13267685058252106173U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 48U)) + RotL64(aCarry, 19U)) + 238242706996630625U;
            aOrbiterK = (((aWandererJ + RotL64(aPrevious, 13U)) + RotL64(aCarry, 3U)) + 8184695499511454281U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = (aWandererD + RotL64(aCross, 21U)) + 12767823220461985403U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 27U)) + 12293198423143850330U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 11149495229952495939U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 7556992689338382800U;
            aOrbiterG = RotL64((aOrbiterG * 18232398462716803063U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 3431338808774134649U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 16863099140844995099U;
            aOrbiterD = RotL64((aOrbiterD * 752376661101787919U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 17872458049880677604U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 16760153457252546974U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11225037229069712805U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 3115544493537438408U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 4359882942759752958U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 561477566995575801U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 13387113067202396536U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 12955690074544490161U;
            aOrbiterK = RotL64((aOrbiterK * 12449941770827974511U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 15614054443728226807U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 1939441328066616114U;
            aOrbiterI = RotL64((aOrbiterI * 4484917074808974359U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 4599016263007782537U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 9962305629016158048U;
            aOrbiterB = RotL64((aOrbiterB * 1496184427500037279U), 21U);
            //
            aIngress = RotL64(aOrbiterD, 43U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterC, 56U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 60U) + RotL64(aOrbiterB, 57U)) + aOrbiterK) + aPhaseEWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterG, 37U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterI, 5U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 53U) + aOrbiterD) + RotL64(aOrbiterB, 51U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 37U) + aOrbiterG) + RotL64(aOrbiterB, 20U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 13U)) + aOrbiterC) + RotL64(aCarry, 51U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 10U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 17309U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23958U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 22033U)) & S_BLOCK1], 46U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 20418U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 13U) ^ RotL64(aCross, 27U)) + (RotL64(aCarry, 58U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = (((aWandererC + RotL64(aIngress, 41U)) + RotL64(aCarry, 39U)) + 1393781663398437180U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aScatter, 47U)) + RotL64(aCarry, 3U)) + 17414594746688585273U;
            aOrbiterB = ((aWandererD + RotL64(aCross, 34U)) + 2823888497053071250U) + aPhaseEOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 5U)) + RotL64(aCarry, 53U)) + 17032631958617884859U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 23U)) + 15222697630461125019U;
            aOrbiterC = (aWandererA + RotL64(aCross, 11U)) + 15737414920751551780U;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 57U)) + 1357196111055783001U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 5315122321649251691U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 7893744655508595974U;
            aOrbiterB = RotL64((aOrbiterB * 17863000246694319149U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 16721939414324611738U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 3444375866323610848U;
            aOrbiterD = RotL64((aOrbiterD * 10874157227815775661U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 1825716513674511632U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 15582066843912467318U;
            aOrbiterJ = RotL64((aOrbiterJ * 12765146555943757373U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 15673590949193923915U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 13887365046280406413U;
            aOrbiterG = RotL64((aOrbiterG * 3169061375011420121U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 12730414371734709356U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 4819112390640821927U;
            aOrbiterA = RotL64((aOrbiterA * 8782547948627685451U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 3089925954422937464U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 7180179304678622530U;
            aOrbiterC = RotL64((aOrbiterC * 16118051565147747413U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 17030269962085008657U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 6675917351883004046U;
            aOrbiterE = RotL64((aOrbiterE * 14134335325316949687U), 29U);
            //
            aIngress = RotL64(aOrbiterA, 51U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 19U) + RotL64(aOrbiterB, 13U)) + aOrbiterG) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterC, 28U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 53U) + RotL64(aOrbiterB, 5U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterD, 51U));
            aWandererF = aWandererF + ((RotL64(aCross, 29U) + RotL64(aOrbiterC, 57U)) + aOrbiterE);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 42U) + aOrbiterC) + RotL64(aOrbiterA, 21U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 39U)) + aOrbiterA) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 6U));
            aCarry = aCarry + RotL64(aWandererF, 23U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 24656U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((aIndex + 28000U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28197U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 31353U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 52U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 21U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (((aWandererH + RotL64(aPrevious, 47U)) + RotL64(aCarry, 19U)) + 12206125048349568300U) + aPhaseEOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aScatter, 58U)) + 5843520589343188818U;
            aOrbiterF = (aWandererI + RotL64(aCross, 23U)) + 12195046124287121687U;
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 5U)) + RotL64(aCarry, 51U)) + 16769779119214020640U;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 37U)) + 5257603646260695833U;
            aOrbiterD = (((aWandererF + RotL64(aScatter, 13U)) + RotL64(aCarry, 39U)) + 8523523946234886745U) + aPhaseEOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aCross, 29U)) + 7316024684200084096U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 11996978575084115207U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 15491711479085513628U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15136690392026011819U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 6036648530996821484U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 926323222234121863U;
            aOrbiterD = RotL64((aOrbiterD * 6639661141258803779U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 2700323841295743492U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 5852273765810284935U;
            aOrbiterC = RotL64((aOrbiterC * 16665696735016345215U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 11697397483133538067U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 17777142964957007194U;
            aOrbiterG = RotL64((aOrbiterG * 6338967222543284999U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 10892176201151170298U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 11759700374509499684U;
            aOrbiterB = RotL64((aOrbiterB * 14247697264744736081U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 11343756773329590643U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 15785048929757652350U;
            aOrbiterJ = RotL64((aOrbiterJ * 17208103574389502597U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 7508839228498497238U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 13088508510402094665U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15730279447009669103U), 57U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 58U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 39U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 35U) + RotL64(aOrbiterJ, 19U)) + aOrbiterD) + aPhaseEWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterD, 43U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 14U) + RotL64(aOrbiterB, 57U)) + aOrbiterI) + RotL64(aCarry, 51U)) + aPhaseEWandererUpdateSaltF[((aIndex + 22U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 41U) + aOrbiterG) + RotL64(aOrbiterD, 3U));
            aWandererG = aWandererG + (((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterI, 26U)) + RotL64(aCarry, 27U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterJ, 51U));
            aWandererC = aWandererC + ((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 11U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererA, 6U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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

void TwistExpander_Softball_Arx::Twist_D(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4370U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7041U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1784U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 599U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 37U) ^ RotL64(aPrevious, 57U)) + (RotL64(aCross, 6U) + RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = (((aWandererA + RotL64(aScatter, 35U)) + RotL64(aCarry, 21U)) + 15549114274303128055U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aCross, 21U)) + 16466750056388063241U;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 6U)) + RotL64(aCarry, 41U)) + 12209449840836787142U;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 47U)) + 14551496099734294336U;
            aOrbiterC = (((aWandererD + RotL64(aCross, 57U)) + RotL64(aCarry, 5U)) + 6266576428679808622U) + aPhaseFOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 16892841575635668152U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 7375966221423362125U;
            aOrbiterJ = RotL64((aOrbiterJ * 15338878556107177587U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 11926105302821753530U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 16219253791550461124U;
            aOrbiterK = RotL64((aOrbiterK * 2117550758226173419U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 7299056065319248160U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 15234001484933728439U;
            aOrbiterE = RotL64((aOrbiterE * 8182244796017018911U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 6615802589932632120U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 5481176858895819247U;
            aOrbiterG = RotL64((aOrbiterG * 3604590158551984877U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 17220507586542139380U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 14137921473739415340U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10634645686035907603U), 21U);
            //
            aIngress = RotL64(aOrbiterK, 19U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterJ, 30U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterC, 27U)) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterC, 57U)) + aOrbiterG) + aPhaseFWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterE, 5U)) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 20U) + RotL64(aOrbiterJ, 43U)) + aOrbiterK);
            aWandererI = aWandererI + (((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterC, 18U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10935U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneD[((aIndex + 10754U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15952U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneB[((aIndex + 9292U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 11U)) + (RotL64(aCross, 37U) ^ RotL64(aIngress, 54U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (((aWandererE + RotL64(aPrevious, 5U)) + RotL64(aCarry, 21U)) + 12535417189990029950U) + aPhaseFOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aScatter, 43U)) + 6204401443676390273U;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 13U)) + RotL64(aCarry, 3U)) + 869613505613154672U;
            aOrbiterC = (aWandererG + RotL64(aCross, 22U)) + 15053590879563855802U;
            aOrbiterB = (((aWandererD + RotL64(aScatter, 57U)) + RotL64(aCarry, 53U)) + 13338989605204591428U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 18306470022403825392U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 1150696349434090218U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1099447646821052165U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 13549541786420596437U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 14302878430259588461U;
            aOrbiterB = RotL64((aOrbiterB * 16813606782134305513U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 4660437084477165225U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 1653628537860912069U;
            aOrbiterA = RotL64((aOrbiterA * 2624835201155303123U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 5594199757006711631U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 11008472193138708891U;
            aOrbiterF = RotL64((aOrbiterF * 13645764762027798301U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 3668516817279364310U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 128159531749679984U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4523246859249826987U), 3U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 11U);
            aIngress = aIngress + (RotL64(aOrbiterF, 22U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterB, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 13U)) + aOrbiterD) + aPhaseFWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 37U) + aOrbiterA) + RotL64(aOrbiterC, 58U)) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 20U) + RotL64(aOrbiterF, 21U)) + aOrbiterA);
            aWandererD = aWandererD + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterA, 37U)) + aOrbiterB) + RotL64(aCarry, 29U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterB, 29U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 46U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 24366U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19609U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18358U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 23510U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aIngress, 47U)) ^ (RotL64(aPrevious, 11U) + RotL64(aCarry, 60U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererB + RotL64(aCross, 27U)) + 16016931609704150191U) + aPhaseFOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aIngress, 56U)) + RotL64(aCarry, 5U)) + 14511433515861302636U;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 47U)) + RotL64(aCarry, 43U)) + 11691237442613269593U;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 3U)) + RotL64(aCarry, 19U)) + 16383220587320484649U;
            aOrbiterA = ((aWandererE + RotL64(aCross, 37U)) + 14293015313458219868U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 4407695248205526670U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 1158323195324398372U;
            aOrbiterC = RotL64((aOrbiterC * 7489061637031434357U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 6577683409653864555U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 171080079472863843U;
            aOrbiterB = RotL64((aOrbiterB * 3063978974927752653U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 5766333425872228205U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 16173508656917582960U;
            aOrbiterD = RotL64((aOrbiterD * 12187968015372936695U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 11781450063402219202U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 13033139686637576694U;
            aOrbiterF = RotL64((aOrbiterF * 4331137994135472025U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 4006310759400926020U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 13156817947481574467U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 563189239835001483U), 21U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterF, 47U);
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 58U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 20U) + aOrbiterD) + RotL64(aOrbiterF, 12U)) + aPhaseFWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 53U)) + aOrbiterD) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterC, 29U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 41U)) + aOrbiterC) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 37U) + aOrbiterA) + RotL64(aOrbiterF, 21U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 26U));
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 31150U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneB[((aIndex + 31711U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29453U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 32283U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 56U)) + (RotL64(aIngress, 11U) ^ RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (((aWandererD + RotL64(aCross, 37U)) + RotL64(aCarry, 35U)) + 10726035965553989335U) + aPhaseFOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = ((aWandererC + RotL64(aIngress, 57U)) + RotL64(aCarry, 19U)) + 967354339530195662U;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 3U)) + RotL64(aCarry, 3U)) + 10834593005478605624U;
            aOrbiterE = (aWandererK + RotL64(aScatter, 20U)) + 1012888282838656933U;
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 47U)) + 15283530351725183253U) + aPhaseFOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 11724495956731703750U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 4288330117317505776U;
            aOrbiterK = RotL64((aOrbiterK * 2738997410474076757U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 10894778070022873473U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 15563886747621617467U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17884709931569040065U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 11182488628562891937U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 10420140066310588580U;
            aOrbiterE = RotL64((aOrbiterE * 13898299782819948719U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 11775138062167543111U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 16545391898578161683U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14588306527161321535U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 1550144656312299266U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 14903504853138279883U;
            aOrbiterH = RotL64((aOrbiterH * 8003033561266164387U), 19U);
            //
            aIngress = RotL64(aOrbiterI, 11U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterI, 23U)) + aOrbiterA) + aPhaseFWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterE, 56U)) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterA, 47U)) + aOrbiterH);
            aWandererC = aWandererC + ((((RotL64(aIngress, 58U) + aOrbiterI) + RotL64(aOrbiterK, 39U)) + RotL64(aCarry, 21U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 39U) + aOrbiterH) + RotL64(aOrbiterI, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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

void TwistExpander_Softball_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterF = 0;
    std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 2153U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 4293U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 3875U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8059U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 47U) ^ RotL64(aCross, 60U)) + (RotL64(aCarry, 19U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (((aWandererE + RotL64(aScatter, 54U)) + RotL64(aCarry, 57U)) + 11210042748013785976U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aCross, 11U)) + RotL64(aCarry, 21U)) + 4584747303233477454U;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 3U)) + 8878765929792969517U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 19U)) + RotL64(aCarry, 43U)) + 2172232330280041122U;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 41U)) + 8378937026022264016U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 8683007464695824208U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 9564352997357118134U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17869948990449143305U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 11713878436769887528U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 8052917623074021077U;
            aOrbiterF = RotL64((aOrbiterF * 7450115139081623477U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 7720597162792145185U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 2602847785328475621U;
            aOrbiterB = RotL64((aOrbiterB * 14065077077207224525U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 17813669222300509724U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 8724263063156573013U;
            aOrbiterA = RotL64((aOrbiterA * 3632927017737834359U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 6882429835961613492U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 13213313479525717359U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2411431247725974895U), 3U);
            //
            aIngress = RotL64(aOrbiterG, 3U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterA, 23U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 46U) + RotL64(aOrbiterA, 5U)) + aOrbiterB);
            aWandererC = aWandererC + ((((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterG, 60U)) + RotL64(aCarry, 29U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 41U)) + aOrbiterF);
            aWandererA = aWandererA + (((RotL64(aScatter, 27U) + RotL64(aOrbiterB, 13U)) + aOrbiterF) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterI, 27U)) + aOrbiterA) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + RotL64(aWandererA, 53U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 8731U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 10287U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 13191U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneA[((aIndex + 15336U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 54U)) + (RotL64(aPrevious, 41U) + RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = (((aWandererI + RotL64(aPrevious, 11U)) + RotL64(aCarry, 19U)) + 8866844335448071821U) + aPhaseGOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aIngress, 19U)) + 15159698739856430085U;
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 47U)) + RotL64(aCarry, 39U)) + 9582805772989594633U;
            aOrbiterK = ((aWandererD + RotL64(aCross, 60U)) + RotL64(aCarry, 3U)) + 1438538239931588373U;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 35U)) + 10862044156620436139U) + aPhaseGOrbiterAssignSaltE[((aIndex + 16U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 13682173320058164615U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 8351013291045977592U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5722336275651615473U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 15777857431516633916U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 16178966745333885377U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7545129923202147703U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 9031889187993001617U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 6308472367425865347U;
            aOrbiterI = RotL64((aOrbiterI * 17118710301967158153U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 642109145903321046U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 9186268569255318035U;
            aOrbiterA = RotL64((aOrbiterA * 10714674348507516749U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 6091345356803675860U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 13218507921880873749U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15415157927185637717U), 5U);
            //
            aIngress = RotL64(aOrbiterJ, 24U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 41U)) + aOrbiterK) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterF, 30U)) + aOrbiterJ) + aPhaseGWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 57U)) + aOrbiterF) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterK, 21U));
            aWandererC = aWandererC + (((RotL64(aScatter, 58U) + RotL64(aOrbiterJ, 11U)) + aOrbiterK) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + RotL64(aWandererD, 39U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 18041U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 23576U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 16575U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((aIndex + 19056U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCarry, 51U)) + (RotL64(aCross, 35U) ^ RotL64(aPrevious, 22U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (aWandererJ + RotL64(aIngress, 43U)) + 4980738603982643969U;
            aOrbiterK = (((aWandererA + RotL64(aPrevious, 27U)) + RotL64(aCarry, 19U)) + 17660278413018470020U) + aPhaseGOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = (((aWandererC + RotL64(aCross, 4U)) + RotL64(aCarry, 53U)) + 17598114429859543466U) + aPhaseGOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aScatter, 19U)) + RotL64(aCarry, 5U)) + 10993929335279994739U;
            aOrbiterI = (aWandererG + RotL64(aIngress, 35U)) + 17967203122976322481U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 1872290205549034384U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 16607778671782810797U;
            aOrbiterJ = RotL64((aOrbiterJ * 340054507611349681U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 4895226930754394376U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 14960359005982301383U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8546231310054433721U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 9921642352377700630U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 893281964367208693U;
            aOrbiterG = RotL64((aOrbiterG * 2345509157333444217U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 8232519988397858732U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 4433022122758913407U;
            aOrbiterH = RotL64((aOrbiterH * 834240393225479419U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 12689609831247168353U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 404535388957472176U;
            aOrbiterI = RotL64((aOrbiterI * 14534020545479806593U), 29U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 46U);
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterG, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 39U) + aOrbiterI) + RotL64(aOrbiterH, 21U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 13U) + RotL64(aOrbiterG, 5U)) + aOrbiterH) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterK, 58U)) + aOrbiterG);
            aWandererG = aWandererG + (((RotL64(aPrevious, 50U) + RotL64(aOrbiterI, 43U)) + aOrbiterJ) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterJ, 13U)) + aOrbiterK) + aPhaseGWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 54U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 27448U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneA[((aIndex + 27739U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32017U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((aIndex + 24931U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 29U)) ^ (RotL64(aIngress, 43U) + RotL64(aCross, 14U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = ((aWandererB + RotL64(aIngress, 21U)) + RotL64(aCarry, 27U)) + 4476099022490972343U;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 10U)) + 16836423700375760429U) + aPhaseGOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aPrevious, 57U)) + 8850577488928703557U;
            aOrbiterF = (((aWandererK + RotL64(aScatter, 39U)) + RotL64(aCarry, 43U)) + 7091631824560042743U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 29U)) + RotL64(aCarry, 5U)) + 12560498899956759494U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 7797973377112012161U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 6173820673874805794U;
            aOrbiterD = RotL64((aOrbiterD * 15741300047917486527U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 10805025132310245348U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 7139216143268029968U;
            aOrbiterI = RotL64((aOrbiterI * 8349754682635765573U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 8241544862261635722U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 4735527016563596150U;
            aOrbiterF = RotL64((aOrbiterF * 6621354217673598381U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 5166171126690294033U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 11117641762075368393U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4980156869201219393U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 6312932356458415421U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 1304139291184508668U;
            aOrbiterB = RotL64((aOrbiterB * 90744653170922319U), 27U);
            //
            aIngress = RotL64(aOrbiterF, 3U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterJ, 18U)) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 12U) + aOrbiterB) + RotL64(aOrbiterF, 3U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 23U) + aOrbiterD) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterJ, 47U)) + aOrbiterD) + aPhaseGWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 39U) + aOrbiterI) + RotL64(aOrbiterB, 37U)) + aPhaseGWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + RotL64(aWandererK, 35U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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

void TwistExpander_Softball_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 7009U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3605U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5391U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 2169U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCarry, 48U)) ^ (RotL64(aCross, 19U) ^ RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = ((aWandererB + RotL64(aCross, 13U)) + 2783898056762489197U) + aPhaseHOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aScatter, 38U)) + RotL64(aCarry, 53U)) + 7177192902873343053U;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 3U)) + RotL64(aCarry, 35U)) + 12254703232691980774U;
            aOrbiterG = (((aWandererI + RotL64(aIngress, 27U)) + RotL64(aCarry, 19U)) + 15446547245691219559U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = (aWandererK + RotL64(aCross, 51U)) + 888475203006174856U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 3649183529366307877U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 4642631047518805167U;
            aOrbiterK = RotL64((aOrbiterK * 14791564497487717167U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 6108329730724782250U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 8334054653023816636U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9352516059501924393U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 5891895375031474350U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 3176720746238477862U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1869961473768307911U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 6111038696865301675U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 11914998302228682704U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11738924766359642853U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 17005063057791320948U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 18333780598768130670U;
            aOrbiterH = RotL64((aOrbiterH * 5416759844884107303U), 3U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 5U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 56U));
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aPrevious, 37U) + aOrbiterG) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 53U)) + aPhaseHWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 12U) + RotL64(aOrbiterH, 43U)) + aOrbiterI);
            aWandererA = aWandererA + ((RotL64(aCross, 47U) + RotL64(aOrbiterI, 11U)) + aOrbiterG);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 60U)) + aOrbiterH);
            aWandererC = aWandererC + ((((RotL64(aCross, 57U) + RotL64(aOrbiterI, 27U)) + aOrbiterK) + RotL64(aCarry, 23U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 4U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 13993U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneC[((aIndex + 12083U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15809U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((aIndex + 14000U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCross, 5U)) + (RotL64(aIngress, 19U) ^ RotL64(aCarry, 36U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = ((aWandererB + RotL64(aIngress, 27U)) + RotL64(aCarry, 51U)) + 17264605017518259932U;
            aOrbiterI = (aWandererF + RotL64(aCross, 35U)) + 15209184354580778643U;
            aOrbiterG = (aWandererH + RotL64(aPrevious, 11U)) + 3299527965014731384U;
            aOrbiterC = (((aWandererG + RotL64(aScatter, 58U)) + RotL64(aCarry, 13U)) + 16293096431816127821U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = (((aWandererE + RotL64(aCross, 43U)) + RotL64(aCarry, 29U)) + 11031983436878828337U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 9188018632448236358U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 13420816400363406556U;
            aOrbiterG = RotL64((aOrbiterG * 10958221259662190519U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 2485063384097917101U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 3089135816938128264U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8813152992957361153U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 10730544971770435788U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 10431767565618874806U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4723078464590561545U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 14883796491656899074U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 13465877783538483706U;
            aOrbiterI = RotL64((aOrbiterI * 14311686051108108503U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 13322163435314643713U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 3307316600284371955U;
            aOrbiterC = RotL64((aOrbiterC * 12337846092069506365U), 29U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 43U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 11U) + aOrbiterG) + RotL64(aOrbiterC, 3U)) + aPhaseHWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 11U)) + aOrbiterK) + RotL64(aCarry, 19U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 44U) + RotL64(aOrbiterI, 56U)) + aOrbiterC);
            aWandererE = aWandererE + (((RotL64(aCross, 53U) + RotL64(aOrbiterI, 21U)) + aOrbiterE) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterC, 39U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + RotL64(aWandererG, 47U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 23417U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19953U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16765U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22705U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCross, 37U)) + (RotL64(aCarry, 6U) ^ RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = (((aWandererH + RotL64(aIngress, 35U)) + RotL64(aCarry, 39U)) + 12027839670755583592U) + aPhaseHOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aScatter, 11U)) + 15380130703509859843U;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 27U)) + RotL64(aCarry, 57U)) + 4590907433867798074U;
            aOrbiterF = (((aWandererB + RotL64(aCross, 60U)) + RotL64(aCarry, 13U)) + 1754574023602519724U) + aPhaseHOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (aWandererK + RotL64(aScatter, 51U)) + 9832756659564903767U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 5035088494491470403U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 14199170923323644638U;
            aOrbiterI = RotL64((aOrbiterI * 4518257134117207121U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 8325619421264440438U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 969534320779067977U;
            aOrbiterH = RotL64((aOrbiterH * 17767548306355264705U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 270575869402913847U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 13344806516599578910U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10193544126281901579U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 15143147951139409101U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 14425582489214169238U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16893787086337916355U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 13951127523239064584U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 14177925225918293579U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13079514031864998485U), 37U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterC, 27U);
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterF, 48U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 51U) + aOrbiterI) + RotL64(aOrbiterF, 3U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aScatter, 37U) + RotL64(aOrbiterI, 37U)) + aOrbiterH) + RotL64(aCarry, 47U)) + aPhaseHWandererUpdateSaltC[((aIndex + 24U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterF, 51U)) + aOrbiterB);
            aWandererJ = aWandererJ + (((RotL64(aCross, 4U) + aOrbiterC) + RotL64(aOrbiterF, 22U)) + RotL64(aCarry, 19U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 13U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererH, 46U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + RotL64(aWandererK, 35U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 24673U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneA[((aIndex + 28866U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27202U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneC[((aIndex + 29983U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 29U) ^ RotL64(aCarry, 54U)) + (RotL64(aIngress, 41U) + RotL64(aCross, 13U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (aWandererA + RotL64(aScatter, 51U)) + 15316464782468770057U;
            aOrbiterB = (((aWandererH + RotL64(aCross, 19U)) + RotL64(aCarry, 5U)) + 6642872057476351588U) + aPhaseHOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 43U)) + 660732654689529192U;
            aOrbiterD = (((aWandererB + RotL64(aIngress, 42U)) + RotL64(aCarry, 29U)) + 7235418086884000655U) + aPhaseHOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aCross, 29U)) + 14784518476694580493U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 12222433977933449375U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 8573001207708329927U;
            aOrbiterK = RotL64((aOrbiterK * 17771120145431297541U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 16035256260815013172U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 15767726974121910203U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 719060452537759331U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 17712217935322939971U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 13488963456923357159U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16785285630840310405U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 10222949131965611079U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 1495561412321657209U;
            aOrbiterB = RotL64((aOrbiterB * 9706305581868526265U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 16156530750584361434U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 7773792489045606309U;
            aOrbiterE = RotL64((aOrbiterE * 10730624207715601393U), 57U);
            //
            aIngress = RotL64(aOrbiterJ, 6U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aPrevious, 23U) + aOrbiterJ) + RotL64(aOrbiterE, 35U)) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 52U)) + aOrbiterK);
            aWandererG = aWandererG + (((RotL64(aScatter, 11U) + RotL64(aOrbiterD, 43U)) + aOrbiterE) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 56U) + RotL64(aOrbiterK, 27U)) + aOrbiterD) + aPhaseHWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterJ, 13U)) + aOrbiterD) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererE, 3U);
            aCarry = aCarry + RotL64(aIngress, 56U);
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
