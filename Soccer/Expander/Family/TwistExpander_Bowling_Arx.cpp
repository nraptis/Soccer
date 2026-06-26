#include "TwistExpander_Bowling_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Bowling_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x86791EFD9D50592DULL + 0x920CBDAD10514C45ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xCA8AFB64B211A277ULL + 0x853F450E8062D7D2ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xBD78520F60316E7DULL + 0xAC332EF6FF7B2AE7ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x9401DDB65260275DULL + 0xC419B8397C96D32BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x9DDBFC1A8C977CA1ULL + 0xFB1074B279FD885EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA147F7B1EB390089ULL + 0xD92C85EC0353C791ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x83E1005049FFBB39ULL + 0xA227B80DEB4A0B00ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE5A11304372171EFULL + 0xBAFE6CA7387BCE68ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xC90CF14EA5327077ULL + 0xDD7C6E81150AB5D2ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xE1D6A1F9ED297631ULL + 0xAAAC8A8F19E6C95FULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xF4414CB64B19323FULL + 0xAA9CF5FB73C7DC92ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xC1238221F03273E3ULL + 0xD8CC642F38A5A0BFULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x887F2E0AC1927359ULL + 0xEF96873842105B74ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x9EF0DC77126CD047ULL + 0xE5CC14758E1AE41EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xA9703C8B5BBD1A2FULL + 0xD9145BA501C706FEULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xB8F1CDEA8091D47FULL + 0x8B725862E60B1488ULL);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 4743U)) & S_BLOCK1], 19U) ^ RotL64(pSnow[((aIndex + 4438U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 370U)) & S_BLOCK1], 13U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 5281U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aPrevious, 6U)) ^ (RotL64(aCarry, 37U) + RotL64(aIngress, 23U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 35U)) + 1364174714924216027U) + aOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aCross, 53U)) + 13561796874229506613U) + aNonceWordA;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 4U)) + RotL64(aCarry, 51U)) + 11845572344206238305U;
            aOrbiterK = (aWandererA + RotL64(aScatter, 23U)) + 15762708240326773763U;
            aOrbiterC = ((aWandererC + RotL64(aIngress, 57U)) + 1157119665207900473U) + aOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = (aWandererK + RotL64(aPrevious, 41U)) + 6823546624372055260U;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 19U)) + RotL64(aCarry, 57U)) + 14465564210523945121U;
            aOrbiterG = ((aWandererG + RotL64(aCross, 50U)) + RotL64(aCarry, 43U)) + 10667464548080807531U;
            aOrbiterD = (aWandererJ + RotL64(aScatter, 29U)) + 13445737493224316575U;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 47U)) + 3009837893785957665U) + aNonceWordG;
            aOrbiterF = (aWandererH + RotL64(aPrevious, 21U)) + 2886920524111083752U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 10886177449328249656U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 15067759884678100433U;
            aOrbiterI = RotL64((aOrbiterI * 5724566815989860041U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 18307930462682331536U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 8791864377579255801U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9265158882471421767U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 805797468642992351U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 5743305867058244964U;
            aOrbiterJ = RotL64((aOrbiterJ * 16263000753351131717U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 17102025528234481273U) + aNonceWordD;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 1841579177327486899U;
            aOrbiterK = RotL64((aOrbiterK * 3841603385577825265U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 2189493507896508972U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 18209567010094914374U;
            aOrbiterB = RotL64((aOrbiterB * 3737080408976852351U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 6697069234216868330U) + aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 927471474577415372U;
            aOrbiterD = RotL64((aOrbiterD * 10680760991009199309U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 13155854301197725408U) + aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 1014625081915435892U;
            aOrbiterF = RotL64((aOrbiterF * 11592754232949990435U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 12697209921410914931U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 11555096613655648647U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4598821388864997089U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 9335308231651271690U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 3160859883353473444U;
            aOrbiterC = RotL64((aOrbiterC * 4753600703924906409U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 15681189182414315768U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 3147692210581710663U;
            aOrbiterG = RotL64((aOrbiterG * 6271949093080510861U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 5373388632562432117U) + aNonceWordJ;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 1364174714924216027U;
            aOrbiterE = RotL64((aOrbiterE * 4694926665965807945U), 23U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 60U);
            aIngress = aIngress + (RotL64(aOrbiterC, 27U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterD, 39U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 30U));
            aIngress = aIngress + RotL64(aOrbiterG, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 19U) + aOrbiterC) + RotL64(aOrbiterD, 57U)) + aWandererUpdateSaltB[((aIndex + 8U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 50U) + RotL64(aOrbiterG, 51U)) + aOrbiterK);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 27U) + aOrbiterI) + RotL64(aOrbiterG, 14U));
            aWandererA = aWandererA + (((RotL64(aCross, 21U) + aOrbiterF) + RotL64(aOrbiterI, 43U)) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 39U) + aOrbiterJ) + RotL64(aOrbiterH, 5U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 11U) + aOrbiterI) + RotL64(aOrbiterH, 41U)) + aWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 41U) + aOrbiterB) + RotL64(aOrbiterE, 21U)) + aNonceWordM);
            aWandererF = aWandererF + ((RotL64(aCross, 23U) + aOrbiterD) + RotL64(aOrbiterE, 35U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 23U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aPrevious, 56U) + aOrbiterC) + RotL64(aOrbiterJ, 27U)) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterB, 60U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererB, 36U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = aCarry ^ aNonceWordA;
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 7614U)) & S_BLOCK1], 37U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 8056U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(pSnow[((S_BLOCK1 - aIndex + 7810U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 6795U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 43U) ^ RotL64(aCarry, 27U)) + (RotL64(aIngress, 57U) + RotL64(aCross, 6U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (((aWandererJ + RotL64(aCross, 60U)) + 4622023259121087483U) + aOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordI;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 57U)) + 10253505250223501352U;
            aOrbiterK = (aWandererF + RotL64(aScatter, 23U)) + 17133877904420462669U;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 47U)) + 6162827793741796700U;
            aOrbiterB = (aWandererA + RotL64(aIngress, 41U)) + 9610986424765907615U;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 3U)) + 11210747154264753754U) + aNonceWordJ;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 10U)) + RotL64(aCarry, 43U)) + 16554205219580654546U;
            aOrbiterA = (aWandererE + RotL64(aCross, 35U)) + 10352576357413766388U;
            aOrbiterI = (aWandererB + RotL64(aPrevious, 57U)) + 3651845783283479752U;
            aOrbiterG = (((aWandererG + RotL64(aCross, 43U)) + RotL64(aCarry, 53U)) + 18145542190463500476U) + aNonceWordN;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 37U)) + 5415609566767162857U) + aOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 2033734872464201570U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 3507213117125813345U;
            aOrbiterK = RotL64((aOrbiterK * 5453058336688881113U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 8716253393049851856U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 695984869565941856U;
            aOrbiterC = RotL64((aOrbiterC * 8377921610764044735U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 7661578828878284931U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 906654265099155956U;
            aOrbiterB = RotL64((aOrbiterB * 8117625377607536949U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 6050049984731254612U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 17882717590338190821U;
            aOrbiterH = RotL64((aOrbiterH * 10807367411402733215U), 13U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterD) + 4996521991532815957U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordE;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 4246460672800604436U;
            aOrbiterI = RotL64((aOrbiterI * 12047466401960824903U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 8700148116452518842U) + aOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 10039050281847466206U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11884791271239660157U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 4513844680425845372U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 3037563127442815153U;
            aOrbiterE = RotL64((aOrbiterE * 18363509277992292407U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 1005237931570968724U) + aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 1373258132025712065U;
            aOrbiterF = RotL64((aOrbiterF * 10458020799382532395U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 12759144329395682277U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 5139371668116336931U;
            aOrbiterA = RotL64((aOrbiterA * 10761543179345026943U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 3211005174890625715U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 18045286961878287418U;
            aOrbiterG = RotL64((aOrbiterG * 4536094526540761611U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 4454078771279674978U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 4622023259121087483U;
            aOrbiterJ = RotL64((aOrbiterJ * 8991756794989027019U), 43U);
            //
            aIngress = RotL64(aOrbiterD, 23U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + (RotL64(aOrbiterB, 54U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((((RotL64(aCross, 53U) + RotL64(aOrbiterB, 5U)) + aOrbiterD) + aNonceWordC) + aWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 27U) + aOrbiterF) + RotL64(aOrbiterG, 21U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterD, 43U)) + aOrbiterG);
            aWandererI = aWandererI + ((RotL64(aScatter, 6U) + aOrbiterJ) + RotL64(aOrbiterB, 29U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterG, 11U));
            aWandererC = aWandererC + ((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 48U)) + aOrbiterJ);
            aWandererH = aWandererH ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterH, 37U)) + aOrbiterE);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 21U) + aOrbiterJ) + RotL64(aOrbiterI, 39U)) + RotL64(aCarry, 5U)) + aNonceWordP);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterA, 35U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 12U) + aOrbiterA) + RotL64(aOrbiterI, 57U)) + RotL64(aCarry, 51U)) + aNonceWordF);
            aWandererG = aWandererG ^ (((RotL64(aCross, 41U) + aOrbiterK) + RotL64(aOrbiterD, 52U)) + aWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 4U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (RotL64(aWandererE, 24U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 53U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordI;
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 14304U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((aIndex + 14181U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 12124U)) & S_BLOCK1], 58U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 11621U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 36U) ^ RotL64(aIngress, 21U)) + (RotL64(aCross, 5U) ^ RotL64(aPrevious, 53U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererB + RotL64(aIngress, 27U)) + 1557680213571812384U;
            aOrbiterB = ((aWandererE + RotL64(aScatter, 60U)) + RotL64(aCarry, 11U)) + 7387349725778021121U;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 23U)) + RotL64(aCarry, 43U)) + 15379264067601586976U;
            aOrbiterE = ((aWandererD + RotL64(aCross, 11U)) + 3730195724576043708U) + aOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aPrevious, 37U)) + 9637070085323827066U;
            aOrbiterA = (aWandererJ + RotL64(aCross, 19U)) + 1170865717363676184U;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 44U)) + 2750833653175252030U) + aNonceWordD;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 53U)) + 15118992811225568305U;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 47U)) + 4974092922102988451U;
            aOrbiterK = (((aWandererA + RotL64(aIngress, 5U)) + RotL64(aCarry, 5U)) + 10625719096296719514U) + aOrbiterAssignSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = (aWandererF + RotL64(aCross, 21U)) + 855167122475471865U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 11322911068958340262U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 4334591909425429835U;
            aOrbiterC = RotL64((aOrbiterC * 10059025861172038183U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 14263701737208936392U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 678723206735649084U;
            aOrbiterA = RotL64((aOrbiterA * 10823239851733632227U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 15652053114252065230U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 1705225940224061401U) ^ aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3626023093533713579U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 6826394665732900206U) + aOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 11902946775066981141U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 18300629262162694137U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 9802212958998591310U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 14001358545610206524U;
            aOrbiterJ = RotL64((aOrbiterJ * 13172645840788327099U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 4299184726135884309U) + aNonceWordC;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 7288757011999872416U;
            aOrbiterK = RotL64((aOrbiterK * 16806027820468277393U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 233801262480580205U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 14208660347238680268U;
            aOrbiterG = RotL64((aOrbiterG * 6299693448313154603U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 9217797359740446104U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 18165073197136050838U;
            aOrbiterE = RotL64((aOrbiterE * 11677479094709512887U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 9101905235436427482U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 2884224555227870272U;
            aOrbiterF = RotL64((aOrbiterF * 12085235281782370391U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 13118509728421714433U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 1385390888603164704U;
            aOrbiterH = RotL64((aOrbiterH * 6927424835779289199U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 9621084561183039538U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 1557680213571812384U) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 3202327770291862207U), 37U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 29U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 46U));
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterK, 48U)) + RotL64(aCarry, 47U)) + aWandererUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 48U) + aOrbiterI) + RotL64(aOrbiterE, 43U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 21U) + aOrbiterC) + RotL64(aOrbiterE, 19U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 43U) + aOrbiterH) + RotL64(aOrbiterA, 29U)) + aNonceWordE);
            aWandererC = aWandererC + (((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterF, 35U)) + aWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 53U)) + aOrbiterC);
            aWandererH = aWandererH + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterD, 3U)) + aOrbiterC) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 23U) + aOrbiterI) + RotL64(aOrbiterG, 11U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 26U) + RotL64(aOrbiterD, 26U)) + aOrbiterG);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterD, 41U)) + aOrbiterB);
            aWandererE = aWandererE + (((RotL64(aCross, 13U) + RotL64(aOrbiterA, 5U)) + aOrbiterG) + aNonceWordG);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 44U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordB);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 19719U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((aIndex + 16496U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18321U)) & S_BLOCK1], 5U) ^ RotL64(mSource[((aIndex + 20556U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 18U) ^ RotL64(aIngress, 39U)) + (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 5U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererH + RotL64(aCross, 53U)) + 3248574644570178787U;
            aOrbiterB = (((aWandererA + RotL64(aIngress, 37U)) + RotL64(aCarry, 23U)) + 4506961512959200024U) + aNonceWordF;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 23U)) + RotL64(aCarry, 35U)) + 8423739774540738590U;
            aOrbiterD = (aWandererK + RotL64(aScatter, 4U)) + 6593975869641735337U;
            aOrbiterK = (aWandererG + RotL64(aIngress, 29U)) + 16441716090557369103U;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 35U)) + RotL64(aCarry, 39U)) + 7936601450453207914U;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 47U)) + 13333752583560167065U) + aNonceWordN;
            aOrbiterI = (aWandererD + RotL64(aCross, 10U)) + 8013703284795432973U;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 43U)) + 2349852779887439236U) + aOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aCross, 27U)) + 5318539364763284138U;
            aOrbiterC = (((aWandererB + RotL64(aPrevious, 41U)) + 11450957608502944376U) + aOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordP;
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 9058992558327552687U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 632095686920230926U;
            aOrbiterG = RotL64((aOrbiterG * 12460364388358520799U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 14734218428913777098U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 16344357661370784442U) ^ aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15049472842002138369U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 2981145363531184308U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 14176472085175714494U;
            aOrbiterH = RotL64((aOrbiterH * 2584623327412130939U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 11198457590069700889U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 952584436750426828U;
            aOrbiterJ = RotL64((aOrbiterJ * 1165713888651280355U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 4311591763498985972U) + aNonceWordG;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 16194341833989936369U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9997934560195932575U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 7560794022401107431U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 10683789740265711603U;
            aOrbiterA = RotL64((aOrbiterA * 15637823045351977883U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 11614366395125937178U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 10750771385100564416U) ^ aOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4987921274272444283U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 2934697034132204529U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 4646873794658020363U;
            aOrbiterC = RotL64((aOrbiterC * 10555456865641580175U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 7913681837683568905U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 17603563535330106340U;
            aOrbiterE = RotL64((aOrbiterE * 17882943067522319671U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 15375641415139193079U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 17059712718085411887U;
            aOrbiterB = RotL64((aOrbiterB * 13722089235751208215U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 14022558453716067200U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 3248574644570178787U;
            aOrbiterD = RotL64((aOrbiterD * 15249135451439374621U), 37U);
            //
            aIngress = RotL64(aOrbiterA, 24U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + RotL64(aOrbiterB, 30U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 23U) + aOrbiterD) + RotL64(aOrbiterF, 40U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 44U) + RotL64(aOrbiterB, 53U)) + aOrbiterF) + RotL64(aCarry, 13U)) + aWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterG, 11U)) + aOrbiterD);
            aWandererE = aWandererE + ((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterK, 23U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterJ, 35U));
            aWandererK = aWandererK + ((RotL64(aScatter, 53U) + RotL64(aOrbiterC, 37U)) + aOrbiterD);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 34U) + RotL64(aOrbiterE, 27U)) + aOrbiterA);
            aWandererA = aWandererA + (((((RotL64(aCross, 41U) + RotL64(aOrbiterI, 13U)) + aOrbiterK) + RotL64(aCarry, 37U)) + aNonceWordD) + aWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterA, 5U));
            aWandererC = aWandererC + ((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterD, 57U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 21U) + aOrbiterA) + RotL64(aOrbiterD, 60U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + (RotL64(aWandererB, 60U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererJ, 26U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordA);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 26200U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23849U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24947U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24183U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 36U) ^ RotL64(aPrevious, 57U)) ^ (RotL64(aCarry, 23U) + RotL64(aIngress, 5U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererB + RotL64(aScatter, 23U)) + 16200278595895089008U;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 51U)) + RotL64(aCarry, 3U)) + 1029614154810465897U;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 60U)) + 7129562468705441295U) + aNonceWordG;
            aOrbiterF = (aWandererE + RotL64(aPrevious, 3U)) + 14388903902433951274U;
            aOrbiterA = (aWandererF + RotL64(aIngress, 35U)) + 1013568949315967455U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 39U)) + RotL64(aCarry, 43U)) + 3128823373497815651U;
            aOrbiterB = (((aWandererA + RotL64(aCross, 37U)) + 14525694606889470589U) + aOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordF;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 43U)) + 14443983602196782887U) + aOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aPrevious, 41U)) + 12244220415328641190U;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 5U)) + RotL64(aCarry, 13U)) + 10477159225338766614U;
            aOrbiterE = (aWandererK + RotL64(aScatter, 58U)) + 2842870123078131566U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 8621138818955849917U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 5038396344400303181U;
            aOrbiterI = RotL64((aOrbiterI * 14636756322207385447U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 2768613802894372496U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 2027754864051410015U;
            aOrbiterG = RotL64((aOrbiterG * 2461322540050569287U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 2848088309172056399U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 15017458513904884651U;
            aOrbiterJ = RotL64((aOrbiterJ * 9926904679902843055U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 9079797279596336139U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 15424866642305110811U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12912331089970158845U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 13751764050290602740U) + aNonceWordM;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 7694557131324740282U) ^ aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14980807690491467023U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 3508673897305667669U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 3600868397311393233U;
            aOrbiterF = RotL64((aOrbiterF * 5165032044164139165U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 1222655844979128996U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 2257342337168905875U;
            aOrbiterB = RotL64((aOrbiterB * 6198995971182272119U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 6290990717563682725U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 15308494772443447109U;
            aOrbiterH = RotL64((aOrbiterH * 1925593111157842325U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 4065385272074155855U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 17216369169581934516U;
            aOrbiterE = RotL64((aOrbiterE * 16172589962950781777U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 15683161334290612079U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 4197626901960576264U;
            aOrbiterC = RotL64((aOrbiterC * 2822547214684481747U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 4400047838649306704U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 16200278595895089008U;
            aOrbiterA = RotL64((aOrbiterA * 6603195071605635697U), 43U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 5U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 30U));
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 58U) + RotL64(aOrbiterH, 27U)) + aOrbiterJ) + aWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aCross, 43U) + RotL64(aOrbiterE, 36U)) + aOrbiterC) + RotL64(aCarry, 35U)) + aNonceWordO);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterD, 21U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 29U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterK, 43U)) + aOrbiterF);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 38U)) + aOrbiterG) + RotL64(aCarry, 57U)) + aNonceWordL);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterF, 51U)) + aOrbiterB);
            aWandererK = aWandererK + ((RotL64(aIngress, 3U) + RotL64(aOrbiterB, 47U)) + aOrbiterH);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 27U) + aOrbiterE) + RotL64(aOrbiterJ, 23U));
            aWandererI = aWandererI + (((RotL64(aCross, 60U) + aOrbiterG) + RotL64(aOrbiterH, 19U)) + aWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterA, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 60U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + RotL64(aWandererE, 56U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordA);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32234U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29297U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31496U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 29266U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCross, 23U)) + (RotL64(aIngress, 38U) + RotL64(aCarry, 5U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (aWandererC + RotL64(aCross, 22U)) + 13499155707765393469U;
            aOrbiterJ = (aWandererA + RotL64(aIngress, 47U)) + 3740324981823726185U;
            aOrbiterG = (aWandererB + RotL64(aScatter, 41U)) + 5470765363949735652U;
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 43U)) + 3446436171274452326U;
            aOrbiterD = (aWandererG + RotL64(aCross, 57U)) + 1778929412631211933U;
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 13U)) + RotL64(aCarry, 47U)) + 14666308799855220954U;
            aOrbiterH = (aWandererI + RotL64(aIngress, 39U)) + 4548410236791175055U;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 51U)) + RotL64(aCarry, 57U)) + 5829739767694190372U;
            aOrbiterC = (((aWandererE + RotL64(aIngress, 5U)) + RotL64(aCarry, 3U)) + 14319231414903675748U) + aOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aCross, 60U)) + 1513851750246111405U) + aOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 53U)) + 1685620217748986019U) + aNonceWordO;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 16284162182006054402U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 6271539598462003309U;
            aOrbiterG = RotL64((aOrbiterG * 13923286694131331137U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 12669312437565969473U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 11894755313393001665U;
            aOrbiterD = RotL64((aOrbiterD * 12556759675372354075U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 6315983824634946566U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 17106616474222892782U;
            aOrbiterI = RotL64((aOrbiterI * 167205520766791073U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 13350266700180455548U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 4608846311203767162U;
            aOrbiterH = RotL64((aOrbiterH * 2504857468837437365U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 14195866746143604365U) + aNonceWordA;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 7917977448256795054U;
            aOrbiterF = RotL64((aOrbiterF * 5927771378657284557U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 10707336923305131629U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 17122696159336995392U;
            aOrbiterC = RotL64((aOrbiterC * 13953518568670659191U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 5182322763573586116U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 6503754948502556246U) ^ aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14749002194140663519U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 14907832047832987341U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 6258064448676621346U;
            aOrbiterE = RotL64((aOrbiterE * 4407960312705621487U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 1180234574888070795U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 801686887651085881U;
            aOrbiterA = RotL64((aOrbiterA * 433981853631548041U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 11810494591997709554U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 9343740505955858127U;
            aOrbiterJ = RotL64((aOrbiterJ * 8733378485648720323U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 12816829575386720695U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 13499155707765393469U) ^ aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9937924703928730369U), 27U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 19U);
            aIngress = aIngress + (RotL64(aOrbiterB, 22U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + RotL64(aOrbiterJ, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 11U)) + aOrbiterD);
            aWandererH = aWandererH ^ ((RotL64(aCross, 18U) + aOrbiterC) + RotL64(aOrbiterD, 27U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 60U)) + aOrbiterA) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 53U)) + aOrbiterK);
            aWandererF = aWandererF + ((((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 23U)) + aWandererUpdateSaltD[((aIndex + 6U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 6U) + RotL64(aOrbiterI, 57U)) + aOrbiterJ);
            aWandererB = aWandererB + (((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 5U)) + aOrbiterD) + aWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 37U) + aOrbiterB) + RotL64(aOrbiterH, 50U)) + aNonceWordJ);
            aWandererA = aWandererA + (((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterH, 19U)) + aNonceWordK);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 21U) + aOrbiterE) + RotL64(aOrbiterB, 43U));
            aWandererK = aWandererK + ((RotL64(aScatter, 11U) + RotL64(aOrbiterE, 35U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (RotL64(aWandererA, 30U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + RotL64(aWandererD, 53U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ aNonceWordK;
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

void TwistExpander_Bowling_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xF18C91B9DE426B9BULL + 0xC0445ED0E0F352FFULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xE017A052796837DDULL + 0xA863AF39705E8499ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xE6E5DFFFF543DE57ULL + 0xC779F3CEFCC1A580ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x969AAE965DC1F47FULL + 0xCA108ADFD332E0A7ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xEE6CC407AF812603ULL + 0xAC4A371F85187055ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x8F0E9D639B7C6B99ULL + 0xA7DC94442DD84168ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xFE04120695C19B51ULL + 0xEA6C6992A7C0415BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF71746EB46CCDD6DULL + 0x88422286A2518EF5ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xF79D29BC06383C7BULL + 0xD467AD81E200DC68ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xA716490EC793A707ULL + 0xC0DB4B75B38D1920ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x97D91A04FB63BD4BULL + 0xB1CFD9C86600F2AEULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xD6F10B58AE79D187ULL + 0xAB9CF6CA77129E6BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xBBEC0AEA55472057ULL + 0xB08F2F57025CDF31ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xEBC7FB9CFC6B9E57ULL + 0x8A4351B7438A3A78ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xCD2628A99244A7FBULL + 0xBD7FC8AAC50DAE53ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xAC48096A0B7D56F9ULL + 0xCA54DD3A0B035DE7ULL);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2098U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneC[((aIndex + 2042U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 8102U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 1473U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aIngress, 35U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCross, 18U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (((aWandererK + RotL64(aCross, 19U)) + RotL64(aCarry, 23U)) + 13583136155674166402U) + aOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 48U)) + 12830472187484919497U) + aNonceWordI;
            aOrbiterF = (aWandererB + RotL64(aScatter, 27U)) + 18081197909484522509U;
            aOrbiterI = (((aWandererJ + RotL64(aIngress, 11U)) + RotL64(aCarry, 5U)) + 8680634051297891550U) + aOrbiterAssignSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = ((aWandererI + RotL64(aCross, 57U)) + 13939998767458656823U) + aNonceWordJ;
            aOrbiterD = (aWandererG + RotL64(aIngress, 23U)) + 1795730579103692594U;
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 5U)) + RotL64(aCarry, 39U)) + 17369751719734069999U;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 35U)) + 224769585901248068U) + aNonceWordD;
            aOrbiterE = (aWandererA + RotL64(aIngress, 44U)) + 4133547085925268180U;
            //
            aOrbiterK = (((aOrbiterK + aOrbiterC) + 7022512056309567391U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordA;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 10319484359046945495U;
            aOrbiterF = RotL64((aOrbiterF * 3400140531307001933U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 10483878349412282069U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 6481381149199985736U;
            aOrbiterD = RotL64((aOrbiterD * 9701719367082506253U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 13721077228796934509U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 9704818014314175007U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 760445624027740287U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 6253040047758584339U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 16890211690273641226U;
            aOrbiterE = RotL64((aOrbiterE * 5622534399866057841U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 6216227831265032436U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 2023609047004658739U;
            aOrbiterK = RotL64((aOrbiterK * 3252332895698310147U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 9201669637050388263U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 5106927540934338576U;
            aOrbiterI = RotL64((aOrbiterI * 6368134569042291431U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 10080368957861445998U) + aNonceWordF;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 10784789383436485808U) ^ aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3794918350254445939U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 15426339824951793026U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 17637144549368340331U;
            aOrbiterC = RotL64((aOrbiterC * 10971293914614704441U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 9941300382181962134U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 8118046374121322097U;
            aOrbiterH = RotL64((aOrbiterH * 8481945819050983127U), 19U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterD, 47U);
            aIngress = aIngress + (RotL64(aOrbiterK, 20U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 60U) + RotL64(aOrbiterF, 6U)) + aOrbiterA) + aWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 5U) + RotL64(aOrbiterF, 29U)) + aOrbiterE) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 51U)) + aOrbiterK);
            aWandererA = aWandererA + ((((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterE, 41U)) + RotL64(aCarry, 3U)) + aNonceWordK);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 42U) + RotL64(aOrbiterJ, 37U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterK, 19U)) + aWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterD, 58U)) + aNonceWordE);
            aWandererE = aWandererE + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterC, 13U)) + aOrbiterH);
            aWandererK = aWandererK ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterD, 23U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 30U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 14087U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11078U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15440U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneB[((aIndex + 14142U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 24U)) ^ (RotL64(aCross, 11U) + RotL64(aIngress, 41U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 14U)) + 4634399531433127141U) + aOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = (aWandererG + RotL64(aCross, 35U)) + 16961792729406903200U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 3U)) + 4105280732301137738U;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 43U)) + RotL64(aCarry, 47U)) + 15692013501147331191U;
            aOrbiterE = (((aWandererC + RotL64(aScatter, 47U)) + RotL64(aCarry, 11U)) + 1252216715968780587U) + aNonceWordK;
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 53U)) + 7958289043012473752U) + aNonceWordN;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 29U)) + 6611577301818896615U) + aNonceWordA;
            aOrbiterH = (((aWandererF + RotL64(aCross, 18U)) + RotL64(aCarry, 29U)) + 8506226754305949140U) + aOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aScatter, 39U)) + 3648813120449403353U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 5195245426245535735U) + aNonceWordO;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 542948051600803051U;
            aOrbiterB = RotL64((aOrbiterB * 4631106308856448475U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 11974253551208964789U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 10596463592332655367U;
            aOrbiterE = RotL64((aOrbiterE * 10941161258815714641U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 12015129484061440159U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 8254944355710109060U;
            aOrbiterC = RotL64((aOrbiterC * 3233697992479357615U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 2754858806943915419U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 5007802002906662779U) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 15613733948331639723U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 6262190752136523216U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 10528977986487821428U;
            aOrbiterI = RotL64((aOrbiterI * 1184258264034585525U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 8511097226098211854U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 12091864735686692582U) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 6128140528141411237U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 4970966265236842566U) + aOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 10728884018459718341U;
            aOrbiterG = RotL64((aOrbiterG * 18205183219769602827U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 13760057185629905360U) + aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 6590269178744829056U;
            aOrbiterJ = RotL64((aOrbiterJ * 14482684769712170123U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 765826377665103262U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 9364759196106579706U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10315111163659289329U), 19U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 20U);
            aIngress = aIngress + (RotL64(aOrbiterG, 39U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + RotL64(aOrbiterD, 44U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterG, 23U)) + aOrbiterB) + RotL64(aCarry, 37U)) + aNonceWordP);
            aWandererD = aWandererD ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterJ, 47U)) + aOrbiterE) + aNonceWordC);
            aWandererF = aWandererF + (((((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 19U)) + aOrbiterC) + RotL64(aCarry, 53U)) + aNonceWordH) + aWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterD, 27U)) + aOrbiterE);
            aWandererB = aWandererB + ((RotL64(aScatter, 41U) + aOrbiterF) + RotL64(aOrbiterE, 52U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 5U) + aOrbiterD) + RotL64(aOrbiterJ, 37U));
            aWandererH = aWandererH + ((RotL64(aCross, 51U) + RotL64(aOrbiterD, 43U)) + aOrbiterC);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 12U) + aOrbiterE) + RotL64(aOrbiterI, 3U)) + aWandererUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 27U) + RotL64(aOrbiterB, 60U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 26U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 35U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 19536U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneA[((aIndex + 23578U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 23648U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 17861U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 6U) ^ RotL64(aCross, 19U)) + (RotL64(aCarry, 37U) ^ RotL64(aIngress, 51U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererI + RotL64(aScatter, 29U)) + 4980738603982643969U;
            aOrbiterI = ((aWandererC + RotL64(aCross, 58U)) + RotL64(aCarry, 21U)) + 17660278413018470020U;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 35U)) + 17598114429859543466U) + aNonceWordH;
            aOrbiterA = (aWandererH + RotL64(aPrevious, 3U)) + 10993929335279994739U;
            aOrbiterC = (aWandererD + RotL64(aCross, 43U)) + 17967203122976322481U;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 53U)) + RotL64(aCarry, 43U)) + 1872290205549034384U;
            aOrbiterF = ((((aWandererE + RotL64(aPrevious, 14U)) + RotL64(aCarry, 35U)) + 16607778671782810797U) + aOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1]) + aNonceWordL;
            aOrbiterK = (aWandererF + RotL64(aIngress, 39U)) + 4895226930754394376U;
            aOrbiterB = (((aWandererB + RotL64(aPrevious, 23U)) + 14960359005982301383U) + aOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordN;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 9921642352377700630U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 893281964367208693U;
            aOrbiterG = RotL64((aOrbiterG * 2345509157333444217U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 8232519988397858732U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 4433022122758913407U;
            aOrbiterJ = RotL64((aOrbiterJ * 834240393225479419U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 12689609831247168353U) + aNonceWordJ;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 404535388957472176U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14534020545479806593U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 3349108201964013155U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 4386449511297371730U;
            aOrbiterI = RotL64((aOrbiterI * 9596273264321140229U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 14314587717949070586U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 10923886625271054985U;
            aOrbiterC = RotL64((aOrbiterC * 7838969002623486809U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 17634909585329833520U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 2021301459918350372U;
            aOrbiterD = RotL64((aOrbiterD * 1388242915918642741U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 5219599112498224367U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 10641339455385046206U;
            aOrbiterF = RotL64((aOrbiterF * 1022283727595400719U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 5003342156562330058U) + aNonceWordF;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 10951027475628404336U;
            aOrbiterK = RotL64((aOrbiterK * 17836928292555158461U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 13040991872592235460U) + aNonceWordG;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 11149099984302782267U;
            aOrbiterB = RotL64((aOrbiterB * 4248667283139686251U), 29U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 51U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 58U));
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + RotL64(aOrbiterK, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 30U) + aOrbiterI) + RotL64(aOrbiterD, 36U)) + aNonceWordK) + aWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 35U) + RotL64(aOrbiterC, 43U)) + aOrbiterF) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 13U) + aOrbiterK) + RotL64(aOrbiterG, 29U)) + aNonceWordO);
            aWandererC = aWandererC + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 51U)) + aOrbiterI) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 40U) + aOrbiterC) + RotL64(aOrbiterJ, 58U)) + aWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 23U) + aOrbiterK) + RotL64(aOrbiterB, 11U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 51U) + aOrbiterA) + RotL64(aOrbiterJ, 19U));
            aWandererI = aWandererI + ((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterA, 23U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterC, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 44U));
            aCarry = aCarry + RotL64(aWandererA, 53U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordD);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 28267U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28900U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24688U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 25350U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aIngress, 5U)) + (RotL64(aCross, 44U) ^ RotL64(aPrevious, 57U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (((aWandererG + RotL64(aPrevious, 12U)) + RotL64(aCarry, 57U)) + 5576732410244514238U) + aOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aScatter, 47U)) + 2833808925935929629U;
            aOrbiterG = (aWandererA + RotL64(aIngress, 41U)) + 3670188682914544792U;
            aOrbiterF = ((aWandererD + RotL64(aCross, 37U)) + 15759072378887814995U) + aNonceWordC;
            aOrbiterB = (aWandererB + RotL64(aIngress, 29U)) + 13934007231137439994U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 51U)) + RotL64(aCarry, 29U)) + 11022225696007690512U;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 60U)) + 16989177104453635790U;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 23U)) + RotL64(aCarry, 11U)) + 9256930045263527091U;
            aOrbiterE = ((aWandererE + RotL64(aCross, 19U)) + 17788596104417068290U) + aOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 17044369456673337625U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 1310908395523250343U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16305084373037705921U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 12067065689034065422U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 15130844248737512262U;
            aOrbiterB = RotL64((aOrbiterB * 9409499577465934107U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 14532689204495587494U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 8198147292120244178U;
            aOrbiterJ = RotL64((aOrbiterJ * 1418356389507740991U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 5485494458627163347U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 10830008207150307611U;
            aOrbiterA = RotL64((aOrbiterA * 6526039534042499457U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 17770065502486618029U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 6397859353395335459U;
            aOrbiterF = RotL64((aOrbiterF * 14286997752368893825U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 5128700697381508319U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 7103394110057060499U) ^ aNonceWordJ;
            aOrbiterC = RotL64((aOrbiterC * 5053680689949149633U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 16024401282261796979U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 12818445221897253410U;
            aOrbiterK = RotL64((aOrbiterK * 11450004517784155405U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 13386978409145916350U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 16740821954556699503U;
            aOrbiterE = RotL64((aOrbiterE * 5376430209628515105U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 313978038530994953U) + aOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 1355733685461795345U) ^ aOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15955927322082619735U), 57U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 11U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 48U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + RotL64(aOrbiterA, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aCross, 48U) + aOrbiterE) + RotL64(aOrbiterF, 39U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterJ, 13U)) + aOrbiterI) + aNonceWordM);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterE, 35U)) + aOrbiterJ) + RotL64(aCarry, 37U)) + aNonceWordN);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterK, 4U)) + aOrbiterJ);
            aWandererG = aWandererG + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterJ, 29U)) + aOrbiterA);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 43U) + aOrbiterF) + RotL64(aOrbiterB, 43U));
            aWandererA = aWandererA + ((RotL64(aIngress, 27U) + aOrbiterI) + RotL64(aOrbiterF, 57U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 3U) + aOrbiterK) + RotL64(aOrbiterG, 24U)) + aWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 10U) + RotL64(aOrbiterK, 51U)) + aOrbiterC) + RotL64(aCarry, 53U)) + aWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 10U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 46U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordM);
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

void TwistExpander_Bowling_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xBFB8A0AA4EDABB57ULL + 0xF77F9B0B829203F3ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xBC7AAC4778B029B5ULL + 0xDE66428676095FC4ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xA5ADB6B71F9D6C03ULL + 0x82F7BEE68F36ECF8ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x891445EC110D9E39ULL + 0x866F2E15F5F8D903ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xF3ED58B4451E06FDULL + 0xF430959421C81916ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xFC86011C3DF83BFDULL + 0xF741601FBA75BD04ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xB8A71734FA5D4E15ULL + 0xC3674B014209B6A7ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xC39212A13E7C4793ULL + 0xFAA7EE5C3A6E7174ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xF69FE792CBE184B1ULL + 0xBD58D07B18AE14F1ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xBCCA13DDAF083B01ULL + 0xED23DCEEBA70517EULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x9838A8FEAA7D00FBULL + 0xFD00D8157917A234ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xE9F6C75E2C6401F5ULL + 0xC0BB72BBE9B62BCDULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xDC11BA95E1ABF15BULL + 0xBC638A62FF20916CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xED6A2DD92ABAC233ULL + 0xE5BA30C81134D2FEULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xC058246478011F99ULL + 0xBA3A270842D28F1DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xE08F0992A436D36FULL + 0x96A4D62B1B5940A0ULL);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 335U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3010U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8086U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneA[((aIndex + 8119U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 52U) + RotL64(aIngress, 35U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererI + RotL64(aScatter, 23U)) + 13714409587461539863U) + aNonceWordA;
            aOrbiterG = (aWandererA + RotL64(aCross, 57U)) + 14101156723903265839U;
            aOrbiterD = ((((aWandererD + RotL64(aIngress, 37U)) + RotL64(aCarry, 13U)) + 7063754562895369001U) + aOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordP;
            aOrbiterB = ((((aWandererB + RotL64(aPrevious, 13U)) + RotL64(aCarry, 39U)) + 12320578575245519386U) + aOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordE;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 48U)) + RotL64(aCarry, 53U)) + 11744826789631008424U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 8744816505096675597U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = (((aOrbiterD ^ aOrbiterF) ^ 10405435520084528645U) ^ aOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 13279521344071568023U), 39U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterJ) + 1463157688070683543U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 12379603577919617703U;
            aOrbiterF = RotL64((aOrbiterF * 14858901470015109311U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 1343439118031348146U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 16118850268070235540U;
            aOrbiterB = RotL64((aOrbiterB * 11184386483735388257U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 14116264435819277136U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 5251698273012432109U;
            aOrbiterG = RotL64((aOrbiterG * 1495818611622063967U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 14806408656041403829U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 11569345414052398227U) ^ aOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9913158908301414861U), 57U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 19U);
            aIngress = aIngress + (RotL64(aOrbiterF, 30U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 39U)) + aOrbiterJ);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterJ, 53U)) + aOrbiterG) + RotL64(aCarry, 47U)) + aNonceWordD);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 11U) + aOrbiterB) + RotL64(aOrbiterG, 12U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 50U) + aOrbiterG) + RotL64(aOrbiterD, 21U)) + RotL64(aCarry, 19U)) + aWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 3U)) + aOrbiterJ) + aWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + (RotL64(aWandererD, 24U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordM;
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9912U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneD[((aIndex + 12869U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15451U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 9160U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aIngress, 4U)) + (RotL64(aCarry, 23U) + RotL64(aPrevious, 53U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererD + RotL64(aPrevious, 3U)) + 9471546960258473684U;
            aOrbiterA = ((((aWandererB + RotL64(aCross, 11U)) + RotL64(aCarry, 23U)) + 18050235435948942244U) + aOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordG;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 29U)) + 3005107102671544641U) + aOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aIngress, 58U)) + RotL64(aCarry, 53U)) + 17898396434573801850U;
            aOrbiterH = (((aWandererK + RotL64(aPrevious, 47U)) + RotL64(aCarry, 37U)) + 15071602525497771648U) + aNonceWordD;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 5780119462702672108U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 13301326224151025687U) ^ aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2868878978993219351U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 18129323022260575961U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 1199228670638790709U) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 1780426336211781025U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 1839199978088021020U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 4999517042246790165U;
            aOrbiterE = RotL64((aOrbiterE * 4585813675677234577U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 8788607633376516299U) + aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 15143903839930468749U;
            aOrbiterA = RotL64((aOrbiterA * 12735914889325422675U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 16674732686428431869U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 15908873150953195581U) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 18049755517524334107U), 53U);
            //
            aIngress = RotL64(aOrbiterG, 3U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterA, 36U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 40U) + aOrbiterE) + RotL64(aOrbiterH, 3U));
            aWandererD = aWandererD + (((((RotL64(aScatter, 27U) + aOrbiterH) + RotL64(aOrbiterI, 11U)) + RotL64(aCarry, 3U)) + aNonceWordH) + aWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterG, 47U)) + aOrbiterI);
            aWandererE = aWandererE + (((((RotL64(aCross, 19U) + RotL64(aOrbiterA, 21U)) + aOrbiterG) + RotL64(aCarry, 27U)) + aNonceWordF) + aWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterG, 36U)) + aNonceWordM);
            //
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 37U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordK);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 22443U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 17885U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20294U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneC[((aIndex + 17423U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCross, 37U)) + (RotL64(aPrevious, 51U) + RotL64(aCarry, 6U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (((aWandererC + RotL64(aScatter, 48U)) + RotL64(aCarry, 35U)) + 5510690816044082200U) + aOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aIngress, 29U)) + RotL64(aCarry, 3U)) + 15967820875033940530U;
            aOrbiterF = (aWandererB + RotL64(aCross, 39U)) + 539348720848176221U;
            aOrbiterH = ((((aWandererD + RotL64(aPrevious, 5U)) + RotL64(aCarry, 53U)) + 15779318183635560817U) + aOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordM;
            aOrbiterG = (aWandererE + RotL64(aIngress, 19U)) + 14511058534424187469U;
            //
            aOrbiterA = (((aOrbiterA + aOrbiterB) + 5811130556873428391U) + aOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1]) + aNonceWordB;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 1085928476499444025U) ^ aOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13965845678632598921U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 6973335316600768130U) + aOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 10747243745475009744U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17322489216048017061U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 1072260008981349754U) + aNonceWordO;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 2018772405352495753U;
            aOrbiterA = RotL64((aOrbiterA * 10840562112080574241U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 1092091597048996547U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 15103140149542167197U;
            aOrbiterH = RotL64((aOrbiterH * 621856991658027989U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 13194619321108681542U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 16749188603268621850U) ^ aNonceWordP;
            aOrbiterG = RotL64((aOrbiterG * 9575408950550922039U), 39U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 13U);
            aIngress = aIngress + (RotL64(aOrbiterF, 60U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 13U)) + aWandererUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 4U) + RotL64(aOrbiterH, 13U)) + aOrbiterG);
            aWandererE = aWandererE + (((RotL64(aCross, 37U) + aOrbiterH) + RotL64(aOrbiterA, 40U)) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterG, 21U)) + aWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 23U) + RotL64(aOrbiterH, 57U)) + aOrbiterF) + aNonceWordJ);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 58U));
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 29U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ aNonceWordI;
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 27484U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30170U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28993U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneD[((aIndex + 31709U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 20U) + RotL64(aCarry, 57U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 19U)) + 3255291173184001106U) + aNonceWordJ;
            aOrbiterB = (((aWandererD + RotL64(aIngress, 3U)) + RotL64(aCarry, 39U)) + 15308468160116255528U) + aNonceWordE;
            aOrbiterA = (((aWandererF + RotL64(aScatter, 30U)) + RotL64(aCarry, 13U)) + 18186972408589866656U) + aOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = ((((aWandererB + RotL64(aCross, 39U)) + RotL64(aCarry, 27U)) + 4439324265978331914U) + aOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordL;
            aOrbiterC = (aWandererK + RotL64(aIngress, 53U)) + 13099263173016322486U;
            //
            aOrbiterD = (((aOrbiterD + aOrbiterB) + 7041561081767500660U) + aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1]) + aNonceWordG;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 6196422612687812971U) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 13359900204297781063U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 7664260932541281413U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 17802347823020441056U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2220679459017369255U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 4253107484061190446U) + aOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 13799496534030645312U) ^ aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9167675060053848207U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 14252892847595951926U) + aNonceWordN;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 5663527578664291422U;
            aOrbiterB = RotL64((aOrbiterB * 18314294235895182465U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 11148755959699137661U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 17036900929333594592U;
            aOrbiterC = RotL64((aOrbiterC * 16041243617369003291U), 41U);
            //
            aIngress = RotL64(aOrbiterG, 3U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + RotL64(aOrbiterB, 26U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterD, 34U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterG, 21U)) + aOrbiterA) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ ((((RotL64(aCross, 37U) + aOrbiterB) + RotL64(aOrbiterA, 57U)) + aNonceWordD) + aWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            aWandererK = aWandererK + (((((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 39U)) + aNonceWordH) + aWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 60U) + aOrbiterD) + RotL64(aOrbiterG, 11U)) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + RotL64(aWandererK, 50U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordN;
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

void TwistExpander_Bowling_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xF221605F38A43BCFULL + 0xA83C6BB5CF1EFEF6ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xDBA0B7D61FDA4E29ULL + 0xFBCD88B271C87FF5ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x903C305BB94EBA0FULL + 0x9967A024A6EC06E4ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xFC5ED1BF7C30BA79ULL + 0x9C3A2E202BF23FF4ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xFA198A83691518BBULL + 0xB39F7D2AE1563D7CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xFA8BD40121D0F453ULL + 0xD3AF4B4BA44E2432ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xCB4DCE70581CB7BBULL + 0xF37D0FD8A2BC796EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x8BA956F8076B866BULL + 0xC8664D3ACCA12F44ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xCA3922B3E06E38C3ULL + 0xE28B8B68DE43E752ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x88C9CA1398D017ABULL + 0xE9A60970E0190ACCULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xED0143986B8F3821ULL + 0xA5BF0AAABD416079ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x9F56C8567B80A80FULL + 0x93A7C2A7016FBB94ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x9532AE7FEC5FD5D7ULL + 0xB087CD0B9B9878F4ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x87018E80DD2C18EBULL + 0xF5DDA65A22EBBA98ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x8FCD24A6FD55ECCDULL + 0xD1030DCB45189A46ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xF979014FDDE0728DULL + 0xFF3136333B7B689AULL);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 6182U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((aIndex + 7046U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1591U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneA[((aIndex + 7118U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 54U) ^ RotL64(aCarry, 3U)) + (RotL64(aCross, 23U) + RotL64(aPrevious, 39U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 58U)) + RotL64(aCarry, 35U)) + 13296600294247799698U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 41U)) + 5818503518080877515U) + aNonceWordC;
            aOrbiterK = (((aWandererH + RotL64(aPrevious, 29U)) + 6735784238734173597U) + aOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1]) + aNonceWordB;
            aOrbiterD = (aWandererG + RotL64(aCross, 5U)) + 7368398209488856201U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 11U)) + RotL64(aCarry, 47U)) + 961734029066455638U;
            aOrbiterJ = (((aWandererF + RotL64(aPrevious, 35U)) + RotL64(aCarry, 13U)) + 797011946660892011U) + aOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aIngress, 21U)) + 12841876018396622350U) + aNonceWordN;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 16213253970483895623U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 15186950557113470375U;
            aOrbiterK = RotL64((aOrbiterK * 4647470430467908107U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 5117930310827477341U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 12265429373166094162U;
            aOrbiterE = RotL64((aOrbiterE * 1522823535151532249U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 13920531346698601568U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterB) ^ 14695405206998211456U) ^ aOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterJ = RotL64((aOrbiterJ * 13950964363414164279U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 7851960904825938443U) + aNonceWordP;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 9501511171732550190U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5614164120361489613U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 5663365182245722077U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 9607860124321315555U;
            aOrbiterA = RotL64((aOrbiterA * 3461820361914280601U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 18171052650586819280U) + aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 3442698321538580861U;
            aOrbiterD = RotL64((aOrbiterD * 6317525514963824829U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 1491052813469258970U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 3956599824067616133U;
            aOrbiterB = RotL64((aOrbiterB * 2928600779267623085U), 21U);
            //
            aIngress = RotL64(aOrbiterA, 27U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 50U));
            aIngress = aIngress + RotL64(aOrbiterJ, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 46U) + RotL64(aOrbiterF, 60U)) + aOrbiterA) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterF, 35U)) + aNonceWordI);
            aWandererF = aWandererF + (((RotL64(aScatter, 11U) + RotL64(aOrbiterJ, 47U)) + aOrbiterA) + aWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterJ, 3U));
            aWandererH = aWandererH + (((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterA, 23U)) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 37U) + aOrbiterD) + RotL64(aOrbiterE, 11U));
            aWandererD = aWandererD + (((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 29U)) + aOrbiterB) + aWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 28U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 13U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10502U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneD[((aIndex + 11703U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10815U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 14348U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 39U)) ^ (RotL64(aCarry, 27U) + RotL64(aIngress, 56U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererA + RotL64(aCross, 43U)) + 8975885703279267062U;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 37U)) + RotL64(aCarry, 19U)) + 8664844915562660637U;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 50U)) + 12281774799736296726U) + aOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = (aWandererE + RotL64(aScatter, 11U)) + 15347461352311329726U;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 27U)) + RotL64(aCarry, 47U)) + 12967500561828907834U;
            aOrbiterA = (aWandererH + RotL64(aCross, 19U)) + 5002833859280402726U;
            aOrbiterF = ((((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 35U)) + 11908257536954668983U) + aOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordI;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 17017174811949227162U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 16851323125613931180U;
            aOrbiterE = RotL64((aOrbiterE * 12446990992858763577U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 13469326957728686706U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 5228638551056105241U) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 13369947664646167255U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 11945166198089308564U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 16268645041872996022U;
            aOrbiterK = RotL64((aOrbiterK * 5391448793718370911U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 14781204627695095701U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 5365325354838101092U;
            aOrbiterI = RotL64((aOrbiterI * 8017284997946310807U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 563147416025715953U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 14660867395395625851U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4769458126865307103U), 21U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterH) + 3168989056355712105U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordG;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 16179131669773665579U;
            aOrbiterA = RotL64((aOrbiterA * 5641461617066671723U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 4160220074225527179U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 8597134686962559111U) ^ aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 639572585431474015U), 57U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterA, 47U);
            aIngress = aIngress + (RotL64(aOrbiterI, 20U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterK, 53U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterB, 51U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterE, 41U)) + aWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterK, 21U)) + aOrbiterH) + aNonceWordE) + aWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterB, 57U)) + aOrbiterF);
            aWandererA = aWandererA + (((RotL64(aIngress, 57U) + RotL64(aOrbiterA, 5U)) + aOrbiterF) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 4U) + aOrbiterK) + RotL64(aOrbiterI, 28U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 52U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 43U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 22259U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 20985U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19410U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneC[((aIndex + 22723U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 36U)) + (RotL64(aCross, 5U) + RotL64(aIngress, 57U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((((aWandererF + RotL64(aScatter, 29U)) + RotL64(aCarry, 23U)) + 15920462086654025436U) + aOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordM;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 13U)) + 487844076858004017U) + aOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aCross, 53U)) + RotL64(aCarry, 57U)) + 14502883786442630566U;
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 20U)) + RotL64(aCarry, 43U)) + 3787107318658233674U;
            aOrbiterA = (aWandererB + RotL64(aIngress, 41U)) + 12548777544693755491U;
            aOrbiterF = (aWandererE + RotL64(aCross, 35U)) + 4907309444075181683U;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 3U)) + 18342396700266492072U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 13503051997624242670U) + aNonceWordH;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 17845742460521374571U;
            aOrbiterC = RotL64((aOrbiterC * 1366356786138085155U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 8640887211877858169U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 5273913123709097537U;
            aOrbiterG = RotL64((aOrbiterG * 1661149444148461791U), 3U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterI) + 17756844173695563883U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordG;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 6713055830729302951U;
            aOrbiterK = RotL64((aOrbiterK * 2832836748513174311U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 5106468334224035972U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 10228769728713526172U;
            aOrbiterI = RotL64((aOrbiterI * 9760310686414358435U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 7687649520668883142U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 7757480627354711605U;
            aOrbiterA = RotL64((aOrbiterA * 7222553727737349209U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 10876291698508634557U) + aOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = (((aOrbiterF ^ aOrbiterC) ^ 8149278085586014186U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterF = RotL64((aOrbiterF * 8577133863470695381U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 15592893988925610485U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 8639028256640537165U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1880655276432963955U), 43U);
            //
            aIngress = RotL64(aOrbiterI, 35U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aScatter, 5U) + aOrbiterK) + RotL64(aOrbiterI, 53U)) + RotL64(aCarry, 29U)) + aNonceWordL);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 34U) + RotL64(aOrbiterC, 29U)) + aOrbiterD);
            aWandererB = aWandererB + (((RotL64(aCross, 27U) + RotL64(aOrbiterA, 60U)) + aOrbiterF) + aNonceWordO);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterD, 41U)) + aWandererUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererE = aWandererE + (((((RotL64(aCross, 11U) + aOrbiterA) + RotL64(aOrbiterD, 23U)) + RotL64(aCarry, 51U)) + aNonceWordC) + aWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterD, 5U)) + aOrbiterF);
            aWandererF = aWandererF + ((RotL64(aIngress, 41U) + aOrbiterI) + RotL64(aOrbiterF, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + RotL64(aWandererD, 12U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 25943U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26182U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27773U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 31521U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aPrevious, 36U)) + (RotL64(aIngress, 53U) ^ RotL64(aCarry, 23U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (((aWandererI + RotL64(aPrevious, 53U)) + 2783898056762489197U) + aOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1]) + aNonceWordF;
            aOrbiterK = (((aWandererD + RotL64(aCross, 27U)) + RotL64(aCarry, 35U)) + 7177192902873343053U) + aNonceWordO;
            aOrbiterB = (aWandererJ + RotL64(aIngress, 3U)) + 12254703232691980774U;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 43U)) + RotL64(aCarry, 47U)) + 15446547245691219559U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 13U)) + RotL64(aCarry, 5U)) + 888475203006174856U;
            aOrbiterI = ((aWandererE + RotL64(aCross, 21U)) + 3649183529366307877U) + aOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aIngress, 36U)) + 4642631047518805167U) + aNonceWordL;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 6108329730724782250U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 8334054653023816636U) ^ aOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9352516059501924393U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 5891895375031474350U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 3176720746238477862U) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 1869961473768307911U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 6111038696865301675U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 11914998302228682704U) ^ aOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11738924766359642853U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 17005063057791320948U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 18333780598768130670U;
            aOrbiterD = RotL64((aOrbiterD * 5416759844884107303U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 2056115016443263153U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 10245512728872962677U;
            aOrbiterG = RotL64((aOrbiterG * 707106795383284903U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 4810366069422162351U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 3051442983125942469U) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 13558537578054436423U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 9285068547223654308U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 13067251130180968842U;
            aOrbiterA = RotL64((aOrbiterA * 7000687697769766605U), 21U);
            //
            aIngress = RotL64(aOrbiterI, 19U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aPrevious, 34U) + RotL64(aOrbiterI, 18U)) + aOrbiterD) + RotL64(aCarry, 53U)) + aNonceWordH);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 3U)) + aOrbiterK) + aNonceWordJ);
            aWandererI = aWandererI + ((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 53U)) + aOrbiterB);
            aWandererH = aWandererH ^ ((RotL64(aCross, 43U) + aOrbiterB) + RotL64(aOrbiterG, 11U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 13U) + aOrbiterK) + RotL64(aOrbiterG, 41U)) + RotL64(aCarry, 41U)) + aWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterA, 27U)) + aOrbiterK) + aWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterD, 47U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 14U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + RotL64(aWandererD, 43U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordP;
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

void TwistExpander_Bowling_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xB8B502E19C45D949ULL + 0xCF0C423FCE97CDD5ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x804B97B6CC69F9BDULL + 0x8E49BD643AB55E16ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xF1262A9DF8A64EEFULL + 0xB943F9939F40126CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x91FBF224C6072A85ULL + 0xB62859E34B6D0B74ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xB15F10E1A5E453CDULL + 0xB78378E2DC21F815ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x9E85D9B7652B85C1ULL + 0xD60396D4DACC5DB9ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x9DA1D08F0ACB030FULL + 0xA6AC5A611B30A1B8ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xFE7D28291ECCE069ULL + 0xFB53296C9F82CB15ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xFE3239AF6F5EA903ULL + 0xC580C278CA67E098ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xB6033ED05B3B34ADULL + 0xAC45956A3666AE76ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xDADBACDFFB7EC401ULL + 0xC2752D66E2098995ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xFBD3C512B023DD3DULL + 0xF1E3A525F4AA48F6ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xBEBD4E878AF38FFFULL + 0xE9BF5E2A1C5A7A12ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xB3CE6C65B0D7DA57ULL + 0xAB0FCB03E8C20F98ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x90722A94FEC87A11ULL + 0xD0BC935CF6D98FC3ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xE86939F95FD16525ULL + 0xD715590FE8832D46ULL);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 3098U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneC[((aIndex + 3426U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 2568U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((aIndex + 5300U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 39U) ^ RotL64(aIngress, 20U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererG + RotL64(aCross, 53U)) + 3561491146322798260U;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 11U)) + 7075025056181885339U) + aNonceWordK;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 35U)) + RotL64(aCarry, 19U)) + 9230910887904171613U;
            aOrbiterA = (((aWandererC + RotL64(aPrevious, 21U)) + RotL64(aCarry, 35U)) + 4119781172609908917U) + aOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aCross, 44U)) + 17155609083870983149U;
            aOrbiterB = (((aWandererE + RotL64(aIngress, 27U)) + RotL64(aCarry, 3U)) + 2423018561430181695U) + aOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aScatter, 5U)) + 12957280305617615744U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 2461704174772065813U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 7907123257849391997U;
            aOrbiterG = RotL64((aOrbiterG * 9416171962847312179U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 7257868138318960007U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 16425903703085702285U) ^ aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7996935869077231999U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 2990822664594079467U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 5654819006718953817U;
            aOrbiterB = RotL64((aOrbiterB * 4465096036756887801U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 12183676471235678779U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 15026286960542123922U;
            aOrbiterH = RotL64((aOrbiterH * 17199049329995315279U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 12169080607071830522U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 2906296852254787499U;
            aOrbiterI = RotL64((aOrbiterI * 6754514406846040163U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 3029858695410344584U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 14406410317495954566U) ^ aOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9663780721657983421U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 11048818178401163861U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 13622063920319445043U) ^ aNonceWordH;
            aOrbiterF = RotL64((aOrbiterF * 2516025554421589857U), 19U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterH, 37U);
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 13U)) + aOrbiterI) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterB, 47U)) + aOrbiterG) + aWandererUpdateSaltF[((aIndex + 12U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 41U)) + aOrbiterI);
            aWandererA = aWandererA ^ (((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterB, 35U)) + aWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 19U) + RotL64(aOrbiterH, 28U)) + aOrbiterA) + aNonceWordM);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 26U) + aOrbiterH) + RotL64(aOrbiterG, 57U)) + aNonceWordG);
            aWandererH = aWandererH + ((((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 35U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 18U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + RotL64(aWandererJ, 23U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 11855U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 11969U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 15892U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((aIndex + 9006U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 43U) + RotL64(aCross, 23U)) ^ (RotL64(aCarry, 58U) + RotL64(aPrevious, 11U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererF + RotL64(aPrevious, 19U)) + 14499676118633326000U;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 28U)) + RotL64(aCarry, 11U)) + 17191273593018552288U;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 3U)) + 4085176294948097737U) + aNonceWordF;
            aOrbiterG = ((aWandererG + RotL64(aIngress, 57U)) + 11112671474158908186U) + aOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = (((aWandererI + RotL64(aPrevious, 41U)) + RotL64(aCarry, 23U)) + 8745787969012266485U) + aOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (((aWandererA + RotL64(aIngress, 35U)) + RotL64(aCarry, 51U)) + 18074049663777707948U) + aNonceWordM;
            aOrbiterC = (aWandererB + RotL64(aScatter, 11U)) + 2543758649719164688U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 4659584749412700523U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 974639159259871273U;
            aOrbiterH = RotL64((aOrbiterH * 17918719351847605523U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 9211220687971081987U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 8567024626862182714U;
            aOrbiterI = RotL64((aOrbiterI * 7755874089832496393U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 5803002132294840900U) + aNonceWordL;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 11968489432878148467U) ^ aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4501441062617123165U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 9470807228394903442U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 1692347973120388469U;
            aOrbiterK = RotL64((aOrbiterK * 17433393164156231575U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 16510815732690193145U) + aOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 755159406833096510U;
            aOrbiterB = RotL64((aOrbiterB * 14091736464659561165U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 1518824876475937620U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 701225390867330446U) ^ aOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12264618860580199927U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 8425976693733003889U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 7182176375442410367U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8860605703761731859U), 29U);
            //
            aIngress = RotL64(aOrbiterC, 60U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + RotL64(aOrbiterB, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aCross, 36U) + RotL64(aOrbiterH, 39U)) + aOrbiterC);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 5U)) + aOrbiterJ) + aNonceWordK);
            aWandererF = aWandererF + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 29U)) + aOrbiterG) + RotL64(aCarry, 39U)) + aNonceWordP);
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 51U) + aOrbiterB) + RotL64(aOrbiterG, 47U)) + aNonceWordO) + aWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterG, 58U)) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 23U) + aOrbiterJ) + RotL64(aOrbiterH, 13U)) + aWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 23U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 24U));
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23532U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 20095U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 21811U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 20151U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCarry, 40U)) ^ (RotL64(aPrevious, 3U) ^ RotL64(aCross, 53U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererC + RotL64(aIngress, 56U)) + 15920462086654025436U;
            aOrbiterF = ((aWandererK + RotL64(aCross, 5U)) + RotL64(aCarry, 53U)) + 487844076858004017U;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 37U)) + RotL64(aCarry, 3U)) + 14502883786442630566U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 43U)) + 3787107318658233674U) + aNonceWordA;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 27U)) + 12548777544693755491U) + aOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = (((aWandererA + RotL64(aPrevious, 11U)) + RotL64(aCarry, 27U)) + 4907309444075181683U) + aOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aIngress, 19U)) + 18342396700266492072U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 13503051997624242670U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 17845742460521374571U;
            aOrbiterJ = RotL64((aOrbiterJ * 1366356786138085155U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 8640887211877858169U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 5273913123709097537U) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 1661149444148461791U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 17756844173695563883U) + aNonceWordH;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 6713055830729302951U) ^ aOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2832836748513174311U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 5106468334224035972U) + aNonceWordP;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 10228769728713526172U;
            aOrbiterC = RotL64((aOrbiterC * 9760310686414358435U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 7687649520668883142U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 7757480627354711605U;
            aOrbiterK = RotL64((aOrbiterK * 7222553727737349209U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 10876291698508634557U) + aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 8149278085586014186U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8577133863470695381U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 15592893988925610485U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 8639028256640537165U;
            aOrbiterG = RotL64((aOrbiterG * 1880655276432963955U), 41U);
            //
            aIngress = RotL64(aOrbiterG, 26U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 60U) + aOrbiterB) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterF, 19U)) + aNonceWordI);
            aWandererC = aWandererC + ((((RotL64(aCross, 21U) + aOrbiterG) + RotL64(aOrbiterJ, 11U)) + RotL64(aCarry, 53U)) + aWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterG, 29U)) + aOrbiterK);
            aWandererF = aWandererF + ((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 58U)) + aOrbiterF);
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterK, 35U)) + aOrbiterC) + aNonceWordB) + aWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 51U) + aOrbiterK) + RotL64(aOrbiterH, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 14U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27608U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((aIndex + 31154U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25732U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 28050U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 36U) + RotL64(aIngress, 53U)) + (RotL64(aPrevious, 19U) ^ RotL64(aCross, 3U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (((aWandererK + RotL64(aIngress, 40U)) + RotL64(aCarry, 43U)) + 6163290588946759209U) + aNonceWordH;
            aOrbiterI = (((aWandererI + RotL64(aPrevious, 47U)) + RotL64(aCarry, 21U)) + 7342672468560105447U) + aOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = ((aWandererC + RotL64(aScatter, 53U)) + RotL64(aCarry, 5U)) + 11574563167017282321U;
            aOrbiterC = ((aWandererE + RotL64(aCross, 27U)) + 2254820206194758964U) + aNonceWordL;
            aOrbiterJ = (aWandererG + RotL64(aIngress, 13U)) + 1469783447473099498U;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 21U)) + 14174828900676165088U) + aOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = (aWandererF + RotL64(aPrevious, 3U)) + 16277954291890598132U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 14845750668693136766U) + aNonceWordO;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 150099699692047766U;
            aOrbiterA = RotL64((aOrbiterA * 7644895634421086357U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 1200784917165131703U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 9469982764806754302U;
            aOrbiterH = RotL64((aOrbiterH * 17851969334511301943U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 10956702761701710182U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 7915506894975487807U) ^ aNonceWordD;
            aOrbiterI = RotL64((aOrbiterI * 8874108311712727983U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 17335794183733623213U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 557028996286989506U;
            aOrbiterJ = RotL64((aOrbiterJ * 3993359298602424281U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 1597385667771002414U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 4376417959915162639U;
            aOrbiterD = RotL64((aOrbiterD * 4626236858205178149U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 549770198518993876U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 756554555648070919U) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 16272320259614325355U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 7298557532533152193U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 3336802611342112013U) ^ aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14679103452120080499U), 21U);
            //
            aIngress = RotL64(aOrbiterD, 47U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterC, 51U)) + aOrbiterI);
            aWandererK = aWandererK + ((((RotL64(aIngress, 43U) + aOrbiterH) + RotL64(aOrbiterJ, 43U)) + aNonceWordK) + aWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterH, 57U)) + aOrbiterC) + aNonceWordN);
            aWandererI = aWandererI + (((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 22U)) + aOrbiterD) + RotL64(aCarry, 37U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 37U) + aOrbiterC) + RotL64(aOrbiterA, 3U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 4U) + RotL64(aOrbiterD, 13U)) + aOrbiterE) + RotL64(aCarry, 21U)) + aWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterE, 37U)) + aNonceWordI);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 36U));
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererG, 53U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordL);
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

void TwistExpander_Bowling_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xB8D673A64FA92BA7ULL + 0x80D5536D78B4BE56ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x9E66DDDDB46E5E4BULL + 0xCEFD4F2AF6771845ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x8808C8B90E226421ULL + 0x88B12904EDFE5F15ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE80E59B02CFA4601ULL + 0xC11AA1588354661EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xF492C2DE9E9866D9ULL + 0xA2D291359CB770FEULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xFEA43F66BEEEFA23ULL + 0x80CF7B2964F4DE5DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xC1A3C0EE875B4F3FULL + 0xA6D27876058E3310ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xA1D9E23FD722D99FULL + 0x80D9091835E10B9BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xC9135F98DB4F050FULL + 0xD9A7689229D2DBC9ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xB2E70E0F9CFD76FDULL + 0xDF0148F85162B8A4ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xE671A471B8270309ULL + 0x8A89B775BB1386FCULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x81DE0F41CC662E43ULL + 0xD03165FDE88E5B4EULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x88E38C516BD343BDULL + 0xF9D12D7B896D0A89ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xEA51AA65E52C0C23ULL + 0xB5C5E4D9D210B125ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xEADFF2573CE8D0E3ULL + 0xB2888F02697D4BB3ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xA5A8C56C182CAD63ULL + 0xE2B76D65D8C5173FULL);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 6614U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4295U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2421U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 2271U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 58U) ^ RotL64(aCarry, 39U)) + (RotL64(aPrevious, 11U) ^ RotL64(aCross, 23U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererI + RotL64(aPrevious, 27U)) + 18087125778766689269U;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 41U)) + 13710545066503235196U) + aOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = ((((aWandererC + RotL64(aCross, 18U)) + RotL64(aCarry, 19U)) + 1701939704736254645U) + aOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1]) + aNonceWordI;
            aOrbiterA = (aWandererK + RotL64(aIngress, 39U)) + 8064093611384019909U;
            aOrbiterE = (aWandererB + RotL64(aCross, 5U)) + 16623332751533885431U;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 29U)) + RotL64(aCarry, 53U)) + 15590129153794910109U;
            aOrbiterF = (aWandererH + RotL64(aPrevious, 20U)) + 7413312683079107383U;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 23U)) + RotL64(aCarry, 5U)) + 4186064478651458810U;
            aOrbiterG = (aWandererG + RotL64(aCross, 11U)) + 5501191643940735954U;
            aOrbiterK = (aWandererE + RotL64(aScatter, 35U)) + 11064645242200570835U;
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 57U)) + 13825922087298055833U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 5944980709887369970U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 8181136916070569646U;
            aOrbiterD = RotL64((aOrbiterD * 395183021205661827U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 15442336949157292482U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 11580554435240641337U;
            aOrbiterJ = RotL64((aOrbiterJ * 6654637892858767739U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 11240018128174598322U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 2027565596050777471U;
            aOrbiterB = RotL64((aOrbiterB * 18048186560314431815U), 51U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterK) + 16425887196883725233U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordN;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 16828683527588834095U;
            aOrbiterA = RotL64((aOrbiterA * 17746289103235902485U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 9923829146479008804U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterI) ^ 6669171007279929454U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 681823450939955099U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 3902430046523165149U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 6739998149289590041U;
            aOrbiterG = RotL64((aOrbiterG * 2675037435528416821U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 16014401255534234075U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 14741857638680634564U) ^ aNonceWordD;
            aOrbiterI = RotL64((aOrbiterI * 8723611021403369393U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 5064807861673260054U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 968747317273200299U) ^ aOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14122304002722582329U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 5282686212362051427U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 6902253563196129760U;
            aOrbiterE = RotL64((aOrbiterE * 7682808024658992049U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 4995580401402368332U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 14949762584793646470U;
            aOrbiterC = RotL64((aOrbiterC * 3539183342072953803U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 2378815735788107402U) + aOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 18087125778766689269U;
            aOrbiterK = RotL64((aOrbiterK * 16799380528404446281U), 43U);
            //
            aIngress = RotL64(aOrbiterD, 37U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 34U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 39U));
            aIngress = aIngress + RotL64(aOrbiterH, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aPrevious, 21U) + aOrbiterB) + RotL64(aOrbiterJ, 11U));
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 39U) + aOrbiterK) + RotL64(aOrbiterD, 6U)) + aNonceWordE) + aWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 53U) + RotL64(aOrbiterJ, 39U)) + aOrbiterE) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 41U)) + aOrbiterI) + aNonceWordK);
            aWandererB = aWandererB + ((RotL64(aPrevious, 13U) + aOrbiterF) + RotL64(aOrbiterC, 53U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 26U) + aOrbiterB) + RotL64(aOrbiterG, 47U));
            aWandererE = aWandererE + (((RotL64(aIngress, 23U) + RotL64(aOrbiterK, 21U)) + aOrbiterJ) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterI, 23U)) + aOrbiterC);
            aWandererH = aWandererH + ((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterD, 51U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 34U)) + aOrbiterI) + aNonceWordB);
            aWandererD = aWandererD + (((RotL64(aCross, 18U) + aOrbiterJ) + RotL64(aOrbiterH, 19U)) + aWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 12U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + RotL64(aWandererI, 41U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 13626U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneD[((aIndex + 15427U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13590U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 12661U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 4U)) ^ (RotL64(aIngress, 51U) + RotL64(aCross, 37U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererB + RotL64(aCross, 34U)) + 4384716820085860551U;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 29U)) + RotL64(aCarry, 57U)) + 9715780315942116888U;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 43U)) + RotL64(aCarry, 5U)) + 15963520052789178632U;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 27U)) + 14346700690686392938U) + aNonceWordP;
            aOrbiterF = ((aWandererK + RotL64(aCross, 47U)) + RotL64(aCarry, 53U)) + 6005518012489966643U;
            aOrbiterE = (aWandererE + RotL64(aIngress, 21U)) + 2506732930310252119U;
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 4U)) + 16782163084851775826U) + aNonceWordB;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 37U)) + 823673076571076303U;
            aOrbiterI = (aWandererA + RotL64(aCross, 51U)) + 1634084509064077736U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 57U)) + 1288134975466877686U) + aOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = ((aWandererI + RotL64(aScatter, 23U)) + 2998220403162908444U) + aOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 220430672180734911U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 10223923547068528867U;
            aOrbiterK = RotL64((aOrbiterK * 12577370238343872139U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 11696469696177647608U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 6545430420379636963U;
            aOrbiterD = RotL64((aOrbiterD * 8387163146257553773U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 79691451831797107U) + aNonceWordM;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 8971444023498649419U;
            aOrbiterF = RotL64((aOrbiterF * 7148919880477390009U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 5624403902454498793U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 9468064161002030997U;
            aOrbiterA = RotL64((aOrbiterA * 8243560528100864595U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 4619361544913629805U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 12682446273369750704U;
            aOrbiterI = RotL64((aOrbiterI * 10879074713156075641U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 8728730962617599223U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 9099675924074253030U) ^ aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5525644236954497523U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 3298303921318288541U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 5953276499411658358U;
            aOrbiterG = RotL64((aOrbiterG * 10565471305001292693U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 6725769507592688539U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 1057277456510215817U;
            aOrbiterE = RotL64((aOrbiterE * 8269412198279297075U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 11317925732206917722U) + aOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 17814749417006079067U;
            aOrbiterB = RotL64((aOrbiterB * 4369209051015735925U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 9258362135343403308U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 4873837345446960113U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14223381466269503273U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 7863380865835889675U) + aOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 4384716820085860551U;
            aOrbiterH = RotL64((aOrbiterH * 2003891033298374621U), 43U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 13U);
            aIngress = aIngress + (RotL64(aOrbiterG, 60U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + RotL64(aOrbiterK, 46U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aCross, 58U) + RotL64(aOrbiterC, 60U)) + aOrbiterF);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterG, 37U)) + aOrbiterF);
            aWandererK = aWandererK + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterJ, 47U)) + aOrbiterK) + aWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 37U) + aOrbiterK) + RotL64(aOrbiterI, 27U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 35U)) + aOrbiterG) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 21U) + aOrbiterD) + RotL64(aOrbiterG, 39U)) + aWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 11U) + RotL64(aOrbiterE, 11U)) + aOrbiterH) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 46U) + RotL64(aOrbiterC, 51U)) + aOrbiterI);
            aWandererI = aWandererI + (((RotL64(aCross, 23U) + aOrbiterA) + RotL64(aOrbiterI, 20U)) + aNonceWordL);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 53U)) + aOrbiterJ);
            aWandererD = aWandererD + (((RotL64(aIngress, 43U) + aOrbiterA) + RotL64(aOrbiterE, 23U)) + aNonceWordI);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 30U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (RotL64(aWandererD, 58U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 35U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordF);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 22207U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneA[((aIndex + 17187U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21647U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 18161U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 19U)) ^ (RotL64(aCarry, 56U) ^ RotL64(aIngress, 35U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 52U)) + 3238389262925516513U) + aNonceWordC;
            aOrbiterD = (aWandererK + RotL64(aIngress, 37U)) + 12381787182611386995U;
            aOrbiterC = (aWandererA + RotL64(aPrevious, 27U)) + 7883885539305181549U;
            aOrbiterE = (((aWandererE + RotL64(aCross, 23U)) + RotL64(aCarry, 11U)) + 1185413044597727092U) + aNonceWordL;
            aOrbiterA = (aWandererC + RotL64(aScatter, 57U)) + 15219353497204773135U;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 60U)) + RotL64(aCarry, 35U)) + 7533774715626734082U;
            aOrbiterI = (((aWandererG + RotL64(aIngress, 43U)) + RotL64(aCarry, 27U)) + 2599930450937763464U) + aOrbiterAssignSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aCross, 5U)) + 16074720663961214284U) + aNonceWordB;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 35U)) + 15483613196360051221U) + aOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aCross, 47U)) + 9396557867081376268U;
            aOrbiterH = (aWandererD + RotL64(aIngress, 41U)) + 9668459976852660245U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 9037269914643207212U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 16936742640861088240U;
            aOrbiterC = RotL64((aOrbiterC * 1040172193161012227U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 16481274825758546398U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 481851372837611166U;
            aOrbiterG = RotL64((aOrbiterG * 2225030139210599207U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 13608921517203544108U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 16930740723286214636U;
            aOrbiterD = RotL64((aOrbiterD * 2605108503821980865U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 902242902582149908U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 1510861213079342977U) ^ aOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3309753895727400707U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 7116243600304980310U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 6631412278359709602U;
            aOrbiterB = RotL64((aOrbiterB * 11452627691392637463U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 9246698682265275165U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 8594373032014031450U;
            aOrbiterF = RotL64((aOrbiterF * 2550138341089957033U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 15912837963877821048U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 11404583513022627609U) ^ aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17715204726760125357U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 17295214920690244319U) + aNonceWordP;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 18315664494984189344U) ^ aOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17398893532076312945U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 2474825506593695564U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 4400473621592150441U;
            aOrbiterI = RotL64((aOrbiterI * 7098832854166953839U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 15270166373215060119U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 4331232225067306139U;
            aOrbiterK = RotL64((aOrbiterK * 2299883590703870703U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 2176207815544347316U) + aOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 3238389262925516513U;
            aOrbiterH = RotL64((aOrbiterH * 13104597690682251231U), 39U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 43U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 60U));
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterH, 52U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 14U) + RotL64(aOrbiterE, 5U)) + aOrbiterJ) + aWandererUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterG, 11U)) + aOrbiterF) + aWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 5U) + aOrbiterF) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 57U)) + aOrbiterF);
            aWandererF = aWandererF + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterC, 21U)) + aOrbiterB) + aNonceWordH);
            aWandererD = aWandererD ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterJ, 19U)) + aOrbiterF);
            aWandererG = aWandererG + ((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterH, 37U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterD, 3U)) + aOrbiterE);
            aWandererA = aWandererA + (((RotL64(aScatter, 39U) + aOrbiterB) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 50U) + RotL64(aOrbiterA, 54U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererB, 56U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 46U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordE);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 32491U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 25320U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25597U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 30616U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 23U)) + (RotL64(aPrevious, 50U) ^ RotL64(aCross, 35U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererD + RotL64(aPrevious, 47U)) + 18191288703716505885U;
            aOrbiterH = (((aWandererJ + RotL64(aScatter, 37U)) + RotL64(aCarry, 19U)) + 9824014524910417136U) + aNonceWordA;
            aOrbiterA = (((aWandererG + RotL64(aIngress, 54U)) + RotL64(aCarry, 47U)) + 11953012029254917548U) + aNonceWordN;
            aOrbiterB = ((aWandererH + RotL64(aCross, 3U)) + RotL64(aCarry, 37U)) + 6297568011027199089U;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 13U)) + 2576999400457367975U) + aNonceWordO;
            aOrbiterF = (aWandererI + RotL64(aPrevious, 21U)) + 13176139160575558254U;
            aOrbiterI = (aWandererB + RotL64(aCross, 24U)) + 9978408174563621810U;
            aOrbiterG = (aWandererE + RotL64(aScatter, 11U)) + 16765834875061607142U;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 19U)) + 16534507305459121344U) + aOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = (aWandererF + RotL64(aScatter, 57U)) + 3114710944346151807U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 43U)) + 10240517868726718592U) + aOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 10721450637990777883U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 16689590768796583952U;
            aOrbiterA = RotL64((aOrbiterA * 3046344179729901637U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 2427422768928450209U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 13495584061816457831U) ^ aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6670984773768885119U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 7058636403765106682U) + aNonceWordB;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 9897341853944713767U;
            aOrbiterF = RotL64((aOrbiterF * 14286816859999869231U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 17749559755733386064U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 12515645083926326659U;
            aOrbiterI = RotL64((aOrbiterI * 6582878478865838245U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 2625692458813609962U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 10596240255026143019U;
            aOrbiterG = RotL64((aOrbiterG * 11605800195771080135U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 12374290338067865540U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 1507386663796330249U;
            aOrbiterJ = RotL64((aOrbiterJ * 1210241080424446087U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 9288099549484146726U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 15159312464747000702U;
            aOrbiterE = RotL64((aOrbiterE * 500055502081347757U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 14998608679505446229U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 17625038109437732009U) ^ aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14785862243019841689U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 10543192232885637211U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 10330547522729618042U) ^ aNonceWordJ;
            aOrbiterC = RotL64((aOrbiterC * 7635903835474874057U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 5753298214283941201U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 15943436872588208065U;
            aOrbiterH = RotL64((aOrbiterH * 17704547766822075741U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 5757218926946874970U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 18191288703716505885U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2644970408001409575U), 43U);
            //
            aIngress = RotL64(aOrbiterD, 19U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + (RotL64(aOrbiterK, 30U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterI, 41U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aCross, 60U) + aOrbiterI) + RotL64(aOrbiterH, 58U)) + RotL64(aCarry, 41U)) + aWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterJ, 3U)) + aOrbiterC);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 41U) + aOrbiterI) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 29U)) + aNonceWordK);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 23U)) + aOrbiterI);
            aWandererF = aWandererF + ((RotL64(aIngress, 53U) + aOrbiterI) + RotL64(aOrbiterA, 41U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterI, 47U));
            aWandererH = aWandererH + (((RotL64(aCross, 43U) + aOrbiterB) + RotL64(aOrbiterA, 19U)) + aNonceWordC);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterB, 21U)) + aWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 10U) + RotL64(aOrbiterF, 27U)) + aOrbiterD);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 5U) + aOrbiterE) + RotL64(aOrbiterK, 34U)) + aNonceWordD);
            aWandererJ = aWandererJ + ((RotL64(aCross, 13U) + RotL64(aOrbiterF, 5U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 34U));
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (RotL64(aWandererF, 56U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordJ);
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

void TwistExpander_Bowling_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xC634FEEED0831A77ULL + 0xF92BD9F0C1C04534ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xF1A4DFB383A09A0BULL + 0x96FDC79808E8D186ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xA6EF3279BAF80027ULL + 0xF9240D4540023569ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x83BCFD857518DFE9ULL + 0xCA9EF7476CCD3FD2ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x9C3EDE711E6806A1ULL + 0xB8207A23B782A272ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xD4E3FE16D2D64D25ULL + 0x9F93853A17D113E6ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xB53D19992D14CD29ULL + 0x804E61C630711DF1ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xB80FF0F979E847FFULL + 0xDAF99F41FBA1657FULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xEC779EAE7D336DB7ULL + 0xA8904726CAE12836ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xA406DD288A9F9B41ULL + 0xA5CA267B955BA0A8ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xB431E96854AADCDFULL + 0xF95D4FB70349F6BAULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xDA6A9E7B12977451ULL + 0xB1354AFDFA8A6F80ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xDAB8D6E367ACB94DULL + 0xDD6B02C023BF4A91ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xDBDD96CFBFBC07CDULL + 0xC4A5B0F710809B49ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x97C487CF251CFD37ULL + 0xA53BDC83182CB2B7ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x86317CFD457E584DULL + 0xE61490BDF5565B18ULL);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 1253U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4926U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 962U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((aIndex + 2849U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 47U) + RotL64(aCross, 3U)) + (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 22U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererC + RotL64(aCross, 13U)) + RotL64(aCarry, 3U)) + 4752759164691497960U;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 34U)) + RotL64(aCarry, 23U)) + 12088872623537639782U;
            aOrbiterI = (aWandererI + RotL64(aPrevious, 47U)) + 3734943577379734227U;
            aOrbiterC = (aWandererD + RotL64(aScatter, 53U)) + 8854778183012444234U;
            aOrbiterH = (aWandererE + RotL64(aIngress, 29U)) + 16948373492893967275U;
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 43U)) + 7962415690046184385U) + aNonceWordG;
            aOrbiterB = ((aWandererH + RotL64(aCross, 20U)) + 1872682375669714454U) + aOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = (aWandererF + RotL64(aScatter, 57U)) + 7776801806943853566U;
            aOrbiterJ = (((aWandererJ + RotL64(aPrevious, 3U)) + RotL64(aCarry, 53U)) + 16665439117257230732U) + aOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            //
            aOrbiterK = (((aOrbiterK + aOrbiterA) + 11088186766134265676U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordE;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 10850237991780969350U;
            aOrbiterI = RotL64((aOrbiterI * 7547414856143095121U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 6464817712131305812U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 244557182884209844U;
            aOrbiterD = RotL64((aOrbiterD * 2394270354887582889U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 13261563971157415841U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 2323811103717827362U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11483723582415081925U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 12338803568475493422U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 2811342930111104982U) ^ aOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5020981755203607757U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 5554497011738996057U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 12712169745460598698U;
            aOrbiterK = RotL64((aOrbiterK * 1985586486150377769U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 17415058661427002973U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 9430421222715343818U;
            aOrbiterC = RotL64((aOrbiterC * 10321140659099470811U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 3926618548181233180U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 6172453297026957838U;
            aOrbiterB = RotL64((aOrbiterB * 1161551082037835233U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 8633288765997226004U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 17270881130844274342U) ^ aNonceWordP;
            aOrbiterA = RotL64((aOrbiterA * 8888559940161770791U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 12232950994807835262U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 15352600312956742750U;
            aOrbiterH = RotL64((aOrbiterH * 6140396356904933003U), 39U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterG, 57U);
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterD, 54U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterA, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterA, 43U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 22U) + aOrbiterJ) + RotL64(aOrbiterB, 13U)) + aWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 23U)) + aOrbiterH);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterD, 19U)) + aOrbiterA) + aNonceWordA);
            aWandererG = aWandererG + (((RotL64(aScatter, 39U) + aOrbiterK) + RotL64(aOrbiterA, 56U)) + RotL64(aCarry, 57U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 34U) + RotL64(aOrbiterI, 35U)) + aOrbiterD);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 13U)) + aWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterC, 3U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 60U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 30U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 41U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + RotL64(aWandererJ, 27U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordJ);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 7708U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneD[((aIndex + 10644U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7712U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((aIndex + 5478U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 29U) + RotL64(aCross, 11U)) + (RotL64(aPrevious, 58U) ^ RotL64(aCarry, 43U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererG + RotL64(aIngress, 53U)) + 12535417189990029950U) + aOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (((aWandererB + RotL64(aScatter, 47U)) + RotL64(aCarry, 53U)) + 6204401443676390273U) + aNonceWordP;
            aOrbiterC = (aWandererA + RotL64(aCross, 43U)) + 869613505613154672U;
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 39U)) + 15053590879563855802U) + aNonceWordC;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 30U)) + 13338989605204591428U;
            aOrbiterG = (aWandererK + RotL64(aCross, 57U)) + 18306470022403825392U;
            aOrbiterE = (((aWandererH + RotL64(aPrevious, 23U)) + RotL64(aCarry, 29U)) + 1150696349434090218U) + aOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aScatter, 19U)) + 13549541786420596437U) + aNonceWordO;
            aOrbiterH = ((aWandererI + RotL64(aCross, 14U)) + RotL64(aCarry, 11U)) + 14302878430259588461U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 4660437084477165225U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 1653628537860912069U;
            aOrbiterC = RotL64((aOrbiterC * 2624835201155303123U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 5594199757006711631U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 11008472193138708891U;
            aOrbiterJ = RotL64((aOrbiterJ * 13645764762027798301U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 3668516817279364310U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 128159531749679984U) ^ aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4523246859249826987U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 6378674346113979108U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 11438762460659123362U;
            aOrbiterD = RotL64((aOrbiterD * 2733309638158283953U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 10624263004446482910U) + aNonceWordJ;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 12546839706919241411U;
            aOrbiterH = RotL64((aOrbiterH * 11468326687628079347U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 8466639576503293921U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 5828694979857951504U;
            aOrbiterI = RotL64((aOrbiterI * 7835487310289634515U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 16496305151014092976U) + aNonceWordF;
            aOrbiterA = (((aOrbiterA ^ aOrbiterE) ^ 589464613876410567U) ^ aOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterA = RotL64((aOrbiterA * 13190816610718051897U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 4168532743415647825U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 15944887793736489375U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17273403561158196717U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 11642456814106259483U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 1609897693632334867U;
            aOrbiterK = RotL64((aOrbiterK * 12912773555616819941U), 19U);
            //
            aIngress = RotL64(aOrbiterK, 44U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aCross, 27U) + aOrbiterI) + RotL64(aOrbiterC, 29U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 53U) + aOrbiterH) + RotL64(aOrbiterE, 18U)) + aWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aScatter, 37U) + RotL64(aOrbiterJ, 23U)) + aOrbiterK) + RotL64(aCarry, 21U)) + aNonceWordB);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 14U) + RotL64(aOrbiterJ, 39U)) + aOrbiterA);
            aWandererH = aWandererH + ((RotL64(aScatter, 3U) + aOrbiterH) + RotL64(aOrbiterK, 51U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 23U) + aOrbiterJ) + RotL64(aOrbiterG, 47U));
            aWandererI = aWandererI + ((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterD, 11U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 10U) + RotL64(aOrbiterC, 4U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterH, 57U)) + aOrbiterA) + RotL64(aCarry, 13U)) + aWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + (RotL64(aWandererK, 50U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 23U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15227U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11846U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 16115U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15830U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 43U) ^ RotL64(aCross, 29U)) + (RotL64(aCarry, 14U) ^ RotL64(aPrevious, 57U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererC + RotL64(aPrevious, 14U)) + 15813325389431304548U;
            aOrbiterD = (aWandererF + RotL64(aIngress, 29U)) + 2223874171125403602U;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 21U)) + RotL64(aCarry, 27U)) + 5510483568496824130U;
            aOrbiterC = (((aWandererA + RotL64(aScatter, 41U)) + RotL64(aCarry, 5U)) + 15474152493495661876U) + aOrbiterAssignSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = ((aWandererJ + RotL64(aCross, 53U)) + 16846339705130829195U) + aNonceWordP;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 4U)) + 1289670576865739669U;
            aOrbiterG = ((((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 41U)) + 18017354919647006944U) + aOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 47U)) + 8539685539928984921U) + aNonceWordH;
            aOrbiterK = (aWandererI + RotL64(aCross, 57U)) + 3333721400836704048U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2261560416623815491U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 4377786131746816567U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9164777834392621157U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 18047393176583722719U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 8184724021940434631U;
            aOrbiterI = RotL64((aOrbiterI * 9800116157750921119U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 10469895939183324807U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 14543391765109879223U) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 4817987697437667225U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 5757225781746158178U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 3539000495894022869U) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 1032298408884695925U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 11288971092707065923U) + aNonceWordL;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 2761384065186568294U;
            aOrbiterB = RotL64((aOrbiterB * 3323838837427471051U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 7120580145300417101U) + aOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 6977246291769372866U;
            aOrbiterA = RotL64((aOrbiterA * 15170353875184253779U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 17625434527765525937U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 3299714663631376190U;
            aOrbiterG = RotL64((aOrbiterG * 6532628892760776767U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 10331889953489885250U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 8550932256881727932U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13085531621192583719U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 11151195711186126257U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 2552002192824926483U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9754056316698523849U), 53U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterI, 57U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + (RotL64(aOrbiterD, 44U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterG, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 28U) + aOrbiterJ) + RotL64(aOrbiterC, 40U)) + aNonceWordC);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterA, 23U)) + aOrbiterG);
            aWandererB = aWandererB + ((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 3U)) + aOrbiterI);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterB, 19U));
            aWandererA = aWandererA + ((RotL64(aIngress, 18U) + aOrbiterD) + RotL64(aOrbiterI, 47U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 39U) + aOrbiterC) + RotL64(aOrbiterK, 53U)) + aWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 11U)) + aOrbiterG) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 28U)) + aOrbiterK) + aWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 51U) + RotL64(aOrbiterB, 35U)) + aOrbiterG) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 60U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordL;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 17400U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18884U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17257U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 18339U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 29U)) ^ (RotL64(aCarry, 56U) ^ RotL64(aPrevious, 41U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (((aWandererJ + RotL64(aScatter, 14U)) + RotL64(aCarry, 47U)) + 8866844335448071821U) + aOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 57U)) + 15159698739856430085U;
            aOrbiterE = (aWandererH + RotL64(aIngress, 23U)) + 9582805772989594633U;
            aOrbiterG = (aWandererG + RotL64(aCross, 47U)) + 1438538239931588373U;
            aOrbiterC = (((aWandererA + RotL64(aPrevious, 3U)) + RotL64(aCarry, 3U)) + 10862044156620436139U) + aOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aScatter, 18U)) + 13682173320058164615U) + aNonceWordC;
            aOrbiterB = (aWandererK + RotL64(aCross, 35U)) + 8351013291045977592U;
            aOrbiterD = (((aWandererF + RotL64(aIngress, 43U)) + RotL64(aCarry, 39U)) + 15777857431516633916U) + aNonceWordB;
            aOrbiterI = (aWandererD + RotL64(aCross, 39U)) + 16178966745333885377U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 9031889187993001617U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 6308472367425865347U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17118710301967158153U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 642109145903321046U) + aOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 9186268569255318035U) ^ aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10714674348507516749U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 6091345356803675860U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 13218507921880873749U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 15415157927185637717U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 4266652275234474616U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 4391422098164506195U;
            aOrbiterH = RotL64((aOrbiterH * 17634679403195085867U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 5160682323243635577U) + aOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 10351728852161347404U;
            aOrbiterG = RotL64((aOrbiterG * 11105410036471745951U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 3950932176454814023U) + aNonceWordK;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 9536466386833427441U;
            aOrbiterA = RotL64((aOrbiterA * 18064984243491293435U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 9927425919978776529U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 6819384090527481081U;
            aOrbiterD = RotL64((aOrbiterD * 18032965969184368561U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 1646274931424218507U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 16166524473976135097U;
            aOrbiterI = RotL64((aOrbiterI * 11672192658072663849U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 11252501968059485262U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 16847854447987609067U;
            aOrbiterJ = RotL64((aOrbiterJ * 6326299154627028295U), 27U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 54U);
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterH, 43U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterD, 39U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aScatter, 30U) + aOrbiterA) + RotL64(aOrbiterB, 39U)) + RotL64(aCarry, 3U)) + aNonceWordM);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterI, 43U));
            aWandererK = aWandererK + (((RotL64(aCross, 11U) + RotL64(aOrbiterE, 58U)) + aOrbiterA) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 53U) + RotL64(aOrbiterE, 27U)) + aOrbiterG) + aNonceWordA) + aWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 42U) + aOrbiterJ) + RotL64(aOrbiterB, 47U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 3U) + aOrbiterJ) + RotL64(aOrbiterG, 35U));
            aWandererB = aWandererB + ((RotL64(aCross, 37U) + aOrbiterD) + RotL64(aOrbiterH, 51U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterI, 23U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterC, 4U)) + aWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 22U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordF);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 25654U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25200U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22481U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26410U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aPrevious, 18U)) ^ (RotL64(aCarry, 51U) + RotL64(aIngress, 3U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererG + RotL64(aIngress, 42U)) + 12131317914288566437U) + aOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 35U)) + RotL64(aCarry, 27U)) + 5672805657999385496U;
            aOrbiterC = (((aWandererA + RotL64(aCross, 47U)) + RotL64(aCarry, 19U)) + 3581710244233124197U) + aOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 47U)) + 15251296040538489436U;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 51U)) + 11295008604679904153U;
            aOrbiterI = (aWandererB + RotL64(aPrevious, 13U)) + 2230897493419504490U;
            aOrbiterB = ((aWandererK + RotL64(aScatter, 58U)) + 7109600123297458999U) + aNonceWordI;
            aOrbiterG = ((aWandererF + RotL64(aCross, 21U)) + 13119156643107683803U) + aNonceWordA;
            aOrbiterF = (aWandererD + RotL64(aScatter, 27U)) + 14755160867807355250U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 16829363373287496832U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 16981122946707720883U;
            aOrbiterC = RotL64((aOrbiterC * 5394974422201576627U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 8806000776958603317U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 16810923047720876014U;
            aOrbiterI = RotL64((aOrbiterI * 17872735050219539145U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 8129657889554436328U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 8653100378491974463U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11395283153912468661U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 17048985838727432415U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 10892675550889823573U;
            aOrbiterF = RotL64((aOrbiterF * 976298937314081913U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 15960158965421254346U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 12290011578634850001U;
            aOrbiterD = RotL64((aOrbiterD * 9280475585104357745U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 16265047040311479093U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterC) ^ 10312956912303656248U) ^ aOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterE = RotL64((aOrbiterE * 3012584393253845131U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 16706890352221352779U) + aNonceWordG;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 10630955894218491929U) ^ aOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12675937483456206355U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 4009352551041162434U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 3043810773683888556U;
            aOrbiterA = RotL64((aOrbiterA * 4328135390387997315U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 1398071019814944785U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 16689766557488135301U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8403881916549404871U), 57U);
            //
            aIngress = RotL64(aOrbiterC, 29U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 20U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aPrevious, 53U) + aOrbiterD) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 29U)) + aWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 10U) + RotL64(aOrbiterJ, 23U)) + aOrbiterC) + aNonceWordD);
            aWandererF = aWandererF + (((RotL64(aCross, 23U) + aOrbiterI) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 48U)) + aOrbiterI);
            aWandererA = aWandererA + ((RotL64(aCross, 43U) + aOrbiterE) + RotL64(aOrbiterC, 57U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 3U)) + aOrbiterG);
            aWandererH = aWandererH + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterB, 53U)) + aOrbiterC);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 30U)) + aOrbiterJ) + aWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 18U) + RotL64(aOrbiterJ, 35U)) + aOrbiterF) + aNonceWordH);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 58U));
            aCarry = aCarry + RotL64(aWandererF, 51U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordD;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31221U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31913U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31866U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneB[((aIndex + 27391U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aPrevious, 23U)) ^ (RotL64(aCarry, 60U) ^ RotL64(aIngress, 35U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererJ + RotL64(aCross, 37U)) + 11998579547770778580U) + aNonceWordC;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 24U)) + 8409465187298704610U) + aNonceWordE;
            aOrbiterG = (aWandererA + RotL64(aIngress, 13U)) + 3470222286110333500U;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 47U)) + RotL64(aCarry, 51U)) + 5704486785203069994U;
            aOrbiterF = (aWandererE + RotL64(aPrevious, 5U)) + 10334944660253279633U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 19U)) + 7626852700722567477U;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 51U)) + 14631310754943209743U) + aOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = (((aWandererF + RotL64(aCross, 56U)) + RotL64(aCarry, 41U)) + 807160297237854120U) + aOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aIngress, 41U)) + RotL64(aCarry, 19U)) + 5624154783624196107U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 4971444394698940423U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 6340057638461027062U;
            aOrbiterG = RotL64((aOrbiterG * 12027586111086798629U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 9003019862787819481U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 13632057463595873033U;
            aOrbiterF = RotL64((aOrbiterF * 12575202147280216765U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 12766104026871797746U) + aOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 4062118445824915939U;
            aOrbiterA = RotL64((aOrbiterA * 13130770039048080701U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 5258212525426469978U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 9956946981015983939U) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 8106382657040497669U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 10837606223056473999U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 13292864885504191134U) ^ aOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4445739587553669471U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 166087925900318658U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 6786842221885441388U;
            aOrbiterH = RotL64((aOrbiterH * 4411147600413147773U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 16888086378070246404U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 5240855484445974002U) ^ aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 402652898573422271U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 6874866669211571608U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 732890824978127460U;
            aOrbiterI = RotL64((aOrbiterI * 3776365957702257453U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 5541380495707308058U) + aNonceWordO;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 17947326584411475765U;
            aOrbiterJ = RotL64((aOrbiterJ * 10920952349981652899U), 11U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterC, 21U);
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + RotL64(aOrbiterJ, 18U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 51U) + aOrbiterH) + RotL64(aOrbiterC, 10U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 35U)) + aOrbiterH);
            aWandererB = aWandererB + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 47U)) + aOrbiterF) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterB, 43U)) + aOrbiterJ);
            aWandererE = aWandererE + ((RotL64(aPrevious, 24U) + RotL64(aOrbiterA, 21U)) + aOrbiterJ);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 47U) + aOrbiterF) + RotL64(aOrbiterD, 27U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterI, 5U)) + aOrbiterA) + aNonceWordI) + aWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterG, 52U));
            aWandererG = aWandererG + (((((RotL64(aIngress, 56U) + aOrbiterC) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 41U)) + aNonceWordG) + aWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (RotL64(aWandererB, 40U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordB;
            aCarry = TwistMix64::DiffuseA(aCarry);
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

void TwistExpander_Bowling_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xFB01000537867BC9ULL + 0xBD2AA4A41C19721CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xB593A54A8CBFCDC1ULL + 0x8A657DE7A6EAD64AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xDC5D1643BB388A47ULL + 0xED3487E5037C1FECULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xB02B0C14B9343C97ULL + 0xCDC86F98A4E3D40CULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xAB5FB35F6E924D33ULL + 0xF5D149198CA4C65CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xECF4D3E85DCC42E5ULL + 0xE99FCD5A6D4A2A58ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xAE0D70EF3B884867ULL + 0xB092C9F442F7E8C4ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xEFF516D622614DABULL + 0xB2C398C5D7323E0AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xAE42D840B980E5A1ULL + 0x8A2DECDFE7F2BB1AULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xA07B2F82BC7AF74FULL + 0xD4E7140019AF366EULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xCDCD49C40E4B63C7ULL + 0xB6024E4A018157DEULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x827401A88DA6C5FDULL + 0x8774BC801D7A8A9DULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xAA0F6F7821C67A93ULL + 0xFBA5CC507E5801F7ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xE007E7662472FCAFULL + 0x9A78FB104E37BC19ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x99B58C3B78E21101ULL + 0x875D8CC30D61892CULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x910DA0A4F646F3D7ULL + 0xE9C45AD628950486ULL);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 563U)) & S_BLOCK1], 21U) ^ RotL64(aKeyRowReadA[((aIndex + 5327U)) & W_KEY1], 38U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 2133U)) & W_KEY1], 53U) ^ RotL64(mSource[((aIndex + 2513U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCross, 35U)) + (RotL64(aCarry, 19U) + RotL64(aPrevious, 4U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterG = ((aWandererC + RotL64(aScatter, 35U)) + RotL64(aCarry, 19U)) + 13960289014350612206U;
            aOrbiterB = (aWandererE + RotL64(aPrevious, 18U)) + 3483331015269589730U;
            aOrbiterC = ((aWandererG + RotL64(aCross, 41U)) + 6873299241002444518U) + aPhaseAOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 47U)) + RotL64(aCarry, 5U)) + 3562094007125534229U;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 27U)) + 11422367439932782705U) + aNonceWordB;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 53U)) + 532453428514259816U) + aPhaseAOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = (((aWandererB + RotL64(aCross, 11U)) + RotL64(aCarry, 37U)) + 17810941465810193088U) + aNonceWordP;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 11869759058631106331U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 8837581071876177566U;
            aOrbiterC = RotL64((aOrbiterC * 15329827515970522213U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 17185378327053837778U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 7578253375676981500U;
            aOrbiterI = RotL64((aOrbiterI * 13371647568758721729U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 17112646434432814442U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 14949096407295697881U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14770977858283051753U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 4259590620758467836U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 6534899413644542303U) ^ aNonceWordA;
            aOrbiterH = RotL64((aOrbiterH * 7987609419215568661U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 2637407498893694243U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 15819295597921425711U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5202015597375051399U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 6373559542002699718U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 11694562937392022505U;
            aOrbiterJ = RotL64((aOrbiterJ * 9311557972331218597U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 3308736483775453062U) + aNonceWordG;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 12749929710650475901U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 248428400724560945U), 13U);
            //
            aIngress = RotL64(aOrbiterC, 3U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 35U));
            aIngress = aIngress + RotL64(aOrbiterJ, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterB, 29U)) + RotL64(aCarry, 41U)) + aNonceWordH);
            aWandererD = aWandererD ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterB, 50U)) + aOrbiterH) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 21U) + RotL64(aOrbiterD, 13U)) + aOrbiterJ) + aNonceWordO);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterG, 43U)) + aOrbiterI);
            aWandererC = aWandererC + (((RotL64(aScatter, 48U) + RotL64(aOrbiterJ, 5U)) + aOrbiterI) + RotL64(aCarry, 19U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterC, 57U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterD, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 14U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 51U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8943U)) & S_BLOCK1], 51U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 9109U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 8114U)) & W_KEY1], 39U) ^ RotL64(aKeyRowReadB[((aIndex + 9258U)) & W_KEY1], 6U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 56U)) + (RotL64(aCarry, 41U) + RotL64(aIngress, 29U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 53U)) + RotL64(aCarry, 5U)) + 13174219512651137892U;
            aOrbiterI = (aWandererC + RotL64(aScatter, 37U)) + 2715455762789269341U;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 47U)) + RotL64(aCarry, 47U)) + 1338018183235594313U;
            aOrbiterC = (((aWandererD + RotL64(aCross, 29U)) + 16566866551729552930U) + aPhaseAOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1]) + aNonceWordA;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 4U)) + 6901845297307236726U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 19U)) + 2476078302049201718U) + aNonceWordF;
            aOrbiterD = (((aWandererA + RotL64(aCross, 13U)) + RotL64(aCarry, 23U)) + 15531109473927052260U) + aNonceWordB;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 4087849380858572351U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 5167830630098599644U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1982835131228146099U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 7275995452428627217U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 14794340370010024117U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8779497557416568379U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 8509217403041662849U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 2321522025240806996U;
            aOrbiterC = RotL64((aOrbiterC * 113568101672878697U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 5676672952755594051U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 2304681269233504384U;
            aOrbiterI = RotL64((aOrbiterI * 15731441084605554497U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 8383399721062437300U) + aNonceWordC;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 13181984036942227666U;
            aOrbiterH = RotL64((aOrbiterH * 1648761328771932069U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 13602604532551684210U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 12725687663616352843U;
            aOrbiterF = RotL64((aOrbiterF * 4684699861686199753U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 5831790822416009806U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 4535048543735457407U;
            aOrbiterD = RotL64((aOrbiterD * 12076777878870257053U), 37U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 19U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterF, 18U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 50U) + aOrbiterF) + RotL64(aOrbiterD, 35U));
            aWandererF = aWandererF + (((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterC, 29U)) + aNonceWordJ);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 11U) + aOrbiterI) + RotL64(aOrbiterE, 57U)) + aNonceWordH);
            aWandererD = aWandererD + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 51U)) + aOrbiterH) + RotL64(aCarry, 37U)) + aPhaseAWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterC, 3U)) + aOrbiterJ) + aPhaseAWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 41U) + aOrbiterJ) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + RotL64(aWandererJ, 12U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordK);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13699U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 15019U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 13479U)) & W_KEY1], 48U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 13487U)) & W_KEY1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aPrevious, 43U)) ^ (RotL64(aIngress, 58U) ^ RotL64(aCross, 27U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterD = (((aWandererH + RotL64(aPrevious, 28U)) + 7896237440058555694U) + aPhaseAOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1]) + aNonceWordL;
            aOrbiterB = (aWandererJ + RotL64(aCross, 13U)) + 11870529476037558635U;
            aOrbiterH = (((aWandererI + RotL64(aScatter, 19U)) + RotL64(aCarry, 11U)) + 9158983227801569448U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aIngress, 3U)) + RotL64(aCarry, 53U)) + 4710172270996950329U;
            aOrbiterA = (aWandererA + RotL64(aScatter, 43U)) + 14634482800356647630U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 35U)) + RotL64(aCarry, 41U)) + 8822207952170610891U;
            aOrbiterF = (aWandererG + RotL64(aCross, 57U)) + 13755891414028982553U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 4555293067488040719U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 2816805148093762081U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16838149138341713943U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 2122631477965135190U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 4592922416380416071U;
            aOrbiterB = RotL64((aOrbiterB * 11644507904538573165U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 7102471666524164715U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 17274623547879474204U;
            aOrbiterD = RotL64((aOrbiterD * 5443572270546181789U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 938587316977094680U) + aNonceWordH;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 18258015823797023523U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6068819567674605919U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 5809987756043471595U) + aNonceWordO;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 5083075160112581620U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3313957222154937503U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 5960021727750946496U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 5967477320950630150U;
            aOrbiterI = RotL64((aOrbiterI * 330964768256424655U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 6578428711689296132U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 5601728218197771276U;
            aOrbiterF = RotL64((aOrbiterF * 9552559022315971847U), 5U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 29U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterF, 43U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 53U) + aOrbiterA) + RotL64(aOrbiterD, 4U)) + RotL64(aCarry, 47U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 20U) + aOrbiterI) + RotL64(aOrbiterA, 27U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 37U) + aOrbiterA) + RotL64(aOrbiterE, 35U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterD, 51U));
            aWandererA = aWandererA + ((((RotL64(aCross, 47U) + RotL64(aOrbiterH, 21U)) + aOrbiterE) + RotL64(aCarry, 19U)) + aNonceWordC);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterF, 13U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 50U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordA);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 16900U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneB[((aIndex + 17429U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17080U)) & S_BLOCK1], 50U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 21104U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 54U)) + (RotL64(aIngress, 3U) + RotL64(aCross, 41U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterK = ((((aWandererB + RotL64(aScatter, 57U)) + RotL64(aCarry, 21U)) + 6342299552323486695U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordL;
            aOrbiterG = (aWandererE + RotL64(aIngress, 43U)) + 12692748514781367538U;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 51U)) + 8202639945493229155U;
            aOrbiterD = (aWandererA + RotL64(aCross, 4U)) + 4439975701793231639U;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 23U)) + RotL64(aCarry, 39U)) + 16774235182859553759U;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 13U)) + RotL64(aCarry, 3U)) + 8764155413335405667U;
            aOrbiterF = (((aWandererF + RotL64(aIngress, 29U)) + 7167848811974967685U) + aPhaseAOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1]) + aNonceWordH;
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 16768278912125334220U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 9090838954826296201U;
            aOrbiterI = RotL64((aOrbiterI * 5459329624017272077U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 7644075729758006298U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 17326182797908071215U;
            aOrbiterJ = RotL64((aOrbiterJ * 2408330168749256075U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 16158809721888137555U) + aNonceWordE;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 8029938783858263694U;
            aOrbiterG = RotL64((aOrbiterG * 12628072435324195483U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 8716553521415553404U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 7012599977009208840U;
            aOrbiterC = RotL64((aOrbiterC * 8775355876188948851U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 13250558696578541499U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 13705957059101025396U;
            aOrbiterK = RotL64((aOrbiterK * 16889495686487056367U), 29U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterI) + 2796775206291902461U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordF;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 13741676263512390669U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10455782033465595947U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 1691908360612389252U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 4114939415206031540U;
            aOrbiterF = RotL64((aOrbiterF * 2797401802892718297U), 43U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 53U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 26U));
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 47U)) + aOrbiterC) + aNonceWordN);
            aWandererH = aWandererH + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 13U)) + aOrbiterF) + RotL64(aCarry, 19U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterI, 29U));
            aWandererB = aWandererB + ((RotL64(aCross, 4U) + aOrbiterJ) + RotL64(aOrbiterC, 3U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 58U)) + aOrbiterK);
            aWandererF = aWandererF + (((((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 41U)) + aOrbiterD) + RotL64(aCarry, 53U)) + aNonceWordK) + aPhaseAWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 13U) + aOrbiterJ) + RotL64(aOrbiterF, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 22U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 5U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordL;
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24329U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((aIndex + 24321U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22376U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26037U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCarry, 14U)) + (RotL64(aCross, 39U) ^ RotL64(aIngress, 51U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterI = ((aWandererK + RotL64(aIngress, 11U)) + RotL64(aCarry, 11U)) + 16160838483846078448U;
            aOrbiterC = (((aWandererI + RotL64(aCross, 44U)) + RotL64(aCarry, 41U)) + 15404960896190227946U) + aNonceWordE;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 29U)) + 16904160594024977199U) + aNonceWordN;
            aOrbiterK = (((aWandererB + RotL64(aPrevious, 37U)) + RotL64(aCarry, 29U)) + 17790460246821031802U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = ((aWandererC + RotL64(aScatter, 51U)) + 16395168254086971959U) + aNonceWordA;
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 5U)) + 7484373204039901786U;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 21U)) + 18026814691322913510U) + aPhaseAOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 15244817793136966450U) + aNonceWordD;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 5795491730356335666U;
            aOrbiterH = RotL64((aOrbiterH * 13253529465289332171U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 3163873518027801504U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 2690791759507349172U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16677948635136515083U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 17898067251167087906U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 8028010015006604239U;
            aOrbiterK = RotL64((aOrbiterK * 5601629670521300241U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 7304739457289910555U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 6476837815096530043U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16380545138701113267U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 14242499233467960602U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 17305645693017634630U;
            aOrbiterG = RotL64((aOrbiterG * 14442976693206929569U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 9772864059444171908U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 7897200728282156408U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 816306719390807411U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 4890999319172950996U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 8165132649356094963U;
            aOrbiterA = RotL64((aOrbiterA * 17297706071263690189U), 21U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 5U);
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 60U));
            aIngress = aIngress + RotL64(aOrbiterA, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 35U) + aOrbiterG) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterH, 11U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 20U) + RotL64(aOrbiterC, 43U)) + aOrbiterE) + RotL64(aCarry, 51U)) + aNonceWordG);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterE, 27U)) + aOrbiterH);
            aWandererK = aWandererK + ((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterG, 37U));
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 3U)) + aOrbiterC) + aNonceWordM) + aPhaseAWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 11U) + aOrbiterH) + RotL64(aOrbiterA, 60U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 42U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ aNonceWordN;
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30595U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30326U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29856U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29467U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 53U)) ^ (RotL64(aPrevious, 41U) + RotL64(aCarry, 26U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterE = (aWandererJ + RotL64(aScatter, 13U)) + 1898718075389870739U;
            aOrbiterB = ((aWandererC + RotL64(aCross, 50U)) + RotL64(aCarry, 53U)) + 5631794889237247403U;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 35U)) + 18219714659484524607U) + aPhaseAOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = (((aWandererI + RotL64(aIngress, 29U)) + RotL64(aCarry, 37U)) + 15419581386225732921U) + aPhaseAOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aCross, 19U)) + 9125575431710198210U;
            aOrbiterF = (((aWandererG + RotL64(aScatter, 41U)) + RotL64(aCarry, 19U)) + 12205871520544965505U) + aNonceWordJ;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 57U)) + 7617534300497343422U) + aNonceWordH;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 18017579105368135814U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 10693882161946020042U;
            aOrbiterC = RotL64((aOrbiterC * 2326507900303932855U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 11669615701700895306U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 11045110212889232165U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5965171269273719849U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 18019107802806469913U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 12315940560472528716U) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 4505122470351404065U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 4899009736070044310U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterC) ^ 17412253404253730364U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterK = RotL64((aOrbiterK * 10791901166391946485U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 4826286251927854181U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterA) ^ 4523455921321845084U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterE = RotL64((aOrbiterE * 14534103906736598099U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 4132514462154182215U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 7164745605985109269U;
            aOrbiterI = RotL64((aOrbiterI * 14107325508977225261U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 6297434295807635654U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 8813887638672996646U;
            aOrbiterB = RotL64((aOrbiterB * 17495632530773158201U), 41U);
            //
            aIngress = RotL64(aOrbiterK, 3U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + RotL64(aOrbiterF, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 57U) + aOrbiterE) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterI, 39U)) + aOrbiterK);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 46U)) + aOrbiterB) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 29U)) + aOrbiterI);
            aWandererA = aWandererA + (((RotL64(aScatter, 13U) + aOrbiterB) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterI, 57U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 50U) + aOrbiterF) + RotL64(aOrbiterA, 23U)) + aNonceWordD) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 6U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordP);
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

void TwistExpander_Bowling_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xE2233B1E2B09D0B7ULL + 0xEAC0DFC677D8B2DFULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x9C1D9E6036C6F305ULL + 0xB5ADEFB5AB8B7859ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xFF503AE3A061FD1FULL + 0xD3ABFBBCD1B11467ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x82A71C38C809C1B1ULL + 0xAF22577A54A79349ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xBF1FFC7568D0A0D5ULL + 0xFF911FBBEA69EA12ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xF19FC3313DC855ABULL + 0xD135F051C88AAB7BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xC3596994C13A7251ULL + 0xE71CE8B06281302AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xD6F6CAAE47F93AA3ULL + 0x981277AEE81BB864ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x96E3DB6AF6F4C1BDULL + 0xC49C85C6E8F531E8ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x971102EBC305D88FULL + 0xE58F121A2BD0ACC9ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xAF676B543C5BE14BULL + 0x8A919687CC1563ABULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xAF3351B2B6016611ULL + 0x935F898C9CC73591ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xE8D678E4D2805DAFULL + 0x9FA210CF15DB88A9ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xB24057E55AAE0DB3ULL + 0x886E1B5852A30A60ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xFC9A12832E6BABC7ULL + 0xC4B839849541F8FDULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xAFB680A8CE9CC345ULL + 0xA545A60C8021C7BDULL);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2292U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneC[((aIndex + 2203U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4973U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((aIndex + 2980U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 41U)) ^ (RotL64(aCross, 28U) ^ RotL64(aIngress, 57U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterC = (((aWandererH + RotL64(aCross, 29U)) + RotL64(aCarry, 37U)) + 4773124477323378268U) + aNonceWordG;
            aOrbiterD = (((aWandererC + RotL64(aScatter, 51U)) + RotL64(aCarry, 5U)) + 16848723289435796005U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 21U)) + 13846642134917107058U;
            aOrbiterJ = (((aWandererG + RotL64(aIngress, 39U)) + 6472057872482789939U) + aPhaseBOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1]) + aNonceWordH;
            aOrbiterF = (aWandererF + RotL64(aCross, 4U)) + 2747019500690707226U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 9003965289739733880U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 3013390651936257377U;
            aOrbiterA = RotL64((aOrbiterA * 11081353600889943167U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 3331004709895625067U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 15355010435553517129U;
            aOrbiterC = RotL64((aOrbiterC * 8322759117004876831U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 7709870658004280052U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 13568728443963926564U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6736090830113688981U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 12409548853419307131U) + aNonceWordD;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 969183352023661537U;
            aOrbiterD = RotL64((aOrbiterD * 5549220554838837145U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 15370309834426476775U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 3896803894396631184U;
            aOrbiterF = RotL64((aOrbiterF * 11018830202891911603U), 27U);
            //
            aIngress = RotL64(aOrbiterC, 13U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + RotL64(aOrbiterD, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 48U) + RotL64(aOrbiterA, 13U)) + aOrbiterF) + aNonceWordI);
            aWandererH = aWandererH + (((RotL64(aIngress, 21U) + RotL64(aOrbiterC, 40U)) + aOrbiterF) + RotL64(aCarry, 51U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterD, 51U));
            aWandererC = aWandererC + (((((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 3U)) + aOrbiterA) + RotL64(aCarry, 3U)) + aNonceWordP) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 29U) + aOrbiterJ) + RotL64(aOrbiterC, 29U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 35U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = aCarry ^ aNonceWordI;
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 7405U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneD[((aIndex + 9880U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5476U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6387U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aIngress, 51U)) + (RotL64(aPrevious, 19U) + RotL64(aCarry, 4U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 43U)) + RotL64(aCarry, 35U)) + 15904465836916519864U;
            aOrbiterI = (((aWandererI + RotL64(aCross, 23U)) + 17725629806317789307U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordF;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 5U)) + RotL64(aCarry, 11U)) + 13794170125914914828U;
            aOrbiterE = ((((aWandererH + RotL64(aIngress, 52U)) + RotL64(aCarry, 23U)) + 2149055907476874332U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordK;
            aOrbiterD = (aWandererE + RotL64(aCross, 13U)) + 5342047776745074649U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 8268148484060546838U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 10821151364028563719U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13626634259250509711U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 4294213820894407378U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 10884726101307943090U) ^ aNonceWordG;
            aOrbiterD = RotL64((aOrbiterD * 1116128870387229159U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 16432210042202444824U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 15196602644336228055U;
            aOrbiterG = RotL64((aOrbiterG * 12680438355124070237U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 14117787670220328165U) + aNonceWordO;
            aOrbiterI = (((aOrbiterI ^ aOrbiterF) ^ 219833877949480215U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 10736293047771972173U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 3326396981881473962U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 14918513066311426279U;
            aOrbiterE = RotL64((aOrbiterE * 14269763278564574663U), 5U);
            //
            aIngress = RotL64(aOrbiterG, 39U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + RotL64(aOrbiterD, 58U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterF, 51U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 29U) + aOrbiterF) + RotL64(aOrbiterE, 34U)) + aPhaseBWandererUpdateSaltC[((aIndex + 4U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterI, 43U)) + aOrbiterF) + RotL64(aCarry, 11U)) + aNonceWordH);
            aWandererH = aWandererH ^ (((RotL64(aCross, 38U) + aOrbiterG) + RotL64(aOrbiterD, 13U)) + aNonceWordE);
            aWandererE = aWandererE + (((((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 23U)) + aOrbiterI) + RotL64(aCarry, 29U)) + aNonceWordB) + aPhaseBWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererB, 46U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 10968U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10956U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15437U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneC[((aIndex + 13527U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCross, 21U)) ^ (RotL64(aCarry, 37U) + RotL64(aPrevious, 50U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterG = ((aWandererC + RotL64(aScatter, 19U)) + RotL64(aCarry, 5U)) + 4634399531433127141U;
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 30U)) + 16961792729406903200U) + aPhaseBOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aIngress, 57U)) + 4105280732301137738U) + aNonceWordM;
            aOrbiterF = (((aWandererI + RotL64(aCross, 41U)) + RotL64(aCarry, 29U)) + 15692013501147331191U) + aNonceWordN;
            aOrbiterB = ((((aWandererD + RotL64(aIngress, 5U)) + RotL64(aCarry, 43U)) + 1252216715968780587U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordO;
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 7958289043012473752U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 6611577301818896615U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2757493607265637973U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 8506226754305949140U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 3648813120449403353U;
            aOrbiterJ = RotL64((aOrbiterJ * 9521367946879238849U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 5195245426245535735U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 542948051600803051U;
            aOrbiterG = RotL64((aOrbiterG * 4631106308856448475U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 11974253551208964789U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 10596463592332655367U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10941161258815714641U), 3U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterI) + 12015129484061440159U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1]) + aNonceWordL;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 8254944355710109060U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3233697992479357615U), 35U);
            //
            aIngress = RotL64(aOrbiterF, 5U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterJ, 28U)) + aPhaseBWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 18U) + RotL64(aOrbiterB, 37U)) + aOrbiterF) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ ((((RotL64(aScatter, 41U) + RotL64(aOrbiterG, 53U)) + aOrbiterF) + aNonceWordD) + aPhaseBWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 27U) + RotL64(aOrbiterJ, 5U)) + aOrbiterG) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterI, 19U)) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + RotL64(aWandererH, 44U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordE;
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 20211U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18879U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18731U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19296U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCarry, 26U)) + (RotL64(aCross, 53U) + RotL64(aPrevious, 3U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterI = ((aWandererA + RotL64(aScatter, 51U)) + RotL64(aCarry, 23U)) + 12692813903177772178U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 41U)) + RotL64(aCarry, 11U)) + 7112496446691277899U;
            aOrbiterJ = (((aWandererI + RotL64(aIngress, 11U)) + RotL64(aCarry, 37U)) + 2112247138290568813U) + aNonceWordG;
            aOrbiterD = (((aWandererE + RotL64(aCross, 3U)) + 3699421080882855947U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordC;
            aOrbiterC = (((aWandererG + RotL64(aIngress, 20U)) + 13761832028354380922U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordM;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 9243822514887600214U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 6863833516853046129U;
            aOrbiterJ = RotL64((aOrbiterJ * 775478131159266165U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 8863897995943098018U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterD) ^ 13346785686701467520U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 18074843497158380703U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 15309543066305531619U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 17515530938817919111U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16625193986319048245U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 760493237816424254U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = (((aOrbiterH ^ aOrbiterC) ^ 7282586354117620860U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterH = RotL64((aOrbiterH * 2327153408185290635U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 4129706068526969105U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 7020175432730888755U;
            aOrbiterC = RotL64((aOrbiterC * 10095158356907592239U), 21U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterI, 57U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + RotL64(aOrbiterH, 24U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 58U) + RotL64(aOrbiterC, 11U)) + aOrbiterI) + aNonceWordK);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterJ, 23U)) + aOrbiterD) + aNonceWordP);
            aWandererE = aWandererE + ((((RotL64(aCross, 11U) + aOrbiterJ) + RotL64(aOrbiterH, 41U)) + RotL64(aCarry, 3U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterI, 3U)) + aNonceWordD) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 50U)) + aOrbiterI) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererG, 26U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ aNonceWordB;
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 23521U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneA[((aIndex + 23502U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26036U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26165U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 20U) + RotL64(aCross, 35U)) ^ (RotL64(aIngress, 53U) + RotL64(aCarry, 5U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterJ = (((aWandererB + RotL64(aScatter, 5U)) + 8020711767807230555U) + aPhaseBOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1]) + aNonceWordB;
            aOrbiterE = ((aWandererC + RotL64(aCross, 43U)) + 15368693777246341570U) + aNonceWordC;
            aOrbiterC = (((aWandererG + RotL64(aIngress, 52U)) + RotL64(aCarry, 35U)) + 5117523734225562401U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 3U)) + 13155269151097507808U;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 35U)) + RotL64(aCarry, 19U)) + 9879303753623578272U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 1165799257173794826U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 930641942062732091U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17151944851548731159U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 11330571332221123153U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 2862963158282518899U;
            aOrbiterG = RotL64((aOrbiterG * 13782195862525974199U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 6019186399361476659U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 1924419843785161958U;
            aOrbiterJ = RotL64((aOrbiterJ * 9485557122500346869U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 12618629043591380461U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 9334176504266512405U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 18239109235362925739U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 16829692481030013551U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 5604784396927022709U) ^ aNonceWordP;
            aOrbiterH = RotL64((aOrbiterH * 2833893610883508353U), 39U);
            //
            aIngress = RotL64(aOrbiterC, 54U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aScatter, 13U) + aOrbiterG) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 57U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 21U) + aOrbiterH) + RotL64(aOrbiterC, 20U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 56U) + RotL64(aOrbiterE, 35U)) + aOrbiterG) + aNonceWordO) + aPhaseBWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 3U) + aOrbiterE) + RotL64(aOrbiterJ, 57U));
            aWandererE = aWandererE + ((((RotL64(aPrevious, 43U) + aOrbiterH) + RotL64(aOrbiterE, 43U)) + RotL64(aCarry, 29U)) + aNonceWordE);
            //
            aCarry = aCarry + (RotL64(aWandererB, 56U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 28272U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneB[((aIndex + 27487U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29557U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27986U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCarry, 3U)) ^ (RotL64(aIngress, 50U) + RotL64(aCross, 37U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 46U)) + RotL64(aCarry, 41U)) + 1708250618750199233U;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 37U)) + RotL64(aCarry, 27U)) + 12009147777553691142U;
            aOrbiterF = ((aWandererG + RotL64(aCross, 23U)) + 8393982703399156592U) + aNonceWordO;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 3U)) + 3247327098356831221U) + aPhaseBOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = (((aWandererA + RotL64(aCross, 57U)) + RotL64(aCarry, 13U)) + 3403590155376353737U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 18197244558104735044U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 3096253642040701606U;
            aOrbiterF = RotL64((aOrbiterF * 6656168712438620783U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 8012692688785412179U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 17531946907545680745U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16510602981731506381U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 17687695944270225817U) + aNonceWordJ;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 16147773866007628769U;
            aOrbiterC = RotL64((aOrbiterC * 16926442582711557877U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 18244641303026196497U) + aNonceWordM;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 8839160526348897457U;
            aOrbiterH = RotL64((aOrbiterH * 14268021129087663397U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 10599266240854068246U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 2056723540756216155U) ^ aNonceWordG;
            aOrbiterK = RotL64((aOrbiterK * 13311591601230386375U), 29U);
            //
            aIngress = RotL64(aOrbiterK, 39U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 41U)) + aOrbiterC) + RotL64(aCarry, 23U)) + aNonceWordF) + aPhaseBWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((((RotL64(aCross, 39U) + aOrbiterH) + RotL64(aOrbiterF, 26U)) + aNonceWordD) + aPhaseBWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 21U) + aOrbiterI) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 58U) + RotL64(aOrbiterC, 51U)) + aOrbiterK) + aNonceWordH);
            aWandererE = aWandererE + ((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterK, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 21U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = aCarry ^ aNonceWordF;
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

void TwistExpander_Bowling_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x9950E04830CB3381ULL + 0xF4DF3AAE844DB384ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xA7C324CC20E48EB9ULL + 0xC42CFDBB3F69B6DAULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xB4D3AD9AB11953B7ULL + 0xBA458CAF78D556D4ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xE2CB41EF56BC0923ULL + 0xD1E5EEFAFF128ADBULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xC1856C5393739115ULL + 0xB32374D80727D01CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xE57012D6B272E3A7ULL + 0xA6EB05B52162E3DAULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xAA6E679FFB0B3685ULL + 0xE8FAFA21B3563F25ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xFC2C6C09EBB284CFULL + 0xD275177627F1DD9AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xB40E036C826530BDULL + 0xB22FB3F2A1412708ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xE1B7C697E6CD1EC3ULL + 0xFA20F9B5952500F6ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xE83A4A4DA242FC95ULL + 0xBB346EC8396D8835ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xC10CB68D358848B3ULL + 0xDFB8C028BF65F119ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xC31D348469B651DBULL + 0x837609AE1C713CF3ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xE1B367298CA85887ULL + 0xDDF13FA6FDD4BDDCULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xAB7BDB3DCAB254C7ULL + 0x94DCFCAD1A989A2DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xD893F3F89A8EEA43ULL + 0xCFFB2BD4D285E657ULL);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 7405U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((aIndex + 2720U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 56U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 1057U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aIngress, 29U)) ^ (RotL64(aCross, 43U) ^ RotL64(aPrevious, 58U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterG = ((aWandererE + RotL64(aIngress, 10U)) + RotL64(aCarry, 19U)) + 380024772508948442U;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 5U)) + 7649029098162567210U;
            aOrbiterF = (((aWandererI + RotL64(aScatter, 51U)) + RotL64(aCarry, 47U)) + 5329304598870421851U) + aNonceWordP;
            aOrbiterH = ((aWandererH + RotL64(aCross, 19U)) + 12306118665045151326U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aPrevious, 29U)) + 960751560457324256U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 57U)) + 3244070254386191876U) + aNonceWordH;
            aOrbiterC = (aWandererF + RotL64(aCross, 24U)) + 15733408571609521746U;
            aOrbiterK = (aWandererB + RotL64(aIngress, 39U)) + 17623448932647018544U;
            aOrbiterJ = (((aWandererK + RotL64(aPrevious, 43U)) + RotL64(aCarry, 29U)) + 8787759896149035829U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 14741681792348288162U) + aNonceWordI;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 8801731213568307302U;
            aOrbiterF = RotL64((aOrbiterF * 12127126999570616489U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 9872248187499779222U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 15407371518644528235U;
            aOrbiterE = RotL64((aOrbiterE * 1245102406469471673U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 4242060317152943062U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 9942784962409917541U;
            aOrbiterK = RotL64((aOrbiterK * 888649755587764533U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 7296348796484458631U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 15061417216070157797U;
            aOrbiterJ = RotL64((aOrbiterJ * 10349554676953256231U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 3233185810644297433U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 9241229457641024287U;
            aOrbiterG = RotL64((aOrbiterG * 2728237515724597517U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 8464051359381554575U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 3307872165699029375U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4859663401033023433U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 5482617843966711997U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 4442149210462943872U;
            aOrbiterC = RotL64((aOrbiterC * 8979352218576515647U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 10591636597580147381U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 14925122230279312217U) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 15038171961638724013U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 9772367878232735350U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 15800661165607190092U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10493976952980533589U), 27U);
            //
            aIngress = RotL64(aOrbiterJ, 34U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterF, 24U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterE, 39U)) + aOrbiterC);
            aWandererF = aWandererF + (((((RotL64(aPrevious, 56U) + RotL64(aOrbiterF, 47U)) + aOrbiterI) + RotL64(aCarry, 47U)) + aNonceWordK) + aPhaseCWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 39U) + aOrbiterE) + RotL64(aOrbiterK, 34U));
            aWandererH = aWandererH + (((RotL64(aScatter, 27U) + RotL64(aOrbiterK, 57U)) + aOrbiterC) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterJ, 27U)) + aOrbiterI);
            aWandererK = aWandererK + (((RotL64(aCross, 43U) + RotL64(aOrbiterG, 43U)) + aOrbiterC) + RotL64(aCarry, 37U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 35U) + aOrbiterJ) + RotL64(aOrbiterF, 21U));
            aWandererA = aWandererA + ((RotL64(aIngress, 52U) + aOrbiterI) + RotL64(aOrbiterH, 4U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 13U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererB, 26U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + RotL64(aWandererK, 60U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordD);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 15684U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 11062U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 10044U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 15032U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCross, 41U)) + (RotL64(aCarry, 4U) ^ RotL64(aIngress, 53U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterB = (aWandererD + RotL64(aPrevious, 35U)) + 7790166497945719700U;
            aOrbiterH = (aWandererC + RotL64(aCross, 23U)) + 7136208896846119188U;
            aOrbiterJ = (aWandererG + RotL64(aIngress, 28U)) + 12123156943355100886U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 41U)) + RotL64(aCarry, 5U)) + 5095546037880875199U;
            aOrbiterD = ((((aWandererH + RotL64(aCross, 11U)) + RotL64(aCarry, 53U)) + 17642705393916765992U) + aPhaseCOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1]) + aNonceWordA;
            aOrbiterE = (aWandererF + RotL64(aIngress, 51U)) + 9918479837334416990U;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 47U)) + RotL64(aCarry, 13U)) + 4890009823843176466U;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 58U)) + 17652590786213674124U) + aPhaseCOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aPrevious, 19U)) + 870002527644696135U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 12545429703552643682U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 5310272867406182581U;
            aOrbiterJ = RotL64((aOrbiterJ * 10420003334833925011U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 3264719049050179440U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 1967241238180278937U;
            aOrbiterD = RotL64((aOrbiterD * 13004319774269457957U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 773883832927040736U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 12766817190261232485U;
            aOrbiterI = RotL64((aOrbiterI * 7448864556802318431U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 260069382395598265U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 15462103891287350123U;
            aOrbiterK = RotL64((aOrbiterK * 5029268763635635753U), 3U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterK) + 4072032867513289827U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordG;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 17153061419083897076U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11934532169271718913U), 19U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterG) + 6207264270332656966U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordH;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 18048064697837314947U;
            aOrbiterB = RotL64((aOrbiterB * 13632594619404208489U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 14484617445340272026U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 16160443600497652026U;
            aOrbiterA = RotL64((aOrbiterA * 1988599349457831597U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 5873314228291583482U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 16418290052752166515U;
            aOrbiterE = RotL64((aOrbiterE * 18270363452003213317U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 9158414409987627714U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterG) ^ 8205937960146492168U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 14008398661393344261U), 47U);
            //
            aIngress = RotL64(aOrbiterA, 19U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterB, 11U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 60U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + RotL64(aOrbiterG, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 42U) + aOrbiterJ) + RotL64(aOrbiterI, 39U));
            aWandererA = aWandererA + (((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterD, 43U)) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterI, 26U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 57U)) + aOrbiterE) + aNonceWordM) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterH, 53U)) + aOrbiterB);
            aWandererD = aWandererD + (((RotL64(aPrevious, 19U) + aOrbiterG) + RotL64(aOrbiterH, 21U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 37U) + aOrbiterH) + RotL64(aOrbiterI, 5U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 60U) + RotL64(aOrbiterJ, 10U)) + aOrbiterK) + RotL64(aCarry, 39U)) + aNonceWordJ);
            aWandererF = aWandererF ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterD, 47U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 22U));
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ aNonceWordL;
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 19364U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneA[((aIndex + 20864U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20394U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneC[((aIndex + 21232U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 51U) ^ RotL64(aCarry, 26U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterI = (aWandererA + RotL64(aPrevious, 40U)) + 4068921616130916949U;
            aOrbiterC = (((aWandererF + RotL64(aScatter, 47U)) + RotL64(aCarry, 35U)) + 12077715273915151726U) + aNonceWordA;
            aOrbiterG = (aWandererI + RotL64(aIngress, 23U)) + 16047546802670596833U;
            aOrbiterF = (aWandererG + RotL64(aCross, 35U)) + 9690277462716999763U;
            aOrbiterE = (aWandererH + RotL64(aPrevious, 57U)) + 14484814700447992628U;
            aOrbiterB = (aWandererE + RotL64(aScatter, 19U)) + 17089267243053958210U;
            aOrbiterH = (((aWandererJ + RotL64(aIngress, 6U)) + RotL64(aCarry, 47U)) + 9138746214446211147U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aCross, 29U)) + RotL64(aCarry, 57U)) + 10181001536979097045U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 11U)) + 6657458969093373191U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 7515983477876590988U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 3039935555863947600U;
            aOrbiterG = RotL64((aOrbiterG * 12511160550780270119U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 16209389224740851136U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 725253312098083182U;
            aOrbiterI = RotL64((aOrbiterI * 17535989492095522597U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 13307041115748941383U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 7159572004825238263U;
            aOrbiterF = RotL64((aOrbiterF * 4855009895002398449U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 12027236743251643820U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 8717826175991286553U;
            aOrbiterC = RotL64((aOrbiterC * 1175614802543098451U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 4769096034227659937U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 11201226563992939616U;
            aOrbiterE = RotL64((aOrbiterE * 15595355978388159931U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 17295978531215563256U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 11850923890626719833U;
            aOrbiterB = RotL64((aOrbiterB * 3854851059897397075U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 14139441565288097706U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 988684899382304485U;
            aOrbiterH = RotL64((aOrbiterH * 11929090869999700891U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 6159251276942253175U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterK) ^ 4849529993914550651U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 18240712676783671317U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 6679745455842119497U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 15838404437552215214U;
            aOrbiterK = RotL64((aOrbiterK * 17357853511591350887U), 19U);
            //
            aIngress = RotL64(aOrbiterE, 13U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterJ, 10U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + RotL64(aOrbiterC, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 11U) + aOrbiterJ) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterB, 57U));
            aWandererE = aWandererE + ((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterG, 43U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterC, 35U)) + aOrbiterH);
            aWandererH = aWandererH + ((RotL64(aPrevious, 42U) + aOrbiterI) + RotL64(aOrbiterK, 22U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterI, 39U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererG = aWandererG + (((((RotL64(aIngress, 23U) + aOrbiterB) + RotL64(aOrbiterK, 51U)) + RotL64(aCarry, 3U)) + aNonceWordD) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterK, 47U));
            aWandererK = aWandererK + ((RotL64(aCross, 60U) + RotL64(aOrbiterI, 26U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererB, 50U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordJ);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 29471U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneB[((aIndex + 29568U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30936U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneD[((aIndex + 27719U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 48U) ^ RotL64(aIngress, 11U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCross, 35U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterD = ((aWandererB + RotL64(aIngress, 35U)) + RotL64(aCarry, 5U)) + 9023059520606551446U;
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 56U)) + 662441755115638133U;
            aOrbiterE = ((aWandererD + RotL64(aCross, 39U)) + 16957253361196144712U) + aNonceWordL;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 47U)) + 7840955025765308605U) + aNonceWordF;
            aOrbiterK = ((((aWandererI + RotL64(aPrevious, 29U)) + RotL64(aCarry, 27U)) + 346855809270395799U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordO;
            aOrbiterH = (aWandererF + RotL64(aIngress, 3U)) + 16099139781586668343U;
            aOrbiterC = (aWandererK + RotL64(aCross, 43U)) + 3706457327118322098U;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 20U)) + RotL64(aCarry, 47U)) + 12166825885547622870U;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 51U)) + 7792658665720344200U) + aPhaseCOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 7128477606152986326U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 11116533962780290084U;
            aOrbiterE = RotL64((aOrbiterE * 11993485572912492297U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 10443889548568288532U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 4402387036946561017U;
            aOrbiterK = RotL64((aOrbiterK * 9032964741841833277U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 13002706161178447654U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 13929727277530310708U;
            aOrbiterC = RotL64((aOrbiterC * 7005639090871200285U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 10949073760696935106U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 15405923432006783533U;
            aOrbiterD = RotL64((aOrbiterD * 17989565878445202495U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 18096057968822208905U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 3032155040484574973U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 448597307502544605U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 17462076466907467134U) + aNonceWordK;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 15471015427013701406U;
            aOrbiterH = RotL64((aOrbiterH * 6113474000571976139U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 3549031751266594344U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 14243218483842508113U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9041601306479302047U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 5803147589312920032U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 5549470512227427855U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12592362489263862879U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 10076661824293832189U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 3196799148974716550U;
            aOrbiterJ = RotL64((aOrbiterJ * 8183276968961467775U), 23U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 23U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 20U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + RotL64(aOrbiterK, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterA, 57U)) + aOrbiterK) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 28U) + aOrbiterK) + RotL64(aOrbiterI, 38U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 51U) + aOrbiterH) + RotL64(aOrbiterJ, 51U)) + aNonceWordP);
            aWandererK = aWandererK + ((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 21U)) + aOrbiterC);
            aWandererB = aWandererB ^ ((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterE, 43U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterB, 11U)) + aOrbiterK) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 3U)) + aOrbiterD) + aNonceWordD);
            aWandererH = aWandererH + ((((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 27U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 34U) + aOrbiterE) + RotL64(aOrbiterH, 28U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 20U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordN;
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

void TwistExpander_Bowling_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x9AE828861D0040CFULL + 0x82C19C86C189783FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xC24E6B9606F566F7ULL + 0xE2629A7961D1DD08ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x8A68BA4180AF1131ULL + 0xCC4F638AA2897D67ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xE8EF83619AE3563BULL + 0xF244096D9DB1CD40ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xEED6139427D43CAFULL + 0x97AFD5C8569F4A5BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xE8881C3BEEDADA5DULL + 0xA22C928BC5804C69ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x8069B11290B5D99FULL + 0xCDFA09C3DA3EA5FCULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xC545CB2E7E9D2035ULL + 0xF71C04A14B398908ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xB96A0CA61F0BFA23ULL + 0xA975284CDFD2008AULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x80862BBC6E913469ULL + 0xDFC536EE37CAE5D2ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xA6D5F31680207C23ULL + 0xD40227979A268A16ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x8013818942DE5F17ULL + 0x8AC7B2D0B3A7E951ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xCFF911A1371030BDULL + 0x877CDB7754E2DA22ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x89DD3528D6764EF3ULL + 0xC032FCBFF25D6F01ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xCCFF5C3BAEBD4E09ULL + 0x82BB076D298D5445ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x953A6E2136E460DBULL + 0xBC7C690ABF64D095ULL);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 750U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneC[((aIndex + 4730U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 870U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 750U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 44U)) + (RotL64(aCross, 57U) ^ RotL64(aIngress, 19U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterB = (aWandererF + RotL64(aIngress, 19U)) + 10915618884692072446U;
            aOrbiterG = (aWandererD + RotL64(aScatter, 10U)) + 12634922308499254909U;
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 39U)) + 6533934734564499389U) + aPhaseDOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aCross, 13U)) + RotL64(aCarry, 35U)) + 6744203303756105181U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 43U)) + 13086782386652045658U) + aPhaseDOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aPrevious, 3U)) + 5693840533331397822U;
            aOrbiterJ = (((aWandererG + RotL64(aIngress, 41U)) + RotL64(aCarry, 19U)) + 1803663542535024611U) + aNonceWordH;
            aOrbiterA = (aWandererC + RotL64(aCross, 53U)) + 3597219300593287708U;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 37U)) + 1429753448204448904U) + aNonceWordD;
            aOrbiterK = (aWandererJ + RotL64(aCross, 21U)) + 17229017825587322715U;
            aOrbiterE = ((aWandererI + RotL64(aScatter, 30U)) + RotL64(aCarry, 43U)) + 1137574712801062932U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 2401991077004083378U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 1332473247826139292U;
            aOrbiterH = RotL64((aOrbiterH * 15029831858261506447U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 11730946340796899885U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 15319163439700390962U;
            aOrbiterF = RotL64((aOrbiterF * 1349242001887975499U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 4744141870145159917U) + aNonceWordN;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 6067132201862688684U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6046100687757836027U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 14991509179286371800U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 4342608825699398682U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10240526103933275875U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 3727521409410742075U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 3302027219498304367U) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 12153634588200479559U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 6039539483340398858U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 2902581519976937051U;
            aOrbiterC = RotL64((aOrbiterC * 2057584328877854239U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 12332784713738947242U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 13761272577223712786U;
            aOrbiterE = RotL64((aOrbiterE * 14930145045480030821U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 2947946397617043735U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 11107014023853644521U;
            aOrbiterG = RotL64((aOrbiterG * 15030903626191481831U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 6212403196992771516U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 16107261731677426470U;
            aOrbiterD = RotL64((aOrbiterD * 13764822942405295129U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 8414111492161335472U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 3625937496991123221U;
            aOrbiterA = RotL64((aOrbiterA * 1736741235159600739U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 5466667339391480293U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 10915618884692072446U;
            aOrbiterK = RotL64((aOrbiterK * 14719282928172086707U), 41U);
            //
            aIngress = RotL64(aOrbiterF, 35U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterD, 52U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + RotL64(aOrbiterH, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aIngress, 19U) + aOrbiterH) + RotL64(aOrbiterE, 56U)) + aNonceWordO);
            aWandererH = aWandererH + (((RotL64(aCross, 43U) + RotL64(aOrbiterG, 11U)) + aOrbiterC) + aPhaseDWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterG, 19U)) + aOrbiterF) + aNonceWordC);
            aWandererK = aWandererK + ((RotL64(aPrevious, 27U) + aOrbiterJ) + RotL64(aOrbiterK, 3U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterC, 23U)) + aPhaseDWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 43U)) + aOrbiterD);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 24U) + RotL64(aOrbiterD, 51U)) + aOrbiterI);
            aWandererE = aWandererE + ((((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterI, 13U)) + RotL64(aCarry, 57U)) + aNonceWordP);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterA, 39U));
            aWandererF = aWandererF + (((RotL64(aScatter, 39U) + RotL64(aOrbiterK, 48U)) + aOrbiterH) + RotL64(aCarry, 51U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 34U) + aOrbiterI) + RotL64(aOrbiterJ, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 60U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererK, 58U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 8614U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneD[((aIndex + 9391U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9749U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((aIndex + 9956U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 58U) ^ RotL64(aCarry, 27U)) + (RotL64(aCross, 13U) ^ RotL64(aIngress, 39U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterA = (aWandererK + RotL64(aPrevious, 54U)) + 13296600294247799698U;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 19U)) + RotL64(aCarry, 27U)) + 5818503518080877515U;
            aOrbiterF = (aWandererF + RotL64(aIngress, 23U)) + 6735784238734173597U;
            aOrbiterH = (((aWandererD + RotL64(aCross, 51U)) + 7368398209488856201U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordG;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 41U)) + 961734029066455638U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aScatter, 35U)) + 797011946660892011U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 37U)) + RotL64(aCarry, 47U)) + 12841876018396622350U;
            aOrbiterK = (aWandererH + RotL64(aPrevious, 43U)) + 16213253970483895623U;
            aOrbiterD = (aWandererG + RotL64(aScatter, 57U)) + 15186950557113470375U;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 29U)) + RotL64(aCarry, 19U)) + 5117930310827477341U;
            aOrbiterE = (aWandererE + RotL64(aCross, 48U)) + 12265429373166094162U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 13920531346698601568U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 14695405206998211456U;
            aOrbiterF = RotL64((aOrbiterF * 13950964363414164279U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 7851960904825938443U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 9501511171732550190U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5614164120361489613U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 5663365182245722077U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 9607860124321315555U;
            aOrbiterI = RotL64((aOrbiterI * 3461820361914280601U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 18171052650586819280U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 3442698321538580861U;
            aOrbiterG = RotL64((aOrbiterG * 6317525514963824829U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 1491052813469258970U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 3956599824067616133U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2928600779267623085U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 10963841237346073453U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 2303020125591252534U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9969099842343321981U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 14503856057958162356U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 11147548150090597694U;
            aOrbiterH = RotL64((aOrbiterH * 11856382308792700441U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 9191681438318311481U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 13556072770381999852U;
            aOrbiterB = RotL64((aOrbiterB * 18316231099054203683U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 10103207278550444685U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 10415809965217261104U;
            aOrbiterK = RotL64((aOrbiterK * 16562732599511350217U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 17435033201864058457U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 5540494424887364682U) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 18230910315317249045U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 18020151683897013854U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 13296600294247799698U;
            aOrbiterE = RotL64((aOrbiterE * 10000194329456668845U), 51U);
            //
            aIngress = RotL64(aOrbiterE, 11U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + (RotL64(aOrbiterG, 44U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 44U) + aOrbiterF) + RotL64(aOrbiterH, 13U)) + aNonceWordJ);
            aWandererB = aWandererB ^ ((RotL64(aCross, 23U) + aOrbiterK) + RotL64(aOrbiterG, 21U));
            aWandererA = aWandererA + (((RotL64(aScatter, 37U) + aOrbiterF) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterI, 56U));
            aWandererC = aWandererC + (((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterG, 47U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 19U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 41U)) + aNonceWordF);
            aWandererH = aWandererH ^ (((RotL64(aCross, 46U) + RotL64(aOrbiterB, 11U)) + aOrbiterJ) + aNonceWordA);
            aWandererE = aWandererE + (((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterI, 30U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterH, 41U));
            aWandererI = aWandererI + ((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterC, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 4U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 43U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 14737U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((aIndex + 12224U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16359U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((aIndex + 14875U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aIngress, 23U)) ^ (RotL64(aPrevious, 40U) + RotL64(aCross, 53U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterI = (aWandererA + RotL64(aPrevious, 51U)) + 12692813903177772178U;
            aOrbiterD = ((aWandererE + RotL64(aCross, 37U)) + RotL64(aCarry, 29U)) + 7112496446691277899U;
            aOrbiterH = (aWandererH + RotL64(aIngress, 27U)) + 2112247138290568813U;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 47U)) + RotL64(aCarry, 19U)) + 3699421080882855947U;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 57U)) + 13761832028354380922U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = (aWandererD + RotL64(aCross, 14U)) + 9243822514887600214U;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 35U)) + 6863833516853046129U) + aPhaseDOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = (aWandererB + RotL64(aScatter, 43U)) + 8863897995943098018U;
            aOrbiterB = (aWandererC + RotL64(aPrevious, 3U)) + 13346785686701467520U;
            aOrbiterA = (((aWandererI + RotL64(aIngress, 54U)) + RotL64(aCarry, 43U)) + 15309543066305531619U) + aNonceWordA;
            aOrbiterJ = (aWandererK + RotL64(aCross, 39U)) + 17515530938817919111U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 760493237816424254U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 7282586354117620860U;
            aOrbiterH = RotL64((aOrbiterH * 2327153408185290635U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 4129706068526969105U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 7020175432730888755U;
            aOrbiterC = RotL64((aOrbiterC * 10095158356907592239U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 9102258982216515596U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 10822031305361453690U) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 2036205056490578491U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 12571477440964330246U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 8436347026653095199U;
            aOrbiterG = RotL64((aOrbiterG * 17930734781213681573U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 14214789872073941940U) + aNonceWordL;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 12915911919403385001U;
            aOrbiterE = RotL64((aOrbiterE * 13161681603528031511U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 15443240166233851298U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 7311369180113240915U;
            aOrbiterA = RotL64((aOrbiterA * 13339195007946889423U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 12976516224995960015U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 7823308381434556721U;
            aOrbiterI = RotL64((aOrbiterI * 502385172763861451U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 4829417661664149137U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 16306394751966719700U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5294376579588592157U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 16769868341852572677U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 7107433163189177642U;
            aOrbiterF = RotL64((aOrbiterF * 5279050651595743649U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 11896784111967113871U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 389626690429371003U;
            aOrbiterB = RotL64((aOrbiterB * 10665914532159182181U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 8226849597052979358U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 12692813903177772178U;
            aOrbiterJ = RotL64((aOrbiterJ * 17909062471564422847U), 5U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterA, 53U);
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterJ, 51U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + RotL64(aOrbiterH, 42U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 39U) + aOrbiterB) + RotL64(aOrbiterA, 21U)) + aNonceWordB);
            aWandererJ = aWandererJ + ((RotL64(aCross, 4U) + aOrbiterJ) + RotL64(aOrbiterI, 44U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 51U) + aOrbiterC) + RotL64(aOrbiterB, 47U));
            aWandererE = aWandererE + (((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterF, 5U)) + RotL64(aCarry, 19U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterB, 57U)) + aOrbiterI) + aNonceWordF);
            aWandererK = aWandererK + (((RotL64(aPrevious, 23U) + aOrbiterK) + RotL64(aOrbiterG, 11U)) + RotL64(aCarry, 13U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterG, 27U)) + aOrbiterD);
            aWandererI = aWandererI + (((RotL64(aIngress, 11U) + aOrbiterE) + RotL64(aOrbiterC, 39U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 21U) + aOrbiterC) + RotL64(aOrbiterA, 23U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 53U) + RotL64(aOrbiterG, 19U)) + aOrbiterI);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 14U) + RotL64(aOrbiterH, 42U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 50U));
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 27U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 19262U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneB[((aIndex + 18405U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18554U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18883U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 38U)) + (RotL64(aCarry, 23U) + RotL64(aIngress, 51U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterA = (aWandererH + RotL64(aIngress, 53U)) + 439898681482066326U;
            aOrbiterE = (aWandererD + RotL64(aCross, 60U)) + 17362083676671776094U;
            aOrbiterC = (aWandererE + RotL64(aScatter, 57U)) + 6418499837265155024U;
            aOrbiterK = (((aWandererK + RotL64(aPrevious, 21U)) + RotL64(aCarry, 35U)) + 17262244253027454972U) + aNonceWordM;
            aOrbiterF = (aWandererF + RotL64(aScatter, 51U)) + 2382066162993139503U;
            aOrbiterH = ((aWandererG + RotL64(aCross, 46U)) + RotL64(aCarry, 43U)) + 14345808395587174135U;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 41U)) + 7534743166385552851U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = ((aWandererB + RotL64(aIngress, 43U)) + RotL64(aCarry, 21U)) + 16994453324688523966U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 13U)) + 7079553728544045092U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aCross, 27U)) + 3562822704508440641U;
            aOrbiterB = (aWandererA + RotL64(aScatter, 39U)) + 13990892681975857821U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 1796728922368577238U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 6605161260520067178U;
            aOrbiterC = RotL64((aOrbiterC * 8147537646591674091U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 13994083795942328918U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 6144523182899107711U;
            aOrbiterF = RotL64((aOrbiterF * 4153879991344611283U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 12247462325297436642U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 1065809332002012789U;
            aOrbiterH = RotL64((aOrbiterH * 5496601177032953251U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 10147919864511540753U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 17138553441127273354U;
            aOrbiterD = RotL64((aOrbiterD * 5773875596275267871U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 2653924016109573974U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 6254416952351699582U;
            aOrbiterI = RotL64((aOrbiterI * 12756861659704947257U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 813046408080197079U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 9624466135414123483U;
            aOrbiterG = RotL64((aOrbiterG * 6960320253124395015U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 972586705850825744U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 155283774901960223U;
            aOrbiterJ = RotL64((aOrbiterJ * 9928051687724257041U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 18200100644751360406U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 1168426822045686004U;
            aOrbiterB = RotL64((aOrbiterB * 5867027156069481313U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 2271564377169233643U) + aNonceWordP;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 1896317305868283986U;
            aOrbiterA = RotL64((aOrbiterA * 8080751157990019287U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 10209708407397294552U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 947585551223387294U;
            aOrbiterE = RotL64((aOrbiterE * 15339472308062247067U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 12313594490465462211U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 439898681482066326U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12336632799055203705U), 39U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterH, 41U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 60U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 37U) + aOrbiterB) + RotL64(aOrbiterF, 10U)) + aPhaseDWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 56U) + aOrbiterA) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 3U)) + aOrbiterA);
            aWandererE = aWandererE + ((((RotL64(aScatter, 39U) + RotL64(aOrbiterA, 37U)) + aOrbiterF) + RotL64(aCarry, 43U)) + aPhaseDWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 3U) + aOrbiterD) + RotL64(aOrbiterK, 28U));
            aWandererA = aWandererA + ((RotL64(aCross, 23U) + RotL64(aOrbiterK, 13U)) + aOrbiterJ);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 53U) + aOrbiterG) + RotL64(aOrbiterF, 51U));
            aWandererB = aWandererB + ((RotL64(aScatter, 51U) + aOrbiterK) + RotL64(aOrbiterC, 35U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 43U)) + aOrbiterB) + aNonceWordO);
            aWandererG = aWandererG + ((RotL64(aCross, 43U) + RotL64(aOrbiterG, 57U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 10U) + aOrbiterC) + RotL64(aOrbiterA, 41U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 58U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + RotL64(aWandererG, 27U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 22251U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 22275U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26331U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 24283U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCross, 18U)) ^ (RotL64(aCarry, 5U) + RotL64(aPrevious, 37U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 34U)) + RotL64(aCarry, 19U)) + 15045917390223766480U;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 37U)) + RotL64(aCarry, 23U)) + 10763054007033668758U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 27U)) + 13190170142593666607U) + aPhaseDOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aCross, 21U)) + 9657025731441167065U;
            aOrbiterG = ((aWandererC + RotL64(aIngress, 51U)) + 11433367178975954211U) + aPhaseDOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = (aWandererD + RotL64(aCross, 29U)) + 17904920143996810366U;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 11U)) + 3244383020512113283U;
            aOrbiterE = ((aWandererI + RotL64(aScatter, 60U)) + 6538815775171139091U) + aNonceWordN;
            aOrbiterK = (aWandererH + RotL64(aPrevious, 39U)) + 7195368312757976343U;
            aOrbiterC = ((aWandererG + RotL64(aCross, 5U)) + RotL64(aCarry, 29U)) + 18134430713910279374U;
            aOrbiterI = (aWandererJ + RotL64(aIngress, 47U)) + 6571776588427107976U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 11830778129647517758U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 9793702760907767365U;
            aOrbiterB = RotL64((aOrbiterB * 4096246227968677179U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 2287235876793192036U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 8951959188326141794U) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 9968356718110753845U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 7583061790273240157U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 3571364625022806085U;
            aOrbiterE = RotL64((aOrbiterE * 6238360922735480669U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 13869345563551689212U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 277480328952975002U;
            aOrbiterC = RotL64((aOrbiterC * 1057564597096163085U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 4983735092494677578U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 9490022869381030928U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12926352917961703123U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 7928039573014765566U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 6504190875809407084U;
            aOrbiterJ = RotL64((aOrbiterJ * 14648214826494826711U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 2787985600176307413U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 16308785053443116826U;
            aOrbiterH = RotL64((aOrbiterH * 17867565986311256691U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 12788128335006767824U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 1187040019537798339U;
            aOrbiterK = RotL64((aOrbiterK * 10834905007658184183U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 10771230162770496645U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 6542421559654716320U;
            aOrbiterI = RotL64((aOrbiterI * 16829492790597069373U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 702458690970201679U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 2806140783487813070U;
            aOrbiterD = RotL64((aOrbiterD * 7415398198842270381U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 950611302199732036U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 15045917390223766480U;
            aOrbiterG = RotL64((aOrbiterG * 9358017420417979347U), 23U);
            //
            aIngress = RotL64(aOrbiterC, 43U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + RotL64(aOrbiterA, 50U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterJ, 51U)) + aOrbiterF) + aNonceWordB);
            aWandererC = aWandererC + ((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterC, 48U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterE, 37U)) + aOrbiterA);
            aWandererF = aWandererF + (((RotL64(aCross, 37U) + RotL64(aOrbiterH, 35U)) + aOrbiterK) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 50U) + aOrbiterK) + RotL64(aOrbiterB, 23U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 23U) + aOrbiterD) + RotL64(aOrbiterF, 57U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterJ, 19U)) + aOrbiterG);
            aWandererH = aWandererH + ((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterH, 43U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 4U) + RotL64(aOrbiterB, 10U)) + aOrbiterH);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 53U)) + aOrbiterI) + RotL64(aCarry, 5U)) + aPhaseDWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 53U) + aOrbiterH) + RotL64(aOrbiterE, 13U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (RotL64(aWandererK, 6U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + RotL64(aWandererD, 54U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 30872U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27856U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29994U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28132U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aPrevious, 22U)) ^ (RotL64(aCross, 5U) ^ RotL64(aIngress, 39U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterH = (aWandererA + RotL64(aPrevious, 54U)) + 17936518874386450467U;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 13U)) + RotL64(aCarry, 57U)) + 13722737841589910344U;
            aOrbiterI = ((aWandererB + RotL64(aCross, 41U)) + 11774969167948715796U) + aNonceWordG;
            aOrbiterA = (aWandererC + RotL64(aScatter, 19U)) + 3640101505680493777U;
            aOrbiterF = (aWandererK + RotL64(aCross, 47U)) + 1369495382725650822U;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 60U)) + RotL64(aCarry, 53U)) + 11827310354654653345U;
            aOrbiterG = (((aWandererJ + RotL64(aScatter, 23U)) + 186037671377175394U) + aPhaseDOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1]) + aNonceWordN;
            aOrbiterB = (aWandererH + RotL64(aIngress, 37U)) + 11428829344234627340U;
            aOrbiterK = (aWandererE + RotL64(aCross, 43U)) + 2275016369870029068U;
            aOrbiterD = (((aWandererD + RotL64(aScatter, 51U)) + RotL64(aCarry, 21U)) + 15471646673734798328U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = (aWandererG + RotL64(aPrevious, 27U)) + 12172082573115640145U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 6626736341348283154U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 12220614992483863623U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8137086205714097487U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 13157102324253760215U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 4143587482368093601U;
            aOrbiterF = RotL64((aOrbiterF * 5060677690991506895U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 11007575246013796426U) + aNonceWordM;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 11721585930088637162U;
            aOrbiterJ = RotL64((aOrbiterJ * 15009627907125738519U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 5720789204450196217U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 3094696226821431648U) ^ aNonceWordJ;
            aOrbiterG = RotL64((aOrbiterG * 4412033981712165541U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 14675830108100986773U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 9444071495289719645U;
            aOrbiterB = RotL64((aOrbiterB * 10983136361953366557U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 5106753847015199956U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 7585421898593510010U;
            aOrbiterK = RotL64((aOrbiterK * 140996914192351011U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 11746948407655524690U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterG) ^ 16336323220286344483U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 6590417628835864497U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 8030445186765781136U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 276034088015165891U;
            aOrbiterE = RotL64((aOrbiterE * 7626025612710225099U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 8116955322602209153U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 5704503350608834450U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7049558959583832449U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 8063875087087055875U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 1111816778196345760U;
            aOrbiterC = RotL64((aOrbiterC * 13820440198677609571U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 7702895879089714461U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 17936518874386450467U;
            aOrbiterA = RotL64((aOrbiterA * 12767279443267850009U), 47U);
            //
            aIngress = RotL64(aOrbiterI, 29U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 18U));
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 6U) + RotL64(aOrbiterH, 14U)) + aOrbiterK);
            aWandererD = aWandererD + ((RotL64(aCross, 35U) + RotL64(aOrbiterB, 53U)) + aOrbiterK);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterD, 23U)) + aOrbiterE);
            aWandererK = aWandererK + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterC, 5U)) + aOrbiterH) + aPhaseDWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterJ, 57U)) + aOrbiterE);
            aWandererC = aWandererC + (((RotL64(aScatter, 21U) + aOrbiterK) + RotL64(aOrbiterG, 47U)) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterA, 29U)) + aOrbiterI) + aNonceWordL);
            aWandererH = aWandererH + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterJ, 3U)) + aOrbiterF) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 50U) + RotL64(aOrbiterJ, 27U)) + aOrbiterA) + aPhaseDWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 47U) + aOrbiterH) + RotL64(aOrbiterJ, 39U)) + aNonceWordF);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterD, 12U)) + aOrbiterJ) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 54U));
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 36U));
            aCarry = aCarry + RotL64(aWandererC, 11U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordL;
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

void TwistExpander_Bowling_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xCF73A7DF29B84CEFULL + 0xEC9AF5C5DD267758ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xAF92042F5E09D859ULL + 0xFE3D15170201A41DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xE9A80F326D8FF4AFULL + 0xED87DCA872A40B04ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x87D58A172818B9F9ULL + 0xCA594279549C1878ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x83A03161865EC0D3ULL + 0xBCDB0A98A9108901ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x8FE117259D9E44FBULL + 0xC42A6AF3B3537246ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x8C09661AA2EA4EFBULL + 0x930392117F36CBAAULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x930DE9E84C15F08FULL + 0xAB5EA900318BEF9AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xC4334658663C3077ULL + 0xB5A0B0BD70771643ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xD858EF3297853FA1ULL + 0xAA1FD41816B9B7D6ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xB79CA770C2A9B6ADULL + 0x95816ABECF935090ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xF1CAB0A74E81BEEBULL + 0xF8DDA9507CB6DA23ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x979E4907C438920DULL + 0xA0B6C0B2374321AFULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xAB930EC122F5F6F3ULL + 0x88DDFE14C80EBE9EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xBD139EC53ED9F4F1ULL + 0x86AE65A2E0F6252EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x9BBC8FFEA704B499ULL + 0xB72150CF674D3C39ULL);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 3091U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneC[((aIndex + 4284U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 859U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 3245U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 56U)) ^ (RotL64(aCarry, 35U) ^ RotL64(aIngress, 23U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterB = ((aWandererH + RotL64(aIngress, 44U)) + 4476099022490972343U) + aNonceWordG;
            aOrbiterC = (((aWandererJ + RotL64(aPrevious, 3U)) + 16836423700375760429U) + aPhaseEOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1]) + aNonceWordA;
            aOrbiterI = ((aWandererI + RotL64(aCross, 35U)) + 8850577488928703557U) + aPhaseEOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (aWandererF + RotL64(aScatter, 5U)) + 7091631824560042743U;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 37U)) + RotL64(aCarry, 39U)) + 12560498899956759494U;
            aOrbiterJ = (aWandererK + RotL64(aIngress, 27U)) + 7797973377112012161U;
            aOrbiterG = (aWandererA + RotL64(aScatter, 21U)) + 6173820673874805794U;
            aOrbiterA = (aWandererE + RotL64(aCross, 29U)) + 10805025132310245348U;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 13U)) + RotL64(aCarry, 21U)) + 7139216143268029968U;
            aOrbiterF = (((aWandererD + RotL64(aCross, 58U)) + RotL64(aCarry, 35U)) + 8241544862261635722U) + aNonceWordM;
            aOrbiterH = (aWandererC + RotL64(aScatter, 47U)) + 4735527016563596150U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 5166171126690294033U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 11117641762075368393U;
            aOrbiterI = RotL64((aOrbiterI * 4980156869201219393U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 6312932356458415421U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 1304139291184508668U;
            aOrbiterJ = RotL64((aOrbiterJ * 90744653170922319U), 3U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterA) + 10085025354842771067U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordB;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 16745854428789531080U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1945983905747274355U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 2497187958708890337U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 16069701876646548995U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16606039730973709495U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 17242004368025978091U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 12334315722243232121U) ^ aNonceWordE;
            aOrbiterG = RotL64((aOrbiterG * 16528598396696346719U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 8007042082518126895U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 5665686359038811484U;
            aOrbiterD = RotL64((aOrbiterD * 11289316305875751813U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 3913477186958600592U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 16918984318564170343U;
            aOrbiterH = RotL64((aOrbiterH * 5128293326494417281U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 10227611546502931418U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 7187623463085447228U;
            aOrbiterC = RotL64((aOrbiterC * 8479839369622163181U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 16655159122037336519U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 9844145011519243346U;
            aOrbiterE = RotL64((aOrbiterE * 16512883184116277583U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 8660130685326542506U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 16192687259641294851U;
            aOrbiterA = RotL64((aOrbiterA * 2882649237163668499U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 15208432734447317310U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 4476099022490972343U;
            aOrbiterF = RotL64((aOrbiterF * 7447168142776253041U), 35U);
            //
            aIngress = RotL64(aOrbiterH, 39U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterA, 54U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterA, 39U)) + aNonceWordD);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 60U) + RotL64(aOrbiterK, 47U)) + aOrbiterH) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 57U)) + aOrbiterK) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterG, 20U)) + aNonceWordL);
            aWandererK = aWandererK + ((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 11U)) + aOrbiterD);
            aWandererH = aWandererH ^ ((RotL64(aCross, 40U) + aOrbiterI) + RotL64(aOrbiterD, 35U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterD, 29U)) + aOrbiterK) + aNonceWordO);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 53U)) + aOrbiterG) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 27U)) + aOrbiterH) + RotL64(aCarry, 23U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterE, 37U)) + aOrbiterJ);
            aWandererE = aWandererE + ((RotL64(aScatter, 27U) + RotL64(aOrbiterA, 22U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererF, 34U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 6479U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 6152U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7071U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 8475U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCross, 53U)) ^ (RotL64(aCarry, 22U) ^ RotL64(aIngress, 3U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterB = ((aWandererB + RotL64(aScatter, 39U)) + 15316464782468770057U) + aNonceWordH;
            aOrbiterK = (aWandererD + RotL64(aIngress, 20U)) + 6642872057476351588U;
            aOrbiterD = ((aWandererK + RotL64(aCross, 23U)) + RotL64(aCarry, 19U)) + 660732654689529192U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 27U)) + 7235418086884000655U) + aPhaseEOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 53U)) + 14784518476694580493U) + aNonceWordE;
            aOrbiterG = (((aWandererC + RotL64(aPrevious, 41U)) + RotL64(aCarry, 13U)) + 12222433977933449375U) + aPhaseEOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = ((aWandererI + RotL64(aIngress, 29U)) + 8573001207708329927U) + aNonceWordF;
            aOrbiterA = (aWandererA + RotL64(aScatter, 47U)) + 16035256260815013172U;
            aOrbiterF = (aWandererH + RotL64(aIngress, 3U)) + 15767726974121910203U;
            aOrbiterH = (aWandererE + RotL64(aCross, 44U)) + 17712217935322939971U;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 57U)) + RotL64(aCarry, 43U)) + 13488963456923357159U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 10222949131965611079U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 1495561412321657209U;
            aOrbiterD = RotL64((aOrbiterD * 9706305581868526265U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 16156530750584361434U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 7773792489045606309U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10730624207715601393U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 11544578291333360613U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 3665587867634242865U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4840528190844842595U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 15248434984650998090U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 15487979645426567581U;
            aOrbiterC = RotL64((aOrbiterC * 10868107809356766183U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 6972347795052712690U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 16074994810010431338U;
            aOrbiterF = RotL64((aOrbiterF * 1262655238856775853U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 16851139687900415292U) + aNonceWordL;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 14630026837021552812U;
            aOrbiterB = RotL64((aOrbiterB * 9577900853521254603U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 14236330619137368169U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 17778707026111136216U;
            aOrbiterI = RotL64((aOrbiterI * 16239561893843454747U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 9390961969105999083U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 1174881758316573228U;
            aOrbiterG = RotL64((aOrbiterG * 6602061268277529311U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 3025148570039849574U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 2813499258480831171U) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 12272555492688861861U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 15397952138592662354U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 10394648143430175275U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 18195627209519212303U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 3043205345760158739U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 15316464782468770057U;
            aOrbiterE = RotL64((aOrbiterE * 8162506622688910545U), 11U);
            //
            aIngress = RotL64(aOrbiterG, 27U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 10U));
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 10U) + RotL64(aOrbiterJ, 43U)) + aOrbiterI) + aNonceWordD);
            aWandererC = aWandererC + (((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 53U)) + aOrbiterH) + aNonceWordB);
            aWandererA = aWandererA ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterK, 23U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 21U) + aOrbiterG) + RotL64(aOrbiterK, 30U)) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 23U) + aOrbiterA) + RotL64(aOrbiterB, 27U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 51U) + aOrbiterC) + RotL64(aOrbiterH, 41U)) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 43U) + aOrbiterE) + RotL64(aOrbiterI, 13U));
            aWandererE = aWandererE + (((RotL64(aCross, 40U) + RotL64(aOrbiterD, 37U)) + aOrbiterB) + aNonceWordK);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterA, 58U)) + aOrbiterI);
            aWandererD = aWandererD + (((RotL64(aCross, 37U) + RotL64(aOrbiterF, 5U)) + aOrbiterC) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterA, 19U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 50U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 38U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 19U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 15822U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 12236U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 14240U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 11133U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 38U) + RotL64(aCarry, 19U)) ^ (RotL64(aIngress, 53U) + RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterG = (aWandererK + RotL64(aCross, 46U)) + 7722279280863371124U;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 39U)) + 11584220561732385598U;
            aOrbiterE = (aWandererE + RotL64(aScatter, 53U)) + 7834679350105534657U;
            aOrbiterB = (aWandererB + RotL64(aIngress, 21U)) + 11347994382444180879U;
            aOrbiterH = (((aWandererA + RotL64(aPrevious, 37U)) + RotL64(aCarry, 35U)) + 9449903188047063431U) + aPhaseEOrbiterAssignSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aIngress, 5U)) + 6516243976652795170U;
            aOrbiterC = (aWandererH + RotL64(aScatter, 10U)) + 8420815253991184777U;
            aOrbiterI = (((aWandererI + RotL64(aCross, 43U)) + RotL64(aCarry, 29U)) + 9081386852515170937U) + aPhaseEOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aScatter, 27U)) + 14375955191735286867U;
            aOrbiterA = (((aWandererD + RotL64(aIngress, 51U)) + RotL64(aCarry, 21U)) + 880757589768436072U) + aNonceWordG;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 3U)) + 3349856625725164229U) + aNonceWordO;
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 7826309957607577207U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 8057435761214313635U;
            aOrbiterE = RotL64((aOrbiterE * 4718430712767038607U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 9565237500443303103U) + aNonceWordL;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 15893066735310588501U;
            aOrbiterD = RotL64((aOrbiterD * 8457633439171452397U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 3276844534476430842U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 6828644383891274120U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 979580351653410157U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 2815676923011504251U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 5030251870850928417U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7075653570570819253U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 13464083008377887034U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 8994560761846897590U;
            aOrbiterI = RotL64((aOrbiterI * 9892839554658865143U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 8398813387154468736U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 8136429428340910892U;
            aOrbiterA = RotL64((aOrbiterA * 3348811490733577295U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 418587250696862341U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 4111667833838312094U;
            aOrbiterG = RotL64((aOrbiterG * 860949442143849147U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 6075478294190926371U) + aNonceWordM;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 2208124955874142264U;
            aOrbiterB = RotL64((aOrbiterB * 15741988616251072075U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 4726538724576443010U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 6524078248882840425U;
            aOrbiterC = RotL64((aOrbiterC * 9784875566721689069U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 14521003220464811621U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 16916247868211621303U) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 1911638054294853877U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 18207293125461843123U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 7722279280863371124U;
            aOrbiterK = RotL64((aOrbiterK * 14303108475807941791U), 35U);
            //
            aIngress = RotL64(aOrbiterC, 23U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 52U));
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterG, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 34U) + aOrbiterE) + RotL64(aOrbiterG, 21U)) + aNonceWordB) + aPhaseEWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterD, 39U)) + aOrbiterA);
            aWandererE = aWandererE + ((RotL64(aCross, 51U) + RotL64(aOrbiterI, 57U)) + aOrbiterE);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 6U)) + aOrbiterC);
            aWandererC = aWandererC + (((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterD, 47U)) + aNonceWordN);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 10U) + aOrbiterF) + RotL64(aOrbiterD, 53U));
            aWandererH = aWandererH + ((RotL64(aIngress, 21U) + aOrbiterK) + RotL64(aOrbiterF, 19U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterD, 41U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 27U) + RotL64(aOrbiterH, 10U)) + aOrbiterE) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterH, 27U)) + aOrbiterI) + aNonceWordK);
            aWandererD = aWandererD + (((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 23U)) + aOrbiterI) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 34U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 43U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordM;
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 17869U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 19645U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 17234U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 19231U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 43U) + RotL64(aCross, 14U)) + (RotL64(aCarry, 29U) ^ RotL64(aIngress, 57U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterI = (aWandererF + RotL64(aCross, 20U)) + 8604208734152026945U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 37U)) + RotL64(aCarry, 53U)) + 1374329953253889829U;
            aOrbiterG = (aWandererA + RotL64(aIngress, 29U)) + 5779278910548228339U;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 27U)) + 17670451230882805140U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aCross, 57U)) + 8193848740764866860U) + aNonceWordF;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 3U)) + 15801168428145650104U) + aNonceWordI;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 51U)) + 2584718176087499066U;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 35U)) + 14950366247822737997U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = ((aWandererK + RotL64(aCross, 53U)) + RotL64(aCarry, 29U)) + 9779293225265670135U;
            aOrbiterA = (aWandererD + RotL64(aScatter, 13U)) + 8688968319288372383U;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 42U)) + RotL64(aCarry, 23U)) + 13665723186950342601U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 9395428688359973510U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 2152719218018108418U) ^ aNonceWordG;
            aOrbiterG = RotL64((aOrbiterG * 15271961483518392671U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 1350324137411377992U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 8729317951386057921U;
            aOrbiterH = RotL64((aOrbiterH * 6008790836417785083U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 6317310451893678411U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 10175620379041384281U;
            aOrbiterF = RotL64((aOrbiterF * 14079679617394330781U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 1203082119358827708U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 523869107818193101U;
            aOrbiterC = RotL64((aOrbiterC * 4629501113595689157U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 4028324959540432983U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 15447631947468213912U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6037306615787729185U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 14225888694733041031U) + aNonceWordH;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 11925000696281947629U;
            aOrbiterE = RotL64((aOrbiterE * 4337022940520411253U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 15015531024930608745U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 16752579225076943550U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15551083683579981439U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 2432733494869267901U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 10103430321388601485U;
            aOrbiterD = RotL64((aOrbiterD * 18372919379972432569U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 15943360147468638325U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 9782703760233558733U) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 685056980418243879U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 18345087852012669037U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 8897505040792027675U;
            aOrbiterK = RotL64((aOrbiterK * 14333687539092412967U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 7402581293947129667U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 8604208734152026945U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9965525485538037673U), 3U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterC, 37U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 44U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 39U) + RotL64(aOrbiterC, 29U)) + aOrbiterF) + aNonceWordA);
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 13U) + aOrbiterB) + RotL64(aOrbiterD, 23U)) + aNonceWordO) + aPhaseEWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 60U) + aOrbiterK) + RotL64(aOrbiterJ, 56U)) + RotL64(aCarry, 41U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 5U) + aOrbiterF) + RotL64(aOrbiterI, 39U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 3U)) + aOrbiterH) + aPhaseEWandererUpdateSaltF[((aIndex + 16U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 51U)) + aOrbiterD);
            aWandererB = aWandererB + ((RotL64(aCross, 11U) + RotL64(aOrbiterA, 47U)) + aOrbiterE);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterD, 13U)) + aOrbiterH);
            aWandererG = aWandererG + ((RotL64(aScatter, 46U) + RotL64(aOrbiterF, 37U)) + aOrbiterA);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterJ, 35U)) + aOrbiterD);
            aWandererD = aWandererD + (((RotL64(aCross, 29U) + RotL64(aOrbiterA, 58U)) + aOrbiterJ) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 46U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 3U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 23873U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24616U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24046U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((aIndex + 25160U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aIngress, 54U)) + (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 37U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 19U)) + 826930775230515406U;
            aOrbiterA = (aWandererH + RotL64(aCross, 60U)) + 5137814617363250861U;
            aOrbiterE = (aWandererE + RotL64(aScatter, 43U)) + 14761561947426681616U;
            aOrbiterF = (((aWandererA + RotL64(aIngress, 41U)) + RotL64(aCarry, 3U)) + 12773023438753662590U) + aNonceWordK;
            aOrbiterD = (((aWandererC + RotL64(aPrevious, 13U)) + RotL64(aCarry, 41U)) + 7331345852207096322U) + aNonceWordF;
            aOrbiterH = (aWandererI + RotL64(aScatter, 53U)) + 3899381212671247460U;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 51U)) + RotL64(aCarry, 19U)) + 10072004147620068599U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 3U)) + 3424585039401897560U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = ((aWandererB + RotL64(aScatter, 34U)) + 8246760141625966321U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aIngress, 27U)) + 3655992860610853290U;
            aOrbiterC = ((aWandererG + RotL64(aCross, 21U)) + 11154618022505863898U) + aNonceWordG;
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 15629361991059709973U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 10842068502278489664U) ^ aNonceWordN;
            aOrbiterE = RotL64((aOrbiterE * 17223002513104960799U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 5571312349016336686U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 589313823745748879U;
            aOrbiterH = RotL64((aOrbiterH * 1356685926549786027U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 13633457935771935260U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 12684602052812183096U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4689206269919806711U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 5711307583717354204U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 7181854170553728211U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9835601115561325911U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 1884620014396115821U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 1471516373272364262U) ^ aNonceWordL;
            aOrbiterK = RotL64((aOrbiterK * 5126319375714848029U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 742739371092077733U) + aNonceWordE;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 8075893317715227838U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11208274111743259795U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 8179547722249281263U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 15305282712174742323U;
            aOrbiterJ = RotL64((aOrbiterJ * 7951986906055462929U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 1430543231751281079U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 14585341768267283387U;
            aOrbiterI = RotL64((aOrbiterI * 313213844964269133U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 8123889986027932297U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 2081696191347150910U;
            aOrbiterC = RotL64((aOrbiterC * 4869653441012615053U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 10166788886199265936U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 15927074835525735601U;
            aOrbiterA = RotL64((aOrbiterA * 6747650218540675523U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 6997764816848988590U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 826930775230515406U;
            aOrbiterD = RotL64((aOrbiterD * 9943232461538279601U), 21U);
            //
            aIngress = RotL64(aOrbiterF, 29U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterD, 54U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterE, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 47U)) + aOrbiterF);
            aWandererK = aWandererK + (((RotL64(aCross, 50U) + RotL64(aOrbiterE, 24U)) + aOrbiterF) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 39U)) + aOrbiterA) + aNonceWordB) + aPhaseEWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterI, 37U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterB, 35U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 37U) + RotL64(aOrbiterJ, 57U)) + aOrbiterG) + RotL64(aCarry, 3U)) + aPhaseEWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 56U) + RotL64(aOrbiterI, 12U)) + aOrbiterA);
            aWandererB = aWandererB + ((RotL64(aScatter, 53U) + aOrbiterA) + RotL64(aOrbiterF, 21U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 29U)) + aOrbiterI);
            aWandererA = aWandererA + ((RotL64(aScatter, 41U) + RotL64(aOrbiterJ, 53U)) + aOrbiterE);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterI, 43U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 44U));
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererH, 41U);
            aCarry = aCarry + RotL64(aIngress, 28U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 31829U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneB[((aIndex + 31066U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31255U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((aIndex + 28383U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aPrevious, 11U)) + (RotL64(aIngress, 57U) ^ RotL64(aCarry, 36U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterA = ((aWandererD + RotL64(aIngress, 34U)) + RotL64(aCarry, 5U)) + 7075016829833562104U;
            aOrbiterB = (aWandererI + RotL64(aCross, 11U)) + 8783765886115517036U;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 5U)) + 2996723892384565829U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 51U)) + RotL64(aCarry, 13U)) + 9494134707342189476U;
            aOrbiterI = (aWandererF + RotL64(aScatter, 48U)) + 5052642981395679904U;
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 41U)) + 8766787055127962238U;
            aOrbiterD = (aWandererG + RotL64(aIngress, 27U)) + 4467211954388738079U;
            aOrbiterH = (aWandererA + RotL64(aCross, 19U)) + 8030255604633658608U;
            aOrbiterF = (((aWandererC + RotL64(aPrevious, 57U)) + 16962408063455702251U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordC;
            aOrbiterK = ((aWandererH + RotL64(aCross, 3U)) + 3768222186567699076U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aScatter, 13U)) + RotL64(aCarry, 41U)) + 14930990410207899871U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 14179761938395502502U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 1879084742719898108U;
            aOrbiterG = RotL64((aOrbiterG * 16783034788172670121U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 5535012408925981515U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 12792553516710295939U) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 8577530993755159329U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 8979253163346099252U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 5559189896063990740U;
            aOrbiterJ = RotL64((aOrbiterJ * 8832485423727331621U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 13937564337299044079U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 2393376759689394948U;
            aOrbiterD = RotL64((aOrbiterD * 2352815657830413941U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 12647519563697356479U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 10946871249960389549U;
            aOrbiterH = RotL64((aOrbiterH * 6272580371881237173U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 13376798695582123147U) + aNonceWordF;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 10958115913599631271U;
            aOrbiterF = RotL64((aOrbiterF * 18233981473003345217U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 4283914227806672773U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 910842005516235816U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6722229871617873429U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 1509644316619370324U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 165987596716078174U;
            aOrbiterE = RotL64((aOrbiterE * 13600064054240185123U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 12491315345199091186U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 5982431705686495125U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2547243804779022665U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 231183123382412440U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 2872632389683254396U;
            aOrbiterB = RotL64((aOrbiterB * 1972278820468847241U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 15259314110008210315U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 7075016829833562104U;
            aOrbiterC = RotL64((aOrbiterC * 8350093877370898869U), 11U);
            //
            aIngress = RotL64(aOrbiterG, 6U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aCross, 39U) + RotL64(aOrbiterJ, 3U)) + aOrbiterF) + aNonceWordB);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 41U) + aOrbiterG) + RotL64(aOrbiterI, 19U));
            aWandererB = aWandererB + ((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 35U)) + aOrbiterJ);
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 36U) + aOrbiterG) + RotL64(aOrbiterF, 53U)) + aNonceWordJ) + aPhaseEWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 27U) + aOrbiterJ) + RotL64(aOrbiterK, 24U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 53U) + aOrbiterJ) + RotL64(aOrbiterD, 11U));
            aWandererF = aWandererF + ((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 43U)) + aOrbiterF);
            aWandererD = aWandererD ^ ((((RotL64(aCross, 13U) + RotL64(aOrbiterF, 21U)) + aOrbiterH) + aNonceWordL) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 51U) + RotL64(aOrbiterA, 37U)) + aOrbiterI) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 18U) + RotL64(aOrbiterD, 57U)) + aOrbiterE);
            aWandererA = aWandererA + (((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 46U)) + aOrbiterH) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 26U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordK);
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

void TwistExpander_Bowling_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xC836552223A58343ULL + 0x88920F24CDFDDFB4ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xC08DA1C2942E61ABULL + 0x8C773CD80FD46634ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC82ED6FAD2A2EFD9ULL + 0xF72103DCC9A8D84EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x87E019508AFB96D1ULL + 0xEB0EE1CD805211C2ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x8F4383B27D0D914BULL + 0xDC193EEF09425A4AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA83F94FC4D0F8D65ULL + 0x9A0D0B413B955C88ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x99571D0B138903E5ULL + 0x84B79D8FBDDAFA6FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE05D46275A6A0695ULL + 0x831591CEAE3DB47AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xB99CCD49CDBFC58FULL + 0xFB9EAC48282CB135ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x8B07D54E489B7451ULL + 0xB4129BF27F34B731ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xD772AB692559E429ULL + 0xD09E96CDC031D328ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xAE1FF00110D7EAB9ULL + 0xCF1267D5AEABCB61ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x95BCCE6E796C1389ULL + 0xE2BE9411F9D42D69ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xD01FF31E609AF1CBULL + 0xD73F085E8BF15B78ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x8BF214C9552898C9ULL + 0xA4D865A75FA38786ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xF6A84CE1524E8D4FULL + 0x8543E5DED7C0C7B8ULL);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 4930U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((aIndex + 3587U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 4289U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneA[((aIndex + 2218U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCross, 23U)) + (RotL64(aCarry, 40U) ^ RotL64(aPrevious, 53U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterJ = (aWandererE + RotL64(aScatter, 39U)) + 8866844335448071821U;
            aOrbiterI = (aWandererB + RotL64(aCross, 19U)) + 15159698739856430085U;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 60U)) + RotL64(aCarry, 51U)) + 9582805772989594633U;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 51U)) + 1438538239931588373U) + aNonceWordK;
            aOrbiterA = (((aWandererG + RotL64(aIngress, 53U)) + 10862044156620436139U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = (aWandererJ + RotL64(aScatter, 27U)) + 13682173320058164615U;
            aOrbiterB = (((aWandererC + RotL64(aPrevious, 11U)) + RotL64(aCarry, 5U)) + 8351013291045977592U) + aNonceWordM;
            aOrbiterK = (aWandererD + RotL64(aCross, 13U)) + 15777857431516633916U;
            aOrbiterF = (aWandererI + RotL64(aPrevious, 3U)) + 16178966745333885377U;
            aOrbiterH = (((aWandererA + RotL64(aCross, 57U)) + RotL64(aCarry, 19U)) + 9031889187993001617U) + aPhaseFOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = (aWandererF + RotL64(aIngress, 30U)) + 6308472367425865347U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 642109145903321046U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 9186268569255318035U;
            aOrbiterC = RotL64((aOrbiterC * 10714674348507516749U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 6091345356803675860U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 13218507921880873749U;
            aOrbiterD = RotL64((aOrbiterD * 15415157927185637717U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 4266652275234474616U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 4391422098164506195U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17634679403195085867U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 5160682323243635577U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 10351728852161347404U) ^ aNonceWordD;
            aOrbiterE = RotL64((aOrbiterE * 11105410036471745951U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 3950932176454814023U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 9536466386833427441U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 18064984243491293435U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 9927425919978776529U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 6819384090527481081U;
            aOrbiterF = RotL64((aOrbiterF * 18032965969184368561U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 1646274931424218507U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 16166524473976135097U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11672192658072663849U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 11252501968059485262U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 16847854447987609067U;
            aOrbiterI = RotL64((aOrbiterI * 6326299154627028295U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 16723218285355036446U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 13870211254243048975U;
            aOrbiterA = RotL64((aOrbiterA * 10203222183774624097U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 11401147367366049493U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 4266628469244269926U) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 2409934496621365221U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 11578385782347296942U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 8866844335448071821U;
            aOrbiterH = RotL64((aOrbiterH * 6456956795450036515U), 37U);
            //
            aIngress = RotL64(aOrbiterA, 29U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (RotL64(aOrbiterE, 34U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterG, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterB, 4U)) + aOrbiterC);
            aWandererE = aWandererE + (((RotL64(aCross, 54U) + aOrbiterJ) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 11U) + aOrbiterD) + RotL64(aOrbiterA, 57U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterF, 19U)) + RotL64(aCarry, 37U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 39U) + aOrbiterH) + RotL64(aOrbiterI, 23U)) + aPhaseFWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 41U) + RotL64(aOrbiterH, 29U)) + aOrbiterE);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 13U)) + aOrbiterK);
            aWandererI = aWandererI + (((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterF, 11U)) + aNonceWordI);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 43U)) + aOrbiterJ);
            aWandererG = aWandererG + ((RotL64(aIngress, 30U) + aOrbiterG) + RotL64(aOrbiterK, 51U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 23U) + aOrbiterD) + RotL64(aOrbiterH, 38U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 44U));
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + RotL64(aWandererA, 12U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ aNonceWordL;
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8581U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 6653U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 9828U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7278U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 24U) ^ RotL64(aCross, 37U)) + (RotL64(aIngress, 57U) ^ RotL64(aCarry, 11U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = ((aWandererE + RotL64(aScatter, 12U)) + RotL64(aCarry, 29U)) + 9630214189402543339U;
            aOrbiterA = (((aWandererD + RotL64(aIngress, 43U)) + 4072576573737526819U) + aPhaseFOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1]) + aNonceWordF;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 27U)) + 15994787452709618869U;
            aOrbiterF = (aWandererI + RotL64(aCross, 37U)) + 6403240137132259482U;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 53U)) + 10229266900170507720U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aIngress, 5U)) + 5025294577989748989U;
            aOrbiterH = (((aWandererK + RotL64(aPrevious, 3U)) + RotL64(aCarry, 21U)) + 16696461238217956883U) + aNonceWordJ;
            aOrbiterJ = (aWandererA + RotL64(aCross, 14U)) + 9878318855341719119U;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 41U)) + 16086635438116177346U;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 23U)) + 12295437783084203730U) + aNonceWordE;
            aOrbiterC = ((aWandererG + RotL64(aCross, 35U)) + RotL64(aCarry, 39U)) + 7681150419912842402U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 2639104034287637448U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 12298170009332243573U;
            aOrbiterE = RotL64((aOrbiterE * 9397919591171238575U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 3485932317267669626U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 16569551670038752475U;
            aOrbiterA = RotL64((aOrbiterA * 8139802826402217631U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 4448490103784103954U) + aNonceWordM;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 14510534073046885941U;
            aOrbiterD = RotL64((aOrbiterD * 7777192047386438305U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 4286195398675733451U) + aNonceWordD;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 15790355933840266463U;
            aOrbiterH = RotL64((aOrbiterH * 13342257823027075501U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 6362891510370156055U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 15121822034579983174U;
            aOrbiterG = RotL64((aOrbiterG * 7268045994574844937U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 13817341015719915628U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 14113474087906143783U;
            aOrbiterI = RotL64((aOrbiterI * 12838910141533126059U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 9988301252236121106U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 11287477288382171758U;
            aOrbiterF = RotL64((aOrbiterF * 4979297247881426383U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 9491727010910328644U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 7961202721830514030U;
            aOrbiterB = RotL64((aOrbiterB * 16300364540313620767U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 10058066852293995222U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 541563830282750968U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1516823517052019845U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 7791201128863372861U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 8334318157449352359U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2924838607279239375U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 6861081455774799715U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 9630214189402543339U;
            aOrbiterC = RotL64((aOrbiterC * 10837610668580336781U), 47U);
            //
            aIngress = RotL64(aOrbiterJ, 37U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 26U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + RotL64(aOrbiterC, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 34U) + aOrbiterG) + RotL64(aOrbiterE, 48U));
            aWandererK = aWandererK + (((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 23U)) + aOrbiterJ) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 41U) + aOrbiterK) + RotL64(aOrbiterI, 19U));
            aWandererI = aWandererI + (((RotL64(aIngress, 37U) + aOrbiterF) + RotL64(aOrbiterC, 43U)) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterD, 5U)) + aOrbiterJ);
            aWandererF = aWandererF + ((RotL64(aIngress, 51U) + aOrbiterI) + RotL64(aOrbiterG, 37U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 30U) + aOrbiterE) + RotL64(aOrbiterF, 11U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 53U) + RotL64(aOrbiterD, 60U)) + aOrbiterC);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 11U) + aOrbiterG) + RotL64(aOrbiterB, 21U));
            aWandererC = aWandererC + ((((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterD, 29U)) + aNonceWordC) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterH, 51U)) + aOrbiterC) + aNonceWordI);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + (RotL64(aWandererE, 56U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 41U);
            aCarry = aCarry + RotL64(aIngress, 38U);
            aCarry = aCarry ^ aNonceWordB;
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12821U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15705U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 16260U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12431U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCarry, 41U)) ^ (RotL64(aCross, 4U) + RotL64(aPrevious, 19U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = (aWandererK + RotL64(aIngress, 41U)) + 3650233661228036955U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 54U)) + RotL64(aCarry, 35U)) + 11607036400067735729U;
            aOrbiterD = (aWandererE + RotL64(aCross, 21U)) + 3899614406903883035U;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 3U)) + RotL64(aCarry, 53U)) + 8159156925629965143U;
            aOrbiterI = (aWandererA + RotL64(aIngress, 43U)) + 7148903913967261270U;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 12U)) + 9161665622287517848U) + aNonceWordP;
            aOrbiterG = ((aWandererG + RotL64(aCross, 27U)) + RotL64(aCarry, 5U)) + 2981535013474059469U;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 57U)) + 15812469008200319549U) + aPhaseFOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (aWandererD + RotL64(aScatter, 51U)) + 14687469489893270300U;
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 35U)) + 6025209349511417063U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aIngress, 47U)) + 12964750392311112676U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 6572355895765394340U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 3542300121890027981U;
            aOrbiterD = RotL64((aOrbiterD * 11201491178181273935U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 6477175684045398359U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 1081388388827929314U;
            aOrbiterA = RotL64((aOrbiterA * 8752188637514143529U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 13754328481584620771U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 3684673342659575917U;
            aOrbiterC = RotL64((aOrbiterC * 6139923312873039143U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6542045150319909445U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 5352102692424060388U) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 7385758355501860261U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 9110100774657340354U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 2813273684436269057U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10468759062594022273U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 5860425751137403755U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 1598622981888978548U;
            aOrbiterH = RotL64((aOrbiterH * 651816500461718345U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 14710305692377606725U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 16280545617802383463U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12541767206978802063U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 6849565243667718750U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 12152381961996750050U;
            aOrbiterK = RotL64((aOrbiterK * 11185935780063403807U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 1318947876257794796U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 5447559252769140391U;
            aOrbiterG = RotL64((aOrbiterG * 13683733413554766327U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 2766869582494246454U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 15757729967222729304U;
            aOrbiterF = RotL64((aOrbiterF * 1858683399257513171U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 13063432816787882618U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 3650233661228036955U;
            aOrbiterB = RotL64((aOrbiterB * 16230564672533821641U), 29U);
            //
            aIngress = RotL64(aOrbiterH, 53U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 6U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 51U) + aOrbiterK) + RotL64(aOrbiterJ, 43U)) + aNonceWordD);
            aWandererH = aWandererH + ((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterI, 37U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 23U)) + aOrbiterH);
            aWandererA = aWandererA + ((RotL64(aCross, 41U) + aOrbiterD) + RotL64(aOrbiterG, 26U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 3U)) + aOrbiterE);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 10U) + RotL64(aOrbiterJ, 19U)) + aOrbiterG) + RotL64(aCarry, 53U)) + aPhaseFWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 5U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aCross, 47U) + RotL64(aOrbiterF, 57U)) + aOrbiterC) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 41U)) + aOrbiterA) + aNonceWordH);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 21U) + aOrbiterK) + RotL64(aOrbiterI, 35U)) + aPhaseFWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 12U) + RotL64(aOrbiterK, 12U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 58U));
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 41U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + RotL64(aWandererA, 38U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 19197U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneB[((aIndex + 16395U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18775U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20701U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aPrevious, 51U)) + (RotL64(aIngress, 10U) ^ RotL64(aCarry, 27U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterJ = ((aWandererI + RotL64(aCross, 50U)) + 14624277139785904404U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = (aWandererD + RotL64(aIngress, 13U)) + 6966977309498165611U;
            aOrbiterG = (aWandererF + RotL64(aScatter, 35U)) + 205536824352530761U;
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 39U)) + 16629575265808255692U;
            aOrbiterA = (aWandererK + RotL64(aIngress, 29U)) + 596881340147972746U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 27U)) + RotL64(aCarry, 5U)) + 11944412799107412650U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 37U)) + RotL64(aCarry, 27U)) + 4615021315668210206U;
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 4U)) + 8497630055977606216U) + aNonceWordP;
            aOrbiterK = ((aWandererB + RotL64(aScatter, 11U)) + 11131601107309336885U) + aPhaseFOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aPrevious, 41U)) + 5935883479805510099U;
            aOrbiterC = ((aWandererC + RotL64(aIngress, 21U)) + RotL64(aCarry, 51U)) + 15629346719765798174U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 5279128339113651273U) + aNonceWordK;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 16778365912440331821U;
            aOrbiterG = RotL64((aOrbiterG * 705421028266789241U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 16003052937645491524U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 6723226158737614764U;
            aOrbiterA = RotL64((aOrbiterA * 16690657664909260573U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 9785784358981219543U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 10055457337292292710U) ^ aNonceWordG;
            aOrbiterE = RotL64((aOrbiterE * 17919129940751761111U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 11779163108592974175U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 1177999477942202687U;
            aOrbiterI = RotL64((aOrbiterI * 13475069421684114643U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 9190694445141492214U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 15605342360346353457U;
            aOrbiterB = RotL64((aOrbiterB * 14547769706392595647U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 14877565450677523492U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 1074095623308025684U;
            aOrbiterK = RotL64((aOrbiterK * 7884068939436891093U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 12803174154216941583U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 8813356463693637033U;
            aOrbiterD = RotL64((aOrbiterD * 4898237214617563167U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 6063909634038581414U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 15112191502834052566U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6780741782103553485U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 13926459034757240311U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 4324555954703597591U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 18068922072149745351U), 3U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterC) + 7183063131331255506U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordI;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 18072787091203847052U;
            aOrbiterH = RotL64((aOrbiterH * 12530396154012878153U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 10143386327707219710U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 14624277139785904404U;
            aOrbiterF = RotL64((aOrbiterF * 12100828883424264587U), 13U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterF, 11U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 39U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + (RotL64(aOrbiterD, 48U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 43U) + aOrbiterH) + RotL64(aOrbiterI, 23U)) + aNonceWordH);
            aWandererH = aWandererH + ((RotL64(aCross, 18U) + RotL64(aOrbiterB, 6U)) + aOrbiterJ);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 37U)) + aOrbiterJ);
            aWandererI = aWandererI + ((RotL64(aIngress, 53U) + aOrbiterK) + RotL64(aOrbiterA, 41U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 27U)) + aOrbiterG);
            aWandererB = aWandererB + (((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 29U)) + aOrbiterD) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterF, 53U)) + aOrbiterC) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 41U) + aOrbiterB) + RotL64(aOrbiterH, 39U)) + aNonceWordF);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 26U) + RotL64(aOrbiterH, 14U)) + aOrbiterF);
            aWandererC = aWandererC + (((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 19U)) + aOrbiterK) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ ((((RotL64(aCross, 37U) + RotL64(aOrbiterC, 11U)) + aOrbiterD) + aNonceWordL) + aPhaseFWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 46U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 60U));
            aCarry = aCarry + RotL64(aWandererI, 53U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordJ);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22358U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24447U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24002U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((aIndex + 26896U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 27U) + RotL64(aCross, 57U)) ^ (RotL64(aPrevious, 44U) ^ RotL64(aCarry, 11U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = ((((aWandererC + RotL64(aScatter, 41U)) + RotL64(aCarry, 47U)) + 13333509828310369865U) + aPhaseFOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1]) + aNonceWordP;
            aOrbiterF = (((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 35U)) + 7645352517103840797U) + aNonceWordJ;
            aOrbiterB = ((aWandererI + RotL64(aCross, 5U)) + 5310766306660062655U) + aPhaseFOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aPrevious, 51U)) + 5165635069832352932U;
            aOrbiterK = (((aWandererG + RotL64(aCross, 14U)) + RotL64(aCarry, 11U)) + 15684141764734281849U) + aNonceWordL;
            aOrbiterE = (aWandererB + RotL64(aIngress, 27U)) + 3327963374225061738U;
            aOrbiterC = (aWandererH + RotL64(aScatter, 29U)) + 8625811794878848871U;
            aOrbiterD = (aWandererK + RotL64(aPrevious, 3U)) + 7598657468430485291U;
            aOrbiterH = (aWandererE + RotL64(aIngress, 37U)) + 2881171216276746485U;
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 10U)) + 10237691227222918101U;
            aOrbiterG = (aWandererA + RotL64(aPrevious, 23U)) + 6419254255884834497U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 4238455444646479956U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 14936613353493061492U;
            aOrbiterB = RotL64((aOrbiterB * 3544216916806292273U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 15324699725208372627U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 9506640480601832011U;
            aOrbiterE = RotL64((aOrbiterE * 12819564111348390227U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 3709149613660215641U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterC) ^ 1724290199312754307U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 12597580418257897965U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 13191172833570139194U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 3686087945377837886U;
            aOrbiterJ = RotL64((aOrbiterJ * 10883609557429936283U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 10418330386245397022U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 5383531313632347245U;
            aOrbiterI = RotL64((aOrbiterI * 2987755379396160073U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 7414716553072652212U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 11301761123966206201U;
            aOrbiterA = RotL64((aOrbiterA * 1546727321088592187U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 8570229732236388847U) + aNonceWordF;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 8773754460060264773U;
            aOrbiterC = RotL64((aOrbiterC * 3251360788932563495U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 13636929800504199371U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 5486599841558573720U) ^ aNonceWordE;
            aOrbiterH = RotL64((aOrbiterH * 2867914211589815153U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 13277541451512422776U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 10409779509190185921U;
            aOrbiterG = RotL64((aOrbiterG * 1926650154570961573U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 7268295836403414306U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 13815969853235433830U;
            aOrbiterF = RotL64((aOrbiterF * 11603750346752441535U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 9353249174240162324U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 13333509828310369865U;
            aOrbiterK = RotL64((aOrbiterK * 10381405217943841655U), 51U);
            //
            aIngress = RotL64(aOrbiterB, 35U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterK, 26U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + (RotL64(aOrbiterH, 39U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterI, 29U)) + RotL64(aCarry, 5U)) + aPhaseFWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterJ, 5U)) + aOrbiterD);
            aWandererD = aWandererD + ((RotL64(aPrevious, 6U) + RotL64(aOrbiterH, 22U)) + aOrbiterK);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterB, 27U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 3U)) + aOrbiterC);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 27U) + aOrbiterA) + RotL64(aOrbiterG, 47U));
            aWandererH = aWandererH + (((RotL64(aCross, 40U) + aOrbiterD) + RotL64(aOrbiterK, 35U)) + aNonceWordD);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 21U) + aOrbiterE) + RotL64(aOrbiterG, 39U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterE, 54U)) + aOrbiterH) + RotL64(aCarry, 51U)) + aPhaseFWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 53U) + aOrbiterF) + RotL64(aOrbiterK, 41U));
            aWandererG = aWandererG + (((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 13U)) + aOrbiterE) + aNonceWordI);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 24U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 60U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 37U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30106U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneB[((aIndex + 32226U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32159U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((aIndex + 30192U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 53U)) + (RotL64(aCross, 4U) ^ RotL64(aPrevious, 23U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterJ = (((aWandererI + RotL64(aPrevious, 19U)) + RotL64(aCarry, 5U)) + 13499155707765393469U) + aNonceWordC;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 5U)) + RotL64(aCarry, 53U)) + 3740324981823726185U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 51U)) + 5470765363949735652U) + aNonceWordD;
            aOrbiterI = (aWandererG + RotL64(aCross, 3U)) + 3446436171274452326U;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 57U)) + 1778929412631211933U;
            aOrbiterB = (aWandererK + RotL64(aPrevious, 60U)) + 14666308799855220954U;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 41U)) + 4548410236791175055U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = (((aWandererD + RotL64(aCross, 43U)) + RotL64(aCarry, 19U)) + 5829739767694190372U) + aPhaseFOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aPrevious, 21U)) + 14319231414903675748U;
            aOrbiterK = ((aWandererC + RotL64(aCross, 37U)) + 1513851750246111405U) + aNonceWordB;
            aOrbiterF = (aWandererF + RotL64(aScatter, 14U)) + 1685620217748986019U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 16284162182006054402U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 6271539598462003309U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13923286694131331137U), 53U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterI) + 12669312437565969473U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordI;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 11894755313393001665U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12556759675372354075U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 6315983824634946566U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 17106616474222892782U;
            aOrbiterB = RotL64((aOrbiterB * 167205520766791073U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 13350266700180455548U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 4608846311203767162U;
            aOrbiterG = RotL64((aOrbiterG * 2504857468837437365U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 14195866746143604365U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 7917977448256795054U;
            aOrbiterD = RotL64((aOrbiterD * 5927771378657284557U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 10707336923305131629U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 17122696159336995392U;
            aOrbiterH = RotL64((aOrbiterH * 13953518568670659191U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 5182322763573586116U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 6503754948502556246U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14749002194140663519U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 14907832047832987341U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 6258064448676621346U) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 4407960312705621487U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 1180234574888070795U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 801686887651085881U;
            aOrbiterJ = RotL64((aOrbiterJ * 433981853631548041U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 11810494591997709554U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 9343740505955858127U;
            aOrbiterE = RotL64((aOrbiterE * 8733378485648720323U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 12816829575386720695U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 13499155707765393469U;
            aOrbiterI = RotL64((aOrbiterI * 9937924703928730369U), 13U);
            //
            aIngress = RotL64(aOrbiterH, 27U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 18U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterG, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 39U) + aOrbiterD) + RotL64(aOrbiterH, 3U));
            aWandererC = aWandererC + (((RotL64(aScatter, 30U) + aOrbiterA) + RotL64(aOrbiterG, 18U)) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterC, 41U)) + aNonceWordA);
            aWandererB = aWandererB + (((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterF, 51U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((RotL64(aCross, 51U) + aOrbiterG) + RotL64(aOrbiterF, 11U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterE, 6U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 46U) + aOrbiterF) + RotL64(aOrbiterJ, 53U)) + aPhaseFWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterE, 39U)) + aOrbiterH);
            aWandererE = aWandererE + (((RotL64(aCross, 43U) + RotL64(aOrbiterI, 21U)) + aOrbiterG) + aNonceWordF);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterK, 37U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 42U) ^ aWandererI);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 27U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = aCarry ^ aNonceWordM;
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

void TwistExpander_Bowling_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xFE9E36173C5A506DULL + 0xD4E09402E290CF40ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xDF7A942B3E558B9FULL + 0xA73C646E08BF4A47ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x8BBBFB8264D79365ULL + 0xF5898D91E357A339ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x842E147A614CCC7BULL + 0x914C27521B74FD09ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xC4C52F1FFA1C153DULL + 0x8ACC210D608623D7ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x993468364D3337A7ULL + 0xA95F86075BDFDADDULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xE89E11397C1CD2B5ULL + 0xC63E8EACB4A80A4DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xCC0E20BFEE19710BULL + 0x9B80CA852061FE7AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xB805987A1EDD8145ULL + 0xEF6A8A54388A5566ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x82898707577E8AD1ULL + 0x8651E874EFE0239CULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xFEC24C908EDF8909ULL + 0x90AC1D67A2D96851ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xDB4EA531DE4845D7ULL + 0x8D2A41E6A957C197ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xA68C4751FAB6964BULL + 0xA9386F8670384326ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xB0CEBF5C8EFC2E37ULL + 0xE15745F3581C94ACULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xA7E67CAF382C54D7ULL + 0x98ECE39FAA67C8C2ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xE4111CA1F57D285FULL + 0xED4A3B18FDDE2F2FULL);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 3393U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneC[((aIndex + 4127U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 2626U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 693U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 37U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCarry, 24U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = (((aWandererH + RotL64(aIngress, 39U)) + RotL64(aCarry, 53U)) + 1557680213571812384U) + aNonceWordB;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 29U)) + 7387349725778021121U;
            aOrbiterG = (aWandererG + RotL64(aCross, 37U)) + 15379264067601586976U;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 43U)) + RotL64(aCarry, 27U)) + 3730195724576043708U;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 13U)) + RotL64(aCarry, 57U)) + 9637070085323827066U;
            aOrbiterD = (aWandererA + RotL64(aCross, 19U)) + 1170865717363676184U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 50U)) + 2750833653175252030U) + aPhaseFOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aIngress, 23U)) + 15118992811225568305U;
            aOrbiterF = (aWandererK + RotL64(aCross, 41U)) + 4974092922102988451U;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 35U)) + 10625719096296719514U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aIngress, 56U)) + 855167122475471865U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 11322911068958340262U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 4334591909425429835U) ^ aNonceWordL;
            aOrbiterG = RotL64((aOrbiterG * 10059025861172038183U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 14263701737208936392U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 678723206735649084U;
            aOrbiterD = RotL64((aOrbiterD * 10823239851733632227U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 15652053114252065230U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 1705225940224061401U;
            aOrbiterE = RotL64((aOrbiterE * 3626023093533713579U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6826394665732900206U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 11902946775066981141U;
            aOrbiterK = RotL64((aOrbiterK * 18300629262162694137U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 9802212958998591310U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 14001358545610206524U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13172645840788327099U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 4299184726135884309U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 7288757011999872416U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16806027820468277393U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 233801262480580205U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 14208660347238680268U;
            aOrbiterJ = RotL64((aOrbiterJ * 6299693448313154603U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 9217797359740446104U) + aNonceWordG;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 18165073197136050838U) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 11677479094709512887U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 9101905235436427482U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 2884224555227870272U;
            aOrbiterI = RotL64((aOrbiterI * 12085235281782370391U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 13118509728421714433U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 1385390888603164704U;
            aOrbiterA = RotL64((aOrbiterA * 6927424835779289199U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 9621084561183039538U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 1557680213571812384U;
            aOrbiterH = RotL64((aOrbiterH * 3202327770291862207U), 53U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 36U);
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + RotL64(aOrbiterA, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 13U) + aOrbiterI) + RotL64(aOrbiterH, 10U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 60U) + RotL64(aOrbiterA, 23U)) + aOrbiterG);
            aWandererE = aWandererE ^ ((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterG, 53U));
            aWandererI = aWandererI + (((RotL64(aIngress, 39U) + RotL64(aOrbiterC, 35U)) + aOrbiterA) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterH, 3U));
            aWandererB = aWandererB + (((RotL64(aIngress, 5U) + RotL64(aOrbiterI, 27U)) + aOrbiterE) + aNonceWordD);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterD, 18U)) + aOrbiterC);
            aWandererA = aWandererA + (((RotL64(aPrevious, 20U) + aOrbiterJ) + RotL64(aOrbiterG, 37U)) + aNonceWordK);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 51U) + aOrbiterI) + RotL64(aOrbiterF, 43U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aCross, 11U) + aOrbiterB) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 19U)) + aPhaseFWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterH, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 58U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 54U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 6568U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 5507U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 10086U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 7761U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCross, 34U)) + (RotL64(aIngress, 19U) ^ RotL64(aCarry, 53U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = (((aWandererK + RotL64(aScatter, 60U)) + RotL64(aCarry, 5U)) + 12136097566601676613U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = (aWandererB + RotL64(aCross, 37U)) + 7969431322248040056U;
            aOrbiterG = (aWandererE + RotL64(aPrevious, 57U)) + 10530676021510553889U;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 39U)) + RotL64(aCarry, 21U)) + 8740777303075445264U;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 46U)) + 13249434169895564739U;
            aOrbiterB = (((aWandererH + RotL64(aCross, 43U)) + RotL64(aCarry, 41U)) + 15529577005925628472U) + aNonceWordL;
            aOrbiterC = (aWandererF + RotL64(aIngress, 23U)) + 344627093687331562U;
            aOrbiterF = (aWandererD + RotL64(aScatter, 27U)) + 8824277416519988893U;
            aOrbiterE = ((aWandererA + RotL64(aCross, 51U)) + 5636276438449709875U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = (aWandererI + RotL64(aScatter, 53U)) + 2079413361031851552U;
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 3U)) + 7807998179168655561U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 13589392896232029112U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 10733011474804473996U;
            aOrbiterG = RotL64((aOrbiterG * 361749145931578805U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 15934162328347805968U) + aNonceWordA;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 7573511217796245232U;
            aOrbiterJ = RotL64((aOrbiterJ * 10694563909931636155U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 4828475187337891975U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 13284974329890393113U;
            aOrbiterD = RotL64((aOrbiterD * 10831075817642374287U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 13173869918669643112U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 15841507674783398167U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15632933198136963277U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 14168272451055700516U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 11134471485501999898U;
            aOrbiterE = RotL64((aOrbiterE * 8019507184494591705U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 2611858916687822610U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 17863271539727513641U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4987884722174985677U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 8874401993454249066U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 5131480593493950665U;
            aOrbiterA = RotL64((aOrbiterA * 8585874663602346121U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 9366563022381918996U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 7890729519928340296U;
            aOrbiterB = RotL64((aOrbiterB * 11428572374057899517U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 131774386529223292U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 4108356674478240148U;
            aOrbiterF = RotL64((aOrbiterF * 2492753294539081613U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 7651738365157869789U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 2745458108574051004U;
            aOrbiterK = RotL64((aOrbiterK * 2175955806036373729U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 10492013124307434604U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 12136097566601676613U;
            aOrbiterH = RotL64((aOrbiterH * 13128652803485742119U), 13U);
            //
            aIngress = RotL64(aOrbiterB, 27U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 10U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 36U) + aOrbiterF) + RotL64(aOrbiterI, 30U)) + aNonceWordK);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterI, 21U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 29U) + aOrbiterA) + RotL64(aOrbiterF, 5U)) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 47U)) + aOrbiterB);
            aWandererA = aWandererA + ((RotL64(aCross, 41U) + aOrbiterI) + RotL64(aOrbiterE, 41U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 53U) + aOrbiterG) + RotL64(aOrbiterI, 23U)) + aNonceWordI);
            aWandererF = aWandererF + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterG, 3U)) + aOrbiterJ);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterH, 38U)) + aNonceWordC);
            aWandererG = aWandererG + (((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterE, 35U)) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 4U) + RotL64(aOrbiterG, 13U)) + aOrbiterD) + aPhaseFWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 13U) + aOrbiterB) + RotL64(aOrbiterK, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 46U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 19U);
            aCarry = aCarry + RotL64(aIngress, 38U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordA);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 14588U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 12802U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 11759U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneC[((aIndex + 13135U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aIngress, 11U)) + (RotL64(aCarry, 30U) ^ RotL64(aPrevious, 43U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = (aWandererA + RotL64(aScatter, 60U)) + 18302975933754610273U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 47U)) + 16736972646771456082U) + aNonceWordF;
            aOrbiterB = (aWandererI + RotL64(aPrevious, 53U)) + 17389406266488137442U;
            aOrbiterJ = (((aWandererC + RotL64(aIngress, 43U)) + RotL64(aCarry, 51U)) + 5252511566486165539U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aScatter, 51U)) + 5730715427422747640U;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 19U)) + RotL64(aCarry, 57U)) + 6412695646456045825U;
            aOrbiterA = (aWandererJ + RotL64(aCross, 13U)) + 9539701605708994494U;
            aOrbiterH = (aWandererD + RotL64(aIngress, 37U)) + 18355107116412945722U;
            aOrbiterK = (((aWandererH + RotL64(aCross, 35U)) + RotL64(aCarry, 41U)) + 11735742491750132942U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aIngress, 58U)) + 12363819388562658842U;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 11U)) + 5861430292304371543U) + aNonceWordC;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 15027487084595017708U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 7012850020745791926U;
            aOrbiterB = RotL64((aOrbiterB * 15952928839355613939U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 11904871669287886120U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 11199760114477343208U;
            aOrbiterE = RotL64((aOrbiterE * 7156374911847525867U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 3856004502263742700U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 3705931243173921893U;
            aOrbiterD = RotL64((aOrbiterD * 10334871178498711485U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 12305785390539209389U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 18057980996551978823U;
            aOrbiterG = RotL64((aOrbiterG * 4850564181113470859U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 3229431819292153014U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 2994716629242460094U;
            aOrbiterH = RotL64((aOrbiterH * 1029427328395257917U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9796307843453735512U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 2957260393651252432U;
            aOrbiterI = RotL64((aOrbiterI * 7261055869794739609U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 4060469664218866340U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 17462081697889685330U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7712009170974461225U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 13638660073917821172U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 15202349592659062565U;
            aOrbiterJ = RotL64((aOrbiterJ * 4514326257446024301U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 12071949111168967041U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 11930843273199806728U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 16229663295689525137U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 11294220104731500296U) + aNonceWordL;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 440743185210586759U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14810195235168807229U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 8514240764798061804U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 18302975933754610273U;
            aOrbiterF = RotL64((aOrbiterF * 1972439346780950873U), 47U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterA, 44U);
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 20U));
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aCross, 26U) + RotL64(aOrbiterD, 46U)) + aOrbiterI) + aPhaseFWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterH, 21U)) + aOrbiterA) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 53U) + aOrbiterJ) + RotL64(aOrbiterC, 5U)) + aNonceWordP);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 37U) + RotL64(aOrbiterI, 53U)) + aOrbiterF);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 28U) + aOrbiterF) + RotL64(aOrbiterK, 48U)) + aPhaseFWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 23U) + aOrbiterA) + RotL64(aOrbiterD, 43U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 39U) + aOrbiterG) + RotL64(aOrbiterH, 39U));
            aWandererF = aWandererF + (((RotL64(aCross, 5U) + RotL64(aOrbiterA, 23U)) + aOrbiterF) + RotL64(aCarry, 37U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterE, 13U)) + aOrbiterH);
            aWandererC = aWandererC + ((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterB, 51U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterD, 35U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 6U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 41U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 18952U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 18957U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 20777U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 18822U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aIngress, 53U)) ^ (RotL64(aPrevious, 14U) ^ RotL64(aCarry, 27U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = ((aWandererD + RotL64(aCross, 37U)) + RotL64(aCarry, 53U)) + 15045917390223766480U;
            aOrbiterC = (((aWandererF + RotL64(aPrevious, 3U)) + RotL64(aCarry, 47U)) + 10763054007033668758U) + aNonceWordK;
            aOrbiterF = (aWandererC + RotL64(aIngress, 27U)) + 13190170142593666607U;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 48U)) + 9657025731441167065U) + aPhaseFOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aIngress, 39U)) + 11433367178975954211U;
            aOrbiterK = ((aWandererG + RotL64(aCross, 35U)) + 17904920143996810366U) + aNonceWordP;
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 51U)) + 3244383020512113283U) + aNonceWordM;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 5U)) + 6538815775171139091U;
            aOrbiterD = (aWandererE + RotL64(aCross, 13U)) + 7195368312757976343U;
            aOrbiterH = ((aWandererK + RotL64(aScatter, 10U)) + RotL64(aCarry, 39U)) + 18134430713910279374U;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 19U)) + 6571776588427107976U) + aPhaseFOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 11830778129647517758U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 9793702760907767365U;
            aOrbiterF = RotL64((aOrbiterF * 4096246227968677179U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 2287235876793192036U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 8951959188326141794U;
            aOrbiterI = RotL64((aOrbiterI * 9968356718110753845U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 7583061790273240157U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 3571364625022806085U;
            aOrbiterK = RotL64((aOrbiterK * 6238360922735480669U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 13869345563551689212U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 277480328952975002U;
            aOrbiterJ = RotL64((aOrbiterJ * 1057564597096163085U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 4983735092494677578U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 9490022869381030928U;
            aOrbiterB = RotL64((aOrbiterB * 12926352917961703123U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 7928039573014765566U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 6504190875809407084U;
            aOrbiterD = RotL64((aOrbiterD * 14648214826494826711U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 2787985600176307413U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 16308785053443116826U) ^ aNonceWordD;
            aOrbiterH = RotL64((aOrbiterH * 17867565986311256691U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 12788128335006767824U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 1187040019537798339U;
            aOrbiterE = RotL64((aOrbiterE * 10834905007658184183U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 10771230162770496645U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 6542421559654716320U;
            aOrbiterG = RotL64((aOrbiterG * 16829492790597069373U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 702458690970201679U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 2806140783487813070U;
            aOrbiterC = RotL64((aOrbiterC * 7415398198842270381U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 950611302199732036U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 15045917390223766480U;
            aOrbiterA = RotL64((aOrbiterA * 9358017420417979347U), 21U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterA, 11U);
            aIngress = aIngress + (RotL64(aOrbiterK, 20U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 51U));
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterC, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterJ, 37U));
            aWandererB = aWandererB + ((RotL64(aScatter, 47U) + aOrbiterC) + RotL64(aOrbiterE, 29U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 3U)) + aOrbiterH);
            aWandererH = aWandererH + (((RotL64(aIngress, 41U) + RotL64(aOrbiterE, 27U)) + aOrbiterK) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 30U) + aOrbiterJ) + RotL64(aOrbiterB, 47U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterD, 58U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterE, 5U)) + aOrbiterG);
            aWandererA = aWandererA + (((RotL64(aCross, 5U) + RotL64(aOrbiterB, 23U)) + aOrbiterA) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterJ, 11U)) + aNonceWordN) + aPhaseFWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 37U) + RotL64(aOrbiterI, 52U)) + aOrbiterE);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 22U) + aOrbiterI) + RotL64(aOrbiterH, 13U)) + aPhaseFWandererUpdateSaltB[((aIndex + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 50U));
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererI);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + RotL64(aWandererA, 53U);
            aCarry = aCarry + RotL64(aIngress, 36U);
            aCarry = aCarry ^ aNonceWordK;
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22726U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneA[((aIndex + 25979U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 22635U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26207U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aIngress, 19U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCarry, 4U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 29U)) + RotL64(aCarry, 27U)) + 13687218104610230596U;
            aOrbiterI = (aWandererC + RotL64(aIngress, 13U)) + 6841550124960692709U;
            aOrbiterA = (aWandererJ + RotL64(aScatter, 57U)) + 17418968668458764131U;
            aOrbiterK = (aWandererG + RotL64(aCross, 11U)) + 8303537912696948204U;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 46U)) + RotL64(aCarry, 51U)) + 12376614417285936537U;
            aOrbiterC = (aWandererH + RotL64(aCross, 37U)) + 14215749063579232654U;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 27U)) + 4111736931433665347U;
            aOrbiterG = (((aWandererE + RotL64(aScatter, 21U)) + RotL64(aCarry, 37U)) + 11250375934571631522U) + aNonceWordF;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 18U)) + 5367367837773331275U) + aPhaseFOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (aWandererI + RotL64(aCross, 35U)) + 15514089192382674434U;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 53U)) + 1475991716685034960U) + aPhaseFOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 5531622777788629748U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 8363822215908303335U;
            aOrbiterA = RotL64((aOrbiterA * 17850203366840994883U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 3741256932685720414U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 11634667238062155772U;
            aOrbiterC = RotL64((aOrbiterC * 15925089729784547403U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 18180546911210417155U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 5123234656838556335U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15362857462853398025U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 11215734271189250284U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 16863747802158398092U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1828035970246160023U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 9859050606636646323U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 9331300036643654675U;
            aOrbiterD = RotL64((aOrbiterD * 2502263410556166281U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 15028845665427209759U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 8916444839488901676U;
            aOrbiterK = RotL64((aOrbiterK * 6646561894156038791U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 8024631140949068570U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 1116378858490660031U;
            aOrbiterJ = RotL64((aOrbiterJ * 4247798531910227367U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 5066486214537899212U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 9346312092322423057U;
            aOrbiterB = RotL64((aOrbiterB * 13443190089768875191U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 11651011617027950122U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 11308862427412671711U;
            aOrbiterF = RotL64((aOrbiterF * 12167147966934334703U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 3850136281462840708U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 13461307727665667424U) ^ aNonceWordN;
            aOrbiterI = RotL64((aOrbiterI * 10788040812090673421U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 17824744996404571928U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 13687218104610230596U;
            aOrbiterE = RotL64((aOrbiterE * 325803029547254631U), 39U);
            //
            aIngress = RotL64(aOrbiterC, 3U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + (RotL64(aOrbiterG, 50U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aIngress, 46U) + RotL64(aOrbiterC, 14U)) + aOrbiterA);
            aWandererA = aWandererA ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterE, 21U)) + aOrbiterB);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterH, 37U)) + RotL64(aCarry, 47U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 19U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 21U) + aOrbiterI) + RotL64(aOrbiterD, 27U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 5U) + aOrbiterE) + RotL64(aOrbiterA, 47U)) + aNonceWordA);
            aWandererF = aWandererF + ((RotL64(aIngress, 23U) + RotL64(aOrbiterE, 51U)) + aOrbiterK);
            aWandererI = aWandererI ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterI, 39U)) + aOrbiterK);
            aWandererB = aWandererB + (((RotL64(aPrevious, 39U) + aOrbiterI) + RotL64(aOrbiterH, 11U)) + aNonceWordH);
            aWandererG = aWandererG ^ (((RotL64(aCross, 41U) + aOrbiterF) + RotL64(aOrbiterK, 5U)) + aNonceWordJ);
            aWandererD = aWandererD + (((RotL64(aScatter, 26U) + RotL64(aOrbiterJ, 58U)) + aOrbiterG) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 36U));
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 24U));
            aCarry = aCarry + RotL64(aWandererF, 21U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ aNonceWordN;
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31170U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((aIndex + 29805U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32571U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneB[((aIndex + 32171U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 24U) ^ RotL64(aIngress, 53U)) ^ (RotL64(aCross, 39U) + RotL64(aPrevious, 3U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = (((aWandererB + RotL64(aCross, 27U)) + RotL64(aCarry, 53U)) + 13174219512651137892U) + aNonceWordO;
            aOrbiterG = (aWandererC + RotL64(aIngress, 39U)) + 2715455762789269341U;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 21U)) + 1338018183235594313U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 23U)) + 16566866551729552930U;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 43U)) + RotL64(aCarry, 29U)) + 6901845297307236726U;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 58U)) + RotL64(aCarry, 43U)) + 2476078302049201718U;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 47U)) + 15531109473927052260U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = (aWandererE + RotL64(aCross, 11U)) + 4087849380858572351U;
            aOrbiterF = (aWandererG + RotL64(aScatter, 53U)) + 5167830630098599644U;
            aOrbiterA = (aWandererH + RotL64(aCross, 13U)) + 7275995452428627217U;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 60U)) + 14794340370010024117U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 8509217403041662849U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 2321522025240806996U;
            aOrbiterE = RotL64((aOrbiterE * 113568101672878697U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 5676672952755594051U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 2304681269233504384U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15731441084605554497U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 8383399721062437300U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 13181984036942227666U;
            aOrbiterJ = RotL64((aOrbiterJ * 1648761328771932069U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 13602604532551684210U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 12725687663616352843U;
            aOrbiterB = RotL64((aOrbiterB * 4684699861686199753U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 5831790822416009806U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 4535048543735457407U;
            aOrbiterC = RotL64((aOrbiterC * 12076777878870257053U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 10617608605149381858U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 5244225377862618630U;
            aOrbiterF = RotL64((aOrbiterF * 15307177251167023999U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 18229989093139888456U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 9728120630096192811U;
            aOrbiterA = RotL64((aOrbiterA * 16052574428163231023U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 1312233443099767304U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 8043115602160128619U;
            aOrbiterK = RotL64((aOrbiterK * 9365756845731616963U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 4679339316686216023U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 211799535650113758U;
            aOrbiterH = RotL64((aOrbiterH * 1478368466990144107U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 13307123762743628190U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 7093673238704478497U;
            aOrbiterG = RotL64((aOrbiterG * 13273906568866802561U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 16396459072175632290U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 13174219512651137892U) ^ aNonceWordF;
            aOrbiterI = RotL64((aOrbiterI * 7581008806810219369U), 11U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterG, 23U);
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 6U));
            aIngress = aIngress + RotL64(aOrbiterF, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 57U) + aOrbiterE) + RotL64(aOrbiterD, 48U)) + aNonceWordN);
            aWandererG = aWandererG + (((RotL64(aScatter, 51U) + aOrbiterJ) + RotL64(aOrbiterA, 13U)) + aPhaseFWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterK, 3U)) + aOrbiterI) + aNonceWordH);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 38U) + aOrbiterB) + RotL64(aOrbiterK, 41U)) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterG, 23U));
            aWandererC = aWandererC + (((RotL64(aIngress, 43U) + aOrbiterH) + RotL64(aOrbiterD, 29U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterH, 5U)) + aOrbiterF);
            aWandererE = aWandererE + ((RotL64(aPrevious, 35U) + aOrbiterF) + RotL64(aOrbiterJ, 18U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterG, 51U)) + aOrbiterD);
            aWandererB = aWandererB + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 11U)) + aOrbiterI) + RotL64(aCarry, 27U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 24U) + RotL64(aOrbiterC, 21U)) + aOrbiterF) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererH, 30U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 58U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 5U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordK);
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

void TwistExpander_Bowling_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 8095U)) & S_BLOCK1], 51U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 4328U)) & W_KEY1], 60U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 4994U)) & W_KEY1], 47U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 622U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 51U)) + (RotL64(aCross, 38U) + RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = (aWandererH + RotL64(aIngress, 10U)) + 5041131702736607991U;
            aOrbiterD = (((aWandererD + RotL64(aCross, 43U)) + RotL64(aCarry, 21U)) + 9295010428212681446U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 39U)) + 6235875895358766017U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aScatter, 53U)) + 2622227802531866918U;
            aOrbiterB = (aWandererB + RotL64(aCross, 29U)) + 3888894734834524972U;
            aOrbiterE = (aWandererF + RotL64(aIngress, 19U)) + 241682012014701753U;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 35U)) + RotL64(aCarry, 3U)) + 15758000422451568079U;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 4U)) + RotL64(aCarry, 29U)) + 2061944548396976912U;
            aOrbiterH = (aWandererK + RotL64(aCross, 57U)) + 8177144990755754531U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 554978075608818497U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 250408260560714933U;
            aOrbiterF = RotL64((aOrbiterF * 1295379390497107727U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 8700027645880997552U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 10026130047465480902U;
            aOrbiterE = RotL64((aOrbiterE * 12417270861933696623U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 9785843014096326696U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 9998582683258411251U;
            aOrbiterC = RotL64((aOrbiterC * 7197956237569462269U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 13817734599383455151U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 6647207154174092691U;
            aOrbiterH = RotL64((aOrbiterH * 1578528131687283531U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 4957715980509035719U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 4994885315786213197U;
            aOrbiterI = RotL64((aOrbiterI * 5676683798126497011U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 5072908311783966503U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 5535039946192891515U;
            aOrbiterJ = RotL64((aOrbiterJ * 2989412783482309753U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 6594577050344146271U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 8750154123258714856U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6942158167127532003U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 3514769314840874873U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 8626045200273524281U;
            aOrbiterD = RotL64((aOrbiterD * 4315441782689789689U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 8524870284841706517U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 1841819423572964209U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9802481758007234681U), 41U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterB, 29U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + (RotL64(aOrbiterI, 60U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 22U) + RotL64(aOrbiterD, 39U)) + aOrbiterC);
            aWandererC = aWandererC + ((RotL64(aCross, 39U) + aOrbiterE) + RotL64(aOrbiterC, 60U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 35U)) + aOrbiterC);
            aWandererI = aWandererI + ((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterH, 47U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterD, 51U)) + aPhaseCWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterD, 43U)) + aOrbiterH);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 19U)) + aOrbiterK) + RotL64(aCarry, 19U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterJ, 24U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 36U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 10582U)) & S_BLOCK1], 42U) ^ RotL64(mSource[((aIndex + 10704U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15579U)) & W_KEY1], 39U) ^ RotL64(aKeyRowReadB[((aIndex + 15366U)) & W_KEY1], 50U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aIngress, 11U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCarry, 42U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (((aWandererG + RotL64(aPrevious, 51U)) + RotL64(aCarry, 21U)) + 785861751704720606U) + aPhaseCOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aIngress, 27U)) + 15968088718435606299U;
            aOrbiterF = (aWandererI + RotL64(aScatter, 43U)) + 1393976526590347151U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 58U)) + RotL64(aCarry, 35U)) + 17240750947292745884U;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 47U)) + 4921576136163183137U) + aPhaseCOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aCross, 23U)) + 3334047873553153032U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 3U)) + RotL64(aCarry, 57U)) + 15086509978458408698U;
            aOrbiterH = (aWandererC + RotL64(aPrevious, 12U)) + 892391205397581998U;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 35U)) + 2965686403183767521U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 14632215393655706170U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 15740589515342377322U;
            aOrbiterF = RotL64((aOrbiterF * 15677716942904794913U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 11131164813943086445U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 6988080581278900960U;
            aOrbiterE = RotL64((aOrbiterE * 6412189142344044255U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 16021254613117657178U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 6183615599897921154U;
            aOrbiterD = RotL64((aOrbiterD * 9976411093264211033U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 12533992547026652747U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 3104325358982904219U;
            aOrbiterH = RotL64((aOrbiterH * 14977348108778147265U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 3878525937957474644U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 2120435259884368445U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15964718652193073177U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 14928658302694194856U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 9121310461310309348U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17304439784647477491U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 3715693239100476493U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 7336577492932262490U;
            aOrbiterB = RotL64((aOrbiterB * 11074754160002665253U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 2312452827448455675U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 4322756069651934618U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6908893297397073539U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 4962079617577705818U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 5072727464750706525U;
            aOrbiterC = RotL64((aOrbiterC * 4947670001221089155U), 29U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 37U);
            aIngress = aIngress + (RotL64(aOrbiterA, 4U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 21U));
            aIngress = aIngress + RotL64(aOrbiterB, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aCross, 51U) + aOrbiterG) + RotL64(aOrbiterC, 27U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 34U) + aOrbiterD) + RotL64(aOrbiterJ, 35U));
            aWandererH = aWandererH + (((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterH, 6U)) + aPhaseCWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterA, 47U));
            aWandererF = aWandererF + (((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 3U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 13U)) + aOrbiterB) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 39U)) + aOrbiterE);
            aWandererG = aWandererG ^ ((RotL64(aCross, 22U) + aOrbiterB) + RotL64(aOrbiterH, 53U));
            aWandererI = aWandererI + (((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 58U)) + aOrbiterD) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 14U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23584U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18774U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 22182U)) & W_KEY1], 41U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 23381U)) & W_KEY1], 26U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCross, 6U)) ^ (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 47U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = ((aWandererE + RotL64(aCross, 46U)) + RotL64(aCarry, 19U)) + 12849591986267890852U;
            aOrbiterK = (((aWandererF + RotL64(aIngress, 39U)) + RotL64(aCarry, 57U)) + 8232614804696815750U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aPrevious, 11U)) + 12141567259210877281U;
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 3U)) + 2928641981037885644U) + aPhaseCOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aIngress, 24U)) + 980733350554783938U;
            aOrbiterF = (aWandererC + RotL64(aPrevious, 57U)) + 2683985177993350746U;
            aOrbiterB = (aWandererI + RotL64(aCross, 19U)) + 14532148403815527355U;
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 53U)) + RotL64(aCarry, 39U)) + 7736296629433884203U;
            aOrbiterC = (aWandererH + RotL64(aIngress, 29U)) + 10428437770166310549U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 18327174144859461029U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 6810436935194432002U;
            aOrbiterG = RotL64((aOrbiterG * 2715987179577753597U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 12606153309690753435U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 17123256945895150555U;
            aOrbiterH = RotL64((aOrbiterH * 13469111258504672565U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 9057777759026189541U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 16478485918911194442U;
            aOrbiterI = RotL64((aOrbiterI * 11054247078884894131U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 18064460487552100483U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 11477276762421684083U;
            aOrbiterK = RotL64((aOrbiterK * 3886501230380184395U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 18318375441973295081U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 13849305985380030986U;
            aOrbiterE = RotL64((aOrbiterE * 12962140243967824959U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 10240409420338313641U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 18360586077779529086U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 18196875422391501927U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 16801797158622424257U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 4950305991208513887U;
            aOrbiterB = RotL64((aOrbiterB * 4437082499761416951U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 15790878572843321918U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 9808781805065559728U;
            aOrbiterJ = RotL64((aOrbiterJ * 9394280083159162953U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 11974996650410830731U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 4955004489435232515U;
            aOrbiterC = RotL64((aOrbiterC * 13301966529515483085U), 35U);
            //
            aIngress = RotL64(aOrbiterJ, 41U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + (RotL64(aOrbiterI, 14U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 34U) + RotL64(aOrbiterH, 23U)) + aOrbiterK) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterE, 29U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 23U) + aOrbiterC) + RotL64(aOrbiterG, 47U));
            aWandererH = aWandererH + ((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterF, 12U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 27U) + aOrbiterF) + RotL64(aOrbiterE, 53U));
            aWandererK = aWandererK + (((RotL64(aScatter, 51U) + RotL64(aOrbiterG, 39U)) + aOrbiterB) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 43U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aCross, 11U) + RotL64(aOrbiterF, 18U)) + aOrbiterK) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 38U) + RotL64(aOrbiterI, 57U)) + aOrbiterH) + aPhaseCWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 44U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + RotL64(aWandererB, 23U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 26052U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25576U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31210U)) & S_BLOCK1], 54U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29939U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCross, 4U)) + (RotL64(aIngress, 53U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = ((aWandererK + RotL64(aCross, 24U)) + 15904465836916519864U) + aPhaseCOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aScatter, 47U)) + 17725629806317789307U;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 19U)) + 13794170125914914828U;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 27U)) + 2149055907476874332U;
            aOrbiterK = (aWandererB + RotL64(aPrevious, 56U)) + 5342047776745074649U;
            aOrbiterB = (((aWandererJ + RotL64(aCross, 43U)) + RotL64(aCarry, 3U)) + 8268148484060546838U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aIngress, 37U)) + 10821151364028563719U;
            aOrbiterI = ((aWandererG + RotL64(aScatter, 5U)) + RotL64(aCarry, 37U)) + 4294213820894407378U;
            aOrbiterC = (aWandererE + RotL64(aIngress, 13U)) + 10884726101307943090U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 16432210042202444824U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 15196602644336228055U;
            aOrbiterD = RotL64((aOrbiterD * 12680438355124070237U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 14117787670220328165U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 219833877949480215U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10736293047771972173U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 3326396981881473962U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 14918513066311426279U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14269763278564574663U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 11795234681370163206U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 3068267285352664813U;
            aOrbiterF = RotL64((aOrbiterF * 15746255933920904619U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 245233356957999496U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 709926406353796673U;
            aOrbiterA = RotL64((aOrbiterA * 13627039596842073595U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 5378105439430271038U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 10114555061122044430U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5351295043424885549U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 13233010815716769713U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 8231291294833548389U;
            aOrbiterI = RotL64((aOrbiterI * 10840516135212753869U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 7160760224172419829U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 14767926435411546785U;
            aOrbiterC = RotL64((aOrbiterC * 1643485739468851073U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 4464245330038080103U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 15778166658285494712U;
            aOrbiterJ = RotL64((aOrbiterJ * 13980891936095282989U), 23U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 60U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 35U)) + aOrbiterK) + RotL64(aCarry, 41U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 30U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 24U) + RotL64(aOrbiterF, 57U)) + aOrbiterC) + RotL64(aCarry, 11U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterF, 5U)) + aOrbiterA);
            aWandererB = aWandererB + (((RotL64(aIngress, 19U) + aOrbiterK) + RotL64(aOrbiterD, 11U)) + aPhaseCWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterF, 39U)) + aOrbiterD);
            aWandererA = aWandererA + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 19U)) + aOrbiterF) + aPhaseCWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 36U) + RotL64(aOrbiterI, 23U)) + aOrbiterD);
            aWandererG = aWandererG + ((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterF, 46U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 38U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererE, 35U);
            aCarry = aCarry + RotL64(aIngress, 58U);
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

void TwistExpander_Bowling_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4521U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6370U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2017U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((aIndex + 4693U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCross, 41U)) + (RotL64(aCarry, 3U) + RotL64(aIngress, 28U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 11U)) + RotL64(aCarry, 41U)) + 1364174714924216027U;
            aOrbiterF = ((aWandererA + RotL64(aCross, 39U)) + 13561796874229506613U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = (aWandererK + RotL64(aPrevious, 22U)) + 11845572344206238305U;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 53U)) + RotL64(aCarry, 29U)) + 15762708240326773763U;
            aOrbiterC = (((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 3U)) + 1157119665207900473U) + aPhaseDOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 6823546624372055260U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 14465564210523945121U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10957323253786161255U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 10667464548080807531U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 13445737493224316575U;
            aOrbiterI = RotL64((aOrbiterI * 12137295000900795711U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 3009837893785957665U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 2886920524111083752U;
            aOrbiterD = RotL64((aOrbiterD * 15308180928967762543U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 10886177449328249656U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 15067759884678100433U;
            aOrbiterF = RotL64((aOrbiterF * 5724566815989860041U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 18307930462682331536U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 8791864377579255801U;
            aOrbiterC = RotL64((aOrbiterC * 9265158882471421767U), 39U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterD, 29U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + RotL64(aOrbiterA, 18U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 29U) + aOrbiterD) + RotL64(aOrbiterF, 35U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 20U) + RotL64(aOrbiterI, 26U)) + aOrbiterD) + RotL64(aCarry, 19U)) + aPhaseDWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 5U) + aOrbiterC) + RotL64(aOrbiterF, 51U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 11U)) + aOrbiterI) + RotL64(aCarry, 47U)) + aPhaseDWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 53U) + aOrbiterI) + RotL64(aOrbiterC, 3U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 4U));
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 9964U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneD[((aIndex + 14474U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14514U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 13952U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 24U) ^ RotL64(aCross, 57U)) + (RotL64(aCarry, 11U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererK + RotL64(aScatter, 13U)) + RotL64(aCarry, 43U)) + 11521331427196538632U;
            aOrbiterK = (((aWandererE + RotL64(aIngress, 21U)) + RotL64(aCarry, 23U)) + 16653824187682957632U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 29U)) + 11654676587350088289U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = ((aWandererH + RotL64(aCross, 44U)) + RotL64(aCarry, 3U)) + 8010313317412193584U;
            aOrbiterF = (aWandererJ + RotL64(aIngress, 53U)) + 1108775560502907471U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 243952321439823521U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 2324945800401240403U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9471328582043504473U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 9257554497543369657U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 16701314607244592540U;
            aOrbiterF = RotL64((aOrbiterF * 8790054741039817107U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 3900445848034341782U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 7652316487347103658U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11480123491361589799U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 14980368605272070578U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 2001165460948764796U;
            aOrbiterK = RotL64((aOrbiterK * 8110980921827107649U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 1911044015666991050U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 11366207111147818339U;
            aOrbiterC = RotL64((aOrbiterC * 17234439040652553865U), 11U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 23U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + RotL64(aOrbiterJ, 48U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aCross, 27U) + RotL64(aOrbiterK, 57U)) + aOrbiterC) + RotL64(aCarry, 37U)) + aPhaseDWandererUpdateSaltF[((aIndex + 12U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterC, 29U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 19U)) + aOrbiterJ) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 38U) + aOrbiterC) + RotL64(aOrbiterJ, 41U));
            aWandererF = aWandererF + (((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterK, 10U)) + aPhaseDWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 4U));
            aCarry = aCarry + RotL64(aWandererJ, 39U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 19953U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23753U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16691U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneC[((aIndex + 23942U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 20U)) + (RotL64(aCross, 51U) ^ RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = ((aWandererK + RotL64(aCross, 35U)) + RotL64(aCarry, 23U)) + 16200278595895089008U;
            aOrbiterF = (((aWandererA + RotL64(aScatter, 43U)) + RotL64(aCarry, 57U)) + 1029614154810465897U) + aPhaseDOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = (((aWandererJ + RotL64(aPrevious, 21U)) + RotL64(aCarry, 11U)) + 7129562468705441295U) + aPhaseDOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aIngress, 3U)) + 14388903902433951274U;
            aOrbiterK = (aWandererB + RotL64(aScatter, 58U)) + 1013568949315967455U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 3128823373497815651U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 14525694606889470589U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12053226114431679195U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 14443983602196782887U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 12244220415328641190U;
            aOrbiterF = RotL64((aOrbiterF * 15052949098014803181U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 10477159225338766614U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 2842870123078131566U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11522265477555954071U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 8621138818955849917U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 5038396344400303181U;
            aOrbiterE = RotL64((aOrbiterE * 14636756322207385447U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 2768613802894372496U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 2027754864051410015U;
            aOrbiterK = RotL64((aOrbiterK * 2461322540050569287U), 39U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 43U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + RotL64(aOrbiterJ, 18U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aCross, 23U) + RotL64(aOrbiterK, 29U)) + aOrbiterE) + RotL64(aCarry, 37U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 54U) + RotL64(aOrbiterK, 19U)) + aOrbiterA);
            aWandererB = aWandererB + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterF, 51U)) + aOrbiterJ) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterF, 37U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 3U) + aOrbiterE) + RotL64(aOrbiterA, 60U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 29221U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneB[((aIndex + 24990U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25767U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneD[((aIndex + 26972U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 43U) + RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 28U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererC + RotL64(aIngress, 35U)) + RotL64(aCarry, 13U)) + 17912271996338180948U;
            aOrbiterD = (((aWandererG + RotL64(aPrevious, 23U)) + RotL64(aCarry, 47U)) + 13259276608841847058U) + aPhaseDOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = ((aWandererK + RotL64(aScatter, 43U)) + RotL64(aCarry, 27U)) + 16225936008657276089U;
            aOrbiterC = ((aWandererA + RotL64(aCross, 60U)) + 2243058962151834071U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aPrevious, 5U)) + 10637439274127347861U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 15312219216405992627U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 2393933972129878613U;
            aOrbiterE = RotL64((aOrbiterE * 13147717214387593761U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 4327069337247976513U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 8307656353434167837U;
            aOrbiterK = RotL64((aOrbiterK * 11386588389133096705U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 17299145556933889336U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 14458100581172798164U;
            aOrbiterC = RotL64((aOrbiterC * 16543734663677070509U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 6410095654927998067U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 6168964796264687686U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16218071040190475953U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 3667999465041020730U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 16021552859323602007U;
            aOrbiterB = RotL64((aOrbiterB * 6427266472526362663U), 5U);
            //
            aIngress = RotL64(aOrbiterK, 4U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 4U) + aOrbiterK) + RotL64(aOrbiterC, 3U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterD, 29U)) + aOrbiterE) + RotL64(aCarry, 37U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterK, 21U)) + aOrbiterB) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 39U) + RotL64(aOrbiterD, 56U)) + aOrbiterK) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterC, 13U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 52U);
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

void TwistExpander_Bowling_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 7323U)) & S_BLOCK1], 34U) ^ RotL64(aOperationLaneC[((aIndex + 2083U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7041U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneA[((aIndex + 3763U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 36U)) + (RotL64(aIngress, 51U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = ((aWandererA + RotL64(aCross, 41U)) + RotL64(aCarry, 39U)) + 2225397913940961213U;
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 28U)) + 8342544893601343643U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aScatter, 13U)) + RotL64(aCarry, 27U)) + 162922186381417187U;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 35U)) + 11660218373710972210U;
            aOrbiterC = (aWandererK + RotL64(aScatter, 3U)) + 14909034764605802354U;
            aOrbiterI = (aWandererB + RotL64(aIngress, 57U)) + 16776955237009701511U;
            aOrbiterK = (((aWandererD + RotL64(aPrevious, 51U)) + RotL64(aCarry, 3U)) + 5834487809188925253U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 1498492772767040320U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 4161765458781579617U;
            aOrbiterE = RotL64((aOrbiterE * 15535994410289065281U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 10511923076962447765U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 8575954471692620021U;
            aOrbiterC = RotL64((aOrbiterC * 12526744988828982731U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 6536325446331340573U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 1790628986900286346U;
            aOrbiterI = RotL64((aOrbiterI * 5262997114200816715U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 2623814807619278590U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 11676970995834706612U;
            aOrbiterK = RotL64((aOrbiterK * 10057461115132434901U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 13836786354224256591U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 6293096163612129260U;
            aOrbiterH = RotL64((aOrbiterH * 8977954126326217153U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 4271144764978661248U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 15938494256992560202U;
            aOrbiterJ = RotL64((aOrbiterJ * 10004841288382726739U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 11038155227307702976U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 12408749795071243930U;
            aOrbiterF = RotL64((aOrbiterF * 5527720475032868855U), 47U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 43U);
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 37U));
            aIngress = aIngress + RotL64(aOrbiterI, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aPrevious, 21U) + aOrbiterI) + RotL64(aOrbiterF, 41U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterK, 35U)) + aOrbiterF) + aPhaseEWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 13U) + aOrbiterF) + RotL64(aOrbiterC, 27U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterC, 21U)) + aOrbiterH);
            aWandererA = aWandererA + ((((RotL64(aScatter, 44U) + RotL64(aOrbiterI, 3U)) + aOrbiterH) + RotL64(aCarry, 51U)) + aPhaseEWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 13U)) + aOrbiterE);
            aWandererK = aWandererK + (((RotL64(aIngress, 51U) + aOrbiterE) + RotL64(aOrbiterK, 58U)) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (RotL64(aWandererA, 36U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + RotL64(aWandererI, 51U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 14399U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 10433U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15408U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 14508U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aPrevious, 3U)) ^ (RotL64(aCross, 21U) + RotL64(aIngress, 48U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = (aWandererK + RotL64(aScatter, 13U)) + 17264605017518259932U;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 47U)) + RotL64(aCarry, 51U)) + 15209184354580778643U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 21U)) + 3299527965014731384U;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 5U)) + RotL64(aCarry, 39U)) + 16293096431816127821U;
            aOrbiterH = (aWandererB + RotL64(aCross, 37U)) + 11031983436878828337U;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 19U)) + 9188018632448236358U) + aPhaseEOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aScatter, 56U)) + 13420816400363406556U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 2485063384097917101U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 3089135816938128264U;
            aOrbiterI = RotL64((aOrbiterI * 8813152992957361153U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 10730544971770435788U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 10431767565618874806U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4723078464590561545U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 14883796491656899074U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 13465877783538483706U;
            aOrbiterD = RotL64((aOrbiterD * 14311686051108108503U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 13322163435314643713U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 3307316600284371955U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12337846092069506365U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 4950101626975919939U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 2596253994220103666U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7181706961838582889U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 17961706029559914243U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 10321902557977495175U;
            aOrbiterC = RotL64((aOrbiterC * 16189559888625084711U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 18146616411403012772U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 8414050129421955787U;
            aOrbiterB = RotL64((aOrbiterB * 14879448948196182863U), 29U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 52U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + RotL64(aOrbiterH, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 41U) + aOrbiterH) + RotL64(aOrbiterB, 19U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 11U) + aOrbiterI) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 51U)) + aPhaseEWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterK, 51U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 47U) + RotL64(aOrbiterH, 57U)) + aOrbiterC) + RotL64(aCarry, 39U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 60U) + aOrbiterH) + RotL64(aOrbiterJ, 12U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 53U) + aOrbiterK) + RotL64(aOrbiterI, 39U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterB, 5U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererB, 30U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 20944U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((aIndex + 24466U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 21312U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneC[((aIndex + 23496U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 60U) ^ RotL64(aCross, 11U)) + (RotL64(aCarry, 23U) ^ RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = (aWandererJ + RotL64(aScatter, 13U)) + 15813325389431304548U;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 51U)) + 2223874171125403602U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = (aWandererI + RotL64(aIngress, 57U)) + 5510483568496824130U;
            aOrbiterA = (((aWandererB + RotL64(aCross, 30U)) + RotL64(aCarry, 5U)) + 15474152493495661876U) + aPhaseEOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 41U)) + RotL64(aCarry, 35U)) + 16846339705130829195U;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 3U)) + RotL64(aCarry, 19U)) + 1289670576865739669U;
            aOrbiterJ = (aWandererE + RotL64(aScatter, 23U)) + 18017354919647006944U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 8539685539928984921U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 3333721400836704048U;
            aOrbiterI = RotL64((aOrbiterI * 3745286323481400085U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 2261560416623815491U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 4377786131746816567U;
            aOrbiterB = RotL64((aOrbiterB * 9164777834392621157U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 18047393176583722719U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 8184724021940434631U;
            aOrbiterH = RotL64((aOrbiterH * 9800116157750921119U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 10469895939183324807U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 14543391765109879223U;
            aOrbiterA = RotL64((aOrbiterA * 4817987697437667225U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 5757225781746158178U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 3539000495894022869U;
            aOrbiterK = RotL64((aOrbiterK * 1032298408884695925U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 11288971092707065923U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 2761384065186568294U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3323838837427471051U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 7120580145300417101U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 6977246291769372866U;
            aOrbiterJ = RotL64((aOrbiterJ * 15170353875184253779U), 35U);
            //
            aIngress = RotL64(aOrbiterG, 3U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 51U) + aOrbiterI) + RotL64(aOrbiterA, 22U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 37U) + aOrbiterA) + RotL64(aOrbiterK, 5U)) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterH, 57U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterJ, 11U)) + aPhaseEWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterB, 51U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 28U) + RotL64(aOrbiterK, 35U)) + aOrbiterH) + aPhaseEWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 12U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + RotL64(aWandererD, 43U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 28690U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((aIndex + 27843U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25163U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneD[((aIndex + 25775U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 52U) + RotL64(aCarry, 3U)) ^ (RotL64(aCross, 39U) + RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = (aWandererB + RotL64(aScatter, 23U)) + 17668251151213543491U;
            aOrbiterC = ((aWandererD + RotL64(aCross, 39U)) + RotL64(aCarry, 13U)) + 16101602509895104517U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 51U)) + 9083915270773304935U;
            aOrbiterF = (((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 37U)) + 12810720730318214811U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = (((aWandererF + RotL64(aIngress, 3U)) + RotL64(aCarry, 57U)) + 18113428002071925621U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aScatter, 29U)) + 1582208899354109878U;
            aOrbiterI = (aWandererH + RotL64(aCross, 58U)) + 4180688104819188154U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 8954598189262820611U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 15360094153175355879U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8177798855402983685U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 8383954114668216260U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 15626783326234049197U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15058420415480073793U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 10609978564404958066U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 17656516608997517984U;
            aOrbiterC = RotL64((aOrbiterC * 4590620354119899777U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 760077259110786536U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 3597338735888033063U;
            aOrbiterA = RotL64((aOrbiterA * 6548831472863517621U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 4431777844935985157U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 10710423172154671296U;
            aOrbiterH = RotL64((aOrbiterH * 16267496318491473315U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 10240882795242085185U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 7826053487019825891U;
            aOrbiterF = RotL64((aOrbiterF * 15053729937684375907U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 9418883403715727353U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 11507423614799075545U;
            aOrbiterI = RotL64((aOrbiterI * 16189463984557044693U), 27U);
            //
            aIngress = RotL64(aOrbiterG, 41U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 60U));
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 13U)) + aOrbiterC) + RotL64(aCarry, 21U)) + aPhaseEWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterG, 19U));
            aWandererG = aWandererG + ((RotL64(aIngress, 5U) + RotL64(aOrbiterD, 3U)) + aOrbiterA);
            aWandererD = aWandererD ^ (((RotL64(aCross, 51U) + aOrbiterG) + RotL64(aOrbiterF, 37U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterC, 43U)) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterI, 50U)) + aOrbiterC);
            aWandererH = aWandererH + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 57U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + (RotL64(aWandererD, 12U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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

void TwistExpander_Bowling_Arx::Twist_D(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 6124U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 722U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3200U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneA[((aIndex + 6323U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aPrevious, 27U)) ^ (RotL64(aCarry, 13U) + RotL64(aIngress, 58U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 13U)) + RotL64(aCarry, 11U)) + 3339283916456813609U;
            aOrbiterG = (aWandererA + RotL64(aScatter, 35U)) + 11339086426180649584U;
            aOrbiterB = (((aWandererG + RotL64(aIngress, 24U)) + RotL64(aCarry, 57U)) + 16819191669329316585U) + aPhaseFOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = (((aWandererJ + RotL64(aCross, 57U)) + RotL64(aCarry, 29U)) + 8361916937762630725U) + aPhaseFOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aScatter, 47U)) + 18031328374429899857U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 18261756894092897276U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 4250319792907645666U;
            aOrbiterB = RotL64((aOrbiterB * 7053489184750217963U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 1492411503643460886U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 17369549067879344180U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2947354306696216579U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 7301713524358676722U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 2985193736033012535U;
            aOrbiterH = RotL64((aOrbiterH * 7473297294949338265U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 14086975808140927408U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 10390516547834639800U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11441293212275890819U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 18205555540941493267U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 16967799565443938873U;
            aOrbiterA = RotL64((aOrbiterA * 3009081009044782443U), 21U);
            //
            aIngress = RotL64(aOrbiterG, 23U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterA, 37U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterH, 14U)) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 14U) + RotL64(aOrbiterF, 5U)) + aOrbiterH);
            aWandererF = aWandererF + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterA, 37U)) + aOrbiterG) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterB, 29U)) + aOrbiterF) + aPhaseFWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 53U) + aOrbiterG) + RotL64(aOrbiterF, 53U)) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + (RotL64(aWandererF, 58U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 3U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 16008U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10933U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10480U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 16039U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 6U)) + (RotL64(aIngress, 19U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (aWandererB + RotL64(aScatter, 23U)) + 11700815697312060726U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 36U)) + RotL64(aCarry, 11U)) + 11808423452327465441U;
            aOrbiterF = (((aWandererI + RotL64(aCross, 11U)) + RotL64(aCarry, 37U)) + 8670503858631730886U) + aPhaseFOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aIngress, 57U)) + RotL64(aCarry, 23U)) + 2400061067991988544U;
            aOrbiterK = ((aWandererD + RotL64(aScatter, 3U)) + 16163118178366229686U) + aPhaseFOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 3280178595904941068U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 3298683600817047727U;
            aOrbiterF = RotL64((aOrbiterF * 9865649058799255343U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 16321624053445183574U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 6730229877611375225U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2022290495153519279U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 10162830636713641322U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 15646771327759599256U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15333053762177144775U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 14841751262270544102U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 9545541117228834895U;
            aOrbiterI = RotL64((aOrbiterI * 11529769874752969377U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 14676615635857599982U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 1231768638470558855U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2716808508509014677U), 3U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 47U);
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterC, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 39U) + aOrbiterG) + RotL64(aOrbiterI, 13U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterC, 36U)) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterG, 57U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterC, 47U)) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 12U) + RotL64(aOrbiterF, 27U)) + aOrbiterK) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 48U));
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 19398U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((aIndex + 18680U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18141U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneC[((aIndex + 22051U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCarry, 51U)) ^ (RotL64(aPrevious, 36U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (aWandererC + RotL64(aScatter, 37U)) + 4739486756133131180U;
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 3U)) + RotL64(aCarry, 37U)) + 16089707555501328184U;
            aOrbiterE = (((aWandererE + RotL64(aIngress, 13U)) + RotL64(aCarry, 57U)) + 15310047330238536453U) + aPhaseFOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aCross, 54U)) + RotL64(aCarry, 13U)) + 7901411596386834955U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 27U)) + 4357555491060982163U) + aPhaseFOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 15667085602825720102U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 8520635334382269253U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7348648918661047791U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 1772509779231068315U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 15336170957886025677U;
            aOrbiterB = RotL64((aOrbiterB * 10996880551392077399U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 8628770833489469980U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 15469234024247246228U;
            aOrbiterF = RotL64((aOrbiterF * 8905266995119987947U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 10796430900884288328U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 10660110397012853289U;
            aOrbiterG = RotL64((aOrbiterG * 9140007610912037461U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 11202284258711214794U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 17509491802893182994U;
            aOrbiterJ = RotL64((aOrbiterJ * 9329107599972703671U), 13U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 13U);
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterJ, 26U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aCross, 21U) + RotL64(aOrbiterF, 27U)) + aOrbiterG) + RotL64(aCarry, 3U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterB, 43U));
            aWandererC = aWandererC + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 35U)) + aOrbiterJ) + RotL64(aCarry, 43U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 13U) + aOrbiterE) + RotL64(aOrbiterG, 56U));
            aWandererE = aWandererE + ((RotL64(aCross, 54U) + aOrbiterB) + RotL64(aOrbiterG, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + RotL64(aWandererF, 37U);
            aCarry = aCarry + RotL64(aIngress, 58U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 29903U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24981U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24584U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 27251U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCarry, 54U)) ^ (RotL64(aIngress, 23U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 39U)) + RotL64(aCarry, 11U)) + 1364174714924216027U;
            aOrbiterH = ((aWandererA + RotL64(aCross, 30U)) + 13561796874229506613U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = (((aWandererH + RotL64(aIngress, 5U)) + RotL64(aCarry, 27U)) + 11845572344206238305U) + aPhaseFOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aScatter, 21U)) + 15762708240326773763U;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 47U)) + RotL64(aCarry, 51U)) + 1157119665207900473U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 6823546624372055260U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 14465564210523945121U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10957323253786161255U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 10667464548080807531U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 13445737493224316575U;
            aOrbiterD = RotL64((aOrbiterD * 12137295000900795711U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 3009837893785957665U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 2886920524111083752U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15308180928967762543U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 10886177449328249656U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 15067759884678100433U;
            aOrbiterH = RotL64((aOrbiterH * 5724566815989860041U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 18307930462682331536U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 8791864377579255801U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9265158882471421767U), 29U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterD, 37U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + RotL64(aOrbiterH, 50U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 51U) + aOrbiterJ) + RotL64(aOrbiterB, 43U)) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterI, 60U)) + aOrbiterH) + aPhaseFWandererUpdateSaltF[((aIndex + 26U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 43U)) + aPhaseFWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 5U) + aOrbiterD) + RotL64(aOrbiterB, 19U));
            aWandererA = aWandererA + ((RotL64(aCross, 60U) + aOrbiterI) + RotL64(aOrbiterB, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void TwistExpander_Bowling_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 1792U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneB[((aIndex + 3308U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7429U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 6688U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 21U)) ^ (RotL64(aIngress, 35U) ^ RotL64(aCarry, 56U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 37U)) + RotL64(aCarry, 43U)) + 6068543441070417854U;
            aOrbiterK = (aWandererA + RotL64(aScatter, 47U)) + 2995980468193441856U;
            aOrbiterA = (((aWandererF + RotL64(aCross, 56U)) + RotL64(aCarry, 3U)) + 18020277482171594003U) + aPhaseGOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = (aWandererE + RotL64(aIngress, 19U)) + 4293807434721230702U;
            aOrbiterE = (((aWandererG + RotL64(aScatter, 5U)) + RotL64(aCarry, 19U)) + 7980599111583893156U) + aPhaseGOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 8593141111851052016U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 5903487523900084325U;
            aOrbiterA = RotL64((aOrbiterA * 2508618861111356699U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 15112035513447930209U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 9854037263057006439U;
            aOrbiterH = RotL64((aOrbiterH * 396276470208637283U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 16759760289688823193U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 12622628933030601390U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2151912984825538321U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 1264668857268123425U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 16302812053619101593U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 18291400055836111547U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 16087995784896123610U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 7970269262800468363U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14924752223305807461U), 39U);
            //
            aIngress = RotL64(aOrbiterH, 27U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 42U));
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 3U)) + aOrbiterE) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 56U) + RotL64(aOrbiterA, 11U)) + aOrbiterH) + RotL64(aCarry, 53U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterE, 57U)) + aOrbiterA);
            aWandererA = aWandererA + (((RotL64(aIngress, 39U) + RotL64(aOrbiterJ, 19U)) + aOrbiterK) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterK, 36U)) + aOrbiterE) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 38U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 14369U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 9080U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 11920U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneA[((aIndex + 8695U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCross, 24U)) + (RotL64(aCarry, 39U) ^ RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = ((aWandererF + RotL64(aCross, 26U)) + RotL64(aCarry, 3U)) + 14249093584376402677U;
            aOrbiterG = (aWandererA + RotL64(aIngress, 51U)) + 8756965951816492264U;
            aOrbiterK = (((aWandererH + RotL64(aScatter, 37U)) + RotL64(aCarry, 29U)) + 11221139480258176330U) + aPhaseGOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 3U)) + 17218894445564194851U) + aPhaseGOrbiterAssignSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aIngress, 13U)) + RotL64(aCarry, 41U)) + 8064642692524949490U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 5822093203710704646U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 3217799620158102238U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2806328682494910635U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 2613757677892120843U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 13647481499551657237U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5517563514031899891U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 3545714196663685016U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 9735422670576621521U;
            aOrbiterC = RotL64((aOrbiterC * 7276207208162697249U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 3911046580637583767U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 9315984027042049203U;
            aOrbiterG = RotL64((aOrbiterG * 12568550776487242469U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 8926367674641729058U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 11035347490524961446U;
            aOrbiterD = RotL64((aOrbiterD * 10948288997163592463U), 29U);
            //
            aIngress = RotL64(aOrbiterD, 58U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterC, 23U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 47U)) + aOrbiterG) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 5U) + aOrbiterK) + RotL64(aOrbiterD, 57U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aIngress, 56U) + RotL64(aOrbiterK, 11U)) + aOrbiterE) + RotL64(aCarry, 53U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterK, 38U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 4U));
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 23892U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneD[((aIndex + 22567U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23497U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((aIndex + 19611U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCarry, 54U)) ^ (RotL64(aCross, 27U) + RotL64(aPrevious, 13U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = (aWandererG + RotL64(aIngress, 27U)) + 2101601659597850213U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 18U)) + RotL64(aCarry, 3U)) + 2759794072560720121U;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 51U)) + RotL64(aCarry, 53U)) + 9443562552411269339U;
            aOrbiterH = ((aWandererK + RotL64(aCross, 3U)) + 10801360546699857975U) + aPhaseGOrbiterAssignSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = (((aWandererF + RotL64(aIngress, 43U)) + RotL64(aCarry, 37U)) + 8020716394829332019U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 1021894212367773801U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 13346855534622490176U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12668950387932320985U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 16359309548462953836U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 12642446944680783519U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12197935153255283321U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 8197424982767553380U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 14346334610901859094U;
            aOrbiterC = RotL64((aOrbiterC * 16982899923227935679U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 14171304260534233539U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 334531601308283605U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5012968232749075075U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 10707856298471572695U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 18364775750091914766U;
            aOrbiterE = RotL64((aOrbiterE * 15735143943129143265U), 11U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterB, 3U);
            aIngress = aIngress + (RotL64(aOrbiterK, 26U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 27U) + aOrbiterK) + RotL64(aOrbiterE, 3U)) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterE, 47U)) + aOrbiterH);
            aWandererH = aWandererH + (((RotL64(aScatter, 3U) + aOrbiterH) + RotL64(aOrbiterC, 39U)) + aPhaseGWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 42U) + aOrbiterC) + RotL64(aOrbiterE, 57U)) + aPhaseGWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 19U) + RotL64(aOrbiterK, 30U)) + aOrbiterB) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 30355U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((aIndex + 27441U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26520U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((aIndex + 25960U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCarry, 3U)) ^ (RotL64(aCross, 38U) + RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 37U)) + 5721224134332887360U) + aPhaseGOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aCross, 5U)) + 6892749729775049095U) + aPhaseGOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 19U)) + RotL64(aCarry, 23U)) + 3884839462099556836U;
            aOrbiterH = ((aWandererI + RotL64(aIngress, 29U)) + RotL64(aCarry, 3U)) + 4365431706830216193U;
            aOrbiterF = ((aWandererF + RotL64(aCross, 56U)) + RotL64(aCarry, 51U)) + 15501528746571578773U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 4505911326320650606U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 1865129050927879580U;
            aOrbiterA = RotL64((aOrbiterA * 9198152644404068721U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 2011737665969640369U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 611672935827062688U;
            aOrbiterJ = RotL64((aOrbiterJ * 12873671551304596619U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 663547038310431047U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 5468932264754299556U;
            aOrbiterH = RotL64((aOrbiterH * 11968657455484578525U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 17920294117231191705U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 486058453837528110U;
            aOrbiterK = RotL64((aOrbiterK * 8851102552244026737U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 2789178451938129313U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 420772587981211184U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17402987842294006667U), 29U);
            //
            aIngress = RotL64(aOrbiterA, 26U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 46U) + aOrbiterA) + RotL64(aOrbiterK, 11U)) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 21U)) + aOrbiterF);
            aWandererI = aWandererI + ((((RotL64(aCross, 37U) + RotL64(aOrbiterH, 53U)) + aOrbiterF) + RotL64(aCarry, 23U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 27U) + aOrbiterK) + RotL64(aOrbiterJ, 29U));
            aWandererF = aWandererF + (((RotL64(aCross, 57U) + RotL64(aOrbiterH, 44U)) + aOrbiterA) + aPhaseGWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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

void TwistExpander_Bowling_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 84U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneB[((aIndex + 4158U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1277U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 422U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aIngress, 41U)) ^ (RotL64(aCarry, 13U) + RotL64(aPrevious, 28U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 5U)) + 16451272412693907816U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aIngress, 43U)) + RotL64(aCarry, 51U)) + 10099485419723255462U;
            aOrbiterA = (((aWandererI + RotL64(aCross, 13U)) + RotL64(aCarry, 21U)) + 17668900099534923192U) + aPhaseHOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aScatter, 58U)) + RotL64(aCarry, 39U)) + 5497093724143181753U;
            aOrbiterD = (aWandererF + RotL64(aPrevious, 21U)) + 10354044773550071706U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 12728258851198019099U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 4144050505314242618U;
            aOrbiterA = RotL64((aOrbiterA * 13629477513971467419U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 14133805325480076530U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 308863673210602899U;
            aOrbiterC = RotL64((aOrbiterC * 2672613556981540433U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 11741180130160569753U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 12926863156769180448U;
            aOrbiterH = RotL64((aOrbiterH * 9726030996091054939U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 211920854786494259U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 13234608842479411078U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2556747209733759467U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 9164711974854618892U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 6667377062281954219U;
            aOrbiterD = RotL64((aOrbiterD * 2603737166987437649U), 53U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterF, 41U);
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 14U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 5U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 41U)) + aOrbiterH) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterC, 56U)) + aOrbiterD) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 6U) + RotL64(aOrbiterD, 27U)) + aOrbiterA) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterD, 13U)) + aPhaseHWandererUpdateSaltC[((aIndex + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 38U));
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 14129U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneC[((aIndex + 15359U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15657U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 11569U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aPrevious, 20U)) + (RotL64(aIngress, 41U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = ((aWandererE + RotL64(aScatter, 48U)) + RotL64(aCarry, 19U)) + 10726035965553989335U;
            aOrbiterJ = (((aWandererK + RotL64(aPrevious, 3U)) + RotL64(aCarry, 39U)) + 967354339530195662U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aCross, 23U)) + 10834593005478605624U;
            aOrbiterD = (((aWandererD + RotL64(aIngress, 57U)) + RotL64(aCarry, 5U)) + 1012888282838656933U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aPrevious, 37U)) + 15283530351725183253U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 11724495956731703750U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 4288330117317505776U;
            aOrbiterB = RotL64((aOrbiterB * 2738997410474076757U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 10894778070022873473U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 15563886747621617467U;
            aOrbiterA = RotL64((aOrbiterA * 17884709931569040065U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 11182488628562891937U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 10420140066310588580U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13898299782819948719U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 11775138062167543111U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 16545391898578161683U;
            aOrbiterJ = RotL64((aOrbiterJ * 14588306527161321535U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 1550144656312299266U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 14903504853138279883U;
            aOrbiterD = RotL64((aOrbiterD * 8003033561266164387U), 51U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterD, 46U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 3U) + RotL64(aOrbiterA, 10U)) + aOrbiterB) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterI, 29U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterD, 41U)) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 22U) + aOrbiterD) + RotL64(aOrbiterB, 21U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 53U) + aOrbiterJ) + RotL64(aOrbiterD, 53U)) + aPhaseHWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 58U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 18059U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((aIndex + 22852U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19493U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18522U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 39U)) + (RotL64(aIngress, 56U) ^ RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 57U)) + 8101351470141807662U) + aPhaseHOrbiterAssignSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = ((aWandererC + RotL64(aCross, 6U)) + RotL64(aCarry, 3U)) + 6965474099521076705U;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 27U)) + 6803828268885684784U) + aPhaseHOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aScatter, 19U)) + RotL64(aCarry, 41U)) + 13454235922950972488U;
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 43U)) + RotL64(aCarry, 27U)) + 11678091885751244777U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 5307134544628507141U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 4873703518950429353U;
            aOrbiterG = RotL64((aOrbiterG * 2680442582958424915U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 8542156221858586039U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 3993726182905296513U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11331376012938127609U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 12113047622035464386U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 1944244448665721151U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7010050836758762003U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 12914188029425467576U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 2486762763475327024U;
            aOrbiterD = RotL64((aOrbiterD * 12319769994433811617U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 14580191602982245481U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 12093414832400135066U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12720286833215690663U), 57U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterD, 47U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 58U));
            aIngress = aIngress + RotL64(aOrbiterB, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aIngress, 53U) + aOrbiterJ) + RotL64(aOrbiterD, 42U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 37U) + aOrbiterB) + RotL64(aOrbiterD, 57U)) + aPhaseHWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 35U)) + aPhaseHWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 12U) + RotL64(aOrbiterG, 29U)) + aOrbiterA);
            aWandererA = aWandererA + (((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 5U)) + aOrbiterA) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + RotL64(aWandererJ, 38U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 31074U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneA[((aIndex + 27004U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29329U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 26127U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 56U) ^ RotL64(aCross, 43U)) ^ (RotL64(aCarry, 5U) + RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (((aWandererD + RotL64(aPrevious, 13U)) + RotL64(aCarry, 23U)) + 9654059367478508868U) + aPhaseHOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = (((aWandererF + RotL64(aScatter, 53U)) + RotL64(aCarry, 43U)) + 6473006635864677427U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aCross, 22U)) + RotL64(aCarry, 3U)) + 6944184481315853243U;
            aOrbiterK = (aWandererG + RotL64(aIngress, 37U)) + 4061496421939102306U;
            aOrbiterC = (aWandererA + RotL64(aCross, 5U)) + 15791809275719085463U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 14050798802646323055U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 12072905924741758266U;
            aOrbiterB = RotL64((aOrbiterB * 4757104346636738119U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 17639076509231343896U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 12195388285571234715U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4317060502521195769U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 4325404419499496529U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 5910567888204238382U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11503787177122206937U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 13092940059929942699U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 13381962590820308761U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6345904465930943295U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 15622862439323440527U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 14027151901132249793U;
            aOrbiterC = RotL64((aOrbiterC * 2273573821630510087U), 53U);
            //
            aIngress = RotL64(aOrbiterB, 43U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterJ, 54U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterB, 43U)) + RotL64(aCarry, 51U)) + aPhaseHWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 37U) + aOrbiterA) + RotL64(aOrbiterC, 35U)) + aPhaseHWandererUpdateSaltB[((aIndex + 16U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 27U) + aOrbiterA) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 23U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 3U) + aOrbiterB) + RotL64(aOrbiterK, 22U));
            aWandererF = aWandererF + ((RotL64(aIngress, 50U) + RotL64(aOrbiterK, 13U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + RotL64(aWandererF, 19U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
