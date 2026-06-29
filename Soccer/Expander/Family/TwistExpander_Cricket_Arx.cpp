#include "TwistExpander_Cricket_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Cricket_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xD58FE7F2C36179B3ULL + 0xEF03E61A55EBFCAFULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x8970DB7F0FB422A7ULL + 0xC15514BEDFAE82FFULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xDBFF0AD7FE70AAC5ULL + 0x908FF90554867586ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xA1221BDAB00AF2B5ULL + 0xD5810451CD64C2C4ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xD53D715FCD36D9F9ULL + 0xF591603EA51F020FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xC2A4F022A2BA345BULL + 0xC23043E299A3EA69ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xFD962F058199B027ULL + 0x81C460782BA9044CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x9715523392674F5BULL + 0xEA60E9C168367974ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xADFC58636E8313CBULL + 0x95CC359641AE13D1ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xEAE08C7470A8873BULL + 0x90F48FBFBE91D837ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xE71F927A65CBB069ULL + 0xF0DD48675840CABBULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xB494846A498EC1F9ULL + 0xF3D25B32E3C38F2AULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x8A8D17C17C6A215DULL + 0x84EC7D76A73EA025ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xDECEDB155F01BBF5ULL + 0xA60BF34459C8328FULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xC286DF4651851EF5ULL + 0x9432EAC450826EB2ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xFC36A2836D9EDF1DULL + 0xD55C04E9E7493BDFULL);
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
            aIngress = RotL64(mSource[((aIndex + 4384U)) & S_BLOCK1], 28U) ^ RotL64(pSnow[((aIndex + 1897U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 827U)) & S_BLOCK1], 19U) ^ RotL64(mSource[((aIndex + 2469U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aIngress, 60U)) ^ (RotL64(aCarry, 37U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterC = ((((aWandererB + RotL64(aCross, 14U)) + RotL64(aCarry, 41U)) + 17711946802293254150U) + aOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1]) + aNonceWordI;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 51U)) + RotL64(aCarry, 51U)) + 16652362590489569378U;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 27U)) + RotL64(aCarry, 11U)) + 6972810344198183097U;
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 19U)) + 13117100889782940546U) + aNonceWordB;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 37U)) + 13199305696782626591U;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 47U)) + 992156184392760945U;
            aOrbiterF = (aWandererI + RotL64(aCross, 41U)) + 13791265442074543880U;
            aOrbiterI = (aWandererD + RotL64(aIngress, 29U)) + 17057087245252294859U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 39U)) + 13444195995883541046U) + aOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = ((aWandererA + RotL64(aScatter, 23U)) + 6723678233676059420U) + aNonceWordN;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 58U)) + 7913379431208430475U) + aNonceWordE;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 4481887195529300665U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 11892724101424384078U;
            aOrbiterG = RotL64((aOrbiterG * 3468639499716604111U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 7700902083270424194U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 1888001433557140271U;
            aOrbiterE = RotL64((aOrbiterE * 8975562955027025349U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 14996753906788986929U) + aNonceWordC;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 939004845422123765U) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 2507090308972292313U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 11922230289291941807U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 15681187459741147199U;
            aOrbiterI = RotL64((aOrbiterI * 10124947739653819101U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 9119043713532718155U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 8327697433992362166U;
            aOrbiterJ = RotL64((aOrbiterJ * 11157657162184304567U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 13630755116592440359U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterJ) ^ 771252613886022889U) ^ aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 2958918915223536519U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 8524239721467527770U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 17732617735422435572U) ^ aNonceWordH;
            aOrbiterB = RotL64((aOrbiterB * 13992947983987668631U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 5265753270696005619U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 14456128349522985053U;
            aOrbiterC = RotL64((aOrbiterC * 5406509991740849617U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 12909993509014176457U) + aOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 10113568710432654194U;
            aOrbiterA = RotL64((aOrbiterA * 6857806395910432831U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 14818978163348513071U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 17843349910031998923U;
            aOrbiterK = RotL64((aOrbiterK * 13608449524810499593U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 12589077818524017161U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 17711946802293254150U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9454569713107675231U), 3U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterF, 13U);
            aIngress = aIngress + (RotL64(aOrbiterE, 44U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 53U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + RotL64(aOrbiterD, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterC, 54U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 51U) + aOrbiterE) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 19U)) + aWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterK, 3U)) + aNonceWordL) + aWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterE, 23U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 14U) + aOrbiterG) + RotL64(aOrbiterH, 5U));
            aWandererG = aWandererG + (((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterF, 13U)) + aNonceWordF);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 39U) + aOrbiterD) + RotL64(aOrbiterI, 51U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterB, 41U)) + aOrbiterC) + RotL64(aCarry, 29U)) + aNonceWordO);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterI, 46U));
            aWandererB = aWandererB + (((RotL64(aScatter, 46U) + RotL64(aOrbiterG, 39U)) + aOrbiterC) + aNonceWordD);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 53U) + aOrbiterA) + RotL64(aOrbiterE, 43U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 48U));
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 58U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererF, 39U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 5948U)) & S_BLOCK1], 3U) ^ RotL64(mSource[((aIndex + 7544U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10748U)) & S_BLOCK1], 3U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 7950U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 42U)) ^ (RotL64(aCarry, 29U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterF = ((aWandererI + RotL64(aScatter, 13U)) + RotL64(aCarry, 19U)) + 8866844335448071821U;
            aOrbiterG = (aWandererA + RotL64(aCross, 23U)) + 15159698739856430085U;
            aOrbiterB = (aWandererH + RotL64(aIngress, 39U)) + 9582805772989594633U;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 43U)) + 1438538239931588373U;
            aOrbiterD = (((aWandererB + RotL64(aIngress, 30U)) + RotL64(aCarry, 51U)) + 10862044156620436139U) + aNonceWordJ;
            aOrbiterA = ((aWandererK + RotL64(aCross, 47U)) + 13682173320058164615U) + aNonceWordH;
            aOrbiterK = (aWandererC + RotL64(aPrevious, 37U)) + 8351013291045977592U;
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 19U)) + 15777857431516633916U) + aNonceWordD;
            aOrbiterH = ((aWandererD + RotL64(aCross, 35U)) + 16178966745333885377U) + aOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aIngress, 51U)) + 9031889187993001617U) + aNonceWordL;
            aOrbiterC = (((aWandererG + RotL64(aPrevious, 28U)) + RotL64(aCarry, 39U)) + 6308472367425865347U) + aOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 642109145903321046U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 9186268569255318035U;
            aOrbiterB = RotL64((aOrbiterB * 10714674348507516749U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 6091345356803675860U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 13218507921880873749U;
            aOrbiterD = RotL64((aOrbiterD * 15415157927185637717U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 4266652275234474616U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 4391422098164506195U) ^ aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17634679403195085867U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 5160682323243635577U) + aOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 10351728852161347404U;
            aOrbiterG = RotL64((aOrbiterG * 11105410036471745951U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 3950932176454814023U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 9536466386833427441U) ^ aOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 18064984243491293435U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 9927425919978776529U) + aNonceWordP;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 6819384090527481081U;
            aOrbiterC = RotL64((aOrbiterC * 18032965969184368561U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 1646274931424218507U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 16166524473976135097U;
            aOrbiterJ = RotL64((aOrbiterJ * 11672192658072663849U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 11252501968059485262U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 16847854447987609067U;
            aOrbiterE = RotL64((aOrbiterE * 6326299154627028295U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 16723218285355036446U) + aNonceWordE;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 13870211254243048975U;
            aOrbiterF = RotL64((aOrbiterF * 10203222183774624097U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 11401147367366049493U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 4266628469244269926U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2409934496621365221U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 11578385782347296942U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 8866844335448071821U;
            aOrbiterK = RotL64((aOrbiterK * 6456956795450036515U), 57U);
            //
            aIngress = RotL64(aOrbiterD, 53U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + RotL64(aOrbiterI, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 23U) + aOrbiterI) + RotL64(aOrbiterG, 39U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterJ, 27U)) + RotL64(aCarry, 23U)) + aNonceWordA);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 38U) + RotL64(aOrbiterJ, 5U)) + aOrbiterI);
            aWandererE = aWandererE + ((RotL64(aCross, 27U) + RotL64(aOrbiterI, 41U)) + aOrbiterA);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterD, 35U)) + aOrbiterA);
            aWandererG = aWandererG + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 13U)) + aOrbiterD) + RotL64(aCarry, 13U)) + aNonceWordF);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 6U) + RotL64(aOrbiterE, 22U)) + aOrbiterK);
            aWandererJ = aWandererJ + (((RotL64(aCross, 47U) + RotL64(aOrbiterD, 51U)) + aOrbiterB) + aWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 57U)) + aOrbiterH);
            aWandererH = aWandererH + (((RotL64(aScatter, 53U) + aOrbiterI) + RotL64(aOrbiterK, 19U)) + aWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterI, 44U)) + aOrbiterH) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 12U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 16107U)) & S_BLOCK1], 27U) ^ RotL64(mSource[((aIndex + 14917U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 14161U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11307U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 21U)) + (RotL64(aCarry, 40U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterD = (aWandererH + RotL64(aScatter, 56U)) + 5697928251815176134U;
            aOrbiterI = ((aWandererC + RotL64(aCross, 21U)) + 337587740689259575U) + aNonceWordM;
            aOrbiterK = (aWandererG + RotL64(aIngress, 3U)) + 4927686903263973950U;
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 19U)) + 3742409032569801033U) + aNonceWordJ;
            aOrbiterA = ((aWandererA + RotL64(aIngress, 53U)) + 1608092659172197650U) + aNonceWordD;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 39U)) + 15848744267145717509U) + aNonceWordE;
            aOrbiterG = (aWandererK + RotL64(aCross, 13U)) + 15300174177963339253U;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 51U)) + 14162868453323648628U;
            aOrbiterF = (((aWandererF + RotL64(aCross, 58U)) + RotL64(aCarry, 27U)) + 12020167069983729869U) + aOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = (((aWandererB + RotL64(aIngress, 37U)) + RotL64(aCarry, 51U)) + 16259538291658723956U) + aOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = ((aWandererI + RotL64(aScatter, 35U)) + RotL64(aCarry, 43U)) + 8516686212464112245U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 3722184575520553132U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 5663609293306386784U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14364218128780764749U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 15265344442454471986U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 3050323350098829515U) ^ aNonceWordB;
            aOrbiterE = RotL64((aOrbiterE * 5890624677162388135U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 1093356813820599238U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 15167726103772238440U;
            aOrbiterD = RotL64((aOrbiterD * 5719466863561311069U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 15170797965325981472U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 17826286701992981628U) ^ aOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11186808881726573677U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 14710892030473425181U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 397194787697553904U;
            aOrbiterG = RotL64((aOrbiterG * 14368930300818752833U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 1273724124862533034U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 13018397560392545616U;
            aOrbiterJ = RotL64((aOrbiterJ * 4644812473262395329U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 9638716186445643730U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 7255587739807843785U;
            aOrbiterB = RotL64((aOrbiterB * 6055682981584011189U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 9272350563697399628U) + aNonceWordK;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 1040729335295009339U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17825687660830291443U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 12128124729613601747U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 2285238815562202219U;
            aOrbiterH = RotL64((aOrbiterH * 15398840993074390573U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 6339113298619163493U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 5911895708485037040U) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 3271006139923200439U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 7601399508218901328U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 5697928251815176134U;
            aOrbiterC = RotL64((aOrbiterC * 8184257916861355735U), 11U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 30U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + (RotL64(aOrbiterF, 53U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + RotL64(aOrbiterG, 4U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterG, 27U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 41U) + aOrbiterF) + RotL64(aOrbiterH, 60U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 51U)) + aOrbiterA) + RotL64(aCarry, 23U)) + aWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterK, 39U)) + aOrbiterF);
            aWandererD = aWandererD + ((RotL64(aPrevious, 22U) + aOrbiterE) + RotL64(aOrbiterF, 47U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterA, 41U));
            aWandererG = aWandererG + ((RotL64(aScatter, 39U) + RotL64(aOrbiterD, 19U)) + aOrbiterB);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 5U) + aOrbiterI) + RotL64(aOrbiterH, 4U)) + aNonceWordO);
            aWandererJ = aWandererJ + (((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 43U) + aOrbiterB) + RotL64(aOrbiterE, 21U)) + aNonceWordF);
            aWandererA = aWandererA + ((((RotL64(aIngress, 14U) + RotL64(aOrbiterE, 37U)) + aOrbiterJ) + aNonceWordG) + aWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 56U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererH, 26U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 16416U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21844U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 21068U)) & S_BLOCK1], 47U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 17515U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17717U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCarry, 43U)) ^ (RotL64(aIngress, 5U) + RotL64(aCross, 56U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterC = (aWandererF + RotL64(aScatter, 43U)) + 13442819395490639310U;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 35U)) + 8187292523194120936U) + aOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = (aWandererG + RotL64(aCross, 30U)) + 11469697159823131388U;
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 23U)) + 13414083692375929653U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 19U)) + 11404010733687907517U) + aNonceWordD;
            aOrbiterH = (((aWandererD + RotL64(aCross, 39U)) + RotL64(aCarry, 35U)) + 6783212827186218247U) + aNonceWordA;
            aOrbiterE = (aWandererH + RotL64(aPrevious, 3U)) + 8561131439340372614U;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 60U)) + RotL64(aCarry, 11U)) + 6252609642004429113U;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 13U)) + RotL64(aCarry, 27U)) + 12804867444200448952U;
            aOrbiterI = (aWandererE + RotL64(aIngress, 11U)) + 2739648749603690781U;
            aOrbiterK = ((aWandererI + RotL64(aScatter, 53U)) + 14808861217017399752U) + aOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 17588866502571268888U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 5882260142735642980U;
            aOrbiterA = RotL64((aOrbiterA * 7688252946143263869U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 15493099088132862949U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 5175647411532429582U;
            aOrbiterG = RotL64((aOrbiterG * 15226544495598541883U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 14279707376173642767U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 6826363572161275158U;
            aOrbiterE = RotL64((aOrbiterE * 5263708315440161809U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 13267185753040999992U) + aNonceWordE;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 9980987858092888720U;
            aOrbiterF = RotL64((aOrbiterF * 13210290848800728635U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 3582972937645514549U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 10140409019562890804U;
            aOrbiterJ = RotL64((aOrbiterJ * 6944490201647678479U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 6160444117287330557U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 16344602960561293113U;
            aOrbiterK = RotL64((aOrbiterK * 2319964919335633293U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 3497141036108337171U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 91269118352540308U) ^ aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5160060720189045505U), 23U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterK) + 12739932748793144857U) + aOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1]) + aNonceWordC;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 12820180915064791197U;
            aOrbiterI = RotL64((aOrbiterI * 5843849637411948699U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 17572075652083359962U) + aNonceWordK;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 10684041099654982701U;
            aOrbiterD = RotL64((aOrbiterD * 7121293375756263771U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 10739534650885677354U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 9731206787727954809U;
            aOrbiterH = RotL64((aOrbiterH * 3730875775588585547U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 9655432616347117764U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 13442819395490639310U) ^ aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3650859301708619119U), 53U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterF, 23U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterI, 26U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 39U));
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterK, 39U)) + aOrbiterB);
            aWandererE = aWandererE + (((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterE, 41U)) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 53U) + aOrbiterJ) + RotL64(aOrbiterK, 37U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 58U) + aOrbiterC) + RotL64(aOrbiterE, 26U)) + aNonceWordP);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterI, 3U)) + aOrbiterD) + aNonceWordO);
            aWandererD = aWandererD + ((RotL64(aScatter, 21U) + aOrbiterC) + RotL64(aOrbiterA, 11U));
            aWandererF = aWandererF ^ ((((RotL64(aCross, 37U) + aOrbiterG) + RotL64(aOrbiterE, 21U)) + aNonceWordM) + aWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 47U)) + aOrbiterJ) + aNonceWordH);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 26U) + RotL64(aOrbiterH, 13U)) + aOrbiterD);
            aWandererA = aWandererA + (((RotL64(aScatter, 47U) + aOrbiterC) + RotL64(aOrbiterK, 30U)) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterF, 19U)) + aOrbiterH) + aWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 46U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 4U));
            aCarry = aCarry + RotL64(aWandererB, 23U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 23698U)) & S_BLOCK1], 21U) ^ RotL64(mSource[((aIndex + 25202U)) & S_BLOCK1], 12U));
            aIngress ^= (RotL64(pSnow[((aIndex + 23817U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((aIndex + 23224U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 22298U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22640U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 41U)) + (RotL64(aPrevious, 20U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterG = ((aWandererA + RotL64(aCross, 26U)) + 7632760812370906911U) + aNonceWordM;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 13U)) + RotL64(aCarry, 11U)) + 6007174525479723089U;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 43U)) + RotL64(aCarry, 5U)) + 3362829642521821048U;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 5U)) + 18009548556107978286U) + aNonceWordP;
            aOrbiterE = (aWandererF + RotL64(aCross, 29U)) + 17880909432272697327U;
            aOrbiterB = (((aWandererG + RotL64(aIngress, 48U)) + RotL64(aCarry, 19U)) + 15961567935420752568U) + aOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aScatter, 37U)) + 10136559064656837921U;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 51U)) + 17622019364405410277U;
            aOrbiterF = (aWandererK + RotL64(aCross, 23U)) + 6927494824421416306U;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 21U)) + 7125170407794874847U) + aOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aIngress, 3U)) + 12342273503071032250U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 14997696377476124836U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 14874498694181230698U) ^ aOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4026127545746010937U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 2549397729130885686U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 4217995818662767955U;
            aOrbiterB = RotL64((aOrbiterB * 5525525344485251063U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 4706089044415442525U) + aNonceWordH;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 17983900172670031015U;
            aOrbiterC = RotL64((aOrbiterC * 541552737180932879U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 1904937798143929988U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 10620877287033139483U;
            aOrbiterJ = RotL64((aOrbiterJ * 16711012562024287213U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 15681091173163181525U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 2655543246639000084U;
            aOrbiterE = RotL64((aOrbiterE * 16686375598149755947U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 2647895110857289213U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 5581609212017175954U) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 15330263616699031311U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 13609076329627787987U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 6244266279516622070U;
            aOrbiterD = RotL64((aOrbiterD * 12488345779236971095U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 5289624364508923581U) + aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 16351476803965903112U;
            aOrbiterG = RotL64((aOrbiterG * 9012522724650442597U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 2731198704224650506U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 4177455951984414332U;
            aOrbiterA = RotL64((aOrbiterA * 2567165277406175517U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 3031687737578718714U) + aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 4866790771642413883U;
            aOrbiterK = RotL64((aOrbiterK * 1139524449666360541U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 12903299652398385014U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 7632760812370906911U;
            aOrbiterF = RotL64((aOrbiterF * 7924544687662448385U), 27U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 46U);
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterA, 42U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 24U) + RotL64(aOrbiterK, 26U)) + aOrbiterB) + aWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 37U) + aOrbiterD) + RotL64(aOrbiterE, 37U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 19U)) + aOrbiterH);
            aWandererF = aWandererF + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 47U)) + aOrbiterD);
            aWandererH = aWandererH ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterA, 53U)) + aOrbiterJ) + aNonceWordJ);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterH, 39U)) + RotL64(aCarry, 5U)) + aWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 21U)) + aOrbiterE) + aNonceWordE);
            aWandererI = aWandererI + (((RotL64(aIngress, 19U) + RotL64(aOrbiterJ, 5U)) + aOrbiterD) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 60U) + RotL64(aOrbiterG, 35U)) + aOrbiterF) + aNonceWordA);
            aWandererB = aWandererB + ((RotL64(aCross, 39U) + RotL64(aOrbiterJ, 30U)) + aOrbiterH);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterE, 43U)) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererH, 30U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 24U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 30320U)) & S_BLOCK1], 51U) ^ RotL64(pSnow[((aIndex + 28250U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 27669U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 30623U)) & S_BLOCK1], 21U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29066U)) & S_BLOCK1], 54U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32683U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 43U)) + (RotL64(aCross, 5U) ^ RotL64(aIngress, 22U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterA = (aWandererD + RotL64(aIngress, 29U)) + 9446153639709651566U;
            aOrbiterC = ((aWandererB + RotL64(aScatter, 11U)) + 10550762260670758167U) + aNonceWordJ;
            aOrbiterF = ((aWandererC + RotL64(aCross, 51U)) + 7062634922142578383U) + aOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = (aWandererA + RotL64(aPrevious, 41U)) + 9178499097812764515U;
            aOrbiterB = (((aWandererE + RotL64(aCross, 34U)) + RotL64(aCarry, 13U)) + 6887103379773525538U) + aNonceWordK;
            aOrbiterD = (aWandererI + RotL64(aScatter, 19U)) + 6239750312052010257U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 43U)) + 17645022614523287959U) + aNonceWordO;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 23U)) + 3639618183259408272U;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 48U)) + RotL64(aCarry, 19U)) + 3131737117548745095U;
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 27U)) + RotL64(aCarry, 51U)) + 7253994382396406554U;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 53U)) + 15217993711938379561U) + aOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 12594152227603630033U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 11250170200489647869U;
            aOrbiterF = RotL64((aOrbiterF * 546800378327864723U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 12936942656624279424U) + aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 10990736056052106149U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7123916809953459187U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 12787293075893090465U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 17154990205620778151U;
            aOrbiterA = RotL64((aOrbiterA * 10031369940028159521U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 1270827262969060301U) + aNonceWordI;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 17337623431665013136U;
            aOrbiterI = RotL64((aOrbiterI * 1517262088236356107U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 830330490987911853U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 6828309232554560547U) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 9742464176986145819U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 11470087853413986203U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 10470148870747884420U;
            aOrbiterC = RotL64((aOrbiterC * 6766079738799967443U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 18315536891901859637U) + aOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 12264670822285914271U) ^ aNonceWordL;
            aOrbiterK = RotL64((aOrbiterK * 5841574505408674119U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 10931842095884524879U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 11134871340959676257U;
            aOrbiterE = RotL64((aOrbiterE * 11714837622285605745U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 11484168476761306078U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 5964766416973454097U;
            aOrbiterJ = RotL64((aOrbiterJ * 14721123403032510803U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 10646362765367117994U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 8994267196877016381U;
            aOrbiterG = RotL64((aOrbiterG * 17386417559346134797U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 16797547458402042464U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 9446153639709651566U) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 567585472220695323U), 43U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterH, 27U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 54U));
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + RotL64(aOrbiterD, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterI, 34U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterD, 19U)) + aOrbiterE);
            aWandererA = aWandererA + (((RotL64(aIngress, 47U) + RotL64(aOrbiterH, 27U)) + aOrbiterI) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 34U) + RotL64(aOrbiterJ, 47U)) + aOrbiterF);
            aWandererH = aWandererH + ((RotL64(aCross, 11U) + RotL64(aOrbiterD, 23U)) + aOrbiterA);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterC, 43U)) + aOrbiterB) + aWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterG, 11U)) + aWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 53U) + aOrbiterK) + RotL64(aOrbiterC, 4U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterD, 29U)) + aOrbiterJ) + RotL64(aCarry, 27U)) + aNonceWordA);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterA, 57U)) + aOrbiterC) + aNonceWordM);
            aWandererD = aWandererD + ((RotL64(aCross, 26U) + RotL64(aOrbiterE, 39U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererI, 28U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 30U));
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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

void TwistExpander_Cricket_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xB25A2E1F897B1575ULL + 0xA1BFE09CC822599CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x9498A74B0BFCD1B5ULL + 0x8092A3343962D863ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x935DD823C46476E3ULL + 0x956136734746B54BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x8E117967B9835FF5ULL + 0xA42FD19DD24EE820ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x8368F035D2AE5C8BULL + 0xB41173E9FD90EFAEULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x9B8F4134E0ACBE4DULL + 0xE7573B9AAA7FFCF8ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x9A3A2FB2DB2A16FDULL + 0x902304F44F81CCAAULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xC3CFA3C700D6503FULL + 0xBBAAB462E2208842ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x8AEC9DC2904F6B5BULL + 0xAD9DDD2255540A71ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xCEC57221BA6782B3ULL + 0xF747FB7AABAE6487ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xA64716A68C58DB57ULL + 0x92E7CAE9945C57B9ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x929F7900F7759177ULL + 0xCB1A54B1ABAEBB89ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xB59B41C050650FDBULL + 0xABA44D41DC84F5D7ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x94065609320A3EBBULL + 0xF85C0250B64C09CBULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xB7C59D623459C7CFULL + 0x96F78D06860B5EE1ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xD3C4D374C3E7CF53ULL + 0xA01FEF9917456D4FULL);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 3451U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 2488U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 408U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneD[((aIndex + 4201U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aIngress, 14U)) + (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterB = (((aWandererJ + RotL64(aCross, 3U)) + RotL64(aCarry, 51U)) + 13350544654542863236U) + aNonceWordC;
            aOrbiterK = (aWandererE + RotL64(aIngress, 56U)) + 12364346790125404372U;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 23U)) + 9738750172849512764U) + aOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 51U)) + 3781373837635491421U) + aOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aCross, 43U)) + 16635020317512702337U;
            aOrbiterC = (aWandererD + RotL64(aScatter, 36U)) + 5383653921676231276U;
            aOrbiterI = (((aWandererI + RotL64(aIngress, 19U)) + RotL64(aCarry, 23U)) + 10181959815492056493U) + aNonceWordE;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 11U)) + 10005510924273927017U) + aNonceWordI;
            aOrbiterD = (((aWandererH + RotL64(aScatter, 29U)) + RotL64(aCarry, 3U)) + 9524687662265740565U) + aNonceWordN;
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 4259138552009771014U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterB) ^ 8973051213213726023U) ^ aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterH = RotL64((aOrbiterH * 12625091476068190979U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 17602611840127337490U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 8218984546932905269U;
            aOrbiterJ = RotL64((aOrbiterJ * 17504305273683304231U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 18102186122213487888U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterC) ^ 2629927500298092976U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 6983280164448292723U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 2491581597835795234U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 9506602492971620955U;
            aOrbiterG = RotL64((aOrbiterG * 9559829640915637163U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 13422942713680612924U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 15037354693234876601U;
            aOrbiterC = RotL64((aOrbiterC * 12692376075738621447U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 12896066842192894694U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 2202952306291905855U;
            aOrbiterA = RotL64((aOrbiterA * 6779368532763429997U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 12160313482450599313U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 10812986281270407756U;
            aOrbiterI = RotL64((aOrbiterI * 7786608700746771809U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 12474638293190144525U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 5882870951276225224U;
            aOrbiterD = RotL64((aOrbiterD * 15532427302173572457U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 3782896138051179209U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 10965680631059882311U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14060923998307082385U), 27U);
            //
            aIngress = RotL64(aOrbiterK, 40U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + RotL64(aOrbiterH, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 27U) + aOrbiterK) + RotL64(aOrbiterC, 23U)) + aNonceWordK);
            aWandererE = aWandererE + ((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 18U)) + aOrbiterK);
            aWandererG = aWandererG ^ (((RotL64(aCross, 23U) + aOrbiterK) + RotL64(aOrbiterD, 29U)) + aNonceWordF);
            aWandererB = aWandererB + ((RotL64(aPrevious, 60U) + RotL64(aOrbiterC, 43U)) + aOrbiterG);
            aWandererF = aWandererF ^ ((((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterB, 53U)) + aNonceWordA) + aWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 37U) + aOrbiterG) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterJ, 34U)) + aOrbiterH) + aNonceWordD) + aWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 39U)) + aOrbiterA) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 54U) + RotL64(aOrbiterI, 11U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererF, 19U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 13786U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneB[((aIndex + 10179U)) & S_BLOCK1], 34U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 9059U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 10304U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 14939U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 36U) + RotL64(aIngress, 5U)) ^ (RotL64(aCross, 57U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterC = (aWandererA + RotL64(aIngress, 14U)) + 5697928251815176134U;
            aOrbiterH = ((aWandererE + RotL64(aCross, 3U)) + 337587740689259575U) + aNonceWordM;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 47U)) + RotL64(aCarry, 51U)) + 4927686903263973950U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 19U)) + 3742409032569801033U) + aNonceWordO;
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 43U)) + 1608092659172197650U) + aNonceWordL;
            aOrbiterF = ((aWandererC + RotL64(aCross, 30U)) + RotL64(aCarry, 43U)) + 15848744267145717509U;
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 23U)) + 15300174177963339253U) + aOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aIngress, 39U)) + RotL64(aCarry, 23U)) + 14162868453323648628U;
            aOrbiterG = (((aWandererB + RotL64(aCross, 51U)) + 12020167069983729869U) + aOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordI;
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 16259538291658723956U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 8516686212464112245U;
            aOrbiterI = RotL64((aOrbiterI * 4731296903548893627U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 3722184575520553132U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 5663609293306386784U;
            aOrbiterF = RotL64((aOrbiterF * 14364218128780764749U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 15265344442454471986U) + aNonceWordC;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 3050323350098829515U;
            aOrbiterH = RotL64((aOrbiterH * 5890624677162388135U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 1093356813820599238U) + aNonceWordK;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 15167726103772238440U) ^ aNonceWordD;
            aOrbiterE = RotL64((aOrbiterE * 5719466863561311069U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 15170797965325981472U) + aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 17826286701992981628U;
            aOrbiterK = RotL64((aOrbiterK * 11186808881726573677U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 14710892030473425181U) + aNonceWordB;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 397194787697553904U;
            aOrbiterG = RotL64((aOrbiterG * 14368930300818752833U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 1273724124862533034U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 13018397560392545616U) ^ aOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4644812473262395329U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 9638716186445643730U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 7255587739807843785U) ^ aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6055682981584011189U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 9272350563697399628U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 1040729335295009339U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17825687660830291443U), 3U);
            //
            aIngress = RotL64(aOrbiterG, 13U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + (RotL64(aOrbiterF, 38U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterE, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 35U) + aOrbiterE) + RotL64(aOrbiterJ, 19U)) + aNonceWordA);
            aWandererB = aWandererB + (((RotL64(aIngress, 30U) + RotL64(aOrbiterF, 4U)) + aOrbiterK) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterC, 39U)) + aNonceWordF);
            aWandererC = aWandererC + ((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 29U)) + aOrbiterK);
            aWandererK = aWandererK ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterK, 57U)) + aOrbiterG);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 18U) + RotL64(aOrbiterE, 11U)) + aOrbiterF) + RotL64(aCarry, 19U)) + aWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterA, 23U)) + aNonceWordJ) + aWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 23U) + aOrbiterJ) + RotL64(aOrbiterH, 43U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterA, 48U)) + aOrbiterI) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 10U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 53U);
            aCarry = aCarry + RotL64(aIngress, 40U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 17147U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneD[((aIndex + 23964U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 20788U)) & S_BLOCK1], 18U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18937U)) & S_BLOCK1], 23U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 16769U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 18368U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 27U) + RotL64(aCross, 39U)) ^ (RotL64(aCarry, 53U) + RotL64(aPrevious, 10U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 26U)) + RotL64(aCarry, 13U)) + 6163290588946759209U;
            aOrbiterE = ((((aWandererC + RotL64(aScatter, 13U)) + RotL64(aCarry, 23U)) + 7342672468560105447U) + aOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1]) + aNonceWordG;
            aOrbiterH = (((aWandererE + RotL64(aIngress, 47U)) + RotL64(aCarry, 37U)) + 11574563167017282321U) + aNonceWordD;
            aOrbiterA = (aWandererB + RotL64(aCross, 35U)) + 2254820206194758964U;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 18U)) + 1469783447473099498U;
            aOrbiterK = (aWandererG + RotL64(aScatter, 39U)) + 14174828900676165088U;
            aOrbiterG = ((aWandererH + RotL64(aCross, 51U)) + 16277954291890598132U) + aNonceWordM;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 3U)) + 14845750668693136766U) + aOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aCross, 43U)) + 150099699692047766U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 1200784917165131703U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 9469982764806754302U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17851969334511301943U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 10956702761701710182U) + aNonceWordL;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 7915506894975487807U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8874108311712727983U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 17335794183733623213U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 557028996286989506U;
            aOrbiterC = RotL64((aOrbiterC * 3993359298602424281U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 1597385667771002414U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 4376417959915162639U;
            aOrbiterD = RotL64((aOrbiterD * 4626236858205178149U), 47U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterG) + 549770198518993876U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 756554555648070919U;
            aOrbiterB = RotL64((aOrbiterB * 16272320259614325355U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 7298557532533152193U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 3336802611342112013U;
            aOrbiterI = RotL64((aOrbiterI * 14679103452120080499U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 2314938232094714365U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 12215066333571149153U;
            aOrbiterG = RotL64((aOrbiterG * 10747052773052630601U), 5U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterI) + 7762752719356805046U) + aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1]) + aNonceWordB;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 6519429915769040078U;
            aOrbiterE = RotL64((aOrbiterE * 15548676502167938513U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 7556691736109752918U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 13731245903412646404U;
            aOrbiterA = RotL64((aOrbiterA * 15581965016668635409U), 23U);
            //
            aIngress = RotL64(aOrbiterA, 51U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterG, 24U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterH, 43U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aIngress, 52U) + RotL64(aOrbiterD, 47U)) + aOrbiterI) + RotL64(aCarry, 37U)) + aNonceWordO);
            aWandererB = aWandererB ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterH, 43U)) + aOrbiterC);
            aWandererD = aWandererD + ((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 18U)) + aOrbiterH);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 19U) + aOrbiterA) + RotL64(aOrbiterE, 23U)) + aWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 13U) + RotL64(aOrbiterC, 39U)) + aOrbiterB);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 3U)) + aOrbiterG);
            aWandererH = aWandererH + (((RotL64(aCross, 39U) + RotL64(aOrbiterI, 52U)) + aOrbiterK) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 35U)) + aOrbiterH) + aWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 30U) + RotL64(aOrbiterE, 57U)) + aOrbiterK) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererG, 10U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + RotL64(aWandererA, 24U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 30790U)) & S_BLOCK1], 24U) ^ RotL64(aFireLaneC[((aIndex + 32723U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 27270U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28315U)) & S_BLOCK1], 37U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 25526U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 30005U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 51U) ^ RotL64(aCross, 37U)) + (RotL64(aCarry, 19U) + RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 5U)) + RotL64(aCarry, 35U)) + 13296600294247799698U;
            aOrbiterG = (((aWandererD + RotL64(aIngress, 47U)) + 5818503518080877515U) + aOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordA;
            aOrbiterF = ((aWandererA + RotL64(aCross, 53U)) + RotL64(aCarry, 5U)) + 6735784238734173597U;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 23U)) + RotL64(aCarry, 19U)) + 7368398209488856201U;
            aOrbiterK = ((aWandererC + RotL64(aIngress, 34U)) + 961734029066455638U) + aNonceWordM;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 57U)) + 797011946660892011U) + aOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aCross, 19U)) + 12841876018396622350U) + aNonceWordE;
            aOrbiterH = (aWandererE + RotL64(aScatter, 29U)) + 16213253970483895623U;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 14U)) + 15186950557113470375U) + aNonceWordN;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 5117930310827477341U) + aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 12265429373166094162U;
            aOrbiterF = RotL64((aOrbiterF * 1522823535151532249U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 13920531346698601568U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 14695405206998211456U;
            aOrbiterC = RotL64((aOrbiterC * 13950964363414164279U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 7851960904825938443U) + aNonceWordC;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 9501511171732550190U) ^ aOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5614164120361489613U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 5663365182245722077U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 9607860124321315555U;
            aOrbiterK = RotL64((aOrbiterK * 3461820361914280601U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 18171052650586819280U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 3442698321538580861U;
            aOrbiterD = RotL64((aOrbiterD * 6317525514963824829U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 1491052813469258970U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 3956599824067616133U;
            aOrbiterG = RotL64((aOrbiterG * 2928600779267623085U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 10963841237346073453U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 2303020125591252534U) ^ aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9969099842343321981U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 14503856057958162356U) + aOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 11147548150090597694U) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 11856382308792700441U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 9191681438318311481U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 13556072770381999852U;
            aOrbiterJ = RotL64((aOrbiterJ * 18316231099054203683U), 11U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 57U);
            aIngress = aIngress + (RotL64(aOrbiterG, 21U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 6U));
            aIngress = aIngress + RotL64(aOrbiterF, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aPrevious, 19U) + aOrbiterA) + RotL64(aOrbiterK, 21U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterB, 12U)) + aOrbiterD);
            aWandererB = aWandererB + (((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 43U)) + aOrbiterH) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 44U) + RotL64(aOrbiterG, 39U)) + aOrbiterC) + aNonceWordP);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterH, 47U)) + aOrbiterJ) + RotL64(aCarry, 27U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 5U)) + aOrbiterK);
            aWandererE = aWandererE + ((((RotL64(aCross, 57U) + RotL64(aOrbiterK, 52U)) + aOrbiterG) + aNonceWordL) + aWandererUpdateSaltF[((aIndex + 8U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterJ, 29U)) + aOrbiterF);
            aWandererA = aWandererA + ((((RotL64(aCross, 48U) + aOrbiterK) + RotL64(aOrbiterB, 57U)) + aNonceWordD) + aWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererC, 39U);
            aCarry = aCarry + RotL64(aIngress, 18U);
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

void TwistExpander_Cricket_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x902DE6A69C0547F9ULL + 0xDD7F6F37C297492DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xB7ECADABBB87AF9FULL + 0x95708F0A5347B713ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xDE36B59946C9BA99ULL + 0x84CC172F24059E92ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB05057B82B232B07ULL + 0xA8E33AEF2864F7EDULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xCDE9B331B8D7A019ULL + 0xDB3A6D096A42A839ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xB259EE25CE9B5971ULL + 0x87E06346466BD11FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xF450B3D95CA39AFDULL + 0xB6B254E5966F5A40ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x94424B64C893BE77ULL + 0x857E753143D7CC98ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xA78F4AD5C6AE06DDULL + 0xD1C1C2E259A0FE0CULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xC7B173DF47A236A7ULL + 0xF915568A651931D1ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xA7AAAE41B5BF7CBBULL + 0xB50BD49AC7B404DCULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xC167F4BC1D72D907ULL + 0xD7000CA196E9FFD4ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xE95D8E02209FA02BULL + 0xD916CF61BF1EA1D4ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x8D19EE2AF6D749EFULL + 0xB1A1987C1BA0E835ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xD15BF71539B76A29ULL + 0xB4CC4F85B762E84AULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xA3E66A77C853F459ULL + 0x95FA357733D9F3C0ULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneA, aOperationLaneC, aOperationLaneD, aWorkLaneA, aFireLaneC, aWorkLaneB, aFireLaneB, aWorkLaneC, aFireLaneD
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 6130U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((aIndex + 825U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 6688U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2274U)) & S_BLOCK1], 34U) ^ RotL64(aOperationLaneD[((aIndex + 7310U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCarry, 54U)) + (RotL64(aPrevious, 39U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterD = ((aWandererF + RotL64(aCross, 53U)) + RotL64(aCarry, 43U)) + 13924571355038625040U;
            aOrbiterC = ((((aWandererD + RotL64(aPrevious, 40U)) + RotL64(aCarry, 57U)) + 16328300979357156658U) + aOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordE;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 11U)) + 3947771961206012461U) + aNonceWordO;
            aOrbiterH = (((aWandererA + RotL64(aIngress, 3U)) + RotL64(aCarry, 29U)) + 15428284250569311285U) + aNonceWordC;
            aOrbiterK = (((aWandererB + RotL64(aPrevious, 23U)) + 5777369485254032486U) + aOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordB;
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 16813320300717644673U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 16689933050200758251U;
            aOrbiterJ = RotL64((aOrbiterJ * 4832495563863469353U), 5U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterJ) + 1856422419049390708U) + aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1]) + aNonceWordF;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 18214498743831925517U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10744120577560529379U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 18278550878494094923U) + aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 797712062039591797U) ^ aNonceWordH;
            aOrbiterC = RotL64((aOrbiterC * 7212998747080137625U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 15854849439012341347U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 996882939768167773U;
            aOrbiterK = RotL64((aOrbiterK * 14936703950807908575U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 3005829974130671692U) + aNonceWordK;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 8793495343509953906U) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 14065479348374612031U), 13U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 13U);
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((((RotL64(aPrevious, 37U) + aOrbiterC) + RotL64(aOrbiterK, 3U)) + RotL64(aCarry, 43U)) + aNonceWordD) + aWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 46U) + RotL64(aOrbiterH, 29U)) + aOrbiterD);
            aWandererB = aWandererB + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 19U)) + aOrbiterH) + RotL64(aCarry, 27U)) + aWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 11U)) + aOrbiterD) + aNonceWordJ);
            aWandererG = aWandererG + (((RotL64(aCross, 23U) + aOrbiterD) + RotL64(aOrbiterC, 52U)) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 11U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 2
        // ingress from: aWorkLaneA, aOperationLaneC, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aOperationLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneD, aOperationLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneD backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 11635U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneC[((aIndex + 12940U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 14288U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 9967U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 15615U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 12153U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aPrevious, 3U)) ^ (RotL64(aIngress, 51U) ^ RotL64(aCarry, 38U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterJ = ((((aWandererA + RotL64(aIngress, 43U)) + RotL64(aCarry, 47U)) + 11480359716598965890U) + aOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1]) + aNonceWordD;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 6U)) + 15431182525482873419U) + aNonceWordP;
            aOrbiterA = ((aWandererF + RotL64(aCross, 27U)) + RotL64(aCarry, 5U)) + 11360504974812776707U;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 19U)) + RotL64(aCarry, 29U)) + 9292576416573382769U;
            aOrbiterC = ((aWandererD + RotL64(aCross, 53U)) + 1549257414531028975U) + aOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 5347769463033129317U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 17019199177478377234U;
            aOrbiterA = RotL64((aOrbiterA * 4336112198640602307U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 16558106007323125094U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 3976182233825939422U) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 4392162052317572289U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 2889047161195954395U) + aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 2241831345026962605U;
            aOrbiterH = RotL64((aOrbiterH * 5757458560979927857U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 12850802412140579294U) + aNonceWordH;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 13541744735436450160U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 906089290000537439U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 2085863085516538212U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterC) ^ 2969034221711544086U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterJ = RotL64((aOrbiterJ * 7768528124408400403U), 13U);
            //
            aIngress = RotL64(aOrbiterA, 29U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterB, 29U)) + aOrbiterJ);
            aWandererA = aWandererA + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 42U)) + aOrbiterJ) + RotL64(aCarry, 47U)) + aWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 54U) + aOrbiterA) + RotL64(aOrbiterH, 3U)) + aWandererUpdateSaltC[((aIndex + 24U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 41U) + aOrbiterH) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 29U)) + aNonceWordG);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterA, 13U)) + aOrbiterC) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererF, 46U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 3
        // ingress from: aWorkLaneB, aOperationLaneD, aFireLaneB
        // ingress directions: aWorkLaneB forward forced, aOperationLaneD forward forced, aFireLaneB forward/backward random
        // cross from: aWorkLaneA, aOperationLaneB, aOperationLaneC
        // cross directions: aWorkLaneA backward forced, aOperationLaneB backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 20011U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneD[((aIndex + 20164U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 22562U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17666U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24286U)) & S_BLOCK1], 12U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 17245U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 22U) ^ RotL64(aIngress, 53U)) + (RotL64(aPrevious, 39U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterA = (aWandererC + RotL64(aScatter, 11U)) + 3612110001869385068U;
            aOrbiterF = (aWandererK + RotL64(aPrevious, 21U)) + 16340824141280225936U;
            aOrbiterB = ((((aWandererD + RotL64(aIngress, 34U)) + RotL64(aCarry, 23U)) + 15222338965130765231U) + aOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordP;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 47U)) + RotL64(aCarry, 47U)) + 6649270508107155041U;
            aOrbiterD = ((((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 768217258655426384U) + aOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1]) + aNonceWordH;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 4481855259658861851U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 18318041934562434016U) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 14913761339765234979U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 4212457153804401807U) + aNonceWordN;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 16143621095636987628U) ^ aOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6576072860505961427U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 2095664232866642086U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 4339527736737366572U;
            aOrbiterJ = RotL64((aOrbiterJ * 17503569508822244125U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 13679353177869884790U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 11582168502846418236U;
            aOrbiterD = RotL64((aOrbiterD * 135539430034462861U), 29U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterJ) + 10451330452898542191U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordE;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 12951448817640617841U) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 4141870904192742091U), 57U);
            //
            aIngress = RotL64(aOrbiterD, 14U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + RotL64(aOrbiterF, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 12U) + aOrbiterD) + RotL64(aOrbiterJ, 3U)) + aNonceWordO);
            aWandererG = aWandererG + ((((RotL64(aScatter, 37U) + RotL64(aOrbiterF, 11U)) + aOrbiterA) + RotL64(aCarry, 37U)) + aNonceWordB);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 29U) + aOrbiterD) + RotL64(aOrbiterB, 57U)) + aWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 47U) + RotL64(aOrbiterF, 48U)) + aOrbiterB) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterF, 19U)) + aNonceWordD) + aWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 60U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aFireLaneD
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aFireLaneD forward/backward random
        // cross from: aWorkLaneB, aOperationLaneC, aOperationLaneD, aOperationLaneA
        // cross directions: aWorkLaneB backward forced, aOperationLaneC backward forced, aOperationLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 30692U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((aIndex + 25198U)) & S_BLOCK1], 38U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 27312U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29145U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 28813U)) & S_BLOCK1], 58U));
            aCross ^= (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 24580U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 25994U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aPrevious, 38U)) ^ (RotL64(aCarry, 57U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterK = ((aWandererI + RotL64(aIngress, 3U)) + 16922357079016918108U) + aOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = (((aWandererJ + RotL64(aCross, 21U)) + RotL64(aCarry, 53U)) + 11771749797137599131U) + aNonceWordE;
            aOrbiterA = ((((aWandererF + RotL64(aPrevious, 11U)) + RotL64(aCarry, 11U)) + 4635668433708036077U) + aOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1]) + aNonceWordN;
            aOrbiterG = (((aWandererE + RotL64(aScatter, 51U)) + RotL64(aCarry, 41U)) + 15827952719230577008U) + aNonceWordF;
            aOrbiterB = (aWandererH + RotL64(aPrevious, 42U)) + 1495675306110023086U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 7294835466949728365U) + aNonceWordG;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 179122461212041978U;
            aOrbiterA = RotL64((aOrbiterA * 14467072888722097971U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 545981421632236251U) + aOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 15338259639814630535U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14895421566334357871U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 12924313840290895215U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 17846785921286020610U;
            aOrbiterI = RotL64((aOrbiterI * 18309347016029917133U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 5721472794107057875U) + aNonceWordD;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 16359630793856870319U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14186771515526698907U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 10614102110239037308U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterG) ^ 16421992251278236531U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 2561232904676068089U), 37U);
            //
            aIngress = RotL64(aOrbiterB, 29U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 54U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 12U)) + aOrbiterA) + aNonceWordJ);
            aWandererF = aWandererF ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterI, 3U)) + aOrbiterA) + aNonceWordP);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 51U) + RotL64(aOrbiterB, 37U)) + aOrbiterG) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 60U) + RotL64(aOrbiterK, 23U)) + aOrbiterB) + aNonceWordC) + aWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererI = aWandererI + (((((RotL64(aIngress, 19U) + RotL64(aOrbiterK, 51U)) + aOrbiterI) + RotL64(aCarry, 23U)) + aNonceWordA) + aWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 56U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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

void TwistExpander_Cricket_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xA6196FB101711881ULL + 0xB4825142091E9EF4ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x84C53B43BA0067A7ULL + 0xAA3EE8402EBB3AB2ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xC4DEBB711BCB26DBULL + 0xE4984227B9AA543EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x91C1E86519ED751FULL + 0xCD2451B6E2668C88ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xBE866F3AC8115C7BULL + 0xDFEAD0B48B8EF51EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xF95574D2FD23F6B7ULL + 0xB118604C57BA2C23ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xD926E5751EF32CE5ULL + 0xD6F1AC685112FB21ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xDBC4BE7E9F97F385ULL + 0xFA42DF77488453C3ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xA4FA8CA302C77141ULL + 0x9881381E51AE5405ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xB378AF0C87592D5BULL + 0xF8101C72C13CC735ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xDBAF0ED63F510BE1ULL + 0xDA4904F9250CBF92ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xCB275B2384D87167ULL + 0xD1978B6F8B65BD77ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xD008BBD11FAC3823ULL + 0xB7180BC3ED4D6332ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xF6A1B2E7F2F19C55ULL + 0xD44D911112E3C1BEULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x8274DADCC550D29BULL + 0xCD7E4D754B9C1E49ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xB1E8B2CB415E1B41ULL + 0xA6C7A5FA88543F3AULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aOperationLaneB, aExpandLaneC, aExpandLaneD, aFireLaneC, aWorkLaneA, aOperationLaneD, aFireLaneA, aWorkLaneB, aFireLaneD, aOperationLaneC, aWorkLaneC, aOperationLaneA, aFireLaneB
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_d loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aOperationLaneB
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aOperationLaneB forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aFireLaneC
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aFireLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3759U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((aIndex + 2263U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 2467U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1514U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3272U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 4115U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 26U) + RotL64(aCross, 5U)) ^ (RotL64(aIngress, 41U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterH = (((aWandererB + RotL64(aIngress, 37U)) + RotL64(aCarry, 35U)) + 4476099022490972343U) + aOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = ((aWandererC + RotL64(aScatter, 47U)) + 16836423700375760429U) + aOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = ((aWandererK + RotL64(aCross, 5U)) + 8850577488928703557U) + aNonceWordL;
            aOrbiterB = (aWandererH + RotL64(aPrevious, 19U)) + 7091631824560042743U;
            aOrbiterG = (((aWandererG + RotL64(aScatter, 13U)) + RotL64(aCarry, 11U)) + 12560498899956759494U) + aNonceWordF;
            aOrbiterF = (aWandererE + RotL64(aCross, 58U)) + 7797973377112012161U;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 29U)) + RotL64(aCarry, 51U)) + 6173820673874805794U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 10805025132310245348U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 7139216143268029968U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8349754682635765573U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 8241544862261635722U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 4735527016563596150U;
            aOrbiterG = RotL64((aOrbiterG * 6621354217673598381U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 5166171126690294033U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 11117641762075368393U;
            aOrbiterI = RotL64((aOrbiterI * 4980156869201219393U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 6312932356458415421U) + aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterA) ^ 1304139291184508668U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 90744653170922319U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 10085025354842771067U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 16745854428789531080U) ^ aNonceWordH;
            aOrbiterF = RotL64((aOrbiterF * 1945983905747274355U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 2497187958708890337U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 16069701876646548995U;
            aOrbiterA = RotL64((aOrbiterA * 16606039730973709495U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 17242004368025978091U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 12334315722243232121U;
            aOrbiterH = RotL64((aOrbiterH * 16528598396696346719U), 27U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterG, 26U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterB, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 21U)) + aOrbiterE) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterA, 60U)) + aNonceWordI);
            aWandererG = aWandererG + ((RotL64(aScatter, 11U) + RotL64(aOrbiterI, 39U)) + aOrbiterF);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterB, 47U)) + aOrbiterG);
            aWandererK = aWandererK + ((((RotL64(aScatter, 50U) + RotL64(aOrbiterF, 13U)) + aOrbiterE) + aNonceWordB) + aWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 35U) + aOrbiterH) + RotL64(aOrbiterG, 5U));
            aWandererE = aWandererE + ((((RotL64(aCross, 43U) + RotL64(aOrbiterB, 27U)) + aOrbiterI) + RotL64(aCarry, 19U)) + aWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 4U));
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + RotL64(aWandererC, 39U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 2
        // ingress from: aWorkLaneA, aExpandLaneC, aOperationLaneD
        // ingress directions: aWorkLaneA forward forced, aExpandLaneC forward forced, aOperationLaneD forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aFireLaneA
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aFireLaneA backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 12776U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneC[((aIndex + 15983U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 14940U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 13531U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9831U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 15375U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 27U)) + (RotL64(aCarry, 40U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterI = (((aWandererF + RotL64(aIngress, 4U)) + RotL64(aCarry, 19U)) + 11521331427196538632U) + aNonceWordC;
            aOrbiterK = (((aWandererG + RotL64(aPrevious, 43U)) + 16653824187682957632U) + aOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordG;
            aOrbiterH = (((aWandererI + RotL64(aScatter, 51U)) + RotL64(aCarry, 35U)) + 11654676587350088289U) + aNonceWordO;
            aOrbiterG = (((aWandererK + RotL64(aCross, 35U)) + 8010313317412193584U) + aOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1]) + aNonceWordP;
            aOrbiterB = (aWandererJ + RotL64(aIngress, 13U)) + 1108775560502907471U;
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 29U)) + RotL64(aCarry, 5U)) + 243952321439823521U;
            aOrbiterF = (aWandererD + RotL64(aScatter, 23U)) + 2324945800401240403U;
            //
            aOrbiterI = (((aOrbiterI + aOrbiterK) + 9257554497543369657U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordB;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 16701314607244592540U) ^ aNonceWordJ;
            aOrbiterH = RotL64((aOrbiterH * 8790054741039817107U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 3900445848034341782U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 7652316487347103658U) ^ aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11480123491361589799U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 14980368605272070578U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 2001165460948764796U) ^ aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8110980921827107649U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 1911044015666991050U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 11366207111147818339U;
            aOrbiterK = RotL64((aOrbiterK * 17234439040652553865U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 16469329744002456607U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 8062793687044950815U) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 5856142259851144369U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 15364721421972807872U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 8979915611483540231U;
            aOrbiterG = RotL64((aOrbiterG * 10899377466171153383U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 7654234623563110457U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 1526832460342135008U) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 12766083052650723051U), 21U);
            //
            aIngress = RotL64(aOrbiterB, 11U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + RotL64(aOrbiterH, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 50U) + RotL64(aOrbiterF, 22U)) + aOrbiterK) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterB, 47U)) + aWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterB, 29U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterF, 35U)) + aOrbiterH) + aNonceWordH);
            aWandererI = aWandererI + ((RotL64(aIngress, 11U) + RotL64(aOrbiterI, 53U)) + aOrbiterF);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 11U)) + aOrbiterG);
            aWandererF = aWandererF + (((((RotL64(aCross, 19U) + RotL64(aOrbiterA, 3U)) + aOrbiterF) + RotL64(aCarry, 35U)) + aNonceWordN) + aWandererUpdateSaltD[((aIndex + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 58U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 3
        // ingress from: aWorkLaneB, aExpandLaneD, aFireLaneD
        // ingress directions: aWorkLaneB forward forced, aExpandLaneD forward forced, aFireLaneD forward/backward random
        // cross from: aWorkLaneA, aExpandLaneB, aOperationLaneC
        // cross directions: aWorkLaneA backward forced, aExpandLaneB backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 17383U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneD[((aIndex + 21298U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 21773U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20870U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 21825U)) & S_BLOCK1], 26U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 17853U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aIngress, 6U)) ^ (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterK = (aWandererI + RotL64(aIngress, 51U)) + 4751694786009671052U;
            aOrbiterI = (((aWandererH + RotL64(aScatter, 27U)) + RotL64(aCarry, 21U)) + 16362725160370844224U) + aNonceWordE;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 43U)) + 6360885380915941057U) + aOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = (aWandererD + RotL64(aCross, 5U)) + 5154536007972297036U;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 57U)) + 9362540581874808253U) + aOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (((aWandererC + RotL64(aCross, 36U)) + RotL64(aCarry, 47U)) + 13902493871525612934U) + aNonceWordC;
            aOrbiterB = (((aWandererF + RotL64(aPrevious, 21U)) + RotL64(aCarry, 5U)) + 10208452885367546542U) + aNonceWordI;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 3117030377279160998U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 17286247690414027870U;
            aOrbiterA = RotL64((aOrbiterA * 4896931759653832095U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 3930314320040949141U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 7289525252391668404U) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 15452162299105112187U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 3434167955466809185U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 17852573095128575663U;
            aOrbiterF = RotL64((aOrbiterF * 1485660158767033425U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 6137259687928853253U) + aOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 13992510605237574698U;
            aOrbiterH = RotL64((aOrbiterH * 15346263295995333395U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 6470556523400123474U) + aOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 4333255670390099293U) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 11089933812030082647U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 7700424876430257995U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 16920736951239453071U;
            aOrbiterB = RotL64((aOrbiterB * 8920407493132380497U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 1635071690430295730U) + aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 9966700845966398620U;
            aOrbiterG = RotL64((aOrbiterG * 17210048121896546867U), 27U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 5U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterK, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aCross, 5U) + RotL64(aOrbiterI, 35U)) + aOrbiterB) + RotL64(aCarry, 19U)) + aWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterH, 13U)) + aOrbiterG);
            aWandererH = aWandererH + (((((RotL64(aIngress, 28U) + RotL64(aOrbiterF, 3U)) + aOrbiterI) + RotL64(aCarry, 37U)) + aNonceWordJ) + aWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 21U) + aOrbiterG) + RotL64(aOrbiterA, 60U)) + aNonceWordF);
            aWandererD = aWandererD + (((RotL64(aCross, 13U) + RotL64(aOrbiterI, 43U)) + aOrbiterK) + aNonceWordL);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterA, 23U));
            aWandererF = aWandererF + (((RotL64(aIngress, 37U) + aOrbiterI) + RotL64(aOrbiterA, 51U)) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 46U));
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aOperationLaneA
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aOperationLaneA forward/backward random
        // cross from: aWorkLaneB, aExpandLaneC, aFireLaneB
        // cross directions: aWorkLaneB backward forced, aExpandLaneC backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 25488U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneA[((aIndex + 27047U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 25817U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29969U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 30359U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 26160U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCarry, 24U)) ^ (RotL64(aCross, 5U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterH = (aWandererK + RotL64(aScatter, 19U)) + 11177787645248006236U;
            aOrbiterI = (((aWandererI + RotL64(aPrevious, 36U)) + RotL64(aCarry, 35U)) + 3808340254579817169U) + aOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aCross, 57U)) + 828030667598518279U;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 47U)) + 16177835921238398371U) + aNonceWordG;
            aOrbiterJ = (((aWandererC + RotL64(aScatter, 13U)) + RotL64(aCarry, 53U)) + 5518747735458708741U) + aOrbiterAssignSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = ((aWandererD + RotL64(aCross, 3U)) + RotL64(aCarry, 23U)) + 17346319082399995165U;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 29U)) + 6397156921893030937U) + aNonceWordD;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 15559381654710713582U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 940404446491415088U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16401260971303026881U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 8047166032048732645U) + aNonceWordE;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 4688468645859470491U) ^ aNonceWordF;
            aOrbiterJ = RotL64((aOrbiterJ * 14383536431614496369U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 3710878044770337260U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterI) ^ 116343189456629220U) ^ aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 5637725064169289339U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 883908030159391659U) + aNonceWordK;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 18058691521694880482U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3132200449123497619U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 17521015077103586117U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 3668332225435714918U) ^ aOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12658899101297839881U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 12229480388278883300U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 16206524049491531816U;
            aOrbiterK = RotL64((aOrbiterK * 11122340196620859805U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 5743265849441077466U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 2812293020719282236U;
            aOrbiterI = RotL64((aOrbiterI * 8903956475200417109U), 29U);
            //
            aIngress = RotL64(aOrbiterF, 21U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 44U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 29U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterH, 3U)) + aOrbiterC);
            aWandererD = aWandererD + ((((RotL64(aScatter, 11U) + aOrbiterJ) + RotL64(aOrbiterK, 41U)) + RotL64(aCarry, 53U)) + aNonceWordH);
            aWandererF = aWandererF ^ (((RotL64(aCross, 23U) + aOrbiterI) + RotL64(aOrbiterG, 57U)) + aNonceWordJ);
            aWandererC = aWandererC + (((RotL64(aIngress, 37U) + aOrbiterJ) + RotL64(aOrbiterG, 10U)) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ ((((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterI, 35U)) + aNonceWordL) + aWandererUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 50U) + aOrbiterH) + RotL64(aOrbiterK, 47U)) + aNonceWordP) + aWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 18U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + RotL64(aWandererJ, 43U);
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

void TwistExpander_Cricket_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xAF0087C998E1A277ULL + 0xD7D58687124DF3CEULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xAAE4659215AE6A49ULL + 0xF70BD1D4E702BBCDULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x9379F742D92170FBULL + 0xF677043599A8DFC5ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB08974400C6991D9ULL + 0xBDADC19D00FE1505ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xF54077EE8DFDEA23ULL + 0xFDD1691885B5C121ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x9A2F2BC729E32F53ULL + 0xD83E3B286DC1727FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xD51668BBAF7B58EDULL + 0x8DDF61D3A01DE74CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xD71298D7C7FF6AA9ULL + 0xBF8A57FAFA6E3659ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xCC89E4DD4DA3AD5BULL + 0xD202FC07B302700DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x8266F5E4CB932AA7ULL + 0x9B517214EE806DF7ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xB6CEB6FF165667A5ULL + 0x919AD9EC2C7439F0ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xF7C5E91D84FEE171ULL + 0xE882B3C8D44FD668ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xD21458BC4E91AEBBULL + 0xDE1694DCFBC19828ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xA289BB5C2722CD59ULL + 0xA2ED378F651D1E5EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x9245A3868940BE1BULL + 0x950A566AFCAAECFEULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xD5C20A5F2FBDE149ULL + 0xB304107D5A3B17F6ULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aFireLaneD, aWorkLaneC, aWorkLaneD, aFireLaneB, aExpandLaneA, aOperationLaneB, aFireLaneC, aExpandLaneB, aOperationLaneD, aOperationLaneC, aExpandLaneC, aFireLaneA, aOperationLaneA
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_a loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aFireLaneD
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aFireLaneD forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aFireLaneB
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 7077U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((aIndex + 3273U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 3141U)) & S_BLOCK1], 54U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7519U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 6996U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 484U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 52U) ^ RotL64(aPrevious, 11U)) ^ (RotL64(aCross, 39U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 47U)) + RotL64(aCarry, 5U)) + 12029393034357490020U;
            aOrbiterB = (((aWandererD + RotL64(aScatter, 57U)) + RotL64(aCarry, 27U)) + 4526754731580694987U) + aNonceWordE;
            aOrbiterI = (((aWandererB + RotL64(aIngress, 18U)) + RotL64(aCarry, 53U)) + 17060419646421271853U) + aNonceWordF;
            aOrbiterC = ((aWandererA + RotL64(aCross, 37U)) + 4128488893837059683U) + aOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aPrevious, 3U)) + 12706894827547160110U;
            aOrbiterK = (((aWandererK + RotL64(aCross, 11U)) + 12506324593645825056U) + aOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1]) + aNonceWordN;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 29U)) + 12581344490649250025U) + aNonceWordJ;
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 14357032418199130132U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 15341977701796331249U;
            aOrbiterI = RotL64((aOrbiterI * 6332369248718076031U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 7086602307544733241U) + aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 12398300065276832486U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 18157408831225635333U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 2499745046076601988U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 7249361592814001829U;
            aOrbiterA = RotL64((aOrbiterA * 14597139848072319685U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 3254456186337366437U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 3472973415969046680U;
            aOrbiterC = RotL64((aOrbiterC * 14583566953969168353U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 7905718972111691591U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 15941413652144021522U) ^ aNonceWordD;
            aOrbiterH = RotL64((aOrbiterH * 3473779492962783565U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 10583964125960308762U) + aOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 13659925272340853715U;
            aOrbiterK = RotL64((aOrbiterK * 16708294803316630743U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 9487054537489454887U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterA) ^ 13287757570441887517U) ^ aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 17351439045329892107U), 35U);
            //
            aIngress = RotL64(aOrbiterA, 21U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterC, 40U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 29U)) + aOrbiterB);
            aWandererB = aWandererB ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterC, 3U)) + aOrbiterK) + aNonceWordK);
            aWandererD = aWandererD + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 35U)) + aOrbiterH) + aNonceWordL) + aWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 56U) + RotL64(aOrbiterA, 20U)) + aOrbiterH) + aNonceWordC) + aWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterH, 43U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 57U)) + aOrbiterI) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 28U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 51U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aOperationLaneB
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aOperationLaneB forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aFireLaneC
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aFireLaneC backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 13732U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneC[((aIndex + 12103U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8804U)) & S_BLOCK1], 12U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16148U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8532U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 13610U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 48U) + RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 56U)) + 3550722402315312207U) + aNonceWordI;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 41U)) + 16724184551669522754U) + aOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = (((aWandererE + RotL64(aCross, 21U)) + RotL64(aCarry, 43U)) + 981751330116773021U) + aOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = ((aWandererF + RotL64(aScatter, 29U)) + RotL64(aCarry, 23U)) + 7891159229704944868U;
            aOrbiterC = (((aWandererJ + RotL64(aPrevious, 13U)) + RotL64(aCarry, 57U)) + 13618396711464799841U) + aNonceWordF;
            aOrbiterG = (aWandererA + RotL64(aCross, 47U)) + 5969291018449003648U;
            aOrbiterH = (aWandererK + RotL64(aIngress, 5U)) + 14595540413313640042U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 3287990436916111762U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 12534369400200483704U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2345945228434740707U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 2277312067930392274U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 10026320559261334353U) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 11020464940995912637U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 11258082063135659551U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 1445958517675746990U;
            aOrbiterH = RotL64((aOrbiterH * 10062265337488757971U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 1011298251290970844U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 6487834862470043744U;
            aOrbiterI = RotL64((aOrbiterI * 15477913837027179675U), 35U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterG) + 9966279022928268335U) + aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1]) + aNonceWordE;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 10285993486057704393U;
            aOrbiterJ = RotL64((aOrbiterJ * 15965714363201157535U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 16005362468813966136U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 223843444699390781U) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 665392038954573081U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 18178876294968532775U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 12490136112181806806U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16380841616662993709U), 47U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterF, 5U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 38U));
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 3U)) + aOrbiterI);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterG, 57U)) + aOrbiterE) + RotL64(aCarry, 13U)) + aNonceWordC);
            aWandererE = aWandererE ^ (((RotL64(aCross, 57U) + aOrbiterI) + RotL64(aOrbiterF, 43U)) + aWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterH, 18U)) + aOrbiterG) + aNonceWordK);
            aWandererF = aWandererF + (((RotL64(aScatter, 12U) + RotL64(aOrbiterJ, 11U)) + aOrbiterF) + aNonceWordJ);
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterI, 29U)) + aNonceWordD) + aWandererUpdateSaltF[((aIndex + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 30U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + RotL64(aWandererK, 35U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aOperationLaneD
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aOperationLaneD forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aOperationLaneC
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 23710U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneD[((aIndex + 18756U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 20757U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18392U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20027U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 19513U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCarry, 37U)) ^ (RotL64(aCross, 19U) ^ RotL64(aIngress, 52U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterB = (((aWandererI + RotL64(aScatter, 21U)) + RotL64(aCarry, 51U)) + 4622023259121087483U) + aNonceWordJ;
            aOrbiterK = (aWandererB + RotL64(aPrevious, 43U)) + 10253505250223501352U;
            aOrbiterA = (aWandererE + RotL64(aIngress, 60U)) + 17133877904420462669U;
            aOrbiterG = ((aWandererK + RotL64(aCross, 27U)) + 6162827793741796700U) + aOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = (((aWandererD + RotL64(aIngress, 51U)) + RotL64(aCarry, 13U)) + 9610986424765907615U) + aOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aCross, 35U)) + RotL64(aCarry, 37U)) + 11210747154264753754U;
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 11U)) + 16554205219580654546U) + aNonceWordI;
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 10352576357413766388U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 3651845783283479752U) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 1011289824180799641U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 18145542190463500476U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 5415609566767162857U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6474184559323816389U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 2033734872464201570U) + aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 3507213117125813345U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5453058336688881113U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 8716253393049851856U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 695984869565941856U) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 8377921610764044735U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 7661578828878284931U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 906654265099155956U;
            aOrbiterE = RotL64((aOrbiterE * 8117625377607536949U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 6050049984731254612U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 17882717590338190821U;
            aOrbiterF = RotL64((aOrbiterF * 10807367411402733215U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 4996521991532815957U) + aOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 4246460672800604436U;
            aOrbiterB = RotL64((aOrbiterB * 12047466401960824903U), 5U);
            //
            aIngress = RotL64(aOrbiterG, 13U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 37U)) + aOrbiterF) + aWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 27U)) + aOrbiterK) + RotL64(aCarry, 43U)) + aNonceWordG);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterK, 21U)) + aNonceWordF);
            aWandererK = aWandererK + (((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 43U)) + aOrbiterG);
            aWandererI = aWandererI + ((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 12U)) + aOrbiterE);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 12U) + aOrbiterH) + RotL64(aOrbiterA, 51U)) + aWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 60U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneA
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aOperationLaneA
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aOperationLaneA backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 25499U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((aIndex + 25859U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 27408U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31227U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 25452U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aOperationLaneA[((aIndex + 29492U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aPrevious, 10U)) + (RotL64(aIngress, 51U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterH = (((aWandererD + RotL64(aScatter, 27U)) + RotL64(aCarry, 37U)) + 8793908991006073956U) + aOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aIngress, 11U)) + 2932916283348441943U;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 43U)) + 11069042087940968262U) + aNonceWordN;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 5U)) + RotL64(aCarry, 5U)) + 14369628676782894441U;
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 53U)) + 8602903272780978282U) + aNonceWordP;
            aOrbiterE = (aWandererG + RotL64(aScatter, 18U)) + 3827036107178568820U;
            aOrbiterG = (((aWandererF + RotL64(aIngress, 37U)) + RotL64(aCarry, 51U)) + 8905245209036772489U) + aOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 13331387530760017893U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 9880107580289737823U;
            aOrbiterF = RotL64((aOrbiterF * 10302652857542703753U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 10199619040626900278U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 2466307560891374281U;
            aOrbiterI = RotL64((aOrbiterI * 6295342978834217571U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 13973403407981259448U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 2851460278409385243U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11226902976321781743U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 10365453393815690776U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 2382382358987358791U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 481563628980705781U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 5058198848163792422U) + aNonceWordH;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 10500434740387593487U) ^ aOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5946747708776079787U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 11289798395177667084U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 14327152153231286666U;
            aOrbiterA = RotL64((aOrbiterA * 18155778059595245561U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 8065137263811956313U) + aNonceWordI;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 3865153574847924816U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9495741102667755161U), 29U);
            //
            aIngress = RotL64(aOrbiterA, 27U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + RotL64(aOrbiterE, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterF, 43U)) + aNonceWordB);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 23U)) + aOrbiterH) + RotL64(aCarry, 35U)) + aWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 3U)) + aOrbiterG) + aNonceWordD) + aWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 41U) + RotL64(aOrbiterH, 29U)) + aOrbiterG) + aNonceWordJ);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterD, 53U)) + aOrbiterI);
            aWandererG = aWandererG + (((RotL64(aCross, 26U) + aOrbiterI) + RotL64(aOrbiterF, 37U)) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 12U)) + aOrbiterE) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 56U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xA70FC749E19271EDULL + 0x871983703D2C4FFBULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x87ECC448D63C7B35ULL + 0xF17A4BF0F561DC05ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x8474DBC44ECA3405ULL + 0xFFDF2C166A440335ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x9E2E2BF6AF4D055BULL + 0xA1DFD1F6EDCB58DBULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xAE648E5D4FE9F50BULL + 0xEEBA92944502F165ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x87D454FC07CF9C4BULL + 0x80A2A8F572B46020ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x8A29AC17FAB44415ULL + 0x870462F1088F2886ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xCB7C37EDCD8ED7A3ULL + 0xCB8E82B07431453DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xA81B055D9D282383ULL + 0xFC1CFEEF60C172B8ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x8DCA7B78EF204793ULL + 0xBF48307D3AC28DEBULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xB9EA4709A2405627ULL + 0xCE89994F42724038ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xBBCCF9C821646F23ULL + 0xFA2DEED865D819A4ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xF2E0A55FDD73294FULL + 0x81044283AE2C7D0DULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xDC2092A6A3F97BBFULL + 0xD9AD901566C1AAC0ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xC8C085AA6EAE3F49ULL + 0xAA7A6EE17035FCB2ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x867E373176DD9C83ULL + 0xF06368F148AD079FULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneA, aExpandLaneC, aExpandLaneD, aFireLaneC, aOperationLaneA, aWorkLaneB, aFireLaneB, aOperationLaneB, aWorkLaneD, aWorkLaneC, aOperationLaneC, aWorkLaneA, aFireLaneD
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // kdf_b_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aFireLaneC
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aFireLaneC backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 286U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((aIndex + 7002U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 2956U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4806U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 1818U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 1281U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 23U)) + (RotL64(aCross, 57U) + RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 43U)) + RotL64(aCarry, 47U)) + 4622023259121087483U;
            aOrbiterA = ((aWandererC + RotL64(aCross, 30U)) + 10253505250223501352U) + aNonceWordF;
            aOrbiterB = (aWandererG + RotL64(aIngress, 19U)) + 17133877904420462669U;
            aOrbiterK = (aWandererI + RotL64(aScatter, 11U)) + 6162827793741796700U;
            aOrbiterD = ((aWandererA + RotL64(aCross, 23U)) + RotL64(aCarry, 43U)) + 9610986424765907615U;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 51U)) + 11210747154264753754U) + aNonceWordE;
            aOrbiterE = (aWandererD + RotL64(aPrevious, 27U)) + 16554205219580654546U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 48U)) + 10352576357413766388U) + aOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aCross, 3U)) + 3651845783283479752U;
            aOrbiterG = (((aWandererK + RotL64(aIngress, 35U)) + 18145542190463500476U) + aOrbiterAssignSaltA[((aIndex + 24U)) & S_SALT1]) + aNonceWordH;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 5U)) + RotL64(aCarry, 35U)) + 5415609566767162857U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 2033734872464201570U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 3507213117125813345U;
            aOrbiterB = RotL64((aOrbiterB * 5453058336688881113U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 8716253393049851856U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 695984869565941856U) ^ aOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8377921610764044735U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 7661578828878284931U) + aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 906654265099155956U) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 8117625377607536949U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 6050049984731254612U) + aNonceWordN;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 17882717590338190821U) ^ aNonceWordA;
            aOrbiterH = RotL64((aOrbiterH * 10807367411402733215U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 4996521991532815957U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 4246460672800604436U;
            aOrbiterI = RotL64((aOrbiterI * 12047466401960824903U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 8700148116452518842U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 10039050281847466206U) ^ aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11884791271239660157U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 4513844680425845372U) + aNonceWordK;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 3037563127442815153U;
            aOrbiterK = RotL64((aOrbiterK * 18363509277992292407U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 1005237931570968724U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 1373258132025712065U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10458020799382532395U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 12759144329395682277U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 5139371668116336931U;
            aOrbiterJ = RotL64((aOrbiterJ * 10761543179345026943U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 3211005174890625715U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 18045286961878287418U;
            aOrbiterD = RotL64((aOrbiterD * 4536094526540761611U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 4454078771279674978U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 4622023259121087483U;
            aOrbiterC = RotL64((aOrbiterC * 8991756794989027019U), 27U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 3U);
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterI, 50U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 35U)) + aOrbiterC);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 51U) + aOrbiterF) + RotL64(aOrbiterH, 3U));
            aWandererH = aWandererH + ((RotL64(aScatter, 60U) + aOrbiterJ) + RotL64(aOrbiterH, 57U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 23U) + aOrbiterA) + RotL64(aOrbiterB, 5U)) + aWandererUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterA, 19U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 11U) + aOrbiterB) + RotL64(aOrbiterJ, 53U)) + aNonceWordC);
            aWandererG = aWandererG + ((RotL64(aCross, 57U) + RotL64(aOrbiterK, 50U)) + aOrbiterD);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 14U) + RotL64(aOrbiterE, 39U)) + aOrbiterG);
            aWandererI = aWandererI + ((((RotL64(aScatter, 53U) + aOrbiterI) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 21U)) + aNonceWordB);
            aWandererK = aWandererK ^ (((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterI, 41U)) + aWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterE, 14U)) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 34U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + RotL64(aWandererJ, 21U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 2
        // ingress from: aOperationLaneA, aExpandLaneC, aWorkLaneB
        // ingress directions: aOperationLaneA forward forced, aExpandLaneC forward forced, aWorkLaneB forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aFireLaneB
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aFireLaneB backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 10021U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((aIndex + 13005U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 8485U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 13795U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15499U)) & S_BLOCK1], 12U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 9662U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 35U)) ^ (RotL64(aIngress, 19U) + RotL64(aCarry, 48U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterD = ((aWandererB + RotL64(aCross, 19U)) + RotL64(aCarry, 19U)) + 13333509828310369865U;
            aOrbiterB = (aWandererA + RotL64(aScatter, 47U)) + 7645352517103840797U;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 39U)) + 5310766306660062655U) + aNonceWordF;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 43U)) + 5165635069832352932U) + aOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 28U)) + 15684141764734281849U) + aOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 37U)) + RotL64(aCarry, 35U)) + 3327963374225061738U;
            aOrbiterK = (aWandererE + RotL64(aCross, 53U)) + 8625811794878848871U;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 13U)) + RotL64(aCarry, 5U)) + 7598657468430485291U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 22U)) + 2881171216276746485U) + aNonceWordO;
            aOrbiterA = (aWandererH + RotL64(aCross, 3U)) + 10237691227222918101U;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 5U)) + 6419254255884834497U) + aNonceWordG;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 4238455444646479956U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 14936613353493061492U;
            aOrbiterG = RotL64((aOrbiterG * 3544216916806292273U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 15324699725208372627U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 9506640480601832011U) ^ aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12819564111348390227U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 3709149613660215641U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 1724290199312754307U;
            aOrbiterH = RotL64((aOrbiterH * 12597580418257897965U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 13191172833570139194U) + aNonceWordD;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 3686087945377837886U;
            aOrbiterK = RotL64((aOrbiterK * 10883609557429936283U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 10418330386245397022U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 5383531313632347245U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2987755379396160073U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 7414716553072652212U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 11301761123966206201U;
            aOrbiterJ = RotL64((aOrbiterJ * 1546727321088592187U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 8570229732236388847U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 8773754460060264773U;
            aOrbiterD = RotL64((aOrbiterD * 3251360788932563495U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 13636929800504199371U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 5486599841558573720U;
            aOrbiterA = RotL64((aOrbiterA * 2867914211589815153U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 13277541451512422776U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 10409779509190185921U;
            aOrbiterI = RotL64((aOrbiterI * 1926650154570961573U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 7268295836403414306U) + aNonceWordK;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 13815969853235433830U) ^ aOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11603750346752441535U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 9353249174240162324U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 13333509828310369865U) ^ aOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10381405217943841655U), 5U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterE, 29U);
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 37U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 54U));
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 48U) + aOrbiterJ) + RotL64(aOrbiterI, 11U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterG, 42U)) + RotL64(aCarry, 23U)) + aWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterF, 5U));
            aWandererB = aWandererB + (((RotL64(aIngress, 39U) + RotL64(aOrbiterA, 23U)) + aOrbiterC) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 21U)) + aOrbiterF) + aWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 6U) + RotL64(aOrbiterG, 39U)) + aOrbiterE);
            aWandererE = aWandererE ^ (((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterH, 37U)) + aNonceWordH);
            aWandererA = aWandererA + (((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 53U)) + aOrbiterB) + aNonceWordE);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterB, 3U)) + aOrbiterI);
            aWandererG = aWandererG + (((RotL64(aIngress, 53U) + RotL64(aOrbiterC, 26U)) + aOrbiterK) + aNonceWordJ);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 41U) + aOrbiterD) + RotL64(aOrbiterK, 19U)) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererB, 44U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (RotL64(aWandererH, 40U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 51U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 3
        // ingress from: aOperationLaneB, aExpandLaneD, aWorkLaneD
        // ingress directions: aOperationLaneB forward forced, aExpandLaneD forward forced, aWorkLaneD forward/backward random
        // cross from: aOperationLaneA, aExpandLaneB, aWorkLaneC
        // cross directions: aOperationLaneA backward forced, aExpandLaneB backward forced, aWorkLaneC backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 20969U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneD[((aIndex + 24075U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 19075U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23739U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 16409U)) & S_BLOCK1], 38U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 22961U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 58U) ^ RotL64(aPrevious, 29U)) + (RotL64(aCarry, 43U) ^ RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterI = (aWandererC + RotL64(aPrevious, 3U)) + 2786079456995203065U;
            aOrbiterD = ((aWandererE + RotL64(aIngress, 53U)) + 7237256119153857253U) + aNonceWordG;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 42U)) + RotL64(aCarry, 35U)) + 9310834010563647604U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 47U)) + 17361734905706517877U;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 19U)) + RotL64(aCarry, 43U)) + 15837111231884647451U;
            aOrbiterE = (((aWandererJ + RotL64(aPrevious, 39U)) + RotL64(aCarry, 19U)) + 18065431964418026445U) + aNonceWordP;
            aOrbiterH = (aWandererA + RotL64(aCross, 37U)) + 3029123922999952652U;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 30U)) + 5166926595573507837U) + aOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aCross, 35U)) + 1918425684273807598U) + aOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aScatter, 13U)) + 4724551751012661440U;
            aOrbiterB = ((aWandererG + RotL64(aIngress, 51U)) + 1818014487579644390U) + aNonceWordC;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 6670090372241084216U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 8485757110007268693U;
            aOrbiterG = RotL64((aOrbiterG * 11876760095108618363U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 4928130251509514742U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 2528788422725346792U;
            aOrbiterE = RotL64((aOrbiterE * 1855982047967756661U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 2860387120895147503U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 12927802338151379368U) ^ aOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8876144125458603029U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 18029699867733207083U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterH) ^ 13361836994951253312U) ^ aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterK = RotL64((aOrbiterK * 5349767426256597073U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 11957294454794128079U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 3755417922063414648U;
            aOrbiterA = RotL64((aOrbiterA * 13896364063651241401U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 18001157153447913032U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 16214145724690286854U;
            aOrbiterD = RotL64((aOrbiterD * 5874139687703360515U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 3860958772090975562U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterK) ^ 12395621524459640173U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterI = RotL64((aOrbiterI * 722817135977510161U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 3402035664910754484U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 2139099117325745602U;
            aOrbiterB = RotL64((aOrbiterB * 14008983756425796029U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 7769274487425053026U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 6492669707749367728U;
            aOrbiterF = RotL64((aOrbiterF * 5149771861620757839U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 14963366447884375043U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 11398874662567519691U;
            aOrbiterH = RotL64((aOrbiterH * 8221521452475029835U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 7168445485232814860U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 2786079456995203065U;
            aOrbiterC = RotL64((aOrbiterC * 14258367164534307955U), 29U);
            //
            aIngress = RotL64(aOrbiterC, 36U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 44U) + aOrbiterD) + RotL64(aOrbiterE, 53U)) + aNonceWordD);
            aWandererA = aWandererA + (((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterG, 24U)) + aOrbiterF);
            aWandererF = aWandererF + ((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterE, 27U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 39U) + aOrbiterK) + RotL64(aOrbiterG, 37U)) + aWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 11U) + aOrbiterB) + RotL64(aOrbiterD, 39U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 54U) + RotL64(aOrbiterD, 3U)) + aOrbiterI) + aWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 35U) + RotL64(aOrbiterG, 19U)) + aOrbiterA);
            aWandererG = aWandererG ^ ((RotL64(aCross, 23U) + aOrbiterJ) + RotL64(aOrbiterD, 44U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 13U) + aOrbiterE) + RotL64(aOrbiterC, 57U)) + RotL64(aCarry, 51U)) + aNonceWordF);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 35U)) + aOrbiterE) + aNonceWordA);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 20U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + RotL64(aWandererH, 30U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 4
        // ingress from: aOperationLaneC, aOperationLaneA, aWorkLaneA
        // ingress directions: aOperationLaneC forward forced, aOperationLaneA forward forced, aWorkLaneA forward/backward random
        // cross from: aOperationLaneB, aExpandLaneC, aFireLaneD
        // cross directions: aOperationLaneB backward forced, aExpandLaneC backward forced, aFireLaneD backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 32343U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((aIndex + 31409U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aWorkLaneA[((aIndex + 31368U)) & S_BLOCK1], 54U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24797U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 25882U)) & S_BLOCK1], 30U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 29897U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCarry, 53U)) ^ (RotL64(aIngress, 18U) ^ RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterE = (aWandererF + RotL64(aIngress, 23U)) + 2617613537256538553U;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 47U)) + RotL64(aCarry, 39U)) + 16642868916835132715U;
            aOrbiterA = ((aWandererE + RotL64(aCross, 53U)) + RotL64(aCarry, 11U)) + 10860291124337073254U;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 37U)) + 6432511273906902472U) + aOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aCross, 14U)) + 7505375005848241910U;
            aOrbiterD = (aWandererK + RotL64(aIngress, 5U)) + 11086616004678821329U;
            aOrbiterK = (((aWandererH + RotL64(aScatter, 19U)) + 3298830587569881951U) + aOrbiterAssignSaltA[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordP;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 11U)) + RotL64(aCarry, 27U)) + 9775143140064220979U;
            aOrbiterC = ((aWandererB + RotL64(aScatter, 56U)) + 4147601326580823120U) + aNonceWordI;
            aOrbiterH = (aWandererD + RotL64(aPrevious, 29U)) + 12245920269898100415U;
            aOrbiterG = (aWandererA + RotL64(aCross, 21U)) + 8391940489176734499U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 17876893379544668477U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 18301882058180370541U;
            aOrbiterA = RotL64((aOrbiterA * 16680384667098921309U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 6869225862715140102U) + aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 15404118372589259800U;
            aOrbiterD = RotL64((aOrbiterD * 5766851935950389915U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 17757381020518233814U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 17677969146092374455U) ^ aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3469432916562405063U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 15783378556632870114U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 5792858258663697864U;
            aOrbiterE = RotL64((aOrbiterE * 12008981883482080427U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 11737803388202260296U) + aNonceWordL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 16001927091970715330U;
            aOrbiterJ = RotL64((aOrbiterJ * 3062030309852922061U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 1749586939123286632U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 6169421068855905938U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12374789910763348695U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 10073586820719728062U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 17744171227198661555U;
            aOrbiterG = RotL64((aOrbiterG * 10658375268803957647U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 1149819647337612792U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 7725598665625892006U;
            aOrbiterH = RotL64((aOrbiterH * 15097586655234391559U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 13930096050550704122U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterG) ^ 3632241034947389647U) ^ aOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 8442222389196610427U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 17933893495867517142U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 7888594392078082482U;
            aOrbiterK = RotL64((aOrbiterK * 9809847720610861237U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 10805303827043372168U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 2617613537256538553U;
            aOrbiterF = RotL64((aOrbiterF * 3940471942234248791U), 21U);
            //
            aIngress = RotL64(aOrbiterF, 57U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 30U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + RotL64(aOrbiterD, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aCross, 30U) + aOrbiterF) + RotL64(aOrbiterJ, 13U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 53U) + aOrbiterE) + RotL64(aOrbiterA, 35U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterC, 58U)) + RotL64(aCarry, 57U)) + aNonceWordM);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 11U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 37U) + RotL64(aOrbiterC, 39U)) + aOrbiterG);
            aWandererI = aWandererI ^ ((RotL64(aCross, 43U) + aOrbiterH) + RotL64(aOrbiterD, 47U));
            aWandererA = aWandererA + (((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 50U)) + aOrbiterI) + aWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 50U) + aOrbiterB) + RotL64(aOrbiterF, 23U));
            aWandererF = aWandererF + (((RotL64(aIngress, 23U) + aOrbiterJ) + RotL64(aOrbiterK, 3U)) + aWandererUpdateSaltF[((aIndex + 22U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterJ, 5U)) + aOrbiterI) + aNonceWordD);
            aWandererB = aWandererB + (((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 40U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 44U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererF, 13U);
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

void TwistExpander_Cricket_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x8CC7D041757B6753ULL + 0xE15436767CD9F83FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xB9809021FFA109D3ULL + 0xDB4898EC4DADF7C4ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xB752211DBE16723BULL + 0xFFA85935140D03BAULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xC2AC3F6EF2DEF441ULL + 0x91C90CAFFDCBB3D5ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xD8F6C084315218EDULL + 0x8C85895C7BE0B254ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xCE10882E1308EAD3ULL + 0x869382DAF050FDEFULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xEA4DBCD12556ADEFULL + 0xF2A0A9D329BD3448ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xDD3EF66B8DC18CC9ULL + 0xC12DEC1E1C6ACEFEULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xD30123077A1B5CDDULL + 0xDB85E6575AFD507EULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xA79375C0141D32A5ULL + 0xFDD92BFCCFEA7DDEULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xCA91B0B03DC05E17ULL + 0xA632EE2C15DD0A58ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xE2B546F771BEB7A7ULL + 0xB22C6F320E5A40D1ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xA75259E79EF4197BULL + 0xF6DD66E8C04E3C88ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xABDE4FA0C859086BULL + 0xFBBD40E381D8C867ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xAF6BF0BA0C0BB72FULL + 0x86FC98EA1184CB61ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xD3CE44A875F663ABULL + 0xCE9E5296A48274EEULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aWorkLaneA, aOperationLaneC, aOperationLaneD, aFireLaneA, aExpandLaneA, aFireLaneC, aWorkLaneD, aExpandLaneB, aFireLaneB, aWorkLaneB, aExpandLaneC, aFireLaneD, aWorkLaneC
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aWorkLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aWorkLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aFireLaneA
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 5887U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneB[((aIndex + 4570U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aWorkLaneA[((aIndex + 3532U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 39U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 145U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 2559U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 43U) ^ RotL64(aCarry, 57U)) + (RotL64(aPrevious, 28U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterA = ((aWandererD + RotL64(aIngress, 26U)) + 9023059520606551446U) + aOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aCross, 47U)) + 662441755115638133U) + aNonceWordH;
            aOrbiterC = (aWandererH + RotL64(aPrevious, 39U)) + 16957253361196144712U;
            aOrbiterI = ((aWandererG + RotL64(aScatter, 35U)) + 7840955025765308605U) + aNonceWordL;
            aOrbiterH = (((aWandererJ + RotL64(aPrevious, 19U)) + RotL64(aCarry, 57U)) + 346855809270395799U) + aOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (((aWandererA + RotL64(aScatter, 53U)) + RotL64(aCarry, 13U)) + 16099139781586668343U) + aNonceWordG;
            aOrbiterE = ((aWandererF + RotL64(aIngress, 57U)) + RotL64(aCarry, 47U)) + 3706457327118322098U;
            aOrbiterK = (aWandererI + RotL64(aCross, 13U)) + 12166825885547622870U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 4U)) + 7792658665720344200U) + aNonceWordN;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 7128477606152986326U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 11116533962780290084U) ^ aOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11993485572912492297U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 10443889548568288532U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 4402387036946561017U) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 9032964741841833277U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 13002706161178447654U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 13929727277530310708U;
            aOrbiterJ = RotL64((aOrbiterJ * 7005639090871200285U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 10949073760696935106U) + aNonceWordO;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 15405923432006783533U;
            aOrbiterE = RotL64((aOrbiterE * 17989565878445202495U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 18096057968822208905U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 3032155040484574973U;
            aOrbiterI = RotL64((aOrbiterI * 448597307502544605U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 17462076466907467134U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 15471015427013701406U;
            aOrbiterH = RotL64((aOrbiterH * 6113474000571976139U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 3549031751266594344U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 14243218483842508113U;
            aOrbiterK = RotL64((aOrbiterK * 9041601306479302047U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 5803147589312920032U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 5549470512227427855U;
            aOrbiterA = RotL64((aOrbiterA * 12592362489263862879U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 10076661824293832189U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 3196799148974716550U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8183276968961467775U), 27U);
            //
            aIngress = RotL64(aOrbiterB, 29U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 37U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 34U));
            aIngress = aIngress + RotL64(aOrbiterJ, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterK, 37U)) + aOrbiterB);
            aWandererF = aWandererF + (((((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterI, 23U)) + RotL64(aCarry, 23U)) + aNonceWordI) + aWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterI, 28U)) + aOrbiterH);
            aWandererK = aWandererK + ((((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 57U)) + aNonceWordD);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 6U) + RotL64(aOrbiterK, 53U)) + aOrbiterD);
            aWandererG = aWandererG + (((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterK, 43U)) + aWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 10U)) + aOrbiterJ);
            aWandererI = aWandererI + ((RotL64(aCross, 53U) + RotL64(aOrbiterJ, 3U)) + aOrbiterB);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 58U) + aOrbiterI) + RotL64(aOrbiterC, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 60U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 2
        // ingress from: aExpandLaneA, aOperationLaneC, aFireLaneC
        // ingress directions: aExpandLaneA forward forced, aOperationLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneD, aWorkLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneD backward forced, aWorkLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 9029U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneC[((aIndex + 11705U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 11335U)) & S_BLOCK1], 30U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 11141U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 13409U)) & S_BLOCK1], 22U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 11285U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 23U)) + (RotL64(aCross, 6U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 57U)) + 13880995121909552664U;
            aOrbiterG = (aWandererH + RotL64(aIngress, 11U)) + 14534942818069300546U;
            aOrbiterB = (((aWandererK + RotL64(aCross, 23U)) + RotL64(aCarry, 41U)) + 17745973100886007133U) + aOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 27U)) + 2249805580771946872U) + aNonceWordH;
            aOrbiterA = (aWandererD + RotL64(aScatter, 52U)) + 4460116116396439410U;
            aOrbiterI = (aWandererE + RotL64(aCross, 47U)) + 3378683994078106878U;
            aOrbiterD = (((aWandererA + RotL64(aPrevious, 43U)) + RotL64(aCarry, 21U)) + 3992996501048809123U) + aOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = (aWandererI + RotL64(aIngress, 35U)) + 12057768808864451929U;
            aOrbiterH = (((aWandererG + RotL64(aScatter, 6U)) + RotL64(aCarry, 57U)) + 4115362079047921130U) + aNonceWordG;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 15297384955502206698U) + aOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 17623548383481905636U;
            aOrbiterB = RotL64((aOrbiterB * 7487278217901483685U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 3559213898000162417U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 12311605719074507335U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3982199462062847697U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 14807313864347885885U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 11222085523291581822U;
            aOrbiterE = RotL64((aOrbiterE * 12580941911587215653U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 916681229436292462U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 2441350114032314686U;
            aOrbiterD = RotL64((aOrbiterD * 7336079498999018067U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 7361470539894653271U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 12153585147213579808U;
            aOrbiterH = RotL64((aOrbiterH * 3040327545467672961U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 13566300726101613579U) + aNonceWordE;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 14875254144748509128U;
            aOrbiterJ = RotL64((aOrbiterJ * 13699179902908972403U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 9268158535644002904U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 14144295981814993491U;
            aOrbiterA = RotL64((aOrbiterA * 12739937231684038161U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 13861225650900541642U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 12620513474052058164U;
            aOrbiterC = RotL64((aOrbiterC * 18141974182442267181U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 14163773386433257965U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterH) ^ 5725700029399455855U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterG = RotL64((aOrbiterG * 10446930901088908809U), 13U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 53U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 22U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 53U) + aOrbiterD) + RotL64(aOrbiterI, 35U));
            aWandererD = aWandererD + (((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 46U)) + aOrbiterB) + aWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterI, 3U)) + aOrbiterE) + aNonceWordN);
            aWandererG = aWandererG + ((RotL64(aCross, 60U) + RotL64(aOrbiterG, 53U)) + aOrbiterJ);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterI, 39U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aIngress, 43U) + aOrbiterC) + RotL64(aOrbiterG, 12U)) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 39U) + aOrbiterC) + RotL64(aOrbiterA, 19U)) + aNonceWordK);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 30U) + aOrbiterI) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 41U)) + aNonceWordI);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 23U)) + aOrbiterH) + aWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 42U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 3
        // ingress from: aExpandLaneB, aOperationLaneD, aFireLaneB
        // ingress directions: aExpandLaneB forward forced, aOperationLaneD forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneA, aOperationLaneB, aWorkLaneB
        // cross directions: aExpandLaneA backward forced, aOperationLaneB backward forced, aWorkLaneB backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 18007U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneD[((aIndex + 16994U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 18645U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21554U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 19496U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 24074U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCross, 21U)) ^ (RotL64(aPrevious, 38U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterD = (aWandererB + RotL64(aPrevious, 35U)) + 12809562813316740345U;
            aOrbiterA = (aWandererH + RotL64(aScatter, 12U)) + 17084212535326321199U;
            aOrbiterB = ((aWandererK + RotL64(aCross, 27U)) + 16074921689983846769U) + aNonceWordO;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 19U)) + 14027986153007120145U) + aNonceWordP;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 53U)) + 7633455951809250227U;
            aOrbiterE = (((aWandererC + RotL64(aCross, 4U)) + RotL64(aCarry, 47U)) + 340989348513370174U) + aNonceWordL;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 39U)) + 5307820377645020116U;
            aOrbiterC = ((((aWandererE + RotL64(aIngress, 47U)) + RotL64(aCarry, 5U)) + 5605285015771527274U) + aOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordB;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 23U)) + 5293500434746182790U) + aOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 7263156475892261811U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 10672879570907433005U;
            aOrbiterB = RotL64((aOrbiterB * 2506338667179450741U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 16659226780900986107U) + aNonceWordD;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 9774892622769850665U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7487477727543183211U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 10728057184108279042U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 5032485856947407217U;
            aOrbiterG = RotL64((aOrbiterG * 16651577903809154285U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 14642241075374862345U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterA) ^ 8386481273395203518U) ^ aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterC = RotL64((aOrbiterC * 11649977733867003445U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2874153265304098104U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 11519900149177261000U;
            aOrbiterH = RotL64((aOrbiterH * 2010158758971864505U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 8885690878540115768U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 4482143389870987714U) ^ aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7105332459437434281U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 17469068567801886615U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 5121422018622394837U;
            aOrbiterD = RotL64((aOrbiterD * 14823827133212643467U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 3130788210672745618U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 6139244627510113216U;
            aOrbiterA = RotL64((aOrbiterA * 2640754184921507389U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 10488511756324474710U) + aOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 1760223670304953696U;
            aOrbiterF = RotL64((aOrbiterF * 4007062295003769311U), 23U);
            //
            aIngress = RotL64(aOrbiterE, 21U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + RotL64(aOrbiterG, 48U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterE, 42U)) + aNonceWordG);
            aWandererF = aWandererF + ((RotL64(aPrevious, 36U) + aOrbiterH) + RotL64(aOrbiterD, 37U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 51U)) + aOrbiterC);
            aWandererK = aWandererK + (((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 11U)) + aOrbiterB) + aNonceWordA);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 19U)) + aOrbiterC);
            aWandererE = aWandererE + (((RotL64(aIngress, 11U) + RotL64(aOrbiterI, 58U)) + aOrbiterD) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 53U) + aOrbiterE) + RotL64(aOrbiterF, 23U)) + aNonceWordJ);
            aWandererC = aWandererC + ((((RotL64(aCross, 40U) + aOrbiterI) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 39U)) + aWandererUpdateSaltF[((aIndex + 26U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterC, 47U)) + aNonceWordF) + aWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 46U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneD
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneB, aOperationLaneC, aWorkLaneC
        // cross directions: aExpandLaneB backward forced, aOperationLaneC backward forced, aWorkLaneC backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 25985U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((aIndex + 32690U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 25701U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25392U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 31872U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 30359U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 13U) + RotL64(aCarry, 57U)) ^ (RotL64(aCross, 40U) ^ RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterC = (((aWandererH + RotL64(aPrevious, 19U)) + 5510690816044082200U) + aOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordL;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 60U)) + 15967820875033940530U) + aNonceWordD;
            aOrbiterK = (((aWandererK + RotL64(aIngress, 43U)) + RotL64(aCarry, 53U)) + 539348720848176221U) + aNonceWordN;
            aOrbiterH = ((aWandererG + RotL64(aCross, 37U)) + RotL64(aCarry, 3U)) + 15779318183635560817U;
            aOrbiterF = (((aWandererF + RotL64(aPrevious, 23U)) + RotL64(aCarry, 39U)) + 14511058534424187469U) + aOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aScatter, 10U)) + 5811130556873428391U;
            aOrbiterB = (aWandererA + RotL64(aIngress, 5U)) + 1085928476499444025U;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 27U)) + 6973335316600768130U) + aNonceWordA;
            aOrbiterD = (aWandererD + RotL64(aScatter, 51U)) + 10747243745475009744U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 1072260008981349754U) + aNonceWordH;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 2018772405352495753U;
            aOrbiterK = RotL64((aOrbiterK * 10840562112080574241U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 1092091597048996547U) + aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 15103140149542167197U;
            aOrbiterA = RotL64((aOrbiterA * 621856991658027989U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 13194619321108681542U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 16749188603268621850U;
            aOrbiterJ = RotL64((aOrbiterJ * 9575408950550922039U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 7427959503086895166U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 9895804051379551393U) ^ aNonceWordI;
            aOrbiterB = RotL64((aOrbiterB * 2701997336201570715U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 4526020800679774259U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 4484850928870048176U;
            aOrbiterG = RotL64((aOrbiterG * 17556987520625677313U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 1837404844299040155U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 15213208978489570694U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7062740584650274133U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 9615231781751396800U) + aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 15872192167825648096U;
            aOrbiterC = RotL64((aOrbiterC * 2900526493682580729U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 12530672039655918903U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 10617836782870315804U;
            aOrbiterF = RotL64((aOrbiterF * 9716778004909794973U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 550750725406860977U) + aOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 3498554352021622907U;
            aOrbiterD = RotL64((aOrbiterD * 9846933294851238495U), 5U);
            //
            aIngress = RotL64(aOrbiterF, 35U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterH, 40U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterK, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 48U) + RotL64(aOrbiterF, 18U)) + aOrbiterK) + aNonceWordB);
            aWandererF = aWandererF + ((((RotL64(aScatter, 11U) + aOrbiterH) + RotL64(aOrbiterA, 23U)) + RotL64(aCarry, 57U)) + aNonceWordC);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterA, 3U)) + aWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 43U) + aOrbiterF) + RotL64(aOrbiterC, 57U)) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 39U)) + aOrbiterJ) + aWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 57U) + RotL64(aOrbiterK, 10U)) + aOrbiterB);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 21U) + aOrbiterF) + RotL64(aOrbiterH, 43U));
            aWandererD = aWandererD + ((RotL64(aIngress, 27U) + RotL64(aOrbiterD, 47U)) + aOrbiterG);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 36U) + RotL64(aOrbiterD, 53U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 30U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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

void TwistExpander_Cricket_Arx::KDF_B_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xBA9BEF979918194DULL + 0xDBA75DCF82EFD1CBULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xCAB6F7253DC2CFA5ULL + 0xB734B1D59F0FD17EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC286DD504E44D5EBULL + 0x97D8C61C9EFCD312ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xDF9465ADA430EBD9ULL + 0xE65DE0ACC8CFEF79ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xE6E7045F60D7E63DULL + 0xA4F7F7F034E6EACCULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x8CB0C15CCB4D0BB5ULL + 0xFEF0EC7E7554FCBFULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xE3F8E845C4E2E8B1ULL + 0x868F1BEF98F4CFDDULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xCB334E5744DC8703ULL + 0xD15B504D5EED9CDCULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xA17AA7188723CA0BULL + 0xA550F851993D191AULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x88F35CDDC9D0B191ULL + 0xCAF1E96D31E7AB95ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xAF18050AB6CEDD01ULL + 0xF31B5E7C81BB815DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xF121AA5A8A4959C3ULL + 0xBF810F42B890D384ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xBC875EFCD58CC2E5ULL + 0xCE772F503CBD48D6ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xA8B061A377D740DFULL + 0xEEBB63E8BCC9FE33ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xB25B66FE371396E5ULL + 0xB169FE0766AF3AE0ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xCAD9BB1C8B551D09ULL + 0x9A156CC0D72865ACULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aOperationLaneA, aWorkLaneC, aWorkLaneD, aOperationLaneC, aExpandLaneA, aOperationLaneB, aFireLaneA, aExpandLaneB, aFireLaneB, aOperationLaneD, aExpandLaneC, aFireLaneC, aFireLaneD
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_d loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aOperationLaneA
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aOperationLaneA forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aOperationLaneC
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 647U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneB[((aIndex + 5652U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 240U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6819U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 4404U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 517U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aIngress, 13U)) ^ (RotL64(aCross, 29U) + RotL64(aPrevious, 42U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterE = ((aWandererG + RotL64(aCross, 43U)) + RotL64(aCarry, 37U)) + 15036852811491820366U;
            aOrbiterI = (((aWandererK + RotL64(aPrevious, 11U)) + 305637140752898475U) + aOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordM;
            aOrbiterK = (aWandererA + RotL64(aIngress, 19U)) + 11948631574496129610U;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 57U)) + RotL64(aCarry, 3U)) + 5321623592482991426U;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 5U)) + RotL64(aCarry, 23U)) + 4075270159062690728U;
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 36U)) + 15111580500356908928U) + aNonceWordK;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 51U)) + 7244150695504160363U) + aOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 5131563519577488862U) + aNonceWordG;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 5881954992088651371U;
            aOrbiterK = RotL64((aOrbiterK * 2424421828597294607U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 12780935808751507998U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 12599159643925470226U) ^ aOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17690046932587062701U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 9466589929741834066U) + aNonceWordE;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 6093158735705189789U) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 7453778295800853653U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 17461243886150519249U) + aOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 15456408913739900718U;
            aOrbiterI = RotL64((aOrbiterI * 16093292401746174671U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 11260643903290392780U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 7870342756041882616U;
            aOrbiterE = RotL64((aOrbiterE * 2431528656086173419U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 134484990005888936U) + aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 10626896209992890407U;
            aOrbiterG = RotL64((aOrbiterG * 12034131076645285597U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 14031164129515132292U) + aNonceWordL;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 1771835705730244212U;
            aOrbiterH = RotL64((aOrbiterH * 186981668443596623U), 29U);
            //
            aIngress = RotL64(aOrbiterC, 5U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 58U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterI, 14U)) + aNonceWordD);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 58U) + RotL64(aOrbiterK, 29U)) + aOrbiterH) + aWandererUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 23U)) + aOrbiterC) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterD, 37U)) + aOrbiterK);
            aWandererI = aWandererI + (((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterG, 43U)) + aWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 21U) + RotL64(aOrbiterH, 53U)) + aOrbiterG) + aNonceWordA);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 60U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + RotL64(aWandererG, 5U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aOperationLaneB
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aOperationLaneB forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aFireLaneA
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 13534U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneC[((aIndex + 11186U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 9917U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13939U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 13328U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 12196U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCarry, 13U)) ^ (RotL64(aCross, 60U) + RotL64(aPrevious, 47U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterI = (aWandererF + RotL64(aScatter, 46U)) + 14686411261024919129U;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 39U)) + 7514582233957632005U) + aOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 13U)) + 6520710480103365552U) + aNonceWordC;
            aOrbiterB = (((aWandererJ + RotL64(aCross, 29U)) + RotL64(aCarry, 11U)) + 1983621978676188036U) + aNonceWordP;
            aOrbiterK = (aWandererD + RotL64(aPrevious, 21U)) + 9003524602590749672U;
            aOrbiterE = (((aWandererE + RotL64(aIngress, 5U)) + RotL64(aCarry, 27U)) + 6428568234045228995U) + aOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aScatter, 57U)) + RotL64(aCarry, 51U)) + 8656552687136446989U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 16916248288415922490U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 9740237548002535784U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7970729853948983849U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 907561000814618339U) + aOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 4751108900841197631U;
            aOrbiterK = RotL64((aOrbiterK * 4545395964730641957U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 167774899400732287U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 11907484918310854962U;
            aOrbiterE = RotL64((aOrbiterE * 7213139491146402985U), 13U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterH) + 14910318613649863924U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordL;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 14882888155751455276U;
            aOrbiterD = RotL64((aOrbiterD * 11394136445442060201U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 16175942562693781908U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterH) ^ 11022373758481651102U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 6836331461393816027U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 12548405399045031548U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 10850926364556828443U;
            aOrbiterI = RotL64((aOrbiterI * 16231561687709867431U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 13391684887911141790U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 14648937281264822988U;
            aOrbiterH = RotL64((aOrbiterH * 6533299316940026059U), 3U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterB, 60U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 41U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + RotL64(aOrbiterH, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 50U) + aOrbiterK) + RotL64(aOrbiterD, 37U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 13U) + RotL64(aOrbiterE, 3U)) + aOrbiterF) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterI, 43U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterE, 29U)) + aOrbiterB) + aNonceWordD);
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 19U)) + aOrbiterD) + aNonceWordB) + aWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 56U)) + aOrbiterH) + RotL64(aCarry, 3U)) + aNonceWordH);
            aWandererH = aWandererH ^ ((((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterB, 13U)) + aNonceWordN) + aWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + RotL64(aWandererE, 34U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aFireLaneB
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aOperationLaneD
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 20484U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneD[((aIndex + 16629U)) & S_BLOCK1], 54U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 16530U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 17493U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20385U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 18693U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 50U) + RotL64(aCross, 3U)) + (RotL64(aPrevious, 37U) ^ RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 11U)) + 1888427424966603593U) + aNonceWordL;
            aOrbiterJ = (((aWandererC + RotL64(aIngress, 51U)) + RotL64(aCarry, 19U)) + 5436761445660415091U) + aNonceWordB;
            aOrbiterC = ((aWandererF + RotL64(aCross, 19U)) + RotL64(aCarry, 5U)) + 17322876217962143270U;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 41U)) + RotL64(aCarry, 53U)) + 9728299982740564979U;
            aOrbiterB = ((aWandererB + RotL64(aCross, 3U)) + 301720335271716921U) + aOrbiterAssignSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 58U)) + 8069685428854814396U) + aNonceWordA;
            aOrbiterK = ((aWandererE + RotL64(aScatter, 27U)) + 1973715500949100991U) + aOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 87666408799854155U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 12195436904339035245U;
            aOrbiterC = RotL64((aOrbiterC * 15427739165893738105U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 4578742069143400295U) + aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 7828776048774876484U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4047964518501081039U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 17203146364542781833U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 16913369550858890466U;
            aOrbiterI = RotL64((aOrbiterI * 13534417587921978507U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 9632761514552265402U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 9106637671877341286U) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 9073709119482640391U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 15423680889126750876U) + aOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 6087310684583331882U;
            aOrbiterH = RotL64((aOrbiterH * 8964465129744898619U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 5420955876411796789U) + aNonceWordD;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 14166807419730848032U) ^ aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 442659738632823751U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 8118312450347026824U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 4253043584558403086U;
            aOrbiterB = RotL64((aOrbiterB * 5651748455190536467U), 39U);
            //
            aIngress = RotL64(aOrbiterC, 51U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + RotL64(aOrbiterJ, 40U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterI, 11U)) + aOrbiterH) + RotL64(aCarry, 19U)) + aNonceWordK);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 13U) + aOrbiterK) + RotL64(aOrbiterJ, 51U)) + aWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 3U)) + aOrbiterJ);
            aWandererF = aWandererF ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterC, 28U)) + aOrbiterH);
            aWandererC = aWandererC + (((RotL64(aScatter, 34U) + aOrbiterC) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 5U) + aOrbiterI) + RotL64(aOrbiterA, 43U)) + aNonceWordN) + aWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 19U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 30U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 5U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneC
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aFireLaneD
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 24907U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneA[((aIndex + 30954U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 29487U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25595U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 30457U)) & S_BLOCK1], 28U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 32633U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCross, 10U)) ^ (RotL64(aCarry, 35U) + RotL64(aIngress, 47U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterF = ((aWandererK + RotL64(aIngress, 29U)) + 2101601659597850213U) + aOrbiterAssignSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aScatter, 56U)) + RotL64(aCarry, 47U)) + 2759794072560720121U;
            aOrbiterG = ((aWandererI + RotL64(aCross, 19U)) + RotL64(aCarry, 27U)) + 9443562552411269339U;
            aOrbiterE = (((aWandererJ + RotL64(aPrevious, 47U)) + 10801360546699857975U) + aOrbiterAssignSaltC[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordK;
            aOrbiterK = ((aWandererE + RotL64(aScatter, 11U)) + 8020716394829332019U) + aNonceWordH;
            aOrbiterH = (((aWandererD + RotL64(aIngress, 41U)) + RotL64(aCarry, 13U)) + 1021894212367773801U) + aNonceWordL;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 35U)) + 13346855534622490176U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 16359309548462953836U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 12642446944680783519U) ^ aOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12197935153255283321U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 8197424982767553380U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 14346334610901859094U;
            aOrbiterF = RotL64((aOrbiterF * 16982899923227935679U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 14171304260534233539U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 334531601308283605U) ^ aNonceWordG;
            aOrbiterK = RotL64((aOrbiterK * 5012968232749075075U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 10707856298471572695U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 18364775750091914766U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15735143943129143265U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 8531394793118363836U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 15352876929406908882U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 475199047053777179U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 567682016232278157U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 2068146551757663119U) ^ aNonceWordO;
            aOrbiterD = RotL64((aOrbiterD * 1557877740957797555U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 7776122587613256525U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 16430938890724272256U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4540270493783593257U), 57U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterD, 29U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterG, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 54U)) + aOrbiterK) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 43U) + aOrbiterH) + RotL64(aOrbiterE, 47U)) + aNonceWordA) + aWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterB, 35U)) + aOrbiterD) + RotL64(aCarry, 51U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterH, 3U)) + aOrbiterG) + aNonceWordN);
            aWandererD = aWandererD + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 13U)) + aOrbiterD) + aWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterK, 41U)) + aOrbiterH) + aNonceWordI);
            aWandererB = aWandererB + (((RotL64(aIngress, 58U) + aOrbiterF) + RotL64(aOrbiterD, 21U)) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (RotL64(aWandererI, 14U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererJ, 51U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_Cricket_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF;
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
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA;
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
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x8B7EE1F25CA87BCFULL + 0xC2CFBB88E4B4BABEULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xF845DDD2A1EE5BEDULL + 0xE8198202F05EBBDCULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xA2C7FE4CB41D1297ULL + 0x8951A00AB42C77DEULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xFD4A6FF9C8FB39D5ULL + 0xF4AFAD132D442075ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xEB69A83DBDB8D90FULL + 0xEAD0D8158E255860ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x9B5A4C21E31A0D81ULL + 0xFDADA6D763E7D09BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xCB333CDFD47FDE2DULL + 0xEDBFE39278F51701ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF3C01E0F66C196A9ULL + 0xD9E5D6E1F5E48159ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xBC65D819B3607DD1ULL + 0xE6C33C7460F1E324ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x8E5CF4BD86353975ULL + 0x8E0FD44AA41D3A59ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xFB00581EE4287797ULL + 0xC2D051FC3694D322ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xA54E61E62C7005C5ULL + 0xA55FC29D4BC548DAULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xD293C36E6CACE4D7ULL + 0xC96EB34CA0BCF921ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x8086E37B37F86BC5ULL + 0x8A35D7490371E3A6ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xD50CA5B186D56A29ULL + 0xAA706BB7292CEBD8ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xDB92AC9CB680EC95ULL + 0xD4D7336A25F4F424ULL);
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 1293U)) & W_KEY1], 11U) ^ RotL64(aKeyRowReadB[((aIndex + 1078U)) & W_KEY1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 785U)) & W_KEY1], 60U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 2222U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 6U) ^ RotL64(aIngress, 51U)) + (RotL64(aCross, 37U) + RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterE = (((aWandererB + RotL64(aCross, 47U)) + 9220392006207660113U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 41U)) + RotL64(aCarry, 21U)) + 11305018553489132882U;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 11U)) + RotL64(aCarry, 37U)) + 5860373868073513684U;
            aOrbiterC = (((aWandererD + RotL64(aIngress, 23U)) + 12319586170883987589U) + aPhaseEOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1]) + aNonceWordE;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 3U)) + 14072333614354649021U;
            aOrbiterB = (aWandererA + RotL64(aIngress, 58U)) + 9332158529453194608U;
            aOrbiterK = ((aWandererE + RotL64(aCross, 29U)) + RotL64(aCarry, 53U)) + 3860569321145958686U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 8119005668901240093U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 13918259792880333239U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5441062406822088853U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 6938856216758228704U) + aNonceWordC;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 3960905839118710604U;
            aOrbiterA = RotL64((aOrbiterA * 16203746868670689793U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 6043879193734253929U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 15691425268831319195U;
            aOrbiterB = RotL64((aOrbiterB * 7189195135654636271U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 14912209933584715274U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 16180183395910618923U) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 3942858974766467849U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 4966642362507707776U) + aNonceWordB;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 6962226782462822861U;
            aOrbiterE = RotL64((aOrbiterE * 3647802407741095419U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 12409120845092026295U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 2302946450253872465U;
            aOrbiterG = RotL64((aOrbiterG * 7099576330777297911U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 16118304388937163838U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 15968419034359049422U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11736207775827080165U), 5U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 41U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 29U)) + aOrbiterG) + aNonceWordK) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aCross, 14U) + aOrbiterG) + RotL64(aOrbiterA, 5U)) + aNonceWordP) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 21U)) + aOrbiterK);
            aWandererG = aWandererG + (((RotL64(aScatter, 53U) + aOrbiterC) + RotL64(aOrbiterE, 47U)) + RotL64(aCarry, 3U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 13U)) + aOrbiterJ) + aNonceWordI);
            aWandererE = aWandererE + ((((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterJ, 41U)) + RotL64(aCarry, 29U)) + aNonceWordN);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterB, 56U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 22U));
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 51U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 4516U)) & S_BLOCK1], 53U) ^ RotL64(aKeyRowReadA[((aIndex + 5370U)) & W_KEY1], 5U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 3270U)) & W_KEY1], 50U) ^ RotL64(mSource[((aIndex + 3926U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aPrevious, 51U)) ^ (RotL64(aCarry, 39U) + RotL64(aIngress, 26U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterG = ((aWandererK + RotL64(aCross, 53U)) + 2617613537256538553U) + aNonceWordE;
            aOrbiterB = (((aWandererG + RotL64(aScatter, 35U)) + RotL64(aCarry, 5U)) + 16642868916835132715U) + aNonceWordC;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 60U)) + 10860291124337073254U;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 19U)) + 6432511273906902472U;
            aOrbiterC = (((aWandererF + RotL64(aPrevious, 21U)) + RotL64(aCarry, 35U)) + 7505375005848241910U) + aPhaseEOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aIngress, 5U)) + 11086616004678821329U;
            aOrbiterK = ((aWandererB + RotL64(aCross, 27U)) + 3298830587569881951U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 9775143140064220979U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 4147601326580823120U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13462244678782260871U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 12245920269898100415U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 8391940489176734499U;
            aOrbiterG = RotL64((aOrbiterG * 9119606167674098007U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 17876893379544668477U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 18301882058180370541U;
            aOrbiterJ = RotL64((aOrbiterJ * 16680384667098921309U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 6869225862715140102U) + aNonceWordF;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 15404118372589259800U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5766851935950389915U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 17757381020518233814U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 17677969146092374455U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3469432916562405063U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 15783378556632870114U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 5792858258663697864U) ^ aNonceWordL;
            aOrbiterC = RotL64((aOrbiterC * 12008981883482080427U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 11737803388202260296U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 16001927091970715330U;
            aOrbiterB = RotL64((aOrbiterB * 3062030309852922061U), 27U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 60U);
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterB, 41U)) + RotL64(aCarry, 29U)) + aPhaseEWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 11U) + aOrbiterH) + RotL64(aOrbiterA, 29U)) + aNonceWordM) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterB, 19U)) + aNonceWordP);
            aWandererH = aWandererH ^ ((RotL64(aCross, 53U) + aOrbiterG) + RotL64(aOrbiterK, 3U));
            aWandererD = aWandererD + (((RotL64(aIngress, 19U) + RotL64(aOrbiterC, 12U)) + aOrbiterJ) + aNonceWordG);
            aWandererB = aWandererB ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterC, 53U)) + aOrbiterG) + aNonceWordD);
            aWandererG = aWandererG + (((RotL64(aScatter, 26U) + RotL64(aOrbiterK, 47U)) + aOrbiterA) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 26U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 7591U)) & S_BLOCK1], 27U) ^ RotL64(aKeyRowReadB[((aIndex + 6021U)) & W_KEY1], 11U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7914U)) & W_KEY1], 53U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6766U)) & S_BLOCK1], 6U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 8129U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCarry, 3U)) ^ (RotL64(aPrevious, 35U) ^ RotL64(aCross, 48U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterI = ((aWandererK + RotL64(aScatter, 19U)) + RotL64(aCarry, 43U)) + 13174219512651137892U;
            aOrbiterF = ((aWandererA + RotL64(aCross, 51U)) + RotL64(aCarry, 11U)) + 2715455762789269341U;
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 29U)) + 1338018183235594313U) + aPhaseEOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = (((aWandererB + RotL64(aPrevious, 44U)) + RotL64(aCarry, 57U)) + 16566866551729552930U) + aNonceWordK;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 37U)) + 6901845297307236726U) + aNonceWordE;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 11U)) + 2476078302049201718U) + aNonceWordL;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 5U)) + 15531109473927052260U) + aPhaseEOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 4087849380858572351U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 5167830630098599644U) ^ aNonceWordH;
            aOrbiterB = RotL64((aOrbiterB * 1982835131228146099U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 7275995452428627217U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 14794340370010024117U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8779497557416568379U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 8509217403041662849U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 2321522025240806996U;
            aOrbiterD = RotL64((aOrbiterD * 113568101672878697U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 5676672952755594051U) + aNonceWordG;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 2304681269233504384U;
            aOrbiterJ = RotL64((aOrbiterJ * 15731441084605554497U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 8383399721062437300U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 13181984036942227666U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1648761328771932069U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 13602604532551684210U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 12725687663616352843U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4684699861686199753U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 5831790822416009806U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 4535048543735457407U) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 12076777878870257053U), 3U);
            //
            aIngress = RotL64(aOrbiterK, 35U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 14U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterH, 43U)) + aOrbiterK) + aNonceWordN);
            aWandererK = aWandererK + (((((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 19U)) + aNonceWordI) + aPhaseEWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterD, 51U)) + aOrbiterF);
            aWandererB = aWandererB + ((RotL64(aIngress, 43U) + RotL64(aOrbiterI, 12U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterB, 5U)) + aOrbiterF);
            aWandererE = aWandererE + ((((RotL64(aCross, 3U) + RotL64(aOrbiterF, 57U)) + aOrbiterI) + RotL64(aCarry, 43U)) + aNonceWordA);
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 28U) + aOrbiterK) + RotL64(aOrbiterJ, 23U)) + aNonceWordD) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 44U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 8264U)) & S_BLOCK1], 35U) ^ RotL64(aKeyRowReadB[((aIndex + 10717U)) & W_KEY1], 43U));
            aIngress ^= (RotL64(mSource[((aIndex + 10744U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10101U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 8596U)) & W_KEY1], 19U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 10645U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 24U)) ^ (RotL64(aCross, 11U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterG = (aWandererB + RotL64(aCross, 3U)) + 4179952823252098240U;
            aOrbiterE = ((((aWandererC + RotL64(aIngress, 47U)) + RotL64(aCarry, 35U)) + 3745613452332101749U) + aPhaseFOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1]) + aNonceWordN;
            aOrbiterH = ((((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 51U)) + 2955689793395307176U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordB;
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 13U)) + RotL64(aCarry, 19U)) + 5639060180251322019U;
            aOrbiterJ = (aWandererA + RotL64(aCross, 21U)) + 7901969163853586463U;
            aOrbiterC = (aWandererD + RotL64(aPrevious, 38U)) + 2242166787816318119U;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 29U)) + 5239936443960750064U) + aNonceWordK;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 13939136954732185558U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 17058884136712717463U) ^ aNonceWordJ;
            aOrbiterH = RotL64((aOrbiterH * 7222348891215482977U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 18148618660054585941U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 7022023484530327814U) ^ aNonceWordA;
            aOrbiterG = RotL64((aOrbiterG * 650100011311048589U), 37U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterH) + 7722084537340095637U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1]) + aNonceWordH;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 11764151879690934182U;
            aOrbiterC = RotL64((aOrbiterC * 12264384877711365655U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 16412785901758144708U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = (((aOrbiterF ^ aOrbiterC) ^ 9666718667728274824U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 10865799822751771795U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 4307127540152109364U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 2457646804702647606U;
            aOrbiterJ = RotL64((aOrbiterJ * 6340030928007058595U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 3179394870088602208U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 504977947273774249U;
            aOrbiterE = RotL64((aOrbiterE * 16190282058883481551U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 16182729401018310837U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 7110817020445860609U;
            aOrbiterB = RotL64((aOrbiterB * 13371352088428584087U), 19U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 53U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + RotL64(aOrbiterC, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 53U)) + aOrbiterB);
            aWandererI = aWandererI ^ ((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterC, 13U));
            aWandererK = aWandererK + (((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 58U) + RotL64(aOrbiterJ, 3U)) + aOrbiterF) + aNonceWordF);
            aWandererH = aWandererH + (((RotL64(aCross, 11U) + aOrbiterH) + RotL64(aOrbiterB, 43U)) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterF, 36U)) + aNonceWordL) + aPhaseFWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 41U) + RotL64(aOrbiterF, 23U)) + aOrbiterB) + aNonceWordE) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 26U));
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 12668U)) & S_BLOCK1], 37U) ^ RotL64(aKeyRowReadA[((aIndex + 12100U)) & W_KEY1], 58U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 13118U)) & W_KEY1], 11U) ^ RotL64(mSource[((aIndex + 11197U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 13010U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12306U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneC[((aIndex + 12496U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 41U)) + (RotL64(aIngress, 56U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterG = ((aWandererA + RotL64(aCross, 53U)) + 18191288703716505885U) + aPhaseFOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 4U)) + RotL64(aCarry, 53U)) + 9824014524910417136U;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 27U)) + 11953012029254917548U) + aNonceWordE;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 13U)) + 6297568011027199089U) + aNonceWordG;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 47U)) + 2576999400457367975U) + aNonceWordC;
            aOrbiterE = (((aWandererD + RotL64(aCross, 21U)) + RotL64(aCarry, 3U)) + 13176139160575558254U) + aPhaseFOrbiterAssignSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = ((aWandererI + RotL64(aIngress, 37U)) + RotL64(aCarry, 27U)) + 9978408174563621810U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 16765834875061607142U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 16534507305459121344U;
            aOrbiterC = RotL64((aOrbiterC * 8943988574248229067U), 57U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterI) + 3114710944346151807U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1]) + aNonceWordD;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 10240517868726718592U;
            aOrbiterB = RotL64((aOrbiterB * 4645691562915606463U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 10721450637990777883U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 16689590768796583952U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3046344179729901637U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 2427422768928450209U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 13495584061816457831U) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 6670984773768885119U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 7058636403765106682U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 9897341853944713767U;
            aOrbiterK = RotL64((aOrbiterK * 14286816859999869231U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 17749559755733386064U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 12515645083926326659U;
            aOrbiterD = RotL64((aOrbiterD * 6582878478865838245U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 2625692458813609962U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 10596240255026143019U;
            aOrbiterE = RotL64((aOrbiterE * 11605800195771080135U), 47U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterI, 21U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 10U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 18U) + RotL64(aOrbiterE, 60U)) + aOrbiterI) + aNonceWordJ);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterG, 13U)) + aNonceWordO);
            aWandererK = aWandererK + (((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterG, 37U)) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 23U)) + aOrbiterD);
            aWandererI = aWandererI + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 5U)) + aOrbiterC) + aNonceWordH) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterK, 53U)) + aOrbiterB) + aNonceWordP) + aPhaseFWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 35U) + RotL64(aOrbiterC, 29U)) + aOrbiterK) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 10U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 13822U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneC[((aIndex + 15998U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15391U)) & W_KEY1], 21U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 15508U)) & W_KEY1], 47U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 14535U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 15089U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15729U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCross, 3U)) ^ (RotL64(aIngress, 41U) + RotL64(aCarry, 54U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterD = (aWandererF + RotL64(aPrevious, 44U)) + 6469584119078165548U;
            aOrbiterC = ((aWandererK + RotL64(aCross, 3U)) + RotL64(aCarry, 11U)) + 14329756366517987910U;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 13U)) + 12890831797059772123U) + aPhaseFOrbiterAssignSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = (((aWandererB + RotL64(aIngress, 57U)) + RotL64(aCarry, 57U)) + 3164503807500018990U) + aNonceWordN;
            aOrbiterA = ((((aWandererG + RotL64(aPrevious, 37U)) + RotL64(aCarry, 43U)) + 177531431387646836U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordH;
            aOrbiterB = ((aWandererJ + RotL64(aCross, 29U)) + 3167421392893561015U) + aNonceWordC;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 21U)) + 2813174781844753460U) + aNonceWordA;
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 10953270419153249857U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 16911518309710356951U;
            aOrbiterJ = RotL64((aOrbiterJ * 13162785997686570445U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 6616750447844893150U) + aNonceWordD;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 10276741398025985982U;
            aOrbiterA = RotL64((aOrbiterA * 6824712685896987133U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 6206043608461213208U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 12021552904553405793U) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 10023362889960174909U), 57U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterK) + 15283586234744144846U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1]) + aNonceWordL;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 5923238786775948571U;
            aOrbiterD = RotL64((aOrbiterD * 8200882393521882651U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 11044014510971660078U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 9351141024085076044U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13316079344614432317U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 17703395981862992420U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 10154548848376027087U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12324478347590509035U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 8836420852291617425U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterA) ^ 10193385413543886344U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterB = RotL64((aOrbiterB * 824935982418585449U), 35U);
            //
            aIngress = RotL64(aOrbiterJ, 27U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + (RotL64(aOrbiterK, 53U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterB, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterA, 29U)) + aOrbiterK) + RotL64(aCarry, 19U)) + aNonceWordF);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterI, 23U)) + aOrbiterJ);
            aWandererB = aWandererB + (((RotL64(aScatter, 28U) + RotL64(aOrbiterJ, 47U)) + aOrbiterK) + aNonceWordJ);
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 13U) + aOrbiterK) + RotL64(aOrbiterB, 11U)) + aNonceWordB) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 21U) + RotL64(aOrbiterC, 35U)) + aOrbiterB);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterD, 41U)) + aNonceWordM);
            aWandererG = aWandererG + ((((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterK, 60U)) + RotL64(aCarry, 37U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 50U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 21U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 17052U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadA[((aIndex + 17487U)) & W_KEY1], 14U));
            aIngress ^= (RotL64(mSource[((aIndex + 16564U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((aIndex + 19061U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 16622U)) & W_KEY1], 54U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16738U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 18964U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 23U)) ^ (RotL64(aIngress, 53U) ^ RotL64(aCross, 40U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterH = (((aWandererD + RotL64(aCross, 13U)) + 5041131702736607991U) + aPhaseGOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1]) + aNonceWordG;
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 3U)) + RotL64(aCarry, 47U)) + 9295010428212681446U;
            aOrbiterI = (((aWandererG + RotL64(aIngress, 53U)) + RotL64(aCarry, 13U)) + 6235875895358766017U) + aNonceWordE;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 47U)) + RotL64(aCarry, 29U)) + 2622227802531866918U;
            aOrbiterG = (aWandererA + RotL64(aCross, 41U)) + 3888894734834524972U;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 30U)) + 241682012014701753U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = (aWandererK + RotL64(aIngress, 19U)) + 15758000422451568079U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 2061944548396976912U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 8177144990755754531U) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 12702392689484397947U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 554978075608818497U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 250408260560714933U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1295379390497107727U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 8700027645880997552U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 10026130047465480902U;
            aOrbiterC = RotL64((aOrbiterC * 12417270861933696623U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 9785843014096326696U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 9998582683258411251U;
            aOrbiterG = RotL64((aOrbiterG * 7197956237569462269U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 13817734599383455151U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 6647207154174092691U;
            aOrbiterJ = RotL64((aOrbiterJ * 1578528131687283531U), 37U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterJ) + 4957715980509035719U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1]) + aNonceWordA;
            aOrbiterH = (((aOrbiterH ^ aOrbiterB) ^ 4994885315786213197U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 5676683798126497011U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 5072908311783966503U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 5535039946192891515U) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 2989412783482309753U), 47U);
            //
            aIngress = RotL64(aOrbiterF, 43U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterI, 27U)) + aNonceWordN);
            aWandererI = aWandererI ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterG, 21U)) + aOrbiterJ);
            aWandererG = aWandererG + ((RotL64(aScatter, 60U) + RotL64(aOrbiterI, 35U)) + aOrbiterC);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 11U) + aOrbiterF) + RotL64(aOrbiterC, 5U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererK = aWandererK + (((((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterC, 41U)) + RotL64(aCarry, 19U)) + aNonceWordB) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 51U)) + aOrbiterF);
            aWandererF = aWandererF + (((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterC, 58U)) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 44U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 20299U)) & S_BLOCK1], 13U) ^ RotL64(mSource[((aIndex + 20550U)) & S_BLOCK1], 51U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 19674U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19815U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 19610U)) & W_KEY1], 35U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 20479U)) & W_KEY1], 3U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 20606U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneB[((aIndex + 20703U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aIngress, 57U)) ^ (RotL64(aCarry, 18U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterB = (aWandererE + RotL64(aCross, 19U)) + 6068543441070417854U;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 29U)) + 2995980468193441856U) + aNonceWordD;
            aOrbiterE = (aWandererB + RotL64(aIngress, 51U)) + 18020277482171594003U;
            aOrbiterI = (((aWandererJ + RotL64(aPrevious, 13U)) + 4293807434721230702U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordA;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 41U)) + RotL64(aCarry, 21U)) + 7980599111583893156U;
            aOrbiterF = (((aWandererK + RotL64(aPrevious, 60U)) + RotL64(aCarry, 37U)) + 8593141111851052016U) + aNonceWordP;
            aOrbiterJ = ((((aWandererH + RotL64(aScatter, 5U)) + RotL64(aCarry, 57U)) + 5903487523900084325U) + aPhaseGOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1]) + aNonceWordK;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 15112035513447930209U) + aNonceWordL;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 9854037263057006439U;
            aOrbiterE = RotL64((aOrbiterE * 396276470208637283U), 19U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterC) + 16759760289688823193U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordC;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 12622628933030601390U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2151912984825538321U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 1264668857268123425U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 16302812053619101593U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 18291400055836111547U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 16087995784896123610U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 7970269262800468363U;
            aOrbiterC = RotL64((aOrbiterC * 14924752223305807461U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 5331477046030959632U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 16534913204255550893U;
            aOrbiterI = RotL64((aOrbiterI * 1013433634373673565U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 11042821902537871209U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 8069677512345031660U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13622218526054132397U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 5737130058129936372U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 1076627182956662997U;
            aOrbiterB = RotL64((aOrbiterB * 14342191224014199929U), 11U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterI, 50U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 23U) + aOrbiterB) + RotL64(aOrbiterK, 11U)) + aPhaseGWandererUpdateSaltE[((aIndex + 26U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 14U) + RotL64(aOrbiterE, 19U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterE, 47U)) + aNonceWordI);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 57U) + aOrbiterF) + RotL64(aOrbiterI, 3U));
            aWandererE = aWandererE + (((((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterF, 53U)) + RotL64(aCarry, 11U)) + aNonceWordB) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterF, 29U)) + aOrbiterC);
            aWandererF = aWandererF + ((((RotL64(aCross, 47U) + aOrbiterI) + RotL64(aOrbiterJ, 38U)) + RotL64(aCarry, 27U)) + aNonceWordN);
            //
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 24U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 22978U)) & S_BLOCK1], 13U) ^ RotL64(aKeyRowReadA[((aIndex + 23037U)) & W_KEY1], 21U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 24574U)) & W_KEY1], 58U) ^ RotL64(aFireLaneC[((aIndex + 23892U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 23660U)) & S_BLOCK1], 37U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23267U)) & S_BLOCK1], 11U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 23871U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 22349U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aPrevious, 56U)) + (RotL64(aIngress, 43U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 11U)) + RotL64(aCarry, 27U)) + 10805654776556844351U;
            aOrbiterF = (((aWandererB + RotL64(aPrevious, 19U)) + RotL64(aCarry, 11U)) + 582794182442795335U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aIngress, 57U)) + 2858343650974681068U;
            aOrbiterK = (aWandererD + RotL64(aCross, 38U)) + 8189584049022064284U;
            aOrbiterA = (((aWandererG + RotL64(aIngress, 27U)) + RotL64(aCarry, 43U)) + 1565100751996962893U) + aNonceWordL;
            aOrbiterH = (((aWandererA + RotL64(aCross, 51U)) + 8062028016947611891U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordI;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 5U)) + 8280504280578451745U) + aNonceWordH;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 11326869194491655350U) + aNonceWordJ;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 1671695656567777163U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7511554500524257921U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 2349843105293943452U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 13015545152052004254U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1316662811685429983U), 3U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterJ) + 16703354404749291869U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordK;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 8713231044374305801U;
            aOrbiterF = RotL64((aOrbiterF * 9242480982197688625U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 11118401674497783533U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 14857556493734710364U;
            aOrbiterJ = RotL64((aOrbiterJ * 3452566050389715195U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 12953419670951660965U) + aNonceWordE;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 12666121730825089017U) ^ aNonceWordN;
            aOrbiterI = RotL64((aOrbiterI * 14049925256934142519U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 11075249639473053423U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 9374217688244187867U;
            aOrbiterK = RotL64((aOrbiterK * 5261156325627117877U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 17608340953291367867U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 13159437499327086340U;
            aOrbiterH = RotL64((aOrbiterH * 4882100944453534805U), 51U);
            //
            aIngress = RotL64(aOrbiterA, 27U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 58U));
            aIngress = aIngress + RotL64(aOrbiterH, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterA, 44U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterJ, 11U)) + aOrbiterH) + RotL64(aCarry, 5U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 11U) + aOrbiterK) + RotL64(aOrbiterG, 57U)) + aNonceWordC);
            aWandererI = aWandererI + (((RotL64(aCross, 23U) + aOrbiterJ) + RotL64(aOrbiterF, 5U)) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 58U) + RotL64(aOrbiterA, 19U)) + aOrbiterG);
            aWandererK = aWandererK + ((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterF, 27U));
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterI, 51U)) + aNonceWordF) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 36U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 25688U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadA[((aIndex + 25923U)) & W_KEY1], 21U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 25767U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneB[((aIndex + 26984U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 24867U)) & W_KEY1], 11U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26459U)) & S_BLOCK1], 3U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 24919U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 25865U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCarry, 11U)) + (RotL64(aIngress, 27U) ^ RotL64(aCross, 56U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterC = ((((aWandererA + RotL64(aScatter, 3U)) + RotL64(aCarry, 57U)) + 12669015908335980355U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordE;
            aOrbiterI = ((aWandererB + RotL64(aCross, 41U)) + 5438715179868613192U) + aNonceWordF;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 13U)) + 13172104448184536460U) + aNonceWordO;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 27U)) + RotL64(aCarry, 13U)) + 13421421503244744803U;
            aOrbiterH = (((aWandererD + RotL64(aIngress, 51U)) + RotL64(aCarry, 37U)) + 13327113302994856582U) + aPhaseHOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 34U)) + 4671768205922454413U) + aNonceWordB;
            aOrbiterJ = (aWandererJ + RotL64(aCross, 21U)) + 5355759962838579929U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 6691720614265406851U) + aNonceWordJ;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 7063906424700911378U;
            aOrbiterF = RotL64((aOrbiterF * 17091734375516280675U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 17328616394166672263U) + aNonceWordP;
            aOrbiterD = (((aOrbiterD ^ aOrbiterG) ^ 1542940602574207068U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterD = RotL64((aOrbiterD * 8981679306319627975U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 7203866278803132454U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 993485696233139264U;
            aOrbiterH = RotL64((aOrbiterH * 11609009908810366447U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 15659679028507488331U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterH) ^ 18321361454094675842U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 3966860765622641843U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 9633319822696783352U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 3496559332232402963U;
            aOrbiterG = RotL64((aOrbiterG * 7772060229838162977U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 1918349708324205526U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 7701088402761359134U;
            aOrbiterI = RotL64((aOrbiterI * 9649485438465644795U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 6006824348814439686U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 18088375375347012557U;
            aOrbiterJ = RotL64((aOrbiterJ * 12801082943086128385U), 5U);
            //
            aIngress = RotL64(aOrbiterD, 57U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + RotL64(aOrbiterI, 12U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 20U) + RotL64(aOrbiterJ, 21U)) + aOrbiterH) + RotL64(aCarry, 11U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterF, 53U)) + aPhaseHWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 11U) + aOrbiterH) + RotL64(aOrbiterC, 13U)) + aNonceWordI);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 41U) + aOrbiterF) + RotL64(aOrbiterI, 60U)) + aPhaseHWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterH, 29U)) + aNonceWordN);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterF, 47U));
            aWandererF = aWandererF + (((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 37U)) + aOrbiterI) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 6U));
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 21U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 29002U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneD[((aIndex + 28037U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 28001U)) & W_KEY1], 13U) ^ RotL64(aFireLaneC[((aIndex + 28332U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 28957U)) & W_KEY1], 19U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 27820U)) & S_BLOCK1], 52U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29883U)) & S_BLOCK1], 37U) ^ RotL64(aFireLaneB[((aIndex + 29250U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCarry, 23U)) + (RotL64(aIngress, 54U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 3U)) + 7651355040951791298U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = (((aWandererA + RotL64(aIngress, 11U)) + RotL64(aCarry, 37U)) + 13988210277931659312U) + aNonceWordJ;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 60U)) + 9846849412579537783U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (((aWandererI + RotL64(aCross, 21U)) + RotL64(aCarry, 11U)) + 12746719939495876158U) + aNonceWordN;
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 47U)) + RotL64(aCarry, 23U)) + 11498066185182895284U;
            aOrbiterK = (aWandererC + RotL64(aCross, 29U)) + 11101058955193080232U;
            aOrbiterD = (aWandererE + RotL64(aIngress, 53U)) + 15513734459555672046U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 15711108675349394643U) + aNonceWordF;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 4771231759949468556U;
            aOrbiterC = RotL64((aOrbiterC * 9806191054594333615U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 11449258010811305256U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 17036938391509986723U) ^ aNonceWordG;
            aOrbiterI = RotL64((aOrbiterI * 7411466953205347639U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 6999245666776654250U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 2106819066263369528U;
            aOrbiterK = RotL64((aOrbiterK * 13005885810757743129U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 12716183358903477216U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 16752724547046059889U;
            aOrbiterH = RotL64((aOrbiterH * 11475905692393034141U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 17623077680983093163U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 6726003022297274986U;
            aOrbiterB = RotL64((aOrbiterB * 14709385877103232653U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 2842410225096524740U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = (((aOrbiterD ^ aOrbiterC) ^ 9235178377537910514U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterD = RotL64((aOrbiterD * 11813751114775673845U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 2619888019860844610U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 6295481948199619613U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15429161806953951205U), 13U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 23U);
            aIngress = aIngress + (RotL64(aOrbiterH, 37U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 29U) + aOrbiterD) + RotL64(aOrbiterB, 29U)) + aNonceWordB);
            aWandererA = aWandererA + ((RotL64(aCross, 5U) + RotL64(aOrbiterK, 37U)) + aOrbiterD);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 5U)) + aOrbiterK) + aNonceWordE);
            aWandererC = aWandererC + (((RotL64(aIngress, 58U) + RotL64(aOrbiterB, 51U)) + aOrbiterH) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 41U) + aOrbiterK) + RotL64(aOrbiterB, 58U));
            aWandererG = aWandererG + ((((RotL64(aCross, 11U) + aOrbiterB) + RotL64(aOrbiterC, 23U)) + RotL64(aCarry, 51U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterB, 43U)) + aPhaseHWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 41U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 10U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + RotL64(aWandererA, 51U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 30616U)) & S_BLOCK1], 54U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 31747U)) & W_KEY1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 32294U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32646U)) & S_BLOCK1], 37U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31034U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadB[((aIndex + 30059U)) & W_KEY1], 3U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 29U) ^ RotL64(aCross, 53U)) ^ (RotL64(aPrevious, 41U) + RotL64(aCarry, 10U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 29U)) + RotL64(aCarry, 37U)) + 4980738603982643969U;
            aOrbiterB = (aWandererI + RotL64(aCross, 21U)) + 17660278413018470020U;
            aOrbiterF = (((aWandererG + RotL64(aScatter, 41U)) + 17598114429859543466U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordF;
            aOrbiterC = (((aWandererE + RotL64(aIngress, 47U)) + RotL64(aCarry, 5U)) + 10993929335279994739U) + aNonceWordG;
            aOrbiterD = ((aWandererF + RotL64(aCross, 56U)) + RotL64(aCarry, 21U)) + 17967203122976322481U;
            aOrbiterI = (aWandererA + RotL64(aPrevious, 11U)) + 1872290205549034384U;
            aOrbiterH = (((aWandererJ + RotL64(aScatter, 3U)) + 16607778671782810797U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordK;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 4895226930754394376U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 14960359005982301383U;
            aOrbiterF = RotL64((aOrbiterF * 8546231310054433721U), 3U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterC) + 9921642352377700630U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1]) + aNonceWordI;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 893281964367208693U;
            aOrbiterD = RotL64((aOrbiterD * 2345509157333444217U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 8232519988397858732U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 4433022122758913407U;
            aOrbiterI = RotL64((aOrbiterI * 834240393225479419U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 12689609831247168353U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 404535388957472176U;
            aOrbiterC = RotL64((aOrbiterC * 14534020545479806593U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 3349108201964013155U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterI) ^ 4386449511297371730U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterH = RotL64((aOrbiterH * 9596273264321140229U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 14314587717949070586U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 10923886625271054985U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7838969002623486809U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 17634909585329833520U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 2021301459918350372U;
            aOrbiterG = RotL64((aOrbiterG * 1388242915918642741U), 35U);
            //
            aIngress = RotL64(aOrbiterF, 29U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + RotL64(aOrbiterB, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aScatter, 39U) + RotL64(aOrbiterC, 19U)) + aOrbiterG) + RotL64(aCarry, 29U)) + aNonceWordE);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterH, 35U)) + aOrbiterG);
            aWandererA = aWandererA + (((RotL64(aIngress, 51U) + aOrbiterF) + RotL64(aOrbiterC, 29U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 13U)) + aOrbiterI);
            aWandererE = aWandererE + (((RotL64(aCross, 27U) + RotL64(aOrbiterB, 51U)) + aOrbiterG) + aNonceWordC);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterF, 4U)) + aOrbiterD);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterF, 41U)) + RotL64(aCarry, 3U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (RotL64(aWandererB, 26U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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

void TwistExpander_Cricket_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xCC92D6052D2066B7ULL + 0xB142DB4870FBBACDULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x8536A64DB68EA83BULL + 0x92477BB0B9D78316ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x921ABD9B23B52803ULL + 0xB65D66B266F0A8A3ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xAB26C8633F5D4F3FULL + 0xFAFD2A0E47E68376ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xD72861F2AC7316F7ULL + 0x8EC79ECF1942F769ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB31D74BA2812D373ULL + 0xA177DB99B88351C5ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xFC46B544AE28E927ULL + 0x8E5C2856329EFE3EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xE87400D171FC4A41ULL + 0x830CBF54A233FF34ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xF3AAB5071E47E903ULL + 0x901612DE5B3AE2E5ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xCFF0D8EE21C10269ULL + 0xF30C407CD8738C2AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xA6D6824F8C9993CFULL + 0xD63BBF0F58451B6DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xAD22D745DAA3BE47ULL + 0xFF92C0F95696B352ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xBFB607293D9D2401ULL + 0x8B5D66ABA8D3ADAEULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x86A4A911AFB63CCDULL + 0xF55710B9AED20760ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x9D053F30B4853689ULL + 0xD5C121D2682983EFULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xD420E9ACBAE5CD5BULL + 0x9CF01C04970B7E08ULL);
    // GSeedRunSeed_B seed_loop_a (start)
    {
        // GSeedRunSeed_B seed_loop_a lane group
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneD, aExpandLaneC, aExpandLaneD, aInvestLaneA, aFireLaneC, aInvestLaneB, aFireLaneB, aOperationLaneA, aFireLaneA, aOperationLaneB, aOperationLaneC
        // write to: aInvestLaneA, aInvestLaneB, aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // seed_loop_a loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneD
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 2640U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((aIndex + 3680U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 2320U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1606U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneD[((aIndex + 3216U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 4U) + RotL64(aPrevious, 39U)) ^ (RotL64(aIngress, 21U) + RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterB = (((aWandererF + RotL64(aPrevious, 5U)) + RotL64(aCarry, 47U)) + 17470880031634374199U) + aPhaseAOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aCross, 53U)) + RotL64(aCarry, 5U)) + 757565846006937746U;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 36U)) + RotL64(aCarry, 21U)) + 9419282475801345674U;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 21U)) + 2014248014107898196U) + aNonceWordN;
            aOrbiterC = (((aWandererA + RotL64(aIngress, 13U)) + 15113928519446490441U) + aPhaseAOrbiterAssignSaltE[((aIndex + 18U)) & S_SALT1]) + aNonceWordA;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 7346126964886259935U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterB) ^ 5594123113093162359U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterG = RotL64((aOrbiterG * 18043634828891483403U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 5659237263369402005U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 11565709683423969703U;
            aOrbiterE = RotL64((aOrbiterE * 16731289017588574671U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 16782863743534856287U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 13499100900072115907U;
            aOrbiterI = RotL64((aOrbiterI * 5567729598873214433U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 11414447651044205242U) + aNonceWordE;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 7545993795121430538U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10758488381206257261U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 11778229237616454988U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 2544793391976514665U;
            aOrbiterC = RotL64((aOrbiterC * 4021060413798523299U), 27U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterG, 35U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aCross, 11U) + aOrbiterC) + RotL64(aOrbiterG, 3U)) + aNonceWordI);
            aWandererK = aWandererK + ((((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterG, 28U)) + RotL64(aCarry, 5U)) + aPhaseAWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 30U) + aOrbiterB) + RotL64(aOrbiterI, 19U)) + aNonceWordB);
            aWandererF = aWandererF + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterI, 51U)) + aOrbiterE) + RotL64(aCarry, 29U)) + aNonceWordD);
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 41U) + aOrbiterE) + RotL64(aOrbiterB, 41U)) + aNonceWordP) + aPhaseAWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 36U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 2
        // ingress from: aInvestLaneA, aExpandLaneC, aFireLaneC
        // ingress directions: aInvestLaneA forward forced, aExpandLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneA[((aIndex + 7568U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneC[((aIndex + 7281U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 7708U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 5698U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8045U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCross, 42U)) ^ (RotL64(aPrevious, 11U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterI = ((aWandererH + RotL64(aIngress, 37U)) + 11039986441331892533U) + aPhaseAOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aScatter, 60U)) + RotL64(aCarry, 23U)) + 6256024955965426119U;
            aOrbiterD = (((aWandererA + RotL64(aCross, 29U)) + 9857443189988995666U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordL;
            aOrbiterB = (((aWandererG + RotL64(aPrevious, 51U)) + RotL64(aCarry, 57U)) + 11900944813380998208U) + aNonceWordC;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 11U)) + RotL64(aCarry, 35U)) + 8422577734978875541U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 3100835100713928724U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 11871553509810206993U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15501681886909921677U), 47U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterD) + 17614749493763417027U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1]) + aNonceWordP;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 3638372131856199916U;
            aOrbiterI = RotL64((aOrbiterI * 480683274898147025U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 6582275259281025770U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 17016882418498941958U;
            aOrbiterB = RotL64((aOrbiterB * 4269869255230867823U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 1747214688658984715U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 9356088987044015278U) ^ aNonceWordH;
            aOrbiterJ = RotL64((aOrbiterJ * 16221733545319753695U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 4056238112133473456U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 16013150119949532998U) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 12913648646318115315U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 47U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 37U));
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterB, 5U)) + aOrbiterE) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererD = aWandererD + (((((RotL64(aScatter, 13U) + aOrbiterI) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 23U)) + aNonceWordK) + aPhaseAWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterE, 41U)) + aOrbiterI) + aNonceWordN);
            aWandererG = aWandererG + ((((RotL64(aCross, 36U) + RotL64(aOrbiterB, 14U)) + aOrbiterD) + RotL64(aCarry, 41U)) + aNonceWordA);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterJ, 51U)) + aNonceWordB);
            //
            aCarry = aCarry + (RotL64(aWandererG, 56U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + RotL64(aWandererH, 39U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aInvestLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 3
        // ingress from: aInvestLaneB, aExpandLaneD, aFireLaneB
        // ingress directions: aInvestLaneB forward forced, aExpandLaneD forward forced, aFireLaneB forward/backward random
        // cross from: aInvestLaneA, aExpandLaneB, aExpandLaneA
        // cross directions: aInvestLaneA backward forced, aExpandLaneB backward forced, aExpandLaneA backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneB[((aIndex + 11495U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((aIndex + 15825U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 14217U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 11229U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 12018U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aExpandLaneA[((aIndex + 12159U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCross, 4U)) ^ (RotL64(aCarry, 39U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterD = (((aWandererA + RotL64(aPrevious, 34U)) + RotL64(aCarry, 57U)) + 16183871922837164759U) + aNonceWordB;
            aOrbiterG = ((aWandererH + RotL64(aCross, 3U)) + 7002058258090219055U) + aNonceWordA;
            aOrbiterC = (aWandererI + RotL64(aIngress, 21U)) + 5650868611888303705U;
            aOrbiterI = ((((aWandererF + RotL64(aScatter, 43U)) + RotL64(aCarry, 43U)) + 11899839660943876690U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordF;
            aOrbiterJ = ((((aWandererE + RotL64(aCross, 53U)) + RotL64(aCarry, 27U)) + 15349649504488111111U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordJ;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 14060149569086744970U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 12920917574225030112U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6552626684290469367U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 2831994965175330135U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 18312543585028439192U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11618182708195744321U), 27U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterI) + 11657562205118394239U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordP;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 10850792819281246052U;
            aOrbiterJ = RotL64((aOrbiterJ * 10663100544207879337U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 17810371216216125323U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 7963413941144223128U;
            aOrbiterG = RotL64((aOrbiterG * 534217972450595401U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 5498715358793875584U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterG) ^ 9256727548911651373U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterI = RotL64((aOrbiterI * 10498848323914000989U), 5U);
            //
            aIngress = RotL64(aOrbiterD, 57U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 20U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterG, 3U)) + aOrbiterC) + aNonceWordG);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterG, 43U)) + RotL64(aCarry, 39U)) + aNonceWordN);
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 18U) + aOrbiterD) + RotL64(aOrbiterI, 51U)) + aNonceWordD) + aPhaseAWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aIngress, 39U) + aOrbiterD) + RotL64(aOrbiterJ, 28U)) + RotL64(aCarry, 51U)) + aPhaseAWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 13U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 4
        // ingress from: aOperationLaneA, aInvestLaneA, aFireLaneA
        // ingress directions: aOperationLaneA forward forced, aInvestLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aInvestLaneB, aExpandLaneD, aExpandLaneC
        // cross directions: aInvestLaneB backward forced, aExpandLaneD backward forced, aExpandLaneC backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 16900U)) & S_BLOCK1], 48U) ^ RotL64(aInvestLaneA[((aIndex + 19493U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 19759U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 19073U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19438U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 18536U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCarry, 38U)) ^ (RotL64(aCross, 21U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterK = (((aWandererE + RotL64(aPrevious, 39U)) + RotL64(aCarry, 5U)) + 9041099828460168106U) + aNonceWordM;
            aOrbiterG = (((aWandererK + RotL64(aCross, 27U)) + RotL64(aCarry, 51U)) + 12883711604096848454U) + aNonceWordO;
            aOrbiterI = ((((aWandererF + RotL64(aScatter, 58U)) + RotL64(aCarry, 27U)) + 17420968786226443079U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordE;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 19U)) + 3448213891716125104U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (aWandererB + RotL64(aPrevious, 11U)) + 11866455977445336560U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 4119356835384495905U) + aNonceWordL;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 2186212599698637068U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6756888950976735707U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 6506144898969301620U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 12556800923644051626U;
            aOrbiterB = RotL64((aOrbiterB * 15961043406612913121U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 4075551535185182945U) + aNonceWordB;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 17877694808492008749U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 901315308379887473U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 5553428900598223316U) + aNonceWordD;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 14362304852277160675U) ^ aNonceWordP;
            aOrbiterK = RotL64((aOrbiterK * 11415103199856419303U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 9174200302876075831U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 16110739511917638547U;
            aOrbiterG = RotL64((aOrbiterG * 7004356839428657949U), 19U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterB, 51U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + RotL64(aOrbiterC, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterI, 11U)) + aOrbiterG) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 29U) + aOrbiterK) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 29U)) + aNonceWordJ);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 47U)) + aOrbiterC) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 53U) + aOrbiterI) + RotL64(aOrbiterB, 58U)) + RotL64(aCarry, 5U)) + aNonceWordG);
            aWandererK = aWandererK ^ (((RotL64(aCross, 14U) + RotL64(aOrbiterG, 3U)) + aOrbiterC) + aNonceWordH);
            //
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + RotL64(aWandererF, 5U);
            aCarry = aCarry + RotL64(aIngress, 56U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 26655U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneA[((aIndex + 22284U)) & S_BLOCK1], 26U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 24370U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 22724U)) & S_BLOCK1], 39U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 27220U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 23748U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 24U)) + (RotL64(aIngress, 39U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterE = (((aWandererA + RotL64(aIngress, 21U)) + 9220392006207660113U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordK;
            aOrbiterB = (((aWandererK + RotL64(aPrevious, 11U)) + RotL64(aCarry, 3U)) + 11305018553489132882U) + aNonceWordN;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 52U)) + 5860373868073513684U) + aPhaseAOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aCross, 39U)) + RotL64(aCarry, 27U)) + 12319586170883987589U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 3U)) + RotL64(aCarry, 43U)) + 14072333614354649021U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 9332158529453194608U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterE) ^ 3860569321145958686U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 907977527866467591U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 8119005668901240093U) + aNonceWordM;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 13918259792880333239U;
            aOrbiterF = RotL64((aOrbiterF * 5441062406822088853U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 6938856216758228704U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = (((aOrbiterE ^ aOrbiterD) ^ 3960905839118710604U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 16203746868670689793U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 6043879193734253929U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 15691425268831319195U;
            aOrbiterB = RotL64((aOrbiterB * 7189195135654636271U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 14912209933584715274U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 16180183395910618923U;
            aOrbiterD = RotL64((aOrbiterD * 3942858974766467849U), 21U);
            //
            aIngress = RotL64(aOrbiterE, 37U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterE, 13U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterD, 48U)) + aOrbiterH) + aNonceWordA);
            aWandererH = aWandererH + (((((RotL64(aIngress, 13U) + aOrbiterB) + RotL64(aOrbiterD, 39U)) + RotL64(aCarry, 21U)) + aNonceWordP) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterF, 23U));
            aWandererE = aWandererE + (((((RotL64(aPrevious, 60U) + aOrbiterF) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 57U)) + aNonceWordF) + aPhaseAWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (RotL64(aWandererA, 60U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 51U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28853U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((aIndex + 31900U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29623U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31285U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 32106U)) & S_BLOCK1], 24U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 29731U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 22U) + RotL64(aPrevious, 57U)) ^ (RotL64(aIngress, 5U) + RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 43U)) + 10038936806177516123U) + aNonceWordA;
            aOrbiterI = ((aWandererA + RotL64(aCross, 35U)) + 1773168435195292638U) + aNonceWordD;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 22U)) + RotL64(aCarry, 11U)) + 10655711161526628072U;
            aOrbiterC = (((aWandererF + RotL64(aIngress, 11U)) + RotL64(aCarry, 23U)) + 14422295664639740437U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = (((aWandererB + RotL64(aCross, 53U)) + RotL64(aCarry, 37U)) + 4125228715513159576U) + aPhaseAOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 3670449653158650845U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 17553727567180813057U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11814335762020146785U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 5111401772713882743U) + aNonceWordN;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 7688573124662314413U) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 10846442063022821393U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 9438375825507814395U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 14177477039902118886U) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 6467406626985022537U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 16329942595859623928U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 3990536794006836672U;
            aOrbiterC = RotL64((aOrbiterC * 579024714339065373U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 5072881436583180756U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 16789727877867289997U) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 8766246302636197905U), 13U);
            //
            aIngress = RotL64(aOrbiterC, 5U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((((RotL64(aCross, 29U) + RotL64(aOrbiterD, 28U)) + aOrbiterF) + aNonceWordL) + aPhaseAWandererUpdateSaltB[((aIndex + 8U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterC, 47U)) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 48U) + RotL64(aOrbiterD, 39U)) + aOrbiterA) + aNonceWordK);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 39U) + aOrbiterI) + RotL64(aOrbiterF, 5U)) + RotL64(aCarry, 47U)) + aNonceWordO);
            aWandererA = aWandererA ^ ((((RotL64(aCross, 5U) + RotL64(aOrbiterA, 19U)) + aOrbiterF) + aNonceWordF) + aPhaseAWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 40U));
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererA, 51U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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

void TwistExpander_Cricket_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xEE6E229F20CE948BULL + 0xA1CBC97470211EF5ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xA236946CA80827D5ULL + 0x9F6A951E048CF4C1ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xD56EFAAF52102FAFULL + 0xD46D65C4CA674987ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xEC3749FA7AEB3C33ULL + 0xD98642D8FA19AB93ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xB7D1E64E61E8AC2DULL + 0xADA4FC8CCDA9014FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xD1DC6C5EE4D67DD9ULL + 0x87853DD9339B2114ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xA1381A314354ED9DULL + 0xF3E610C6969F9728ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xA9E50C90DDBB2B2BULL + 0x88EF4AE26E590559ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x984D1B22D5E705B3ULL + 0xC087D743C7954817ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xCAB0B8F9D5D5050BULL + 0x8A7BA3AB654528C1ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xF146F27856F2F43DULL + 0x9DB5D017646DE47EULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x9B764915A1F6B0C3ULL + 0xD43DD4AA54895713ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xC610465D9B601B8BULL + 0xC2ED890450BA48C0ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xD4800D285B7CD4EBULL + 0x806D4C4CCCEE3F3DULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x8DCDD5AA7F11436DULL + 0xBB3659545A1C651CULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x85176DE6068100E3ULL + 0xE0589C12C9A4231EULL);
    // GSeedRunSeed_C seed_loop_b (start)
    {
        // GSeedRunSeed_C seed_loop_b lane group
        // read from: aOperationLaneA, aOperationLaneB, aExpandLaneD, aOperationLaneC, aOperationLaneD, aFireLaneD, aInvestLaneC, aFireLaneA, aExpandLaneA, aInvestLaneD, aFireLaneB, aWorkLaneA, aExpandLaneB, aWorkLaneB, aFireLaneC, aWorkLaneC, aExpandLaneC
        // write to: aInvestLaneC, aInvestLaneD, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // seed_loop_b loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aExpandLaneD
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aExpandLaneD forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aFireLaneD
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aFireLaneD backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 3098U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((aIndex + 1590U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 803U)) & S_BLOCK1], 34U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4228U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 1513U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 2765U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aIngress, 19U)) + (RotL64(aCross, 3U) ^ RotL64(aPrevious, 52U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterF = (aWandererG + RotL64(aIngress, 37U)) + 16160838483846078448U;
            aOrbiterH = ((aWandererC + RotL64(aCross, 41U)) + 15404960896190227946U) + aNonceWordA;
            aOrbiterJ = (aWandererE + RotL64(aScatter, 47U)) + 16904160594024977199U;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 57U)) + 17790460246821031802U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aCross, 52U)) + RotL64(aCarry, 23U)) + 16395168254086971959U;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 23U)) + RotL64(aCarry, 39U)) + 7484373204039901786U;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 19U)) + RotL64(aCarry, 51U)) + 18026814691322913510U;
            aOrbiterE = (aWandererI + RotL64(aIngress, 3U)) + 15244817793136966450U;
            aOrbiterG = (((aWandererA + RotL64(aPrevious, 12U)) + 5795491730356335666U) + aPhaseBOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1]) + aNonceWordO;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 3163873518027801504U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 2690791759507349172U;
            aOrbiterJ = RotL64((aOrbiterJ * 16677948635136515083U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 17898067251167087906U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 8028010015006604239U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5601629670521300241U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 7304739457289910555U) + aNonceWordL;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 6476837815096530043U;
            aOrbiterF = RotL64((aOrbiterF * 16380545138701113267U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 14242499233467960602U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 17305645693017634630U) ^ aNonceWordF;
            aOrbiterA = RotL64((aOrbiterA * 14442976693206929569U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 9772864059444171908U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 7897200728282156408U;
            aOrbiterC = RotL64((aOrbiterC * 816306719390807411U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 4890999319172950996U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 8165132649356094963U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17297706071263690189U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 9342923520083533265U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 7213639583505088067U;
            aOrbiterD = RotL64((aOrbiterD * 1349251979649428909U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 4079475132684197272U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 3350998022472827283U;
            aOrbiterI = RotL64((aOrbiterI * 948841791460066265U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 2479140576609216238U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 7703147534931674972U;
            aOrbiterG = RotL64((aOrbiterG * 11419116495223970801U), 47U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 4U);
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterC, 23U)) + aOrbiterD);
            aWandererF = aWandererF + ((((RotL64(aIngress, 6U) + aOrbiterC) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 5U)) + aNonceWordM);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterG, 11U)) + aOrbiterF);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 47U) + aOrbiterH) + RotL64(aOrbiterE, 51U)) + aNonceWordN) + aPhaseBWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 44U)) + aOrbiterA);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterI, 3U)) + aOrbiterE) + RotL64(aCarry, 35U)) + aNonceWordC);
            aWandererI = aWandererI ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterD, 35U)) + aOrbiterE);
            aWandererA = aWandererA + ((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 19U)) + aOrbiterG);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 60U) + RotL64(aOrbiterE, 40U)) + aOrbiterJ) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 54U));
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 2
        // ingress from: aInvestLaneC, aOperationLaneC, aOperationLaneD, aFireLaneA
        // ingress directions: aInvestLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aFireLaneA forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aExpandLaneA
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aExpandLaneA backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 6923U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((aIndex + 6383U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 5727U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 8432U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 9043U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8139U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aExpandLaneA[((aIndex + 9570U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 51U)) + (RotL64(aIngress, 24U) ^ RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterC = ((aWandererG + RotL64(aScatter, 43U)) + 5041131702736607991U) + aNonceWordA;
            aOrbiterI = (((aWandererC + RotL64(aIngress, 58U)) + RotL64(aCarry, 43U)) + 9295010428212681446U) + aNonceWordF;
            aOrbiterJ = (aWandererB + RotL64(aCross, 23U)) + 6235875895358766017U;
            aOrbiterD = (aWandererF + RotL64(aPrevious, 11U)) + 2622227802531866918U;
            aOrbiterK = (aWandererK + RotL64(aIngress, 27U)) + 3888894734834524972U;
            aOrbiterF = ((aWandererA + RotL64(aCross, 39U)) + RotL64(aCarry, 27U)) + 241682012014701753U;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 47U)) + 15758000422451568079U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aScatter, 6U)) + 2061944548396976912U) + aNonceWordK;
            aOrbiterB = (((aWandererH + RotL64(aPrevious, 53U)) + RotL64(aCarry, 57U)) + 8177144990755754531U) + aPhaseBOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 554978075608818497U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 250408260560714933U;
            aOrbiterJ = RotL64((aOrbiterJ * 1295379390497107727U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 8700027645880997552U) + aNonceWordP;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 10026130047465480902U;
            aOrbiterK = RotL64((aOrbiterK * 12417270861933696623U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 9785843014096326696U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 9998582683258411251U;
            aOrbiterI = RotL64((aOrbiterI * 7197956237569462269U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 13817734599383455151U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 6647207154174092691U;
            aOrbiterC = RotL64((aOrbiterC * 1578528131687283531U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 4957715980509035719U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 4994885315786213197U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5676683798126497011U), 35U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterG) + 5072908311783966503U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 5535039946192891515U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2989412783482309753U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 6594577050344146271U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 8750154123258714856U;
            aOrbiterF = RotL64((aOrbiterF * 6942158167127532003U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 3514769314840874873U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 8626045200273524281U;
            aOrbiterB = RotL64((aOrbiterB * 4315441782689789689U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 8524870284841706517U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 1841819423572964209U;
            aOrbiterG = RotL64((aOrbiterG * 9802481758007234681U), 23U);
            //
            aIngress = RotL64(aOrbiterK, 23U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 50U));
            aIngress = aIngress + RotL64(aOrbiterB, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aIngress, 35U) + aOrbiterB) + RotL64(aOrbiterA, 39U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 40U) + RotL64(aOrbiterI, 35U)) + aOrbiterB) + aNonceWordI);
            aWandererJ = aWandererJ + (((RotL64(aCross, 47U) + aOrbiterG) + RotL64(aOrbiterC, 51U)) + aPhaseBWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 29U)) + aOrbiterJ);
            aWandererH = aWandererH + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 24U)) + aOrbiterB) + RotL64(aCarry, 29U)) + aNonceWordO);
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 22U) + aOrbiterF) + RotL64(aOrbiterD, 47U)) + aNonceWordC) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 11U) + RotL64(aOrbiterF, 3U)) + aOrbiterI) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 5U) + aOrbiterF) + RotL64(aOrbiterG, 19U));
            aWandererA = aWandererA + (((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterG, 12U)) + aNonceWordH);
            //
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererE, 23U);
            aCarry = aCarry + RotL64(aIngress, 26U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aInvestLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 3
        // ingress from: aInvestLaneD, aOperationLaneA, aFireLaneB
        // ingress directions: aInvestLaneD forward forced, aOperationLaneA forward forced, aFireLaneB forward/backward random
        // cross from: aInvestLaneC, aOperationLaneC
        // cross directions: aInvestLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneD[((aIndex + 13255U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((aIndex + 16347U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 13392U)) & S_BLOCK1], 46U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 11065U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 14389U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 58U) + RotL64(aCross, 29U)) + (RotL64(aIngress, 11U) ^ RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterA = (((aWandererE + RotL64(aIngress, 24U)) + RotL64(aCarry, 51U)) + 4622023259121087483U) + aNonceWordI;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 47U)) + 10253505250223501352U;
            aOrbiterK = (((aWandererA + RotL64(aScatter, 19U)) + RotL64(aCarry, 5U)) + 17133877904420462669U) + aNonceWordA;
            aOrbiterI = (((aWandererD + RotL64(aCross, 39U)) + RotL64(aCarry, 23U)) + 6162827793741796700U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aScatter, 53U)) + 9610986424765907615U;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 43U)) + 11210747154264753754U;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 34U)) + 16554205219580654546U) + aPhaseBOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aCross, 11U)) + 10352576357413766388U;
            aOrbiterF = (aWandererI + RotL64(aIngress, 5U)) + 3651845783283479752U;
            //
            aOrbiterA = (((aOrbiterA + aOrbiterG) + 18145542190463500476U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 5415609566767162857U;
            aOrbiterK = RotL64((aOrbiterK * 6474184559323816389U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 2033734872464201570U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 3507213117125813345U) ^ aNonceWordB;
            aOrbiterH = RotL64((aOrbiterH * 5453058336688881113U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 8716253393049851856U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 695984869565941856U;
            aOrbiterA = RotL64((aOrbiterA * 8377921610764044735U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 7661578828878284931U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 906654265099155956U;
            aOrbiterD = RotL64((aOrbiterD * 8117625377607536949U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 6050049984731254612U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 17882717590338190821U;
            aOrbiterG = RotL64((aOrbiterG * 10807367411402733215U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 4996521991532815957U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 4246460672800604436U;
            aOrbiterJ = RotL64((aOrbiterJ * 12047466401960824903U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 8700148116452518842U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 10039050281847466206U;
            aOrbiterF = RotL64((aOrbiterF * 11884791271239660157U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 4513844680425845372U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 3037563127442815153U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 18363509277992292407U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 1005237931570968724U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 1373258132025712065U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10458020799382532395U), 19U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterI, 43U);
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 22U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + RotL64(aOrbiterG, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aPrevious, 46U) + RotL64(aOrbiterK, 29U)) + aOrbiterA) + RotL64(aCarry, 53U)) + aNonceWordK);
            aWandererF = aWandererF ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterK, 43U)) + aOrbiterJ) + aNonceWordM);
            aWandererH = aWandererH + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 47U)) + aOrbiterG) + RotL64(aCarry, 3U)) + aPhaseBWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 23U) + aOrbiterF) + RotL64(aOrbiterI, 56U));
            aWandererB = aWandererB + (((RotL64(aCross, 51U) + RotL64(aOrbiterG, 5U)) + aOrbiterH) + aNonceWordP);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterF, 19U)) + aOrbiterD);
            aWandererD = aWandererD + ((RotL64(aPrevious, 14U) + aOrbiterD) + RotL64(aOrbiterI, 11U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 34U)) + aOrbiterD) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 41U) + RotL64(aOrbiterK, 39U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + (RotL64(aWandererC, 58U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 29U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 4
        // ingress from: aWorkLaneA, aInvestLaneC, aExpandLaneB
        // ingress directions: aWorkLaneA forward forced, aInvestLaneC forward forced, aExpandLaneB forward/backward random
        // cross from: aInvestLaneD, aOperationLaneD
        // cross directions: aInvestLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 17199U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneC[((aIndex + 21643U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 19189U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 17315U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20799U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 18U) ^ RotL64(aCarry, 37U)) + (RotL64(aIngress, 53U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterK = (aWandererE + RotL64(aCross, 34U)) + 14823268998003220191U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 27U)) + 15295237288788213847U) + aNonceWordN;
            aOrbiterE = (aWandererA + RotL64(aScatter, 3U)) + 16434853402001133899U;
            aOrbiterH = (aWandererD + RotL64(aIngress, 47U)) + 7555911304407871631U;
            aOrbiterB = (((aWandererI + RotL64(aScatter, 21U)) + RotL64(aCarry, 21U)) + 14977248264994834620U) + aPhaseBOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 51U)) + RotL64(aCarry, 57U)) + 9707764144919392380U;
            aOrbiterC = ((aWandererC + RotL64(aIngress, 41U)) + 1277304385464681529U) + aNonceWordI;
            aOrbiterJ = (((aWandererF + RotL64(aCross, 56U)) + RotL64(aCarry, 29U)) + 3089786220465849395U) + aNonceWordO;
            aOrbiterG = (((aWandererJ + RotL64(aScatter, 13U)) + 3700503853358695085U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordM;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 3240054112993517371U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 16897532076915366859U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4120874717534309035U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 18167359289798364307U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 8870819278575769863U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9334066154398059075U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 15363069206212330251U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 14858164441499725158U;
            aOrbiterI = RotL64((aOrbiterI * 14931933411393847915U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 5357144808788707522U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 2910681277417754860U;
            aOrbiterC = RotL64((aOrbiterC * 13170868582159347059U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 9824408699018165151U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 368370224788793300U;
            aOrbiterD = RotL64((aOrbiterD * 14358982366258729959U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 7095398304588825115U) + aNonceWordC;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 11418879758164313554U) ^ aNonceWordF;
            aOrbiterG = RotL64((aOrbiterG * 5983520332639771791U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 2171599720681913272U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 17593730219647495033U;
            aOrbiterK = RotL64((aOrbiterK * 12926053208918563087U), 47U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterG) + 17755947635188715523U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordH;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 14565740605227022106U;
            aOrbiterH = RotL64((aOrbiterH * 15866418354612945335U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 14538017880915584414U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 6174566474851449123U) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 179569008593475683U), 39U);
            //
            aIngress = RotL64(aOrbiterE, 35U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterB, 12U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 23U) + aOrbiterB) + RotL64(aOrbiterI, 57U));
            aWandererI = aWandererI + ((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 37U)) + aOrbiterK);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 18U) + aOrbiterJ) + RotL64(aOrbiterC, 27U));
            aWandererG = aWandererG + (((RotL64(aCross, 13U) + RotL64(aOrbiterH, 6U)) + aOrbiterC) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterI, 43U)) + aOrbiterG) + aNonceWordJ);
            aWandererF = aWandererF + (((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterJ, 47U)) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ ((((RotL64(aCross, 27U) + RotL64(aOrbiterG, 23U)) + aOrbiterH) + aNonceWordD) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 57U) + aOrbiterE) + RotL64(aOrbiterG, 11U)) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 4U) + aOrbiterK) + RotL64(aOrbiterD, 18U)) + aNonceWordB);
            //
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 14U));
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 5
        // ingress from: aWorkLaneB, aInvestLaneD, aFireLaneC
        // ingress directions: aWorkLaneB forward forced, aInvestLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aWorkLaneA, aInvestLaneC
        // cross directions: aWorkLaneA backward forced, aInvestLaneC backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 24629U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneD[((aIndex + 25943U)) & S_BLOCK1], 48U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 22379U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27296U)) & S_BLOCK1], 43U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 26413U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 47U) ^ RotL64(aPrevious, 35U)) + (RotL64(aCross, 20U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterB = (((aWandererB + RotL64(aCross, 43U)) + 2101601659597850213U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordG;
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 23U)) + 2759794072560720121U) + aNonceWordD;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 10U)) + 9443562552411269339U) + aNonceWordP;
            aOrbiterG = (aWandererC + RotL64(aIngress, 35U)) + 10801360546699857975U;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 51U)) + RotL64(aCarry, 51U)) + 8020716394829332019U;
            aOrbiterH = (aWandererA + RotL64(aIngress, 3U)) + 1021894212367773801U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 19U)) + RotL64(aCarry, 21U)) + 13346855534622490176U;
            aOrbiterF = ((((aWandererH + RotL64(aScatter, 30U)) + RotL64(aCarry, 43U)) + 16359309548462953836U) + aPhaseBOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterA = (aWandererD + RotL64(aCross, 47U)) + 12642446944680783519U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 8197424982767553380U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 14346334610901859094U;
            aOrbiterE = RotL64((aOrbiterE * 16982899923227935679U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 14171304260534233539U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 334531601308283605U;
            aOrbiterK = RotL64((aOrbiterK * 5012968232749075075U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 10707856298471572695U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 18364775750091914766U) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 15735143943129143265U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 8531394793118363836U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 15352876929406908882U;
            aOrbiterD = RotL64((aOrbiterD * 475199047053777179U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 567682016232278157U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 2068146551757663119U;
            aOrbiterC = RotL64((aOrbiterC * 1557877740957797555U), 13U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterG) + 7776122587613256525U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordC;
            aOrbiterA = (((aOrbiterA ^ aOrbiterC) ^ 16430938890724272256U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 4540270493783593257U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 11912000645055436094U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 16800749242578741498U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17804584625034241737U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 5909199180260499150U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 5751089915336865588U;
            aOrbiterF = RotL64((aOrbiterF * 15376689503142397927U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 3478216857728853008U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 18007567146937338241U;
            aOrbiterG = RotL64((aOrbiterG * 6620498877303917855U), 19U);
            //
            aIngress = RotL64(aOrbiterB, 23U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 50U));
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + RotL64(aOrbiterK, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aPrevious, 18U) + aOrbiterB) + RotL64(aOrbiterF, 51U)) + RotL64(aCarry, 53U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 51U) + aOrbiterB) + RotL64(aOrbiterA, 47U)) + aPhaseBWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterK, 43U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterA, 4U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 44U) + aOrbiterH) + RotL64(aOrbiterG, 57U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterK, 27U)) + aOrbiterF) + aNonceWordH);
            aWandererH = aWandererH + ((((RotL64(aCross, 37U) + aOrbiterD) + RotL64(aOrbiterC, 37U)) + RotL64(aCarry, 37U)) + aNonceWordB);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterA, 20U)) + aOrbiterE);
            aWandererD = aWandererD + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 13U)) + aOrbiterK) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererB, 34U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererE, 23U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 6
        // ingress from: aWorkLaneC, aWorkLaneA, aExpandLaneC
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aExpandLaneC forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 28921U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 29840U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 28733U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31196U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30537U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aPrevious, 41U)) + (RotL64(aIngress, 56U) ^ RotL64(aCarry, 13U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterK = ((((aWandererD + RotL64(aPrevious, 23U)) + RotL64(aCarry, 27U)) + 8604208734152026945U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordA;
            aOrbiterA = (aWandererC + RotL64(aIngress, 39U)) + 1374329953253889829U;
            aOrbiterJ = (((aWandererK + RotL64(aCross, 34U)) + RotL64(aCarry, 51U)) + 5779278910548228339U) + aNonceWordI;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 47U)) + RotL64(aCarry, 19U)) + 17670451230882805140U;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 43U)) + 8193848740764866860U) + aNonceWordF;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 11U)) + 15801168428145650104U) + aNonceWordG;
            aOrbiterI = (aWandererJ + RotL64(aScatter, 27U)) + 2584718176087499066U;
            aOrbiterG = ((aWandererG + RotL64(aCross, 53U)) + 14950366247822737997U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aIngress, 18U)) + 9779293225265670135U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 8688968319288372383U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 13665723186950342601U;
            aOrbiterJ = RotL64((aOrbiterJ * 292035540396910837U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 9395428688359973510U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 2152719218018108418U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15271961483518392671U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 1350324137411377992U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 8729317951386057921U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6008790836417785083U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 6317310451893678411U) + aNonceWordC;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 10175620379041384281U) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 14079679617394330781U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 1203082119358827708U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 523869107818193101U;
            aOrbiterI = RotL64((aOrbiterI * 4629501113595689157U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 4028324959540432983U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 15447631947468213912U;
            aOrbiterK = RotL64((aOrbiterK * 6037306615787729185U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 14225888694733041031U) + aNonceWordH;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 11925000696281947629U;
            aOrbiterG = RotL64((aOrbiterG * 4337022940520411253U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 15015531024930608745U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 16752579225076943550U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15551083683579981439U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 2432733494869267901U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 10103430321388601485U;
            aOrbiterB = RotL64((aOrbiterB * 18372919379972432569U), 27U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterB, 19U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + (RotL64(aOrbiterA, 34U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterE, 37U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 58U) + aOrbiterK) + RotL64(aOrbiterD, 34U)) + aPhaseBWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aIngress, 43U) + aOrbiterA) + RotL64(aOrbiterK, 43U)) + RotL64(aCarry, 21U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 57U)) + aOrbiterE);
            aWandererA = aWandererA + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 11U)) + aOrbiterG) + aNonceWordO);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 47U) + aOrbiterI) + RotL64(aOrbiterE, 51U)) + aNonceWordJ);
            aWandererI = aWandererI + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterI, 5U)) + aOrbiterF) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 18U) + aOrbiterF) + RotL64(aOrbiterJ, 39U));
            aWandererD = aWandererD + (((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 27U)) + aOrbiterD) + aNonceWordL);
            aWandererG = aWandererG ^ (((RotL64(aCross, 27U) + aOrbiterB) + RotL64(aOrbiterA, 18U)) + aNonceWordN);
            //
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 39U);
            aCarry = aCarry + RotL64(aIngress, 48U);
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

void TwistExpander_Cricket_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC1A0C9959E11EFC1ULL + 0xC897E88ECEDCA16AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xD5AF303F0580CF83ULL + 0xD47CB8231B46BDB3ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x9406BFCE6879EDFDULL + 0xE04B0E86B95C125EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xD899545E3B89E3E5ULL + 0xEEB1830B4B89DA71ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA1BAC022A0DE5B91ULL + 0x8C1EF0C43D69E607ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xDD0223BE2CDA148DULL + 0xE5B69B870EF3C4E0ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xFFBDB1ECC666884FULL + 0x9E497C24F722F5FAULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x9D42F524C23C23D3ULL + 0xBFBB563846C55B5BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xA85D56649136AE73ULL + 0xAB322B03BEE5B8F1ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xDB7F68A8C2D19D79ULL + 0x851072E1E3C83F9EULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x9A7F4CDD11CBD545ULL + 0x966E1551742DB0A5ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xB9BFC18CBDD6F4B1ULL + 0xE88BE1F17B1BBE13ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xB6BF84EB22292181ULL + 0x87F5C4F2A7C94C44ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xEA46A857087558B5ULL + 0x875CF8B2EF966862ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xB7BAE9E7E1462671ULL + 0xB8AE0DF3835E766DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xC4F493F647C6AA8FULL + 0xCAB2EB9B33D19EC8ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 4855U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((aIndex + 1540U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 4876U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1802U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3215U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 691U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aIngress, 57U)) ^ (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 26U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterD = ((aWandererD + RotL64(aCross, 10U)) + 7948891781097675369U) + aPhaseDOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 53U)) + 13928362874228230226U) + aNonceWordL;
            aOrbiterI = (aWandererH + RotL64(aScatter, 35U)) + 10776180542602258926U;
            aOrbiterA = ((((aWandererG + RotL64(aIngress, 21U)) + RotL64(aCarry, 35U)) + 5735115172149470447U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordP;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 27U)) + RotL64(aCarry, 5U)) + 5353591822981766987U;
            aOrbiterK = ((aWandererB + RotL64(aCross, 3U)) + RotL64(aCarry, 57U)) + 562301708107268570U;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 43U)) + 10467810247578364868U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 14541630141152308564U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 2350076897065139429U;
            aOrbiterI = RotL64((aOrbiterI * 12222554362482034393U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 17519109078651162228U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 6061035173339902910U) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 10021905773432907835U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 15654836633731000065U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 13723521735153718904U) ^ aNonceWordK;
            aOrbiterD = RotL64((aOrbiterD * 14459516479283070563U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 2849680038315532197U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 17336102435576647923U;
            aOrbiterA = RotL64((aOrbiterA * 10984689101753586739U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 7671010488872356142U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 11485114338165600777U;
            aOrbiterF = RotL64((aOrbiterF * 4162584865462407791U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 8759060657343458985U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 11009137869375286581U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8741417343929809115U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 15792999392743144135U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 6180808423175992479U;
            aOrbiterH = RotL64((aOrbiterH * 13681230339693676907U), 43U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 3U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 42U));
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 54U)) + aOrbiterA) + aNonceWordE);
            aWandererF = aWandererF + ((((RotL64(aScatter, 24U) + RotL64(aOrbiterG, 13U)) + aOrbiterK) + RotL64(aCarry, 27U)) + aPhaseDWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 3U)) + aOrbiterA) + aNonceWordJ);
            aWandererB = aWandererB + ((((RotL64(aCross, 47U) + RotL64(aOrbiterK, 35U)) + aOrbiterD) + RotL64(aCarry, 5U)) + aNonceWordF);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterD, 43U)) + aOrbiterI);
            aWandererC = aWandererC + (((RotL64(aScatter, 5U) + aOrbiterH) + RotL64(aOrbiterG, 29U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterH, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 26U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 43U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 9526U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((aIndex + 5585U)) & S_BLOCK1], 51U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 10492U)) & S_BLOCK1], 39U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 5775U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8656U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6323U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 7309U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 50U) + RotL64(aCarry, 11U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterD = (aWandererA + RotL64(aIngress, 5U)) + 13854738573712660276U;
            aOrbiterB = ((aWandererI + RotL64(aCross, 20U)) + 16835460633412286294U) + aNonceWordC;
            aOrbiterE = (((aWandererJ + RotL64(aPrevious, 47U)) + RotL64(aCarry, 3U)) + 6785859293758091931U) + aPhaseDOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (((aWandererE + RotL64(aScatter, 35U)) + RotL64(aCarry, 23U)) + 126317283127992659U) + aNonceWordE;
            aOrbiterA = ((((aWandererC + RotL64(aIngress, 13U)) + RotL64(aCarry, 53U)) + 7568963536291415413U) + aPhaseDOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1]) + aNonceWordF;
            aOrbiterG = (aWandererB + RotL64(aPrevious, 27U)) + 12294016745653004819U;
            aOrbiterF = (aWandererF + RotL64(aScatter, 57U)) + 18269588932920281147U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 5872406424994751026U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 7764434758831474129U;
            aOrbiterE = RotL64((aOrbiterE * 3772146788188420071U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 4804168969415573371U) + aNonceWordG;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 959601763507651280U;
            aOrbiterA = RotL64((aOrbiterA * 4647396592804833217U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 9257644462479293048U) + aNonceWordA;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 14332699366894494579U;
            aOrbiterG = RotL64((aOrbiterG * 8829304078930625541U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 10487012596470786004U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 612729229562321440U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11380387280507726003U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 7845523921295625315U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 12742115479740024747U;
            aOrbiterB = RotL64((aOrbiterB * 15578543510683986421U), 35U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterE) + 10294667720904610944U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordP;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 14369711143154904567U;
            aOrbiterF = RotL64((aOrbiterF * 13753005602288309379U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 10918344717497681894U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 18136794828308636957U;
            aOrbiterK = RotL64((aOrbiterK * 17899418637978002409U), 11U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 3U);
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 14U));
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterK, 47U)) + aOrbiterD);
            aWandererF = aWandererF + (((((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 11U)) + aOrbiterK) + RotL64(aCarry, 53U)) + aNonceWordO) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 23U) + aOrbiterA) + RotL64(aOrbiterE, 27U)) + aNonceWordB);
            aWandererC = aWandererC + ((RotL64(aIngress, 6U) + aOrbiterA) + RotL64(aOrbiterD, 60U));
            aWandererI = aWandererI ^ ((((RotL64(aCross, 29U) + RotL64(aOrbiterG, 3U)) + aOrbiterD) + aNonceWordN) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 39U) + RotL64(aOrbiterA, 19U)) + aOrbiterB) + RotL64(aCarry, 41U)) + aNonceWordK);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 37U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 58U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + RotL64(aWandererF, 53U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 15505U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((aIndex + 16372U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 15271U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 11786U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneC[((aIndex + 12289U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 13U) ^ RotL64(aCarry, 39U)) ^ (RotL64(aIngress, 26U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 13U)) + RotL64(aCarry, 53U)) + 2571116506511057880U;
            aOrbiterD = (((aWandererB + RotL64(aScatter, 43U)) + RotL64(aCarry, 27U)) + 13112435411509707292U) + aNonceWordJ;
            aOrbiterA = (((aWandererA + RotL64(aIngress, 37U)) + 10403251762787357256U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordC;
            aOrbiterG = ((aWandererI + RotL64(aCross, 51U)) + RotL64(aCarry, 41U)) + 8461951095541400405U;
            aOrbiterK = ((aWandererC + RotL64(aIngress, 5U)) + 9890793478557463815U) + aNonceWordN;
            aOrbiterI = (((aWandererG + RotL64(aCross, 30U)) + 3030229465991783707U) + aPhaseDOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1]) + aNonceWordO;
            aOrbiterE = (aWandererD + RotL64(aPrevious, 19U)) + 7273848154043719247U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 10681774862516028276U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 7105082755586853104U;
            aOrbiterA = RotL64((aOrbiterA * 12217705329504230357U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 6588579345319551129U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 14616333550242386092U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2934574715879306337U), 27U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterK) + 15439666290229654921U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1]) + aNonceWordG;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 3360304356760164799U) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 5164191920584106237U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 14438730801970761889U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 14515616787452085729U;
            aOrbiterH = RotL64((aOrbiterH * 2041601927968559821U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 4167853822635132419U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 8950982233003320239U;
            aOrbiterG = RotL64((aOrbiterG * 887144270884244907U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 12391327853728029953U) + aNonceWordH;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 7100871010552394421U;
            aOrbiterK = RotL64((aOrbiterK * 16552349374101955967U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 15381697462381887944U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 6801677551341079401U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13325954438427340703U), 13U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterH, 11U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 56U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + RotL64(aOrbiterA, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterH, 22U)) + aOrbiterE) + aNonceWordL);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 41U) + aOrbiterG) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 43U)) + aNonceWordB);
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 3U)) + aOrbiterG) + aNonceWordM) + aPhaseDWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterK, 57U)) + aOrbiterE) + RotL64(aCarry, 23U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 41U)) + aOrbiterH) + aNonceWordD);
            aWandererH = aWandererH + ((RotL64(aIngress, 5U) + aOrbiterK) + RotL64(aOrbiterI, 29U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 26U) + RotL64(aOrbiterD, 47U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererA, 52U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 17433U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneA[((aIndex + 17111U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 18466U)) & S_BLOCK1], 28U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 17124U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20561U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aPrevious, 54U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 37U) ^ RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterB = (aWandererA + RotL64(aIngress, 43U)) + 12311607308490066301U;
            aOrbiterA = ((((aWandererG + RotL64(aScatter, 21U)) + RotL64(aCarry, 51U)) + 13100864684740679846U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordF;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 60U)) + RotL64(aCarry, 5U)) + 13697304189274329704U;
            aOrbiterJ = (((aWandererC + RotL64(aCross, 35U)) + 9047976902871216732U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordG;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 53U)) + 2147897579538537888U;
            aOrbiterF = ((aWandererD + RotL64(aCross, 11U)) + RotL64(aCarry, 19U)) + 2072444829390996142U;
            aOrbiterC = (aWandererB + RotL64(aIngress, 27U)) + 2129307836981020908U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 10663145333751112064U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 15019844390503785459U;
            aOrbiterD = RotL64((aOrbiterD * 7442321463110790449U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 5460865577557928142U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterJ) ^ 15806522559993224197U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 8722932687972240099U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 6361113778657833389U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 8306013884615042570U;
            aOrbiterB = RotL64((aOrbiterB * 8234258702656728667U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 4038420580499706912U) + aNonceWordJ;
            aOrbiterC = (((aOrbiterC ^ aOrbiterD) ^ 11908091484457158973U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterC = RotL64((aOrbiterC * 3964111175645156719U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 11133912466611921250U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 2469227904206936928U;
            aOrbiterJ = RotL64((aOrbiterJ * 2704438771198001599U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 13234017916788297295U) + aNonceWordB;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 9061117693840451988U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3637440416741459419U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 12013423690843812324U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 14371779015144617412U;
            aOrbiterG = RotL64((aOrbiterG * 3359568073302062667U), 29U);
            //
            aIngress = RotL64(aOrbiterC, 27U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 42U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((((RotL64(aCross, 27U) + aOrbiterB) + RotL64(aOrbiterG, 11U)) + aNonceWordA) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 11U) + aOrbiterG) + RotL64(aOrbiterC, 47U)) + aNonceWordC);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 58U) + RotL64(aOrbiterF, 27U)) + aOrbiterG) + aNonceWordN);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 41U) + aOrbiterB) + RotL64(aOrbiterJ, 36U)) + RotL64(aCarry, 43U)) + aNonceWordO);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterB, 21U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 35U) + aOrbiterA) + RotL64(aOrbiterF, 5U)) + RotL64(aCarry, 5U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterG, 57U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + RotL64(aWandererD, 6U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 24278U)) & S_BLOCK1], 30U) ^ RotL64(aSnowLaneB[((aIndex + 24836U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 25410U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 24294U)) & S_BLOCK1], 46U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 26172U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 48U)) + (RotL64(aIngress, 19U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterG = ((aWandererD + RotL64(aIngress, 11U)) + RotL64(aCarry, 5U)) + 6069475454765660321U;
            aOrbiterI = (((aWandererE + RotL64(aPrevious, 43U)) + RotL64(aCarry, 27U)) + 11483704742497268068U) + aNonceWordE;
            aOrbiterE = (((aWandererH + RotL64(aCross, 58U)) + 11055697447388986418U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordA;
            aOrbiterC = (((aWandererF + RotL64(aScatter, 29U)) + RotL64(aCarry, 41U)) + 10897095046039997004U) + aNonceWordP;
            aOrbiterA = (aWandererG + RotL64(aCross, 51U)) + 4731637118230457840U;
            aOrbiterD = ((aWandererI + RotL64(aScatter, 3U)) + 13855839187084986751U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 35U)) + 5328208115460188239U) + aNonceWordC;
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 12479538544291412985U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterG) ^ 10740165998792608231U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterE = RotL64((aOrbiterE * 14046827922294477379U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 6492798157284955373U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 13056825957483891921U) ^ aNonceWordF;
            aOrbiterG = RotL64((aOrbiterG * 14882112110627751751U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 2068184064919194657U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterD) ^ 5656302738780746294U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 16493021179127646345U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 11193756120230763294U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 17306750816837208999U;
            aOrbiterD = RotL64((aOrbiterD * 7949360041241439741U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 12952818800389361804U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 15380412293642628312U;
            aOrbiterI = RotL64((aOrbiterI * 2914662289178925547U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 7706090204767242996U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 14598802276412649570U) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 4821408736292041399U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 17819762117328075515U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 6481384240915075101U;
            aOrbiterC = RotL64((aOrbiterC * 4836701121865783029U), 11U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 4U);
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterH, 23U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterC, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aIngress, 41U) + aOrbiterE) + RotL64(aOrbiterG, 19U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 3U)) + aOrbiterA) + aNonceWordK);
            aWandererG = aWandererG + ((((RotL64(aCross, 57U) + RotL64(aOrbiterA, 11U)) + aOrbiterI) + RotL64(aCarry, 51U)) + aNonceWordB);
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 12U) + RotL64(aOrbiterG, 51U)) + aOrbiterC) + aNonceWordG) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterA, 35U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 43U)) + aOrbiterH);
            aWandererH = aWandererH + (((((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 58U)) + aOrbiterI) + RotL64(aCarry, 13U)) + aNonceWordH) + aPhaseDWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 42U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 28443U)) & S_BLOCK1], 52U) ^ RotL64(aInvestLaneA[((aIndex + 29745U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 29374U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 28525U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29802U)) & S_BLOCK1], 46U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 35U)) + (RotL64(aCross, 52U) ^ RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterG = (((aWandererH + RotL64(aScatter, 35U)) + RotL64(aCarry, 13U)) + 14249093584376402677U) + aNonceWordK;
            aOrbiterD = ((aWandererI + RotL64(aCross, 50U)) + 8756965951816492264U) + aNonceWordF;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 3U)) + 11221139480258176330U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (((aWandererB + RotL64(aIngress, 43U)) + RotL64(aCarry, 35U)) + 17218894445564194851U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 57U)) + 8064642692524949490U) + aNonceWordL;
            aOrbiterE = ((aWandererE + RotL64(aCross, 23U)) + RotL64(aCarry, 53U)) + 5822093203710704646U;
            aOrbiterK = (aWandererG + RotL64(aIngress, 29U)) + 3217799620158102238U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 2613757677892120843U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 13647481499551657237U;
            aOrbiterF = RotL64((aOrbiterF * 5517563514031899891U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 3545714196663685016U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 9735422670576621521U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7276207208162697249U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 3911046580637583767U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 9315984027042049203U;
            aOrbiterD = RotL64((aOrbiterD * 12568550776487242469U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 8926367674641729058U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 11035347490524961446U;
            aOrbiterE = RotL64((aOrbiterE * 10948288997163592463U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 10748158733051120339U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 2467801787989056455U;
            aOrbiterG = RotL64((aOrbiterG * 12621934274702358977U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 9244415080474351390U) + aNonceWordC;
            aOrbiterK = (((aOrbiterK ^ aOrbiterA) ^ 8517784887959492079U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterK = RotL64((aOrbiterK * 17022899813765884147U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 8409307332803038455U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 11043806021873232950U) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 8294888329708842989U), 43U);
            //
            aIngress = RotL64(aOrbiterD, 21U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + (RotL64(aOrbiterG, 48U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aScatter, 11U) + RotL64(aOrbiterD, 35U)) + aOrbiterG);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterA, 3U)) + aNonceWordJ);
            aWandererG = aWandererG + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 41U)) + aOrbiterF);
            aWandererH = aWandererH ^ ((RotL64(aCross, 60U) + aOrbiterK) + RotL64(aOrbiterJ, 20U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterE, 13U)) + aOrbiterK) + RotL64(aCarry, 41U)) + aNonceWordH);
            aWandererE = aWandererE ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterD, 29U)) + aOrbiterJ) + aPhaseDWandererUpdateSaltF[((aIndex + 22U)) & S_SALT1]);
            aWandererC = aWandererC + (((((RotL64(aPrevious, 37U) + RotL64(aOrbiterJ, 53U)) + aOrbiterG) + RotL64(aCarry, 57U)) + aNonceWordD) + aPhaseDWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 28U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_Cricket_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xEFC719C1126E62B7ULL + 0xBFA13211C7C637BCULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xC5F7BE334B08A87FULL + 0xA4C23E5E1D577E28ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x91B7C9202395869BULL + 0xE6073EC72D005A5BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x9048527B865593DDULL + 0x97199E796C32C0B6ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xFAF1DA6EF5BE43D3ULL + 0xF8CBB2E1AE10D4D4ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xD4D5FD33D9F01CF1ULL + 0xB52C199B4850553BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xCFC027C057734E15ULL + 0xD4FE718C12640619ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xF2D3319AA29F101BULL + 0x913B14ADC1779A85ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xD9093082D3485C61ULL + 0xE0133FC366389AD1ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xB922056CFE6ABFABULL + 0xAAD72CD2AC6E6FBFULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xEE7321E178E98C9BULL + 0xD644E4ADF9BEB4F5ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xB61E4999475C2003ULL + 0xA53DA18981A395E7ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xA14FBDE15F212825ULL + 0xD65E164E54B53A87ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xC85B84B6A5026C15ULL + 0xE196A7BDBED1D5A8ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xC170EA4DF6AC50A9ULL + 0xED360B71B0899242ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xAC8DCD57779AADB3ULL + 0xB42DAA6D5C0C03DDULL);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 562U)) & S_BLOCK1], 41U) ^ RotL64(aInvestLaneB[((aIndex + 1502U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 4553U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 4873U)) & S_BLOCK1], 47U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 3165U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 2376U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 24U) + RotL64(aIngress, 11U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 11U)) + 16519040829220310189U;
            aOrbiterK = (aWandererF + RotL64(aIngress, 11U)) + 6888002778416941825U;
            aOrbiterF = ((((aWandererC + RotL64(aScatter, 24U)) + RotL64(aCarry, 57U)) + 1310832187746534025U) + aPhaseEOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1]) + aNonceWordP;
            aOrbiterB = (aWandererG + RotL64(aCross, 43U)) + 5890888009051281674U;
            aOrbiterH = (((aWandererH + RotL64(aScatter, 19U)) + 5143864838362464857U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordC;
            aOrbiterC = (((aWandererB + RotL64(aIngress, 39U)) + RotL64(aCarry, 27U)) + 15591534069452660003U) + aNonceWordI;
            aOrbiterE = (aWandererI + RotL64(aPrevious, 5U)) + 1466867671765325096U;
            aOrbiterI = (aWandererK + RotL64(aCross, 35U)) + 13931443680107902488U;
            aOrbiterA = (aWandererA + RotL64(aIngress, 53U)) + 15400747367673245552U;
            aOrbiterD = (aWandererJ + RotL64(aCross, 3U)) + 2836975369734495759U;
            aOrbiterG = (aWandererD + RotL64(aPrevious, 56U)) + 2370720358274970117U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 3470677184188006133U) + aNonceWordB;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 7175584278499266723U;
            aOrbiterF = RotL64((aOrbiterF * 10067096593682482345U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 6095078817776863055U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 2176637999243513070U;
            aOrbiterC = RotL64((aOrbiterC * 12215701810843975501U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 5580391239754903129U) + aNonceWordD;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 15196125567953871184U;
            aOrbiterB = RotL64((aOrbiterB * 12686361960729564519U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 12787014151503209931U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 1523153207064063495U;
            aOrbiterA = RotL64((aOrbiterA * 3113907543551927561U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 12973289026485937829U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 9087439766232078173U;
            aOrbiterI = RotL64((aOrbiterI * 5817029335999350327U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 16318022893068674015U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 11089160685103562409U;
            aOrbiterK = RotL64((aOrbiterK * 17087834321385147603U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 8680037953925067235U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 3112588943274158119U;
            aOrbiterJ = RotL64((aOrbiterJ * 9214011370307670371U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 16749015684369649821U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 9419550535891334966U;
            aOrbiterH = RotL64((aOrbiterH * 5421312787569114811U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 12309598080688360615U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 12244971765096881835U;
            aOrbiterE = RotL64((aOrbiterE * 17260277357109449509U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 10088685417774847648U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 3241987595838650154U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14096986158958931367U), 11U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterE) + 17916401586500786536U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1]) + aNonceWordK;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 16519040829220310189U;
            aOrbiterD = RotL64((aOrbiterD * 6742024268853509861U), 23U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterA, 39U);
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 28U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 23U)) + aOrbiterD) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 39U) + RotL64(aOrbiterB, 35U)) + aOrbiterH) + aNonceWordL);
            aWandererE = aWandererE ^ ((RotL64(aCross, 56U) + aOrbiterK) + RotL64(aOrbiterC, 53U));
            aWandererK = aWandererK + (((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterG, 60U)) + RotL64(aCarry, 23U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 37U) + aOrbiterB) + RotL64(aOrbiterE, 19U)) + aNonceWordF);
            aWandererI = aWandererI + (((RotL64(aIngress, 23U) + RotL64(aOrbiterE, 37U)) + aOrbiterG) + aNonceWordM);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 52U) + aOrbiterJ) + RotL64(aOrbiterC, 43U)) + aNonceWordH);
            aWandererF = aWandererF + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 51U)) + aOrbiterF) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterH, 58U)) + aOrbiterA);
            aWandererB = aWandererB + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 47U)) + aOrbiterK) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 21U) + aOrbiterA) + RotL64(aOrbiterE, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 18U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererJ, 46U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aFireLaneA[((aIndex + 6895U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneC[((aIndex + 7467U)) & S_BLOCK1], 10U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 7519U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10430U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 9635U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 6690U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 9024U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCarry, 24U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterI = ((aWandererD + RotL64(aScatter, 23U)) + RotL64(aCarry, 13U)) + 13714409587461539863U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 38U)) + 14101156723903265839U) + aNonceWordK;
            aOrbiterF = (((aWandererC + RotL64(aIngress, 13U)) + RotL64(aCarry, 41U)) + 7063754562895369001U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 43U)) + 12320578575245519386U) + aNonceWordG;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 27U)) + 11744826789631008424U) + aNonceWordJ;
            aOrbiterK = (aWandererK + RotL64(aCross, 36U)) + 8744816505096675597U;
            aOrbiterH = (aWandererH + RotL64(aIngress, 5U)) + 10405435520084528645U;
            aOrbiterB = (aWandererE + RotL64(aPrevious, 29U)) + 1463157688070683543U;
            aOrbiterE = ((aWandererF + RotL64(aCross, 3U)) + 12379603577919617703U) + aNonceWordH;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 47U)) + RotL64(aCarry, 27U)) + 1343439118031348146U;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 19U)) + 16118850268070235540U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 14116264435819277136U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 5251698273012432109U;
            aOrbiterF = RotL64((aOrbiterF * 1495818611622063967U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 14806408656041403829U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 11569345414052398227U;
            aOrbiterC = RotL64((aOrbiterC * 9913158908301414861U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 17063874769147888574U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 9927420478679581917U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9042782809534196563U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 2550285599827162167U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 17801534123304996448U) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 2160836889363614721U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 6456685241021762041U) + aNonceWordP;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 17064208177372969289U;
            aOrbiterA = RotL64((aOrbiterA * 13726627607233302493U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 18279938244131982650U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 8211002229712129419U;
            aOrbiterJ = RotL64((aOrbiterJ * 12931373380977640645U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 12795832560781931767U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 286378504074349650U;
            aOrbiterD = RotL64((aOrbiterD * 85453101173293509U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 5835304250436889513U) + aNonceWordC;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 12704972686724379659U;
            aOrbiterE = RotL64((aOrbiterE * 1198789639656336053U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 12555700587254295099U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 6740149669657971715U;
            aOrbiterK = RotL64((aOrbiterK * 9376048577305482691U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 1541392147096889431U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 16891341703173286949U;
            aOrbiterG = RotL64((aOrbiterG * 697452963711223355U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 8811637585092392653U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 13714409587461539863U;
            aOrbiterI = RotL64((aOrbiterI * 2578939920876994763U), 3U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 57U);
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + (RotL64(aOrbiterD, 18U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 39U));
            aIngress = aIngress + RotL64(aOrbiterJ, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 23U) + aOrbiterC) + RotL64(aOrbiterF, 57U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 48U) + RotL64(aOrbiterI, 47U)) + aOrbiterA);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterH, 39U)) + aOrbiterJ) + aNonceWordL);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 43U)) + aOrbiterD);
            aWandererG = aWandererG ^ ((RotL64(aCross, 51U) + aOrbiterB) + RotL64(aOrbiterK, 24U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 37U) + aOrbiterB) + RotL64(aOrbiterE, 37U)) + RotL64(aCarry, 23U)) + aNonceWordM);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 14U) + aOrbiterG) + RotL64(aOrbiterD, 35U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 51U)) + aOrbiterA) + RotL64(aCarry, 19U)) + aPhaseEWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterJ, 10U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterK, 13U)) + aOrbiterE);
            aWandererE = aWandererE ^ (((RotL64(aCross, 3U) + aOrbiterF) + RotL64(aOrbiterG, 29U)) + aPhaseEWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 52U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 56U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 12353U)) & S_BLOCK1], 29U) ^ RotL64(aInvestLaneA[((aIndex + 15523U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 12185U)) & S_BLOCK1], 48U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 13077U)) & S_BLOCK1], 22U) ^ RotL64(aInvestLaneC[((aIndex + 16146U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aPrevious, 56U)) + (RotL64(aCarry, 11U) + RotL64(aIngress, 43U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterF = (aWandererC + RotL64(aScatter, 43U)) + 16160838483846078448U;
            aOrbiterE = (((aWandererJ + RotL64(aIngress, 13U)) + RotL64(aCarry, 47U)) + 15404960896190227946U) + aNonceWordB;
            aOrbiterK = ((aWandererF + RotL64(aCross, 47U)) + 16904160594024977199U) + aPhaseEOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aPrevious, 10U)) + 17790460246821031802U;
            aOrbiterH = (aWandererG + RotL64(aCross, 29U)) + 16395168254086971959U;
            aOrbiterC = (aWandererD + RotL64(aPrevious, 19U)) + 7484373204039901786U;
            aOrbiterB = (((aWandererA + RotL64(aScatter, 23U)) + RotL64(aCarry, 53U)) + 18026814691322913510U) + aNonceWordD;
            aOrbiterD = (aWandererI + RotL64(aIngress, 51U)) + 15244817793136966450U;
            aOrbiterI = ((aWandererB + RotL64(aScatter, 35U)) + 5795491730356335666U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = (aWandererK + RotL64(aPrevious, 3U)) + 3163873518027801504U;
            aOrbiterJ = (((aWandererH + RotL64(aCross, 26U)) + RotL64(aCarry, 43U)) + 2690791759507349172U) + aNonceWordM;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 17898067251167087906U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 8028010015006604239U) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 5601629670521300241U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 7304739457289910555U) + aNonceWordL;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 6476837815096530043U;
            aOrbiterF = RotL64((aOrbiterF * 16380545138701113267U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 14242499233467960602U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 17305645693017634630U;
            aOrbiterB = RotL64((aOrbiterB * 14442976693206929569U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 9772864059444171908U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 7897200728282156408U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 816306719390807411U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 4890999319172950996U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 8165132649356094963U;
            aOrbiterI = RotL64((aOrbiterI * 17297706071263690189U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 9342923520083533265U) + aNonceWordI;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 7213639583505088067U;
            aOrbiterD = RotL64((aOrbiterD * 1349251979649428909U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 4079475132684197272U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 3350998022472827283U;
            aOrbiterA = RotL64((aOrbiterA * 948841791460066265U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 2479140576609216238U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 7703147534931674972U;
            aOrbiterG = RotL64((aOrbiterG * 11419116495223970801U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 9050277787914448469U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 13295888852307317371U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3027097172772140975U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 15380254190549884741U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 17653690414528791774U;
            aOrbiterH = RotL64((aOrbiterH * 15923958179714368315U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 6825072759468337036U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 16160838483846078448U) ^ aNonceWordO;
            aOrbiterC = RotL64((aOrbiterC * 11690325563580492415U), 11U);
            //
            aIngress = RotL64(aOrbiterE, 53U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 43U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + RotL64(aOrbiterA, 34U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterJ, 43U)) + aNonceWordK);
            aWandererE = aWandererE + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterG, 21U)) + aOrbiterJ);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 3U)) + aOrbiterK);
            aWandererF = aWandererF + (((RotL64(aScatter, 21U) + RotL64(aOrbiterG, 11U)) + aOrbiterE) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterH, 29U));
            aWandererI = aWandererI + ((RotL64(aScatter, 34U) + RotL64(aOrbiterJ, 60U)) + aOrbiterC);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterA, 27U)) + aPhaseEWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterI, 19U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 13U)) + aOrbiterD) + aNonceWordG);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 37U)) + aOrbiterF) + RotL64(aCarry, 21U)) + aPhaseEWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 10U) + RotL64(aOrbiterD, 24U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 10U));
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (RotL64(aWandererC, 14U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 27U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 17757U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneA[((aIndex + 19496U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 17050U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 18225U)) & S_BLOCK1], 51U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 21018U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 56U) ^ RotL64(aPrevious, 5U)) ^ (RotL64(aCarry, 23U) + RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterK = ((aWandererC + RotL64(aCross, 11U)) + RotL64(aCarry, 13U)) + 6916817163240024692U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 26U)) + RotL64(aCarry, 47U)) + 14554930751292077817U;
            aOrbiterA = (aWandererD + RotL64(aPrevious, 51U)) + 1098305064484336101U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 3U)) + RotL64(aCarry, 27U)) + 12192821172420471527U;
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 47U)) + 2435134991707318845U;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 29U)) + 1896745368738512624U) + aNonceWordJ;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 42U)) + 1114996424222923873U) + aNonceWordO;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 53U)) + 9839135798371512656U) + aPhaseEOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = ((aWandererI + RotL64(aCross, 57U)) + 8037967239603177043U) + aPhaseEOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = (aWandererE + RotL64(aIngress, 19U)) + 15185468738487237432U;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 13U)) + 4912098316394854543U) + aNonceWordL;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 13142688607850380888U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 4507379759608945839U;
            aOrbiterA = RotL64((aOrbiterA * 2989332387754215967U), 41U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterF) + 7299006009652289342U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordF;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 5390655277207053627U;
            aOrbiterJ = RotL64((aOrbiterJ * 10973744708856143715U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 6744737023577785725U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 15539737698867067285U;
            aOrbiterE = RotL64((aOrbiterE * 4686092035261336911U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 13329866734681377952U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 13284937458969166257U;
            aOrbiterK = RotL64((aOrbiterK * 3965985432462699445U), 39U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterK) + 8695002088915702168U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1]) + aNonceWordA;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 3858059421620839286U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9559783727301092937U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 6609163873243179836U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 9416165620556710540U;
            aOrbiterH = RotL64((aOrbiterH * 240385043740268229U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 1578449067529000433U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 14309000104419489303U) ^ aNonceWordD;
            aOrbiterD = RotL64((aOrbiterD * 7599078306153684729U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 15785180680737461320U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 10099222679918382021U;
            aOrbiterF = RotL64((aOrbiterF * 2012232597046182581U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 10666287769220108179U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 13648647399222807034U;
            aOrbiterB = RotL64((aOrbiterB * 10772381733103127201U), 27U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterH) + 9292207828896796810U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordN;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 9155130791347443553U;
            aOrbiterI = RotL64((aOrbiterI * 16838229790655977057U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 11334395119119245556U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 6916817163240024692U;
            aOrbiterG = RotL64((aOrbiterG * 9640906826978028183U), 5U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 13U);
            aIngress = aIngress + (RotL64(aOrbiterG, 37U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 46U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aScatter, 39U) + RotL64(aOrbiterJ, 37U)) + aOrbiterC);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 14U) + RotL64(aOrbiterA, 27U)) + aOrbiterK);
            aWandererC = aWandererC + (((RotL64(aIngress, 19U) + aOrbiterF) + RotL64(aOrbiterG, 54U)) + aNonceWordC);
            aWandererD = aWandererD ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterG, 5U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aScatter, 41U) + aOrbiterG) + RotL64(aOrbiterE, 21U)) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 10U) + aOrbiterC) + RotL64(aOrbiterH, 29U)) + aNonceWordG);
            aWandererF = aWandererF + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 12U)) + aOrbiterD);
            aWandererH = aWandererH ^ ((RotL64(aCross, 47U) + aOrbiterH) + RotL64(aOrbiterA, 41U));
            aWandererA = aWandererA + (((((RotL64(aIngress, 29U) + RotL64(aOrbiterI, 39U)) + aOrbiterJ) + RotL64(aCarry, 23U)) + aNonceWordB) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterD, 19U)) + aOrbiterJ) + aNonceWordK);
            aWandererB = aWandererB + (((RotL64(aPrevious, 23U) + aOrbiterI) + RotL64(aOrbiterB, 47U)) + aPhaseEWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + (RotL64(aWandererB, 14U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + RotL64(aWandererG, 35U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 27168U)) & S_BLOCK1], 10U) ^ RotL64(aFireLaneB[((aIndex + 23421U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 24618U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25652U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 26887U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 26872U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 54U) ^ RotL64(aCross, 5U)) + (RotL64(aIngress, 19U) + RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterK = (((aWandererA + RotL64(aIngress, 47U)) + 6469584119078165548U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordA;
            aOrbiterA = (aWandererC + RotL64(aScatter, 13U)) + 14329756366517987910U;
            aOrbiterI = (aWandererE + RotL64(aCross, 60U)) + 12890831797059772123U;
            aOrbiterF = (aWandererH + RotL64(aPrevious, 35U)) + 3164503807500018990U;
            aOrbiterJ = (aWandererF + RotL64(aScatter, 39U)) + 177531431387646836U;
            aOrbiterB = ((aWandererB + RotL64(aCross, 21U)) + 3167421392893561015U) + aPhaseEOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 39U)) + 2813174781844753460U) + aNonceWordN;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 41U)) + RotL64(aCarry, 29U)) + 10953270419153249857U;
            aOrbiterC = ((aWandererD + RotL64(aCross, 5U)) + RotL64(aCarry, 43U)) + 16911518309710356951U;
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 23U)) + 6616750447844893150U;
            aOrbiterE = (aWandererG + RotL64(aIngress, 30U)) + 10276741398025985982U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 6206043608461213208U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 12021552904553405793U;
            aOrbiterI = RotL64((aOrbiterI * 10023362889960174909U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 15283586234744144846U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 5923238786775948571U;
            aOrbiterB = RotL64((aOrbiterB * 8200882393521882651U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 11044014510971660078U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 9351141024085076044U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13316079344614432317U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 17703395981862992420U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 10154548848376027087U) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 12324478347590509035U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 8836420852291617425U) + aNonceWordO;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 10193385413543886344U;
            aOrbiterH = RotL64((aOrbiterH * 824935982418585449U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 8248580084535685190U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 3910083671888152974U;
            aOrbiterE = RotL64((aOrbiterE * 17825311776715895927U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 12350341628569930642U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 2565977481575002842U) ^ aNonceWordD;
            aOrbiterK = RotL64((aOrbiterK * 18233446879833776677U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 9271041067874027417U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 14289254596554201861U;
            aOrbiterD = RotL64((aOrbiterD * 7985522692852251413U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 5981802134118235214U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 14047813418129636856U;
            aOrbiterA = RotL64((aOrbiterA * 15961435325216504877U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 11808443842149398212U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 11380858372643695792U;
            aOrbiterC = RotL64((aOrbiterC * 100198424024622179U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 10385375464069162356U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 6469584119078165548U;
            aOrbiterF = RotL64((aOrbiterF * 5263876933019848989U), 29U);
            //
            aIngress = RotL64(aOrbiterE, 60U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterA, 23U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterG, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterB, 42U)) + aOrbiterH) + RotL64(aCarry, 37U)) + aPhaseEWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterE, 27U)) + aOrbiterJ);
            aWandererF = aWandererF + ((RotL64(aCross, 13U) + RotL64(aOrbiterK, 11U)) + aOrbiterF);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterF, 37U)) + aOrbiterB);
            aWandererC = aWandererC + ((RotL64(aScatter, 48U) + aOrbiterG) + RotL64(aOrbiterA, 3U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 51U) + aOrbiterK) + RotL64(aOrbiterJ, 51U)) + aNonceWordK);
            aWandererE = aWandererE + (((RotL64(aCross, 39U) + RotL64(aOrbiterD, 23U)) + aOrbiterH) + aNonceWordI);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 23U) + aOrbiterI) + RotL64(aOrbiterD, 53U)) + aNonceWordM);
            aWandererG = aWandererG + (((RotL64(aCross, 46U) + aOrbiterI) + RotL64(aOrbiterC, 6U)) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 21U) + RotL64(aOrbiterI, 21U)) + aOrbiterF) + aNonceWordL) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterG, 57U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 26U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 6U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 29391U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((aIndex + 28128U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 31677U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28588U)) & S_BLOCK1], 53U) ^ RotL64(aInvestLaneB[((aIndex + 30475U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCarry, 28U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterA = ((aWandererA + RotL64(aScatter, 53U)) + 3612110001869385068U) + aPhaseEOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aIngress, 43U)) + RotL64(aCarry, 3U)) + 16340824141280225936U;
            aOrbiterF = ((aWandererF + RotL64(aCross, 35U)) + RotL64(aCarry, 27U)) + 15222338965130765231U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 6U)) + 6649270508107155041U) + aNonceWordA;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 13U)) + 768217258655426384U) + aNonceWordI;
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 29U)) + 4481855259658861851U) + aNonceWordF;
            aOrbiterJ = (aWandererH + RotL64(aCross, 3U)) + 18318041934562434016U;
            aOrbiterG = (aWandererK + RotL64(aIngress, 60U)) + 4212457153804401807U;
            aOrbiterD = (((aWandererD + RotL64(aPrevious, 47U)) + RotL64(aCarry, 23U)) + 16143621095636987628U) + aNonceWordD;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 21U)) + 2095664232866642086U) + aPhaseEOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = (aWandererG + RotL64(aCross, 19U)) + 4339527736737366572U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 13679353177869884790U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 11582168502846418236U;
            aOrbiterF = RotL64((aOrbiterF * 135539430034462861U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 10451330452898542191U) + aNonceWordL;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 12951448817640617841U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4141870904192742091U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 15389161934419370747U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 4754886272708253014U) ^ aNonceWordP;
            aOrbiterG = RotL64((aOrbiterG * 16638243718191281597U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 11746389873929280688U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 12042680172517298768U;
            aOrbiterH = RotL64((aOrbiterH * 3814780289755857543U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 2648103752465009244U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 451594673632597973U) ^ aNonceWordJ;
            aOrbiterK = RotL64((aOrbiterK * 8496763663271072425U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 5696534794094099710U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 14609435045257077395U;
            aOrbiterE = RotL64((aOrbiterE * 14658408563237468407U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 11599395126850950133U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 12699598504604446664U) ^ aNonceWordN;
            aOrbiterA = RotL64((aOrbiterA * 14313494063098111823U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 9398465148537154745U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 12139736860648011256U;
            aOrbiterJ = RotL64((aOrbiterJ * 15257503229375247987U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 5390816291244486383U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 2797988892316486895U;
            aOrbiterD = RotL64((aOrbiterD * 14668138881285892065U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 18356290434261054712U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 16582824574485822826U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7207935384746719969U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 9858803484150150915U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 3612110001869385068U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2862887443435821143U), 47U);
            //
            aIngress = RotL64(aOrbiterH, 29U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 22U));
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterB, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 19U) + aOrbiterK) + RotL64(aOrbiterB, 41U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 48U) + RotL64(aOrbiterJ, 21U)) + aOrbiterK);
            aWandererI = aWandererI + ((RotL64(aScatter, 41U) + RotL64(aOrbiterI, 48U)) + aOrbiterH);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterB, 37U)) + aOrbiterF) + aNonceWordB);
            aWandererH = aWandererH + (((RotL64(aIngress, 39U) + aOrbiterA) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterG, 5U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 23U) + aOrbiterD) + RotL64(aOrbiterI, 29U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterE, 39U)) + aOrbiterB);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 44U) + aOrbiterC) + RotL64(aOrbiterG, 3U)) + aNonceWordC);
            aWandererF = aWandererF ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterG, 52U)) + aOrbiterD);
            aWandererC = aWandererC + (((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterF, 43U)) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 24U));
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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

void TwistExpander_Cricket_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xDC6E8912CCC101A3ULL + 0xB482146F51EF47A3ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xC70EBFA5F10A24F3ULL + 0xA2CBDEB14890B604ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xF73924D926A505BBULL + 0xE99D28F7EF6A18F5ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x97E4B8489E3A8255ULL + 0xD4B12903345555AEULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xB29A2D6FE3E2C5C3ULL + 0x817429483D139B8AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xC1E8BDACC439BEFFULL + 0xE9BA7E22EC7248A4ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xA7514C722116DDD9ULL + 0xFF37E3A60B634FD4ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xBF3EF81FE25CE071ULL + 0xEACD5CABB9FF448EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xD81C4891CAD35FC1ULL + 0xE55EC3AA8712F2DCULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xDC69214B6A925C25ULL + 0xD26259A72883A1F5ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xBFA882958B17CA07ULL + 0x8D4B3609C19177A0ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xFBB3D8AE2B8ADC27ULL + 0x96FF9DA49B31EB87ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xD55AA05CAC6089BBULL + 0xC2EE8265FDCE2C8DULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xE745BC6F636D5049ULL + 0x85A7DFDBB69EA84FULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xF09AD43F1BF9B70DULL + 0xE3A2E86E1EED2CDAULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xCB5E194277633163ULL + 0xE2D1F2B175D62065ULL);
    // GSeedRunSeed_F seed_loop_f (start)
    {
        // GSeedRunSeed_F seed_loop_f lane group
        // read from: aOperationLaneA, aOperationLaneB, aInvestLaneC, aOperationLaneC, aOperationLaneD, aInvestLaneB, aSnowLaneC, aSnowLaneB, aInvestLaneD, aSnowLaneD, aInvestLaneA, aExpandLaneA, aWorkLaneC, aExpandLaneB, aWorkLaneD, aExpandLaneC, aSnowLaneA
        // write to: aSnowLaneC, aSnowLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_f loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aInvestLaneC
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aInvestLaneC forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aInvestLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aInvestLaneB backward/forward random
        // write to: aSnowLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 2817U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((aIndex + 4804U)) & S_BLOCK1], 60U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 3955U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5323U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 3938U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 126U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 20U)) + (RotL64(aIngress, 5U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterD = ((aWandererG + RotL64(aScatter, 18U)) + 7632760812370906911U) + aNonceWordI;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 35U)) + 6007174525479723089U) + aNonceWordK;
            aOrbiterH = (((aWandererF + RotL64(aIngress, 29U)) + RotL64(aCarry, 21U)) + 3362829642521821048U) + aPhaseFOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aCross, 39U)) + RotL64(aCarry, 57U)) + 18009548556107978286U;
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 53U)) + 17880909432272697327U;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 57U)) + RotL64(aCarry, 5U)) + 15961567935420752568U;
            aOrbiterB = (aWandererI + RotL64(aIngress, 13U)) + 10136559064656837921U;
            aOrbiterK = (aWandererC + RotL64(aCross, 3U)) + 17622019364405410277U;
            aOrbiterF = (((aWandererE + RotL64(aIngress, 22U)) + 6927494824421416306U) + aPhaseFOrbiterAssignSaltD[((aIndex + 28U)) & S_SALT1]) + aNonceWordO;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 7125170407794874847U) + aNonceWordE;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 12342273503071032250U;
            aOrbiterH = RotL64((aOrbiterH * 867417849555857179U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 14997696377476124836U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 14874498694181230698U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4026127545746010937U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 2549397729130885686U) + aNonceWordA;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 4217995818662767955U;
            aOrbiterB = RotL64((aOrbiterB * 5525525344485251063U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 4706089044415442525U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 17983900172670031015U;
            aOrbiterK = RotL64((aOrbiterK * 541552737180932879U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 1904937798143929988U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 10620877287033139483U;
            aOrbiterD = RotL64((aOrbiterD * 16711012562024287213U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 15681091173163181525U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 2655543246639000084U;
            aOrbiterJ = RotL64((aOrbiterJ * 16686375598149755947U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 2647895110857289213U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 5581609212017175954U;
            aOrbiterA = RotL64((aOrbiterA * 15330263616699031311U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 13609076329627787987U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 6244266279516622070U;
            aOrbiterF = RotL64((aOrbiterF * 12488345779236971095U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 5289624364508923581U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 16351476803965903112U;
            aOrbiterG = RotL64((aOrbiterG * 9012522724650442597U), 51U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 35U);
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 60U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + RotL64(aOrbiterA, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterE, 23U)) + aNonceWordC);
            aWandererC = aWandererC + ((((RotL64(aCross, 53U) + RotL64(aOrbiterH, 39U)) + aOrbiterK) + RotL64(aCarry, 13U)) + aNonceWordM);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 12U) + RotL64(aOrbiterE, 10U)) + aOrbiterF) + aNonceWordN);
            aWandererE = aWandererE + (((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 57U)) + aOrbiterF) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterJ, 3U)) + aNonceWordH);
            aWandererF = aWandererF + (((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 27U)) + aOrbiterB) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterB, 18U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 20U) + aOrbiterH) + RotL64(aOrbiterB, 43U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterG, 51U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererG, 50U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererI);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aSnowLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 2
        // ingress from: aSnowLaneC, aOperationLaneC, aOperationLaneD, aSnowLaneB
        // ingress directions: aSnowLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aSnowLaneB forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aInvestLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aInvestLaneD backward/forward random
        // write to: aSnowLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneC[((aIndex + 8812U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneC[((aIndex + 7112U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 9302U)) & S_BLOCK1], 35U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 10631U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 10166U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6387U)) & S_BLOCK1], 6U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 7302U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aPrevious, 54U)) ^ (RotL64(aIngress, 5U) + RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterB = (((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 43U)) + 18319689184146942855U) + aNonceWordA;
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 60U)) + RotL64(aCarry, 11U)) + 8041304130090501019U;
            aOrbiterE = ((aWandererC + RotL64(aCross, 23U)) + 11347064191990897738U) + aNonceWordH;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 43U)) + 15242243470024447468U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = ((aWandererB + RotL64(aScatter, 47U)) + 10619749107163611105U) + aNonceWordM;
            aOrbiterH = (((aWandererI + RotL64(aIngress, 11U)) + RotL64(aCarry, 51U)) + 14795614276221947128U) + aPhaseFOrbiterAssignSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = (aWandererA + RotL64(aPrevious, 39U)) + 1578095288886372393U;
            aOrbiterJ = (aWandererE + RotL64(aCross, 54U)) + 13593906305770501684U;
            aOrbiterD = (aWandererD + RotL64(aScatter, 27U)) + 8919815528334599172U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 17425548324720065145U) + aNonceWordI;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 11125018338392347335U;
            aOrbiterE = RotL64((aOrbiterE * 4377887040461528587U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 3779189180734244399U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 10958224663276134041U) ^ aNonceWordJ;
            aOrbiterH = RotL64((aOrbiterH * 6206963519509783781U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 4317305352561612995U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 4891139433808505355U;
            aOrbiterJ = RotL64((aOrbiterJ * 11507024985663120317U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 5166074784835930965U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 10080890270621589202U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13170894418184288695U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 4501071771615514619U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 6486573807774431753U;
            aOrbiterA = RotL64((aOrbiterA * 324029625116648669U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 15714881857668975753U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 3506619392820235900U;
            aOrbiterD = RotL64((aOrbiterD * 5707033870161224499U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 5295711072762443783U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 11192836530396570648U;
            aOrbiterC = RotL64((aOrbiterC * 4361810118382207039U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 7993389678399774574U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 12551394763541226695U;
            aOrbiterI = RotL64((aOrbiterI * 11903486656172026403U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 11553674370322129668U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterI) ^ 4459881583199320245U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 2805857426321555685U), 47U);
            //
            aIngress = RotL64(aOrbiterJ, 6U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterH, 43U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 47U) + aOrbiterI) + RotL64(aOrbiterC, 57U)) + aNonceWordD);
            aWandererI = aWandererI + (((RotL64(aScatter, 27U) + RotL64(aOrbiterH, 19U)) + aOrbiterB) + aNonceWordK);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 18U) + RotL64(aOrbiterC, 38U)) + aOrbiterB);
            aWandererK = aWandererK + (((RotL64(aCross, 43U) + RotL64(aOrbiterH, 29U)) + aOrbiterA) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 43U)) + aOrbiterC);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 5U) + RotL64(aOrbiterH, 23U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 39U) + aOrbiterB) + RotL64(aOrbiterA, 53U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 56U) + aOrbiterH) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 23U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterK, 4U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (RotL64(aWandererA, 42U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 11U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aSnowLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 3
        // ingress from: aSnowLaneD, aOperationLaneA, aInvestLaneA
        // ingress directions: aSnowLaneD forward forced, aOperationLaneA forward forced, aInvestLaneA forward/backward random
        // cross from: aSnowLaneC, aOperationLaneC
        // cross directions: aSnowLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneD[((aIndex + 11052U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((aIndex + 13018U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 11938U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 10996U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 13121U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCarry, 18U)) ^ (RotL64(aIngress, 5U) + RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 29U)) + RotL64(aCarry, 27U)) + 17668251151213543491U;
            aOrbiterG = ((aWandererG + RotL64(aCross, 5U)) + 16101602509895104517U) + aNonceWordG;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 57U)) + 9083915270773304935U) + aPhaseFOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aPrevious, 41U)) + 12810720730318214811U;
            aOrbiterC = (aWandererB + RotL64(aIngress, 48U)) + 18113428002071925621U;
            aOrbiterF = (aWandererH + RotL64(aCross, 13U)) + 1582208899354109878U;
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 53U)) + 4180688104819188154U) + aNonceWordN;
            aOrbiterD = (((aWandererF + RotL64(aPrevious, 19U)) + RotL64(aCarry, 53U)) + 8954598189262820611U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aCross, 36U)) + RotL64(aCarry, 35U)) + 15360094153175355879U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 8383954114668216260U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 15626783326234049197U;
            aOrbiterI = RotL64((aOrbiterI * 15058420415480073793U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 10609978564404958066U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 17656516608997517984U;
            aOrbiterF = RotL64((aOrbiterF * 4590620354119899777U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 760077259110786536U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 3597338735888033063U;
            aOrbiterC = RotL64((aOrbiterC * 6548831472863517621U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 4431777844935985157U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 10710423172154671296U;
            aOrbiterG = RotL64((aOrbiterG * 16267496318491473315U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 10240882795242085185U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 7826053487019825891U) ^ aNonceWordJ;
            aOrbiterB = RotL64((aOrbiterB * 15053729937684375907U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 9418883403715727353U) + aNonceWordB;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 11507423614799075545U;
            aOrbiterJ = RotL64((aOrbiterJ * 16189463984557044693U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 11545217316421066655U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 617921402135485341U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8182920764965471653U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 14456933220749921009U) + aNonceWordF;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 7990243583564535387U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5994900368027985469U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 14023633125757654751U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 11319146808574958827U) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 13676159969338309307U), 51U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 3U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + (RotL64(aOrbiterF, 14U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 39U));
            aIngress = aIngress + RotL64(aOrbiterD, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aScatter, 11U) + aOrbiterK) + RotL64(aOrbiterJ, 47U)) + aNonceWordK) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 34U) + aOrbiterC) + RotL64(aOrbiterK, 60U));
            aWandererC = aWandererC + (((RotL64(aCross, 19U) + aOrbiterB) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 5U)) + aOrbiterA);
            aWandererB = aWandererB + ((RotL64(aIngress, 39U) + RotL64(aOrbiterB, 41U)) + aOrbiterI);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 51U)) + aOrbiterK);
            aWandererF = aWandererF + (((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterF, 35U)) + aPhaseFWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterF, 18U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 56U) + RotL64(aOrbiterB, 11U)) + aOrbiterD) + RotL64(aCarry, 19U)) + aNonceWordA);
            //
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 50U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + RotL64(aWandererF, 39U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 4
        // ingress from: aExpandLaneA, aSnowLaneC, aWorkLaneC
        // ingress directions: aExpandLaneA forward forced, aSnowLaneC forward forced, aWorkLaneC forward/backward random
        // cross from: aSnowLaneD, aOperationLaneD
        // cross directions: aSnowLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 17839U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneC[((aIndex + 18197U)) & S_BLOCK1], 54U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 17606U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 18386U)) & S_BLOCK1], 20U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20126U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 53U)) + (RotL64(aIngress, 5U) + RotL64(aCross, 38U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterB = (aWandererJ + RotL64(aIngress, 19U)) + 10805654776556844351U;
            aOrbiterC = ((aWandererH + RotL64(aCross, 48U)) + 582794182442795335U) + aNonceWordN;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 37U)) + 2858343650974681068U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 43U)) + 8189584049022064284U;
            aOrbiterD = ((aWandererE + RotL64(aIngress, 3U)) + RotL64(aCarry, 21U)) + 1565100751996962893U;
            aOrbiterG = ((aWandererF + RotL64(aCross, 23U)) + RotL64(aCarry, 57U)) + 8062028016947611891U;
            aOrbiterH = (((aWandererB + RotL64(aPrevious, 30U)) + 8280504280578451745U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 57U)) + RotL64(aCarry, 11U)) + 11326869194491655350U;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 13U)) + 1671695656567777163U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 2349843105293943452U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 13015545152052004254U;
            aOrbiterF = RotL64((aOrbiterF * 1316662811685429983U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 16703354404749291869U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterI) ^ 8713231044374305801U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 9242480982197688625U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 11118401674497783533U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 14857556493734710364U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3452566050389715195U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 12953419670951660965U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 12666121730825089017U;
            aOrbiterD = RotL64((aOrbiterD * 14049925256934142519U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 11075249639473053423U) + aNonceWordA;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 9374217688244187867U;
            aOrbiterI = RotL64((aOrbiterI * 5261156325627117877U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 17608340953291367867U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 13159437499327086340U) ^ aNonceWordG;
            aOrbiterA = RotL64((aOrbiterA * 4882100944453534805U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 4304700511322366815U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 10172544755256706767U;
            aOrbiterC = RotL64((aOrbiterC * 4013006212154771797U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 17340067939877432472U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 14130447570008179105U;
            aOrbiterG = RotL64((aOrbiterG * 8178075071208718915U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 2652532710498072378U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 10384945384238518296U;
            aOrbiterE = RotL64((aOrbiterE * 17137694272394304045U), 57U);
            //
            aIngress = RotL64(aOrbiterH, 56U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + (RotL64(aOrbiterD, 39U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aPrevious, 39U) + aOrbiterF) + RotL64(aOrbiterI, 43U)) + RotL64(aCarry, 27U)) + aNonceWordJ);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterC, 50U)) + aPhaseFWandererUpdateSaltD[((aIndex + 20U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 10U) + RotL64(aOrbiterD, 3U)) + aOrbiterH) + aNonceWordE);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterA, 37U));
            aWandererC = aWandererC + (((RotL64(aCross, 53U) + RotL64(aOrbiterG, 19U)) + aOrbiterA) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 11U)) + aOrbiterI);
            aWandererH = aWandererH + (((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 23U)) + aOrbiterA) + aPhaseFWandererUpdateSaltF[((aIndex + 8U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 18U) + aOrbiterE) + RotL64(aOrbiterH, 29U)) + aNonceWordL);
            aWandererB = aWandererB + ((RotL64(aCross, 27U) + RotL64(aOrbiterE, 56U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 30U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 23U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 5
        // ingress from: aExpandLaneB, aSnowLaneD, aWorkLaneD
        // ingress directions: aExpandLaneB forward forced, aSnowLaneD forward forced, aWorkLaneD forward/backward random
        // cross from: aExpandLaneA, aSnowLaneC
        // cross directions: aExpandLaneA backward forced, aSnowLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 24933U)) & S_BLOCK1], 35U) ^ RotL64(aSnowLaneD[((aIndex + 23935U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 22901U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24515U)) & S_BLOCK1], 6U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 22975U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 10U)) ^ (RotL64(aCross, 51U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 19U)) + RotL64(aCarry, 35U)) + 479672811032092393U;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 35U)) + 18061121631394564425U) + aPhaseFOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = (((aWandererE + RotL64(aCross, 46U)) + RotL64(aCarry, 57U)) + 14237400452740566065U) + aNonceWordD;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 5U)) + 6723123812257706134U) + aNonceWordJ;
            aOrbiterF = (aWandererC + RotL64(aCross, 23U)) + 4247997188026499248U;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 29U)) + 1939107415066134869U) + aNonceWordE;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 39U)) + RotL64(aCarry, 3U)) + 3912640123546395979U;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 50U)) + 8295478436553964298U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 13U)) + 3218960600711526885U) + aNonceWordL;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 5874096203353388890U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 10294536533673023358U;
            aOrbiterI = RotL64((aOrbiterI * 15561710414949058923U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 11268561953904130747U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 16693201256788898423U;
            aOrbiterF = RotL64((aOrbiterF * 16291987237693567209U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 7550969634681894654U) + aNonceWordA;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 9501647424602245869U;
            aOrbiterA = RotL64((aOrbiterA * 11265865222096866605U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 8881869255994319423U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 16770136406906800016U;
            aOrbiterK = RotL64((aOrbiterK * 1782039587385512923U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 16185384746435761363U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 13841034186650721627U) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 12000155593277035447U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 15229062695864608309U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 3576122704615303733U;
            aOrbiterJ = RotL64((aOrbiterJ * 2433987493885779279U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 13898167174453181224U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 12878032061609524049U;
            aOrbiterH = RotL64((aOrbiterH * 18104665741338251495U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 12719156051299028649U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 8640980843376950769U;
            aOrbiterE = RotL64((aOrbiterE * 10242616778390983333U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 12133332160916004365U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 8743563985229104484U;
            aOrbiterG = RotL64((aOrbiterG * 4575129690615054691U), 47U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 60U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterB, 4U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aIngress, 13U) + aOrbiterK) + RotL64(aOrbiterB, 53U)) + aNonceWordC);
            aWandererF = aWandererF + ((RotL64(aCross, 24U) + RotL64(aOrbiterH, 43U)) + aOrbiterI);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterK, 47U));
            aWandererD = aWandererD + (((RotL64(aScatter, 39U) + aOrbiterA) + RotL64(aOrbiterG, 14U)) + RotL64(aCarry, 41U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 19U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 18U) + RotL64(aOrbiterI, 57U)) + aOrbiterF) + RotL64(aCarry, 19U)) + aNonceWordB);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterJ, 29U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 51U) + aOrbiterG) + RotL64(aOrbiterB, 5U)) + aNonceWordI);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterJ, 38U)) + aPhaseFWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 24U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 39U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 30332U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 27537U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 31192U)) & S_BLOCK1], 38U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27683U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31481U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 51U)) + (RotL64(aIngress, 20U) ^ RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterK = (aWandererJ + RotL64(aIngress, 47U)) + 2225397913940961213U;
            aOrbiterI = (((aWandererI + RotL64(aCross, 60U)) + 8342544893601343643U) + aPhaseFOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1]) + aNonceWordA;
            aOrbiterB = (aWandererG + RotL64(aPrevious, 5U)) + 162922186381417187U;
            aOrbiterD = (aWandererC + RotL64(aScatter, 23U)) + 11660218373710972210U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 39U)) + 14909034764605802354U) + aNonceWordJ;
            aOrbiterF = ((aWandererB + RotL64(aCross, 29U)) + RotL64(aCarry, 5U)) + 16776955237009701511U;
            aOrbiterE = (((aWandererA + RotL64(aPrevious, 35U)) + 5834487809188925253U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordC;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 11U)) + RotL64(aCarry, 23U)) + 1498492772767040320U;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 52U)) + RotL64(aCarry, 47U)) + 4161765458781579617U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 10511923076962447765U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 8575954471692620021U;
            aOrbiterB = RotL64((aOrbiterB * 12526744988828982731U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 6536325446331340573U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 1790628986900286346U;
            aOrbiterI = RotL64((aOrbiterI * 5262997114200816715U), 51U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterD) + 2623814807619278590U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1]) + aNonceWordD;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 11676970995834706612U;
            aOrbiterK = RotL64((aOrbiterK * 10057461115132434901U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 13836786354224256591U) + aNonceWordN;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 6293096163612129260U;
            aOrbiterC = RotL64((aOrbiterC * 8977954126326217153U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 4271144764978661248U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 15938494256992560202U;
            aOrbiterG = RotL64((aOrbiterG * 10004841288382726739U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 11038155227307702976U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 12408749795071243930U;
            aOrbiterD = RotL64((aOrbiterD * 5527720475032868855U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 1673665849053496882U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 12866353361497103629U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6041125499398924871U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 10673935802381580966U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 8946776538955520352U;
            aOrbiterJ = RotL64((aOrbiterJ * 12293084177712710021U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 16294935203370452805U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 4697759331563852212U;
            aOrbiterE = RotL64((aOrbiterE * 14407806317275373043U), 37U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 57U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 54U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 43U)) + aOrbiterF) + aNonceWordM) + aPhaseFWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 30U) + aOrbiterC) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 23U) + aOrbiterD) + RotL64(aOrbiterC, 58U)) + aNonceWordG);
            aWandererC = aWandererC + (((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 29U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 39U) + aOrbiterF) + RotL64(aOrbiterJ, 35U));
            aWandererA = aWandererA + ((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 47U)) + aOrbiterK);
            aWandererF = aWandererF ^ (((RotL64(aCross, 12U) + RotL64(aOrbiterE, 23U)) + aOrbiterI) + aPhaseFWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 19U)) + aOrbiterJ);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterK, 4U)) + aOrbiterI) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererA, 30U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + RotL64(aWandererK, 6U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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

void TwistExpander_Cricket_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xC2A400CD1136D689ULL + 0xD5C5AAE0A23E418AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xE9D38D06A8E2DFE9ULL + 0xD0366D292342DF0CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x8D4467DFF8E1E367ULL + 0xF9E1CF285D05E559ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x860A01427D21013FULL + 0x859CA49767689615ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xDEB02DFC79F71307ULL + 0xEE7AED80294D890DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xCF06BFF349392A09ULL + 0x9DD37B9B156712D9ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xDDFF5293B946852BULL + 0xADB547AA1036C73CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE01320F117735CAFULL + 0xB4284DF8D9D24812ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xCF2AC9E4B519EAEDULL + 0x92425F921FCD71C6ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xB5C68A3EB2851B47ULL + 0xD162BE79BC07D6C7ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x8DF4B94F0677FB35ULL + 0xE7FFAE2CB36CCEC2ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xC614BE0316C0F94DULL + 0xC70D52C891934170ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xC64E71F128CFB459ULL + 0xDFF908F011A4970EULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xB9E50ABD42B18779ULL + 0xF319B6A47378BAAEULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xC9E28978A2FD6E5FULL + 0x96F7B4CA43D858B9ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x959E13D380094BB7ULL + 0xFFBA11E71264440DULL);
    // GSeedRunSeed_G seed_loop_h (start)
    {
        // GSeedRunSeed_G seed_loop_h lane group
        // read from: aSnowLaneA, aSnowLaneB, aInvestLaneB, aSnowLaneC, aSnowLaneD, aFireLaneD, aWorkLaneA, aInvestLaneA, aFireLaneA, aWorkLaneB, aInvestLaneC, aExpandLaneA, aInvestLaneD, aExpandLaneB, aFireLaneC, aExpandLaneC, aFireLaneB
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_h loop 1
        // ingress from: aSnowLaneA, aSnowLaneB, aInvestLaneB
        // ingress directions: aSnowLaneA forward forced, aSnowLaneB forward forced, aInvestLaneB forward/backward random
        // cross from: aSnowLaneC, aSnowLaneD, aFireLaneD
        // cross directions: aSnowLaneC backward forced, aSnowLaneD backward forced, aFireLaneD backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 2215U)) & S_BLOCK1], 26U) ^ RotL64(aSnowLaneB[((aIndex + 5365U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 3193U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 253U)) & S_BLOCK1], 5U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 3355U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 2564U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aIngress, 41U)) ^ (RotL64(aCarry, 5U) + RotL64(aPrevious, 56U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterH = (((aWandererH + RotL64(aPrevious, 53U)) + RotL64(aCarry, 19U)) + 2786079456995203065U) + aNonceWordC;
            aOrbiterB = (aWandererI + RotL64(aCross, 21U)) + 7237256119153857253U;
            aOrbiterJ = (aWandererA + RotL64(aScatter, 28U)) + 9310834010563647604U;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 11U)) + RotL64(aCarry, 5U)) + 17361734905706517877U;
            aOrbiterI = (((aWandererJ + RotL64(aCross, 3U)) + RotL64(aCarry, 53U)) + 15837111231884647451U) + aPhaseHOrbiterAssignSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aIngress, 35U)) + 18065431964418026445U) + aNonceWordM;
            aOrbiterK = (((aWandererC + RotL64(aPrevious, 41U)) + 3029123922999952652U) + aPhaseHOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1]) + aNonceWordL;
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 5166926595573507837U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 1918425684273807598U) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 16616641579714896719U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 4724551751012661440U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 1818014487579644390U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14904092108647864911U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 6670090372241084216U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 8485757110007268693U) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 11876760095108618363U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 4928130251509514742U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 2528788422725346792U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1855982047967756661U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 2860387120895147503U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 12927802338151379368U;
            aOrbiterH = RotL64((aOrbiterH * 8876144125458603029U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 18029699867733207083U) + aNonceWordP;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 13361836994951253312U;
            aOrbiterF = RotL64((aOrbiterF * 5349767426256597073U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 11957294454794128079U) + aNonceWordJ;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 3755417922063414648U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13896364063651241401U), 5U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterI, 13U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 43U));
            aIngress = aIngress + (RotL64(aOrbiterF, 60U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 19U)) + aOrbiterK) + aNonceWordD);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterK, 28U)) + aNonceWordI);
            aWandererF = aWandererF + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 37U)) + aOrbiterJ) + RotL64(aCarry, 47U)) + aPhaseHWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 39U) + aOrbiterF) + RotL64(aOrbiterB, 5U)) + aNonceWordF);
            aWandererH = aWandererH + (((RotL64(aIngress, 53U) + RotL64(aOrbiterI, 43U)) + aOrbiterH) + RotL64(aCarry, 23U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 46U) + aOrbiterC) + RotL64(aOrbiterK, 57U)) + aPhaseHWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterH, 13U)) + aNonceWordA);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 4U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 2
        // ingress from: aWorkLaneA, aSnowLaneC, aSnowLaneD, aInvestLaneA
        // ingress directions: aWorkLaneA forward forced, aSnowLaneC forward forced, aSnowLaneD forward forced, aInvestLaneA forward/backward random
        // cross from: aSnowLaneA, aSnowLaneB, aFireLaneA
        // cross directions: aSnowLaneA backward forced, aSnowLaneB backward forced, aFireLaneA backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 5564U)) & S_BLOCK1], 41U) ^ RotL64(aSnowLaneC[((aIndex + 8812U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 9115U)) & S_BLOCK1], 6U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 5857U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 9650U)) & S_BLOCK1], 39U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 6330U)) & S_BLOCK1], 14U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 10646U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCarry, 20U)) + (RotL64(aCross, 5U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterC = (((aWandererK + RotL64(aCross, 41U)) + RotL64(aCarry, 57U)) + 3236820517816085022U) + aNonceWordH;
            aOrbiterE = (((aWandererA + RotL64(aPrevious, 35U)) + RotL64(aCarry, 41U)) + 741288875914097926U) + aNonceWordG;
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 23U)) + 8417246926007729580U) + aNonceWordJ;
            aOrbiterA = (((aWandererC + RotL64(aIngress, 51U)) + RotL64(aCarry, 21U)) + 9715717805774537170U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aCross, 29U)) + 14360243844821619482U;
            aOrbiterI = (((aWandererD + RotL64(aPrevious, 3U)) + 10760908100206775334U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordC;
            aOrbiterK = (aWandererB + RotL64(aScatter, 14U)) + 3434641779946167811U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 7885568822756234567U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 3041563437672051294U;
            aOrbiterB = RotL64((aOrbiterB * 11440300917533482297U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 15761355327564963516U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 1158633562785937421U;
            aOrbiterE = RotL64((aOrbiterE * 15511324886867188235U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 9338581575871970653U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 9172038894262857354U;
            aOrbiterI = RotL64((aOrbiterI * 3110871165285625807U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 14653924713599790081U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 3854497592598563309U) ^ aNonceWordP;
            aOrbiterA = RotL64((aOrbiterA * 11737111068815795303U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 16286980180327600557U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterE) ^ 5092583772591249756U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterK = RotL64((aOrbiterK * 13955105624639442903U), 47U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterA) + 4288397994175567333U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1]) + aNonceWordA;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 15584236478994873104U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1860480595862755379U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 5557463939827483792U) + aNonceWordF;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 2659814275753280856U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17702430405693184643U), 13U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 53U);
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 60U) + RotL64(aOrbiterI, 21U)) + aOrbiterA) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterB, 57U)) + aNonceWordL);
            aWandererA = aWandererA + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 27U)) + aOrbiterE) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterD, 5U)) + aOrbiterA) + aNonceWordN);
            aWandererK = aWandererK + (((RotL64(aPrevious, 53U) + aOrbiterC) + RotL64(aOrbiterK, 50U)) + aNonceWordB);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterI, 11U)) + aOrbiterD) + aPhaseHWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterE, 35U)) + aOrbiterI) + RotL64(aCarry, 21U)) + aNonceWordO);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 46U));
            aCarry = aCarry + RotL64(aWandererD, 23U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 14100U)) & S_BLOCK1], 52U) ^ RotL64(aSnowLaneA[((aIndex + 13074U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 16124U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12239U)) & S_BLOCK1], 13U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 15636U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aIngress, 53U)) + (RotL64(aCross, 36U) ^ RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterH = (((aWandererF + RotL64(aCross, 43U)) + RotL64(aCarry, 19U)) + 3448371607470865612U) + aPhaseHOrbiterAssignSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = (aWandererE + RotL64(aScatter, 53U)) + 3743742913651580573U;
            aOrbiterF = (aWandererB + RotL64(aIngress, 13U)) + 13069491287948807280U;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 6U)) + 16872779275586545632U;
            aOrbiterG = (((aWandererA + RotL64(aIngress, 35U)) + RotL64(aCarry, 3U)) + 17945792656755062795U) + aNonceWordJ;
            aOrbiterC = (((aWandererH + RotL64(aPrevious, 21U)) + RotL64(aCarry, 39U)) + 18199747196793731853U) + aNonceWordF;
            aOrbiterA = (((aWandererC + RotL64(aScatter, 27U)) + 15953311878379809513U) + aPhaseHOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1]) + aNonceWordI;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 941268763494588338U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 10090221530365796809U;
            aOrbiterF = RotL64((aOrbiterF * 14035236086292997613U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 8335698093307607001U) + aNonceWordH;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 6147498804734306100U;
            aOrbiterK = RotL64((aOrbiterK * 6904444049941211327U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 5980246079567570090U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 4152167624425912978U;
            aOrbiterG = RotL64((aOrbiterG * 10019421651535123573U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 14990418790239735916U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 3418668387496597219U;
            aOrbiterA = RotL64((aOrbiterA * 12814077238529863119U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 4206650904177199425U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 3905470780938996069U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16030122739273137005U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 9968672788233080924U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 602258075661864866U;
            aOrbiterD = RotL64((aOrbiterD * 2615726693066300065U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 17751667243048041383U) + aNonceWordP;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 2414054413585296027U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1049512574773201893U), 57U);
            //
            aIngress = RotL64(aOrbiterD, 13U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + RotL64(aOrbiterG, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 35U)) + aOrbiterH) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 50U) + RotL64(aOrbiterK, 47U)) + aOrbiterG);
            aWandererE = aWandererE + ((((RotL64(aCross, 11U) + aOrbiterC) + RotL64(aOrbiterA, 41U)) + RotL64(aCarry, 53U)) + aNonceWordM);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 35U) + aOrbiterK) + RotL64(aOrbiterD, 28U));
            aWandererB = aWandererB + (((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterC, 21U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterH, 5U)) + aNonceWordA) + aPhaseHWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 53U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 58U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 22U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 4
        // ingress from: aExpandLaneA, aWorkLaneA, aInvestLaneD
        // ingress directions: aExpandLaneA forward forced, aWorkLaneA forward forced, aInvestLaneD forward/backward random
        // cross from: aWorkLaneB, aSnowLaneD
        // cross directions: aWorkLaneB backward forced, aSnowLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 21433U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneA[((aIndex + 18383U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 20689U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21006U)) & S_BLOCK1], 47U) ^ RotL64(aSnowLaneD[((aIndex + 18245U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aPrevious, 5U)) + (RotL64(aIngress, 50U) ^ RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterD = ((aWandererK + RotL64(aScatter, 3U)) + 6243113109470883144U) + aNonceWordE;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 19U)) + 3891552123999605832U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aIngress, 13U)) + 8758797898587019128U) + aNonceWordN;
            aOrbiterF = (((aWandererC + RotL64(aPrevious, 58U)) + RotL64(aCarry, 29U)) + 1005891374086408851U) + aPhaseHOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aCross, 37U)) + RotL64(aCarry, 41U)) + 3713426782180050764U;
            aOrbiterC = (((aWandererF + RotL64(aIngress, 43U)) + RotL64(aCarry, 13U)) + 18358143862391573534U) + aNonceWordC;
            aOrbiterE = (aWandererD + RotL64(aPrevious, 27U)) + 17504394029693712404U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 5312729289027417014U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 2560873623431186029U;
            aOrbiterA = RotL64((aOrbiterA * 16843728573219210173U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 16309322822806704211U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 10195513918020652600U;
            aOrbiterJ = RotL64((aOrbiterJ * 14569219741824123715U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 2552116263258744287U) + aNonceWordG;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 7732784879810980089U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 15041929399477790999U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 16499127570665381507U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 10890036715535519036U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9065115450010475187U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 16288944603478791554U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 14542766121469312846U) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 8435383464425875209U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 5973595239494084696U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 1820492719977197097U;
            aOrbiterC = RotL64((aOrbiterC * 16164917159141304405U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 10489529555776381736U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 6392552206958240484U;
            aOrbiterF = RotL64((aOrbiterF * 11761477994533503307U), 11U);
            //
            aIngress = RotL64(aOrbiterB, 57U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterE, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((((RotL64(aCross, 60U) + aOrbiterD) + RotL64(aOrbiterJ, 43U)) + aNonceWordL) + aPhaseHWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterC, 21U)) + RotL64(aCarry, 21U)) + aNonceWordA);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 30U)) + aOrbiterD);
            aWandererC = aWandererC + (((RotL64(aPrevious, 27U) + aOrbiterB) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 51U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 11U) + aOrbiterF) + RotL64(aOrbiterC, 37U)) + aNonceWordK);
            aWandererH = aWandererH + ((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterD, 53U));
            aWandererB = aWandererB ^ ((((RotL64(aCross, 53U) + aOrbiterJ) + RotL64(aOrbiterB, 13U)) + aNonceWordJ) + aPhaseHWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 18U));
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_h loop 5
        // ingress from: aExpandLaneB, aWorkLaneB, aFireLaneC
        // ingress directions: aExpandLaneB forward forced, aWorkLaneB forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aWorkLaneA
        // cross directions: aExpandLaneA backward forced, aWorkLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 26785U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((aIndex + 26818U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 26714U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24527U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27155U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 20U) + RotL64(aCross, 57U)) ^ (RotL64(aCarry, 5U) ^ RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterB = (aWandererD + RotL64(aIngress, 37U)) + 10726035965553989335U;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 3U)) + 967354339530195662U) + aNonceWordB;
            aOrbiterI = ((((aWandererB + RotL64(aScatter, 47U)) + RotL64(aCarry, 23U)) + 10834593005478605624U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordP;
            aOrbiterF = ((aWandererA + RotL64(aCross, 28U)) + RotL64(aCarry, 53U)) + 1012888282838656933U;
            aOrbiterK = (aWandererF + RotL64(aIngress, 21U)) + 15283530351725183253U;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 53U)) + 11724495956731703750U) + aNonceWordI;
            aOrbiterC = (((aWandererH + RotL64(aPrevious, 13U)) + RotL64(aCarry, 35U)) + 4288330117317505776U) + aPhaseHOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 10894778070022873473U) + aNonceWordC;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 15563886747621617467U) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 17884709931569040065U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 11182488628562891937U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 10420140066310588580U;
            aOrbiterK = RotL64((aOrbiterK * 13898299782819948719U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 11775138062167543111U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 16545391898578161683U;
            aOrbiterB = RotL64((aOrbiterB * 14588306527161321535U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 1550144656312299266U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 14903504853138279883U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8003033561266164387U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 309935535526750396U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 13991265868040011411U;
            aOrbiterF = RotL64((aOrbiterF * 2887531132228588441U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 1755976294857114222U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 2259275858478396846U;
            aOrbiterC = RotL64((aOrbiterC * 7416165760067878161U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 4838175912944552936U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 12307900457200936013U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14719363144850838805U), 37U);
            //
            aIngress = RotL64(aOrbiterF, 47U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aIngress, 53U) + aOrbiterF) + RotL64(aOrbiterJ, 19U)) + RotL64(aCarry, 47U)) + aPhaseHWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 39U) + aOrbiterF) + RotL64(aOrbiterC, 51U)) + aNonceWordE);
            aWandererF = aWandererF + (((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterC, 13U)) + aNonceWordM);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterC, 29U)) + aOrbiterK) + aNonceWordK);
            aWandererK = aWandererK + (((RotL64(aIngress, 6U) + RotL64(aOrbiterC, 3U)) + aOrbiterB) + aNonceWordA);
            aWandererB = aWandererB ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterF, 37U)) + aOrbiterA);
            aWandererA = aWandererA + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterA, 44U)) + aOrbiterK) + RotL64(aCarry, 11U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 38U));
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 5U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneB
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneB, aSnowLaneB
        // cross directions: aExpandLaneB backward forced, aSnowLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 32627U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((aIndex + 28156U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 29499U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30702U)) & S_BLOCK1], 53U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 32200U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aPrevious, 4U)) + (RotL64(aIngress, 47U) ^ RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterG = ((aWandererB + RotL64(aCross, 23U)) + RotL64(aCarry, 43U)) + 4384716820085860551U;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 51U)) + 9715780315942116888U) + aNonceWordG;
            aOrbiterF = (((aWandererK + RotL64(aIngress, 5U)) + RotL64(aCarry, 27U)) + 15963520052789178632U) + aNonceWordB;
            aOrbiterE = (aWandererE + RotL64(aPrevious, 43U)) + 14346700690686392938U;
            aOrbiterI = (((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 57U)) + 6005518012489966643U) + aPhaseHOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aIngress, 30U)) + 2506732930310252119U;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 13U)) + 16782163084851775826U) + aPhaseHOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 823673076571076303U) + aNonceWordC;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 1634084509064077736U;
            aOrbiterF = RotL64((aOrbiterF * 1128407326773234517U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 1288134975466877686U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 2998220403162908444U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4321412662318298283U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 220430672180734911U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 10223923547068528867U;
            aOrbiterG = RotL64((aOrbiterG * 12577370238343872139U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 11696469696177647608U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 6545430420379636963U;
            aOrbiterC = RotL64((aOrbiterC * 8387163146257553773U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 79691451831797107U) + aNonceWordP;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 8971444023498649419U) ^ aNonceWordA;
            aOrbiterH = RotL64((aOrbiterH * 7148919880477390009U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 5624403902454498793U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 9468064161002030997U;
            aOrbiterJ = RotL64((aOrbiterJ * 8243560528100864595U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 4619361544913629805U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 12682446273369750704U;
            aOrbiterE = RotL64((aOrbiterE * 10879074713156075641U), 29U);
            //
            aIngress = RotL64(aOrbiterI, 3U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + RotL64(aOrbiterG, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterE, 37U)) + aOrbiterH);
            aWandererA = aWandererA + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 60U)) + aOrbiterI) + RotL64(aCarry, 51U)) + aNonceWordK);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 5U) + aOrbiterF) + RotL64(aOrbiterH, 13U)) + aNonceWordH);
            aWandererF = aWandererF + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 5U)) + aOrbiterI) + RotL64(aCarry, 13U));
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterE, 27U)) + aNonceWordN) + aPhaseHWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 22U) + RotL64(aOrbiterG, 21U)) + aOrbiterC) + aNonceWordO);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterG, 43U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 42U));
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE;
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
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF;
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 66U)) & W_KEY1], 60U) ^ RotL64(aKeyRowReadB[((aIndex + 710U)) & W_KEY1], 47U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 1521U)) & W_KEY1], 24U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 2226U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 47U) ^ RotL64(aPrevious, 22U)) + (RotL64(aIngress, 35U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (aWandererD + RotL64(aIngress, 43U)) + 16160838483846078448U;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 47U)) + RotL64(aCarry, 23U)) + 15404960896190227946U;
            aOrbiterK = (((aWandererB + RotL64(aPrevious, 12U)) + RotL64(aCarry, 37U)) + 16904160594024977199U) + aPhaseAOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = (aWandererC + RotL64(aCross, 51U)) + 17790460246821031802U;
            aOrbiterD = (aWandererA + RotL64(aScatter, 35U)) + 16395168254086971959U;
            aOrbiterB = (aWandererG + RotL64(aIngress, 39U)) + 7484373204039901786U;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 56U)) + 18026814691322913510U) + aPhaseAOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aCross, 3U)) + RotL64(aCarry, 57U)) + 15244817793136966450U;
            aOrbiterI = (aWandererI + RotL64(aScatter, 27U)) + 5795491730356335666U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 3163873518027801504U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 2690791759507349172U;
            aOrbiterK = RotL64((aOrbiterK * 16677948635136515083U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 17898067251167087906U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 8028010015006604239U;
            aOrbiterC = RotL64((aOrbiterC * 5601629670521300241U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 7304739457289910555U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 6476837815096530043U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16380545138701113267U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 14242499233467960602U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 17305645693017634630U;
            aOrbiterA = RotL64((aOrbiterA * 14442976693206929569U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 9772864059444171908U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 7897200728282156408U;
            aOrbiterH = RotL64((aOrbiterH * 816306719390807411U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 4890999319172950996U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 8165132649356094963U;
            aOrbiterI = RotL64((aOrbiterI * 17297706071263690189U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 9342923520083533265U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 7213639583505088067U;
            aOrbiterD = RotL64((aOrbiterD * 1349251979649428909U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 4079475132684197272U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 3350998022472827283U;
            aOrbiterG = RotL64((aOrbiterG * 948841791460066265U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 2479140576609216238U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 7703147534931674972U;
            aOrbiterB = RotL64((aOrbiterB * 11419116495223970801U), 11U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterB, 43U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 60U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 23U) + aOrbiterG) + RotL64(aOrbiterD, 53U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 58U) + RotL64(aOrbiterH, 41U)) + aOrbiterB) + RotL64(aCarry, 43U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 35U) + aOrbiterG) + RotL64(aOrbiterE, 34U));
            aWandererD = aWandererD + (((RotL64(aCross, 27U) + RotL64(aOrbiterK, 57U)) + aOrbiterI) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 21U)) + aOrbiterK);
            aWandererC = aWandererC + (((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterG, 5U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterB, 29U));
            aWandererG = aWandererG + ((RotL64(aCross, 42U) + aOrbiterH) + RotL64(aOrbiterA, 12U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterD, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 30U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 4U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 4217U)) & S_BLOCK1], 44U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 3049U)) & W_KEY1], 23U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 3605U)) & W_KEY1], 3U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 4188U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCross, 39U)) + (RotL64(aIngress, 20U) ^ RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 58U)) + 3561491146322798260U;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 51U)) + 7075025056181885339U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aIngress, 3U)) + RotL64(aCarry, 19U)) + 9230910887904171613U;
            aOrbiterA = (aWandererJ + RotL64(aCross, 19U)) + 4119781172609908917U;
            aOrbiterE = (aWandererE + RotL64(aPrevious, 23U)) + 17155609083870983149U;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 13U)) + 2423018561430181695U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = ((aWandererG + RotL64(aScatter, 37U)) + RotL64(aCarry, 37U)) + 12957280305617615744U;
            aOrbiterB = ((aWandererD + RotL64(aCross, 27U)) + RotL64(aCarry, 53U)) + 2461704174772065813U;
            aOrbiterC = (aWandererA + RotL64(aIngress, 46U)) + 7907123257849391997U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 7257868138318960007U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 16425903703085702285U;
            aOrbiterG = RotL64((aOrbiterG * 7996935869077231999U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 2990822664594079467U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 5654819006718953817U;
            aOrbiterE = RotL64((aOrbiterE * 4465096036756887801U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 12183676471235678779U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 15026286960542123922U;
            aOrbiterA = RotL64((aOrbiterA * 17199049329995315279U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 12169080607071830522U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 2906296852254787499U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6754514406846040163U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 3029858695410344584U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 14406410317495954566U;
            aOrbiterI = RotL64((aOrbiterI * 9663780721657983421U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 11048818178401163861U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 13622063920319445043U;
            aOrbiterD = RotL64((aOrbiterD * 2516025554421589857U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 2642646089141233277U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 12761571777929273548U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5518252696078700127U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 7753802695131502382U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 8510425459525030222U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12412361423636026483U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 13522645164493316722U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 1437430302489702713U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14019316635365783545U), 35U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 19U);
            aIngress = aIngress + (RotL64(aOrbiterC, 46U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + RotL64(aOrbiterH, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterD, 57U));
            aWandererC = aWandererC + ((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterE, 3U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterC, 23U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 28U) + aOrbiterI) + RotL64(aOrbiterG, 48U)) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 13U) + aOrbiterG) + RotL64(aOrbiterA, 35U));
            aWandererK = aWandererK + (((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 53U)) + aOrbiterH) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterE, 29U)) + aOrbiterI) + aPhaseAWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterC, 10U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 18U) + RotL64(aOrbiterE, 19U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (RotL64(aWandererK, 14U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 8041U)) & S_BLOCK1], 4U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 6010U)) & W_KEY1], 13U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 5971U)) & W_KEY1], 6U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6373U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 6072U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCross, 50U)) + (RotL64(aCarry, 35U) ^ RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 35U)) + RotL64(aCarry, 57U)) + 9654059367478508868U;
            aOrbiterC = ((aWandererG + RotL64(aCross, 19U)) + 6473006635864677427U) + aPhaseAOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 50U)) + 6944184481315853243U;
            aOrbiterH = (aWandererH + RotL64(aScatter, 23U)) + 4061496421939102306U;
            aOrbiterE = ((aWandererK + RotL64(aCross, 13U)) + RotL64(aCarry, 41U)) + 15791809275719085463U;
            aOrbiterK = (aWandererA + RotL64(aPrevious, 57U)) + 14050798802646323055U;
            aOrbiterA = (((aWandererE + RotL64(aIngress, 41U)) + RotL64(aCarry, 19U)) + 12072905924741758266U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aScatter, 3U)) + 17639076509231343896U;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 30U)) + 12195388285571234715U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 4325404419499496529U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 5910567888204238382U;
            aOrbiterJ = RotL64((aOrbiterJ * 11503787177122206937U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 13092940059929942699U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 13381962590820308761U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6345904465930943295U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 15622862439323440527U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 14027151901132249793U;
            aOrbiterG = RotL64((aOrbiterG * 2273573821630510087U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 4584410023907605157U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 15763755180625487157U;
            aOrbiterE = RotL64((aOrbiterE * 6755736130607297639U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 17023059745666559199U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 5298529579288492971U;
            aOrbiterC = RotL64((aOrbiterC * 2483562793328357721U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 2870152867331654736U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 12017191100173748848U;
            aOrbiterF = RotL64((aOrbiterF * 9958191466506480519U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 15899529176182436062U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 16482713846343388735U;
            aOrbiterH = RotL64((aOrbiterH * 719465695044265601U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 12943393531812774449U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 9881108254540483225U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8011108108007885059U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 3532054586199716750U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 7142230313294797435U;
            aOrbiterA = RotL64((aOrbiterA * 14154176174768868421U), 19U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterE, 43U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 30U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterC, 37U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + RotL64(aOrbiterH, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aPrevious, 23U) + aOrbiterG) + RotL64(aOrbiterC, 4U)) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 6U) + aOrbiterH) + RotL64(aOrbiterK, 51U));
            aWandererC = aWandererC + (((RotL64(aScatter, 11U) + RotL64(aOrbiterH, 11U)) + aOrbiterE) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterC, 39U)) + aOrbiterF);
            aWandererE = aWandererE + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterG, 57U)) + aOrbiterA);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 34U)) + aOrbiterJ);
            aWandererH = aWandererH + (((RotL64(aCross, 58U) + RotL64(aOrbiterC, 43U)) + aOrbiterD) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterE, 21U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 43U) + RotL64(aOrbiterF, 47U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 6U));
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 10646U)) & S_BLOCK1], 39U) ^ RotL64(aKeyRowReadB[((aIndex + 9341U)) & W_KEY1], 27U));
            aIngress ^= (RotL64(mSource[((aIndex + 8505U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneA[((aIndex + 8950U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 9835U)) & W_KEY1], 5U) ^ RotL64(aWorkLaneB[((aIndex + 10842U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aIngress, 6U)) ^ (RotL64(aCarry, 27U) + RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = (aWandererC + RotL64(aPrevious, 34U)) + 4068921616130916949U;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 11U)) + RotL64(aCarry, 27U)) + 12077715273915151726U;
            aOrbiterD = (((aWandererK + RotL64(aCross, 51U)) + RotL64(aCarry, 3U)) + 16047546802670596833U) + aPhaseBOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aIngress, 27U)) + RotL64(aCarry, 37U)) + 9690277462716999763U;
            aOrbiterC = (aWandererE + RotL64(aCross, 18U)) + 14484814700447992628U;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 47U)) + 17089267243053958210U) + aPhaseBOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aIngress, 43U)) + 9138746214446211147U;
            aOrbiterB = (aWandererA + RotL64(aScatter, 57U)) + 10181001536979097045U;
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 23U)) + 6657458969093373191U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 7515983477876590988U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 3039935555863947600U;
            aOrbiterD = RotL64((aOrbiterD * 12511160550780270119U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 16209389224740851136U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 725253312098083182U;
            aOrbiterC = RotL64((aOrbiterC * 17535989492095522597U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 13307041115748941383U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 7159572004825238263U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4855009895002398449U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 12027236743251643820U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 8717826175991286553U;
            aOrbiterF = RotL64((aOrbiterF * 1175614802543098451U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 4769096034227659937U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 11201226563992939616U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15595355978388159931U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 17295978531215563256U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 11850923890626719833U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3854851059897397075U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 14139441565288097706U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 988684899382304485U;
            aOrbiterE = RotL64((aOrbiterE * 11929090869999700891U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 6159251276942253175U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 4849529993914550651U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 18240712676783671317U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 6679745455842119497U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 15838404437552215214U;
            aOrbiterB = RotL64((aOrbiterB * 17357853511591350887U), 13U);
            //
            aIngress = RotL64(aOrbiterG, 43U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 20U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 6U) + RotL64(aOrbiterH, 47U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 53U) + aOrbiterH) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 23U)) + aPhaseBWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 23U) + aOrbiterB) + RotL64(aOrbiterC, 51U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterC, 20U)) + aOrbiterD);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterF, 11U)) + aPhaseBWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 48U) + aOrbiterA) + RotL64(aOrbiterB, 41U)) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 57U)) + aOrbiterH);
            aWandererC = aWandererC + ((RotL64(aCross, 57U) + RotL64(aOrbiterG, 29U)) + aOrbiterC);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterG, 34U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 38U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 12516U)) & S_BLOCK1], 47U) ^ RotL64(aKeyRowReadA[((aIndex + 11759U)) & W_KEY1], 29U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 12864U)) & W_KEY1], 57U) ^ RotL64(mSource[((aIndex + 12145U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 11281U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13423U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 12940U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCarry, 5U)) ^ (RotL64(aPrevious, 34U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = ((aWandererH + RotL64(aCross, 5U)) + RotL64(aCarry, 11U)) + 17454559218352016650U;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 58U)) + 8005709669325164803U;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 19U)) + RotL64(aCarry, 37U)) + 13393741948412816357U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 13U)) + RotL64(aCarry, 23U)) + 3665865624348875553U;
            aOrbiterD = (aWandererA + RotL64(aCross, 39U)) + 8334142570031883436U;
            aOrbiterC = (aWandererC + RotL64(aIngress, 43U)) + 17226066128706139657U;
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 35U)) + 3319093033121522613U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = (aWandererB + RotL64(aPrevious, 30U)) + 6657535603401588798U;
            aOrbiterH = ((aWandererK + RotL64(aCross, 53U)) + 5469746182326331147U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 17846791786050221418U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 15939541003714896288U;
            aOrbiterG = RotL64((aOrbiterG * 1400351482213119809U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 12076763190461077406U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 3594038213596405284U;
            aOrbiterC = RotL64((aOrbiterC * 10244002692575821495U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 8301291631324464622U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 8460406137668390582U;
            aOrbiterJ = RotL64((aOrbiterJ * 9117147929757711595U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 7612394867020871200U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 8525076134853103975U;
            aOrbiterI = RotL64((aOrbiterI * 5790440201072204659U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 11929899088215090379U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 7119509166360685726U;
            aOrbiterK = RotL64((aOrbiterK * 1662341427992528823U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 5081078459225240607U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 17149991983909906705U;
            aOrbiterH = RotL64((aOrbiterH * 950223374568067343U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 8817303295675241994U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 7962039282652745113U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12773588587795522121U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 13596273086338032370U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 8186297702278180956U;
            aOrbiterE = RotL64((aOrbiterE * 6226504769888753861U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 1696277861691580263U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 17360461831507082959U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1651378456022210983U), 29U);
            //
            aIngress = RotL64(aOrbiterK, 11U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + RotL64(aOrbiterD, 60U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 43U) + aOrbiterH) + RotL64(aOrbiterJ, 50U)) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 36U) + RotL64(aOrbiterG, 5U)) + aOrbiterJ);
            aWandererG = aWandererG + ((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 57U)) + aOrbiterB);
            aWandererC = aWandererC ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterE, 43U)) + aOrbiterH);
            aWandererK = aWandererK + (((RotL64(aIngress, 19U) + aOrbiterC) + RotL64(aOrbiterJ, 13U)) + aPhaseBWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterG, 27U)) + aOrbiterD);
            aWandererA = aWandererA + (((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 19U)) + aOrbiterK) + RotL64(aCarry, 37U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterD, 39U)) + aOrbiterB);
            aWandererH = aWandererH + (((RotL64(aScatter, 28U) + RotL64(aOrbiterI, 34U)) + aOrbiterE) + aPhaseBWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 24U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 14U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 14540U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 15502U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15399U)) & W_KEY1], 3U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 16284U)) & W_KEY1], 11U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 14191U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 14106U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14924U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCarry, 3U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCross, 18U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (aWandererB + RotL64(aPrevious, 30U)) + 3339283916456813609U;
            aOrbiterK = (aWandererA + RotL64(aScatter, 19U)) + 11339086426180649584U;
            aOrbiterE = (aWandererE + RotL64(aCross, 37U)) + 16819191669329316585U;
            aOrbiterH = (((aWandererI + RotL64(aIngress, 47U)) + RotL64(aCarry, 29U)) + 8361916937762630725U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aScatter, 57U)) + RotL64(aCarry, 43U)) + 18031328374429899857U;
            aOrbiterC = (((aWandererJ + RotL64(aPrevious, 14U)) + RotL64(aCarry, 19U)) + 18261756894092897276U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aIngress, 43U)) + 4250319792907645666U;
            aOrbiterI = (aWandererF + RotL64(aCross, 5U)) + 1492411503643460886U;
            aOrbiterA = (aWandererG + RotL64(aIngress, 51U)) + 17369549067879344180U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 7301713524358676722U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 2985193736033012535U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7473297294949338265U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 14086975808140927408U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 10390516547834639800U;
            aOrbiterC = RotL64((aOrbiterC * 11441293212275890819U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 18205555540941493267U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 16967799565443938873U;
            aOrbiterK = RotL64((aOrbiterK * 3009081009044782443U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 9209505304067579944U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 3522631966146762306U;
            aOrbiterG = RotL64((aOrbiterG * 3441982898533162599U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 8811497120829041188U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 14707301680850257294U;
            aOrbiterB = RotL64((aOrbiterB * 11383709499376464085U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 10080595991787801029U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 6822892187784299166U;
            aOrbiterD = RotL64((aOrbiterD * 7417016898027778287U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 1981637172055758689U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 16463077485583119324U;
            aOrbiterH = RotL64((aOrbiterH * 2876782050665869121U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 8383837717361569465U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 2788511294985017326U;
            aOrbiterI = RotL64((aOrbiterI * 2809163242875130677U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 3529607472855930041U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 8850940802020173766U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7821450253655655943U), 3U);
            //
            aIngress = RotL64(aOrbiterK, 37U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterI, 30U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + RotL64(aOrbiterG, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aIngress, 18U) + aOrbiterH) + RotL64(aOrbiterG, 53U)) + aPhaseBWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterH, 39U)) + aOrbiterD);
            aWandererF = aWandererF + ((RotL64(aScatter, 41U) + RotL64(aOrbiterA, 48U)) + aOrbiterK);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 13U)) + aOrbiterI);
            aWandererC = aWandererC + ((RotL64(aIngress, 27U) + RotL64(aOrbiterG, 29U)) + aOrbiterI);
            aWandererG = aWandererG ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterG, 43U)) + aOrbiterC) + aPhaseBWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 3U) + aOrbiterE) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterD, 3U));
            aWandererK = aWandererK + (((RotL64(aIngress, 58U) + RotL64(aOrbiterE, 20U)) + aOrbiterB) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 26U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 23U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 17836U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadA[((aIndex + 18926U)) & W_KEY1], 23U));
            aIngress ^= (RotL64(mSource[((aIndex + 19038U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 17685U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 17403U)) & W_KEY1], 56U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 17638U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 18696U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 47U)) + (RotL64(aCross, 60U) + RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (aWandererE + RotL64(aCross, 19U)) + 17668251151213543491U;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 29U)) + 16101602509895104517U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aIngress, 5U)) + 9083915270773304935U;
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 13U)) + 12810720730318214811U;
            aOrbiterK = (aWandererI + RotL64(aScatter, 34U)) + 18113428002071925621U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 23U)) + RotL64(aCarry, 57U)) + 1582208899354109878U;
            aOrbiterH = ((aWandererD + RotL64(aCross, 41U)) + 4180688104819188154U) + aPhaseCOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 51U)) + RotL64(aCarry, 41U)) + 8954598189262820611U;
            aOrbiterE = ((aWandererB + RotL64(aCross, 60U)) + RotL64(aCarry, 27U)) + 15360094153175355879U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 8383954114668216260U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 15626783326234049197U;
            aOrbiterJ = RotL64((aOrbiterJ * 15058420415480073793U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 10609978564404958066U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 17656516608997517984U;
            aOrbiterK = RotL64((aOrbiterK * 4590620354119899777U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 760077259110786536U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 3597338735888033063U;
            aOrbiterD = RotL64((aOrbiterD * 6548831472863517621U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 4431777844935985157U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 10710423172154671296U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16267496318491473315U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 10240882795242085185U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 7826053487019825891U;
            aOrbiterG = RotL64((aOrbiterG * 15053729937684375907U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 9418883403715727353U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 11507423614799075545U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16189463984557044693U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 11545217316421066655U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 617921402135485341U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8182920764965471653U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 14456933220749921009U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 7990243583564535387U;
            aOrbiterE = RotL64((aOrbiterE * 5994900368027985469U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 14023633125757654751U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 11319146808574958827U;
            aOrbiterH = RotL64((aOrbiterH * 13676159969338309307U), 3U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterE, 57U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + (RotL64(aOrbiterA, 14U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterG, 21U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aCross, 52U) + RotL64(aOrbiterA, 57U)) + aOrbiterE);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 39U) + aOrbiterB) + RotL64(aOrbiterI, 13U));
            aWandererF = aWandererF + (((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterH, 51U)) + aPhaseCWandererUpdateSaltF[((aIndex + 28U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterG, 18U)) + aOrbiterD);
            aWandererB = aWandererB + ((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterA, 41U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 19U) + aOrbiterB) + RotL64(aOrbiterK, 5U)) + aPhaseCWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 34U) + aOrbiterK) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterD, 37U)) + aOrbiterJ);
            aWandererA = aWandererA + (((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 24U)) + aOrbiterB) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 6U));
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 21797U)) & S_BLOCK1], 21U) ^ RotL64(mSource[((aIndex + 20772U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 19780U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneA[((aIndex + 20597U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 19156U)) & W_KEY1], 19U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 19897U)) & W_KEY1], 30U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21093U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((aIndex + 19767U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 19U)) + (RotL64(aCarry, 57U) ^ RotL64(aIngress, 36U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = ((aWandererI + RotL64(aCross, 58U)) + RotL64(aCarry, 23U)) + 12206125048349568300U;
            aOrbiterG = (aWandererB + RotL64(aScatter, 43U)) + 5843520589343188818U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 19U)) + RotL64(aCarry, 37U)) + 12195046124287121687U;
            aOrbiterF = (aWandererC + RotL64(aPrevious, 27U)) + 16769779119214020640U;
            aOrbiterE = (aWandererD + RotL64(aCross, 37U)) + 5257603646260695833U;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 4U)) + 8523523946234886745U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 13U)) + 7316024684200084096U;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 23U)) + 11996978575084115207U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 53U)) + RotL64(aCarry, 53U)) + 15491711479085513628U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 6036648530996821484U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 926323222234121863U;
            aOrbiterA = RotL64((aOrbiterA * 6639661141258803779U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 2700323841295743492U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 5852273765810284935U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16665696735016345215U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 11697397483133538067U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 17777142964957007194U;
            aOrbiterF = RotL64((aOrbiterF * 6338967222543284999U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 10892176201151170298U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 11759700374509499684U;
            aOrbiterE = RotL64((aOrbiterE * 14247697264744736081U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 11343756773329590643U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 15785048929757652350U;
            aOrbiterJ = RotL64((aOrbiterJ * 17208103574389502597U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 7508839228498497238U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 13088508510402094665U;
            aOrbiterC = RotL64((aOrbiterC * 15730279447009669103U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 16259236641717377699U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 11228995722951003980U;
            aOrbiterK = RotL64((aOrbiterK * 4870092259515181323U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 13775851561528617086U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 3023564646900497080U;
            aOrbiterG = RotL64((aOrbiterG * 9936548213275464131U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 154952467284609583U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 14239675888632174461U;
            aOrbiterI = RotL64((aOrbiterI * 1370550680736926425U), 29U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 19U);
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 24U));
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterC, 51U));
            aWandererH = aWandererH + (((RotL64(aCross, 56U) + aOrbiterI) + RotL64(aOrbiterJ, 41U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 13U) + aOrbiterB) + RotL64(aOrbiterK, 29U));
            aWandererD = aWandererD + (((RotL64(aIngress, 37U) + aOrbiterK) + RotL64(aOrbiterE, 58U)) + RotL64(aCarry, 39U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterC, 5U));
            aWandererI = aWandererI + (((RotL64(aScatter, 23U) + aOrbiterA) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterF, 47U)) + aOrbiterE) + aPhaseCWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterC, 34U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 4U) + aOrbiterG) + RotL64(aOrbiterF, 23U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 44U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererK, 35U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 22553U)) & S_BLOCK1], 35U) ^ RotL64(aKeyRowReadA[((aIndex + 23505U)) & W_KEY1], 12U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 24037U)) & W_KEY1], 3U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 23005U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 23631U)) & S_BLOCK1], 20U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 24390U)) & S_BLOCK1], 11U));
            aCross ^= (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 24424U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 23513U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 18U) + RotL64(aCross, 53U)) ^ (RotL64(aIngress, 39U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = ((aWandererK + RotL64(aScatter, 26U)) + 13296600294247799698U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 37U)) + RotL64(aCarry, 21U)) + 5818503518080877515U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 47U)) + 6735784238734173597U;
            aOrbiterF = (aWandererB + RotL64(aCross, 5U)) + 7368398209488856201U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 51U)) + 961734029066455638U) + aPhaseCOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aPrevious, 11U)) + 797011946660892011U;
            aOrbiterI = ((aWandererE + RotL64(aCross, 60U)) + RotL64(aCarry, 5U)) + 12841876018396622350U;
            aOrbiterC = (aWandererG + RotL64(aIngress, 19U)) + 16213253970483895623U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 43U)) + RotL64(aCarry, 35U)) + 15186950557113470375U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 5117930310827477341U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 12265429373166094162U;
            aOrbiterG = RotL64((aOrbiterG * 1522823535151532249U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 13920531346698601568U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 14695405206998211456U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13950964363414164279U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 7851960904825938443U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 9501511171732550190U;
            aOrbiterB = RotL64((aOrbiterB * 5614164120361489613U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 5663365182245722077U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 9607860124321315555U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3461820361914280601U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 18171052650586819280U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 3442698321538580861U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6317525514963824829U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 1491052813469258970U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 3956599824067616133U;
            aOrbiterI = RotL64((aOrbiterI * 2928600779267623085U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 10963841237346073453U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 2303020125591252534U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9969099842343321981U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 14503856057958162356U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 11147548150090597694U;
            aOrbiterK = RotL64((aOrbiterK * 11856382308792700441U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 9191681438318311481U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 13556072770381999852U;
            aOrbiterF = RotL64((aOrbiterF * 18316231099054203683U), 23U);
            //
            aIngress = RotL64(aOrbiterI, 53U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterC, 56U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + RotL64(aOrbiterG, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aIngress, 23U) + aOrbiterB) + RotL64(aOrbiterI, 3U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 14U)) + aOrbiterG);
            aWandererC = aWandererC + ((RotL64(aCross, 41U) + aOrbiterD) + RotL64(aOrbiterB, 57U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 28U) + aOrbiterB) + RotL64(aOrbiterJ, 19U)) + aPhaseCWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterE, 43U)) + RotL64(aCarry, 57U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 37U) + aOrbiterD) + RotL64(aOrbiterK, 47U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterC, 51U)) + aOrbiterD) + RotL64(aCarry, 37U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 48U) + aOrbiterK) + RotL64(aOrbiterJ, 27U));
            aWandererK = aWandererK + (((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterE, 38U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 48U));
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + RotL64(aWandererK, 53U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 25326U)) & S_BLOCK1], 23U) ^ RotL64(aKeyRowReadA[((aIndex + 26591U)) & W_KEY1], 42U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 24766U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 26246U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 26850U)) & W_KEY1], 23U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 25899U)) & S_BLOCK1], 34U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 25925U)) & S_BLOCK1], 43U) ^ RotL64(aInvestLaneB[((aIndex + 26119U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aPrevious, 23U)) ^ (RotL64(aCross, 37U) + RotL64(aIngress, 4U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = (aWandererD + RotL64(aCross, 53U)) + 1557680213571812384U;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 30U)) + 7387349725778021121U;
            aOrbiterE = ((aWandererH + RotL64(aScatter, 11U)) + RotL64(aCarry, 35U)) + 15379264067601586976U;
            aOrbiterI = ((aWandererA + RotL64(aIngress, 3U)) + 3730195724576043708U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 41U)) + RotL64(aCarry, 23U)) + 9637070085323827066U;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 57U)) + 1170865717363676184U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = (aWandererG + RotL64(aCross, 26U)) + 2750833653175252030U;
            aOrbiterF = (aWandererI + RotL64(aScatter, 19U)) + 15118992811225568305U;
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 35U)) + RotL64(aCarry, 13U)) + 4974092922102988451U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 10625719096296719514U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 855167122475471865U;
            aOrbiterE = RotL64((aOrbiterE * 7441090331293158773U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 11322911068958340262U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 4334591909425429835U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10059025861172038183U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 14263701737208936392U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 678723206735649084U;
            aOrbiterC = RotL64((aOrbiterC * 10823239851733632227U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 15652053114252065230U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 1705225940224061401U;
            aOrbiterF = RotL64((aOrbiterF * 3626023093533713579U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 6826394665732900206U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 11902946775066981141U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 18300629262162694137U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 9802212958998591310U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 14001358545610206524U;
            aOrbiterG = RotL64((aOrbiterG * 13172645840788327099U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 4299184726135884309U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 7288757011999872416U;
            aOrbiterI = RotL64((aOrbiterI * 16806027820468277393U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 233801262480580205U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 14208660347238680268U;
            aOrbiterD = RotL64((aOrbiterD * 6299693448313154603U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 9217797359740446104U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 18165073197136050838U;
            aOrbiterB = RotL64((aOrbiterB * 11677479094709512887U), 19U);
            //
            aIngress = RotL64(aOrbiterG, 29U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterF, 6U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 23U) + RotL64(aOrbiterJ, 27U)) + aOrbiterB) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 29U) + aOrbiterE) + RotL64(aOrbiterG, 20U));
            aWandererA = aWandererA + ((RotL64(aCross, 42U) + RotL64(aOrbiterH, 5U)) + aOrbiterF);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 47U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((RotL64(aCross, 57U) + aOrbiterE) + RotL64(aOrbiterF, 37U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterC, 60U)) + aOrbiterE);
            aWandererK = aWandererK + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterI, 41U)) + aOrbiterB) + RotL64(aCarry, 47U)) + aPhaseDWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 37U) + aOrbiterC) + RotL64(aOrbiterI, 53U));
            aWandererI = aWandererI + (((RotL64(aCross, 52U) + RotL64(aOrbiterJ, 13U)) + aOrbiterD) + aPhaseDWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (RotL64(aWandererJ, 18U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + RotL64(aWandererA, 53U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 28335U)) & S_BLOCK1], 37U) ^ RotL64(aFireLaneD[((aIndex + 29634U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 28285U)) & W_KEY1], 53U) ^ RotL64(aFireLaneC[((aIndex + 29122U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 29585U)) & W_KEY1], 21U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28928U)) & S_BLOCK1], 35U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29654U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneB[((aIndex + 27626U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 29U) ^ RotL64(aIngress, 56U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = ((aWandererD + RotL64(aIngress, 19U)) + RotL64(aCarry, 41U)) + 11480359716598965890U;
            aOrbiterA = (aWandererB + RotL64(aCross, 52U)) + 15431182525482873419U;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 27U)) + 11360504974812776707U;
            aOrbiterG = (aWandererG + RotL64(aScatter, 41U)) + 9292576416573382769U;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 23U)) + 1549257414531028975U) + aPhaseDOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = (((aWandererF + RotL64(aScatter, 48U)) + RotL64(aCarry, 19U)) + 5347769463033129317U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (aWandererE + RotL64(aCross, 57U)) + 17019199177478377234U;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 3U)) + RotL64(aCarry, 53U)) + 16558106007323125094U;
            aOrbiterD = (aWandererI + RotL64(aCross, 11U)) + 3976182233825939422U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 2889047161195954395U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 2241831345026962605U;
            aOrbiterJ = RotL64((aOrbiterJ * 5757458560979927857U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 12850802412140579294U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 13541744735436450160U;
            aOrbiterI = RotL64((aOrbiterI * 906089290000537439U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 2085863085516538212U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 2969034221711544086U;
            aOrbiterH = RotL64((aOrbiterH * 7768528124408400403U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 6482666944512391472U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 16969153556875844613U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9483462388353216219U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 5161314086757363678U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 7150282484670673211U;
            aOrbiterD = RotL64((aOrbiterD * 8522427002337918663U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 5465304381272305847U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 2344610773390354017U;
            aOrbiterC = RotL64((aOrbiterC * 17010258514288089191U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 8335906578006588582U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 13668796013474193793U;
            aOrbiterG = RotL64((aOrbiterG * 8228000547141147777U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 9663362594301419686U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 3683773739120343413U;
            aOrbiterA = RotL64((aOrbiterA * 8319320803406104749U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2538583190438044942U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 4454069062219406996U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16329554225309389599U), 53U);
            //
            aIngress = RotL64(aOrbiterG, 57U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 60U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterI, 12U)) + aOrbiterG);
            aWandererC = aWandererC + ((RotL64(aCross, 39U) + aOrbiterA) + RotL64(aOrbiterE, 47U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 5U) + aOrbiterH) + RotL64(aOrbiterA, 21U)) + aPhaseDWandererUpdateSaltF[((aIndex + 10U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 52U) + aOrbiterH) + RotL64(aOrbiterF, 43U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 29U)) + aOrbiterF);
            aWandererA = aWandererA + (((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 37U)) + aOrbiterD) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 43U) + aOrbiterD) + RotL64(aOrbiterJ, 3U)) + aPhaseDWandererUpdateSaltD[((aIndex + 26U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 11U) + RotL64(aOrbiterF, 53U)) + aOrbiterC) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterD, 60U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererA, 6U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 32522U)) & S_BLOCK1], 6U) ^ RotL64(aKeyRowReadA[((aIndex + 32197U)) & W_KEY1], 27U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 30795U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30482U)) & S_BLOCK1], 41U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31551U)) & S_BLOCK1], 50U) ^ RotL64(aKeyRowReadB[((aIndex + 31206U)) & W_KEY1], 29U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aIngress, 41U)) + (RotL64(aPrevious, 27U) + RotL64(aCross, 60U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 40U)) + RotL64(aCarry, 21U)) + 3255291173184001106U;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 57U)) + 15308468160116255528U) + aPhaseDOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aCross, 19U)) + 18186972408589866656U;
            aOrbiterA = (aWandererB + RotL64(aScatter, 53U)) + 4439324265978331914U;
            aOrbiterK = ((aWandererK + RotL64(aCross, 35U)) + RotL64(aCarry, 37U)) + 13099263173016322486U;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 5U)) + 7041561081767500660U) + aPhaseDOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 11U)) + RotL64(aCarry, 3U)) + 6196422612687812971U;
            aOrbiterD = (aWandererF + RotL64(aIngress, 48U)) + 7664260932541281413U;
            aOrbiterI = (aWandererE + RotL64(aPrevious, 23U)) + 17802347823020441056U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 4253107484061190446U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 13799496534030645312U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9167675060053848207U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 14252892847595951926U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 5663527578664291422U;
            aOrbiterH = RotL64((aOrbiterH * 18314294235895182465U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 11148755959699137661U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 17036900929333594592U;
            aOrbiterB = RotL64((aOrbiterB * 16041243617369003291U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 2403828181385259549U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 17813580350434928194U;
            aOrbiterG = RotL64((aOrbiterG * 13666780980793857831U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 5623611126885414523U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 7293224381174846969U;
            aOrbiterA = RotL64((aOrbiterA * 7032561584670788117U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 10602620906929686163U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 18015916257203385982U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10684090189688871993U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 13592915735376305773U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 13995866908043417505U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3802175869395887331U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 8200465989447697618U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 9866671660800629464U;
            aOrbiterI = RotL64((aOrbiterI * 2138851839905326265U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 11557528777230608777U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 131060617338185060U;
            aOrbiterD = RotL64((aOrbiterD * 11068705423012265209U), 35U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 11U);
            aIngress = aIngress + (RotL64(aOrbiterI, 34U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 23U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + RotL64(aOrbiterH, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterB, 30U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterF, 43U)) + aOrbiterA);
            aWandererI = aWandererI + ((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterC, 51U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterK, 3U)) + aOrbiterA);
            aWandererC = aWandererC + ((RotL64(aIngress, 30U) + RotL64(aOrbiterI, 47U)) + aOrbiterG);
            aWandererD = aWandererD ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterD, 19U)) + aOrbiterC);
            aWandererA = aWandererA + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 57U)) + aOrbiterC) + RotL64(aCarry, 5U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterB, 26U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 42U) + aOrbiterD) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 21U)) + aPhaseDWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 14U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneC, aFireLaneD, aInvestLaneD, aFireLaneA, aOperationLaneA, aFireLaneC, aOperationLaneB, aOperationLaneC
        // write to: aInvestLaneC, aInvestLaneD, aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // twist_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneB
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 1505U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneB[((aIndex + 4293U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 2856U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1940U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3587U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 43U) ^ RotL64(aCross, 5U)) ^ (RotL64(aIngress, 18U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (((aWandererE + RotL64(aCross, 21U)) + RotL64(aCarry, 47U)) + 3448371607470865612U) + aPhaseEOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aScatter, 35U)) + 3743742913651580573U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 13U)) + RotL64(aCarry, 35U)) + 13069491287948807280U;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 47U)) + RotL64(aCarry, 23U)) + 16872779275586545632U;
            aOrbiterJ = (aWandererA + RotL64(aScatter, 29U)) + 17945792656755062795U;
            aOrbiterA = (aWandererI + RotL64(aCross, 58U)) + 18199747196793731853U;
            aOrbiterD = ((aWandererF + RotL64(aIngress, 41U)) + 15953311878379809513U) + aPhaseEOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 941268763494588338U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 10090221530365796809U;
            aOrbiterI = RotL64((aOrbiterI * 14035236086292997613U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 8335698093307607001U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 6147498804734306100U;
            aOrbiterJ = RotL64((aOrbiterJ * 6904444049941211327U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 5980246079567570090U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 4152167624425912978U;
            aOrbiterA = RotL64((aOrbiterA * 10019421651535123573U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 14990418790239735916U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 3418668387496597219U;
            aOrbiterH = RotL64((aOrbiterH * 12814077238529863119U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 4206650904177199425U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 3905470780938996069U;
            aOrbiterF = RotL64((aOrbiterF * 16030122739273137005U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 9968672788233080924U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 602258075661864866U;
            aOrbiterC = RotL64((aOrbiterC * 2615726693066300065U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 17751667243048041383U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 2414054413585296027U;
            aOrbiterD = RotL64((aOrbiterD * 1049512574773201893U), 53U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 13U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterC, 3U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterI, 37U)) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterJ, 57U)) + aOrbiterA);
            aWandererF = aWandererF + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterF, 21U)) + aOrbiterI);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterC, 11U)) + aOrbiterH);
            aWandererA = aWandererA + ((((RotL64(aCross, 12U) + aOrbiterD) + RotL64(aOrbiterA, 28U)) + RotL64(aCarry, 5U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 47U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 10U));
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + RotL64(aWandererA, 21U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 6101U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneC[((aIndex + 6385U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 5779U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9032U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneD[((aIndex + 10760U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 56U)) + (RotL64(aIngress, 43U) ^ RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (aWandererJ + RotL64(aScatter, 37U)) + 1210605127156905516U;
            aOrbiterK = (aWandererA + RotL64(aCross, 43U)) + 11964595428173569519U;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 23U)) + RotL64(aCarry, 3U)) + 16277319029916258482U;
            aOrbiterD = (aWandererG + RotL64(aPrevious, 29U)) + 12369497463101824572U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 11U)) + 6201248574067068202U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = (((aWandererK + RotL64(aScatter, 4U)) + RotL64(aCarry, 21U)) + 1727477025667206661U) + aPhaseEOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 53U)) + RotL64(aCarry, 41U)) + 1404510627789806851U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 6948213591282018925U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 6688865181284421478U;
            aOrbiterB = RotL64((aOrbiterB * 12619122841662247279U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 3351130769402360855U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 12681032488906270823U;
            aOrbiterG = RotL64((aOrbiterG * 3680893896579741263U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 3591412591193726763U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 16153817571210878589U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4165137036092246349U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 3808228354421006630U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 1427373776207504205U;
            aOrbiterF = RotL64((aOrbiterF * 4534374093769595531U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 1831554180932501132U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 1114853085120949215U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4264176108298812905U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 2080935638828366835U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 16104777999646489828U;
            aOrbiterI = RotL64((aOrbiterI * 15205199362011777473U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 9782806013673440791U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 3721620299829386454U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6286765834910272409U), 39U);
            //
            aIngress = RotL64(aOrbiterK, 46U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + RotL64(aOrbiterF, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 11U)) + aOrbiterJ) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 57U) + aOrbiterI) + RotL64(aOrbiterF, 57U));
            aWandererK = aWandererK + (((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 44U)) + aOrbiterG) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterB, 35U)) + aOrbiterD);
            aWandererG = aWandererG + (((RotL64(aCross, 23U) + aOrbiterG) + RotL64(aOrbiterK, 51U)) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 3U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltA[((aIndex + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 14U) + aOrbiterB) + RotL64(aOrbiterI, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 60U));
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererC, 11U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneD[((aIndex + 13156U)) & S_BLOCK1], 42U) ^ RotL64(aExpandLaneD[((aIndex + 13113U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 15975U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 14098U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 13470U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 15776U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 13U) + RotL64(aPrevious, 53U)) ^ (RotL64(aCarry, 41U) + RotL64(aIngress, 26U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = (aWandererI + RotL64(aScatter, 29U)) + 4476099022490972343U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 47U)) + RotL64(aCarry, 11U)) + 16836423700375760429U;
            aOrbiterF = (aWandererA + RotL64(aIngress, 60U)) + 8850577488928703557U;
            aOrbiterB = (((aWandererK + RotL64(aCross, 53U)) + RotL64(aCarry, 43U)) + 7091631824560042743U) + aPhaseEOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aIngress, 21U)) + 12560498899956759494U;
            aOrbiterJ = (aWandererC + RotL64(aCross, 3U)) + 7797973377112012161U;
            aOrbiterG = (((aWandererJ + RotL64(aScatter, 39U)) + RotL64(aCarry, 23U)) + 6173820673874805794U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 10805025132310245348U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 7139216143268029968U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8349754682635765573U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 8241544862261635722U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 4735527016563596150U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6621354217673598381U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 5166171126690294033U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 11117641762075368393U;
            aOrbiterB = RotL64((aOrbiterB * 4980156869201219393U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 6312932356458415421U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 1304139291184508668U;
            aOrbiterI = RotL64((aOrbiterI * 90744653170922319U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 10085025354842771067U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 16745854428789531080U;
            aOrbiterK = RotL64((aOrbiterK * 1945983905747274355U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 2497187958708890337U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 16069701876646548995U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16606039730973709495U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 17242004368025978091U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 12334315722243232121U;
            aOrbiterG = RotL64((aOrbiterG * 16528598396696346719U), 11U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 43U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 6U));
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterJ, 23U)) + aOrbiterF);
            aWandererK = aWandererK + (((RotL64(aIngress, 3U) + aOrbiterJ) + RotL64(aOrbiterI, 48U)) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 29U) + aOrbiterK) + RotL64(aOrbiterI, 37U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 23U) + aOrbiterB) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 39U)) + aPhaseEWandererUpdateSaltC[((aIndex + 28U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterH, 5U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 29U)) + aOrbiterG);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 58U) + RotL64(aOrbiterH, 11U)) + aOrbiterF) + aPhaseEWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 44U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + RotL64(aWandererJ, 53U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_b loop 4
        // ingress from: aOperationLaneA, aInvestLaneC, aFireLaneC
        // ingress directions: aOperationLaneA forward forced, aInvestLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aInvestLaneD, aExpandLaneD, aExpandLaneC
        // cross directions: aInvestLaneD backward forced, aExpandLaneD backward forced, aExpandLaneC backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 19071U)) & S_BLOCK1], 21U) ^ RotL64(aInvestLaneC[((aIndex + 20790U)) & S_BLOCK1], 38U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 16442U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 18123U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18788U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 17183U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 27U) ^ RotL64(aCarry, 11U)) + (RotL64(aIngress, 39U) ^ RotL64(aCross, 58U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = ((aWandererA + RotL64(aIngress, 58U)) + RotL64(aCarry, 5U)) + 2558105147674438050U;
            aOrbiterB = (aWandererC + RotL64(aScatter, 35U)) + 15856662514774702561U;
            aOrbiterE = (aWandererK + RotL64(aCross, 41U)) + 13346869226246584582U;
            aOrbiterK = (aWandererD + RotL64(aPrevious, 11U)) + 7632111846116243973U;
            aOrbiterF = ((aWandererI + RotL64(aCross, 3U)) + 2102101361626976279U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aScatter, 47U)) + RotL64(aCarry, 53U)) + 5605968705067851563U;
            aOrbiterG = (((aWandererG + RotL64(aPrevious, 29U)) + RotL64(aCarry, 27U)) + 6842483186584326681U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 5559797213819425064U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 12422313931331576759U;
            aOrbiterE = RotL64((aOrbiterE * 7399849122565913401U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 2751024420047872601U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 11031320239359798610U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8607639453141148025U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 14366375309473793217U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 11971479429768505316U;
            aOrbiterH = RotL64((aOrbiterH * 10063001532313098203U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 3947595951884469542U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 17882767922372770896U;
            aOrbiterD = RotL64((aOrbiterD * 3361906348965810211U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 513871456983509223U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 5951677013597794294U;
            aOrbiterG = RotL64((aOrbiterG * 8508629569649935293U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 437626309049021931U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 466674061172005705U;
            aOrbiterB = RotL64((aOrbiterB * 1310502572084891157U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 12362602809233133718U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 10525852878882195702U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17755022180514914325U), 57U);
            //
            aIngress = RotL64(aOrbiterD, 19U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterB, 11U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterE, 60U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 29U)) + aOrbiterB) + RotL64(aCarry, 51U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterB, 57U)) + aOrbiterG);
            aWandererI = aWandererI + (((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 26U) + aOrbiterF) + RotL64(aOrbiterH, 44U)) + aPhaseEWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterF, 13U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 51U)) + aOrbiterK);
            aWandererC = aWandererC + ((RotL64(aCross, 41U) + RotL64(aOrbiterH, 21U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 10U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 24194U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneA[((aIndex + 24741U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 22617U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 23450U)) & S_BLOCK1], 29U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 26788U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 26838U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCarry, 10U)) + (RotL64(aPrevious, 39U) ^ RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (((aWandererA + RotL64(aCross, 35U)) + RotL64(aCarry, 21U)) + 5576732410244514238U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 47U)) + RotL64(aCarry, 39U)) + 2833808925935929629U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 23U)) + RotL64(aCarry, 3U)) + 3670188682914544792U;
            aOrbiterH = (aWandererF + RotL64(aIngress, 11U)) + 15759072378887814995U;
            aOrbiterC = (aWandererB + RotL64(aCross, 58U)) + 13934007231137439994U;
            aOrbiterA = (aWandererH + RotL64(aPrevious, 5U)) + 11022225696007690512U;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 29U)) + 16989177104453635790U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 9256930045263527091U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 17788596104417068290U;
            aOrbiterG = RotL64((aOrbiterG * 675554110563253305U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 17044369456673337625U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 1310908395523250343U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16305084373037705921U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 12067065689034065422U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 15130844248737512262U;
            aOrbiterE = RotL64((aOrbiterE * 9409499577465934107U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 14532689204495587494U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 8198147292120244178U;
            aOrbiterF = RotL64((aOrbiterF * 1418356389507740991U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 5485494458627163347U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 10830008207150307611U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6526039534042499457U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 17770065502486618029U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 6397859353395335459U;
            aOrbiterA = RotL64((aOrbiterA * 14286997752368893825U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 5128700697381508319U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 7103394110057060499U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5053680689949149633U), 3U);
            //
            aIngress = RotL64(aOrbiterE, 35U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 26U));
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 35U) + aOrbiterF) + RotL64(aOrbiterG, 34U));
            aWandererF = aWandererF + (((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterE, 47U)) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 41U) + aOrbiterD) + RotL64(aOrbiterG, 13U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 21U)) + aOrbiterA) + RotL64(aCarry, 41U)) + aPhaseEWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 26U) + RotL64(aOrbiterE, 53U)) + aOrbiterD);
            aWandererB = aWandererB + ((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterH, 3U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 53U) + aOrbiterF) + RotL64(aOrbiterD, 27U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 4U));
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + RotL64(aWandererK, 21U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28413U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((aIndex + 31421U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 31280U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32135U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27331U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 32058U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 53U)) + (RotL64(aCross, 35U) + RotL64(aPrevious, 20U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = (aWandererC + RotL64(aCross, 38U)) + 4970414922752555648U;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 19U)) + 9462756592787669327U;
            aOrbiterG = (((aWandererI + RotL64(aIngress, 51U)) + RotL64(aCarry, 11U)) + 3948790686662213095U) + aPhaseEOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aPrevious, 13U)) + 14542857212241578311U;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 29U)) + RotL64(aCarry, 39U)) + 3387479009827029547U;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 3U)) + RotL64(aCarry, 57U)) + 1411421370057797877U;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 57U)) + 16894451466895681236U) + aPhaseEOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 12727136462290223542U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 4625389198191960525U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5726474430977810191U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 3471881403786164913U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 6433115856048534831U;
            aOrbiterH = RotL64((aOrbiterH * 9363233870194144053U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 9825592965466157982U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 1553125767261293088U;
            aOrbiterE = RotL64((aOrbiterE * 411535191177308781U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 9951616357109647617U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 11231080382787286889U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14024961994986659187U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 13419663264017317947U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 4835055642466215566U;
            aOrbiterJ = RotL64((aOrbiterJ * 17898065852351759171U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 14558747666410946768U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 13120938960926874504U;
            aOrbiterA = RotL64((aOrbiterA * 5681766019285559739U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 11910501376797343986U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 15074100100781785300U;
            aOrbiterB = RotL64((aOrbiterB * 228976960937473851U), 21U);
            //
            aIngress = RotL64(aOrbiterI, 27U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + RotL64(aOrbiterE, 44U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 36U) + RotL64(aOrbiterG, 29U)) + aOrbiterH) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 43U) + aOrbiterE) + RotL64(aOrbiterB, 43U));
            aWandererC = aWandererC + (((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterE, 13U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 21U) + aOrbiterB) + RotL64(aOrbiterH, 56U)) + RotL64(aCarry, 39U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterB, 21U)) + aOrbiterI);
            aWandererB = aWandererB + ((RotL64(aCross, 13U) + RotL64(aOrbiterI, 5U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 60U));
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
        // read from: aOperationLaneA, aOperationLaneB, aInvestLaneB, aOperationLaneC, aOperationLaneD, aExpandLaneB, aSnowLaneA, aExpandLaneC, aExpandLaneD, aSnowLaneB, aInvestLaneC, aWorkLaneA, aExpandLaneA, aWorkLaneB, aInvestLaneD, aWorkLaneC, aInvestLaneA
        // write to: aSnowLaneA, aSnowLaneB, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // twist_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aInvestLaneB
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aInvestLaneB forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aExpandLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aExpandLaneB backward/forward random
        // write to: aSnowLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 2449U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneB[((aIndex + 3205U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 3484U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2886U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 1853U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aExpandLaneB[((aIndex + 2679U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCarry, 37U)) + (RotL64(aCross, 10U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (aWandererB + RotL64(aIngress, 37U)) + 2571116506511057880U;
            aOrbiterD = (aWandererI + RotL64(aPrevious, 43U)) + 13112435411509707292U;
            aOrbiterB = (aWandererJ + RotL64(aCross, 24U)) + 10403251762787357256U;
            aOrbiterK = ((aWandererE + RotL64(aScatter, 53U)) + 8461951095541400405U) + aPhaseFOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 27U)) + 9890793478557463815U;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 39U)) + 3030229465991783707U) + aPhaseFOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aCross, 41U)) + 7273848154043719247U;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 29U)) + RotL64(aCarry, 21U)) + 10681774862516028276U;
            aOrbiterE = (aWandererF + RotL64(aIngress, 21U)) + 7105082755586853104U;
            aOrbiterA = ((aWandererC + RotL64(aCross, 13U)) + RotL64(aCarry, 29U)) + 6588579345319551129U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 56U)) + RotL64(aCarry, 5U)) + 14616333550242386092U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 15439666290229654921U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 3360304356760164799U;
            aOrbiterB = RotL64((aOrbiterB * 5164191920584106237U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 14438730801970761889U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 14515616787452085729U;
            aOrbiterC = RotL64((aOrbiterC * 2041601927968559821U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 4167853822635132419U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 8950982233003320239U;
            aOrbiterI = RotL64((aOrbiterI * 887144270884244907U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 12391327853728029953U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 7100871010552394421U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16552349374101955967U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 15381697462381887944U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 6801677551341079401U;
            aOrbiterF = RotL64((aOrbiterF * 13325954438427340703U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 947011315719204867U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 6356920162398333481U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5566721941682667419U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 8910262020598577378U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 8778455415977526457U;
            aOrbiterJ = RotL64((aOrbiterJ * 4092470497616637283U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 5585696961453127223U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 9670655481681494412U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7863197168965036383U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 10713004007087085729U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 4036355047492922339U;
            aOrbiterA = RotL64((aOrbiterA * 6923922258047667173U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 14580156873863533497U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 7049502932205025182U;
            aOrbiterK = RotL64((aOrbiterK * 8665428649262370727U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 12707521269341941677U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 2571116506511057880U;
            aOrbiterE = RotL64((aOrbiterE * 2388236789245943699U), 47U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterC, 20U);
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + RotL64(aOrbiterG, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 52U) + RotL64(aOrbiterE, 21U)) + aOrbiterK);
            aWandererG = aWandererG + ((RotL64(aIngress, 23U) + aOrbiterB) + RotL64(aOrbiterC, 58U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterD, 37U)) + aOrbiterB);
            aWandererD = aWandererD + ((RotL64(aPrevious, 39U) + aOrbiterD) + RotL64(aOrbiterH, 43U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 6U) + aOrbiterF) + RotL64(aOrbiterD, 35U));
            aWandererA = aWandererA + ((RotL64(aCross, 47U) + RotL64(aOrbiterG, 51U)) + aOrbiterE);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterD, 47U));
            aWandererE = aWandererE + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 11U)) + aOrbiterG) + RotL64(aCarry, 41U)) + aPhaseFWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterF, 41U)) + aOrbiterH);
            aWandererH = aWandererH + (((RotL64(aScatter, 41U) + aOrbiterJ) + RotL64(aOrbiterD, 27U)) + RotL64(aCarry, 27U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterJ, 24U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (RotL64(aWandererI, 18U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aSnowLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 2
        // ingress from: aSnowLaneA, aOperationLaneC, aOperationLaneD, aExpandLaneC
        // ingress directions: aSnowLaneA forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aExpandLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aExpandLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aExpandLaneD backward/forward random
        // write to: aSnowLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 5844U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((aIndex + 7538U)) & S_BLOCK1], 58U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 9189U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8949U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 5734U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6817U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 7307U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 41U)) ^ (RotL64(aPrevious, 28U) + RotL64(aCarry, 13U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = (aWandererK + RotL64(aIngress, 27U)) + 4384716820085860551U;
            aOrbiterJ = (((aWandererH + RotL64(aCross, 34U)) + RotL64(aCarry, 21U)) + 9715780315942116888U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aScatter, 57U)) + RotL64(aCarry, 41U)) + 15963520052789178632U;
            aOrbiterB = (aWandererG + RotL64(aPrevious, 3U)) + 14346700690686392938U;
            aOrbiterF = (aWandererJ + RotL64(aCross, 43U)) + 6005518012489966643U;
            aOrbiterK = (aWandererE + RotL64(aIngress, 21U)) + 2506732930310252119U;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 13U)) + 16782163084851775826U;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 47U)) + 823673076571076303U) + aPhaseFOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = (aWandererD + RotL64(aCross, 37U)) + 1634084509064077736U;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 10U)) + RotL64(aCarry, 27U)) + 1288134975466877686U;
            aOrbiterG = (aWandererC + RotL64(aScatter, 41U)) + 2998220403162908444U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 220430672180734911U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 10223923547068528867U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12577370238343872139U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 11696469696177647608U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 6545430420379636963U;
            aOrbiterF = RotL64((aOrbiterF * 8387163146257553773U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 79691451831797107U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 8971444023498649419U;
            aOrbiterD = RotL64((aOrbiterD * 7148919880477390009U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 5624403902454498793U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 9468064161002030997U;
            aOrbiterJ = RotL64((aOrbiterJ * 8243560528100864595U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 4619361544913629805U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 12682446273369750704U;
            aOrbiterE = RotL64((aOrbiterE * 10879074713156075641U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 8728730962617599223U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 9099675924074253030U;
            aOrbiterK = RotL64((aOrbiterK * 5525644236954497523U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 3298303921318288541U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 5953276499411658358U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10565471305001292693U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6725769507592688539U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 1057277456510215817U;
            aOrbiterG = RotL64((aOrbiterG * 8269412198279297075U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 11317925732206917722U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 17814749417006079067U;
            aOrbiterC = RotL64((aOrbiterC * 4369209051015735925U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 9258362135343403308U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 4873837345446960113U;
            aOrbiterA = RotL64((aOrbiterA * 14223381466269503273U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 7863380865835889675U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 4384716820085860551U;
            aOrbiterB = RotL64((aOrbiterB * 2003891033298374621U), 53U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterC, 24U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterC, 22U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 5U) + aOrbiterD) + RotL64(aOrbiterC, 19U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterG, 27U)) + aOrbiterB);
            aWandererK = aWandererK + (((RotL64(aIngress, 18U) + RotL64(aOrbiterA, 47U)) + aOrbiterJ) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 51U)) + aOrbiterC);
            aWandererH = aWandererH + ((RotL64(aCross, 47U) + RotL64(aOrbiterE, 30U)) + aOrbiterF);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterH, 37U)) + aOrbiterA);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterK, 13U)) + RotL64(aCarry, 27U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterH, 35U)) + aOrbiterJ);
            aWandererA = aWandererA + ((RotL64(aIngress, 56U) + RotL64(aOrbiterD, 11U)) + aOrbiterI);
            aWandererG = aWandererG ^ ((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterF, 5U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 56U));
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererD, 44U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aSnowLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 3
        // ingress from: aSnowLaneB, aOperationLaneA, aInvestLaneC
        // ingress directions: aSnowLaneB forward forced, aOperationLaneA forward forced, aInvestLaneC forward/backward random
        // cross from: aSnowLaneA, aOperationLaneC
        // cross directions: aSnowLaneA backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneB[((aIndex + 14044U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((aIndex + 12607U)) & S_BLOCK1], 42U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 13076U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 14137U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneC[((aIndex + 14586U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 27U) + RotL64(aIngress, 53U)) + (RotL64(aPrevious, 10U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = ((aWandererF + RotL64(aCross, 34U)) + RotL64(aCarry, 47U)) + 13278949403988203974U;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 53U)) + RotL64(aCarry, 5U)) + 9213599924054673756U;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 23U)) + 1255746482932381798U;
            aOrbiterC = (((aWandererA + RotL64(aScatter, 43U)) + RotL64(aCarry, 35U)) + 11575321997144516122U) + aPhaseFOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = (aWandererI + RotL64(aCross, 19U)) + 15881587525529432437U;
            aOrbiterK = (aWandererH + RotL64(aIngress, 14U)) + 9846195809864862707U;
            aOrbiterB = (aWandererG + RotL64(aPrevious, 51U)) + 12319815691858217670U;
            aOrbiterF = (aWandererD + RotL64(aScatter, 39U)) + 16322617427294439587U;
            aOrbiterJ = (aWandererK + RotL64(aCross, 37U)) + 16332130810525887437U;
            aOrbiterD = (aWandererB + RotL64(aScatter, 47U)) + 4920951156015336794U;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 27U)) + 16767126455124552329U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 12553595911087945223U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 1437522202135436142U;
            aOrbiterE = RotL64((aOrbiterE * 2001992794165550905U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 12313100454852227143U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 2761983020631055729U;
            aOrbiterH = RotL64((aOrbiterH * 3874839760378039509U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 17635303588421554367U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 788212489507463763U;
            aOrbiterB = RotL64((aOrbiterB * 17896475584538528059U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 5192552894670654434U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 6784748488807738811U;
            aOrbiterJ = RotL64((aOrbiterJ * 8077237651953896479U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 16113417046719114943U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 1096874945215225916U;
            aOrbiterG = RotL64((aOrbiterG * 17308604412622879833U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 7610274704570171595U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 10466070212284342550U;
            aOrbiterI = RotL64((aOrbiterI * 6449728258497920613U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 6777845928873855221U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 5251515022021984126U;
            aOrbiterF = RotL64((aOrbiterF * 9018277343404261611U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 13849343158824111498U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 7977711210181714021U;
            aOrbiterA = RotL64((aOrbiterA * 4182053966171053577U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 6494539818728106982U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 11314590450226080781U;
            aOrbiterD = RotL64((aOrbiterD * 12455979257225599157U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 552687702594328012U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 14961304171192292246U;
            aOrbiterC = RotL64((aOrbiterC * 846375892915484717U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 9771874402848476494U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 13278949403988203974U;
            aOrbiterK = RotL64((aOrbiterK * 2119203863777871233U), 53U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 43U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 14U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + RotL64(aOrbiterH, 24U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterH, 47U)) + aOrbiterB);
            aWandererA = aWandererA + ((RotL64(aScatter, 24U) + aOrbiterD) + RotL64(aOrbiterI, 41U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterF, 39U)) + aOrbiterJ);
            aWandererK = aWandererK + ((RotL64(aPrevious, 27U) + aOrbiterB) + RotL64(aOrbiterJ, 21U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterJ, 13U)) + aOrbiterA) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterC, 34U)) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 5U) + aOrbiterH) + RotL64(aOrbiterK, 23U));
            aWandererD = aWandererD + (((RotL64(aIngress, 60U) + aOrbiterE) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 39U) + aOrbiterD) + RotL64(aOrbiterF, 53U));
            aWandererI = aWandererI + (((RotL64(aIngress, 21U) + RotL64(aOrbiterG, 4U)) + aOrbiterF) + aPhaseFWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 29U) + aOrbiterD) + RotL64(aOrbiterC, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + (RotL64(aWandererE, 26U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 37U);
            aCarry = aCarry + RotL64(aIngress, 10U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 4
        // ingress from: aWorkLaneA, aSnowLaneA, aExpandLaneA
        // ingress directions: aWorkLaneA forward forced, aSnowLaneA forward forced, aExpandLaneA forward/backward random
        // cross from: aSnowLaneB, aOperationLaneD
        // cross directions: aSnowLaneB backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 19178U)) & S_BLOCK1], 29U) ^ RotL64(aSnowLaneA[((aIndex + 21336U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aExpandLaneA[((aIndex + 18794U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 19676U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 18899U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 57U)) ^ (RotL64(aCarry, 38U) + RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = ((aWandererE + RotL64(aCross, 60U)) + RotL64(aCarry, 19U)) + 9888431329297626900U;
            aOrbiterF = (aWandererB + RotL64(aPrevious, 5U)) + 2937735167534624403U;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 57U)) + 17626022970343789617U) + aPhaseFOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aIngress, 13U)) + 5665660859333693743U;
            aOrbiterI = (aWandererI + RotL64(aPrevious, 21U)) + 1060537034632076669U;
            aOrbiterB = (aWandererA + RotL64(aScatter, 43U)) + 743777763907175800U;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 40U)) + 5744905970181808845U;
            aOrbiterA = (aWandererF + RotL64(aCross, 19U)) + 3545351394494002180U;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 53U)) + RotL64(aCarry, 47U)) + 4877547088414106007U;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 27U)) + 11669378338379598445U) + aPhaseFOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aIngress, 37U)) + RotL64(aCarry, 23U)) + 2961072441706158212U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 13984945589234919765U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 1433097875470903205U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 451996840039906781U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 716415411025451152U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 8542286150858297810U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9139015340823332449U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 12932391786479661299U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 14005503313299177013U;
            aOrbiterA = RotL64((aOrbiterA * 802663466907819743U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 9382792812676318046U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 5138554251079724724U;
            aOrbiterG = RotL64((aOrbiterG * 6386016499265056247U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 8522380066269546172U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 11825536408101906458U;
            aOrbiterH = RotL64((aOrbiterH * 17042837108792016849U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 15504062350899452495U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 1219010998820336744U;
            aOrbiterD = RotL64((aOrbiterD * 10650635772711590803U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 6442717843380349632U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 1047843426279085117U;
            aOrbiterF = RotL64((aOrbiterF * 4074561571072878005U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 10611039527108679173U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 5092816736177358221U;
            aOrbiterK = RotL64((aOrbiterK * 14342779343820140833U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 12327496881352988530U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 6405703847824845457U;
            aOrbiterE = RotL64((aOrbiterE * 12094143526751620113U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 8906613392335197542U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 5962698890029858689U;
            aOrbiterI = RotL64((aOrbiterI * 9136193803330500489U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 2610083915800734277U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 9888431329297626900U;
            aOrbiterJ = RotL64((aOrbiterJ * 3794133356691218671U), 13U);
            //
            aIngress = RotL64(aOrbiterA, 39U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + (RotL64(aOrbiterI, 46U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 51U) + aOrbiterK) + RotL64(aOrbiterH, 18U));
            aWandererB = aWandererB + (((RotL64(aScatter, 53U) + aOrbiterI) + RotL64(aOrbiterG, 39U)) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 41U) + aOrbiterF) + RotL64(aOrbiterE, 5U)) + aPhaseFWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 38U) + aOrbiterE) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterJ, 47U)) + aOrbiterG);
            aWandererF = aWandererF + ((RotL64(aCross, 23U) + RotL64(aOrbiterD, 35U)) + aOrbiterH);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterC, 27U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterE, 53U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 27U) + aOrbiterB) + RotL64(aOrbiterJ, 29U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 56U) + aOrbiterA) + RotL64(aOrbiterE, 10U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterA, 57U)) + aOrbiterC) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 44U));
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + RotL64(aWandererC, 52U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 5
        // ingress from: aWorkLaneB, aSnowLaneB, aInvestLaneD
        // ingress directions: aWorkLaneB forward forced, aSnowLaneB forward forced, aInvestLaneD forward/backward random
        // cross from: aWorkLaneA, aSnowLaneA
        // cross directions: aWorkLaneA backward forced, aSnowLaneA backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 26012U)) & S_BLOCK1], 22U) ^ RotL64(aSnowLaneB[((aIndex + 25346U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 22125U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26762U)) & S_BLOCK1], 21U) ^ RotL64(aSnowLaneA[((aIndex + 22508U)) & S_BLOCK1], 46U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCross, 53U)) + (RotL64(aIngress, 36U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (aWandererE + RotL64(aIngress, 48U)) + 12206125048349568300U;
            aOrbiterG = (aWandererJ + RotL64(aCross, 23U)) + 5843520589343188818U;
            aOrbiterA = (((aWandererC + RotL64(aScatter, 3U)) + RotL64(aCarry, 21U)) + 12195046124287121687U) + aPhaseFOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = (((aWandererD + RotL64(aPrevious, 41U)) + RotL64(aCarry, 29U)) + 16769779119214020640U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = (aWandererF + RotL64(aCross, 29U)) + 5257603646260695833U;
            aOrbiterF = (aWandererK + RotL64(aScatter, 35U)) + 8523523946234886745U;
            aOrbiterD = (aWandererI + RotL64(aPrevious, 21U)) + 7316024684200084096U;
            aOrbiterH = ((aWandererB + RotL64(aIngress, 10U)) + RotL64(aCarry, 11U)) + 11996978575084115207U;
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 13U)) + 15491711479085513628U;
            aOrbiterI = (aWandererA + RotL64(aCross, 37U)) + 6036648530996821484U;
            aOrbiterE = (aWandererG + RotL64(aScatter, 19U)) + 926323222234121863U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 2700323841295743492U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 5852273765810284935U;
            aOrbiterA = RotL64((aOrbiterA * 16665696735016345215U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 11697397483133538067U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 17777142964957007194U;
            aOrbiterC = RotL64((aOrbiterC * 6338967222543284999U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 10892176201151170298U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 11759700374509499684U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14247697264744736081U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 11343756773329590643U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 15785048929757652350U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17208103574389502597U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 7508839228498497238U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 13088508510402094665U;
            aOrbiterH = RotL64((aOrbiterH * 15730279447009669103U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 16259236641717377699U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 11228995722951003980U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4870092259515181323U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 13775851561528617086U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 3023564646900497080U;
            aOrbiterK = RotL64((aOrbiterK * 9936548213275464131U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 154952467284609583U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 14239675888632174461U;
            aOrbiterJ = RotL64((aOrbiterJ * 1370550680736926425U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 168749514558708557U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 5070416708211422927U;
            aOrbiterD = RotL64((aOrbiterD * 13631900152346927703U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 1961290602001581341U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 12235345489656113478U;
            aOrbiterI = RotL64((aOrbiterI * 14403534235273302211U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 2295581049708176078U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 12206125048349568300U;
            aOrbiterG = RotL64((aOrbiterG * 6008868846674396181U), 35U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterB, 23U);
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + RotL64(aOrbiterI, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 60U) + aOrbiterC) + RotL64(aOrbiterJ, 39U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterF, 13U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 13U) + aOrbiterK) + RotL64(aOrbiterB, 6U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 11U)) + aOrbiterH);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterB, 53U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 41U) + aOrbiterJ) + RotL64(aOrbiterI, 19U)) + RotL64(aCarry, 37U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterG, 26U));
            aWandererI = aWandererI + ((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 37U)) + aOrbiterF);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 48U) + aOrbiterD) + RotL64(aOrbiterE, 43U));
            aWandererD = aWandererD + ((((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 23U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterA, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 46U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 20U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 6
        // ingress from: aWorkLaneC, aWorkLaneA, aInvestLaneA
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aInvestLaneA forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 28686U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((aIndex + 28042U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 31698U)) & S_BLOCK1], 54U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30259U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29453U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 29U) ^ RotL64(aIngress, 10U)) + (RotL64(aCross, 57U) ^ RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 13U)) + 18087125778766689269U) + aPhaseFOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aScatter, 39U)) + 13710545066503235196U;
            aOrbiterD = (aWandererC + RotL64(aCross, 54U)) + 1701939704736254645U;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 43U)) + RotL64(aCarry, 35U)) + 8064093611384019909U;
            aOrbiterH = (aWandererE + RotL64(aCross, 57U)) + 16623332751533885431U;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 19U)) + 15590129153794910109U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = (aWandererJ + RotL64(aIngress, 35U)) + 7413312683079107383U;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 5U)) + RotL64(aCarry, 27U)) + 4186064478651458810U;
            aOrbiterF = (aWandererD + RotL64(aIngress, 27U)) + 5501191643940735954U;
            aOrbiterK = (aWandererF + RotL64(aScatter, 29U)) + 11064645242200570835U;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 50U)) + RotL64(aCarry, 5U)) + 13825922087298055833U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 5944980709887369970U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 8181136916070569646U;
            aOrbiterD = RotL64((aOrbiterD * 395183021205661827U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 15442336949157292482U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 11580554435240641337U;
            aOrbiterH = RotL64((aOrbiterH * 6654637892858767739U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 11240018128174598322U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 2027565596050777471U;
            aOrbiterE = RotL64((aOrbiterE * 18048186560314431815U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 16425887196883725233U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 16828683527588834095U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17746289103235902485U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 9923829146479008804U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 6669171007279929454U;
            aOrbiterF = RotL64((aOrbiterF * 681823450939955099U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 3902430046523165149U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 6739998149289590041U;
            aOrbiterJ = RotL64((aOrbiterJ * 2675037435528416821U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 16014401255534234075U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 14741857638680634564U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8723611021403369393U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 5064807861673260054U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 968747317273200299U;
            aOrbiterB = RotL64((aOrbiterB * 14122304002722582329U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 5282686212362051427U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 6902253563196129760U;
            aOrbiterC = RotL64((aOrbiterC * 7682808024658992049U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 4995580401402368332U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 14949762584793646470U;
            aOrbiterK = RotL64((aOrbiterK * 3539183342072953803U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 2378815735788107402U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 18087125778766689269U;
            aOrbiterA = RotL64((aOrbiterA * 16799380528404446281U), 19U);
            //
            aIngress = RotL64(aOrbiterI, 37U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterD, 6U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 20U) + RotL64(aOrbiterA, 51U)) + aOrbiterG) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterE, 41U));
            aWandererC = aWandererC + ((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 13U)) + aOrbiterH);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 13U) + aOrbiterB) + RotL64(aOrbiterE, 53U));
            aWandererI = aWandererI + ((RotL64(aScatter, 24U) + RotL64(aOrbiterJ, 44U)) + aOrbiterI);
            aWandererA = aWandererA ^ (((RotL64(aCross, 29U) + aOrbiterE) + RotL64(aOrbiterG, 57U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 39U)) + aOrbiterB);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterJ, 3U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 39U) + aOrbiterF) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 11U)) + aPhaseFWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterC, 34U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterD, 37U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 14U));
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 58U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterK = 0;

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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 3033U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneB[((aIndex + 7721U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 1561U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 2314U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 4194U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 7506U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 28U) ^ RotL64(aIngress, 57U)) + (RotL64(aCross, 41U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (aWandererA + RotL64(aPrevious, 11U)) + 6733949564325516029U;
            aOrbiterC = (aWandererH + RotL64(aIngress, 20U)) + 7304098437143918796U;
            aOrbiterA = (((aWandererF + RotL64(aCross, 51U)) + RotL64(aCarry, 11U)) + 3923949518391777800U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aScatter, 29U)) + RotL64(aCarry, 29U)) + 14243591003388927124U;
            aOrbiterG = (((aWandererC + RotL64(aPrevious, 41U)) + RotL64(aCarry, 47U)) + 18329498724605410406U) + aPhaseGOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 13118172167747037249U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 5272025143849174212U;
            aOrbiterA = RotL64((aOrbiterA * 9935990954321437743U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 16075917179214318424U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 15263590648674658399U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9918239923411740337U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 13730046728289525921U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 7703141464499623408U;
            aOrbiterF = RotL64((aOrbiterF * 5886009900621521987U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 1382279753822135359U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 2973369221699098292U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7440242040663550631U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 11578274119583013219U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 3419411247737896674U;
            aOrbiterC = RotL64((aOrbiterC * 17814942652262802991U), 57U);
            //
            aIngress = RotL64(aOrbiterA, 3U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + RotL64(aOrbiterD, 14U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterA, 53U)) + RotL64(aCarry, 43U)) + aPhaseGWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterF, 41U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 44U) + RotL64(aOrbiterD, 4U)) + aOrbiterA) + RotL64(aCarry, 27U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 13U)) + aOrbiterC);
            aWandererC = aWandererC + (((RotL64(aCross, 13U) + RotL64(aOrbiterC, 21U)) + aOrbiterG) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 53U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 15674U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneB[((aIndex + 12556U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 10983U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16056U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 10030U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 10556U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCross, 18U)) ^ (RotL64(aCarry, 5U) + RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = (aWandererJ + RotL64(aScatter, 53U)) + 18191288703716505885U;
            aOrbiterA = ((aWandererA + RotL64(aCross, 21U)) + RotL64(aCarry, 11U)) + 9824014524910417136U;
            aOrbiterI = (((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 37U)) + 11953012029254917548U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aIngress, 30U)) + RotL64(aCarry, 53U)) + 6297568011027199089U;
            aOrbiterG = ((aWandererD + RotL64(aCross, 39U)) + 2576999400457367975U) + aPhaseGOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 13176139160575558254U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 9978408174563621810U;
            aOrbiterI = RotL64((aOrbiterI * 1399052522159751531U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 16765834875061607142U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 16534507305459121344U;
            aOrbiterA = RotL64((aOrbiterA * 8943988574248229067U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 3114710944346151807U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 10240517868726718592U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4645691562915606463U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 10721450637990777883U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 16689590768796583952U;
            aOrbiterE = RotL64((aOrbiterE * 3046344179729901637U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 2427422768928450209U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 13495584061816457831U;
            aOrbiterB = RotL64((aOrbiterB * 6670984773768885119U), 29U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterG, 57U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 37U));
            aIngress = aIngress + RotL64(aOrbiterE, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 34U) + RotL64(aOrbiterI, 43U)) + aOrbiterE);
            aWandererH = aWandererH + ((((RotL64(aIngress, 13U) + aOrbiterB) + RotL64(aOrbiterE, 30U)) + RotL64(aCarry, 35U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 43U) + aOrbiterB) + RotL64(aOrbiterI, 51U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 21U)) + aOrbiterA) + RotL64(aCarry, 5U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 11U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + RotL64(aWandererJ, 4U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 18441U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneA[((aIndex + 22525U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 20748U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20904U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 18771U)) & S_BLOCK1], 10U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 18621U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 14U) ^ RotL64(aIngress, 27U)) + (RotL64(aCarry, 39U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = (aWandererK + RotL64(aScatter, 39U)) + 15726877954695761686U;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 48U)) + RotL64(aCarry, 11U)) + 14187652171881943587U;
            aOrbiterF = (((aWandererG + RotL64(aCross, 3U)) + RotL64(aCarry, 23U)) + 8420423151313882782U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 19U)) + RotL64(aCarry, 53U)) + 14942322692433259283U;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 29U)) + 7272331475919796255U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 154504365041805840U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 17475491222554948786U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2095330528612694779U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 5759181483165339605U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 5993060214499322845U;
            aOrbiterK = RotL64((aOrbiterK * 10799489831896153301U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 10901786237875941844U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 17135786595614068473U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15923538730142047043U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 5208202073886811165U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 6821452921018900631U;
            aOrbiterE = RotL64((aOrbiterE * 13119330055184115669U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 13348064837402206969U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 8967943922403445136U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 300168481725373093U), 3U);
            //
            aIngress = RotL64(aOrbiterA, 47U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterF, 18U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterE, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterE, 41U)) + aOrbiterH);
            aWandererG = aWandererG + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 29U)) + aOrbiterF) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterF, 11U)) + aOrbiterE) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aIngress, 11U) + aOrbiterK) + RotL64(aOrbiterH, 56U)) + RotL64(aCarry, 23U)) + aPhaseGWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 28U) + aOrbiterA) + RotL64(aOrbiterE, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 30495U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((aIndex + 28738U)) & S_BLOCK1], 26U));
            aIngress ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28584U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26342U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31923U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 25685U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 47U) ^ RotL64(aIngress, 21U)) ^ (RotL64(aPrevious, 35U) + RotL64(aCross, 60U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 28U)) + RotL64(aCarry, 43U)) + 6068543441070417854U;
            aOrbiterK = (((aWandererD + RotL64(aCross, 37U)) + RotL64(aCarry, 5U)) + 2995980468193441856U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = (((aWandererG + RotL64(aIngress, 57U)) + RotL64(aCarry, 23U)) + 18020277482171594003U) + aPhaseGOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aScatter, 47U)) + 4293807434721230702U;
            aOrbiterH = (aWandererA + RotL64(aCross, 11U)) + 7980599111583893156U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 8593141111851052016U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 5903487523900084325U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2508618861111356699U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 15112035513447930209U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 9854037263057006439U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 396276470208637283U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 16759760289688823193U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 12622628933030601390U;
            aOrbiterF = RotL64((aOrbiterF * 2151912984825538321U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 1264668857268123425U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 16302812053619101593U;
            aOrbiterC = RotL64((aOrbiterC * 18291400055836111547U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 16087995784896123610U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 7970269262800468363U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14924752223305807461U), 3U);
            //
            aIngress = RotL64(aOrbiterC, 18U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 27U) + aOrbiterE) + RotL64(aOrbiterK, 37U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 48U)) + aOrbiterH) + RotL64(aCarry, 57U)) + aPhaseGWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterC, 27U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 5U) + aOrbiterF) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 52U) + RotL64(aOrbiterK, 5U)) + aOrbiterC) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 5991U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((aIndex + 840U)) & S_BLOCK1], 12U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 2672U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5773U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8122U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 1215U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 29U) + RotL64(aCarry, 11U)) ^ (RotL64(aCross, 58U) ^ RotL64(aIngress, 43U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = (((aWandererD + RotL64(aPrevious, 11U)) + RotL64(aCarry, 51U)) + 15920462086654025436U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aIngress, 19U)) + RotL64(aCarry, 21U)) + 487844076858004017U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 57U)) + RotL64(aCarry, 37U)) + 14502883786442630566U;
            aOrbiterC = (aWandererE + RotL64(aCross, 30U)) + 3787107318658233674U;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 3U)) + 12548777544693755491U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 4907309444075181683U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 18342396700266492072U;
            aOrbiterB = RotL64((aOrbiterB * 14842961036061482089U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 13503051997624242670U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 17845742460521374571U;
            aOrbiterC = RotL64((aOrbiterC * 1366356786138085155U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 8640887211877858169U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 5273913123709097537U;
            aOrbiterF = RotL64((aOrbiterF * 1661149444148461791U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 17756844173695563883U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 6713055830729302951U;
            aOrbiterD = RotL64((aOrbiterD * 2832836748513174311U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 5106468334224035972U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 10228769728713526172U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9760310686414358435U), 57U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 29U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 52U));
            aIngress = aIngress + RotL64(aOrbiterF, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aPrevious, 50U) + aOrbiterE) + RotL64(aOrbiterC, 53U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterD, 43U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 37U) + aOrbiterB) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 35U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterD, 3U)) + aOrbiterB);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 21U) + aOrbiterE) + RotL64(aOrbiterF, 30U)) + RotL64(aCarry, 21U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + RotL64(aWandererK, 13U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 10974U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((aIndex + 9677U)) & S_BLOCK1], 34U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 9234U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11280U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11438U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11220U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 28U) ^ RotL64(aCarry, 43U)) ^ (RotL64(aIngress, 57U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = ((aWandererK + RotL64(aIngress, 43U)) + RotL64(aCarry, 37U)) + 12262991801139086177U;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 34U)) + 7963038771924890197U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aPrevious, 5U)) + 15540520327933568896U;
            aOrbiterA = (((aWandererC + RotL64(aCross, 19U)) + RotL64(aCarry, 21U)) + 8745565892055020722U) + aPhaseHOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 51U)) + RotL64(aCarry, 5U)) + 16619329199683755286U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 10865705026433867260U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 2743368697984518059U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2989232417816919375U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 5556006271515473135U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 5355833281353498588U;
            aOrbiterI = RotL64((aOrbiterI * 4190140212757841511U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 8313616108963479829U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 16657121016801866434U;
            aOrbiterK = RotL64((aOrbiterK * 331533349428472477U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 16532226425013000833U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 5800465874932467232U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5966395771690704577U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 17882948163883121328U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 15029375310296563175U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17021415832288477713U), 35U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 37U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 6U));
            aIngress = aIngress + RotL64(aOrbiterE, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 48U) + RotL64(aOrbiterE, 11U)) + aOrbiterA) + aPhaseHWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 27U) + RotL64(aOrbiterA, 52U)) + aOrbiterC) + RotL64(aCarry, 35U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 19U)) + aOrbiterE);
            aWandererH = aWandererH + (((RotL64(aCross, 57U) + RotL64(aOrbiterI, 27U)) + aOrbiterK) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 35U)) + aOrbiterK) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 58U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 22579U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneA[((aIndex + 19838U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aExpandLaneD[((aIndex + 17450U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17505U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20762U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 23607U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 24U) ^ RotL64(aPrevious, 37U)) + (RotL64(aIngress, 57U) ^ RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = (aWandererJ + RotL64(aCross, 4U)) + 17711946802293254150U;
            aOrbiterJ = (aWandererA + RotL64(aIngress, 21U)) + 16652362590489569378U;
            aOrbiterK = (((aWandererK + RotL64(aScatter, 37U)) + RotL64(aCarry, 23U)) + 6972810344198183097U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = (((aWandererE + RotL64(aPrevious, 47U)) + RotL64(aCarry, 57U)) + 13117100889782940546U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aIngress, 13U)) + RotL64(aCarry, 37U)) + 13199305696782626591U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 992156184392760945U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 13791265442074543880U;
            aOrbiterK = RotL64((aOrbiterK * 1263919538622722673U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 17057087245252294859U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 13444195995883541046U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13067044288608808777U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 6723678233676059420U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 7913379431208430475U;
            aOrbiterF = RotL64((aOrbiterF * 2295062944289127123U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 4481887195529300665U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 11892724101424384078U;
            aOrbiterJ = RotL64((aOrbiterJ * 3468639499716604111U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 7700902083270424194U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 1888001433557140271U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8975562955027025349U), 43U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 3U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + RotL64(aOrbiterB, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 3U) + aOrbiterE) + RotL64(aOrbiterF, 35U)) + aPhaseHWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 11U) + aOrbiterE) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 48U) + aOrbiterB) + RotL64(aOrbiterF, 11U)) + aPhaseHWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterK, 22U)) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 37U) + aOrbiterE) + RotL64(aOrbiterB, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 47U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 25846U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneB[((aIndex + 32215U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28209U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28468U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32246U)) & S_BLOCK1], 46U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 32040U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 43U)) ^ (RotL64(aIngress, 5U) ^ RotL64(aCarry, 26U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (((aWandererK + RotL64(aScatter, 28U)) + RotL64(aCarry, 19U)) + 16462052553719977502U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aPrevious, 3U)) + 12337064059566619581U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 51U)) + RotL64(aCarry, 53U)) + 15801005007094515447U;
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 41U)) + RotL64(aCarry, 35U)) + 8228706742665081656U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 19U)) + 11006723027845190869U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 18173765337829177450U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 530215083653542558U;
            aOrbiterH = RotL64((aOrbiterH * 8938680024265564887U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 6608611827035564511U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 2246051826221626809U;
            aOrbiterB = RotL64((aOrbiterB * 6333352641495253539U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 5228575308895381421U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 10999213210689606857U;
            aOrbiterC = RotL64((aOrbiterC * 5467601259546342925U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 3773371037240485696U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 8887985779436152504U;
            aOrbiterG = RotL64((aOrbiterG * 698713082830739677U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 11150566414723818350U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 8336366151003049546U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9033771197242493699U), 21U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterG, 57U);
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 57U)) + aOrbiterH);
            aWandererK = aWandererK + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 38U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterH, 21U)) + aOrbiterC) + aPhaseHWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 40U) + aOrbiterF) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 23U)) + aPhaseHWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 30U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
