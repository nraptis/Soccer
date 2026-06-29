#include "TwistExpander_Lacrosse_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Lacrosse_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xD6C601658866DBCDULL + 0xAF8420875BEA1234ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xC74BF96C72650A69ULL + 0x8EEEF381F5AAD854ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x8C6E3F5D23918969ULL + 0xA1E13991EFA7425CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xA611C5226B7E4D8BULL + 0x95A7297B549CF782ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xAAF0354F17D28A7DULL + 0xDEA1C5CABC0B48B3ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xCE3C623E81582029ULL + 0x94CFB8457400E5C7ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xFDBF55A1F3CEAD6DULL + 0x8D2AE198B2591316ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xCB8CBA6D9D67DD65ULL + 0xA989D1BB7B7A8A1FULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xDFCF67208BF728A1ULL + 0xD6E4E2458F5B9652ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xBF1E5ED7B3395631ULL + 0x938E45CD400F5BFDULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xD1895B84B3EADF0FULL + 0xA6A051682F216529ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xF1BCAE860EAEAA39ULL + 0xC4D6BD1021F773CBULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xF6E9F78528F85B63ULL + 0xBB0F79BCEC173530ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xD3F433BE6EA0534BULL + 0x8B3EAC38F282A2F5ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xFCBCE38A060F3E57ULL + 0x8C707749F6485228ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xBA731FBAAFF23F5FULL + 0xFEE7C53973150B42ULL);
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
            aIngress = RotL64(mSource[((aIndex + 3372U)) & S_BLOCK1], 39U) ^ RotL64(pSnow[((aIndex + 4515U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 1126U)) & S_BLOCK1], 41U) ^ RotL64(mSource[((aIndex + 555U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aIngress, 27U)) + (RotL64(aCross, 56U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterH = ((aWandererE + RotL64(aScatter, 6U)) + 7651355040951791298U) + aOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 43U)) + RotL64(aCarry, 11U)) + 13988210277931659312U;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 29U)) + 9846849412579537783U) + aNonceWordG;
            aOrbiterI = (aWandererB + RotL64(aCross, 37U)) + 12746719939495876158U;
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 53U)) + 11498066185182895284U;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 39U)) + 11101058955193080232U) + aNonceWordA;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 57U)) + 15513734459555672046U) + aNonceWordO;
            aOrbiterG = ((aWandererI + RotL64(aCross, 18U)) + RotL64(aCarry, 47U)) + 15711108675349394643U;
            aOrbiterF = ((aWandererH + RotL64(aIngress, 13U)) + 4771231759949468556U) + aOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (aWandererK + RotL64(aCross, 3U)) + 11449258010811305256U;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 27U)) + RotL64(aCarry, 37U)) + 17036938391509986723U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 6999245666776654250U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 2106819066263369528U;
            aOrbiterB = RotL64((aOrbiterB * 13005885810757743129U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 12716183358903477216U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 16752724547046059889U;
            aOrbiterC = RotL64((aOrbiterC * 11475905692393034141U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 17623077680983093163U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 6726003022297274986U;
            aOrbiterE = RotL64((aOrbiterE * 14709385877103232653U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 2842410225096524740U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 9235178377537910514U;
            aOrbiterF = RotL64((aOrbiterF * 11813751114775673845U), 41U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterK) + 2619888019860844610U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordM;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 6295481948199619613U) ^ aNonceWordL;
            aOrbiterI = RotL64((aOrbiterI * 15429161806953951205U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 9724921158061115570U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 4070976180958458679U;
            aOrbiterA = RotL64((aOrbiterA * 6080566609081811453U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 5864247978960125554U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 7771249710071026757U;
            aOrbiterG = RotL64((aOrbiterG * 4787660062590737657U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 15006900854988166845U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 2755659268987119046U) ^ aNonceWordJ;
            aOrbiterK = RotL64((aOrbiterK * 8043939381186802359U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 1922321482806966418U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 13910818219761929659U;
            aOrbiterJ = RotL64((aOrbiterJ * 8895973123729951173U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 7540972911473176026U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 5419023469522423893U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1380429266266313945U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 2349651834739320824U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 7651355040951791298U;
            aOrbiterH = RotL64((aOrbiterH * 3713776056028698433U), 53U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterF, 43U);
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + (RotL64(aOrbiterA, 39U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 54U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 5U) + aOrbiterH) + RotL64(aOrbiterA, 52U)) + aWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 41U) + aOrbiterC) + RotL64(aOrbiterE, 23U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 20U) + RotL64(aOrbiterJ, 47U)) + aOrbiterB) + aNonceWordC);
            aWandererG = aWandererG + (((RotL64(aScatter, 43U) + RotL64(aOrbiterB, 39U)) + aOrbiterH) + RotL64(aCarry, 23U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 3U) + aOrbiterB) + RotL64(aOrbiterA, 3U));
            aWandererC = aWandererC + ((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 29U)) + aOrbiterA);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 13U)) + aOrbiterJ);
            aWandererB = aWandererB + ((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterG, 35U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 57U) + aOrbiterC) + RotL64(aOrbiterF, 60U)) + aNonceWordH);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 28U) + aOrbiterK) + RotL64(aOrbiterJ, 11U)) + RotL64(aCarry, 37U)) + aNonceWordI);
            aWandererF = aWandererF ^ (((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterG, 37U)) + aWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 54U));
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 26U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 9426U)) & S_BLOCK1], 21U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 7676U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 8130U)) & S_BLOCK1], 3U) ^ RotL64(mSource[((aIndex + 7939U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 29U) ^ RotL64(aIngress, 41U)) + (RotL64(aPrevious, 58U) ^ RotL64(aCross, 13U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterH = ((aWandererD + RotL64(aCross, 5U)) + 11210042748013785976U) + aOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = (((aWandererB + RotL64(aScatter, 53U)) + RotL64(aCarry, 27U)) + 4584747303233477454U) + aNonceWordD;
            aOrbiterC = (aWandererH + RotL64(aIngress, 35U)) + 8878765929792969517U;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 48U)) + RotL64(aCarry, 19U)) + 2172232330280041122U;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 13U)) + 8378937026022264016U) + aOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 21U)) + 8683007464695824208U;
            aOrbiterI = (aWandererJ + RotL64(aScatter, 57U)) + 9564352997357118134U;
            aOrbiterB = ((aWandererK + RotL64(aCross, 23U)) + 11713878436769887528U) + aNonceWordM;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 19U)) + RotL64(aCarry, 43U)) + 8052917623074021077U;
            aOrbiterF = (aWandererG + RotL64(aScatter, 30U)) + 7720597162792145185U;
            aOrbiterG = (aWandererC + RotL64(aCross, 37U)) + 2602847785328475621U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 17813669222300509724U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 8724263063156573013U) ^ aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3632927017737834359U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 6882429835961613492U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 13213313479525717359U;
            aOrbiterH = RotL64((aOrbiterH * 2411431247725974895U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 2401526093648669573U) + aOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 3616448566579979749U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13323155103752121393U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 18268262471839710401U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 5116424918948694752U;
            aOrbiterB = RotL64((aOrbiterB * 7641143782996332069U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 11405305689555640431U) + aNonceWordP;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 12427591396711015574U) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 8112834135715541223U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 16960781161508084626U) + aNonceWordC;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 12382604781005282628U;
            aOrbiterD = RotL64((aOrbiterD * 17196168631120103115U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 10054839091354729292U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 4167641616532985407U) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 919291747187787625U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 14383737233143309039U) + aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 16258779988369405932U;
            aOrbiterE = RotL64((aOrbiterE * 8348773195366160215U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 4777263172049970723U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 12498046021142146499U;
            aOrbiterK = RotL64((aOrbiterK * 5941015011162130901U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 7435001955334177144U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 4100235545173125433U;
            aOrbiterG = RotL64((aOrbiterG * 5046572784117638909U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 1981704568071298614U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 11210042748013785976U;
            aOrbiterJ = RotL64((aOrbiterJ * 17889749044418386565U), 5U);
            //
            aIngress = RotL64(aOrbiterD, 6U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterA, 41U)) + aOrbiterC) + RotL64(aCarry, 53U)) + aWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 37U) + aOrbiterH) + RotL64(aOrbiterA, 53U));
            aWandererJ = aWandererJ + (((((RotL64(aIngress, 53U) + RotL64(aOrbiterE, 13U)) + aOrbiterF) + RotL64(aCarry, 13U)) + aNonceWordK) + aWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 48U) + RotL64(aOrbiterA, 23U)) + aOrbiterI);
            aWandererI = aWandererI + ((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 26U)) + aOrbiterD);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 21U) + aOrbiterA) + RotL64(aOrbiterG, 37U));
            aWandererD = aWandererD + ((RotL64(aCross, 29U) + RotL64(aOrbiterB, 47U)) + aOrbiterC);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 41U) + aOrbiterE) + RotL64(aOrbiterG, 39U));
            aWandererK = aWandererK + ((RotL64(aIngress, 51U) + RotL64(aOrbiterK, 35U)) + aOrbiterA);
            aWandererH = aWandererH ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterK, 19U)) + aOrbiterI) + aNonceWordN);
            aWandererF = aWandererF + ((RotL64(aScatter, 60U) + RotL64(aOrbiterJ, 50U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 48U));
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + RotL64(aWandererF, 35U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aFireLaneB[((aIndex + 11759U)) & S_BLOCK1], 52U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 16062U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 11637U)) & S_BLOCK1], 43U) ^ RotL64(pSnow[((aIndex + 15585U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 21U)) ^ (RotL64(aCross, 39U) + RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterJ = (aWandererD + RotL64(aScatter, 35U)) + 2101601659597850213U;
            aOrbiterI = (aWandererB + RotL64(aIngress, 21U)) + 2759794072560720121U;
            aOrbiterG = (aWandererG + RotL64(aCross, 58U)) + 9443562552411269339U;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 29U)) + RotL64(aCarry, 57U)) + 10801360546699857975U;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 27U)) + RotL64(aCarry, 29U)) + 8020716394829332019U;
            aOrbiterE = (((aWandererA + RotL64(aScatter, 5U)) + 1021894212367773801U) + aOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 43U)) + 13346855534622490176U) + aNonceWordG;
            aOrbiterB = ((aWandererJ + RotL64(aCross, 11U)) + RotL64(aCarry, 47U)) + 16359309548462953836U;
            aOrbiterC = (aWandererH + RotL64(aIngress, 14U)) + 12642446944680783519U;
            aOrbiterA = ((aWandererF + RotL64(aScatter, 41U)) + 8197424982767553380U) + aOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = (aWandererK + RotL64(aCross, 47U)) + 14346334610901859094U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 14171304260534233539U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 334531601308283605U;
            aOrbiterG = RotL64((aOrbiterG * 5012968232749075075U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 10707856298471572695U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 18364775750091914766U;
            aOrbiterK = RotL64((aOrbiterK * 15735143943129143265U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 8531394793118363836U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 15352876929406908882U) ^ aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 475199047053777179U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 567682016232278157U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 2068146551757663119U;
            aOrbiterD = RotL64((aOrbiterD * 1557877740957797555U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 7776122587613256525U) + aOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 16430938890724272256U;
            aOrbiterB = RotL64((aOrbiterB * 4540270493783593257U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 11912000645055436094U) + aNonceWordD;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 16800749242578741498U;
            aOrbiterC = RotL64((aOrbiterC * 17804584625034241737U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 5909199180260499150U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 5751089915336865588U;
            aOrbiterI = RotL64((aOrbiterI * 15376689503142397927U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 3478216857728853008U) + aOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 18007567146937338241U;
            aOrbiterJ = RotL64((aOrbiterJ * 6620498877303917855U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 17454259424163653490U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 6276120962018305311U;
            aOrbiterA = RotL64((aOrbiterA * 7560618224285018801U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 3839336239901666431U) + aNonceWordL;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 6230149015045237670U;
            aOrbiterE = RotL64((aOrbiterE * 1838983748994340883U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 17552095486612766544U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 2101601659597850213U;
            aOrbiterH = RotL64((aOrbiterH * 2915330118061857271U), 3U);
            //
            aIngress = RotL64(aOrbiterG, 3U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + (RotL64(aOrbiterA, 50U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + RotL64(aOrbiterK, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aScatter, 29U) + aOrbiterG) + RotL64(aOrbiterF, 11U)) + aWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 51U)) + aOrbiterK) + RotL64(aCarry, 53U)) + aNonceWordK);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 14U)) + aOrbiterG);
            aWandererA = aWandererA + ((RotL64(aCross, 27U) + RotL64(aOrbiterC, 27U)) + aOrbiterH);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 51U) + aOrbiterB) + RotL64(aOrbiterJ, 35U)) + aNonceWordP);
            aWandererJ = aWandererJ + ((RotL64(aCross, 48U) + aOrbiterA) + RotL64(aOrbiterH, 29U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterA, 18U)) + aOrbiterB) + aWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 37U) + aOrbiterD) + RotL64(aOrbiterE, 21U)) + aNonceWordH);
            aWandererB = aWandererB ^ ((RotL64(aCross, 53U) + aOrbiterI) + RotL64(aOrbiterJ, 23U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterC, 3U)) + aOrbiterG) + RotL64(aCarry, 21U)) + aNonceWordB);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 10U) + aOrbiterE) + RotL64(aOrbiterA, 5U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 34U));
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 22U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 19736U)) & S_BLOCK1], 57U) ^ RotL64(pSnow[((aIndex + 17737U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 17857U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(mSource[((S_BLOCK1 - aIndex + 21335U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21219U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aPrevious, 43U)) + (RotL64(aCarry, 57U) + RotL64(aIngress, 10U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterI = (((aWandererJ + RotL64(aPrevious, 27U)) + RotL64(aCarry, 5U)) + 785861751704720606U) + aNonceWordO;
            aOrbiterD = (aWandererF + RotL64(aScatter, 29U)) + 15968088718435606299U;
            aOrbiterB = (aWandererE + RotL64(aCross, 44U)) + 1393976526590347151U;
            aOrbiterE = (aWandererG + RotL64(aIngress, 5U)) + 17240750947292745884U;
            aOrbiterF = ((((aWandererB + RotL64(aCross, 3U)) + RotL64(aCarry, 51U)) + 4921576136163183137U) + aOrbiterAssignSaltA[((aIndex + 6U)) & S_SALT1]) + aNonceWordD;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 13U)) + 3334047873553153032U;
            aOrbiterH = (aWandererK + RotL64(aScatter, 46U)) + 15086509978458408698U;
            aOrbiterJ = (((aWandererH + RotL64(aIngress, 19U)) + RotL64(aCarry, 21U)) + 892391205397581998U) + aOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (aWandererI + RotL64(aCross, 11U)) + 2965686403183767521U;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 57U)) + 14632215393655706170U) + aNonceWordG;
            aOrbiterC = (aWandererA + RotL64(aScatter, 35U)) + 15740589515342377322U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 11131164813943086445U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 6988080581278900960U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6412189142344044255U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 16021254613117657178U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 6183615599897921154U;
            aOrbiterF = RotL64((aOrbiterF * 9976411093264211033U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 12533992547026652747U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 3104325358982904219U;
            aOrbiterH = RotL64((aOrbiterH * 14977348108778147265U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 3878525937957474644U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 2120435259884368445U;
            aOrbiterA = RotL64((aOrbiterA * 15964718652193073177U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 14928658302694194856U) + aNonceWordJ;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 9121310461310309348U;
            aOrbiterC = RotL64((aOrbiterC * 17304439784647477491U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 3715693239100476493U) + aNonceWordI;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 7336577492932262490U;
            aOrbiterJ = RotL64((aOrbiterJ * 11074754160002665253U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 2312452827448455675U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 4322756069651934618U;
            aOrbiterI = RotL64((aOrbiterI * 6908893297397073539U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 4962079617577705818U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 5072727464750706525U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4947670001221089155U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 4553791875259778686U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 15823770920225774233U) ^ aOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 409663191536830375U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 9468608484284459072U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 8658861660659699947U;
            aOrbiterG = RotL64((aOrbiterG * 2933359123761406353U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 14453429515273506170U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 785861751704720606U;
            aOrbiterK = RotL64((aOrbiterK * 3544627380583668815U), 37U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterC, 47U);
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterB, 11U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterD, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aScatter, 41U) + RotL64(aOrbiterB, 35U)) + aOrbiterE);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 26U) + aOrbiterD) + RotL64(aOrbiterE, 29U));
            aWandererI = aWandererI + (((RotL64(aCross, 23U) + RotL64(aOrbiterC, 44U)) + aOrbiterD) + aWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 19U)) + aOrbiterB);
            aWandererA = aWandererA + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 39U)) + aOrbiterF) + RotL64(aCarry, 47U)) + aWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 21U)) + aOrbiterC) + aNonceWordC);
            aWandererE = aWandererE + ((((RotL64(aCross, 29U) + RotL64(aOrbiterH, 48U)) + aOrbiterD) + RotL64(aCarry, 53U)) + aNonceWordE);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 11U) + aOrbiterK) + RotL64(aOrbiterI, 3U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterH, 11U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 46U) + RotL64(aOrbiterF, 51U)) + aOrbiterI) + aNonceWordL);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterK, 37U)) + aNonceWordB);
            //
            aCarry = aCarry + (RotL64(aWandererK, 14U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 21U));
            aCarry = aCarry + RotL64(aWandererD, 60U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 24040U)) & S_BLOCK1], 13U) ^ RotL64(mSource[((aIndex + 24696U)) & S_BLOCK1], 46U));
            aIngress ^= (RotL64(pSnow[((aIndex + 24886U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 25551U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26542U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneB[((aIndex + 24044U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aPrevious, 24U)) ^ (RotL64(aCross, 5U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterJ = (aWandererE + RotL64(aScatter, 27U)) + 7722279280863371124U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 35U)) + 11584220561732385598U) + aNonceWordO;
            aOrbiterA = ((aWandererA + RotL64(aCross, 58U)) + 7834679350105534657U) + aOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = (aWandererD + RotL64(aIngress, 41U)) + 11347994382444180879U;
            aOrbiterB = (((aWandererG + RotL64(aCross, 23U)) + RotL64(aCarry, 41U)) + 9449903188047063431U) + aNonceWordI;
            aOrbiterC = ((aWandererB + RotL64(aScatter, 47U)) + 6516243976652795170U) + aOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aPrevious, 19U)) + 8420815253991184777U;
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 13U)) + RotL64(aCarry, 37U)) + 9081386852515170937U;
            aOrbiterD = (aWandererF + RotL64(aCross, 21U)) + 14375955191735286867U;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 56U)) + RotL64(aCarry, 23U)) + 880757589768436072U;
            aOrbiterE = (aWandererH + RotL64(aPrevious, 3U)) + 3349856625725164229U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 7826309957607577207U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 8057435761214313635U;
            aOrbiterA = RotL64((aOrbiterA * 4718430712767038607U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 9565237500443303103U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 15893066735310588501U;
            aOrbiterC = RotL64((aOrbiterC * 8457633439171452397U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 3276844534476430842U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 6828644383891274120U) ^ aOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 979580351653410157U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 2815676923011504251U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 5030251870850928417U;
            aOrbiterB = RotL64((aOrbiterB * 7075653570570819253U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 13464083008377887034U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 8994560761846897590U;
            aOrbiterK = RotL64((aOrbiterK * 9892839554658865143U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 8398813387154468736U) + aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 8136429428340910892U) ^ aNonceWordG;
            aOrbiterG = RotL64((aOrbiterG * 3348811490733577295U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 418587250696862341U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 4111667833838312094U;
            aOrbiterI = RotL64((aOrbiterI * 860949442143849147U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 6075478294190926371U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 2208124955874142264U;
            aOrbiterH = RotL64((aOrbiterH * 15741988616251072075U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 4726538724576443010U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 6524078248882840425U;
            aOrbiterD = RotL64((aOrbiterD * 9784875566721689069U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 14521003220464811621U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 16916247868211621303U) ^ aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1911638054294853877U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 18207293125461843123U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterI) ^ 7722279280863371124U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 14303108475807941791U), 37U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 51U);
            aIngress = aIngress + (RotL64(aOrbiterE, 60U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 6U)) + aOrbiterJ) + aNonceWordF);
            aWandererK = aWandererK ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterH, 21U)) + aOrbiterJ);
            aWandererB = aWandererB + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterI, 29U)) + aOrbiterC) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 23U) + aOrbiterB) + RotL64(aOrbiterG, 19U)) + aNonceWordK) + aWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterG, 37U)) + aOrbiterE);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterE, 23U));
            aWandererE = aWandererE + (((RotL64(aCross, 18U) + aOrbiterI) + RotL64(aOrbiterK, 53U)) + aNonceWordD);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 41U)) + aOrbiterE);
            aWandererI = aWandererI + (((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 13U)) + aOrbiterF) + aNonceWordA);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterB, 39U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 46U) + aOrbiterA) + RotL64(aOrbiterC, 46U)) + RotL64(aCarry, 5U)) + aWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 44U));
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28268U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((aIndex + 31329U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 32429U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27573U)) & S_BLOCK1], 5U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 30412U)) & S_BLOCK1], 43U));
            aCross ^= (RotL64(pSnow[((S_BLOCK1 - aIndex + 28110U)) & S_BLOCK1], 14U) ^ RotL64(aFireLaneB[((aIndex + 31081U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCross, 26U)) ^ (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterB = (aWandererK + RotL64(aPrevious, 29U)) + 15036852811491820366U;
            aOrbiterG = (aWandererH + RotL64(aScatter, 24U)) + 305637140752898475U;
            aOrbiterE = (((aWandererE + RotL64(aIngress, 39U)) + RotL64(aCarry, 43U)) + 11948631574496129610U) + aOrbiterAssignSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = (((aWandererG + RotL64(aCross, 57U)) + RotL64(aCarry, 13U)) + 5321623592482991426U) + aNonceWordP;
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 11U)) + 4075270159062690728U) + aNonceWordI;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 37U)) + RotL64(aCarry, 47U)) + 15111580500356908928U;
            aOrbiterK = (aWandererA + RotL64(aCross, 19U)) + 7244150695504160363U;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 13U)) + 5131563519577488862U) + aNonceWordE;
            aOrbiterD = (aWandererD + RotL64(aCross, 21U)) + 5881954992088651371U;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 35U)) + 12780935808751507998U) + aOrbiterAssignSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aScatter, 44U)) + 12599159643925470226U) + aNonceWordH;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 9466589929741834066U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 6093158735705189789U;
            aOrbiterE = RotL64((aOrbiterE * 7453778295800853653U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 17461243886150519249U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 15456408913739900718U;
            aOrbiterB = RotL64((aOrbiterB * 16093292401746174671U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 11260643903290392780U) + aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 7870342756041882616U;
            aOrbiterC = RotL64((aOrbiterC * 2431528656086173419U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 134484990005888936U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 10626896209992890407U;
            aOrbiterH = RotL64((aOrbiterH * 12034131076645285597U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 14031164129515132292U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 1771835705730244212U;
            aOrbiterG = RotL64((aOrbiterG * 186981668443596623U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 16395472745067254664U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 1455944290845294254U;
            aOrbiterF = RotL64((aOrbiterF * 6757824754363319079U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 17866422769075350837U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 10226884082632410805U;
            aOrbiterK = RotL64((aOrbiterK * 206035536985843815U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 14474587247775371703U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 8501763445324525303U) ^ aNonceWordD;
            aOrbiterI = RotL64((aOrbiterI * 5298694643596784007U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 222650368553738561U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterC) ^ 3901452368735982094U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterA = RotL64((aOrbiterA * 18347115513126660483U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 3063093906728331146U) + aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 9026710562384443411U;
            aOrbiterJ = RotL64((aOrbiterJ * 8411243802199203035U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 11282041925238364080U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 15036852811491820366U;
            aOrbiterD = RotL64((aOrbiterD * 18185121326941087841U), 27U);
            //
            aIngress = RotL64(aOrbiterH, 29U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 10U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 53U));
            aIngress = aIngress + RotL64(aOrbiterF, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 6U) + aOrbiterD) + RotL64(aOrbiterE, 13U)) + aWandererUpdateSaltD[((aIndex + 6U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterK, 41U));
            aWandererD = aWandererD ^ ((((RotL64(aCross, 53U) + RotL64(aOrbiterI, 11U)) + aOrbiterH) + aNonceWordC) + aWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 57U)) + aOrbiterB) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 11U) + aOrbiterJ) + RotL64(aOrbiterA, 19U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 37U)) + aOrbiterJ) + RotL64(aCarry, 13U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 56U) + RotL64(aOrbiterG, 52U)) + aOrbiterI) + aNonceWordJ);
            aWandererC = aWandererC + ((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterA, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterF, 27U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterD, 21U)) + aOrbiterH);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 13U) + aOrbiterK) + RotL64(aOrbiterB, 6U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 40U));
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 34U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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

void TwistExpander_Lacrosse_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x8E31C79865484BEDULL + 0xF76B9367755A225AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xA0EF27E6A5F17E91ULL + 0x97A1CA1E83A21B7EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xBE50401FF7F3F237ULL + 0xB640FC6D95408488ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xDC405BA9C2F9EB41ULL + 0x849E19DCEA6E48DBULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xF567FEE898F5C409ULL + 0xB318A0567A501F41ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xF4FF67EF820E29E1ULL + 0xAC4E62985DC4D5EAULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xFA8B117F54689733ULL + 0xDBE05A9C920C60BBULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xAB5651EDC0C4C369ULL + 0xFD14DF4498009910ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xA7A48185A85EE693ULL + 0xFB0DF962BCA8F930ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xF6328A23F14D1D11ULL + 0xD5580FA844800F1CULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x8BD9648E70AC16EDULL + 0x85CE658026E328CCULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xBD0D881F837F485BULL + 0xD6DAABC5B550C274ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xE117860ADA02FF15ULL + 0x94FDB106C4D8F07CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xA4451A6A37B362A7ULL + 0xD8C17B68B9C606ACULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xB77BBB7AFF2626BFULL + 0xD0FB14B0934F1E64ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x923CB819F7AFEB99ULL + 0x8DCB8AB554395BDCULL);
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
            aIngress = RotL64(aExpandLaneA[((aIndex + 2678U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2352U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 860U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3504U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aPrevious, 57U)) + (RotL64(aIngress, 5U) ^ RotL64(aCarry, 34U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterB = ((aWandererK + RotL64(aCross, 46U)) + 11998579547770778580U) + aNonceWordB;
            aOrbiterG = (((aWandererC + RotL64(aScatter, 19U)) + 8409465187298704610U) + aOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1]) + aNonceWordH;
            aOrbiterD = (((aWandererA + RotL64(aIngress, 23U)) + 3470222286110333500U) + aOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordP;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 57U)) + RotL64(aCarry, 3U)) + 5704486785203069994U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 53U)) + RotL64(aCarry, 27U)) + 10334944660253279633U;
            aOrbiterC = (aWandererE + RotL64(aScatter, 40U)) + 7626852700722567477U;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 11U)) + RotL64(aCarry, 11U)) + 14631310754943209743U;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 35U)) + 807160297237854120U;
            aOrbiterH = (aWandererJ + RotL64(aCross, 27U)) + 5624154783624196107U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 4971444394698940423U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 6340057638461027062U;
            aOrbiterD = RotL64((aOrbiterD * 12027586111086798629U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 9003019862787819481U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 13632057463595873033U;
            aOrbiterA = RotL64((aOrbiterA * 12575202147280216765U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 12766104026871797746U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 4062118445824915939U;
            aOrbiterE = RotL64((aOrbiterE * 13130770039048080701U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 5258212525426469978U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 9956946981015983939U;
            aOrbiterC = RotL64((aOrbiterC * 8106382657040497669U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 10837606223056473999U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 13292864885504191134U;
            aOrbiterG = RotL64((aOrbiterG * 4445739587553669471U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 166087925900318658U) + aNonceWordD;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 6786842221885441388U) ^ aOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4411147600413147773U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 16888086378070246404U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 5240855484445974002U) ^ aOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 402652898573422271U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 6874866669211571608U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 732890824978127460U;
            aOrbiterJ = RotL64((aOrbiterJ * 3776365957702257453U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 5541380495707308058U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 17947326584411475765U) ^ aNonceWordC;
            aOrbiterH = RotL64((aOrbiterH * 10920952349981652899U), 35U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 35U);
            aIngress = aIngress + (RotL64(aOrbiterH, 21U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 48U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + RotL64(aOrbiterG, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aPrevious, 29U) + aOrbiterC) + RotL64(aOrbiterH, 6U)) + RotL64(aCarry, 47U)) + aNonceWordO);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 58U) + aOrbiterA) + RotL64(aOrbiterC, 41U));
            aWandererC = aWandererC + ((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterB, 23U));
            aWandererE = aWandererE ^ ((((RotL64(aCross, 37U) + aOrbiterJ) + RotL64(aOrbiterD, 27U)) + aNonceWordI) + aWandererUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 53U)) + aOrbiterJ) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 23U) + aOrbiterD) + RotL64(aOrbiterA, 12U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterH, 47U)) + aNonceWordL);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterH, 35U)) + aOrbiterG);
            aWandererH = aWandererH + (((RotL64(aIngress, 52U) + aOrbiterB) + RotL64(aOrbiterC, 19U)) + aWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 40U));
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + RotL64(aWandererD, 21U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 8149U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((aIndex + 5554U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7123U)) & S_BLOCK1], 6U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8212U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9799U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCarry, 21U)) + (RotL64(aPrevious, 3U) + RotL64(aCross, 38U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterH = ((aWandererK + RotL64(aIngress, 51U)) + 3650233661228036955U) + aOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aPrevious, 42U)) + 11607036400067735729U;
            aOrbiterK = (aWandererE + RotL64(aScatter, 57U)) + 3899614406903883035U;
            aOrbiterF = (aWandererD + RotL64(aCross, 19U)) + 8159156925629965143U;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 23U)) + 7148903913967261270U) + aNonceWordB;
            aOrbiterC = ((aWandererH + RotL64(aCross, 10U)) + RotL64(aCarry, 53U)) + 9161665622287517848U;
            aOrbiterA = (((aWandererF + RotL64(aIngress, 47U)) + RotL64(aCarry, 13U)) + 2981535013474059469U) + aOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aScatter, 27U)) + RotL64(aCarry, 41U)) + 15812469008200319549U;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 3U)) + 14687469489893270300U) + aNonceWordD;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 6025209349511417063U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 12964750392311112676U;
            aOrbiterK = RotL64((aOrbiterK * 12955480283032701843U), 53U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterB) + 6572355895765394340U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordP;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 3542300121890027981U;
            aOrbiterH = RotL64((aOrbiterH * 11201491178181273935U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 6477175684045398359U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 1081388388827929314U) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 8752188637514143529U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 13754328481584620771U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 3684673342659575917U;
            aOrbiterE = RotL64((aOrbiterE * 6139923312873039143U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 6542045150319909445U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 5352102692424060388U) ^ aOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7385758355501860261U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 9110100774657340354U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 2813273684436269057U) ^ aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10468759062594022273U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 5860425751137403755U) + aNonceWordH;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 1598622981888978548U;
            aOrbiterJ = RotL64((aOrbiterJ * 651816500461718345U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 14710305692377606725U) + aNonceWordK;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 16280545617802383463U;
            aOrbiterA = RotL64((aOrbiterA * 12541767206978802063U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 6849565243667718750U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 12152381961996750050U;
            aOrbiterC = RotL64((aOrbiterC * 11185935780063403807U), 47U);
            //
            aIngress = RotL64(aOrbiterE, 19U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + (RotL64(aOrbiterF, 46U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterB, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aCross, 5U) + RotL64(aOrbiterB, 4U)) + aOrbiterJ);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 47U) + aOrbiterH) + RotL64(aOrbiterK, 53U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 41U) + RotL64(aOrbiterA, 47U)) + aOrbiterJ) + RotL64(aCarry, 57U)) + aNonceWordO);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 34U) + aOrbiterA) + RotL64(aOrbiterB, 23U)) + aWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 51U) + RotL64(aOrbiterC, 18U)) + aOrbiterD) + aNonceWordF);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterF, 57U)) + aWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 27U) + RotL64(aOrbiterA, 13U)) + aOrbiterF);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 60U) + aOrbiterH) + RotL64(aOrbiterE, 37U)) + aNonceWordN);
            aWandererA = aWandererA + ((((RotL64(aCross, 21U) + RotL64(aOrbiterK, 27U)) + aOrbiterE) + RotL64(aCarry, 43U)) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererG, 37U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 11639U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneD[((aIndex + 11111U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11282U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 15859U)) & S_BLOCK1], 28U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 15680U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aIngress, 53U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 24U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterJ = ((aWandererH + RotL64(aCross, 26U)) + RotL64(aCarry, 19U)) + 3199575576585871314U;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 5U)) + 2533378188975571824U) + aNonceWordH;
            aOrbiterF = (aWandererF + RotL64(aIngress, 51U)) + 6819782112558312658U;
            aOrbiterC = (((aWandererE + RotL64(aScatter, 47U)) + RotL64(aCarry, 11U)) + 12690060987724798497U) + aOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = ((aWandererK + RotL64(aIngress, 10U)) + 7088375139715629606U) + aOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = (((aWandererC + RotL64(aPrevious, 43U)) + RotL64(aCarry, 47U)) + 17785618677423695666U) + aNonceWordC;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 21U)) + 1714999280296491277U) + aNonceWordA;
            aOrbiterB = (aWandererI + RotL64(aCross, 57U)) + 17611338506932491624U;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 39U)) + 6475727359297421201U) + aNonceWordK;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 2347744591204119530U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 2739317903351401068U;
            aOrbiterF = RotL64((aOrbiterF * 15435029315209475631U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 8663535261373274338U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 8205245127823536479U;
            aOrbiterE = RotL64((aOrbiterE * 13857005110466856439U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 8916510616749754516U) + aNonceWordI;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 3944805940148512932U;
            aOrbiterH = RotL64((aOrbiterH * 18082271583211389701U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 14094751253118853302U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 14094299829196076311U;
            aOrbiterG = RotL64((aOrbiterG * 6370012560657108493U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 3940673811518673802U) + aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 3015106523254484839U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9655401190755573379U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 15404103131982599922U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 1828655763233900875U;
            aOrbiterB = RotL64((aOrbiterB * 13024358077740310049U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 1236981890899916502U) + aNonceWordF;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 18208975564570342697U;
            aOrbiterD = RotL64((aOrbiterD * 4577109989465876801U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 17882273895471449661U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 16196010765612713713U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15624856645134182005U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 14639250100311162559U) + aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 9139027997336903273U;
            aOrbiterJ = RotL64((aOrbiterJ * 1853126389565574293U), 27U);
            //
            aIngress = RotL64(aOrbiterE, 35U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterC, 38U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 60U)) + aOrbiterJ);
            aWandererE = aWandererE + (((RotL64(aScatter, 23U) + RotL64(aOrbiterC, 23U)) + aOrbiterE) + aWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 13U)) + aOrbiterH);
            aWandererF = aWandererF + (((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 39U));
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 38U) + RotL64(aOrbiterC, 3U)) + aOrbiterF) + aNonceWordD) + aWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 53U) + RotL64(aOrbiterD, 27U)) + aOrbiterC) + RotL64(aCarry, 11U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterJ, 52U)) + aOrbiterF);
            aWandererG = aWandererG + (((RotL64(aScatter, 5U) + RotL64(aOrbiterC, 35U)) + aOrbiterJ) + aNonceWordP);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 34U) + aOrbiterB) + RotL64(aOrbiterH, 47U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + RotL64(aWandererF, 30U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 21068U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneC[((aIndex + 18935U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 18741U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19545U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 21658U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aPrevious, 13U)) ^ (RotL64(aIngress, 26U) + RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterF = (aWandererD + RotL64(aCross, 28U)) + 7632760812370906911U;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 19U)) + 6007174525479723089U) + aNonceWordE;
            aOrbiterI = (aWandererA + RotL64(aIngress, 51U)) + 3362829642521821048U;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 39U)) + 18009548556107978286U;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 57U)) + 17880909432272697327U;
            aOrbiterB = (aWandererE + RotL64(aIngress, 43U)) + 15961567935420752568U;
            aOrbiterG = (((aWandererF + RotL64(aPrevious, 14U)) + RotL64(aCarry, 57U)) + 10136559064656837921U) + aOrbiterAssignSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = (((aWandererB + RotL64(aCross, 47U)) + RotL64(aCarry, 23U)) + 17622019364405410277U) + aNonceWordJ;
            aOrbiterA = (((aWandererK + RotL64(aIngress, 35U)) + RotL64(aCarry, 41U)) + 6927494824421416306U) + aOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 7125170407794874847U) + aOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 12342273503071032250U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 867417849555857179U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 14997696377476124836U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 14874498694181230698U) ^ aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4026127545746010937U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 2549397729130885686U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 4217995818662767955U;
            aOrbiterC = RotL64((aOrbiterC * 5525525344485251063U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 4706089044415442525U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 17983900172670031015U) ^ aNonceWordK;
            aOrbiterK = RotL64((aOrbiterK * 541552737180932879U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 1904937798143929988U) + aNonceWordF;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 10620877287033139483U;
            aOrbiterF = RotL64((aOrbiterF * 16711012562024287213U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 15681091173163181525U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 2655543246639000084U;
            aOrbiterA = RotL64((aOrbiterA * 16686375598149755947U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 2647895110857289213U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 5581609212017175954U) ^ aOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15330263616699031311U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 13609076329627787987U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 6244266279516622070U) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 12488345779236971095U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 5289624364508923581U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 16351476803965903112U;
            aOrbiterJ = RotL64((aOrbiterJ * 9012522724650442597U), 11U);
            //
            aIngress = RotL64(aOrbiterK, 51U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterD, 60U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 42U) + RotL64(aOrbiterG, 51U)) + aOrbiterJ) + aWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 20U)) + aOrbiterC) + aNonceWordO);
            aWandererH = aWandererH + ((RotL64(aScatter, 19U) + RotL64(aOrbiterB, 3U)) + aOrbiterK);
            aWandererG = aWandererG ^ ((RotL64(aCross, 23U) + aOrbiterK) + RotL64(aOrbiterG, 41U));
            aWandererD = aWandererD + ((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 37U)) + aOrbiterD);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterA, 10U));
            aWandererE = aWandererE + (((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 29U)) + aOrbiterI) + aWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 56U) + RotL64(aOrbiterD, 47U)) + aOrbiterC) + RotL64(aCarry, 21U)) + aNonceWordG);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 10U));
            aCarry = aCarry + RotL64(aWandererJ, 29U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = RotL64(aOperationLaneB[((aIndex + 22044U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 24144U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24918U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24252U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aPrevious, 54U)) ^ (RotL64(aCarry, 23U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterH = (aWandererF + RotL64(aPrevious, 38U)) + 9133751643283278896U;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 43U)) + RotL64(aCarry, 35U)) + 8971581804375380408U;
            aOrbiterG = ((aWandererK + RotL64(aCross, 29U)) + RotL64(aCarry, 53U)) + 12559650383714566592U;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 47U)) + 15753206088872859163U) + aNonceWordL;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 5U)) + 7640756270450762350U) + aOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = (((aWandererG + RotL64(aScatter, 53U)) + 7340073357551376125U) + aOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1]) + aNonceWordC;
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 11U)) + RotL64(aCarry, 21U)) + 5270256573644196046U;
            aOrbiterB = ((aWandererE + RotL64(aCross, 57U)) + 3567367996479995928U) + aNonceWordF;
            aOrbiterC = (aWandererB + RotL64(aScatter, 20U)) + 11939634537492733738U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 7051817732424527120U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 1730487669951837941U;
            aOrbiterG = RotL64((aOrbiterG * 15191634337956285841U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 18009252467909454817U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 2361024272031696442U;
            aOrbiterF = RotL64((aOrbiterF * 15215151562500226027U), 13U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterD) + 15902755877642960397U) + aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1]) + aNonceWordP;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 12243517544704116184U;
            aOrbiterJ = RotL64((aOrbiterJ * 2576071074148141447U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 16846181962302186187U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 636121425116506681U) ^ aOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17075030673338779993U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 6887385655828217318U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 3705834550934775862U;
            aOrbiterK = RotL64((aOrbiterK * 11275428284929594435U), 37U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterH) + 11165142437077969438U) + aOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1]) + aNonceWordM;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 6426659930331618269U;
            aOrbiterC = RotL64((aOrbiterC * 17170640810530893705U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 12629082390899315789U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 4277510580069574724U) ^ aNonceWordH;
            aOrbiterI = RotL64((aOrbiterI * 9829125163412708305U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 13814834144170469978U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 3698381854100295826U;
            aOrbiterB = RotL64((aOrbiterB * 5126359230872258015U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 11623170635983579937U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 7247413650388803796U;
            aOrbiterH = RotL64((aOrbiterH * 3403219499465560059U), 5U);
            //
            aIngress = RotL64(aOrbiterC, 14U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + RotL64(aOrbiterB, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aCross, 4U) + RotL64(aOrbiterC, 47U)) + aOrbiterB) + RotL64(aCarry, 21U)) + aNonceWordG);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterD, 11U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 23U) + aOrbiterB) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 37U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterK, 4U)) + aNonceWordK);
            aWandererF = aWandererF + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 57U)) + aOrbiterJ) + aWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 14U) + RotL64(aOrbiterC, 43U)) + aOrbiterG);
            aWandererK = aWandererK + (((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 39U)) + aOrbiterG) + aWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterH, 26U)) + aOrbiterI) + aNonceWordO);
            aWandererG = aWandererG + ((RotL64(aScatter, 51U) + RotL64(aOrbiterJ, 51U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (RotL64(aWandererD, 60U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + RotL64(aWandererB, 11U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aOperationLaneC[((aIndex + 28282U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneA[((aIndex + 32590U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32586U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29499U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCarry, 50U)) + (RotL64(aCross, 35U) ^ RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterC = (aWandererD + RotL64(aCross, 18U)) + 2225397913940961213U;
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 23U)) + 8342544893601343643U;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 57U)) + 162922186381417187U) + aNonceWordB;
            aOrbiterD = (aWandererG + RotL64(aIngress, 11U)) + 11660218373710972210U;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 41U)) + RotL64(aCarry, 51U)) + 14909034764605802354U;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 34U)) + 16776955237009701511U) + aOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aCross, 51U)) + 5834487809188925253U) + aOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = (((aWandererE + RotL64(aScatter, 29U)) + RotL64(aCarry, 39U)) + 1498492772767040320U) + aNonceWordP;
            aOrbiterB = (((aWandererC + RotL64(aCross, 5U)) + RotL64(aCarry, 27U)) + 4161765458781579617U) + aNonceWordJ;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 10511923076962447765U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 8575954471692620021U) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 12526744988828982731U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 6536325446331340573U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterA) ^ 1790628986900286346U) ^ aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterI = RotL64((aOrbiterI * 5262997114200816715U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 2623814807619278590U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 11676970995834706612U;
            aOrbiterD = RotL64((aOrbiterD * 10057461115132434901U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 13836786354224256591U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 6293096163612129260U) ^ aOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8977954126326217153U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 4271144764978661248U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 15938494256992560202U;
            aOrbiterE = RotL64((aOrbiterE * 10004841288382726739U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 11038155227307702976U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 12408749795071243930U;
            aOrbiterB = RotL64((aOrbiterB * 5527720475032868855U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 1673665849053496882U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 12866353361497103629U;
            aOrbiterC = RotL64((aOrbiterC * 6041125499398924871U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 10673935802381580966U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 8946776538955520352U) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 12293084177712710021U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 16294935203370452805U) + aNonceWordK;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 4697759331563852212U) ^ aOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14407806317275373043U), 23U);
            //
            aIngress = RotL64(aOrbiterC, 47U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 40U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterE, 3U)) + aOrbiterB) + RotL64(aCarry, 11U)) + aNonceWordA);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterE, 19U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 18U) + RotL64(aOrbiterK, 56U)) + aOrbiterE) + aNonceWordC) + aWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterE, 47U)) + aOrbiterJ) + aWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 29U)) + aOrbiterC) + RotL64(aCarry, 53U)) + aNonceWordE);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 3U) + aOrbiterE) + RotL64(aOrbiterH, 23U));
            aWandererE = aWandererE + ((RotL64(aCross, 57U) + RotL64(aOrbiterJ, 51U)) + aOrbiterA);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterE, 12U)) + aNonceWordO);
            aWandererH = aWandererH + ((RotL64(aIngress, 26U) + RotL64(aOrbiterI, 37U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 60U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + RotL64(aWandererD, 41U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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

void TwistExpander_Lacrosse_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x9D43257BEEC2EFA5ULL + 0xA03A4B068A031736ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x8334137F1F879EEBULL + 0xB85158C43E8951D7ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xDEAA0504732E4371ULL + 0x82932837AED9FC56ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xD3CFB5749BE32C9FULL + 0x86DE0890C3D56968ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xFED08DE80F798A01ULL + 0xB20425BF5CD87E6EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xFCBA8ECFA0F02BB5ULL + 0xDE5F9ABBDCA423C2ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xDCD19BEA2A5F30CDULL + 0x84D705C65403C2B6ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xED022892F638FD6FULL + 0x8B364FBAF019C7B6ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xDFA12C9576BC91DFULL + 0xD9D6DB7D3B9BA137ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xFAF849F5D0DDB74DULL + 0xEFE13DDE420D3A36ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x8BC6DC0744C8758DULL + 0x8358230F59D7D384ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xFD14F81C7BDBDDBBULL + 0x9F003946B26C9CDBULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xAAD938B8E22C3AF3ULL + 0xE55CF3E17CAE3B46ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xF7EFC59EECC87CE3ULL + 0xEE0F2DC49301E7FEULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xA4A352D4C105DBCBULL + 0xD5227C465A1614B1ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xD88C7CA828E65C11ULL + 0x8936ED7690E7928BULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 7119U)) & S_BLOCK1], 20U) ^ RotL64(aOperationLaneB[((aIndex + 5621U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 4218U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 6218U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 7842U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 2925U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 13U)) + (RotL64(aCross, 27U) + RotL64(aIngress, 44U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterE = (((aWandererK + RotL64(aPrevious, 56U)) + 12583180859826261500U) + aOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterA = ((aWandererB + RotL64(aCross, 29U)) + RotL64(aCarry, 27U)) + 9067093488553721468U;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 3U)) + 12173106198862881754U) + aOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = (((aWandererI + RotL64(aScatter, 41U)) + RotL64(aCarry, 11U)) + 11333491014394592654U) + aNonceWordF;
            aOrbiterH = (((aWandererC + RotL64(aIngress, 19U)) + RotL64(aCarry, 41U)) + 3511883526940919554U) + aNonceWordC;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 7416810692106273044U) + aNonceWordM;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 8341174972619784110U;
            aOrbiterK = RotL64((aOrbiterK * 17722163445765437279U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 2220852854836962979U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 8090781422229383825U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 578293950675644397U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 2338801236599102223U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 12484514711848308104U;
            aOrbiterA = RotL64((aOrbiterA * 10364216764253366067U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 13684861340589131816U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 12796636819991873058U) ^ aOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5533508014234835669U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 7634198650894837690U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterA) ^ 10240326122201201762U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 8758703497719125901U), 13U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterA, 13U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + RotL64(aOrbiterE, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterE, 51U));
            aWandererC = aWandererC + ((((RotL64(aCross, 51U) + RotL64(aOrbiterA, 3U)) + aOrbiterH) + RotL64(aCarry, 19U)) + aWandererUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 27U) + RotL64(aOrbiterE, 13U)) + aOrbiterA) + aNonceWordE) + aWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterA, 26U)) + RotL64(aCarry, 53U)) + aNonceWordO);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 18U) + RotL64(aOrbiterE, 37U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 40U));
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 8337U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((aIndex + 12301U)) & S_BLOCK1], 28U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 14071U)) & S_BLOCK1], 37U) ^ RotL64(aFireLaneC[((aIndex + 14964U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 10616U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 13457U)) & S_BLOCK1], 28U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 11822U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 6U) + RotL64(aIngress, 53U)) ^ (RotL64(aCross, 23U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterI = (((aWandererB + RotL64(aCross, 21U)) + 13915875634607599122U) + aOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordB;
            aOrbiterH = (((aWandererE + RotL64(aIngress, 39U)) + RotL64(aCarry, 5U)) + 1695770381382411673U) + aNonceWordI;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 11U)) + RotL64(aCarry, 39U)) + 3709105579778295511U;
            aOrbiterB = ((((aWandererD + RotL64(aScatter, 51U)) + RotL64(aCarry, 57U)) + 7673376335333251804U) + aOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1]) + aNonceWordD;
            aOrbiterD = ((aWandererF + RotL64(aCross, 60U)) + 8814147709738503518U) + aNonceWordC;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 13451412605350381172U) + aNonceWordH;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 6447870234069609538U) ^ aOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4016219229618539433U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 13419487997946496825U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 5478309847615220345U;
            aOrbiterD = RotL64((aOrbiterD * 12953043149543448765U), 5U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterI) + 3635184969215610049U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 12527903812035294828U;
            aOrbiterB = RotL64((aOrbiterB * 12540800512035534967U), 35U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterG) + 1684685110885338814U) + aOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1]) + aNonceWordP;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 12860354576326835090U) ^ aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12743745087733307255U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 9081823570147481835U) + aNonceWordM;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 14369321778210049109U;
            aOrbiterH = RotL64((aOrbiterH * 17865953349448767035U), 13U);
            //
            aIngress = RotL64(aOrbiterD, 36U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 36U)) + aOrbiterH) + aNonceWordE) + aWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 19U)) + aOrbiterH) + RotL64(aCarry, 21U)) + aNonceWordO);
            aWandererF = aWandererF ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterI, 27U)) + aOrbiterD) + aNonceWordN);
            aWandererB = aWandererB + ((((RotL64(aIngress, 22U) + RotL64(aOrbiterB, 57U)) + aOrbiterG) + aNonceWordF) + aWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 10U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 19605U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((aIndex + 20033U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 24303U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21823U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19162U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 24160U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 22069U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 21U)) ^ (RotL64(aIngress, 43U) + RotL64(aCross, 56U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterB = (((aWandererD + RotL64(aScatter, 35U)) + RotL64(aCarry, 23U)) + 7270044678408187242U) + aNonceWordO;
            aOrbiterH = (((aWandererG + RotL64(aPrevious, 51U)) + RotL64(aCarry, 51U)) + 10192278965379756766U) + aOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 5U)) + RotL64(aCarry, 11U)) + 17568666746676060748U;
            aOrbiterF = (((aWandererB + RotL64(aCross, 22U)) + 14312927531124963037U) + aOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1]) + aNonceWordC;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 13U)) + 9825825726152087706U) + aNonceWordE;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 9696778570255265896U) + aOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 17657841352013417228U) ^ aOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17562220176018833833U), 5U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterE) + 16207815085909628439U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterF = (((aOrbiterF ^ aOrbiterH) ^ 1752979206374514227U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterF = RotL64((aOrbiterF * 14182667540650694199U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 10456310689643905854U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 16127830548663742550U) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 4355938404839045417U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 2940917376003930842U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 7353596864777649953U;
            aOrbiterI = RotL64((aOrbiterI * 7499468723171042005U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 12725092740446150705U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 5791296650856037010U;
            aOrbiterH = RotL64((aOrbiterH * 760379251950502133U), 19U);
            //
            aIngress = RotL64(aOrbiterF, 47U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 30U) + aOrbiterH) + RotL64(aOrbiterB, 58U)) + aWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterF, 13U)) + aOrbiterE);
            aWandererG = aWandererG + ((((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 35U)) + aNonceWordF);
            aWandererD = aWandererD ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterH, 41U)) + aOrbiterI);
            aWandererK = aWandererK + (((((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterH, 23U)) + RotL64(aCarry, 23U)) + aNonceWordH) + aWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 30521U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((aIndex + 27317U)) & S_BLOCK1], 10U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 30899U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((aIndex + 27963U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26258U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28735U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 32054U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 29U) ^ RotL64(aPrevious, 43U)) + (RotL64(aCross, 11U) ^ RotL64(aIngress, 60U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterA = (((aWandererG + RotL64(aScatter, 51U)) + RotL64(aCarry, 57U)) + 18302975933754610273U) + aNonceWordI;
            aOrbiterE = (((aWandererE + RotL64(aPrevious, 35U)) + RotL64(aCarry, 5U)) + 16736972646771456082U) + aNonceWordA;
            aOrbiterG = (((aWandererC + RotL64(aCross, 18U)) + RotL64(aCarry, 19U)) + 17389406266488137442U) + aNonceWordN;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 43U)) + 5252511566486165539U) + aOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = (((aWandererD + RotL64(aPrevious, 5U)) + 5730715427422747640U) + aOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1]) + aNonceWordK;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 6412695646456045825U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 9539701605708994494U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6511935168278632407U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 18355107116412945722U) + aNonceWordH;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 11735742491750132942U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 18129835093627763685U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 12363819388562658842U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 5861430292304371543U;
            aOrbiterA = RotL64((aOrbiterA * 12989055611235382695U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 15027487084595017708U) + aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 7012850020745791926U) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 15952928839355613939U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 11904871669287886120U) + aOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 11199760114477343208U;
            aOrbiterE = RotL64((aOrbiterE * 7156374911847525867U), 3U);
            //
            aIngress = RotL64(aOrbiterG, 57U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 18U));
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterA, 27U)) + aNonceWordC);
            aWandererC = aWandererC + (((((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 51U)) + aNonceWordG) + aWandererUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterK, 5U));
            aWandererG = aWandererG + (((((RotL64(aScatter, 14U) + aOrbiterK) + RotL64(aOrbiterA, 36U)) + RotL64(aCarry, 13U)) + aNonceWordE) + aWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 47U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 30U);
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

void TwistExpander_Lacrosse_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x81BBC7D1431D111FULL + 0xFCA4043F3B684F1EULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x9C50FDA90358BC73ULL + 0xE46324C52278B3AAULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xE15E2CA1924B6C77ULL + 0xF1522F59128EB3E3ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xC620F01A00A3EE27ULL + 0xE04D5E100F5FE3ECULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xED53626A68706FD5ULL + 0x8F8DC274E317040BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xEF73E454E7FA1F67ULL + 0xB8FC9FDE7EC7114FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xE6F5F219A0888521ULL + 0x88DFF7ECDCC168B3ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xD0D89E140A9AC0F7ULL + 0xACCF448B4C92A18CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x8C5AB9078FA9C125ULL + 0x863450DFDF097176ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x8FBDB8BA38CAE0ABULL + 0xF786A5CBEEDA6084ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xBA851EE695387589ULL + 0xE9AF9636617EAE78ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xF57A6596198F28FBULL + 0xBC2176C3B9A479B7ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xF206B6E8A13335D9ULL + 0xF7889CD3B9F0C467ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x88054B717FD3C085ULL + 0xA6815A496D4EE46CULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xB0060141AE2DDC87ULL + 0xC830A82D0181DA17ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xC69B4096EC50E1A9ULL + 0xD24E9B655C8C0EBDULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3036U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((aIndex + 6684U)) & S_BLOCK1], 12U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 1588U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2243U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 4122U)) & S_BLOCK1], 10U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 6675U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCross, 6U)) + (RotL64(aIngress, 19U) + RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterF = ((aWandererA + RotL64(aIngress, 19U)) + RotL64(aCarry, 29U)) + 5295352595333316211U;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 11U)) + RotL64(aCarry, 3U)) + 2341795367042042605U;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 53U)) + 10122175780504033663U) + aNonceWordN;
            aOrbiterC = (aWandererJ + RotL64(aCross, 37U)) + 10084612804696198554U;
            aOrbiterI = (aWandererC + RotL64(aIngress, 60U)) + 16470424309851045971U;
            aOrbiterH = (((aWandererD + RotL64(aCross, 5U)) + 656016130975227994U) + aOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordD;
            aOrbiterE = (((aWandererE + RotL64(aPrevious, 43U)) + RotL64(aCarry, 53U)) + 15313268829659834317U) + aOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 3795220914993923394U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 14044442220988813825U;
            aOrbiterG = RotL64((aOrbiterG * 3270650852546606835U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 3804224626734584802U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 7980006306010255693U;
            aOrbiterI = RotL64((aOrbiterI * 13958505239726088561U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 13746830564584711549U) + aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 11852212099729274845U) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 2164880979318247855U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 9083223471018084847U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 13706723820703853346U;
            aOrbiterE = RotL64((aOrbiterE * 11361854103656219887U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 1713819986642275223U) + aNonceWordO;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 1382000168233902914U;
            aOrbiterC = RotL64((aOrbiterC * 3894160765130198157U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 4540474625764565485U) + aNonceWordH;
            aOrbiterH = (((aOrbiterH ^ aOrbiterG) ^ 1756168174375757220U) ^ aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 12739160208010092017U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 1409297070183609309U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 6082750101445444357U) ^ aOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17438740230251860935U), 47U);
            //
            aIngress = RotL64(aOrbiterE, 27U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 20U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aScatter, 27U) + aOrbiterF) + RotL64(aOrbiterE, 21U)) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 21U) + RotL64(aOrbiterF, 43U)) + aOrbiterG) + aNonceWordI) + aWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 46U) + RotL64(aOrbiterC, 13U)) + aOrbiterI) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterG, 51U)) + aOrbiterJ) + aWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 53U) + RotL64(aOrbiterH, 35U)) + aOrbiterC);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 3U) + aOrbiterH) + RotL64(aOrbiterI, 28U)) + aNonceWordF);
            aWandererF = aWandererF + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 5U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 34U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + RotL64(aWandererA, 21U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 12143U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((aIndex + 8808U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 10487U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneC[((aIndex + 13778U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8624U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 15022U)) & S_BLOCK1], 20U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 11597U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 29U) ^ RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 43U) + RotL64(aCross, 56U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterB = (aWandererC + RotL64(aIngress, 34U)) + 6771552164800695068U;
            aOrbiterI = (aWandererF + RotL64(aCross, 27U)) + 12131763371571322040U;
            aOrbiterC = (aWandererE + RotL64(aScatter, 47U)) + 3326182381395522013U;
            aOrbiterH = ((((aWandererA + RotL64(aPrevious, 41U)) + RotL64(aCarry, 29U)) + 12288775097697156383U) + aOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1]) + aNonceWordO;
            aOrbiterE = ((aWandererK + RotL64(aCross, 13U)) + RotL64(aCarry, 43U)) + 5195948373449796741U;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 57U)) + 14404044002250137144U) + aNonceWordM;
            aOrbiterD = ((((aWandererG + RotL64(aScatter, 19U)) + RotL64(aCarry, 3U)) + 11142382920035825426U) + aOrbiterAssignSaltE[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordI;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 2967149520256475485U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 1470907369577818097U;
            aOrbiterC = RotL64((aOrbiterC * 9398653295177725883U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 9231668148004163910U) + aNonceWordL;
            aOrbiterE = (((aOrbiterE ^ aOrbiterH) ^ 13078929163913892386U) ^ aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterE = RotL64((aOrbiterE * 7509829068700523627U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 9485274692075657877U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 12216951187543631673U) ^ aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6571066246507310805U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 6933334652581744234U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 17260276102423580920U;
            aOrbiterB = RotL64((aOrbiterB * 7796879893790990605U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 387767848169714392U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 8597538259308082638U;
            aOrbiterK = RotL64((aOrbiterK * 4888054690557707241U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 7996708724489146033U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 15357384191688149939U) ^ aOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9827691726832491373U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 17739222908739454637U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 1614322333281471170U;
            aOrbiterI = RotL64((aOrbiterI * 7063116837752240891U), 53U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterD, 27U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aCross, 50U) + RotL64(aOrbiterB, 41U)) + aOrbiterD) + aNonceWordB);
            aWandererI = aWandererI + ((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 12U)) + aOrbiterE);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterC, 19U)) + aOrbiterK);
            aWandererK = aWandererK + ((((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterK, 51U)) + RotL64(aCarry, 39U)) + aWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 5U)) + aOrbiterI) + aNonceWordN);
            aWandererA = aWandererA + ((((RotL64(aScatter, 27U) + RotL64(aOrbiterK, 29U)) + aOrbiterI) + RotL64(aCarry, 27U)) + aWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 37U) + aOrbiterE) + RotL64(aOrbiterK, 35U)) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (RotL64(aWandererK, 20U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 23296U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneA[((aIndex + 18640U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 16576U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 20550U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17032U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 17481U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 16962U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCarry, 27U)) ^ (RotL64(aCross, 53U) + RotL64(aIngress, 40U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 35U)) + RotL64(aCarry, 5U)) + 9855743441035905047U;
            aOrbiterD = (((aWandererG + RotL64(aIngress, 3U)) + 8426286937143990276U) + aOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordM;
            aOrbiterC = ((aWandererE + RotL64(aCross, 43U)) + RotL64(aCarry, 41U)) + 7146752367170267002U;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 19U)) + 12947210066678101726U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 27U)) + 15902163559925328965U;
            aOrbiterH = (((aWandererA + RotL64(aIngress, 52U)) + 8506649889346449469U) + aOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordI;
            aOrbiterJ = (((aWandererH + RotL64(aPrevious, 11U)) + RotL64(aCarry, 29U)) + 8226286036430263052U) + aNonceWordB;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 2703047093452420216U) + aNonceWordO;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 6769351326360139560U;
            aOrbiterC = RotL64((aOrbiterC * 5318104980014706265U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 9857025533281333281U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 238297452132277585U) ^ aNonceWordD;
            aOrbiterH = RotL64((aOrbiterH * 12974709749856065985U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 7203572312072908931U) + aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 12497027346166575632U;
            aOrbiterD = RotL64((aOrbiterD * 1703586436725662307U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 473851890609048879U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 1664484956453886047U;
            aOrbiterK = RotL64((aOrbiterK * 8566500756326590209U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 4635095143004754116U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 17695676150967345793U) ^ aOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5780416541584439301U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 15628965269863402796U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 9190117464399730235U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5586437438425999715U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 17835918238346011086U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 4398005402429282682U) ^ aOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14828737209913317463U), 27U);
            //
            aIngress = RotL64(aOrbiterD, 27U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 27U)) + aOrbiterK);
            aWandererH = aWandererH ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterI, 53U)) + aOrbiterJ) + aNonceWordA);
            aWandererG = aWandererG + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterC, 5U)) + aOrbiterJ) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 43U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 22U) + RotL64(aOrbiterI, 21U)) + aOrbiterK) + RotL64(aCarry, 35U)) + aWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 34U)) + aOrbiterH) + aWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 3U) + aOrbiterJ) + RotL64(aOrbiterA, 13U)) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererA, 24U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + RotL64(aWandererD, 43U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 30381U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 26900U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 30106U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 28584U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32030U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26828U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 29136U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aPrevious, 19U)) + (RotL64(aIngress, 53U) ^ RotL64(aCarry, 6U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterF = ((aWandererB + RotL64(aCross, 51U)) + 4751694786009671052U) + aNonceWordA;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 21U)) + 16362725160370844224U) + aNonceWordC;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 35U)) + 6360885380915941057U) + aOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = (((aWandererG + RotL64(aScatter, 13U)) + RotL64(aCarry, 11U)) + 5154536007972297036U) + aNonceWordG;
            aOrbiterB = (((aWandererA + RotL64(aIngress, 41U)) + RotL64(aCarry, 41U)) + 9362540581874808253U) + aOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = ((aWandererK + RotL64(aCross, 3U)) + 13902493871525612934U) + aNonceWordJ;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 28U)) + RotL64(aCarry, 29U)) + 10208452885367546542U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 3117030377279160998U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 17286247690414027870U;
            aOrbiterJ = RotL64((aOrbiterJ * 4896931759653832095U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 3930314320040949141U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 7289525252391668404U;
            aOrbiterA = RotL64((aOrbiterA * 15452162299105112187U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 3434167955466809185U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 17852573095128575663U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1485660158767033425U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 6137259687928853253U) + aNonceWordD;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 13992510605237574698U) ^ aNonceWordE;
            aOrbiterB = RotL64((aOrbiterB * 15346263295995333395U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 6470556523400123474U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 4333255670390099293U;
            aOrbiterE = RotL64((aOrbiterE * 11089933812030082647U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 7700424876430257995U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 16920736951239453071U;
            aOrbiterG = RotL64((aOrbiterG * 8920407493132380497U), 13U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterB) + 1635071690430295730U) + aOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1]) + aNonceWordP;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 9966700845966398620U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17210048121896546867U), 47U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 57U);
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 58U) + RotL64(aOrbiterF, 35U)) + aOrbiterB) + aNonceWordB);
            aWandererH = aWandererH + ((((RotL64(aIngress, 3U) + aOrbiterJ) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 57U)) + aNonceWordI);
            aWandererK = aWandererK ^ ((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterF, 53U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 41U) + aOrbiterE) + RotL64(aOrbiterF, 41U)) + RotL64(aCarry, 37U)) + aWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterA, 29U)) + aOrbiterE) + aNonceWordL);
            aWandererB = aWandererB + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 4U)) + aOrbiterG) + aNonceWordK) + aWandererUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 47U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererA, 12U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 39U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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

void TwistExpander_Lacrosse_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xEADCAAF42782CAA7ULL + 0xE92EF14B36DEF892ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x9F72A1DE8EFC318DULL + 0x957C11B63694AF09ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xFE76A3655DE13537ULL + 0x9FCB49D659970110ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xD622615CDDEA404DULL + 0x83A8DB0D0D88D6D2ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x8333D60703A633F9ULL + 0xA7B18FE76E565C57ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x9954DBE26804C7BBULL + 0x93A25A17F9C87B52ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xB424193530231313ULL + 0x87A2C10A54E37680ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xFF101FA33E79C13DULL + 0xFBA3CF6B388FEA53ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x8DC764CB7536CFDFULL + 0xB982C7B2CCE42071ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xFE0408C587F6A457ULL + 0xB8CCD3D3572AA07AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xD249CC431BA79A37ULL + 0xE92C7C18A601FEE8ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xBE36694D12B8EB0BULL + 0x9347CD82F53C317FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x9CD24F3865E5BB93ULL + 0xE9A31E28315A6BA4ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xB5F5CC6A87EC4F1DULL + 0xE9270EA9BF6C94FFULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xB3616D07AFAF833FULL + 0xF2FD6B06B91B7875ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xDD15C197CAE314F1ULL + 0xADB4A3ECA89C1704ULL);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 4795U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((aIndex + 1680U)) & S_BLOCK1], 42U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 2606U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 4834U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 2406U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 13U) ^ RotL64(aCarry, 40U)) + (RotL64(aIngress, 27U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterF = (((aWandererD + RotL64(aCross, 43U)) + RotL64(aCarry, 51U)) + 15036852811491820366U) + aOrbiterAssignSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = ((aWandererI + RotL64(aIngress, 3U)) + RotL64(aCarry, 5U)) + 305637140752898475U;
            aOrbiterE = ((((aWandererH + RotL64(aPrevious, 19U)) + RotL64(aCarry, 23U)) + 11948631574496129610U) + aOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordO;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 50U)) + 5321623592482991426U) + aNonceWordC;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 27U)) + 4075270159062690728U) + aNonceWordP;
            aOrbiterJ = (aWandererE + RotL64(aCross, 35U)) + 15111580500356908928U;
            aOrbiterB = (aWandererG + RotL64(aPrevious, 13U)) + 7244150695504160363U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 5131563519577488862U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 5881954992088651371U) ^ aNonceWordD;
            aOrbiterE = RotL64((aOrbiterE * 2424421828597294607U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 12780935808751507998U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 12599159643925470226U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17690046932587062701U), 51U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterE) + 9466589929741834066U) + aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1]) + aNonceWordA;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 6093158735705189789U) ^ aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7453778295800853653U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 17461243886150519249U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 15456408913739900718U;
            aOrbiterB = RotL64((aOrbiterB * 16093292401746174671U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 11260643903290392780U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 7870342756041882616U) ^ aNonceWordJ;
            aOrbiterK = RotL64((aOrbiterK * 2431528656086173419U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 134484990005888936U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 10626896209992890407U;
            aOrbiterJ = RotL64((aOrbiterJ * 12034131076645285597U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 14031164129515132292U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 1771835705730244212U;
            aOrbiterH = RotL64((aOrbiterH * 186981668443596623U), 13U);
            //
            aIngress = RotL64(aOrbiterE, 3U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 19U)) + aOrbiterE) + aNonceWordB);
            aWandererH = aWandererH + (((((RotL64(aCross, 47U) + RotL64(aOrbiterF, 13U)) + aOrbiterJ) + RotL64(aCarry, 37U)) + aNonceWordN) + aWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 56U) + RotL64(aOrbiterI, 3U)) + aOrbiterH);
            aWandererF = aWandererF + (((RotL64(aIngress, 19U) + aOrbiterK) + RotL64(aOrbiterI, 28U)) + aNonceWordL);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 37U)) + aOrbiterK) + aNonceWordI);
            aWandererK = aWandererK + (((RotL64(aIngress, 41U) + aOrbiterJ) + RotL64(aOrbiterE, 47U)) + RotL64(aCarry, 13U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 11U) + aOrbiterJ) + RotL64(aOrbiterB, 57U)) + aWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 14U));
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneA[((aIndex + 7984U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneC[((aIndex + 10509U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 6855U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 5903U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 10272U)) & S_BLOCK1], 30U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 10188U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCross, 21U)) + (RotL64(aIngress, 52U) ^ RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterC = (((aWandererJ + RotL64(aScatter, 21U)) + RotL64(aCarry, 43U)) + 6467297102954816305U) + aNonceWordL;
            aOrbiterJ = ((((aWandererD + RotL64(aIngress, 10U)) + RotL64(aCarry, 57U)) + 7921154109831114952U) + aOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1]) + aNonceWordA;
            aOrbiterD = (aWandererB + RotL64(aPrevious, 29U)) + 5701131763215638919U;
            aOrbiterH = (aWandererC + RotL64(aCross, 57U)) + 10022999076719002684U;
            aOrbiterK = (((aWandererK + RotL64(aPrevious, 51U)) + 4367135243038982316U) + aOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1]) + aNonceWordN;
            aOrbiterA = ((aWandererG + RotL64(aCross, 35U)) + RotL64(aCarry, 19U)) + 14445846824810383592U;
            aOrbiterF = (aWandererH + RotL64(aScatter, 3U)) + 7683697954545773253U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 17517006750428030899U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 2052484792684025476U;
            aOrbiterD = RotL64((aOrbiterD * 12463117571122469643U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 6279463052085808926U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 679280153651813684U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3047031560593583881U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 2939516520188460569U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 1960616434964712325U) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 15145998415466343039U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 12273819390719947361U) + aNonceWordO;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 5685033154709449397U) ^ aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9845666295874714959U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 9314494172199500653U) + aOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 15757631834636427621U;
            aOrbiterK = RotL64((aOrbiterK * 15483543888965744529U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 10878078046389399574U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 3583495913766365232U;
            aOrbiterC = RotL64((aOrbiterC * 2913540984990155225U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 7385544065754622301U) + aOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 16839599460207922881U;
            aOrbiterH = RotL64((aOrbiterH * 240651605910592561U), 35U);
            //
            aIngress = RotL64(aOrbiterC, 10U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 37U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterC, 19U)) + aOrbiterF);
            aWandererH = aWandererH + ((((RotL64(aIngress, 50U) + RotL64(aOrbiterK, 60U)) + aOrbiterD) + RotL64(aCarry, 3U)) + aNonceWordJ);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterD, 3U)) + aWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 21U) + RotL64(aOrbiterA, 27U)) + aOrbiterJ);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 41U)) + aOrbiterA);
            aWandererC = aWandererC + ((((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterJ, 47U)) + aNonceWordD) + aWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 14U));
            aCarry = aCarry + RotL64(aWandererC, 53U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 12380U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneD[((aIndex + 12774U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15951U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 15247U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneA[((aIndex + 12401U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCross, 23U)) ^ (RotL64(aCarry, 6U) ^ RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 41U)) + 3339283916456813609U) + aOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = ((aWandererD + RotL64(aIngress, 58U)) + 11339086426180649584U) + aNonceWordF;
            aOrbiterH = ((aWandererB + RotL64(aCross, 5U)) + RotL64(aCarry, 11U)) + 16819191669329316585U;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 21U)) + RotL64(aCarry, 57U)) + 8361916937762630725U;
            aOrbiterK = (aWandererH + RotL64(aCross, 29U)) + 18031328374429899857U;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 35U)) + 18261756894092897276U) + aNonceWordK;
            aOrbiterI = (((aWandererG + RotL64(aScatter, 11U)) + RotL64(aCarry, 39U)) + 4250319792907645666U) + aOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 1492411503643460886U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 17369549067879344180U;
            aOrbiterH = RotL64((aOrbiterH * 2947354306696216579U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 7301713524358676722U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 2985193736033012535U;
            aOrbiterK = RotL64((aOrbiterK * 7473297294949338265U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 14086975808140927408U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 10390516547834639800U;
            aOrbiterI = RotL64((aOrbiterI * 11441293212275890819U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 18205555540941493267U) + aOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 16967799565443938873U;
            aOrbiterF = RotL64((aOrbiterF * 3009081009044782443U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 9209505304067579944U) + aNonceWordG;
            aOrbiterC = (((aOrbiterC ^ aOrbiterF) ^ 3522631966146762306U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 3441982898533162599U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 8811497120829041188U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 14707301680850257294U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11383709499376464085U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 10080595991787801029U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 6822892187784299166U;
            aOrbiterD = RotL64((aOrbiterD * 7417016898027778287U), 47U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 47U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 12U) + aOrbiterH) + RotL64(aOrbiterC, 27U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 21U) + aOrbiterD) + RotL64(aOrbiterH, 3U)) + aNonceWordC) + aWandererUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterI, 58U)) + aOrbiterD);
            aWandererB = aWandererB + ((((RotL64(aCross, 53U) + RotL64(aOrbiterF, 47U)) + aOrbiterI) + RotL64(aCarry, 3U)) + aNonceWordM);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 47U) + aOrbiterK) + RotL64(aOrbiterH, 11U)) + aWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aIngress, 27U) + aOrbiterA) + RotL64(aOrbiterF, 39U)) + RotL64(aCarry, 23U)) + aNonceWordO);
            aWandererF = aWandererF ^ (((RotL64(aCross, 5U) + aOrbiterF) + RotL64(aOrbiterH, 21U)) + aNonceWordJ);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 60U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 19475U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneC[((aIndex + 18432U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 16576U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 17881U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16721U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCross, 6U)) ^ (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 19U)) + RotL64(aCarry, 53U)) + 6733949564325516029U;
            aOrbiterB = (((aWandererI + RotL64(aPrevious, 57U)) + 7304098437143918796U) + aOrbiterAssignSaltD[((aIndex + 20U)) & S_SALT1]) + aNonceWordD;
            aOrbiterG = (((aWandererA + RotL64(aCross, 27U)) + RotL64(aCarry, 13U)) + 3923949518391777800U) + aOrbiterAssignSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = ((aWandererK + RotL64(aScatter, 46U)) + RotL64(aCarry, 27U)) + 14243591003388927124U;
            aOrbiterE = (aWandererH + RotL64(aCross, 5U)) + 18329498724605410406U;
            aOrbiterA = (aWandererG + RotL64(aIngress, 11U)) + 13118172167747037249U;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 37U)) + 5272025143849174212U) + aNonceWordG;
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 16075917179214318424U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 15263590648674658399U) ^ aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9918239923411740337U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 13730046728289525921U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 7703141464499623408U) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 5886009900621521987U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 1382279753822135359U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterF) ^ 2973369221699098292U) ^ aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 7440242040663550631U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 11578274119583013219U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 3419411247737896674U;
            aOrbiterC = RotL64((aOrbiterC * 17814942652262802991U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 2582783513078999303U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 3959762790273529677U;
            aOrbiterE = RotL64((aOrbiterE * 383974377372162751U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 465795011576934604U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 17880826624185821135U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4445949147592860913U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 10819659185349413173U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 17298208553586835030U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1965860510614222093U), 3U);
            //
            aIngress = RotL64(aOrbiterF, 13U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 60U));
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 11U)) + aOrbiterF) + aWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 58U) + aOrbiterK) + RotL64(aOrbiterG, 5U));
            aWandererC = aWandererC + ((RotL64(aCross, 21U) + aOrbiterA) + RotL64(aOrbiterC, 51U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 43U)) + aOrbiterK);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 43U) + RotL64(aOrbiterF, 26U)) + aOrbiterA) + RotL64(aCarry, 13U)) + aNonceWordP);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 11U) + aOrbiterB) + RotL64(aOrbiterK, 35U));
            aWandererH = aWandererH + (((((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterC, 19U)) + RotL64(aCarry, 39U)) + aNonceWordB) + aWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererC, 52U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aExpandLaneB[((aIndex + 23843U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 26836U)) & S_BLOCK1], 34U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23227U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26434U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aIngress, 39U)) ^ (RotL64(aCross, 5U) + RotL64(aPrevious, 18U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterI = ((aWandererB + RotL64(aCross, 47U)) + RotL64(aCarry, 29U)) + 10336802574069791273U;
            aOrbiterH = (aWandererG + RotL64(aIngress, 21U)) + 169025388197058936U;
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 53U)) + 6541354188379168846U) + aNonceWordE;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 41U)) + 16223920526599306104U) + aNonceWordL;
            aOrbiterE = ((((aWandererE + RotL64(aIngress, 34U)) + RotL64(aCarry, 11U)) + 12756613707692514808U) + aOrbiterAssignSaltA[((aIndex + 24U)) & S_SALT1]) + aNonceWordO;
            aOrbiterA = (aWandererK + RotL64(aPrevious, 13U)) + 5082475548176484035U;
            aOrbiterF = (((aWandererJ + RotL64(aScatter, 5U)) + RotL64(aCarry, 47U)) + 4907435526952698526U) + aOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 14236627073831834337U) + aNonceWordP;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 11502511046130497584U;
            aOrbiterJ = RotL64((aOrbiterJ * 3460330807286625917U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 3679044835550219497U) + aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 11254838916686736746U;
            aOrbiterE = RotL64((aOrbiterE * 8631695922983532915U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 10582608424233200966U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 10449735026385340313U;
            aOrbiterI = RotL64((aOrbiterI * 7363770199734997411U), 21U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterE) + 4628253464169957835U) + aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1]) + aNonceWordD;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 17664454668473204465U) ^ aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4234720298731378527U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 3798386391743884889U) + aNonceWordF;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 1379331161819246587U;
            aOrbiterA = RotL64((aOrbiterA * 13086160171095077295U), 57U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterF) + 9816600392407327227U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordC;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 16781971616348376878U;
            aOrbiterB = RotL64((aOrbiterB * 12503867584828289879U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 4807797577690520554U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 2492057261148595922U;
            aOrbiterF = RotL64((aOrbiterF * 9453302540675483005U), 35U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 29U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 36U));
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 11U)) + aOrbiterH);
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterJ, 39U)) + aNonceWordB) + aWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterE, 4U)) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterH, 29U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 35U) + aOrbiterA) + RotL64(aOrbiterH, 53U));
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 58U) + aOrbiterB) + RotL64(aOrbiterJ, 21U)) + aNonceWordA) + aWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aScatter, 27U) + aOrbiterE) + RotL64(aOrbiterA, 47U)) + RotL64(aCarry, 3U)) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererE, 60U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + RotL64(aWandererI, 23U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 29854U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28650U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27539U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((aIndex + 29360U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 19U) ^ RotL64(aIngress, 6U)) + (RotL64(aCross, 39U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterE = (aWandererG + RotL64(aPrevious, 41U)) + 15813325389431304548U;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 11U)) + RotL64(aCarry, 53U)) + 2223874171125403602U;
            aOrbiterB = ((((aWandererC + RotL64(aIngress, 4U)) + RotL64(aCarry, 27U)) + 5510483568496824130U) + aOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1]) + aNonceWordL;
            aOrbiterH = ((aWandererB + RotL64(aCross, 35U)) + 15474152493495661876U) + aNonceWordB;
            aOrbiterD = (((aWandererE + RotL64(aIngress, 29U)) + 16846339705130829195U) + aOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1]) + aNonceWordE;
            aOrbiterI = (aWandererF + RotL64(aScatter, 51U)) + 1289670576865739669U;
            aOrbiterF = ((aWandererD + RotL64(aCross, 19U)) + RotL64(aCarry, 13U)) + 18017354919647006944U;
            //
            aOrbiterE = (((aOrbiterE + aOrbiterK) + 8539685539928984921U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordG;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 3333721400836704048U;
            aOrbiterB = RotL64((aOrbiterB * 3745286323481400085U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 2261560416623815491U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 4377786131746816567U;
            aOrbiterE = RotL64((aOrbiterE * 9164777834392621157U), 47U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterI) + 18047393176583722719U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordC;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 8184724021940434631U;
            aOrbiterD = RotL64((aOrbiterD * 9800116157750921119U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 10469895939183324807U) + aNonceWordF;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 14543391765109879223U;
            aOrbiterK = RotL64((aOrbiterK * 4817987697437667225U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 5757225781746158178U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 3539000495894022869U;
            aOrbiterI = RotL64((aOrbiterI * 1032298408884695925U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 11288971092707065923U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 2761384065186568294U) ^ aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3323838837427471051U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 7120580145300417101U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 6977246291769372866U) ^ aOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15170353875184253779U), 11U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 5U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + (RotL64(aOrbiterF, 46U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 21U) + aOrbiterE) + RotL64(aOrbiterK, 3U)) + aNonceWordN);
            aWandererC = aWandererC + ((((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterK, 11U)) + RotL64(aCarry, 23U)) + aWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterD, 51U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterD, 40U)) + aOrbiterB) + RotL64(aCarry, 57U)) + aWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterF, 21U)) + aOrbiterI) + aNonceWordK);
            aWandererF = aWandererF + (((RotL64(aPrevious, 35U) + aOrbiterF) + RotL64(aOrbiterH, 57U)) + aNonceWordJ);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 46U) + RotL64(aOrbiterH, 27U)) + aOrbiterD) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 48U));
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void TwistExpander_Lacrosse_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xF3D748DE46B09DA1ULL + 0xEA5F28B0080580E7ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xAF8029CB3F1CD8EFULL + 0xAA7F8EDB49587EE4ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xF4160CC4F9C596EDULL + 0xFF1DAC305FC50FD2ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xD92BDC82EAA6406DULL + 0xC0F46FA3FC2C35C3ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xD22FD82101E24BEBULL + 0xFA0C7A4B2B180745ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x9C8DFC55514F46D9ULL + 0xF8F8083EF4FAFB59ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x84A5E39C3FD7CC1DULL + 0xF0B3805AE67C7B58ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xB141568FEB46F509ULL + 0xE6857314B35A42FFULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x9A27AFF220199F61ULL + 0xF3D36CC197F7DC2CULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xCE7ECB4ED689AC13ULL + 0xC83495D1E5F3B77EULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xF399DA51DF32B84FULL + 0xE6C25D377B2AF218ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xDC37373FAE197AB9ULL + 0x9BA6FCADA2D958AAULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xF3572820571C7F69ULL + 0x87DEF06B82446B2BULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xA44CBAC0C5F0758FULL + 0xCE9497533B19F49CULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xD229A3415FAA4721ULL + 0xF74CD48DF27E9A8EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xA282B08414CBF33FULL + 0xFD6199AD06651B03ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 866U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((aIndex + 5934U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 714U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 134U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 7631U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 6738U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aIngress, 42U)) ^ (RotL64(aCarry, 5U) + RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterA = ((aWandererD + RotL64(aCross, 41U)) + 5480870806135400132U) + aNonceWordL;
            aOrbiterI = (aWandererI + RotL64(aScatter, 12U)) + 8034874599430768743U;
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 35U)) + 4006919843736863767U;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 21U)) + 2988069748674633718U;
            aOrbiterE = (aWandererA + RotL64(aCross, 53U)) + 12347295651973135786U;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 19U)) + RotL64(aCarry, 39U)) + 14152683894431568192U;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 47U)) + 15765143815254196598U;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 51U)) + 10473067082331244233U) + aNonceWordD;
            aOrbiterG = (((aWandererK + RotL64(aCross, 39U)) + 1089466925383677249U) + aOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1]) + aNonceWordM;
            aOrbiterC = ((aWandererB + RotL64(aScatter, 22U)) + 13215039929873682230U) + aNonceWordB;
            aOrbiterF = (((aWandererG + RotL64(aPrevious, 27U)) + RotL64(aCarry, 43U)) + 3957997712247961479U) + aOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 10023907397941685546U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 14593012591254614353U;
            aOrbiterJ = RotL64((aOrbiterJ * 17111300092082154687U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 13353797968154036726U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 9259966668512102858U;
            aOrbiterK = RotL64((aOrbiterK * 8326732574268308221U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 10757861831070349321U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 10530223113483866178U;
            aOrbiterD = RotL64((aOrbiterD * 11269177745265396583U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 7554320926405521865U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 6978052067277966996U;
            aOrbiterG = RotL64((aOrbiterG * 18020134738536217801U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 1053695861967171420U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 15980734683539854451U) ^ aNonceWordE;
            aOrbiterH = RotL64((aOrbiterH * 3208466640010555357U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 17041258393808061556U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 12846551858751995530U) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 9303891433380993639U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 14617434286683320666U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 3999309956180741302U;
            aOrbiterI = RotL64((aOrbiterI * 15037707937050015205U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 13452627760403094126U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 2633241575260427158U) ^ aOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2638570213290747581U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 15575035993965639421U) + aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 7829837426112185905U;
            aOrbiterB = RotL64((aOrbiterB * 17059814556114938275U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 12565466096663867876U) + aNonceWordG;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 4845209979900289818U;
            aOrbiterE = RotL64((aOrbiterE * 14990494169374347835U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 13472490162287247012U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 5480870806135400132U;
            aOrbiterC = RotL64((aOrbiterC * 9150331893094034245U), 39U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterC, 51U);
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 23U));
            aIngress = aIngress + RotL64(aOrbiterE, 12U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 37U) + aOrbiterC) + RotL64(aOrbiterF, 57U));
            aWandererD = aWandererD + ((RotL64(aScatter, 50U) + RotL64(aOrbiterA, 43U)) + aOrbiterC);
            aWandererC = aWandererC ^ ((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterF, 39U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterJ, 13U)) + aOrbiterH) + aNonceWordJ);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterB, 30U)) + aOrbiterF);
            aWandererG = aWandererG + ((((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 41U)) + aWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 5U)) + aOrbiterF) + aNonceWordI) + aWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 53U) + aOrbiterI) + RotL64(aOrbiterE, 53U)) + RotL64(aCarry, 19U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 3U) + aOrbiterD) + RotL64(aOrbiterH, 46U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 60U) + aOrbiterJ) + RotL64(aOrbiterK, 19U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 41U) + aOrbiterB) + RotL64(aOrbiterD, 11U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 20U));
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 10U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 12433U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((aIndex + 8238U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 15662U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 14381U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9187U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 13834U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 12647U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCross, 22U)) ^ (RotL64(aCarry, 47U) ^ RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterE = ((aWandererK + RotL64(aIngress, 60U)) + RotL64(aCarry, 21U)) + 5088525177670191619U;
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 13U)) + 9966456257813932112U;
            aOrbiterH = (aWandererA + RotL64(aScatter, 57U)) + 7707646574027146307U;
            aOrbiterD = ((aWandererI + RotL64(aCross, 39U)) + 75480203757681173U) + aOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aScatter, 37U)) + 384659134071835163U) + aOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = ((aWandererD + RotL64(aCross, 43U)) + 3158769775373307778U) + aNonceWordK;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 29U)) + 17360830943513941272U) + aNonceWordM;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 51U)) + 5317278822721604586U;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 27U)) + RotL64(aCarry, 47U)) + 1371427105215954781U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 21U)) + 3162710551223553423U;
            aOrbiterC = ((aWandererF + RotL64(aCross, 48U)) + RotL64(aCarry, 43U)) + 5332921933853550756U;
            //
            aOrbiterE = (((aOrbiterE + aOrbiterK) + 10572462410297815854U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordD;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 10234389605554817892U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2130374833440291193U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 13421365517991380605U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 10186643614984034083U;
            aOrbiterI = RotL64((aOrbiterI * 8554471709467808453U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 4742438973260817120U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 6081590345899008846U;
            aOrbiterA = RotL64((aOrbiterA * 7069396301823124931U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 15360092808493795340U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 12186413069553132646U;
            aOrbiterK = RotL64((aOrbiterK * 3815981440611914267U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 16756221656224451552U) + aNonceWordO;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 12232880965861373143U) ^ aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14196910735715726471U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 10090954323470840557U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 15615770271463853537U;
            aOrbiterF = RotL64((aOrbiterF * 13544181592829027283U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 556029032505658411U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 13311879111583579039U) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 3924744868168749003U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 8646360871497847336U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 2064833941982069154U;
            aOrbiterC = RotL64((aOrbiterC * 10016546852137913163U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 1701847261278886621U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 9654208200019718374U;
            aOrbiterE = RotL64((aOrbiterE * 4398089490129603677U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 14276143262844412074U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 10738184916176200661U) ^ aNonceWordF;
            aOrbiterD = RotL64((aOrbiterD * 8940267914440361883U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 2966052720680305600U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 5088525177670191619U) ^ aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11621585388684456139U), 19U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 39U);
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 28U));
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aPrevious, 10U) + RotL64(aOrbiterI, 21U)) + aOrbiterC) + RotL64(aCarry, 43U)) + aWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 27U) + aOrbiterD) + RotL64(aOrbiterG, 23U));
            aWandererD = aWandererD + (((RotL64(aCross, 21U) + RotL64(aOrbiterA, 19U)) + aOrbiterK) + aNonceWordG);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterB, 11U));
            aWandererE = aWandererE + (((RotL64(aCross, 47U) + RotL64(aOrbiterA, 42U)) + aOrbiterE) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 47U)) + aOrbiterF) + aNonceWordH);
            aWandererI = aWandererI + ((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterB, 3U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterJ, 27U)) + aOrbiterC) + aWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 60U) + aOrbiterF) + RotL64(aOrbiterI, 37U)) + aNonceWordE);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 13U)) + aOrbiterG) + aNonceWordA);
            aWandererC = aWandererC + ((RotL64(aCross, 5U) + RotL64(aOrbiterE, 30U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 12U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + RotL64(aWandererA, 21U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 17538U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 17586U)) & S_BLOCK1], 56U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 24156U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19408U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19528U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 18130U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 23422U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 24U)) + (RotL64(aCross, 3U) + RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterJ = ((aWandererC + RotL64(aCross, 6U)) + 8402620908307642697U) + aOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = ((aWandererA + RotL64(aScatter, 57U)) + 11347672014525086047U) + aOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = (aWandererI + RotL64(aIngress, 29U)) + 2816462912503401876U;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 35U)) + 6940159795470696093U) + aNonceWordM;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 39U)) + RotL64(aCarry, 19U)) + 9134692490095883851U;
            aOrbiterF = (aWandererE + RotL64(aPrevious, 23U)) + 4999455497008026526U;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 51U)) + 5992451460350651332U) + aNonceWordF;
            aOrbiterG = (aWandererB + RotL64(aScatter, 44U)) + 3417087346651371924U;
            aOrbiterI = (((aWandererD + RotL64(aCross, 37U)) + RotL64(aCarry, 35U)) + 3612773820086198270U) + aNonceWordL;
            aOrbiterD = (((aWandererK + RotL64(aScatter, 27U)) + RotL64(aCarry, 57U)) + 463398077083428570U) + aNonceWordP;
            aOrbiterB = (aWandererF + RotL64(aPrevious, 53U)) + 11249391303705089012U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 17027535139825739501U) + aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 568131384979596481U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5683451044852895957U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 4793712537158004047U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 10415170179135963622U;
            aOrbiterA = RotL64((aOrbiterA * 13729564030210361415U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 2391473979460065630U) + aNonceWordH;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 4240058362680064261U;
            aOrbiterC = RotL64((aOrbiterC * 12375884373396400889U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 9963957011090031698U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 3325305624067445525U;
            aOrbiterK = RotL64((aOrbiterK * 3128542681461806309U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 2094945647665114693U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 10703615640774042674U;
            aOrbiterI = RotL64((aOrbiterI * 12641986098450423751U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 3768738815518590289U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 15021301790376706827U;
            aOrbiterH = RotL64((aOrbiterH * 14445850924223550339U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 10571246886181608316U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 5130325144599151793U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3185251943547657467U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 8617523421720966373U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 16574597770835250074U;
            aOrbiterD = RotL64((aOrbiterD * 1759209403428937799U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 17474733286551120355U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 17914672092861237776U;
            aOrbiterJ = RotL64((aOrbiterJ * 13657291990878792267U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 12856557371623447773U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 1636296609747335898U) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 9286345529656087313U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 12588848560509679821U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 8402620908307642697U;
            aOrbiterB = RotL64((aOrbiterB * 2269772223506258147U), 43U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 27U);
            aIngress = aIngress + (RotL64(aOrbiterH, 6U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 51U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 39U));
            aIngress = aIngress + RotL64(aOrbiterA, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 28U) + RotL64(aOrbiterI, 40U)) + aOrbiterB) + aNonceWordD);
            aWandererH = aWandererH + ((RotL64(aIngress, 41U) + RotL64(aOrbiterF, 57U)) + aOrbiterJ);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterF, 11U)) + aOrbiterA) + aWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 23U)) + aOrbiterG) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 13U)) + aOrbiterC);
            aWandererE = aWandererE + (((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 35U)) + aOrbiterA) + aNonceWordE);
            aWandererF = aWandererF ^ ((RotL64(aCross, 53U) + aOrbiterH) + RotL64(aOrbiterJ, 42U));
            aWandererK = aWandererK + (((RotL64(aScatter, 50U) + RotL64(aOrbiterC, 27U)) + aOrbiterK) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 21U) + aOrbiterH) + RotL64(aOrbiterG, 3U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 37U)) + aOrbiterD);
            aWandererI = aWandererI ^ (((RotL64(aCross, 39U) + aOrbiterK) + RotL64(aOrbiterI, 47U)) + aWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 46U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + RotL64(aWandererD, 14U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 32473U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((aIndex + 29917U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 29237U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 29172U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31434U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26729U)) & S_BLOCK1], 36U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 31414U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 56U) + RotL64(aCross, 37U)) + (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 47U)) + 13650869943246163567U) + aNonceWordE;
            aOrbiterI = (aWandererH + RotL64(aScatter, 35U)) + 3435284932011770999U;
            aOrbiterG = (aWandererJ + RotL64(aCross, 57U)) + 12388155658186776579U;
            aOrbiterK = ((((aWandererE + RotL64(aIngress, 26U)) + RotL64(aCarry, 53U)) + 2374345913955712039U) + aOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordG;
            aOrbiterJ = (((aWandererI + RotL64(aCross, 53U)) + 6095094526980292156U) + aOrbiterAssignSaltF[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordL;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 51U)) + RotL64(aCarry, 23U)) + 4965147025852444174U;
            aOrbiterE = (aWandererG + RotL64(aIngress, 43U)) + 3261881216269075298U;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 29U)) + RotL64(aCarry, 35U)) + 4939780217097329222U;
            aOrbiterD = (aWandererC + RotL64(aCross, 3U)) + 3019862009792676287U;
            aOrbiterC = (aWandererF + RotL64(aScatter, 18U)) + 901910626217143974U;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 5U)) + 3647055146712366383U) + aNonceWordB;
            //
            aOrbiterB = (((aOrbiterB + aOrbiterI) + 7731765438957392967U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 13409819457393479741U;
            aOrbiterG = RotL64((aOrbiterG * 3345078200262410715U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 5415832109107794258U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 8876738832313114471U) ^ aNonceWordH;
            aOrbiterJ = RotL64((aOrbiterJ * 1304277600444504135U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 17135570542519390359U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 2373193062766802082U) ^ aOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4213691513185791519U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 16318403285501718552U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 8456043288604687045U;
            aOrbiterF = RotL64((aOrbiterF * 10556964529144571683U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 10572534930284516528U) + aNonceWordD;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 14616251186735204677U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2048651204265459805U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 2837006243817205610U) + aNonceWordP;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 5315917323622194254U;
            aOrbiterD = RotL64((aOrbiterD * 4080522050089666599U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 12084676282761185907U) + aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 7922080344175593788U;
            aOrbiterI = RotL64((aOrbiterI * 7603522302708937379U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 17620847289789547792U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 12140386059533463650U;
            aOrbiterA = RotL64((aOrbiterA * 1443266480620969535U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 4006608081473218762U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 3152507055132739011U;
            aOrbiterB = RotL64((aOrbiterB * 11929522909695002321U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 10845720206369283181U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 16572752872386133133U;
            aOrbiterH = RotL64((aOrbiterH * 2891952650448087211U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 15544908026178481075U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 13650869943246163567U;
            aOrbiterE = RotL64((aOrbiterE * 1275090431127426217U), 57U);
            //
            aIngress = RotL64(aOrbiterC, 47U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterB, 50U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterD, 10U)) + aOrbiterE) + aNonceWordF) + aWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterA, 35U)) + aOrbiterI) + aWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 48U) + aOrbiterI) + RotL64(aOrbiterD, 39U)) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 43U) + aOrbiterH) + RotL64(aOrbiterF, 3U));
            aWandererH = aWandererH + (((RotL64(aIngress, 19U) + RotL64(aOrbiterH, 53U)) + aOrbiterA) + aNonceWordI);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterF, 51U)) + aOrbiterG);
            aWandererD = aWandererD + (((RotL64(aPrevious, 23U) + aOrbiterD) + RotL64(aOrbiterB, 6U)) + aNonceWordN);
            aWandererC = aWandererC ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterE, 21U)) + aOrbiterK) + aNonceWordM);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterC, 37U)) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 6U) + aOrbiterG) + RotL64(aOrbiterJ, 41U));
            aWandererF = aWandererF + ((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterD, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 40U));
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + RotL64(aWandererF, 48U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void TwistExpander_Lacrosse_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xEE260783F35A38FDULL + 0xC683E145F23112EBULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xB6633EC29356C20FULL + 0x9E34176B1AFD12F2ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xEE47E1697EF6034BULL + 0xA359D249002E90C0ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xB0351A62F57377EFULL + 0xD3F2FB7C5939CEF7ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xBF108192C14C6233ULL + 0xDCC8E67DFA24BFEAULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xEDE3C189339E1DE9ULL + 0xD979743F3DD8464BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xCACB13ED66E2248BULL + 0xD0EA14812479E074ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xF246D40E9E3AA157ULL + 0xBB9ADCC71D442A8FULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xFC0B9AD437B93B23ULL + 0x9092EACB49857198ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xA104192F71DC8933ULL + 0xF3F1FEEB29FBC249ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xA230A9AE8AD1E427ULL + 0x98A64F1CBCCB8FCDULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xEF174AC9B8608F8FULL + 0xE8C4CC20756CA3AAULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x8A9C57B07AF633F3ULL + 0x9496BFB1A9559F39ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x85AA95D05A6B8F3DULL + 0xB159A39B1B5902D0ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xF628446DB9BF8BD3ULL + 0xAE306F9FA8E74456ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xA92CD0DBA35124E1ULL + 0xB48232F4A0941513ULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 2957U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((aIndex + 1869U)) & S_BLOCK1], 20U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 1325U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5636U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 5900U)) & S_BLOCK1], 42U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 5910U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCarry, 36U)) ^ (RotL64(aCross, 3U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterK = ((aWandererB + RotL64(aIngress, 23U)) + 6068543441070417854U) + aNonceWordJ;
            aOrbiterD = (aWandererH + RotL64(aCross, 6U)) + 2995980468193441856U;
            aOrbiterG = (aWandererE + RotL64(aScatter, 35U)) + 18020277482171594003U;
            aOrbiterJ = (((aWandererA + RotL64(aPrevious, 19U)) + RotL64(aCarry, 41U)) + 4293807434721230702U) + aOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aScatter, 41U)) + 7980599111583893156U) + aNonceWordO;
            aOrbiterA = ((aWandererG + RotL64(aCross, 13U)) + RotL64(aCarry, 29U)) + 8593141111851052016U;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 27U)) + RotL64(aCarry, 19U)) + 5903487523900084325U;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 47U)) + 15112035513447930209U) + aOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aScatter, 56U)) + 9854037263057006439U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 16759760289688823193U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 12622628933030601390U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2151912984825538321U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 1264668857268123425U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 16302812053619101593U;
            aOrbiterK = RotL64((aOrbiterK * 18291400055836111547U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 16087995784896123610U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 7970269262800468363U;
            aOrbiterF = RotL64((aOrbiterF * 14924752223305807461U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 5331477046030959632U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 16534913204255550893U) ^ aNonceWordH;
            aOrbiterC = RotL64((aOrbiterC * 1013433634373673565U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 11042821902537871209U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 8069677512345031660U;
            aOrbiterA = RotL64((aOrbiterA * 13622218526054132397U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 5737130058129936372U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 1076627182956662997U;
            aOrbiterD = RotL64((aOrbiterD * 14342191224014199929U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 13911061091801078190U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 15397603151098990373U;
            aOrbiterE = RotL64((aOrbiterE * 1802890451633592245U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 15137326716738637972U) + aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterC) ^ 11248737008959896786U) ^ aOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 90789374131547005U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 1847847987633923657U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 10560748778679145431U;
            aOrbiterB = RotL64((aOrbiterB * 2919333327817231099U), 23U);
            //
            aIngress = RotL64(aOrbiterB, 6U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + RotL64(aOrbiterG, 46U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aIngress, 46U) + RotL64(aOrbiterA, 47U)) + aOrbiterG) + RotL64(aCarry, 39U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterA, 5U)) + aOrbiterF) + aNonceWordA);
            aWandererE = aWandererE + ((RotL64(aScatter, 11U) + RotL64(aOrbiterJ, 29U)) + aOrbiterD);
            aWandererG = aWandererG ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterK, 56U)) + aOrbiterJ);
            aWandererH = aWandererH + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 21U)) + aOrbiterB) + aWandererUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 57U) + aOrbiterE) + RotL64(aOrbiterD, 39U));
            aWandererK = aWandererK + ((((RotL64(aCross, 41U) + RotL64(aOrbiterE, 43U)) + aOrbiterA) + RotL64(aCarry, 47U)) + aWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 36U) + aOrbiterJ) + RotL64(aOrbiterB, 14U)) + aNonceWordM);
            aWandererB = aWandererB + ((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterJ, 51U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 44U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + RotL64(aWandererD, 37U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 13280U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneC[((aIndex + 10741U)) & S_BLOCK1], 14U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 13380U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 9533U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 15527U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 15242U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 14592U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 27U) + RotL64(aPrevious, 53U)) ^ (RotL64(aIngress, 39U) + RotL64(aCross, 10U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterF = (aWandererE + RotL64(aCross, 10U)) + 16016931609704150191U;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 43U)) + 14511433515861302636U) + aOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = ((aWandererD + RotL64(aScatter, 35U)) + RotL64(aCarry, 47U)) + 11691237442613269593U;
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 27U)) + 16383220587320484649U) + aNonceWordL;
            aOrbiterA = ((aWandererK + RotL64(aCross, 18U)) + 14293015313458219868U) + aNonceWordB;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 57U)) + 4407695248205526670U) + aOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = (aWandererB + RotL64(aScatter, 5U)) + 1158323195324398372U;
            aOrbiterC = ((aWandererC + RotL64(aIngress, 39U)) + RotL64(aCarry, 57U)) + 6577683409653864555U;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 53U)) + RotL64(aCarry, 5U)) + 171080079472863843U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 5766333425872228205U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 16173508656917582960U;
            aOrbiterI = RotL64((aOrbiterI * 12187968015372936695U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 11781450063402219202U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 13033139686637576694U;
            aOrbiterA = RotL64((aOrbiterA * 4331137994135472025U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 4006310759400926020U) + aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 13156817947481574467U;
            aOrbiterG = RotL64((aOrbiterG * 563189239835001483U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 12791290558893516411U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 989729955679243234U;
            aOrbiterF = RotL64((aOrbiterF * 8757228712495095017U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 838379839663022790U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 2830743864262313606U;
            aOrbiterJ = RotL64((aOrbiterJ * 10173947177104802797U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 2146646527331684652U) + aNonceWordG;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 4629168181742174906U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9046124907945045131U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 1150129989168501777U) + aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 619659995945229440U;
            aOrbiterD = RotL64((aOrbiterD * 13734821008174603409U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 8120315647582116952U) + aNonceWordP;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 13754584116324996165U;
            aOrbiterH = RotL64((aOrbiterH * 12295486140772079747U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 6084566798869999580U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 5731665119233722504U;
            aOrbiterB = RotL64((aOrbiterB * 5921510209025133639U), 37U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterB, 43U);
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 20U));
            aIngress = aIngress + (RotL64(aOrbiterI, 39U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 57U)) + aOrbiterB) + aNonceWordJ);
            aWandererA = aWandererA + ((RotL64(aIngress, 18U) + RotL64(aOrbiterD, 21U)) + aOrbiterG);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterJ, 11U)) + aOrbiterB);
            aWandererH = aWandererH + (((RotL64(aCross, 53U) + RotL64(aOrbiterC, 28U)) + aOrbiterA) + RotL64(aCarry, 35U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterA, 43U)) + aOrbiterG) + aNonceWordK);
            aWandererE = aWandererE + ((RotL64(aCross, 22U) + aOrbiterJ) + RotL64(aOrbiterI, 5U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterH, 39U)) + aOrbiterD) + aWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aIngress, 27U) + aOrbiterA) + RotL64(aOrbiterF, 34U)) + RotL64(aCarry, 43U)) + aNonceWordE);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterF, 53U)) + aWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 14U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 24561U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((aIndex + 19922U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 22584U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((aIndex + 18270U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 19389U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 17312U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23860U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 12U) ^ RotL64(aCarry, 29U)) + (RotL64(aCross, 41U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterB = (aWandererE + RotL64(aPrevious, 47U)) + 12583180859826261500U;
            aOrbiterJ = ((((aWandererJ + RotL64(aScatter, 60U)) + RotL64(aCarry, 29U)) + 9067093488553721468U) + aOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1]) + aNonceWordD;
            aOrbiterD = ((aWandererH + RotL64(aIngress, 39U)) + RotL64(aCarry, 3U)) + 12173106198862881754U;
            aOrbiterG = ((aWandererD + RotL64(aCross, 19U)) + 11333491014394592654U) + aNonceWordA;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 27U)) + 3511883526940919554U) + aOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aPrevious, 56U)) + 7416810692106273044U;
            aOrbiterI = (aWandererI + RotL64(aIngress, 35U)) + 8341174972619784110U;
            aOrbiterE = ((aWandererA + RotL64(aCross, 5U)) + RotL64(aCarry, 39U)) + 2220852854836962979U;
            aOrbiterH = (aWandererB + RotL64(aScatter, 11U)) + 8090781422229383825U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 2338801236599102223U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 12484514711848308104U) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 10364216764253366067U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 13684861340589131816U) + aNonceWordE;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 12796636819991873058U;
            aOrbiterF = RotL64((aOrbiterF * 5533508014234835669U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 7634198650894837690U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 10240326122201201762U) ^ aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8758703497719125901U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 4162814763739453934U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 2766504649149048469U;
            aOrbiterB = RotL64((aOrbiterB * 16731843453895178671U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 11051393030148769655U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 17687055068651386665U) ^ aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1042927176246229537U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 3353615315436983420U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 5971640796220306310U;
            aOrbiterG = RotL64((aOrbiterG * 15804313508835034807U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 12299773092762384765U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 7435804907797063411U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9848139805288165965U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 8735783937125735699U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 11903126115475835615U;
            aOrbiterH = RotL64((aOrbiterH * 16942088822124940265U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 4427166023462475475U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 6011733469446008137U;
            aOrbiterI = RotL64((aOrbiterI * 17298067225913923517U), 23U);
            //
            aIngress = RotL64(aOrbiterF, 47U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterI, 14U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 51U));
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterG, 18U));
            aWandererF = aWandererF + (((RotL64(aScatter, 29U) + aOrbiterC) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 18U) + aOrbiterD) + RotL64(aOrbiterG, 23U)) + aNonceWordI) + aWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterC, 27U)) + RotL64(aCarry, 47U)) + aWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterE, 57U)) + aOrbiterB);
            aWandererK = aWandererK + ((RotL64(aScatter, 41U) + RotL64(aOrbiterJ, 47U)) + aOrbiterF);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 34U) + RotL64(aOrbiterI, 51U)) + aOrbiterG);
            aWandererE = aWandererE + (((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterB, 10U)) + aNonceWordG);
            aWandererB = aWandererB ^ ((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterD, 37U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 30U));
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + RotL64(aWandererK, 51U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 31134U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((aIndex + 32033U)) & S_BLOCK1], 41U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 28706U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneC[((aIndex + 27879U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26264U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 25790U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 24639U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 54U) + RotL64(aCross, 39U)) ^ (RotL64(aIngress, 5U) ^ RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterF = (aWandererD + RotL64(aIngress, 58U)) + 9041099828460168106U;
            aOrbiterB = (aWandererG + RotL64(aScatter, 13U)) + 12883711604096848454U;
            aOrbiterH = (((aWandererE + RotL64(aCross, 47U)) + RotL64(aCarry, 27U)) + 17420968786226443079U) + aNonceWordB;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 19U)) + 3448213891716125104U;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 37U)) + 11866455977445336560U) + aOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 23U)) + 4119356835384495905U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 41U)) + RotL64(aCarry, 13U)) + 2186212599698637068U;
            aOrbiterI = (((aWandererI + RotL64(aCross, 4U)) + 6506144898969301620U) + aOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordD;
            aOrbiterC = ((aWandererB + RotL64(aScatter, 27U)) + RotL64(aCarry, 57U)) + 12556800923644051626U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 4075551535185182945U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 17877694808492008749U;
            aOrbiterH = RotL64((aOrbiterH * 901315308379887473U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 5553428900598223316U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 14362304852277160675U;
            aOrbiterE = RotL64((aOrbiterE * 11415103199856419303U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 9174200302876075831U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 16110739511917638547U;
            aOrbiterG = RotL64((aOrbiterG * 7004356839428657949U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 10189881974519849402U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 2128076632642616677U) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 8860453653433114929U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 18133523799074400083U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 9916472958834153766U;
            aOrbiterC = RotL64((aOrbiterC * 3454601168808001733U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 10274457562795569227U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 14134814273275356425U;
            aOrbiterK = RotL64((aOrbiterK * 15912501063665343159U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 6394306369514735480U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 4825761192736485643U;
            aOrbiterD = RotL64((aOrbiterD * 12534544147331805643U), 3U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterI) + 5672807934779206275U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordP;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 3881953574159390421U;
            aOrbiterB = RotL64((aOrbiterB * 7448770570912161095U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 12012232712634303203U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 14176392925893052596U) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 11288668529893084583U), 51U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterE, 18U);
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterK, 54U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterI, 53U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 23U)) + aOrbiterG);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 56U) + aOrbiterK) + RotL64(aOrbiterH, 60U)) + aNonceWordH);
            aWandererB = aWandererB ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterC, 13U)) + aOrbiterI) + aWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 23U) + RotL64(aOrbiterC, 47U)) + aOrbiterB);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterI, 35U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 5U)) + aOrbiterG) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterE, 29U)) + aOrbiterH) + aNonceWordO);
            aWandererI = aWandererI + ((((RotL64(aScatter, 60U) + aOrbiterK) + RotL64(aOrbiterD, 40U)) + RotL64(aCarry, 23U)) + aWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 60U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererE, 23U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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

void TwistExpander_Lacrosse_Arx::KDF_B_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xBB0DFDC44C11DB9BULL + 0xFBD0E3E07D715B74ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xEFA7364F606CD74DULL + 0xF58CD65485A39372ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xAEB8E92E05BDD04DULL + 0xCF66DC6D982AFE16ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xBABFFCECE4FC47A7ULL + 0xC2231FD379B981F7ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xD2E7D6D22C82EF53ULL + 0x88D261CC7A87C2B7ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xC0F93D5C67D85DBBULL + 0x9E1C22F283CD4330ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xE85F0D4D4255D1EFULL + 0xA6F2FA596612E0D1ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xDF6F6C616441A097ULL + 0x87713FBC86F5C6DDULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xDB3E7D5FBF14CD07ULL + 0xCFC956257DA8B2F3ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xE672CA31A0E64E83ULL + 0xC83D7B44BBD27B36ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xB8E80F65935A0263ULL + 0xFC348E1DF0A03546ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xD4DE658C51EC8DF3ULL + 0xE1BD5003AC0EC88FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xC59D914306243FCFULL + 0xD9246A7F9A3A3A35ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xFF1581C5139C40F7ULL + 0xB96554D2794DCFA9ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x85B71EE0A1714DE1ULL + 0xBF945B4F2A8AF7C9ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xB7B0B2CD7C6F7F29ULL + 0x8706EDBC2763AF39ULL);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 7605U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneB[((aIndex + 6106U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 7996U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7625U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 4156U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 567U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 19U) ^ RotL64(aPrevious, 52U)) ^ (RotL64(aIngress, 5U) + RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterK = (aWandererA + RotL64(aCross, 11U)) + 6733949564325516029U;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 42U)) + RotL64(aCarry, 41U)) + 7304098437143918796U;
            aOrbiterH = (((aWandererK + RotL64(aScatter, 29U)) + RotL64(aCarry, 11U)) + 3923949518391777800U) + aNonceWordM;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 35U)) + 14243591003388927124U) + aNonceWordJ;
            aOrbiterF = (((aWandererB + RotL64(aScatter, 57U)) + 18329498724605410406U) + aOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordL;
            aOrbiterC = (aWandererF + RotL64(aIngress, 23U)) + 13118172167747037249U;
            aOrbiterA = ((((aWandererH + RotL64(aCross, 51U)) + RotL64(aCarry, 29U)) + 5272025143849174212U) + aOrbiterAssignSaltC[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordB;
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 16075917179214318424U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 15263590648674658399U;
            aOrbiterH = RotL64((aOrbiterH * 9918239923411740337U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 13730046728289525921U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 7703141464499623408U;
            aOrbiterF = RotL64((aOrbiterF * 5886009900621521987U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 1382279753822135359U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterC) ^ 2973369221699098292U) ^ aOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 7440242040663550631U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 11578274119583013219U) + aNonceWordD;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 3419411247737896674U;
            aOrbiterA = RotL64((aOrbiterA * 17814942652262802991U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 2582783513078999303U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 3959762790273529677U) ^ aOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 383974377372162751U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 465795011576934604U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 17880826624185821135U;
            aOrbiterE = RotL64((aOrbiterE * 4445949147592860913U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 10819659185349413173U) + aOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 17298208553586835030U) ^ aNonceWordI;
            aOrbiterC = RotL64((aOrbiterC * 1965860510614222093U), 11U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 5U);
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + RotL64(aOrbiterA, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterF, 29U)) + aWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 58U)) + aOrbiterF) + aNonceWordN);
            aWandererF = aWandererF + ((RotL64(aIngress, 53U) + RotL64(aOrbiterE, 41U)) + aOrbiterH);
            aWandererD = aWandererD ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterH, 13U)) + aOrbiterK);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 19U)) + aOrbiterG) + RotL64(aCarry, 11U)) + aNonceWordO);
            aWandererA = aWandererA ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterE, 47U)) + aOrbiterK);
            aWandererK = aWandererK + (((((RotL64(aIngress, 19U) + RotL64(aOrbiterC, 35U)) + aOrbiterG) + RotL64(aCarry, 35U)) + aNonceWordF) + aWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 26U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 35U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 8565U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneC[((aIndex + 12730U)) & S_BLOCK1], 52U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 16114U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 13661U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12568U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 12763U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 10252U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 27U)) + (RotL64(aIngress, 42U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterF = (aWandererD + RotL64(aPrevious, 51U)) + 16451272412693907816U;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 13U)) + RotL64(aCarry, 57U)) + 10099485419723255462U;
            aOrbiterD = (((aWandererJ + RotL64(aCross, 35U)) + RotL64(aCarry, 39U)) + 17668900099534923192U) + aNonceWordK;
            aOrbiterG = (((aWandererG + RotL64(aScatter, 4U)) + 5497093724143181753U) + aOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordC;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 43U)) + 10354044773550071706U;
            aOrbiterK = (((aWandererA + RotL64(aScatter, 21U)) + RotL64(aCarry, 23U)) + 12728258851198019099U) + aNonceWordF;
            aOrbiterE = (((aWandererC + RotL64(aIngress, 27U)) + 4144050505314242618U) + aOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordN;
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 14133805325480076530U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 308863673210602899U;
            aOrbiterD = RotL64((aOrbiterD * 2672613556981540433U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 11741180130160569753U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 12926863156769180448U) ^ aNonceWordA;
            aOrbiterH = RotL64((aOrbiterH * 9726030996091054939U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 211920854786494259U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 13234608842479411078U) ^ aOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2556747209733759467U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 9164711974854618892U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 6667377062281954219U;
            aOrbiterB = RotL64((aOrbiterB * 2603737166987437649U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 4559040002406721850U) + aNonceWordB;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 1749875480850675109U;
            aOrbiterE = RotL64((aOrbiterE * 15822640067349481089U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 9555365165561936366U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 18289733999504213574U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14156217554673229429U), 23U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterK) + 8727162691639622461U) + aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1]) + aNonceWordG;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 291406782452963706U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8413500075082350243U), 5U);
            //
            aIngress = RotL64(aOrbiterB, 21U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 51U));
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterG, 34U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 18U) + RotL64(aOrbiterH, 29U)) + aOrbiterD) + aNonceWordL);
            aWandererG = aWandererG + (((RotL64(aPrevious, 51U) + aOrbiterF) + RotL64(aOrbiterE, 53U)) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterK, 13U)) + aNonceWordI);
            aWandererI = aWandererI + (((RotL64(aCross, 37U) + aOrbiterG) + RotL64(aOrbiterK, 47U)) + aWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 22U)) + aOrbiterG);
            aWandererC = aWandererC + (((((RotL64(aScatter, 29U) + RotL64(aOrbiterE, 37U)) + aOrbiterD) + RotL64(aCarry, 39U)) + aNonceWordE) + aWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 3U)) + aOrbiterH) + aNonceWordH);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 4U));
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 27U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 20075U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((aIndex + 16469U)) & S_BLOCK1], 27U));
            aIngress ^= (RotL64(aWorkLaneB[((aIndex + 17476U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((aIndex + 22637U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23859U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 22261U)) & S_BLOCK1], 50U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 16472U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 23U)) + (RotL64(aPrevious, 37U) ^ RotL64(aCross, 50U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterA = (((aWandererI + RotL64(aScatter, 5U)) + RotL64(aCarry, 11U)) + 13687218104610230596U) + aNonceWordL;
            aOrbiterC = (((aWandererB + RotL64(aPrevious, 35U)) + 6841550124960692709U) + aOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordE;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 57U)) + 17418968668458764131U) + aNonceWordF;
            aOrbiterE = (aWandererD + RotL64(aCross, 41U)) + 8303537912696948204U;
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 47U)) + RotL64(aCarry, 37U)) + 12376614417285936537U;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 13U)) + 14215749063579232654U) + aOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = (((aWandererA + RotL64(aIngress, 24U)) + RotL64(aCarry, 51U)) + 4111736931433665347U) + aNonceWordI;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 11250375934571631522U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 5367367837773331275U;
            aOrbiterF = RotL64((aOrbiterF * 7262723007545807179U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 15514089192382674434U) + aOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 1475991716685034960U) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 17720681295551650891U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 5531622777788629748U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 8363822215908303335U;
            aOrbiterA = RotL64((aOrbiterA * 17850203366840994883U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 3741256932685720414U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterE) ^ 11634667238062155772U) ^ aOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 15925089729784547403U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 18180546911210417155U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 5123234656838556335U) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 15362857462853398025U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 11215734271189250284U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 16863747802158398092U;
            aOrbiterE = RotL64((aOrbiterE * 1828035970246160023U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 9859050606636646323U) + aNonceWordG;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 9331300036643654675U) ^ aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2502263410556166281U), 57U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 43U);
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 14U) + RotL64(aOrbiterA, 29U)) + aOrbiterJ);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterJ, 47U)) + aOrbiterD) + RotL64(aCarry, 19U)) + aWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 5U) + aOrbiterA) + RotL64(aOrbiterC, 60U)) + aNonceWordO) + aWandererUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 5U)) + aOrbiterE);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterE, 11U)) + aOrbiterC);
            aWandererA = aWandererA + (((RotL64(aCross, 41U) + RotL64(aOrbiterE, 19U)) + aOrbiterI) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterF, 39U)) + aOrbiterA) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 10U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 23U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 26944U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneA[((aIndex + 32403U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 31927U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneC[((aIndex + 24583U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31644U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28934U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 31344U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 24U) + RotL64(aCross, 57U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterD = (((aWandererE + RotL64(aPrevious, 11U)) + RotL64(aCarry, 37U)) + 9023059520606551446U) + aNonceWordO;
            aOrbiterI = (((aWandererH + RotL64(aCross, 5U)) + RotL64(aCarry, 23U)) + 662441755115638133U) + aNonceWordB;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 23U)) + 16957253361196144712U) + aNonceWordC;
            aOrbiterK = ((aWandererC + RotL64(aIngress, 37U)) + 7840955025765308605U) + aOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = (((aWandererJ + RotL64(aScatter, 43U)) + RotL64(aCarry, 57U)) + 346855809270395799U) + aNonceWordG;
            aOrbiterE = (aWandererD + RotL64(aIngress, 29U)) + 16099139781586668343U;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 50U)) + 3706457327118322098U) + aOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 12166825885547622870U) + aOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 7792658665720344200U) ^ aOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16305542632794270697U), 13U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterF) + 7128477606152986326U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordH;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 11116533962780290084U) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 11993485572912492297U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 10443889548568288532U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 4402387036946561017U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9032964741841833277U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 13002706161178447654U) + aNonceWordF;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 13929727277530310708U;
            aOrbiterK = RotL64((aOrbiterK * 7005639090871200285U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 10949073760696935106U) + aNonceWordJ;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 15405923432006783533U;
            aOrbiterB = RotL64((aOrbiterB * 17989565878445202495U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 18096057968822208905U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 3032155040484574973U;
            aOrbiterE = RotL64((aOrbiterE * 448597307502544605U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 17462076466907467134U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 15471015427013701406U;
            aOrbiterF = RotL64((aOrbiterF * 6113474000571976139U), 41U);
            //
            aIngress = RotL64(aOrbiterI, 21U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterK, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aCross, 5U) + aOrbiterB) + RotL64(aOrbiterK, 5U)) + aNonceWordM);
            aWandererF = aWandererF + ((RotL64(aScatter, 41U) + aOrbiterK) + RotL64(aOrbiterF, 13U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterE, 29U)) + aWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererD = aWandererD + (((((RotL64(aPrevious, 22U) + RotL64(aOrbiterH, 20U)) + aOrbiterE) + RotL64(aCarry, 23U)) + aNonceWordA) + aWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 47U)) + aOrbiterH);
            aWandererC = aWandererC + (((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 41U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererD, 58U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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

void TwistExpander_Lacrosse_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltD;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x9B8A59F5A6CE0417ULL + 0xA217273F3BD71E82ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xF19E324E1E982D13ULL + 0xDD7605F877176EE0ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xE0363D0C328840C5ULL + 0x8AAA57C7187C0390ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xBE24A0425A0DDF6BULL + 0xCB167A626D5096ABULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xA8360B633ED896B1ULL + 0xF01BAB206F213B54ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xF8C3EF741282E98BULL + 0xC45AD7C3506F2B0BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xB4AFECDDF52A6063ULL + 0xBF6CB16DAB80EF8AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x96C669465ACC162BULL + 0xD16C49E8F50D1B4CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x94AF445DF6C7CB7FULL + 0xFB2F6E723B7C1BF6ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xE2A58D2C0B04FAFDULL + 0x802BA09C08BEF4BDULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xF03265B1C2AE5EBDULL + 0x8098BE724395A3F5ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x85200EED0D82F005ULL + 0xE40E40E9CEC76374ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x9BF9ECFF7ECF6717ULL + 0xB8DF0A7EE84DAD56ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x8AE2ECD340120073ULL + 0xF085E4E0362145F2ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xB70B8B7D231DB497ULL + 0x85F33D82939534F3ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xBA14FE53F3CC67EDULL + 0xD5695788336E9510ULL);
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 836U)) & W_KEY1], 21U) ^ RotL64(aKeyRowReadB[((aIndex + 1188U)) & W_KEY1], 12U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 2059U)) & W_KEY1], 47U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 1985U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 50U) + RotL64(aIngress, 5U)) ^ (RotL64(aCross, 23U) + RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 36U)) + 4384716820085860551U) + aPhaseEOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 41U)) + 9715780315942116888U) + aNonceWordB;
            aOrbiterF = ((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 5U)) + 15963520052789178632U;
            aOrbiterI = (((aWandererC + RotL64(aCross, 13U)) + 14346700690686392938U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordC;
            aOrbiterD = (aWandererB + RotL64(aScatter, 53U)) + 6005518012489966643U;
            aOrbiterH = (aWandererE + RotL64(aIngress, 43U)) + 2506732930310252119U;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 23U)) + RotL64(aCarry, 53U)) + 16782163084851775826U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 823673076571076303U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 1634084509064077736U;
            aOrbiterF = RotL64((aOrbiterF * 1128407326773234517U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 1288134975466877686U) + aNonceWordD;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 2998220403162908444U;
            aOrbiterG = RotL64((aOrbiterG * 4321412662318298283U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 220430672180734911U) + aNonceWordI;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 10223923547068528867U;
            aOrbiterH = RotL64((aOrbiterH * 12577370238343872139U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 11696469696177647608U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 6545430420379636963U;
            aOrbiterA = RotL64((aOrbiterA * 8387163146257553773U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 79691451831797107U) + aNonceWordM;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 8971444023498649419U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7148919880477390009U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 5624403902454498793U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 9468064161002030997U;
            aOrbiterD = RotL64((aOrbiterD * 8243560528100864595U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 4619361544913629805U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = (((aOrbiterI ^ aOrbiterF) ^ 12682446273369750704U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterI = RotL64((aOrbiterI * 10879074713156075641U), 47U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 29U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + RotL64(aOrbiterG, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterD, 51U)) + aOrbiterH) + aNonceWordJ);
            aWandererE = aWandererE ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterH, 21U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 38U) + RotL64(aOrbiterD, 39U)) + aOrbiterE) + RotL64(aCarry, 47U)) + aNonceWordE);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterD, 58U));
            aWandererG = aWandererG + ((RotL64(aScatter, 5U) + RotL64(aOrbiterA, 27U)) + aOrbiterG);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterF, 11U)) + aOrbiterE) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aIngress, 53U) + aOrbiterG) + RotL64(aOrbiterH, 5U)) + RotL64(aCarry, 5U)) + aPhaseEWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 60U));
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 3504U)) & S_BLOCK1], 21U) ^ RotL64(aKeyRowReadA[((aIndex + 3953U)) & W_KEY1], 11U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 3864U)) & W_KEY1], 43U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 3688U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCarry, 23U)) ^ (RotL64(aIngress, 54U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterJ = ((aWandererD + RotL64(aCross, 11U)) + 2168513956284366370U) + aNonceWordC;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 47U)) + RotL64(aCarry, 51U)) + 10290361969974613111U;
            aOrbiterD = (((aWandererA + RotL64(aScatter, 53U)) + RotL64(aCarry, 5U)) + 15673836275828498050U) + aNonceWordH;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 41U)) + RotL64(aCarry, 23U)) + 16600540024145812236U;
            aOrbiterH = ((aWandererC + RotL64(aCross, 27U)) + 9428052101528111892U) + aPhaseEOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aPrevious, 35U)) + 12763657928312763377U;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 18U)) + 10751286982008662485U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 1708230173038057979U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 4011389705422783816U) ^ aNonceWordJ;
            aOrbiterD = RotL64((aOrbiterD * 11692237130784795961U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 11704428328093077714U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 2055336619674699284U;
            aOrbiterH = RotL64((aOrbiterH * 6374289210096410907U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 1870865272102705804U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 3574214263751923179U;
            aOrbiterG = RotL64((aOrbiterG * 13132083406834413563U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 984611970726966186U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 15207945449947643672U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9539470161576639981U), 23U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterH) + 4181398506373973169U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 15222345431506025949U;
            aOrbiterJ = RotL64((aOrbiterJ * 6925143692628659467U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 15023513452326240962U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 14965669361708810699U;
            aOrbiterE = RotL64((aOrbiterE * 587008860996713147U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 7985755518735406360U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 225592097619240187U;
            aOrbiterA = RotL64((aOrbiterA * 2313509354133400439U), 51U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterE, 3U);
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterE, 56U));
            aWandererC = aWandererC + (((RotL64(aIngress, 29U) + RotL64(aOrbiterI, 5U)) + aOrbiterA) + aNonceWordF);
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterI, 21U)) + aNonceWordN) + aPhaseEWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 41U) + aOrbiterA) + RotL64(aOrbiterD, 41U)) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterE, 29U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterD, 47U)) + aOrbiterJ) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 20U) + RotL64(aOrbiterH, 35U)) + aOrbiterA) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 10U));
            aCarry = aCarry + RotL64(aWandererC, 43U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aFireLaneB[((aIndex + 7743U)) & S_BLOCK1], 29U) ^ RotL64(aKeyRowReadB[((aIndex + 6235U)) & W_KEY1], 18U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7048U)) & W_KEY1], 4U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 5678U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 6656U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 22U)) ^ (RotL64(aCross, 43U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterB = (((aWandererC + RotL64(aIngress, 11U)) + 12809562813316740345U) + aPhaseEOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1]) + aNonceWordO;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 60U)) + RotL64(aCarry, 35U)) + 17084212535326321199U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 35U)) + RotL64(aCarry, 57U)) + 16074921689983846769U;
            aOrbiterH = (((aWandererD + RotL64(aCross, 41U)) + RotL64(aCarry, 13U)) + 14027986153007120145U) + aNonceWordN;
            aOrbiterK = (((aWandererB + RotL64(aIngress, 47U)) + 7633455951809250227U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordH;
            aOrbiterF = (aWandererE + RotL64(aScatter, 27U)) + 340989348513370174U;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 21U)) + 5307820377645020116U) + aNonceWordK;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 5605285015771527274U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 5293500434746182790U;
            aOrbiterI = RotL64((aOrbiterI * 17674669610895537063U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 7263156475892261811U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 10672879570907433005U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2506338667179450741U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 16659226780900986107U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 9774892622769850665U;
            aOrbiterC = RotL64((aOrbiterC * 7487477727543183211U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 10728057184108279042U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 5032485856947407217U;
            aOrbiterH = RotL64((aOrbiterH * 16651577903809154285U), 5U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterF) + 14642241075374862345U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordA;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 8386481273395203518U;
            aOrbiterB = RotL64((aOrbiterB * 11649977733867003445U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 2874153265304098104U) + aNonceWordF;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 11519900149177261000U) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 2010158758971864505U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 8885690878540115768U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 4482143389870987714U) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 7105332459437434281U), 41U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 5U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 30U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + RotL64(aOrbiterG, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterK, 38U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 47U)) + aOrbiterI) + aNonceWordL) + aPhaseEWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 42U) + RotL64(aOrbiterF, 13U)) + aOrbiterC) + aNonceWordD);
            aWandererI = aWandererI + (((RotL64(aCross, 57U) + RotL64(aOrbiterF, 27U)) + aOrbiterG) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterB, 21U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 23U) + aOrbiterB) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 29U)) + aNonceWordM);
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 57U)) + aOrbiterI) + aNonceWordE) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 56U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + RotL64(aWandererB, 5U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 8208U)) & S_BLOCK1], 46U) ^ RotL64(aKeyRowReadB[((aIndex + 10528U)) & W_KEY1], 57U));
            aIngress ^= (RotL64(mSource[((aIndex + 9682U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 9380U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 9668U)) & W_KEY1], 57U) ^ RotL64(aFireLaneB[((aIndex + 9118U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 37U) + RotL64(aCross, 22U)) ^ (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterC = (aWandererE + RotL64(aPrevious, 21U)) + 1297415699043177788U;
            aOrbiterG = (aWandererK + RotL64(aCross, 36U)) + 17583786534509260153U;
            aOrbiterF = (((aWandererJ + RotL64(aScatter, 11U)) + 643197858925708798U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordD;
            aOrbiterH = (((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 27U)) + 5062653766915694874U) + aNonceWordG;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 57U)) + RotL64(aCarry, 51U)) + 7034273638367180511U;
            aOrbiterB = ((aWandererB + RotL64(aCross, 43U)) + 2026909726972916996U) + aNonceWordK;
            aOrbiterD = (((aWandererI + RotL64(aPrevious, 3U)) + RotL64(aCarry, 5U)) + 2785690475553211646U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 2910341716302991892U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 2834181605200829791U) ^ aNonceWordF;
            aOrbiterF = RotL64((aOrbiterF * 1510617068750957651U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 13323052600571281928U) + aNonceWordI;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 10434901530315760460U;
            aOrbiterG = RotL64((aOrbiterG * 2042210188346767033U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 247903955625194782U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 5196515747387257163U;
            aOrbiterD = RotL64((aOrbiterD * 1799024689023272275U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 7196305682377987476U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 14777739876892587484U;
            aOrbiterC = RotL64((aOrbiterC * 95220583948241581U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 10609060796540136671U) + aNonceWordM;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 8386027207212484155U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4855610536246556893U), 11U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterJ) + 729659744301903424U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordE;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 2350564261412606157U;
            aOrbiterB = RotL64((aOrbiterB * 16713856782349084977U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 16611987556673864177U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 1525195188708550503U;
            aOrbiterH = RotL64((aOrbiterH * 10045858602151004553U), 23U);
            //
            aIngress = RotL64(aOrbiterB, 35U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + RotL64(aOrbiterJ, 50U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 34U) + aOrbiterB) + RotL64(aOrbiterF, 5U)) + aNonceWordH);
            aWandererK = aWandererK + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterH, 60U)) + aOrbiterB) + RotL64(aCarry, 57U)) + aNonceWordA);
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterC, 37U)) + aNonceWordC) + aPhaseFWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 5U) + RotL64(aOrbiterH, 23U)) + aOrbiterD) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 11U)) + aOrbiterF) + aNonceWordJ);
            aWandererG = aWandererG + (((RotL64(aIngress, 41U) + aOrbiterG) + RotL64(aOrbiterJ, 53U)) + aPhaseFWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 27U) + aOrbiterG) + RotL64(aOrbiterH, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 54U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 12099U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadA[((aIndex + 13491U)) & W_KEY1], 39U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 12003U)) & W_KEY1], 12U) ^ RotL64(mSource[((aIndex + 12200U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 11007U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 12589U)) & S_BLOCK1], 41U) ^ RotL64(aFireLaneC[((aIndex + 13379U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCross, 42U)) + (RotL64(aCarry, 11U) ^ RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterD = ((aWandererA + RotL64(aScatter, 47U)) + 7960325128608297381U) + aNonceWordD;
            aOrbiterC = (aWandererG + RotL64(aCross, 41U)) + 12773836012104052042U;
            aOrbiterG = (((aWandererH + RotL64(aIngress, 53U)) + RotL64(aCarry, 21U)) + 3173972621347773016U) + aNonceWordP;
            aOrbiterH = (((aWandererJ + RotL64(aPrevious, 13U)) + RotL64(aCarry, 3U)) + 3708401356314308171U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aCross, 35U)) + 950774285720019449U) + aNonceWordL;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 21U)) + RotL64(aCarry, 37U)) + 4170092315705438265U;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 28U)) + 17000449130864980747U) + aPhaseFOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 8793910540062893860U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 520277969543516469U;
            aOrbiterG = RotL64((aOrbiterG * 4150613128885828229U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 12762214857389827271U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 2932451184340207695U) ^ aNonceWordJ;
            aOrbiterD = RotL64((aOrbiterD * 7513337346940091655U), 29U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterD) + 11062179998786293839U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1]) + aNonceWordB;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 7919119215271524178U;
            aOrbiterJ = RotL64((aOrbiterJ * 9053677007180081359U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 1774988449597115155U) + aNonceWordM;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 3799792889466518953U;
            aOrbiterH = RotL64((aOrbiterH * 17512791286490623455U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 1815062051307896589U) + aNonceWordH;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 15260373951371654483U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2208604434669491625U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 12867546628945676853U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 7772820973895846946U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7581704643538761985U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 14213957831821966834U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 16561105721170419454U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2540533987337175367U), 5U);
            //
            aIngress = RotL64(aOrbiterA, 3U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterG, 13U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 23U) + aOrbiterG) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 5U)) + aNonceWordO);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterJ, 5U)) + aOrbiterI) + aNonceWordE);
            aWandererC = aWandererC + ((RotL64(aPrevious, 60U) + RotL64(aOrbiterI, 23U)) + aOrbiterD);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 29U)) + aOrbiterG) + aPhaseFWandererUpdateSaltF[((aIndex + 10U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 41U) + aOrbiterC) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 43U)) + aPhaseFWandererUpdateSaltB[((aIndex + 16U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 46U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (RotL64(aWandererC, 30U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 15132U)) & S_BLOCK1], 34U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 15374U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 14496U)) & W_KEY1], 56U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 14900U)) & W_KEY1], 39U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 14543U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 15278U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 14994U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 37U) ^ RotL64(aCross, 23U)) ^ (RotL64(aPrevious, 52U) + RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterC = (((aWandererJ + RotL64(aCross, 30U)) + RotL64(aCarry, 11U)) + 9888431329297626900U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aIngress, 57U)) + 2937735167534624403U;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 3U)) + 17626022970343789617U;
            aOrbiterD = ((((aWandererH + RotL64(aScatter, 11U)) + RotL64(aCarry, 51U)) + 5665660859333693743U) + aPhaseFOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1]) + aNonceWordM;
            aOrbiterG = (aWandererG + RotL64(aIngress, 23U)) + 1060537034632076669U;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 41U)) + 743777763907175800U) + aNonceWordA;
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 51U)) + RotL64(aCarry, 29U)) + 5744905970181808845U;
            //
            aOrbiterC = (((aOrbiterC + aOrbiterE) + 3545351394494002180U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1]) + aNonceWordL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 4877547088414106007U;
            aOrbiterJ = RotL64((aOrbiterJ * 5416792889338547109U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 11669378338379598445U) + aNonceWordD;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 2961072441706158212U;
            aOrbiterC = RotL64((aOrbiterC * 2677988507090705371U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 13984945589234919765U) + aNonceWordJ;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 1433097875470903205U) ^ aNonceWordF;
            aOrbiterA = RotL64((aOrbiterA * 451996840039906781U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 716415411025451152U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 8542286150858297810U;
            aOrbiterD = RotL64((aOrbiterD * 9139015340823332449U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 12932391786479661299U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 14005503313299177013U;
            aOrbiterG = RotL64((aOrbiterG * 802663466907819743U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 9382792812676318046U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 5138554251079724724U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6386016499265056247U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 8522380066269546172U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 11825536408101906458U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17042837108792016849U), 5U);
            //
            aIngress = RotL64(aOrbiterA, 3U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 26U) + aOrbiterA) + RotL64(aOrbiterJ, 41U)) + aNonceWordO);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterC, 10U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterB, 3U)) + aOrbiterG) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 43U) + aOrbiterB) + RotL64(aOrbiterA, 53U));
            aWandererA = aWandererA + (((((RotL64(aCross, 37U) + RotL64(aOrbiterG, 35U)) + aOrbiterE) + RotL64(aCarry, 19U)) + aNonceWordN) + aPhaseFWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterC, 29U)) + aOrbiterD) + aNonceWordI);
            aWandererK = aWandererK + (((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterJ, 19U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 12U));
            aCarry = aCarry + RotL64(aWandererG, 21U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 18431U)) & S_BLOCK1], 13U) ^ RotL64(aKeyRowReadA[((aIndex + 18090U)) & W_KEY1], 3U));
            aIngress ^= (RotL64(mSource[((aIndex + 18292U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 19015U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 16956U)) & W_KEY1], 29U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 18504U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16818U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCarry, 5U)) ^ (RotL64(aCross, 19U) ^ RotL64(aIngress, 44U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterG = ((aWandererH + RotL64(aIngress, 29U)) + 2786079456995203065U) + aNonceWordJ;
            aOrbiterI = (((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 19U)) + 7237256119153857253U) + aNonceWordG;
            aOrbiterF = ((((aWandererB + RotL64(aScatter, 41U)) + RotL64(aCarry, 35U)) + 9310834010563647604U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordF;
            aOrbiterE = (aWandererD + RotL64(aCross, 57U)) + 17361734905706517877U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 35U)) + 15837111231884647451U) + aNonceWordA;
            aOrbiterH = (aWandererG + RotL64(aIngress, 6U)) + 18065431964418026445U;
            aOrbiterK = (((aWandererI + RotL64(aCross, 51U)) + RotL64(aCarry, 47U)) + 3029123922999952652U) + aPhaseGOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 5166926595573507837U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 1918425684273807598U;
            aOrbiterF = RotL64((aOrbiterF * 16616641579714896719U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 4724551751012661440U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 1818014487579644390U;
            aOrbiterC = RotL64((aOrbiterC * 14904092108647864911U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 6670090372241084216U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 8485757110007268693U) ^ aNonceWordN;
            aOrbiterG = RotL64((aOrbiterG * 11876760095108618363U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 4928130251509514742U) + aNonceWordE;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 2528788422725346792U;
            aOrbiterE = RotL64((aOrbiterE * 1855982047967756661U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 2860387120895147503U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 12927802338151379368U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8876144125458603029U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 18029699867733207083U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 13361836994951253312U;
            aOrbiterK = RotL64((aOrbiterK * 5349767426256597073U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 11957294454794128079U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 3755417922063414648U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13896364063651241401U), 13U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 3U);
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + RotL64(aOrbiterI, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aScatter, 41U) + aOrbiterE) + RotL64(aOrbiterK, 43U)) + RotL64(aCarry, 19U)) + aNonceWordB);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 11U) + aOrbiterI) + RotL64(aOrbiterE, 53U));
            aWandererI = aWandererI + (((RotL64(aIngress, 20U) + aOrbiterI) + RotL64(aOrbiterH, 35U)) + aNonceWordM);
            aWandererH = aWandererH ^ (((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterF, 60U)) + aNonceWordP);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterF, 29U)) + aOrbiterH) + RotL64(aCarry, 41U)) + aPhaseGWandererUpdateSaltE[((aIndex + 8U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterK, 13U));
            aWandererB = aWandererB + (((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 3U)) + aOrbiterI) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 20U));
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 19510U)) & S_BLOCK1], 56U) ^ RotL64(mSource[((aIndex + 21805U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aWorkLaneA[((aIndex + 21496U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 21691U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20875U)) & W_KEY1], 11U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 20703U)) & W_KEY1], 21U));
            aCross ^= (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19493U)) & S_BLOCK1], 30U) ^ RotL64(aFireLaneB[((aIndex + 20685U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aPrevious, 35U)) ^ (RotL64(aIngress, 54U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 21U)) + 5171470532667965920U) + aNonceWordG;
            aOrbiterJ = (((aWandererB + RotL64(aIngress, 14U)) + RotL64(aCarry, 21U)) + 750549462358682403U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = (((aWandererA + RotL64(aScatter, 35U)) + 3325689257577120525U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordA;
            aOrbiterI = ((aWandererF + RotL64(aCross, 57U)) + RotL64(aCarry, 51U)) + 18031575461559790826U;
            aOrbiterK = ((aWandererK + RotL64(aScatter, 5U)) + RotL64(aCarry, 37U)) + 13874739537012288677U;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 27U)) + 4250029868785016865U;
            aOrbiterF = ((aWandererI + RotL64(aCross, 41U)) + 8211158803112611161U) + aNonceWordH;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 1083939790236786027U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 3446525462376962464U;
            aOrbiterE = RotL64((aOrbiterE * 13603702473750888213U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 6973817815000417325U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 15230876489676945543U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7737039082964537651U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 9359727659738755880U) + aNonceWordN;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 8775170107816327654U;
            aOrbiterC = RotL64((aOrbiterC * 6910680458261008653U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 11958941755525038545U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterF) ^ 16966819714283167348U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterG = RotL64((aOrbiterG * 16363457661846050749U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 14556087985619763243U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 17915047508377045221U;
            aOrbiterF = RotL64((aOrbiterF * 6727635453185130109U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 8578745677485367222U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 7002181668717618866U;
            aOrbiterJ = RotL64((aOrbiterJ * 12329703532414955235U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 3569939503066735457U) + aNonceWordC;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 2956247934282522184U;
            aOrbiterI = RotL64((aOrbiterI * 9946650822131152531U), 5U);
            //
            aIngress = RotL64(aOrbiterG, 57U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + RotL64(aOrbiterJ, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 41U)) + aOrbiterF) + aNonceWordD);
            aWandererI = aWandererI + ((RotL64(aIngress, 13U) + aOrbiterG) + RotL64(aOrbiterJ, 51U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterK, 11U));
            aWandererC = aWandererC + (((((RotL64(aCross, 20U) + aOrbiterK) + RotL64(aOrbiterI, 57U)) + RotL64(aCarry, 5U)) + aNonceWordK) + aPhaseGWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterE, 19U)) + aOrbiterF) + aPhaseGWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 37U) + RotL64(aOrbiterC, 3U)) + aOrbiterF) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 30U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 60U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 41U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + RotL64(aWandererA, 27U);
            aCarry = aCarry + RotL64(aIngress, 36U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 22795U)) & S_BLOCK1], 24U) ^ RotL64(aKeyRowReadA[((aIndex + 23045U)) & W_KEY1], 3U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 24450U)) & W_KEY1], 57U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 22427U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 22717U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23043U)) & S_BLOCK1], 35U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 22155U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 23248U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 13U) ^ RotL64(aPrevious, 26U)) ^ (RotL64(aCarry, 41U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterK = ((aWandererA + RotL64(aCross, 11U)) + RotL64(aCarry, 5U)) + 18180797995100240808U;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 57U)) + 6585906608223552885U) + aNonceWordF;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 19U)) + 14088708930575939855U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aIngress, 27U)) + 468974153311516044U;
            aOrbiterE = (((aWandererH + RotL64(aScatter, 3U)) + RotL64(aCarry, 39U)) + 12481951025619894110U) + aPhaseGOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 44U)) + 17227987923860711763U) + aNonceWordM;
            aOrbiterA = (((aWandererJ + RotL64(aIngress, 37U)) + RotL64(aCarry, 57U)) + 4373962756657477139U) + aNonceWordH;
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 2077576476565420951U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 17435011300234663764U;
            aOrbiterG = RotL64((aOrbiterG * 8910133867294004711U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 4118039398293246896U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 13724716599855216683U;
            aOrbiterB = RotL64((aOrbiterB * 17556333902751079677U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 12391461204689596339U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 9900605191533799627U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13553565332531046301U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 972946858824366125U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 17247681919694541215U) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 2974639094630445643U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 15442851427306771601U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 7303586227288294037U) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 15406402525021428799U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 12650358753454105119U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 1483710933373510492U;
            aOrbiterA = RotL64((aOrbiterA * 6531763256577221891U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 18065810162229740788U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 11311677121338794007U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15116367961682119467U), 35U);
            //
            aIngress = RotL64(aOrbiterG, 20U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + RotL64(aOrbiterI, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 43U) + RotL64(aOrbiterA, 5U)) + aOrbiterE) + aNonceWordO);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 20U) + RotL64(aOrbiterB, 13U)) + aOrbiterE) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 57U)) + aOrbiterB) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterB, 51U)) + aNonceWordC);
            aWandererA = aWandererA + (((RotL64(aCross, 27U) + aOrbiterG) + RotL64(aOrbiterE, 21U)) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterI, 36U)) + aNonceWordP) + aPhaseGWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterK, 43U)) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 10U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + RotL64(aWandererI, 29U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 25442U)) & S_BLOCK1], 5U) ^ RotL64(aKeyRowReadA[((aIndex + 25503U)) & W_KEY1], 29U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 26384U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneB[((aIndex + 26625U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 25245U)) & W_KEY1], 14U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26208U)) & S_BLOCK1], 23U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 27239U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneD[((aIndex + 24713U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 27U) + RotL64(aCross, 57U)) + (RotL64(aPrevious, 11U) ^ RotL64(aCarry, 44U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterH = (aWandererA + RotL64(aPrevious, 14U)) + 1898718075389870739U;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 35U)) + RotL64(aCarry, 53U)) + 5631794889237247403U;
            aOrbiterK = ((aWandererC + RotL64(aCross, 47U)) + RotL64(aCarry, 3U)) + 18219714659484524607U;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 41U)) + 15419581386225732921U) + aNonceWordI;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 53U)) + 9125575431710198210U) + aPhaseHOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = (((aWandererD + RotL64(aScatter, 23U)) + RotL64(aCarry, 21U)) + 12205871520544965505U) + aPhaseHOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 3U)) + 7617534300497343422U) + aNonceWordA;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 18017579105368135814U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 10693882161946020042U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2326507900303932855U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 11669615701700895306U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 11045110212889232165U;
            aOrbiterF = RotL64((aOrbiterF * 5965171269273719849U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 18019107802806469913U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 12315940560472528716U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4505122470351404065U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 4899009736070044310U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 17412253404253730364U;
            aOrbiterA = RotL64((aOrbiterA * 10791901166391946485U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 4826286251927854181U) + aNonceWordL;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 4523455921321845084U;
            aOrbiterC = RotL64((aOrbiterC * 14534103906736598099U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 4132514462154182215U) + aNonceWordE;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 7164745605985109269U) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 14107325508977225261U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 6297434295807635654U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 8813887638672996646U;
            aOrbiterH = RotL64((aOrbiterH * 17495632530773158201U), 21U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 18U);
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 3U)) + aOrbiterH) + aNonceWordM);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 41U)) + aOrbiterF) + aNonceWordF);
            aWandererC = aWandererC + (((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 57U)) + aOrbiterH) + aNonceWordK);
            aWandererB = aWandererB ^ ((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterH, 13U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterE, 47U)) + aOrbiterA) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterF, 27U)) + aNonceWordC) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 20U) + RotL64(aOrbiterB, 34U)) + aOrbiterH) + RotL64(aCarry, 39U)) + aPhaseHWandererUpdateSaltD[((aIndex + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 6U));
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 28335U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneD[((aIndex + 28851U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 29280U)) & W_KEY1], 5U) ^ RotL64(aWorkLaneC[((aIndex + 28838U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 28900U)) & W_KEY1], 11U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 27610U)) & S_BLOCK1], 3U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30035U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28276U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aIngress, 51U)) + (RotL64(aPrevious, 6U) ^ RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterE = (((aWandererE + RotL64(aScatter, 29U)) + 11480359716598965890U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterD = (((aWandererB + RotL64(aCross, 23U)) + 15431182525482873419U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordH;
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 47U)) + RotL64(aCarry, 13U)) + 11360504974812776707U;
            aOrbiterH = (aWandererH + RotL64(aIngress, 39U)) + 9292576416573382769U;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 6U)) + RotL64(aCarry, 53U)) + 1549257414531028975U;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 53U)) + RotL64(aCarry, 41U)) + 5347769463033129317U;
            aOrbiterB = (aWandererF + RotL64(aPrevious, 13U)) + 17019199177478377234U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 16558106007323125094U) + aNonceWordD;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 3976182233825939422U;
            aOrbiterI = RotL64((aOrbiterI * 4392162052317572289U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 2889047161195954395U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 2241831345026962605U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5757458560979927857U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 12850802412140579294U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 13541744735436450160U) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 906089290000537439U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 2085863085516538212U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 2969034221711544086U;
            aOrbiterE = RotL64((aOrbiterE * 7768528124408400403U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 6482666944512391472U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 16969153556875844613U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9483462388353216219U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 5161314086757363678U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 7150282484670673211U;
            aOrbiterD = RotL64((aOrbiterD * 8522427002337918663U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 5465304381272305847U) + aNonceWordA;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 2344610773390354017U) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 17010258514288089191U), 21U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 10U);
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 60U) + aOrbiterE) + RotL64(aOrbiterI, 23U));
            aWandererF = aWandererF + (((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterD, 51U)) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterB, 35U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 11U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterA, 41U));
            aWandererD = aWandererD + ((((RotL64(aCross, 53U) + RotL64(aOrbiterH, 58U)) + aOrbiterD) + aNonceWordE) + aPhaseHWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterD, 3U)) + aOrbiterJ) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 28U));
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + RotL64(aWandererI, 39U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 31424U)) & S_BLOCK1], 12U) ^ RotL64(aKeyRowReadA[((aIndex + 30594U)) & W_KEY1], 39U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 30834U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31816U)) & S_BLOCK1], 5U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31940U)) & S_BLOCK1], 37U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 31275U)) & W_KEY1], 29U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 4U) ^ RotL64(aPrevious, 39U)) ^ (RotL64(aCarry, 53U) + RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterE = (((aWandererG + RotL64(aPrevious, 27U)) + 9654059367478508868U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordO;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 53U)) + RotL64(aCarry, 41U)) + 6473006635864677427U;
            aOrbiterC = ((((aWandererK + RotL64(aScatter, 21U)) + RotL64(aCarry, 3U)) + 6944184481315853243U) + aPhaseHOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1]) + aNonceWordG;
            aOrbiterD = ((aWandererC + RotL64(aCross, 13U)) + 4061496421939102306U) + aNonceWordK;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 43U)) + 15791809275719085463U) + aNonceWordC;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 3U)) + RotL64(aCarry, 27U)) + 14050798802646323055U;
            aOrbiterF = (aWandererF + RotL64(aIngress, 34U)) + 12072905924741758266U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 17639076509231343896U) + aNonceWordJ;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 12195388285571234715U;
            aOrbiterC = RotL64((aOrbiterC * 4317060502521195769U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 4325404419499496529U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 5910567888204238382U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11503787177122206937U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 13092940059929942699U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 13381962590820308761U;
            aOrbiterH = RotL64((aOrbiterH * 6345904465930943295U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 15622862439323440527U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 14027151901132249793U) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 2273573821630510087U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 4584410023907605157U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 15763755180625487157U;
            aOrbiterE = RotL64((aOrbiterE * 6755736130607297639U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 17023059745666559199U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 5298529579288492971U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2483562793328357721U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 2870152867331654736U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 12017191100173748848U;
            aOrbiterK = RotL64((aOrbiterK * 9958191466506480519U), 29U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 11U);
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 4U));
            aIngress = aIngress + RotL64(aOrbiterC, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aIngress, 27U) + aOrbiterC) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 41U)) + aNonceWordN);
            aWandererC = aWandererC ^ (((RotL64(aCross, 34U) + RotL64(aOrbiterH, 51U)) + aOrbiterK) + aNonceWordH);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterC, 57U)) + RotL64(aCarry, 57U)) + aNonceWordL);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterD, 20U)) + aOrbiterK);
            aWandererG = aWandererG + (((RotL64(aIngress, 51U) + RotL64(aOrbiterD, 43U)) + aOrbiterE) + aPhaseHWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 11U)) + aOrbiterF) + aPhaseHWandererUpdateSaltC[((aIndex + 24U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 13U) + aOrbiterE) + RotL64(aOrbiterH, 27U)) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 58U));
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_Lacrosse_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xD1576DDB3FC97509ULL + 0xF71E439FA79BDD26ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xD5A9FD078A128889ULL + 0x87FFE86F5439511DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x836A005B44B20A6DULL + 0x8536C22EBE4465EBULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x9080FBBB988C7945ULL + 0xA7EBD13879E56EA9ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xF5FC0B9192188BDBULL + 0xA1097B31266AB563ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xC052E4A3C660E111ULL + 0xF5E33057B895354DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xF8188D59A7F8D599ULL + 0x876D9CA389B5F2B9ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xA4089EE7A8018CF3ULL + 0xA2B98EF9CAAC2711ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x8CFBFEF20D79F8B9ULL + 0xB428CE71F5776F5EULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xE21D1A1C8DF664FFULL + 0x8AE52A7F2E64BDA0ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x9AE385C372845EB7ULL + 0xBAF2288E48B2352DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xE441EE6E0E90BC3DULL + 0x92DAB567965504CEULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xB789E11ED2B9D0ADULL + 0xE802BDBDE8789918ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x8144C74C9AFABD5DULL + 0xC4A7F12E2EB12B6AULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x9786D08C80011505ULL + 0xAB7CE474647874C8ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xEF553D51D4683471ULL + 0x8F194F176833906EULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 512U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((aIndex + 3433U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 4517U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5108U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3192U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 4377U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aIngress, 23U)) + (RotL64(aCross, 5U) ^ RotL64(aPrevious, 50U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterH = (((aWandererI + RotL64(aIngress, 19U)) + RotL64(aCarry, 11U)) + 9774364261626083532U) + aNonceWordG;
            aOrbiterE = ((((aWandererA + RotL64(aPrevious, 6U)) + RotL64(aCarry, 57U)) + 18059001521926116420U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordF;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 29U)) + RotL64(aCarry, 29U)) + 10615626210406381148U;
            aOrbiterA = ((aWandererB + RotL64(aCross, 47U)) + 10536484278007898620U) + aPhaseAOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = (aWandererE + RotL64(aPrevious, 39U)) + 13320663045139972700U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 17127001787268166583U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterH) ^ 16742574590844166551U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterJ = RotL64((aOrbiterJ * 17828964140627204983U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 8347719720758228053U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 13502468705946051986U;
            aOrbiterE = RotL64((aOrbiterE * 13822952083584784695U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 3512687886188904904U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 495660316165795934U) ^ aNonceWordK;
            aOrbiterA = RotL64((aOrbiterA * 6724596801190194913U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 5092722552034477356U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 15641128019608284015U;
            aOrbiterI = RotL64((aOrbiterI * 3621036395703527059U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 15421873776811085458U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = (((aOrbiterH ^ aOrbiterI) ^ 17978775513204574125U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterH = RotL64((aOrbiterH * 18359600395119440183U), 11U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterI, 24U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 57U)) + aOrbiterE) + RotL64(aCarry, 29U)) + aNonceWordC);
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 58U) + RotL64(aOrbiterI, 29U)) + aOrbiterH) + aNonceWordN) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 37U) + aOrbiterJ) + RotL64(aOrbiterE, 3U));
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterI, 18U)) + aNonceWordI) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aCross, 21U) + aOrbiterJ) + RotL64(aOrbiterH, 37U)) + RotL64(aCarry, 5U)) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererI, 53U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 8850U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((aIndex + 9189U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 6514U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 6616U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 6807U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9802U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 10790U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 40U) + RotL64(aPrevious, 57U)) ^ (RotL64(aIngress, 5U) ^ RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterC = (aWandererH + RotL64(aScatter, 39U)) + 14008824488073394623U;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 18U)) + 13317978415866411468U) + aNonceWordJ;
            aOrbiterD = (((aWandererA + RotL64(aPrevious, 29U)) + RotL64(aCarry, 3U)) + 13209180141897453900U) + aPhaseAOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = ((((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 41U)) + 11870521586865233578U) + aPhaseAOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1]) + aNonceWordI;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 47U)) + RotL64(aCarry, 27U)) + 8052156380448047385U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 12158131176743680605U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 14674467487607719347U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 18372548574199176503U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 18055496790566231147U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 3838105585041578784U) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 1075709247574580091U), 21U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterA) + 2839568255183054418U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordG;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 11933612922864258179U;
            aOrbiterG = RotL64((aOrbiterG * 7571964469321160347U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 6289849094151630580U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 2640344350528492271U;
            aOrbiterE = RotL64((aOrbiterE * 16197726750829369365U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 16306175266267657791U) + aNonceWordC;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 3339898380394883600U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7105436590182982373U), 11U);
            //
            aIngress = RotL64(aOrbiterE, 3U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterA, 24U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 24U) + aOrbiterE) + RotL64(aOrbiterG, 50U)) + aNonceWordO);
            aWandererA = aWandererA + ((((RotL64(aCross, 13U) + RotL64(aOrbiterA, 35U)) + aOrbiterG) + RotL64(aCarry, 3U)) + aNonceWordL);
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 51U) + RotL64(aOrbiterC, 3U)) + aOrbiterG) + aNonceWordK) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 27U)) + aOrbiterE) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterE, 19U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 14123U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((aIndex + 15868U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aWorkLaneA[((aIndex + 14319U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 15446U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15403U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 47U) + RotL64(aCarry, 20U)) ^ (RotL64(aPrevious, 35U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 37U)) + 12027839670755583592U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = (((aWandererK + RotL64(aScatter, 57U)) + 15380130703509859843U) + aPhaseAOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1]) + aNonceWordE;
            aOrbiterA = (((aWandererG + RotL64(aCross, 14U)) + RotL64(aCarry, 23U)) + 4590907433867798074U) + aNonceWordI;
            aOrbiterI = (((aWandererD + RotL64(aPrevious, 27U)) + RotL64(aCarry, 53U)) + 1754574023602519724U) + aNonceWordM;
            aOrbiterE = (((aWandererE + RotL64(aIngress, 3U)) + RotL64(aCarry, 5U)) + 9832756659564903767U) + aNonceWordJ;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 5035088494491470403U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 14199170923323644638U;
            aOrbiterA = RotL64((aOrbiterA * 4518257134117207121U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 8325619421264440438U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 969534320779067977U) ^ aNonceWordC;
            aOrbiterC = RotL64((aOrbiterC * 17767548306355264705U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 270575869402913847U) + aNonceWordO;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 13344806516599578910U;
            aOrbiterE = RotL64((aOrbiterE * 10193544126281901579U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 15143147951139409101U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 14425582489214169238U) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 16893787086337916355U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 13951127523239064584U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = (((aOrbiterI ^ aOrbiterA) ^ 14177925225918293579U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterI = RotL64((aOrbiterI * 13079514031864998485U), 23U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 19U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 19U)) + aNonceWordF) + aPhaseAWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 56U)) + aOrbiterI) + aNonceWordP);
            aWandererE = aWandererE + ((RotL64(aCross, 13U) + RotL64(aOrbiterI, 11U)) + aOrbiterE);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterI, 41U)) + aOrbiterA) + aNonceWordL);
            aWandererG = aWandererG + (((((RotL64(aCross, 34U) + RotL64(aOrbiterA, 23U)) + aOrbiterE) + RotL64(aCarry, 37U)) + aNonceWordN) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 58U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererE, 3U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 18991U)) & S_BLOCK1], 51U) ^ RotL64(aInvestLaneA[((aIndex + 17577U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18380U)) & S_BLOCK1], 26U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 19539U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneD[((aIndex + 19633U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCross, 21U)) ^ (RotL64(aPrevious, 51U) + RotL64(aCarry, 4U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterG = (((aWandererA + RotL64(aCross, 60U)) + RotL64(aCarry, 41U)) + 2617613537256538553U) + aNonceWordF;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 37U)) + RotL64(aCarry, 23U)) + 16642868916835132715U;
            aOrbiterA = ((((aWandererF + RotL64(aPrevious, 27U)) + RotL64(aCarry, 11U)) + 10860291124337073254U) + aPhaseAOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1]) + aNonceWordA;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 19U)) + 6432511273906902472U) + aNonceWordN;
            aOrbiterD = ((aWandererJ + RotL64(aCross, 47U)) + 7505375005848241910U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            //
            aOrbiterG = (((aOrbiterG + aOrbiterI) + 11086616004678821329U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1]) + aNonceWordL;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 3298830587569881951U) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 4304047944073454489U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 9775143140064220979U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 4147601326580823120U;
            aOrbiterF = RotL64((aOrbiterF * 13462244678782260871U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 12245920269898100415U) + aNonceWordJ;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 8391940489176734499U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9119606167674098007U), 11U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterG) + 17876893379544668477U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1]) + aNonceWordM;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 18301882058180370541U;
            aOrbiterI = RotL64((aOrbiterI * 16680384667098921309U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 6869225862715140102U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 15404118372589259800U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5766851935950389915U), 3U);
            //
            aIngress = RotL64(aOrbiterA, 19U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterD, 52U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 5U) + aOrbiterF) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 22U) + aOrbiterD) + RotL64(aOrbiterG, 50U)) + aNonceWordB) + aPhaseAWandererUpdateSaltF[((aIndex + 26U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterI, 5U)) + aNonceWordH);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 57U) + aOrbiterI) + RotL64(aOrbiterG, 29U)) + aNonceWordP);
            aWandererA = aWandererA + (((((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 21U)) + aOrbiterF) + RotL64(aCarry, 37U)) + aNonceWordD) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + RotL64(aWandererA, 37U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 25113U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneB[((aIndex + 23509U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 24519U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24058U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneA[((aIndex + 22917U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCarry, 57U)) + (RotL64(aCross, 26U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterE = (((aWandererH + RotL64(aPrevious, 37U)) + RotL64(aCarry, 53U)) + 7825479804710770560U) + aNonceWordL;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 50U)) + 5298124167101358123U) + aNonceWordD;
            aOrbiterG = ((((aWandererI + RotL64(aScatter, 3U)) + RotL64(aCarry, 21U)) + 17774541024369233726U) + aPhaseAOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1]) + aNonceWordC;
            aOrbiterC = ((((aWandererE + RotL64(aIngress, 23U)) + RotL64(aCarry, 37U)) + 7679371833537454082U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = (aWandererB + RotL64(aCross, 11U)) + 5385914900748772224U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 3879781930908486531U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 659110346638873236U) ^ aNonceWordE;
            aOrbiterG = RotL64((aOrbiterG * 17439162088869824407U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 10749021728538539749U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 3631252455767429457U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8552825360915119613U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 2271978810960685021U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 5963558780692551176U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4772055335210781149U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 974909966119198104U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 9296998242911152296U;
            aOrbiterC = RotL64((aOrbiterC * 2613629915877957661U), 57U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterF) + 2245318466901521959U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1]) + aNonceWordK;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 13391076374843288568U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 18094558036982107419U), 11U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 13U);
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterG, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterA, 11U)) + aOrbiterE) + aPhaseAWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aScatter, 27U) + aOrbiterE) + RotL64(aOrbiterF, 19U)) + RotL64(aCarry, 53U)) + aNonceWordA);
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterG, 27U)) + aNonceWordJ) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 40U) + aOrbiterC) + RotL64(aOrbiterG, 37U)) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterG, 54U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + RotL64(aWandererJ, 29U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 29414U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((aIndex + 29970U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 30494U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30240U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((aIndex + 29643U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 29U)) ^ (RotL64(aIngress, 11U) + RotL64(aCross, 58U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterH = (((aWandererB + RotL64(aPrevious, 5U)) + 1210605127156905516U) + aPhaseAOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1]) + aNonceWordF;
            aOrbiterE = (((aWandererG + RotL64(aScatter, 13U)) + RotL64(aCarry, 27U)) + 11964595428173569519U) + aNonceWordP;
            aOrbiterG = ((((aWandererF + RotL64(aIngress, 40U)) + RotL64(aCarry, 43U)) + 16277319029916258482U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordD;
            aOrbiterK = (aWandererD + RotL64(aCross, 27U)) + 12369497463101824572U;
            aOrbiterB = (((aWandererJ + RotL64(aPrevious, 51U)) + RotL64(aCarry, 5U)) + 6201248574067068202U) + aNonceWordJ;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 1727477025667206661U) + aNonceWordB;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 1404510627789806851U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4810039298122529021U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 6948213591282018925U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 6688865181284421478U;
            aOrbiterH = RotL64((aOrbiterH * 12619122841662247279U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 3351130769402360855U) + aNonceWordO;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 12681032488906270823U;
            aOrbiterE = RotL64((aOrbiterE * 3680893896579741263U), 21U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterK) + 3591412591193726763U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordK;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 16153817571210878589U;
            aOrbiterB = RotL64((aOrbiterB * 4165137036092246349U), 53U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterG) + 3808228354421006630U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordE;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 1427373776207504205U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4534374093769595531U), 13U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 41U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 18U));
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 52U) + aOrbiterG) + RotL64(aOrbiterB, 43U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterK, 5U)) + aOrbiterH) + RotL64(aCarry, 41U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterK, 13U)) + aOrbiterG) + aNonceWordH);
            aWandererF = aWandererF + (((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 53U)) + aOrbiterK) + RotL64(aCarry, 23U));
            aWandererG = aWandererG ^ ((((RotL64(aCross, 11U) + RotL64(aOrbiterH, 30U)) + aOrbiterG) + aNonceWordG) + aPhaseAWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 58U));
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_Lacrosse_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xEF6F98CED04E3F41ULL + 0x817C7558D1654C42ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xA906A3D63695830BULL + 0x9FA933235B9C6860ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x97A4ECDB88739DABULL + 0x85920CE80A16B699ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x9438F8D5B8889989ULL + 0xAABC21D52BD9C50DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x8598DFC5031D49CFULL + 0xF09E1696B3E86CCAULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xC6C3FFB21880141FULL + 0xFA20A9AC92245AFEULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xECE15559C5767DC7ULL + 0xA089270087F63C1BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xB81B34B02D7FC9F7ULL + 0xA9B656D924BAFA15ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xA7D1877C898A1493ULL + 0xAE65F79F4A106BBAULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xFD945A3DAFA52AD7ULL + 0xCEAE711AB1500482ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x9971704FEE3F83FFULL + 0xCDFBAFF332FC0D25ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xC9F3F81A77E69A09ULL + 0xAD0E29B39E04BA21ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xAE9712326B0826A3ULL + 0xFEC73B46FFC9607CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xB9FA077D2CCCE04FULL + 0x9247E76CCCC284EBULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xA9446CBAD3D19243ULL + 0xC02D7D8F9BD7E400ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xCFBB2A9C875BA365ULL + 0xB9F1B577446F41F6ULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 4211U)) & S_BLOCK1], 24U) ^ RotL64(aOperationLaneB[((aIndex + 6565U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 4641U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 6012U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 7781U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 5283U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 18U) + RotL64(aPrevious, 57U)) ^ (RotL64(aIngress, 5U) ^ RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 57U)) + RotL64(aCarry, 39U)) + 13333509828310369865U;
            aOrbiterH = ((aWandererI + RotL64(aCross, 29U)) + RotL64(aCarry, 51U)) + 7645352517103840797U;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 34U)) + 5310766306660062655U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (((aWandererD + RotL64(aPrevious, 53U)) + 5165635069832352932U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordD;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 41U)) + 15684141764734281849U) + aNonceWordJ;
            aOrbiterK = (aWandererB + RotL64(aCross, 13U)) + 3327963374225061738U;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 3U)) + 8625811794878848871U) + aNonceWordH;
            aOrbiterG = (aWandererF + RotL64(aIngress, 19U)) + 7598657468430485291U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 48U)) + RotL64(aCarry, 5U)) + 2881171216276746485U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 10237691227222918101U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 6419254255884834497U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3816625473642865305U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 4238455444646479956U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 14936613353493061492U;
            aOrbiterK = RotL64((aOrbiterK * 3544216916806292273U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 15324699725208372627U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 9506640480601832011U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12819564111348390227U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 3709149613660215641U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 1724290199312754307U;
            aOrbiterG = RotL64((aOrbiterG * 12597580418257897965U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 13191172833570139194U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 3686087945377837886U) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 10883609557429936283U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 10418330386245397022U) + aNonceWordO;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 5383531313632347245U;
            aOrbiterE = RotL64((aOrbiterE * 2987755379396160073U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 7414716553072652212U) + aNonceWordP;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 11301761123966206201U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1546727321088592187U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 8570229732236388847U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 8773754460060264773U;
            aOrbiterJ = RotL64((aOrbiterJ * 3251360788932563495U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 13636929800504199371U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 5486599841558573720U;
            aOrbiterC = RotL64((aOrbiterC * 2867914211589815153U), 47U);
            //
            aIngress = RotL64(aOrbiterE, 13U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 60U));
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 47U)) + aOrbiterA) + aNonceWordF);
            aWandererB = aWandererB + (((RotL64(aIngress, 10U) + RotL64(aOrbiterC, 57U)) + aOrbiterA) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterF, 53U)) + aOrbiterE) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterH, 19U)) + aOrbiterE) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 12U)) + aOrbiterJ) + aNonceWordI);
            aWandererE = aWandererE + (((RotL64(aCross, 23U) + RotL64(aOrbiterG, 29U)) + aOrbiterF) + aNonceWordC);
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 14U) + RotL64(aOrbiterB, 35U)) + aOrbiterA) + aNonceWordN) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 47U) + aOrbiterH) + RotL64(aOrbiterB, 5U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterA, 40U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 60U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + RotL64(aWandererA, 13U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 9072U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((aIndex + 14687U)) & S_BLOCK1], 56U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 10673U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 8493U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 13658U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 15333U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 12187U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 43U) ^ RotL64(aCross, 11U)) + (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 26U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterA = (aWandererK + RotL64(aCross, 13U)) + 2225397913940961213U;
            aOrbiterI = (((aWandererI + RotL64(aPrevious, 38U)) + 8342544893601343643U) + aPhaseBOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1]) + aNonceWordB;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 29U)) + 162922186381417187U) + aNonceWordJ;
            aOrbiterK = (((aWandererJ + RotL64(aScatter, 57U)) + 11660218373710972210U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordE;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 19U)) + RotL64(aCarry, 23U)) + 14909034764605802354U;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 44U)) + RotL64(aCarry, 13U)) + 16776955237009701511U;
            aOrbiterH = (aWandererF + RotL64(aScatter, 53U)) + 5834487809188925253U;
            aOrbiterG = ((aWandererD + RotL64(aCross, 5U)) + RotL64(aCarry, 57U)) + 1498492772767040320U;
            aOrbiterB = (aWandererH + RotL64(aPrevious, 23U)) + 4161765458781579617U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 10511923076962447765U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 8575954471692620021U;
            aOrbiterE = RotL64((aOrbiterE * 12526744988828982731U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 6536325446331340573U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 1790628986900286346U;
            aOrbiterF = RotL64((aOrbiterF * 5262997114200816715U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 2623814807619278590U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 11676970995834706612U;
            aOrbiterH = RotL64((aOrbiterH * 10057461115132434901U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 13836786354224256591U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 6293096163612129260U;
            aOrbiterK = RotL64((aOrbiterK * 8977954126326217153U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 4271144764978661248U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterE) ^ 15938494256992560202U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 10004841288382726739U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 11038155227307702976U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 12408749795071243930U;
            aOrbiterG = RotL64((aOrbiterG * 5527720475032868855U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 1673665849053496882U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 12866353361497103629U;
            aOrbiterI = RotL64((aOrbiterI * 6041125499398924871U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 10673935802381580966U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 8946776538955520352U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12293084177712710021U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 16294935203370452805U) + aNonceWordA;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 4697759331563852212U;
            aOrbiterA = RotL64((aOrbiterA * 14407806317275373043U), 11U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterI, 35U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 46U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterD, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 3U) + aOrbiterD) + RotL64(aOrbiterH, 3U)) + aNonceWordM);
            aWandererI = aWandererI + ((((RotL64(aCross, 12U) + aOrbiterD) + RotL64(aOrbiterG, 53U)) + RotL64(aCarry, 29U)) + aNonceWordI);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterF, 14U)) + aOrbiterE);
            aWandererE = aWandererE + (((RotL64(aScatter, 47U) + aOrbiterK) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 39U) + aOrbiterI) + RotL64(aOrbiterB, 47U));
            aWandererK = aWandererK + ((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 43U)) + aOrbiterA);
            aWandererD = aWandererD ^ (((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterA, 39U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 53U) + aOrbiterH) + RotL64(aOrbiterA, 30U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 58U) + RotL64(aOrbiterE, 23U)) + aOrbiterK) + aPhaseBWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + (RotL64(aWandererH, 26U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 21866U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneA[((aIndex + 23694U)) & S_BLOCK1], 23U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 18632U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21453U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20616U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 17791U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 19711U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aPrevious, 6U)) + (RotL64(aCross, 53U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterD = ((aWandererF + RotL64(aScatter, 29U)) + 17081642665820489793U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aIngress, 35U)) + 14468854040067229623U;
            aOrbiterK = (((aWandererA + RotL64(aCross, 39U)) + RotL64(aCarry, 47U)) + 2249450222593057429U) + aNonceWordG;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 4U)) + RotL64(aCarry, 35U)) + 14964389079511378664U;
            aOrbiterI = (aWandererG + RotL64(aCross, 53U)) + 17003491054252360650U;
            aOrbiterC = ((((aWandererE + RotL64(aScatter, 47U)) + RotL64(aCarry, 19U)) + 12710882240582032588U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordE;
            aOrbiterG = (aWandererB + RotL64(aIngress, 13U)) + 9887078182156755359U;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 57U)) + 7665284531810584704U;
            aOrbiterA = (aWandererC + RotL64(aIngress, 24U)) + 7304284015511876717U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 5517927023543751734U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 17704756310857362759U;
            aOrbiterK = RotL64((aOrbiterK * 15826832172923213591U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 11347400363019508578U) + aNonceWordO;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 11696395232760991243U;
            aOrbiterD = RotL64((aOrbiterD * 9725231749679442003U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 10875780291242873583U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 7808740614343437672U;
            aOrbiterE = RotL64((aOrbiterE * 8889516201913716283U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 3145390996141902032U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 16080636485642732615U;
            aOrbiterC = RotL64((aOrbiterC * 7445756373012217305U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 3929263288176983844U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 18210228766683996806U) ^ aNonceWordI;
            aOrbiterB = RotL64((aOrbiterB * 13178080076505449091U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 13948962323541421431U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 3037683309790156893U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13406672352222636739U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 17827265198532699474U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterB) ^ 7270895262023504864U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterF = RotL64((aOrbiterF * 13467417362477308167U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 6431243064980879185U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 6680205390976259885U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10421386694108590789U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 15910655919164357152U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 8046213498216027383U;
            aOrbiterI = RotL64((aOrbiterI * 18061867495824063553U), 13U);
            //
            aIngress = RotL64(aOrbiterB, 6U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 21U));
            aIngress = aIngress + RotL64(aOrbiterI, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 41U)) + aOrbiterA);
            aWandererA = aWandererA + (((RotL64(aCross, 19U) + RotL64(aOrbiterC, 30U)) + aOrbiterI) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 19U)) + aOrbiterI) + aPhaseBWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 23U) + aOrbiterC) + RotL64(aOrbiterE, 51U)) + RotL64(aCarry, 3U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 14U) + aOrbiterG) + RotL64(aOrbiterC, 57U));
            aWandererK = aWandererK + ((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterK, 11U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterB, 37U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterK, 4U)) + aOrbiterF) + aNonceWordK);
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 60U) + RotL64(aOrbiterE, 23U)) + aOrbiterB) + aNonceWordM) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 26U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererB, 41U);
            aCarry = aCarry + RotL64(aIngress, 56U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 27026U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 31746U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 24839U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 31837U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31568U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27378U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 31081U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 52U)) ^ (RotL64(aIngress, 5U) + RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterA = ((aWandererA + RotL64(aIngress, 57U)) + 17454559218352016650U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = (aWandererC + RotL64(aPrevious, 36U)) + 8005709669325164803U;
            aOrbiterG = (aWandererB + RotL64(aScatter, 11U)) + 13393741948412816357U;
            aOrbiterB = (aWandererH + RotL64(aCross, 3U)) + 3665865624348875553U;
            aOrbiterD = (((aWandererI + RotL64(aPrevious, 53U)) + RotL64(aCarry, 29U)) + 8334142570031883436U) + aNonceWordI;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 47U)) + 17226066128706139657U) + aNonceWordM;
            aOrbiterF = ((((aWandererD + RotL64(aScatter, 23U)) + RotL64(aCarry, 39U)) + 3319093033121522613U) + aPhaseBOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterI = ((aWandererG + RotL64(aCross, 43U)) + RotL64(aCarry, 3U)) + 6657535603401588798U;
            aOrbiterC = (aWandererF + RotL64(aIngress, 30U)) + 5469746182326331147U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 17846791786050221418U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 15939541003714896288U;
            aOrbiterG = RotL64((aOrbiterG * 1400351482213119809U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 12076763190461077406U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 3594038213596405284U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10244002692575821495U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 8301291631324464622U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 8460406137668390582U;
            aOrbiterF = RotL64((aOrbiterF * 9117147929757711595U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 7612394867020871200U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 8525076134853103975U) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 5790440201072204659U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 11929899088215090379U) + aNonceWordO;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 7119509166360685726U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1662341427992528823U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 5081078459225240607U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 17149991983909906705U;
            aOrbiterD = RotL64((aOrbiterD * 950223374568067343U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 8817303295675241994U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 7962039282652745113U;
            aOrbiterB = RotL64((aOrbiterB * 12773588587795522121U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 13596273086338032370U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 8186297702278180956U;
            aOrbiterI = RotL64((aOrbiterI * 6226504769888753861U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 1696277861691580263U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 17360461831507082959U;
            aOrbiterA = RotL64((aOrbiterA * 1651378456022210983U), 23U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 43U);
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 39U));
            aIngress = aIngress + RotL64(aOrbiterC, 58U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 36U) + RotL64(aOrbiterJ, 36U)) + aOrbiterI) + aNonceWordN);
            aWandererE = aWandererE ^ (((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterH, 23U)) + aNonceWordP);
            aWandererB = aWandererB + (((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 57U)) + aOrbiterF) + aPhaseBWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterC, 41U)) + aOrbiterB) + aNonceWordH);
            aWandererA = aWandererA + ((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterA, 12U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 23U) + aOrbiterJ) + RotL64(aOrbiterF, 47U));
            aWandererI = aWandererI + (((RotL64(aIngress, 47U) + RotL64(aOrbiterD, 29U)) + aOrbiterH) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 10U) + aOrbiterC) + RotL64(aOrbiterD, 19U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterH, 51U)) + RotL64(aCarry, 21U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 22U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + RotL64(aWandererI, 5U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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

void TwistExpander_Lacrosse_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xFDB5FE4C4C1EF5C9ULL + 0xE506395F8514AFC8ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xB1D96BFA043C58BBULL + 0x8EACC7E4CBE23A68ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x87E29D681831325DULL + 0xBA5A4CAEE235AD65ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x833B1BE6B97A351DULL + 0xAB56E9EE08217E04ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xE23904CFA6A10BD5ULL + 0xB4765B19463A3779ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xD0CAE758D2B4E41FULL + 0xED6F0D8F950965FCULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x8AAF30CE1DF6E36DULL + 0xC4F8C600CA9EF415ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF8D95112C188B655ULL + 0x9BF0CBADA95FB77FULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xF53E75F1A1F51157ULL + 0x8B052CED7388FE63ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x9F70D7E965DAB161ULL + 0x9C12947E038E086CULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x86ABCE00CB1ED04DULL + 0x99E681E34FD21FD7ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x9B63A7DF716BBC6BULL + 0x850CDDD2E9FEE804ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xD5D762860DE4B485ULL + 0xBAC345203D4B2AD3ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xC892F7321008BBEBULL + 0xA592E1CFDF1AD356ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x88E5EFBCD795C0E9ULL + 0xEB2ECA3592D1E430ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xF2A4474E1D76DD97ULL + 0xD1F745CC352988FFULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 1588U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((aIndex + 2352U)) & S_BLOCK1], 38U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 3470U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2841U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3601U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 572U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 54U) ^ RotL64(aIngress, 21U)) + (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterI = (((aWandererK + RotL64(aCross, 5U)) + RotL64(aCarry, 5U)) + 5131645209694953015U) + aNonceWordJ;
            aOrbiterF = (aWandererJ + RotL64(aScatter, 30U)) + 12070391048835379854U;
            aOrbiterK = (aWandererG + RotL64(aIngress, 51U)) + 2604295836242338724U;
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 43U)) + 14042039029284001596U) + aNonceWordP;
            aOrbiterE = ((aWandererD + RotL64(aCross, 11U)) + 8914654543854559327U) + aNonceWordA;
            aOrbiterG = (((aWandererE + RotL64(aPrevious, 21U)) + RotL64(aCarry, 21U)) + 2185619407969359869U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = (((aWandererA + RotL64(aScatter, 37U)) + RotL64(aCarry, 37U)) + 5187406295103352574U) + aPhaseDOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 8022832481290871217U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 8783061916740573472U) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 3309891377744201773U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 10711028365596196301U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterF) ^ 13387065038269133571U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 12444578026365205255U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 11187001318931801582U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = (((aOrbiterI ^ aOrbiterH) ^ 14191473173276034019U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterI = RotL64((aOrbiterI * 2491253922434756431U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 16207761776716426435U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 9677408414452078760U;
            aOrbiterG = RotL64((aOrbiterG * 5487303383095129949U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 17812460332794370649U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 7736423148554132028U;
            aOrbiterH = RotL64((aOrbiterH * 15588733747232852555U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 17293203944059014763U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 13487243633338010243U;
            aOrbiterF = RotL64((aOrbiterF * 9468688858740539095U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 15979293016815060755U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 17645215484691359547U;
            aOrbiterA = RotL64((aOrbiterA * 1449450767288733995U), 35U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 19U);
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + RotL64(aOrbiterI, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 52U)) + aOrbiterA) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 35U)) + aOrbiterF) + RotL64(aCarry, 21U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterG, 11U));
            aWandererF = aWandererF + ((RotL64(aCross, 21U) + aOrbiterH) + RotL64(aOrbiterG, 5U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 27U)) + aOrbiterG);
            aWandererE = aWandererE + ((((RotL64(aCross, 4U) + aOrbiterK) + RotL64(aOrbiterI, 21U)) + RotL64(aCarry, 35U)) + aNonceWordB);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterF, 41U)) + aOrbiterE) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 56U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 5954U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneC[((aIndex + 9445U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 6596U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 9996U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8319U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6222U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 6316U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCross, 3U)) + (RotL64(aCarry, 23U) + RotL64(aIngress, 54U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterI = (((aWandererK + RotL64(aCross, 19U)) + 12222235191147985484U) + aPhaseDOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1]) + aNonceWordM;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 30U)) + 16367317014523328414U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 13U)) + 3511378091284703789U;
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 37U)) + RotL64(aCarry, 51U)) + 15247492830966725949U;
            aOrbiterJ = (((aWandererG + RotL64(aCross, 13U)) + RotL64(aCarry, 37U)) + 7745995913390407897U) + aNonceWordA;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 53U)) + 6463593307540108810U) + aNonceWordO;
            aOrbiterD = (aWandererE + RotL64(aPrevious, 47U)) + 1101669311005268630U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 12988052764067518580U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 17717179747434679772U) ^ aNonceWordL;
            aOrbiterC = RotL64((aOrbiterC * 10820310705487638793U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 11662190906682400416U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 6563014073547628748U;
            aOrbiterJ = RotL64((aOrbiterJ * 16967910471722117761U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 13099094932059419219U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 16342730862261868847U;
            aOrbiterE = RotL64((aOrbiterE * 10988124108686164829U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 16855346813127524624U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 6570063128502306944U) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 4571570049463124831U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 11328352033809240501U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 11640986648833160901U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2895830492089678919U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 2675226158571501666U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 17700531248266458165U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2231403813970188657U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 7729597396731910874U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 15172374484412053756U;
            aOrbiterI = RotL64((aOrbiterI * 149009041406406517U), 13U);
            //
            aIngress = RotL64(aOrbiterJ, 57U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterD, 12U)) + aNonceWordP);
            aWandererE = aWandererE ^ ((((RotL64(aCross, 11U) + RotL64(aOrbiterC, 21U)) + aOrbiterI) + aNonceWordF) + aPhaseDWandererUpdateSaltD[((aIndex + 12U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 18U) + aOrbiterK) + RotL64(aOrbiterE, 41U)) + aNonceWordG);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 41U) + aOrbiterF) + RotL64(aOrbiterI, 29U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterJ, 35U)) + aOrbiterK) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 5U)) + aOrbiterK) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterF, 51U)) + RotL64(aCarry, 5U)) + aNonceWordD);
            //
            aCarry = aCarry + (RotL64(aWandererB, 6U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 27U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 14081U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneA[((aIndex + 15562U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 11914U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12083U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15457U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 40U) ^ RotL64(aIngress, 27U)) + (RotL64(aPrevious, 5U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterJ = ((((aWandererD + RotL64(aIngress, 41U)) + RotL64(aCarry, 57U)) + 17225673071833726819U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordE;
            aOrbiterF = (((aWandererF + RotL64(aPrevious, 51U)) + RotL64(aCarry, 19U)) + 10301458382103627331U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aWandererB + RotL64(aCross, 21U)) + 3960233050857362414U;
            aOrbiterA = (((aWandererG + RotL64(aScatter, 5U)) + RotL64(aCarry, 5U)) + 17768665685046605837U) + aNonceWordP;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 14U)) + 14471018461213959767U) + aNonceWordO;
            aOrbiterG = (aWandererH + RotL64(aScatter, 57U)) + 10730597892721340453U;
            aOrbiterE = ((aWandererI + RotL64(aCross, 35U)) + 14863394003122760542U) + aNonceWordL;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 9948587274816688296U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 3573569431435100993U;
            aOrbiterI = RotL64((aOrbiterI * 2303922230056523077U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 8153670675740450590U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 16438856577722561424U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4689247488336908827U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 15765587867581925041U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 1082039522061775213U;
            aOrbiterJ = RotL64((aOrbiterJ * 17023740047246402641U), 37U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterA) + 4202521649260798876U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1]) + aNonceWordB;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 15877659681260461141U) ^ aNonceWordG;
            aOrbiterD = RotL64((aOrbiterD * 11369910758551088173U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 2551560426129646123U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterD) ^ 3005102326163906320U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 4241583192662435107U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 1675501058857208089U) + aNonceWordF;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 12774812270956702043U;
            aOrbiterA = RotL64((aOrbiterA * 5488437008504905105U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 1044886020922563597U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 4857445127457225171U;
            aOrbiterF = RotL64((aOrbiterF * 13223560654459705259U), 19U);
            //
            aIngress = RotL64(aOrbiterE, 3U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 57U) + aOrbiterF) + RotL64(aOrbiterE, 30U)) + aNonceWordD);
            aWandererI = aWandererI + (((((RotL64(aIngress, 41U) + aOrbiterD) + RotL64(aOrbiterA, 41U)) + RotL64(aCarry, 41U)) + aNonceWordC) + aPhaseDWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterF, 21U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 3U)) + aOrbiterJ) + aPhaseDWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterI, 47U)) + aOrbiterD);
            aWandererF = aWandererF + (((RotL64(aScatter, 4U) + aOrbiterD) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 13U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 13U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 48U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 19595U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 20891U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 21725U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19450U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18276U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 57U)) + (RotL64(aCross, 43U) ^ RotL64(aPrevious, 30U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 39U)) + 3684295017013759987U) + aNonceWordB;
            aOrbiterD = ((aWandererJ + RotL64(aCross, 12U)) + 6740408842457292881U) + aPhaseDOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aIngress, 5U)) + 4563975890702399441U) + aPhaseDOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aScatter, 47U)) + RotL64(aCarry, 57U)) + 797804144825287940U;
            aOrbiterC = ((aWandererK + RotL64(aCross, 29U)) + RotL64(aCarry, 41U)) + 2763779540450101303U;
            aOrbiterG = (((aWandererB + RotL64(aIngress, 19U)) + RotL64(aCarry, 19U)) + 13211846164102089685U) + aNonceWordK;
            aOrbiterH = (aWandererC + RotL64(aPrevious, 53U)) + 15214578447281401982U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 13745208628754232427U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterE) ^ 17358621225969190747U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterI = RotL64((aOrbiterI * 5325024317338823061U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 779739369960480023U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 4370963533701407813U;
            aOrbiterE = RotL64((aOrbiterE * 3123135216876641039U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 6061333005507739975U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 3589705340762734456U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16499293983611196967U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 10607697666369230567U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 9356757995305239271U;
            aOrbiterH = RotL64((aOrbiterH * 10945513661439954731U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 10093033335903048138U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 11037328061699834100U) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 11189760551792389605U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 558431161176115540U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterH) ^ 17795680919453449358U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 3910117359996283803U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 6096779391116214109U) + aNonceWordG;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 17594243286880690775U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12655610181937429915U), 13U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterG, 29U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 48U));
            aIngress = aIngress + (RotL64(aOrbiterE, 23U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterG, 21U)) + RotL64(aCarry, 43U)) + aNonceWordP);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 5U) + aOrbiterH) + RotL64(aOrbiterG, 29U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 37U) + aOrbiterE) + RotL64(aOrbiterD, 5U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterD, 13U)) + aOrbiterG) + aNonceWordA);
            aWandererD = aWandererD + (((RotL64(aIngress, 13U) + aOrbiterC) + RotL64(aOrbiterH, 37U)) + aPhaseDWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterI, 43U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aScatter, 46U) + aOrbiterF) + RotL64(aOrbiterE, 58U)) + RotL64(aCarry, 11U)) + aNonceWordH);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 56U));
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 13U);
            aCarry = aCarry + RotL64(aIngress, 28U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 26955U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((aIndex + 26701U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 26059U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 26064U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22916U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCross, 41U)) ^ (RotL64(aPrevious, 6U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterG = (((aWandererC + RotL64(aPrevious, 5U)) + 6916817163240024692U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordP;
            aOrbiterB = (((aWandererJ + RotL64(aScatter, 35U)) + RotL64(aCarry, 53U)) + 14554930751292077817U) + aNonceWordM;
            aOrbiterC = (aWandererD + RotL64(aCross, 24U)) + 1098305064484336101U;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 47U)) + RotL64(aCarry, 21U)) + 12192821172420471527U;
            aOrbiterF = ((aWandererG + RotL64(aCross, 41U)) + RotL64(aCarry, 39U)) + 2435134991707318845U;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 11U)) + 1896745368738512624U) + aNonceWordO;
            aOrbiterH = (((aWandererI + RotL64(aIngress, 53U)) + 1114996424222923873U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordG;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 9839135798371512656U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 8037967239603177043U;
            aOrbiterC = RotL64((aOrbiterC * 7848951103759663025U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 15185468738487237432U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 4912098316394854543U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3072785550384399929U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 13142688607850380888U) + aNonceWordH;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 4507379759608945839U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2989332387754215967U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 7299006009652289342U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 5390655277207053627U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10973744708856143715U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 6744737023577785725U) + aNonceWordK;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 15539737698867067285U;
            aOrbiterB = RotL64((aOrbiterB * 4686092035261336911U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 13329866734681377952U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 13284937458969166257U;
            aOrbiterH = RotL64((aOrbiterH * 3965985432462699445U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 8695002088915702168U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 3858059421620839286U;
            aOrbiterE = RotL64((aOrbiterE * 9559783727301092937U), 47U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterG, 22U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 11U) + RotL64(aOrbiterG, 11U)) + aOrbiterB) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 51U) + aOrbiterF) + RotL64(aOrbiterG, 21U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 47U)) + aOrbiterI) + aNonceWordE);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 60U)) + aOrbiterF) + aNonceWordN);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 21U) + aOrbiterC) + RotL64(aOrbiterH, 5U)) + RotL64(aCarry, 13U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 53U)) + aOrbiterE) + aPhaseDWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 4U) + aOrbiterH) + RotL64(aOrbiterG, 39U)) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 48U));
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererD, 43U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 30895U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneA[((aIndex + 31752U)) & S_BLOCK1], 48U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 32135U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 31492U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29923U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 24U) + RotL64(aCarry, 57U)) ^ (RotL64(aCross, 5U) + RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 51U)) + RotL64(aCarry, 3U)) + 4204560462077827182U;
            aOrbiterK = (((aWandererH + RotL64(aIngress, 11U)) + RotL64(aCarry, 41U)) + 6572370199668594039U) + aPhaseDOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = (((aWandererI + RotL64(aCross, 5U)) + 15958999876732622825U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordB;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 21U)) + RotL64(aCarry, 21U)) + 9969349486879280377U;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 35U)) + 15450238998293956181U;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 60U)) + 9128619863683138259U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 41U)) + 5691270563628979565U) + aNonceWordC;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 5901029710568933106U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 10442738941988588834U;
            aOrbiterF = RotL64((aOrbiterF * 7386621444831603817U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 3508116020325721993U) + aNonceWordH;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 13221917083569767259U) ^ aNonceWordI;
            aOrbiterK = RotL64((aOrbiterK * 6845108555710135357U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 11627915460377128176U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 17858261365514253433U;
            aOrbiterD = RotL64((aOrbiterD * 7535577636975884641U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 4294837988806295989U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 11242915481585070249U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17540688242763829319U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 13030663829236027109U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 7451948220723185149U;
            aOrbiterJ = RotL64((aOrbiterJ * 5191778587712222029U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 5575508866505031037U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterJ) ^ 5161096033789876794U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterA = RotL64((aOrbiterA * 16843827915802461797U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 3980482740649505122U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 11188906150207270241U;
            aOrbiterB = RotL64((aOrbiterB * 408550837615188413U), 35U);
            //
            aIngress = RotL64(aOrbiterB, 19U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterH, 27U)) + aPhaseDWandererUpdateSaltF[((aIndex + 16U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 4U) + RotL64(aOrbiterB, 19U)) + aOrbiterH) + aNonceWordA);
            aWandererF = aWandererF + (((RotL64(aIngress, 57U) + RotL64(aOrbiterA, 35U)) + aOrbiterK) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 39U) + aOrbiterD) + RotL64(aOrbiterJ, 60U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 53U)) + aOrbiterF) + RotL64(aCarry, 37U)) + aNonceWordD);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterD, 41U));
            aWandererH = aWandererH + (((RotL64(aIngress, 47U) + aOrbiterH) + RotL64(aOrbiterJ, 47U)) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 58U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 43U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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

void TwistExpander_Lacrosse_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xBE42CB6B5EAA8AADULL + 0xE329FE9AE1D5E563ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x9BBDF70CF73A6493ULL + 0xFAB0C212FCEB0985ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x95C296AD95363BD5ULL + 0xA05519363EBDE7F4ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xE2B6D03A550C82D7ULL + 0xEBEB5A89F63A7EFBULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x80A7B20AA2C8C201ULL + 0x8817B10CED33E31CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x8A8EFCACE8988DB3ULL + 0x82219E404265F5E6ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xE8D3A6BF9FFDAF03ULL + 0xEE395AAE0D5444F9ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x8CFD41520C75EE6DULL + 0x8795E9CFBAE18936ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xE7F154C0E4A3ED59ULL + 0xEA96143520D97F48ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xDF781EAA77884F9DULL + 0x8FEDC464C770ECD4ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xE830911609E23EE3ULL + 0xB77BDCEB1A92E244ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xDD9A852405157DCBULL + 0xF1E274B4C46C9EA8ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xBDCACE9105908303ULL + 0x91EF947FDC1E4C70ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xA0A58E9E65090EEBULL + 0xC49C37C563B92716ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xBD0590A8599E49DFULL + 0xF264CFEAF6CDF266ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xF5EDECB5BCC5E07FULL + 0xAFAA8859937C1D24ULL);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 3914U)) & S_BLOCK1], 28U) ^ RotL64(aInvestLaneB[((aIndex + 509U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 5022U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 1418U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 1623U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 3785U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 11U)) ^ (RotL64(aIngress, 52U) + RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterK = (aWandererK + RotL64(aIngress, 11U)) + 14157904117287696136U;
            aOrbiterF = (aWandererJ + RotL64(aScatter, 51U)) + 7369512677371640676U;
            aOrbiterI = (aWandererA + RotL64(aCross, 54U)) + 8411250745902073798U;
            aOrbiterC = (((aWandererE + RotL64(aPrevious, 13U)) + 5002041814539710275U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordG;
            aOrbiterH = (aWandererI + RotL64(aIngress, 21U)) + 9538041410816283124U;
            aOrbiterA = (aWandererH + RotL64(aScatter, 39U)) + 5210700103927513061U;
            aOrbiterB = (aWandererF + RotL64(aCross, 57U)) + 7600709399101287982U;
            aOrbiterG = (((aWandererC + RotL64(aPrevious, 43U)) + 2366369466696580499U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordM;
            aOrbiterE = (((aWandererB + RotL64(aIngress, 35U)) + RotL64(aCarry, 3U)) + 5544575244203019109U) + aNonceWordP;
            aOrbiterJ = (((aWandererG + RotL64(aScatter, 19U)) + RotL64(aCarry, 47U)) + 8710073749110329779U) + aNonceWordF;
            aOrbiterD = ((aWandererD + RotL64(aCross, 60U)) + RotL64(aCarry, 19U)) + 15998211310115361630U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 15354357553877376422U) + aNonceWordE;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 10657523549259276169U;
            aOrbiterI = RotL64((aOrbiterI * 13695239532898311073U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 10405750198355464768U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 3465819693133515142U) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 14678343718277562799U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 16724189641701408630U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 3484340153620198872U;
            aOrbiterG = RotL64((aOrbiterG * 17247547677520703125U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 7420442404884871126U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 11138445997256757636U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11167543379937571127U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 1428191560884663125U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 16950093140800653985U;
            aOrbiterF = RotL64((aOrbiterF * 4423012306984814805U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 17288299075036481960U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 13793597915359681028U;
            aOrbiterD = RotL64((aOrbiterD * 9639204979982125757U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 5017972942710079726U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 12409957957614320964U) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 10273295741911545745U), 5U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterC) + 12487994181992095174U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordO;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 1573393166996612118U;
            aOrbiterJ = RotL64((aOrbiterJ * 13364311829104520751U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 13227642825780350128U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 7961292096150889569U;
            aOrbiterA = RotL64((aOrbiterA * 16627209081334341289U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 10312485102088913337U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 3177620041478410950U;
            aOrbiterB = RotL64((aOrbiterB * 15918551366833593853U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 2599092792737616563U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 14157904117287696136U;
            aOrbiterH = RotL64((aOrbiterH * 14883446269291639813U), 23U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterD, 5U);
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + (RotL64(aOrbiterA, 34U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterB, 44U)) + RotL64(aCarry, 27U)) + aNonceWordI);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterK, 53U));
            aWandererB = aWandererB + (((RotL64(aCross, 11U) + RotL64(aOrbiterB, 27U)) + aOrbiterE) + aPhaseEWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 11U)) + aOrbiterI) + aPhaseEWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 21U)) + aOrbiterG) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 48U) + RotL64(aOrbiterJ, 13U)) + aOrbiterI) + aNonceWordC);
            aWandererD = aWandererD + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 57U)) + aOrbiterK) + aNonceWordD);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterD, 3U)) + aOrbiterG);
            aWandererG = aWandererG + ((RotL64(aPrevious, 13U) + aOrbiterF) + RotL64(aOrbiterC, 39U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterC, 34U)) + aOrbiterD);
            aWandererH = aWandererH + (((RotL64(aIngress, 50U) + aOrbiterH) + RotL64(aOrbiterI, 29U)) + aNonceWordJ);
            //
            aCarry = aCarry + (RotL64(aWandererD, 54U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 44U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 6888U)) & S_BLOCK1], 43U) ^ RotL64(aInvestLaneC[((aIndex + 5968U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 7534U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 6369U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 7570U)) & S_BLOCK1], 57U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 6518U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 6040U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 54U) ^ RotL64(aCross, 35U)) + (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterG = ((aWandererK + RotL64(aIngress, 57U)) + 4980738603982643969U) + aNonceWordC;
            aOrbiterH = (aWandererI + RotL64(aScatter, 6U)) + 17660278413018470020U;
            aOrbiterC = (aWandererA + RotL64(aPrevious, 51U)) + 17598114429859543466U;
            aOrbiterA = (aWandererC + RotL64(aCross, 39U)) + 10993929335279994739U;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 43U)) + 17967203122976322481U) + aNonceWordO;
            aOrbiterJ = (((aWandererB + RotL64(aPrevious, 10U)) + 1872290205549034384U) + aPhaseEOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1]) + aNonceWordK;
            aOrbiterD = (((aWandererJ + RotL64(aCross, 47U)) + RotL64(aCarry, 43U)) + 16607778671782810797U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aScatter, 19U)) + 4895226930754394376U;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 21U)) + RotL64(aCarry, 11U)) + 14960359005982301383U;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 41U)) + RotL64(aCarry, 19U)) + 9921642352377700630U;
            aOrbiterI = ((aWandererE + RotL64(aCross, 13U)) + 893281964367208693U) + aNonceWordP;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 8232519988397858732U) + aNonceWordH;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 4433022122758913407U;
            aOrbiterC = RotL64((aOrbiterC * 834240393225479419U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 12689609831247168353U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 404535388957472176U;
            aOrbiterG = RotL64((aOrbiterG * 14534020545479806593U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 3349108201964013155U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 4386449511297371730U) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 9596273264321140229U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 14314587717949070586U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 10923886625271054985U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7838969002623486809U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 17634909585329833520U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 2021301459918350372U;
            aOrbiterJ = RotL64((aOrbiterJ * 1388242915918642741U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 5219599112498224367U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 10641339455385046206U;
            aOrbiterE = RotL64((aOrbiterE * 1022283727595400719U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 5003342156562330058U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 10951027475628404336U;
            aOrbiterH = RotL64((aOrbiterH * 17836928292555158461U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 13040991872592235460U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 11149099984302782267U;
            aOrbiterI = RotL64((aOrbiterI * 4248667283139686251U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 2202253777854402763U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 16679038924474862612U;
            aOrbiterD = RotL64((aOrbiterD * 2624443661523083597U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 1959650241410955571U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 8415989510614674816U;
            aOrbiterF = RotL64((aOrbiterF * 16340289102832732519U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 2344501711730399821U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 4980738603982643969U;
            aOrbiterB = RotL64((aOrbiterB * 6419275275477478723U), 3U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 6U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 51U));
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 58U));
            aIngress = aIngress + RotL64(aOrbiterJ, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aCross, 30U) + aOrbiterJ) + RotL64(aOrbiterB, 37U)) + aNonceWordI) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 57U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aPrevious, 39U) + aOrbiterD) + RotL64(aOrbiterK, 41U)) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 35U)) + aOrbiterC);
            aWandererD = aWandererD + ((RotL64(aScatter, 37U) + aOrbiterD) + RotL64(aOrbiterJ, 60U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 23U) + aOrbiterB) + RotL64(aOrbiterK, 3U)) + aNonceWordN);
            aWandererI = aWandererI + ((RotL64(aCross, 60U) + aOrbiterE) + RotL64(aOrbiterC, 29U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterC, 51U)) + aOrbiterK);
            aWandererG = aWandererG + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterK, 12U)) + aOrbiterG) + RotL64(aCarry, 27U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterE, 5U)) + aOrbiterF) + aNonceWordM);
            aWandererE = aWandererE + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterH, 21U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 38U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 12483U)) & S_BLOCK1], 4U) ^ RotL64(aInvestLaneA[((aIndex + 12364U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15641U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 13743U)) & S_BLOCK1], 43U) ^ RotL64(aInvestLaneC[((aIndex + 13319U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 54U)) + (RotL64(aCross, 19U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterA = (aWandererH + RotL64(aCross, 19U)) + 15188686795415908074U;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 43U)) + 17310049041983079779U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = (((aWandererI + RotL64(aPrevious, 22U)) + RotL64(aCarry, 23U)) + 8246925977992441471U) + aNonceWordM;
            aOrbiterH = (aWandererK + RotL64(aScatter, 35U)) + 8644260919918112781U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 53U)) + 13401663736874819483U;
            aOrbiterI = (((aWandererG + RotL64(aScatter, 47U)) + RotL64(aCarry, 35U)) + 7940358935238314973U) + aNonceWordP;
            aOrbiterJ = (((aWandererJ + RotL64(aPrevious, 13U)) + 13278990328548007839U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordC;
            aOrbiterK = ((aWandererF + RotL64(aCross, 27U)) + RotL64(aCarry, 47U)) + 11346868298353840706U;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 60U)) + 2374077904806833579U) + aNonceWordA;
            aOrbiterE = (aWandererB + RotL64(aScatter, 3U)) + 6978903378645019166U;
            aOrbiterD = (aWandererC + RotL64(aIngress, 39U)) + 11951633297870965212U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 17398460995357409673U) + aNonceWordL;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 1215437945597836770U;
            aOrbiterG = RotL64((aOrbiterG * 9322970054123481621U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 1878751468043972239U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 5343002808239712390U;
            aOrbiterI = RotL64((aOrbiterI * 11878640995447558811U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 9884918450053276861U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 15894599082080422550U) ^ aNonceWordO;
            aOrbiterK = RotL64((aOrbiterK * 8359936745539546131U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 13917339232771145459U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 18101134009493720683U;
            aOrbiterE = RotL64((aOrbiterE * 15835859435306756387U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 3830086372356903769U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 15894394599564584010U;
            aOrbiterA = RotL64((aOrbiterA * 9513921913446609263U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 5127590955274245812U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 9410946933309720054U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14507476989423060561U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 15544384157294987085U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 998801294460434123U;
            aOrbiterB = RotL64((aOrbiterB * 5946968142746472745U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 16442095194965452163U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 14294936349037516932U) ^ aNonceWordE;
            aOrbiterF = RotL64((aOrbiterF * 14655345374740882581U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 16680659892463349201U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 10921918150041635666U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2908474941036821745U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 15350264522133299871U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 16413848767507968239U;
            aOrbiterC = RotL64((aOrbiterC * 10226942289998651355U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 11963105565077056299U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 15188686795415908074U;
            aOrbiterJ = RotL64((aOrbiterJ * 13002484121826831091U), 37U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterF, 60U);
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 39U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + RotL64(aOrbiterG, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterI, 34U)) + aOrbiterD);
            aWandererK = aWandererK + ((RotL64(aPrevious, 14U) + aOrbiterF) + RotL64(aOrbiterI, 19U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 29U) + aOrbiterE) + RotL64(aOrbiterC, 51U)) + aNonceWordG);
            aWandererC = aWandererC + ((RotL64(aScatter, 53U) + aOrbiterB) + RotL64(aOrbiterH, 39U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterH, 43U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 14U)) + aOrbiterD) + RotL64(aCarry, 19U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 11U) + aOrbiterA) + RotL64(aOrbiterJ, 57U)) + aNonceWordF);
            aWandererF = aWandererF + (((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 27U)) + aOrbiterC) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterE, 37U)) + aOrbiterA) + aPhaseEWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aIngress, 20U) + RotL64(aOrbiterA, 47U)) + aOrbiterG) + RotL64(aCarry, 35U)) + aNonceWordN);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterG, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 26U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (RotL64(aWandererE, 10U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 16737U)) & S_BLOCK1], 21U) ^ RotL64(aSnowLaneA[((aIndex + 21285U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 17389U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 18380U)) & S_BLOCK1], 36U) ^ RotL64(aInvestLaneD[((aIndex + 18989U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 24U) ^ RotL64(aPrevious, 39U)) ^ (RotL64(aCarry, 11U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterF = ((aWandererB + RotL64(aScatter, 19U)) + 2783898056762489197U) + aNonceWordC;
            aOrbiterK = (aWandererD + RotL64(aCross, 11U)) + 7177192902873343053U;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 46U)) + RotL64(aCarry, 53U)) + 12254703232691980774U;
            aOrbiterE = (aWandererE + RotL64(aIngress, 13U)) + 15446547245691219559U;
            aOrbiterG = (aWandererH + RotL64(aPrevious, 43U)) + 888475203006174856U;
            aOrbiterI = (((aWandererA + RotL64(aCross, 53U)) + RotL64(aCarry, 5U)) + 3649183529366307877U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aScatter, 23U)) + 4642631047518805167U) + aNonceWordA;
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 35U)) + RotL64(aCarry, 21U)) + 6108329730724782250U;
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 37U)) + 8334054653023816636U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = ((aWandererG + RotL64(aCross, 41U)) + 5891895375031474350U) + aNonceWordG;
            aOrbiterA = (aWandererK + RotL64(aScatter, 28U)) + 3176720746238477862U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 6111038696865301675U) + aNonceWordL;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 11914998302228682704U;
            aOrbiterB = RotL64((aOrbiterB * 11738924766359642853U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 17005063057791320948U) + aNonceWordO;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 18333780598768130670U;
            aOrbiterI = RotL64((aOrbiterI * 5416759844884107303U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 2056115016443263153U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 10245512728872962677U;
            aOrbiterE = RotL64((aOrbiterE * 707106795383284903U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 4810366069422162351U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 3051442983125942469U;
            aOrbiterH = RotL64((aOrbiterH * 13558537578054436423U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 9285068547223654308U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 13067251130180968842U;
            aOrbiterK = RotL64((aOrbiterK * 7000687697769766605U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 3203670242792002165U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 1770881716916463461U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13870229847371882171U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 16286823712870537410U) + aNonceWordP;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 13067191141829694202U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15629974528467350445U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 3414576315085336932U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 8979691827341555245U;
            aOrbiterG = RotL64((aOrbiterG * 15971594804040295757U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 11370607523115189596U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 1346943598249651668U;
            aOrbiterC = RotL64((aOrbiterC * 4994794423314630209U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 2441719135451272926U) + aNonceWordM;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 3347272129827184676U;
            aOrbiterJ = RotL64((aOrbiterJ * 10434510775894776597U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 1116857329130532047U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 2783898056762489197U;
            aOrbiterD = RotL64((aOrbiterD * 9504855173533274401U), 39U);
            //
            aIngress = RotL64(aOrbiterH, 43U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 34U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aIngress, 42U) + RotL64(aOrbiterH, 57U)) + aOrbiterE);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterH, 29U));
            aWandererK = aWandererK + (((RotL64(aScatter, 29U) + aOrbiterF) + RotL64(aOrbiterJ, 11U)) + RotL64(aCarry, 29U));
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 51U) + RotL64(aOrbiterD, 19U)) + aOrbiterH) + aNonceWordF) + aPhaseEWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 27U) + aOrbiterF) + RotL64(aOrbiterG, 3U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterC, 46U)) + aNonceWordJ);
            aWandererD = aWandererD + ((RotL64(aCross, 53U) + RotL64(aOrbiterG, 37U)) + aOrbiterJ);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterD, 35U));
            aWandererH = aWandererH + ((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 23U)) + aOrbiterH);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 60U) + RotL64(aOrbiterI, 21U)) + aOrbiterE) + aPhaseEWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterI, 48U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 14U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 26U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 24808U)) & S_BLOCK1], 29U) ^ RotL64(aSnowLaneB[((aIndex + 23125U)) & S_BLOCK1], 20U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 23973U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22238U)) & S_BLOCK1], 40U) ^ RotL64(aSnowLaneA[((aIndex + 25283U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 43U) ^ RotL64(aIngress, 30U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterC = ((aWandererB + RotL64(aScatter, 57U)) + 9774364261626083532U) + aNonceWordO;
            aOrbiterB = (aWandererA + RotL64(aCross, 43U)) + 18059001521926116420U;
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 11U)) + 10615626210406381148U) + aNonceWordJ;
            aOrbiterD = ((aWandererH + RotL64(aIngress, 54U)) + RotL64(aCarry, 57U)) + 10536484278007898620U;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 41U)) + 13320663045139972700U;
            aOrbiterG = ((aWandererE + RotL64(aCross, 23U)) + RotL64(aCarry, 51U)) + 17127001787268166583U;
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 47U)) + 16742574590844166551U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 41U)) + 8347719720758228053U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aPrevious, 14U)) + 13502468705946051986U;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 51U)) + 3512687886188904904U) + aNonceWordN;
            aOrbiterF = (aWandererD + RotL64(aScatter, 37U)) + 495660316165795934U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 5092722552034477356U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 15641128019608284015U;
            aOrbiterE = RotL64((aOrbiterE * 3621036395703527059U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 15421873776811085458U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 17978775513204574125U) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 18359600395119440183U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 16617179197537669849U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 1931805387534012528U;
            aOrbiterA = RotL64((aOrbiterA * 3400139345857733775U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 9544923119559308431U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 12930999400470173353U;
            aOrbiterD = RotL64((aOrbiterD * 16791006919271490005U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 13673733276226249890U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 2032263473309124738U;
            aOrbiterH = RotL64((aOrbiterH * 3088728329261360607U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 14868502349358414206U) + aNonceWordL;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 10116495537187552321U;
            aOrbiterC = RotL64((aOrbiterC * 1380512121796709469U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 5341113995358179244U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterI) ^ 8415417980279705731U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterK = RotL64((aOrbiterK * 8521501372683793821U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 2462819265072352463U) + aNonceWordF;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 7657062767608441931U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15554638801273540163U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 8153420530633265789U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 10990681417675210534U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1928509513380702895U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 17035995983178569271U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 2806563871848226777U;
            aOrbiterF = RotL64((aOrbiterF * 4137935663733587867U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 6570698907081812011U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 9774364261626083532U;
            aOrbiterB = RotL64((aOrbiterB * 1766375419340392741U), 29U);
            //
            aIngress = RotL64(aOrbiterB, 57U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterK, 41U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 4U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + RotL64(aOrbiterI, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterF, 13U)) + aOrbiterD);
            aWandererC = aWandererC + (((RotL64(aIngress, 29U) + aOrbiterI) + RotL64(aOrbiterB, 29U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 39U) + aOrbiterA) + RotL64(aOrbiterJ, 3U)) + aNonceWordA);
            aWandererE = aWandererE + ((RotL64(aPrevious, 60U) + aOrbiterI) + RotL64(aOrbiterK, 60U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterI, 39U)) + aOrbiterH) + aNonceWordM);
            aWandererI = aWandererI + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 47U)) + aOrbiterI) + RotL64(aCarry, 35U)) + aNonceWordC);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterD, 43U)) + aOrbiterA);
            aWandererG = aWandererG + (((RotL64(aPrevious, 22U) + RotL64(aOrbiterH, 50U)) + aOrbiterF) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterD, 23U)) + aOrbiterC);
            aWandererD = aWandererD + (((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterG, 57U)) + aPhaseEWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterE, 35U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererB, 54U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + RotL64(aWandererK, 13U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 31457U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneA[((aIndex + 27900U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 32585U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32411U)) & S_BLOCK1], 51U) ^ RotL64(aInvestLaneB[((aIndex + 32721U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 43U) ^ RotL64(aCross, 58U)) + (RotL64(aCarry, 29U) + RotL64(aIngress, 13U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterK = ((aWandererF + RotL64(aScatter, 5U)) + RotL64(aCarry, 37U)) + 6733949564325516029U;
            aOrbiterF = (aWandererG + RotL64(aCross, 23U)) + 7304098437143918796U;
            aOrbiterB = (aWandererK + RotL64(aPrevious, 3U)) + 3923949518391777800U;
            aOrbiterD = (aWandererE + RotL64(aIngress, 30U)) + 14243591003388927124U;
            aOrbiterE = (aWandererD + RotL64(aCross, 57U)) + 18329498724605410406U;
            aOrbiterH = (((aWandererB + RotL64(aPrevious, 41U)) + 13118172167747037249U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordL;
            aOrbiterJ = (aWandererH + RotL64(aIngress, 39U)) + 5272025143849174212U;
            aOrbiterI = (aWandererA + RotL64(aScatter, 21U)) + 16075917179214318424U;
            aOrbiterG = ((aWandererC + RotL64(aCross, 47U)) + RotL64(aCarry, 51U)) + 15263590648674658399U;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 18U)) + RotL64(aCarry, 29U)) + 13730046728289525921U;
            aOrbiterC = (((aWandererJ + RotL64(aPrevious, 51U)) + 7703141464499623408U) + aPhaseEOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1]) + aNonceWordM;
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 1382279753822135359U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 2973369221699098292U) ^ aNonceWordH;
            aOrbiterB = RotL64((aOrbiterB * 7440242040663550631U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 11578274119583013219U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterD) ^ 3419411247737896674U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 17814942652262802991U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 2582783513078999303U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 3959762790273529677U;
            aOrbiterJ = RotL64((aOrbiterJ * 383974377372162751U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 465795011576934604U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 17880826624185821135U) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 4445949147592860913U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 10819659185349413173U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 17298208553586835030U;
            aOrbiterA = RotL64((aOrbiterA * 1965860510614222093U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 12585880006661489402U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 16650193903267408586U;
            aOrbiterF = RotL64((aOrbiterF * 5781132589396936615U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 885882046325991589U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 869560078374809974U;
            aOrbiterG = RotL64((aOrbiterG * 13440973563438747181U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 11871305571797951851U) + aNonceWordF;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 12137095015607196226U;
            aOrbiterC = RotL64((aOrbiterC * 7618152256560808581U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 6044048326509186958U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 622564532811968856U;
            aOrbiterI = RotL64((aOrbiterI * 14988345089359014037U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 17133994029325040272U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 8612895899003926829U;
            aOrbiterE = RotL64((aOrbiterE * 2128664397481732179U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 2169081503433534750U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 6733949564325516029U;
            aOrbiterH = RotL64((aOrbiterH * 10062179904046311601U), 11U);
            //
            aIngress = RotL64(aOrbiterF, 48U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 37U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + RotL64(aOrbiterD, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aPrevious, 24U) + aOrbiterD) + RotL64(aOrbiterH, 10U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 21U) + aOrbiterD) + RotL64(aOrbiterG, 21U)) + aNonceWordP);
            aWandererD = aWandererD + (((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 5U)) + aOrbiterJ) + aNonceWordJ);
            aWandererC = aWandererC ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterH, 3U)) + aOrbiterB);
            aWandererG = aWandererG + (((RotL64(aScatter, 39U) + aOrbiterF) + RotL64(aOrbiterE, 39U)) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterI, 53U)) + aOrbiterE);
            aWandererK = aWandererK + ((RotL64(aPrevious, 37U) + aOrbiterI) + RotL64(aOrbiterA, 47U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 57U)) + aOrbiterK);
            aWandererJ = aWandererJ + (((RotL64(aCross, 13U) + RotL64(aOrbiterD, 24U)) + aOrbiterK) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 18U) + aOrbiterF) + RotL64(aOrbiterK, 37U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 43U)) + aOrbiterC) + aNonceWordK) + aPhaseEWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 18U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + RotL64(aWandererD, 58U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_Lacrosse_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xBF34BA1FD0A161A1ULL + 0xD8C12C09A23C9955ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xA974233B00500005ULL + 0x9BDEAC37F5F5CE46ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x81224936E20C9A4BULL + 0xC46374BBCAA68CBAULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x824AB0E440116729ULL + 0xDC59214FC349DEE7ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xD929E4C7E6BE5FAFULL + 0xBF6CED960A0702D0ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xAB69C78C0ABC816DULL + 0xDE1C4DB860E5965BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xDA4AB1DA4940D439ULL + 0xE7FB427A9EC2EE93ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x82890369CD822F5DULL + 0xA2B2C7707733F43EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x9BDE1B86F6B9EB41ULL + 0x8C6B0FE56783AA42ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xE51E080790AFA3C7ULL + 0xAF5D8DB259C81373ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xDD22DD6410665251ULL + 0xFA798EA505C58691ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xCBE6420095D44F5BULL + 0xFFEDA13E575E8DEDULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xD71BC6CA8E0DB59BULL + 0xDC638FCA6222D0AAULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xACE15E752710E8AFULL + 0xC793BF07F8A4ED16ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xC4C2310AE4D9012DULL + 0xB113472DFB3DA53EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x9B9C1B78A74F7A4BULL + 0x8134710BA365E17EULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 4890U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((aIndex + 2772U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 2385U)) & S_BLOCK1], 6U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3699U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 4323U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 4846U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 6U) ^ RotL64(aCarry, 57U)) + (RotL64(aPrevious, 43U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterI = ((aWandererI + RotL64(aScatter, 39U)) + RotL64(aCarry, 21U)) + 6469584119078165548U;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 53U)) + RotL64(aCarry, 3U)) + 14329756366517987910U;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 58U)) + RotL64(aCarry, 37U)) + 12890831797059772123U;
            aOrbiterE = ((aWandererH + RotL64(aCross, 35U)) + 3164503807500018990U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aIngress, 3U)) + 177531431387646836U;
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 27U)) + 3167421392893561015U) + aNonceWordJ;
            aOrbiterH = ((aWandererB + RotL64(aCross, 47U)) + 2813174781844753460U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = (aWandererA + RotL64(aPrevious, 10U)) + 10953270419153249857U;
            aOrbiterC = ((aWandererG + RotL64(aCross, 19U)) + 16911518309710356951U) + aNonceWordB;
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 6616750447844893150U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 10276741398025985982U;
            aOrbiterB = RotL64((aOrbiterB * 6824712685896987133U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 6206043608461213208U) + aNonceWordM;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 12021552904553405793U;
            aOrbiterK = RotL64((aOrbiterK * 10023362889960174909U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 15283586234744144846U) + aNonceWordO;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 5923238786775948571U;
            aOrbiterH = RotL64((aOrbiterH * 8200882393521882651U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 11044014510971660078U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 9351141024085076044U;
            aOrbiterG = RotL64((aOrbiterG * 13316079344614432317U), 53U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterC) + 17703395981862992420U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1]) + aNonceWordF;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 10154548848376027087U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12324478347590509035U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 8836420852291617425U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 10193385413543886344U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 824935982418585449U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 8248580084535685190U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 3910083671888152974U;
            aOrbiterF = RotL64((aOrbiterF * 17825311776715895927U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 12350341628569930642U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 2565977481575002842U;
            aOrbiterI = RotL64((aOrbiterI * 18233446879833776677U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 9271041067874027417U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 14289254596554201861U;
            aOrbiterD = RotL64((aOrbiterD * 7985522692852251413U), 19U);
            //
            aIngress = RotL64(aOrbiterF, 57U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterC, 27U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + (RotL64(aOrbiterI, 6U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 6U)) + aOrbiterD) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterC, 41U)) + aOrbiterG);
            aWandererG = aWandererG + ((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterI, 53U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterG, 57U)) + aNonceWordI);
            aWandererF = aWandererF + ((RotL64(aPrevious, 39U) + aOrbiterG) + RotL64(aOrbiterD, 19U));
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 56U) + RotL64(aOrbiterC, 35U)) + aOrbiterB) + aNonceWordH) + aPhaseFWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterD, 23U)) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterI, 10U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterG, 29U)) + aNonceWordE) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 60U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 7644U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneC[((aIndex + 9697U)) & S_BLOCK1], 12U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 9451U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneC[((aIndex + 8115U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 9282U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 9005U)) & S_BLOCK1], 30U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 8700U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCarry, 35U)) + (RotL64(aPrevious, 23U) + RotL64(aCross, 50U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterK = (aWandererH + RotL64(aPrevious, 30U)) + 5721224134332887360U;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 19U)) + 6892749729775049095U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = (((aWandererC + RotL64(aCross, 43U)) + RotL64(aCarry, 57U)) + 3884839462099556836U) + aNonceWordE;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 13U)) + RotL64(aCarry, 41U)) + 4365431706830216193U;
            aOrbiterF = (((aWandererB + RotL64(aIngress, 47U)) + RotL64(aCarry, 29U)) + 15501528746571578773U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = (aWandererF + RotL64(aPrevious, 35U)) + 4505911326320650606U;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 54U)) + 1865129050927879580U) + aNonceWordJ;
            aOrbiterH = (aWandererD + RotL64(aCross, 23U)) + 2011737665969640369U;
            aOrbiterI = (aWandererK + RotL64(aScatter, 39U)) + 611672935827062688U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 663547038310431047U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 5468932264754299556U) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 11968657455484578525U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 17920294117231191705U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 486058453837528110U;
            aOrbiterC = RotL64((aOrbiterC * 8851102552244026737U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 2789178451938129313U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 420772587981211184U;
            aOrbiterK = RotL64((aOrbiterK * 17402987842294006667U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 16196774774442181825U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 16264169656793713547U;
            aOrbiterF = RotL64((aOrbiterF * 6900221986041638783U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 10207659833859860796U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 8593749091183323678U;
            aOrbiterB = RotL64((aOrbiterB * 10696776033512404927U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 7224922076047787384U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 15366267474865172373U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10134187073321814217U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 4235342515820080294U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 5239480080426950612U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12077621553561927079U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 10891752830598395582U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 7797358829694471108U) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 7621206775460997431U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 3755715857903753416U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 3172069024987421726U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16048490837178650865U), 53U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterD, 57U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterJ, 6U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 6U)) + aOrbiterI) + aPhaseFWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterB, 57U)) + aOrbiterH);
            aWandererK = aWandererK + (((RotL64(aCross, 53U) + aOrbiterG) + RotL64(aOrbiterJ, 29U)) + aNonceWordA);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterH, 41U)) + aOrbiterI);
            aWandererA = aWandererA + (((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 19U)) + aOrbiterG) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 11U)) + aOrbiterJ);
            aWandererD = aWandererD + (((RotL64(aCross, 11U) + aOrbiterJ) + RotL64(aOrbiterK, 23U)) + aPhaseFWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 22U) + aOrbiterF) + RotL64(aOrbiterI, 35U)) + aNonceWordL);
            aWandererG = aWandererG + ((((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterD, 48U)) + RotL64(aCarry, 39U)) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + RotL64(aWandererD, 50U);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 15819U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((aIndex + 14759U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 12387U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 16382U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneC[((aIndex + 16189U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 19U)) ^ (RotL64(aIngress, 5U) + RotL64(aCross, 36U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterG = (aWandererH + RotL64(aScatter, 58U)) + 9080426856729228705U;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 47U)) + 7851218321653539276U) + aNonceWordO;
            aOrbiterJ = (((aWandererG + RotL64(aCross, 19U)) + RotL64(aCarry, 3U)) + 7023344692919298036U) + aPhaseFOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = (((aWandererI + RotL64(aPrevious, 43U)) + RotL64(aCarry, 21U)) + 9772846154227440734U) + aNonceWordE;
            aOrbiterE = (aWandererA + RotL64(aCross, 39U)) + 12008298632429608431U;
            aOrbiterA = (((aWandererB + RotL64(aScatter, 51U)) + RotL64(aCarry, 51U)) + 12201090455849562875U) + aNonceWordC;
            aOrbiterH = (aWandererD + RotL64(aIngress, 4U)) + 9498721803411445471U;
            aOrbiterF = (aWandererK + RotL64(aPrevious, 35U)) + 351203764023093632U;
            aOrbiterC = (((aWandererJ + RotL64(aIngress, 29U)) + 4966360430644539250U) + aPhaseFOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1]) + aNonceWordI;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 9194167899071345693U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 4922477697284269116U) ^ aNonceWordL;
            aOrbiterJ = RotL64((aOrbiterJ * 8444814161720407881U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 15742625291642356429U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 7528703106518431730U;
            aOrbiterE = RotL64((aOrbiterE * 11530049278751507567U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 15279053574704935317U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 2425839793660355555U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11486964816849830667U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 13209849392400008898U) + aNonceWordK;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 9041500097716231309U) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 340661035700748739U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 7885423750878814599U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 1992993999902904603U;
            aOrbiterD = RotL64((aOrbiterD * 1478629826632201617U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 6120758615019314102U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 8529621625846992066U;
            aOrbiterC = RotL64((aOrbiterC * 8485991471612862467U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 9125182130757385320U) + aNonceWordP;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 15691232622970220043U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16517916951054758147U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 11413090085435424697U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 11563151001080914939U;
            aOrbiterG = RotL64((aOrbiterG * 16828196274450408201U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 1778975369262558069U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 3232132443557192010U;
            aOrbiterF = RotL64((aOrbiterF * 17132823737792200981U), 57U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 41U);
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 60U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 29U) + aOrbiterD) + RotL64(aOrbiterC, 19U)) + aNonceWordJ);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterC, 23U)) + aOrbiterA) + RotL64(aCarry, 27U)) + aNonceWordH);
            aWandererG = aWandererG ^ (((RotL64(aCross, 14U) + RotL64(aOrbiterF, 47U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 39U) + aOrbiterB) + RotL64(aOrbiterH, 4U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 5U) + aOrbiterH) + RotL64(aOrbiterD, 13U));
            aWandererC = aWandererC + ((((RotL64(aCross, 47U) + RotL64(aOrbiterH, 41U)) + aOrbiterC) + aNonceWordF) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 23U) + aOrbiterH) + RotL64(aOrbiterE, 37U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 58U) + aOrbiterF) + RotL64(aOrbiterG, 58U)) + RotL64(aCarry, 5U)) + aNonceWordA);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 51U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + RotL64(aWandererI, 6U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 18713U)) & S_BLOCK1], 26U) ^ RotL64(aSnowLaneA[((aIndex + 21015U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 18281U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 17471U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 16762U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aPrevious, 4U)) ^ (RotL64(aIngress, 37U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterD = ((aWandererB + RotL64(aCross, 47U)) + 7632760812370906911U) + aNonceWordJ;
            aOrbiterA = (((aWandererJ + RotL64(aIngress, 34U)) + RotL64(aCarry, 19U)) + 6007174525479723089U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = (aWandererA + RotL64(aPrevious, 3U)) + 3362829642521821048U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 43U)) + 18009548556107978286U) + aNonceWordL;
            aOrbiterF = (aWandererE + RotL64(aCross, 19U)) + 17880909432272697327U;
            aOrbiterE = (((aWandererI + RotL64(aScatter, 38U)) + RotL64(aCarry, 41U)) + 15961567935420752568U) + aNonceWordD;
            aOrbiterK = (aWandererH + RotL64(aIngress, 53U)) + 10136559064656837921U;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 27U)) + RotL64(aCarry, 27U)) + 17622019364405410277U;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 11U)) + 6927494824421416306U) + aPhaseFOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 7125170407794874847U) + aNonceWordF;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 12342273503071032250U;
            aOrbiterB = RotL64((aOrbiterB * 867417849555857179U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 14997696377476124836U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 14874498694181230698U;
            aOrbiterF = RotL64((aOrbiterF * 4026127545746010937U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 2549397729130885686U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 4217995818662767955U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5525525344485251063U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 4706089044415442525U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterK) ^ 17983900172670031015U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 541552737180932879U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 1904937798143929988U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 10620877287033139483U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16711012562024287213U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 15681091173163181525U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 2655543246639000084U;
            aOrbiterD = RotL64((aOrbiterD * 16686375598149755947U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 2647895110857289213U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 5581609212017175954U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15330263616699031311U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 13609076329627787987U) + aNonceWordG;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 6244266279516622070U;
            aOrbiterH = RotL64((aOrbiterH * 12488345779236971095U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 5289624364508923581U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 16351476803965903112U) ^ aNonceWordK;
            aOrbiterA = RotL64((aOrbiterA * 9012522724650442597U), 51U);
            //
            aIngress = RotL64(aOrbiterD, 12U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 39U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterK, 42U)) + aOrbiterH) + aNonceWordN);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 46U) + RotL64(aOrbiterA, 47U)) + aOrbiterD) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterC, 57U));
            aWandererI = aWandererI + ((RotL64(aScatter, 29U) + aOrbiterF) + RotL64(aOrbiterA, 19U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterK, 35U)) + aOrbiterA);
            aWandererB = aWandererB + ((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 53U)) + aOrbiterE);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 41U) + aOrbiterG) + RotL64(aOrbiterC, 27U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 10U) + RotL64(aOrbiterC, 3U)) + aOrbiterB) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ ((((RotL64(aCross, 51U) + RotL64(aOrbiterA, 10U)) + aOrbiterH) + aNonceWordM) + aPhaseFWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 18U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 43U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 26219U)) & S_BLOCK1], 35U) ^ RotL64(aSnowLaneB[((aIndex + 24202U)) & S_BLOCK1], 26U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 22148U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26904U)) & S_BLOCK1], 23U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 27021U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 42U)) + (RotL64(aIngress, 11U) + RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 43U)) + 5906639480605353429U) + aNonceWordB;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 35U)) + RotL64(aCarry, 5U)) + 5293518570213287605U;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 47U)) + 15383185501428521377U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 39U)) + RotL64(aCarry, 35U)) + 15364072512743978902U;
            aOrbiterA = (aWandererE + RotL64(aScatter, 56U)) + 4525473357144014271U;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 5U)) + 10400911938125603074U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 29U)) + 16417506293824627550U) + aPhaseFOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = ((((aWandererD + RotL64(aIngress, 51U)) + RotL64(aCarry, 53U)) + 2419329331753341815U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordH;
            aOrbiterI = ((aWandererH + RotL64(aCross, 24U)) + 14929222427923332069U) + aNonceWordJ;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 16771573504983922586U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterD) ^ 1863466450051787622U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterC = RotL64((aOrbiterC * 2585626547126027053U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 12895350137096692415U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 3700979086526298327U;
            aOrbiterJ = RotL64((aOrbiterJ * 10279730254867618193U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 1977099106211282426U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 6144698304096915742U;
            aOrbiterH = RotL64((aOrbiterH * 5039822990560519609U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 3858895556659724975U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 1283646340363435327U;
            aOrbiterG = RotL64((aOrbiterG * 11622421841377018069U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 6240532051889108891U) + aNonceWordK;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 757364889381634634U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 943852137901972945U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 5272945693977418174U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 6850528198786172283U;
            aOrbiterD = RotL64((aOrbiterD * 1966383079897679953U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 14431587733859573714U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 16124590257870999553U;
            aOrbiterB = RotL64((aOrbiterB * 7755796211433191143U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 14912695018110241411U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 11098623474413346520U;
            aOrbiterI = RotL64((aOrbiterI * 15167688959990872051U), 47U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterH) + 3484847683376368686U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1]) + aNonceWordE;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 2295388097292719800U;
            aOrbiterA = RotL64((aOrbiterA * 1240808318176106909U), 43U);
            //
            aIngress = RotL64(aOrbiterJ, 41U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterH, 24U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 27U) + aOrbiterD) + RotL64(aOrbiterG, 10U)) + RotL64(aCarry, 3U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 56U) + RotL64(aOrbiterI, 43U)) + aOrbiterG) + aNonceWordL);
            aWandererE = aWandererE + (((RotL64(aScatter, 39U) + aOrbiterC) + RotL64(aOrbiterI, 5U)) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterJ, 21U)) + aOrbiterD) + aPhaseFWandererUpdateSaltD[((aIndex + 12U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterJ, 35U)) + aOrbiterC);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 21U) + aOrbiterB) + RotL64(aOrbiterG, 53U)) + aNonceWordM);
            aWandererA = aWandererA + ((RotL64(aIngress, 34U) + RotL64(aOrbiterA, 28U)) + aOrbiterF);
            aWandererH = aWandererH ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterF, 39U)) + aOrbiterH) + aNonceWordA);
            aWandererF = aWandererF + (((RotL64(aScatter, 47U) + aOrbiterC) + RotL64(aOrbiterF, 57U)) + aNonceWordI);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + RotL64(aWandererB, 60U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28155U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneA[((aIndex + 30180U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 29435U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28020U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30393U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCarry, 38U)) + (RotL64(aIngress, 5U) + RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterD = (aWandererK + RotL64(aScatter, 34U)) + 2101601659597850213U;
            aOrbiterB = (((aWandererG + RotL64(aIngress, 29U)) + RotL64(aCarry, 13U)) + 2759794072560720121U) + aNonceWordO;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 43U)) + 9443562552411269339U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = (((aWandererJ + RotL64(aCross, 39U)) + 10801360546699857975U) + aPhaseFOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1]) + aNonceWordG;
            aOrbiterC = (aWandererA + RotL64(aPrevious, 18U)) + 8020716394829332019U;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 11U)) + 1021894212367773801U;
            aOrbiterG = ((aWandererB + RotL64(aCross, 23U)) + RotL64(aCarry, 53U)) + 13346855534622490176U;
            aOrbiterK = (((aWandererC + RotL64(aScatter, 5U)) + RotL64(aCarry, 5U)) + 16359309548462953836U) + aNonceWordP;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 47U)) + 12642446944680783519U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 8197424982767553380U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 14346334610901859094U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16982899923227935679U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 14171304260534233539U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 334531601308283605U;
            aOrbiterC = RotL64((aOrbiterC * 5012968232749075075U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 10707856298471572695U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 18364775750091914766U;
            aOrbiterJ = RotL64((aOrbiterJ * 15735143943129143265U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 8531394793118363836U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 15352876929406908882U;
            aOrbiterF = RotL64((aOrbiterF * 475199047053777179U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 567682016232278157U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 2068146551757663119U;
            aOrbiterD = RotL64((aOrbiterD * 1557877740957797555U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 7776122587613256525U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 16430938890724272256U;
            aOrbiterG = RotL64((aOrbiterG * 4540270493783593257U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 11912000645055436094U) + aNonceWordA;
            aOrbiterA = (((aOrbiterA ^ aOrbiterF) ^ 16800749242578741498U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 17804584625034241737U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 5909199180260499150U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 5751089915336865588U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15376689503142397927U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 3478216857728853008U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 18007567146937338241U;
            aOrbiterK = RotL64((aOrbiterK * 6620498877303917855U), 53U);
            //
            aIngress = RotL64(aOrbiterI, 14U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 48U) + aOrbiterK) + RotL64(aOrbiterD, 14U)) + aNonceWordM);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterG, 3U));
            aWandererG = aWandererG + (((RotL64(aScatter, 41U) + RotL64(aOrbiterA, 23U)) + aOrbiterK) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 21U) + aOrbiterA) + RotL64(aOrbiterI, 29U)) + aPhaseFWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 11U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 12U) + aOrbiterB) + RotL64(aOrbiterK, 19U)) + aNonceWordJ);
            aWandererH = aWandererH + ((RotL64(aScatter, 53U) + aOrbiterF) + RotL64(aOrbiterC, 10U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterG, 57U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 51U)) + aOrbiterA) + aPhaseFWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 6U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void TwistExpander_Lacrosse_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x87539FA16852229DULL + 0xEFD994D943E32946ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xFE8A1734F0B0F2D7ULL + 0xB52F3E47DE49D7B2ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xD6098F3F013A9B75ULL + 0xF06BF26BA623FB4BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xBED75D998E59B629ULL + 0xCF0D538570CC51B0ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xF45A1652A414E68DULL + 0xA2BFB5EB21382A31ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xB13F7D4A414C31FDULL + 0xD23569423DA357F2ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xA63832B4D4C81FF1ULL + 0xDE8F4CBC4C10008FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xCF9E7325598F31E9ULL + 0xFA60AC319F3A8144ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x8135341658170B37ULL + 0x824E4E6461795E4AULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xB6B11B6BBC0B7E7FULL + 0xD552637D1628F9F8ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xD879EC4FFAC6F09BULL + 0xC92E922782FAAFE1ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x8E32F4768853A26BULL + 0xAE6EFB455B764B1CULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xE446058DADB2C661ULL + 0xC1265634A2753910ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xEB3DDE38E4762281ULL + 0xCA3182D3F476FF3DULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xF461B7681A640DBDULL + 0xDE77E8DA3432E339ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xCD12F1FA79652B53ULL + 0x83227C46FA9EADA1ULL);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 124U)) & S_BLOCK1], 5U) ^ RotL64(aSnowLaneB[((aIndex + 4300U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 4429U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 1175U)) & S_BLOCK1], 28U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 4334U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 2569U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCarry, 41U)) ^ (RotL64(aCross, 19U) + RotL64(aPrevious, 54U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterE = (aWandererH + RotL64(aPrevious, 29U)) + 4622023259121087483U;
            aOrbiterI = (((aWandererE + RotL64(aIngress, 19U)) + RotL64(aCarry, 3U)) + 10253505250223501352U) + aNonceWordB;
            aOrbiterF = (aWandererG + RotL64(aScatter, 57U)) + 17133877904420462669U;
            aOrbiterD = ((aWandererB + RotL64(aCross, 51U)) + 6162827793741796700U) + aPhaseHOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aIngress, 10U)) + 9610986424765907615U;
            aOrbiterK = (((aWandererD + RotL64(aCross, 3U)) + RotL64(aCarry, 35U)) + 11210747154264753754U) + aNonceWordD;
            aOrbiterH = ((((aWandererJ + RotL64(aPrevious, 39U)) + RotL64(aCarry, 53U)) + 16554205219580654546U) + aPhaseHOrbiterAssignSaltD[((aIndex + 26U)) & S_SALT1]) + aNonceWordL;
            //
            aOrbiterE = (((aOrbiterE + aOrbiterI) + 10352576357413766388U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordO;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 3651845783283479752U;
            aOrbiterF = RotL64((aOrbiterF * 1011289824180799641U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 18145542190463500476U) + aNonceWordK;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 5415609566767162857U) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 6474184559323816389U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 2033734872464201570U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 3507213117125813345U;
            aOrbiterH = RotL64((aOrbiterH * 5453058336688881113U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 8716253393049851856U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 695984869565941856U;
            aOrbiterK = RotL64((aOrbiterK * 8377921610764044735U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 7661578828878284931U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 906654265099155956U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8117625377607536949U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 6050049984731254612U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 17882717590338190821U;
            aOrbiterA = RotL64((aOrbiterA * 10807367411402733215U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 4996521991532815957U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterA) ^ 4246460672800604436U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterI = RotL64((aOrbiterI * 12047466401960824903U), 3U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 28U);
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterH, 47U)) + aOrbiterK) + aNonceWordA);
            aWandererE = aWandererE ^ (((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterH, 35U)) + aNonceWordM);
            aWandererI = aWandererI + (((RotL64(aIngress, 54U) + aOrbiterD) + RotL64(aOrbiterH, 28U)) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 21U)) + aOrbiterF) + aPhaseHWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 27U) + aOrbiterA) + RotL64(aOrbiterI, 41U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterI, 57U)) + aOrbiterE) + aNonceWordH);
            aWandererB = aWandererB + (((((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 53U)) + aNonceWordN) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 10U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 7458U)) & S_BLOCK1], 57U) ^ RotL64(aSnowLaneC[((aIndex + 6893U)) & S_BLOCK1], 48U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 9323U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneC[((aIndex + 7294U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 6003U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 9495U)) & S_BLOCK1], 54U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 9249U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 36U) ^ RotL64(aPrevious, 51U)) + (RotL64(aCross, 3U) ^ RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 57U)) + RotL64(aCarry, 13U)) + 8685374557928800912U;
            aOrbiterD = (((aWandererK + RotL64(aScatter, 13U)) + RotL64(aCarry, 51U)) + 3482312691892161229U) + aPhaseHOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aCross, 43U)) + 6948130297389161165U;
            aOrbiterK = ((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 35U)) + 5506385663788942690U;
            aOrbiterI = (((aWandererA + RotL64(aPrevious, 51U)) + 17859982009307397161U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordE;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 23U)) + 9178488809207094043U) + aNonceWordO;
            aOrbiterH = ((aWandererI + RotL64(aIngress, 36U)) + 1835479501226057169U) + aNonceWordK;
            //
            aOrbiterF = (((aOrbiterF + aOrbiterD) + 5368101733632614939U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterA = (((aOrbiterA ^ aOrbiterF) ^ 9050459666576835422U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterA = RotL64((aOrbiterA * 10351719549990259551U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 9042186993119635078U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 17528342580198295025U;
            aOrbiterI = RotL64((aOrbiterI * 14316671546614386775U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 6495418332558436882U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 8834495762667327342U;
            aOrbiterF = RotL64((aOrbiterF * 10783141541937645995U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 4364314196965690905U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 6357485231062120459U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 289429584586504995U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 3321488322626415347U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 10817330671781848737U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15875919466358823335U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 17974092279281611763U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 2871472057292789157U;
            aOrbiterK = RotL64((aOrbiterK * 16104199340711015181U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 15187929795092006849U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 13482063681546475923U;
            aOrbiterJ = RotL64((aOrbiterJ * 14466266308157364963U), 35U);
            //
            aIngress = RotL64(aOrbiterJ, 3U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterJ, 37U)) + aOrbiterH) + aNonceWordN);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 19U) + RotL64(aOrbiterJ, 4U)) + aOrbiterK) + RotL64(aCarry, 23U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterF, 13U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 35U) + aOrbiterA) + RotL64(aOrbiterD, 43U)) + aPhaseHWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 60U) + aOrbiterK) + RotL64(aOrbiterD, 51U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 27U)) + aOrbiterD) + RotL64(aCarry, 41U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 43U) + aOrbiterH) + RotL64(aOrbiterF, 57U)) + aNonceWordG);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 14U));
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererC, 53U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 15301U)) & S_BLOCK1], 46U) ^ RotL64(aSnowLaneA[((aIndex + 11774U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 12133U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15187U)) & S_BLOCK1], 13U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 11435U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCross, 57U)) ^ (RotL64(aCarry, 5U) + RotL64(aIngress, 42U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterG = ((aWandererH + RotL64(aIngress, 57U)) + RotL64(aCarry, 35U)) + 3248574644570178787U;
            aOrbiterD = (((aWandererG + RotL64(aPrevious, 5U)) + RotL64(aCarry, 57U)) + 4506961512959200024U) + aNonceWordF;
            aOrbiterF = ((aWandererI + RotL64(aCross, 48U)) + 8423739774540738590U) + aNonceWordP;
            aOrbiterK = ((aWandererB + RotL64(aScatter, 21U)) + RotL64(aCarry, 21U)) + 6593975869641735337U;
            aOrbiterE = (((aWandererC + RotL64(aIngress, 27U)) + 16441716090557369103U) + aPhaseHOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1]) + aNonceWordI;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 13U)) + 7936601450453207914U) + aNonceWordL;
            aOrbiterB = ((aWandererK + RotL64(aCross, 39U)) + 13333752583560167065U) + aPhaseHOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 8013703284795432973U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 2349852779887439236U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2422888500648100783U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 5318539364763284138U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 11450957608502944376U;
            aOrbiterJ = RotL64((aOrbiterJ * 1957880366707810635U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 9058992558327552687U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 632095686920230926U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12460364388358520799U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 14734218428913777098U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterD) ^ 16344357661370784442U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 15049472842002138369U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 2981145363531184308U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 14176472085175714494U;
            aOrbiterE = RotL64((aOrbiterE * 2584623327412130939U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 11198457590069700889U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 952584436750426828U;
            aOrbiterG = RotL64((aOrbiterG * 1165713888651280355U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 4311591763498985972U) + aNonceWordH;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 16194341833989936369U) ^ aNonceWordJ;
            aOrbiterK = RotL64((aOrbiterK * 9997934560195932575U), 13U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 36U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aPrevious, 37U) + aOrbiterF) + RotL64(aOrbiterD, 58U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterB, 51U));
            aWandererC = aWandererC + (((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 14U) + RotL64(aOrbiterE, 43U)) + aOrbiterK) + aPhaseHWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 23U) + aOrbiterF) + RotL64(aOrbiterJ, 37U)) + aNonceWordD);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterJ, 27U)) + aOrbiterK) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aIngress, 51U) + RotL64(aOrbiterK, 3U)) + aOrbiterB) + RotL64(aCarry, 57U)) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 18U));
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 51U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 16436U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneA[((aIndex + 21260U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 17646U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21144U)) & S_BLOCK1], 42U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 17511U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aIngress, 12U)) + (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterG = ((aWandererF + RotL64(aIngress, 11U)) + 2330952702412094686U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 21U)) + RotL64(aCarry, 23U)) + 7820188225935060799U;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 53U)) + 9347644591709839145U) + aNonceWordK;
            aOrbiterB = ((aWandererE + RotL64(aCross, 27U)) + 2288624878446846870U) + aPhaseHOrbiterAssignSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aScatter, 43U)) + RotL64(aCarry, 35U)) + 9358977729492824128U;
            aOrbiterA = (((aWandererA + RotL64(aCross, 60U)) + RotL64(aCarry, 51U)) + 1858511275052455039U) + aNonceWordM;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 5U)) + 13715478509322292552U) + aNonceWordB;
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 16413396625604260455U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 17714322215518432705U) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 1904184102419934333U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 16188315436202861122U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 5564445841368207813U;
            aOrbiterA = RotL64((aOrbiterA * 14125834616162835983U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 13717068949900594673U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 14143659432287313765U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17281441046722262917U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 5729546141908425670U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 4297827922736712074U;
            aOrbiterC = RotL64((aOrbiterC * 13631630436759768885U), 5U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterJ) + 829520109395163673U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1]) + aNonceWordA;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 11547160328525174295U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4759690159673049775U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 2907177944512117206U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 11100346409065275671U) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 17927994356809011637U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 1344592529249949068U) + aNonceWordI;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 6470438516791143572U;
            aOrbiterG = RotL64((aOrbiterG * 13339390828725370475U), 47U);
            //
            aIngress = RotL64(aOrbiterC, 57U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 35U)) + aOrbiterB) + aNonceWordG);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterC, 5U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 57U) + aOrbiterC) + RotL64(aOrbiterD, 12U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterG, 51U)) + aOrbiterA) + aPhaseHWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 19U) + RotL64(aOrbiterA, 57U)) + aOrbiterB) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 43U) + aOrbiterC) + RotL64(aOrbiterG, 43U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 26U) + RotL64(aOrbiterF, 27U)) + aOrbiterG) + RotL64(aCarry, 11U)) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 46U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 26983U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((aIndex + 27271U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 23050U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26590U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26398U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 41U)) + (RotL64(aIngress, 56U) ^ RotL64(aCross, 29U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 47U)) + 2571116506511057880U) + aNonceWordK;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 11U)) + RotL64(aCarry, 23U)) + 13112435411509707292U;
            aOrbiterG = (((aWandererF + RotL64(aCross, 57U)) + RotL64(aCarry, 47U)) + 10403251762787357256U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aIngress, 27U)) + RotL64(aCarry, 3U)) + 8461951095541400405U;
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 21U)) + 9890793478557463815U) + aPhaseHOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 34U)) + 3030229465991783707U) + aNonceWordH;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 5U)) + 7273848154043719247U) + aNonceWordD;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 10681774862516028276U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 7105082755586853104U;
            aOrbiterG = RotL64((aOrbiterG * 12217705329504230357U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 6588579345319551129U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 14616333550242386092U;
            aOrbiterI = RotL64((aOrbiterI * 2934574715879306337U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 15439666290229654921U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 3360304356760164799U;
            aOrbiterB = RotL64((aOrbiterB * 5164191920584106237U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 14438730801970761889U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 14515616787452085729U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2041601927968559821U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 4167853822635132419U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 8950982233003320239U) ^ aNonceWordJ;
            aOrbiterE = RotL64((aOrbiterE * 887144270884244907U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 12391327853728029953U) + aNonceWordL;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 7100871010552394421U;
            aOrbiterA = RotL64((aOrbiterA * 16552349374101955967U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 15381697462381887944U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 6801677551341079401U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13325954438427340703U), 5U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 41U);
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 58U));
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 11U) + aOrbiterJ) + RotL64(aOrbiterK, 57U)) + aNonceWordI);
            aWandererD = aWandererD + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 5U)) + aOrbiterG) + RotL64(aCarry, 27U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 58U) + aOrbiterA) + RotL64(aOrbiterJ, 27U));
            aWandererI = aWandererI + ((RotL64(aIngress, 3U) + RotL64(aOrbiterB, 36U)) + aOrbiterI);
            aWandererC = aWandererC ^ ((((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 19U)) + aOrbiterE) + aNonceWordN) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterK, 13U)) + aOrbiterG) + RotL64(aCarry, 13U)) + aNonceWordP);
            aWandererA = aWandererA ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterK, 43U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 44U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 29899U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((aIndex + 31975U)) & S_BLOCK1], 40U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 31651U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32680U)) & S_BLOCK1], 30U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 28226U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 35U)) + (RotL64(aCarry, 54U) ^ RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterB = (aWandererF + RotL64(aPrevious, 29U)) + 9435962834163239322U;
            aOrbiterJ = (((aWandererK + RotL64(aIngress, 39U)) + RotL64(aCarry, 51U)) + 10524704356081318973U) + aNonceWordN;
            aOrbiterE = ((aWandererE + RotL64(aCross, 19U)) + RotL64(aCarry, 11U)) + 7403401305665208680U;
            aOrbiterH = (aWandererB + RotL64(aScatter, 5U)) + 7525414805023556493U;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 47U)) + 1116686470029070951U) + aPhaseHOrbiterAssignSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = ((((aWandererJ + RotL64(aPrevious, 56U)) + RotL64(aCarry, 35U)) + 13257612299137802420U) + aPhaseHOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1]) + aNonceWordK;
            aOrbiterI = (aWandererH + RotL64(aScatter, 11U)) + 9181543003986598283U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9739384852307501107U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 11308402900229016057U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12690186771773188967U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 14935167593705272337U) + aNonceWordJ;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 7171824007631943535U;
            aOrbiterJ = RotL64((aOrbiterJ * 4839974427616194289U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 8068411284829563567U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 12350207458513447578U;
            aOrbiterH = RotL64((aOrbiterH * 813973258659041895U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 17039236343991574134U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 18291683592714999632U;
            aOrbiterI = RotL64((aOrbiterI * 7771718817924840713U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 6239616841884430968U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterI) ^ 10604527977569876774U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 6972820410084939637U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 1707724300671717658U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 3802268808625297647U;
            aOrbiterA = RotL64((aOrbiterA * 11296811630387191563U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 9423064323799920219U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 242153923313096551U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12117679073775630197U), 47U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterB, 11U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 50U));
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 21U) + aOrbiterJ) + RotL64(aOrbiterB, 3U));
            aWandererK = aWandererK + ((((RotL64(aCross, 41U) + aOrbiterD) + RotL64(aOrbiterE, 43U)) + RotL64(aCarry, 11U)) + aNonceWordP);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 60U)) + aOrbiterD);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterA, 23U)) + aNonceWordI);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 48U) + aOrbiterA) + RotL64(aOrbiterH, 11U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 37U)) + aOrbiterJ) + RotL64(aCarry, 29U)) + aNonceWordC);
            aWandererB = aWandererB ^ (((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterE, 53U)) + aPhaseHWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (RotL64(aWandererF, 28U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_Lacrosse_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB;
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
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF;
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
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC;
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 715U)) & W_KEY1], 24U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 1636U)) & W_KEY1], 57U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 1353U)) & W_KEY1], 46U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 323U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCarry, 23U)) + (RotL64(aCross, 37U) ^ RotL64(aPrevious, 50U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = ((aWandererD + RotL64(aCross, 34U)) + RotL64(aCarry, 23U)) + 9446153639709651566U;
            aOrbiterB = (aWandererH + RotL64(aScatter, 23U)) + 10550762260670758167U;
            aOrbiterF = (aWandererA + RotL64(aIngress, 39U)) + 7062634922142578383U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 5U)) + RotL64(aCarry, 47U)) + 9178499097812764515U;
            aOrbiterI = (aWandererB + RotL64(aCross, 57U)) + 6887103379773525538U;
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 43U)) + 6239750312052010257U;
            aOrbiterK = (((aWandererG + RotL64(aIngress, 10U)) + RotL64(aCarry, 35U)) + 17645022614523287959U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 51U)) + 3639618183259408272U) + aPhaseAOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aScatter, 47U)) + 3131737117548745095U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 7253994382396406554U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 15217993711938379561U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17853313384747259923U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 12594152227603630033U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 11250170200489647869U;
            aOrbiterJ = RotL64((aOrbiterJ * 546800378327864723U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 12936942656624279424U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 10990736056052106149U;
            aOrbiterA = RotL64((aOrbiterA * 7123916809953459187U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 12787293075893090465U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 17154990205620778151U;
            aOrbiterE = RotL64((aOrbiterE * 10031369940028159521U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 1270827262969060301U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 17337623431665013136U;
            aOrbiterK = RotL64((aOrbiterK * 1517262088236356107U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 830330490987911853U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 6828309232554560547U;
            aOrbiterD = RotL64((aOrbiterD * 9742464176986145819U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 11470087853413986203U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 10470148870747884420U;
            aOrbiterB = RotL64((aOrbiterB * 6766079738799967443U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 18315536891901859637U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 12264670822285914271U;
            aOrbiterI = RotL64((aOrbiterI * 5841574505408674119U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 10931842095884524879U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 11134871340959676257U;
            aOrbiterG = RotL64((aOrbiterG * 11714837622285605745U), 27U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 51U);
            aIngress = aIngress + (RotL64(aOrbiterI, 10U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterG, 14U)) + aOrbiterK);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 34U) + aOrbiterB) + RotL64(aOrbiterE, 51U));
            aWandererC = aWandererC + ((RotL64(aCross, 43U) + RotL64(aOrbiterB, 29U)) + aOrbiterI);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 39U) + aOrbiterD) + RotL64(aOrbiterJ, 5U)) + aPhaseAWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterA, 41U)) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterE, 19U));
            aWandererE = aWandererE + ((RotL64(aScatter, 27U) + RotL64(aOrbiterI, 37U)) + aOrbiterE);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterD, 23U)) + aOrbiterF) + aPhaseAWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 60U) + aOrbiterB) + RotL64(aOrbiterK, 58U)) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 26U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 4850U)) & S_BLOCK1], 52U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 2810U)) & W_KEY1], 13U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 5082U)) & W_KEY1], 22U) ^ RotL64(mSource[((aIndex + 3777U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 21U)) + (RotL64(aCross, 53U) + RotL64(aIngress, 36U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = (aWandererG + RotL64(aIngress, 23U)) + 5480870806135400132U;
            aOrbiterA = ((aWandererE + RotL64(aCross, 57U)) + RotL64(aCarry, 11U)) + 8034874599430768743U;
            aOrbiterC = (aWandererD + RotL64(aPrevious, 12U)) + 4006919843736863767U;
            aOrbiterH = (aWandererB + RotL64(aScatter, 43U)) + 2988069748674633718U;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 29U)) + 12347295651973135786U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 47U)) + RotL64(aCarry, 41U)) + 14152683894431568192U;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 53U)) + 15765143815254196598U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 51U)) + 10473067082331244233U;
            aOrbiterK = (aWandererC + RotL64(aIngress, 38U)) + 1089466925383677249U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 13215039929873682230U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 3957997712247961479U;
            aOrbiterC = RotL64((aOrbiterC * 7631186240013784703U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 10023907397941685546U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 14593012591254614353U;
            aOrbiterJ = RotL64((aOrbiterJ * 17111300092082154687U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 13353797968154036726U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 9259966668512102858U;
            aOrbiterF = RotL64((aOrbiterF * 8326732574268308221U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 10757861831070349321U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 10530223113483866178U;
            aOrbiterE = RotL64((aOrbiterE * 11269177745265396583U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 7554320926405521865U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 6978052067277966996U;
            aOrbiterG = RotL64((aOrbiterG * 18020134738536217801U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 1053695861967171420U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 15980734683539854451U;
            aOrbiterH = RotL64((aOrbiterH * 3208466640010555357U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 17041258393808061556U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 12846551858751995530U;
            aOrbiterD = RotL64((aOrbiterD * 9303891433380993639U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 14617434286683320666U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 3999309956180741302U;
            aOrbiterA = RotL64((aOrbiterA * 15037707937050015205U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 13452627760403094126U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 2633241575260427158U;
            aOrbiterK = RotL64((aOrbiterK * 2638570213290747581U), 51U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 43U);
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 37U));
            aIngress = aIngress + RotL64(aOrbiterJ, 26U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 37U)) + aOrbiterK) + aPhaseAWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 27U)) + aOrbiterK) + RotL64(aCarry, 39U)) + aPhaseAWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterK, 43U)) + aOrbiterE);
            aWandererH = aWandererH + ((RotL64(aCross, 47U) + RotL64(aOrbiterH, 19U)) + aOrbiterC);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 14U)) + aOrbiterC);
            aWandererB = aWandererB + (((RotL64(aPrevious, 5U) + aOrbiterC) + RotL64(aOrbiterA, 51U)) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterJ, 47U));
            aWandererI = aWandererI + ((RotL64(aIngress, 39U) + aOrbiterD) + RotL64(aOrbiterA, 23U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 10U) + RotL64(aOrbiterC, 6U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 60U));
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = RotL64(aFireLaneB[((aIndex + 6577U)) & S_BLOCK1], 40U) ^ RotL64(aKeyRowReadB[((aIndex + 5878U)) & W_KEY1], 11U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7679U)) & W_KEY1], 41U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 5662U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 6536U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 34U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 57U) + RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = (aWandererF + RotL64(aPrevious, 46U)) + 4179952823252098240U;
            aOrbiterI = (aWandererK + RotL64(aScatter, 23U)) + 3745613452332101749U;
            aOrbiterF = (aWandererD + RotL64(aCross, 41U)) + 2955689793395307176U;
            aOrbiterE = (aWandererI + RotL64(aIngress, 19U)) + 5639060180251322019U;
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 13U)) + RotL64(aCarry, 3U)) + 7901969163853586463U;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 29U)) + RotL64(aCarry, 27U)) + 2242166787816318119U;
            aOrbiterG = (((aWandererE + RotL64(aScatter, 56U)) + RotL64(aCarry, 11U)) + 5239936443960750064U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 35U)) + 13939136954732185558U) + aPhaseAOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = (aWandererC + RotL64(aIngress, 51U)) + 17058884136712717463U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 18148618660054585941U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 7022023484530327814U;
            aOrbiterF = RotL64((aOrbiterF * 650100011311048589U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 7722084537340095637U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 11764151879690934182U;
            aOrbiterA = RotL64((aOrbiterA * 12264384877711365655U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 16412785901758144708U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 9666718667728274824U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10865799822751771795U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 4307127540152109364U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 2457646804702647606U;
            aOrbiterG = RotL64((aOrbiterG * 6340030928007058595U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 3179394870088602208U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 504977947273774249U;
            aOrbiterC = RotL64((aOrbiterC * 16190282058883481551U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 16182729401018310837U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 7110817020445860609U;
            aOrbiterB = RotL64((aOrbiterB * 13371352088428584087U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 12960656706837391973U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 7103806893724395904U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14365984439655979791U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 1248300178080633527U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 7195473175424961337U;
            aOrbiterI = RotL64((aOrbiterI * 4633558992739305045U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 13007951568242991449U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 10296811247653636372U;
            aOrbiterH = RotL64((aOrbiterH * 16469682651380549395U), 35U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 21U);
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 50U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 34U) + aOrbiterA) + RotL64(aOrbiterB, 27U)) + aPhaseAWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 51U) + aOrbiterE) + RotL64(aOrbiterC, 4U));
            aWandererB = aWandererB + (((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 23U)) + aOrbiterH);
            aWandererK = aWandererK + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 37U)) + aOrbiterI);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 3U) + aOrbiterJ) + RotL64(aOrbiterE, 51U));
            aWandererG = aWandererG + (((RotL64(aCross, 43U) + RotL64(aOrbiterF, 44U)) + aOrbiterA) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 30U) + RotL64(aOrbiterA, 19U)) + aOrbiterE);
            aWandererF = aWandererF + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 57U)) + aOrbiterI) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + RotL64(aWandererK, 34U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 9121U)) & S_BLOCK1], 29U) ^ RotL64(aKeyRowReadB[((aIndex + 10332U)) & W_KEY1], 21U));
            aIngress ^= (RotL64(mSource[((aIndex + 8627U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneA[((aIndex + 8857U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 8609U)) & W_KEY1], 6U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 8333U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 22U) ^ RotL64(aCarry, 41U)) ^ (RotL64(aCross, 3U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 13U)) + 7948891781097675369U;
            aOrbiterD = (aWandererF + RotL64(aScatter, 39U)) + 13928362874228230226U;
            aOrbiterE = (((aWandererG + RotL64(aCross, 58U)) + RotL64(aCarry, 11U)) + 10776180542602258926U) + aPhaseBOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 47U)) + RotL64(aCarry, 27U)) + 5735115172149470447U;
            aOrbiterB = (aWandererH + RotL64(aPrevious, 35U)) + 5353591822981766987U;
            aOrbiterH = (aWandererA + RotL64(aCross, 19U)) + 562301708107268570U;
            aOrbiterC = (aWandererB + RotL64(aIngress, 5U)) + 10467810247578364868U;
            aOrbiterK = (aWandererI + RotL64(aScatter, 30U)) + 14541630141152308564U;
            aOrbiterI = (((aWandererD + RotL64(aPrevious, 43U)) + RotL64(aCarry, 3U)) + 2350076897065139429U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 17519109078651162228U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 6061035173339902910U;
            aOrbiterE = RotL64((aOrbiterE * 10021905773432907835U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 15654836633731000065U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 13723521735153718904U;
            aOrbiterB = RotL64((aOrbiterB * 14459516479283070563U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 2849680038315532197U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 17336102435576647923U;
            aOrbiterJ = RotL64((aOrbiterJ * 10984689101753586739U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 7671010488872356142U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 11485114338165600777U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4162584865462407791U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 8759060657343458985U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 11009137869375286581U;
            aOrbiterC = RotL64((aOrbiterC * 8741417343929809115U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 15792999392743144135U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 6180808423175992479U;
            aOrbiterA = RotL64((aOrbiterA * 13681230339693676907U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 361487389591183005U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 15292753806514404853U;
            aOrbiterI = RotL64((aOrbiterI * 17478232597253311153U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 14929153438443362045U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 7904556383593914086U;
            aOrbiterH = RotL64((aOrbiterH * 2484130486635511403U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 3793180909904286848U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 10391957637467171320U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 505484041943467117U), 47U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterH, 5U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 40U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterJ, 23U)) + aOrbiterH);
            aWandererC = aWandererC + (((RotL64(aPrevious, 19U) + aOrbiterA) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 56U) + aOrbiterD) + RotL64(aOrbiterH, 46U));
            aWandererG = aWandererG + (((RotL64(aCross, 11U) + RotL64(aOrbiterB, 29U)) + aOrbiterI) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 27U) + aOrbiterI) + RotL64(aOrbiterD, 11U)) + aPhaseBWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterC, 41U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 52U) + aOrbiterJ) + RotL64(aOrbiterC, 51U));
            aWandererB = aWandererB + (((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 60U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererI, 60U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 53U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 11950U)) & S_BLOCK1], 5U) ^ RotL64(aKeyRowReadA[((aIndex + 11920U)) & W_KEY1], 51U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 12560U)) & W_KEY1], 13U) ^ RotL64(mSource[((aIndex + 12950U)) & S_BLOCK1], 24U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 13110U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 12233U)) & S_BLOCK1], 37U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 11366U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aIngress, 53U)) + (RotL64(aPrevious, 18U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = ((aWandererG + RotL64(aScatter, 5U)) + 11410829607777684449U) + aPhaseBOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = (((aWandererI + RotL64(aCross, 46U)) + RotL64(aCarry, 11U)) + 7502698839700975347U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aIngress, 57U)) + RotL64(aCarry, 19U)) + 13267685058252106173U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 13U)) + RotL64(aCarry, 41U)) + 238242706996630625U;
            aOrbiterB = (aWandererA + RotL64(aScatter, 35U)) + 8184695499511454281U;
            aOrbiterD = (aWandererC + RotL64(aCross, 40U)) + 12767823220461985403U;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 23U)) + 12293198423143850330U;
            aOrbiterG = (aWandererJ + RotL64(aIngress, 51U)) + 11149495229952495939U;
            aOrbiterF = (aWandererH + RotL64(aScatter, 29U)) + 7556992689338382800U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 3431338808774134649U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 16863099140844995099U;
            aOrbiterK = RotL64((aOrbiterK * 752376661101787919U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 17872458049880677604U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 16760153457252546974U;
            aOrbiterD = RotL64((aOrbiterD * 11225037229069712805U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 3115544493537438408U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 4359882942759752958U;
            aOrbiterE = RotL64((aOrbiterE * 561477566995575801U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 13387113067202396536U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 12955690074544490161U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12449941770827974511U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 15614054443728226807U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 1939441328066616114U;
            aOrbiterG = RotL64((aOrbiterG * 4484917074808974359U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 4599016263007782537U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 9962305629016158048U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1496184427500037279U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 8428467674122750557U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 3938884087806393439U;
            aOrbiterH = RotL64((aOrbiterH * 12810531094050481761U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 6018636830758044658U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 1510372000641305416U;
            aOrbiterB = RotL64((aOrbiterB * 9002834928626918247U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 17592782466215337843U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 8119921507606870360U;
            aOrbiterF = RotL64((aOrbiterF * 1299795061644535485U), 53U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 27U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 39U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 21U));
            aIngress = aIngress + (RotL64(aOrbiterE, 34U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 13U)) + aOrbiterG) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterB, 28U));
            aWandererI = aWandererI + ((((RotL64(aCross, 47U) + aOrbiterG) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 47U)) + aPhaseBWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 47U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((RotL64(aCross, 28U) + RotL64(aOrbiterD, 51U)) + aOrbiterG);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 21U) + aOrbiterK) + RotL64(aOrbiterH, 24U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 43U)) + aOrbiterD);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 39U)) + aOrbiterG) + aPhaseBWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 60U) + RotL64(aOrbiterH, 35U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 10U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererG, 5U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 13740U)) & S_BLOCK1], 50U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 14811U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 13671U)) & W_KEY1], 54U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 13669U)) & W_KEY1], 11U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 15076U)) & S_BLOCK1], 37U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 14954U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 13960U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 37U) + RotL64(aIngress, 11U)) ^ (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 58U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = ((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 13U)) + 1297415699043177788U;
            aOrbiterA = (aWandererF + RotL64(aCross, 51U)) + 17583786534509260153U;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 23U)) + 643197858925708798U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 18U)) + RotL64(aCarry, 51U)) + 5062653766915694874U;
            aOrbiterI = (aWandererA + RotL64(aIngress, 39U)) + 7034273638367180511U;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 5U)) + 2026909726972916996U;
            aOrbiterK = ((aWandererB + RotL64(aCross, 43U)) + RotL64(aCarry, 5U)) + 2785690475553211646U;
            aOrbiterD = ((aWandererI + RotL64(aScatter, 30U)) + 2910341716302991892U) + aPhaseBOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aPrevious, 57U)) + 2834181605200829791U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 13323052600571281928U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 10434901530315760460U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2042210188346767033U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 247903955625194782U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 5196515747387257163U;
            aOrbiterC = RotL64((aOrbiterC * 1799024689023272275U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 7196305682377987476U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 14777739876892587484U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 95220583948241581U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 10609060796540136671U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 8386027207212484155U;
            aOrbiterI = RotL64((aOrbiterI * 4855610536246556893U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 729659744301903424U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 2350564261412606157U;
            aOrbiterB = RotL64((aOrbiterB * 16713856782349084977U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 16611987556673864177U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 1525195188708550503U;
            aOrbiterH = RotL64((aOrbiterH * 10045858602151004553U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 4654808490980989596U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 8189569777087686263U;
            aOrbiterK = RotL64((aOrbiterK * 17278657566389299577U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 10932857495004451792U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 1833880112534916813U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8004341577533825681U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 13100236350175516423U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 2773759534195186313U;
            aOrbiterE = RotL64((aOrbiterE * 3194954066097323161U), 47U);
            //
            aIngress = RotL64(aOrbiterG, 57U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterA, 50U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterB, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aIngress, 6U) + RotL64(aOrbiterA, 34U)) + aOrbiterC);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 43U) + aOrbiterB) + RotL64(aOrbiterH, 5U));
            aWandererD = aWandererD + ((((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterC, 47U)) + RotL64(aCarry, 21U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 51U) + aOrbiterI) + RotL64(aOrbiterC, 11U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 58U) + RotL64(aOrbiterE, 27U)) + aOrbiterG);
            aWandererK = aWandererK ^ ((RotL64(aCross, 27U) + aOrbiterK) + RotL64(aOrbiterE, 39U));
            aWandererA = aWandererA + (((RotL64(aScatter, 39U) + aOrbiterG) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 51U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterE, 23U)) + aOrbiterA);
            aWandererH = aWandererH + ((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterG, 52U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 26U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 16624U)) & S_BLOCK1], 23U) ^ RotL64(aKeyRowReadA[((aIndex + 17958U)) & W_KEY1], 51U));
            aIngress ^= (RotL64(mSource[((aIndex + 19090U)) & S_BLOCK1], 60U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 16780U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 16945U)) & W_KEY1], 47U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 17020U)) & S_BLOCK1], 22U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 18014U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 6U) + RotL64(aPrevious, 57U)) ^ (RotL64(aIngress, 27U) ^ RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = (aWandererG + RotL64(aCross, 60U)) + 13350544654542863236U;
            aOrbiterK = (((aWandererE + RotL64(aPrevious, 11U)) + RotL64(aCarry, 27U)) + 12364346790125404372U) + aPhaseCOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = (aWandererK + RotL64(aScatter, 47U)) + 9738750172849512764U;
            aOrbiterF = (aWandererI + RotL64(aIngress, 5U)) + 3781373837635491421U;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 35U)) + RotL64(aCarry, 3U)) + 16635020317512702337U;
            aOrbiterB = (aWandererC + RotL64(aIngress, 56U)) + 5383653921676231276U;
            aOrbiterD = (aWandererJ + RotL64(aCross, 41U)) + 10181959815492056493U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 29U)) + 10005510924273927017U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = ((aWandererF + RotL64(aCross, 21U)) + RotL64(aCarry, 43U)) + 9524687662265740565U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 4259138552009771014U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 8973051213213726023U;
            aOrbiterE = RotL64((aOrbiterE * 12625091476068190979U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 17602611840127337490U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 8218984546932905269U;
            aOrbiterA = RotL64((aOrbiterA * 17504305273683304231U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 18102186122213487888U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 2629927500298092976U;
            aOrbiterD = RotL64((aOrbiterD * 6983280164448292723U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 2491581597835795234U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 9506602492971620955U;
            aOrbiterB = RotL64((aOrbiterB * 9559829640915637163U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 13422942713680612924U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 15037354693234876601U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12692376075738621447U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 12896066842192894694U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 2202952306291905855U;
            aOrbiterI = RotL64((aOrbiterI * 6779368532763429997U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 12160313482450599313U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 10812986281270407756U;
            aOrbiterG = RotL64((aOrbiterG * 7786608700746771809U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 12474638293190144525U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 5882870951276225224U;
            aOrbiterF = RotL64((aOrbiterF * 15532427302173572457U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 3782896138051179209U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 10965680631059882311U;
            aOrbiterK = RotL64((aOrbiterK * 14060923998307082385U), 5U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterB, 57U);
            aIngress = aIngress + (RotL64(aOrbiterD, 40U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 56U) + aOrbiterE) + RotL64(aOrbiterI, 3U));
            aWandererC = aWandererC + (((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 18U)) + aOrbiterH) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterD, 53U));
            aWandererH = aWandererH + ((((RotL64(aCross, 23U) + RotL64(aOrbiterH, 43U)) + aOrbiterK) + RotL64(aCarry, 37U)) + aPhaseCWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 43U) + aOrbiterB) + RotL64(aOrbiterE, 13U));
            aWandererE = aWandererE + ((RotL64(aIngress, 39U) + RotL64(aOrbiterK, 23U)) + aOrbiterA);
            aWandererK = aWandererK ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterA, 39U)) + aOrbiterE);
            aWandererD = aWandererD + (((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterE, 35U)) + RotL64(aCarry, 57U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 18U) + RotL64(aOrbiterG, 30U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 60U));
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 19313U)) & S_BLOCK1], 57U) ^ RotL64(mSource[((aIndex + 21718U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aWorkLaneA[((aIndex + 20324U)) & S_BLOCK1], 28U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 21402U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 19272U)) & W_KEY1], 23U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 20101U)) & W_KEY1], 60U));
            aCross ^= (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20903U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 20808U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCross, 23U)) ^ (RotL64(aIngress, 11U) + RotL64(aCarry, 56U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (aWandererI + RotL64(aCross, 23U)) + 12426357877879529292U;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 37U)) + 12604900366173639176U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 30U)) + RotL64(aCarry, 11U)) + 13511119007338929401U;
            aOrbiterE = (aWandererA + RotL64(aPrevious, 57U)) + 9878720081166788060U;
            aOrbiterA = (((aWandererE + RotL64(aScatter, 47U)) + RotL64(aCarry, 43U)) + 15463195409806395076U) + aPhaseCOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aIngress, 53U)) + 6407922778852833423U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aPrevious, 11U)) + 7690427254160734016U;
            aOrbiterK = ((aWandererD + RotL64(aCross, 6U)) + RotL64(aCarry, 3U)) + 18030974031722143619U;
            aOrbiterH = (aWandererB + RotL64(aScatter, 41U)) + 17983938038322737041U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 16605512170117753884U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 681802273302348322U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14608920184802647123U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 15550312921312083819U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 17824154101711884508U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7358612830654795357U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 1939207786756735430U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 3132864634777826569U;
            aOrbiterF = RotL64((aOrbiterF * 13606281919426730325U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 12822929773923954849U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 16576106045887115660U;
            aOrbiterE = RotL64((aOrbiterE * 16370914370769903051U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 2398825881649235260U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 13700821892926092479U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10830623703416956043U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 2439833784883391606U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 15870638514107637833U;
            aOrbiterA = RotL64((aOrbiterA * 3797380922767479287U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 9165457123134229670U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 8736642509192659417U;
            aOrbiterK = RotL64((aOrbiterK * 16219277537523484065U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 9232719746484835693U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 7826680628853322541U;
            aOrbiterH = RotL64((aOrbiterH * 12578050118133526187U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 14323652326982518782U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 2254524512851399313U;
            aOrbiterD = RotL64((aOrbiterD * 4119339547645451149U), 35U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterD, 53U);
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 24U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aScatter, 18U) + RotL64(aOrbiterE, 23U)) + aOrbiterK);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterA, 19U)) + aPhaseCWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 23U) + aOrbiterA) + RotL64(aOrbiterC, 6U)) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterD, 13U)) + aOrbiterA) + aPhaseCWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 39U)) + aOrbiterJ);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterE, 53U));
            aWandererA = aWandererA + ((RotL64(aCross, 43U) + RotL64(aOrbiterE, 57U)) + aOrbiterB);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 58U) + RotL64(aOrbiterH, 30U)) + aOrbiterJ);
            aWandererD = aWandererD + (((RotL64(aScatter, 39U) + RotL64(aOrbiterF, 47U)) + aOrbiterH) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + (RotL64(aWandererJ, 26U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 22899U)) & S_BLOCK1], 60U) ^ RotL64(aKeyRowReadA[((aIndex + 22310U)) & W_KEY1], 37U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 23008U)) & W_KEY1], 11U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 22181U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 23792U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22082U)) & S_BLOCK1], 47U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 24473U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneD[((aIndex + 22197U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 26U) + RotL64(aCross, 41U)) ^ (RotL64(aPrevious, 3U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (((aWandererA + RotL64(aCross, 47U)) + RotL64(aCarry, 53U)) + 8866844335448071821U) + aPhaseCOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = (aWandererG + RotL64(aPrevious, 3U)) + 15159698739856430085U;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 53U)) + RotL64(aCarry, 37U)) + 9582805772989594633U;
            aOrbiterG = (aWandererK + RotL64(aScatter, 57U)) + 1438538239931588373U;
            aOrbiterF = (aWandererH + RotL64(aPrevious, 34U)) + 10862044156620436139U;
            aOrbiterK = (aWandererB + RotL64(aIngress, 27U)) + 13682173320058164615U;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 11U)) + RotL64(aCarry, 29U)) + 8351013291045977592U;
            aOrbiterH = (aWandererI + RotL64(aCross, 39U)) + 15777857431516633916U;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 20U)) + 16178966745333885377U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 9031889187993001617U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 6308472367425865347U;
            aOrbiterB = RotL64((aOrbiterB * 17118710301967158153U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 642109145903321046U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 9186268569255318035U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10714674348507516749U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 6091345356803675860U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 13218507921880873749U;
            aOrbiterF = RotL64((aOrbiterF * 15415157927185637717U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 4266652275234474616U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 4391422098164506195U;
            aOrbiterE = RotL64((aOrbiterE * 17634679403195085867U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 5160682323243635577U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 10351728852161347404U;
            aOrbiterJ = RotL64((aOrbiterJ * 11105410036471745951U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 3950932176454814023U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 9536466386833427441U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 18064984243491293435U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 9927425919978776529U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 6819384090527481081U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 18032965969184368561U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 1646274931424218507U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 16166524473976135097U;
            aOrbiterD = RotL64((aOrbiterD * 11672192658072663849U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 11252501968059485262U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 16847854447987609067U;
            aOrbiterH = RotL64((aOrbiterH * 6326299154627028295U), 57U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 57U);
            aIngress = aIngress + (RotL64(aOrbiterB, 11U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterK, 22U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 27U) + aOrbiterI) + RotL64(aOrbiterG, 43U));
            aWandererK = aWandererK + (((RotL64(aIngress, 51U) + RotL64(aOrbiterE, 13U)) + aOrbiterK) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 6U) + RotL64(aOrbiterD, 5U)) + aOrbiterI);
            aWandererG = aWandererG + ((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterB, 38U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterF, 47U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 57U)) + aOrbiterB);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 56U) + RotL64(aOrbiterK, 29U)) + aOrbiterI);
            aWandererH = aWandererH + (((RotL64(aPrevious, 39U) + aOrbiterF) + RotL64(aOrbiterJ, 52U)) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 23U)) + aOrbiterE) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 58U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 43U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 26939U)) & S_BLOCK1], 53U) ^ RotL64(aKeyRowReadA[((aIndex + 27071U)) & W_KEY1], 6U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 25860U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26754U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 25270U)) & W_KEY1], 13U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 25633U)) & S_BLOCK1], 56U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 25203U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneD[((aIndex + 26161U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 54U) + RotL64(aCross, 37U)) + (RotL64(aIngress, 23U) ^ RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = ((aWandererD + RotL64(aIngress, 21U)) + 17081642665820489793U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aScatter, 47U)) + RotL64(aCarry, 19U)) + 14468854040067229623U;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 5U)) + 2249450222593057429U;
            aOrbiterJ = (aWandererI + RotL64(aCross, 57U)) + 14964389079511378664U;
            aOrbiterB = (aWandererC + RotL64(aIngress, 26U)) + 17003491054252360650U;
            aOrbiterE = ((aWandererH + RotL64(aCross, 11U)) + 12710882240582032588U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aScatter, 53U)) + 9887078182156755359U;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 35U)) + RotL64(aCarry, 35U)) + 7665284531810584704U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 42U)) + RotL64(aCarry, 43U)) + 7304284015511876717U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 5517927023543751734U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 17704756310857362759U;
            aOrbiterC = RotL64((aOrbiterC * 15826832172923213591U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 11347400363019508578U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 11696395232760991243U;
            aOrbiterG = RotL64((aOrbiterG * 9725231749679442003U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 10875780291242873583U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 7808740614343437672U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8889516201913716283U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 3145390996141902032U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 16080636485642732615U;
            aOrbiterE = RotL64((aOrbiterE * 7445756373012217305U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 3929263288176983844U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 18210228766683996806U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13178080076505449091U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 13948962323541421431U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 3037683309790156893U;
            aOrbiterJ = RotL64((aOrbiterJ * 13406672352222636739U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 17827265198532699474U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 7270895262023504864U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13467417362477308167U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 6431243064980879185U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 6680205390976259885U;
            aOrbiterD = RotL64((aOrbiterD * 10421386694108590789U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 15910655919164357152U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 8046213498216027383U;
            aOrbiterA = RotL64((aOrbiterA * 18061867495824063553U), 35U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterC, 47U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 42U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + RotL64(aOrbiterD, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterH, 35U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 28U)) + aOrbiterF) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterA, 19U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 23U)) + aOrbiterA);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 34U) + aOrbiterC) + RotL64(aOrbiterE, 51U));
            aWandererC = aWandererC + (((RotL64(aIngress, 39U) + aOrbiterH) + RotL64(aOrbiterE, 39U)) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 11U)) + aOrbiterH);
            aWandererH = aWandererH + (((RotL64(aCross, 47U) + RotL64(aOrbiterH, 56U)) + aOrbiterG) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 18U) + aOrbiterF) + RotL64(aOrbiterA, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererA, 50U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 28732U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneD[((aIndex + 27586U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 28348U)) & W_KEY1], 57U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 28897U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 29875U)) & W_KEY1], 5U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28553U)) & S_BLOCK1], 37U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28803U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneB[((aIndex + 28484U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 29U) ^ RotL64(aCarry, 54U)) ^ (RotL64(aPrevious, 11U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = (aWandererA + RotL64(aIngress, 29U)) + 8988572360732005217U;
            aOrbiterA = (((aWandererK + RotL64(aPrevious, 12U)) + RotL64(aCarry, 3U)) + 17889613225105985335U) + aPhaseDOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aScatter, 53U)) + 15563478320513948626U;
            aOrbiterG = (aWandererF + RotL64(aCross, 19U)) + 3441351228410524816U;
            aOrbiterE = ((aWandererH + RotL64(aScatter, 57U)) + RotL64(aCarry, 35U)) + 4425592689451435346U;
            aOrbiterK = (aWandererG + RotL64(aCross, 47U)) + 12733160231627305928U;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 40U)) + RotL64(aCarry, 19U)) + 3574152157304607854U;
            aOrbiterF = (aWandererE + RotL64(aPrevious, 3U)) + 15167631896729808783U;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 35U)) + 15822667973915417055U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 17181685481076577637U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 9979204751408873468U;
            aOrbiterJ = RotL64((aOrbiterJ * 8244434774754786565U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 1334240485667164762U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 9190066751460137016U;
            aOrbiterK = RotL64((aOrbiterK * 14585141844653660363U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 15465215829109246336U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 2305208282453624419U;
            aOrbiterE = RotL64((aOrbiterE * 10257861974108363283U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 16951510027310993926U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 11117938943423526901U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7805486716716924787U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 12461379120662979432U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 11719697049048823897U;
            aOrbiterG = RotL64((aOrbiterG * 14880996802304818757U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 6843357278142933570U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 12727898578324702374U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9786435451654365097U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 18127999660067652233U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 11754709060558683082U;
            aOrbiterH = RotL64((aOrbiterH * 12798744012150745847U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 16940151146420516184U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 12924950783056761895U;
            aOrbiterF = RotL64((aOrbiterF * 8898170377271926745U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 14829713915929878471U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 840466047621042565U;
            aOrbiterB = RotL64((aOrbiterB * 10748511630509529489U), 19U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 48U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + RotL64(aOrbiterJ, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aIngress, 37U) + aOrbiterK) + RotL64(aOrbiterG, 35U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 4U) + aOrbiterE) + RotL64(aOrbiterH, 13U));
            aWandererA = aWandererA + ((RotL64(aScatter, 27U) + aOrbiterA) + RotL64(aOrbiterB, 47U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterG, 60U)) + aOrbiterJ);
            aWandererF = aWandererF + ((((RotL64(aIngress, 41U) + aOrbiterA) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 5U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 21U) + aOrbiterC) + RotL64(aOrbiterJ, 5U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterH, 19U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 51U) + aOrbiterA) + RotL64(aOrbiterG, 53U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 58U) + RotL64(aOrbiterC, 40U)) + aOrbiterE) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 6U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 31170U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 31586U)) & W_KEY1], 14U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 32335U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32066U)) & S_BLOCK1], 27U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31113U)) & S_BLOCK1], 35U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 32722U)) & W_KEY1], 54U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 37U) ^ RotL64(aCross, 19U)) + (RotL64(aIngress, 52U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = (aWandererF + RotL64(aPrevious, 21U)) + 9471546960258473684U;
            aOrbiterJ = (((aWandererD + RotL64(aIngress, 52U)) + RotL64(aCarry, 53U)) + 18050235435948942244U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = ((aWandererH + RotL64(aScatter, 47U)) + RotL64(aCarry, 21U)) + 3005107102671544641U;
            aOrbiterG = (aWandererG + RotL64(aCross, 13U)) + 17898396434573801850U;
            aOrbiterI = (aWandererI + RotL64(aIngress, 39U)) + 15071602525497771648U;
            aOrbiterH = (aWandererJ + RotL64(aScatter, 26U)) + 5780119462702672108U;
            aOrbiterD = (aWandererB + RotL64(aPrevious, 3U)) + 13301326224151025687U;
            aOrbiterK = (((aWandererK + RotL64(aCross, 35U)) + RotL64(aCarry, 13U)) + 18129323022260575961U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = (aWandererE + RotL64(aIngress, 43U)) + 1199228670638790709U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 1839199978088021020U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 4999517042246790165U;
            aOrbiterF = RotL64((aOrbiterF * 4585813675677234577U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 8788607633376516299U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 15143903839930468749U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12735914889325422675U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 16674732686428431869U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 15908873150953195581U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 18049755517524334107U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 11204775359756474667U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 2525984309543939465U;
            aOrbiterK = RotL64((aOrbiterK * 3988529812023791571U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 4566345170476825512U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 14876612901557406267U;
            aOrbiterD = RotL64((aOrbiterD * 9047956948845135339U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 14926290877038883931U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 12710203178186614846U;
            aOrbiterB = RotL64((aOrbiterB * 14841163494801662515U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 7315094513967387996U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 11050116830482816766U;
            aOrbiterG = RotL64((aOrbiterG * 3702999495721152019U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 4505368486032503953U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 17905748055257551092U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14775870175093453197U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 5728886950801376350U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 17998141690182325170U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16008599930125391379U), 53U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 39U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + (RotL64(aOrbiterF, 10U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + RotL64(aOrbiterD, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 39U)) + aOrbiterH) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 39U) + aOrbiterG) + RotL64(aOrbiterD, 6U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 18U) + aOrbiterJ) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterF, 47U));
            aWandererG = aWandererG + ((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 35U)) + aOrbiterH);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterE, 11U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 60U)) + aOrbiterB);
            aWandererF = aWandererF ^ (((RotL64(aCross, 58U) + RotL64(aOrbiterF, 53U)) + aOrbiterB) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 23U) + RotL64(aOrbiterF, 19U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 38U));
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 35U);
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

void TwistExpander_Lacrosse_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterE = 0;
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 1444U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneB[((aIndex + 1020U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 2270U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3059U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 1161U)) & S_BLOCK1], 54U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 7766U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 56U) + RotL64(aIngress, 21U)) ^ (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (((aWandererG + RotL64(aPrevious, 27U)) + RotL64(aCarry, 3U)) + 16183871922837164759U) + aPhaseEOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aIngress, 10U)) + 7002058258090219055U;
            aOrbiterI = ((aWandererF + RotL64(aCross, 47U)) + RotL64(aCarry, 23U)) + 5650868611888303705U;
            aOrbiterK = ((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 47U)) + 11899839660943876690U;
            aOrbiterC = (aWandererB + RotL64(aCross, 37U)) + 15349649504488111111U;
            aOrbiterA = (aWandererE + RotL64(aScatter, 21U)) + 14060149569086744970U;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 53U)) + 12920917574225030112U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 2831994965175330135U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 18312543585028439192U;
            aOrbiterI = RotL64((aOrbiterI * 11618182708195744321U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 11657562205118394239U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 10850792819281246052U;
            aOrbiterC = RotL64((aOrbiterC * 10663100544207879337U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 17810371216216125323U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 7963413941144223128U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 534217972450595401U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 5498715358793875584U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 9256727548911651373U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10498848323914000989U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 17246360111302191699U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 18309978718113983369U;
            aOrbiterA = RotL64((aOrbiterA * 18267472694666221077U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 3100998994319502921U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 8129301860291235970U;
            aOrbiterG = RotL64((aOrbiterG * 17847033539279176187U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 1889641029473279114U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 16538494307002917945U;
            aOrbiterE = RotL64((aOrbiterE * 8081488217920885783U), 11U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 5U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 39U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + RotL64(aOrbiterA, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 58U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 22U) + aOrbiterK) + RotL64(aOrbiterH, 21U));
            aWandererI = aWandererI + ((((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 35U)) + aPhaseEWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 27U)) + aOrbiterI);
            aWandererB = aWandererB + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 41U)) + aOrbiterI);
            aWandererE = aWandererE ^ (((RotL64(aCross, 41U) + aOrbiterE) + RotL64(aOrbiterI, 3U)) + aPhaseEWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 3U) + RotL64(aOrbiterA, 11U)) + aOrbiterC) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 22U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + RotL64(aWandererJ, 39U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 15055U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((aIndex + 10199U)) & S_BLOCK1], 39U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 11820U)) & S_BLOCK1], 14U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 13991U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 14116U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 11757U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 12711U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 37U)) ^ (RotL64(aIngress, 6U) ^ RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = (aWandererH + RotL64(aScatter, 19U)) + 1297415699043177788U;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 41U)) + 17583786534509260153U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (aWandererI + RotL64(aCross, 48U)) + 643197858925708798U;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 27U)) + RotL64(aCarry, 11U)) + 5062653766915694874U;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 57U)) + RotL64(aCarry, 41U)) + 7034273638367180511U;
            aOrbiterK = (aWandererG + RotL64(aCross, 3U)) + 2026909726972916996U;
            aOrbiterC = (((aWandererF + RotL64(aIngress, 35U)) + RotL64(aCarry, 23U)) + 2785690475553211646U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 2910341716302991892U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 2834181605200829791U;
            aOrbiterE = RotL64((aOrbiterE * 1510617068750957651U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 13323052600571281928U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 10434901530315760460U;
            aOrbiterG = RotL64((aOrbiterG * 2042210188346767033U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 247903955625194782U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 5196515747387257163U;
            aOrbiterH = RotL64((aOrbiterH * 1799024689023272275U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 7196305682377987476U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 14777739876892587484U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 95220583948241581U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 10609060796540136671U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 8386027207212484155U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4855610536246556893U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 729659744301903424U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 2350564261412606157U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16713856782349084977U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 16611987556673864177U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 1525195188708550503U;
            aOrbiterF = RotL64((aOrbiterF * 10045858602151004553U), 37U);
            //
            aIngress = RotL64(aOrbiterF, 37U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterH, 23U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aCross, 4U) + RotL64(aOrbiterF, 3U)) + aOrbiterB);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterH, 13U)) + aOrbiterB);
            aWandererC = aWandererC + (((RotL64(aIngress, 21U) + aOrbiterE) + RotL64(aOrbiterF, 37U)) + aPhaseEWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 57U) + aOrbiterG) + RotL64(aOrbiterH, 44U));
            aWandererA = aWandererA + (((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 23U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterH, 21U)) + aOrbiterE);
            aWandererI = aWandererI + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 53U)) + aOrbiterK) + RotL64(aCarry, 53U)) + aPhaseEWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 30U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 10U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 20638U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((aIndex + 17898U)) & S_BLOCK1], 53U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 23633U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((aIndex + 17863U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18220U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 23286U)) & S_BLOCK1], 48U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17710U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 4U) ^ RotL64(aPrevious, 47U)) ^ (RotL64(aIngress, 19U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (aWandererG + RotL64(aIngress, 39U)) + 3621877681473089725U;
            aOrbiterE = (((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 53U)) + 4451752751536414717U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aCross, 47U)) + 11371625415377772117U;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 53U)) + RotL64(aCarry, 23U)) + 6046792758881150619U;
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 60U)) + 8213166120394461682U) + aPhaseEOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = ((aWandererD + RotL64(aCross, 19U)) + RotL64(aCarry, 3U)) + 4343156661140422645U;
            aOrbiterF = (aWandererF + RotL64(aIngress, 11U)) + 11105271483234947905U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 348904609985341372U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 12924652822526858767U;
            aOrbiterI = RotL64((aOrbiterI * 2801892489296408735U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 7461211697358520287U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 16551553555297890558U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16432952324635746293U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 11908056404140782995U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 9147367258259948715U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10777628928376261667U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 8876461054692728610U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 10546855952702525404U;
            aOrbiterF = RotL64((aOrbiterF * 10071104785895309677U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 4748636139110443794U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 783046909529525098U;
            aOrbiterE = RotL64((aOrbiterE * 8969157702460927215U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 16683965945838696665U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 12385412690177109575U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10795062772707143187U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 8210546822184469023U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 13146493623236979963U;
            aOrbiterH = RotL64((aOrbiterH * 13199947810161148155U), 11U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterH, 58U);
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + RotL64(aOrbiterK, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 13U) + aOrbiterI) + RotL64(aOrbiterH, 3U));
            aWandererD = aWandererD + ((((RotL64(aCross, 21U) + aOrbiterJ) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 41U)) + aPhaseEWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 21U)) + aOrbiterH);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterG, 35U)) + aOrbiterK) + RotL64(aCarry, 23U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 42U) + RotL64(aOrbiterI, 41U)) + aOrbiterE);
            aWandererG = aWandererG + ((RotL64(aCross, 35U) + RotL64(aOrbiterH, 13U)) + aOrbiterE);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 58U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 34U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 24944U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneA[((aIndex + 29445U)) & S_BLOCK1], 27U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 32664U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 28789U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24685U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26224U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 24954U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 35U)) ^ (RotL64(aPrevious, 47U) + RotL64(aCross, 18U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = (aWandererA + RotL64(aPrevious, 11U)) + 10726035965553989335U;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 47U)) + RotL64(aCarry, 39U)) + 967354339530195662U;
            aOrbiterJ = (aWandererG + RotL64(aIngress, 60U)) + 10834593005478605624U;
            aOrbiterG = ((aWandererH + RotL64(aCross, 37U)) + RotL64(aCarry, 53U)) + 1012888282838656933U;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 53U)) + RotL64(aCarry, 19U)) + 15283530351725183253U;
            aOrbiterI = ((aWandererK + RotL64(aCross, 3U)) + 11724495956731703750U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 27U)) + 4288330117317505776U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 10894778070022873473U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 15563886747621617467U;
            aOrbiterJ = RotL64((aOrbiterJ * 17884709931569040065U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 11182488628562891937U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 10420140066310588580U;
            aOrbiterI = RotL64((aOrbiterI * 13898299782819948719U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 11775138062167543111U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 16545391898578161683U;
            aOrbiterB = RotL64((aOrbiterB * 14588306527161321535U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 1550144656312299266U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 14903504853138279883U;
            aOrbiterF = RotL64((aOrbiterF * 8003033561266164387U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 309935535526750396U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 13991265868040011411U;
            aOrbiterH = RotL64((aOrbiterH * 2887531132228588441U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 1755976294857114222U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 2259275858478396846U;
            aOrbiterC = RotL64((aOrbiterC * 7416165760067878161U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 4838175912944552936U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 12307900457200936013U;
            aOrbiterG = RotL64((aOrbiterG * 14719363144850838805U), 35U);
            //
            aIngress = RotL64(aOrbiterC, 57U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterF, 51U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterB, 47U));
            aWandererG = aWandererG + (((RotL64(aCross, 56U) + aOrbiterJ) + RotL64(aOrbiterH, 21U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 41U) + aOrbiterG) + RotL64(aOrbiterC, 3U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterI, 27U)) + aOrbiterJ) + RotL64(aCarry, 29U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 35U) + aOrbiterB) + RotL64(aOrbiterG, 56U)) + aPhaseEWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 27U) + RotL64(aOrbiterC, 11U)) + aOrbiterF) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterB, 39U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 46U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererC, 11U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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

void TwistExpander_Lacrosse_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 270U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((aIndex + 5480U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 5267U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 269U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 299U)) & S_BLOCK1], 24U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 7270U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCross, 57U)) ^ (RotL64(aIngress, 6U) ^ RotL64(aCarry, 29U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = (aWandererJ + RotL64(aIngress, 52U)) + 4848316479321533394U;
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 21U)) + RotL64(aCarry, 39U)) + 6919360256662636195U;
            aOrbiterH = (aWandererK + RotL64(aCross, 13U)) + 9897013582181108544U;
            aOrbiterE = (((aWandererG + RotL64(aScatter, 19U)) + RotL64(aCarry, 19U)) + 7319353809896158678U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aIngress, 41U)) + RotL64(aCarry, 43U)) + 2848175435514849859U;
            aOrbiterI = (aWandererF + RotL64(aPrevious, 5U)) + 6967780718720437934U;
            aOrbiterG = (aWandererC + RotL64(aScatter, 11U)) + 10143884766603388136U;
            aOrbiterF = ((aWandererE + RotL64(aCross, 27U)) + 8675965006150972051U) + aPhaseFOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aPrevious, 23U)) + 16350117755560994281U;
            aOrbiterK = (aWandererH + RotL64(aCross, 34U)) + 17976597517118423760U;
            aOrbiterD = (aWandererI + RotL64(aScatter, 37U)) + 1399631141355370237U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 3590613762034716792U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 5134624314245932157U;
            aOrbiterH = RotL64((aOrbiterH * 13077589037975283371U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 10082236952942943654U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 4015535035905433450U;
            aOrbiterI = RotL64((aOrbiterI * 4961808568701908559U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 611474103801573800U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 5786708483794098001U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7694007039340089267U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 5201943497363274455U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 9282160506938328489U;
            aOrbiterA = RotL64((aOrbiterA * 5368182164239021367U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 4932320527498940158U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 11576526341731392916U;
            aOrbiterF = RotL64((aOrbiterF * 1712051774729439363U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 10790691517638887125U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 16280649213607464422U;
            aOrbiterK = RotL64((aOrbiterK * 10756733801499471873U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 9553716940667712810U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 11827518270964003341U;
            aOrbiterG = RotL64((aOrbiterG * 1322489827908132831U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 16777463701235809321U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 3375489084588454149U;
            aOrbiterB = RotL64((aOrbiterB * 3335010977457647307U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 8129898095524287632U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 14496406641486541929U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10077246205532940301U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 17968163292907132345U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 2431407778543471402U;
            aOrbiterC = RotL64((aOrbiterC * 407105842057624537U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 18330313613898211889U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 4848316479321533394U;
            aOrbiterD = RotL64((aOrbiterD * 3462735144109152811U), 19U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 60U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 51U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 39U));
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterE, 41U)) + aOrbiterJ);
            aWandererD = aWandererD + ((((RotL64(aIngress, 60U) + aOrbiterI) + RotL64(aOrbiterH, 21U)) + RotL64(aCarry, 39U)) + aPhaseFWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterK, 47U));
            aWandererE = aWandererE + (((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 19U)) + aOrbiterC) + RotL64(aCarry, 29U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterA, 29U));
            aWandererC = aWandererC + ((RotL64(aScatter, 46U) + RotL64(aOrbiterJ, 26U)) + aOrbiterG);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 51U) + aOrbiterF) + RotL64(aOrbiterB, 23U)) + aPhaseFWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 57U)) + aOrbiterJ);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterG, 5U)) + aOrbiterE);
            aWandererF = aWandererF + ((RotL64(aCross, 11U) + RotL64(aOrbiterB, 52U)) + aOrbiterD);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterF, 11U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + (RotL64(aWandererA, 54U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + RotL64(aWandererB, 51U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 13331U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneC[((aIndex + 8641U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 13377U)) & S_BLOCK1], 38U) ^ RotL64(aFireLaneC[((aIndex + 11617U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 16056U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 12345U)) & S_BLOCK1], 24U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 12447U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCarry, 5U)) + (RotL64(aPrevious, 22U) ^ RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = ((aWandererK + RotL64(aScatter, 11U)) + RotL64(aCarry, 19U)) + 16124889768301047791U;
            aOrbiterH = ((aWandererB + RotL64(aCross, 41U)) + RotL64(aCarry, 3U)) + 11912338587186717280U;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 5U)) + 8594012868813114354U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aIngress, 57U)) + 18281043566156682815U;
            aOrbiterF = (aWandererI + RotL64(aCross, 13U)) + 16853106130200942302U;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 34U)) + RotL64(aCarry, 41U)) + 2611212958619673086U;
            aOrbiterD = (aWandererG + RotL64(aIngress, 51U)) + 18039472325066855180U;
            aOrbiterI = (aWandererC + RotL64(aScatter, 19U)) + 14495785571345122046U;
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 37U)) + 4556063793412832418U;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 54U)) + 14896419970271244358U) + aPhaseFOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aIngress, 3U)) + 880028529183500036U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 2379557167489415783U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 11854373946064529806U;
            aOrbiterE = RotL64((aOrbiterE * 150755294320438887U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 1487252775956449964U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 12777924204511625545U;
            aOrbiterH = RotL64((aOrbiterH * 1366019527386994789U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 15998631485222477969U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 8864212892296191613U;
            aOrbiterG = RotL64((aOrbiterG * 579242788050369815U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 17069347835763226743U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 7443008171694679791U;
            aOrbiterK = RotL64((aOrbiterK * 748894368884566607U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 17334256152350782002U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 8986626119086556393U;
            aOrbiterJ = RotL64((aOrbiterJ * 2258172145924120235U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 8528180968228358674U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 12702290928064582589U;
            aOrbiterD = RotL64((aOrbiterD * 15673603224146737631U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 7742438100860023610U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 3729687240959702198U;
            aOrbiterB = RotL64((aOrbiterB * 3756794766163746783U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 426129097367382096U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 16782175452274911213U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1041477289638333659U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 5942016166948841079U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 5260815086125551703U;
            aOrbiterI = RotL64((aOrbiterI * 1603799103692438147U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 11732742583346900772U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 17182924380693084401U;
            aOrbiterC = RotL64((aOrbiterC * 14858685629471497071U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 8539335803784852017U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 16124889768301047791U;
            aOrbiterA = RotL64((aOrbiterA * 6607245691919237755U), 53U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 10U);
            aIngress = aIngress + (RotL64(aOrbiterA, 37U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 42U));
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterH, 44U)) + aOrbiterG);
            aWandererI = aWandererI + ((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterK, 47U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 51U) + aOrbiterE) + RotL64(aOrbiterD, 11U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 29U)) + aOrbiterA) + aPhaseFWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 14U)) + aOrbiterF) + aPhaseFWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 24U) + RotL64(aOrbiterI, 21U)) + aOrbiterD) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterC, 41U));
            aWandererE = aWandererE + (((RotL64(aCross, 21U) + aOrbiterB) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 11U) + aOrbiterG) + RotL64(aOrbiterC, 23U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 43U) + aOrbiterB) + RotL64(aOrbiterH, 37U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterC, 39U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 24U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 5U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 22302U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneA[((aIndex + 17139U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 18251U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((aIndex + 21536U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22075U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 18917U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aExpandLaneB[((aIndex + 21173U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aPrevious, 42U)) + (RotL64(aCross, 27U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 35U)) + 9107326720193244489U;
            aOrbiterB = (aWandererD + RotL64(aCross, 30U)) + 10868585484401664145U;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 51U)) + RotL64(aCarry, 5U)) + 13637736741437846622U;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 19U)) + RotL64(aCarry, 13U)) + 6130725216183918844U;
            aOrbiterA = (aWandererF + RotL64(aCross, 5U)) + 2063834478521338187U;
            aOrbiterF = (aWandererH + RotL64(aScatter, 3U)) + 8564870627911949158U;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 43U)) + 6524015751064086390U;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 57U)) + 9874937766875388236U) + aPhaseFOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = (aWandererB + RotL64(aPrevious, 37U)) + 14723718409522680894U;
            aOrbiterE = (((aWandererI + RotL64(aCross, 21U)) + RotL64(aCarry, 41U)) + 13767059954741528279U) + aPhaseFOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aIngress, 10U)) + 6387608251033722169U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 5391425980008431000U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 11524218415655093779U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12508457981779189389U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 155510463350385905U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 10554591788433641311U;
            aOrbiterA = RotL64((aOrbiterA * 5412084824127934293U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 8662160162966241542U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 5092555636369853727U;
            aOrbiterD = RotL64((aOrbiterD * 433807340167635499U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 7163345798448796101U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 695089002178413267U;
            aOrbiterK = RotL64((aOrbiterK * 17302689458565434475U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 5409173939213468972U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 15349690077393827541U;
            aOrbiterB = RotL64((aOrbiterB * 10984681254001609841U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 12376011890751302027U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 7809614158898158383U;
            aOrbiterJ = RotL64((aOrbiterJ * 13845113198736843629U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 13031938699536449576U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 3983178190194056516U;
            aOrbiterC = RotL64((aOrbiterC * 1341678482929213405U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 5567935037909671790U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 17137042627663349797U;
            aOrbiterF = RotL64((aOrbiterF * 13535586899620672373U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 8726085717433137208U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 13154097637429217548U;
            aOrbiterI = RotL64((aOrbiterI * 5523758597936082363U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 4030516340575723215U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 7121696965917254968U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13569584361980228493U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 12079991626282752674U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 9107326720193244489U;
            aOrbiterH = RotL64((aOrbiterH * 7225937408665051799U), 43U);
            //
            aIngress = RotL64(aOrbiterC, 44U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 23U));
            aIngress = aIngress + RotL64(aOrbiterK, 46U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aCross, 26U) + aOrbiterE) + RotL64(aOrbiterK, 35U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterA, 53U)) + aOrbiterB) + aPhaseFWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterB, 57U)) + aOrbiterC);
            aWandererF = aWandererF + ((RotL64(aIngress, 35U) + RotL64(aOrbiterJ, 3U)) + aOrbiterF);
            aWandererE = aWandererE ^ ((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterG, 60U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 23U) + aOrbiterC) + RotL64(aOrbiterA, 27U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 30U) + RotL64(aOrbiterD, 39U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 13U) + aOrbiterA) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 53U)) + aPhaseFWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterC, 20U)) + aOrbiterH);
            aWandererB = aWandererB + ((RotL64(aPrevious, 53U) + aOrbiterI) + RotL64(aOrbiterF, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + (RotL64(aWandererF, 26U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 32746U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 27360U)) & S_BLOCK1], 20U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 27832U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 31136U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27302U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31349U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 27386U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 21U)) ^ (RotL64(aIngress, 35U) + RotL64(aCross, 52U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = (aWandererB + RotL64(aPrevious, 3U)) + 9220392006207660113U;
            aOrbiterC = (aWandererG + RotL64(aIngress, 11U)) + 11305018553489132882U;
            aOrbiterI = (aWandererI + RotL64(aScatter, 60U)) + 5860373868073513684U;
            aOrbiterF = (aWandererC + RotL64(aCross, 37U)) + 12319586170883987589U;
            aOrbiterK = (aWandererD + RotL64(aPrevious, 5U)) + 14072333614354649021U;
            aOrbiterD = (((aWandererE + RotL64(aIngress, 47U)) + RotL64(aCarry, 39U)) + 9332158529453194608U) + aPhaseFOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (((aWandererJ + RotL64(aCross, 43U)) + RotL64(aCarry, 21U)) + 3860569321145958686U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = (aWandererA + RotL64(aScatter, 21U)) + 8119005668901240093U;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 27U)) + 13918259792880333239U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 41U)) + 6938856216758228704U;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 30U)) + RotL64(aCarry, 11U)) + 3960905839118710604U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 6043879193734253929U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 15691425268831319195U;
            aOrbiterI = RotL64((aOrbiterI * 7189195135654636271U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 14912209933584715274U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 16180183395910618923U;
            aOrbiterD = RotL64((aOrbiterD * 3942858974766467849U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 4966642362507707776U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 6962226782462822861U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3647802407741095419U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 12409120845092026295U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 2302946450253872465U;
            aOrbiterC = RotL64((aOrbiterC * 7099576330777297911U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 16118304388937163838U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 15968419034359049422U;
            aOrbiterJ = RotL64((aOrbiterJ * 11736207775827080165U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 17098982091525008231U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 10298979200690822062U;
            aOrbiterA = RotL64((aOrbiterA * 12620028874653521945U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 552826643694256437U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 11786560990790695378U;
            aOrbiterH = RotL64((aOrbiterH * 11190309640069208311U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 13730399230389329793U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 17614226859252305432U;
            aOrbiterG = RotL64((aOrbiterG * 2640019643570222977U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 1062738267846296283U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 13959480457644980835U;
            aOrbiterE = RotL64((aOrbiterE * 1194145909157002977U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 4635071137794189167U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 13374502212707796180U;
            aOrbiterF = RotL64((aOrbiterF * 129680788767298945U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 11479902881487238033U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 9220392006207660113U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1437457810224888809U), 23U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 54U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + (RotL64(aOrbiterG, 37U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + RotL64(aOrbiterA, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 21U) + aOrbiterD) + RotL64(aOrbiterB, 53U)) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 41U) + aOrbiterD) + RotL64(aOrbiterG, 39U));
            aWandererF = aWandererF + ((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterJ, 37U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 5U)) + aOrbiterD);
            aWandererA = aWandererA + (((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterJ, 19U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterI, 58U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 28U) + aOrbiterC) + RotL64(aOrbiterH, 23U)) + RotL64(aCarry, 51U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterF, 29U)) + aOrbiterB);
            aWandererK = aWandererK + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterB, 47U)) + aOrbiterH);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 12U)) + aOrbiterK);
            aWandererH = aWandererH + ((RotL64(aCross, 38U) + RotL64(aOrbiterE, 41U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 14U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + RotL64(aWandererI, 18U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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

void TwistExpander_Lacrosse_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 1393U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneB[((aIndex + 2924U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 4650U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 2254U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5073U)) & S_BLOCK1], 22U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 2911U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aIngress, 6U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = ((aWandererH + RotL64(aCross, 5U)) + RotL64(aCarry, 53U)) + 15726877954695761686U;
            aOrbiterK = (((aWandererB + RotL64(aPrevious, 21U)) + RotL64(aCarry, 13U)) + 14187652171881943587U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aIngress, 39U)) + RotL64(aCarry, 39U)) + 8420423151313882782U;
            aOrbiterI = (aWandererJ + RotL64(aScatter, 54U)) + 14942322692433259283U;
            aOrbiterC = ((aWandererC + RotL64(aIngress, 29U)) + 7272331475919796255U) + aPhaseGOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 154504365041805840U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 17475491222554948786U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2095330528612694779U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 5759181483165339605U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 5993060214499322845U;
            aOrbiterK = RotL64((aOrbiterK * 10799489831896153301U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 10901786237875941844U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 17135786595614068473U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15923538730142047043U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 5208202073886811165U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 6821452921018900631U;
            aOrbiterC = RotL64((aOrbiterC * 13119330055184115669U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 13348064837402206969U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 8967943922403445136U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 300168481725373093U), 57U);
            //
            aIngress = RotL64(aOrbiterI, 3U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 48U) + aOrbiterE) + RotL64(aOrbiterI, 58U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterK, 27U)) + aOrbiterI) + RotL64(aCarry, 5U)) + aPhaseGWandererUpdateSaltD[((aIndex + 6U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterH, 43U)) + aOrbiterE);
            aWandererH = aWandererH + ((((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterK, 13U)) + RotL64(aCarry, 35U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 3U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 11U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 9235U)) & S_BLOCK1], 40U) ^ RotL64(aWorkLaneB[((aIndex + 12732U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 15719U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 8700U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 14833U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 14422U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 24U) + RotL64(aIngress, 39U)) ^ (RotL64(aPrevious, 11U) + RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = (aWandererF + RotL64(aCross, 19U)) + 12583180859826261500U;
            aOrbiterF = (((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 47U)) + 9067093488553721468U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 47U)) + 12173106198862881754U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aScatter, 36U)) + RotL64(aCarry, 3U)) + 11333491014394592654U;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 57U)) + RotL64(aCarry, 29U)) + 3511883526940919554U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 7416810692106273044U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 8341174972619784110U;
            aOrbiterJ = RotL64((aOrbiterJ * 17722163445765437279U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 2220852854836962979U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 8090781422229383825U;
            aOrbiterE = RotL64((aOrbiterE * 578293950675644397U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 2338801236599102223U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 12484514711848308104U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10364216764253366067U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 13684861340589131816U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 12796636819991873058U;
            aOrbiterF = RotL64((aOrbiterF * 5533508014234835669U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 7634198650894837690U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 10240326122201201762U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8758703497719125901U), 39U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 14U);
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterF, 29U)) + aOrbiterI);
            aWandererH = aWandererH + (((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 47U)) + aOrbiterE) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 22U) + aOrbiterI) + RotL64(aOrbiterA, 5U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterJ, 18U)) + RotL64(aCarry, 5U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterF, 37U)) + aOrbiterA) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 30U));
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 39U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 19423U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneA[((aIndex + 23679U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 23267U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18470U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 24306U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 21345U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 39U)) ^ (RotL64(aCarry, 56U) + RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = ((aWandererA + RotL64(aCross, 52U)) + RotL64(aCarry, 3U)) + 12206125048349568300U;
            aOrbiterC = (((aWandererC + RotL64(aIngress, 5U)) + RotL64(aCarry, 41U)) + 5843520589343188818U) + aPhaseGOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = (((aWandererB + RotL64(aScatter, 21U)) + RotL64(aCarry, 19U)) + 12195046124287121687U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aWandererF + RotL64(aPrevious, 29U)) + 16769779119214020640U;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 37U)) + 5257603646260695833U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 8523523946234886745U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 7316024684200084096U;
            aOrbiterF = RotL64((aOrbiterF * 11620083021691341337U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 11996978575084115207U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 15491711479085513628U;
            aOrbiterI = RotL64((aOrbiterI * 15136690392026011819U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 6036648530996821484U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 926323222234121863U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6639661141258803779U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 2700323841295743492U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 5852273765810284935U;
            aOrbiterE = RotL64((aOrbiterE * 16665696735016345215U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 11697397483133538067U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 17777142964957007194U;
            aOrbiterA = RotL64((aOrbiterA * 6338967222543284999U), 19U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterA, 37U);
            aIngress = aIngress + (RotL64(aOrbiterF, 23U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 29U) + aOrbiterA) + RotL64(aOrbiterE, 47U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 43U) + aOrbiterA) + RotL64(aOrbiterC, 57U)) + RotL64(aCarry, 21U)) + aPhaseGWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterF, 6U)) + aOrbiterE);
            aWandererB = aWandererB + ((((RotL64(aScatter, 57U) + aOrbiterE) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 35U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 20U) + aOrbiterC) + RotL64(aOrbiterE, 19U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 10U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 24841U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((aIndex + 28654U)) & S_BLOCK1], 52U));
            aIngress ^= RotL64(aExpandLaneA[((aIndex + 27593U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27615U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24707U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 28890U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCross, 48U)) + (RotL64(aIngress, 35U) + RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 13U)) + 1898718075389870739U) + aPhaseGOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aCross, 22U)) + RotL64(aCarry, 27U)) + 5631794889237247403U;
            aOrbiterD = (((aWandererI + RotL64(aIngress, 51U)) + RotL64(aCarry, 3U)) + 18219714659484524607U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aScatter, 41U)) + RotL64(aCarry, 51U)) + 15419581386225732921U;
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 3U)) + 9125575431710198210U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 12205871520544965505U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 7617534300497343422U;
            aOrbiterD = RotL64((aOrbiterD * 10052675719887595625U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 18017579105368135814U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 10693882161946020042U;
            aOrbiterJ = RotL64((aOrbiterJ * 2326507900303932855U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 11669615701700895306U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 11045110212889232165U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5965171269273719849U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 18019107802806469913U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 12315940560472528716U;
            aOrbiterG = RotL64((aOrbiterG * 4505122470351404065U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 4899009736070044310U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 17412253404253730364U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10791901166391946485U), 57U);
            //
            aIngress = RotL64(aOrbiterG, 58U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 37U));
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterG, 3U));
            aWandererE = aWandererE + (((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterB, 39U)) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 14U) + aOrbiterF) + RotL64(aOrbiterJ, 11U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 23U) + aOrbiterG) + RotL64(aOrbiterB, 53U)) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 22U)) + aOrbiterD) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 13U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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

void TwistExpander_Lacrosse_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 1866U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneB[((aIndex + 1585U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 2460U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1985U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4879U)) & S_BLOCK1], 46U));
            aCross ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 6537U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 20U) + RotL64(aCarry, 43U)) + (RotL64(aCross, 5U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = (((aWandererH + RotL64(aCross, 5U)) + RotL64(aCarry, 21U)) + 17470880031634374199U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aIngress, 43U)) + RotL64(aCarry, 51U)) + 757565846006937746U;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 20U)) + 9419282475801345674U) + aPhaseHOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = ((aWandererD + RotL64(aScatter, 53U)) + RotL64(aCarry, 37U)) + 2014248014107898196U;
            aOrbiterB = (aWandererG + RotL64(aPrevious, 29U)) + 15113928519446490441U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 7346126964886259935U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 5594123113093162359U;
            aOrbiterJ = RotL64((aOrbiterJ * 18043634828891483403U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 5659237263369402005U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 11565709683423969703U;
            aOrbiterA = RotL64((aOrbiterA * 16731289017588574671U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 16782863743534856287U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 13499100900072115907U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5567729598873214433U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 11414447651044205242U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 7545993795121430538U;
            aOrbiterK = RotL64((aOrbiterK * 10758488381206257261U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 11778229237616454988U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 2544793391976514665U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4021060413798523299U), 13U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 35U);
            aIngress = aIngress + (RotL64(aOrbiterA, 48U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterJ, 5U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 51U) + aOrbiterB) + RotL64(aOrbiterI, 13U));
            aWandererG = aWandererG + ((((RotL64(aCross, 21U) + aOrbiterJ) + RotL64(aOrbiterK, 21U)) + RotL64(aCarry, 5U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 47U)) + aOrbiterK);
            aWandererA = aWandererA + ((((RotL64(aIngress, 30U) + RotL64(aOrbiterB, 60U)) + aOrbiterJ) + RotL64(aCarry, 23U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererA, 39U);
            aCarry = aCarry + RotL64(aIngress, 4U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 11839U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneB[((aIndex + 9439U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12129U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9588U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15886U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13081U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 4U) + RotL64(aPrevious, 51U)) ^ (RotL64(aIngress, 37U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = (aWandererC + RotL64(aScatter, 5U)) + 3255291173184001106U;
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 13U)) + 15308468160116255528U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aIngress, 57U)) + RotL64(aCarry, 41U)) + 18186972408589866656U;
            aOrbiterI = (((aWandererJ + RotL64(aCross, 37U)) + RotL64(aCarry, 3U)) + 4439324265978331914U) + aPhaseHOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aScatter, 46U)) + RotL64(aCarry, 29U)) + 13099263173016322486U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 7041561081767500660U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 6196422612687812971U;
            aOrbiterG = RotL64((aOrbiterG * 13359900204297781063U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 7664260932541281413U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 17802347823020441056U;
            aOrbiterH = RotL64((aOrbiterH * 2220679459017369255U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 4253107484061190446U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 13799496534030645312U;
            aOrbiterD = RotL64((aOrbiterD * 9167675060053848207U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 14252892847595951926U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 5663527578664291422U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 18314294235895182465U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 11148755959699137661U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 17036900929333594592U;
            aOrbiterE = RotL64((aOrbiterE * 16041243617369003291U), 43U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterI, 39U);
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 27U) + RotL64(aOrbiterG, 43U)) + aOrbiterI) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 39U) + aOrbiterI) + RotL64(aOrbiterE, 35U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 6U) + RotL64(aOrbiterE, 56U)) + aOrbiterH) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterD, 27U)) + aOrbiterE);
            aWandererC = aWandererC + (((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterH, 11U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 16697U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 19940U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19218U)) & S_BLOCK1], 24U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22450U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19559U)) & S_BLOCK1], 22U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 21189U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 35U)) ^ (RotL64(aIngress, 47U) + RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (aWandererC + RotL64(aIngress, 19U)) + 15904465836916519864U;
            aOrbiterJ = (((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 37U)) + 17725629806317789307U) + aPhaseHOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aCross, 28U)) + RotL64(aCarry, 51U)) + 13794170125914914828U;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 51U)) + RotL64(aCarry, 3U)) + 2149055907476874332U;
            aOrbiterH = ((aWandererK + RotL64(aScatter, 39U)) + 5342047776745074649U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 8268148484060546838U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 10821151364028563719U;
            aOrbiterG = RotL64((aOrbiterG * 13626634259250509711U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 4294213820894407378U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 10884726101307943090U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1116128870387229159U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 16432210042202444824U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 15196602644336228055U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12680438355124070237U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 14117787670220328165U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 219833877949480215U;
            aOrbiterK = RotL64((aOrbiterK * 10736293047771972173U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 3326396981881473962U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 14918513066311426279U;
            aOrbiterC = RotL64((aOrbiterC * 14269763278564574663U), 27U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 35U);
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 19U) + aOrbiterG) + RotL64(aOrbiterH, 18U));
            aWandererG = aWandererG + (((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 57U)) + aOrbiterJ) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 27U) + aOrbiterC) + RotL64(aOrbiterK, 39U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 46U) + RotL64(aOrbiterH, 29U)) + aOrbiterC) + RotL64(aCarry, 39U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterC, 3U)) + aPhaseHWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 27245U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((aIndex + 26302U)) & S_BLOCK1], 18U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24787U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28993U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26624U)) & S_BLOCK1], 14U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 31197U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCross, 14U)) + (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = ((aWandererG + RotL64(aScatter, 58U)) + RotL64(aCarry, 29U)) + 11274974230580265396U;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 3U)) + 16658438747342741547U) + aPhaseHOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = (aWandererH + RotL64(aCross, 11U)) + 16612986966106053844U;
            aOrbiterB = (((aWandererI + RotL64(aPrevious, 39U)) + RotL64(aCarry, 13U)) + 9329502236843231290U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aCross, 47U)) + RotL64(aCarry, 51U)) + 14088261356708344656U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 13692608802007789581U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 6824473946645682398U;
            aOrbiterE = RotL64((aOrbiterE * 13619437545775237601U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 2072915876348570040U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 7420507753044460759U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13239288539564571257U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 4677557318688502593U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 15081678577055628459U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16659305295251177155U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 7026792817486507482U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 14871665922943969918U;
            aOrbiterC = RotL64((aOrbiterC * 694073180313083145U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 6807734532159292872U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 17882797335141303280U;
            aOrbiterF = RotL64((aOrbiterF * 15439872930381050291U), 21U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterE, 19U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + RotL64(aOrbiterC, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterF, 3U)) + aOrbiterB);
            aWandererD = aWandererD + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterE, 29U)) + aOrbiterC) + RotL64(aCarry, 47U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 48U) + RotL64(aOrbiterC, 21U)) + aOrbiterB);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterH, 51U)) + aOrbiterF) + RotL64(aCarry, 5U)) + aPhaseHWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterB, 42U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + RotL64(aWandererH, 51U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
