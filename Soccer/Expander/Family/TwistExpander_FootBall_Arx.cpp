#include "TwistExpander_FootBall_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_FootBall_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xB2F61A02BE4875D5ULL + 0xAB761A0B7A75B52BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xFD3817B5BED2457FULL + 0xD3A4122811D74A15ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x8047C345A61517B9ULL + 0xE4060EAF96884BE6ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xCF4078832DCD2E6DULL + 0x975654611E641E2DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xD81534B4CD6D6FEFULL + 0x937D2D676C57F179ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xAA6BCEF90D4DE2BBULL + 0xAD3B64A01C57BA00ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xD9ED293A74C6035DULL + 0xB46D6DD5E43191E8ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF69E52A13DA35529ULL + 0xDF440C6E34D04883ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x8D9B236186957BB5ULL + 0x9ED82A6D514827C2ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x9AB967D3A6642A45ULL + 0xF1A8A3AAD8774F2AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xF7A5BCB880819565ULL + 0xDC8E19B51756BC00ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xAE60F2F2EEB1F52DULL + 0xA6696AB9C9A326CCULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xDF9DD3D6D8A02C5DULL + 0xDA714F79EA161800ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x9F9C98FB3E7EABD7ULL + 0xC9C66081920564DCULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xC4EDCFB99C366BABULL + 0xEC1089BFDF379DA7ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xCE9D152218EF015BULL + 0x8DACD93574F8F6C7ULL);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 1255U)) & S_BLOCK1], 38U) ^ RotL64(pSnow[((aIndex + 5444U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 4018U)) & S_BLOCK1], 23U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 140U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 22U) + RotL64(aPrevious, 39U)) ^ (RotL64(aIngress, 53U) ^ RotL64(aCarry, 5U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererJ + RotL64(aCross, 53U)) + 12535417189990029950U;
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 21U)) + RotL64(aCarry, 23U)) + 6204401443676390273U;
            aOrbiterB = (aWandererE + RotL64(aIngress, 5U)) + 869613505613154672U;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 11U)) + 15053590879563855802U) + aOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 58U)) + 13338989605204591428U) + aOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = (aWandererK + RotL64(aCross, 35U)) + 18306470022403825392U;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 13U)) + RotL64(aCarry, 27U)) + 1150696349434090218U;
            aOrbiterI = (((aWandererH + RotL64(aScatter, 39U)) + RotL64(aCarry, 43U)) + 13549541786420596437U) + aNonceWordK;
            aOrbiterF = (aWandererD + RotL64(aPrevious, 19U)) + 14302878430259588461U;
            aOrbiterA = ((aWandererG + RotL64(aCross, 24U)) + 4660437084477165225U) + aNonceWordN;
            aOrbiterK = (aWandererF + RotL64(aIngress, 51U)) + 1653628537860912069U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 5594199757006711631U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 11008472193138708891U;
            aOrbiterB = RotL64((aOrbiterB * 13645764762027798301U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 3668516817279364310U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 128159531749679984U;
            aOrbiterH = RotL64((aOrbiterH * 4523246859249826987U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 6378674346113979108U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 11438762460659123362U;
            aOrbiterJ = RotL64((aOrbiterJ * 2733309638158283953U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 10624263004446482910U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 12546839706919241411U;
            aOrbiterC = RotL64((aOrbiterC * 11468326687628079347U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 8466639576503293921U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 5828694979857951504U;
            aOrbiterE = RotL64((aOrbiterE * 7835487310289634515U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 16496305151014092976U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 589464613876410567U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13190816610718051897U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 4168532743415647825U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 15944887793736489375U) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 17273403561158196717U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 11642456814106259483U) + aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 1609897693632334867U) ^ aNonceWordJ;
            aOrbiterD = RotL64((aOrbiterD * 12912773555616819941U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 14950238412766325479U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 11862438528287402255U;
            aOrbiterG = RotL64((aOrbiterG * 7635864312080265695U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 5900629306795222263U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 3221591991392500536U) ^ aOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7188525011266868855U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 16938699391746264010U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 12535417189990029950U;
            aOrbiterA = RotL64((aOrbiterA * 18212319484142613215U), 23U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 51U);
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 35U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 51U)) + aOrbiterI);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 35U) + aOrbiterE) + RotL64(aOrbiterB, 48U)) + aNonceWordE);
            aWandererH = aWandererH + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterF, 11U)) + aOrbiterC) + RotL64(aCarry, 41U)) + aNonceWordH);
            aWandererI = aWandererI ^ ((RotL64(aCross, 18U) + aOrbiterJ) + RotL64(aOrbiterE, 27U));
            aWandererK = aWandererK + ((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 19U)) + aOrbiterB);
            aWandererA = aWandererA ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterD, 3U)) + aOrbiterF);
            aWandererE = aWandererE + (((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterA, 53U)) + aWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 39U) + aOrbiterI) + RotL64(aOrbiterK, 57U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterG, 41U)) + RotL64(aCarry, 21U)) + aWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterC, 38U)) + aOrbiterE);
            aWandererG = aWandererG + ((RotL64(aScatter, 48U) + RotL64(aOrbiterK, 43U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererG, 58U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (RotL64(aWandererF, 38U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 13U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8365U)) & S_BLOCK1], 13U) ^ RotL64(mSource[((aIndex + 10708U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(pSnow[((S_BLOCK1 - aIndex + 8865U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9743U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 38U) + RotL64(aCross, 3U)) ^ (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 51U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererA + RotL64(aCross, 13U)) + 11177787645248006236U) + aNonceWordP;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 34U)) + 3808340254579817169U;
            aOrbiterF = ((aWandererI + RotL64(aScatter, 43U)) + 828030667598518279U) + aOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aWandererD + RotL64(aIngress, 47U)) + 16177835921238398371U;
            aOrbiterB = (aWandererK + RotL64(aScatter, 11U)) + 5518747735458708741U;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 18U)) + RotL64(aCarry, 29U)) + 17346319082399995165U;
            aOrbiterK = (aWandererB + RotL64(aCross, 29U)) + 6397156921893030937U;
            aOrbiterG = (((aWandererE + RotL64(aIngress, 41U)) + RotL64(aCarry, 43U)) + 15559381654710713582U) + aOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = ((aWandererJ + RotL64(aCross, 3U)) + RotL64(aCarry, 23U)) + 940404446491415088U;
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 23U)) + 8047166032048732645U) + aNonceWordH;
            aOrbiterI = (aWandererG + RotL64(aScatter, 57U)) + 4688468645859470491U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 3710878044770337260U) + aNonceWordN;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 116343189456629220U;
            aOrbiterF = RotL64((aOrbiterF * 5637725064169289339U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 883908030159391659U) + aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 18058691521694880482U;
            aOrbiterC = RotL64((aOrbiterC * 3132200449123497619U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 17521015077103586117U) + aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 3668332225435714918U;
            aOrbiterB = RotL64((aOrbiterB * 12658899101297839881U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 12229480388278883300U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 16206524049491531816U;
            aOrbiterK = RotL64((aOrbiterK * 11122340196620859805U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 5743265849441077466U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 2812293020719282236U;
            aOrbiterA = RotL64((aOrbiterA * 8903956475200417109U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 13718364781538837074U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 861529717259766236U;
            aOrbiterH = RotL64((aOrbiterH * 17019744777211266685U), 35U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterD) + 4862687502126693872U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordI;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 7722024283321020761U;
            aOrbiterE = RotL64((aOrbiterE * 18086944039541060829U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 8205803118233399853U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 15130160926615050422U;
            aOrbiterD = RotL64((aOrbiterD * 1454552751453996765U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 667469191899263617U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 18048970185163843471U;
            aOrbiterG = RotL64((aOrbiterG * 1800698970568737425U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 508102841337488721U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 3803840516662727630U;
            aOrbiterJ = RotL64((aOrbiterJ * 8477778555284121637U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 17055028117762299436U) + aNonceWordA;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 11177787645248006236U;
            aOrbiterI = RotL64((aOrbiterI * 12457019014051206805U), 29U);
            //
            aIngress = RotL64(aOrbiterA, 11U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + (RotL64(aOrbiterH, 48U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterE, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 44U) + RotL64(aOrbiterK, 40U)) + aOrbiterE) + aNonceWordO);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterK, 13U)) + aWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 27U) + RotL64(aOrbiterK, 5U)) + aOrbiterF) + aWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 37U) + aOrbiterD) + RotL64(aOrbiterI, 43U)) + aNonceWordD);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterH, 27U)) + aOrbiterA) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 21U)) + aOrbiterA) + aNonceWordE);
            aWandererF = aWandererF + ((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterG, 3U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterJ, 29U));
            aWandererG = aWandererG + ((RotL64(aIngress, 21U) + RotL64(aOrbiterG, 23U)) + aOrbiterF);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 19U)) + aOrbiterK);
            aWandererI = aWandererI + (((RotL64(aCross, 10U) + RotL64(aOrbiterJ, 34U)) + aOrbiterB) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 54U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 58U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordH);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12381U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneA[((aIndex + 15500U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 16018U)) & S_BLOCK1], 12U) ^ RotL64(pSnow[((aIndex + 16335U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aIngress, 5U)) + (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 22U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (((aWandererI + RotL64(aScatter, 51U)) + RotL64(aCarry, 43U)) + 701291026547470433U) + aOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aCross, 39U)) + 17283292650462111643U) + aOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aPrevious, 27U)) + 9969124091931303406U;
            aOrbiterI = (((aWandererE + RotL64(aIngress, 21U)) + RotL64(aCarry, 21U)) + 889176772718046988U) + aNonceWordG;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 53U)) + 6054541844643748084U;
            aOrbiterB = (aWandererD + RotL64(aCross, 23U)) + 14703226235143028132U;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 18U)) + 7977975878522921062U) + aNonceWordA;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 29U)) + 16894322614172266274U) + aNonceWordD;
            aOrbiterJ = (aWandererC + RotL64(aScatter, 3U)) + 12160451749345900570U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 13U)) + 10870847008043897470U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 60U)) + RotL64(aCarry, 57U)) + 8159920947172520247U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 2440099120969517932U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 2428396147731468007U;
            aOrbiterH = RotL64((aOrbiterH * 9363073341539598441U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 2213226274394673479U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 7079731443427765333U;
            aOrbiterB = RotL64((aOrbiterB * 16918930776877030559U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 958896789550478970U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 10788682955708075458U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 913321215613559729U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 2003386579317564870U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 8419686358774204999U;
            aOrbiterC = RotL64((aOrbiterC * 6547052526438697621U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 6989167615157578904U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 17636634003643824148U) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 11038576417283732937U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 13824962118933907859U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 9543912892587859646U;
            aOrbiterD = RotL64((aOrbiterD * 14736710162285997415U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 15729878041027706114U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 9542137475454825463U;
            aOrbiterE = RotL64((aOrbiterE * 11420547128115090491U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 5327302277575009955U) + aOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 2707383132257428583U) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 6120763309390182129U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 9008601903853562620U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 11050463189491777908U;
            aOrbiterF = RotL64((aOrbiterF * 9178386878636430553U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 14683684132116778056U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 5390271065690907120U;
            aOrbiterJ = RotL64((aOrbiterJ * 17903005409098232619U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 5183407290520277451U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 701291026547470433U;
            aOrbiterG = RotL64((aOrbiterG * 16329261100139524239U), 27U);
            //
            aIngress = RotL64(aOrbiterC, 13U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 58U));
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterE, 37U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterB, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterE, 57U)) + aOrbiterG);
            aWandererI = aWandererI + ((RotL64(aCross, 37U) + RotL64(aOrbiterH, 53U)) + aOrbiterK);
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 50U) + aOrbiterG) + RotL64(aOrbiterK, 13U)) + aNonceWordL) + aWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterI, 43U)) + aOrbiterF) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterE, 36U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterE, 21U)) + aNonceWordF);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterF, 41U));
            aWandererK = aWandererK + ((RotL64(aCross, 18U) + aOrbiterE) + RotL64(aOrbiterH, 29U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterG, 47U)) + aWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 41U) + RotL64(aOrbiterA, 26U)) + aOrbiterI) + RotL64(aCarry, 19U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterD, 19U)) + aOrbiterB) + aNonceWordJ);
            //
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 24U));
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 21U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordE);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 20341U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneB[((aIndex + 20995U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16478U)) & S_BLOCK1], 58U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 18466U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aPrevious, 36U)) ^ (RotL64(aIngress, 53U) + RotL64(aCarry, 23U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererB + RotL64(aCross, 53U)) + 9914837590440975587U) + aNonceWordG;
            aOrbiterI = (aWandererJ + RotL64(aIngress, 27U)) + 6706125076401958051U;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 46U)) + 16570817772679258409U) + aNonceWordL;
            aOrbiterB = (aWandererA + RotL64(aScatter, 57U)) + 6843705658115186948U;
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 21U)) + 16099930446791572351U) + aNonceWordO;
            aOrbiterG = (aWandererG + RotL64(aIngress, 3U)) + 5420550009556030459U;
            aOrbiterJ = (aWandererC + RotL64(aCross, 23U)) + 5729549069420177477U;
            aOrbiterK = (((aWandererH + RotL64(aScatter, 13U)) + RotL64(aCarry, 23U)) + 15590601126188675834U) + aOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 35U)) + RotL64(aCarry, 3U)) + 13044027390998620029U;
            aOrbiterD = (((aWandererK + RotL64(aCross, 60U)) + RotL64(aCarry, 11U)) + 11068338135659636772U) + aOrbiterAssignSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = (aWandererE + RotL64(aIngress, 37U)) + 6584988841809544332U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 8516813219883915404U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 10647314042912492785U;
            aOrbiterE = RotL64((aOrbiterE * 15559481057047148785U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 201691689889605304U) + aOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 15512161798401184003U;
            aOrbiterA = RotL64((aOrbiterA * 11473219183982564709U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 3883760518944464145U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 13861805129175491145U;
            aOrbiterG = RotL64((aOrbiterG * 17194438894492581181U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 12019138626550801486U) + aNonceWordF;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 13030350224959652248U;
            aOrbiterJ = RotL64((aOrbiterJ * 11724200983306280107U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 2643807255422544248U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 4127143302485631794U;
            aOrbiterK = RotL64((aOrbiterK * 5441038881111578487U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 14602951930809633069U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 4555737199162278494U;
            aOrbiterH = RotL64((aOrbiterH * 12415825635220991865U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 6343143902997169834U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 10404783711336491985U;
            aOrbiterD = RotL64((aOrbiterD * 6235474458879439079U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 7406959231434835393U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 6684368109277850196U;
            aOrbiterC = RotL64((aOrbiterC * 8760360417572331159U), 3U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterD) + 4835889355927954728U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 7917682889852676712U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9045350756570117327U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 10268055422944417055U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 5563744562922937643U;
            aOrbiterI = RotL64((aOrbiterI * 12442484191329795173U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 17244672945880141679U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 9914837590440975587U;
            aOrbiterB = RotL64((aOrbiterB * 12269340309792850489U), 39U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterE, 42U);
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + (RotL64(aOrbiterG, 37U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 14U) + aOrbiterD) + RotL64(aOrbiterG, 27U)) + aNonceWordD);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 51U) + aOrbiterI) + RotL64(aOrbiterD, 11U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterB, 58U)) + aOrbiterE) + RotL64(aCarry, 37U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterC, 5U));
            aWandererH = aWandererH + ((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 19U)) + aOrbiterF);
            aWandererK = aWandererK ^ (((RotL64(aCross, 23U) + aOrbiterJ) + RotL64(aOrbiterK, 21U)) + aWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 29U) + RotL64(aOrbiterE, 3U)) + aOrbiterJ);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 46U) + RotL64(aOrbiterI, 51U)) + aOrbiterK) + aNonceWordH);
            aWandererI = aWandererI + (((RotL64(aCross, 35U) + RotL64(aOrbiterE, 43U)) + aOrbiterK) + aWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 35U)) + aOrbiterH);
            aWandererE = aWandererE + (((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterG, 56U)) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 38U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + RotL64(aWandererK, 27U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 25934U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25098U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26300U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22652U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 18U) ^ RotL64(aCross, 53U)) ^ (RotL64(aIngress, 41U) + RotL64(aCarry, 5U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererA + RotL64(aCross, 3U)) + 1210605127156905516U;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 39U)) + 11964595428173569519U) + aOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 36U)) + 16277319029916258482U) + aOrbiterAssignSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = (((aWandererF + RotL64(aIngress, 47U)) + RotL64(aCarry, 21U)) + 12369497463101824572U) + aNonceWordI;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 51U)) + 6201248574067068202U;
            aOrbiterA = (aWandererD + RotL64(aIngress, 11U)) + 1727477025667206661U;
            aOrbiterI = ((aWandererG + RotL64(aCross, 42U)) + RotL64(aCarry, 11U)) + 1404510627789806851U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 21U)) + RotL64(aCarry, 29U)) + 6948213591282018925U;
            aOrbiterH = (aWandererH + RotL64(aCross, 53U)) + 6688865181284421478U;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 27U)) + 3351130769402360855U;
            aOrbiterD = (aWandererK + RotL64(aIngress, 29U)) + 12681032488906270823U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 3591412591193726763U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 16153817571210878589U;
            aOrbiterK = RotL64((aOrbiterK * 4165137036092246349U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 3808228354421006630U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 1427373776207504205U;
            aOrbiterA = RotL64((aOrbiterA * 4534374093769595531U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 1831554180932501132U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 1114853085120949215U) ^ aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4264176108298812905U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 2080935638828366835U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 16104777999646489828U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15205199362011777473U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 9782806013673440791U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 3721620299829386454U;
            aOrbiterF = RotL64((aOrbiterF * 6286765834910272409U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 4013706412064296527U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 5751022780695158579U) ^ aNonceWordP;
            aOrbiterE = RotL64((aOrbiterE * 13766736471646116397U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 17684546333240329338U) + aOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 1106947111128020920U;
            aOrbiterI = RotL64((aOrbiterI * 3158839453318658951U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 11564229705849500598U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 1585817314460274286U;
            aOrbiterH = RotL64((aOrbiterH * 12687162159791577431U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 13549147977354138518U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 5148731385622182707U) ^ aNonceWordJ;
            aOrbiterD = RotL64((aOrbiterD * 11016443961557395981U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 17048442399822433365U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 13772472534194030098U) ^ aNonceWordC;
            aOrbiterC = RotL64((aOrbiterC * 13155895389652826889U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 9982971300679888388U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 1210605127156905516U) ^ aOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9183351854400012949U), 35U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterC, 39U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 30U));
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aIngress, 5U) + RotL64(aOrbiterJ, 51U)) + aOrbiterK);
            aWandererK = aWandererK ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterC, 35U)) + aOrbiterH) + aWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 18U) + RotL64(aOrbiterD, 41U)) + aOrbiterE);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 37U) + aOrbiterA) + RotL64(aOrbiterE, 21U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 39U) + aOrbiterC) + RotL64(aOrbiterA, 27U)) + RotL64(aCarry, 27U)) + aNonceWordM);
            aWandererE = aWandererE ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterG, 48U)) + aOrbiterK);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 43U)) + aOrbiterE) + RotL64(aCarry, 37U)) + aNonceWordL);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterK, 53U)) + aOrbiterF);
            aWandererF = aWandererF + (((RotL64(aIngress, 13U) + RotL64(aOrbiterI, 3U)) + aOrbiterH) + aNonceWordG);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 43U) + aOrbiterB) + RotL64(aOrbiterI, 39U)) + aWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 58U) + RotL64(aOrbiterG, 6U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (RotL64(aWandererF, 56U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererK, 58U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordD;
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28738U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30730U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27551U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 30316U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 51U) + RotL64(aCarry, 5U)) + (RotL64(aIngress, 20U) ^ RotL64(aCross, 39U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererF + RotL64(aCross, 18U)) + 10812151398716051703U;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 37U)) + 18202551453336003710U;
            aOrbiterJ = (aWandererK + RotL64(aIngress, 57U)) + 9434410809101973752U;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 41U)) + RotL64(aCarry, 47U)) + 12955829998028534045U;
            aOrbiterK = (aWandererG + RotL64(aIngress, 39U)) + 12271740641929640181U;
            aOrbiterG = (((aWandererB + RotL64(aPrevious, 20U)) + RotL64(aCarry, 43U)) + 14009351527014534752U) + aOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = ((aWandererD + RotL64(aScatter, 47U)) + 4316296955679133450U) + aNonceWordP;
            aOrbiterH = (((aWandererE + RotL64(aCross, 35U)) + RotL64(aCarry, 11U)) + 16473324966997442872U) + aOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aScatter, 3U)) + 15735123324965019802U) + aNonceWordG;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 51U)) + 17656375090484080236U;
            aOrbiterF = ((aWandererI + RotL64(aCross, 11U)) + 16066325053456055298U) + aNonceWordE;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 12908968778503516903U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 12761433987676836197U;
            aOrbiterJ = RotL64((aOrbiterJ * 1023329467480907925U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 12737513138040664509U) + aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 14535795767570998392U) ^ aOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15560519667062222269U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 14370908061811284364U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 7001358781208669795U;
            aOrbiterG = RotL64((aOrbiterG * 11641248025734015835U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 7298578161120090849U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 10498302152357484629U;
            aOrbiterI = RotL64((aOrbiterI * 13144110412179037175U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 11447343228638006767U) + aOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 18284143620422655675U) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 572862190073605651U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 5918253208127360199U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 3910541329178205943U) ^ aNonceWordC;
            aOrbiterE = RotL64((aOrbiterE * 4550654545328228103U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 10357053096941367910U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 5610891501128498748U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8676370811772047449U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 9049881176058575811U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 6307599924966452216U;
            aOrbiterF = RotL64((aOrbiterF * 5551444450572055895U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 17109966783467892046U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 11563095828344462249U) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 15463753739272001875U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 3739147427725509014U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 5324449517615050698U;
            aOrbiterC = RotL64((aOrbiterC * 5926079615575226853U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 5706251076252597592U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 10812151398716051703U;
            aOrbiterA = RotL64((aOrbiterA * 5666491216813197045U), 29U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 35U);
            aIngress = aIngress + (RotL64(aOrbiterC, 18U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 52U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterI, 3U));
            aWandererG = aWandererG + ((RotL64(aScatter, 13U) + aOrbiterI) + RotL64(aOrbiterJ, 37U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 34U) + aOrbiterB) + RotL64(aOrbiterH, 43U));
            aWandererH = aWandererH + (((RotL64(aCross, 21U) + RotL64(aOrbiterK, 57U)) + aOrbiterG) + RotL64(aCarry, 35U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterC, 11U));
            aWandererF = aWandererF + ((RotL64(aScatter, 41U) + aOrbiterC) + RotL64(aOrbiterA, 21U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterI, 30U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aCross, 3U) + RotL64(aOrbiterC, 23U)) + aOrbiterE) + aWandererUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 26U) + aOrbiterE) + RotL64(aOrbiterH, 41U));
            aWandererB = aWandererB + (((((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterJ, 47U)) + RotL64(aCarry, 41U)) + aNonceWordN) + aWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterF, 28U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 36U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererK, 13U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordL);
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

void TwistExpander_FootBall_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xA3E580AB3A751063ULL + 0xFB774D06BE3991D5ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x8D0E9151571123CBULL + 0xB38148A33D978AFAULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xC837F0E38B65DE4DULL + 0xD6D7E2F52B32420AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x83745A1AC7E76DDFULL + 0xA6401660B65F3806ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x80A9FAE61566BC25ULL + 0x898AAE7C68854893ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xDD45105B674ED799ULL + 0xFBC97E1872AC66A8ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xC62219B5088619E1ULL + 0x8EAD4FE2DFC1CB83ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xD1BFE486850226F3ULL + 0xE1914764E1938D8AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x9312915787908375ULL + 0xE13CA836A7530BC7ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x9A5CE79D1E220BE1ULL + 0xDF98ADE613D25FC9ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xA121EA8CF2E65F67ULL + 0xDD12D7077EDAC1CDULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xA6259912717C91A7ULL + 0xC2DD743731F703DAULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xA0F42D7EE1BF437DULL + 0xF15578A25F2B12DAULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x90B4DCE55BEC404DULL + 0xC5C8785D8B5511C9ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xE76A6D082F5475F3ULL + 0x9FE8E0FDD93B2A39ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x98F0181F843E9E49ULL + 0xD09177DAC3A91807ULL);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 7246U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((aIndex + 2345U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2378U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 1283U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 39U)) + (RotL64(aCross, 27U) ^ RotL64(aIngress, 6U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererF + RotL64(aScatter, 23U)) + 5088525177670191619U;
            aOrbiterD = ((aWandererH + RotL64(aIngress, 29U)) + 9966456257813932112U) + aOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aCross, 47U)) + RotL64(aCarry, 43U)) + 7707646574027146307U;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 14U)) + RotL64(aCarry, 21U)) + 75480203757681173U;
            aOrbiterK = (aWandererD + RotL64(aCross, 19U)) + 384659134071835163U;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 3U)) + 3158769775373307778U) + aNonceWordC;
            aOrbiterJ = (aWandererC + RotL64(aScatter, 51U)) + 17360830943513941272U;
            aOrbiterC = (((aWandererE + RotL64(aIngress, 37U)) + RotL64(aCarry, 57U)) + 5317278822721604586U) + aOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aScatter, 10U)) + 1371427105215954781U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 3162710551223553423U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 5332921933853550756U;
            aOrbiterA = RotL64((aOrbiterA * 11709546145149357887U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 10572462410297815854U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 10234389605554817892U) ^ aOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2130374833440291193U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 13421365517991380605U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 10186643614984034083U;
            aOrbiterC = RotL64((aOrbiterC * 8554471709467808453U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 4742438973260817120U) + aNonceWordF;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 6081590345899008846U;
            aOrbiterH = RotL64((aOrbiterH * 7069396301823124931U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 15360092808493795340U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 12186413069553132646U;
            aOrbiterG = RotL64((aOrbiterG * 3815981440611914267U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 16756221656224451552U) + aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 12232880965861373143U;
            aOrbiterB = RotL64((aOrbiterB * 14196910735715726471U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 10090954323470840557U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 15615770271463853537U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13544181592829027283U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 556029032505658411U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 13311879111583579039U;
            aOrbiterD = RotL64((aOrbiterD * 3924744868168749003U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 8646360871497847336U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 2064833941982069154U;
            aOrbiterK = RotL64((aOrbiterK * 10016546852137913163U), 51U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 29U);
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 20U));
            aIngress = aIngress + RotL64(aOrbiterC, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 13U)) + aOrbiterI) + aNonceWordJ);
            aWandererH = aWandererH + ((RotL64(aIngress, 52U) + aOrbiterI) + RotL64(aOrbiterB, 60U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 39U) + aOrbiterJ) + RotL64(aOrbiterH, 53U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterH, 3U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterD, 29U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 19U)) + aOrbiterG) + RotL64(aCarry, 35U)) + aWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterG, 36U)) + aOrbiterA);
            aWandererB = aWandererB + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 47U)) + aOrbiterA) + RotL64(aCarry, 19U)) + aWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 48U) + aOrbiterI) + RotL64(aOrbiterJ, 41U)) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererH, 44U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordL;
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 15253U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10612U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11990U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneB[((aIndex + 14103U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 19U)) ^ (RotL64(aCross, 35U) + RotL64(aIngress, 50U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererB + RotL64(aCross, 51U)) + 17454559218352016650U;
            aOrbiterD = ((aWandererH + RotL64(aScatter, 10U)) + 8005709669325164803U) + aOrbiterAssignSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aIngress, 57U)) + 13393741948412816357U;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 29U)) + 3665865624348875553U) + aNonceWordE;
            aOrbiterJ = (((aWandererI + RotL64(aCross, 37U)) + RotL64(aCarry, 41U)) + 8334142570031883436U) + aOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 43U)) + RotL64(aCarry, 57U)) + 17226066128706139657U;
            aOrbiterC = (aWandererA + RotL64(aScatter, 19U)) + 3319093033121522613U;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 3U)) + RotL64(aCarry, 19U)) + 6657535603401588798U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 24U)) + 5469746182326331147U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 17846791786050221418U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 15939541003714896288U;
            aOrbiterB = RotL64((aOrbiterB * 1400351482213119809U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 12076763190461077406U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 3594038213596405284U;
            aOrbiterJ = RotL64((aOrbiterJ * 10244002692575821495U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 8301291631324464622U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 8460406137668390582U;
            aOrbiterC = RotL64((aOrbiterC * 9117147929757711595U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 7612394867020871200U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 8525076134853103975U;
            aOrbiterA = RotL64((aOrbiterA * 5790440201072204659U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 11929899088215090379U) + aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 7119509166360685726U;
            aOrbiterI = RotL64((aOrbiterI * 1662341427992528823U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 5081078459225240607U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 17149991983909906705U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 950223374568067343U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 8817303295675241994U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 7962039282652745113U;
            aOrbiterF = RotL64((aOrbiterF * 12773588587795522121U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 13596273086338032370U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 8186297702278180956U;
            aOrbiterG = RotL64((aOrbiterG * 6226504769888753861U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 1696277861691580263U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterI) ^ 17360461831507082959U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 1651378456022210983U), 11U);
            //
            aIngress = RotL64(aOrbiterB, 3U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + (RotL64(aOrbiterK, 24U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 38U) + RotL64(aOrbiterJ, 10U)) + aOrbiterD) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterA, 43U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 13U) + aOrbiterF) + RotL64(aOrbiterJ, 47U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterA, 39U)) + aOrbiterD) + aWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterG, 29U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 6U) + aOrbiterI) + RotL64(aOrbiterC, 35U)) + aWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 57U) + aOrbiterI) + RotL64(aOrbiterB, 5U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterK, 23U)) + aNonceWordI);
            aWandererD = aWandererD + ((((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterG, 52U)) + RotL64(aCarry, 43U)) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 26U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordJ);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 20244U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 21530U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17389U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((aIndex + 20678U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 37U)) ^ (RotL64(aCross, 11U) + RotL64(aIngress, 50U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererJ + RotL64(aCross, 30U)) + RotL64(aCarry, 35U)) + 8402620908307642697U;
            aOrbiterF = (((aWandererD + RotL64(aPrevious, 57U)) + RotL64(aCarry, 21U)) + 11347672014525086047U) + aNonceWordP;
            aOrbiterC = (aWandererF + RotL64(aIngress, 41U)) + 2816462912503401876U;
            aOrbiterB = (aWandererA + RotL64(aScatter, 37U)) + 6940159795470696093U;
            aOrbiterK = (aWandererK + RotL64(aCross, 19U)) + 9134692490095883851U;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 53U)) + 4999455497008026526U) + aNonceWordN;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 26U)) + 5992451460350651332U) + aOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aPrevious, 47U)) + 3417087346651371924U;
            aOrbiterG = (((aWandererH + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 3612773820086198270U) + aOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 463398077083428570U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 11249391303705089012U;
            aOrbiterC = RotL64((aOrbiterC * 7106735772303292983U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 17027535139825739501U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 568131384979596481U) ^ aOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5683451044852895957U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 4793712537158004047U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 10415170179135963622U;
            aOrbiterB = RotL64((aOrbiterB * 13729564030210361415U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 2391473979460065630U) + aNonceWordB;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 4240058362680064261U;
            aOrbiterF = RotL64((aOrbiterF * 12375884373396400889U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 9963957011090031698U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 3325305624067445525U;
            aOrbiterK = RotL64((aOrbiterK * 3128542681461806309U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 2094945647665114693U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 10703615640774042674U;
            aOrbiterI = RotL64((aOrbiterI * 12641986098450423751U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 3768738815518590289U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 15021301790376706827U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14445850924223550339U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 10571246886181608316U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 5130325144599151793U) ^ aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3185251943547657467U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 8617523421720966373U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 16574597770835250074U;
            aOrbiterG = RotL64((aOrbiterG * 1759209403428937799U), 47U);
            //
            aIngress = RotL64(aOrbiterF, 21U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + (RotL64(aOrbiterB, 4U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 37U) + RotL64(aOrbiterH, 12U)) + aOrbiterC) + aNonceWordJ);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 53U)) + aOrbiterH);
            aWandererK = aWandererK + (((RotL64(aCross, 30U) + RotL64(aOrbiterE, 29U)) + aOrbiterA) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 41U) + aOrbiterI) + RotL64(aOrbiterK, 57U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 57U) + aOrbiterF) + RotL64(aOrbiterB, 39U)) + aWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 51U) + aOrbiterG) + RotL64(aOrbiterI, 43U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterB, 3U)) + aOrbiterG) + RotL64(aCarry, 21U)) + aWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 11U) + aOrbiterB) + RotL64(aOrbiterK, 48U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 46U) + aOrbiterF) + RotL64(aOrbiterC, 35U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 24U));
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordA);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 29884U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30099U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27564U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((aIndex + 31874U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 51U) + RotL64(aCarry, 34U)) ^ (RotL64(aCross, 19U) ^ RotL64(aIngress, 3U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 57U)) + 10038936806177516123U) + aNonceWordM;
            aOrbiterA = (aWandererK + RotL64(aIngress, 29U)) + 1773168435195292638U;
            aOrbiterE = (((aWandererH + RotL64(aCross, 41U)) + RotL64(aCarry, 29U)) + 10655711161526628072U) + aNonceWordG;
            aOrbiterH = (aWandererA + RotL64(aScatter, 10U)) + 14422295664639740437U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 51U)) + RotL64(aCarry, 41U)) + 4125228715513159576U;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 35U)) + 3670449653158650845U) + aOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = (((aWandererF + RotL64(aIngress, 5U)) + RotL64(aCarry, 57U)) + 17553727567180813057U) + aOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aCross, 24U)) + 5111401772713882743U;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 47U)) + 7688573124662314413U) + aNonceWordN;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 9438375825507814395U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 14177477039902118886U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6467406626985022537U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 16329942595859623928U) + aNonceWordC;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 3990536794006836672U;
            aOrbiterD = RotL64((aOrbiterD * 579024714339065373U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 5072881436583180756U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 16789727877867289997U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8766246302636197905U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 17313956922306689438U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 11530878396329822041U;
            aOrbiterG = RotL64((aOrbiterG * 11356860047841383129U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 3612616532321160196U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 4172189825359187763U;
            aOrbiterH = RotL64((aOrbiterH * 12938945495299393177U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 8677279703778052804U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 1912172980909479362U;
            aOrbiterB = RotL64((aOrbiterB * 10053289257955474143U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 1460085850227494500U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 12116763868122868147U;
            aOrbiterK = RotL64((aOrbiterK * 6076945628020280957U), 47U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterK) + 17571840610366424432U) + aOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1]) + aNonceWordE;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 15581362592611080868U;
            aOrbiterF = RotL64((aOrbiterF * 1129054058044872003U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 14434700039977611666U) + aNonceWordL;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 4534294602623329152U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5860911553425182045U), 19U);
            //
            aIngress = RotL64(aOrbiterG, 14U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aIngress, 22U) + aOrbiterA) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 41U)) + aNonceWordJ);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterD, 34U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterB, 43U)) + aOrbiterD) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterI, 53U)) + aOrbiterG);
            aWandererK = aWandererK + (((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterF, 23U)) + aWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 18U) + RotL64(aOrbiterK, 58U)) + aOrbiterI);
            aWandererC = aWandererC + (((RotL64(aIngress, 11U) + RotL64(aOrbiterA, 29U)) + aOrbiterG) + aWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 41U) + aOrbiterG) + RotL64(aOrbiterH, 13U));
            aWandererA = aWandererA + ((RotL64(aIngress, 51U) + aOrbiterK) + RotL64(aOrbiterF, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 28U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordB;
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

void TwistExpander_FootBall_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterJ = 0;
    std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xD397DDFC8AD95C3DULL + 0xFAF0BB252A44291DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xA9AEFC7CD466D1E3ULL + 0x8338BF751463D66FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x9EB1DE6577F568DBULL + 0xE1BB5B305B49873EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xE14E273503C4BB8FULL + 0x96F66BA3EB06869AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x9ADD292C69DFCA47ULL + 0x84B247DAD0FFF766ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xB81C2990A2FCC1D1ULL + 0xAE5A953E5EFB0F75ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xCD2EA0A6CB3BD783ULL + 0x89E1E4990B6B27B8ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xFB77090D9B3E848FULL + 0xDF67C77BA49C8F8DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xD6A838EF30EB620DULL + 0xE81BF6155E5F5C84ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xAEA7B7B2EB0C5BAFULL + 0xC4843D28E5FEA6D0ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xC96770919D1F78BFULL + 0xFB98EA51C50C57F4ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xD607A6303E5E17C9ULL + 0xCC6C1B74EB7B07D3ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xC286C5F5BD965BA1ULL + 0xB707DFEFAE066706ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xA043B88C7464BF09ULL + 0xFE5AA17DFD35264AULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xA2FB0A751BC1E383ULL + 0xE185339878430D86ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x8C35EE9E2E917495ULL + 0x9A83E05BA7A03F85ULL);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 2932U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 249U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 2671U)) & S_BLOCK1], 34U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 4426U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCross, 54U)) + (RotL64(aCarry, 41U) + RotL64(aIngress, 29U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 29U)) + RotL64(aCarry, 11U)) + 12669015908335980355U;
            aOrbiterJ = (((aWandererA + RotL64(aScatter, 19U)) + RotL64(aCarry, 29U)) + 5438715179868613192U) + aNonceWordK;
            aOrbiterA = ((((aWandererF + RotL64(aCross, 53U)) + RotL64(aCarry, 43U)) + 13172104448184536460U) + aOrbiterAssignSaltC[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordI;
            aOrbiterG = ((aWandererC + RotL64(aIngress, 40U)) + 13421421503244744803U) + aNonceWordJ;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 11U)) + 13327113302994856582U) + aOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 4671768205922454413U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 5355759962838579929U) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 15080379163499722187U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 6691720614265406851U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 7063906424700911378U) ^ aOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17091734375516280675U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 17328616394166672263U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterJ) ^ 1542940602574207068U) ^ aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterG = RotL64((aOrbiterG * 8981679306319627975U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 7203866278803132454U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 993485696233139264U;
            aOrbiterJ = RotL64((aOrbiterJ * 11609009908810366447U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 15659679028507488331U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 18321361454094675842U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3966860765622641843U), 29U);
            //
            aIngress = RotL64(aOrbiterA, 43U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + RotL64(aOrbiterG, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterA, 53U)) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterG, 43U)) + aOrbiterH);
            aWandererE = aWandererE + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 6U)) + aOrbiterG) + RotL64(aCarry, 41U)) + aWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterF, 27U)) + aNonceWordG);
            aWandererF = aWandererF + (((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterF, 35U)) + aWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 30U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + RotL64(aWandererE, 11U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordK;
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 13576U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 9718U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 8551U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((aIndex + 12889U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aPrevious, 37U)) + (RotL64(aCross, 52U) ^ RotL64(aIngress, 23U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (((aWandererE + RotL64(aCross, 29U)) + RotL64(aCarry, 51U)) + 1297415699043177788U) + aOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = (((aWandererB + RotL64(aScatter, 47U)) + RotL64(aCarry, 27U)) + 17583786534509260153U) + aNonceWordD;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 20U)) + 643197858925708798U;
            aOrbiterH = (((aWandererH + RotL64(aIngress, 37U)) + RotL64(aCarry, 11U)) + 5062653766915694874U) + aOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = ((aWandererK + RotL64(aCross, 3U)) + 7034273638367180511U) + aNonceWordP;
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 2026909726972916996U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 2785690475553211646U;
            aOrbiterB = RotL64((aOrbiterB * 6612792037861160393U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 2910341716302991892U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 2834181605200829791U) ^ aOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1510617068750957651U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 13323052600571281928U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 10434901530315760460U;
            aOrbiterC = RotL64((aOrbiterC * 2042210188346767033U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 247903955625194782U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 5196515747387257163U) ^ aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1799024689023272275U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 7196305682377987476U) + aNonceWordK;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 14777739876892587484U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 95220583948241581U), 57U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 41U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + RotL64(aOrbiterC, 30U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterB, 3U)) + aNonceWordB) + aWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterC, 34U)) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 4U) + aOrbiterC) + RotL64(aOrbiterH, 21U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 13U)) + aOrbiterK) + RotL64(aCarry, 43U)) + aWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterC, 57U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 27U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordM);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 18759U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((aIndex + 17129U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20435U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 16770U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 20U) ^ RotL64(aPrevious, 39U)) + (RotL64(aIngress, 51U) + RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 3U)) + 14823268998003220191U) + aNonceWordE;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 28U)) + 15295237288788213847U) + aOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = (((aWandererD + RotL64(aScatter, 57U)) + RotL64(aCarry, 53U)) + 16434853402001133899U) + aNonceWordL;
            aOrbiterD = (((aWandererC + RotL64(aCross, 13U)) + RotL64(aCarry, 3U)) + 7555911304407871631U) + aNonceWordC;
            aOrbiterF = (((aWandererF + RotL64(aIngress, 39U)) + RotL64(aCarry, 27U)) + 14977248264994834620U) + aOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 9707764144919392380U) + aOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 1277304385464681529U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2864691650462053463U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 3089786220465849395U) + aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 3700503853358695085U;
            aOrbiterK = RotL64((aOrbiterK * 2079089949442685421U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 3240054112993517371U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 16897532076915366859U;
            aOrbiterA = RotL64((aOrbiterA * 4120874717534309035U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 18167359289798364307U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 8870819278575769863U;
            aOrbiterD = RotL64((aOrbiterD * 9334066154398059075U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 15363069206212330251U) + aNonceWordN;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 14858164441499725158U) ^ aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14931933411393847915U), 3U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 13U);
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aCross, 21U) + aOrbiterB) + RotL64(aOrbiterF, 21U)) + aNonceWordB) + aWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 56U)) + aOrbiterK) + aNonceWordF);
            aWandererG = aWandererG + (((RotL64(aIngress, 51U) + RotL64(aOrbiterD, 29U)) + aOrbiterA) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 6U) + aOrbiterF) + RotL64(aOrbiterD, 43U)) + aNonceWordI) + aWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 41U) + aOrbiterD) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordP);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 30031U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((aIndex + 25562U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28143U)) & S_BLOCK1], 20U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 31633U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 13U)) + (RotL64(aCross, 60U) ^ RotL64(aIngress, 27U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (((aWandererC + RotL64(aIngress, 5U)) + RotL64(aCarry, 19U)) + 380024772508948442U) + aNonceWordP;
            aOrbiterC = (((aWandererI + RotL64(aPrevious, 53U)) + RotL64(aCarry, 3U)) + 7649029098162567210U) + aOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 43U)) + 5329304598870421851U) + aNonceWordJ;
            aOrbiterF = ((aWandererB + RotL64(aCross, 22U)) + RotL64(aCarry, 35U)) + 12306118665045151326U;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 13U)) + 960751560457324256U) + aOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 3244070254386191876U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 15733408571609521746U;
            aOrbiterJ = RotL64((aOrbiterJ * 11280008313548121407U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 17623448932647018544U) + aOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 8787759896149035829U) ^ aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7092515868845497573U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 14741681792348288162U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 8801731213568307302U;
            aOrbiterF = RotL64((aOrbiterF * 12127126999570616489U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 9872248187499779222U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 15407371518644528235U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1245102406469471673U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 4242060317152943062U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterJ) ^ 9942784962409917541U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 888649755587764533U), 3U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 54U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterJ, 3U)) + aOrbiterF) + aNonceWordD);
            aWandererI = aWandererI + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterC, 51U)) + aOrbiterJ) + RotL64(aCarry, 39U)) + aNonceWordM);
            aWandererC = aWandererC ^ ((RotL64(aCross, 56U) + aOrbiterD) + RotL64(aOrbiterC, 27U));
            aWandererK = aWandererK + (((((RotL64(aPrevious, 43U) + aOrbiterD) + RotL64(aOrbiterF, 38U)) + RotL64(aCarry, 23U)) + aNonceWordN) + aWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 11U) + aOrbiterD) + RotL64(aOrbiterB, 11U)) + aWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 36U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordD);
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

void TwistExpander_FootBall_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xE2806C2AFC694D9FULL + 0xE254FCE6068C0610ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xE4AD4186F4D1035FULL + 0xC2121A8460F700F6ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC0C4E9B1CEE82C61ULL + 0xFA791F6D5A65C8CEULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xDCDEA4C50CA0CC31ULL + 0xF3A813DFFD1DEBF7ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xE7139C5E5BB89EDDULL + 0xBB4AA878E1551737ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xDA5739FE4DC8B697ULL + 0x88F37AE9E6DC85AEULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x9F830AD21B0F19BDULL + 0x8003E289812ABB8AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xEDC1E3D163EA1F5DULL + 0xADDE9D528E73DB55ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x8647F0831095D7F9ULL + 0xC8F7C37B333AE12FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xAE8645B416F2FAE9ULL + 0xE58779ED066ACA86ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xE6042393DEAEFE2BULL + 0xA879E46E5775E9D1ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xA5B1DE10166A4707ULL + 0x9DC7AC54500D2EB3ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xD9AC03DF8C1424DDULL + 0xD3B59784C92D5E78ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xDF7D8C185E6DCF77ULL + 0xC76A9C44ED1EF63FULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xD1FEAC091EAC4D2DULL + 0x825E920D8595CF94ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xD76B8403FA49E6EDULL + 0xC15BF1A777429471ULL);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 6415U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4095U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4349U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 5760U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 37U) ^ RotL64(aCarry, 21U)) ^ (RotL64(aCross, 4U) + RotL64(aPrevious, 53U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererI + RotL64(aCross, 43U)) + 14179205183062705133U;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 35U)) + RotL64(aCarry, 57U)) + 210032324058740920U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 11U)) + 7387115089142500152U) + aOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aIngress, 57U)) + RotL64(aCarry, 37U)) + 17583362781238061430U;
            aOrbiterJ = ((((aWandererD + RotL64(aScatter, 18U)) + RotL64(aCarry, 13U)) + 4991442849150005943U) + aOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1]) + aNonceWordM;
            aOrbiterF = ((aWandererC + RotL64(aCross, 3U)) + 2891376254689854555U) + aNonceWordK;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 51U)) + 10523274382407446239U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 3861893764676218667U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 3366674459852093746U;
            aOrbiterK = RotL64((aOrbiterK * 14005994095369483813U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 5898492634386601145U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 7047353571244768721U;
            aOrbiterJ = RotL64((aOrbiterJ * 2257518291062508467U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 14374108805453186316U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 8763667021501226510U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7694695426430267863U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 18261523829316379575U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 650477532238860965U;
            aOrbiterD = RotL64((aOrbiterD * 8291758490821819851U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 2162326554604894042U) + aOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 5776546692501825278U;
            aOrbiterI = RotL64((aOrbiterI * 14911545784585246537U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 3501863793638415049U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 14853789267425352958U) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 10590325397179928739U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 15399673014671329743U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 12253428583438990426U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12052855472196447849U), 11U);
            //
            aIngress = RotL64(aOrbiterH, 20U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 19U)) + aOrbiterJ);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 41U) + aOrbiterD) + RotL64(aOrbiterJ, 51U));
            aWandererC = aWandererC + (((((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterH, 4U)) + RotL64(aCarry, 21U)) + aNonceWordO) + aWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterG, 27U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 35U)) + aOrbiterF) + RotL64(aCarry, 37U)) + aNonceWordN);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 19U) + aOrbiterD) + RotL64(aOrbiterH, 41U)) + aWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 4U) + aOrbiterD) + RotL64(aOrbiterK, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + (RotL64(aWandererC, 36U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 11196U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16185U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10525U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((aIndex + 9106U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aIngress, 23U)) + (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 10U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 57U)) + RotL64(aCarry, 39U)) + 14823268998003220191U;
            aOrbiterB = (((aWandererE + RotL64(aScatter, 39U)) + RotL64(aCarry, 5U)) + 15295237288788213847U) + aOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aCross, 47U)) + 16434853402001133899U;
            aOrbiterA = (aWandererA + RotL64(aIngress, 26U)) + 7555911304407871631U;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 3U)) + 14977248264994834620U) + aNonceWordM;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 19U)) + RotL64(aCarry, 51U)) + 9707764144919392380U;
            aOrbiterK = ((aWandererD + RotL64(aCross, 13U)) + 1277304385464681529U) + aOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 3089786220465849395U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterH) ^ 3700503853358695085U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterF = RotL64((aOrbiterF * 2079089949442685421U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 3240054112993517371U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 16897532076915366859U) ^ aOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4120874717534309035U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 18167359289798364307U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 8870819278575769863U;
            aOrbiterA = RotL64((aOrbiterA * 9334066154398059075U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 15363069206212330251U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterG) ^ 14858164441499725158U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 14931933411393847915U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 5357144808788707522U) + aNonceWordP;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 2910681277417754860U;
            aOrbiterG = RotL64((aOrbiterG * 13170868582159347059U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 9824408699018165151U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 368370224788793300U;
            aOrbiterC = RotL64((aOrbiterC * 14358982366258729959U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 7095398304588825115U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 11418879758164313554U) ^ aOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5983520332639771791U), 29U);
            //
            aIngress = RotL64(aOrbiterB, 37U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 26U));
            aIngress = aIngress + RotL64(aOrbiterK, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 4U) + RotL64(aOrbiterK, 19U)) + aOrbiterG) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterF, 13U)) + aWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterC, 51U)) + aOrbiterH) + RotL64(aCarry, 13U)) + aNonceWordJ);
            aWandererD = aWandererD ^ (((RotL64(aCross, 11U) + aOrbiterB) + RotL64(aOrbiterA, 28U)) + aWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 35U) + RotL64(aOrbiterA, 57U)) + aOrbiterH);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 23U) + aOrbiterK) + RotL64(aOrbiterH, 43U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterB, 35U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 46U));
            aCarry = aCarry + RotL64(aWandererI, 39U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 16548U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 16821U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18968U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((aIndex + 20754U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 53U)) ^ (RotL64(aIngress, 13U) + RotL64(aCross, 28U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererD + RotL64(aCross, 47U)) + RotL64(aCarry, 5U)) + 9654059367478508868U;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 60U)) + 6473006635864677427U;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 39U)) + 6944184481315853243U;
            aOrbiterE = (((aWandererK + RotL64(aIngress, 5U)) + RotL64(aCarry, 19U)) + 4061496421939102306U) + aNonceWordH;
            aOrbiterI = ((aWandererC + RotL64(aCross, 53U)) + 15791809275719085463U) + aOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = (aWandererB + RotL64(aScatter, 29U)) + 14050798802646323055U;
            aOrbiterF = ((((aWandererA + RotL64(aPrevious, 19U)) + RotL64(aCarry, 57U)) + 12072905924741758266U) + aOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordA;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 17639076509231343896U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 12195388285571234715U;
            aOrbiterG = RotL64((aOrbiterG * 4317060502521195769U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 4325404419499496529U) + aNonceWordC;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 5910567888204238382U;
            aOrbiterH = RotL64((aOrbiterH * 11503787177122206937U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 13092940059929942699U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 13381962590820308761U) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 6345904465930943295U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 15622862439323440527U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 14027151901132249793U;
            aOrbiterE = RotL64((aOrbiterE * 2273573821630510087U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 4584410023907605157U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 15763755180625487157U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6755736130607297639U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 17023059745666559199U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 5298529579288492971U;
            aOrbiterC = RotL64((aOrbiterC * 2483562793328357721U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 2870152867331654736U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 12017191100173748848U) ^ aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9958191466506480519U), 3U);
            //
            aIngress = RotL64(aOrbiterI, 60U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + RotL64(aOrbiterF, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterF, 51U)) + aOrbiterH) + aNonceWordP);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 37U) + aOrbiterE) + RotL64(aOrbiterJ, 43U)) + RotL64(aCarry, 3U)) + aWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterC, 57U)) + aOrbiterI);
            aWandererD = aWandererD + (((RotL64(aPrevious, 29U) + aOrbiterC) + RotL64(aOrbiterE, 3U)) + aWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 58U) + RotL64(aOrbiterC, 36U)) + aOrbiterG);
            aWandererB = aWandererB + (((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 21U)) + aOrbiterI) + RotL64(aCarry, 35U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterJ, 13U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 46U));
            aCarry = aCarry + RotL64(aWandererJ, 51U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordD);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 28298U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((aIndex + 32150U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24746U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((aIndex + 32292U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 22U) ^ RotL64(aCarry, 57U)) + (RotL64(aPrevious, 37U) ^ RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererK + RotL64(aScatter, 58U)) + 12775735908960052604U;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 29U)) + RotL64(aCarry, 47U)) + 11791373812080296887U;
            aOrbiterA = (((aWandererA + RotL64(aPrevious, 35U)) + RotL64(aCarry, 35U)) + 5537362877706057303U) + aOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aCross, 5U)) + 2023912048504189380U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 43U)) + 17668828109963766893U) + aNonceWordL;
            aOrbiterF = (((aWandererD + RotL64(aCross, 23U)) + RotL64(aCarry, 13U)) + 558908629933941224U) + aOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aScatter, 13U)) + 1479633119685446888U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 15460320397843364063U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterE) ^ 10059749397555469054U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 8671817118586065469U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 9987633811929693924U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 10087337844580228269U) ^ aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13817142288940843815U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 4446204415503364254U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 15106063243302192717U;
            aOrbiterH = RotL64((aOrbiterH * 13273756657334709803U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 9430197906134676162U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 1226048679997253363U;
            aOrbiterB = RotL64((aOrbiterB * 14247538885252664127U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 10611580584157624739U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 3137391249289641509U;
            aOrbiterE = RotL64((aOrbiterE * 5462682413239873181U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 9327201928815412810U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 7890659377013147073U;
            aOrbiterG = RotL64((aOrbiterG * 13827717178378062047U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 10675114832750356941U) + aNonceWordK;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 8804440385852327267U) ^ aNonceWordG;
            aOrbiterD = RotL64((aOrbiterD * 8520671775587260601U), 11U);
            //
            aIngress = RotL64(aOrbiterG, 23U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 46U));
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterD, 29U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterF, 3U)) + aOrbiterD) + aNonceWordI);
            aWandererB = aWandererB + ((RotL64(aScatter, 26U) + RotL64(aOrbiterH, 21U)) + aOrbiterE);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterH, 35U)) + aWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterG, 60U)) + RotL64(aCarry, 35U)) + aWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterH, 51U)) + aOrbiterD);
            aWandererF = aWandererF + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 11U)) + aOrbiterA) + RotL64(aCarry, 57U)) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 42U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 35U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ aNonceWordK;
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

void TwistExpander_FootBall_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x91A27AB37776A36BULL + 0xDA3C33F75768C799ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xD90E84C83F52232BULL + 0xA8A02FA97EA41D8BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xF7E2EFC47D1E56CDULL + 0x8FF6DF3C92FF8569ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xBB15492FB4D2DDE5ULL + 0xAE27B498FD4F9B8FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xB1BA96D10FD7DECFULL + 0x8EB1455D2DABF230ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xD30DE1CEABD041D3ULL + 0xB0B840AB6F394228ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x8FBB4E4C39D329E3ULL + 0xAD07BF72719498EFULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xD117493860AF3917ULL + 0x8F20F6A0F4708FF6ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xE445CC8FC257C415ULL + 0xF80B6E2422B3F774ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xBCBAD75C616FA1CDULL + 0xB9A573FA2CFCFAB8ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xB19762AF38B4650BULL + 0x9B36F0CB13127847ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x9EFEF11DA0E0B175ULL + 0xEB90FFD6AB9646DBULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xAEC9012558EFD551ULL + 0xC040A054075C8BF9ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xA2AF97FCBB0669D7ULL + 0x9438352CB9A52AEFULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xADFC1922325A7CABULL + 0x8B3AB466E587F355ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xCF558463B3187C3FULL + 0xF071DCD1B5E3F456ULL);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 7862U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneC[((aIndex + 3373U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 1601U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((aIndex + 291U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aPrevious, 4U)) ^ (RotL64(aCarry, 53U) + RotL64(aIngress, 21U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererI + RotL64(aPrevious, 27U)) + 18319689184146942855U;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 41U)) + 8041304130090501019U) + aOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aCross, 19U)) + RotL64(aCarry, 39U)) + 11347064191990897738U;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 5U)) + 15242243470024447468U) + aNonceWordA;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 48U)) + 10619749107163611105U) + aNonceWordB;
            aOrbiterI = (((aWandererF + RotL64(aScatter, 57U)) + RotL64(aCarry, 5U)) + 14795614276221947128U) + aOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = (((aWandererB + RotL64(aIngress, 13U)) + RotL64(aCarry, 51U)) + 1578095288886372393U) + aNonceWordL;
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 13593906305770501684U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 8919815528334599172U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2033810402808238127U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 17425548324720065145U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 11125018338392347335U;
            aOrbiterD = RotL64((aOrbiterD * 4377887040461528587U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 3779189180734244399U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 10958224663276134041U;
            aOrbiterI = RotL64((aOrbiterI * 6206963519509783781U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 4317305352561612995U) + aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 4891139433808505355U;
            aOrbiterJ = RotL64((aOrbiterJ * 11507024985663120317U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 5166074784835930965U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 10080890270621589202U;
            aOrbiterB = RotL64((aOrbiterB * 13170894418184288695U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 4501071771615514619U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 6486573807774431753U) ^ aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 324029625116648669U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 15714881857668975753U) + aNonceWordE;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 3506619392820235900U;
            aOrbiterA = RotL64((aOrbiterA * 5707033870161224499U), 57U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 29U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 43U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 12U));
            aIngress = aIngress + RotL64(aOrbiterI, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterE, 43U)) + aOrbiterB);
            aWandererE = aWandererE + ((((RotL64(aScatter, 4U) + aOrbiterA) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 21U)) + aNonceWordI);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 21U)) + aOrbiterI);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 37U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 21U) + aOrbiterA) + RotL64(aOrbiterD, 27U)) + aWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 29U) + RotL64(aOrbiterI, 11U)) + aOrbiterC);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterD, 4U)) + aWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 54U));
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 12825U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 13334U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 9819U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 12183U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 48U) + RotL64(aCarry, 5U)) + (RotL64(aPrevious, 35U) ^ RotL64(aCross, 19U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererH + RotL64(aIngress, 27U)) + RotL64(aCarry, 13U)) + 10805654776556844351U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 11U)) + 582794182442795335U) + aNonceWordH;
            aOrbiterF = ((((aWandererC + RotL64(aPrevious, 58U)) + RotL64(aCarry, 57U)) + 2858343650974681068U) + aOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordC;
            aOrbiterA = ((aWandererD + RotL64(aCross, 47U)) + 8189584049022064284U) + aNonceWordD;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 35U)) + RotL64(aCarry, 43U)) + 1565100751996962893U;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 21U)) + 8062028016947611891U) + aOrbiterAssignSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aCross, 5U)) + 8280504280578451745U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 11326869194491655350U) + aOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 1671695656567777163U;
            aOrbiterF = RotL64((aOrbiterF * 7511554500524257921U), 23U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterE) + 2349843105293943452U) + aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1]) + aNonceWordG;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 13015545152052004254U;
            aOrbiterK = RotL64((aOrbiterK * 1316662811685429983U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 16703354404749291869U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 8713231044374305801U) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 9242480982197688625U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 11118401674497783533U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 14857556493734710364U;
            aOrbiterD = RotL64((aOrbiterD * 3452566050389715195U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 12953419670951660965U) + aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 12666121730825089017U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14049925256934142519U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 11075249639473053423U) + aNonceWordF;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 9374217688244187867U;
            aOrbiterG = RotL64((aOrbiterG * 5261156325627117877U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 17608340953291367867U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 13159437499327086340U;
            aOrbiterJ = RotL64((aOrbiterJ * 4882100944453534805U), 29U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 35U);
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterG, 26U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 37U) + aOrbiterA) + RotL64(aOrbiterK, 3U));
            aWandererA = aWandererA + (((RotL64(aCross, 23U) + aOrbiterF) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 27U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 13U)) + aOrbiterF) + aWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aScatter, 11U) + aOrbiterJ) + RotL64(aOrbiterE, 47U)) + RotL64(aCarry, 3U)) + aWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 57U) + aOrbiterA) + RotL64(aOrbiterF, 38U)) + aNonceWordN);
            aWandererD = aWandererD + ((RotL64(aCross, 43U) + RotL64(aOrbiterK, 53U)) + aOrbiterG);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 4U) + RotL64(aOrbiterD, 19U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererD, 48U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + RotL64(aWandererC, 41U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordK;
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 17027U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((aIndex + 18458U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 17198U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneC[((aIndex + 18540U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aPrevious, 29U)) + (RotL64(aIngress, 57U) ^ RotL64(aCarry, 6U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererA + RotL64(aCross, 47U)) + RotL64(aCarry, 39U)) + 11274974230580265396U;
            aOrbiterE = (((aWandererD + RotL64(aScatter, 5U)) + RotL64(aCarry, 57U)) + 16658438747342741547U) + aOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 21U)) + 16612986966106053844U;
            aOrbiterI = (aWandererJ + RotL64(aIngress, 11U)) + 9329502236843231290U;
            aOrbiterA = (((aWandererF + RotL64(aPrevious, 27U)) + RotL64(aCarry, 11U)) + 14088261356708344656U) + aNonceWordM;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 41U)) + 13692608802007789581U) + aOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = ((aWandererE + RotL64(aCross, 60U)) + 6824473946645682398U) + aNonceWordL;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 2072915876348570040U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 7420507753044460759U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13239288539564571257U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 4677557318688502593U) + aNonceWordP;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 15081678577055628459U;
            aOrbiterE = RotL64((aOrbiterE * 16659305295251177155U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 7026792817486507482U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterA) ^ 14871665922943969918U) ^ aOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterK = RotL64((aOrbiterK * 694073180313083145U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 6807734532159292872U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 17882797335141303280U;
            aOrbiterI = RotL64((aOrbiterI * 15439872930381050291U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 9233542707022629190U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 1205501586581350876U;
            aOrbiterA = RotL64((aOrbiterA * 2596053290311090589U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 10878718669747466677U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 8066049063548639241U;
            aOrbiterF = RotL64((aOrbiterF * 3031382633089381605U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 861295180226875235U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 9134969787937288583U) ^ aOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7565008208670843555U), 53U);
            //
            aIngress = RotL64(aOrbiterD, 37U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterK, 26U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterJ, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterI, 57U)) + aWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 43U) + aOrbiterA) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 47U)) + aWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterE, 13U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterI, 4U)) + aNonceWordC);
            aWandererE = aWandererE ^ ((RotL64(aCross, 36U) + aOrbiterD) + RotL64(aOrbiterF, 43U));
            aWandererD = aWandererD + (((RotL64(aScatter, 51U) + RotL64(aOrbiterA, 51U)) + aOrbiterD) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterJ, 27U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 24U));
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 41U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordA);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31922U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneB[((aIndex + 29958U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31141U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 28262U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aPrevious, 21U)) ^ (RotL64(aIngress, 6U) + RotL64(aCarry, 51U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererB + RotL64(aCross, 29U)) + 8506388683755208267U;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 19U)) + RotL64(aCarry, 3U)) + 2179323259055019735U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 5U)) + RotL64(aCarry, 53U)) + 3345902531140983016U;
            aOrbiterG = (aWandererH + RotL64(aIngress, 13U)) + 17456139311481306584U;
            aOrbiterJ = (((aWandererI + RotL64(aPrevious, 37U)) + 14587864088462311164U) + aOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1]) + aNonceWordG;
            aOrbiterI = ((aWandererF + RotL64(aCross, 47U)) + 13178947246650647057U) + aOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (((aWandererE + RotL64(aIngress, 58U)) + RotL64(aCarry, 35U)) + 12866578138946916962U) + aNonceWordB;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 13098524333655118173U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 15451329483787541982U;
            aOrbiterD = RotL64((aOrbiterD * 13580376920467431451U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 9494299579678389385U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 15581954810375490643U) ^ aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13670002280188424825U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 4487042505730624892U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 2774455928791636186U;
            aOrbiterK = RotL64((aOrbiterK * 15847933919136777451U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 12435319582397755819U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 10077180055177766823U;
            aOrbiterJ = RotL64((aOrbiterJ * 3924363471701748703U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 10391963896910956455U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 6149237416725301794U;
            aOrbiterE = RotL64((aOrbiterE * 10115917698918612823U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 15673402771629639978U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 14729117178956592426U) ^ aNonceWordL;
            aOrbiterG = RotL64((aOrbiterG * 9070464269215820531U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 14492001279368870240U) + aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 6278248084483259952U;
            aOrbiterH = RotL64((aOrbiterH * 16731228350971263873U), 11U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 35U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 44U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 53U) + aOrbiterK) + RotL64(aOrbiterH, 35U)) + aNonceWordA);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 37U) + aOrbiterH) + RotL64(aOrbiterI, 11U)) + aWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterH, 4U)) + aOrbiterE) + aNonceWordN);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 51U)) + aOrbiterG);
            aWandererF = aWandererF + (((((RotL64(aPrevious, 20U) + RotL64(aOrbiterJ, 23U)) + aOrbiterK) + RotL64(aCarry, 41U)) + aNonceWordC) + aWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterD, 29U)) + aOrbiterJ);
            aWandererH = aWandererH + (((RotL64(aIngress, 3U) + RotL64(aOrbiterE, 41U)) + aOrbiterD) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 36U));
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ aNonceWordF;
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

void TwistExpander_FootBall_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC5C200A57E794C61ULL + 0xF26091AEB857A6AEULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xC63CD3E66BAB1543ULL + 0xBBCAA3316F8EF236ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xBDE9451B64D3381DULL + 0xBC1CC8752B2B5B76ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xDF0052DF57A0F125ULL + 0x92448207C1A47FE6ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xADFE326F727802BFULL + 0xDD3DA989DA7F05FAULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x8E546535C33A7B1BULL + 0xFAE9EF49809B2B3FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xB220803D85362C91ULL + 0x928F5366A8B408A0ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xB37C5073DD41F37FULL + 0xC482C548F437957CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xDC2B16942BE4FB4BULL + 0x8244948E74AE5814ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xD09511CF60AC1E33ULL + 0xB65AE2DC12135810ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xB576C31227FE53F9ULL + 0xF6E7A923F901A429ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x8D0D609A7FCCA919ULL + 0xD83149FADD3F1B77ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xBEB6F4DA21761371ULL + 0xF7C38DF4B25A1A02ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xA0DD36ED39BC0CD3ULL + 0x9EE2852072CF56D2ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xA6E1DA7CE041F2BBULL + 0x8BBF07C68A21BD13ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xD7337E10CEC09A23ULL + 0x923A819A61718D75ULL);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5369U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((aIndex + 3782U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5952U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 3228U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCarry, 56U)) + (RotL64(aPrevious, 37U) + RotL64(aCross, 11U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererI + RotL64(aScatter, 47U)) + RotL64(aCarry, 51U)) + 9435962834163239322U;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 34U)) + 10524704356081318973U) + aOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aCross, 27U)) + 7403401305665208680U;
            aOrbiterG = ((aWandererG + RotL64(aIngress, 57U)) + RotL64(aCarry, 23U)) + 7525414805023556493U;
            aOrbiterF = ((aWandererD + RotL64(aCross, 11U)) + 1116686470029070951U) + aNonceWordP;
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 5U)) + 13257612299137802420U) + aOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 41U)) + 9181543003986598283U) + aNonceWordF;
            aOrbiterI = (aWandererC + RotL64(aScatter, 37U)) + 9739384852307501107U;
            aOrbiterH = (aWandererB + RotL64(aIngress, 19U)) + 11308402900229016057U;
            aOrbiterB = ((aWandererA + RotL64(aCross, 29U)) + RotL64(aCarry, 5U)) + 14935167593705272337U;
            aOrbiterE = (aWandererH + RotL64(aPrevious, 22U)) + 7171824007631943535U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 8068411284829563567U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 12350207458513447578U) ^ aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 813973258659041895U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 17039236343991574134U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 18291683592714999632U;
            aOrbiterJ = RotL64((aOrbiterJ * 7771718817924840713U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 6239616841884430968U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 10604527977569876774U) ^ aNonceWordD;
            aOrbiterC = RotL64((aOrbiterC * 6972820410084939637U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 1707724300671717658U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 3802268808625297647U;
            aOrbiterG = RotL64((aOrbiterG * 11296811630387191563U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 9423064323799920219U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 242153923313096551U;
            aOrbiterK = RotL64((aOrbiterK * 12117679073775630197U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 945801070951928277U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 13094814302414492064U;
            aOrbiterH = RotL64((aOrbiterH * 14638176479878969775U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 7572219725951040117U) + aNonceWordB;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 16494986983782503428U;
            aOrbiterE = RotL64((aOrbiterE * 2739189408707408171U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 10949497978229234856U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 11219643352002119905U;
            aOrbiterD = RotL64((aOrbiterD * 16900635614259262873U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 14245670385849499678U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterB) ^ 13771155918235018585U) ^ aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 14121731385133220921U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 15722734439532828816U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 11032710342174118366U;
            aOrbiterI = RotL64((aOrbiterI * 16096465375397981585U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 2071496769185495150U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 9435962834163239322U;
            aOrbiterB = RotL64((aOrbiterB * 10640995428633266765U), 41U);
            //
            aIngress = RotL64(aOrbiterC, 5U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 60U));
            aIngress = aIngress + (RotL64(aOrbiterA, 23U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 21U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + RotL64(aOrbiterK, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterB, 27U)) + aOrbiterJ);
            aWandererG = aWandererG + ((RotL64(aScatter, 39U) + RotL64(aOrbiterH, 60U)) + aOrbiterC);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 50U) + RotL64(aOrbiterG, 29U)) + aOrbiterE);
            aWandererB = aWandererB + ((RotL64(aPrevious, 29U) + aOrbiterD) + RotL64(aOrbiterE, 43U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterK, 3U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterB, 41U)) + aOrbiterK) + RotL64(aCarry, 39U)) + aNonceWordJ);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 23U) + aOrbiterI) + RotL64(aOrbiterC, 19U)) + aWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 11U) + aOrbiterD) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 47U)) + aNonceWordA);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterI, 37U)) + aOrbiterF);
            aWandererA = aWandererA + ((RotL64(aScatter, 6U) + RotL64(aOrbiterG, 46U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 27U) + aOrbiterA) + RotL64(aOrbiterK, 21U)) + aWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (RotL64(aWandererD, 44U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererF, 56U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordI;
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 15496U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((aIndex + 16257U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15554U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 16064U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 41U)) + (RotL64(aIngress, 28U) + RotL64(aCross, 11U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererF + RotL64(aCross, 27U)) + 6521330037475130256U;
            aOrbiterE = (aWandererK + RotL64(aScatter, 53U)) + 12611880456055428940U;
            aOrbiterI = (aWandererG + RotL64(aIngress, 58U)) + 12061611078130934708U;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 29U)) + 1558112410801116984U) + aNonceWordO;
            aOrbiterJ = (aWandererB + RotL64(aIngress, 3U)) + 10509115227850160786U;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 43U)) + 4045915960688792066U) + aOrbiterAssignSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aCross, 20U)) + 1196541286513243082U) + aOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 39U)) + RotL64(aCarry, 13U)) + 15564991032722373702U;
            aOrbiterK = ((aWandererD + RotL64(aScatter, 5U)) + RotL64(aCarry, 5U)) + 4897765238703641798U;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 47U)) + 12327429514907752733U;
            aOrbiterA = ((aWandererC + RotL64(aCross, 13U)) + RotL64(aCarry, 35U)) + 6189189797708711636U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 6374267075282018852U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 1888758503831341439U;
            aOrbiterI = RotL64((aOrbiterI * 74387714918264257U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 14956857689299491800U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 14879361107223331957U;
            aOrbiterE = RotL64((aOrbiterE * 9166712966729591953U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 16086885494838105042U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 8069724185844303923U;
            aOrbiterJ = RotL64((aOrbiterJ * 8878470736758734353U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 10854345917959911439U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 7078313614360332089U;
            aOrbiterC = RotL64((aOrbiterC * 9864025732292844871U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 15083669236062255011U) + aNonceWordJ;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 594879695916679116U;
            aOrbiterK = RotL64((aOrbiterK * 9852515479152735283U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 6721466068234534523U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 475816724162626782U) ^ aNonceWordN;
            aOrbiterG = RotL64((aOrbiterG * 4799725182757588407U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 4341655358154605899U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 15477254302340298586U;
            aOrbiterH = RotL64((aOrbiterH * 13961520225881974201U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 10179091913200895775U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 6310490897546909571U) ^ aNonceWordB;
            aOrbiterF = RotL64((aOrbiterF * 15080621088825477613U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 13462682513035460711U) + aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 16739138858084100385U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16386371811268298031U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 13608837667062268989U) + aOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 12902415667552110103U;
            aOrbiterD = RotL64((aOrbiterD * 16398790854093048017U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 16596211634603915761U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 6521330037475130256U;
            aOrbiterA = RotL64((aOrbiterA * 631958426544321145U), 13U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 41U);
            aIngress = aIngress + (RotL64(aOrbiterB, 56U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aIngress, 48U) + RotL64(aOrbiterH, 37U)) + aOrbiterB);
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterC, 57U)) + aNonceWordL) + aWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aCross, 41U) + aOrbiterG) + RotL64(aOrbiterA, 47U)) + RotL64(aCarry, 13U)) + aNonceWordA);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 43U) + aOrbiterB) + RotL64(aOrbiterG, 13U)) + aWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterI, 39U)) + RotL64(aCarry, 21U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterD, 60U));
            aWandererI = aWandererI + ((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 53U)) + aOrbiterH);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 26U) + RotL64(aOrbiterA, 43U)) + aOrbiterJ) + aNonceWordM);
            aWandererK = aWandererK + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterK, 35U)) + aOrbiterD);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterF, 50U)) + aOrbiterK);
            aWandererD = aWandererD + ((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterG, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 60U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + RotL64(aWandererF, 41U);
            aCarry = aCarry + RotL64(aIngress, 26U);
            aCarry = aCarry ^ aNonceWordI;
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 22506U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 20465U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21782U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneC[((aIndex + 19850U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 18U) ^ RotL64(aPrevious, 5U)) + (RotL64(aIngress, 37U) ^ RotL64(aCross, 53U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererG + RotL64(aScatter, 6U)) + 964165145848253292U;
            aOrbiterE = (aWandererJ + RotL64(aIngress, 57U)) + 10645976767204934746U;
            aOrbiterH = ((aWandererD + RotL64(aCross, 51U)) + 8241612229349212650U) + aNonceWordC;
            aOrbiterD = (aWandererE + RotL64(aPrevious, 39U)) + 4159196033256913347U;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 29U)) + RotL64(aCarry, 51U)) + 7194795864620233507U;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 60U)) + RotL64(aCarry, 47U)) + 7638928444536778384U;
            aOrbiterK = (aWandererC + RotL64(aCross, 13U)) + 11819105916503968109U;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 27U)) + 18052213302858186237U) + aOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = (aWandererB + RotL64(aPrevious, 41U)) + 8663575313970041570U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 35U)) + 16644136720439299786U) + aOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = (((aWandererI + RotL64(aScatter, 3U)) + RotL64(aCarry, 3U)) + 16930316530442679864U) + aNonceWordM;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 16251107616988250593U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 7171986193609401665U;
            aOrbiterH = RotL64((aOrbiterH * 3543709971414550087U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 17885046834432626644U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 7757069274715713557U;
            aOrbiterA = RotL64((aOrbiterA * 15766885299397923879U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 2212805322061155615U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 6368539134638838822U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13383744883433594259U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 5264326094252925613U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 6126345334815012938U;
            aOrbiterC = RotL64((aOrbiterC * 17180934809764905307U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 13826731214018407061U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 6621261811613643620U;
            aOrbiterG = RotL64((aOrbiterG * 2823596473596114171U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 5964406317285863781U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 2167324450276308078U;
            aOrbiterB = RotL64((aOrbiterB * 1098346374733634905U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 16740710162977859724U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 8236083581048717923U;
            aOrbiterF = RotL64((aOrbiterF * 4364887787000704039U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 13967473987446124012U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 5136051802217149813U;
            aOrbiterD = RotL64((aOrbiterD * 13997246005108872883U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 5842999397215390366U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 8621394946580065499U;
            aOrbiterK = RotL64((aOrbiterK * 11658023035736362355U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 18086875424872976900U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 7429246355923896047U;
            aOrbiterI = RotL64((aOrbiterI * 5077079237334961761U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 18123753993386959014U) + aNonceWordG;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 964165145848253292U) ^ aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3178072569980307307U), 13U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterE, 29U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + RotL64(aOrbiterG, 10U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterB, 41U)) + aOrbiterE) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 23U) + aOrbiterF) + RotL64(aOrbiterD, 38U));
            aWandererD = aWandererD + (((RotL64(aIngress, 41U) + aOrbiterG) + RotL64(aOrbiterH, 29U)) + aWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 14U) + RotL64(aOrbiterG, 3U)) + aOrbiterB) + aNonceWordI);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterJ, 21U)) + aOrbiterG);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterC, 13U)) + aWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 53U) + aOrbiterK) + RotL64(aOrbiterA, 23U)) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 44U) + RotL64(aOrbiterH, 57U)) + aOrbiterA);
            aWandererC = aWandererC + ((RotL64(aScatter, 51U) + RotL64(aOrbiterC, 51U)) + aOrbiterE);
            aWandererK = aWandererK ^ ((RotL64(aCross, 21U) + aOrbiterI) + RotL64(aOrbiterE, 26U));
            aWandererH = aWandererH + ((RotL64(aIngress, 37U) + aOrbiterG) + RotL64(aOrbiterD, 43U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 22U));
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + RotL64(aWandererK, 53U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordF);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 32588U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((aIndex + 25044U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29819U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 30852U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 27U) ^ RotL64(aCarry, 41U)) ^ (RotL64(aPrevious, 13U) + RotL64(aCross, 60U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererC + RotL64(aCross, 47U)) + 7896237440058555694U;
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 57U)) + 11870529476037558635U) + aNonceWordG;
            aOrbiterI = (((aWandererD + RotL64(aIngress, 51U)) + 9158983227801569448U) + aOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1]) + aNonceWordK;
            aOrbiterJ = (((aWandererE + RotL64(aPrevious, 3U)) + RotL64(aCarry, 5U)) + 4710172270996950329U) + aNonceWordJ;
            aOrbiterF = (aWandererH + RotL64(aCross, 26U)) + 14634482800356647630U;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 13U)) + RotL64(aCarry, 41U)) + 8822207952170610891U;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 39U)) + 13755891414028982553U) + aOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aIngress, 19U)) + 4555293067488040719U;
            aOrbiterC = (aWandererG + RotL64(aCross, 29U)) + 2816805148093762081U;
            aOrbiterD = (aWandererF + RotL64(aScatter, 41U)) + 2122631477965135190U;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 22U)) + RotL64(aCarry, 13U)) + 4592922416380416071U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 7102471666524164715U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 17274623547879474204U;
            aOrbiterI = RotL64((aOrbiterI * 5443572270546181789U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 938587316977094680U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 18258015823797023523U;
            aOrbiterF = RotL64((aOrbiterF * 6068819567674605919U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 5809987756043471595U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 5083075160112581620U;
            aOrbiterA = RotL64((aOrbiterA * 3313957222154937503U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 5960021727750946496U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 5967477320950630150U;
            aOrbiterG = RotL64((aOrbiterG * 330964768256424655U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 6578428711689296132U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 5601728218197771276U) ^ aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9552559022315971847U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 7923809409017855241U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 16479366540906497019U;
            aOrbiterC = RotL64((aOrbiterC * 7118578387798460919U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 17000467091738009736U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 6801634573655508028U;
            aOrbiterD = RotL64((aOrbiterD * 10584635770060137089U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 123668445682719574U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 14462802805503986316U;
            aOrbiterH = RotL64((aOrbiterH * 12398236364304875941U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 2433338393261685871U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 13869012262404991729U;
            aOrbiterE = RotL64((aOrbiterE * 12443261517483942937U), 29U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterH) + 4832421585086516998U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordF;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 11284414949564414958U;
            aOrbiterB = RotL64((aOrbiterB * 1586650935440790991U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 17872556812561387030U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 7896237440058555694U) ^ aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16784165278693056013U), 27U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 41U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 60U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterF, 43U)) + aOrbiterH);
            aWandererA = aWandererA + (((RotL64(aPrevious, 48U) + aOrbiterK) + RotL64(aOrbiterF, 51U)) + aNonceWordH);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterE, 3U)) + aOrbiterK) + aWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 5U) + RotL64(aOrbiterD, 14U)) + aOrbiterF) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 13U) + aOrbiterB) + RotL64(aOrbiterJ, 27U));
            aWandererI = aWandererI + ((RotL64(aCross, 27U) + RotL64(aOrbiterA, 53U)) + aOrbiterE);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterF, 57U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterG, 41U)) + aOrbiterJ);
            aWandererF = aWandererF ^ ((RotL64(aCross, 41U) + aOrbiterA) + RotL64(aOrbiterB, 21U));
            aWandererG = aWandererG + (((RotL64(aScatter, 60U) + aOrbiterI) + RotL64(aOrbiterD, 38U)) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterC, 11U)) + aOrbiterE) + aWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 42U));
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererJ, 27U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordN);
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

void TwistExpander_FootBall_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x85716C95288F7E2DULL + 0xEAB2789391EC4F5DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xF7C5C9763F584973ULL + 0xCBB043AA465FAE52ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xF898BF3865A76989ULL + 0xF3F3D8DEE1FB158BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xEB7A0CC7F2A6E139ULL + 0xA6343698ACF1E434ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xC7B5750EDB542483ULL + 0x8897473A49075953ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA7EA1C58C55B98B5ULL + 0xF0C265A3F9706502ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x8D0E5558D12DA297ULL + 0xA22C794AEE03BC3BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x91096459B1092953ULL + 0x9A3B236E4269DAD8ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xEB18BE67C5AE5EDFULL + 0xEDC3001B85A8AA6BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xECD68DEB7EE69697ULL + 0xBD107AE1F5FBC5D1ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x9841174C82B94CC5ULL + 0xBBC865AD109A382DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x915CB40F160808D3ULL + 0xDD0427BB55B0700BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xC96619E9D60AB73BULL + 0xD681BF23E323D9BFULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x82CA0C3234621FB5ULL + 0xC2C7F376F0C567DDULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xEDCDF0715ED49217ULL + 0x95548FDB0D28C02CULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xA5B0D2E3E088DD5DULL + 0xADF164C471A2663FULL);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 3784U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneC[((aIndex + 3596U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 444U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 4723U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 57U)) ^ (RotL64(aCarry, 26U) + RotL64(aIngress, 41U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererI + RotL64(aPrevious, 40U)) + 15813325389431304548U;
            aOrbiterD = ((aWandererH + RotL64(aCross, 57U)) + RotL64(aCarry, 13U)) + 2223874171125403602U;
            aOrbiterE = ((((aWandererB + RotL64(aIngress, 47U)) + RotL64(aCarry, 3U)) + 5510483568496824130U) + aOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordA;
            aOrbiterF = (aWandererC + RotL64(aScatter, 27U)) + 15474152493495661876U;
            aOrbiterH = (aWandererG + RotL64(aPrevious, 35U)) + 16846339705130829195U;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 19U)) + RotL64(aCarry, 35U)) + 1289670576865739669U;
            aOrbiterJ = (aWandererA + RotL64(aIngress, 53U)) + 18017354919647006944U;
            aOrbiterA = ((aWandererK + RotL64(aCross, 3U)) + 8539685539928984921U) + aOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aPrevious, 12U)) + 3333721400836704048U;
            //
            aOrbiterC = (((aOrbiterC + aOrbiterD) + 2261560416623815491U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordD;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 4377786131746816567U;
            aOrbiterE = RotL64((aOrbiterE * 9164777834392621157U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 18047393176583722719U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 8184724021940434631U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9800116157750921119U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 10469895939183324807U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 14543391765109879223U;
            aOrbiterA = RotL64((aOrbiterA * 4817987697437667225U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 5757225781746158178U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 3539000495894022869U) ^ aNonceWordN;
            aOrbiterG = RotL64((aOrbiterG * 1032298408884695925U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 11288971092707065923U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 2761384065186568294U;
            aOrbiterC = RotL64((aOrbiterC * 3323838837427471051U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 7120580145300417101U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 6977246291769372866U;
            aOrbiterF = RotL64((aOrbiterF * 15170353875184253779U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 17625434527765525937U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 3299714663631376190U;
            aOrbiterJ = RotL64((aOrbiterJ * 6532628892760776767U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 10331889953489885250U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 8550932256881727932U;
            aOrbiterD = RotL64((aOrbiterD * 13085531621192583719U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 11151195711186126257U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 2552002192824926483U) ^ aOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9754056316698523849U), 51U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterC, 41U);
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 10U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterJ, 53U)) + aNonceWordJ);
            aWandererH = aWandererH + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 19U)) + aOrbiterF) + RotL64(aCarry, 57U)) + aNonceWordM);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterH, 28U)) + aOrbiterC);
            aWandererC = aWandererC + ((RotL64(aCross, 14U) + RotL64(aOrbiterA, 23U)) + aOrbiterC);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterE, 57U)) + aWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 11U)) + aOrbiterJ) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 4U)) + aOrbiterC);
            aWandererA = aWandererA + ((RotL64(aCross, 24U) + aOrbiterJ) + RotL64(aOrbiterK, 39U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 29U) + aOrbiterE) + RotL64(aOrbiterF, 43U)) + aWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 14U));
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + RotL64(aWandererH, 54U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordM);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8423U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneD[((aIndex + 8427U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 6393U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7680U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 34U) ^ RotL64(aCross, 21U)) ^ (RotL64(aCarry, 51U) + RotL64(aPrevious, 5U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (((aWandererC + RotL64(aPrevious, 39U)) + RotL64(aCarry, 47U)) + 14157904117287696136U) + aNonceWordP;
            aOrbiterC = (aWandererJ + RotL64(aCross, 14U)) + 7369512677371640676U;
            aOrbiterG = (aWandererA + RotL64(aScatter, 35U)) + 8411250745902073798U;
            aOrbiterB = ((aWandererI + RotL64(aIngress, 51U)) + 5002041814539710275U) + aOrbiterAssignSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = ((aWandererD + RotL64(aCross, 5U)) + 9538041410816283124U) + aNonceWordH;
            aOrbiterI = ((aWandererG + RotL64(aScatter, 18U)) + RotL64(aCarry, 57U)) + 5210700103927513061U;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 57U)) + 7600709399101287982U) + aOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aIngress, 27U)) + RotL64(aCarry, 21U)) + 2366369466696580499U;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 23U)) + 5544575244203019109U) + aNonceWordC;
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 8710073749110329779U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 15998211310115361630U;
            aOrbiterG = RotL64((aOrbiterG * 15275657696897688955U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 15354357553877376422U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 10657523549259276169U;
            aOrbiterJ = RotL64((aOrbiterJ * 13695239532898311073U), 39U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterJ) + 10405750198355464768U) + aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1]) + aNonceWordA;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 3465819693133515142U) ^ aNonceWordB;
            aOrbiterE = RotL64((aOrbiterE * 14678343718277562799U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 16724189641701408630U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 3484340153620198872U;
            aOrbiterH = RotL64((aOrbiterH * 17247547677520703125U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 7420442404884871126U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterG) ^ 11138445997256757636U) ^ aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterA = RotL64((aOrbiterA * 11167543379937571127U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 1428191560884663125U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 16950093140800653985U;
            aOrbiterD = RotL64((aOrbiterD * 4423012306984814805U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 17288299075036481960U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 13793597915359681028U;
            aOrbiterB = RotL64((aOrbiterB * 9639204979982125757U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 5017972942710079726U) + aOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 12409957957614320964U;
            aOrbiterI = RotL64((aOrbiterI * 10273295741911545745U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 12487994181992095174U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 1573393166996612118U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13364311829104520751U), 27U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 43U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (RotL64(aOrbiterC, 54U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterG, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterJ, 57U)) + aOrbiterB) + aWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 10U) + RotL64(aOrbiterE, 44U)) + aOrbiterD) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterH, 5U)) + aWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 51U) + aOrbiterB) + RotL64(aOrbiterC, 29U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterI, 35U)) + aOrbiterJ) + aNonceWordD);
            aWandererC = aWandererC + (((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 53U)) + aOrbiterB);
            aWandererA = aWandererA + ((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 39U)) + aOrbiterG);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 58U) + RotL64(aOrbiterD, 22U)) + aOrbiterJ) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 18U));
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 3U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15002U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14826U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 15155U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15656U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 29U)) + (RotL64(aIngress, 56U) ^ RotL64(aCross, 13U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 4U)) + 4179952823252098240U) + aOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = ((aWandererK + RotL64(aIngress, 35U)) + RotL64(aCarry, 37U)) + 3745613452332101749U;
            aOrbiterF = (aWandererC + RotL64(aScatter, 51U)) + 2955689793395307176U;
            aOrbiterH = ((aWandererI + RotL64(aCross, 39U)) + RotL64(aCarry, 51U)) + 5639060180251322019U;
            aOrbiterJ = (((aWandererG + RotL64(aScatter, 21U)) + RotL64(aCarry, 13U)) + 7901969163853586463U) + aNonceWordJ;
            aOrbiterG = (aWandererJ + RotL64(aIngress, 46U)) + 2242166787816318119U;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 57U)) + 5239936443960750064U) + aOrbiterAssignSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = (aWandererA + RotL64(aCross, 27U)) + 13939136954732185558U;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 13U)) + 17058884136712717463U) + aNonceWordM;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 18148618660054585941U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 7022023484530327814U) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 650100011311048589U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 7722084537340095637U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 11764151879690934182U;
            aOrbiterA = RotL64((aOrbiterA * 12264384877711365655U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 16412785901758144708U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 9666718667728274824U;
            aOrbiterH = RotL64((aOrbiterH * 10865799822751771795U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 4307127540152109364U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 2457646804702647606U;
            aOrbiterE = RotL64((aOrbiterE * 6340030928007058595U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 3179394870088602208U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 504977947273774249U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16190282058883481551U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 16182729401018310837U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 7110817020445860609U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13371352088428584087U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 12960656706837391973U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 7103806893724395904U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14365984439655979791U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 1248300178080633527U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 7195473175424961337U;
            aOrbiterC = RotL64((aOrbiterC * 4633558992739305045U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 13007951568242991449U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 10296811247653636372U;
            aOrbiterD = RotL64((aOrbiterD * 16469682651380549395U), 51U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterE, 47U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 4U));
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterH, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 54U) + RotL64(aOrbiterH, 21U)) + aOrbiterD);
            aWandererI = aWandererI + ((RotL64(aScatter, 39U) + aOrbiterA) + RotL64(aOrbiterC, 47U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterF, 51U)) + aOrbiterD) + aWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 29U) + RotL64(aOrbiterG, 42U)) + aOrbiterJ) + RotL64(aCarry, 21U)) + aWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterA, 13U)) + aNonceWordO);
            aWandererG = aWandererG + ((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterF, 3U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 27U)) + aOrbiterJ) + aNonceWordF);
            aWandererE = aWandererE + (((RotL64(aIngress, 23U) + RotL64(aOrbiterJ, 38U)) + aOrbiterC) + RotL64(aCarry, 37U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 60U) + aOrbiterC) + RotL64(aOrbiterK, 57U)) + aNonceWordH);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 10U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererJ, 35U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordB;
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 20231U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((aIndex + 18146U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21278U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 16999U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aIngress, 20U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCross, 37U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererB + RotL64(aPrevious, 11U)) + 12615321415808640429U;
            aOrbiterJ = (((aWandererJ + RotL64(aCross, 22U)) + RotL64(aCarry, 3U)) + 15712784676459931207U) + aOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = ((aWandererC + RotL64(aScatter, 47U)) + RotL64(aCarry, 19U)) + 11013335427004930046U;
            aOrbiterA = ((((aWandererG + RotL64(aIngress, 5U)) + RotL64(aCarry, 29U)) + 8298733856304768806U) + aOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1]) + aNonceWordF;
            aOrbiterI = (aWandererF + RotL64(aScatter, 27U)) + 6207732959150824216U;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 57U)) + 9769864876127544038U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 39U)) + 10782181918651152563U;
            aOrbiterK = (aWandererK + RotL64(aCross, 18U)) + 5790454015845620939U;
            aOrbiterF = (aWandererE + RotL64(aPrevious, 51U)) + 15606578025386733803U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 5522352539991175304U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 5993355818572869649U;
            aOrbiterG = RotL64((aOrbiterG * 15221467311057431139U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 10864534396947622047U) + aNonceWordA;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 12090053126235913528U;
            aOrbiterI = RotL64((aOrbiterI * 7250801471645972261U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 14191181677234981396U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 2258570108233924592U) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 8307541155393855209U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 8448114811381534603U) + aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 2702389315763499817U;
            aOrbiterE = RotL64((aOrbiterE * 6710443836432274393U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 17202184076718780200U) + aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 150549910056015002U;
            aOrbiterA = RotL64((aOrbiterA * 195034681254956335U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 4910512055808124967U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 4783477997418403079U;
            aOrbiterB = RotL64((aOrbiterB * 861977492146512865U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 13842899106208709771U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 7930112618036681468U;
            aOrbiterK = RotL64((aOrbiterK * 8609551859830858419U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 8790107242863198659U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 6882768826643279144U;
            aOrbiterF = RotL64((aOrbiterF * 13745521454063360763U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 12136498871759890015U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterD) ^ 8120456314755584336U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 1830725195528043575U), 11U);
            //
            aIngress = RotL64(aOrbiterJ, 41U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterB, 44U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterJ, 19U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 29U)) + aOrbiterI) + RotL64(aCarry, 19U)) + aWandererUpdateSaltA[((aIndex + 8U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 28U) + aOrbiterE) + RotL64(aOrbiterF, 47U)) + aNonceWordE);
            aWandererC = aWandererC + ((RotL64(aIngress, 35U) + RotL64(aOrbiterJ, 51U)) + aOrbiterD);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterA, 56U));
            aWandererB = aWandererB + (((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 11U)) + aOrbiterB) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterG, 37U)) + aOrbiterA);
            aWandererG = aWandererG + (((RotL64(aIngress, 58U) + RotL64(aOrbiterE, 41U)) + aOrbiterD) + aNonceWordO);
            aWandererH = aWandererH ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterK, 6U)) + aOrbiterD) + aWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + (RotL64(aWandererC, 6U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererH, 43U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 21925U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((aIndex + 22123U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24071U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((aIndex + 22655U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCarry, 5U)) + (RotL64(aCross, 27U) + RotL64(aPrevious, 42U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererE + RotL64(aPrevious, 18U)) + 13650869943246163567U;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 53U)) + RotL64(aCarry, 21U)) + 3435284932011770999U;
            aOrbiterB = (aWandererC + RotL64(aIngress, 23U)) + 12388155658186776579U;
            aOrbiterC = ((aWandererK + RotL64(aCross, 29U)) + RotL64(aCarry, 3U)) + 2374345913955712039U;
            aOrbiterD = (aWandererF + RotL64(aPrevious, 58U)) + 6095094526980292156U;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 35U)) + 4965147025852444174U) + aNonceWordP;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 43U)) + 3261881216269075298U) + aOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = ((((aWandererA + RotL64(aIngress, 47U)) + RotL64(aCarry, 39U)) + 4939780217097329222U) + aOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordN;
            aOrbiterK = ((aWandererB + RotL64(aCross, 3U)) + 3019862009792676287U) + aNonceWordB;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 901910626217143974U) + aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 3647055146712366383U;
            aOrbiterB = RotL64((aOrbiterB * 1792602402476450009U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 7731765438957392967U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 13409819457393479741U;
            aOrbiterG = RotL64((aOrbiterG * 3345078200262410715U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 5415832109107794258U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 8876738832313114471U;
            aOrbiterJ = RotL64((aOrbiterJ * 1304277600444504135U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 17135570542519390359U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 2373193062766802082U;
            aOrbiterK = RotL64((aOrbiterK * 4213691513185791519U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 16318403285501718552U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 8456043288604687045U;
            aOrbiterE = RotL64((aOrbiterE * 10556964529144571683U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 10572534930284516528U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 14616251186735204677U) ^ aOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2048651204265459805U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 2837006243817205610U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 5315917323622194254U;
            aOrbiterF = RotL64((aOrbiterF * 4080522050089666599U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 12084676282761185907U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 7922080344175593788U;
            aOrbiterH = RotL64((aOrbiterH * 7603522302708937379U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 17620847289789547792U) + aNonceWordA;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 12140386059533463650U;
            aOrbiterD = RotL64((aOrbiterD * 1443266480620969535U), 29U);
            //
            aIngress = RotL64(aOrbiterE, 57U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 39U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 26U));
            aIngress = aIngress + RotL64(aOrbiterH, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterE, 23U)) + aOrbiterC);
            aWandererA = aWandererA + (((RotL64(aScatter, 18U) + aOrbiterE) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 52U)) + aOrbiterE);
            aWandererE = aWandererE + (((RotL64(aPrevious, 41U) + aOrbiterB) + RotL64(aOrbiterC, 43U)) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 27U)) + aOrbiterJ);
            aWandererK = aWandererK + ((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterJ, 19U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 58U) + RotL64(aOrbiterG, 11U)) + aOrbiterB) + aWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 51U) + RotL64(aOrbiterF, 56U)) + aOrbiterK) + aWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 37U)) + aOrbiterJ) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 42U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 27U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28089U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((aIndex + 29388U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28451U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32576U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCross, 12U)) + (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 27U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 39U)) + 785861751704720606U) + aNonceWordG;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 58U)) + 15968088718435606299U) + aOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aIngress, 21U)) + RotL64(aCarry, 3U)) + 1393976526590347151U;
            aOrbiterK = (aWandererC + RotL64(aCross, 27U)) + 17240750947292745884U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 47U)) + RotL64(aCarry, 19U)) + 4921576136163183137U;
            aOrbiterB = (((aWandererG + RotL64(aScatter, 51U)) + 3334047873553153032U) + aOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = ((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 47U)) + 15086509978458408698U;
            aOrbiterC = (aWandererF + RotL64(aIngress, 35U)) + 892391205397581998U;
            aOrbiterH = (aWandererB + RotL64(aScatter, 10U)) + 2965686403183767521U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 14632215393655706170U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 15740589515342377322U;
            aOrbiterD = RotL64((aOrbiterD * 15677716942904794913U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 11131164813943086445U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 6988080581278900960U;
            aOrbiterF = RotL64((aOrbiterF * 6412189142344044255U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 16021254613117657178U) + aOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 6183615599897921154U;
            aOrbiterA = RotL64((aOrbiterA * 9976411093264211033U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 12533992547026652747U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 3104325358982904219U;
            aOrbiterC = RotL64((aOrbiterC * 14977348108778147265U), 39U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterC) + 3878525937957474644U) + aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1]) + aNonceWordA;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 2120435259884368445U;
            aOrbiterH = RotL64((aOrbiterH * 15964718652193073177U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 14928658302694194856U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 9121310461310309348U) ^ aNonceWordO;
            aOrbiterI = RotL64((aOrbiterI * 17304439784647477491U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 3715693239100476493U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 7336577492932262490U) ^ aOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11074754160002665253U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 2312452827448455675U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 4322756069651934618U;
            aOrbiterB = RotL64((aOrbiterB * 6908893297397073539U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 4962079617577705818U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 5072727464750706525U) ^ aNonceWordE;
            aOrbiterG = RotL64((aOrbiterG * 4947670001221089155U), 57U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 56U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + RotL64(aOrbiterA, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aCross, 56U) + RotL64(aOrbiterD, 23U)) + aOrbiterK) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 23U) + aOrbiterH) + RotL64(aOrbiterD, 14U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 35U)) + aNonceWordF);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 37U) + aOrbiterG) + RotL64(aOrbiterI, 43U)) + aNonceWordP);
            aWandererA = aWandererA + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 3U)) + aOrbiterF);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 39U)) + aOrbiterC) + aWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 51U) + RotL64(aOrbiterH, 10U)) + aOrbiterG);
            aWandererG = aWandererG ^ ((((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterK, 57U)) + aNonceWordL) + aWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 60U) + RotL64(aOrbiterC, 47U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 54U));
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordP);
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

void TwistExpander_FootBall_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xFAF8876C5EF87981ULL + 0x953AA9709FCE6686ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xF06507AFB58DD807ULL + 0x82BBDBE41B5DBC4FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xB670B0A717BDF6FBULL + 0xE628FB9AFB01D8E8ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x95FA5D149B3CAD13ULL + 0x8DBEB56E1383EC0EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xCCF55B34F8134B5BULL + 0xE9F3496DC0413173ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xDE0BCF742CB54511ULL + 0x8E3C128937E5B375ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x9BA3529251251EBDULL + 0xAA96A9C0B58356A4ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xEEC1BDECBB43E5A1ULL + 0x922992F531930A50ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xE025BA41EA967211ULL + 0xCEC3BDFFB2D7F6BDULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x917B15616BBA308DULL + 0xEE5C053657AACEC5ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xA24BAA2DD0BE540DULL + 0xEB2F24A7F7D0BB4CULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xF8C05BC4883A4A4FULL + 0xB9777E7865139F35ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xA481FFD395B15B5BULL + 0xAF94368FF3793125ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xB109590ADE379921ULL + 0xDF6E4C4EE054B49AULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xC3DF3D986FD1EEFFULL + 0xC782A93B61537609ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xD81300C2698B1545ULL + 0xB1B5862D3967BD7CULL);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 709U)) & S_BLOCK1], 39U) ^ RotL64(aKeyRowReadA[((aIndex + 4114U)) & W_KEY1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 937U)) & W_KEY1], 51U) ^ RotL64(mSource[((aIndex + 583U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCarry, 50U)) ^ (RotL64(aIngress, 23U) ^ RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterK = ((aWandererB + RotL64(aCross, 5U)) + 12311607308490066301U) + aPhaseAOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 13U)) + RotL64(aCarry, 11U)) + 13100864684740679846U;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 29U)) + 13697304189274329704U) + aNonceWordA;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 43U)) + RotL64(aCarry, 23U)) + 9047976902871216732U;
            aOrbiterA = (aWandererI + RotL64(aScatter, 56U)) + 2147897579538537888U;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 37U)) + RotL64(aCarry, 41U)) + 2072444829390996142U;
            aOrbiterI = (((aWandererK + RotL64(aPrevious, 21U)) + 2129307836981020908U) + aPhaseAOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1]) + aNonceWordI;
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 10663145333751112064U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 15019844390503785459U) ^ aNonceWordM;
            aOrbiterE = RotL64((aOrbiterE * 7442321463110790449U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 5460865577557928142U) + aNonceWordB;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 15806522559993224197U;
            aOrbiterA = RotL64((aOrbiterA * 8722932687972240099U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 6361113778657833389U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 8306013884615042570U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8234258702656728667U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 4038420580499706912U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 11908091484457158973U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3964111175645156719U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 11133912466611921250U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 2469227904206936928U;
            aOrbiterK = RotL64((aOrbiterK * 2704438771198001599U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 13234017916788297295U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 9061117693840451988U;
            aOrbiterB = RotL64((aOrbiterB * 3637440416741459419U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 12013423690843812324U) + aNonceWordF;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 14371779015144617412U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3359568073302062667U), 29U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 35U);
            aIngress = aIngress + (RotL64(aOrbiterG, 48U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + RotL64(aOrbiterI, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 20U) + aOrbiterG) + RotL64(aOrbiterK, 57U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterA, 19U)) + aOrbiterF) + RotL64(aCarry, 27U)) + aPhaseAWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterI, 27U));
            aWandererF = aWandererF + ((((RotL64(aCross, 51U) + RotL64(aOrbiterB, 11U)) + aOrbiterA) + RotL64(aCarry, 57U)) + aNonceWordC);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 47U)) + aOrbiterA);
            aWandererI = aWandererI + (((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterE, 40U)) + aPhaseAWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterF, 3U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 56U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 7891U)) & S_BLOCK1], 23U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 5703U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 8386U)) & W_KEY1], 57U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 10487U)) & W_KEY1], 28U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aPrevious, 35U)) ^ (RotL64(aCross, 19U) + RotL64(aIngress, 4U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterD = (aWandererK + RotL64(aCross, 37U)) + 5160910997561396461U;
            aOrbiterI = (((aWandererE + RotL64(aPrevious, 19U)) + 14920764751058512062U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordL;
            aOrbiterC = (((aWandererH + RotL64(aScatter, 60U)) + RotL64(aCarry, 5U)) + 6080952401749660022U) + aNonceWordP;
            aOrbiterH = ((aWandererI + RotL64(aIngress, 53U)) + 17667234330526298627U) + aNonceWordN;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 5U)) + RotL64(aCarry, 41U)) + 760630072638686756U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 43U)) + 3504157162816997476U) + aPhaseAOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 29U)) + RotL64(aCarry, 19U)) + 9489022223422585882U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 1149898536879968964U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 10492284328940025310U;
            aOrbiterC = RotL64((aOrbiterC * 7893416766300156495U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 13213275606286399312U) + aNonceWordG;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 10557118912847180413U) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 10077877991284587845U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 15618980209023994776U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 5268600749854045564U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3849660559223919613U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 8011552687609649990U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 3148133096349525066U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5245156554959620007U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 12032847944237867285U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 14999005703490824673U;
            aOrbiterG = RotL64((aOrbiterG * 6631584955208646049U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 5426735969392906710U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 3593177531650386729U;
            aOrbiterE = RotL64((aOrbiterE * 12997284886192717043U), 51U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterH) + 1701444719333347373U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordA;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 15928731228196894960U;
            aOrbiterB = RotL64((aOrbiterB * 1919318226904213433U), 19U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 29U);
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterB, 29U)) + aNonceWordB);
            aWandererK = aWandererK ^ ((((RotL64(aCross, 23U) + RotL64(aOrbiterD, 43U)) + aOrbiterC) + aNonceWordD) + aPhaseAWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterG, 5U)) + aOrbiterI);
            aWandererE = aWandererE + (((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterH, 23U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 54U) + RotL64(aOrbiterI, 36U)) + aOrbiterD);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterD, 51U)) + RotL64(aCarry, 23U)) + aNonceWordJ);
            //
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 6U));
            aCarry = aCarry + RotL64(aWandererJ, 13U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ aNonceWordN;
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12054U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 13245U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15547U)) & W_KEY1], 39U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 15466U)) & W_KEY1], 18U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aPrevious, 58U)) ^ (RotL64(aIngress, 29U) ^ RotL64(aCarry, 11U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterA = (((aWandererD + RotL64(aIngress, 53U)) + RotL64(aCarry, 11U)) + 3621877681473089725U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = (((aWandererI + RotL64(aCross, 29U)) + RotL64(aCarry, 47U)) + 4451752751536414717U) + aNonceWordP;
            aOrbiterC = (((aWandererH + RotL64(aScatter, 60U)) + RotL64(aCarry, 27U)) + 11371625415377772117U) + aNonceWordL;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 47U)) + 6046792758881150619U;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 35U)) + 8213166120394461682U;
            aOrbiterJ = (((aWandererA + RotL64(aPrevious, 11U)) + 4343156661140422645U) + aPhaseAOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1]) + aNonceWordF;
            aOrbiterG = (aWandererE + RotL64(aScatter, 19U)) + 11105271483234947905U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 348904609985341372U) + aNonceWordD;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 12924652822526858767U;
            aOrbiterC = RotL64((aOrbiterC * 2801892489296408735U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 7461211697358520287U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 16551553555297890558U;
            aOrbiterK = RotL64((aOrbiterK * 16432952324635746293U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 11908056404140782995U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 9147367258259948715U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10777628928376261667U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 8876461054692728610U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 10546855952702525404U;
            aOrbiterE = RotL64((aOrbiterE * 10071104785895309677U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 4748636139110443794U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 783046909529525098U;
            aOrbiterD = RotL64((aOrbiterD * 8969157702460927215U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 16683965945838696665U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 12385412690177109575U;
            aOrbiterJ = RotL64((aOrbiterJ * 10795062772707143187U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 8210546822184469023U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 13146493623236979963U;
            aOrbiterG = RotL64((aOrbiterG * 13199947810161148155U), 35U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterE, 51U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterG, 11U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 5U)) + aOrbiterA) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 21U)) + aOrbiterE);
            aWandererD = aWandererD + (((((RotL64(aPrevious, 27U) + aOrbiterG) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 27U)) + aNonceWordG) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 21U) + aOrbiterD) + RotL64(aOrbiterA, 27U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterA, 57U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 42U) + RotL64(aOrbiterG, 42U)) + aOrbiterK) + aPhaseAWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 20U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + RotL64(aWandererH, 53U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 16402U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((aIndex + 20178U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21561U)) & S_BLOCK1], 3U) ^ RotL64(mSource[((aIndex + 21561U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 26U) ^ RotL64(aCross, 39U)) + (RotL64(aIngress, 51U) ^ RotL64(aCarry, 5U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterH = (aWandererA + RotL64(aIngress, 23U)) + 9107326720193244489U;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 57U)) + 10868585484401664145U) + aPhaseAOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aCross, 41U)) + RotL64(aCarry, 3U)) + 13637736741437846622U;
            aOrbiterK = ((aWandererI + RotL64(aScatter, 51U)) + RotL64(aCarry, 41U)) + 6130725216183918844U;
            aOrbiterI = (((aWandererC + RotL64(aCross, 29U)) + 2063834478521338187U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordP;
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 14U)) + 8564870627911949158U;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 5U)) + RotL64(aCarry, 19U)) + 6524015751064086390U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 9874937766875388236U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 14723718409522680894U;
            aOrbiterA = RotL64((aOrbiterA * 17379140128833323431U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 13767059954741528279U) + aNonceWordN;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 6387608251033722169U;
            aOrbiterF = RotL64((aOrbiterF * 6601902195707980693U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 5391425980008431000U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 11524218415655093779U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12508457981779189389U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 155510463350385905U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 10554591788433641311U;
            aOrbiterI = RotL64((aOrbiterI * 5412084824127934293U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 8662160162966241542U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 5092555636369853727U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 433807340167635499U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 7163345798448796101U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 695089002178413267U;
            aOrbiterK = RotL64((aOrbiterK * 17302689458565434475U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 5409173939213468972U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 15349690077393827541U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10984681254001609841U), 43U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 51U);
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + RotL64(aOrbiterC, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterI, 29U)) + RotL64(aCarry, 27U)) + aPhaseAWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterH, 47U)) + aOrbiterB);
            aWandererE = aWandererE + ((RotL64(aIngress, 51U) + RotL64(aOrbiterB, 3U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 44U) + aOrbiterB) + RotL64(aOrbiterA, 11U)) + aPhaseAWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterH, 60U)) + aOrbiterC) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 5U) + aOrbiterF) + RotL64(aOrbiterC, 53U)) + aNonceWordL);
            aWandererA = aWandererA + (((RotL64(aIngress, 21U) + RotL64(aOrbiterB, 23U)) + aOrbiterC) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 12U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 29U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ aNonceWordN;
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22928U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneA[((aIndex + 24004U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24090U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneA[((aIndex + 26135U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCarry, 5U)) ^ (RotL64(aCross, 53U) + RotL64(aPrevious, 40U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 57U)) + RotL64(aCarry, 57U)) + 12122689833405846292U;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 27U)) + RotL64(aCarry, 41U)) + 9640400270962766788U;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 3U)) + 9141937998266739071U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = (((aWandererA + RotL64(aCross, 14U)) + RotL64(aCarry, 19U)) + 12899395770434090537U) + aPhaseAOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = ((aWandererF + RotL64(aScatter, 51U)) + 13457918115408031842U) + aNonceWordI;
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 43U)) + 15134784483576000943U;
            aOrbiterG = (aWandererB + RotL64(aIngress, 21U)) + 12540961268790055438U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 6306886773092764230U) + aNonceWordM;
            aOrbiterB = (((aOrbiterB ^ aOrbiterC) ^ 13573343491337243121U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterB = RotL64((aOrbiterB * 15893457012357368707U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 8545588657348974413U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 10891410570357275120U;
            aOrbiterC = RotL64((aOrbiterC * 5399310978367842841U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 2877137119767060151U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 9178097682386595144U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3524486002084427513U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 15528007881855616978U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 11368419529245281435U;
            aOrbiterF = RotL64((aOrbiterF * 12433207037378339309U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 5932738914934356645U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 5551842263864055419U;
            aOrbiterD = RotL64((aOrbiterD * 16093776759971522681U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 3824433359595690603U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 17184628855571662441U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 691208053136187317U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 8724462245014132623U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 7481349499528092352U;
            aOrbiterG = RotL64((aOrbiterG * 8212182934509617583U), 35U);
            //
            aIngress = RotL64(aOrbiterD, 27U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterH, 37U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 43U));
            aIngress = aIngress + RotL64(aOrbiterF, 10U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 53U)) + aOrbiterJ) + aPhaseAWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aCross, 47U) + RotL64(aOrbiterG, 35U)) + aOrbiterC) + RotL64(aCarry, 35U)) + aNonceWordF);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterF, 19U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterB, 13U)) + aOrbiterG) + RotL64(aCarry, 19U)) + aNonceWordC);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 34U) + RotL64(aOrbiterG, 5U)) + aOrbiterD);
            aWandererA = aWandererA + (((RotL64(aPrevious, 5U) + aOrbiterD) + RotL64(aOrbiterH, 60U)) + aPhaseAWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 27U) + aOrbiterD) + RotL64(aOrbiterF, 41U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + RotL64(aWandererH, 18U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordG);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + S_BLOCK1)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29859U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27730U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28874U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 4U) + RotL64(aCross, 51U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 37U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterG = (aWandererK + RotL64(aIngress, 51U)) + 15036852811491820366U;
            aOrbiterD = ((aWandererI + RotL64(aCross, 37U)) + 305637140752898475U) + aPhaseAOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (((aWandererC + RotL64(aPrevious, 13U)) + RotL64(aCarry, 29U)) + 11948631574496129610U) + aNonceWordI;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 21U)) + RotL64(aCarry, 3U)) + 5321623592482991426U;
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 57U)) + 4075270159062690728U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = (((aWandererF + RotL64(aCross, 3U)) + RotL64(aCarry, 43U)) + 15111580500356908928U) + aNonceWordF;
            aOrbiterH = (aWandererG + RotL64(aIngress, 30U)) + 7244150695504160363U;
            //
            aOrbiterG = (((aOrbiterG + aOrbiterD) + 5131563519577488862U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordP;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 5881954992088651371U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2424421828597294607U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 12780935808751507998U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 12599159643925470226U;
            aOrbiterE = RotL64((aOrbiterE * 17690046932587062701U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 9466589929741834066U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 6093158735705189789U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7453778295800853653U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 17461243886150519249U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 15456408913739900718U;
            aOrbiterH = RotL64((aOrbiterH * 16093292401746174671U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 11260643903290392780U) + aNonceWordO;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 7870342756041882616U;
            aOrbiterG = RotL64((aOrbiterG * 2431528656086173419U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 134484990005888936U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 10626896209992890407U;
            aOrbiterA = RotL64((aOrbiterA * 12034131076645285597U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 14031164129515132292U) + aNonceWordB;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 1771835705730244212U;
            aOrbiterD = RotL64((aOrbiterD * 186981668443596623U), 53U);
            //
            aIngress = RotL64(aOrbiterA, 27U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + RotL64(aOrbiterJ, 20U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterI, 37U)) + aOrbiterE);
            aWandererB = aWandererB + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterE, 51U)) + aOrbiterG);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterA, 5U));
            aWandererC = aWandererC + (((RotL64(aIngress, 10U) + aOrbiterD) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterG, 23U)) + aOrbiterD) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererH = aWandererH + (((((RotL64(aPrevious, 35U) + aOrbiterA) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 3U)) + aNonceWordK) + aPhaseAWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 44U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 46U));
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ aNonceWordP;
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

void TwistExpander_FootBall_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xA7B6EE3B32D30D79ULL + 0xF4EA0DF29A20C409ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xC91D534B1166E48BULL + 0x8D40C14061C24661ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x937167813175CAB7ULL + 0xBA20FD22A29D42FCULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xD3332300E5DD0FC9ULL + 0xAEC9941B134DFA96ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xDA49D2E29A50AC25ULL + 0xE3737440BD12DF1BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xEDC930784734E5C7ULL + 0x934529A01E584539ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xA4CA6E237AE081FBULL + 0x9C360D7C2F887E91ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xA37F87B41DDF0617ULL + 0x9C59C0DD27C76EE2ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x8E35C0D05B775DBDULL + 0xF384FF3BF77CA4A9ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xDEDE8799661F705BULL + 0xC67B338CF19F152DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xD566D6BEB5F87A03ULL + 0xA3D0D0CFACEE9B3AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xC15EBB9BC7110CE9ULL + 0xEE09DDD53927BD8EULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x88D7759A8E7D6AF7ULL + 0x9100E128B6513285ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xE69FEFA5BABDA0D9ULL + 0xB23CEFFFA8B35D74ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x91A719768F09A871ULL + 0xF1031F681E8F9087ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xDDA3396F9519BA01ULL + 0xA9EF4F6BABC94017ULL);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 525U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneC[((aIndex + 5015U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4708U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 3532U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aPrevious, 11U)) + (RotL64(aCarry, 24U) + RotL64(aIngress, 39U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterB = ((aWandererH + RotL64(aIngress, 47U)) + RotL64(aCarry, 35U)) + 11210042748013785976U;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 13U)) + 4584747303233477454U) + aPhaseBOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aCross, 24U)) + 8878765929792969517U) + aNonceWordJ;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 23U)) + 2172232330280041122U;
            aOrbiterA = (((aWandererF + RotL64(aCross, 37U)) + RotL64(aCarry, 57U)) + 8378937026022264016U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 8683007464695824208U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 9564352997357118134U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17869948990449143305U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 11713878436769887528U) + aNonceWordF;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 8052917623074021077U;
            aOrbiterB = RotL64((aOrbiterB * 7450115139081623477U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 7720597162792145185U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 2602847785328475621U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14065077077207224525U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 17813669222300509724U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 8724263063156573013U;
            aOrbiterI = RotL64((aOrbiterI * 3632927017737834359U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 6882429835961613492U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 13213313479525717359U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2411431247725974895U), 19U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterI, 13U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 26U));
            aIngress = aIngress + RotL64(aOrbiterD, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterD, 21U)) + aNonceWordI) + aPhaseBWandererUpdateSaltF[((aIndex + 12U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterG, 11U)) + RotL64(aCarry, 29U)) + aNonceWordN);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterA, 30U)) + aOrbiterG) + aPhaseBWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 13U) + RotL64(aOrbiterB, 3U)) + aOrbiterD) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 56U) + aOrbiterI) + RotL64(aOrbiterA, 41U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordM);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 5554U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10256U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8855U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10232U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 56U) + RotL64(aCross, 27U)) ^ (RotL64(aIngress, 39U) ^ RotL64(aCarry, 13U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterG = ((((aWandererF + RotL64(aIngress, 19U)) + RotL64(aCarry, 39U)) + 12775735908960052604U) + aPhaseBOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1]) + aNonceWordP;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 27U)) + 11791373812080296887U;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 46U)) + RotL64(aCarry, 11U)) + 5537362877706057303U;
            aOrbiterE = ((aWandererI + RotL64(aScatter, 11U)) + RotL64(aCarry, 53U)) + 2023912048504189380U;
            aOrbiterB = ((aWandererG + RotL64(aCross, 57U)) + 17668828109963766893U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 558908629933941224U) + aNonceWordK;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 1479633119685446888U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4447153373540811385U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 15460320397843364063U) + aNonceWordO;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 10059749397555469054U;
            aOrbiterB = RotL64((aOrbiterB * 8671817118586065469U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 9987633811929693924U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 10087337844580228269U) ^ aNonceWordG;
            aOrbiterG = RotL64((aOrbiterG * 13817142288940843815U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 4446204415503364254U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 15106063243302192717U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13273756657334709803U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 9430197906134676162U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 1226048679997253363U;
            aOrbiterE = RotL64((aOrbiterE * 14247538885252664127U), 21U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 57U);
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterG, 13U)) + RotL64(aCarry, 53U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((((RotL64(aCross, 38U) + RotL64(aOrbiterG, 54U)) + aOrbiterB) + aNonceWordC) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterB, 43U)) + RotL64(aCarry, 13U)) + aNonceWordN);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterE, 29U));
            aWandererG = aWandererG + (((RotL64(aScatter, 27U) + aOrbiterC) + RotL64(aOrbiterE, 5U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 48U));
            aCarry = aCarry + RotL64(aWandererK, 27U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 14800U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11728U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12686U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((aIndex + 12180U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aIngress, 24U)) ^ (RotL64(aCarry, 39U) + RotL64(aPrevious, 57U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterB = (((aWandererD + RotL64(aScatter, 36U)) + RotL64(aCarry, 53U)) + 9654059367478508868U) + aPhaseBOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aCross, 3U)) + RotL64(aCarry, 19U)) + 6473006635864677427U;
            aOrbiterC = (aWandererA + RotL64(aIngress, 57U)) + 6944184481315853243U;
            aOrbiterE = ((((aWandererI + RotL64(aPrevious, 11U)) + RotL64(aCarry, 41U)) + 4061496421939102306U) + aPhaseBOrbiterAssignSaltD[((aIndex + 20U)) & S_SALT1]) + aNonceWordA;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 47U)) + 15791809275719085463U) + aNonceWordC;
            //
            aOrbiterB = (((aOrbiterB + aOrbiterH) + 14050798802646323055U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1]) + aNonceWordB;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 12072905924741758266U;
            aOrbiterC = RotL64((aOrbiterC * 4757104346636738119U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 17639076509231343896U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 12195388285571234715U;
            aOrbiterH = RotL64((aOrbiterH * 4317060502521195769U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 4325404419499496529U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 5910567888204238382U;
            aOrbiterB = RotL64((aOrbiterB * 11503787177122206937U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 13092940059929942699U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 13381962590820308761U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6345904465930943295U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 15622862439323440527U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 14027151901132249793U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2273573821630510087U), 19U);
            //
            aIngress = RotL64(aOrbiterE, 21U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 60U));
            aIngress = aIngress + RotL64(aOrbiterI, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 60U) + aOrbiterC) + RotL64(aOrbiterH, 3U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 35U)) + aOrbiterI) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterC, 57U)) + aOrbiterI);
            aWandererI = aWandererI + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 11U)) + aOrbiterB) + RotL64(aCarry, 3U)) + aNonceWordE);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterB, 46U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 17772U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20072U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19629U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16956U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aPrevious, 11U)) ^ (RotL64(aCarry, 24U) + RotL64(aIngress, 39U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterG = ((((aWandererF + RotL64(aIngress, 27U)) + RotL64(aCarry, 47U)) + 11998579547770778580U) + aPhaseBOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1]) + aNonceWordD;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 43U)) + RotL64(aCarry, 11U)) + 8409465187298704610U;
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 18U)) + 3470222286110333500U) + aPhaseBOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aScatter, 5U)) + RotL64(aCarry, 27U)) + 5704486785203069994U;
            aOrbiterK = (aWandererH + RotL64(aCross, 57U)) + 10334944660253279633U;
            //
            aOrbiterG = (((aOrbiterG + aOrbiterJ) + 7626852700722567477U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordI;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 14631310754943209743U;
            aOrbiterE = RotL64((aOrbiterE * 1958866541508493967U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 807160297237854120U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 5624154783624196107U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2404066593958052159U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 4971444394698940423U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 6340057638461027062U;
            aOrbiterD = RotL64((aOrbiterD * 12027586111086798629U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 9003019862787819481U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterK) ^ 13632057463595873033U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 12575202147280216765U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 12766104026871797746U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 4062118445824915939U;
            aOrbiterK = RotL64((aOrbiterK * 13130770039048080701U), 11U);
            //
            aIngress = RotL64(aOrbiterE, 18U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + RotL64(aOrbiterJ, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterJ, 37U)) + aOrbiterE) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterG, 27U)) + aNonceWordH);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 5U)) + aOrbiterK);
            aWandererC = aWandererC + ((((RotL64(aScatter, 24U) + aOrbiterD) + RotL64(aOrbiterG, 58U)) + RotL64(aCarry, 5U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 25048U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24375U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24586U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26169U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 22U) ^ RotL64(aPrevious, 5U)) + (RotL64(aIngress, 57U) ^ RotL64(aCross, 43U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 27U)) + RotL64(aCarry, 11U)) + 15652862298542575895U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 19U)) + 16925323928418184554U) + aNonceWordL;
            aOrbiterB = (((aWandererI + RotL64(aPrevious, 53U)) + RotL64(aCarry, 23U)) + 4413861484961668394U) + aPhaseBOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = (((aWandererA + RotL64(aCross, 42U)) + RotL64(aCarry, 35U)) + 2215946422098155969U) + aNonceWordJ;
            aOrbiterA = (((aWandererE + RotL64(aIngress, 3U)) + 14975185533513111110U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordM;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 9711613814905834552U) + aNonceWordG;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 13154957291850149471U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17049677190793844477U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 5058313016418534840U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 15011423472941211620U;
            aOrbiterA = RotL64((aOrbiterA * 6125316151731105673U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 2030053257469580168U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 150530795186791193U;
            aOrbiterH = RotL64((aOrbiterH * 11106050063717096073U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 10878237472104183427U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 11724672539469573109U;
            aOrbiterG = RotL64((aOrbiterG * 16158741837357985395U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 9589700906445846956U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 1367381624958248949U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8459515089081211977U), 5U);
            //
            aIngress = RotL64(aOrbiterA, 13U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + RotL64(aOrbiterH, 54U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterI, 4U)) + aOrbiterB) + aPhaseBWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 29U)) + aOrbiterA) + RotL64(aCarry, 41U)) + aNonceWordO);
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 44U) + aOrbiterA) + RotL64(aOrbiterG, 19U)) + aNonceWordN) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 23U) + aOrbiterA) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 11U) + aOrbiterB) + RotL64(aOrbiterG, 37U)) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordJ;
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 32732U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((aIndex + 30982U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 32075U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((aIndex + 29184U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 29U) + RotL64(aPrevious, 11U)) ^ (RotL64(aCarry, 57U) + RotL64(aIngress, 42U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterA = (((aWandererB + RotL64(aScatter, 21U)) + RotL64(aCarry, 13U)) + 17711946802293254150U) + aPhaseBOrbiterAssignSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aCross, 39U)) + RotL64(aCarry, 51U)) + 16652362590489569378U;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 60U)) + 6972810344198183097U) + aNonceWordM;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 5U)) + RotL64(aCarry, 35U)) + 13117100889782940546U;
            aOrbiterI = (((aWandererJ + RotL64(aPrevious, 47U)) + 13199305696782626591U) + aPhaseBOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1]) + aNonceWordP;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 992156184392760945U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 13791265442074543880U;
            aOrbiterH = RotL64((aOrbiterH * 1263919538622722673U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 17057087245252294859U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 13444195995883541046U;
            aOrbiterC = RotL64((aOrbiterC * 13067044288608808777U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 6723678233676059420U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterI) ^ 7913379431208430475U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 2295062944289127123U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 4481887195529300665U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 11892724101424384078U;
            aOrbiterJ = RotL64((aOrbiterJ * 3468639499716604111U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 7700902083270424194U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 1888001433557140271U;
            aOrbiterI = RotL64((aOrbiterI * 8975562955027025349U), 29U);
            //
            aIngress = RotL64(aOrbiterJ, 13U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterC, 11U)) + aOrbiterA) + RotL64(aCarry, 47U)) + aPhaseBWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 58U)) + aOrbiterH);
            aWandererD = aWandererD + (((((RotL64(aPrevious, 53U) + aOrbiterA) + RotL64(aOrbiterI, 27U)) + RotL64(aCarry, 3U)) + aNonceWordB) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterC, 39U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 36U) + RotL64(aOrbiterH, 47U)) + aOrbiterA) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordD;
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

void TwistExpander_FootBall_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xDA7AB56A2BB5ED49ULL + 0x8A04862680911ADFULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xED0D91E8F0971BD7ULL + 0xC95092C1F3DA56D9ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xD8CD0CD3799ED695ULL + 0x8AE55FC373E4A6F7ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xC4154AA3E66EA3C3ULL + 0xB0B5CC62C83FAAAEULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xD0486D350149C66FULL + 0x8035FA9EE252EB5DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x9AD26AF4366C9741ULL + 0xB68822B4B2BBA043ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xD8F4310E16762C39ULL + 0xA2C74959475452A7ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x8323414B56BE81FDULL + 0xE761837D559ACFD8ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xF9422ECD8972814DULL + 0xE8F3BACF11503116ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xB95E681C3D758137ULL + 0x9E45E20C85FF6D3BULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xA66184BC13AB9D3BULL + 0x871096B9ABBA25C3ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xDF43F4898232D4F5ULL + 0xE8D1D003F36E6BB9ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xFC6AA93ACC29D2E5ULL + 0x935122F003D188E7ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x94FDB4D54BB26CD5ULL + 0xB3AA50953914D93AULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xB6B0D59D4A8DD157ULL + 0x94747D9F03C74FE3ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xE1C3C2129F3972FFULL + 0xE2F7A3477DA482D2ULL);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 3516U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneC[((aIndex + 2083U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 1744U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneA[((aIndex + 6144U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 6U)) + (RotL64(aCarry, 19U) ^ RotL64(aPrevious, 35U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 10U)) + RotL64(aCarry, 53U)) + 5041131702736607991U;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 19U)) + 9295010428212681446U) + aPhaseCOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aIngress, 35U)) + 6235875895358766017U;
            aOrbiterE = ((aWandererH + RotL64(aCross, 47U)) + 2622227802531866918U) + aNonceWordM;
            aOrbiterC = (((aWandererC + RotL64(aIngress, 40U)) + 3888894734834524972U) + aPhaseCOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1]) + aNonceWordE;
            aOrbiterK = (aWandererD + RotL64(aPrevious, 51U)) + 241682012014701753U;
            aOrbiterH = ((aWandererG + RotL64(aCross, 3U)) + RotL64(aCarry, 21U)) + 15758000422451568079U;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 27U)) + 2061944548396976912U) + aNonceWordB;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 57U)) + RotL64(aCarry, 41U)) + 8177144990755754531U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 554978075608818497U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 250408260560714933U;
            aOrbiterF = RotL64((aOrbiterF * 1295379390497107727U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 8700027645880997552U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 10026130047465480902U;
            aOrbiterK = RotL64((aOrbiterK * 12417270861933696623U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 9785843014096326696U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 9998582683258411251U;
            aOrbiterG = RotL64((aOrbiterG * 7197956237569462269U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 13817734599383455151U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 6647207154174092691U;
            aOrbiterJ = RotL64((aOrbiterJ * 1578528131687283531U), 19U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterG) + 4957715980509035719U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordH;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 4994885315786213197U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5676683798126497011U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 5072908311783966503U) + aNonceWordC;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 5535039946192891515U;
            aOrbiterE = RotL64((aOrbiterE * 2989412783482309753U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 6594577050344146271U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 8750154123258714856U;
            aOrbiterH = RotL64((aOrbiterH * 6942158167127532003U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 3514769314840874873U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 8626045200273524281U;
            aOrbiterB = RotL64((aOrbiterB * 4315441782689789689U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 8524870284841706517U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 1841819423572964209U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9802481758007234681U), 57U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 23U);
            aIngress = aIngress + (RotL64(aOrbiterI, 36U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + RotL64(aOrbiterF, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aPrevious, 43U) + aOrbiterB) + RotL64(aOrbiterG, 51U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 6U) + RotL64(aOrbiterG, 23U)) + aOrbiterK) + aPhaseCWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 14U)) + aOrbiterC) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 13U) + aOrbiterE) + RotL64(aOrbiterF, 47U));
            aWandererK = aWandererK + ((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 39U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 52U) + aOrbiterH) + RotL64(aOrbiterI, 19U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 23U) + RotL64(aOrbiterI, 43U)) + aOrbiterJ) + RotL64(aCarry, 43U)) + aNonceWordD);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 39U) + aOrbiterC) + RotL64(aOrbiterF, 29U));
            aWandererA = aWandererA + (((RotL64(aCross, 57U) + aOrbiterK) + RotL64(aOrbiterH, 6U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + (RotL64(aWandererJ, 30U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordA);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 14280U)) & S_BLOCK1], 36U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 15038U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 10101U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((aIndex + 15683U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 13U) + RotL64(aCarry, 51U)) ^ (RotL64(aCross, 26U) ^ RotL64(aPrevious, 39U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 11U)) + 4179952823252098240U) + aNonceWordN;
            aOrbiterG = ((aWandererB + RotL64(aIngress, 51U)) + RotL64(aCarry, 37U)) + 3745613452332101749U;
            aOrbiterH = ((aWandererI + RotL64(aCross, 37U)) + 2955689793395307176U) + aPhaseCOrbiterAssignSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 3U)) + RotL64(aCarry, 23U)) + 5639060180251322019U;
            aOrbiterB = (aWandererH + RotL64(aCross, 60U)) + 7901969163853586463U;
            aOrbiterK = (((aWandererA + RotL64(aPrevious, 43U)) + RotL64(aCarry, 57U)) + 2242166787816318119U) + aNonceWordC;
            aOrbiterA = (aWandererE + RotL64(aScatter, 27U)) + 5239936443960750064U;
            aOrbiterI = (((aWandererD + RotL64(aIngress, 19U)) + 13939136954732185558U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordD;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 56U)) + 17058884136712717463U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 18148618660054585941U) + aNonceWordI;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 7022023484530327814U;
            aOrbiterH = RotL64((aOrbiterH * 650100011311048589U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 7722084537340095637U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 11764151879690934182U;
            aOrbiterB = RotL64((aOrbiterB * 12264384877711365655U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 16412785901758144708U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 9666718667728274824U;
            aOrbiterA = RotL64((aOrbiterA * 10865799822751771795U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 4307127540152109364U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 2457646804702647606U;
            aOrbiterI = RotL64((aOrbiterI * 6340030928007058595U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 3179394870088602208U) + aNonceWordG;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 504977947273774249U;
            aOrbiterE = RotL64((aOrbiterE * 16190282058883481551U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 16182729401018310837U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 7110817020445860609U;
            aOrbiterD = RotL64((aOrbiterD * 13371352088428584087U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 12960656706837391973U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 7103806893724395904U;
            aOrbiterJ = RotL64((aOrbiterJ * 14365984439655979791U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 1248300178080633527U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 7195473175424961337U;
            aOrbiterK = RotL64((aOrbiterK * 4633558992739305045U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 13007951568242991449U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterE) ^ 10296811247653636372U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterG = RotL64((aOrbiterG * 16469682651380549395U), 57U);
            //
            aIngress = RotL64(aOrbiterD, 47U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 12U));
            aIngress = aIngress + RotL64(aOrbiterG, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterE, 11U)) + aNonceWordF);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 53U)) + aOrbiterK) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 24U) + aOrbiterD) + RotL64(aOrbiterB, 29U));
            aWandererC = aWandererC + (((RotL64(aIngress, 51U) + RotL64(aOrbiterD, 5U)) + aOrbiterG) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterK, 60U)) + aOrbiterA);
            aWandererI = aWandererI + (((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 23U)) + aOrbiterJ) + aPhaseCWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 46U) + RotL64(aOrbiterE, 19U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aPrevious, 5U) + aOrbiterD) + RotL64(aOrbiterH, 35U)) + aNonceWordJ);
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 41U) + RotL64(aOrbiterG, 44U)) + aOrbiterE) + aNonceWordE) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (RotL64(aWandererB, 22U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordE;
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 21729U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((aIndex + 18641U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 24227U)) & S_BLOCK1], 42U) ^ RotL64(aOperationLaneC[((aIndex + 21858U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 24U) + RotL64(aPrevious, 41U)) ^ (RotL64(aCross, 53U) + RotL64(aIngress, 3U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterA = (aWandererG + RotL64(aScatter, 4U)) + 9914837590440975587U;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 57U)) + RotL64(aCarry, 35U)) + 6706125076401958051U;
            aOrbiterF = (((aWandererJ + RotL64(aIngress, 29U)) + RotL64(aCarry, 19U)) + 16570817772679258409U) + aPhaseCOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aCross, 11U)) + 6843705658115186948U;
            aOrbiterB = (aWandererK + RotL64(aPrevious, 47U)) + 16099930446791572351U;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 41U)) + 5420550009556030459U) + aPhaseCOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 24U)) + 5729549069420177477U) + aNonceWordJ;
            aOrbiterE = ((aWandererA + RotL64(aCross, 37U)) + RotL64(aCarry, 47U)) + 15590601126188675834U;
            aOrbiterK = (aWandererD + RotL64(aIngress, 53U)) + 13044027390998620029U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 11068338135659636772U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 6584988841809544332U;
            aOrbiterF = RotL64((aOrbiterF * 1683336180438945439U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 8516813219883915404U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 10647314042912492785U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15559481057047148785U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 201691689889605304U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 15512161798401184003U) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 11473219183982564709U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 3883760518944464145U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 13861805129175491145U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17194438894492581181U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 12019138626550801486U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 13030350224959652248U;
            aOrbiterB = RotL64((aOrbiterB * 11724200983306280107U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 2643807255422544248U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 4127143302485631794U;
            aOrbiterI = RotL64((aOrbiterI * 5441038881111578487U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 14602951930809633069U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 4555737199162278494U;
            aOrbiterJ = RotL64((aOrbiterJ * 12415825635220991865U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 6343143902997169834U) + aNonceWordM;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 10404783711336491985U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6235474458879439079U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 7406959231434835393U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 6684368109277850196U;
            aOrbiterK = RotL64((aOrbiterK * 8760360417572331159U), 19U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterK, 13U);
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterG, 30U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterA, 51U)) + aOrbiterG) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 58U) + RotL64(aOrbiterF, 26U)) + aOrbiterE) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 21U)) + aOrbiterA);
            aWandererF = aWandererF + ((RotL64(aScatter, 53U) + RotL64(aOrbiterD, 39U)) + aOrbiterA);
            aWandererK = aWandererK ^ ((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterF, 57U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterB, 6U)) + aNonceWordD) + aPhaseCWandererUpdateSaltB[((aIndex + 16U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 10U) + RotL64(aOrbiterB, 47U)) + aOrbiterG);
            aWandererH = aWandererH + (((RotL64(aScatter, 23U) + RotL64(aOrbiterI, 43U)) + aOrbiterB) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterB, 35U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (RotL64(aWandererG, 10U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 35U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 32092U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((aIndex + 27890U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29035U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 30052U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCross, 60U)) + (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 47U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterH = (aWandererK + RotL64(aPrevious, 13U)) + 13053031069776604052U;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 19U)) + 1331396630251085122U) + aNonceWordM;
            aOrbiterB = (aWandererF + RotL64(aScatter, 36U)) + 15879286043343942393U;
            aOrbiterK = (((aWandererJ + RotL64(aCross, 23U)) + RotL64(aCarry, 51U)) + 13590365633321406830U) + aNonceWordO;
            aOrbiterJ = (((aWandererA + RotL64(aScatter, 47U)) + RotL64(aCarry, 27U)) + 14569235423040242618U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = (((aWandererG + RotL64(aPrevious, 3U)) + RotL64(aCarry, 43U)) + 11397370636618371560U) + aNonceWordE;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 57U)) + 3455933494593971847U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = (aWandererC + RotL64(aCross, 52U)) + 1307153376443784593U;
            aOrbiterF = (aWandererB + RotL64(aPrevious, 41U)) + 10688618762584786871U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 17746248451153600096U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 8512568600755410158U;
            aOrbiterB = RotL64((aOrbiterB * 16648320170768234063U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 8950230550112591092U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 17790968369472845496U) ^ aNonceWordP;
            aOrbiterJ = RotL64((aOrbiterJ * 5104988920132008913U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 12583323865381967534U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 11243927099685293887U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12867003042486433971U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 9690268715525781389U) + aNonceWordD;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 7466066217365074653U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17565696765505320889U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 3673528673209875118U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 14079103852360952255U;
            aOrbiterK = RotL64((aOrbiterK * 17449228863409999629U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 6747836856132250630U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 5027692924422297153U;
            aOrbiterI = RotL64((aOrbiterI * 2492421273167124437U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 11370341866003395776U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 14013204893442579282U;
            aOrbiterD = RotL64((aOrbiterD * 6602239957997240785U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 3436953430697936790U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 6399073534839993637U;
            aOrbiterF = RotL64((aOrbiterF * 14186050072610021241U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 7054057507823631422U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 5752085719673338095U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13252660162476029593U), 29U);
            //
            aIngress = RotL64(aOrbiterF, 50U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterE, 18U)) + aOrbiterK) + aNonceWordA);
            aWandererI = aWandererI + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 11U)) + aOrbiterH) + RotL64(aCarry, 21U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterB, 29U));
            aWandererH = aWandererH + (((RotL64(aScatter, 52U) + RotL64(aOrbiterJ, 47U)) + aOrbiterF) + aPhaseCWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterA, 57U)) + aOrbiterJ);
            aWandererC = aWandererC + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterH, 5U)) + aOrbiterK) + RotL64(aCarry, 29U)) + aNonceWordJ);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterE, 23U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 39U) + aOrbiterJ) + RotL64(aOrbiterK, 51U)) + aPhaseCWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 48U) + aOrbiterH) + RotL64(aOrbiterB, 38U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 50U));
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + RotL64(aWandererF, 60U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordF);
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

void TwistExpander_FootBall_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xEC4E6CC78FBF3A9BULL + 0xA371B969AA97DB53ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xBAA83E1CDAA86D19ULL + 0xF4B46C2080A46020ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xCD16A4BB029BE603ULL + 0xDC98D7DFF04D291CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x83AFB39A34848997ULL + 0xEEAB0EA2F5CC3D6DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xB1E41C036D61E4E3ULL + 0xF81E7AB44F9CF3F1ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB1A04C694A184827ULL + 0xE61E9894434E9581ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x924AD6744B6001D5ULL + 0x90486CCE1C7A08C2ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x87CFE2F5ECB0CB4DULL + 0x9366F38AA28AC401ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xF32170DB94918DE1ULL + 0x9AD022AA0328D703ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xA344FC01D39FBF99ULL + 0xFC839D3E11D85DA8ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xDF1AE4BA329C811BULL + 0x8BE7189D6F8EC617ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xAEE271FDCE72BF59ULL + 0xBAC2F8D162E1DA94ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x8C3CB45EBDC7D279ULL + 0xD984C206353F25F4ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x8D18D785E2CB1CFFULL + 0xAF26513CC3ECB51DULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x9A814C382B8D4401ULL + 0xFA47399E908CFBCCULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xD838F85BCE9D4EDBULL + 0xEB11863F1483B0CCULL);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4236U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneC[((aIndex + 2614U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3304U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneA[((aIndex + 1143U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 27U) + RotL64(aIngress, 6U)) ^ (RotL64(aCross, 41U) + RotL64(aPrevious, 57U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterH = (aWandererE + RotL64(aIngress, 23U)) + 479672811032092393U;
            aOrbiterI = (aWandererH + RotL64(aScatter, 58U)) + 18061121631394564425U;
            aOrbiterB = (aWandererC + RotL64(aCross, 53U)) + 14237400452740566065U;
            aOrbiterK = (((aWandererA + RotL64(aPrevious, 51U)) + RotL64(aCarry, 37U)) + 6723123812257706134U) + aPhaseDOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aCross, 11U)) + RotL64(aCarry, 53U)) + 4247997188026499248U;
            aOrbiterE = (aWandererJ + RotL64(aIngress, 18U)) + 1939107415066134869U;
            aOrbiterD = (aWandererK + RotL64(aPrevious, 47U)) + 3912640123546395979U;
            aOrbiterA = (aWandererG + RotL64(aScatter, 43U)) + 8295478436553964298U;
            aOrbiterG = ((((aWandererI + RotL64(aIngress, 35U)) + RotL64(aCarry, 19U)) + 3218960600711526885U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordG;
            aOrbiterJ = (aWandererF + RotL64(aCross, 13U)) + 5874096203353388890U;
            aOrbiterF = (aWandererB + RotL64(aPrevious, 29U)) + 10294536533673023358U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 11268561953904130747U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 16693201256788898423U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16291987237693567209U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 7550969634681894654U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 9501647424602245869U;
            aOrbiterE = RotL64((aOrbiterE * 11265865222096866605U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 8881869255994319423U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 16770136406906800016U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1782039587385512923U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 16185384746435761363U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 13841034186650721627U;
            aOrbiterK = RotL64((aOrbiterK * 12000155593277035447U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 15229062695864608309U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 3576122704615303733U;
            aOrbiterD = RotL64((aOrbiterD * 2433987493885779279U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 13898167174453181224U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 12878032061609524049U) ^ aNonceWordN;
            aOrbiterG = RotL64((aOrbiterG * 18104665741338251495U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 12719156051299028649U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 8640980843376950769U;
            aOrbiterF = RotL64((aOrbiterF * 10242616778390983333U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 12133332160916004365U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 8743563985229104484U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4575129690615054691U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 7362223873479167793U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 4230720394788635807U;
            aOrbiterC = RotL64((aOrbiterC * 3658720603716856293U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 5095842824285329272U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 7483469517256234638U;
            aOrbiterA = RotL64((aOrbiterA * 9782114499878763883U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 17426017004856399653U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 479672811032092393U;
            aOrbiterJ = RotL64((aOrbiterJ * 14921028515589317919U), 53U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 5U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 56U));
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 20U) + aOrbiterB) + RotL64(aOrbiterF, 41U));
            aWandererD = aWandererD + (((((RotL64(aScatter, 51U) + RotL64(aOrbiterC, 5U)) + aOrbiterI) + RotL64(aCarry, 5U)) + aNonceWordD) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 23U) + aOrbiterG) + RotL64(aOrbiterJ, 11U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 23U)) + aOrbiterB) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterK, 47U)) + aOrbiterE);
            aWandererH = aWandererH + ((RotL64(aScatter, 27U) + aOrbiterE) + RotL64(aOrbiterJ, 54U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 37U)) + aOrbiterG);
            aWandererB = aWandererB + ((RotL64(aPrevious, 11U) + aOrbiterD) + RotL64(aOrbiterA, 39U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 3U) + aOrbiterJ) + RotL64(aOrbiterK, 43U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 60U) + aOrbiterA) + RotL64(aOrbiterI, 50U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterA, 3U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 30U));
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 54U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererF, 41U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 8461U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10673U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5559U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((aIndex + 7851U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 40U)) ^ (RotL64(aCross, 57U) + RotL64(aPrevious, 27U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterC = (aWandererA + RotL64(aPrevious, 60U)) + 12380376990224645149U;
            aOrbiterD = (((aWandererJ + RotL64(aCross, 57U)) + 18296928500297384014U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordI;
            aOrbiterI = (aWandererH + RotL64(aScatter, 37U)) + 3550626816361145100U;
            aOrbiterA = (aWandererG + RotL64(aIngress, 51U)) + 2667792936946706027U;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 46U)) + RotL64(aCarry, 39U)) + 12020969779370926953U;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 13U)) + 737340727886903447U) + aNonceWordJ;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 41U)) + RotL64(aCarry, 35U)) + 1681797651799760502U;
            aOrbiterJ = (((aWandererE + RotL64(aCross, 29U)) + RotL64(aCarry, 53U)) + 2956186342689489064U) + aPhaseDOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aPrevious, 21U)) + 1876852870402977177U;
            aOrbiterF = (aWandererK + RotL64(aScatter, 19U)) + 6433205819353555071U;
            aOrbiterH = (aWandererF + RotL64(aIngress, 11U)) + 9065076854974222998U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 3254410578766789992U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 2005081975473815576U;
            aOrbiterI = RotL64((aOrbiterI * 9947701153722014085U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 15992999234834560419U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 3458344156815120948U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1668460113964608051U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 17069783053664877727U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 1260234710193913099U;
            aOrbiterK = RotL64((aOrbiterK * 4561226779897414381U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 3825186451876061335U) + aNonceWordN;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 2905344294992827535U;
            aOrbiterG = RotL64((aOrbiterG * 2469896090698580795U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 18141402347899180617U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterF) ^ 8760129857609925066U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterE = RotL64((aOrbiterE * 2507999156108123047U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 594052473780678210U) + aNonceWordM;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 13216719212966128379U;
            aOrbiterC = RotL64((aOrbiterC * 10691355329696722303U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 10029948739466316169U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 11912428807431992996U;
            aOrbiterA = RotL64((aOrbiterA * 85016510811938307U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 8735634019801417287U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 12785916159063273545U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1161917531260663357U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 367752057919802452U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 3961036242431041564U;
            aOrbiterJ = RotL64((aOrbiterJ * 16352646009782597315U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 3858415336170090719U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 14325258358254321551U;
            aOrbiterF = RotL64((aOrbiterF * 12080431158781060059U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 16872184337970977180U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 12380376990224645149U;
            aOrbiterH = RotL64((aOrbiterH * 16559121155413059221U), 11U);
            //
            aIngress = RotL64(aOrbiterH, 43U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 4U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + RotL64(aOrbiterF, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 39U) + aOrbiterF) + RotL64(aOrbiterK, 41U)) + aNonceWordP);
            aWandererB = aWandererB + (((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 53U)) + aOrbiterA) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 43U)) + aOrbiterI) + aNonceWordC);
            aWandererD = aWandererD + (((RotL64(aCross, 28U) + RotL64(aOrbiterK, 57U)) + aOrbiterH) + aNonceWordF);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 5U) + aOrbiterH) + RotL64(aOrbiterA, 39U));
            aWandererF = aWandererF + ((((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 27U)) + aPhaseDWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterC, 50U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 37U) + RotL64(aOrbiterI, 35U)) + aOrbiterG);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterD, 23U)) + aOrbiterE);
            aWandererH = aWandererH + ((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 11U)) + aOrbiterB);
            aWandererG = aWandererG ^ ((RotL64(aCross, 10U) + aOrbiterD) + RotL64(aOrbiterI, 4U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 44U));
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererG, 21U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordG);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 13521U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 12309U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16103U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((aIndex + 12126U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 53U)) + (RotL64(aCross, 11U) + RotL64(aIngress, 24U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterK = ((aWandererH + RotL64(aCross, 27U)) + RotL64(aCarry, 19U)) + 5480870806135400132U;
            aOrbiterI = (((aWandererB + RotL64(aScatter, 53U)) + 8034874599430768743U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordI;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 6U)) + RotL64(aCarry, 27U)) + 4006919843736863767U;
            aOrbiterA = (aWandererK + RotL64(aPrevious, 11U)) + 2988069748674633718U;
            aOrbiterF = (aWandererC + RotL64(aIngress, 35U)) + 12347295651973135786U;
            aOrbiterC = (((aWandererI + RotL64(aScatter, 47U)) + RotL64(aCarry, 39U)) + 14152683894431568192U) + aNonceWordM;
            aOrbiterJ = (aWandererE + RotL64(aCross, 51U)) + 15765143815254196598U;
            aOrbiterB = (aWandererF + RotL64(aPrevious, 38U)) + 10473067082331244233U;
            aOrbiterH = (aWandererD + RotL64(aIngress, 21U)) + 1089466925383677249U;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 43U)) + 13215039929873682230U) + aPhaseDOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 29U)) + 3957997712247961479U) + aNonceWordB;
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 10023907397941685546U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterK) ^ 14593012591254614353U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterE = RotL64((aOrbiterE * 17111300092082154687U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 13353797968154036726U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 9259966668512102858U;
            aOrbiterC = RotL64((aOrbiterC * 8326732574268308221U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 10757861831070349321U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 10530223113483866178U;
            aOrbiterI = RotL64((aOrbiterI * 11269177745265396583U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 7554320926405521865U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 6978052067277966996U;
            aOrbiterF = RotL64((aOrbiterF * 18020134738536217801U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 1053695861967171420U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 15980734683539854451U;
            aOrbiterB = RotL64((aOrbiterB * 3208466640010555357U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 17041258393808061556U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 12846551858751995530U;
            aOrbiterG = RotL64((aOrbiterG * 9303891433380993639U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 14617434286683320666U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 3999309956180741302U;
            aOrbiterK = RotL64((aOrbiterK * 15037707937050015205U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 13452627760403094126U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 2633241575260427158U;
            aOrbiterA = RotL64((aOrbiterA * 2638570213290747581U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 15575035993965639421U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 7829837426112185905U) ^ aNonceWordC;
            aOrbiterJ = RotL64((aOrbiterJ * 17059814556114938275U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 12565466096663867876U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 4845209979900289818U) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 14990494169374347835U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 13472490162287247012U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 5480870806135400132U;
            aOrbiterD = RotL64((aOrbiterD * 9150331893094034245U), 37U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 19U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 58U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterC, 41U)) + aOrbiterJ);
            aWandererF = aWandererF + ((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterB, 13U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterG, 52U)) + aOrbiterD);
            aWandererD = aWandererD + ((RotL64(aScatter, 53U) + RotL64(aOrbiterC, 43U)) + aOrbiterB);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 14U) + aOrbiterC) + RotL64(aOrbiterE, 47U)) + aNonceWordP);
            aWandererI = aWandererI + ((RotL64(aScatter, 37U) + RotL64(aOrbiterI, 57U)) + aOrbiterH);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 35U)) + aOrbiterK);
            aWandererJ = aWandererJ + (((RotL64(aCross, 43U) + RotL64(aOrbiterA, 19U)) + aOrbiterB) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 29U) + aOrbiterE) + RotL64(aOrbiterK, 11U)) + aPhaseDWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 39U) + RotL64(aOrbiterA, 39U)) + aOrbiterJ) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 24U) + aOrbiterG) + RotL64(aOrbiterH, 28U)) + aPhaseDWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 56U));
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + RotL64(aWandererF, 30U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 21672U)) & S_BLOCK1], 24U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 20769U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 17524U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19042U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 54U) + RotL64(aCarry, 41U)) + (RotL64(aIngress, 23U) ^ RotL64(aCross, 3U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterF = (aWandererD + RotL64(aPrevious, 39U)) + 12535417189990029950U;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 35U)) + RotL64(aCarry, 57U)) + 6204401443676390273U;
            aOrbiterH = (aWandererI + RotL64(aScatter, 48U)) + 869613505613154672U;
            aOrbiterA = (((aWandererK + RotL64(aCross, 23U)) + RotL64(aCarry, 27U)) + 15053590879563855802U) + aNonceWordN;
            aOrbiterG = (((aWandererJ + RotL64(aIngress, 13U)) + 13338989605204591428U) + aPhaseDOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1]) + aNonceWordF;
            aOrbiterE = (aWandererH + RotL64(aScatter, 11U)) + 18306470022403825392U;
            aOrbiterK = (aWandererA + RotL64(aPrevious, 53U)) + 1150696349434090218U;
            aOrbiterC = ((aWandererE + RotL64(aCross, 46U)) + 13549541786420596437U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = (aWandererB + RotL64(aScatter, 57U)) + 14302878430259588461U;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 5U)) + RotL64(aCarry, 11U)) + 4660437084477165225U;
            aOrbiterD = (aWandererF + RotL64(aIngress, 29U)) + 1653628537860912069U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 5594199757006711631U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 11008472193138708891U;
            aOrbiterH = RotL64((aOrbiterH * 13645764762027798301U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 3668516817279364310U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 128159531749679984U;
            aOrbiterG = RotL64((aOrbiterG * 4523246859249826987U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 6378674346113979108U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 11438762460659123362U;
            aOrbiterE = RotL64((aOrbiterE * 2733309638158283953U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 10624263004446482910U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 12546839706919241411U;
            aOrbiterK = RotL64((aOrbiterK * 11468326687628079347U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 8466639576503293921U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 5828694979857951504U;
            aOrbiterC = RotL64((aOrbiterC * 7835487310289634515U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 16496305151014092976U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 589464613876410567U;
            aOrbiterJ = RotL64((aOrbiterJ * 13190816610718051897U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 4168532743415647825U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 15944887793736489375U;
            aOrbiterI = RotL64((aOrbiterI * 17273403561158196717U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 11642456814106259483U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 1609897693632334867U;
            aOrbiterD = RotL64((aOrbiterD * 12912773555616819941U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 14950238412766325479U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 11862438528287402255U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7635864312080265695U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 5900629306795222263U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 3221591991392500536U) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 7188525011266868855U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 16938699391746264010U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 12535417189990029950U;
            aOrbiterA = RotL64((aOrbiterA * 18212319484142613215U), 57U);
            //
            aIngress = RotL64(aOrbiterH, 34U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 39U));
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 6U) + RotL64(aOrbiterA, 21U)) + aOrbiterB);
            aWandererK = aWandererK + ((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterB, 35U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 60U)) + aOrbiterI) + aNonceWordH);
            aWandererG = aWandererG + (((RotL64(aCross, 11U) + RotL64(aOrbiterI, 5U)) + aOrbiterD) + aPhaseDWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 37U)) + aOrbiterJ) + aNonceWordM);
            aWandererC = aWandererC + (((RotL64(aCross, 39U) + RotL64(aOrbiterH, 39U)) + aOrbiterC) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 43U)) + aOrbiterD) + aPhaseDWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 48U) + RotL64(aOrbiterF, 3U)) + aOrbiterC) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterG, 53U)) + aOrbiterI);
            aWandererA = aWandererA + ((RotL64(aIngress, 53U) + RotL64(aOrbiterK, 18U)) + aOrbiterH);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 37U) + aOrbiterJ) + RotL64(aOrbiterA, 29U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (RotL64(aWandererF, 50U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + RotL64(aWandererB, 22U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 24558U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21917U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 23411U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneA[((aIndex + 23442U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 27U) ^ RotL64(aCarry, 51U)) + (RotL64(aCross, 4U) ^ RotL64(aPrevious, 39U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterK = ((aWandererK + RotL64(aScatter, 5U)) + RotL64(aCarry, 53U)) + 13687218104610230596U;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 19U)) + 6841550124960692709U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aIngress, 30U)) + 17418968668458764131U) + aNonceWordK;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 43U)) + 8303537912696948204U;
            aOrbiterB = (aWandererG + RotL64(aIngress, 23U)) + 12376614417285936537U;
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 35U)) + RotL64(aCarry, 5U)) + 14215749063579232654U;
            aOrbiterE = ((aWandererI + RotL64(aScatter, 39U)) + 4111736931433665347U) + aPhaseDOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aCross, 56U)) + 11250375934571631522U;
            aOrbiterA = (aWandererD + RotL64(aScatter, 51U)) + 5367367837773331275U;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 13U)) + 15514089192382674434U) + aNonceWordC;
            aOrbiterG = ((aWandererF + RotL64(aCross, 47U)) + RotL64(aCarry, 13U)) + 1475991716685034960U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 5531622777788629748U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 8363822215908303335U;
            aOrbiterI = RotL64((aOrbiterI * 17850203366840994883U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 3741256932685720414U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 11634667238062155772U;
            aOrbiterD = RotL64((aOrbiterD * 15925089729784547403U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 18180546911210417155U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 5123234656838556335U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15362857462853398025U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 11215734271189250284U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 16863747802158398092U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1828035970246160023U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 9859050606636646323U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 9331300036643654675U) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 2502263410556166281U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 15028845665427209759U) + aNonceWordE;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 8916444839488901676U;
            aOrbiterH = RotL64((aOrbiterH * 6646561894156038791U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 8024631140949068570U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 1116378858490660031U;
            aOrbiterE = RotL64((aOrbiterE * 4247798531910227367U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 5066486214537899212U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 9346312092322423057U;
            aOrbiterA = RotL64((aOrbiterA * 13443190089768875191U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 11651011617027950122U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 11308862427412671711U;
            aOrbiterG = RotL64((aOrbiterG * 12167147966934334703U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 3850136281462840708U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 13461307727665667424U;
            aOrbiterJ = RotL64((aOrbiterJ * 10788040812090673421U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 17824744996404571928U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 13687218104610230596U;
            aOrbiterB = RotL64((aOrbiterB * 325803029547254631U), 27U);
            //
            aIngress = RotL64(aOrbiterB, 60U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + (RotL64(aOrbiterK, 41U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aScatter, 27U) + RotL64(aOrbiterA, 37U)) + aOrbiterC);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 6U) + RotL64(aOrbiterA, 39U)) + aOrbiterK);
            aWandererA = aWandererA + ((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 35U)) + aOrbiterF);
            aWandererD = aWandererD ^ ((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterH, 4U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 57U)) + aOrbiterB) + RotL64(aCarry, 43U)) + aPhaseDWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 11U) + aOrbiterH) + RotL64(aOrbiterD, 43U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterC, 41U)) + aOrbiterB) + RotL64(aCarry, 27U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterA, 23U)) + aOrbiterD);
            aWandererC = aWandererC + ((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterI, 54U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 23U) + aOrbiterG) + RotL64(aOrbiterI, 19U)) + aNonceWordL);
            aWandererH = aWandererH + (((RotL64(aPrevious, 60U) + aOrbiterF) + RotL64(aOrbiterH, 27U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + (RotL64(aWandererG, 38U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + RotL64(aWandererD, 5U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordP);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 27393U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((aIndex + 29822U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27744U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneB[((aIndex + 32091U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aIngress, 57U)) ^ (RotL64(aPrevious, 6U) + RotL64(aCarry, 35U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterJ = (aWandererA + RotL64(aScatter, 24U)) + 3621877681473089725U;
            aOrbiterH = (aWandererD + RotL64(aCross, 19U)) + 4451752751536414717U;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 39U)) + 11371625415377772117U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = (((aWandererK + RotL64(aPrevious, 21U)) + RotL64(aCarry, 19U)) + 6046792758881150619U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aIngress, 51U)) + 8213166120394461682U;
            aOrbiterA = (((aWandererI + RotL64(aScatter, 3U)) + RotL64(aCarry, 23U)) + 4343156661140422645U) + aNonceWordA;
            aOrbiterG = (aWandererH + RotL64(aPrevious, 37U)) + 11105271483234947905U;
            aOrbiterE = (aWandererG + RotL64(aCross, 29U)) + 348904609985341372U;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 5U)) + 12924652822526858767U) + aNonceWordG;
            aOrbiterD = (aWandererE + RotL64(aIngress, 43U)) + 7461211697358520287U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 46U)) + RotL64(aCarry, 53U)) + 16551553555297890558U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 11908056404140782995U) + aNonceWordM;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 9147367258259948715U;
            aOrbiterC = RotL64((aOrbiterC * 10777628928376261667U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 8876461054692728610U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 10546855952702525404U;
            aOrbiterI = RotL64((aOrbiterI * 10071104785895309677U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 4748636139110443794U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 783046909529525098U;
            aOrbiterA = RotL64((aOrbiterA * 8969157702460927215U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 16683965945838696665U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 12385412690177109575U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10795062772707143187U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 8210546822184469023U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 13146493623236979963U;
            aOrbiterE = RotL64((aOrbiterE * 13199947810161148155U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 13857628148804187115U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 7241297989337473475U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16223448508809614229U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 773904571213804946U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 7660676598236419707U;
            aOrbiterD = RotL64((aOrbiterD * 14467390638468925567U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 16822672435156055469U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 6514707119190640433U;
            aOrbiterB = RotL64((aOrbiterB * 7097496727567460535U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 17784153215885060832U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 16027189961519690419U;
            aOrbiterJ = RotL64((aOrbiterJ * 3248782394761733169U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 821916530432611671U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 8764650990196504963U;
            aOrbiterH = RotL64((aOrbiterH * 6269514974278082251U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 5987370764866753332U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 3621877681473089725U;
            aOrbiterK = RotL64((aOrbiterK * 14763908964222787377U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 24U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + (RotL64(aOrbiterG, 21U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + RotL64(aOrbiterF, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 46U) + RotL64(aOrbiterF, 21U)) + aOrbiterC);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 41U) + aOrbiterB) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 37U) + aOrbiterG) + RotL64(aOrbiterJ, 11U));
            aWandererG = aWandererG + ((RotL64(aIngress, 21U) + RotL64(aOrbiterI, 56U)) + aOrbiterA);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 29U)) + aOrbiterG);
            aWandererH = aWandererH + ((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 23U)) + aOrbiterE);
            aWandererB = aWandererB ^ (((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterC, 51U)) + aPhaseDWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 56U) + RotL64(aOrbiterD, 3U)) + aOrbiterG) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterK, 48U)) + aOrbiterH);
            aWandererI = aWandererI + (((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 13U)) + aOrbiterK) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 5U)) + aOrbiterH) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 34U));
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 24U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ aNonceWordO;
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

void TwistExpander_FootBall_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xC162FF85861EF0A7ULL + 0x8288F464BB9D8F24ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xA036DEED179803F5ULL + 0xDC67550CB66EDD1CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xEBBC3D6839891823ULL + 0x9B31C7FB1538CA04ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xF6A2F6C1C3991D6DULL + 0x913A6334128B3679ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xA0EE4CA37F5BB6D3ULL + 0xF5DED0C874B696DDULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xEF1D1DBD1215F4A7ULL + 0x81C96943C5186CAAULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xF744548205F0EA3BULL + 0xF19FF131300C00F6ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x9506713D3357028FULL + 0xFEAD186B9E51E0E7ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x8F8835F5A8867AEFULL + 0xED9F0B352A5E1128ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xCC7E2C0F72A2905BULL + 0xF47B835A313F3DA6ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x8EE0D706D31C6035ULL + 0xF20E5DE169228569ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xA35F21B03F22BAC5ULL + 0xAF2289E5587FCA7CULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xB40B3A6A63D7A2D5ULL + 0xC320F4394929BF66ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x9CC1EB1086E9FDC3ULL + 0xA940805CA9FB6106ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xCFF4B39FA75B3771ULL + 0xBCD687DD71AD851CULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xE91AC15076FAD50BULL + 0x8F34FC5CC1693C6BULL);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 5276U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 2798U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 4603U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 1349U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 24U) ^ RotL64(aPrevious, 57U)) + (RotL64(aCarry, 41U) + RotL64(aIngress, 5U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 35U)) + 6318740973868639425U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aCross, 26U)) + 5487840061430920881U;
            aOrbiterF = (aWandererE + RotL64(aIngress, 13U)) + 10258706763248072672U;
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 21U)) + 18356875269730338208U) + aPhaseEOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = ((aWandererD + RotL64(aCross, 51U)) + RotL64(aCarry, 3U)) + 12883160282903147010U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 47U)) + 1010140474942697730U) + aNonceWordE;
            aOrbiterB = ((aWandererF + RotL64(aIngress, 41U)) + RotL64(aCarry, 29U)) + 17733939421700898293U;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 23U)) + 13693055887924981201U) + aNonceWordD;
            aOrbiterA = (aWandererA + RotL64(aIngress, 19U)) + 14574732452793385269U;
            aOrbiterI = ((aWandererI + RotL64(aCross, 37U)) + 10832873941223609012U) + aNonceWordG;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 54U)) + RotL64(aCarry, 11U)) + 8212600587135328040U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 5312744319781971178U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 6173741211706546923U;
            aOrbiterF = RotL64((aOrbiterF * 12854414066390848249U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 3693249147883790810U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 18365859989736602556U;
            aOrbiterC = RotL64((aOrbiterC * 3348463719324104997U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 10645056678337549771U) + aNonceWordM;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 1175668356822251045U;
            aOrbiterD = RotL64((aOrbiterD * 6579675292775345579U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 13556844570541823717U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 4790355739411849736U;
            aOrbiterJ = RotL64((aOrbiterJ * 4083544011788850307U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 14905575502272644116U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 17047244574558476634U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2356386971503880047U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 10161614295718414869U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 13413914082651612468U;
            aOrbiterA = RotL64((aOrbiterA * 16224039093981079491U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 6072693130156927774U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 4333656233793103787U;
            aOrbiterE = RotL64((aOrbiterE * 9374745547133955709U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 17209776289202130250U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 11752001118070361543U;
            aOrbiterG = RotL64((aOrbiterG * 4416523594812872339U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 15367365111105608277U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 8650687767097460704U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11430451559660578667U), 19U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterA) + 18074648514448405693U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1]) + aNonceWordL;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 10857586858462237581U;
            aOrbiterH = RotL64((aOrbiterH * 3722891011080095849U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 17219932344278345591U) + aNonceWordF;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 6318740973868639425U;
            aOrbiterI = RotL64((aOrbiterI * 8846295038878812229U), 13U);
            //
            aIngress = RotL64(aOrbiterK, 35U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 60U));
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 43U)) + aNonceWordI) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 38U) + aOrbiterF) + RotL64(aOrbiterH, 3U));
            aWandererE = aWandererE + (((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterF, 14U)) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterF, 21U)) + aOrbiterI);
            aWandererD = aWandererD + (((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterD, 43U)) + aNonceWordC);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 18U) + RotL64(aOrbiterB, 57U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aCross, 5U) + aOrbiterC) + RotL64(aOrbiterF, 39U)) + aNonceWordH);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 46U)) + aOrbiterH) + aPhaseEWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 41U) + aOrbiterC) + RotL64(aOrbiterJ, 5U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterG, 27U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((RotL64(aCross, 53U) + RotL64(aOrbiterE, 37U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 48U));
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 28U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 53U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 10862U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneD[((aIndex + 8898U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 8054U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((aIndex + 7244U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 19U)) + (RotL64(aPrevious, 35U) + RotL64(aCross, 56U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterC = ((aWandererG + RotL64(aScatter, 19U)) + 2101601659597850213U) + aNonceWordP;
            aOrbiterF = (aWandererB + RotL64(aIngress, 37U)) + 2759794072560720121U;
            aOrbiterI = (aWandererH + RotL64(aPrevious, 13U)) + 9443562552411269339U;
            aOrbiterK = ((aWandererF + RotL64(aCross, 43U)) + 10801360546699857975U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aIngress, 51U)) + RotL64(aCarry, 53U)) + 8020716394829332019U;
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 60U)) + 1021894212367773801U;
            aOrbiterA = (aWandererI + RotL64(aCross, 21U)) + 13346855534622490176U;
            aOrbiterB = ((aWandererE + RotL64(aScatter, 27U)) + 16359309548462953836U) + aPhaseEOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = ((aWandererA + RotL64(aCross, 53U)) + RotL64(aCarry, 5U)) + 12642446944680783519U;
            aOrbiterH = ((aWandererK + RotL64(aScatter, 34U)) + RotL64(aCarry, 13U)) + 8197424982767553380U;
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 57U)) + 14346334610901859094U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 14171304260534233539U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 334531601308283605U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5012968232749075075U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 10707856298471572695U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 18364775750091914766U;
            aOrbiterF = RotL64((aOrbiterF * 15735143943129143265U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 8531394793118363836U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 15352876929406908882U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 475199047053777179U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 567682016232278157U) + aNonceWordD;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 2068146551757663119U;
            aOrbiterA = RotL64((aOrbiterA * 1557877740957797555U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 7776122587613256525U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 16430938890724272256U;
            aOrbiterG = RotL64((aOrbiterG * 4540270493783593257U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 11912000645055436094U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 16800749242578741498U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17804584625034241737U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 5909199180260499150U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 5751089915336865588U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15376689503142397927U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 3478216857728853008U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 18007567146937338241U;
            aOrbiterJ = RotL64((aOrbiterJ * 6620498877303917855U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 17454259424163653490U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 6276120962018305311U;
            aOrbiterB = RotL64((aOrbiterB * 7560618224285018801U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 3839336239901666431U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 6230149015045237670U;
            aOrbiterH = RotL64((aOrbiterH * 1838983748994340883U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 17552095486612766544U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 2101601659597850213U;
            aOrbiterD = RotL64((aOrbiterD * 2915330118061857271U), 35U);
            //
            aIngress = RotL64(aOrbiterJ, 12U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 37U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + RotL64(aOrbiterC, 60U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 20U) + aOrbiterI) + RotL64(aOrbiterB, 43U)) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterJ, 3U)) + aOrbiterI) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 23U)) + aOrbiterF);
            aWandererG = aWandererG ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterB, 40U)) + aOrbiterC) + aNonceWordH);
            aWandererH = aWandererH + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterD, 21U)) + aOrbiterJ) + aNonceWordI);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterI, 57U)) + aOrbiterA);
            aWandererI = aWandererI + (((RotL64(aCross, 53U) + aOrbiterK) + RotL64(aOrbiterA, 29U)) + aPhaseEWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 39U) + aOrbiterF) + RotL64(aOrbiterE, 60U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 5U)) + aOrbiterE) + aNonceWordA);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 30U) + RotL64(aOrbiterF, 11U)) + aOrbiterB);
            aWandererE = aWandererE + (((RotL64(aCross, 13U) + RotL64(aOrbiterG, 53U)) + aOrbiterA) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 30U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + RotL64(aWandererF, 6U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 16277U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 11007U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 11762U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneC[((aIndex + 15775U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 28U)) + (RotL64(aIngress, 57U) ^ RotL64(aCross, 11U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterE = (aWandererD + RotL64(aIngress, 53U)) + 1708250618750199233U;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 37U)) + 12009147777553691142U;
            aOrbiterH = ((aWandererI + RotL64(aCross, 29U)) + 8393982703399156592U) + aNonceWordH;
            aOrbiterK = ((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 57U)) + 3247327098356831221U;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 50U)) + RotL64(aCarry, 21U)) + 3403590155376353737U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 43U)) + 18197244558104735044U) + aPhaseEOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aCross, 47U)) + 3096253642040701606U;
            aOrbiterA = (aWandererG + RotL64(aIngress, 11U)) + 8012692688785412179U;
            aOrbiterF = (aWandererH + RotL64(aCross, 6U)) + 17531946907545680745U;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 27U)) + 17687695944270225817U) + aNonceWordI;
            aOrbiterB = (((aWandererB + RotL64(aIngress, 19U)) + RotL64(aCarry, 11U)) + 16147773866007628769U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 18244641303026196497U) + aNonceWordC;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 8839160526348897457U;
            aOrbiterH = RotL64((aOrbiterH * 14268021129087663397U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 10599266240854068246U) + aNonceWordK;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 2056723540756216155U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13311591601230386375U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 4629354220460621284U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 9505955649473204942U;
            aOrbiterI = RotL64((aOrbiterI * 17775391885312236187U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 17078153810088721310U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 9470436761716263000U;
            aOrbiterG = RotL64((aOrbiterG * 5431855497250357229U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 3305863413630104742U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 14377172434239576161U;
            aOrbiterA = RotL64((aOrbiterA * 6880176890091033423U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 415687827894226513U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 16975319836893760993U;
            aOrbiterD = RotL64((aOrbiterD * 6597144958013976445U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 12707054129431596074U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 8974182792497231239U;
            aOrbiterE = RotL64((aOrbiterE * 7874658957269462717U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 10826131924322955095U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 4168545139712703154U) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 10305904857550051705U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 4539070253658625193U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 3737870219498561326U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13130847633918921393U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 11563084648810555040U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 7410695535361901473U;
            aOrbiterF = RotL64((aOrbiterF * 7540855656023807389U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 6687453696858775037U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 1708250618750199233U;
            aOrbiterB = RotL64((aOrbiterB * 13104250803527718135U), 13U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterC, 46U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (RotL64(aOrbiterA, 37U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterE, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterH, 35U)) + aOrbiterK);
            aWandererD = aWandererD + (((RotL64(aCross, 27U) + aOrbiterA) + RotL64(aOrbiterG, 23U)) + aNonceWordN);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterB, 21U)) + aNonceWordJ);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterH, 42U)) + aOrbiterA) + RotL64(aCarry, 47U)) + aNonceWordL);
            aWandererF = aWandererF ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterI, 3U)) + aOrbiterB);
            aWandererH = aWandererH + (((RotL64(aScatter, 41U) + aOrbiterF) + RotL64(aOrbiterE, 13U)) + aPhaseEWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterC, 5U)) + aOrbiterA);
            aWandererI = aWandererI + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterJ, 19U)) + aOrbiterG) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 34U) + RotL64(aOrbiterI, 27U)) + aOrbiterD);
            aWandererG = aWandererG + (((RotL64(aPrevious, 39U) + aOrbiterK) + RotL64(aOrbiterC, 53U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterE, 46U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (RotL64(aWandererH, 42U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + RotL64(aWandererB, 11U);
            aCarry = aCarry + RotL64(aIngress, 46U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 18176U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 20724U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18460U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 18879U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 22U) ^ RotL64(aCross, 57U)) + (RotL64(aPrevious, 41U) + RotL64(aCarry, 5U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterB = (aWandererG + RotL64(aScatter, 57U)) + 2571116506511057880U;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 60U)) + 13112435411509707292U;
            aOrbiterI = (aWandererA + RotL64(aIngress, 43U)) + 10403251762787357256U;
            aOrbiterK = (((aWandererK + RotL64(aCross, 19U)) + RotL64(aCarry, 3U)) + 8461951095541400405U) + aNonceWordJ;
            aOrbiterA = (((aWandererB + RotL64(aIngress, 11U)) + 9890793478557463815U) + aPhaseEOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1]) + aNonceWordC;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 27U)) + 3030229465991783707U) + aPhaseEOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aScatter, 13U)) + RotL64(aCarry, 41U)) + 7273848154043719247U;
            aOrbiterJ = (aWandererJ + RotL64(aCross, 53U)) + 10681774862516028276U;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 24U)) + RotL64(aCarry, 21U)) + 7105082755586853104U;
            aOrbiterG = (aWandererD + RotL64(aScatter, 39U)) + 6588579345319551129U;
            aOrbiterF = (aWandererI + RotL64(aIngress, 35U)) + 14616333550242386092U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 15439666290229654921U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 3360304356760164799U;
            aOrbiterI = RotL64((aOrbiterI * 5164191920584106237U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 14438730801970761889U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 14515616787452085729U;
            aOrbiterA = RotL64((aOrbiterA * 2041601927968559821U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 4167853822635132419U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 8950982233003320239U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 887144270884244907U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 12391327853728029953U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 7100871010552394421U;
            aOrbiterE = RotL64((aOrbiterE * 16552349374101955967U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 15381697462381887944U) + aNonceWordA;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 6801677551341079401U;
            aOrbiterJ = RotL64((aOrbiterJ * 13325954438427340703U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 947011315719204867U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterC) ^ 6356920162398333481U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 5566721941682667419U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 8910262020598577378U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 8778455415977526457U;
            aOrbiterG = RotL64((aOrbiterG * 4092470497616637283U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 5585696961453127223U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 9670655481681494412U;
            aOrbiterF = RotL64((aOrbiterF * 7863197168965036383U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 10713004007087085729U) + aNonceWordB;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 4036355047492922339U;
            aOrbiterB = RotL64((aOrbiterB * 6923922258047667173U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 14580156873863533497U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 7049502932205025182U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8665428649262370727U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 12707521269341941677U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 2571116506511057880U;
            aOrbiterK = RotL64((aOrbiterK * 2388236789245943699U), 37U);
            //
            aIngress = RotL64(aOrbiterE, 41U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 26U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + RotL64(aOrbiterD, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((((RotL64(aCross, 40U) + aOrbiterC) + RotL64(aOrbiterB, 23U)) + aNonceWordL) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 37U) + RotL64(aOrbiterK, 57U)) + aOrbiterF);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterC, 13U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterH, 11U)) + aOrbiterA) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 3U) + aOrbiterJ) + RotL64(aOrbiterH, 60U));
            aWandererA = aWandererA + ((RotL64(aScatter, 24U) + RotL64(aOrbiterE, 37U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterG, 29U)) + aOrbiterC);
            aWandererE = aWandererE + (((RotL64(aCross, 13U) + RotL64(aOrbiterI, 53U)) + aOrbiterA) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterF, 34U)) + aOrbiterB);
            aWandererI = aWandererI + ((RotL64(aIngress, 53U) + RotL64(aOrbiterD, 27U)) + aOrbiterC);
            aWandererD = aWandererD ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterK, 19U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 48U));
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 36U));
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 23125U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((aIndex + 25421U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25615U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneA[((aIndex + 24825U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCarry, 5U)) ^ (RotL64(aIngress, 56U) + RotL64(aCross, 39U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterF = ((aWandererE + RotL64(aScatter, 60U)) + 5568146815535263910U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = (aWandererD + RotL64(aIngress, 41U)) + 7736084960873834666U;
            aOrbiterH = (aWandererB + RotL64(aCross, 23U)) + 1336413621817562093U;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 11U)) + 5218462026934984692U) + aNonceWordB;
            aOrbiterB = (aWandererK + RotL64(aCross, 51U)) + 7048890985969555935U;
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 29U)) + 13415955213864702118U) + aNonceWordE;
            aOrbiterC = (aWandererF + RotL64(aScatter, 53U)) + 5657023257021528548U;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 27U)) + RotL64(aCarry, 29U)) + 14338310943137497116U;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 38U)) + RotL64(aCarry, 37U)) + 12305161641833950473U;
            aOrbiterA = (aWandererJ + RotL64(aIngress, 57U)) + 14514226578370459131U;
            aOrbiterG = (((aWandererG + RotL64(aCross, 43U)) + RotL64(aCarry, 5U)) + 12692904083266024340U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 11012959130001327964U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 7106471380403489078U;
            aOrbiterH = RotL64((aOrbiterH * 515626559384817223U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 3718101961355280891U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 13364192077222322664U;
            aOrbiterE = RotL64((aOrbiterE * 1411328915372590283U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 6720867800318913440U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 14497243926965866546U;
            aOrbiterK = RotL64((aOrbiterK * 13595058589060114653U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 5789056168233262435U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 14438482587495779937U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10593535547917767263U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 313917798940179945U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 15241845511889502917U) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 16483477103771326107U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 3591957424821693032U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 1559050939014453558U;
            aOrbiterI = RotL64((aOrbiterI * 17933346117866604725U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 15340590914441451383U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 5538037287390050110U;
            aOrbiterC = RotL64((aOrbiterC * 4082576643144951473U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 4151270491894969214U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 263593701314144898U;
            aOrbiterJ = RotL64((aOrbiterJ * 10372046955804512457U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 9025145270653080646U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 6867950904094870056U;
            aOrbiterG = RotL64((aOrbiterG * 9975247022340627751U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 3183454301841252109U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 3054904157641290615U;
            aOrbiterD = RotL64((aOrbiterD * 4092317552439599475U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 1768555574434776135U) + aNonceWordH;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 5568146815535263910U;
            aOrbiterB = RotL64((aOrbiterB * 12466957001078663927U), 27U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 3U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 56U));
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterJ, 51U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 39U));
            aIngress = aIngress + RotL64(aOrbiterE, 20U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterC, 29U)) + aOrbiterH);
            aWandererE = aWandererE + ((RotL64(aPrevious, 36U) + aOrbiterE) + RotL64(aOrbiterK, 51U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterA, 5U)) + aOrbiterJ) + aNonceWordP);
            aWandererC = aWandererC + (((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterF, 14U)) + RotL64(aCarry, 27U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 3U)) + aOrbiterG);
            aWandererI = aWandererI + ((RotL64(aScatter, 5U) + RotL64(aOrbiterJ, 39U)) + aOrbiterC);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 52U) + aOrbiterH) + RotL64(aOrbiterF, 21U)) + aNonceWordI);
            aWandererK = aWandererK + (((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterD, 12U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterD, 23U)) + aOrbiterE);
            aWandererH = aWandererH + (((RotL64(aPrevious, 21U) + aOrbiterE) + RotL64(aOrbiterG, 47U)) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterG, 35U)) + aOrbiterI) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 30U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 4U));
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 32377U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27660U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30919U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((aIndex + 29895U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 51U)) + (RotL64(aIngress, 22U) ^ RotL64(aCarry, 37U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterK = (aWandererA + RotL64(aScatter, 39U)) + 701291026547470433U;
            aOrbiterB = (aWandererH + RotL64(aPrevious, 37U)) + 17283292650462111643U;
            aOrbiterG = (aWandererE + RotL64(aCross, 10U)) + 9969124091931303406U;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 41U)) + 889176772718046988U) + aNonceWordF;
            aOrbiterE = (aWandererD + RotL64(aScatter, 19U)) + 6054541844643748084U;
            aOrbiterF = (((aWandererF + RotL64(aIngress, 51U)) + RotL64(aCarry, 29U)) + 14703226235143028132U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aPrevious, 27U)) + 7977975878522921062U;
            aOrbiterI = ((aWandererI + RotL64(aCross, 21U)) + RotL64(aCarry, 57U)) + 16894322614172266274U;
            aOrbiterC = (((aWandererB + RotL64(aPrevious, 14U)) + RotL64(aCarry, 13U)) + 12160451749345900570U) + aNonceWordK;
            aOrbiterA = (((aWandererK + RotL64(aScatter, 5U)) + 10870847008043897470U) + aPhaseEOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1]) + aNonceWordL;
            aOrbiterJ = (aWandererJ + RotL64(aCross, 43U)) + 8159920947172520247U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 2440099120969517932U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 2428396147731468007U;
            aOrbiterG = RotL64((aOrbiterG * 9363073341539598441U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 2213226274394673479U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 7079731443427765333U;
            aOrbiterE = RotL64((aOrbiterE * 16918930776877030559U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 958896789550478970U) + aNonceWordG;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 10788682955708075458U;
            aOrbiterF = RotL64((aOrbiterF * 913321215613559729U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 2003386579317564870U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 8419686358774204999U) ^ aNonceWordD;
            aOrbiterD = RotL64((aOrbiterD * 6547052526438697621U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 6989167615157578904U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 17636634003643824148U;
            aOrbiterI = RotL64((aOrbiterI * 11038576417283732937U), 11U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterD) + 13824962118933907859U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordM;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 9543912892587859646U;
            aOrbiterC = RotL64((aOrbiterC * 14736710162285997415U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 15729878041027706114U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 9542137475454825463U;
            aOrbiterA = RotL64((aOrbiterA * 11420547128115090491U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 5327302277575009955U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 2707383132257428583U;
            aOrbiterJ = RotL64((aOrbiterJ * 6120763309390182129U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 9008601903853562620U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 11050463189491777908U;
            aOrbiterK = RotL64((aOrbiterK * 9178386878636430553U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 14683684132116778056U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 5390271065690907120U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17903005409098232619U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 5183407290520277451U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 701291026547470433U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16329261100139524239U), 21U);
            //
            aIngress = RotL64(aOrbiterE, 39U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + (RotL64(aOrbiterA, 18U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 53U));
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterG, 23U)) + aOrbiterH);
            aWandererK = aWandererK + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterJ, 27U)) + aOrbiterK) + aNonceWordA);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 43U) + aOrbiterJ) + RotL64(aOrbiterI, 58U));
            aWandererA = aWandererA + ((((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterA, 21U)) + aNonceWordN) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterA, 5U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 60U) + aOrbiterH) + RotL64(aOrbiterJ, 37U)) + RotL64(aCarry, 37U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterH, 47U)) + aOrbiterC);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterG, 41U)) + aOrbiterD) + RotL64(aCarry, 19U)) + aNonceWordP);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterC, 19U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 34U) + aOrbiterB) + RotL64(aOrbiterF, 43U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterC, 30U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererK, 24U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + RotL64(aWandererI, 5U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordD);
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

void TwistExpander_FootBall_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xDF6620A7269AC065ULL + 0xDBCE3AB8756AD8F3ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xF43F5ED67C2EC315ULL + 0xCE3CF44BFE6171D6ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x84C36E48557E3E33ULL + 0xCC21A4054B2CFBCAULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x8E5ADAD3257893B7ULL + 0x84222B9D7F70D6ECULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xCBA4F2F1A803CAC5ULL + 0xF813300AF6F5B4E9ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xAB676CE4CD3E64E3ULL + 0xC9897D9527F4C6FFULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x97A776E3B42D31A9ULL + 0xB02B25E05B4DB76EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xC102727FF7FE3FEDULL + 0xA89036BC1CCA53EDULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xD1F25D73E292DEBBULL + 0xA650E8D918FC468FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xAA4118EF853CB50DULL + 0x81AB7308E54E5608ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xA6D921F2E6536B81ULL + 0xA9B0E2C340C2BDCDULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xABB6A824D6874FB9ULL + 0xBBB97ED2332E0AA4ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xF6020439E0C3D4ABULL + 0xC00CA17744CF25F2ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x93C0A523A06F215DULL + 0x962BACBB9E98EA3DULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x9311BB09966E7FF7ULL + 0xDF1A121F0DCE14C7ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xCDF88EABC4A8558DULL + 0xFCFAFE6FB605DA11ULL);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 5262U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((aIndex + 4781U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 1605U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 3105U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 24U) + RotL64(aCross, 41U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCarry, 5U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = (aWandererG + RotL64(aCross, 20U)) + 8793908991006073956U;
            aOrbiterB = (aWandererJ + RotL64(aIngress, 13U)) + 2932916283348441943U;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 53U)) + 11069042087940968262U) + aPhaseFOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = (aWandererA + RotL64(aPrevious, 5U)) + 14369628676782894441U;
            aOrbiterK = (aWandererI + RotL64(aIngress, 39U)) + 8602903272780978282U;
            aOrbiterJ = (((aWandererE + RotL64(aCross, 3U)) + RotL64(aCarry, 43U)) + 3827036107178568820U) + aPhaseFOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aScatter, 41U)) + RotL64(aCarry, 13U)) + 8905245209036772489U;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 57U)) + 13331387530760017893U) + aNonceWordL;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 50U)) + RotL64(aCarry, 39U)) + 9880107580289737823U;
            aOrbiterA = (aWandererC + RotL64(aScatter, 47U)) + 10199619040626900278U;
            aOrbiterI = (aWandererH + RotL64(aCross, 37U)) + 2466307560891374281U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 13973403407981259448U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 2851460278409385243U;
            aOrbiterD = RotL64((aOrbiterD * 11226902976321781743U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 10365453393815690776U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 2382382358987358791U;
            aOrbiterJ = RotL64((aOrbiterJ * 481563628980705781U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 5058198848163792422U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 10500434740387593487U;
            aOrbiterC = RotL64((aOrbiterC * 5946747708776079787U), 21U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterA) + 11289798395177667084U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordM;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 14327152153231286666U;
            aOrbiterH = RotL64((aOrbiterH * 18155778059595245561U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 8065137263811956313U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 3865153574847924816U) ^ aNonceWordD;
            aOrbiterE = RotL64((aOrbiterE * 9495741102667755161U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 18102279969722473375U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 6306428427188742325U;
            aOrbiterG = RotL64((aOrbiterG * 17826782872351406167U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 16953348204663693724U) + aNonceWordC;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 11950791817032898613U;
            aOrbiterI = RotL64((aOrbiterI * 1498946055469611133U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 11980823193543752994U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 17845490308799454871U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16385153013485463791U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 5566398755702887071U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 10308378271388889968U;
            aOrbiterK = RotL64((aOrbiterK * 142732084484961281U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 6717846700455219260U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 8297225372883997017U;
            aOrbiterF = RotL64((aOrbiterF * 14102812043481327907U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 12249337046267666603U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 8793908991006073956U;
            aOrbiterA = RotL64((aOrbiterA * 5851229209188473467U), 47U);
            //
            aIngress = RotL64(aOrbiterB, 23U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 43U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 28U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aPrevious, 44U) + RotL64(aOrbiterI, 44U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 23U) + aOrbiterD) + RotL64(aOrbiterE, 37U));
            aWandererK = aWandererK + ((((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 47U)) + aNonceWordF);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterG, 41U));
            aWandererI = aWandererI + (((RotL64(aIngress, 39U) + RotL64(aOrbiterJ, 29U)) + aOrbiterD) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterK, 3U)) + aOrbiterA);
            aWandererH = aWandererH + ((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 35U)) + aOrbiterD);
            aWandererF = aWandererF ^ ((((RotL64(aCross, 10U) + RotL64(aOrbiterI, 21U)) + aOrbiterC) + aNonceWordI) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterB, 14U)) + aOrbiterE) + aNonceWordO) + aPhaseFWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterE, 51U));
            aWandererC = aWandererC + ((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterH, 27U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 50U));
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + RotL64(aWandererJ, 20U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 7530U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 7675U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 8660U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((aIndex + 8333U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 10U)) ^ (RotL64(aIngress, 57U) + RotL64(aCross, 41U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = (aWandererA + RotL64(aPrevious, 24U)) + 15920462086654025436U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 57U)) + RotL64(aCarry, 37U)) + 487844076858004017U;
            aOrbiterD = (aWandererK + RotL64(aIngress, 19U)) + 14502883786442630566U;
            aOrbiterC = (aWandererI + RotL64(aCross, 13U)) + 3787107318658233674U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 28U)) + 12548777544693755491U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aCross, 53U)) + 4907309444075181683U) + aNonceWordB;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 3U)) + 18342396700266492072U;
            aOrbiterF = (((aWandererB + RotL64(aPrevious, 43U)) + RotL64(aCarry, 21U)) + 13503051997624242670U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aIngress, 51U)) + 17845742460521374571U) + aNonceWordF;
            aOrbiterJ = (aWandererC + RotL64(aScatter, 21U)) + 8640887211877858169U;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 37U)) + 5273913123709097537U) + aNonceWordP;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 17756844173695563883U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 6713055830729302951U;
            aOrbiterD = RotL64((aOrbiterD * 2832836748513174311U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 5106468334224035972U) + aNonceWordE;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 10228769728713526172U;
            aOrbiterB = RotL64((aOrbiterB * 9760310686414358435U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 7687649520668883142U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 7757480627354711605U;
            aOrbiterA = RotL64((aOrbiterA * 7222553727737349209U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 10876291698508634557U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 8149278085586014186U;
            aOrbiterH = RotL64((aOrbiterH * 8577133863470695381U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 15592893988925610485U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 8639028256640537165U;
            aOrbiterI = RotL64((aOrbiterI * 1880655276432963955U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 475660347892196219U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 1903736092401853832U;
            aOrbiterE = RotL64((aOrbiterE * 8486318978769094799U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 12463250192809450953U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 7253918448601703982U) ^ aNonceWordD;
            aOrbiterC = RotL64((aOrbiterC * 3821034106528009129U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 5171661020093804486U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 11627344933828324146U) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 5388047063152043277U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 6206801139131132815U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 9221302203943031377U;
            aOrbiterF = RotL64((aOrbiterF * 12912049016813367241U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 1798857939965423979U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 5476854168685641232U;
            aOrbiterJ = RotL64((aOrbiterJ * 3884216989250294213U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2816659151953455230U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 15920462086654025436U;
            aOrbiterG = RotL64((aOrbiterG * 17843161654734820613U), 3U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 11U);
            aIngress = aIngress + (RotL64(aOrbiterK, 50U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aPrevious, 26U) + aOrbiterF) + RotL64(aOrbiterC, 20U)) + RotL64(aCarry, 39U)) + aPhaseFWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 29U) + aOrbiterG) + RotL64(aOrbiterJ, 53U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 37U) + RotL64(aOrbiterK, 37U)) + aOrbiterB);
            aWandererI = aWandererI ^ ((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterI, 11U));
            aWandererK = aWandererK + ((RotL64(aIngress, 60U) + RotL64(aOrbiterA, 50U)) + aOrbiterB);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 23U) + aOrbiterA) + RotL64(aOrbiterK, 39U)) + aNonceWordJ);
            aWandererF = aWandererF + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 27U)) + aOrbiterH);
            aWandererC = aWandererC ^ (((RotL64(aCross, 57U) + aOrbiterC) + RotL64(aOrbiterH, 35U)) + aPhaseFWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterJ, 47U)) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterE, 43U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 57U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 44U));
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 12U));
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 14830U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11931U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 13380U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15202U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 6U) ^ RotL64(aCarry, 23U)) + (RotL64(aPrevious, 35U) ^ RotL64(aCross, 53U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = (aWandererC + RotL64(aPrevious, 51U)) + 6068543441070417854U;
            aOrbiterA = ((aWandererI + RotL64(aCross, 23U)) + 2995980468193441856U) + aNonceWordK;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 5U)) + 18020277482171594003U) + aPhaseFOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aIngress, 56U)) + 4293807434721230702U;
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 21U)) + RotL64(aCarry, 41U)) + 7980599111583893156U;
            aOrbiterB = ((aWandererH + RotL64(aCross, 43U)) + 8593141111851052016U) + aPhaseFOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aIngress, 53U)) + 5903487523900084325U;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 39U)) + RotL64(aCarry, 21U)) + 15112035513447930209U;
            aOrbiterG = ((aWandererF + RotL64(aCross, 29U)) + RotL64(aCarry, 51U)) + 9854037263057006439U;
            aOrbiterE = (aWandererD + RotL64(aIngress, 58U)) + 16759760289688823193U;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 11U)) + 12622628933030601390U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 1264668857268123425U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 16302812053619101593U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 18291400055836111547U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 16087995784896123610U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 7970269262800468363U;
            aOrbiterB = RotL64((aOrbiterB * 14924752223305807461U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 5331477046030959632U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 16534913204255550893U;
            aOrbiterA = RotL64((aOrbiterA * 1013433634373673565U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 11042821902537871209U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 8069677512345031660U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13622218526054132397U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 5737130058129936372U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 1076627182956662997U;
            aOrbiterC = RotL64((aOrbiterC * 14342191224014199929U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 13911061091801078190U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 15397603151098990373U) ^ aNonceWordM;
            aOrbiterE = RotL64((aOrbiterE * 1802890451633592245U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 15137326716738637972U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 11248737008959896786U;
            aOrbiterF = RotL64((aOrbiterF * 90789374131547005U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 1847847987633923657U) + aNonceWordI;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 10560748778679145431U;
            aOrbiterD = RotL64((aOrbiterD * 2919333327817231099U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 2703726238610290251U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 12950671360471467310U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7490327691501537047U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 10331504168520449467U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 1541527607705280906U;
            aOrbiterG = RotL64((aOrbiterG * 14197400812600186171U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 9135056476214341809U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 6068543441070417854U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14102524444094948875U), 11U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 23U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 50U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterE, 27U)) + RotL64(aCarry, 35U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 26U) + aOrbiterJ) + RotL64(aOrbiterF, 3U));
            aWandererI = aWandererI + (((RotL64(aIngress, 37U) + aOrbiterD) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 53U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 34U)) + aOrbiterG) + aPhaseFWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 21U)) + aOrbiterC) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 3U) + aOrbiterK) + RotL64(aOrbiterB, 23U)) + aNonceWordL);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterK, 41U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((RotL64(aCross, 23U) + aOrbiterJ) + RotL64(aOrbiterA, 44U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 51U) + aOrbiterJ) + RotL64(aOrbiterK, 19U));
            aWandererA = aWandererA + ((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterK, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 58U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererH, 54U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 21221U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18860U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19600U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneD[((aIndex + 19453U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCross, 56U)) + (RotL64(aCarry, 37U) ^ RotL64(aPrevious, 5U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 37U)) + 17019646486641172469U) + aNonceWordP;
            aOrbiterI = ((aWandererG + RotL64(aCross, 57U)) + 12276141179299971572U) + aNonceWordN;
            aOrbiterF = (aWandererC + RotL64(aScatter, 39U)) + 3617241694029841555U;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 5U)) + RotL64(aCarry, 57U)) + 6967963401259371737U;
            aOrbiterK = (((aWandererF + RotL64(aCross, 42U)) + RotL64(aCarry, 27U)) + 6340709284279891017U) + aPhaseFOrbiterAssignSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = ((aWandererE + RotL64(aScatter, 27U)) + 456065368903896482U) + aNonceWordF;
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 23U)) + RotL64(aCarry, 35U)) + 17686765719908116203U;
            aOrbiterH = (aWandererI + RotL64(aIngress, 19U)) + 1322045955429785736U;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 47U)) + 5163772703302372887U) + aPhaseFOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aCross, 21U)) + 13268431135020363252U;
            aOrbiterB = (aWandererK + RotL64(aPrevious, 12U)) + 6538789950366849332U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 10390344544314544893U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 5087084271300584267U;
            aOrbiterF = RotL64((aOrbiterF * 15149302947570776165U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 13423071121590981727U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 18324443012024134729U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15814349432207734533U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 4129091815978464507U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 17024797553831962245U;
            aOrbiterD = RotL64((aOrbiterD * 3137753479364378175U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 6501545108779991661U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 11930037791867597447U;
            aOrbiterE = RotL64((aOrbiterE * 4904739567549702851U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 4667298703308315851U) + aNonceWordG;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 6315980380900062127U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12080555704907924637U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 12732382340390769888U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 7792095326183864547U;
            aOrbiterA = RotL64((aOrbiterA * 12645556660611824631U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 17428384983571405782U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 3193205313177048443U;
            aOrbiterG = RotL64((aOrbiterG * 14488006565106259731U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 2813743367131107264U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 2742138679703780981U;
            aOrbiterB = RotL64((aOrbiterB * 18356569025783532225U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 6270291142961043031U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 3490174937775044998U;
            aOrbiterJ = RotL64((aOrbiterJ * 13879285210885619613U), 29U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterB) + 13182535825771438942U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordE;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 13047228760732694484U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10365428317468779549U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 17926326514553542739U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 17019646486641172469U;
            aOrbiterC = RotL64((aOrbiterC * 13978838314848228053U), 3U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterI, 5U);
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + (RotL64(aOrbiterE, 23U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterF, 28U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 39U)) + aOrbiterH);
            aWandererE = aWandererE + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 58U)) + aOrbiterA);
            aWandererG = aWandererG ^ ((RotL64(aCross, 24U) + RotL64(aOrbiterK, 35U)) + aOrbiterB);
            aWandererD = aWandererD + (((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterH, 23U)) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterC, 13U)) + aPhaseFWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 5U) + aOrbiterI) + RotL64(aOrbiterE, 53U)) + aPhaseFWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterI, 43U)) + aOrbiterA);
            aWandererB = aWandererB + ((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterG, 47U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterI, 60U)) + aOrbiterJ) + aNonceWordJ);
            aWandererF = aWandererF + (((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 3U)) + aOrbiterJ) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 38U) + aOrbiterH) + RotL64(aOrbiterB, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 50U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererI);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 18U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordK);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23784U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22241U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25254U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((aIndex + 22240U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aIngress, 57U)) + (RotL64(aPrevious, 40U) ^ RotL64(aCarry, 11U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = ((aWandererA + RotL64(aScatter, 53U)) + RotL64(aCarry, 37U)) + 3199575576585871314U;
            aOrbiterE = (aWandererJ + RotL64(aIngress, 58U)) + 2533378188975571824U;
            aOrbiterA = (aWandererB + RotL64(aCross, 39U)) + 6819782112558312658U;
            aOrbiterI = (aWandererE + RotL64(aPrevious, 11U)) + 12690060987724798497U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 29U)) + 7088375139715629606U;
            aOrbiterB = (aWandererG + RotL64(aIngress, 27U)) + 17785618677423695666U;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 13U)) + 1714999280296491277U) + aNonceWordL;
            aOrbiterH = (aWandererC + RotL64(aPrevious, 41U)) + 17611338506932491624U;
            aOrbiterD = (aWandererI + RotL64(aScatter, 20U)) + 6475727359297421201U;
            aOrbiterK = (((aWandererK + RotL64(aIngress, 5U)) + RotL64(aCarry, 11U)) + 2347744591204119530U) + aPhaseFOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = (((aWandererF + RotL64(aCross, 51U)) + RotL64(aCarry, 5U)) + 2739317903351401068U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 8663535261373274338U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 8205245127823536479U;
            aOrbiterA = RotL64((aOrbiterA * 13857005110466856439U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 8916510616749754516U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 3944805940148512932U;
            aOrbiterB = RotL64((aOrbiterB * 18082271583211389701U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 14094751253118853302U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 14094299829196076311U;
            aOrbiterH = RotL64((aOrbiterH * 6370012560657108493U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 3940673811518673802U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 3015106523254484839U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9655401190755573379U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 15404103131982599922U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 1828655763233900875U;
            aOrbiterF = RotL64((aOrbiterF * 13024358077740310049U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 1236981890899916502U) + aNonceWordB;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 18208975564570342697U;
            aOrbiterI = RotL64((aOrbiterI * 4577109989465876801U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 17882273895471449661U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 16196010765612713713U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15624856645134182005U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 14639250100311162559U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 9139027997336903273U;
            aOrbiterD = RotL64((aOrbiterD * 1853126389565574293U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 16848571995585465845U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 15901000078517800358U;
            aOrbiterC = RotL64((aOrbiterC * 11617866400577762383U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 9405166641274108606U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 6776079798531281127U;
            aOrbiterE = RotL64((aOrbiterE * 6914644957401512339U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 15056085197286596847U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 3199575576585871314U;
            aOrbiterJ = RotL64((aOrbiterJ * 15940936753708416817U), 43U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 5U);
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterC, 58U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aScatter, 19U) + aOrbiterD) + RotL64(aOrbiterA, 3U)) + aNonceWordE);
            aWandererH = aWandererH + ((RotL64(aCross, 50U) + aOrbiterJ) + RotL64(aOrbiterK, 43U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 37U) + aOrbiterI) + RotL64(aOrbiterH, 57U)) + aNonceWordN);
            aWandererG = aWandererG + (((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterD, 37U)) + aPhaseFWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterG, 10U)) + aOrbiterI);
            aWandererB = aWandererB + ((((RotL64(aCross, 39U) + aOrbiterE) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 23U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 21U) + aOrbiterG) + RotL64(aOrbiterE, 39U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 11U) + aOrbiterC) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 6U) + aOrbiterD) + RotL64(aOrbiterB, 13U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterJ, 50U)) + aOrbiterF);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterJ, 47U)) + aNonceWordA);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 56U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 54U));
            aCarry = aCarry + RotL64(aWandererI, 43U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ aNonceWordK;
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29172U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27984U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27466U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31906U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCarry, 34U)) ^ (RotL64(aCross, 5U) + RotL64(aPrevious, 51U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = (aWandererJ + RotL64(aScatter, 52U)) + 3561491146322798260U;
            aOrbiterF = ((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 35U)) + 7075025056181885339U;
            aOrbiterB = (((aWandererC + RotL64(aPrevious, 13U)) + RotL64(aCarry, 13U)) + 9230910887904171613U) + aPhaseFOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aIngress, 35U)) + 4119781172609908917U;
            aOrbiterH = (aWandererI + RotL64(aScatter, 47U)) + 17155609083870983149U;
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 19U)) + 2423018561430181695U) + aPhaseFOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aIngress, 23U)) + 12957280305617615744U) + aNonceWordM;
            aOrbiterG = (aWandererF + RotL64(aCross, 3U)) + 2461704174772065813U;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 6U)) + 7907123257849391997U) + aNonceWordA;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 41U)) + 7257868138318960007U;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 37U)) + RotL64(aCarry, 47U)) + 16425903703085702285U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 2990822664594079467U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterD) ^ 5654819006718953817U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterB = RotL64((aOrbiterB * 4465096036756887801U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 12183676471235678779U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 15026286960542123922U;
            aOrbiterH = RotL64((aOrbiterH * 17199049329995315279U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 12169080607071830522U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 2906296852254787499U;
            aOrbiterJ = RotL64((aOrbiterJ * 6754514406846040163U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 3029858695410344584U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 14406410317495954566U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9663780721657983421U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 11048818178401163861U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 13622063920319445043U;
            aOrbiterG = RotL64((aOrbiterG * 2516025554421589857U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 2642646089141233277U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 12761571777929273548U;
            aOrbiterI = RotL64((aOrbiterI * 5518252696078700127U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 7753802695131502382U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 8510425459525030222U;
            aOrbiterC = RotL64((aOrbiterC * 12412361423636026483U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 13522645164493316722U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 1437430302489702713U;
            aOrbiterK = RotL64((aOrbiterK * 14019316635365783545U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 14745189473423751499U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 16968328257002103715U;
            aOrbiterD = RotL64((aOrbiterD * 17915588590593471981U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 5001838243344386314U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 13506188720092630563U;
            aOrbiterF = RotL64((aOrbiterF * 7010027510838271877U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 16902624500530747723U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 3561491146322798260U;
            aOrbiterA = RotL64((aOrbiterA * 95761172090277669U), 19U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterF, 10U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 37U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterK, 41U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 21U) + aOrbiterI) + RotL64(aOrbiterG, 41U));
            aWandererF = aWandererF + (((RotL64(aScatter, 6U) + RotL64(aOrbiterB, 57U)) + aOrbiterK) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 19U) + aOrbiterH) + RotL64(aOrbiterC, 4U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 53U) + aOrbiterF) + RotL64(aOrbiterA, 47U)) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 47U) + aOrbiterC) + RotL64(aOrbiterF, 19U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 37U)) + aOrbiterD) + aNonceWordK) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 39U)) + aOrbiterB);
            aWandererG = aWandererG + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 30U)) + aOrbiterJ);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterD, 21U)) + aOrbiterK) + aNonceWordF);
            aWandererA = aWandererA + (((RotL64(aIngress, 60U) + aOrbiterB) + RotL64(aOrbiterC, 35U)) + aNonceWordP);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 3U) + aOrbiterE) + RotL64(aOrbiterA, 53U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 54U));
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 60U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordA);
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

void TwistExpander_FootBall_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xE5040DBD570000A7ULL + 0x8FB73F0FD4338D07ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x8F2897BBA19C44DBULL + 0x979A233E0F2CAD91ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xA6602786D0D9F947ULL + 0x9CC66D9EA2F8ED70ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xAC9C99A0A12251E9ULL + 0xC9D1374618416781ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xF90F305FAEF1D391ULL + 0xDBD3EAA4E03F129BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xFDE8B7C11985A63BULL + 0xBD655988673077DAULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x8D4D265E51BED049ULL + 0xF69BF799A3B589B0ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xC16EB078F40844E9ULL + 0xD7F4C55A7CB8C26DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xC179C377C296BF5BULL + 0xF5E9B354FF8412D8ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xA925C21D6C1C747DULL + 0x9205D30C7653C60DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xFD2DBD1B73F050A5ULL + 0xE6F23966B42519C1ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xFFD9DF9FB89AB31FULL + 0x8AD865CC144E537BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x850749939AD5EBC5ULL + 0xDDEB832F9F837E12ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xDDC004E2BD9F36A7ULL + 0x8C4FE8F5EA01D8B8ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xF26319497A69CA99ULL + 0xC07B7F24662C6F39ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xCCB3838FE3020E19ULL + 0xC25C2964970BB2AEULL);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 2547U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneC[((aIndex + 2220U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 969U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 219U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 10U) ^ RotL64(aCross, 53U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 41U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = ((aWandererH + RotL64(aCross, 39U)) + RotL64(aCarry, 37U)) + 15383045568644941552U;
            aOrbiterD = (aWandererC + RotL64(aIngress, 13U)) + 17452811657750910067U;
            aOrbiterK = (aWandererD + RotL64(aPrevious, 58U)) + 15660117718455155603U;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 41U)) + 10396441207743665753U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 53U)) + RotL64(aCarry, 53U)) + 3708971058200841442U;
            aOrbiterC = ((aWandererA + RotL64(aCross, 5U)) + 7000673057768598750U) + aNonceWordC;
            aOrbiterH = (aWandererE + RotL64(aScatter, 34U)) + 9886354469011131596U;
            aOrbiterB = ((aWandererI + RotL64(aIngress, 29U)) + RotL64(aCarry, 47U)) + 16018065329058043467U;
            aOrbiterE = (aWandererG + RotL64(aCross, 47U)) + 5024756166109352320U;
            aOrbiterA = (aWandererB + RotL64(aIngress, 21U)) + 6587818720728886652U;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 51U)) + 3652672354944162319U) + aPhaseFOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 6307315649915348048U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 16405347331742979258U;
            aOrbiterK = RotL64((aOrbiterK * 7183142442906743699U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 5427299664054601957U) + aNonceWordK;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 4983381733483185898U;
            aOrbiterC = RotL64((aOrbiterC * 14646556236306407673U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 10182995521328377487U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 8694282877540593550U;
            aOrbiterI = RotL64((aOrbiterI * 14614602561910403893U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 4085927978153269932U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 6176195962815240877U) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 16792916528959579875U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 6966742100601433005U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 9920952446921247521U;
            aOrbiterH = RotL64((aOrbiterH * 1879821050131820933U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 11958734477518336014U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 2058335903640404380U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6986170159285417789U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 77366119537297816U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 12072894199692855000U;
            aOrbiterG = RotL64((aOrbiterG * 9083781120514635987U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 11874297832446385377U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 13715562531763053196U;
            aOrbiterD = RotL64((aOrbiterD * 12822488258322963187U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 13664465415354326653U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 10365386643010882315U;
            aOrbiterF = RotL64((aOrbiterF * 3687934567254955761U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 2003863843075564853U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 8864134110143237364U;
            aOrbiterB = RotL64((aOrbiterB * 4586162015675320985U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 8055736412403126985U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 15383045568644941552U;
            aOrbiterA = RotL64((aOrbiterA * 5175405553995854715U), 43U);
            //
            aIngress = RotL64(aOrbiterK, 21U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterA, 26U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterC, 41U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 60U)) + aOrbiterC) + aNonceWordM);
            aWandererA = aWandererA + ((((RotL64(aCross, 5U) + RotL64(aOrbiterB, 19U)) + aOrbiterK) + RotL64(aCarry, 37U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 41U)) + aOrbiterH);
            aWandererH = aWandererH + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterF, 3U)) + aOrbiterA) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 50U) + RotL64(aOrbiterC, 27U)) + aOrbiterG) + aNonceWordD);
            aWandererC = aWandererC + ((RotL64(aCross, 47U) + RotL64(aOrbiterK, 29U)) + aOrbiterE);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 23U) + aOrbiterH) + RotL64(aOrbiterD, 53U)) + aNonceWordG);
            aWandererG = aWandererG + ((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterE, 13U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 30U) + aOrbiterE) + RotL64(aOrbiterA, 36U)) + aPhaseFWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterI, 23U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterI, 21U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 24U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 6U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordN;
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 6356U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneD[((aIndex + 7386U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 10568U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 9663U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 6U) + RotL64(aCarry, 53U)) ^ (RotL64(aIngress, 19U) ^ RotL64(aCross, 37U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = ((aWandererB + RotL64(aIngress, 13U)) + RotL64(aCarry, 21U)) + 11410829607777684449U;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 6U)) + 7502698839700975347U) + aPhaseFOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aScatter, 39U)) + 13267685058252106173U;
            aOrbiterJ = (aWandererD + RotL64(aCross, 27U)) + 238242706996630625U;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 53U)) + 8184695499511454281U) + aNonceWordM;
            aOrbiterK = (aWandererI + RotL64(aIngress, 43U)) + 12767823220461985403U;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 37U)) + RotL64(aCarry, 35U)) + 12293198423143850330U;
            aOrbiterB = ((aWandererK + RotL64(aCross, 3U)) + RotL64(aCarry, 47U)) + 11149495229952495939U;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 30U)) + 7556992689338382800U;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 11U)) + 3431338808774134649U) + aNonceWordO;
            aOrbiterF = ((aWandererH + RotL64(aIngress, 47U)) + 16863099140844995099U) + aPhaseFOrbiterAssignSaltD[((aIndex + 6U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 17872458049880677604U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 16760153457252546974U;
            aOrbiterA = RotL64((aOrbiterA * 11225037229069712805U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 3115544493537438408U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 4359882942759752958U;
            aOrbiterG = RotL64((aOrbiterG * 561477566995575801U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 13387113067202396536U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 12955690074544490161U;
            aOrbiterE = RotL64((aOrbiterE * 12449941770827974511U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 15614054443728226807U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 1939441328066616114U;
            aOrbiterH = RotL64((aOrbiterH * 4484917074808974359U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 4599016263007782537U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 9962305629016158048U;
            aOrbiterD = RotL64((aOrbiterD * 1496184427500037279U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 8428467674122750557U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 3938884087806393439U;
            aOrbiterI = RotL64((aOrbiterI * 12810531094050481761U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 6018636830758044658U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 1510372000641305416U) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 9002834928626918247U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 17592782466215337843U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 8119921507606870360U) ^ aNonceWordD;
            aOrbiterK = RotL64((aOrbiterK * 1299795061644535485U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 8753237702359236964U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 12389957327067768090U) ^ aNonceWordI;
            aOrbiterB = RotL64((aOrbiterB * 4586786761936601607U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 17791633199762408683U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 11606494383812053915U;
            aOrbiterC = RotL64((aOrbiterC * 13041480602055778521U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 4418614662439151979U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 11410829607777684449U;
            aOrbiterF = RotL64((aOrbiterF * 3342270212301058781U), 21U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterI, 29U);
            aIngress = aIngress + (RotL64(aOrbiterF, 18U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 5U)) + aOrbiterK);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 29U) + aOrbiterC) + RotL64(aOrbiterF, 42U));
            aWandererK = aWandererK + ((RotL64(aIngress, 10U) + RotL64(aOrbiterK, 13U)) + aOrbiterF);
            aWandererB = aWandererB ^ (((RotL64(aCross, 41U) + aOrbiterI) + RotL64(aOrbiterA, 39U)) + aPhaseFWandererUpdateSaltF[((aIndex + 28U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 21U)) + aOrbiterF) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterJ, 24U)) + aNonceWordF);
            aWandererH = aWandererH + ((((RotL64(aScatter, 19U) + aOrbiterE) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 39U)) + aNonceWordG);
            aWandererA = aWandererA ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterF, 53U)) + aOrbiterJ);
            aWandererG = aWandererG + ((RotL64(aScatter, 37U) + aOrbiterD) + RotL64(aOrbiterB, 19U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 53U) + aOrbiterG) + RotL64(aOrbiterI, 51U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 44U) + RotL64(aOrbiterG, 27U)) + aOrbiterA) + aPhaseFWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 28U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 41U));
            aCarry = aCarry + RotL64(aWandererA, 18U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordM;
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 14160U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 13633U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 12997U)) & S_BLOCK1], 40U) ^ RotL64(aWorkLaneC[((aIndex + 11755U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 29U) + RotL64(aCross, 41U)) ^ (RotL64(aCarry, 13U) ^ RotL64(aPrevious, 54U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = ((aWandererC + RotL64(aCross, 19U)) + 17711946802293254150U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aIngress, 11U)) + 16652362590489569378U;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 5U)) + 6972810344198183097U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = (aWandererH + RotL64(aScatter, 38U)) + 13117100889782940546U;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 13U)) + 13199305696782626591U) + aNonceWordN;
            aOrbiterB = (((aWandererJ + RotL64(aScatter, 47U)) + RotL64(aCarry, 53U)) + 992156184392760945U) + aNonceWordE;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 23U)) + 13791265442074543880U;
            aOrbiterD = (aWandererE + RotL64(aCross, 36U)) + 17057087245252294859U;
            aOrbiterK = (((aWandererB + RotL64(aIngress, 43U)) + RotL64(aCarry, 13U)) + 13444195995883541046U) + aNonceWordB;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 27U)) + RotL64(aCarry, 41U)) + 6723678233676059420U;
            aOrbiterC = (aWandererD + RotL64(aScatter, 41U)) + 7913379431208430475U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 4481887195529300665U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 11892724101424384078U;
            aOrbiterF = RotL64((aOrbiterF * 3468639499716604111U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 7700902083270424194U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 1888001433557140271U;
            aOrbiterB = RotL64((aOrbiterB * 8975562955027025349U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 14996753906788986929U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 939004845422123765U;
            aOrbiterA = RotL64((aOrbiterA * 2507090308972292313U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 11922230289291941807U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 15681187459741147199U;
            aOrbiterJ = RotL64((aOrbiterJ * 10124947739653819101U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 9119043713532718155U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 8327697433992362166U;
            aOrbiterD = RotL64((aOrbiterD * 11157657162184304567U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 13630755116592440359U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 771252613886022889U) ^ aNonceWordO;
            aOrbiterI = RotL64((aOrbiterI * 2958918915223536519U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 8524239721467527770U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 17732617735422435572U;
            aOrbiterH = RotL64((aOrbiterH * 13992947983987668631U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 5265753270696005619U) + aNonceWordD;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 14456128349522985053U;
            aOrbiterE = RotL64((aOrbiterE * 5406509991740849617U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 12909993509014176457U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 10113568710432654194U;
            aOrbiterG = RotL64((aOrbiterG * 6857806395910432831U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 14818978163348513071U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 17843349910031998923U;
            aOrbiterK = RotL64((aOrbiterK * 13608449524810499593U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 12589077818524017161U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 17711946802293254150U;
            aOrbiterC = RotL64((aOrbiterC * 9454569713107675231U), 43U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterH, 29U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 48U));
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 50U) + aOrbiterF) + RotL64(aOrbiterE, 53U)) + aPhaseFWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aCross, 43U) + RotL64(aOrbiterK, 35U)) + aOrbiterC) + RotL64(aCarry, 39U)) + aPhaseFWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 21U) + aOrbiterG) + RotL64(aOrbiterA, 51U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 60U)) + aOrbiterD);
            aWandererF = aWandererF ^ ((RotL64(aCross, 27U) + aOrbiterH) + RotL64(aOrbiterK, 21U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 5U)) + aOrbiterI);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 23U) + aOrbiterH) + RotL64(aOrbiterC, 41U)) + aNonceWordP);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 54U) + RotL64(aOrbiterE, 3U)) + aOrbiterA);
            aWandererD = aWandererD ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterB, 48U)) + aOrbiterF) + aNonceWordH);
            aWandererG = aWandererG + (((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 13U)) + aOrbiterJ) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 37U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererK, 52U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 50U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordF);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 18937U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 21520U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 17883U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneD[((aIndex + 20411U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 10U) + RotL64(aPrevious, 29U)) + (RotL64(aCarry, 41U) ^ RotL64(aIngress, 53U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = (aWandererD + RotL64(aIngress, 43U)) + 12615321415808640429U;
            aOrbiterF = (aWandererE + RotL64(aCross, 13U)) + 15712784676459931207U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 11U)) + 11013335427004930046U) + aNonceWordO;
            aOrbiterG = (aWandererA + RotL64(aScatter, 22U)) + 8298733856304768806U;
            aOrbiterC = ((aWandererF + RotL64(aCross, 53U)) + RotL64(aCarry, 11U)) + 6207732959150824216U;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 51U)) + RotL64(aCarry, 51U)) + 9769864876127544038U;
            aOrbiterH = (aWandererB + RotL64(aScatter, 57U)) + 10782181918651152563U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 37U)) + 5790454015845620939U) + aNonceWordF;
            aOrbiterB = ((aWandererG + RotL64(aCross, 27U)) + 15606578025386733803U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 47U)) + 5522352539991175304U) + aPhaseFOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aScatter, 6U)) + RotL64(aCarry, 43U)) + 5993355818572869649U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 10864534396947622047U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 12090053126235913528U;
            aOrbiterK = RotL64((aOrbiterK * 7250801471645972261U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 14191181677234981396U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 2258570108233924592U;
            aOrbiterC = RotL64((aOrbiterC * 8307541155393855209U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 8448114811381534603U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 2702389315763499817U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6710443836432274393U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 17202184076718780200U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 150549910056015002U;
            aOrbiterH = RotL64((aOrbiterH * 195034681254956335U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 4910512055808124967U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterC) ^ 4783477997418403079U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterE = RotL64((aOrbiterE * 861977492146512865U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 13842899106208709771U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 7930112618036681468U;
            aOrbiterB = RotL64((aOrbiterB * 8609551859830858419U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 8790107242863198659U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 6882768826643279144U;
            aOrbiterJ = RotL64((aOrbiterJ * 13745521454063360763U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 12136498871759890015U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 8120456314755584336U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1830725195528043575U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 14425711740351183016U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 15907406009196323049U;
            aOrbiterI = RotL64((aOrbiterI * 8599371693260686839U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 4878521420367891861U) + aNonceWordK;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 1184672056055028939U;
            aOrbiterF = RotL64((aOrbiterF * 5963961755367831967U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 10126736568567000180U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 12615321415808640429U;
            aOrbiterG = RotL64((aOrbiterG * 11663715449073755137U), 47U);
            //
            aIngress = RotL64(aOrbiterD, 35U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 54U));
            aIngress = aIngress + (RotL64(aOrbiterF, 51U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterF, 60U)) + aOrbiterA) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 6U) + aOrbiterI) + RotL64(aOrbiterK, 43U)) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 37U) + aOrbiterI) + RotL64(aOrbiterE, 39U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 35U) + aOrbiterF) + RotL64(aOrbiterJ, 35U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterB, 48U)) + aOrbiterK);
            aWandererB = aWandererB + ((RotL64(aCross, 27U) + aOrbiterK) + RotL64(aOrbiterH, 29U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 47U) + aOrbiterC) + RotL64(aOrbiterE, 19U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterC, 23U)) + aOrbiterI) + RotL64(aCarry, 19U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 41U) + aOrbiterD) + RotL64(aOrbiterG, 27U));
            aWandererF = aWandererF + (((RotL64(aScatter, 56U) + aOrbiterI) + RotL64(aOrbiterF, 5U)) + aNonceWordJ);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterD, 51U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 24U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 36U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23652U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((aIndex + 23032U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27208U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 21895U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 6U) ^ RotL64(aCarry, 29U)) + (RotL64(aIngress, 41U) + RotL64(aCross, 53U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = (aWandererK + RotL64(aIngress, 35U)) + 5480870806135400132U;
            aOrbiterA = (aWandererJ + RotL64(aScatter, 29U)) + 8034874599430768743U;
            aOrbiterC = (aWandererD + RotL64(aCross, 43U)) + 4006919843736863767U;
            aOrbiterD = (aWandererF + RotL64(aPrevious, 23U)) + 2988069748674633718U;
            aOrbiterJ = (aWandererA + RotL64(aScatter, 41U)) + 12347295651973135786U;
            aOrbiterG = (aWandererG + RotL64(aCross, 54U)) + 14152683894431568192U;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 51U)) + 15765143815254196598U) + aPhaseFOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 27U)) + RotL64(aCarry, 27U)) + 10473067082331244233U;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 37U)) + 1089466925383677249U) + aNonceWordK;
            aOrbiterI = (((aWandererB + RotL64(aIngress, 21U)) + RotL64(aCarry, 41U)) + 13215039929873682230U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = ((aWandererC + RotL64(aCross, 18U)) + RotL64(aCarry, 57U)) + 3957997712247961479U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 10023907397941685546U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 14593012591254614353U;
            aOrbiterC = RotL64((aOrbiterC * 17111300092082154687U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 13353797968154036726U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 9259966668512102858U;
            aOrbiterG = RotL64((aOrbiterG * 8326732574268308221U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 10757861831070349321U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 10530223113483866178U;
            aOrbiterB = RotL64((aOrbiterB * 11269177745265396583U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 7554320926405521865U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 6978052067277966996U;
            aOrbiterI = RotL64((aOrbiterI * 18020134738536217801U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 1053695861967171420U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 15980734683539854451U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3208466640010555357U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 17041258393808061556U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 12846551858751995530U;
            aOrbiterD = RotL64((aOrbiterD * 9303891433380993639U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 14617434286683320666U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 3999309956180741302U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15037707937050015205U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 13452627760403094126U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 2633241575260427158U;
            aOrbiterF = RotL64((aOrbiterF * 2638570213290747581U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 15575035993965639421U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 7829837426112185905U;
            aOrbiterK = RotL64((aOrbiterK * 17059814556114938275U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 12565466096663867876U) + aNonceWordL;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 4845209979900289818U;
            aOrbiterA = RotL64((aOrbiterA * 14990494169374347835U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 13472490162287247012U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 5480870806135400132U;
            aOrbiterJ = RotL64((aOrbiterJ * 9150331893094034245U), 11U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 13U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 50U));
            aIngress = aIngress + RotL64(aOrbiterC, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 11U) + aOrbiterH) + RotL64(aOrbiterI, 11U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterK, 3U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 6U) + RotL64(aOrbiterB, 5U)) + aOrbiterI);
            aWandererD = aWandererD + (((RotL64(aScatter, 37U) + RotL64(aOrbiterE, 24U)) + aOrbiterD) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterJ, 41U)) + aOrbiterA) + aNonceWordF);
            aWandererK = aWandererK + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 35U)) + aOrbiterG) + aPhaseFWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 41U) + aOrbiterC) + RotL64(aOrbiterF, 29U));
            aWandererC = aWandererC + (((RotL64(aIngress, 20U) + RotL64(aOrbiterF, 39U)) + aOrbiterA) + aNonceWordO);
            aWandererI = aWandererI ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterK, 53U)) + aOrbiterG) + aNonceWordJ);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 13U)) + aOrbiterE) + RotL64(aCarry, 53U)) + aPhaseFWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 44U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererB, 44U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererK, 24U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordD);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28790U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29016U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28622U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29176U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCross, 53U)) ^ (RotL64(aCarry, 18U) + RotL64(aPrevious, 5U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = ((aWandererD + RotL64(aCross, 46U)) + RotL64(aCarry, 19U)) + 7790166497945719700U;
            aOrbiterE = (aWandererI + RotL64(aIngress, 19U)) + 7136208896846119188U;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 3U)) + 12123156943355100886U;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 39U)) + 5095546037880875199U) + aNonceWordI;
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 12U)) + 17642705393916765992U) + aPhaseFOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aScatter, 53U)) + 9918479837334416990U;
            aOrbiterB = (aWandererG + RotL64(aCross, 51U)) + 4890009823843176466U;
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 27U)) + 17652590786213674124U;
            aOrbiterK = (((aWandererH + RotL64(aIngress, 21U)) + RotL64(aCarry, 3U)) + 870002527644696135U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aScatter, 35U)) + 12545429703552643682U;
            aOrbiterC = (((aWandererF + RotL64(aPrevious, 23U)) + RotL64(aCarry, 43U)) + 5310272867406182581U) + aNonceWordF;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 3264719049050179440U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 1967241238180278937U;
            aOrbiterH = RotL64((aOrbiterH * 13004319774269457957U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 773883832927040736U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterE) ^ 12766817190261232485U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 7448864556802318431U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 260069382395598265U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 15462103891287350123U;
            aOrbiterG = RotL64((aOrbiterG * 5029268763635635753U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 4072032867513289827U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 17153061419083897076U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11934532169271718913U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 6207264270332656966U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 18048064697837314947U;
            aOrbiterD = RotL64((aOrbiterD * 13632594619404208489U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 14484617445340272026U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 16160443600497652026U;
            aOrbiterK = RotL64((aOrbiterK * 1988599349457831597U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 5873314228291583482U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 16418290052752166515U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 18270363452003213317U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 9158414409987627714U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 8205937960146492168U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14008398661393344261U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 16386126219854809263U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 12418021156683187869U;
            aOrbiterA = RotL64((aOrbiterA * 13897930566207284517U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 5427232681451476584U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 18237670074497382745U;
            aOrbiterE = RotL64((aOrbiterE * 15528665160297906195U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 8330262458028468513U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 7790166497945719700U;
            aOrbiterI = RotL64((aOrbiterI * 6001280767763971107U), 43U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 35U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 54U));
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 41U));
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 21U) + aOrbiterK) + RotL64(aOrbiterG, 43U));
            aWandererH = aWandererH + ((((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterF, 5U)) + RotL64(aCarry, 21U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterB, 35U)) + aOrbiterD) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aIngress, 35U) + aOrbiterJ) + RotL64(aOrbiterC, 40U)) + RotL64(aCarry, 53U)) + aNonceWordA);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 23U)) + aOrbiterD);
            aWandererG = aWandererG + ((RotL64(aIngress, 14U) + RotL64(aOrbiterK, 47U)) + aOrbiterI);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterI, 19U)) + aOrbiterB);
            aWandererD = aWandererD + ((RotL64(aCross, 29U) + RotL64(aOrbiterG, 26U)) + aOrbiterJ);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterF, 51U)) + aOrbiterE);
            aWandererB = aWandererB + ((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterE, 29U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 12U) + aOrbiterA) + RotL64(aOrbiterB, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 54U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererI, 42U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordB);
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

void TwistExpander_FootBall_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 3107U)) & S_BLOCK1], 30U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 2498U)) & W_KEY1], 13U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 7836U)) & W_KEY1], 10U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 569U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 21U)) + (RotL64(aCross, 35U) + RotL64(aPrevious, 50U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = ((aWandererE + RotL64(aIngress, 58U)) + 2915859148137000694U) + aPhaseCOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aCross, 43U)) + 210680583721444425U;
            aOrbiterK = (aWandererC + RotL64(aScatter, 51U)) + 6668118118775650387U;
            aOrbiterA = (aWandererG + RotL64(aPrevious, 21U)) + 15794200818099010989U;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 27U)) + RotL64(aCarry, 5U)) + 6565076707062828369U;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 11U)) + 16323164497808856719U) + aPhaseCOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aCross, 47U)) + 7965435318816716560U;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 34U)) + RotL64(aCarry, 13U)) + 7390281030573369017U;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 5U)) + RotL64(aCarry, 29U)) + 2269738866911824875U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 9664014216039993873U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 18284857398028357633U;
            aOrbiterK = RotL64((aOrbiterK * 8402008251343393737U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 367667619795303009U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 7935945060956274197U;
            aOrbiterG = RotL64((aOrbiterG * 5481786693511955209U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 16683666162337789540U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 10655658270998102390U;
            aOrbiterH = RotL64((aOrbiterH * 15231596813382239841U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 8307037916581540297U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 3247742749860703524U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15052136713218656641U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 10446792483683818139U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 16374602929344972364U;
            aOrbiterB = RotL64((aOrbiterB * 12599903932725787599U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 2411334498322777183U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 1093701164116833765U;
            aOrbiterA = RotL64((aOrbiterA * 13129220206835381729U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 17018480952982840635U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 17348395690080029814U;
            aOrbiterI = RotL64((aOrbiterI * 6212591395713433257U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 16111252311283623152U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 12776492920397785951U;
            aOrbiterD = RotL64((aOrbiterD * 6136009241593081821U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 12214538600808144816U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 10043377462096783363U;
            aOrbiterJ = RotL64((aOrbiterJ * 14639467375095185877U), 23U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 54U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 21U));
            aIngress = aIngress + RotL64(aOrbiterH, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterG, 23U)) + aOrbiterB);
            aWandererF = aWandererF + (((RotL64(aPrevious, 30U) + aOrbiterD) + RotL64(aOrbiterC, 6U)) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterG, 57U));
            aWandererI = aWandererI + (((RotL64(aIngress, 19U) + aOrbiterH) + RotL64(aOrbiterG, 43U)) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterJ, 35U));
            aWandererD = aWandererD + ((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterH, 13U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 24U) + aOrbiterG) + RotL64(aOrbiterD, 53U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterJ, 27U)) + aPhaseCWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 18U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 50U));
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 43U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 9738U)) & S_BLOCK1], 18U) ^ RotL64(mSource[((aIndex + 13288U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15771U)) & W_KEY1], 23U) ^ RotL64(aKeyRowReadB[((aIndex + 8841U)) & W_KEY1], 56U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 37U) + RotL64(aIngress, 3U)) ^ (RotL64(aPrevious, 50U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = (aWandererH + RotL64(aIngress, 11U)) + 5573188770530340913U;
            aOrbiterI = (aWandererB + RotL64(aPrevious, 58U)) + 1431772230889897111U;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 39U)) + RotL64(aCarry, 53U)) + 4809192776429682319U;
            aOrbiterH = (aWandererF + RotL64(aCross, 35U)) + 5576603692574369341U;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 3U)) + 2720143226007220386U;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 53U)) + RotL64(aCarry, 29U)) + 17220328778565331629U;
            aOrbiterK = (((aWandererD + RotL64(aCross, 23U)) + RotL64(aCarry, 21U)) + 9629485808442089423U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aScatter, 44U)) + 1136998437010390983U;
            aOrbiterA = ((aWandererC + RotL64(aCross, 19U)) + 11893390497814523841U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 1764986431917532370U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 1741014798007010376U;
            aOrbiterG = RotL64((aOrbiterG * 13414914086049500731U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 12221368453236547044U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 7694538641172350430U;
            aOrbiterJ = RotL64((aOrbiterJ * 8439120733670016501U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 17472344518811560603U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 3308740700728172984U;
            aOrbiterK = RotL64((aOrbiterK * 15290400462887712083U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 9535358833412446771U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 11192312491731312451U;
            aOrbiterB = RotL64((aOrbiterB * 17405609148475445743U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 14850451970047190039U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 11932493299452443256U;
            aOrbiterA = RotL64((aOrbiterA * 7964808728820467795U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 5972619895614731870U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 17174497535809891690U;
            aOrbiterE = RotL64((aOrbiterE * 15471084511364572533U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 17412894714378898351U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 14675615208706549810U;
            aOrbiterH = RotL64((aOrbiterH * 7864845089606499769U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 16116792108013658523U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 9702262005960966336U;
            aOrbiterC = RotL64((aOrbiterC * 970452849653781703U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 17337264966818542841U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 7004462033775827275U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11943575980344402681U), 43U);
            //
            aIngress = RotL64(aOrbiterC, 39U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + (RotL64(aOrbiterI, 24U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 19U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aPrevious, 48U) + aOrbiterH) + RotL64(aOrbiterA, 44U)) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 57U)) + aOrbiterJ);
            aWandererH = aWandererH + (((RotL64(aIngress, 23U) + RotL64(aOrbiterK, 3U)) + aOrbiterI) + aPhaseCWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 39U) + aOrbiterG) + RotL64(aOrbiterE, 27U));
            aWandererF = aWandererF + (((RotL64(aIngress, 34U) + aOrbiterE) + RotL64(aOrbiterK, 39U)) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 13U) + aOrbiterJ) + RotL64(aOrbiterB, 51U));
            aWandererB = aWandererB + (((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterC, 11U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterH, 34U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 54U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 27U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23384U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneA[((aIndex + 19816U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 19651U)) & W_KEY1], 10U) ^ RotL64(aKeyRowReadB[((aIndex + 18469U)) & W_KEY1], 27U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 13U) ^ RotL64(aPrevious, 56U)) ^ (RotL64(aCarry, 29U) + RotL64(aIngress, 43U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = ((aWandererF + RotL64(aScatter, 27U)) + 3105313968748067810U) + aPhaseCOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = ((aWandererC + RotL64(aIngress, 57U)) + 9977249451119627064U) + aPhaseCOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aCross, 47U)) + 17941392803495349366U;
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 22U)) + 4279533326705471133U;
            aOrbiterH = (aWandererE + RotL64(aIngress, 11U)) + 13983828966811580039U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 5U)) + RotL64(aCarry, 37U)) + 3983490984234810378U;
            aOrbiterC = (aWandererK + RotL64(aCross, 35U)) + 308786542215259956U;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 51U)) + RotL64(aCarry, 53U)) + 8443607695364427037U;
            aOrbiterF = ((aWandererG + RotL64(aCross, 40U)) + RotL64(aCarry, 21U)) + 14939626441464340668U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 9350693577306121110U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 1717071159396961752U;
            aOrbiterB = RotL64((aOrbiterB * 11062480662625054525U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 15911765265202100610U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 14898546272333182767U;
            aOrbiterD = RotL64((aOrbiterD * 2674900543810733067U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 3560903518513465868U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 5367062725726860234U;
            aOrbiterJ = RotL64((aOrbiterJ * 8521908836601319553U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 15233321480618877327U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 9288449812290126074U;
            aOrbiterG = RotL64((aOrbiterG * 6815298520404038519U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 5504840529511585676U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 6825598386801620046U;
            aOrbiterH = RotL64((aOrbiterH * 11666542445846250077U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 6433024450721339470U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 97934156644929458U;
            aOrbiterK = RotL64((aOrbiterK * 8630530773006923215U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 3260053604798744515U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 16539416623243059076U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12199577351166064503U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 9814290051339038920U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 13280156404507444041U;
            aOrbiterI = RotL64((aOrbiterI * 15269010043398910061U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 11853942590993546833U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 13207869904312989977U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15503461937625795969U), 47U);
            //
            aIngress = RotL64(aOrbiterK, 40U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + RotL64(aOrbiterB, 54U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aIngress, 43U) + aOrbiterF) + RotL64(aOrbiterI, 48U)) + RotL64(aCarry, 43U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 58U) + RotL64(aOrbiterF, 11U)) + aOrbiterB);
            aWandererE = aWandererE + (((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 53U)) + aOrbiterG) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterF, 43U));
            aWandererF = aWandererF + ((RotL64(aScatter, 13U) + aOrbiterG) + RotL64(aOrbiterD, 3U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 4U) + RotL64(aOrbiterH, 39U)) + aOrbiterK);
            aWandererI = aWandererI + (((RotL64(aPrevious, 27U) + aOrbiterI) + RotL64(aOrbiterJ, 30U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterC, 57U)) + aOrbiterI);
            aWandererB = aWandererB + ((RotL64(aIngress, 51U) + RotL64(aOrbiterG, 35U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererI, 6U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 21U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27844U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((aIndex + 26488U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28904U)) & S_BLOCK1], 3U) ^ RotL64(mSource[((aIndex + 28462U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCross, 23U)) + (RotL64(aIngress, 48U) + RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = (aWandererI + RotL64(aIngress, 48U)) + 13960289014350612206U;
            aOrbiterB = (aWandererK + RotL64(aPrevious, 29U)) + 3483331015269589730U;
            aOrbiterA = (aWandererH + RotL64(aCross, 57U)) + 6873299241002444518U;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 39U)) + RotL64(aCarry, 41U)) + 3562094007125534229U;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 11U)) + RotL64(aCarry, 13U)) + 11422367439932782705U;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 18U)) + 532453428514259816U) + aPhaseCOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aIngress, 35U)) + 17810941465810193088U;
            aOrbiterG = (((aWandererA + RotL64(aCross, 53U)) + RotL64(aCarry, 21U)) + 11869759058631106331U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = (aWandererF + RotL64(aIngress, 23U)) + 8837581071876177566U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 17185378327053837778U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 7578253375676981500U;
            aOrbiterA = RotL64((aOrbiterA * 13371647568758721729U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 17112646434432814442U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 14949096407295697881U;
            aOrbiterF = RotL64((aOrbiterF * 14770977858283051753U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 4259590620758467836U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 6534899413644542303U;
            aOrbiterK = RotL64((aOrbiterK * 7987609419215568661U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 2637407498893694243U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 15819295597921425711U;
            aOrbiterE = RotL64((aOrbiterE * 5202015597375051399U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 6373559542002699718U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 11694562937392022505U;
            aOrbiterD = RotL64((aOrbiterD * 9311557972331218597U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 3308736483775453062U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 12749929710650475901U;
            aOrbiterH = RotL64((aOrbiterH * 248428400724560945U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 1569528215675579656U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 1044077933631689572U;
            aOrbiterG = RotL64((aOrbiterG * 6443796233912755143U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 8393422728124537471U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 2002732612516530754U;
            aOrbiterC = RotL64((aOrbiterC * 13702146823622364279U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 13469191942843147943U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 7633171368709520560U;
            aOrbiterB = RotL64((aOrbiterB * 9713514012478203047U), 47U);
            //
            aIngress = RotL64(aOrbiterH, 43U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 60U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + RotL64(aOrbiterC, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aPrevious, 46U) + aOrbiterE) + RotL64(aOrbiterH, 5U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterB, 10U));
            aWandererC = aWandererC + (((RotL64(aScatter, 23U) + RotL64(aOrbiterG, 27U)) + aOrbiterK) + aPhaseCWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterF, 19U));
            aWandererK = aWandererK + ((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 53U)) + aOrbiterG);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterC, 58U));
            aWandererB = aWandererB + (((RotL64(aIngress, 30U) + RotL64(aOrbiterB, 23U)) + aOrbiterA) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterC, 43U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 37U) + aOrbiterB) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 19U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 54U));
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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

void TwistExpander_FootBall_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5675U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4212U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6353U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneA[((aIndex + 2471U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aIngress, 37U)) + (RotL64(aPrevious, 3U) + RotL64(aCross, 20U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = (aWandererG + RotL64(aScatter, 3U)) + 7960325128608297381U;
            aOrbiterG = (((aWandererF + RotL64(aIngress, 47U)) + RotL64(aCarry, 43U)) + 12773836012104052042U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = (((aWandererD + RotL64(aCross, 37U)) + RotL64(aCarry, 57U)) + 3173972621347773016U) + aPhaseDOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 57U)) + RotL64(aCarry, 13U)) + 3708401356314308171U;
            aOrbiterA = (aWandererE + RotL64(aIngress, 14U)) + 950774285720019449U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 4170092315705438265U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 17000449130864980747U;
            aOrbiterH = RotL64((aOrbiterH * 7710635557693533263U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 8793910540062893860U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 520277969543516469U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4150613128885828229U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 12762214857389827271U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 2932451184340207695U;
            aOrbiterF = RotL64((aOrbiterF * 7513337346940091655U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 11062179998786293839U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 7919119215271524178U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9053677007180081359U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 1774988449597115155U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 3799792889466518953U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17512791286490623455U), 19U);
            //
            aIngress = RotL64(aOrbiterB, 3U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 28U));
            aIngress = aIngress + RotL64(aOrbiterA, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterH, 13U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 27U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 60U) + RotL64(aOrbiterB, 53U)) + aOrbiterH) + aPhaseDWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterF, 36U)) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 27U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 53U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 11257U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((aIndex + 8529U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11201U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneB[((aIndex + 10029U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCross, 35U)) ^ (RotL64(aCarry, 3U) + RotL64(aPrevious, 52U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = (((aWandererB + RotL64(aPrevious, 21U)) + RotL64(aCarry, 3U)) + 3970829908171131502U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = (((aWandererG + RotL64(aCross, 29U)) + RotL64(aCarry, 23U)) + 7040283759419531991U) + aPhaseDOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aIngress, 11U)) + 11856292169397052901U;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 60U)) + RotL64(aCarry, 51U)) + 819598588791819022U;
            aOrbiterJ = (aWandererK + RotL64(aIngress, 51U)) + 2176451710970866848U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 6454704928613390494U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 11792122387218053841U;
            aOrbiterG = RotL64((aOrbiterG * 17994898985794518565U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 9254780213489752211U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 16591812589999846482U;
            aOrbiterJ = RotL64((aOrbiterJ * 5425771603523423167U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 1471246223935074832U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 1424843083106386453U;
            aOrbiterK = RotL64((aOrbiterK * 15020536982657410783U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 1856469958050891629U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 6331743690452052712U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15327924647897459645U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 10351075711345476487U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 9518585245330480185U;
            aOrbiterF = RotL64((aOrbiterF * 3792179827396760391U), 5U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 29U);
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterH, 42U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 23U) + aOrbiterK) + RotL64(aOrbiterF, 19U)) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 51U) + aOrbiterH) + RotL64(aOrbiterK, 27U));
            aWandererH = aWandererH + (((RotL64(aCross, 34U) + aOrbiterF) + RotL64(aOrbiterG, 58U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterF, 35U)) + aOrbiterH) + aPhaseDWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterG, 43U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 60U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 18334U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneA[((aIndex + 20614U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19831U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 20159U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 60U) + RotL64(aPrevious, 19U)) ^ (RotL64(aIngress, 47U) ^ RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = ((aWandererF + RotL64(aIngress, 13U)) + RotL64(aCarry, 19U)) + 7632760812370906911U;
            aOrbiterK = (((aWandererB + RotL64(aScatter, 5U)) + RotL64(aCarry, 3U)) + 6007174525479723089U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aPrevious, 38U)) + 3362829642521821048U;
            aOrbiterD = ((aWandererK + RotL64(aCross, 47U)) + RotL64(aCarry, 39U)) + 18009548556107978286U;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 23U)) + 17880909432272697327U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 15961567935420752568U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 10136559064656837921U;
            aOrbiterE = RotL64((aOrbiterE * 14473810261421912849U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 17622019364405410277U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 6927494824421416306U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2686290883767829973U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 7125170407794874847U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 12342273503071032250U;
            aOrbiterA = RotL64((aOrbiterA * 867417849555857179U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 14997696377476124836U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 14874498694181230698U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4026127545746010937U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 2549397729130885686U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 4217995818662767955U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5525525344485251063U), 39U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 19U);
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterJ, 47U)) + aOrbiterE);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 35U)) + aOrbiterK);
            aWandererB = aWandererB + ((((RotL64(aIngress, 24U) + aOrbiterD) + RotL64(aOrbiterJ, 20U)) + RotL64(aCarry, 53U)) + aPhaseDWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterD, 5U)) + aOrbiterE);
            aWandererK = aWandererK + ((((RotL64(aScatter, 39U) + aOrbiterA) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 5U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 54U));
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 29053U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31716U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 32042U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 27731U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aIngress, 4U)) ^ (RotL64(aCarry, 51U) + RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = (aWandererB + RotL64(aCross, 3U)) + 13650869943246163567U;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 43U)) + RotL64(aCarry, 5U)) + 3435284932011770999U;
            aOrbiterK = (((aWandererC + RotL64(aScatter, 35U)) + RotL64(aCarry, 19U)) + 12388155658186776579U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 27U)) + RotL64(aCarry, 35U)) + 2374345913955712039U;
            aOrbiterD = ((aWandererG + RotL64(aCross, 12U)) + 6095094526980292156U) + aPhaseDOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 4965147025852444174U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 3261881216269075298U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4874733445914960785U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 4939780217097329222U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 3019862009792676287U;
            aOrbiterC = RotL64((aOrbiterC * 2452316208025448747U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 901910626217143974U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 3647055146712366383U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1792602402476450009U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 7731765438957392967U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 13409819457393479741U;
            aOrbiterB = RotL64((aOrbiterB * 3345078200262410715U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 5415832109107794258U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 8876738832313114471U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1304277600444504135U), 3U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 41U);
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterK, 19U)) + aOrbiterB);
            aWandererC = aWandererC + ((((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 39U)) + aPhaseDWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 56U)) + aOrbiterC) + aPhaseDWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 20U) + RotL64(aOrbiterB, 27U)) + aOrbiterC) + RotL64(aCarry, 13U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterH, 5U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererB, 28U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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

void TwistExpander_FootBall_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 3999U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5383U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7847U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((aIndex + 5835U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 20U)) ^ (RotL64(aCross, 37U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = (aWandererE + RotL64(aScatter, 13U)) + 1557680213571812384U;
            aOrbiterD = ((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 37U)) + 7387349725778021121U;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 50U)) + 15379264067601586976U) + aPhaseEOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 29U)) + RotL64(aCarry, 3U)) + 3730195724576043708U;
            aOrbiterI = (aWandererI + RotL64(aScatter, 39U)) + 9637070085323827066U;
            aOrbiterA = (aWandererF + RotL64(aPrevious, 5U)) + 1170865717363676184U;
            aOrbiterF = (((aWandererB + RotL64(aIngress, 23U)) + RotL64(aCarry, 19U)) + 2750833653175252030U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 15118992811225568305U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 4974092922102988451U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10575977398702460975U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 10625719096296719514U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 855167122475471865U;
            aOrbiterI = RotL64((aOrbiterI * 7441090331293158773U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 11322911068958340262U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 4334591909425429835U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10059025861172038183U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 14263701737208936392U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 678723206735649084U;
            aOrbiterF = RotL64((aOrbiterF * 10823239851733632227U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 15652053114252065230U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 1705225940224061401U;
            aOrbiterH = RotL64((aOrbiterH * 3626023093533713579U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 6826394665732900206U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 11902946775066981141U;
            aOrbiterE = RotL64((aOrbiterE * 18300629262162694137U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 9802212958998591310U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 14001358545610206524U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13172645840788327099U), 13U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterA, 4U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 43U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + RotL64(aOrbiterI, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 42U) + aOrbiterD) + RotL64(aOrbiterI, 21U)) + aPhaseEWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 56U)) + aOrbiterA);
            aWandererK = aWandererK + ((RotL64(aCross, 11U) + RotL64(aOrbiterC, 43U)) + aOrbiterH);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterH, 3U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 37U)) + aOrbiterF) + aPhaseEWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 29U) + RotL64(aOrbiterC, 27U)) + aOrbiterE) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 52U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + RotL64(aWandererI, 13U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 12401U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 9628U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12323U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneB[((aIndex + 15125U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCarry, 24U)) ^ (RotL64(aCross, 11U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = (aWandererE + RotL64(aCross, 3U)) + 8793908991006073956U;
            aOrbiterI = (aWandererG + RotL64(aIngress, 13U)) + 2932916283348441943U;
            aOrbiterE = (((aWandererF + RotL64(aScatter, 57U)) + RotL64(aCarry, 3U)) + 11069042087940968262U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = (aWandererA + RotL64(aPrevious, 28U)) + 14369628676782894441U;
            aOrbiterB = (aWandererK + RotL64(aIngress, 21U)) + 8602903272780978282U;
            aOrbiterH = ((aWandererB + RotL64(aCross, 37U)) + RotL64(aCarry, 23U)) + 3827036107178568820U;
            aOrbiterC = (((aWandererD + RotL64(aPrevious, 43U)) + RotL64(aCarry, 47U)) + 8905245209036772489U) + aPhaseEOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 13331387530760017893U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 9880107580289737823U;
            aOrbiterE = RotL64((aOrbiterE * 10302652857542703753U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 10199619040626900278U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 2466307560891374281U;
            aOrbiterJ = RotL64((aOrbiterJ * 6295342978834217571U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 13973403407981259448U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 2851460278409385243U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11226902976321781743U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 10365453393815690776U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 2382382358987358791U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 481563628980705781U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 5058198848163792422U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 10500434740387593487U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5946747708776079787U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 11289798395177667084U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 14327152153231286666U;
            aOrbiterH = RotL64((aOrbiterH * 18155778059595245561U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 8065137263811956313U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 3865153574847924816U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9495741102667755161U), 11U);
            //
            aIngress = RotL64(aOrbiterI, 11U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + RotL64(aOrbiterE, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterE, 52U)) + aOrbiterH);
            aWandererF = aWandererF + (((RotL64(aScatter, 39U) + aOrbiterC) + RotL64(aOrbiterH, 43U)) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterK, 5U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 29U)) + aOrbiterJ) + RotL64(aCarry, 3U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 11U) + aOrbiterI) + RotL64(aOrbiterB, 11U)) + aPhaseEWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 30U) + aOrbiterK) + RotL64(aOrbiterI, 37U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 23U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererA, 54U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 10U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 18143U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21465U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 18451U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneC[((aIndex + 18013U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 52U) + RotL64(aIngress, 23U)) + (RotL64(aCarry, 37U) ^ RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererD + RotL64(aCross, 57U)) + RotL64(aCarry, 19U)) + 252059974543142812U;
            aOrbiterI = (aWandererH + RotL64(aIngress, 30U)) + 11690823093681457368U;
            aOrbiterB = (((aWandererC + RotL64(aPrevious, 13U)) + RotL64(aCarry, 43U)) + 13282189752890971123U) + aPhaseEOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = ((aWandererG + RotL64(aScatter, 47U)) + 9507416294305708435U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = (aWandererB + RotL64(aPrevious, 39U)) + 14053038174390776539U;
            aOrbiterF = (aWandererK + RotL64(aScatter, 3U)) + 14605253312318725009U;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 23U)) + RotL64(aCarry, 3U)) + 18138286582677863671U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 8530091235978489988U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 14381731677571170073U;
            aOrbiterB = RotL64((aOrbiterB * 11675896999665768253U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 13316413456378978456U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 3910529530149320706U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16000139333493588429U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 6302070286831566901U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 12324134652758551396U;
            aOrbiterK = RotL64((aOrbiterK * 17136438281540250165U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 4773478557638475048U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 4031153435446078944U;
            aOrbiterG = RotL64((aOrbiterG * 3876928995240982769U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 3114794895962903899U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 3552936509969106796U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16823186892738820299U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 5828754613946145627U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 17985241114076114558U;
            aOrbiterF = RotL64((aOrbiterF * 1986669631395606833U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 11319331046368072261U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 6104267020171882160U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12525117969211576177U), 13U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 14U);
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + RotL64(aOrbiterF, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterG, 3U)) + aOrbiterB);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterK, 11U)) + aOrbiterI);
            aWandererE = aWandererE + ((((RotL64(aCross, 60U) + RotL64(aOrbiterC, 43U)) + aOrbiterK) + RotL64(aCarry, 53U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterC, 37U)) + aOrbiterJ);
            aWandererB = aWandererB + ((RotL64(aIngress, 37U) + RotL64(aOrbiterI, 53U)) + aOrbiterJ);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterK, 60U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 53U) + aOrbiterF) + RotL64(aOrbiterC, 27U)) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 50U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + RotL64(aWandererB, 23U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 27312U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((aIndex + 26468U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25494U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 25355U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 29U) + RotL64(aCarry, 54U)) ^ (RotL64(aCross, 3U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (aWandererC + RotL64(aIngress, 29U)) + 16451272412693907816U;
            aOrbiterA = ((aWandererA + RotL64(aCross, 60U)) + RotL64(aCarry, 51U)) + 10099485419723255462U;
            aOrbiterG = (aWandererE + RotL64(aScatter, 47U)) + 17668900099534923192U;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 41U)) + RotL64(aCarry, 39U)) + 5497093724143181753U;
            aOrbiterK = (aWandererB + RotL64(aScatter, 3U)) + 10354044773550071706U;
            aOrbiterH = (((aWandererG + RotL64(aIngress, 53U)) + RotL64(aCarry, 5U)) + 12728258851198019099U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aCross, 13U)) + 4144050505314242618U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 14133805325480076530U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 308863673210602899U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2672613556981540433U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 11741180130160569753U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 12926863156769180448U;
            aOrbiterH = RotL64((aOrbiterH * 9726030996091054939U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 211920854786494259U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 13234608842479411078U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2556747209733759467U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 9164711974854618892U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 6667377062281954219U;
            aOrbiterK = RotL64((aOrbiterK * 2603737166987437649U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 4559040002406721850U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 1749875480850675109U;
            aOrbiterD = RotL64((aOrbiterD * 15822640067349481089U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 9555365165561936366U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 18289733999504213574U;
            aOrbiterI = RotL64((aOrbiterI * 14156217554673229429U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 8727162691639622461U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 291406782452963706U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8413500075082350243U), 11U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterH, 60U);
            aIngress = aIngress + (RotL64(aOrbiterG, 21U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + RotL64(aOrbiterA, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterF, 35U)) + RotL64(aCarry, 37U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 19U)) + aOrbiterG) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterK, 3U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 41U) + aOrbiterF) + RotL64(aOrbiterH, 27U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterD, 46U)) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 13U)) + aOrbiterD);
            aWandererB = aWandererB + ((RotL64(aCross, 26U) + aOrbiterI) + RotL64(aOrbiterA, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 44U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererG, 35U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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

void TwistExpander_FootBall_Arx::Twist_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1872U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneC[((aIndex + 1575U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7952U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 4285U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 6U) + RotL64(aPrevious, 53U)) ^ (RotL64(aCarry, 39U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = (((aWandererK + RotL64(aCross, 3U)) + RotL64(aCarry, 37U)) + 4068921616130916949U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aPrevious, 56U)) + 12077715273915151726U;
            aOrbiterH = (aWandererD + RotL64(aScatter, 41U)) + 16047546802670596833U;
            aOrbiterC = (((aWandererJ + RotL64(aIngress, 13U)) + RotL64(aCarry, 19U)) + 9690277462716999763U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aScatter, 27U)) + RotL64(aCarry, 57U)) + 14484814700447992628U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 17089267243053958210U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 9138746214446211147U;
            aOrbiterH = RotL64((aOrbiterH * 8244950097712975043U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 10181001536979097045U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 6657458969093373191U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4311019792293202747U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 7515983477876590988U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 3039935555863947600U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12511160550780270119U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 16209389224740851136U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 725253312098083182U;
            aOrbiterI = RotL64((aOrbiterI * 17535989492095522597U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 13307041115748941383U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 7159572004825238263U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4855009895002398449U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 53U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 39U) + aOrbiterD) + RotL64(aOrbiterI, 11U)) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterC, 19U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 35U)) + aOrbiterH);
            aWandererG = aWandererG ^ (((RotL64(aCross, 27U) + aOrbiterH) + RotL64(aOrbiterA, 54U)) + aPhaseFWandererUpdateSaltF[((aIndex + 16U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 48U) + aOrbiterI) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + RotL64(aWandererD, 37U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 15332U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12026U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10697U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 11254U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 4U) + RotL64(aCarry, 53U)) ^ (RotL64(aCross, 35U) ^ RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 29U)) + RotL64(aCarry, 53U)) + 17470880031634374199U;
            aOrbiterI = ((aWandererF + RotL64(aCross, 3U)) + 757565846006937746U) + aPhaseFOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aScatter, 11U)) + RotL64(aCarry, 5U)) + 9419282475801345674U;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 57U)) + RotL64(aCarry, 39U)) + 2014248014107898196U;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 40U)) + 15113928519446490441U) + aPhaseFOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 7346126964886259935U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 5594123113093162359U;
            aOrbiterE = RotL64((aOrbiterE * 18043634828891483403U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 5659237263369402005U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 11565709683423969703U;
            aOrbiterH = RotL64((aOrbiterH * 16731289017588574671U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 16782863743534856287U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 13499100900072115907U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5567729598873214433U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 11414447651044205242U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 7545993795121430538U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10758488381206257261U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 11778229237616454988U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 2544793391976514665U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4021060413798523299U), 53U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterI, 27U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterD, 11U)) + aOrbiterE) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterB, 34U)) + RotL64(aCarry, 35U)) + aPhaseFWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 54U) + RotL64(aOrbiterB, 3U)) + aOrbiterD);
            aWandererB = aWandererB + (((RotL64(aScatter, 27U) + aOrbiterE) + RotL64(aOrbiterH, 51U)) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterI, 23U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 44U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 18626U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17441U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18202U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 24061U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 47U)) ^ (RotL64(aIngress, 21U) + RotL64(aCarry, 34U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = (aWandererI + RotL64(aCross, 43U)) + 9435962834163239322U;
            aOrbiterC = (((aWandererB + RotL64(aIngress, 56U)) + RotL64(aCarry, 57U)) + 10524704356081318973U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aScatter, 5U)) + 7403401305665208680U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 35U)) + RotL64(aCarry, 43U)) + 7525414805023556493U;
            aOrbiterB = ((aWandererC + RotL64(aCross, 27U)) + RotL64(aCarry, 5U)) + 1116686470029070951U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 13257612299137802420U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 9181543003986598283U;
            aOrbiterI = RotL64((aOrbiterI * 18162011316880411235U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 9739384852307501107U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 11308402900229016057U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12690186771773188967U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 14935167593705272337U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 7171824007631943535U;
            aOrbiterK = RotL64((aOrbiterK * 4839974427616194289U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 8068411284829563567U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 12350207458513447578U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 813973258659041895U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 17039236343991574134U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 18291683592714999632U;
            aOrbiterB = RotL64((aOrbiterB * 7771718817924840713U), 11U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterI, 57U);
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterH, 42U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aCross, 22U) + RotL64(aOrbiterK, 39U)) + aOrbiterC) + aPhaseFWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 41U) + RotL64(aOrbiterC, 28U)) + aOrbiterI) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 57U)) + aOrbiterH);
            aWandererA = aWandererA + (((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 21U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterB, 3U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 34U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 24707U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27592U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29198U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 24749U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 58U) + RotL64(aCross, 27U)) ^ (RotL64(aCarry, 13U) ^ RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 39U)) + RotL64(aCarry, 21U)) + 5510690816044082200U;
            aOrbiterI = (((aWandererA + RotL64(aCross, 47U)) + RotL64(aCarry, 39U)) + 15967820875033940530U) + aPhaseFOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aScatter, 11U)) + 539348720848176221U;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 27U)) + RotL64(aCarry, 51U)) + 15779318183635560817U;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 56U)) + 14511058534424187469U) + aPhaseFOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 5811130556873428391U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 1085928476499444025U;
            aOrbiterA = RotL64((aOrbiterA * 13965845678632598921U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 6973335316600768130U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 10747243745475009744U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17322489216048017061U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 1072260008981349754U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 2018772405352495753U;
            aOrbiterB = RotL64((aOrbiterB * 10840562112080574241U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 1092091597048996547U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 15103140149542167197U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 621856991658027989U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 13194619321108681542U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 16749188603268621850U;
            aOrbiterJ = RotL64((aOrbiterJ * 9575408950550922039U), 37U);
            //
            aIngress = RotL64(aOrbiterJ, 41U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 52U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 5U) + aOrbiterI) + RotL64(aOrbiterA, 21U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 13U) + aOrbiterB) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 53U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterB, 13U)) + aOrbiterA);
            aWandererC = aWandererC + ((((RotL64(aIngress, 23U) + RotL64(aOrbiterJ, 40U)) + aOrbiterG) + RotL64(aCarry, 23U)) + aPhaseFWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterG, 53U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 56U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_FootBall_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 2898U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 4936U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 639U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 7966U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aIngress, 39U)) + (RotL64(aPrevious, 3U) + RotL64(aCarry, 18U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = ((aWandererG + RotL64(aScatter, 58U)) + RotL64(aCarry, 19U)) + 13481227414590594621U;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 47U)) + RotL64(aCarry, 37U)) + 17425964381118918026U;
            aOrbiterB = (((aWandererD + RotL64(aCross, 11U)) + RotL64(aCarry, 53U)) + 4792004356135956581U) + aPhaseGOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 23U)) + 11926849936000639098U) + aPhaseGOrbiterAssignSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aCross, 35U)) + 990697329347742142U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 9307721505373076588U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 17605732738841908719U;
            aOrbiterB = RotL64((aOrbiterB * 13123627214143336281U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 13110764518634187439U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 17970109897810645911U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10395095143998920213U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 10273133817644703654U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 11239046688920468137U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5197802934333553327U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 8355821483275763145U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 15522151127786049345U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4844278537850520413U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 5381663179722418112U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 9551368011768104906U;
            aOrbiterJ = RotL64((aOrbiterJ * 14202470972121732997U), 53U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 4U);
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 35U) + aOrbiterB) + RotL64(aOrbiterA, 47U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 14U)) + aOrbiterJ) + aPhaseGWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 46U) + RotL64(aOrbiterB, 27U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 14009U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneC[((aIndex + 8204U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 14538U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 12547U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aIngress, 5U)) + (RotL64(aCarry, 54U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (((aWandererJ + RotL64(aIngress, 39U)) + RotL64(aCarry, 5U)) + 1708250618750199233U) + aPhaseGOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = (((aWandererB + RotL64(aCross, 53U)) + RotL64(aCarry, 39U)) + 12009147777553691142U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = (aWandererC + RotL64(aScatter, 24U)) + 8393982703399156592U;
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 51U)) + 3247327098356831221U;
            aOrbiterC = (aWandererI + RotL64(aIngress, 11U)) + 3403590155376353737U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 18197244558104735044U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 3096253642040701606U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6656168712438620783U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 8012692688785412179U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 17531946907545680745U;
            aOrbiterC = RotL64((aOrbiterC * 16510602981731506381U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 17687695944270225817U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 16147773866007628769U;
            aOrbiterD = RotL64((aOrbiterD * 16926442582711557877U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 18244641303026196497U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 8839160526348897457U;
            aOrbiterK = RotL64((aOrbiterK * 14268021129087663397U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 10599266240854068246U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 2056723540756216155U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13311591601230386375U), 13U);
            //
            aIngress = RotL64(aOrbiterB, 13U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 23U) + aOrbiterC) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterD, 11U)) + aOrbiterC) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 6U) + aOrbiterK) + RotL64(aOrbiterD, 48U)) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterB, 3U)) + aOrbiterJ);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 35U) + aOrbiterJ) + RotL64(aOrbiterK, 35U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 58U));
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 20468U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneD[((aIndex + 21402U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23003U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((aIndex + 18782U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aIngress, 18U)) ^ (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = ((aWandererG + RotL64(aCross, 27U)) + RotL64(aCarry, 37U)) + 6068543441070417854U;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 51U)) + 2995980468193441856U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aScatter, 5U)) + 18020277482171594003U;
            aOrbiterD = ((aWandererE + RotL64(aIngress, 14U)) + RotL64(aCarry, 19U)) + 4293807434721230702U;
            aOrbiterH = (((aWandererA + RotL64(aPrevious, 41U)) + RotL64(aCarry, 5U)) + 7980599111583893156U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 8593141111851052016U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 5903487523900084325U;
            aOrbiterI = RotL64((aOrbiterI * 2508618861111356699U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 15112035513447930209U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 9854037263057006439U;
            aOrbiterB = RotL64((aOrbiterB * 396276470208637283U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 16759760289688823193U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 12622628933030601390U;
            aOrbiterA = RotL64((aOrbiterA * 2151912984825538321U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 1264668857268123425U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 16302812053619101593U;
            aOrbiterD = RotL64((aOrbiterD * 18291400055836111547U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 16087995784896123610U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 7970269262800468363U;
            aOrbiterH = RotL64((aOrbiterH * 14924752223305807461U), 5U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 43U);
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterA, 56U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterD, 26U)) + aOrbiterH);
            aWandererE = aWandererE + (((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 3U)) + aOrbiterI) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterD, 51U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 48U) + aOrbiterB) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 53U)) + aPhaseGWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterB, 39U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererA, 19U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 28110U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29169U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27744U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 32471U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCross, 53U)) ^ (RotL64(aPrevious, 35U) + RotL64(aCarry, 10U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = (aWandererD + RotL64(aPrevious, 41U)) + 3970829908171131502U;
            aOrbiterH = (((aWandererH + RotL64(aIngress, 53U)) + RotL64(aCarry, 11U)) + 7040283759419531991U) + aPhaseGOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aCross, 3U)) + 11856292169397052901U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = ((aWandererC + RotL64(aScatter, 22U)) + RotL64(aCarry, 43U)) + 819598588791819022U;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 13U)) + RotL64(aCarry, 57U)) + 2176451710970866848U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 6454704928613390494U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 11792122387218053841U;
            aOrbiterF = RotL64((aOrbiterF * 17994898985794518565U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 9254780213489752211U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 16591812589999846482U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5425771603523423167U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 1471246223935074832U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 1424843083106386453U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15020536982657410783U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 1856469958050891629U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 6331743690452052712U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15327924647897459645U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 10351075711345476487U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 9518585245330480185U;
            aOrbiterC = RotL64((aOrbiterC * 3792179827396760391U), 51U);
            //
            aIngress = RotL64(aOrbiterA, 27U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + RotL64(aOrbiterF, 50U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aCross, 29U) + aOrbiterA) + RotL64(aOrbiterE, 47U)) + aPhaseGWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 56U)) + aOrbiterF) + RotL64(aCarry, 43U)) + aPhaseGWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 19U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aScatter, 38U) + RotL64(aOrbiterE, 35U)) + aOrbiterC) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 3U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 4U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + RotL64(aWandererC, 21U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void TwistExpander_FootBall_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 7527U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 707U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4443U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 1511U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCarry, 5U)) ^ (RotL64(aCross, 53U) ^ RotL64(aPrevious, 40U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = (((aWandererF + RotL64(aCross, 51U)) + RotL64(aCarry, 11U)) + 6521330037475130256U) + aPhaseHOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aScatter, 27U)) + 12611880456055428940U;
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 36U)) + RotL64(aCarry, 57U)) + 12061611078130934708U;
            aOrbiterH = (((aWandererE + RotL64(aIngress, 19U)) + RotL64(aCarry, 27U)) + 1558112410801116984U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 5U)) + 10509115227850160786U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 4045915960688792066U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 1196541286513243082U;
            aOrbiterA = RotL64((aOrbiterA * 5454309408259753479U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 15564991032722373702U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 4897765238703641798U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9693901276712946763U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 12327429514907752733U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 6189189797708711636U;
            aOrbiterH = RotL64((aOrbiterH * 9017615866338877651U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 6374267075282018852U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 1888758503831341439U;
            aOrbiterG = RotL64((aOrbiterG * 74387714918264257U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 14956857689299491800U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 14879361107223331957U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9166712966729591953U), 57U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 57U);
            aIngress = aIngress + (RotL64(aOrbiterD, 30U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterB, 29U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterG, 39U)) + RotL64(aCarry, 11U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterH, 48U)) + aOrbiterG);
            aWandererF = aWandererF + ((((RotL64(aIngress, 20U) + aOrbiterD) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 29U)) + aPhaseHWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 19U)) + aOrbiterB) + aPhaseHWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + RotL64(aWandererF, 37U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 12035U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((aIndex + 14124U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8757U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneA[((aIndex + 8331U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 18U) + RotL64(aCross, 5U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 13U)) + RotL64(aCarry, 57U)) + 10726035965553989335U;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 53U)) + RotL64(aCarry, 19U)) + 967354339530195662U;
            aOrbiterC = ((aWandererK + RotL64(aCross, 24U)) + 10834593005478605624U) + aPhaseHOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aScatter, 43U)) + 1012888282838656933U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = ((aWandererB + RotL64(aCross, 5U)) + RotL64(aCarry, 43U)) + 15283530351725183253U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 11724495956731703750U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 4288330117317505776U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2738997410474076757U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 10894778070022873473U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 15563886747621617467U;
            aOrbiterH = RotL64((aOrbiterH * 17884709931569040065U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 11182488628562891937U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 10420140066310588580U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13898299782819948719U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 11775138062167543111U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 16545391898578161683U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14588306527161321535U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 1550144656312299266U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 14903504853138279883U;
            aOrbiterK = RotL64((aOrbiterK * 8003033561266164387U), 11U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 47U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + RotL64(aOrbiterC, 34U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 3U) + aOrbiterB) + RotL64(aOrbiterH, 38U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 43U)) + aPhaseHWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 56U) + RotL64(aOrbiterF, 21U)) + aOrbiterK);
            aWandererF = aWandererF + (((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterC, 29U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 19U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 17090U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 24106U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18355U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20228U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 54U) ^ RotL64(aIngress, 3U)) ^ (RotL64(aCarry, 41U) + RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = (((aWandererJ + RotL64(aPrevious, 18U)) + RotL64(aCarry, 37U)) + 1457104756581596530U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = (aWandererB + RotL64(aScatter, 35U)) + 6127240317844622874U;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 3U)) + RotL64(aCarry, 53U)) + 16492290056044189421U;
            aOrbiterK = ((aWandererA + RotL64(aCross, 47U)) + 10963676850938416468U) + aPhaseHOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aScatter, 27U)) + RotL64(aCarry, 21U)) + 4872917367399752405U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 15218882377875616148U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 5934166612122118251U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10365045124180379919U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 14215280930872003003U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 11428034799044600979U;
            aOrbiterE = RotL64((aOrbiterE * 12162528943733976177U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 5453003654321728726U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 14273775120265649389U;
            aOrbiterC = RotL64((aOrbiterC * 5139018128323795309U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 328723770018440271U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 13032190719588211088U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13363368478932798315U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 2386881543033598494U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 1649501123340887116U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11148976582360499033U), 51U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 18U);
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterE, 13U)) + aOrbiterC);
            aWandererH = aWandererH + (((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterF, 5U)) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 58U) + RotL64(aOrbiterF, 37U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 5U)) + aPhaseHWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterG, 56U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 37U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 25235U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29464U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27087U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneC[((aIndex + 30207U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 13U) + RotL64(aCross, 56U)) ^ (RotL64(aCarry, 43U) ^ RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = ((aWandererD + RotL64(aCross, 29U)) + 7722279280863371124U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 37U)) + RotL64(aCarry, 5U)) + 11584220561732385598U;
            aOrbiterH = (((aWandererF + RotL64(aIngress, 50U)) + RotL64(aCarry, 19U)) + 7834679350105534657U) + aPhaseHOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = ((aWandererA + RotL64(aScatter, 13U)) + RotL64(aCarry, 57U)) + 11347994382444180879U;
            aOrbiterF = (aWandererE + RotL64(aCross, 5U)) + 9449903188047063431U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 6516243976652795170U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 8420815253991184777U;
            aOrbiterH = RotL64((aOrbiterH * 1358649408967265415U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 9081386852515170937U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 14375955191735286867U;
            aOrbiterE = RotL64((aOrbiterE * 2772840314542262283U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 880757589768436072U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 3349856625725164229U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 681514212582331781U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 7826309957607577207U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 8057435761214313635U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4718430712767038607U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 9565237500443303103U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 15893066735310588501U;
            aOrbiterF = RotL64((aOrbiterF * 8457633439171452397U), 57U);
            //
            aIngress = RotL64(aOrbiterG, 29U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 44U));
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 11U) + RotL64(aOrbiterG, 53U)) + aOrbiterH) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 3U) + aOrbiterD) + RotL64(aOrbiterE, 21U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aCross, 34U) + aOrbiterF) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 5U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 53U) + aOrbiterH) + RotL64(aOrbiterD, 44U));
            aWandererD = aWandererD + ((RotL64(aCross, 23U) + RotL64(aOrbiterF, 29U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 54U));
            aCarry = aCarry + RotL64(aWandererI, 39U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
